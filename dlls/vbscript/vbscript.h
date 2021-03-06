/*
 * Copyright 2011 Jacek Caban for CodeWeavers
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#include <stdarg.h>

#define COBJMACROS

#include "windef.h"
#include "winbase.h"
#include "ole2.h"
#include "dispex.h"
#include "activscp.h"

#include "vbscript_classes.h"

#include "wine/list.h"
#include "wine/unicode.h"

typedef struct {
    void **blocks;
    DWORD block_cnt;
    DWORD last_block;
    DWORD offset;
    struct list custom_blocks;
} vbsheap_t;

void vbsheap_init(vbsheap_t*) DECLSPEC_HIDDEN;
void *vbsheap_alloc(vbsheap_t*,size_t) __WINE_ALLOC_SIZE(2) DECLSPEC_HIDDEN;
void vbsheap_free(vbsheap_t*) DECLSPEC_HIDDEN;

typedef struct _function_t function_t;
typedef struct _vbscode_t vbscode_t;
typedef struct _script_ctx_t script_ctx_t;
typedef struct _vbdisp_t vbdisp_t;

typedef struct named_item_t {
    IDispatch *disp;
    DWORD flags;
    LPWSTR name;

    struct list entry;
} named_item_t;

typedef enum {
    VBDISP_CALLGET,
    VBDISP_LET,
    VBDISP_SET,
    VBDISP_ANY
} vbdisp_invoke_type_t;

typedef struct {
    BOOL is_public;
    const WCHAR *name;
} vbdisp_prop_desc_t;

typedef struct {
    const WCHAR *name;
    BOOL is_public;
    function_t *entries[VBDISP_ANY];
} vbdisp_funcprop_desc_t;

#define BP_GET      1
#define BP_GETPUT   2

typedef struct {
    DISPID id;
    HRESULT (*proc)(vbdisp_t*,VARIANT*,unsigned,VARIANT*);
    DWORD flags;
    unsigned min_args;
    unsigned max_args;
} builtin_prop_t;

typedef struct _class_desc_t {
    const WCHAR *name;
    script_ctx_t *ctx;

    unsigned class_initialize_id;
    unsigned class_terminate_id;
    unsigned func_cnt;
    vbdisp_funcprop_desc_t *funcs;

    unsigned prop_cnt;
    vbdisp_prop_desc_t *props;

    unsigned builtin_prop_cnt;
    const builtin_prop_t *builtin_props;
    ITypeInfo *typeinfo;

    struct _class_desc_t *next;
} class_desc_t;

struct _vbdisp_t {
    IDispatchEx IDispatchEx_iface;

    LONG ref;
    BOOL terminator_ran;
    struct list entry;

    const class_desc_t *desc;
    VARIANT props[1];
};

HRESULT create_vbdisp(const class_desc_t*,vbdisp_t**);
HRESULT disp_get_id(IDispatch*,BSTR,vbdisp_invoke_type_t,BOOL,DISPID*);
HRESULT vbdisp_get_id(vbdisp_t*,BSTR,vbdisp_invoke_type_t,BOOL,DISPID*);
HRESULT disp_call(script_ctx_t*,IDispatch*,DISPID,DISPPARAMS*,VARIANT*);
HRESULT disp_propput(script_ctx_t*,IDispatch*,DISPID,VARIANT*);
void collect_objects(script_ctx_t*);

static inline unsigned arg_cnt(const DISPPARAMS *dp)
{
    return dp->cArgs - dp->cNamedArgs;
}

static inline VARIANT *get_arg(DISPPARAMS *dp, DWORD i)
{
    return dp->rgvarg + dp->cArgs-i-1;
}

typedef struct _dynamic_var_t {
    struct _dynamic_var_t *next;
    VARIANT v;
    const WCHAR *name;
} dynamic_var_t;

struct _script_ctx_t {
    IActiveScriptSite *site;
    LCID lcid;

    IDispatch *host_global;

    class_desc_t script_desc;
    vbdisp_t *script_obj;

    class_desc_t global_desc;
    vbdisp_t *global_obj;

    class_desc_t err_desc;
    vbdisp_t *err_obj;

    dynamic_var_t *global_vars;
    function_t *global_funcs;
    class_desc_t *classes;

    struct list objects;
    struct list code_list;
    struct list named_items;
};

HRESULT init_global(script_ctx_t*);
HRESULT init_err(script_ctx_t*);

typedef enum {
    ARG_NONE = 0,
    ARG_STR,
    ARG_BSTR,
    ARG_INT,
    ARG_UINT,
    ARG_ADDR,
    ARG_DOUBLE
} instr_arg_type_t;

#define OP_LIST                                   \
    X(add,            1, 0,           0)          \
    X(and,            1, 0,           0)          \
    X(assign_ident,   1, ARG_BSTR,    0)          \
    X(assign_member,  1, ARG_BSTR,    0)          \
    X(bool,           1, ARG_INT,     0)          \
    X(concat,         1, 0,           0)          \
    X(div,            1, 0,           0)          \
    X(double,         1, ARG_DOUBLE,  0)          \
    X(empty,          1, 0,           0)          \
    X(equal,          1, 0,           0)          \
    X(errmode,        1, ARG_INT,     0)          \
    X(eqv,            1, 0,           0)          \
    X(exp,            1, 0,           0)          \
    X(gt,             1, 0,           0)          \
    X(gteq,           1, 0,           0)          \
    X(icall,          1, ARG_BSTR,    ARG_UINT)   \
    X(icallv,         1, ARG_BSTR,    ARG_UINT)   \
    X(idiv,           1, 0,           0)          \
    X(imp,            1, 0,           0)          \
    X(is,             1, 0,           0)          \
    X(jmp,            0, ARG_ADDR,    0)          \
    X(jmp_false,      0, ARG_ADDR,    0)          \
    X(jmp_true,       0, ARG_ADDR,    0)          \
    X(long,           1, ARG_INT,     0)          \
    X(lt,             1, 0,           0)          \
    X(lteq,           1, 0,           0)          \
    X(mcall,          1, ARG_BSTR,    ARG_UINT)   \
    X(mcallv,         1, ARG_BSTR,    ARG_UINT)   \
    X(me,             1, 0,           0)          \
    X(mod,            1, 0,           0)          \
    X(mul,            1, 0,           0)          \
    X(neg,            1, 0,           0)          \
    X(nequal,         1, 0,           0)          \
    X(new,            1, ARG_STR,     0)          \
    X(not,            1, 0,           0)          \
    X(nothing,        1, 0,           0)          \
    X(null,           1, 0,           0)          \
    X(or,             1, 0,           0)          \
    X(ret,            0, 0,           0)          \
    X(set_ident,      1, ARG_BSTR,    0)          \
    X(set_member,     1, ARG_BSTR,    0)          \
    X(short,          1, ARG_INT,     0)          \
    X(stop,           1, 0,           0)          \
    X(string,         1, ARG_STR,     0)          \
    X(sub,            1, 0,           0)          \
    X(xor,            1, 0,           0)

typedef enum {
#define X(x,n,a,b) OP_##x,
OP_LIST
#undef X
    OP_LAST
} vbsop_t;

typedef union {
    const WCHAR *str;
    BSTR bstr;
    unsigned uint;
    LONG lng;
    double *dbl;
} instr_arg_t;

typedef struct {
    vbsop_t op;
    instr_arg_t arg1;
    instr_arg_t arg2;
} instr_t;

typedef struct {
    const WCHAR *name;
    BOOL by_ref;
} arg_desc_t;

typedef enum {
    FUNC_GLOBAL,
    FUNC_FUNCTION,
    FUNC_SUB,
    FUNC_PROPGET,
    FUNC_PROPLET,
    FUNC_PROPSET,
    FUNC_DEFGET
} function_type_t;

typedef struct {
    const WCHAR *name;
} var_desc_t;

struct _function_t {
    function_type_t type;
    const WCHAR *name;
    BOOL is_public;
    arg_desc_t *args;
    unsigned arg_cnt;
    var_desc_t *vars;
    unsigned var_cnt;
    unsigned code_off;
    vbscode_t *code_ctx;
    function_t *next;
};

struct _vbscode_t {
    instr_t *instrs;
    WCHAR *source;

    BOOL option_explicit;

    BOOL global_executed;
    function_t global_code;

    BSTR *bstr_pool;
    unsigned bstr_pool_size;
    unsigned bstr_cnt;
    vbsheap_t heap;

    struct list entry;
};

void release_vbscode(vbscode_t*) DECLSPEC_HIDDEN;
HRESULT compile_script(script_ctx_t*,const WCHAR*,vbscode_t**) DECLSPEC_HIDDEN;
HRESULT exec_script(script_ctx_t*,function_t*,IDispatch*,DISPPARAMS*,VARIANT*) DECLSPEC_HIDDEN;

#define TID_LIST \
    XDIID(ErrObj) \
    XDIID(GlobalObj)

typedef enum {
#define XDIID(iface) iface ## _tid,
TID_LIST
#undef XDIID
    LAST_tid
} tid_t;

HRESULT get_typeinfo(tid_t,ITypeInfo**);

HRESULT WINAPI VBScriptFactory_CreateInstance(IClassFactory*,IUnknown*,REFIID,void**);

const char *debugstr_variant(const VARIANT*) DECLSPEC_HIDDEN;

static inline void *heap_alloc(size_t len)
{
    return HeapAlloc(GetProcessHeap(), 0, len);
}

static inline void *heap_alloc_zero(size_t len)
{
    return HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, len);
}

static inline void *heap_realloc(void *mem, size_t len)
{
    return HeapReAlloc(GetProcessHeap(), 0, mem, len);
}

static inline BOOL heap_free(void *mem)
{
    return HeapFree(GetProcessHeap(), 0, mem);
}

static inline LPWSTR heap_strdupW(LPCWSTR str)
{
    LPWSTR ret = NULL;

    if(str) {
        DWORD size;

        size = (strlenW(str)+1)*sizeof(WCHAR);
        ret = heap_alloc(size);
        if(ret)
            memcpy(ret, str, size);
    }

    return ret;
}

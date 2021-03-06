/*
 * hhctrl implementation
 *
 * Copyright 2004 Krzysztof Foltman
 * Copyright 2007 Jacek Caban for CodeWeavers
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

#include "wine/debug.h"

#include <stdarg.h>

#define COBJMACROS

#include "windef.h"
#include "winbase.h"
#include "winuser.h"
#include "winnls.h"
#include "htmlhelp.h"
#include "ole2.h"
#include "rpcproxy.h"

#define INIT_GUID
#include "hhctrl.h"

WINE_DEFAULT_DEBUG_CHANNEL(htmlhelp);

HINSTANCE hhctrl_hinstance;
BOOL hh_process = FALSE;

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID lpvReserved)
{
    TRACE("(%p,%d,%p)\n", hInstance, fdwReason, lpvReserved);

    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        hhctrl_hinstance = hInstance;
        DisableThreadLibraryCalls(hInstance);
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

static const char *command_to_string(UINT command)
{
#define X(x) case x: return #x
    switch (command)
    {
        X( HH_DISPLAY_TOPIC );
        X( HH_DISPLAY_TOC );
        X( HH_DISPLAY_INDEX );
        X( HH_DISPLAY_SEARCH );
        X( HH_SET_WIN_TYPE );
        X( HH_GET_WIN_TYPE );
        X( HH_GET_WIN_HANDLE );
        X( HH_ENUM_INFO_TYPE );
        X( HH_SET_INFO_TYPE );
        X( HH_SYNC );
        X( HH_RESERVED1 );
        X( HH_RESERVED2 );
        X( HH_RESERVED3 );
        X( HH_KEYWORD_LOOKUP );
        X( HH_DISPLAY_TEXT_POPUP );
        X( HH_HELP_CONTEXT );
        X( HH_TP_HELP_CONTEXTMENU );
        X( HH_TP_HELP_WM_HELP );
        X( HH_CLOSE_ALL );
        X( HH_ALINK_LOOKUP );
        X( HH_GET_LAST_ERROR );
        X( HH_ENUM_CATEGORY );
        X( HH_ENUM_CATEGORY_IT );
        X( HH_RESET_IT_FILTER );
        X( HH_SET_INCLUSIVE_FILTER );
        X( HH_SET_EXCLUSIVE_FILTER );
        X( HH_INITIALIZE );
        X( HH_UNINITIALIZE );
        X( HH_SAFE_DISPLAY_TOPIC );
        X( HH_PRETRANSLATEMESSAGE );
        X( HH_SET_GLOBAL_PROPERTY );
    default: return "???";
    }
#undef X
}

static BOOL resolve_filename(const WCHAR *filename, WCHAR *fullname, DWORD buflen, const WCHAR **index, const WCHAR **window)
{
    const WCHAR *extra;
    WCHAR chm_file[MAX_PATH];

    static const WCHAR helpW[] = {'\\','h','e','l','p','\\',0};
    static const WCHAR delimW[] = {':',':',0};
    static const WCHAR delim2W[] = {'>',0};

    filename = skip_schema(filename);

    /* the format is "helpFile[::/index][>window]" */
    if (index) *index = NULL;
    if (window) *window = NULL;

    extra = strstrW(filename, delim2W);
    if (extra)
    {
        memcpy(chm_file, filename, (extra-filename)*sizeof(WCHAR));
        chm_file[extra-filename] = 0;
        filename = chm_file;
        if (window)
            *window = strdupW(extra+1);
    }

    extra = strstrW(filename, delimW);
    if (extra)
    {
        if (filename != chm_file)
            memcpy(chm_file, filename, (extra-filename)*sizeof(WCHAR));
        chm_file[extra-filename] = 0;
        filename = chm_file;
        if (index)
            *index = strdupW(extra+2);
    }

    GetFullPathNameW(filename, buflen, fullname, NULL);
    if (GetFileAttributesW(fullname) == INVALID_FILE_ATTRIBUTES)
    {
        GetWindowsDirectoryW(fullname, buflen);
        strcatW(fullname, helpW);
        strcatW(fullname, filename);
    }
    return (GetFileAttributesW(fullname) != INVALID_FILE_ATTRIBUTES);
}

/******************************************************************
 *		HtmlHelpW (HHCTRL.OCX.15)
 */
HWND WINAPI HtmlHelpW(HWND caller, LPCWSTR filename, UINT command, DWORD_PTR data)
{
    WCHAR fullname[MAX_PATH];

    TRACE("(%p, %s, command=%s, data=%lx)\n",
          caller, debugstr_w( filename ),
          command_to_string( command ), data);

    switch (command)
    {
    case HH_DISPLAY_TOPIC:
    case HH_DISPLAY_TOC:
    case HH_DISPLAY_SEARCH:{
        HHInfo *info;
        BOOL res;
        const WCHAR *index = NULL;

        FIXME("Not all HH cases handled correctly\n");

        if (!filename)
            return NULL;

        if (!resolve_filename(filename, fullname, MAX_PATH, &index, NULL))
        {
            WARN("can't find %s\n", debugstr_w(filename));
            return 0;
        }

        info = CreateHelpViewer(fullname);
        if(!info)
            return NULL;

        if(!index)
            index = info->WinType.pszFile;

        res = NavigateToChm(info, info->pCHMInfo->szFile, index);

        if (index != info->WinType.pszFile)
            heap_free((WCHAR*)index);

        if(!res)
        {
            ReleaseHelpViewer(info);
            return NULL;
        }
        return info->WinType.hwndHelp;
    }
    case HH_HELP_CONTEXT: {
        HHInfo *info;
        LPWSTR url;

        if (!filename)
            return NULL;

        if (!resolve_filename(filename, fullname, MAX_PATH, NULL, NULL))
        {
            WARN("can't find %s\n", debugstr_w(filename));
            return 0;
        }

        info = CreateHelpViewer(fullname);
        if(!info)
            return NULL;

        url = FindContextAlias(info->pCHMInfo, data);
        if(!url)
        {
            ReleaseHelpViewer(info);
            return NULL;
        }

        NavigateToUrl(info, url);
        heap_free(url);
        return info->WinType.hwndHelp;
    }
    case HH_PRETRANSLATEMESSAGE: {
        static BOOL warned = FALSE;

        if (!warned)
        {
            FIXME("HH_PRETRANSLATEMESSAGE unimplemented\n");
            warned = TRUE;
        }
        return 0;
    }
    default:
        FIXME("HH case %s not handled.\n", command_to_string( command ));
    }

    return 0;
}

/******************************************************************
 *		HtmlHelpA (HHCTRL.OCX.14)
 */
HWND WINAPI HtmlHelpA(HWND caller, LPCSTR filename, UINT command, DWORD_PTR data)
{
    WCHAR *wfile = NULL, *wdata = NULL;
    DWORD len;
    HWND result;

    if (filename)
    {
        len = MultiByteToWideChar( CP_ACP, 0, filename, -1, NULL, 0 );
        wfile = heap_alloc(len*sizeof(WCHAR));
        MultiByteToWideChar( CP_ACP, 0, filename, -1, wfile, len );
    }

    if (data)
    {
        switch(command)
        {
        case HH_ALINK_LOOKUP:
        case HH_DISPLAY_SEARCH:
        case HH_DISPLAY_TEXT_POPUP:
        case HH_GET_LAST_ERROR:
        case HH_GET_WIN_TYPE:
        case HH_KEYWORD_LOOKUP:
        case HH_SET_WIN_TYPE:
        case HH_SYNC:
            FIXME("structures not handled yet\n");
            break;

        case HH_DISPLAY_INDEX:
        case HH_DISPLAY_TOPIC:
        case HH_DISPLAY_TOC:
        case HH_GET_WIN_HANDLE:
        case HH_SAFE_DISPLAY_TOPIC:
            len = MultiByteToWideChar( CP_ACP, 0, (const char*)data, -1, NULL, 0 );
            wdata = heap_alloc(len*sizeof(WCHAR));
            MultiByteToWideChar( CP_ACP, 0, (const char*)data, -1, wdata, len );
            break;

        case HH_CLOSE_ALL:
        case HH_HELP_CONTEXT:
        case HH_INITIALIZE:
        case HH_PRETRANSLATEMESSAGE:
        case HH_TP_HELP_CONTEXTMENU:
        case HH_TP_HELP_WM_HELP:
        case HH_UNINITIALIZE:
            /* either scalar or pointer to scalar - do nothing */
            break;

        default:
            FIXME("Unknown command: %s (%d)\n", command_to_string(command), command);
            break;
        }
    }

    result = HtmlHelpW( caller, wfile, command, wdata ? (DWORD_PTR)wdata : data );

    heap_free(wfile);
    heap_free(wdata);
    return result;
}

/******************************************************************
 *		doWinMain (HHCTRL.OCX.13)
 */
int WINAPI doWinMain(HINSTANCE hInstance, LPSTR szCmdLine)
{
    MSG msg;
    int len, buflen, mapid = -1;
    WCHAR *filename;
    char *endq = NULL;

    hh_process = TRUE;

    /* Parse command line option of the HTML Help command.
     *
     * Note: The only currently handled action is "mapid",
     *  which corresponds to opening a specific page.
     */
    while(*szCmdLine == '-')
    {
        LPSTR space, ptr;

        ptr = szCmdLine + 1;
        space = strchr(ptr, ' ');
        if(!strncmp(ptr, "mapid", space-ptr))
        {
            char idtxt[10];

            ptr += strlen("mapid")+1;
            space = strchr(ptr, ' ');
            /* command line ends without number */
            if (!space)
                return 0;
            memcpy(idtxt, ptr, space-ptr);
            idtxt[space-ptr] = '\0';
            mapid = atoi(idtxt);
            szCmdLine = space+1;
        }
        else
        {
            FIXME("Unhandled HTML Help command line parameter! (%.*s)\n", (int)(space-szCmdLine), szCmdLine);
            return 0;
        }
    }

    /* FIXME: Check szCmdLine for bad arguments */
    if (*szCmdLine == '\"')
        endq = strchr(++szCmdLine, '\"');

    if (endq)
        len = endq - szCmdLine;
    else
        len = strlen(szCmdLine);

    /* no filename given */
    if (!len)
        return 0;

    buflen = MultiByteToWideChar(CP_ACP, 0, szCmdLine, len, NULL, 0) + 1;
    filename = heap_alloc(buflen * sizeof(WCHAR));
    MultiByteToWideChar(CP_ACP, 0, szCmdLine, len, filename, buflen);
    filename[buflen-1] = 0;

    /* Open a specific help topic */
    if(mapid != -1)
        HtmlHelpW(GetDesktopWindow(), filename, HH_HELP_CONTEXT, mapid);
    else
        HtmlHelpW(GetDesktopWindow(), filename, HH_DISPLAY_TOPIC, 0);

    heap_free(filename);

    while (GetMessageW(&msg, 0, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    return 0;
}

/******************************************************************
 *		DllGetClassObject (HHCTRL.OCX.@)
 */
HRESULT WINAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID *ppv)
{
    FIXME("(%s %s %p)\n", debugstr_guid(rclsid), debugstr_guid(riid), ppv);
    return CLASS_E_CLASSNOTAVAILABLE;
}

/***********************************************************************
 *		DllRegisterServer (HHCTRL.OCX.@)
 */
HRESULT WINAPI DllRegisterServer(void)
{
    return __wine_register_resources( hhctrl_hinstance );
}

/***********************************************************************
 *		DllUnregisterServer (HHCTRL.OCX.@)
 */
HRESULT WINAPI DllUnregisterServer(void)
{
    return __wine_unregister_resources( hhctrl_hinstance );
}

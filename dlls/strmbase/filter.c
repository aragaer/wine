/*
 * Generic Implementation of IBaseFilter Interface
 *
 * Copyright 2010 Aric Stewart, CodeWeavers
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

#define COBJMACROS

#include "dshow.h"
#include "wine/debug.h"
#include "wine/unicode.h"
#include "wine/strmbase.h"
#include "uuids.h"
#include <assert.h>

WINE_DEFAULT_DEBUG_CHANNEL(strmbase);

HRESULT WINAPI BaseFilterImpl_QueryInterface(IBaseFilter * iface, REFIID riid, LPVOID * ppv)
{
    BaseFilter *This = (BaseFilter *)iface;
    TRACE("(%p)->(%s, %p)\n", iface, debugstr_guid(riid), ppv);

    *ppv = NULL;

    if (IsEqualIID(riid, &IID_IUnknown))
        *ppv = This;
    else if (IsEqualIID(riid, &IID_IPersist))
        *ppv = This;
    else if (IsEqualIID(riid, &IID_IMediaFilter))
        *ppv = This;
    else if (IsEqualIID(riid, &IID_IBaseFilter))
        *ppv = This;

    if (*ppv)
    {
        IUnknown_AddRef((IUnknown *)(*ppv));
        return S_OK;
    }

    return E_NOINTERFACE;
}

ULONG WINAPI BaseFilterImpl_AddRef(IBaseFilter * iface)
{
    BaseFilter *This = (BaseFilter*)iface;
    ULONG refCount = InterlockedIncrement(&This->refCount);

    TRACE("(%p)->() AddRef from %d\n", This, refCount - 1);

    return refCount;
}

ULONG WINAPI BaseFilterImpl_Release(IBaseFilter * iface)
{
    BaseFilter *This = (BaseFilter *)iface;
    ULONG refCount = InterlockedDecrement(&This->refCount);

    TRACE("(%p)->() Release from %d\n", This, refCount + 1);

    if (!refCount)
    {
        if (This->pClock)
            IReferenceClock_Release(This->pClock);

        This->lpVtbl = NULL;
        This->csFilter.DebugInfo->Spare[0] = 0;
        DeleteCriticalSection(&This->csFilter);
    }

    return refCount;
}

HRESULT WINAPI BaseFilterImpl_GetClassID(IBaseFilter * iface, CLSID * pClsid)
{
    BaseFilter *This = (BaseFilter*)iface;
    TRACE("(%p)->(%p)\n", This, pClsid);

    *pClsid = This->clsid;

    return S_OK;
}

HRESULT WINAPI BaseFilterImpl_GetState(IBaseFilter * iface, DWORD dwMilliSecsTimeout, FILTER_STATE *pState )
{
    BaseFilter *This = (BaseFilter*)iface;
    TRACE("(%p)->(%d, %p)\n", This, dwMilliSecsTimeout, pState);

    EnterCriticalSection(&This->csFilter);
    {
        *pState = This->state;
    }
    LeaveCriticalSection(&This->csFilter);

    return S_OK;
}

HRESULT WINAPI BaseFilterImpl_SetSyncSource(IBaseFilter * iface, IReferenceClock *pClock)
{
    BaseFilter *This = (BaseFilter*)iface;
    TRACE("(%p)->(%p)\n", This, pClock);

    EnterCriticalSection(&This->csFilter);
    {
        if (This->pClock)
            IReferenceClock_Release(This->pClock);
        This->pClock = pClock;
        if (This->pClock)
            IReferenceClock_AddRef(This->pClock);
    }
    LeaveCriticalSection(&This->csFilter);

    return S_OK;
}

HRESULT WINAPI BaseFilterImpl_GetSyncSource(IBaseFilter * iface, IReferenceClock **ppClock)
{
    BaseFilter *This = (BaseFilter*)iface;
    TRACE("(%p)->(%p)\n", This, ppClock);

    EnterCriticalSection(&This->csFilter);
    {
        *ppClock = This->pClock;
        if (This->pClock)
            IReferenceClock_AddRef(This->pClock);
    }
    LeaveCriticalSection(&This->csFilter);

    return S_OK;
}

HRESULT WINAPI BaseFilterImpl_EnumPins(IBaseFilter * iface, IEnumPins **ppEnum)
{
    BaseFilter *This = (BaseFilter*)iface;

    TRACE("(%p)->(%p)\n", iface, ppEnum);

    return EnumPins_Construct(This, This->pFuncsTable->pfnGetPin, This->pFuncsTable->pfnGetPinCount, BaseFilterImpl_GetPinVersion, ppEnum);
}


HRESULT WINAPI BaseFilterImpl_QueryFilterInfo(IBaseFilter * iface, FILTER_INFO *pInfo)
{
    BaseFilter *This = (BaseFilter*)iface;
    TRACE("(%p)->(%p)\n", This, pInfo);

    strcpyW(pInfo->achName, This->filterInfo.achName);
    pInfo->pGraph = This->filterInfo.pGraph;

    if (pInfo->pGraph)
        IFilterGraph_AddRef(pInfo->pGraph);

    return S_OK;
}

HRESULT WINAPI BaseFilterImpl_JoinFilterGraph(IBaseFilter * iface, IFilterGraph *pGraph, LPCWSTR pName )
{
    HRESULT hr = S_OK;
    BaseFilter *This = (BaseFilter*)iface;

    TRACE("(%p)->(%p, %s)\n", This, pGraph, debugstr_w(pName));

    EnterCriticalSection(&This->csFilter);
    {
        if (pName)
            strcpyW(This->filterInfo.achName, pName);
        else
            *This->filterInfo.achName = '\0';
        This->filterInfo.pGraph = pGraph; /* NOTE: do NOT increase ref. count */
    }
    LeaveCriticalSection(&This->csFilter);

    return hr;
}

HRESULT WINAPI BaseFilterImpl_QueryVendorInfo(IBaseFilter * iface, LPWSTR *pVendorInfo)
{
    TRACE("(%p)->(%p)\n", iface, pVendorInfo);
    return E_NOTIMPL;
}

LONG WINAPI BaseFilterImpl_GetPinVersion(BaseFilter * This)
{
    TRACE("(%p)\n", This);
    return This->pinVersion;
}

VOID WINAPI BaseFilterImpl_IncrementPinVersion(BaseFilter * This)
{
    InterlockedIncrement(&This->pinVersion);
    TRACE("(%p) -> New pinVersion %i\n", This,This->pinVersion);
}

HRESULT WINAPI BaseFilter_Init(BaseFilter * This, const IBaseFilterVtbl *Vtbl, const CLSID *pClsid, DWORD_PTR DebugInfo, const BaseFilterFuncTable* pBaseFuncsTable)
{
    This->lpVtbl = Vtbl;
    This->refCount = 1;
    InitializeCriticalSection(&This->csFilter);
    This->state = State_Stopped;
    This->rtStreamStart = 0;
    This->pClock = NULL;
    ZeroMemory(&This->filterInfo, sizeof(FILTER_INFO));
    This->clsid = *pClsid;
    This->csFilter.DebugInfo->Spare[0] = DebugInfo;
    This->pinVersion = 1;

    This->pFuncsTable = pBaseFuncsTable;

    return S_OK;
}
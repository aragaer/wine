/*
 * Copyright 2002 Andriy Palamarchuk
 *
 * netapi32 internal functions.
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
 * License along with this library; if not, writ
e to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef __WINE_NETAPI32_MISC_H
#define __WINE_NETAPI32_MISC_H

extern BOOL NETAPI_IsLocalComputer(LPCWSTR ServerName);

#define NETAPI_ForceLocalComputer(ServerName, FailureCode) \
    if (!NETAPI_IsLocalComputer(ServerName)) \
    { \
        FIXME("Action Implemented for local computer only. " \
              "Requested for server %s\n", debugstr_w(ServerName)); \
        return FailureCode; \
    }

#endif

/***
  This file is part of systemd.

  Copyright 2014 Zbigniew Jędrzejewski-Szmek

  systemd is free software; you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  systemd is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with systemd; If not, see <http://www.gnu.org/licenses/>.
***/

#include <errno.h>

#include "sd-bus.h"

#include "bus-common-errors.h"
#include "bus-error.h"

BUS_ERROR_MAP_ELF_REGISTER const sd_bus_error_map bus_common_errors[] = {
#if 0 /// UNNEEDED by elogind
        SD_BUS_ERROR_MAP(BUS_ERROR_NO_SUCH_UNIT,                 ENOENT),
        SD_BUS_ERROR_MAP(BUS_ERROR_NO_UNIT_FOR_PID,              ESRCH),
        SD_BUS_ERROR_MAP(BUS_ERROR_NO_UNIT_FOR_INVOCATION_ID,    ENOENT),
        SD_BUS_ERROR_MAP(BUS_ERROR_UNIT_EXISTS,                  EEXIST),
        SD_BUS_ERROR_MAP(BUS_ERROR_LOAD_FAILED,                  EIO),
        SD_BUS_ERROR_MAP(BUS_ERROR_JOB_FAILED,                   EREMOTEIO),
        SD_BUS_ERROR_MAP(BUS_ERROR_NO_SUCH_JOB,                  ENOENT),
        SD_BUS_ERROR_MAP(BUS_ERROR_NOT_SUBSCRIBED,               EINVAL),
        SD_BUS_ERROR_MAP(BUS_ERROR_ALREADY_SUBSCRIBED,           EINVAL),
        SD_BUS_ERROR_MAP(BUS_ERROR_ONLY_BY_DEPENDENCY,           EINVAL),
        SD_BUS_ERROR_MAP(BUS_ERROR_TRANSACTION_JOBS_CONFLICTING, EDEADLK),
        SD_BUS_ERROR_MAP(BUS_ERROR_TRANSACTION_ORDER_IS_CYCLIC,  EDEADLK),
        SD_BUS_ERROR_MAP(BUS_ERROR_TRANSACTION_IS_DESTRUCTIVE,   EDEADLK),
        SD_BUS_ERROR_MAP(BUS_ERROR_UNIT_MASKED,                  ERFKILL),
        SD_BUS_ERROR_MAP(BUS_ERROR_UNIT_GENERATED,               EADDRNOTAVAIL),
        SD_BUS_ERROR_MAP(BUS_ERROR_UNIT_LINKED,                  ELOOP),
        SD_BUS_ERROR_MAP(BUS_ERROR_JOB_TYPE_NOT_APPLICABLE,      EBADR),
        SD_BUS_ERROR_MAP(BUS_ERROR_NO_ISOLATION,                 EPERM),
        SD_BUS_ERROR_MAP(BUS_ERROR_SHUTTING_DOWN,                ECANCELED),
        SD_BUS_ERROR_MAP(BUS_ERROR_SCOPE_NOT_RUNNING,            EHOSTDOWN),
        SD_BUS_ERROR_MAP(BUS_ERROR_NO_SUCH_DYNAMIC_USER,         ESRCH),
        SD_BUS_ERROR_MAP(BUS_ERROR_NOT_REFERENCED,               EUNATCH),
        SD_BUS_ERROR_MAP(BUS_ERROR_DISK_FULL,                    ENOSPC),

        SD_BUS_ERROR_MAP(BUS_ERROR_NO_SUCH_MACHINE,              ENXIO),
        SD_BUS_ERROR_MAP(BUS_ERROR_NO_SUCH_IMAGE,                ENOENT),
        SD_BUS_ERROR_MAP(BUS_ERROR_NO_MACHINE_FOR_PID,           ENXIO),
        SD_BUS_ERROR_MAP(BUS_ERROR_MACHINE_EXISTS,               EEXIST),
        SD_BUS_ERROR_MAP(BUS_ERROR_NO_PRIVATE_NETWORKING,        ENOSYS),
        SD_BUS_ERROR_MAP(BUS_ERROR_NO_SUCH_USER_MAPPING,         ENXIO),
        SD_BUS_ERROR_MAP(BUS_ERROR_NO_SUCH_GROUP_MAPPING,        ENXIO),
#endif // 0

        SD_BUS_ERROR_MAP(BUS_ERROR_NO_SUCH_SESSION,              ENXIO),
        SD_BUS_ERROR_MAP(BUS_ERROR_NO_SESSION_FOR_PID,           ENXIO),
        SD_BUS_ERROR_MAP(BUS_ERROR_NO_SUCH_USER,                 ENXIO),
        SD_BUS_ERROR_MAP(BUS_ERROR_NO_USER_FOR_PID,              ENXIO),
        SD_BUS_ERROR_MAP(BUS_ERROR_NO_SUCH_SEAT,                 ENXIO),
        SD_BUS_ERROR_MAP(BUS_ERROR_SESSION_NOT_ON_SEAT,          EINVAL),
        SD_BUS_ERROR_MAP(BUS_ERROR_NOT_IN_CONTROL,               EINVAL),
        SD_BUS_ERROR_MAP(BUS_ERROR_DEVICE_IS_TAKEN,              EINVAL),
        SD_BUS_ERROR_MAP(BUS_ERROR_DEVICE_NOT_TAKEN,             EINVAL),
        SD_BUS_ERROR_MAP(BUS_ERROR_OPERATION_IN_PROGRESS,        EINPROGRESS),
        SD_BUS_ERROR_MAP(BUS_ERROR_SLEEP_VERB_NOT_SUPPORTED,     EOPNOTSUPP),
        SD_BUS_ERROR_MAP(BUS_ERROR_SESSION_BUSY,                 EBUSY),

#if 0 /// UNNEEDED by elogind
        SD_BUS_ERROR_MAP(BUS_ERROR_AUTOMATIC_TIME_SYNC_ENABLED,  EALREADY),

        SD_BUS_ERROR_MAP(BUS_ERROR_NO_SUCH_PROCESS,              ESRCH),

        SD_BUS_ERROR_MAP(BUS_ERROR_NO_NAME_SERVERS,              ESRCH),
        SD_BUS_ERROR_MAP(BUS_ERROR_INVALID_REPLY,                EINVAL),
        SD_BUS_ERROR_MAP(BUS_ERROR_NO_SUCH_RR,                   ENOENT),
        SD_BUS_ERROR_MAP(BUS_ERROR_CNAME_LOOP,                   EDEADLK),
        SD_BUS_ERROR_MAP(BUS_ERROR_ABORTED,                      ECANCELED),
        SD_BUS_ERROR_MAP(BUS_ERROR_NO_SUCH_SERVICE,              EUNATCH),
        SD_BUS_ERROR_MAP(BUS_ERROR_DNSSEC_FAILED,                EHOSTUNREACH),
        SD_BUS_ERROR_MAP(BUS_ERROR_NO_TRUST_ANCHOR,              EHOSTUNREACH),
        SD_BUS_ERROR_MAP(BUS_ERROR_RR_TYPE_UNSUPPORTED,          EOPNOTSUPP),
        SD_BUS_ERROR_MAP(BUS_ERROR_NO_SUCH_LINK,                 ENXIO),
        SD_BUS_ERROR_MAP(BUS_ERROR_LINK_BUSY,                    EBUSY),
        SD_BUS_ERROR_MAP(BUS_ERROR_NETWORK_DOWN,                 ENETDOWN),

        SD_BUS_ERROR_MAP(_BUS_ERROR_DNS "FORMERR",               EBADMSG),
        SD_BUS_ERROR_MAP(_BUS_ERROR_DNS "SERVFAIL",              EHOSTDOWN),
        SD_BUS_ERROR_MAP(_BUS_ERROR_DNS "NXDOMAIN",              ENXIO),
        SD_BUS_ERROR_MAP(_BUS_ERROR_DNS "NOTIMP",                ENOSYS),
        SD_BUS_ERROR_MAP(_BUS_ERROR_DNS "REFUSED",               EACCES),
        SD_BUS_ERROR_MAP(_BUS_ERROR_DNS "YXDOMAIN",              EEXIST),
        SD_BUS_ERROR_MAP(_BUS_ERROR_DNS "YRRSET",                EEXIST),
        SD_BUS_ERROR_MAP(_BUS_ERROR_DNS "NXRRSET",               ENOENT),
        SD_BUS_ERROR_MAP(_BUS_ERROR_DNS "NOTAUTH",               EACCES),
        SD_BUS_ERROR_MAP(_BUS_ERROR_DNS "NOTZONE",               EREMOTE),
        SD_BUS_ERROR_MAP(_BUS_ERROR_DNS "BADVERS",               EBADMSG),
        SD_BUS_ERROR_MAP(_BUS_ERROR_DNS "BADKEY",                EKEYREJECTED),
        SD_BUS_ERROR_MAP(_BUS_ERROR_DNS "BADTIME",               EBADMSG),
        SD_BUS_ERROR_MAP(_BUS_ERROR_DNS "BADMODE",               EBADMSG),
        SD_BUS_ERROR_MAP(_BUS_ERROR_DNS "BADNAME",               EBADMSG),
        SD_BUS_ERROR_MAP(_BUS_ERROR_DNS "BADALG",                EBADMSG),
        SD_BUS_ERROR_MAP(_BUS_ERROR_DNS "BADTRUNC",              EBADMSG),
        SD_BUS_ERROR_MAP(_BUS_ERROR_DNS "BADCOOKIE",             EBADR),

        SD_BUS_ERROR_MAP(BUS_ERROR_NO_SUCH_TRANSFER,             ENXIO),
        SD_BUS_ERROR_MAP(BUS_ERROR_TRANSFER_IN_PROGRESS,         EBUSY),
#endif // 0

        SD_BUS_ERROR_MAP_END
};

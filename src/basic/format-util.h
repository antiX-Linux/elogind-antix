#pragma once

/***
  This file is part of systemd.

  Copyright 2015 Ronny Chevalier

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

#include <inttypes.h>

#if SIZEOF_PID_T == 4
#  define PID_PRI PRIi32
#elif SIZEOF_PID_T == 2
#  define PID_PRI PRIi16
#else
#  error Unknown pid_t size
#endif
#define PID_FMT "%" PID_PRI

#if SIZEOF_UID_T == 4
#  define UID_FMT "%" PRIu32
#elif SIZEOF_UID_T == 2
#  define UID_FMT "%" PRIu16
#else
#  error Unknown uid_t size
#endif

#if SIZEOF_GID_T == 4
#  define GID_FMT "%" PRIu32
#elif SIZEOF_GID_T == 2
#  define GID_FMT "%" PRIu16
#else
#  error Unknown gid_t size
#endif

#if SIZEOF_TIME_T == 8
#  define PRI_TIME PRIi64
#elif SIZEOF_TIME_T == 4
#  define PRI_TIME "li"
#else
#  error Unknown time_t size
#endif

#if defined __x86_64__ && defined __ILP32__
#  define PRI_TIMEX PRIi64
#else
#  define PRI_TIMEX "li"
#endif

#if SIZEOF_RLIM_T == 8
#  define RLIM_FMT "%" PRIu64
#elif SIZEOF_RLIM_T == 4
#  define RLIM_FMT "%" PRIu32
#else
#  error Unknown rlim_t size
#endif

#if SIZEOF_DEV_T == 8
#  define DEV_FMT "%" PRIu64
#elif SIZEOF_DEV_T == 4
#  define DEV_FMT "%" PRIu32
#else
#  error Unknown dev_t size
#endif

#if SIZEOF_INO_T == 8
#  define INO_FMT "%" PRIu64
#elif SIZEOF_INO_T == 4
#  define INO_FMT "%" PRIu32
#else
#  error Unknown ino_t size
#endif

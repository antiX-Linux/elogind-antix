#pragma once

/***
  This file is part of systemd.

  Copyright 2010 Lennart Poettering

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

#include "util.h"

#define DEFAULT_TIMEOUT_USEC (90*USEC_PER_SEC)
#define DEFAULT_RESTART_USEC (100*USEC_PER_MSEC)
#define DEFAULT_CONFIRM_USEC (30*USEC_PER_SEC)

#define DEFAULT_START_LIMIT_INTERVAL (10*USEC_PER_SEC)
#define DEFAULT_START_LIMIT_BURST 5

/* The default time after which exit-on-idle services exit. This
 * should be kept lower than the watchdog timeout, because otherwise
 * the watchdog pings will keep the loop busy. */
#define DEFAULT_EXIT_USEC (30*USEC_PER_SEC)

/* The default value for the net.unix.max_dgram_qlen sysctl */
#define DEFAULT_UNIX_MAX_DGRAM_QLEN 512UL

#if 0 /// elogind allows foreign cgroup controllers. (Well, needs them, actually)
#define SYSTEMD_CGROUP_CONTROLLER_LEGACY "name=systemd"
#define SYSTEMD_CGROUP_CONTROLLER_HYBRID "name=unified"
#define SYSTEMD_CGROUP_CONTROLLER "_systemd"
#else
#ifndef SYSTEMD_CGROUP_CONTROLLER_LEGACY
#  define SYSTEMD_CGROUP_CONTROLLER_LEGACY "name=elogind"
#endif // SYSTEMD_CGROUP_CONTROLLER_LEGACY
#ifndef SYSTEMD_CGROUP_CONTROLLER_HYBRID
#  define SYSTEMD_CGROUP_CONTROLLER_HYBRID "name=elogind"
#endif // SYSTEMD_CGROUP_CONTROLLER_HYBRID
#ifndef SYSTEMD_CGROUP_CONTROLLER
#  define SYSTEMD_CGROUP_CONTROLLER "_elogind"
#endif // SYSTEMD_CGROUP_CONTROLLER
#endif // 0

#define SIGNALS_CRASH_HANDLER SIGSEGV,SIGILL,SIGFPE,SIGBUS,SIGQUIT,SIGABRT
#define SIGNALS_IGNORE SIGPIPE

#ifdef HAVE_SPLIT_USR
#define KBD_KEYMAP_DIRS                         \
        "/usr/share/keymaps/\0"                 \
        "/usr/share/kbd/keymaps/\0"             \
        "/usr/lib/kbd/keymaps/\0"               \
        "/lib/kbd/keymaps/\0"
#else
#define KBD_KEYMAP_DIRS                         \
        "/usr/share/keymaps/\0"                 \
        "/usr/share/kbd/keymaps/\0"             \
        "/usr/lib/kbd/keymaps/\0"
#endif

#define UNIX_SYSTEM_BUS_ADDRESS "unix:path=/var/run/dbus/system_bus_socket"
#define KERNEL_SYSTEM_BUS_ADDRESS "kernel:path=/sys/fs/kdbus/0-system/bus"
#define DEFAULT_SYSTEM_BUS_ADDRESS KERNEL_SYSTEM_BUS_ADDRESS ";" UNIX_SYSTEM_BUS_ADDRESS
#define UNIX_USER_BUS_ADDRESS_FMT "unix:path=%s/bus"
#define KERNEL_USER_BUS_ADDRESS_FMT "kernel:path=/sys/fs/kdbus/"UID_FMT"-user/bus"

#define PLYMOUTH_SOCKET {                                       \
                .un.sun_family = AF_UNIX,                       \
                .un.sun_path = "\0/org/freedesktop/plymouthd",  \
        }

#define NOTIFY_FD_MAX 768
#define NOTIFY_BUFFER_MAX PIPE_BUF

#ifdef HAVE_SPLIT_USR
#  define _CONF_PATHS_SPLIT_USR(n) "/lib/" n "\0"
#else
#  define _CONF_PATHS_SPLIT_USR(n)
#endif

/* Return a nulstr for a standard cascade of configuration paths,
 * suitable to pass to conf_files_list_nulstr() or config_parse_many_nulstr()
 * to implement drop-in directories for extending configuration
 * files. */
#define CONF_PATHS_NULSTR(n)                    \
        "/etc/" n "\0"                          \
        "/run/" n "\0"                          \
        "/usr/local/lib/" n "\0"                \
        "/usr/lib/" n "\0"                      \
        _CONF_PATHS_SPLIT_USR(n)

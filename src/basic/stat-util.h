#pragma once

/***
  This file is part of systemd.

  Copyright 2010-2012 Lennart Poettering

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

#include <stdbool.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/statfs.h>
#include <sys/types.h>
#include <sys/vfs.h>

#include "macro.h"

#if 0 /// UNNEEDED by elogind
int is_symlink(const char *path);
#endif // 0
int is_dir(const char *path, bool follow);
#if 0 /// UNNEEDED by elogind
int is_device_node(const char *path);

int dir_is_empty(const char *path);

static inline int dir_is_populated(const char *path) {
        int r;
        r = dir_is_empty(path);
        if (r < 0)
                return r;
        return !r;
}
#endif // 0

bool null_or_empty(struct stat *st) _pure_;
int null_or_empty_path(const char *fn);
#if 0 /// UNNEEDED by elogind
int null_or_empty_fd(int fd);
#endif // 0

int path_is_read_only_fs(const char *path);
#if 0 /// UNNEEDED by elogind
int path_is_os_tree(const char *path);
#endif // 0

int files_same(const char *filea, const char *fileb, int flags);

/* The .f_type field of struct statfs is really weird defined on
 * different archs. Let's give its type a name. */
typedef typeof(((struct statfs*)NULL)->f_type) statfs_f_type_t;

bool is_fs_type(const struct statfs *s, statfs_f_type_t magic_value) _pure_;
#if 0 /// UNNEEDED by elogind
int fd_check_fstype(int fd, statfs_f_type_t magic_value);
int path_check_fstype(const char *path, statfs_f_type_t magic_value);
#endif // 0

bool is_temporary_fs(const struct statfs *s) _pure_;
#if 0 /// UNNEEDED by elogind
int fd_is_temporary_fs(int fd);
int path_is_temporary_fs(const char *path);
#endif // 0

/* Because statfs.t_type can be int on some architectures, we have to cast
 * the const magic to the type, otherwise the compiler warns about
 * signed/unsigned comparison, because the magic can be 32 bit unsigned.
 */
#define F_TYPE_EQUAL(a, b) (a == (typeof(a)) b)

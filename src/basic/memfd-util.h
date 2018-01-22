#pragma once

/***
  This file is part of systemd.

  Copyright 2013 Lennart Poettering

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
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

int memfd_new(const char *name);
#if 0 /// UNNEEDED by elogind
int memfd_new_and_map(const char *name, size_t sz, void **p);

int memfd_map(int fd, uint64_t offset, size_t size, void **p);
#endif // 0

int memfd_set_sealed(int fd);
#if 0 /// UNNEEDED by elogind
int memfd_get_sealed(int fd);
#endif // 0

int memfd_get_size(int fd, uint64_t *sz);
int memfd_set_size(int fd, uint64_t sz);

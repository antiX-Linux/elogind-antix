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

#include "macro.h"

int bus_gvariant_get_size(const char *signature) _pure_;
int bus_gvariant_get_alignment(const char *signature) _pure_;
int bus_gvariant_is_fixed_size(const char *signature) _pure_;

size_t bus_gvariant_determine_word_size(size_t sz, size_t extra);
void bus_gvariant_write_word_le(void *p, size_t sz, size_t value);
size_t bus_gvariant_read_word_le(void *p, size_t sz);

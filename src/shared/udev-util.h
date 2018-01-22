#pragma once

/***
  This file is part of systemd.

  Copyright 2013 Zbigniew Jędrzejewski-Szmek

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

#if 0 /// elogind needs the systems udev header
#include "udev.h"
#else
#include <libudev.h>
#endif // 0
#include "util.h"

DEFINE_TRIVIAL_CLEANUP_FUNC(struct udev*, udev_unref);
DEFINE_TRIVIAL_CLEANUP_FUNC(struct udev_device*, udev_device_unref);
DEFINE_TRIVIAL_CLEANUP_FUNC(struct udev_enumerate*, udev_enumerate_unref);
#if 0 /// UNNEEDED by elogind
DEFINE_TRIVIAL_CLEANUP_FUNC(struct udev_event*, udev_event_unref);
DEFINE_TRIVIAL_CLEANUP_FUNC(struct udev_rules*, udev_rules_unref);
DEFINE_TRIVIAL_CLEANUP_FUNC(struct udev_ctrl*, udev_ctrl_unref);
DEFINE_TRIVIAL_CLEANUP_FUNC(struct udev_ctrl_connection*, udev_ctrl_connection_unref);
DEFINE_TRIVIAL_CLEANUP_FUNC(struct udev_ctrl_msg*, udev_ctrl_msg_unref);
#endif // 0
DEFINE_TRIVIAL_CLEANUP_FUNC(struct udev_monitor*, udev_monitor_unref);

#define _cleanup_udev_unref_ _cleanup_(udev_unrefp)
#define _cleanup_udev_device_unref_ _cleanup_(udev_device_unrefp)
#define _cleanup_udev_enumerate_unref_ _cleanup_(udev_enumerate_unrefp)
#if 0 /// UNNEEDED by elogind
#define _cleanup_udev_event_unref_ _cleanup_(udev_event_unrefp)
#define _cleanup_udev_rules_unref_ _cleanup_(udev_rules_unrefp)
#define _cleanup_udev_ctrl_unref_ _cleanup_(udev_ctrl_unrefp)
#define _cleanup_udev_ctrl_connection_unref_ _cleanup_(udev_ctrl_connection_unrefp)
#define _cleanup_udev_ctrl_msg_unref_ _cleanup_(udev_ctrl_msg_unrefp)
#endif // 0
#define _cleanup_udev_monitor_unref_ _cleanup_(udev_monitor_unrefp)
#define _cleanup_udev_list_cleanup_ _cleanup_(udev_list_cleanup)

int udev_parse_config(void);

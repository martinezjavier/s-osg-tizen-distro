#
# Copyright (C) 2007 OpenedHand Ltd.
#

DESCRIPTON = "Gnome Mobile And Embedded Software Development Kit for OpenedHand Poky"
PR = "r6"

ALLOW_EMPTY = "1"

require task-sdk-gmae.inc

PACKAGES = "${PN}"

RDEPENDS = "\
    task-poky-standalone-sdk-target \
    libglade-dev \
    ${SDK-GMAE}"

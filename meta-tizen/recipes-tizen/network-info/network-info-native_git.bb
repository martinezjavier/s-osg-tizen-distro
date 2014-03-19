require network-info.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/network-info;protocol=ssh;tag=ef4e98a2c9187bf5801515e2e4c2388d49b34aa5;nobranch=1"


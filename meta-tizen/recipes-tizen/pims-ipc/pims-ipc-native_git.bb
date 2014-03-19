require pims-ipc.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/pim/pims-ipc;protocol=ssh;tag=9300ed95d75b0d3c6dc0805d60f08eff7fc907a2;nobranch=1"


require libslp-sensor.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/libslp-sensor;protocol=ssh;tag=0b466302afcb0ce0e23f0d8f1e1e9820e42326dc;nobranch=1"


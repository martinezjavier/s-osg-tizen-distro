require wifi-direct.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/wifi-direct;protocol=ssh;tag=6b4dc140b3c126667d75fb577ccf6bcbbe184244;nobranch=1"


require bluetooth-tools.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/connectivity/bluetooth-tools;protocol=ssh;tag=896de069d8c212e32bf966ffb9adaddf8e1dd402;nobranch=1"


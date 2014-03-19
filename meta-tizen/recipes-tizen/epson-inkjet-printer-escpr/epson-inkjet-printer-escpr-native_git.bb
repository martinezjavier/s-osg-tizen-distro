require epson-inkjet-printer-escpr.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/epson-inkjet-printer-escpr;protocol=ssh;tag=9b22142658537888edbf61a547e8401fad1b1a57;nobranch=1"


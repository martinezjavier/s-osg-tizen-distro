require openconnect.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/openconnect;protocol=ssh;tag=438d487626a37f1d4e5c1430328220bce5efb35e;nobranch=1"


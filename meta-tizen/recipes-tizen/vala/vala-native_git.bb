require vala.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/vala;protocol=ssh;tag=d62c06f6ce6bd5f636e2d8cbdb1e62ff5b715a17;nobranch=1"


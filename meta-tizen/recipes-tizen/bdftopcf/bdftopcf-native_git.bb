require bdftopcf.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/bdftopcf;protocol=ssh;tag=754ca93eb8f482ff7341153b370b7afca41af6a7;nobranch=1"


require iptables.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/iptables;protocol=ssh;tag=338375bf5a7efe75a50044aa9ce0a7118cf4b81f;nobranch=1"


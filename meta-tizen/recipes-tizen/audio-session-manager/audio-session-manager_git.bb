require audio-session-manager.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/audio-session-manager;protocol=ssh;tag=9226f6a77ba5b3a466ff7113479cab7cff770788;nobranch=1"


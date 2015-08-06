SUMMARY = "v4l2 and IR applications"
LICENSE = "GPLv2 & LGPLv2.1"
LIC_FILES_CHKSUM = "file://COPYING;md5=48da9957849056017dc568bbc43d8975 \
                    file://COPYING.libv4l;md5=d749e86a105281d7a44c2328acebc4b0"

DEPENDS = "jpeg \
           ${@base_contains('DISTRO_FEATURES', 'x11', 'virtual/libx11', '', d)}"

inherit autotools gettext pkgconfig

# libv4l was absorbed into this, let OE know that
PROVIDES = "libv4l"

SRC_URI = "http://linuxtv.org/downloads/v4l-utils/v4l-utils-${PV}.tar.bz2"
SRC_URI += "file://0001-add-support-for-qt5.patch"

SRC_URI[md5sum] = "9cb3c178f937954e65bf30920af433ef"
SRC_URI[sha256sum] = "d3d6eb1f0204fb11f3d318bfca35d5f73cc077f88fac7665a47856a16496be7d"

EXTRA_OECONF = " --enable-shared --with-udevdir=${base_libdir}/udev"

PACKAGES =+ "rc-keymaps libv4l libv4l-dbg libv4l-dev qv4l2"

PACKAGECONFIG ?= "${@base_contains('BBFILE_COLLECTIONS', 'qt5-layer', 'qv4l2', '', d)}"

PACKAGECONFIG[qv4l2] = ",--disable-qv4l2,qtbase"

FILES_rc-keymaps = "${sysconfdir}/rc* ${base_libdir}/udev/rc*"
FILES_${PN} = "${bindir} ${sbindir} ${base_libdir}/udev/rules.d/70-infrared.rules"
FILES_libv4l += "${libdir}/libv4l*${SOLIBS} ${libdir}/libv4l/*.so \
                 ${libdir}/libdvbv5*${SOLIBS} \
                 ${libdir}/libv4l/plugins/*.so \
                 ${libdir}/libv4l/*-decomp"
FILES_libv4l-dbg += "${libdir}/libv4l/.debug ${libdir}/libv4l/plugins/.debug"
FILES_libv4l-dev += "${libdir}/v4l*${SOLIBSDEV} ${libdir}/libv4l/*.la ${libdir}/libv4l/plugins/*.la"
FILES_qv4l2 += "${bindir}/qv4l2 \
		${datadir}/icons/hicolor/*/apps/qv4l2.* \
		${datadir}/applications/qv4l2.desktop"

do_configure_prepend() {
    sed -i -e 's:UIC=${QT_PATH}:UIC=${STAGING_DIR_NATIVE}${QT_PATH}:g' ${S}/configure.ac
    sed -i -e 's:MOC=${QT_PATH}:MOC=${STAGING_DIR_NATIVE}${QT_PATH}:g' ${S}/configure.ac
    sed -i -e 's:RCC=${QT_PATH}:RCC=${STAGING_DIR_NATIVE}${QT_PATH}:g' ${S}/configure.ac
}

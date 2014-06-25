DESCRIPTION = "Multimedia Framework Utility Library"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by libmm-utility


#PROVIDES by libmm-utility-dev


#PROVIDES by libmm-utility-tool


RDEPENDS = ""
#RDEPENDS of libmm-utility (${PN})
RDEPENDS_${PN} += "eglibc"

#RDEPENDS of libmm-utility-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "libmm-utility"

#RDEPENDS of libmm-utility-tool (${PN}-tool)
RDEPENDS_${PN}-tool += "libmm-utility"


DEPENDS = ""
#DEPENDS of libmm-utility
DEPENDS += "libmm-common"
DEPENDS += "libjpeg-turbo"
DEPENDS += "tizen-platform-config"
DEPENDS += "libmm-log"
DEPENDS += "glib-2.0"
DEPENDS += "libmm-ta"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q
 cp ${S}/packaging/libmm-utility.manifest .
}
do_patch_append() {
    bb.build.exec_func('do_prep', d)
}

do_configure() {
}

do_compile() {
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" ; export CFLAGS ;
 CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ;
 FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ;
 LD_AS_NEEDED=1; export LD_AS_NEEDED ;


 CFLAGS="$CFLAGS -DEXPORT_API=\"__attribute__((visibility(\\\"default\\\")))\" -D_MM_PROJECT_FLOATER" \
 LDFLAGS+=" -Wl,--rpath=${prefix}/lib -Wl,--hash-style=both -Wl,--as-needed " \

   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ;
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ;
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ;
   autotools_do_configure --build=${TARGET_SYS} --host=${HOST_SYS} \
         --target=x86_64-tizen-linux \
         --program-prefix= \
         --prefix=${prefix} \
         --exec-prefix=${prefix} \
         --bindir=${prefix}/bin \
         --sbindir=${prefix}/sbin \
         --sysconfdir=${sysconfdir} \
         --datadir=${prefix}/share \
         --includedir=${prefix}/include \
         --libdir=${prefix}/lib \
         --libexecdir=${prefix}/libexec \
         --localstatedir=${localstatedir} \
         --sharedstatedir=${prefix}/com \
         --mandir=${mandir} \
         --infodir=${infodir}
 make -j16


 sed -i -e "s#@IMGP_REQPKG@#$IMGP_REQPKG#g" imgp/mmutil-imgp.pc
 sed -i -e "s#@JPEG_REQPKG@#$JPEG_REQPKG#g" jpeg/mmutil-jpeg.pc




}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}


 rm -rf ${D}

   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install
   rm -f ${D}${infodir}/dir
   find ${D} -regex ".*\.la$" | xargs rm -f --
   find ${D} -regex ".*\.a$" | xargs rm -f --
 mkdir -p ${D}/usr/share/license
 cp LICENSE ${D}/usr/share/license/libmm-utility



}

pkg_postinst_${PN}() {
    #!/bin/sh -e

    ldconfig
}

pkg_postrm_${PN}() {
    #!/bin/sh -e

    ldconfig
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " libmm-utility "
PACKAGES += " libmm-utility-dev "
PACKAGES += " libmm-utility-tool "

libmm-utility_files = ""
libmm-utility_files += "libmm-utility.manifest"
libmm-utility_files += "/usr/share/license/libmm-utility"
libmm-utility_files += "libmm-utility.manifest"
libmm-utility_files += "${prefix}/lib/*.so*"

libmm-utility-dev_files = ""
libmm-utility-dev_files += "libmm-utility.manifest"
libmm-utility-dev_files += "${prefix}/include/*"
libmm-utility-dev_files += "${prefix}/lib/pkgconfig/*"

libmm-utility-tool_files = ""
libmm-utility-tool_files += "libmm-utility.manifest"
libmm-utility-tool_files += "${prefix}/bin/*_testsuite"

FILES_${PN} = "${libmm-utility_files}"
FILES_${PN}-dev = "${libmm-utility-dev_files}"
FILES_${PN}-tool = "${libmm-utility-tool_files}"

PKG_libmm-utility= "libmm-utility"
PKG_libmm-utility-dev= "libmm-utility-dev"
PKG_libmm-utility-tool= "libmm-utility-tool"

require libmm-utility-extraconf.inc

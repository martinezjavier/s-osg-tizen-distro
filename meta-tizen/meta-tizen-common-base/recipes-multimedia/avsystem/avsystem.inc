DESCRIPTION = "Audio Video System"
HOMEPAGE = "http://nohomepage.org"
SECTION = "System/Libraries"
LICENSE = "Apache-2.0"
PV = "0.5.6"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit manifest autotools-brokensep 

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by avsystem


#PROVIDES by avsystem-dev
PROVIDES += "avsystem-dev"


#PROVIDES by libavsysaudio
PROVIDES += "libavsysaudio"


RDEPENDS = ""
#RDEPENDS of avsystem (${PN})
RDEPENDS_${PN} += "glibc"
RDEPENDS_${PN} += "systemd"

#RDEPENDS of avsystem-dev (${PN}-dev)
RDEPENDS_${PN}-dev += "avsystem"


DEPENDS = ""
#DEPENDS of avsystem
DEPENDS += "alsa-lib"
DEPENDS += "libmm-log"
inherit pkgconfig
DEPENDS += "iniparser"
DEPENDS += "pulseaudio"
DEPENDS += "libexif"
DEPENDS += "libmm-ta"
DEPENDS += "alsa-scenario"

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n avsystem-0.5.6
 cp ${S}/packaging/avsystem.manifest .
 
 
 
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
  LD_AS_NEEDED=1; export LD_AS_NEEDED ;
  
  
  autotools_do_configure
  
  oe_runmake
  
  
  
  
}
EXTRA_OECONF += " --enable-audiotest"

do_install() {
 export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D}
 mkdir -p ${D}
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 
 mkdir -m 755 -p ${D}${systemd_unitdir}/system/multi-user.target.wants
 install -m 0644 ${S}/packaging/avsystem.service ${D}${systemd_unitdir}/system/avsystem.service
 ln -sf ../avsystem.service ${D}${systemd_unitdir}/system/multi-user.target.wants/avsystem.service
 
 mkdir -m 755 -p ${D}/etc/rc.d/rc3.d/
 mkdir -m 755 -p ${D}/etc/rc.d/rc4.d/
 ln -sf ../init.d/snd_init ${D}/etc/rc.d/rc3.d/S15snd_init
 ln -sf ../init.d/snd_init ${D}/etc/rc.d/rc4.d/S15snd_init
 
 
}

pkg_postinst_libavsysaudio() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig

}

pkg_postrm_libavsysaudio() {
    #!/bin/sh -e

    [ "x$D" == "x" ] && ldconfig

}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-locale"
PACKAGES += " avsystem "
PACKAGES += " avsystem-dev "
PACKAGES += " libavsysaudio "

avsystem_files = ""
avsystem_files += "${prefix}/bin/*"
avsystem_files += "${systemd_unitdir}/system/avsystem.service"
avsystem_files += "${systemd_unitdir}/system/multi-user.target.wants/avsystem.service"
avsystem_files += "/etc/rc.d/init.d/snd_init"
avsystem_files += "/etc/rc.d/rc3.d/S15snd_init"
avsystem_files += "/etc/rc.d/rc4.d/S15snd_init"
MANIFESTFILES_${PN} = "avsystem.manifest"

avsystem-dev_files = ""
avsystem-dev_files += "${prefix}/lib/pkgconfig/*.pc"
avsystem-dev_files += "${prefix}/lib/*.so"
avsystem-dev_files += "${prefix}/include/avsystem/*.h"
MANIFESTFILES_${PN}-dev = "avsystem.manifest"

libavsysaudio_files = ""
libavsysaudio_files += "${prefix}/lib/lib*.so.*"
MANIFESTFILES_libavsysaudio = "avsystem.manifest"

FILES_${PN} = "${avsystem_files}"
FILES_${PN}-dev = "${avsystem-dev_files}"
FILES_libavsysaudio = "${libavsysaudio_files}"

PKG_avsystem= "avsystem"
PKG_avsystem-dev= "avsystem-dev"
PKG_libavsysaudio= "libavsysaudio"

require avsystem-extraconf.inc


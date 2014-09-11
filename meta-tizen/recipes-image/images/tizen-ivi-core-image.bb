require recipes-image/images/tizen-core-image-minimal.bb

SUMMARY = "Tizen IVI image"

LICENSE = "MIT"

DESCRIPTION = "A Tizen IVI image based on Tizen common ."

WESTONSTARTUP = "weston-ivi"
IMAGECONFIG = "config-tizen-ivi"

# Modello packages
CORE_IMAGE_EXTRA_INSTALL += "packagegroup-tizen-ivi-modello"

CORE_IMAGE_EXTRA_INSTALL += "automotive-message-broker"
CORE_IMAGE_EXTRA_INSTALL += "efl-theme-tizen-hd"
CORE_IMAGE_EXTRA_INSTALL += "festival"
CORE_IMAGE_EXTRA_INSTALL += "genivi-audio-manager"

CORE_IMAGE_EXTRA_INSTALL += "lemolo"
CORE_IMAGE_EXTRA_INSTALL += "libwebsockets"
CORE_IMAGE_EXTRA_INSTALL += "murphy"
CORE_IMAGE_EXTRA_INSTALL += "node-startup-controller"
CORE_IMAGE_EXTRA_INSTALL += "pulseaudio-module-murphy-ivi"
CORE_IMAGE_EXTRA_INSTALL += "weston-ivi-config"

# TMP Remove rygel
# BTY-36
#CORE_IMAGE_EXTRA_INSTALL += "rygel"

CORE_IMAGE_EXTRA_INSTALL += "sphinxbase"
CORE_IMAGE_EXTRA_INSTALL += "udev-rules-ivi"
CORE_IMAGE_EXTRA_INSTALL += "genivi-shell"
CORE_IMAGE_EXTRA_INSTALL += "weston-ivi-shell"

# Crosswalk
CORE_IMAGE_EXTRA_INSTALL += "packagegroup-tizen-crosswalk"

# Time zone
CORE_IMAGE_EXTRA_INSTALL += "tzdata"

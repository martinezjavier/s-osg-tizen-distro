require recipes-image/images/tizen-common-core-image-minimal.bb

DESCRIPTION = "A weston image with Tizen common and \
is suitable for development work."

IMAGE_FEATURES += "dev-pkgs tools-debug debug-tweaks ssh-server-openssh"
CORE_IMAGE_EXTRA_INSTALL += "packagegroup-tizen-dev-tools"
CORE_IMAGE_EXTRA_INSTALL += "packagegroup-tizen-tests-connectivity"
CORE_IMAGE_EXTRA_INSTALL += "nano"
CORE_IMAGE_EXTRA_INSTALL += "v4l-utils"

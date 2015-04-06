# %description imx kernel package


DESCRIPTION = "Linux kernel"

inherit kernel
require recipes-kernel/linux/linux-imx.inc
require recipes-kernel/linux/linux-dtb.inc


#LINUX_VERSION ?= "3.10"
LINUX_VERSION_EXTENSION = "-starterkit"


COMPATIBLE_MACHINE = "(sk-imx6q|sk)"

SRCBRANCH = "imx_3.10.17_1.0.0_ga"
SRCREV = "33597e348b2d60dd5c71890ef7b7d3d3fd6e4e97"
SRC_URI = "git://git.freescale.com/imx/linux-2.6-imx.git;protocol=git;branch=${SRCBRANCH}"

# i don't want to download this from mirrors
PREMIRRORS = ""
MIRRORS = ""

S = "${WORKDIR}/git"

LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://README;md5=540ef59d74a60c409333b6da95720f4c"

# kernel patches and defconfig
SRC_URI += " file://sk-kernel-v2.patch file://git file://defconfig"


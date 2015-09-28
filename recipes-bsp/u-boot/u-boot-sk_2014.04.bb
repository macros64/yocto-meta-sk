# %description U-boot package

require recipes-bsp/u-boot/u-boot.inc

PROVIDES += "u-boot"

DESCRIPTION = "U-Boot provided by Freescale with focus on  i.MX reference boards."


SRCBRANCH = "imx_v2014.04_3.10.31_1.1.0_beta"
SRCREV = "7f7d66b7653f3a72548ba247099717a531c0c0e7"
SRC_URI = "git://git.freescale.com/imx/uboot-imx.git;protocol=git;branch=${SRCBRANCH}"

S = "${WORKDIR}/git"

LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://Licenses/README;md5=025bf9f768cbcb1a165dbe1a110babfb"

# files ot be placed on top of existing {S} dir
# i was unable to find better solution for it than place under 'git' folder
SRC_URI += " file://sk-u-boot-201404.patch file://git"

COMPATIBLE_MACHINE = "(sk-imx6q|sk-holaduo|sk-hola)"

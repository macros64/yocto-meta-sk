# common settings for starterkit imx6 boards
# 2015 macros64@gmail.com

include conf/machine/include/tune-cortexa9.inc

#
# linux kernel
#
PREFERRED_PROVIDER_virtual/kernel = "linux-yocto-sk"
PREFERRED_VERSION_linux-yocto-sk = "3.10"
KERNEL_IMAGETYPE = "zImage"


#
# bootloader
#
PREFERRED_PROVIDER_virtual/bootloader = "u-boot-sk"
PREFERRED_PROVIDER_u-boot = "u-boot-sk"
PREFERRED_VERSION_u-boot-sk = "2014.04%"
UBOOT_SUFFIX = "imx"


# this is default value
#UBOOT_ENTRYPOINT = "0x80008000"
UBOOT_LOADADDRESS = "0x12000000"
UBOOT_LOCALVERSION = "-starterkit"

#
# filesystem image
#
IMAGE_BOOTLOADER = "u-boot-sk"
IMAGE_CLASSES += "image_types_fsl"
SDCARD_ROOTFS = "${DEPLOY_DIR_IMAGE}/${IMAGE_NAME}.rootfs.ext3"
IMAGE_FSTYPES += "tar.bz2 ext3 sdcard"

#
# other settings
#
XSERVER_DRIVER = "xf86-video-imxfb-vivante"
PREFERRED_PROVIDER_virtual/xserver = "xserver-xorg"
XSERVER = "xserver-xorg \
           xf86-input-evdev \
           xf86-input-mouse \
           xf86-video-omapfb \
           xf86-input-keyboard ${XSERVER_DRIVER}"

PREFERRED_VERSION_xserver-xorg = "2:1.14.4"
PREFERRED_VERSION_directfb = "1.6.3"
PREFERRED_VERSION_directfb-examples = "1.6.0"
 

MACHINE_ARCH_FILTER = "virtual/kernel"
MACHINE_SOCARCH_FILTER = "libfslcodec libfslvpuwrap libfslparser gst-fsl-plugins"
MACHINE_SOCARCH_FILTER += " virtual/libopenvg virtual/libgles1 virtual/libgles2 virtual/egl virtual/libg2d"
#MACHINE_SOCARCH_FILTER += " virtual/mesa virtual/libgl"

INHERIT += "fsl-dynamic-packagearch"

# Firmware
MACHINE_FIRMWARE = "firmware-imx-vpu-imx6q"

# GStreamer 0.10 plugins
MACHINE_GSTREAMER_PLUGIN = "gst-fsl-plugin"

# GStreamer 1.0 plugins
MACHINE_GSTREAMER_1_0_PLUGIN = "gstreamer1.0-plugins-imx-meta"

# mx6 GPU libraries
PREFERRED_PROVIDER_virtual/egl = "gpu-viv-bin-mx6q"
PREFERRED_PROVIDER_virtual/libgles1 = "gpu-viv-bin-mx6q"
PREFERRED_PROVIDER_virtual/libgles2 = "gpu-viv-bin-mx6q"
PREFERRED_PROVIDER_virtual/libgl = "gpu-viv-bin-mx6q"

# for solo core processors
#PREFERRED_PROVIDER_virtual/libgles2 ?= "mesa"
#PREFERRED_PROVIDER_virtual/libgles1 ?= "mesa"
#PREFERRED_PROVIDER_virtual/libgl ?= "mesa"
 
# Ship all kernel modules by default
MACHINE_EXTRA_RRECOMMENDS = " kernel-modules udev-rules-imx"
MACHINE_FEATURES = "usbgadget usbhost vfat alsa touchscreen"

SERIAL_CONSOLE = "115200 ttymxc0"

MACHINE_SOCARCH = "${TUNE_PKGARCH}-mx6qdl"
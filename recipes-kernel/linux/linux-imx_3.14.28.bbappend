FILESEXTRAPATHS_append := "${THISDIR}/${PN}-${PV}"
SRC_URI += "file://3.14.28-sk.patch"
COMPATIBLE_MACHINE = "(sk-hola|sk-holaduo|sk-imx6q)"

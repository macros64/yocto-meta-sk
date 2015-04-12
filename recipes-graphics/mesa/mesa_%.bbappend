PACKAGECONFIG_remove = "egl gles"

PROVIDES_remove = "virtual/libgles1 virtual/libgles2 virtual/egl"
PROVIDES_remove += "virtual/libgl"

USE_VIV_LIBGL = "yes"

# FIXME: Dirty hack to allow use of Vivante GPU libGL binary
do_install_append () {
    if [ "${USE_VIV_LIBGL}" = "yes" ]; then
        rm -f ${D}${libdir}/libGL.*
    fi
}

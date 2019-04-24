FILESEXTRAPATHS_prepend := "${THISDIR}/vcu-firmware:"

SRCREV = "d01951905e1aedb179d838a6b86016f34e2f4966"

SRC_URI_append = " \
	file://al5e.fw \
	file://al5e_b.fw \
"

do_install_append() {
	install -m 0644 ${WORKDIR}/al5e.fw ${D}/lib/firmware/al5e.fw
	install -m 0644 ${WORKDIR}/al5e_b.fw ${D}/lib/firmware/al5e_b.fw
}

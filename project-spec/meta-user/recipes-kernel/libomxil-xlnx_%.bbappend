FILESEXTRAPATHS_prepend := "${THISDIR}/libomxil-xlnx:"

SRCREV = "cf4b031ac88c7889e4f29ac7fc8ca7592bf12144"

SRC_URI_append = " \
	file://0001-Do-not-print-errors-for-the-OMX_EventPortSettingsCha.patch \
	file://0002-backport-lowref-fix.patch \
"

do_install() {
    install -d ${D}${libdir}
    install -d ${D}${includedir}/vcu-omx-il

    install -m 0644 ${S}/omx_header/*.h ${D}${includedir}/vcu-omx-il

    install -Dm 0755 ${S}/bin/omx_decoder ${D}/${bindir}/omx_decoder
    install -Dm 0755 ${S}/bin/omx_encoder ${D}/${bindir}/omx_encoder

    oe_libinstall -C ${S}/bin/ -so libOMX.allegro.core ${D}/${libdir}/
    oe_libinstall -C ${S}/bin/ -so libOMX.allegro.video_decoder ${D}/${libdir}/
    oe_libinstall -C ${S}/bin/ -so libOMX.allegro.video_encoder ${D}/${libdir}/
}

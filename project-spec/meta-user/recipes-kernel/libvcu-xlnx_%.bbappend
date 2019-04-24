FILESEXTRAPATHS_prepend := "${THISDIR}/libvcu-xlnx:"

SRCREV = "1cb5281d319ea4f3c0eb5514864c80d95e78fe6e"

SRC_URI_append = " \
	file://0001-fix-filler-data.-They-should-be-clipped-to-fit-in-th.patch \
	file://0002-Fix-decoder-for-streams-where-PPS_id-0-is-not-presen.patch \
	file://0003-Improve-error-resilence-on-SEI-message-parsing.patch \
	file://0004-Fix-decoder-glitches.patch \
	file://0005-Fix-HEVC_MAIN_422-custom-422-8bits-profiles.patch \
	file://0006-Improve-error-resilience-when-corrupted-stream-has-M.patch \
	file://0007-Do-not-use-floating-point-arithmetic-for-dynamic-lam.patch \
	file://0008-uNumShortTerm-uNumLongTerm-shouldn-t-be-higher-than-.patch \
	file://0009-Fix-decoding-start-up-on-IDR-in-the-middle-of-a-stre.patch \
	file://0010-Decoder-Resilience-to-bitstreams-with-max_num_ref-DP.patch \
	file://0011-Decoder-Conceal-slice-with-invalid-reordering-in-hea.patch \
	file://0012-increase-encoder-process-robustness.patch \
"


do_install() {
    install -d ${D}${libdir}
    install -d ${D}${includedir}/vcu-ctrl-sw/include

    install -Dm 0755 ${S}/bin/ctrlsw_encoder ${D}/${bindir}/ctrlsw_encoder
    install -Dm 0755 ${S}/bin/ctrlsw_decoder ${D}/${bindir}/ctrlsw_decoder

    oe_runmake install_headers INSTALL_HDR_PATH=${D}${includedir}/vcu-ctrl-sw/include
    oe_libinstall -C ${S}/bin/ -so liballegro_decode ${D}/${libdir}/
    oe_libinstall -C ${S}/bin/ -so liballegro_encode ${D}/${libdir}/
}

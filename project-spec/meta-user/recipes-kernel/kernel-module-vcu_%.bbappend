FILESEXTRAPATHS_prepend := "${THISDIR}/kernel-module-vcu:"

SRCREV = "f6a9093ec32ee97a2df065aee8b8e676c2024f01"

SRC_URI_append = " \
	file://0001-spacing-uncrustify-instability.patch \
	file://0002-Remove-sleeping-function-from-the-spinlock-critical-.patch \
	file://0003-Mailbox-structures-are-now-directly-inside-the-mcu_i.patch \
	file://0004-Fix-wrong-kmalloc-size-1675-KASAN-trace.patch \
"

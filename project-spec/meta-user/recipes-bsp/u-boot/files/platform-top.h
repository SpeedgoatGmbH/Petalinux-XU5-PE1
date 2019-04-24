#include <configs/platform-auto.h>

#define CONFIG_SYS_BAUDRATE_TABLE  { 4800, 9600, 19200, 38400, 57600, 115200 }



/* processor - psu_cortexa53_0 */
#define CONFIG_CPU_ARMV8
#define CONFIG_CLOCKS
#define CONFIG_REMAKE_ELF
#define CONFIG_BOARD_EARLY_INIT_R
#define CONFIG_BOARD_EARLY_INIT_F
#define CONFIG_ARM_DCC
#define CONFIG_MP

/* main_memory - psu_ddr_0 */

/* uart - psu_uart_0 */
#define PSSERIAL0	"psserial0=setenv stdout ttyPS0;setenv stdin ttyPS0\0"
#define SERIAL_MULTI	"serial=setenv stdout serial;setenv stdin serial\0"
#define CONSOLE_ARG	"console=console=ttyPS0,115200\0"
#define SERIAL_MULTI  "serial=setenv stdout serial;setenv stdin serial\0"
#define CONFIG_BAUDRATE	115200

/* ethernet - psu_ethernet_3 */
#define CONFIG_SYS_FAULT_ECHO_LINK_DOWN
#define PHY_ANEG_TIMEOUT 20000
#define CONFIG_MII
#define CONFIG_NET_MULTI
#define CONFIG_NETCONSOLE	1
#define CONFIG_SERVERIP	10.0.2.15
#define CONFIG_IPADDR

/* spi_flash - psu_qspi_0 */
#define XILINX_PS8_QSPI_CLK_FREQ_HZ	49999500
#define CONFIG_SF_DEFAULT_SPEED   (XILINX_PS8_QSPI_CLK_FREQ_HZ / 4)
#define CONFIG_MTD_UBI_WL_THRESHOLD 4096
#define CONFIG_MTD_UBI_BEB_LIMIT 0
#define CONFIG_CMD_UBI
#define CONFIG_RBTREE
#define CONFIG_CMD_UBIFS
#define CONFIG_LZO
#define CONFIG_CMD_MTDPARTS
#define CONFIG_MTD_DEVICE
#define CONFIG_MTD_PARTITIONS
#define CONFIG_SPI_FLASH_MTD

/* sdio - psu_sd_1 */
#define CONFIG_ZYNQ_SDHCI1
#define CONFIG_SUPPORT_VFAT
#define CONFIG_SUPPORT_EMMC_BOOT
#define CONFIG_ZYNQ_SDHCI_MAX_FREQ  200000000

/* sdio - psu_sd_0 */
#define CONFIG_ZYNQ_SDHCI0

/* rtc - psu_rtc */

/* i2c - psu_i2c_0 */
#define CONFIG_SYS_I2C_ZYNQ
#define CONFIG_SYS_I2C
#define CONFIG_SYS_I2C_ZYNQ_SLAVE	0
#define CONFIG_SYS_I2C_ZYNQ_SPEED 100000

/* usb - psu_usb_0 */
#define CONFIG_USB_CABLE_CHECK
#define CONFIG_USB_FUNCTION_THOR
#define CONFIG_THOR_RESET_OFF
#define CONFIG_SUPPORT_VFAT
#define CONFIG_SYS_DFU_DATA_BUF_SIZE 0x1800000
#define DFU_DEFAULT_POLL_TIMEOUT 300

/* mpsoc_ss_zynq_ultra_ps_e_0 */
#define COUNTER_FREQUENCY 100000000

/* intc - psu_acpu_gic */
#define ACPU_GIC_BASEADDR	0xF9010000
#define CONFIG_GICV2	1
#define GICD_BASE	(ACPU_GIC_BASEADDR)
#define GICC_BASE (ACPU_GIC_BASEADDR + 0x10000)

/* FPGA */

/* Memory testing handling */
#define CONFIG_SYS_MEMTEST_START	0x0
#define CONFIG_SYS_MEMTEST_END	(0x0 + 0x1000)
#define CONFIG_SYS_LOAD_ADDR	(0x0 + 0x100000) /* default load address */
#define CONFIG_SYS_INIT_SP_ADDR	(CONFIG_SYS_LOAD_ADDR - GENERATED_GBL_DATA_SIZE)
#define CONFIG_NR_DRAM_BANKS	2

/* Size of malloc() pool */
#define SIZE	0x2000000
#define CONFIG_SYS_MALLOC_LEN	SIZE


/* BOOTP options */
#define CONFIG_BOOTP_SERVERIP
#define CONFIG_BOOTP_BOOTFILESIZE
#define CONFIG_BOOTP_BOOTPATH
#define CONFIG_BOOTP_GATEWAY
#define CONFIG_BOOTP_HOSTNAME
#define CONFIG_BOOTP_MAY_FAIL
#define CONFIG_BOOTP_DNS
#define CONFIG_BOOTP_SUBNETMASK
#define CONFIG_BOOTP_PXE

/*Command line configuration.*/
#define CONFIG_CMDLINE_EDITING
#define CONFIG_AUTO_COMPLETE

#define CONFIG_IMAGE_FORMAT_LEGACY
#define CONFIG_SUPPORT_RAW_INITRD

/* Miscellaneous configurable options */
#define CONFIG_SYS_CBSIZE	2048/* Console I/O Buffer Size      */
#define CONFIG_SYS_PBSIZE	(CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_BARGSIZE CONFIG_SYS_CBSIZE

/* Use the HUSH parser */
#define CONFIG_SYS_PROMPT_HUSH_PS2 "> "

#define CONFIG_ENV_VARS_UBOOT_CONFIG
#define CONFIG_ENV_OVERWRITE	/* Allow to overwrite the u-boot environment variables */

#define CONFIG_LMB

/* FDT support */
#define CONFIG_DISPLAY_BOARDINFO_LATE


/* Boot Argument Buffer Size */
#define CONFIG_SYS_MAXARGS      64      /* max number of command args */
#define CONFIG_SYS_LONGHELP

/* Initial memory map for Linux */
#define CONFIG_SYS_BOOTMAPSZ 0x8000000

/* Environment settings*/
#define CONFIG_ENV_SIZE	0x80000

/* PREBOOT */
#define CONFIG_PREBOOT	"echo U-BOOT for IO351_PE1;setenv preboot; echo; dhcp"

#include <configs/mw_xilinx_common.h>

/* Extra U-Boot Env settings */
#define CONFIG_EXTRA_ENV_SETTINGS \
	SERIAL_MULTI \ 
	CONSOLE_ARG \ 
	DFU_ALT_INFO_RAM \ 
	DFU_ALT_INFO_MMC \ 
	PSSERIAL0 \ 
  	"kernel_addr=0x10000000\0" \
	"initrd_addr=0x2000000\0" \
	"initrd_high=0x10000000\0" \
	"initrd_size=0x2000000\0" \
	"initrd_image=uramdisk.image.gz\0"	\
	"fdt_addr=23fff000\0" \
	"fdt_high=0x10000000\0" \
	"fdt_image=devicetree.dtb\0"	\
	"bitstream_addr=0x1000000\0"	\
	"bitstream_image=system.bit\0"	\
	"nc=setenv stdout nc;setenv stdin nc;\0" \ 
	"ethaddr=00:0a:35:00:22:01\0" \
	"bootenv=uEnv.txt\0" \ 
	"importbootenv=echo \"Importing environment from SD ...\"; " \ 
		"env import -t ${loadbootenv_addr} $filesize\0" \ 
	"loadbootenv=load mmc $sdbootdev:$partid ${loadbootenv_addr} ${bootenv}\0" \ 
	"sd_uEnvtxt_existence_test=test -e mmc $sdbootdev:$partid /uEnv.txt\0" \ 
	"uenvboot=" \
		"if run sd_uEnvtxt_existence_test; then " \
			"run loadbootenv; " \
			"echo Loaded environment from ${bootenv}; " \
			"run importbootenv; " \
		"fi; " \
		"if test -n $uenvcmd; then " \
			"echo Running uenvcmd ...; " \
			"run uenvcmd; " \
		"fi\0" \
    	"mmc_loadbit=echo Loading bitstream from SD/MMC/eMMC to RAM.. && " \
		"load mmc $sdbootdev:$partid ${bitstream_addr} ${bitstream_image} && " \
		"fpga loadb 0 ${bitstream_addr} ${filesize}\0" \
	"sd_bitstream_existence_test=test -e mmc $sdbootdev:$partid /${bitstream_image}\0" \
	"sd_boot_loadbit=" \
		"if run sd_bitstream_existence_test; then " \
			"run mmc_loadbit;" \
		"fi; \0" \    
    	ENV_CMD_INIT_ENV_ONCE \
	"sdboot=if mmc dev $sdbootdev; then " \
			"run uenv_init; " \
			"run uenvboot; " \
			"run sd_boot_loadbit; " \
			"echo Copying Linux from SD to RAM... && " \
			"load mmc $sdbootdev:$partid $kernel_addr Image && " \
			"load mmc $sdbootdev:$partid $fdt_addr $fdt_image && " \
			"if load mmc 0 ${initrd_addr} ${initrd_image}; then " \
				"booti ${kernel_addr} ${initrd_addr} ${fdt_addr}; " \
			"else " \
				"booti ${kernel_addr} - ${fdt_addr}; " \
			"fi &&" \
		"fi\0" \
	"autoload=no\0" \ 
	"sdbootdev=1\0" \ 
	"clobstart=0x10000000\0" \ 
	"netstart=0x10000000\0" \ 
	"dtbnetstart=0x23fff000\0" \ 
	"loadaddr=0x10000000\0" \ 
	"boot_img=BOOT.BIN\0" \ 
	"load_boot=tftpboot ${clobstart} ${boot_img}\0" \ 
	"update_boot=setenv img boot; setenv psize ${bootsize}; setenv installcmd \"install_boot\"; run load_boot ${installcmd}; setenv img; setenv psize; setenv installcmd\0" \ 
	"install_boot=fatwrite mmc ${sdbootdev} ${clobstart} ${boot_img} ${filesize}\0" \ 
	"install_bootenv=fatwrite mmc ${sdbootdev} ${clobstart} ${bootenv_img} ${filesize}\0" \ 
	"jffs2_img=rootfs.jffs2\0" \ 
	"load_jffs2=tftpboot ${clobstart} ${jffs2_img}\0" \ 
	"update_jffs2=setenv img jffs2; setenv psize ${jffs2size}; setenv installcmd \"install_jffs2\"; run load_jffs2 test_img; setenv img; setenv psize; setenv installcmd\0" \ 
	"sd_update_jffs2=echo Updating jffs2 from SD;fatload mmc ${sdbootdev}:1 ${clobstart} ${jffs2_img} && run install_jffs2\0" \ 
	"install_jffs2=sf probe 0 && sf erase ${jffs2start} ${jffs2size} && " \ 
		"sf write ${clobstart} ${jffs2start} ${filesize}\0" \ 
	"kernel_img=Image\0" \ 
	"load_kernel=tftpboot ${clobstart} ${kernel_img}\0" \ 
	"update_kernel=setenv img kernel; setenv psize ${kernelsize}; setenv installcmd \"install_kernel\"; run load_kernel ${installcmd}; setenv img; setenv psize; setenv installcmd\0" \ 
	"install_kernel=fatwrite mmc ${sdbootdev} ${clobstart} ${kernel_img} ${filesize}\0" \ 
	"cp_kernel2ram=fatload mmc ${sdbootdev} ${netstart} ${kernel_img}\0" \ 
	"dtb_img=system.dtb\0" \ 
	"load_dtb=tftpboot ${clobstart} ${dtb_img}\0" \ 
	"update_dtb=setenv img dtb; setenv psize ${dtbsize}; setenv installcmd \"install_dtb\"; run load_dtb test_img; setenv img; setenv psize; setenv installcmd\0" \ 
	"sd_update_dtb=echo Updating dtb from SD;fatload mmc ${sdbootdev}:1 ${clobstart} ${dtb_img} && run install_dtb\0" \ 
	"loadbootenv_addr=0x00100000\0" \ 
	"fault=echo ${img} image size is greater than allocated place - partition ${img} is NOT UPDATED\0" \ 
	"test_crc=if imi ${clobstart}; then run test_img; else echo ${img} Bad CRC - ${img} is NOT UPDATED; fi\0" \ 
	"test_img=setenv var \"if test ${filesize} -gt ${psize}\\; then run fault\\; else run ${installcmd}\\; fi\"; run var; setenv var\0" \ 
	"netboot=tftpboot ${netstart} ${kernel_img} && bootm\0" \ 
	"default_bootcmd=run uenvboot; run cp_kernel2ram && bootm ${netstart}\0" \ 
""

/* BOOTCOMMAND */
#define CONFIG_BOOTCOMMAND	"run sdboot"

#if !defined(CONFIG_ENV_IS_IN_FAT)
#define CONFIG_ENV_IS_NOWHERE		1
#endif

#define CONFIG_SYS_BOOTM_LEN 0xF000000

#define DFU_ALT_INFO_RAM \
                "dfu_ram_info=" \
        "setenv dfu_alt_info " \
        "image.ub ram $netstart 0x1e00000\0" \
        "dfu_ram=run dfu_ram_info && dfu 0 ram 0\0" \
        "thor_ram=run dfu_ram_info && thordown 0 ram 0\0"

#define DFU_ALT_INFO_MMC \
        "dfu_mmc_info=" \
        "set dfu_alt_info " \
        "${kernel_image} fat 0 1\\\\;" \
        "dfu_mmc=run dfu_mmc_info && dfu 0 mmc 0\0" \
        "thor_mmc=run dfu_mmc_info && thordown 0 mmc 0\0"

/*Required for uartless designs */
#ifndef CONFIG_BAUDRATE
#define CONFIG_BAUDRATE 115200
#ifdef CONFIG_DEBUG_UART
#undef CONFIG_DEBUG_UART
#endif
#endif

/*Define CONFIG_ZYNQMP_EEPROM here and its necessaries in u-boot menuconfig if you had EEPROM memory. */
#ifdef CONFIG_ZYNQMP_EEPROM
#define CONFIG_SYS_I2C_EEPROM_ADDR_LEN  1
#define CONFIG_CMD_EEPROM
#define CONFIG_ZYNQ_EEPROM_BUS          5
#define CONFIG_ZYNQ_GEM_EEPROM_ADDR     0x54
#define CONFIG_ZYNQ_GEM_I2C_MAC_OFFSET  0x20
#endif

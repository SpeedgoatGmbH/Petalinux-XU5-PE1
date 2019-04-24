# Speedgoat GmbH&reg; ZynqMP Vision Petalinux

Speedgoat Petalinux build system

Current Supported Boards
- IO351-PE1-300 ZynqMP

General build instructions

- Setup the petalinux environment in your terminal (ie

`$ source /local/petalinux/settings.sh`).

   Ensure you are using /bin/bash
- In the project directory, run the build command

`$ petalinux-build`

- After the build has succeeded, to create the SD image, run the helper script below

`$ mw_package_binaries.sh`

- A directory with the following files should appear

`$ ls MW_Petalinux_2018-12-01_18-38-58/`

    BOOT.BIN
    system.bit
	devicetree.dtb
    Image
    uramdisk.image.gz
	
- Copy these files over to your SD card and boot the board

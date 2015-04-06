/*
 * Copyright (C) 2014 starterkit.ru
 *
 * Based on mx6qsabrelite.h which is:
 * Copyright (C) 2010-2011 Freescale Semiconductor, Inc.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include "mx6_common.h"
#include <asm/arch/imx-regs.h>
#include <asm/imx-common/gpio.h>

#define CONFIG_MX6
#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_DISPLAY_BOARDINFO

#define MACH_TYPE_SK                    3769
#define CONFIG_MACH_TYPE                MACH_TYPE_SK

#define CONFIG_CMDLINE_TAG
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG
#define CONFIG_REVISION_TAG

/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN           (10 << 20)

#define CONFIG_BOARD_EARLY_INIT_F
#define CONFIG_MISC_INIT_R
#define CONFIG_MXC_GPIO

#define CONFIG_CMD_FUSE
#ifdef CONFIG_CMD_FUSE
#define CONFIG_MXC_OCOTP
#endif

#ifdef CONFIG_HW_WATCHDOG
#define CONFIG_IMX_WATCHDOG
#define CONFIG_WATCHDOG_TIMEOUT_MSECS   20000 /* 20 sec */
#endif

#define CONFIG_MXC_UART
#define CONFIG_MXC_UART_BASE            UART1_BASE

/* MMC Configs */
#define CONFIG_FSL_ESDHC
#define CONFIG_FSL_USDHC
#define CONFIG_SYS_FSL_ESDHC_ADDR       0
#define CONFIG_SYS_FSL_USDHC_NUM        2
#define CONFIG_MMC
#define CONFIG_CMD_MMC
#define CONFIG_GENERIC_MMC
#define CONFIG_BOUNCE_BUFFER
#define CONFIG_CMD_EXT2
#define CONFIG_CMD_FAT
#define CONFIG_DOS_PARTITION

#define CONFIG_CMD_PING
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_MII
#define CONFIG_CMD_NET
#define CONFIG_FEC_MXC
#define CONFIG_MII
#define IMX_FEC_BASE                    ENET_BASE_ADDR
#define CONFIG_FEC_XCV_TYPE             RMII
#define CONFIG_FEC_MXC_PHYADDR          0
#define CONFIG_PHYLIB
#define CONFIG_PHY_SMSC

/* Miscellaneous commands */
#define CONFIG_CMD_BMODE
#define CONFIG_CMD_SETEXPR

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE
#define CONFIG_CONS_INDEX               1
#define CONFIG_BAUDRATE                 115200

/* Command definition */
#include <config_cmd_default.h>

#undef CONFIG_CMD_IMLS

#define CONFIG_BOOTDELAY                3
#define CONFIG_ZERO_BOOTDELAY_CHECK

#define CONFIG_LOADADDR                 0x12000000
#define CONFIG_SYS_TEXT_BASE            0x17800000

#define CONFIG_SYS_MEMTEST_START        0x10000000
#define CONFIG_SYS_MEMTEST_END          0x10010000

#define MTDIDS_DEFAULT		"nand0=gpmi-nand"
#define MTDPARTS_DEFAULT	"mtdparts=gpmi-nand:16M(boot),512M(rootfs),-(userdata)"

#define CONFIG_SK_VIDEO "video=mxcfb0:dev=hdmi,1920x1080M@60,if=RGB24 dmfc=3"

#ifdef CONFIG_SYS_BOOT_MMC
#define CONFIG_EXTRA_ENV_SETTINGS \
	"delenv=env default -a -f; saveenv\0" \
	"ipaddr=192.168.0.136\0" \
	"netmask=255.255.255.0\0" \
	"ethaddr=00:1f:f2:00:00:00\0" \
	"serverip=192.168.0.2\0" \
	"kernel=zImage\0" \
	"dtbfile=" CONFIG_DEFAULT_FDT_FILE "\0" \
	"dtbaddr=12800000\0" \
	"fdt_high=0xffffffff\0"	  \
	"initrd_high=0xffffffff\0" \
	"console=console=ttymxc0,115200\0" \
	"mmcroot=root=/dev/mmcblk0p1 rootfstype=ext4 rootwait rw\0" \
	"video=" CONFIG_SK_VIDEO " "\
	"consoleblank=0\0" \
	"mtdparts=" MTDPARTS_DEFAULT "\0" \
	"mmcargs=setenv bootargs ${console} ${mtdparts} ${mmcroot} ${video}\0" \
	"mmc_boot=run mmcargs;" \
	"ext2load mmc 1:1 ${loadaddr} /boot/${kernel};" \
	"ext2load mmc 1:1 ${dtbaddr} /boot/${dtbfile};" \
	"bootz ${loadaddr} - ${dtbaddr}\0" \
	"bootcmd=run mmc_boot\0"

/* Environment in MMC */
#define CONFIG_ENV_IS_IN_MMC
#define CONFIG_ENV_SIZE                 (8 << 10)
#define CONFIG_ENV_OFFSET               (6 * 64 * 1024)
#define CONFIG_SYS_MMC_ENV_DEV          1
#endif /* CONFIG_SYS_BOOT_MMC */

#ifdef CONFIG_SYS_BOOT_NAND
#define CONFIG_EXTRA_ENV_SETTINGS \
	"delenv=env default -a -f; saveenv\0" \
	"ipaddr=192.168.0.136\0" \
	"netmask=255.255.255.0\0" \
	"ethaddr=00:1f:f2:00:00:00\0" \
	"serverip=192.168.0.2\0" \
	"kernel=zImage\0" \
	"dtbfile=" CONFIG_DEFAULT_FDT_FILE "\0" \
	"dtbaddr=12800000\0" \
	"fdt_high=0xffffffff\0"	  \
	"initrd_high=0xffffffff\0" \
	"console=console=ttymxc0,115200\0" \
	"nandroot=root=ubi0:rootfs rootfstype=ubifs rootwait rw\0" \
	"video=" CONFIG_SK_VIDEO " "\
	"consoleblank=0\0" \
	"mtdparts=" MTDPARTS_DEFAULT "\0" \
	"ubilayout=ubi.mtd=1\0" \
	"nandargs=setenv bootargs ${console} ${mtdparts} ${ubilayout} ${nandroot} ${video}\0" \
	"nand_boot=run nandargs;" \
	"mtdparts default; ubi part rootfs; ubifsmount ubi0:rootfs;" \
	"ubifsload ${loadaddr} /boot/${kernel};" \
	"ubifsload ${dtbaddr} /boot/${dtbfile};" \
	"bootz ${loadaddr} - ${dtbaddr}\0" \
	"bootcmd=run nand_boot\0"

/* NAND stuff */
#define CONFIG_NAND_MXS
#define CONFIG_CMD_NAND
#define CONFIG_CMD_NAND_TRIMFFS
#define CONFIG_SYS_MAX_NAND_DEVICE      1
#define CONFIG_SYS_NAND_BASE            0x40000000
#define CONFIG_SYS_NAND_5_ADDR_CYCLE
#define CONFIG_SYS_NAND_ONFI_DETECTION
/* DMA stuff, needed for GPMI/MXS NAND support */
#define CONFIG_APBH_DMA
#define CONFIG_APBH_DMA_BURST
#define CONFIG_APBH_DMA_BURST8

/* UBI/UBIFS config options */
#define CONFIG_LZO
#define CONFIG_MTD_DEVICE
#define CONFIG_MTD_PARTITIONS
#define CONFIG_RBTREE
#define CONFIG_CMD_MTDPARTS
#define CONFIG_CMD_UBI
#define CONFIG_CMD_UBIFS

/* Environment in NAND */
#define CONFIG_ENV_IS_IN_NAND
#define CONFIG_ENV_OFFSET               (8 << 20)
#define CONFIG_ENV_SECT_SIZE            (1024 << 10)
#define CONFIG_ENV_SIZE                 CONFIG_ENV_SECT_SIZE
#endif /* CONFIG_SYS_BOOT_NAND */

/* Miscellaneous configurable options */
#define CONFIG_SYS_LONGHELP
#define CONFIG_SYS_HUSH_PARSER
#define CONFIG_SYS_PROMPT               "u-boot > "
#define CONFIG_AUTO_COMPLETE
#define CONFIG_CMDLINE_EDITING
#define CONFIG_SYS_CONSOLE_INFO_QUIET	/* don't print console @ startup */

#define CONFIG_SYS_CBSIZE               256

/* Print Buffer Size */
#define CONFIG_SYS_PBSIZE               (CONFIG_SYS_CBSIZE + \
                                        sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_MAXARGS              16
#define CONFIG_SYS_BARGSIZE             CONFIG_SYS_CBSIZE

#define CONFIG_SYS_LOAD_ADDR            CONFIG_LOADADDR
#define CONFIG_SYS_HZ                   1000

/* Physical Memory Map */
#define CONFIG_NR_DRAM_BANKS            1
#define PHYS_SDRAM                      MMDC0_ARB_BASE_ADDR
#define CONFIG_SYS_SDRAM_BASE           PHYS_SDRAM
#define CONFIG_SYS_INIT_RAM_ADDR        IRAM_BASE_ADDR
#define CONFIG_SYS_INIT_RAM_SIZE        IRAM_SIZE

#define CONFIG_SYS_INIT_SP_OFFSET       (CONFIG_SYS_INIT_RAM_SIZE - \
                                        GENERATED_GBL_DATA_SIZE)
#define CONFIG_SYS_INIT_SP_ADDR         (CONFIG_SYS_INIT_RAM_ADDR + \
                                        CONFIG_SYS_INIT_SP_OFFSET)

/* FLASH and environment organization */
#define CONFIG_SYS_NO_FLASH

#define CONFIG_OF_LIBFDT
#define CONFIG_CMD_BOOTZ
#define CONFIG_CMD_ELF

#ifndef CONFIG_SYS_DCACHE_OFF
#define CONFIG_CMD_CACHE
#endif

#endif			       /* __CONFIG_H */

/*
 *  arch/arm/include/asm/mach/mmc.h
 */
#ifndef ASMARM_MACH_MMC_H
#define ASMARM_MACH_MMC_H

#include <linux/mmc/host.h>
#include <linux/mmc/card.h>
#include <linux/mmc/sdio_func.h>

struct embedded_sdio_data {
        struct sdio_cis cis;
        struct sdio_cccr cccr;
        struct sdio_embedded_func *funcs;
        int num_funcs;
};

#if 0
struct mmc_platform_data {
	unsigned int ocr_mask;			/* available voltages */
	u32 (*translate_vdd)(struct device *, unsigned int);
	unsigned int (*status)(struct device *);
//	unsigned int status_irq;   // for 4715
	struct embedded_sdio_data *embedded_sdio;
	int (*register_status_notify)(void (*callback)(int card_present, void *dev_id), void *dev_id);
	unsigned long irq_flags;
	unsigned long mmc_bus_width;
	int (*wpswitch) (struct device *);
};
#else
struct mmc_platform_data {
	unsigned int ocr_mask;			/* available voltages */
	u32 (*translate_vdd)(struct device *, unsigned int);
	unsigned int (*status)(struct device *);
	unsigned int status_irq;
	struct embedded_sdio_data *embedded_sdio;
	unsigned int sdiowakeup_irq;
	int (*register_status_notify)(void (*callback)(int card_present, void *dev_id), void *dev_id);
	unsigned long irq_flags;
	unsigned long mmc_bus_width;
	int (*wpswitch) (struct device *);
	int dummy52_required;
};
#endif

#endif

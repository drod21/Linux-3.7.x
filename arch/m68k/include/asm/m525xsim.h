/****************************************************************************/

/*
 *	m525xsim.h -- ColdFire 525x System Integration Module support.
 *
 *	(C) Copyright 2012, Steven king <sfking@fdwdc.com>
 *	(C) Copyright 2002, Greg Ungerer (gerg@snapgear.com)
 */

/****************************************************************************/
#ifndef	m525xsim_h
#define m525xsim_h
/****************************************************************************/

#define CPU_NAME		"COLDFIRE(m525x)"
#define CPU_INSTR_PER_JIFFY	3
#define MCF_BUSCLK		(MCF_CLK / 2)

#include <asm/m52xxacr.h>

/*
 *	The 525x has a second MBAR region, define its address.
 */
#define MCF_MBAR2		0x80000000

/*
 *	Define the 525x SIM register set addresses.
 */
#define MCFSIM_RSR		(MCF_MBAR + 0x00)	/* Reset Status */
#define MCFSIM_SYPCR		(MCF_MBAR + 0x01)	/* System Protection */
#define MCFSIM_SWIVR		(MCF_MBAR + 0x02)	/* SW Watchdog intr */
#define MCFSIM_SWSR		(MCF_MBAR + 0x03)	/* SW Watchdog srv */
#define MCFSIM_MPARK		(MCF_MBAR + 0x0C)	/* BUS Master Ctrl */
#define MCFSIM_IPR		(MCF_MBAR + 0x40)	/* Interrupt Pending */
#define MCFSIM_IMR		(MCF_MBAR + 0x44)	/* Interrupt Mask */
#define MCFSIM_ICR0		(MCF_MBAR + 0x4c)	/* Intr Ctrl reg 0 */
#define MCFSIM_ICR1		(MCF_MBAR + 0x4d)	/* Intr Ctrl reg 1 */
#define MCFSIM_ICR2		(MCF_MBAR + 0x4e)	/* Intr Ctrl reg 2 */
#define MCFSIM_ICR3		(MCF_MBAR + 0x4f)	/* Intr Ctrl reg 3 */
#define MCFSIM_ICR4		(MCF_MBAR + 0x50)	/* Intr Ctrl reg 4 */
#define MCFSIM_ICR5		(MCF_MBAR + 0x51)	/* Intr Ctrl reg 5 */
#define MCFSIM_ICR6		(MCF_MBAR + 0x52)	/* Intr Ctrl reg 6 */
#define MCFSIM_ICR7		(MCF_MBAR + 0x53)	/* Intr Ctrl reg 7 */
#define MCFSIM_ICR8		(MCF_MBAR + 0x54)	/* Intr Ctrl reg 8 */
#define MCFSIM_ICR9		(MCF_MBAR + 0x55)	/* Intr Ctrl reg 9 */
#define MCFSIM_ICR10		(MCF_MBAR + 0x56)	/* Intr Ctrl reg 10 */
#define MCFSIM_ICR11		(MCF_MBAR + 0x57)	/* Intr Ctrl reg 11 */

#define MCFSIM_CSAR0		(MCF_MBAR + 0x80)	/* CS 0 Address reg */
#define MCFSIM_CSMR0		(MCF_MBAR + 0x84)	/* CS 0 Mask reg */
#define MCFSIM_CSCR0		(MCF_MBAR + 0x8a)	/* CS 0 Control reg */
#define MCFSIM_CSAR1		(MCF_MBAR + 0x8c)	/* CS 1 Address reg */
#define MCFSIM_CSMR1		(MCF_MBAR + 0x90)	/* CS 1 Mask reg */
#define MCFSIM_CSCR1		(MCF_MBAR + 0x96)	/* CS 1 Control reg */
#define MCFSIM_CSAR2		(MCF_MBAR + 0x98)	/* CS 2 Address reg */
#define MCFSIM_CSMR2		(MCF_MBAR + 0x9c)	/* CS 2 Mask reg */
#define MCFSIM_CSCR2		(MCF_MBAR + 0xa2)	/* CS 2 Control reg */
#define MCFSIM_CSAR3		(MCF_MBAR + 0xa4)	/* CS 3 Address reg */
#define MCFSIM_CSMR3		(MCF_MBAR + 0xa8)	/* CS 3 Mask reg */
#define MCFSIM_CSCR3		(MCF_MBAR + 0xae)	/* CS 3 Control reg */
#define MCFSIM_CSAR4		(MCF_MBAR + 0xb0)	/* CS 4 Address reg */
#define MCFSIM_CSMR4		(MCF_MBAR + 0xb4)	/* CS 4 Mask reg */
#define MCFSIM_CSCR4		(MCF_MBAR + 0xba)	/* CS 4 Control reg */

#define MCFSIM_DCR		(MCF_MBAR + 0x100)	/* DRAM Control */
#define MCFSIM_DACR0		(MCF_MBAR + 0x108)	/* DRAM 0 Addr/Ctrl */
#define MCFSIM_DMR0		(MCF_MBAR + 0x10c)	/* DRAM 0 Mask */

/*
 * Secondary Interrupt Controller (in MBAR2)
*/
#define MCFINTC2_INTBASE	(MCF_MBAR2 + 0x168)	/* Base Vector Reg */
#define MCFINTC2_INTPRI1	(MCF_MBAR2 + 0x140)	/* 0-7 priority */
#define MCFINTC2_INTPRI2	(MCF_MBAR2 + 0x144)	/* 8-15 priority */
#define MCFINTC2_INTPRI3	(MCF_MBAR2 + 0x148)	/* 16-23 priority */
#define MCFINTC2_INTPRI4	(MCF_MBAR2 + 0x14c)	/* 24-31 priority */
#define MCFINTC2_INTPRI5	(MCF_MBAR2 + 0x150)	/* 32-39 priority */
#define MCFINTC2_INTPRI6	(MCF_MBAR2 + 0x154)	/* 40-47 priority */
#define MCFINTC2_INTPRI7	(MCF_MBAR2 + 0x158)	/* 48-55 priority */
#define MCFINTC2_INTPRI8	(MCF_MBAR2 + 0x15c)	/* 56-63 priority */

#define MCFINTC2_INTPRI_REG(i)	(MCFINTC2_INTPRI1 + \
				((((i) - MCFINTC2_VECBASE) / 8) * 4))
#define MCFINTC2_INTPRI_BITS(b, i)	((b) << (((i) % 8) * 4))

/*
 *	Timer module.
 */
#define MCFTIMER_BASE1		(MCF_MBAR + 0x140)	/* Base of TIMER1 */
#define MCFTIMER_BASE2		(MCF_MBAR + 0x180)	/* Base of TIMER2 */

/*
 *	UART module.
 */
#define MCFUART_BASE0		(MCF_MBAR + 0x1c0)	/* Base address UART0 */
#define MCFUART_BASE1		(MCF_MBAR + 0x200)	/* Base address UART1 */

/*
 *	QSPI module.
 */
#define MCFQSPI_BASE		(MCF_MBAR + 0x300)	/* Base address QSPI */
#define MCFQSPI_SIZE		0x40			/* Register set size */


#define MCFQSPI_CS0		15
#define MCFQSPI_CS1		16
#define MCFQSPI_CS2		24
#define MCFQSPI_CS3		28

/*
 *	I2C module.
 */
#define MCFI2C_BASE0		(MCF_MBAR + 0x280)	/* Base addreess I2C0 */
#define MCFI2C_SIZE0		0x20			/* Register set size */

#define MCFI2C_BASE1		(MCF_MBAR2 + 0x440)	/* Base addreess I2C1 */
#define MCFI2C_SIZE1		0x20			/* Register set size */
/*
 *	DMA unit base addresses.
 */
#define MCFDMA_BASE0		(MCF_MBAR + 0x300)	/* Base address DMA 0 */
#define MCFDMA_BASE1		(MCF_MBAR + 0x340)	/* Base address DMA 1 */
#define MCFDMA_BASE2		(MCF_MBAR + 0x380)	/* Base address DMA 2 */
#define MCFDMA_BASE3		(MCF_MBAR + 0x3C0)	/* Base address DMA 3 */

/*
 *	Some symbol defines for the above...
 */
#define MCFSIM_SWDICR		MCFSIM_ICR0	/* Watchdog timer ICR */
#define MCFSIM_TIMER1ICR	MCFSIM_ICR1	/* Timer 1 ICR */
#define MCFSIM_TIMER2ICR	MCFSIM_ICR2	/* Timer 2 ICR */
#define MCFSIM_I2CICR		MCFSIM_ICR3	/* I2C ICR */
#define MCFSIM_UART1ICR		MCFSIM_ICR4	/* UART 1 ICR */
#define MCFSIM_UART2ICR		MCFSIM_ICR5	/* UART 2 ICR */
#define MCFSIM_DMA0ICR		MCFSIM_ICR6	/* DMA 0 ICR */
#define MCFSIM_DMA1ICR		MCFSIM_ICR7	/* DMA 1 ICR */
#define MCFSIM_DMA2ICR		MCFSIM_ICR8	/* DMA 2 ICR */
#define MCFSIM_DMA3ICR		MCFSIM_ICR9	/* DMA 3 ICR */
#define MCFSIM_QSPIICR		MCFSIM_ICR10	/* QSPI ICR */

/*
 *	Define system peripheral IRQ usage.
 */
#define MCF_IRQ_QSPI		28		/* QSPI, Level 4 */
#define MCF_IRQ_I2C0		29
#define MCF_IRQ_TIMER		30		/* Timer0, Level 6 */
#define MCF_IRQ_PROFILER	31		/* Timer1, Level 7 */

#define MCF_IRQ_UART0		73		/* UART0 */
#define MCF_IRQ_UART1		74		/* UART1 */

/*
 * Define the base interrupt for the second interrupt controller.
 * We set it to 128, out of the way of the base interrupts, and plenty
 * of room for its 64 interrupts.
 */
#define MCFINTC2_VECBASE	128

#define MCF_IRQ_GPIO0		(MCFINTC2_VECBASE + 32)
#define MCF_IRQ_GPIO1		(MCFINTC2_VECBASE + 33)
#define MCF_IRQ_GPIO2		(MCFINTC2_VECBASE + 34)
#define MCF_IRQ_GPIO3		(MCFINTC2_VECBASE + 35)
#define MCF_IRQ_GPIO4		(MCFINTC2_VECBASE + 36)
#define MCF_IRQ_GPIO5		(MCFINTC2_VECBASE + 37)
#define MCF_IRQ_GPIO6		(MCFINTC2_VECBASE + 38)

#define MCF_IRQ_USBWUP		(MCFINTC2_VECBASE + 40)
#define MCF_IRQ_I2C1		(MCFINTC2_VECBASE + 62)

/*
 *	General purpose IO registers (in MBAR2).
 */
#define MCFSIM2_GPIOREAD	(MCF_MBAR2 + 0x000)	/* GPIO read values */
#define MCFSIM2_GPIOWRITE	(MCF_MBAR2 + 0x004)	/* GPIO write values */
#define MCFSIM2_GPIOENABLE	(MCF_MBAR2 + 0x008)	/* GPIO enabled */
#define MCFSIM2_GPIOFUNC	(MCF_MBAR2 + 0x00C)	/* GPIO function */
#define MCFSIM2_GPIO1READ	(MCF_MBAR2 + 0x0B0)	/* GPIO1 read values */
#define MCFSIM2_GPIO1WRITE	(MCF_MBAR2 + 0x0B4)	/* GPIO1 write values */
#define MCFSIM2_GPIO1ENABLE	(MCF_MBAR2 + 0x0B8)	/* GPIO1 enabled */
#define MCFSIM2_GPIO1FUNC	(MCF_MBAR2 + 0x0BC)	/* GPIO1 function */

#define MCFSIM2_GPIOINTSTAT	(MCF_MBAR2 + 0xc0)	/* GPIO intr status */
#define MCFSIM2_GPIOINTCLEAR	(MCF_MBAR2 + 0xc0)	/* GPIO intr clear */
#define MCFSIM2_GPIOINTENABLE	(MCF_MBAR2 + 0xc4)	/* GPIO intr enable */

/*
 * Generic GPIO support
 */
#define MCFGPIO_PIN_MAX		64
#define MCFGPIO_IRQ_MAX		7
#define MCFGPIO_IRQ_VECBASE	MCF_IRQ_GPIO0

/****************************************************************************/
#endif	/* m525xsim_h */

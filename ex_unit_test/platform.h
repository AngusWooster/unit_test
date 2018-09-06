#ifndef _PLATFORM_H_
#define _PLATFORM_H_

#include "platform_reg.h"

#define FAILURE (-1)
#define SUCCESS (0)

#ifndef UNIT_TEST
#define IO_REG_RD8(ADDR)  (*((volatile uint8_t *)(ADDR)))
#define IO_REG_WR8(ADDR, VAL_8)   (*((volatile uint8_t *)(ADDR)) = (VAL_8))
#else
/* UNIT_TEST fake functions */
uint8_t IO_REG_RD8(uint32_t reg);
void IO_REG_WR8(uint32_t reg, uint8_t val);
#endif

#endif
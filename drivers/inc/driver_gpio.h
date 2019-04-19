/**
 * Copyright (c) 2019, Tsingtao Freqchip
 * 
 * All rights reserved.
 * 
 * 
 */
 
#ifndef _DRIVER_GPIO_H
#define _DRIVER_GPIO_H

#include <stdint.h>
#include "driver_iomux.h"

#define BIT(x) (1<<(x))

#define GPIOAB_BASE         0x50060000
#define GPIOCD_BASE         0x50064000

#define GPIO_PORTA_DATA         (GPIOAB_BASE + 0x00)
#define GPIO_PORTB_DATA         (GPIOAB_BASE + 0x04)
#define GPIO_PORTA_DIR          (GPIOAB_BASE + 0x08)
#define GPIO_PORTB_DIR          (GPIOAB_BASE + 0x0c)
#define GPIO_PORTC_DATA         (GPIOCD_BASE + 0x00)
#define GPIO_PORTD_DATA         (GPIOCD_BASE + 0x04)
#define GPIO_PORTC_DIR          (GPIOCD_BASE + 0x08)
#define GPIO_PORTD_DIR          (GPIOCD_BASE + 0x0c)

#define GPIO_DIR_IN         1
#define GPIO_DIR_OUT        0

/// Macro to read a platform register
#define GPIO_REG_PL_RD(addr)              (*(volatile uint32_t *)(addr))

/// Macro to write a platform register
#define GPIO_REG_PL_WR(addr, value)       (*(volatile uint32_t *)(addr)) = (value)

//void gpio_porta_write(uint8_t value)
#define gpio_porta_write(value)  GPIO_REG_PL_WR(GPIO_PORTA_DATA, value)
#define gpio_portb_write(value)  GPIO_REG_PL_WR(GPIO_PORTB_DATA, value)
#define gpio_portc_write(value)  GPIO_REG_PL_WR(GPIO_PORTC_DATA, value)
#define gpio_portd_write(value)  GPIO_REG_PL_WR(GPIO_PORTD_DATA, value)

//uint8_t gpio_porta_read(void)
#define gpio_porta_read() GPIO_REG_PL_RD(GPIO_PORTA_DATA)
#define gpio_portb_read() GPIO_REG_PL_RD(GPIO_PORTB_DATA)
#define gpio_portc_read() GPIO_REG_PL_RD(GPIO_PORTC_DATA)
#define gpio_portd_read() GPIO_REG_PL_RD(GPIO_PORTD_DATA)

//void gpio_porta_set_dir(uint8_t dir)
#define gpio_porta_set_dir(dir) GPIO_REG_PL_WR(GPIO_PORTA_DIR, dir)
#define gpio_portb_set_dir(dir) GPIO_REG_PL_WR(GPIO_PORTB_DIR, dir)
#define gpio_portc_set_dir(dir) GPIO_REG_PL_WR(GPIO_PORTC_DIR, dir)
#define gpio_portd_set_dir(dir) GPIO_REG_PL_WR(GPIO_PORTD_DIR, dir)

//uint8_t gpio_porta_get_dir(void)
#define gpio_porta_get_dir() GPIO_REG_PL_RD(GPIO_PORTA_DIR)
#define gpio_portb_get_dir() GPIO_REG_PL_RD(GPIO_PORTB_DIR)
#define gpio_portc_get_dir() GPIO_REG_PL_RD(GPIO_PORTC_DIR)
#define gpio_portd_get_dir() GPIO_REG_PL_RD(GPIO_PORTD_DIR)

/*****
Example code:

#include "driver_iomux.h"
#include "driver_gpio.h"
  
	......
	
	gpio_set_port_mux(GPIO_PORT_A,GPIO_BIT_4,PORTA4_FUNC_A4);
  gpio_set_dir(GPIO_PORT_A, GPIO_BIT_4, GPIO_DIR_OUT);
  gpio_porta_write(gpio_porta_read() & (~(1<<GPIO_BIT_4)));
	
******/


//void system_set_port_mux(enum gpio_port_t port, enum gpio_port_bit_t bit, uint8_t func);
extern void system_set_port_mux(enum gpio_port_t port, enum gpio_port_bit_t bit, uint8_t func);
#define gpio_set_port_mux system_set_port_mux

extern void system_set_port_pull(uint32_t num, uint8_t pull);
#define gpio_set_port_pull system_set_port_pull


void gpio_set_dir(enum gpio_port_t port, enum gpio_port_bit_t bit, uint8_t dir);
void gpio_set_dir_as_high_imp(enum gpio_port_t port, enum gpio_port_bit_t bit);

#endif //_DRIVER_GPIO_H


/**
 * Copyright (c) 2019, Tsingtao Freqchip
 * 
 * All rights reserved.
 * 
 * 
 */
 
/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include <stdio.h>
#include <string.h>

#include "gap_api.h"

#include "driver_iomux.h"
#include "driver_gpio.h"

void user_proj_main_before_ble_ini(void)
{
    printf("user proj_main_before_ble_ini\r\n");
    uint8_t addr[] = {0x1f, 0x09, 0x07, 0x09, 0x17, 0x20};
    gap_address_set(addr);
}


void user_proj_main(void)
{
	printf("Configure PC2 as OUTPUT high\r\n");
	gpio_set_port_mux(GPIO_PORT_C, GPIO_BIT_2, PORTC2_FUNC_C2);
	gpio_set_dir(GPIO_PORT_C, GPIO_BIT_2, GPIO_DIR_OUT);
	gpio_portc_write(gpio_portc_read() | ((1<<GPIO_BIT_2)));

	printf("Configure PC3 as INPUT\r\n");
	gpio_set_port_mux(GPIO_PORT_C, GPIO_BIT_3, PORTC3_FUNC_C3);
	gpio_set_dir(GPIO_PORT_C, GPIO_BIT_3, GPIO_DIR_IN);
	
	if(gpio_portc_read() & BIT(3))
			printf("PC3 is high\r\n");
	
	if(!(gpio_portc_read() & BIT(3)))
			printf("PC3 is low\r\n");
}




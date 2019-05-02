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

#include "osal_timer.h"

osal_timer_struct demo_timer;

void user_proj_main_before_ble_ini(void)
{
    printf("user proj_main_before_ble_ini\r\n");
    uint8_t addr[] = {0x1f, 0x09, 0x07, 0x09, 0x17, 0x20};
    gap_address_set(addr);
}

void demo_timer_callback(void *parg)
{
		printf("Timer loop!\r\n");
}

void user_proj_main(void)
{
		osal_timer_init(&demo_timer, demo_timer_callback, NULL);
		osal_timer_start(&demo_timer, 3000, true);
    
		//osal_timer_stop(demo_timer);
}




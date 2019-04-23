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

#include "driver_gpio.h"
#include "driver_iomux.h"
#include "driver_pwm.h"

/*
one count means: 83ns
high_count:1~0xffffffff
low_count:1~0xffffffff
high_count + low_count <=0xffffffff
*/

pwm_config_t demo_pwm_cfg;

void user_proj_main_before_ble_ini(void)
{
    printf("user proj_main_before_ble_ini\r\n");
    uint8_t addr[] = {0x1f, 0x09, 0x07, 0x09, 0x17, 0x20};
    gap_address_set(addr);
}


void user_proj_main(void)
{
		//Configure PC2 as PWM
		gpio_set_port_mux(GPIO_PORT_C,GPIO_BIT_2,PORTC2_FUNC_PWM2);
	
		demo_pwm_cfg.gpio_pin = GPIO_BIT_2;
		demo_pwm_cfg.gpio_port = GPIO_PORT_C;
		demo_pwm_cfg.high_count = 10000000; //Set the high count as 830 milliseconds
		demo_pwm_cfg.low_count = 10000000; //Set the low count as 830 milliseconds
	
		pwm_timer_init(&demo_pwm_cfg);
		pwm_timer_config(&demo_pwm_cfg);
	
		pwm_timer_start(&demo_pwm_cfg);
	
		//pwm_timer_stop(&demo_pwm_cfg);
	
}




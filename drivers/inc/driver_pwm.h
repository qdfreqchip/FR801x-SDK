/**
 * Copyright (c) 2019, Tsingtao Freqchip
 * 
 * All rights reserved.
 * 
 * 
 */
#ifndef DRIVER_PWM_H
#define DRIVER_PWM_H

/*
 * INCLUDES (包含头文件)
 */

/*
 * MACROS (宏定义)
 */

/*
 * CONSTANTS (常量定义)
 */

/*
 * TYPEDEFS (类型定义)
 */
 
/*
one count means:
@48M 21ns
@24M 41ns
@12M 83ns

high_count:1~0xffffffff
low_count:1~0xffffffff
high_count + low_count <=0xffffffff

NOTE: Refer to driver_iomux.h, do not configure the same GPIO pin in different GPIO port as PWM.
注意：参考driver_iomux.h, 不要把不同的GPIO端口上相同的GPIO PIN脚号配置成PWM。每个PIN脚号只能对应一个PWM。
*/
typedef struct {
	uint8_t gpio_port; //GPIO port 
	uint8_t gpio_pin;  //GPIO pin number 
	uint32_t high_count; //counts for PWM HIGH
	uint32_t low_count; //count for PWM LOW
} pwm_config_t;

/*********************************************************************
 * @fn      pwm_timer_init
 *
 * @brief   Initialize PWM timer.
 *			初始化一个PWM定时器.
 *
 * @param   app_pwm_param - pointer to the pwm configuration parameters.
 *			
 * @return  None.
 */
void pwm_timer_init(pwm_config_t *app_pwm_param);

/*********************************************************************
 * @fn      pwm_timer_config
 *
 * @brief   Configure the PWM timer, like duty cycle and period.
 *			配置PWM定时器.
 *
 * @param   app_pwm_param - pointer to the pwm configuration parameters.
 * @return  None.
 */
void pwm_timer_config(pwm_config_t *app_pwm_param);

/*********************************************************************
 * @fn      pwm_timer_start
 *
 * @brief   Start PWM.
 *			触发PWM.
 *
 * @param   app_pwm_param - pointer to the pwm configuration parameters.
 * @return  None.
 */
void pwm_timer_start(pwm_config_t *app_pwm_param);

 /*********************************************************************
 * @fn      pwm_timer_stop
 *
 * @brief   Stop a PWM timer.
 *			停止PWM.
 *
 * @param   app_pwm_param - pointer to the pwm configuration parameters.
 *
 * @return  None.
 */
void pwm_timer_stop(pwm_config_t *app_pwm_param);

#endif // DRIVER_PWM_H

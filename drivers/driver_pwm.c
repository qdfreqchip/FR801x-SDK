/**
 * Copyright (c) 2019, Tsingtao Freqchip
 * 
 * All rights reserved.
 * 
 * 
 */
 
/*
 * INCLUDES (包含头文件)
 */
#include "gpio.h"
#include "pwm.h"
#include <stdint.h>           // standard integer functions
#include "system.h"
#include "reg_access.h"
#include "driver_pwm.h"

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
 * GLOBAL VARIABLES (全局变量)
 */

/*
 * LOCAL VARIABLES (本地变量)
 */

/*
 * LOCAL FUNCTIONS (本地函数)
 */

/*
 * EXTERN FUNCTIONS (外部函数)
 */

/*
 * PUBLIC FUNCTIONS (全局函数)
 */

/** @function group PWM timer APIs (PWM定时器相关的API)
 * @{
 */

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
void pwm_timer_init(pwm_config_t *app_pwm_param)
{
	system_set_port_mux(app_pwm_param->gpio_port, app_pwm_param->gpio_pin, PORT_FUNC_PWM);
}

/*********************************************************************
 * @fn      pwm_timer_config
 *
 * @brief   Configure the PWM timer, like duty cycle and period.
 *			配置PWM定时器.
 *
 * @param   app_pwm_param - pointer to the pwm configuration parameters.
 * @return  None.
 */
void pwm_timer_config(pwm_config_t *app_pwm_param)
{
	pwm_set_param(app_pwm_param->gpio_pin, app_pwm_param->high_count, app_pwm_param->low_count);
}

/*********************************************************************
 * @fn      pwm_timer_start
 *
 * @brief   Start PWM.
 *			触发PWM.
 *
 * @param   app_pwm_param - pointer to the pwm configuration parameters.
 * @return  None.
 */
void pwm_timer_start(pwm_config_t *app_pwm_param)
{
	pwm_start(app_pwm_param->gpio_pin);
}

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
void pwm_timer_stop(pwm_config_t *app_pwm_param)
{
	pwm_stop(app_pwm_param->gpio_pin);
}
 
/** @function group PWM timer APIs (PWM定时器相关的API)
 * @{
 */
 
 

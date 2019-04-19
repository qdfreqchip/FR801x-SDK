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
#include "app.h"
#include "user_timer.h"
#include "osal_timer.h"

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

/** @function group OS timer APIs (OS定时器相关的API)
 * @{
 */

/*********************************************************************
 * @fn      osal_timer_init
 *
 * @brief   Initialize an OS timer and malloc a buffer for it.
 *			分配一个缓冲区并初始化一个OS定时器.
 *
 * @param   ptimer - pointer to the timer buffer.
 *			pfunction - callback of the timer
 *          parg - parameter of timer callback
 * @return  None.
 */
void osal_timer_init(osal_timer_struct *ptimer, osal_timer_func_t pfunction, void *parg)
{
	os_timer_t *p_os_timer;
	
    ptimer = (void *)ke_malloc(sizeof(os_timer_t) + 1, KE_MEM_NON_RETENTION);
	
	p_os_timer = (osal_timer_struct *)ptimer;
	
	os_timer_setfn(p_os_timer, pfunction, parg);
}

/*********************************************************************
 * @fn      osal_timer_start
 *
 * @brief   Start a timer.
 *			触发Timer.
 *
 * @param   ptimer - pointer to the timer buffer.
 *			ms - expire of the timer with milliseconds
 *          repeat_flag - repeat or one shot timer
 * @return  None.
 */
void osal_timer_start(osal_timer_struct *ptimer,uint32_t ms,bool repeat_flag)
{
	os_timer_t *p_os_timer;
	
	p_os_timer = (osal_timer_struct *)ptimer;
	
    os_timer_arm(p_os_timer, ms, repeat_flag);
}
	  
 /*********************************************************************
 * @fn      osal_timer_stop
 *
 * @brief   Stop a timer.
 *			停止timer.
 *
 * @param   ptimer - pointer to the timer buffer.
 *
 * @return  None.
 */
void osal_timer_stop(osal_timer_struct *ptimer)
{	
	os_timer_t *p_os_timer;
	
	p_os_timer = (osal_timer_struct *)ptimer;
	
	os_timer_disarm(p_os_timer);
	
    ke_free(ptimer);
}
 
/** @function group OS timer APIs (OS定时器相关的API)
 * @{
 */
 
 

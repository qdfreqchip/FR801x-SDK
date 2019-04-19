/**
 * Copyright (c) 2019, Tsingtao Freqchip
 * 
 * All rights reserved.
 * 
 * 
 */
#ifndef OS_TIMER_H
#define OS_TIMER_H

typedef void osal_timer_struct;

typedef void(* osal_timer_func_t)(void *parg);


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
void osal_timer_init(osal_timer_struct *ptimer, osal_timer_func_t pfunction, void *parg);

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
void osal_timer_start(osal_timer_struct *ptimer,uint32_t ms,bool repeat_flag);

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
void osal_timer_stop(osal_timer_struct *ptimer);

#endif // OS_TIMER_H

/**
 * Copyright (c) 2019, Tsingtao Freqchip
 * 
 * All rights reserved.
 * 
 * 
 */

#ifndef _DRIVER_WDT_H
#define _DRIVER_WDT_H

#include <stdint.h>

typedef struct
{
    uint32_t load_value:16;
    uint32_t reserved:16;
} wd_timer_load_t;

typedef struct
{
    uint32_t rst_value:8;
    uint32_t reserved:24;
} wd_timer_counter_rst_t;

typedef struct
{
    uint32_t divisor_l:4;
    uint32_t divisor_h:4;
    uint32_t action:1;
    uint32_t enable:1;
    uint32_t timeout_range:3;
    uint32_t reserved:19;
} wd_timer_ctrl_t;

typedef struct
{
    uint32_t len:16;
    uint32_t reserved:16;
} wd_rst_pulse_len_t;

typedef struct
{
    uint32_t curr_value:16;
    uint32_t reserved:16;
} wd_timer_counter_t;

typedef struct
{
    uint32_t status:1;
    uint32_t reserved:31;
} wd_timer_inpt_sta_t;

typedef volatile struct
{
    wd_timer_load_t           timer_load;
    wd_timer_counter_rst_t    timer_counter_rst;
    wd_timer_ctrl_t           timer_ctrl;
    wd_rst_pulse_len_t        rst_pulse_len;
    wd_timer_counter_t        timer_counter;
    wd_timer_inpt_sta_t       timer_inpt_sta;

} wd_regs_t;


#define RESET_ACTION    0
#define INT_ACTION  1

void os_wdt_ini(void);
void os_wdt_stop(void);
void os_wdt_start(void);
void os_wdt_begins(void);

#endif //_DRIVER_WDT_H

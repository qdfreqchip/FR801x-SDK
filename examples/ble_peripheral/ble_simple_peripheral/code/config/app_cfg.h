/**
 * Copyright (c) 2019, Tsingtao Freqchip
 * 
 * All rights reserved.
 * 
 * 
 */
#ifndef APP_CFG_H
#define APP_CFG_H

/*
 * INCLUDES (包含头文件)
 */
#include <stdio.h>
#include <stdint.h>

/*
 * MACROS (宏定义)
 */
/** @define group ble GAP defines, change here to get your settings (ble的GAP设置, 可以在这里修改成你需要的模式)
 * @{
 */
//!< Advertising mode, 广播模式
#define GAP_ADV_MODE			GAP_ADV_TYPE_NON_CONN//GAP_ADV_TYPE_UNDIRECT
// Advertising address type, 地址类型
#define GAP_ADV_ADDR_TYPE		GAP_ADDR_TYPE_PUBLIC  
// Default advertising interval, units of 625us, 160=100ms, 广播间隔, 625us 为单位，160=100ms
#define GAP_ADV_INTV			160
// Advertising channel map, 37, 38, 39, 广播信道选择，37,38,39
#define GAP_ADV_CHNL_MAP		GAP_ADV_CHAN_ALL
// Advertising discoverable mode, 广播可被发现模式设置
#define GAP_ADV_DIS_MODE		GAP_GEN_DISCOVERABLE
// Advertising filter scan parameters, 允许被什么样的设备扫描到
#define GAP_ADV_FILT_POLICY		ADV_ALLOW_SCAN_ANY_CON_ANY

//!< Connection parameters, 连接参数
#define GAP_CONN_MIN_INTV
#define GAP_CONN_MAX_INTV
#define GAP_CONN_SLAVE_LATENCY
#define GAP_CONN_SUPERVISION_TIMEOUT

/*
 * CONSTANTS (常量定义)
 */
#define CFG_OTA_ENABLE

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


#endif // end of #ifndef APP_CFG_H

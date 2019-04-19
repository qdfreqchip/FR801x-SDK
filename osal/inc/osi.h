/**
 * Copyright (c) 2019, Tsingtao Freqchip
 * 
 * All rights reserved.
 * 
 * 
 */
#ifndef OSI_H
#define OSI_H

/*
 * INCLUDES (包含头文件)
 */
#include <stdio.h>
#include <stdint.h>

/*
 * MACROS (宏定义)
 */

/*
 * CONSTANTS (常量定义)
 */

/*
 * TYPEDEFS (类型定义)
 */
  /**
 * OS event definition.
 */
 typedef struct
{
    uint16_t event_id;
    void *param;
    uint16_t param_len;
    uint16_t src_task_id;
} osi_event_t;

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

/** @function OS Interface APIs (OS接口相关的API)
 * @{
 */

/*********************************************************************
 * @fn      osal_malloc
 *
 * @brief   malloc a buffer.buffer
 * @return  Allocates a memory block whose
 *			分配一个缓冲区.
 *
 * @param   size - the size of  size is size; if no memory is available return NULL
 */
void *osal_malloc(uint32_t size);

/*********************************************************************
 * @fn      osal_free
 *
 * @brief  free a block of memory
 * 
 *
 * @param   the pointer of memory buffer
 * @return  NULL
 */
void osal_free(void *ptr);

#endif // end of #ifndef OSI_H

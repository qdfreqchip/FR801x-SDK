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
#include "rwip_config.h"
#include "ke_mem.h"

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

/** @function group OS memory APIs (OS内存相关的API)
 * @{
 */

/*********************************************************************
 * @fn      osal_malloc
 *
 * @brief   malloc a block of memory 分配一个缓冲区.
 * @param  size - the size of  size is size; 
 *			
 *
 * @return    the pointer of memory buffer allocated, if no memory is available return NULL
 */
void *osal_malloc(uint32_t size)
{
	return ke_malloc(size, KE_MEM_NON_RETENTION);
}

/*********************************************************************
 * @fn      osal_free
 *
 * @brief  free a block of memory
 * 
 *
 * @param   the pointer of memory buffer
 * @return  NULL
 */
void osal_free(void *ptr)
{
	ke_free(ptr);
}

/** @function group OS memory APIs (OS内存相关的API)
 * @{
 */
 
 

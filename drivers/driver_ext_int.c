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
#include "exti.h"
#include "system.h"
/*
 * MACROS (宏定义)
 */

/*
 * CONSTANTS (常量定义)
 */

/*
 * TYPEDEFS (类型定义)
 */


/*********************************************************************
 * @fn      ext_interrupt_enable
 *
 * @brief   Enable external interrupt source.
 *			使能一个外部中断源.
 *
 * @param   num - .
 *			
 * @return  None.
 */
void ext_interrupt_pin_select(uint8_t pin_num)
{
    ext_int_enable(pin_num);
}

/*********************************************************************
 * @fn      ext_interrupt_disable
 *
 * @brief   Disable external interrupt source.
 *			关闭一个外部中断源.
 *
 * @param   num - .
 *			
 * @return  None.
 */
void ext_interrupt_pin_deselect(uint8_t pin_num)
{
    ext_int_disable(pin_num);
}

/*********************************************************************
 * @fn      ext_interrupt_get_status
 *
 * @brief   .
 *			.
 *
 * @param   None.
 *			
 * @return  .
 */
uint32_t ext_interrupt_get_status(void)
{
    return ext_int_get_status();
}


/*********************************************************************
 * @fn      ext_interrupt_clear_status
 *
 * @brief   Configure the speed of I2C.
 *			配置I2C的速度.
 *
 * @param   bit - pointer to the i2c configuration parameters.
 * @return  None.
 */
void ext_interrupt_clear_status(uint32_t bit)
{
    ext_int_clear_status(bit);
}

/*********************************************************************
 * @fn      ext_interrupt_set_type
 *
 * @brief   Read one byte through I2C.
 *			从I2C读一个字节.
 *
 * @param   num - i2c channel: I2C_CHANNEL_0 or I2C_CHANNEL_1.
 *          type - slave address
 *
 * @return  None.
 */
void ext_interrupt_set_type(uint8_t num, uint8_t type)
{
    ext_int_set_type(num, (enum ext_int_type_t)type);
}

/*********************************************************************
 * @fn      i2c_read_bytes
 *
 * @brief   Read multiple bytes through I2C.
 *			从I2C读多个个字节.
 *
 * @param   chan_num - i2c channel: I2C_CHANNEL_0 or I2C_CHANNEL_1.
 *          slave_addr - slave address
 *          addr - address
 *          pbuf - pointer to multiple bytes buffer
 *          len - buffer length
 * @return  None.
 */
void ext_interrupt_set_control(uint8_t num, uint32_t clk, uint8_t counter)
{
    ext_int_set_control(num, clk, counter);
}

/*********************************************************************
 * @fn      i2c_write_byte
 *
 * @brief   Write one byte through I2C.
 *          通过I2C写一个字节.
 *
 * @param   chan_num - i2c channel: I2C_CHANNEL_0 or I2C_CHANNEL_1.
 *          slave_addr - slave address
 *          addr - address
 *          pdata - one byte data
 * @return  None.
 */
void ext_int_isr_ram(void)
{
    external_interrupt_handler();
}

 /*********************************************************************
  * @fn      i2c_write_byte
  *
  * @brief   Write one byte through I2C.
  *          通过I2C写一个字节.
  *
  * @param   chan_num - i2c channel: I2C_CHANNEL_0 or I2C_CHANNEL_1.
  *          slave_addr - slave address
  *          addr - address
  *          pdata - one byte data
  * @return  None.
  */
void ext_interrupt_enable(void)
{
    NVIC_EnableIRQ(EXT_INTR_IRQn);
}

 /*********************************************************************
  * @fn      i2c_write_byte
  *
  * @brief   Write one byte through I2C.
  *          通过I2C写一个字节.
  *
  * @param   chan_num - i2c channel: I2C_CHANNEL_0 or I2C_CHANNEL_1.
  *          slave_addr - slave address
  *          addr - address
  *          pdata - one byte data
  * @return  None.
  */
void ext_interrupt_disable(void)
{
    NVIC_DisableIRQ(EXT_INTR_IRQn);
}


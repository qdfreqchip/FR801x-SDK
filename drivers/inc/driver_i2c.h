/**
 * Copyright (c) 2019, Tsingtao Freqchip
 * 
 * All rights reserved.
 * 
 * 
 */
#ifndef DRIVER_I2C_H
#define DRIVER_I2C_H

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

/* Please note only channel 0 and 1 are supported */
enum i2c_channel_t
{
    I2C_CHANNEL_0,
    I2C_CHANNEL_1,
};

typedef struct {
	uint8_t gpio_port; //GPIO port 
	uint8_t gpio_pin;  //GPIO pin number 
	enum i2c_channel_t chan_num; //I2C channel number
	uint32_t speed; //I2C speed which has a range.
} i2c_config_t;

/*********************************************************************
 * @fn      i2c_init
 *
 * @brief   Initialize I2C instance.
 *			初始化一个I2C实例.
 *
 * @param   app_i2c_param - pointer to the i2c configuration parameters.
 *			
 * @return  None.
 */
void i2c_init(i2c_config_t *app_i2c_param);

/*********************************************************************
 * @fn      i2c_get_min_speed
 *
 * @brief   Get the minimum speed of I2C interface.
 *			获取I2C允许的最小速度.
 *
 * @param   None.
 *			
 * @return  I2C speed.
 */
uint16_t i2c_get_min_speed(void);

/*********************************************************************
 * @fn      i2c_get_max_speed
 *
 * @brief   Get the maximum speed of I2C interface.
 *			获取I2C允许的最大速度.
 *
 * @param   None.
 *			
 * @return  I2C speed.
 */
uint16_t i2c_get_max_speed(void);


/*********************************************************************
 * @fn      i2c_config
 *
 * @brief   Configure the speed of I2C.
 *			配置I2C的速度.
 *
 * @param   app_i2c_param - pointer to the i2c configuration parameters.
 * @return  None.
 */
void i2c_config(i2c_config_t *app_i2c_param);

/*********************************************************************
 * @fn      i2c_read_byte
 *
 * @brief   Read one byte through I2C.
 *			从I2C读一个字节.
 *
 * @param   chan_num - i2c channel: I2C_CHANNEL_0 or I2C_CHANNEL_1.
 *          slave_addr - slave address
 *          addr - address
 *          pbuf - pointer to one byte buffer
 * @return  None.
 */
void i2c_read_byte(enum i2c_channel_t chan_num, uint8_t slave_addr, uint16_t addr, uint8_t *pbuf);

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
void i2c_read_bytes(enum i2c_channel_t chan_num, uint8_t slave_addr, uint16_t addr, uint8_t *pbuf, uint16_t len);

/*********************************************************************
 * @fn      i2c_write_byte
 *
 * @brief   Write one byte through I2C.
 *			通过I2C写一个字节.
 *
 * @param   chan_num - i2c channel: I2C_CHANNEL_0 or I2C_CHANNEL_1.
 *          slave_addr - slave address
 *          addr - address
 *          pdata - one byte data
 * @return  None.
 */
void i2c_write_byte(enum i2c_channel_t chan_num, uint8_t slave_addr, uint16_t addr, uint8_t pdata);

/*********************************************************************
 * @fn      i2c_write_bytes
 *
 * @brief   Write multiple bytes through I2C.
 *			通过I2C写多个个字节.
 *
 * @param   chan_num - i2c channel: I2C_CHANNEL_0 or I2C_CHANNEL_1.
 *          slave_addr - slave address
 *          addr - address
 *          pbuf - pointer to multiple bytes buffer
 *          len - buffer length
 * @return  None.
 */
void i2c_write_bytes(enum i2c_channel_t chan_num, uint8_t slave_addr, uint16_t addr, uint8_t *pbuf, uint16_t len);

#endif // DRIVER_I2C_H

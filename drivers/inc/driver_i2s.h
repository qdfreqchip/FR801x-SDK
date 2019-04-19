/**
 * Copyright (c) 2019, Tsingtao Freqchip
 * 
 * All rights reserved.
 * 
 * 
 */

#ifndef _DRIVER_I2S_H
#define _DRIVER_I2S_H

#include <stdint.h>

#define CO_BIT(pos) (1UL<<(pos))

#define I2S_REG_BASE_ADDRESS    0x50070000

#define I2S_REG_CTRL            I2S_REG_BASE_ADDRESS
#define I2S_REG_BCLK_DIV        (I2S_REG_BASE_ADDRESS+0x04)
#define I2S_REG_FRM_DIV         (I2S_REG_BASE_ADDRESS+0x08)
#define I2S_REG_DATA            (I2S_REG_BASE_ADDRESS+0x0C)
#define I2S_REG_STATUS          (I2S_REG_BASE_ADDRESS+0x10)
#define I2S_REG_INTEN           (I2S_REG_BASE_ADDRESS+0x14)
#define I2S_REG_DIS_DMA         (I2S_REG_BASE_ADDRESS+0x1C)

/*bitmap*/
/*CONTROL REG*/
#define I2S_CTRL_EN                 (CO_BIT(0))
#define I2S_CTRL_FMT                (CO_BIT(1))
#define I2S_CTRL_DLYEN              (CO_BIT(2))
#define I2S_CTRL_FRMINV             (CO_BIT(3))
#define I2S_CTRL_BCLKINV            (CO_BIT(4))
#define I2S_CTRL_MODE_MASTER        (CO_BIT(5))
#define I2S_CTRL_LP                 (CO_BIT(6))
#define I2S_CTRL_DMARXEN            (CO_BIT(7))
#define I2S_CTRL_DMATXEN            (CO_BIT(8))
#define I2S_CTRL_INTEN              (CO_BIT(9))

/*status reg*/
#define I2S_STATUS_RXFFFULL         (CO_BIT(0))
#define I2S_STATUS_RXFFHFULL        (CO_BIT(1))
#define I2S_STATUS_RXFFEMPTY        (CO_BIT(2))
#define I2S_STATUS_TXFFFULL         (CO_BIT(3))
#define I2S_STATUS_TXFFHEMPTY       (CO_BIT(4))
#define I2S_STATUS_TXFFEMPTY        (CO_BIT(5))

/*interrupt enable reg*/
#define I2S_INTEN_RXFFFULL          (CO_BIT(0))
#define I2S_INTEN_RXFFHFULL         (CO_BIT(1))
#define I2S_INTEN_RXFFEMPTY         (CO_BIT(2))
#define I2S_INTEN_TXFFFULL          (CO_BIT(3))
#define I2S_INTEN_TXFFHEMPTY        (CO_BIT(4))
#define I2S_INTEN_TXFFEMPTY         (CO_BIT(5))


enum
{
    I2S_MIC = 1,
    I2S_SPEAKER = 2,
    I2S_NULL,
};
void i2s_init(uint8_t type, uint32_t sample_rate);  //type. 0:mic; 1:speaker
void i2s_stop(void);
void i2s_fifo_flush(void);
void i2s_start(void);

#endif /* _DRIVER_I2S_H */


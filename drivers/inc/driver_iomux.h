/**
 * Copyright (c) 2019, Tsingtao Freqchip
 * 
 * All rights reserved.
 * 
 * 
 */
#ifndef DRIVER_IOMUX_H
#define DRIVER_IOMUX_H

/**********************************************************************************************************************************************
IO PINMUX table as below: 

4'h0	    4'h1       4'h2	    4'h3       4'h4	    4'h5       4'h6	    4'h7       4'h8	    4'h9      4'ha         4'hd
PORTA0  gpio_a0     ext_int0    I2C0_CLK    I2S_CLK     PWM0    SSP0_CLK    SSP1_CLK    UART0_RXD   UART1_RXD   UART0_CTS   PWM_EN0
PORTA1  gpio_a1     ext_int1    I2C0_DAT    I2S_FRM     PWM1    SSP0_CSN    SSP1_CSN    UART0_TXD   UART1_TXD   UART0_RTS   PWM_EN1
PORTA2  gpio_a2     ext_int2    I2C1_CLK    I2S_DOUT    PWM2    SSP0_DOUT   SSP1_DOUT   UART1_RXD   UART0_RXD   UART1_CTS   PWM_EN2
PORTA3  gpio_a3     ext_int3    I2C1_DAT    I2S_DIN     PWM3    SSP0_DIN    SSP1_DIN    UART1_TXD   UART0_TXD   UART1_RTS   PWM_EN3
PORTA4  gpio_a4     ext_int4    I2S_CLK     I2C0_CLK    PWM4    SSP1_CLK    SSP0_CLK    UART0_RXD   UART1_RXD   UART0_CTS   PWM_IN0     SSP0_DIN
PORTA5  gpio_a5     ext_int5    I2S_FRM     I2C0_DAT    PWM5    SSP1_CSN    SSP0_CSN    UART0_TXD   UART1_TXD   UART0_RTS   PWM_IN1
PORTA6  gpio_a6     ext_int6    I2S_DOUT    I2C1_CLK    PWM6    SSP1_DOUT   SSP0_DOUT   UART1_RXD   UART0_RXD   UART1_CTS   PWM_IN2
PORTA7  gpio_a7     ext_int7    I2S_DIN     I2C1_DAT    PWM7    SSP1_DIN    SSP0_DIN    UART1_TXD   UART0_TXD   UART1_RTS   PWM_IN3

PORTB0  gpio_b0     ext_int8    I2C0_CLK    I2S_CLK     PWM0    SSP0_CLK    SSP1_CLK    UART0_RXD   UART1_RXD   UART0_CTS   PWM_EN4
PORTB1  gpio_b1     ext_int9    I2C0_DAT    I2S_FRM     PWM1    SSP0_CSN    SSP1_CSN    UART0_TXD   UART1_TXD   UART0_RTS   PWM_EN5
PORTB2  gpio_b2     ext_int10   I2C1_CLK    I2S_DOUT    PWM2    SSP0_DOUT   SSP1_DOUT   UART1_RXD   UART0_RXD   UART1_CTS   PWM_EN6
PORTB3  gpio_b3     ext_int11   I2C1_DAT    I2S_DIN     PWM3    SSP0_DIN    SSP1_DIN    UART1_TXD   UART0_TXD   UART1_RTS   PWM_EN7
PORTB4  gpio_b4     ext_int12   I2S_CLK     I2C0_CLK    PWM4    SSP1_CLK    SSP0_CLK    UART0_RXD   UART1_RXD   UART0_CTS   PWM_IN4
PORTB5  gpio_b5     ext_int13   I2S_FRM     I2C0_DAT    PWM5    SSP1_CSN    SSP0_CSN    UART0_TXD   UART1_TXD   UART0_RTS   PWM_IN5
PORTB6  gpio_b6     ext_int14   I2S_DOUT    I2C1_CLK    PWM6    SSP1_DOUT   SSP0_DOUT   UART1_RXD   UART0_RXD   UART1_CTS   PWM_IN6
PORTB7  gpio_b7     ext_int15   I2S_DIN     I2C1_DAT    PWM7    SSP1_DIN    SSP0_DIN    UART1_TXD   UART0_TXD   UART1_RTS   PWM_IN7

PORTC0  gpio_c0     ext_int16   I2C0_CLK    I2S_CLK     PWM0    SSP0_CLK    SSP1_CLK    UART0_RXD   UART1_RXD   ADC0*       PWM_EN0
PORTC1  gpio_c1     ext_int17   I2C0_DAT    I2S_FRM     PWM1    SSP0_CSN    SSP1_CSN    UART0_TXD   UART1_TXD   ADC1*       PWM_EN1
PORTC2  gpio_c2     ext_int18   I2C1_CLK    I2S_DOUT    PWM2    SSP0_DOUT   SSP1_DOUT   UART1_RXD   UART0_RXD   ADC2*       PWM_EN2
PORTC3  gpio_c3     ext_int19   I2C1_DAT    I2S_DIN     PWM3    SSP0_DIN    SSP1_DIN    UART1_TXD   UART0_TXD   ADC3*       PWM_EN3
PORTC4  gpio_c4     ext_int20   I2S_CLK     I2C0_CLK    PWM4    SSP1_CLK    SSP0_CLK    UART0_RXD   UART1_RXD   ADC4*       PWM_IN0
PORTC5  gpio_c5     ext_int21   I2S_FRM     I2C0_DAT    PWM5    SSP1_CSN    SSP0_CSN    UART0_TXD   UART1_TXD   ADC5*       PWM_IN1
PORTC6  gpio_c6     ext_int22   I2S_DOUT    I2C1_CLK    PWM6    SSP1_DOUT   SSP0_DOUT   UART1_RXD   UART0_RXD   ADC6*       PWM_IN2
PORTC7  gpio_c7     ext_int23   I2S_DIN     I2C1_DAT    PWM7    SSP1_DIN    SSP0_DIN    UART1_TXD   UART0_TXD   ADC7*       PWM_IN3

PORTD0  gpio_d0     ext_int24   I2C0_CLK    I2S_CLK     PWM0    SSP0_CLK    SSP1_CLK    UART0_RXD   UART1_RXD   UART0_CTS   PWM_EN4
PORTD1  gpio_d1     ext_int25   I2C0_DAT    I2S_FRM     PWM1    SSP0_CSN    SSP1_CSN    UART0_TXD   UART1_TXD   UART0_RTS   PWM_EN5
PORTD2  gpio_d2     ext_int26   I2C1_CLK    I2S_DOUT    PWM2    SSP0_DOUT   SSP1_DOUT   UART1_RXD   UART0_RXD   UART1_CTS   PWM_EN6
PORTD3  gpio_d3     ext_int27   I2C1_DAT    I2S_DIN     PWM3    SSP0_DIN    SSP1_DIN    UART1_TXD   UART0_TXD   UART1_RTS   PWM_EN7
PORTD4  gpio_d4     ext_int28   I2S_CLK     I2C0_CLK    PWM4    SSP1_CLK    SSP0_CLK    UART0_RXD   UART1_RXD   UART0_CTS   PWM_IN4
PORTD5  gpio_d5     ext_int29   I2S_FRM     I2C0_DAT    PWM5    SSP1_CSN    SSP0_CSN    UART0_TXD   UART1_TXD   UART0_RTS   PWM_IN5
PORTD6  gpio_d6     ext_int30   I2S_DOUT    I2C1_CLK    PWM6    SSP1_DOUT   SSP0_DOUT   UART1_RXD   UART0_RXD   UART1_CTS   PWM_IN6
PORTD7  gpio_d7     ext_int31   I2S_DIN     I2C1_DAT    PWM7    SSP1_DIN    SSP0_DIN    UART1_TXD   UART0_TXD   UART1_RTS   PWM_IN7     SSP0_CLK
*************************************************************************************************************************************************/

enum gpio_port_t
{
    GPIO_PORT_A,
    GPIO_PORT_B,
    GPIO_PORT_C,
    GPIO_PORT_D,
};

enum gpio_port_bit_t
{
    GPIO_BIT_0,
    GPIO_BIT_1,
    GPIO_BIT_2,
    GPIO_BIT_3,
    GPIO_BIT_4,
    GPIO_BIT_5,
    GPIO_BIT_6,
    GPIO_BIT_7,
};

#define PORT_FUNC_GPIO              0x00
#define PORT_FUNC_EXT_INT           0x01
#define PORT_FUNC_PWM               0x04
#define PORT_FUNC_PWM_EN            0x0a

#define PORTA0_FUNC_A0              PORT_FUNC_GPIO
#define PORTA0_FUNC_INT0            PORT_FUNC_EXT_INT
#define PORTA0_FUNC_I2C0_CLK        0x02
#define PORTA0_FUNC_I2S_CLK         0x03
#define PORTA0_FUNC_PWM0            PORT_FUNC_PWM
#define PORTA0_FUNC_SSP0_CLK        0x05
#define PORTA0_FUNC_SSP1_CLK        0x06
#define PORTA0_FUNC_UART0_RXD       0x07
#define PORTA0_FUNC_UART1_RXD       0x08
#define PORTA0_FUNC_UART0_CTS       0x09
#define PORTA0_FUNC_PWM_EN0         PORT_FUNC_PWM_EN

#define PORTA1_FUNC_A1              PORT_FUNC_GPIO
#define PORTA1_FUNC_INT1            PORT_FUNC_EXT_INT
#define PORTA1_FUNC_I2C0_DAT        0x02
#define PORTA1_FUNC_I2S_FRM         0x03
#define PORTA1_FUNC_PWM1            PORT_FUNC_PWM
#define PORTA1_FUNC_SSP0_CSN        0x05
#define PORTA1_FUNC_SSP1_CSN        0x06
#define PORTA1_FUNC_UART0_TXD       0x07
#define PORTA1_FUNC_UART1_TXD       0x08
#define PORTA1_FUNC_UART0_RTS       0x09
#define PORTA1_FUNC_PWM_EN1         PORT_FUNC_PWM_EN

#define PORTA2_FUNC_A2              PORT_FUNC_GPIO
#define PORTA2_FUNC_INT2            PORT_FUNC_EXT_INT
#define PORTA2_FUNC_I2C1_CLK        0x02
#define PORTA2_FUNC_I2S_DOUT        0x03
#define PORTA2_FUNC_PWM2            PORT_FUNC_PWM
#define PORTA2_FUNC_SSP0_DOUT       0x05
#define PORTA2_FUNC_SSP1_DOUT       0x06
#define PORTA2_FUNC_UART1_RXD       0x07
#define PORTA2_FUNC_UART0_RXD       0x08
#define PORTA2_FUNC_UART1_CTS       0x09
#define PORTA2_FUNC_PWM_EN2         PORT_FUNC_PWM_EN

#define PORTA3_FUNC_A3              PORT_FUNC_GPIO
#define PORTA3_FUNC_INT3            PORT_FUNC_EXT_INT
#define PORTA3_FUNC_I2C1_DAT        0x02
#define PORTA3_FUNC_I2S_DIN         0x03
#define PORTA3_FUNC_PWM3            PORT_FUNC_PWM
#define PORTA3_FUNC_SSP0_DIN        0x05
#define PORTA3_FUNC_SSP1_DIN        0x06
#define PORTA3_FUNC_UART1_TXD       0x07
#define PORTA3_FUNC_UART0_TXD       0x08
#define PORTA3_FUNC_UART1_RTS       0x09
#define PORTA3_FUNC_PWM_EN3         PORT_FUNC_PWM_EN

#define PORTA4_FUNC_A4              PORT_FUNC_GPIO
#define PORTA4_FUNC_INT4            PORT_FUNC_EXT_INT
#define PORTA4_FUNC_I2S_CLK         0x02
#define PORTA4_FUNC_I2C0_CLK        0x03
#define PORTA4_FUNC_PWM4            PORT_FUNC_PWM
#define PORTA4_FUNC_SSP1_CLK        0x05
#define PORTA4_FUNC_SSP0_CLK        0x06
#define PORTA4_FUNC_UART0_RXD       0x07
#define PORTA4_FUNC_UART1_RXD       0x08
#define PORTA4_FUNC_UART0_CTS       0x09
#define PORTA4_FUNC_PWM_EN4         PORT_FUNC_PWM_EN
#define PORTA4_FUNC_SSP0_DIN        0x0d

#define PORTA5_FUNC_A5              PORT_FUNC_GPIO
#define PORTA5_FUNC_INT5            PORT_FUNC_EXT_INT
#define PORTA5_FUNC_I2S_FRM         0x02
#define PORTA5_FUNC_I2C0_DAT        0x03
#define PORTA5_FUNC_PWM5            PORT_FUNC_PWM
#define PORTA5_FUNC_SSP1_CSN        0x05
#define PORTA5_FUNC_SSP0_CSN        0x06
#define PORTA5_FUNC_UART0_TXD       0x07
#define PORTA5_FUNC_UART1_TXD       0x08
#define PORTA5_FUNC_UART0_RTS       0x09
#define PORTA5_FUNC_PWM_EN5         PORT_FUNC_PWM_EN

#define PORTA6_FUNC_A6              PORT_FUNC_GPIO
#define PORTA6_FUNC_INT6            PORT_FUNC_EXT_INT
#define PORTA6_FUNC_I2S_DOUT        0x02
#define PORTA6_FUNC_I2C1_CLK        0x03
#define PORTA6_FUNC_PWM6            PORT_FUNC_PWM
#define PORTA6_FUNC_SSP1_DOUT       0x05
#define PORTA6_FUNC_SSP0_DOUT       0x06
#define PORTA6_FUNC_UART1_RXD       0x07
#define PORTA6_FUNC_UART0_RXD       0x08
#define PORTA6_FUNC_UART1_CTS       0x09
#define PORTA6_FUNC_PWM_EN6         PORT_FUNC_PWM_EN

#define PORTA7_FUNC_A7              PORT_FUNC_GPIO
#define PORTA7_FUNC_INT7            PORT_FUNC_EXT_INT
#define PORTA7_FUNC_I2S_DIN         0x02
#define PORTA7_FUNC_I2C1_DAT        0x03
#define PORTA7_FUNC_PWM7            PORT_FUNC_PWM
#define PORTA7_FUNC_SSP1_DIN        0x05
#define PORTA7_FUNC_SSP0_DIN        0x06
#define PORTA7_FUNC_UART1_TXD       0x07
#define PORTA7_FUNC_UART0_TXD       0x08
#define PORTA7_FUNC_UART1_RTS       0x09
#define PORTA7_FUNC_PWM_EN7         PORT_FUNC_PWM_EN

#define PORTB0_FUNC_B0              PORT_FUNC_GPIO
#define PORTB0_FUNC_INT8            PORT_FUNC_EXT_INT
#define PORTB0_FUNC_I2C0_CLK        0x02
#define PORTB0_FUNC_I2S_CLK         0x03
#define PORTB0_FUNC_PWM0            PORT_FUNC_PWM
#define PORTB0_FUNC_SSP0_CLK        0x05
#define PORTB0_FUNC_SSP1_CLK        0x06
#define PORTB0_FUNC_UART0_RXD       0x07
#define PORTB0_FUNC_UART1_RXD       0x08
#define PORTB0_FUNC_UART0_CTS       0x09
#define PORTB0_FUNC_PWM_EN0         PORT_FUNC_PWM_EN

#define PORTB1_FUNC_B1              PORT_FUNC_GPIO
#define PORTB1_FUNC_INT9            PORT_FUNC_EXT_INT
#define PORTB1_FUNC_I2C0_DAT        0x02
#define PORTB1_FUNC_I2S_FRM         0x03
#define PORTB1_FUNC_PWM1            PORT_FUNC_PWM
#define PORTB1_FUNC_SSP0_CSN        0x05
#define PORTB1_FUNC_SSP1_CSN        0x06
#define PORTB1_FUNC_UART0_TXD       0x07
#define PORTB1_FUNC_UART1_TXD       0x08
#define PORTB1_FUNC_UART0_RTS       0x09
#define PORTB1_FUNC_PWM_EN1         PORT_FUNC_PWM_EN

#define PORTB2_FUNC_B2              PORT_FUNC_GPIO
#define PORTB2_FUNC_INT10           PORT_FUNC_EXT_INT
#define PORTB2_FUNC_I2C1_CLK        0x02
#define PORTB2_FUNC_I2S_DOUT        0x03
#define PORTB2_FUNC_PWM2            PORT_FUNC_PWM
#define PORTB2_FUNC_SSP0_DOUT       0x05
#define PORTB2_FUNC_SSP1_DOUT       0x06
#define PORTB2_FUNC_UART1_RXD       0x07
#define PORTB2_FUNC_UART0_RXD       0x08
#define PORTB2_FUNC_UART1_CTS       0x09
#define PORTB2_FUNC_PWM_EN2         PORT_FUNC_PWM_EN

#define PORTB3_FUNC_B3              PORT_FUNC_GPIO
#define PORTB3_FUNC_INT11           PORT_FUNC_EXT_INT
#define PORTB3_FUNC_I2C1_DAT        0x02
#define PORTB3_FUNC_I2S_DIN         0x03
#define PORTB3_FUNC_PWM3            PORT_FUNC_PWM
#define PORTB3_FUNC_SSP0_DIN        0x05
#define PORTB3_FUNC_SSP1_DIN        0x06
#define PORTB3_FUNC_UART0_TXD       0x07
#define PORTB3_FUNC_UART1_TXD       0x08
#define PORTB3_FUNC_UART1_RTS       0x09
#define PORTB3_FUNC_PWM_EN3         PORT_FUNC_PWM_EN

#define PORTB4_FUNC_B4              PORT_FUNC_GPIO
#define PORTB4_FUNC_INT12           PORT_FUNC_EXT_INT
#define PORTB4_FUNC_I2S_CLK         0x02
#define PORTB4_FUNC_I2C0_CLK        0x03
#define PORTB4_FUNC_PWM4            PORT_FUNC_PWM
#define PORTB4_FUNC_SSP1_CLK        0x05
#define PORTB4_FUNC_SSP0_CLK        0x06
#define PORTB4_FUNC_UART0_RXD       0x07
#define PORTB4_FUNC_UART1_RXD       0x08
#define PORTB4_FUNC_UART0_CTS       0x09
#define PORTB4_FUNC_PWM_EN4         PORT_FUNC_PWM_EN

#define PORTB5_FUNC_B5              PORT_FUNC_GPIO
#define PORTB5_FUNC_INT13           PORT_FUNC_EXT_INT
#define PORTB5_FUNC_I2S_FRM         0x02
#define PORTB5_FUNC_I2C0_DAT        0x03
#define PORTB5_FUNC_PWM5            PORT_FUNC_PWM
#define PORTB5_FUNC_SSP1_CSN        0x05
#define PORTB5_FUNC_SSP0_CSN        0x06
#define PORTB5_FUNC_UART0_TXD       0x07
#define PORTB5_FUNC_UART1_TXD       0x08
#define PORTB5_FUNC_UART0_RTS       0x09
#define PORTB5_FUNC_PWM_EN5         PORT_FUNC_PWM_EN

#define PORTB6_FUNC_B6              PORT_FUNC_GPIO
#define PORTB6_FUNC_INT14           PORT_FUNC_EXT_INT
#define PORTB6_FUNC_I2S_DOUT        0x02
#define PORTB6_FUNC_I2C1_CLK        0x03
#define PORTB6_FUNC_PWM6            PORT_FUNC_PWM
#define PORTB6_FUNC_SSP1_DOUT       0x05
#define PORTB6_FUNC_SSP0_DOUT       0x06
#define PORTB6_FUNC_UART1_RXD       0x07
#define PORTB6_FUNC_UART0_RXD       0x08
#define PORTB6_FUNC_UART1_CTS       0x09
#define PORTB6_FUNC_PWM_EN6         PORT_FUNC_PWM_EN

#define PORTB7_FUNC_B7              PORT_FUNC_GPIO
#define PORTB7_FUNC_INT15           PORT_FUNC_EXT_INT
#define PORTB7_FUNC_I2S_DIN         0x02
#define PORTB7_FUNC_I2C1_DAT        0x03
#define PORTB7_FUNC_PWM7            PORT_FUNC_PWM
#define PORTB7_FUNC_SSP1_DIN        0x05
#define PORTB7_FUNC_SSP0_DIN        0x06
#define PORTB7_FUNC_UART1_TXD       0x07
#define PORTB7_FUNC_UART0_TXD       0x08
#define PORTB7_FUNC_UART1_RTS       0x09
#define PORTB7_FUNC_PWM_EN7         PORT_FUNC_PWM_EN

#define PORTC0_FUNC_C0              PORT_FUNC_GPIO
#define PORTC0_FUNC_INT16           PORT_FUNC_EXT_INT
#define PORTC0_FUNC_I2C0_CLK        0x02
#define PORTC0_FUNC_I2S_CLK         0x03
#define PORTC0_FUNC_PWM0            PORT_FUNC_PWM
#define PORTC0_FUNC_SSP0_CLK        0x05
#define PORTC0_FUNC_SSP1_CLK        0x06
#define PORTC0_FUNC_UART0_RXD       0x07
#define PORTC0_FUNC_UART1_RXD       0x08
#define PORTC0_FUNC_ADC0            0x09
#define PORTC0_FUNC_PWM_EN0         PORT_FUNC_PWM_EN

#define PORTC1_FUNC_C1              PORT_FUNC_GPIO
#define PORTC1_FUNC_INT17           PORT_FUNC_EXT_INT
#define PORTC1_FUNC_I2C0_DAT        0x02
#define PORTC1_FUNC_I2S_FRM         0x03
#define PORTC1_FUNC_PWM1            PORT_FUNC_PWM
#define PORTC1_FUNC_SSP0_CSN        0x05
#define PORTC1_FUNC_SSP1_CSN        0x06
#define PORTC1_FUNC_UART0_TXD       0x07
#define PORTC1_FUNC_UART1_TXD       0x08
#define PORTC1_FUNC_ADC1            0x09
#define PORTC1_FUNC_PWM_EN1         PORT_FUNC_PWM_EN

#define PORTC2_FUNC_C2              PORT_FUNC_GPIO
#define PORTC2_FUNC_INT18           PORT_FUNC_EXT_INT
#define PORTC2_FUNC_I2C1_CLK        0x02
#define PORTC2_FUNC_I2S_DOUT        0x03
#define PORTC2_FUNC_PWM2            PORT_FUNC_PWM
#define PORTC2_FUNC_SSP0_DOUT       0x05
#define PORTC2_FUNC_SSP1_DOUT       0x06
#define PORTC2_FUNC_UART1_RXD       0x07
#define PORTC2_FUNC_UART0_RXD       0x08
#define PORTC2_FUNC_ADC2            0x09
#define PORTC2_FUNC_PWM_EN2         PORT_FUNC_PWM_EN

#define PORTC3_FUNC_C3              PORT_FUNC_GPIO
#define PORTC3_FUNC_INT19           PORT_FUNC_EXT_INT
#define PORTC3_FUNC_I2C1_DAT        0x02
#define PORTC3_FUNC_I2S_DIN         0x03
#define PORTC3_FUNC_PWM3            PORT_FUNC_PWM
#define PORTC3_FUNC_SSP0_DIN        0x05
#define PORTC3_FUNC_SSP1_DIN        0x06
#define PORTC3_FUNC_UART1_TXD       0x07
#define PORTC3_FUNC_UART0_TXD       0x08
#define PORTC3_FUNC_ADC3            0x09
#define PORTC3_FUNC_PWM_EN3         PORT_FUNC_PWM_EN

#define PORTC4_FUNC_C4              PORT_FUNC_GPIO
#define PORTC4_FUNC_INT20           PORT_FUNC_EXT_INT
#define PORTC4_FUNC_I2S_CLK         0x02
#define PORTC4_FUNC_I2C0_CLK        0x03
#define PORTC4_FUNC_PWM4            PORT_FUNC_PWM
#define PORTC4_FUNC_SSP1_CLK        0x05
#define PORTC4_FUNC_SSP0_CLK        0x06
#define PORTC4_FUNC_UART0_RXD       0x07
#define PORTC4_FUNC_UART2_RXD       0x08
#define PORTC4_FUNC_ADC4            0x09
#define PORTC4_FUNC_PWM_EN4         PORT_FUNC_PWM_EN

#define PORTC5_FUNC_C5              PORT_FUNC_GPIO
#define PORTC5_FUNC_INT21           PORT_FUNC_EXT_INT
#define PORTC5_FUNC_I2S_FRM         0x02
#define PORTC5_FUNC_I2C0_DAT        0x03
#define PORTC5_FUNC_PWM5            PORT_FUNC_PWM
#define PORTC5_FUNC_SSP1_CSN        0x05
#define PORTC5_FUNC_SSP0_CSN        0x06
#define PORTC5_FUNC_UART0_TXD       0x07
#define PORTC5_FUNC_UART2_TXD       0x08
#define PORTC5_FUNC_ADC5            0x09
#define PORTC5_FUNC_PWM_EN5         PORT_FUNC_PWM_EN

#define PORTC6_FUNC_C6              PORT_FUNC_GPIO
#define PORTC6_FUNC_INT22           PORT_FUNC_EXT_INT
#define PORTC6_FUNC_I2S_DOUT        0x02
#define PORTC6_FUNC_I2C1_CLK        0x03
#define PORTC6_FUNC_PWM6            PORT_FUNC_PWM
#define PORTC6_FUNC_SSP1_DOUT       0x05
#define PORTC6_FUNC_SSP0_DOUT       0x06
#define PORTC6_FUNC_UART1_RXD       0x07
#define PORTC6_FUNC_UART0_RXD       0x08
#define PORTC6_FUNC_ADC6            0x09
#define PORTC6_FUNC_PWM_EN6         PORT_FUNC_PWM_EN

#define PORTC7_FUNC_C7              PORT_FUNC_GPIO
#define PORTC7_FUNC_INT23           PORT_FUNC_EXT_INT
#define PORTC7_FUNC_I2S_DIN         0x02
#define PORTC7_FUNC_I2C1_DAT        0x03
#define PORTC7_FUNC_PWM7            PORT_FUNC_PWM
#define PORTC7_FUNC_SSP1_DIN        0x05
#define PORTC7_FUNC_SSP0_DIN        0x06
#define PORTC7_FUNC_UART1_TXD       0x07
#define PORTC7_FUNC_UART0_TXD       0x08
#define PORTC7_FUNC_ADC7            0x09
#define PORTC7_FUNC_PWM_EN7         PORT_FUNC_PWM_EN

#define PORTD0_FUNC_D0              PORT_FUNC_GPIO
#define PORTD0_FUNC_INT24           PORT_FUNC_EXT_INT
#define PORTD0_FUNC_I2C0_CLK        0x02
#define PORTD0_FUNC_I2S_CLK         0x03
#define PORTD0_FUNC_PWM0            PORT_FUNC_PWM
#define PORTD0_FUNC_SSP0_CLK        0x05
#define PORTD0_FUNC_SSP1_CLK        0x06
#define PORTD0_FUNC_UART0_RXD       0x07
#define PORTD0_FUNC_UART1_RXD       0x08
#define PORTD0_FUNC_UART0_CTS       0x09
#define PORTD0_FUNC_PWM_EN4         PORT_FUNC_PWM_EN
#define PORTC5_FUNC_SW_DV           0x0e

#define PORTD1_FUNC_D1              PORT_FUNC_GPIO
#define PORTD1_FUNC_INT25           PORT_FUNC_EXT_INT
#define PORTD1_FUNC_I2C0_DAT        0x02
#define PORTD1_FUNC_I2S_FRM         0x03
#define PORTD1_FUNC_PWM1            PORT_FUNC_PWM
#define PORTD1_FUNC_SSP0_CSN        0x05
#define PORTD1_FUNC_SSP1_CSN        0x06
#define PORTD1_FUNC_UART0_TXD       0x07
#define PORTD1_FUNC_UART1_TXD       0x08
#define PORTD1_FUNC_UART0_RTS       0x09
#define PORTD1_FUNC_PWM_EN5         PORT_FUNC_PWM_EN

#define PORTD2_FUNC_D2              PORT_FUNC_GPIO
#define PORTD2_FUNC_INT26           PORT_FUNC_EXT_INT
#define PORTD2_FUNC_I2C1_CLK        0x02
#define PORTD2_FUNC_I2S_DOUT        0x03
#define PORTD2_FUNC_PWM2            PORT_FUNC_PWM
#define PORTD2_FUNC_SSP0_DOUT       0x05
#define PORTD2_FUNC_SSP1_DOUT       0x06
#define PORTD2_FUNC_UART1_RXD       0x07
#define PORTD2_FUNC_UART0_RXD       0x08
#define PORTD2_FUNC_UART1_CTS       0x09
#define PORTD2_FUNC_PWM_EN6         PORT_FUNC_PWM_EN

#define PORTD3_FUNC_D3              PORT_FUNC_GPIO
#define PORTD3_FUNC_INT27           PORT_FUNC_EXT_INT
#define PORTD3_FUNC_I2C1_DAT        0x02
#define PORTD3_FUNC_I2S_DIN         0x03
#define PORTD3_FUNC_PWM3            PORT_FUNC_PWM
#define PORTD3_FUNC_SSP0_DIN        0x05
#define PORTD3_FUNC_SSP1_DIN        0x06
#define PORTD3_FUNC_UART1_TXD       0x07
#define PORTD3_FUNC_UART0_TXD       0x08
#define PORTD3_FUNC_UART1_RTS       0x09
#define PORTD3_FUNC_PWM_EN7         PORT_FUNC_PWM_EN

#define PORTD4_FUNC_D4              PORT_FUNC_GPIO
#define PORTD4_FUNC_INT28           PORT_FUNC_EXT_INT
#define PORTD4_FUNC_I2S_CLK         0x02
#define PORTD4_FUNC_I2C0_CLK        0x03
#define PORTD4_FUNC_PWM4            PORT_FUNC_PWM
#define PORTD4_FUNC_SSP1_CLK        0x05
#define PORTD4_FUNC_SSP0_CLK        0x06
#define PORTD4_FUNC_UART0_RXD       0x07
#define PORTD4_FUNC_UART1_RXD       0x08
#define PORTD4_FUNC_UART0_CTS       0x09
#define PORTD4_FUNC_PWM_IN4         PORT_FUNC_PWM_EN

#define PORTD5_FUNC_D5              PORT_FUNC_GPIO
#define PORTD5_FUNC_INT29           PORT_FUNC_EXT_INT
#define PORTD5_FUNC_I2S_FRM         0x02
#define PORTD5_FUNC_I2C0_DAT        0x03
#define PORTD5_FUNC_PWM5            PORT_FUNC_PWM
#define PORTD5_FUNC_SSP1_CSN        0x05
#define PORTD5_FUNC_SSP0_CSN        0x06
#define PORTD5_FUNC_UART0_TXD       0x07
#define PORTD5_FUNC_UART1_TXD       0x08
#define PORTD5_FUNC_UART0_RTS       0x09
#define PORTD5_FUNC_PWM_IN5         PORT_FUNC_PWM_EN

#define PORTD6_FUNC_D6              PORT_FUNC_GPIO
#define PORTD6_FUNC_INT30           PORT_FUNC_EXT_INT
#define PORTD6_FUNC_I2S_DOUT        0x02
#define PORTD6_FUNC_I2C1_CLK        0x03
#define PORTD6_FUNC_PWM6            PORT_FUNC_PWM
#define PORTD6_FUNC_SSP1_DOUT       0x05
#define PORTD6_FUNC_SSP0_DOUT       0x06
#define PORTD6_FUNC_UART1_RXD       0x07
#define PORTD6_FUNC_UART0_RXD       0x08
#define PORTD6_FUNC_UART1_CTS       0x09
#define PORTD6_FUNC_PWM_IN6         PORT_FUNC_PWM_EN

#define PORTD7_FUNC_D7              PORT_FUNC_GPIO
#define PORTD7_FUNC_INT31           PORT_FUNC_EXT_INT
#define PORTD7_FUNC_I2S_DIN         0x02
#define PORTD7_FUNC_I2C1_DAT        0x03
#define PORTD7_FUNC_PWM7            PORT_FUNC_PWM
#define PORTD7_FUNC_SSP1_DIN        0x05
#define PORTD7_FUNC_SSP0_DIN        0x06
#define PORTD7_FUNC_UART1_TXD       0x07
#define PORTD7_FUNC_UART0_TXD       0x08
#define PORTD7_FUNC_UART1_RTS       0x09
#define PORTD7_FUNC_PWM_IN7         PORT_FUNC_PWM_EN
#define PORTD7_FUNC_SSP0_CLK        0x0d

#endif // DRIVER_IOMUX_H

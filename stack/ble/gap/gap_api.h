/**
 * Copyright (c) 2019, Tsingtao Freqchip
 * 
 * All rights reserved.
 * 
 * 
 */
#ifndef GAP_API_H
#define GAP_API_H

/*
 * INCLUDES (包含头文件)
 */
#include <stdio.h>
#include <stdint.h>

/*
 * MACROS (宏定义)
 */


enum gap_event
{
	GAP_EVT_DEV_CFG_DONE = 0,				/* Device coinfiguration done, 设备配置完成,       central, peripheral 角色等 */
	GAP_EVT_SVC_INIT_DONE,					/* Service initialization done, profile service初始化完成. */

	GAP_EVT_BOND_INFO_IND,					/* Bond information indication, after a successful bonding, 绑定成功后，收到绑定信息，LTK等等 */
	GAP_EVT_BOND_INFO_REQ,					/* Bond information request, 请求保存在flash中的bond information */

	GAP_EVT_CONNECTED,						/* Device connected to peer device, 和对方设备建立了BLE连接 */
	GAP_EVT_ENCRYPTED,						/* BLE link is encrypted, BLE连接加密成功 */
	GAP_EVT_DISCONNECTED,					/* Device disconnected from peer device, 和对方设备断开了BLE连接 */

	GAP_EVT_PARAM_UPDATE_IND,               /* Connection paramters update indication, Link layer收到parameter update indication */
	GAP_EVT_PARAM_UPDATED,                  /* Connection paramters successfully updated, Link layer参数更新成功 */
    GAP_EVT_PARAM_UPDATE_REJECTED,          /* Connection paramters update rejected, Link layer参数更新请求被拒绝 */

	GAP_EVT_ADV_END,                        /* Advertising ended, 广播超时停止 */

	GAP_EVT_SCAN_COMPLETED,
	GAP_EVT_ADV_REPORT,

	GAP_EVT_CONNECT_FAILED,

    GAP_EVT_BOND_SUCCESS,

};


/*
 * TYPEDEFS (类型定义)
 */

/*
 * CONSTANTS (常量定义)
 */
#define	GAP_ROLE_TYPE_PERIPHERAL	0x01
#define	GAP_ROLE_TYPE_CENTRAL		0x02
#define	GAP_ROLE_TYPE_BROADCASTER	0x04
#define	GAP_ROLE_TYPE_OBSERVER		0x08

#define GAP_ADDR_TYPE_PUBLIC						0x01
#define GAP_ADDR_TYPE_PRIVATE						0x02
#define GAP_ADDR_TYPE_RANDOM_RESOVABLE				0x03
#define GAP_ADDR_TYPE_RANDOM_NONE_RESOVABLE			0x04

/** @defgroup GAP_ADVCHAN_DEFINES GAP Advertisement Channel Map
 * @{
 */
#define GAP_ADV_CHAN_37  0x01  //!< Advertisement Channel 37
#define GAP_ADV_CHAN_38  0x02  //!< Advertisement Channel 38
#define GAP_ADV_CHAN_39  0x04  //!< Advertisement Channel 39
#define GAP_ADV_CHAN_ALL (GAP_ADV_CHAN_37 | GAP_ADV_CHAN_38 | GAP_ADV_CHAN_39) //!< All Advertisement Channels Enabled

#define GAP_ADV_TYPE_UNDIRECT	0x01
#define GAP_ADV_TYPE_DIRECT		0x02
#define GAP_ADV_TYPE_NON_CONN	0x03

/** @defgroup GAP_ADVTYPE_DEFINES GAP Advertisement Data Types
 * These are the data type identifiers for the data tokens in the advertisement data field.
 * @{
 */
#define GAP_ADTVYPE_FLAGS						 						 0x01 //!< Discovery Mode: @ref GAP_ADTYPE_FLAGS_MODES	
#define GAP_ADVTYPE_16BIT_MORE                   0x02 //!< Service: More 16-bit UUIDs available
#define GAP_ADVTYPE_16BIT_COMPLETE               0x03 //!< Service: Complete list of 16-bit UUIDs
#define GAP_ADVTYPE_32BIT_MORE                   0x04 //!< Service: More 32-bit UUIDs available
#define GAP_ADVTYPE_32BIT_COMPLETE               0x05 //!< Service: Complete list of 32-bit UUIDs
#define GAP_ADVTYPE_128BIT_MORE                  0x06 //!< Service: More 128-bit UUIDs available
#define GAP_ADVTYPE_128BIT_COMPLETE              0x07 //!< Service: Complete list of 128-bit UUIDs
#define GAP_ADVTYPE_LOCAL_NAME_SHORT             0x08 //!< Shortened local name
#define GAP_ADVTYPE_LOCAL_NAME_COMPLETE          0x09 //!< Complete local name
#define GAP_ADVTYPE_POWER_LEVEL                  0x0A //!< TX Power Level: 0xXX: -127 to +127 dBm
#define GAP_ADVTYPE_OOB_CLASS_OF_DEVICE          0x0D //!< Simple Pairing OOB Tag: Class of device (3 octets)
#define GAP_ADVTYPE_OOB_SIMPLE_PAIRING_HASHC     0x0E //!< Simple Pairing OOB Tag: Simple Pairing Hash C (16 octets)
#define GAP_ADVTYPE_OOB_SIMPLE_PAIRING_RANDR     0x0F //!< Simple Pairing OOB Tag: Simple Pairing Randomizer R (16 octets)
#define GAP_ADVTYPE_SM_TK                        0x10 //!< Security Manager TK Value
#define GAP_ADVTYPE_SM_OOB_FLAG                  0x11 //!< Secutiry Manager OOB Flags
#define GAP_ADVTYPE_SLAVE_CONN_INTERVAL_RANGE    0x12 //!< Min and Max values of the connection interval (2 octets Min, 2 octets Max) (0xFFFF indicates no conn interval min or max)
#define GAP_ADVTYPE_SIGNED_DATA                  0x13 //!< Signed Data field
#define GAP_ADVTYPE_SERVICES_LIST_16BIT          0x14 //!< Service Solicitation: list of 16-bit Service UUIDs
#define GAP_ADVTYPE_SERVICES_LIST_128BIT         0x15 //!< Service Solicitation: list of 128-bit Service UUIDs
#define GAP_ADVTYPE_SERVICE_DATA                 0x16 //!< Service Data - 16-bit UUID
#define GAP_ADVTYPE_PUBLIC_TARGET_ADDR           0x17 //!< Public Target Address
#define GAP_ADVTYPE_RANDOM_TARGET_ADDR           0x18 //!< Random Target Address
#define GAP_ADVTYPE_APPEARANCE                   0x19 //!< Appearance
#define GAP_ADVTYPE_ADV_INTERVAL                 0x1A //!< Advertising Interval
#define GAP_ADVTYPE_LE_BD_ADDR                   0x1B //!< LE Bluetooth Device Address
#define GAP_ADVTYPE_LE_ROLE                      0x1C //!< LE Role
#define GAP_ADVTYPE_SIMPLE_PAIRING_HASHC_256     0x1D //!< Simple Pairing Hash C-256
#define GAP_ADVTYPE_SIMPLE_PAIRING_RANDR_256     0x1E //!< Simple Pairing Randomizer R-256
#define GAP_ADVTYPE_SERVICE_DATA_32BIT           0x20 //!< Service Data - 32-bit UUID
#define GAP_ADVTYPE_SERVICE_DATA_128BIT          0x21 //!< Service Data - 128-bit UUID
#define GAP_ADVTYPE_3D_INFO_DATA                 0x3D //!< 3D Information Data
#define GAP_ADVTYPE_MANUFACTURER_SPECIFIC        0xFF //!< Manufacturer Specific Data: first 2 octets contain the Company Identifier Code followed by the additional manufacturer specific data
/** @} End GAP_ADVTYPE_DEFINES */


typedef void(* gap_callback_func_t)(void * param);


typedef struct
{
	uint8_t gap_role_type;
	uint8_t addr_type;
	uint16_t mtu_size;
}gap_cfg_t;


typedef struct
{
	uint8_t     adv_mode;
	uint8_t     adv_addr_type;
	uint16_t    adv_intv_min;
	uint16_t    adv_intv_max;
    uint8_t     adv_chnl_map;
    uint8_t     adv_dis_mode;
    uint8_t     adv_filt_policy;
}gap_adv_param_t;

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

/** @function group ble peripheral device APIs (ble外设相关的API)
 * @{
 */

/*********************************************************************
 * @fn      gap_set_cb_func
 *
 * @brief   Gap callback functions set. Links application layer callbacks to gap layer.
 *			用于设置Gap的回调函数. 把应用层的回调注册到gap层.
 *
 * @param   id - gap events.
 *			func - application layer callback function.
 *
 * @return  None.
 */
void gap_set_cb_func(uint8_t id, gap_callback_func_t func);

void gap_dev_config(gap_cfg_t *p_gap_cfg);


/*********************************************************************
 * @fn      gap_set_advertising_data
 *
 * @brief   Set ble advertising data.
 *			用于设置广播的内容.
 *
 * @param   p_adv_data - pointer to advertising data.
 *			adv_data_len - advertising data length
 *
 * @return  None.
 */
void gap_set_advertising_data(uint8_t *p_adv_data, uint8_t adv_data_len);

/*********************************************************************
 * @fn      gap_set_scan_response_data
 *
 * @brief   Set ble scan response data.
 *			用于设置被主机扫描的相应的内容.
 *
 * @param   p_scan_response_data - pointer to scan response data.
 *			scan_response_data_len - scan response data length.
 *
 * @return  None.
 */
void gap_set_scan_response_data(uint8_t *p_scan_response_data, uint8_t scan_response_data_len);
	  
 /*********************************************************************
 * @fn      gap_start_advertising
 *
 * @brief   Start advertising.
 *			开始广播.
 *
 * @param   p_adv_param - adv parameters.
 *
 * @return  None.
 */
void gap_start_advertising(gap_adv_param_t *p_adv_param);

 /*********************************************************************
 * @fn      gap_stop_advertising
 *
 * @brief   Stop advertising.
 *			停止广播.
 *
 * @param   None.
 *
 * @return  None.
 */
 void gap_stop_advertising(void);

 /*********************************************************************
 * @fn      gap_address_get
 *
 * @brief   Fetch BLE mac address.
 *
 * @param   None.
 *
 * @return  Mac address. Note: Please copy BLE mac address to a 6 bytes buffer
 */
uint8_t *gap_address_get(void);

 /*********************************************************************
 * @fn      gap_address_set
 *
 * @brief   Configure BLE mac address.
 *
 * @param   mac: 6 bytes MAC address
 *
 * @return  None.
 */
void gap_address_set(uint8_t *mac);

#endif // end of #ifndef GAP_API_H

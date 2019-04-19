/**
 * Copyright (c) 2019, Tsingtao Freqchip
 * 
 * All rights reserved.
 * 
 * 
 */

#ifndef GATT_SIG_UUID_H
#define GATT_SIG_UUID_H


/*********************************************************************
 * INCLUDES
 */
#include <stdio.h>
#include <stdint.h>

/*********************************************************************
 * CONSTANTS
 */
 // SIG UUID size is always 2.
#define ATT_BT_UUID_SIZE 2

/*
 * WARNING: The 16-bit UUIDs are assigned by the Bluetooth SIG and published
 *          in the Bluetooth Assigned Numbers page. Do not change these values.
 *          Changing them will cause Bluetooth interoperability issues.
 */

/**
 * GATT Services
 */
#define GAP_SERVICE_UUID                           0x1800 // Generic Access Profile
#define GATT_SERVICE_UUID                          0x1801 // Generic Attribute Profile

/**
 * GATT Declarations
 */
#define GATT_PRIMARY_SERVICE_UUID                  0x2800 // Primary Service
#define GATT_SECONDARY_SERVICE_UUID                0x2801 // Secondary Service
#define GATT_INCLUDE_UUID                          0x2802 // Include
#define GATT_CHARACTER_UUID                        0x2803 // Characteristic

/**
 * GATT Descriptors
 */
#define GATT_CHAR_EXT_PROPS_UUID                   0x2900 // Characteristic Extended Properties
#define GATT_CHAR_USER_DESC_UUID                   0x2901 // Characteristic User Description
#define GATT_CLIENT_CHAR_CFG_UUID                  0x2902 // Client Characteristic Configuration
#define GATT_SERV_CHAR_CFG_UUID                    0x2903 // Server Characteristic Configuration
#define GATT_CHAR_FORMAT_UUID                      0x2904 // Characteristic Presentation Format
#define GATT_CHAR_AGG_FORMAT_UUID                  0x2905 // Characteristic Aggregate Format
#define GATT_VALID_RANGE_UUID                      0x2906 // Valid Range
#define GATT_EXT_REPORT_REF_UUID                   0x2907 // External Report Reference Descriptor
#define GATT_REPORT_REF_UUID                       0x2908 // Report Reference Descriptor

/**
 * GATT Characteristics
 */
#define GATT_DEVICE_NAME_UUID                           0x2A00 // Device Name
#define GATT_APPEARANCE_UUID                            0x2A01 // Appearance
#define GATT_PERI_PRIVACY_FLAG_UUID                     0x2A02 // Peripheral Privacy Flag
#define GATT_RECONNECT_ADDR_UUID                        0x2A03 // Reconnection Address
#define GATT_PERI_CONN_PARAM_UUID                       0x2A04 // Peripheral Preferred Connection Parameters
#define GATT_SERVICE_CHANGED_UUID                       0x2A05 // Service Changed

/*********************************************************************
 * MACROS
 */

#define BUILD_UINT16(loByte, hiByte) \
          ((uint16_t)(((loByte) & 0x00FF) + (((hiByte) & 0x00FF) << 8)))

#define HI_UINT16(a) (((a) >> 8) & 0xFF)
#define LO_UINT16(a) ((a) & 0xFF)

/*********************************************************************
 * TYPEDEFS
 */

/*********************************************************************
 * VARIABLES
 */

/**
 * GATT Services
 */
extern uint8_t gapServiceUUID[];
extern uint8_t gattServiceUUID[];

/**
 * GATT Attribute Types
 */
extern uint8_t PRIMARY_SVC_UUID[];
extern uint8_t SECONDARY_SVC_UUID[];
extern uint8_t INCLUDE_UUID[];
extern uint8_t CHARACTER_UUID[];

/**
 * GATT Characteristic Descriptors
 */
extern uint8_t CHAR_EXT_PROPS_UUID[];
extern uint8_t CHAR_USER_DESC_UUID[];
extern uint8_t CLIENT_CHAR_CFG_UUID[];
extern uint8_t SERV_CHAR_CFG_UUID[];
extern uint8_t CHAR_FORMAT_UUID[];
extern uint8_t CHAR_AGG_FORMAT_UUID[];
extern uint8_t VALID_RANGE_UUID[];
extern uint8_t EXT_REPORT_REF_UUID[];
extern uint8_t REPORT_REF_UUID[];

/**
 * GATT Characteristic Types
 */
extern uint8_t DEVICE_NAME_UUID[];
extern uint8_t APPEARANCE_UUID[];
extern uint8_t PERI_PRIVACY_FLAG_UUID[];
extern uint8_t RECONNECT_ADDR_UUID[];
extern uint8_t PERI_CONN_PARAM_UUID[];
extern uint8_t SERVICE_CHANGED_UUID[];
extern uint8_t manuNameUUID[];
extern uint8_t serialNumUUID[];
extern uint8_t manuAddrUUID[];




#endif /* GATT_SIG_UUID_H */

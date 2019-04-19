/**
 * Copyright (c) 2019, Tsingtao Freqchip
 * 
 * All rights reserved.
 * 
 * 
 */

/*********************************************************************
 * INCLUDES
 */
#include "gatt_sig_uuid.h"

/*********************************************************************
 * CONSTANTS
 */

/*********************************************************************
 * MACROS
 */

/*********************************************************************
 * TYPEDEFS
 */

/*********************************************************************
 * VARIABLES
 */
/**
 * GATT Services
 */
// Generic Access Profile Service UUID
uint8_t gapServiceUUID[ATT_BT_UUID_SIZE] =
{
  LO_UINT16( GAP_SERVICE_UUID ), HI_UINT16( GAP_SERVICE_UUID )
};

// Generic Attribute Profile Service UUID
uint8_t gattServiceUUID[ATT_BT_UUID_SIZE] =
{
  LO_UINT16( GATT_SERVICE_UUID ), HI_UINT16( GATT_SERVICE_UUID )
};

/**
 * GATT Declarations
 */
// Primary Service UUID
uint8_t PRIMARY_SVC_UUID[ATT_BT_UUID_SIZE] =
{
  LO_UINT16( GATT_PRIMARY_SERVICE_UUID ), HI_UINT16( GATT_PRIMARY_SERVICE_UUID )
};

// Secondary Service UUID
uint8_t SECONDARY_SVC_UUID[ATT_BT_UUID_SIZE] =
{
  LO_UINT16( GATT_SECONDARY_SERVICE_UUID ), HI_UINT16( GATT_SECONDARY_SERVICE_UUID )
};

// Include UUID
uint8_t INCLUDE_UUID[ATT_BT_UUID_SIZE] =
{
  LO_UINT16( GATT_INCLUDE_UUID ), HI_UINT16( GATT_INCLUDE_UUID )
};

// Characteristic UUID
uint8_t CHARACTER_UUID[ATT_BT_UUID_SIZE] =
{
  LO_UINT16( GATT_CHARACTER_UUID ), HI_UINT16( GATT_CHARACTER_UUID )
};

/**
 * GATT Descriptors
 */
// Characteristic Extended Properties UUID
uint8_t CHAR_EXT_PROPS_UUID[ATT_BT_UUID_SIZE] =
{
  LO_UINT16( GATT_CHAR_EXT_PROPS_UUID ), HI_UINT16( GATT_CHAR_EXT_PROPS_UUID )
};

// Characteristic User Description UUID
uint8_t CHAR_USER_DESC_UUID[ATT_BT_UUID_SIZE] =
{
  LO_UINT16( GATT_CHAR_USER_DESC_UUID ), HI_UINT16( GATT_CHAR_USER_DESC_UUID )
};

// Client Characteristic Configuration UUID
uint8_t CLIENT_CHAR_CFG_UUID[ATT_BT_UUID_SIZE] =
{
  LO_UINT16( GATT_CLIENT_CHAR_CFG_UUID ), HI_UINT16( GATT_CLIENT_CHAR_CFG_UUID )
};

// Server Characteristic Configuration UUID
uint8_t SERV_CHAR_CFG_UUID[ATT_BT_UUID_SIZE] =
{
  LO_UINT16( GATT_SERV_CHAR_CFG_UUID ), HI_UINT16( GATT_SERV_CHAR_CFG_UUID )
};

// Characteristic Presentation Format UUID
uint8_t CHAR_FORMAT_UUID[ATT_BT_UUID_SIZE] =
{
  LO_UINT16( GATT_CHAR_FORMAT_UUID ), HI_UINT16( GATT_CHAR_FORMAT_UUID )
};

// Characteristic Aggregate Format UUID
uint8_t CHAR_AGG_FORMAT_UUID[ATT_BT_UUID_SIZE] =
{
  LO_UINT16( GATT_CHAR_AGG_FORMAT_UUID ), HI_UINT16( GATT_CHAR_AGG_FORMAT_UUID )
};

/**
 * GATT Characteristics
 */
// Device Name UUID
uint8_t DEVICE_NAME_UUID[ATT_BT_UUID_SIZE] =
{
  LO_UINT16( GATT_DEVICE_NAME_UUID ), HI_UINT16( GATT_DEVICE_NAME_UUID )
};

// Appearance UUID
uint8_t APPEARANCE_UUID[ATT_BT_UUID_SIZE] =
{
  LO_UINT16( GATT_APPEARANCE_UUID ), HI_UINT16( GATT_APPEARANCE_UUID )
};

// Peripheral Privacy Flag UUID
uint8_t PERI_PRIVACY_FLAG_UUID[ATT_BT_UUID_SIZE] =
{
  LO_UINT16( GATT_PERI_PRIVACY_FLAG_UUID ), HI_UINT16( GATT_PERI_PRIVACY_FLAG_UUID )
};

// Reconnection Address UUID
uint8_t RECONNECT_ADDR_UUID[ATT_BT_UUID_SIZE] =
{
  LO_UINT16( GATT_RECONNECT_ADDR_UUID ), HI_UINT16( GATT_RECONNECT_ADDR_UUID )
};

// Peripheral Preferred Connection Parameters UUID
uint8_t PERI_CONN_PARAM_UUID[ATT_BT_UUID_SIZE] =
{
  LO_UINT16( GATT_PERI_CONN_PARAM_UUID ), HI_UINT16( GATT_PERI_CONN_PARAM_UUID )
};

// Service Changed UUID
uint8_t SERVICE_CHANGED_UUID[ATT_BT_UUID_SIZE] =
{
  LO_UINT16( GATT_SERVICE_CHANGED_UUID ), HI_UINT16( GATT_SERVICE_CHANGED_UUID )
};

// Valid Range UUID
uint8_t VALID_RANGE_UUID[ATT_BT_UUID_SIZE] =
{
  LO_UINT16( GATT_VALID_RANGE_UUID ), HI_UINT16( GATT_VALID_RANGE_UUID )
};

// External Report Reference Descriptor
uint8_t EXT_REPORT_REF_UUID[ATT_BT_UUID_SIZE] =
{
  LO_UINT16( GATT_EXT_REPORT_REF_UUID ), HI_UINT16( GATT_EXT_REPORT_REF_UUID )
};

// Report Reference characteristic descriptor
uint8_t REPORT_REF_UUID[ATT_BT_UUID_SIZE] =
{
  LO_UINT16( GATT_REPORT_REF_UUID ), HI_UINT16( GATT_REPORT_REF_UUID )
};




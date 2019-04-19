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
#include <stdio.h>
#include <string.h>
#include "osi.h"
#include "gap_api.h"
#include "gatt_api.h"
#include "gatt_sig_uuid.h"

#include "simple_gatt_profile.h"


/*
 * MACROS (宏定义)
 */

/*
 * CONSTANTS (常量定义)
 */


// Simple GATT Profile Service UUID: 0xFFF0
uint8_t sp_svc_uuid[UUID_SIZE_2] =
{ 
  LO_UINT16(SP_SVC_UUID), HI_UINT16(SP_SVC_UUID)
};

/******************************* Characteristic 1 defination *******************************/
// Characteristic 1 UUID: 0xFFF1
uint8_t sp_char1_uuid[UUID_SIZE_2] =
{ 
  LO_UINT16(SP_CHAR1_UUID), HI_UINT16(SP_CHAR1_UUID)
};
// Characteristic 1 data 
#define SP_CHAR1_VALUE_LEN  100
uint8_t sp_char1_value[SP_CHAR1_VALUE_LEN] = {0};
// Characteristic 1 User Description
#define SP_CHAR1_DESC_LEN   17
uint8_t sp_char1_desc[SP_CHAR1_DESC_LEN] = "Characteristic 1";

/******************************* Characteristic 2 defination *******************************/
// Characteristic 2 UUID: 0xFFF2
uint8_t sp_char2_uuid[UUID_SIZE_2] =
{ 
  LO_UINT16(SP_CHAR2_UUID), HI_UINT16(SP_CHAR2_UUID)
};
// Characteristic 2 data 
#define SP_CHAR2_VALUE_LEN  100
uint8_t sp_char2_value[SP_CHAR2_VALUE_LEN] = {0};
// Characteristic 2 User Description
#define SP_CHAR2_DESC_LEN   17
uint8_t sp_char2_desc[SP_CHAR2_DESC_LEN] = "Characteristic 2";

/******************************* Characteristic 3 defination *******************************/
// Characteristic 3 UUID: 0xFFF3
uint8_t sp_char3_uuid[UUID_SIZE_2] =
{ 
  LO_UINT16(SP_CHAR3_UUID), HI_UINT16(SP_CHAR3_UUID)
};
// Characteristic 3 data 
#define SP_CHAR3_VALUE_LEN  100
uint8_t sp_char3_value[SP_CHAR3_VALUE_LEN] = {0};
// Characteristic 3 User Description
#define SP_CHAR3_DESC_LEN   17
uint8_t sp_char3_desc[SP_CHAR3_DESC_LEN] = "Characteristic 3";

/******************************* Characteristic 4 defination *******************************/
// Characteristic 4 UUID: 0xFFF4
uint8_t sp_char4_uuid[UUID_SIZE_2] =
{ 
  LO_UINT16(SP_CHAR4_UUID), HI_UINT16(SP_CHAR4_UUID)
};
// Characteristic 4 data 
#define SP_CHAR4_VALUE_LEN  100
uint8_t sp_char4_value[SP_CHAR4_VALUE_LEN] = {0};
// Characteristic 4 client characteristic configuration
#define SP_CHAR4_CCC_LEN   2
uint8_t sp_char4_ccc[SP_CHAR4_CCC_LEN] = {0};
// Characteristic 4 User Description
#define SP_CHAR4_DESC_LEN   17
uint8_t sp_char4_desc[SP_CHAR4_DESC_LEN] = "Characteristic 4";

/******************************* Characteristic 5 defination *******************************/
// Characteristic 5 UUID: 0xFFF5
uint8_t sp_char5_uuid[UUID_SIZE_2] =
{ 
  LO_UINT16(SP_CHAR5_UUID), HI_UINT16(SP_CHAR5_UUID)
};
// Characteristic 5 data 
#define SP_CHAR5_VALUE_LEN  100
uint8_t sp_char5_value[SP_CHAR5_VALUE_LEN] = {0};
// Characteristic 5 User Description
#define SP_CHAR5_DESC_LEN   17
uint8_t sp_char5_desc[SP_CHAR5_DESC_LEN] = "Characteristic 5";

/*
 * TYPEDEFS (类型定义)
 */

/*
 * GLOBAL VARIABLES (全局变量)
 */


/*
 * LOCAL VARIABLES (本地变量)
 */

/*********************************************************************
 * Profile Attributes - Table
 * 每一项都是一个attribute的定义。
 * 第一个attribute为Service 的的定义。
 * 每一个特征值(characteristic)的定义，都至少包含三个attribute的定义；
 * 1. 特征值声明(Characteristic Declaration)
 * 2. 特征值的值(Characteristic value)
 * 3. 特征值描述符(Characteristic description)
 * 如果有notification 或者indication 的功能，则会包含四个attribute的定义，除了前面定义的三个，还会有一个特征值客户端配置(client characteristic configuration)。
 *
 */

gatt_attribute_t simple_profile_att_table[SP_IDX_NB] =
{
	// Simple gatt Service Declaration
	[SP_IDX_SERVICE]                        =   {
    												{ UUID_SIZE_2, PRIMARY_SVC_UUID },		/* UUID */
    												GATT_PROP_READ, 						/* Permissions */
    												UUID_SIZE_2, 							/* Max size of the value */		/* Service UUID size in service declaration */
    												sp_svc_uuid								/* Value of the attribute */	/* Service UUID value in service declaration */
												},

		// Characteristic 1 Declaration           
        [SP_IDX_CHAR1_DECLARATION]          =   {
													{ UUID_SIZE_2, CHARACTER_UUID }, 		/* UUID */
													GATT_PROP_READ,						    /* Permissions */
													0, 										/* Max size of the value */
													NULL									/* Value of the attribute */
												},
		// Characteristic 1 Value                  
		[SP_IDX_CHAR1_VALUE]                =   {
													{ UUID_SIZE_2, sp_char1_uuid }, 		/* UUID */
													GATT_PROP_READ | GATT_PROP_WRITE, 	    /* Permissions */
													SP_CHAR1_VALUE_LEN, 						/* Max size of the value */
													sp_char1_value							/* Value of the attribute */	/* Can assign a buffer here, or can be assigned in the application by user */
												},             
		// Characteristic 1 User Description
		[SP_IDX_CHAR1_USER_DESCRIPTION]     =   {
													{ UUID_SIZE_2, CHAR_USER_DESC_UUID }, 	/* UUID */
													GATT_PROP_READ, 						/* Permissions */
													SP_CHAR1_DESC_LEN, 						/* Max size of the value */
													sp_char1_desc							/* Value of the attribute */
												},


		// Characteristic 2 Declaration 		  
		[SP_IDX_CHAR2_DECLARATION]			=	{
													{ UUID_SIZE_2, CHARACTER_UUID },		/* UUID */
													GATT_PROP_READ, 						/* Permissions */
													0,									    /* Max size of the value */
													NULL									/* Value of the attribute */
												},
		// Characteristic 2 Value				   
		[SP_IDX_CHAR2_VALUE]				=	{
													{ UUID_SIZE_2, sp_char2_uuid },			/* UUID */
													GATT_PROP_READ,							/* Permissions */
													SP_CHAR2_VALUE_LEN,						/* Max size of the value */
													sp_char2_value							/* Value of the attribute */	/* Can assign a buffer here, or can be assigned in the application by user */
												},			   
		// Characteristic 2 User Description
		[SP_IDX_CHAR2_USER_DESCRIPTION] 	=	{
													{ UUID_SIZE_2, CHAR_USER_DESC_UUID },	/* UUID */
													GATT_PROP_READ, 						/* Permissions */
                                                    SP_CHAR2_DESC_LEN,                      /* Max size of the value */
                                                    sp_char2_desc                           /* Value of the attribute */
												},



		// Characteristic 3 Declaration 		  
		[SP_IDX_CHAR3_DECLARATION]			=	{
													{ UUID_SIZE_2, CHARACTER_UUID },		/* UUID */
													GATT_PROP_READ, 						/* Permissions */
													0,										/* Max size of the value */
													NULL									/* Value of the attribute */
												},
		// Characteristic 3 Value				   
		[SP_IDX_CHAR3_VALUE]				=	{
													{ UUID_SIZE_2, sp_char3_uuid },		    /* UUID */
													GATT_PROP_WRITE,						/* Permissions */
                                                    SP_CHAR3_VALUE_LEN,                     /* Max size of the value */
                                                    sp_char3_value                          /* Value of the attribute */    /* Can assign a buffer here, or can be assigned in the application by user */
												},			   
		// Characteristic 3 User Description
		[SP_IDX_CHAR3_USER_DESCRIPTION] 	=	{
													{ UUID_SIZE_2, CHAR_USER_DESC_UUID },	/* UUID */
													GATT_PROP_READ, 						/* Permissions */
                                                    SP_CHAR3_DESC_LEN,                      /* Max size of the value */
                                                    sp_char3_desc                           /* Value of the attribute */
												},


		// Characteristic 4 Declaration 		  
		[SP_IDX_CHAR4_DECLARATION]			=	{
													{ UUID_SIZE_2, CHARACTER_UUID },		/* UUID */
													GATT_PROP_READ, 						/* Permissions */
													0,										/* Max size of the value */
													NULL									/* Value of the attribute */
												},
		// Characteristic 4 Value				   
		[SP_IDX_CHAR4_VALUE]				=	{
													{ UUID_SIZE_2, sp_char4_uuid },			    /* UUID */
													GATT_PROP_WRITE | GATT_PROP_NOTIFICATION,	/* Permissions */
                                                    SP_CHAR4_VALUE_LEN,                         /* Max size of the value */
                                                    sp_char4_value                              /* Value of the attribute */    /* Can assign a buffer here, or can be assigned in the application by user */
												},			   
		// Characteristic 4 client characteristic configuration				   
		[SP_IDX_CHAR4_CFG]					=	{
													{ UUID_SIZE_2, CLIENT_CHAR_CFG_UUID },		/* UUID */
													GATT_PROP_READ | GATT_PROP_WRITE,			/* Permissions */
													SP_CHAR4_CCC_LEN,							/* Max size of the value */
													sp_char4_ccc								/* Value of the attribute */	/* Can assign a buffer here, or can be assigned in the application by user */
												},			   
		// Characteristic 4 User Description
		[SP_IDX_CHAR4_USER_DESCRIPTION] 	=	{
													{ UUID_SIZE_2, CHAR_USER_DESC_UUID },		/* UUID */
													GATT_PROP_READ, 							/* Permissions */
                                                    SP_CHAR4_DESC_LEN,                          /* Max size of the value */
                                                    sp_char4_desc                               /* Value of the attribute */
												},


		// Characteristic 5 Declaration 		  
		[SP_IDX_CHAR5_DECLARATION]			=	{
													{ UUID_SIZE_2, CHARACTER_UUID },			/* UUID */
													GATT_PROP_READ, 							/* Permissions */
													0,											/* Max size of the value */
													NULL										/* Value of the attribute */
												},
		// Characteristic 5 Value				   
		[SP_IDX_CHAR5_VALUE]				=	{
													{ UUID_SIZE_2, sp_char5_uuid },				    /* UUID */
													GATT_PROP_AUTHEN_WRITE | GATT_PROP_AUTHEN_READ,	/* Permissions */
                                                    SP_CHAR5_VALUE_LEN,                             /* Max size of the value */
                                                    sp_char5_value                                  /* Value of the attribute */    /* Can assign a buffer here, or can be assigned in the application by user */
												},			   
		// Characteristic 5 User Description
		[SP_IDX_CHAR5_USER_DESCRIPTION] 	=	{
													{ UUID_SIZE_2, CHAR_USER_DESC_UUID },		/* UUID */
													GATT_PROP_READ, 						    /* Permissions */
                                                    SP_CHAR5_DESC_LEN,                          /* Max size of the value */
                                                    sp_char5_desc                               /* Value of the attribute */
												},
};








/**
 * Copyright (c) 2019, Tsingtao Freqchip
 * 
 * All rights reserved.
 * 
 * 
 */
 
#ifndef GATT_API_H
#define GATT_API_H


 /*
 * INCLUDES (包含头文件)
 */

/*
 * MACROS (宏定义)
 */

/*
 * CONSTANTS (常量定义)
 */
#define UUID_SIZE_2		2	//!< 2 bytes UUID, usually SIG assigned UUID. 2字节的UUID, 通常是SIG指定.
#define UUID_SIZE_16	16	//!< 16 bytes UUID, usually assigned by users. 16字节的UUID, 通常是由用户自定义.

/** @defgroup GATT_PROP_BITMAPS_DEFINES GATT Attribute Access Permissions Bit Fields
 * @{
 */
	
#define GATT_PROP_READ                 	0x0001 //!< Attribute is Readable
#define GATT_PROP_WRITE                	0x0002 //!< Attribute is Writable
#define GATT_PROP_AUTHEN_READ          	0x0004 //!< Read requires Authentication
#define GATT_PROP_AUTHEN_WRITE         	0x0008 //!< Write requires Authentication
#define GATT_PROP_AUTHOR_READ          	0x0010 //!< Read requires Authorization
#define GATT_PROP_AUTHOR_WRITE         	0x0020 //!< Write requires Authorization
#define GATT_PROP_ENCRYPT_READ         	0x0040 //!< Read requires Encryption
#define GATT_PROP_ENCRYPT_WRITE        	0x0080 //!< Write requires Encryption
#define GATT_PROP_NOTIFICATION         	0x0100 //!< Attribute is able to send notification
#define GATT_PROP_INDICATION         	0x0200 //!< Attribute is able to send indication
	  
/** @} End GATT_PERMIT_BITMAPS_DEFINES */

/*
 * TYPEDEFS (类型定义)
 */

/*********************************************************************
 * @fn      gatt_read_handler
 *
 * @brief   User application handles read request in this callback.
 *			应用层在这个回调函数里面处理读的请求。
 *
 * @param   p_read  - the pointer to read buffer. NOTE: It's just a pointer from lower layer, please create the buffer in application layer.
 *					  指向读缓冲区的指针。 请注意这只是一个指针，请在应用程序中分配缓冲区. 为输出函数, 因此为指针的指针.
 *          len     - the pointer to the length of read buffer. Application to assign it.
 *                    读缓冲区的长度，用户应用程序去给它赋值.
 *          att_idx - offset of the attribute value.
 *					  Attribute的偏移量.
 *
 * @return  读请求的长度.
 */
typedef uint16_t (*gatt_read_handler)(uint8_t **p_read, uint16_t *len, uint16_t att_idx);

/*********************************************************************
 * @fn      gatt_write_handler
 *
 * @brief   User application handles write request in this callback.
 *			应用层在这个回调函数里面处理写的请求。
 *
 * @param   write_buf   - the buffer for write
 *			              写操作的数据.
 *					  
 *          len         - the length of write buffer.
 *                        写缓冲区的长度.
 *          att_idx     - offset of the attribute value.
 *					      Attribute的偏移量.
 *
 * @return  写请求的长度.
 */
typedef uint16_t (*gatt_write_handler)(uint8_t *write_buf, uint16_t len, uint16_t att_idx);


/**
* GATT UUID format.
*/
typedef struct
{
	uint8_t size;		//!< Length of UUID (2 or 16 bytes UUIDs: UUID_SIZE_2 or UUID_SIZE_16). UUID长度(2 或者 16字节长度UUID). 
	uint8_t *p_uuid;	//!< Pointer to uuid, could be 2 or 16 bytes array. 指向UUID的指针, 可以是2字节的, 也可以是16字节的数组.
}gatt_uuid_t;

/**
* BLE attribute define format.
*/
typedef struct
{
	gatt_uuid_t 	uuid;
	uint16_t		prop;
	uint16_t		max_size;
	uint8_t			*p_data;
}gatt_attribute_t;

 /**
 * BLE service define format.
 */
typedef struct
{
  gatt_attribute_t	 	*p_att_tb;    	//!< Service's attributes table to add to system attribute database. 本服务的特征值的表格数组, 用于添加到系统的特征值数据库中.
  uint8_t		 		att_nb;    		//!< Service's attributes number. 本服务的特征值的表格数组的特征值个数, 这里包括所有的特征值, value, descriptor, CCC等等等等, 不是单单用于数据传输那几个value值.
  uint16_t				svc_id;			//!< Service ID among all services in current system. 每个服务都会在系统里被分配一个特定的身份识别ID, 我们在svc_id中记录,这只是系统内部的, 注意这个SIG要求定义的全宇宙唯一UUID不同.
  gatt_read_handler 	read_handler;	//!< Read request callback function. 读请求回调函数指针.
  gatt_write_handler 	write_handler; 	//!< Write request callback function. 写请求回调函数指针.
} gatt_service_t;

 /**
 * BLE notification format.
 */
typedef struct 
{
  uint16_t			svc_id;		//!< Service ID among all services in current system. 每个服务都会在系统里被分配一个特定的身份识别ID, 我们在svc_id中记录,这只是系统内部的, 注意这个SIG要求定义的全宇宙唯一UUID不同.
  uint8_t		 	att_idx;    	//!< Attribute id number in its service attribute table. 需要发送notification的特征值在它service的特征值表格中的位置，这可以从预定义特征值表格数组中轻松复制得到.
} gatt_ntf_t;

 /**
 * BLE indication format.
 */
typedef struct 
{
  uint16_t			svc_id;		//!< Service ID among all services in current system. 每个服务都会在系统里被分配一个特定的身份识别ID, 我们在svc_id中记录,这只是系统内部的, 注意这个SIG要求定义的全宇宙唯一UUID不同.
  uint8_t		 	att_idx;    	//!< Attribute id number in its service attribute table. 需要发送indication的特征值在它service的特征值表格中的位置，这可以从预定义特征值表格数组中轻松复制得到.
} gatt_ind_t;

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
 * @fn      gatt_add_service
 *
 * @brief   Addding a services & characteristics into gatt database.
 *			添加一个服务和各个特征值到gatt的数据库里面去.
 *
 * @param   service - service data to be added.
 *					  需要添加的服务的相关信息.
 *
 * @return  None.
 */
void gatt_add_service(gatt_service_t *p_service);

/*********************************************************************
 * @fn      gatt_notification
 *
 * @brief   Sending notification.
 *			发送notification.
 *
 * @param   ntf_att - in which service and which attribute the notification will be sent
 *					  This parameter contains servcie ID and attribute ID 
 *					  to indicate exact which attribute will be used to send notification.
 *					  指明哪一个服务的哪一个特征值用来发送notification, 用初始化已经确定好的服务ID和特征值ID.
 *			p_data - notification data to be sent.
 *					 发送的内容.
 *			data_len - length of notification data.
 *					   发送内容的长度.
 *
 * @return  None.
 */
void gatt_notification(gatt_ntf_t ntf_att, uint8_t *p_data, uint8_t data_len);
	  
 /*********************************************************************
  * @fn 	 gatt_indication
  *
  * @brief	 Sending indication.
  * 		 发送indication.
  *
  * @param	 ind_att - in which service and which attribute the indication will be sent
  * 				   This parameter contains servcie ID and attribute ID 
  * 				   to indicate exact which attribute will be used to send indication.
  * 				   指明哪一个服务的哪一个特征值用来发送indication, 用初始化已经确定好的服务ID和特征值ID.
  * 		 p_data - indication data to be sent.
  * 				  发送的内容.
  * 		 data_len - length of indication data.
  * 					发送内容的长度.
  *
  * @return  None.
  */
void gatt_indication(gatt_ind_t ind_att, uint8_t *p_data, uint8_t data_len);


/*********************************************************************
 * @fn      gatt_indication
 *
 * @brief   Sending indication.
 *			发送indication.
 *
 * @param   ind_att - in which service and which attribute the indication will be sent
 *					  This parameter contains servcie ID and attribute ID 
 *					  to indicate exact which attribute will be used to send indication.
 *					  指明哪一个服务的哪一个特征值用来发送indication, 用初始化已经确定好的服务ID和特征值ID.
 *			p_data - indication data to be sent.
 *					 发送的内容.
 *			data_len - length of indication data.
 *					   发送内容的长度.
 *
 * @return  None.
 */
void gatt_indication(gatt_ind_t ind_att, uint8_t *p_data, uint8_t data_len);

#endif // end of #ifndef GATT_API_H

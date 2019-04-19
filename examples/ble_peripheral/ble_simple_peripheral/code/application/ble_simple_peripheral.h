/**
 * Copyright (c) 2019, Tsingtao Freqchip
 * 
 * All rights reserved.
 * 
 * 
 */
#ifndef BLE_SIMPLE_PERIPHERAL_H
#define BLE_SIMPLE_PERIPHERAL_H
 
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
 * @fn      sp_cb_dev_cfg_done
 *
 * @brief   Read confirm message to the peer. User application invokes it while received BLE_GATT_READ_REQ_IND.
 *			返回读的确认信息给对方，应用层在收到BLE_GATT_READ_REQ_IND后调用这个函数。
 *
 * @param   
 *          msg - os event message from gatt task
 *           gatt任务发送的事件信息.
 *
 * @return  None.
 */
void sp_cfg_dev_init_done_cb(void *arg);

void sp_cfg_svc_init_done_cb(void *arg);


/*********************************************************************
 * @fn      gatt_write_cfm_cb
 *
 * @brief   Write confirm message to the peer. User application invokes it while received BLE_GATT_WRITE_REQ_IND.
 *			返回写的确认信息给对方，应用层在收到BLE_GATT_WRITE_REQ_IND后调用这个函数。
 *
 * @param   
 *          msg - os event message from gatt task
 *           gatt任务发送的事件信息.
 *
 * @return  None.
 */
void sp_gap_connected_cb(void *arg);

void sp_gap_disconnected_cb(void *arg);


void sp_param_update_ind_cb(void *arg);


void sp_param_updated_cb(void *arg);

void sp_param_update_rejected_cb(void *arg);



/*********************************************************************
 * @fn      gatt_msg_handler
 *
 * @brief   the default gatt message handler.
 *			处理从gatt controller传送来的message.
 *
 * @param   msg - msg from gatt controller.
 *					  从gatt controller来的message.
 *
 * @return  None.
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
  
#endif

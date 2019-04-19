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
#include "app.h"
#include "gap_api.h"
#include "gapm_task.h"
#include "gapc_task.h"

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
app_callback_func_t gatt_service_final_ready;

/*
 * LOCAL VARIABLES (本地变量)
 */
static struct gapm_start_advertise_cmd adv_cmd;

/*
 * LOCAL FUNCTIONS (本地函数)
 */

/*
 * EXTERN FUNCTIONS (外部函数)
 */

/*
 * PUBLIC FUNCTIONS (全局函数)
 */
/** @function group ble GAP configuration APIs (ble GAP相关配置的API)
 * @{
 */

/*********************************************************************
 * @fn      gap_set_cb_func
 *
 * @brief   Gap callback functions set. Links application layer callbacks to gap layer.
 *			用于设置Gap的回调函数. 把应用层的回调注册到gap层.
 *
 * @param   event - gap events.
 *			func - application layer callback function.
 *
 * @return  None.
 */
void gap_set_cb_func(uint8_t event, gap_callback_func_t func)
{
	switch (event)
	{
		case GAP_EVT_DEV_CFG_DONE:
			appm_set_cb_func(APP_EVT_ID_DEV_CFG_COMPLETED, (app_callback_func_t)func);
			break;
		
		case GAP_EVT_SVC_INIT_DONE:
            // 注意：APP_EVT_ID_SVC_ADDED 和 APP_EVT_ID_DB_ADDED 两个事件对应的回调函数在
            // app_task.c 里面 由GAPM_PROFILE_ADDED_IND事件里面前后一起调用
            // APP_EVT_ID_SVC_ADDED 会在gatt_api.c中初始化，并且调用，用于att value初始化。
			appm_set_cb_func(APP_EVT_ID_DB_ADDED, (app_callback_func_t)func);
			break;

		case GAP_EVT_BOND_INFO_REQ:
			appm_set_cb_func(APP_EVT_ID_REQ_INFO, (app_callback_func_t)func);
			break;
		
		case GAP_EVT_BOND_INFO_IND:
			appm_set_cb_func(APP_EVT_ID_GOT_INFO, (app_callback_func_t)func);
			break;
		
		case GAP_EVT_CONNECTED:
			appm_set_cb_func(APP_EVT_ID_SLAVER_CONNECTED, (app_callback_func_t)func);
			appm_set_cb_func(APP_EVT_ID_MASTER_CONNECTED, (app_callback_func_t)func);
			break;
			
        case GAP_EVT_PARAM_UPDATE_IND:
            appm_set_cb_func(APP_EVT_ID_PARAM_UPDATE_IND, (app_callback_func_t)func);
            break;

        case GAP_EVT_PARAM_UPDATED:
            appm_set_cb_func(APP_EVT_ID_PARAM_UPDATED, (app_callback_func_t)func);
            break;
            
        case GAP_EVT_PARAM_UPDATE_REJECTED:
            appm_set_cb_func(APP_EVT_ID_PARAM_UPDATE_REJECTED, (app_callback_func_t)func);
            break;
            
        case GAP_EVT_ADV_END:
            appm_set_cb_func(APP_EVT_ID_ADV_END, (app_callback_func_t)func);
            break;

        case GAP_EVT_BOND_SUCCESS:
            appm_set_cb_func(APP_EVT_ID_GOT_INFO, (app_callback_func_t)func);
            break;
        
		default:
			break;
	}
}

void gap_dev_config(gap_cfg_t *p_gap_cfg)
{
	struct gapm_set_dev_config_cmd dev_cfg;
	memset( &dev_cfg, 0, sizeof(struct gapm_set_dev_config_cmd) );
	if ( p_gap_cfg->gap_role_type & GAP_ROLE_TYPE_PERIPHERAL )
		dev_cfg.role |= GAP_ROLE_PERIPHERAL;
	if ( p_gap_cfg->gap_role_type == GAP_ROLE_TYPE_CENTRAL )
		dev_cfg.role |= GAP_ROLE_CENTRAL;
	if ( p_gap_cfg->gap_role_type == GAP_ROLE_TYPE_BROADCASTER )
		dev_cfg.role |= GAP_ROLE_BROADCASTER;
	if ( p_gap_cfg->gap_role_type == GAP_ROLE_TYPE_OBSERVER )
		dev_cfg.role |= GAP_ROLE_OBSERVER;

	if ( p_gap_cfg->addr_type == GAP_ADDR_TYPE_PUBLIC )
		dev_cfg.addr_type = GAPM_CFG_ADDR_PUBLIC;
	else if ( p_gap_cfg->addr_type == GAP_ADDR_TYPE_PRIVATE )
		dev_cfg.addr_type = GAPM_CFG_ADDR_PRIVATE;
	else if ( p_gap_cfg->addr_type == GAP_ADDR_TYPE_RANDOM_RESOVABLE ||  p_gap_cfg->addr_type == GAP_ADDR_TYPE_RANDOM_NONE_RESOVABLE )
		dev_cfg.addr_type = GAPM_CFG_ADDR_CTNL_PRIVACY;

	dev_cfg.max_mtu = p_gap_cfg->mtu_size;
	dev_cfg.max_mps = p_gap_cfg->mtu_size;
	
	appm_set_dev_configuration(NULL);

}


/** @function group ble peripheral device APIs (ble外设相关的API)
 * @{
 */

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
 void gap_set_advertising_data(uint8_t *p_adv_data, uint8_t adv_data_len)
 {
	 adv_cmd.info.host.adv_data_len = adv_data_len;
	 printf(">>>>>>>>>>>>>>>>> Adv data len: %d \r\n", adv_cmd.info.host.adv_data_len);
	 memcpy(adv_cmd.info.host.adv_data, p_adv_data, adv_data_len);
	 
#if 0	//发送GAPM的命令方式
	// Remember to check fuctions in gapm_execute_adv_op() in the future, to see if can remove gapm_util.c;
    APP_LOG("app_status:%d\r\n",ke_state_get(TASK_APP));

    // Check if the advertising procedure is already is progress
    if (ke_state_get(TASK_APP) == APPM_READY)
    {
        // Prepare the GAPM_UPDATE_ADVERTISE_DATA_CMD message
        struct gapm_update_advertise_data_cmd *cmd = KE_MSG_ALLOC(GAPM_UPDATE_ADVERTISE_DATA_CMD,
                                               TASK_GAPM, TASK_APP,
                                               gapm_update_advertise_data_cmd);

        cmd->operation = GAPM_UPDATE_ADVERTISE_DATA;
        cmd->adv_data_len = adv_data_len;
				memcpy(cmd->adv_data, p_adv_data, adv_data_len);
		
        //cmd->scan_rsp_data = NULL;
        //cmd->scan_rsp_data_len = 0;

        // Send the message
        ke_msg_send(cmd);
    }
#endif
    // else ignore the request
#if 0 // 真正通过hci命令改写广播内容的代码
// Another way?
    // retrieve command
    struct gapm_start_advertise_cmd *adv =
        (struct gapm_start_advertise_cmd *) gapm_get_operation_ptr(GAPM_OP_AIR);

    // Set advertising data
    struct hci_le_set_adv_data_cmd *adv_data = KE_MSG_ALLOC(HCI_COMMAND, 0, HCI_LE_SET_ADV_DATA_CMD_OPCODE, hci_le_set_adv_data_cmd);
    // Set data lengh (with added AD_TYPE Flag)
    adv_data->adv_data_len = length + 3;
    // copy provided advertising data
    memcpy(&(adv_data->data.data[3]), data, ADV_DATA_LEN-3);
    // Set ad type flags.
    adv_data->data.data[0] = 2;// Length of ad type flags
    adv_data->data.data[1] = GAP_AD_TYPE_FLAGS;
    adv_data->data.data[2] = GAP_BR_EDR_NOT_SUPPORTED;
    // set mode in ad_type
    switch(adv->info.host.mode)
    {
        // General discoverable mode
        case GAP_GEN_DISCOVERABLE:
        {
            adv_data->data.data[2] |= GAP_LE_GEN_DISCOVERABLE_FLG;
        }
        break;
        // Limited discoverable mode
        case GAP_LIM_DISCOVERABLE:
        {
            adv_data->data.data[2] |= GAP_LE_LIM_DISCOVERABLE_FLG;
        }
        break;
        default:
            break; // do nothing
    }
    /* send the data */
    hci_send_2_controller(adv_data);
#endif

}

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
 void gap_set_scan_response_data(uint8_t *p_scan_response_data, uint8_t scan_response_data_len)
 {
	 adv_cmd.info.host.scan_rsp_data_len = scan_response_data_len;
	 memcpy(adv_cmd.info.host.scan_rsp_data, p_scan_response_data, scan_response_data_len);

#if 0	//发送GAPM的命令方式
    APP_LOG("app_status:%d\r\n",ke_state_get(TASK_APP));

    // Check if the advertising procedure is already is progress
    if (ke_state_get(TASK_APP) == APPM_READY)
    {
        // Prepare the GAPM_UPDATE_ADVERTISE_DATA_CMD message
        struct gapm_update_advertise_data_cmd *cmd = KE_MSG_ALLOC(GAPM_UPDATE_ADVERTISE_DATA_CMD,	//需要在gapm_task.c中增加相应的GAPM_UPDATE_SCAN_RESPONSE_DATA_CMD
                                               TASK_GAPM, TASK_APP,
                                               gapm_update_advertise_data_cmd);

        cmd->operation = GAPM_UPDATE_ADVERTISE_DATA;
        cmd->adv_data_len = 0;
		//memcpy(cmd->adv_data, p_adv_data, adv_data_len);
		
        cmd->scan_rsp_data_len = scan_response_data_len;
				memcpy(cmd->scan_rsp_data, p_scan_response_data, scan_response_data_len);

        // Send the message
        ke_msg_send(cmd);
    }
#endif
    // else ignore the request

#if 0 // 真正通过hci命令直接改写scan response内容的代码
// Another way?
            struct hci_le_set_scan_rsp_data_cmd *scan_resp = KE_MSG_ALLOC(HCI_COMMAND, 0, HCI_LE_SET_SCAN_RSP_DATA_CMD_OPCODE, hci_le_set_scan_rsp_data_cmd);
            // retrieve scan response data length
            scan_resp->scan_rsp_data_len =adv->info.host.scan_rsp_data_len;
            // copy provided scan response data
            memcpy(&(scan_resp->data), adv->info.host.scan_rsp_data, SCAN_RSP_DATA_LEN);

            hci_send_2_controller(scan_resp);
#endif

}
	  
 /*********************************************************************
 * @fn      gap_start_advertising
 *
 * @brief   Start advertising.
 *			开始广播.
 *
 * @param   None.
 *
 * @return  None.
 */
void gap_start_advertising(gap_adv_param_t *p_adv_param)
{	
    if ( p_adv_param == NULL )  // 默认参数
    {
        adv_cmd.op.code = GAPM_ADV_UNDIRECT;
    
        adv_cmd.op.addr_src = GAPM_STATIC_ADDR;
        
        adv_cmd.intv_min    = 160;           
        adv_cmd.intv_max    = 160;             
        adv_cmd.channel_map = 0x07;
        
        adv_cmd.info.host.mode = GAP_GEN_DISCOVERABLE;
        adv_cmd.info.host.adv_filt_policy = ADV_ALLOW_SCAN_ANY_CON_ANY;
        
    }
    else
    {
    	if ( p_adv_param->adv_mode == GAP_ADV_TYPE_UNDIRECT )
    		adv_cmd.op.code = GAPM_ADV_UNDIRECT;
    	else if ( p_adv_param->adv_mode == GAP_ADV_TYPE_DIRECT )
    		adv_cmd.op.code = GAPM_ADV_DIRECT;
    	else if ( p_adv_param->adv_mode == GAP_ADV_TYPE_NON_CONN )
    		adv_cmd.op.code = GAPM_ADV_NON_CONN;

    	if ( p_adv_param->adv_addr_type == GAP_ADDR_TYPE_PUBLIC || p_adv_param->adv_addr_type == GAP_ADDR_TYPE_PRIVATE )
    		adv_cmd.op.addr_src = GAPM_STATIC_ADDR;
    	else if ( p_adv_param->adv_addr_type == GAP_ADDR_TYPE_RANDOM_RESOVABLE )
    		adv_cmd.op.addr_src = GAPM_GEN_RSLV_ADDR;
    	else if ( p_adv_param->adv_addr_type == GAP_ADDR_TYPE_RANDOM_NONE_RESOVABLE )
    		adv_cmd.op.addr_src = GAPM_GEN_NON_RSLV_ADDR;

    	adv_cmd.intv_min    = p_adv_param->adv_intv_min;           
    	adv_cmd.intv_max    = p_adv_param->adv_intv_max;     		
    	adv_cmd.channel_map = p_adv_param->adv_chnl_map;

    	adv_cmd.info.host.mode = p_adv_param->adv_dis_mode;
    	adv_cmd.info.host.adv_filt_policy = p_adv_param->adv_filt_policy;
    }
	
	appm_start_advertising(&adv_cmd);
}

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
void gap_stop_advertising(void)
{
	appm_stop_advertising();
}

 /*********************************************************************
 * @fn      gap_address_get
 *
 * @brief   Fetch BLE mac address.
 *
 * @param   None.
 *
 * @return  Mac address. Note: Please copy BLE mac address to a 6 bytes buffer
 */
uint8_t *gap_address_get(void)
{
	return ble_get_addr();
}

 /*********************************************************************
 * @fn      gap_address_set
 *
 * @brief   Configure BLE mac address.
 *
 * @param   mac: 6 bytes MAC address
 *
 * @return  None.
 */
void gap_address_set(uint8_t *mac)
{
	ble_set_addr(mac);
}

/** @function group ble central device APIs (ble澶栬鐩稿叧鐨凙PI)
}

 *********************************************************************
 * @fn      gap_conn_param_update
 *
 * @brief   Send connection parameters update request from ble peripheral device.
 *			发送连接参数更新请, 注意协议规定只允许外设发起此命令.
 *
 * @param   conn_handle - connection handle/index of the connection.
 *						  连接handle/index, 这在连接建立时得到.
 *			min_intv - minimum connection interval.
 *					   最短连接间隔.
 * 		 	max_intv - maximum connection interval, in normal case can be set same as min_intv.
 *					   最长连接间隔, 通常根据实际需要, 设置成和min_intv同样的值.
 *			slave_latency - slave latency, number of connection events that slave would like to skip.
 *							允许外设跳过的connection event的个数.
 *			supervision_timeout - timeout before connection is dropped.
 *								  连接超时设置.
 *
 * @return  None.
 */
void gap_conn_param_update(uint8_t conn_handle, uint16_t min_intv, uint16_t max_intv, uint16_t slave_latency, uint16_t supervision_timeout)
{
	struct gapc_conn_param conn_param;
	conn_param.intv_min = min_intv;
	conn_param.intv_max = max_intv;
	conn_param.latency = slave_latency;
	conn_param.time_out = supervision_timeout;
	appm_update_param(conn_handle, &conn_param);
}

 
/** @function group ble central device APIs (ble中心设备相关的API)
 * @{
 */


#if 0
/** @function group ble security APIs (ble中心设备相关的API)
 * @{
 */
 
/*********************************************************************
* @fn      gap_address_set
*
* @brief   Configure BLE mac address.
*
* @param   mac: 6 bytes MAC address
*
* @return  None.
*/
void gap_security_req(uint8_t conn_idx)
 {
     // Send security request
     struct gapc_security_cmd *cmd = KE_MSG_ALLOC(GAPC_SECURITY_CMD,
                                     KE_BUILD_ID(TASK_GAPC, conn_idx), TASK_APP,
                                     gapc_security_cmd);
 
     cmd->operation = GAPC_SECURITY_REQ;
     cmd->auth      = APP_SEC_GAP_AUTH;//GAP_AUTH_REQ_MITM_BOND;
 
     // Send the message
     ke_msg_send(cmd);
 }
#endif
 

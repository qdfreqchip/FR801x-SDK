/**
 * Copyright (c) 2019, Tsingtao Freqchip
 * 
 * All rights reserved.
 * 
 * 
 */
 
/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include <stdio.h>
#include <string.h>

#include "gap_api.h"
#include "gatt_api.h"
#include "simple_gatt_profile.h"
#include "ble_simple_peripheral.h"

void user_proj_main_before_ble_ini(void)
{
    printf("user proj_main_before_ble_ini\r\n");
    uint8_t addr[] = {0x1f, 0x09, 0x07, 0x09, 0x17, 0x20};
    gap_address_set(addr);
}


void user_proj_main(void)
{
	gap_set_cb_func(GAP_EVT_DEV_CFG_DONE,sp_cfg_dev_init_done_cb);
	gap_set_cb_func(GAP_EVT_SVC_INIT_DONE,sp_cfg_svc_init_done_cb);
	gap_set_cb_func(GAP_EVT_CONNECTED,sp_gap_connected_cb);
	gap_set_cb_func(GAP_EVT_DISCONNECTED,sp_gap_disconnected_cb);
	gap_set_cb_func(GAP_EVT_PARAM_UPDATED,sp_param_updated_cb);
	gap_set_cb_func(GAP_EVT_PARAM_UPDATE_IND,sp_param_update_ind_cb);
	gap_set_cb_func(GAP_EVT_PARAM_UPDATE_REJECTED,sp_param_update_rejected_cb);

	gap_dev_config(NULL);
		
}




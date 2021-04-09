/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2017 by G-Pulse.		All rights reserved.
** This software is copyright protected and proprietary to G-Pulse.
** G-Pulse grants to you only those rights as set out in the license conditions.
** All other rights remain with G-Pulse.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \CddDrv\AurixQspi$
* $Class_____: C$
* $Name______: AurixQspi.h$
* $Variant___: 1.0.4$
* $Revision__: 0$
* $Author____: YM$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION:
** AURIX QSPI manual driver header code
*******************************************************************************/
#ifndef AURIX_QSPI_H_
#define AURIX_QSPI_H_

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "AurixQspi_Cfg.h"

/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/

/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/

/*******************************************************************************
**                  Global Variables With Extern Linkage               		  **
*******************************************************************************/

/*******************************************************************************
**                        Global Function Prototypes              	    	  **
*******************************************************************************/

/*******************************************************************************
** Function Name	: AurixQspi_Init
** Parameter[in] 	: const AurixQspi_HWCfgType *arg_HWCfg_pst
** Parameter[out] 	: None
** Return Value	  	: Std_ReturnType Status
** Note	  			: None
** Description	  	: AURIX QSPI模块 初始化
*******************************************************************************/
extern	Std_ReturnType AurixQspi_Init
(
	const AurixQspi_HWCfgType *arg_HWCfg_pst
);

/*******************************************************************************
** Function Name	: AurixQspi_ChannelCfg
** Parameter[in] 	: uint8 arg_SeqNum_u8,uint32 *arg_TxBuff_u32,
					  uint32 *arg_RxBuff_u32,uint16 arg_Datalen_u16
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: 配置 SPI通道
*******************************************************************************/
extern	void AurixQspi_ChannelCfg
(
	uint8 arg_SeqNum_u8,uint32 *arg_TxBuff_u32,\
	uint32 *arg_RxBuff_u32,uint16 arg_Datalen_u16
);

/*******************************************************************************
** Function Name	: AurixQspi_Transmit
** Parameter[in] 	: uint8 arg_SeqNum_u8
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: 发送一个10M,16BIT数据,耗时约 2.81US(CPU时钟300M)
** Description	  	: QSPI 同步 数据传输
*******************************************************************************/
extern	Std_ReturnType AurixQspi_Transmit(uint8 arg_SeqNum_u8);

#endif /* AURIX_QSPI_H_ */

/*******************************************************************************
* $History__:$
* V1.0.0; 0     02.06.2017 YM
*  N: new created
* V1.0.1; 0     14.08.2017 YM
*  I:  修复部分BUG
* V1.0.2; 0     22.08.2017 YM
*  I:  修复BUG,添加注释
* V1.0.3; 0     25.08.2017 YM
*  I:  更改配置文件部分结构体,增加注释
* V1.0.4; 0     1.09.2017 YM
*  I:  修改同步传输一帧发送多个数据存在的BUG,增加发送接收内部静态函数,修改配置说明
*******************************************************************************/

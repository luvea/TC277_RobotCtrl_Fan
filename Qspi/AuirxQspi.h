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
** Description	  	: AURIX QSPIģ�� ��ʼ��
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
** Description	  	: ���� SPIͨ��
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
** Note	  			: ����һ��10M,16BIT����,��ʱԼ 2.81US(CPUʱ��300M)
** Description	  	: QSPI ͬ�� ���ݴ���
*******************************************************************************/
extern	Std_ReturnType AurixQspi_Transmit(uint8 arg_SeqNum_u8);

#endif /* AURIX_QSPI_H_ */

/*******************************************************************************
* $History__:$
* V1.0.0; 0     02.06.2017 YM
*  N: new created
* V1.0.1; 0     14.08.2017 YM
*  I:  �޸�����BUG
* V1.0.2; 0     22.08.2017 YM
*  I:  �޸�BUG,���ע��
* V1.0.3; 0     25.08.2017 YM
*  I:  ���������ļ����ֽṹ��,����ע��
* V1.0.4; 0     1.09.2017 YM
*  I:  �޸�ͬ������һ֡���Ͷ�����ݴ��ڵ�BUG,���ӷ��ͽ����ڲ���̬����,�޸�����˵��
*******************************************************************************/

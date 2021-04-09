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
* $Name______: AurixQspi_Cfg.h$
* $Variant___: 1.0.0$
* $Revision__: 0$
* $Author____: YM$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: Yes
**----------------------------------------------------------------------------**
** DESCRIPTION:
** AURIX QSPI manual driver configuration header code
*******************************************************************************/
#ifndef AURIX_QSPI_CFG_H_
#define AURIX_QSPI_CFG_H_

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "AurixQspi_Types.h"

/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
/* QSPI ģ��ʹ������ */
#define AURIX_QSPI_MOUDLE_USE_NUM 		1U

/* QSPI ͨ������ */
#define AURIX_QSPI_CHANNEL_USE_NUM 		4U

/*ʵ��ʹ�õ�SEQUENCE �ӿڣ�ͨ��������Ψһ��Ӧ	*/
#define Aurix_Spi_Ch_Sq_Num_AD2S1210_D8			0U	/* 8λ���ݳ��� */
#define Aurix_Spi_Ch_Sq_Num_AD2S1210_D16		1U	/* 16λ���ݳ��� */
#define	Aurix_Spi_Ch_Sq_Num_9180				0U
#define	Aurix_Spi_Ch_Sq_Num_9180_1				1U
#define	Aurix_Spi_Ch_Sq_Num_9180_2				2U
#define	Aurix_Spi_Ch_Sq_Num_9180_3				3U


/* QSPIģ��״̬���������ֵ,ʹ��4MƵ��ʱ���������ֵΪ60,��3�����������  */
/* ��������QSPIģ�鶼ʹ��ͬһ�ο�ֵ,�����в����ʽϵ͵�ͨ��,�����Ӹ�����ֵ */
#define AURIX_QSPI_STATUS_CHECK_NUM_MAX  	((uint16)500U)
/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/
typedef struct AurixQspi_HWCfg
{
	const AurixQspi_MoudleType *HW_MoudleCfg_ptr[AURIX_QSPI_MOUDLE_USE_NUM];
}AurixQspi_HWCfgType;

/*******************************************************************************
**                  Global Variables With Extern Linkage               		  **
*******************************************************************************/
/*CFG ָ��*/
extern	const AurixQspi_HWCfgType AurixQspi_HWCfg_cst;

/* modules */
extern	const AurixQspi_MoudleType \
			AurixQspi_Moudle_cst[AURIX_QSPI_MOUDLE_USE_NUM];

/*channels*/
extern	const AurixQspi_ChannelType \
			AurixQspi_Channel_cst[AURIX_QSPI_CHANNEL_USE_NUM];

/*******************************************************************************
**                        Global Function Prototypes              	    	  **
*******************************************************************************/


#endif /* AURIX_QSPI_CFG_H_ */


/*******************************************************************************
* $History__:$
* V1.0.0; 0     02.06.2017 YM
*  N: new created
*******************************************************************************/

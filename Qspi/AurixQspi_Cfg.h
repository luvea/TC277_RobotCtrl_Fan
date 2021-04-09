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
/* QSPI 模块使用数量 */
#define AURIX_QSPI_MOUDLE_USE_NUM 		1U

/* QSPI 通道数量 */
#define AURIX_QSPI_CHANNEL_USE_NUM 		4U

/*实际使用的SEQUENCE 接口，通道、序列唯一对应	*/
#define Aurix_Spi_Ch_Sq_Num_AD2S1210_D8			0U	/* 8位数据长度 */
#define Aurix_Spi_Ch_Sq_Num_AD2S1210_D16		1U	/* 16位数据长度 */
#define	Aurix_Spi_Ch_Sq_Num_9180				0U
#define	Aurix_Spi_Ch_Sq_Num_9180_1				1U
#define	Aurix_Spi_Ch_Sq_Num_9180_2				2U
#define	Aurix_Spi_Ch_Sq_Num_9180_3				3U


/* QSPI模块状态检查次数最大值,使用4M频率时，测试最大值为60,给3倍多的冗余量  */
/* 由于所有QSPI模块都使用同一参考值,故若有波特率较低的通道,需增加该配置值 */
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
/*CFG 指针*/
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

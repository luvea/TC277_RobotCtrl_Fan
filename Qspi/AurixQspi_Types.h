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
* $Name______: AurixQspi_Types.h$
* $Variant___: 1.0.4$
* $Revision__: 0$
* $Author____: YM$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION:
** AURIX QSPI manual driver all Types header code
*******************************************************************************/
#ifndef AURIX_QSPI_TYPES_H_
#define AURIX_QSPI_TYPES_H_

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
/*数据位宽宏定义;只支持8位、16位、32位数据*/
#define AURIX_QSPI_DATA_LENGTH_8			0U
#define AURIX_QSPI_DATA_LENGTH_16			1U
#define AURIX_QSPI_DATA_LENGTH_32			2U

/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/

/*SPI模块参数配置 结构体类型*/
typedef struct AurixQspi_Moudle
{
	uint8	ModuleIndx_u8;		/*QSPI模块索引*/
	uint32 	GLOBALCON_u32;		/*GLOBALCON*/
	uint32 	GLOBALCON1_u32;		/*GLOBALCON1*/
}AurixQspi_MoudleType;

/*SPI 通道配置 结构体类型*/
typedef struct AurixQspi_Channel
{
	uint8	ModuleIndx_u8;		/*QSPI模块索引*/
	uint8 	Qspi_Channel_u8;	/*QSPI通道*/
	uint8 	Data_Length;		/*数据宽度*/
	/*NOTE:数据若为一帧数据只有一次CS跳变;配置BACON LAST位需配置为0*/
	/*数据若为每个数据都需要CS跳变;配置BACON LAST位需配置为1*/
	uint32	BACON_u32;			/*BACON*/
	uint32	ECON_u32;			/*ECON*/
	uint32	PISEL_u32;			/*PISEL*/
	uint32	SSOC_u32;			/*SSOC*/
}AurixQspi_ChannelType;

/*SPI 数据结构体类型*/
typedef struct AurixQspi_Data
{
	uint16	DataLen_u16;		/*数据长度*/
	uint16 	DataCnt_u16;		/*数据计数*/
	uint32 	*TxBuffer_pu32;		/*发送数据指针,32位数据*/
	uint32	*RxBuffer_pu32;		/*接收数据指针,32位数据*/
	uint16	*TxBuffer_pu16;		/*发送数据指针,16位数据*/
	uint16	*RxBuffer_pu16;		/*接收数据指针,16位数据*/
	uint8	*TxBuffer_pu8;		/*发送数据指针,8位数据*/
	uint8	*RxBuffer_pu8;		/*接收数据指针,8位数据*/
}AurixQspi_DataType;

/*******************************************************************************
**                  Global Variables With Extern Linkage               		  **
*******************************************************************************/

/*******************************************************************************
**                        Global Function Prototypes              	    	  **
*******************************************************************************/

#endif /* AURIX_QSPI_TYPES_H_ */

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

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
/*����λ��궨��;ֻ֧��8λ��16λ��32λ����*/
#define AURIX_QSPI_DATA_LENGTH_8			0U
#define AURIX_QSPI_DATA_LENGTH_16			1U
#define AURIX_QSPI_DATA_LENGTH_32			2U

/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/

/*SPIģ��������� �ṹ������*/
typedef struct AurixQspi_Moudle
{
	uint8	ModuleIndx_u8;		/*QSPIģ������*/
	uint32 	GLOBALCON_u32;		/*GLOBALCON*/
	uint32 	GLOBALCON1_u32;		/*GLOBALCON1*/
}AurixQspi_MoudleType;

/*SPI ͨ������ �ṹ������*/
typedef struct AurixQspi_Channel
{
	uint8	ModuleIndx_u8;		/*QSPIģ������*/
	uint8 	Qspi_Channel_u8;	/*QSPIͨ��*/
	uint8 	Data_Length;		/*���ݿ��*/
	/*NOTE:������Ϊһ֡����ֻ��һ��CS����;����BACON LASTλ������Ϊ0*/
	/*������Ϊÿ�����ݶ���ҪCS����;����BACON LASTλ������Ϊ1*/
	uint32	BACON_u32;			/*BACON*/
	uint32	ECON_u32;			/*ECON*/
	uint32	PISEL_u32;			/*PISEL*/
	uint32	SSOC_u32;			/*SSOC*/
}AurixQspi_ChannelType;

/*SPI ���ݽṹ������*/
typedef struct AurixQspi_Data
{
	uint16	DataLen_u16;		/*���ݳ���*/
	uint16 	DataCnt_u16;		/*���ݼ���*/
	uint32 	*TxBuffer_pu32;		/*��������ָ��,32λ����*/
	uint32	*RxBuffer_pu32;		/*��������ָ��,32λ����*/
	uint16	*TxBuffer_pu16;		/*��������ָ��,16λ����*/
	uint16	*RxBuffer_pu16;		/*��������ָ��,16λ����*/
	uint8	*TxBuffer_pu8;		/*��������ָ��,8λ����*/
	uint8	*RxBuffer_pu8;		/*��������ָ��,8λ����*/
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
*  I:  �޸�����BUG
* V1.0.2; 0     22.08.2017 YM
*  I:  �޸�BUG,���ע��
* V1.0.3; 0     25.08.2017 YM
*  I:  ���������ļ����ֽṹ��,����ע��
* V1.0.4; 0     1.09.2017 YM
*  I:  �޸�ͬ������һ֡���Ͷ�����ݴ��ڵ�BUG,���ӷ��ͽ����ڲ���̬����,�޸�����˵��
*******************************************************************************/

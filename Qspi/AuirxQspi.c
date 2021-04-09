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
* $Name______: AurixQspi.c$
* $Variant___: 1.0.4$
* $Revision__: 0$
* $Author____: YM$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION:
** AURIX QSPI manual driver source code
*******************************************************************************/

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "AuirxQspi.h"
#include "Mcal_WdgLib.h"
#include "IfxQspi_reg.h"

/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
/*SPI MODULE ADDRESS*/
#define AURIX_QSPI_MODULE 				((volatile Ifx_QSPI*) &(MODULE_QSPI0))

/*QSPIģ��CLC�Ĵ���MASK*/
#define AURIX_QSPI_ENABLE_CLOCK_MASK		((uint32)0x00000008U)

/*QSPIģ��ʹ��BIT MASK*/
#define	AURIX_QSPI_GLOBALCON_ENBIT_MASK		((uint32)0x01000000U)

/*QSPIģ�������б�־λMASK*/
#define AURIX_QSPI_FLAGSCLEAR_ALL_MASK		((uint32)0x0000FFFFU)

/*QSPIģ�����RX��־λMASK*/
#define AURIX_QSPI_FLAGSCLEAR_RXF_MASK		((uint32)0x00000400U)

/*QSPIģ��RX״̬��־λMASK*/
#define AURIX_QSPI_STATUS_RXF_MASK			((uint32)0x00000400U)

/*QSPIģ�����״̬��־λMASK*/
#define AURIX_QSPI_STATUS_ERRORFLAGS_MASK	((uint32)0x000001FFU)

/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/

/*******************************************************************************
**                   Static Local Variables Definition              		  **
*******************************************************************************/
/* SPI �����ڲ����� */
static AurixQspi_DataType AurixQspi_Data_st[AURIX_QSPI_CHANNEL_USE_NUM];

/*******************************************************************************
**                     Global Variables Definition              		      **
*******************************************************************************/

/*******************************************************************************
**                  Static Local Function Declaration            		      **
*******************************************************************************/
static void AurixQspi_SendData
(
	const AurixQspi_ChannelType *AurixQspi_Channel_Ptr,\
	AurixQspi_DataType *AurixQspi_Data_Ptr
);
static void AurixQspi_ReceiveData
(
	const AurixQspi_ChannelType *AurixQspi_Channel_Ptr,\
	AurixQspi_DataType *AurixQspi_Data_Ptr
);
static Std_ReturnType AurixQspi_CheckStatus(uint8 arg_QspiIndex_u8);

/*******************************************************************************
**                 		  Function Source Code            		              **
*******************************************************************************/

/*******************************************************************************
** Function Name	: AurixQspi_Init
** Parameter[in] 	: const AurixQspi_HWCfgType *arg_HWCfg_pst
** Parameter[out] 	: None
** Return Value	  	: Std_ReturnType Status
** Note	  			: None
** Description	  	: AURIX QSPIģ�� ��ʼ��
*******************************************************************************/
Std_ReturnType AurixQspi_Init(const AurixQspi_HWCfgType *arg_HWCfg_pst)
{
	Std_ReturnType Status = E_NOT_OK;

	uint8 QspiMoudleCnt_u8;
	uint32 GLOBALCON_Temp_ui32;
	const AurixQspi_MoudleType *AurixQspi_Moudle_ptr;

	if(arg_HWCfg_pst != NULL_PTR)
	{
		/*���ò�ʹ��������Ҫ�õ���QSPIģ��*/
		for(QspiMoudleCnt_u8=0U;QspiMoudleCnt_u8<AURIX_QSPI_MOUDLE_USE_NUM;\
			QspiMoudleCnt_u8++)
		{
			AurixQspi_Moudle_ptr = \
					arg_HWCfg_pst->HW_MoudleCfg_ptr[QspiMoudleCnt_u8];
			/* Enable Module Request,Disable Sleep Mode */
			Mcal_ResetENDINIT();
			AURIX_QSPI_MODULE[AurixQspi_Moudle_ptr->ModuleIndx_u8].CLC.U =\
										AURIX_QSPI_ENABLE_CLOCK_MASK;
	        Mcal_SetENDINIT();

			/*����GLOBALCON*/
			AURIX_QSPI_MODULE[AurixQspi_Moudle_ptr->ModuleIndx_u8].GLOBALCON.U =\
					AurixQspi_Moudle_ptr->GLOBALCON_u32;

			/*����GLOBALCON1*/
			AURIX_QSPI_MODULE[AurixQspi_Moudle_ptr->ModuleIndx_u8].GLOBALCON1.U =\
					AurixQspi_Moudle_ptr->GLOBALCON1_u32;

			/*ʹ��QSPIģ��*/
			GLOBALCON_Temp_ui32 = \
				AURIX_QSPI_MODULE[AurixQspi_Moudle_ptr->ModuleIndx_u8].GLOBALCON.U;
			GLOBALCON_Temp_ui32 |= AURIX_QSPI_GLOBALCON_ENBIT_MASK;
			AURIX_QSPI_MODULE[AurixQspi_Moudle_ptr->ModuleIndx_u8].GLOBALCON.U =\
					GLOBALCON_Temp_ui32;

			/*����жϡ������־*/
			AURIX_QSPI_MODULE[AurixQspi_Moudle_ptr->ModuleIndx_u8].FLAGSCLEAR.U =\
										AURIX_QSPI_FLAGSCLEAR_ALL_MASK;
		}

		Status = E_OK;	/*��ʼ���ɹ�*/
	}
	else
	{
		Status = E_NOT_OK;/*��ʼ��ʧ��*/
	}

	return Status;
}

/*******************************************************************************
** Function Name	: AurixQspi_ChannelCfg
** Parameter[in] 	: uint8 arg_SeqNum_u8,uint32 *arg_TxBuff_u32,
					  uint32 *arg_RxBuff_u32,uint16 arg_Datalen_u16
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: ���� SPIͨ��
*******************************************************************************/
void AurixQspi_ChannelCfg
(
	uint8 arg_SeqNum_u8,uint32 *arg_TxBuff_u32,\
	uint32 *arg_RxBuff_u32,uint16 arg_Datalen_u16
)

{
	uint8 QspiChannel_u8;
	const AurixQspi_ChannelType *arg_ChannelCfg_pst;                                           //channelType ���͵�ָ��arg_channelCfg_pst

	/*��ȡͨ����Ϣ*/
	arg_ChannelCfg_pst = &AurixQspi_Channel_cst[arg_SeqNum_u8];

    /*����PISEL*/
	AURIX_QSPI_MODULE[arg_ChannelCfg_pst->ModuleIndx_u8].PISEL.U =\
						arg_ChannelCfg_pst->PISEL_u32;
    /*д��ECON*/
	QspiChannel_u8 = arg_ChannelCfg_pst->Qspi_Channel_u8 % 8U;
	AURIX_QSPI_MODULE[arg_ChannelCfg_pst->ModuleIndx_u8].\
						ECON[QspiChannel_u8].U = arg_ChannelCfg_pst->ECON_u32;
	/*д��SSOC*/
	AURIX_QSPI_MODULE[arg_ChannelCfg_pst->ModuleIndx_u8].SSOC.U =\
						arg_ChannelCfg_pst->SSOC_u32;

	/*��ռ���ֵ;д�����ݳ���ֵ*/
	AurixQspi_Data_st[arg_SeqNum_u8].DataCnt_u16 = 0U;
	AurixQspi_Data_st[arg_SeqNum_u8].DataLen_u16 = arg_Datalen_u16;





	/*����SPI BUFFERָ��*/
	switch(arg_ChannelCfg_pst->Data_Length)                                                   //�ж�ָ���е�Data_Length
	{
		case AURIX_QSPI_DATA_LENGTH_8:/*SPI ���ݿ��Ϊ8*/
		{
			AurixQspi_Data_st[arg_SeqNum_u8].TxBuffer_pu8 =\
					(uint8*)arg_TxBuff_u32;
			AurixQspi_Data_st[arg_SeqNum_u8].RxBuffer_pu8 =\
					(uint8*)arg_RxBuff_u32;
			break;
		}
		case AURIX_QSPI_DATA_LENGTH_16:/*SPI ���ݿ��Ϊ16*/
		{
			AurixQspi_Data_st[arg_SeqNum_u8].TxBuffer_pu16 =\
					(uint16*)arg_TxBuff_u32;
			AurixQspi_Data_st[arg_SeqNum_u8].RxBuffer_pu16 =\
					(uint16*)arg_RxBuff_u32;
			break;
		}
		case AURIX_QSPI_DATA_LENGTH_32:/*SPI ���ݿ��Ϊ32*/
		{
			AurixQspi_Data_st[arg_SeqNum_u8].TxBuffer_pu32 = arg_TxBuff_u32;
			AurixQspi_Data_st[arg_SeqNum_u8].RxBuffer_pu32 = arg_RxBuff_u32;
			break;
		}
		default:/*SPI Ĭ�����ݿ��Ϊ32*/
		{
			AurixQspi_Data_st[arg_SeqNum_u8].TxBuffer_pu32 = arg_TxBuff_u32;
			AurixQspi_Data_st[arg_SeqNum_u8].RxBuffer_pu32 = arg_RxBuff_u32;
			break;
		}
	}
}

/*******************************************************************************
** Function Name	: AurixQspi_Transmit
** Parameter[in] 	: uint8 arg_SeqNum_u8
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: ����һ��10M,16BIT����,��ʱԼ 2.81US(CPUʱ��300M)
** Description	  	: QSPI ͬ�� ���ݴ���
*******************************************************************************/
Std_ReturnType AurixQspi_Transmit(uint8 arg_SeqNum_u8)
{
	Std_ReturnType Status = E_NOT_OK;
	uint8 QspiMoudleIndex_u8;

	/*��ȡͨ��������Ϣ*/
	const AurixQspi_ChannelType *AurixQspi_Channel_pst =\
			&AurixQspi_Channel_cst[arg_SeqNum_u8];

	/*��ȡͨ��������Ϣ*/
	AurixQspi_DataType *AurixQspi_Data_pst = &AurixQspi_Data_st[arg_SeqNum_u8];

	/*��ռ���ֵ*/
	AurixQspi_Data_pst->DataCnt_u16 = 0U;

	/*�������״̬��־*/
	AURIX_QSPI_MODULE[AurixQspi_Channel_pst->ModuleIndx_u8].FLAGSCLEAR.U =\
						AURIX_QSPI_FLAGSCLEAR_ALL_MASK;

	/*ѭ����������*/
	while(AurixQspi_Data_pst->DataCnt_u16 < AurixQspi_Data_pst->DataLen_u16)
	{
		if((AurixQspi_Data_pst->DataCnt_u16) <\
				(uint16)(AurixQspi_Data_pst->DataLen_u16-1U))/*�����һλ����*/
		{
			/*д��BACON����*/
			AURIX_QSPI_MODULE[AurixQspi_Channel_pst->ModuleIndx_u8].\
				BACONENTRY.U = AurixQspi_Channel_pst->BACON_u32;
		}
		else/*���һλ����*/
		{
			/*LAST λ��1*/
			AURIX_QSPI_MODULE[AurixQspi_Channel_pst->ModuleIndx_u8].\
			BACONENTRY.U = AurixQspi_Channel_pst->BACON_u32 | 1U;
		}

		/*��������*/
		AurixQspi_SendData(AurixQspi_Channel_pst,AurixQspi_Data_pst);

		/*���״̬���ȴ����ձ�־λ��������״̬��*/
		QspiMoudleIndex_u8 = AurixQspi_Channel_pst->ModuleIndx_u8;
		Status = AurixQspi_CheckStatus(QspiMoudleIndex_u8);

		if(Status == E_OK)/*���յ����ݲ����޴���*/
		{
			/*����������ݱ�־*/
			AURIX_QSPI_MODULE[AurixQspi_Channel_pst->ModuleIndx_u8].FLAGSCLEAR.U =\
					AURIX_QSPI_FLAGSCLEAR_RXF_MASK;

			/*��ȡ��������*/
			AurixQspi_ReceiveData(AurixQspi_Channel_pst,AurixQspi_Data_pst);

			/*�������ݼ����Լ�*/
			AurixQspi_Data_pst->DataCnt_u16++;
		}
		else/*״̬���ʧ��*/
		{
			break;/*����ѭ��*/
		}
	}

	return Status;
}

/*******************************************************************************
** Function Name	: AurixQspi_SendData
** Parameter[in] 	: const AurixQspi_ChannelType *AurixQspi_Channel_Ptr,
**					  AurixQspi_DataType *AurixQspi_Data_Ptr
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: QSPI ��������,дDATAENTRY�Ĵ���
*******************************************************************************/
static void AurixQspi_SendData
(
	const AurixQspi_ChannelType *AurixQspi_Channel_Ptr,\
	AurixQspi_DataType *AurixQspi_Data_Ptr
)
{
	switch(AurixQspi_Channel_Ptr->Data_Length)/*�ж�����λ��*/
	{
		case AURIX_QSPI_DATA_LENGTH_8:/*SPI ���ݿ��Ϊ8*/
		{
			AURIX_QSPI_MODULE[AurixQspi_Channel_Ptr->ModuleIndx_u8].\
			DATAENTRY[0U].U = (uint32)AurixQspi_Data_Ptr->\
					TxBuffer_pu8[AurixQspi_Data_Ptr->DataCnt_u16];
			break;
		}
		case AURIX_QSPI_DATA_LENGTH_16:/*SPI ���ݿ��Ϊ16*/
		{
			AURIX_QSPI_MODULE[AurixQspi_Channel_Ptr->ModuleIndx_u8].\
			DATAENTRY[0U].U = (uint32)AurixQspi_Data_Ptr->\
					TxBuffer_pu16[AurixQspi_Data_Ptr->DataCnt_u16];
			break;
		}
		case AURIX_QSPI_DATA_LENGTH_32:/*SPI ���ݿ��Ϊ32*/
		{
			AURIX_QSPI_MODULE[AurixQspi_Channel_Ptr->ModuleIndx_u8].\
			DATAENTRY[0U].U = (uint32)AurixQspi_Data_Ptr->\
					TxBuffer_pu32[AurixQspi_Data_Ptr->DataCnt_u16];
			break;
		}
		default:/*SPI Ĭ�����ݿ��Ϊ32*/
		{
			AURIX_QSPI_MODULE[AurixQspi_Channel_Ptr->ModuleIndx_u8].\
			DATAENTRY[0U].U = (uint32)AurixQspi_Data_Ptr->\
					TxBuffer_pu32[AurixQspi_Data_Ptr->DataCnt_u16];
			break;
		}
	}
}

/*******************************************************************************
** Function Name	: AurixQspi_ReceiveData
** Parameter[in] 	: const AurixQspi_ChannelType *AurixQspi_Channel_Ptr,
**					  AurixQspi_DataType *AurixQspi_Data_Ptr
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: QSPI ��������,��RXEXIT�Ĵ���
*******************************************************************************/
static void AurixQspi_ReceiveData
(
	const AurixQspi_ChannelType *AurixQspi_Channel_Ptr,\
	AurixQspi_DataType *AurixQspi_Data_Ptr
)
{
	switch(AurixQspi_Channel_Ptr->Data_Length)/*�ж�����λ��*/
	{
		case AURIX_QSPI_DATA_LENGTH_8:/*SPI ���ݿ��Ϊ8*/
		{
			AurixQspi_Data_Ptr->\
			RxBuffer_pu8[AurixQspi_Data_Ptr->DataCnt_u16] = \
			(uint8)AURIX_QSPI_MODULE[AurixQspi_Channel_Ptr->ModuleIndx_u8].\
																RXEXIT.U;
			break;
		}
		case AURIX_QSPI_DATA_LENGTH_16:/*SPI ���ݿ��Ϊ16*/
		{
			AurixQspi_Data_Ptr->\
			RxBuffer_pu16[AurixQspi_Data_Ptr->DataCnt_u16] =\
			(uint16)AURIX_QSPI_MODULE[AurixQspi_Channel_Ptr->ModuleIndx_u8].\
																RXEXIT.U;
			break;
		}
		case AURIX_QSPI_DATA_LENGTH_32:/*SPI ���ݿ��Ϊ32*/
		{
			AurixQspi_Data_Ptr->\
			RxBuffer_pu32[AurixQspi_Data_Ptr->DataCnt_u16] =\
			(uint32)AURIX_QSPI_MODULE[AurixQspi_Channel_Ptr->ModuleIndx_u8].\
																RXEXIT.U;
			break;
		}
		default:/*SPI Ĭ�����ݿ��Ϊ32*/
		{
			AurixQspi_Data_Ptr->\
			RxBuffer_pu32[AurixQspi_Data_Ptr->DataCnt_u16] =\
			(uint32)AURIX_QSPI_MODULE[AurixQspi_Channel_Ptr->ModuleIndx_u8].\
																RXEXIT.U;
			break;
		}
	}
}

/*******************************************************************************
** Function Name	: AurixQspi_CheckStatus
** Parameter[in] 	: uint8 arg_QspiIndex_u8
** Parameter[out] 	: None
** Return Value	  	: Std_ReturnType Status
** Note	  			: None
** Description	  	: AURIX QSPI ���״̬
*******************************************************************************/
static Std_ReturnType AurixQspi_CheckStatus(uint8 arg_QspiIndex_u8)
{
	Std_ReturnType Status = E_NOT_OK;
	uint16 OverTimeCnt_u16;
	uint32 StatusTemp_u32;

	/*ѭ����ȡ�����STATUS*/
	for(OverTimeCnt_u16=0U;OverTimeCnt_u16 < \
		AURIX_QSPI_STATUS_CHECK_NUM_MAX;OverTimeCnt_u16++)
	{
		/*��ȡSTATUS�Ĵ������� */
		StatusTemp_u32 =\
				AURIX_QSPI_MODULE[arg_QspiIndex_u8].STATUS.U;
		/*�жϽ������ݱ�־�Ƿ���*/
		if((StatusTemp_u32 & AURIX_QSPI_STATUS_RXF_MASK) == \
				AURIX_QSPI_STATUS_RXF_MASK)
		{
			break;	/*�������ݱ�־����������ѭ��*/
		}
	}

	/*��ȡSTATUS�Ĵ������� */
	StatusTemp_u32 = AURIX_QSPI_MODULE[arg_QspiIndex_u8].STATUS.U;

	/*����ȡ�������ݱ�־�Ƿ�ʱ���Ƿ��д������*/
	if((OverTimeCnt_u16 < AURIX_QSPI_STATUS_CHECK_NUM_MAX)\
	&&((StatusTemp_u32&AURIX_QSPI_STATUS_ERRORFLAGS_MASK)==0U))
	{
		Status = E_OK;	/*���ͨ��*/
	}
	else
	{
		Status = E_NOT_OK;	/*��鲻ͨ��*/
	}

	return Status;
}

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

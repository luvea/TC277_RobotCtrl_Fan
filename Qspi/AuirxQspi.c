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

/*QSPI模块CLC寄存器MASK*/
#define AURIX_QSPI_ENABLE_CLOCK_MASK		((uint32)0x00000008U)

/*QSPI模块使能BIT MASK*/
#define	AURIX_QSPI_GLOBALCON_ENBIT_MASK		((uint32)0x01000000U)

/*QSPI模块清所有标志位MASK*/
#define AURIX_QSPI_FLAGSCLEAR_ALL_MASK		((uint32)0x0000FFFFU)

/*QSPI模块清除RX标志位MASK*/
#define AURIX_QSPI_FLAGSCLEAR_RXF_MASK		((uint32)0x00000400U)

/*QSPI模块RX状态标志位MASK*/
#define AURIX_QSPI_STATUS_RXF_MASK			((uint32)0x00000400U)

/*QSPI模块错误状态标志位MASK*/
#define AURIX_QSPI_STATUS_ERRORFLAGS_MASK	((uint32)0x000001FFU)

/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/

/*******************************************************************************
**                   Static Local Variables Definition              		  **
*******************************************************************************/
/* SPI 数据内部变量 */
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
** Description	  	: AURIX QSPI模块 初始化
*******************************************************************************/
Std_ReturnType AurixQspi_Init(const AurixQspi_HWCfgType *arg_HWCfg_pst)
{
	Std_ReturnType Status = E_NOT_OK;

	uint8 QspiMoudleCnt_u8;
	uint32 GLOBALCON_Temp_ui32;
	const AurixQspi_MoudleType *AurixQspi_Moudle_ptr;

	if(arg_HWCfg_pst != NULL_PTR)
	{
		/*配置并使能所有需要用到的QSPI模块*/
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

			/*配置GLOBALCON*/
			AURIX_QSPI_MODULE[AurixQspi_Moudle_ptr->ModuleIndx_u8].GLOBALCON.U =\
					AurixQspi_Moudle_ptr->GLOBALCON_u32;

			/*配置GLOBALCON1*/
			AURIX_QSPI_MODULE[AurixQspi_Moudle_ptr->ModuleIndx_u8].GLOBALCON1.U =\
					AurixQspi_Moudle_ptr->GLOBALCON1_u32;

			/*使能QSPI模块*/
			GLOBALCON_Temp_ui32 = \
				AURIX_QSPI_MODULE[AurixQspi_Moudle_ptr->ModuleIndx_u8].GLOBALCON.U;
			GLOBALCON_Temp_ui32 |= AURIX_QSPI_GLOBALCON_ENBIT_MASK;
			AURIX_QSPI_MODULE[AurixQspi_Moudle_ptr->ModuleIndx_u8].GLOBALCON.U =\
					GLOBALCON_Temp_ui32;

			/*清除中断、错误标志*/
			AURIX_QSPI_MODULE[AurixQspi_Moudle_ptr->ModuleIndx_u8].FLAGSCLEAR.U =\
										AURIX_QSPI_FLAGSCLEAR_ALL_MASK;
		}

		Status = E_OK;	/*初始化成功*/
	}
	else
	{
		Status = E_NOT_OK;/*初始化失败*/
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
** Description	  	: 配置 SPI通道
*******************************************************************************/
void AurixQspi_ChannelCfg
(
	uint8 arg_SeqNum_u8,uint32 *arg_TxBuff_u32,\
	uint32 *arg_RxBuff_u32,uint16 arg_Datalen_u16
)

{
	uint8 QspiChannel_u8;
	const AurixQspi_ChannelType *arg_ChannelCfg_pst;                                           //channelType 类型的指针arg_channelCfg_pst

	/*获取通道信息*/
	arg_ChannelCfg_pst = &AurixQspi_Channel_cst[arg_SeqNum_u8];

    /*配置PISEL*/
	AURIX_QSPI_MODULE[arg_ChannelCfg_pst->ModuleIndx_u8].PISEL.U =\
						arg_ChannelCfg_pst->PISEL_u32;
    /*写入ECON*/
	QspiChannel_u8 = arg_ChannelCfg_pst->Qspi_Channel_u8 % 8U;
	AURIX_QSPI_MODULE[arg_ChannelCfg_pst->ModuleIndx_u8].\
						ECON[QspiChannel_u8].U = arg_ChannelCfg_pst->ECON_u32;
	/*写入SSOC*/
	AURIX_QSPI_MODULE[arg_ChannelCfg_pst->ModuleIndx_u8].SSOC.U =\
						arg_ChannelCfg_pst->SSOC_u32;

	/*清空计数值;写入数据长度值*/
	AurixQspi_Data_st[arg_SeqNum_u8].DataCnt_u16 = 0U;
	AurixQspi_Data_st[arg_SeqNum_u8].DataLen_u16 = arg_Datalen_u16;





	/*链接SPI BUFFER指针*/
	switch(arg_ChannelCfg_pst->Data_Length)                                                   //判断指针中的Data_Length
	{
		case AURIX_QSPI_DATA_LENGTH_8:/*SPI 数据宽度为8*/
		{
			AurixQspi_Data_st[arg_SeqNum_u8].TxBuffer_pu8 =\
					(uint8*)arg_TxBuff_u32;
			AurixQspi_Data_st[arg_SeqNum_u8].RxBuffer_pu8 =\
					(uint8*)arg_RxBuff_u32;
			break;
		}
		case AURIX_QSPI_DATA_LENGTH_16:/*SPI 数据宽度为16*/
		{
			AurixQspi_Data_st[arg_SeqNum_u8].TxBuffer_pu16 =\
					(uint16*)arg_TxBuff_u32;
			AurixQspi_Data_st[arg_SeqNum_u8].RxBuffer_pu16 =\
					(uint16*)arg_RxBuff_u32;
			break;
		}
		case AURIX_QSPI_DATA_LENGTH_32:/*SPI 数据宽度为32*/
		{
			AurixQspi_Data_st[arg_SeqNum_u8].TxBuffer_pu32 = arg_TxBuff_u32;
			AurixQspi_Data_st[arg_SeqNum_u8].RxBuffer_pu32 = arg_RxBuff_u32;
			break;
		}
		default:/*SPI 默认数据宽度为32*/
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
** Note	  			: 发送一个10M,16BIT数据,耗时约 2.81US(CPU时钟300M)
** Description	  	: QSPI 同步 数据传输
*******************************************************************************/
Std_ReturnType AurixQspi_Transmit(uint8 arg_SeqNum_u8)
{
	Std_ReturnType Status = E_NOT_OK;
	uint8 QspiMoudleIndex_u8;

	/*获取通道配置信息*/
	const AurixQspi_ChannelType *AurixQspi_Channel_pst =\
			&AurixQspi_Channel_cst[arg_SeqNum_u8];

	/*获取通道数据信息*/
	AurixQspi_DataType *AurixQspi_Data_pst = &AurixQspi_Data_st[arg_SeqNum_u8];

	/*清空计数值*/
	AurixQspi_Data_pst->DataCnt_u16 = 0U;

	/*清空所有状态标志*/
	AURIX_QSPI_MODULE[AurixQspi_Channel_pst->ModuleIndx_u8].FLAGSCLEAR.U =\
						AURIX_QSPI_FLAGSCLEAR_ALL_MASK;

	/*循环发送数据*/
	while(AurixQspi_Data_pst->DataCnt_u16 < AurixQspi_Data_pst->DataLen_u16)
	{
		if((AurixQspi_Data_pst->DataCnt_u16) <\
				(uint16)(AurixQspi_Data_pst->DataLen_u16-1U))/*非最后一位数据*/
		{
			/*写入BACON配置*/
			AURIX_QSPI_MODULE[AurixQspi_Channel_pst->ModuleIndx_u8].\
				BACONENTRY.U = AurixQspi_Channel_pst->BACON_u32;
		}
		else/*最后一位数据*/
		{
			/*LAST 位置1*/
			AURIX_QSPI_MODULE[AurixQspi_Channel_pst->ModuleIndx_u8].\
			BACONENTRY.U = AurixQspi_Channel_pst->BACON_u32 | 1U;
		}

		/*发送数据*/
		AurixQspi_SendData(AurixQspi_Channel_pst,AurixQspi_Data_pst);

		/*检查状态（等待接收标志位、检查错误状态）*/
		QspiMoudleIndex_u8 = AurixQspi_Channel_pst->ModuleIndx_u8;
		Status = AurixQspi_CheckStatus(QspiMoudleIndex_u8);

		if(Status == E_OK)/*接收到数据并且无错误*/
		{
			/*清除接收数据标志*/
			AURIX_QSPI_MODULE[AurixQspi_Channel_pst->ModuleIndx_u8].FLAGSCLEAR.U =\
					AURIX_QSPI_FLAGSCLEAR_RXF_MASK;

			/*读取接收数据*/
			AurixQspi_ReceiveData(AurixQspi_Channel_pst,AurixQspi_Data_pst);

			/*接收数据计数自加*/
			AurixQspi_Data_pst->DataCnt_u16++;
		}
		else/*状态检查失败*/
		{
			break;/*跳出循环*/
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
** Description	  	: QSPI 发送数据,写DATAENTRY寄存器
*******************************************************************************/
static void AurixQspi_SendData
(
	const AurixQspi_ChannelType *AurixQspi_Channel_Ptr,\
	AurixQspi_DataType *AurixQspi_Data_Ptr
)
{
	switch(AurixQspi_Channel_Ptr->Data_Length)/*判断数据位宽*/
	{
		case AURIX_QSPI_DATA_LENGTH_8:/*SPI 数据宽度为8*/
		{
			AURIX_QSPI_MODULE[AurixQspi_Channel_Ptr->ModuleIndx_u8].\
			DATAENTRY[0U].U = (uint32)AurixQspi_Data_Ptr->\
					TxBuffer_pu8[AurixQspi_Data_Ptr->DataCnt_u16];
			break;
		}
		case AURIX_QSPI_DATA_LENGTH_16:/*SPI 数据宽度为16*/
		{
			AURIX_QSPI_MODULE[AurixQspi_Channel_Ptr->ModuleIndx_u8].\
			DATAENTRY[0U].U = (uint32)AurixQspi_Data_Ptr->\
					TxBuffer_pu16[AurixQspi_Data_Ptr->DataCnt_u16];
			break;
		}
		case AURIX_QSPI_DATA_LENGTH_32:/*SPI 数据宽度为32*/
		{
			AURIX_QSPI_MODULE[AurixQspi_Channel_Ptr->ModuleIndx_u8].\
			DATAENTRY[0U].U = (uint32)AurixQspi_Data_Ptr->\
					TxBuffer_pu32[AurixQspi_Data_Ptr->DataCnt_u16];
			break;
		}
		default:/*SPI 默认数据宽度为32*/
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
** Description	  	: QSPI 接收数据,读RXEXIT寄存器
*******************************************************************************/
static void AurixQspi_ReceiveData
(
	const AurixQspi_ChannelType *AurixQspi_Channel_Ptr,\
	AurixQspi_DataType *AurixQspi_Data_Ptr
)
{
	switch(AurixQspi_Channel_Ptr->Data_Length)/*判断数据位宽*/
	{
		case AURIX_QSPI_DATA_LENGTH_8:/*SPI 数据宽度为8*/
		{
			AurixQspi_Data_Ptr->\
			RxBuffer_pu8[AurixQspi_Data_Ptr->DataCnt_u16] = \
			(uint8)AURIX_QSPI_MODULE[AurixQspi_Channel_Ptr->ModuleIndx_u8].\
																RXEXIT.U;
			break;
		}
		case AURIX_QSPI_DATA_LENGTH_16:/*SPI 数据宽度为16*/
		{
			AurixQspi_Data_Ptr->\
			RxBuffer_pu16[AurixQspi_Data_Ptr->DataCnt_u16] =\
			(uint16)AURIX_QSPI_MODULE[AurixQspi_Channel_Ptr->ModuleIndx_u8].\
																RXEXIT.U;
			break;
		}
		case AURIX_QSPI_DATA_LENGTH_32:/*SPI 数据宽度为32*/
		{
			AurixQspi_Data_Ptr->\
			RxBuffer_pu32[AurixQspi_Data_Ptr->DataCnt_u16] =\
			(uint32)AURIX_QSPI_MODULE[AurixQspi_Channel_Ptr->ModuleIndx_u8].\
																RXEXIT.U;
			break;
		}
		default:/*SPI 默认数据宽度为32*/
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
** Description	  	: AURIX QSPI 检查状态
*******************************************************************************/
static Std_ReturnType AurixQspi_CheckStatus(uint8 arg_QspiIndex_u8)
{
	Std_ReturnType Status = E_NOT_OK;
	uint16 OverTimeCnt_u16;
	uint32 StatusTemp_u32;

	/*循环获取并检测STATUS*/
	for(OverTimeCnt_u16=0U;OverTimeCnt_u16 < \
		AURIX_QSPI_STATUS_CHECK_NUM_MAX;OverTimeCnt_u16++)
	{
		/*获取STATUS寄存器数据 */
		StatusTemp_u32 =\
				AURIX_QSPI_MODULE[arg_QspiIndex_u8].STATUS.U;
		/*判断接收数据标志是否建立*/
		if((StatusTemp_u32 & AURIX_QSPI_STATUS_RXF_MASK) == \
				AURIX_QSPI_STATUS_RXF_MASK)
		{
			break;	/*接收数据标志建立，跳出循环*/
		}
	}

	/*获取STATUS寄存器数据 */
	StatusTemp_u32 = AURIX_QSPI_MODULE[arg_QspiIndex_u8].STATUS.U;

	/*检查获取接收数据标志是否超时、是否有错误产生*/
	if((OverTimeCnt_u16 < AURIX_QSPI_STATUS_CHECK_NUM_MAX)\
	&&((StatusTemp_u32&AURIX_QSPI_STATUS_ERRORFLAGS_MASK)==0U))
	{
		Status = E_OK;	/*检查通过*/
	}
	else
	{
		Status = E_NOT_OK;	/*检查不通过*/
	}

	return Status;
}

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

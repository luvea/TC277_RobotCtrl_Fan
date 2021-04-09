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
* $Name______: AurixQspi_PBCfg.c$
* $Variant___: 1.0.0$
* $Revision__: 0$
* $Author____: YM$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: Yes
**----------------------------------------------------------------------------**
** DESCRIPTION:
** AURIX QSPI manual driver PB configuration source code
*******************************************************************************/

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
**                   Static Local Variables Definition              		  **
*******************************************************************************/

/*******************************************************************************
**                     Global Variables Definition              		      **
*******************************************************************************/
/* SPI 模块配置 */
const AurixQspi_MoudleType AurixQspi_Moudle_cst[AURIX_QSPI_MOUDLE_USE_NUM] =
{
	/* QSPI MOUDLE 0 */
//	{//slave
//		0U, 			/*QSPI模块索引*/
//		0x050F3E00U,	/*GLOBALCON*/                   //050 slave
//		0x16E0977FU,	/*GLOBALCON1*/
//	},

	{//master
		0U, 			/*QSPI模块索引*/
		0x010F3C00U,	/*GLOBALCON*/      //master 7c/3c                                                            //00000001 00001111 00111100 00000000
		0x16E0977FU,	/*GLOBALCON1*/                                                                //00010110 11100000 10010111 01111111
	},
//	{//master
//		3U, 			/*QSPI模块索引*/
//		0x010F3C00U,	/*GLOBALCON*/
//		0x16E0977FU,	/*GLOBALCON1*/
//	},
};

/* SPI 通道配置 */
const AurixQspi_ChannelType AurixQspi_Channel_cst[AURIX_QSPI_CHANNEL_USE_NUM] =
{
//	{
//		0U, 						/*QSPI模块索引*/
//		5U,							/*QSPI通道(Channel 13)*/
//		AURIX_QSPI_DATA_LENGTH_8,	/*数据位宽*/
//		/*24bit ,2M*/
//		0xD3B12493U,				/*BACON*/               //channel 13 8bit
//		0x00001FC4U,				/*ECON*/                //1FC4U
//		/*MRST1A,P20.12*/
//		0x00002000U,				/*PISEL*/               //MTSRA     SLSI B
//		/*CHANNEL 13*/
//		0x20000000U,				/*SSOC*/               //channel 13
//	},




		//cs4
	{
		0U, 						/*QSPI模块索引*/
		2U,							/*QSPI通道(Channel 2)*/
		AURIX_QSPI_DATA_LENGTH_32,	/*数据位宽*/
		/*24bit ,2M*/
		0x2BB12493U,				/*BACON*/                       //ch2
		0x00000FC4U,				/*ECON*///FC4U
		/*MRST1A,P20.12*/
		0x00000000U,				/*PISEL*/
		/*CHANNEL 6*/
		0x00040000U,				/*SSOC*/                        //cs ch2
	},


		/*24 bit*/   //cs3
		{
			0U, 						/*QSPI模块索引*/
			0U,							/*QSPI通道(Channel 8)*/
			AURIX_QSPI_DATA_LENGTH_32,	/*数据位宽*/
			/*24bit ,2M*/
			0x8BB12493U,				/*BACON*/
			0x00000FC4U,				/*ECON*///FC4U
			/*MRST1A,P20.12*/
			0x00000000U,				/*PISEL*/
			/*CHANNEL 8*/
			0x01000000U,				/*SSOC*/
		},




//		/*24 bit*/cs2
		{
			0U, 						/*QSPI模块索引*/
			1U,							/*QSPI通道(Channel 9)*/
			AURIX_QSPI_DATA_LENGTH_32,	/*数据位宽*/
			/*24bit ,2M*/
			0x9BB12493U,				/*BACON*/
			0x00000FC4U,				/*ECON*///FC4U
			/*MRST1A,P20.12*/
			0x00000000U,				/*PISEL*/
			/*CHANNEL 9*/
			0x02000000U,				/*SSOC*/
		},




		//cs1
		{
			0U, 						/*QSPI模块索引*/
			2U,							/*QSPI通道(Channel 10)*/
			AURIX_QSPI_DATA_LENGTH_32,	/*数据位宽*/
			/*24bit ,2M*/
			0xABB12493U,				/*BACON*/
			0x00000FC4U,				/*ECON*///FC4U
			/*MRST1A,P20.12*/
			0x00000000U,				/*PISEL*/
			/*CHANNEL 8*/
			0x04000000U,				/*SSOC*/
		},

};
/*******************************************************************************
**                  Static Local Function Declaration            		      **
*******************************************************************************/

/*******************************************************************************
**                 		  Function Source Code            		              **
*******************************************************************************/


/*******************************************************************************
* $History__:$
* V1.0.0; 0     02.06.2017 YM
*  N: new created
*******************************************************************************/


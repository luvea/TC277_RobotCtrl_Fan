/*
 * Uart_Test.c
 *
 *  Created on: 2021Äê1ÔÂ21ÈÕ
 *      Author: jw
 */

/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2014)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Uart_Demo.c $                                              **
**                                                                           **
**  $CC VERSION : \main\19 $                                                 **
**                                                                           **
**  $DATE       : 2014-07-23 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                - Sample Demo Application for UART module                  **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Mcal.h"

#include "Test_Print.h"
#include "Test_Time.h"
#include "Test_Main.h"
#include "DemoApp_Cfg.h"

#include "Uart_Test.h"
#include "Dio.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/



/*******************************************************************************
**                      Private Variable Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

uint8 UartDemo_ValidateData(uint16 UartRxDataCnt)
{
  uint16 idx;
  uint8 RsltDataCheck = 0;

  #if (UART_NINEBITS_USED == STD_ON)
  UartRxDataCnt = UartRxDataCnt/2;
  #endif

  for(idx = 0; idx < UartRxDataCnt; idx++)
  {
    /*Compare Data Read with the Data Written for the Channel*/
  #if (UART_NINEBITS_USED == STD_ON)
    if((Uart_TxDataBuff[idx] & UART_NINE_BIT_DATA_MASK) == \
      Uart_RxDataBuff[idx])
  #else
    if(Uart_TxDataBuff[idx] == Uart_RxDataBuff[idx])
  #endif
     {
       RsltDataCheck =0;
     }
     else
     {
       RsltDataCheck =1;
       break;
     }
  }

  /*Clear the App Rx Data Buffer for Next Operation*/
//  for(idx = 0; idx < UartRxDataCnt; idx++)
//  {
//   Uart_RxDataBuff[idx] = 0;
//  }

  return RsltDataCheck;
}

uint8 Ultrasonic_Uart1(Uart_ChannelIdType Channel,uint8 Uart_Data_u8[10], uint32 Distance_Data_u32[4])
{

	Dio_WriteChannel(DioConf_DioChannel_D0_USS1_TX, STD_HIGH);

	uint8 UltraData_Num = 10;

    Uart_Read(Channel, Uart_Data_u8, UltraData_Num);

    Distance_Data_u32[0] = Uart_Data_u8[1] * 256 + Uart_Data_u8[2];
    Distance_Data_u32[1] = Uart_Data_u8[3] * 256 + Uart_Data_u8[4];
    Distance_Data_u32[2] = Uart_Data_u8[5] * 256 + Uart_Data_u8[6];
    Distance_Data_u32[3] = Uart_Data_u8[7] * 256 + Uart_Data_u8[8];
    return UltraData_Num;
 }

uint8 Ultrasonic_Uart2(Uart_ChannelIdType Channel,uint8 Uart_Data_u8[10], uint32 Distance_Data_u32[4])
{

	Dio_WriteChannel(DioConf_DioChannel_DO_USS2_TX, STD_HIGH);

	uint8 UltraData_Num = 10;

    Uart_Read(Channel, Uart_Data_u8, UltraData_Num);

    Distance_Data_u32[0] = Uart_Data_u8[1] * 256 + Uart_Data_u8[2];
    Distance_Data_u32[1] = Uart_Data_u8[3] * 256 + Uart_Data_u8[4];
    Distance_Data_u32[2] = Uart_Data_u8[5] * 256 + Uart_Data_u8[6];
    Distance_Data_u32[3] = Uart_Data_u8[7] * 256 + Uart_Data_u8[8];
    return UltraData_Num;
 }


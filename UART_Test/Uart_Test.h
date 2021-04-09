/*
 * Uart_Test.h
 *
 *  Created on: 2021Äê1ÔÂ21ÈÕ
 *      Author: jw
 */

#ifndef UART_TEST_UART_TEST_H_
#define UART_TEST_UART_TEST_H_

/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Uart_Demo.h $                                              **
**                                                                           **
**  $CC VERSION : \main\5 $                                                  **
**                                                                           **
**  $DATE       : 2013-06-25 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                - sample Demo Test for UART module                         **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Uart.h"
#include "Std_Types.h"
#include "Mcal.h"

#include "DemoApp_Cfg.h"
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define UART_NINE_BIT_DATA_MASK   (0x01FFU)
#define UART_TX_DATA_COUNT        (10U)

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/
extern uint8 Uart_TxDataBuff[12];
extern uint8 Uart_RxDataBuff[12];


/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
extern uint8 UartDemo_ValidateData(uint16 UartRxDataCnt);
extern void TestUartReadandWrite();
extern void UartDemo_AbortReadWrite();
extern void UartReceiveNotif (Uart_ErrorIdType Error);
extern void UartTransmitNotif (Uart_ErrorIdType Error);
extern uint8 Ultrasonic_Uart1(Uart_ChannelIdType Channel,uint8 Uart_Data_u8[10], uint32 Distance_Data_u32[4]);
extern uint8 Ultrasonic_Uart2(Uart_ChannelIdType Channel,uint8 Uart_Data_u8[10], uint32 Distance_Data_u32[4]);

#endif /* UART_TEST_UART_TEST_H_ */

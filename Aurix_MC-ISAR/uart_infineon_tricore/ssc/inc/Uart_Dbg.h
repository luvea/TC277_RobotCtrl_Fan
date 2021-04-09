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
**  $FILENAME   : Uart_Dbg.h $                                               **
**                                                                           **
**  $CC VERSION : \main\4 $                                                  **
**                                                                           **
**  $DATE       : 2014-11-06 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                Debug information of UART driver                           **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

#ifndef UART_DBG_H
#define UART_DBG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Uart.h"

/*******************************************************************************
**                            Global Variables                                **
*******************************************************************************/
#if ( UART_DEBUG_SUPPORT == STD_ON )

#define UART_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

extern Uart_ChannelInfoType  Uart_ChannelInfo[UART_MAXIMUM_CHANNEL];

#define UART_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#endif /* End of UART_DEBUG_SUPPORT */

#endif /* UART_DBG_H */

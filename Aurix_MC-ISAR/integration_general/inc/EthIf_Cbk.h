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
**  $FILENAME   : EthIf_Cbk.h $                                              **
**                                                                           **
**  $CC VERSION : \main\6 $                                                  **
**                                                                           **
**  $DATE       : 2013-06-19 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                Implementation of ETH interface callback functions         **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/

#ifndef ETHIF_CBK_H
#define ETHIF_CBK_H

#include "Eth_17_EthMac.h"
#include "ComStack_Types.h"

extern volatile uint8 TxFrameCount;

extern void EthIf_Cbk_RxIndication(uint8 CtrlIdx,uint8* DataPtr,uint16 LenByte);
extern void EthIf_Cbk_TxConfirmation( uint8 CtrlIdx, uint8 BufIdx );

#endif

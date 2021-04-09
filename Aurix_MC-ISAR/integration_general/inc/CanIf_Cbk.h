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
**  $FILENAME   : CanIf_Cbk.h $                                              **
**                                                                           **
**  $CC VERSION : \main\12 $                                                 **
**                                                                           **
**  $DATE       : 2013-06-19 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This file contains CAN interface functions.               **
**                  This file is for Evaluation Purpose Only                 **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/

#ifndef CANIF_CBK_H
#define CANIF_CBK_H
#include "ComStack_Types.h"
#include "CanIf.h"
#include "EcuM.h"

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#ifdef ECUM_USES_CAN
#include "Can_17_MCanP.h"
#endif

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

#ifdef ECUM_USES_CAN

extern void CanIf_RxIndication(Can_HwHandleType Hrh,
                               Can_IdType CanId,
                               uint8 CanDlc, 
                               const uint8 *CanSduPtr);

extern void CanIf_TxConfirmation(PduIdType CanTxPduId);

extern void CanIf_ControllerBusOff(uint8 ControllerId);

extern void CanIf_ControllerModeIndication(uint8 ControllerId,
                                    CanIf_ControllerModeType ControllerMode);

extern boolean Appl_LPduRxCalloutFunction(uint8 Hrh,
                                          Can_IdType CanId,
                                          uint8 CanDlc,
                                          const uint8 *CanSduPtr);

#endif


#endif
/*END OF CANIF_CBK_H */

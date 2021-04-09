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
**  $FILENAME   : CanTrcv6250GV33_Cbk.h $                                    **
**                                                                           **
**  $CC VERSION : \main\3 $                                                  **
**                                                                           **
**  $DATE       : 2013-06-19 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This header file exports                                  **
**                 - CAN Transceiver Call back function declaration          **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/

#ifndef CANTRCV6250GV33_CBK_H
#define CANTRCV6250GV33_CBK_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
/******************************************************************************
** Syntax : Std_ReturnType CanTrcv_17_6250GV33_CB_WakeupByBus(               **
**                                          uint8 CanNetwork)                **
**                                                                           **
** Service ID:  0x07                                                         **
**                                                                           **
** Sync/Async:  Synchronous                                                  **
**                                                                           **
** Reentrancy:  non reentrant                                                **
**                                                                           **
** Parameters (in): CanNetwork - CAN Network to which the API                **
**                               call has to be applied.                     **
** Parameters (out):  E_OK : when a valid interrupt is detected              **
**                    E_NOT_OK : when a no interrupt is detected             **
**                                                                           **
** Return value:  none                                                       **
**                                                                           **
** Description :                                                             **
**    - CanTrcv012: This function is called by underlying SPAL Icu driver in **
**                  case a wake up interrupt is detected. The API validates  **
**                  wake up reason in terms whether it is a wake up or not.  **
**                                                                           **
******************************************************************************/
extern Std_ReturnType CanTrcv_17_6250GV33_CB_WakeupByBus(uint8 CanNetwork);

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#endif
  /*End of  CANTRCV6250GV33_CBK_H */

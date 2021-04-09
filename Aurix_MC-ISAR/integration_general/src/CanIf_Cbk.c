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
**  $FILENAME   : CanIf_Cbk.c $                                              **
**                                                                           **
**  $CC VERSION : \main\9 $                                                  **
**                                                                           **
**  $DATE       : 2013-06-20 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : Implementation of CAN interface callback functions for     **
**                module testing                                             **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include <CanIf_Cbk.h>
#include <Test_Print.h>
#include <Mcal.h>

#ifdef ECUM_USES_CAN
/* Macro to set MSB for Extended messages */
#define CAN_EXTENDED_MSB_SET            (0x80000000U)

extern uint8 Test_RxConfirmCount;
extern uint8 Test_TxConfirmCount;

/*******************************************************************************
                      CanIf_RxIndication
*******************************************************************************/
void CanIf_RxIndication(Can_HwHandleType Hrh,
                        Can_IdType CanId,
                        uint8 CanDlc, 
                        const uint8 *CanSduPtr)
{
  uint8 i;

  #if (CAN_STANDARD_ID_ONLY == STD_OFF) 
  if(CanId & CAN_EXTENDED_MSB_SET)
  {
    print_f("\n Received a Extended Id Message! ");
    print_f(" Hrh = %d, ID = 0x%x, DLC = %d",Hrh,CanId&0x1FFFFFFF,CanDlc);
  }
  else
  #endif
  {
    print_f("\n Received a Standard Id Message! ");
    print_f("\n Hrh = %d, ID = 0x%x, DLC = %d", Hrh, CanId, CanDlc );
  }
  
  
  print_f(" Msg = ");
  for (i=0; i < CanDlc ; i++)
  {
    print_f("%x ",CanSduPtr[i]);
  }
  print_f("\n");

  Test_RxConfirmCount++ ;
}

/*******************************************************************************
                      CanIf_TxConfirmation
*******************************************************************************/
void CanIf_TxConfirmation (PduIdType CanTxPduId)
{
  print_f("\n Transmitted a message! CanTxPduId = %d", CanTxPduId);
  Test_TxConfirmCount++ ;
}

/*******************************************************************************
                      CanIf_ControllerBusOff
*******************************************************************************/
void CanIf_ControllerBusOff(uint8 ControllerId)
{
  print_f("\n Callback function Can_ControllerBusOff is called!");
  print_f("ControllerId = %d", ControllerId);
}

/*******************************************************************************
                    CanIf_ControllerModeIndication
*******************************************************************************/
void CanIf_ControllerModeIndication( uint8 ControllerId,
                                     CanIf_ControllerModeType ControllerMode )
{
  print_f("\n Callback function CanIf_ControllerModeIndication is called!\n");
  print_f(" ControllerId = %d \n", ControllerId);
  print_f(" ControllerMode = %d \n", ControllerMode);
}

/*******************************************************************************
                  CAN L-PDU Rx Callout Function Definition
*******************************************************************************/
boolean Appl_LPduRxCalloutFunction(uint8 Hrh,
                                   Can_IdType CanId,
                                   uint8 CanDlc,
                                   const uint8 *CanSduPtr)
{
  UNUSED_PARAMETER (Hrh)
  UNUSED_PARAMETER (CanId)
  UNUSED_PARAMETER (CanDlc)
  UNUSED_PARAMETER (CanSduPtr)
  print_f("\n Callback function Appl_LPduRxCalloutFunction is called!");
  return(TRUE);
}
#endif

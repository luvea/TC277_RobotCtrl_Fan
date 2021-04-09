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
**  $FILENAME   : CanIf.c $                                                  **
**                                                                           **
**  $CC VERSION : \main\6 $                                                  **
**                                                                           **
**  $DATE       : 2014-12-09 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains CAN interface (CanIf) function          **
**                definitions                                                **
**                Note : This file is for Evaluation Purpose Only            **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of CanIf module header file  */
#include "CanIf.h"
#include "Mcal.h"
#include "Test_Print.h"
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*******************************************************************************
** Syntax : void CanIf_SetWakeupEvent(uint8 CanNetwork,                       **
**                                    CanIf_WakeupSourceType WakeupSource )   **
**                                                                            **
** Service ID: none                                                           **
**                                                                            **
** Sync/Async:  none                                                          **
**                                                                            **
** Reentrancy:  none                                                          **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:  none                                                        **
**                                                                            **
** Description : This function is called in CanTrcv_MainFunction or           **
**               CanTrcv_CB_WakeupByBus function.                             **
**                                                                            **
*******************************************************************************/
void CanIf_SetWakeupEvent(uint8 CanNetwork,
                                   CanIf_WakeupSourceType WakeupSource )
{
	UNUSED_PARAMETER(CanNetwork)
	UNUSED_PARAMETER(WakeupSource)
}


void CanIf_CheckWakeup(CanIf_WakeupSourceType WakeupSource )
{

UNUSED_PARAMETER(WakeupSource)
	
}

void CanIf_TrcvModeIndication(uint8 Transceiver,CanTrcv_TrcvModeType OpMode)
{
	UNUSED_PARAMETER(Transceiver)
	UNUSED_PARAMETER(OpMode)
  print_f("\n Callback function CanIf_TrcvModeIndication is called!\n");
  print_f(" Transceiver = %d \n", Transceiver);
  print_f(" OpMode = %d \n", OpMode);
}

void CanIf_CheckTrcvWakeFlagIndication(uint8 Transceiver)
{
		UNUSED_PARAMETER(Transceiver)
    print_f("\n Callback function CanIf_CheckTrcvWakeFlagIndication is called!\n");
    print_f(" Transceiver = %d \n", Transceiver);
}

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

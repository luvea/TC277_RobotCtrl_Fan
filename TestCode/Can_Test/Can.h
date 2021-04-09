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
**  $FILENAME   : Can_17_MCanP_Demo.h $                                      **
**                                                                           **
**  $CC VERSION : \main\6 $                                                  **
**                                                                           **
**  $DATE       : 2013-06-25 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                - Import file for demo application for CAN driver          **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
** Syntax : void Can_17_MCanP_Demo(void)                                      **
**                                                                            **
** Service ID:   : NA                                                         **
**                                                                            **
** Sync/Async:   : Synchronous                                                **
**                                                                            **
** Reentrancy:   : Non Reentrant                                              **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : DemoApp for CAN driver                                       **
**                                                                            **
*******************************************************************************/
#define CAN_17_MCANP_START_SEC_CODE
#include "MemMap.h"
#include "Std_Types.h"
#include <Hal_Sensor.h>
#include "IfxSrc_reg.h"
#include "Std_Types.h"
#include "Mcal.h"
#include "Can_17_MCanP.h"
#include "Test_Print.h"
#include "EcuM.h"
#include "Irq.h"
#include "Adc.h"
#include "Adc3ph.h"
//#include "Testmodel_Core1.h"
//#include "Testmodel_Core2.h"
#include "Testmodel.h"

extern void Can_17_MCanP_Send(void);
extern void Can_MCanP_Init(void);
extern void Can_EnableServiceRequest(uint8 node);

#define CAN_17_MCANP_STOP_SEC_CODE
#include "MemMap.h"

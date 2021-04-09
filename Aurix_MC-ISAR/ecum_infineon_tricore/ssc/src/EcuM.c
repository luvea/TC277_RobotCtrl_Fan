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
**  $FILENAME   : EcuM.c $                                                   **
**                                                                           **
**  $CC VERSION : \main\6 $                                                  **
**                                                                           **
**  $DATE       : 2016-07-01 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : Contains a simple example of ECU State Manager Code       **
**                 This file is for Evaluation Purpose Only                  **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "EcuM.h"
#include "EcuM_Cbk.h"
#include "Mcu.h"

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
**                      Global Functon Definitions                            **
*******************************************************************************/
#define ECUM_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives 
  is allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
** Syntax           : void EcuM_Init(const EcuM_ConfigType *configptr)        **
**                                                                            **
** Service ID       : None/<Specified>                                        **
**                                                                            **
** Sync/Async       : Synchronous / Asynchronous                              **
**                                                                            **
** Reentrancy       : Non-reentrant / Reentrant                               **
**                                                                            **
** Parameters(in)   : None/<Specified>                                        **
**                                                                            **
** Parameters (out) : None/<Specified>                                        **
**                                                                            **
** Return value     : None/<Specified>                                        **
**                                                                            **
** Description      : <Suitable Description>                                  **
**                                                                            **                                                                                                                                 **
*******************************************************************************/

void EcuM_Init(const EcuM_ConfigType *configptr) 
{
  volatile uint32 ConfError;
  
  ConfError = 0;
  
  
  /* Check Consistency of configuration data */
  if(EcuM_ConfigConsistencyHash !=  configptr->PreCompileIdentifier) 
  {
    /* printf("Configuration mismatch!!!\n"); */
    ConfError=2;
  }
  if (ConfError!=0)  
  {
    /* print_f("\nConfiguration Problem\n "); */
  }
           
  /*Initialize DET Module*/
  /*Det_Init();*/
  
  /*Pre-Initialize DEM Module*/
  /*Dem_PreInit()*/

  /*Call Driver Init Zero. Initialize drivers before OS Init*/
  /* no parameters for this function, call modules like DET or 
     pre compile, LT modules */
  EcuM_AL_DriverInitZero();
  
  /* List one is mandated with MCU configuration */
  /*Initialize MCU Driver*/
  #if(MCU_USES_FIXED_ADDR == ON)
  Mcu_Init(&Mcu_ConfigRoot[0]);
  #else
  Mcu_Init(configptr->Mcu_ConfigData);
  #endif
     
  /*Call Driver Init One. Initialize drivers before OS Init*/
  EcuM_AL_DriverInitOne(configptr);
  
  /*Select Shut Down Target*/
  
  /* Call OS */  
 
  /*Call Driver Init Two. Initialize drivers after OS Init*/
  EcuM_AL_DriverInitTwo(configptr);
  /*Call Driver Init Three. Initialize drivers after OS Init*/
  EcuM_AL_DriverInitThree(configptr);





}
/*******************************************************************************
** Syntax           : void EcuM_SetWakeupEvent(EcuM_WakeupSourceType events)  **
**                                                                            **
** Service ID       : None/<Specified>                                        **
**                                                                            **
** Sync/Async       : Synchronous / Asynchronous                              **
**                                                                            **
** Reentrancy       : Non-reentrant / Reentrant                               **
**                                                                            **
** Parameters(in)   : None/<Specified>                                        **
**                                                                            **
** Parameters (out) : None/<Specified>                                        **
**                                                                            **
** Return value     : None/<Specified>                                        **
**                                                                            **
** Description      : <Suitable Description>                                  **
**                                                                            **                                                                                                                                 **
*******************************************************************************/
void EcuM_SetWakeupEvent(EcuM_WakeupSourceType WakeupInfo)
{
  UNUSED_PARAMETER(WakeupInfo)
}
/*******************************************************************************
** Syntax           : void EcuM_ValidateWakeupEvent                           **
**                    (EcuM_WakeupSourceType events)                          **
**                                                                            **
** Service ID       : None/<Specified>                                        **
**                                                                            **
** Sync/Async       : Synchronous / Asynchronous                              **
**                                                                            **
** Reentrancy       : Non-reentrant / Reentrant                               **
**                                                                            **
** Parameters(in)   : None/<Specified>                                        **
**                                                                            **
** Parameters (out) : None/<Specified>                                        **
**                                                                            **
** Return value     : None/<Specified>                                        **
**                                                                            **
** Description      : <Suitable Description>                                  **
**                                                                            **                                                                                                                                 **
*******************************************************************************/
void EcuM_ValidateWakeupEvent(EcuM_WakeupSourceType events)
{
  UNUSED_PARAMETER(events)
}

/*******************************************************************************
** Syntax           : void EcuM_CheckWakeup                                   **
**                    (EcuM_WakeupSourceType wakeupSource)                    **
**                                                                            **
** Service ID       : None/<Specified>                                        **
**                                                                            **
** Sync/Async       : Synchronous / Asynchronous                              **
**                                                                            **
** Reentrancy       : Non-reentrant / Reentrant                               **
**                                                                            **
** Parameters(in)   : wakeupSource                                            **
**                                                                            **
** Parameters (out) : None/<Specified>                                        **
**                                                                            **
** Return value     : None/<Specified>                                        **
**                                                                            **
** Description      : <Suitable Description>                                  **
**                                                                            **                                                                                                                                 **
*******************************************************************************/
void EcuM_CheckWakeup(EcuM_WakeupSourceType wakeupSource)
{
  UNUSED_PARAMETER(wakeupSource)
}
#define ECUM_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives 
  is allowed only for MemMap.h*/
#include "MemMap.h"

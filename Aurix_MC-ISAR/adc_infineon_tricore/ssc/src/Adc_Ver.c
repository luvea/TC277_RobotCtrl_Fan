/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : Adc_Ver.c $                                                **
**                                                                            **
**   $CC VERSION : \main\8 $                                                  **
**                                                                            **
**   $DATE       : 2016-03-22 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : This file contains                                         **
**                 - Autosar specific functionality of Adc driver.            **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**  TRACEABILITY: [cover parentID=DS_NAS_ADC_PR730,DS_AS40X_ADC124]           **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - Autosar specific functionality of Adc driver.            **
**                                                                            **
**  [/cover]                                                                  **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* this includes Adc.h file and declare the functions defined here  */
#include "Adc_Utility.h"
/* To use OS call in ADC functions */
#include "SchM_Adc.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/* Check for definition of the AS Version */
#ifndef ADC_AR_RELEASE_MAJOR_VERSION
  #error "ADC_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif

#ifndef ADC_AR_RELEASE_MINOR_VERSION
  #error "ADC_AR_RELEASE_MINOR_VERSION is not defined. "
#endif

#ifndef ADC_AR_RELEASE_REVISION_VERSION
  #error "ADC_AR_RELEASE_REVISION_VERSION is not defined. "
#endif

#if ( ADC_AR_RELEASE_MAJOR_VERSION != 4U)
  #error "ADC_AR_RELEASE_MAJOR_VERSION does not match. "
#endif

#if ( ADC_AR_RELEASE_MINOR_VERSION != 0U )
  #error "ADC_AR_RELEASE_MINOR_VERSION does not match. "
#endif


#ifndef ADC_SW_MAJOR_VERSION
  #error "ADC_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef ADC_SW_MINOR_VERSION
  #error "ADC_SW_MINOR_VERSION is not defined. "
#endif

#ifndef ADC_SW_PATCH_VERSION
  #error "ADC_SW_PATCH_VERSION is not defined. "
#endif

/* Check for Correct inclusion of headers */
#if ( ADC_SW_MAJOR_VERSION != 3U )
  #error "ADC_SW_MAJOR_VERSION does not match. "
#endif

#if ( ADC_SW_MINOR_VERSION != 2U )
  #error "ADC_SW_MINOR_VERSION does not match. "
#endif

/*
  ADC124: Inter Module Checks to avoid integration of incompatible files
  Its applicable and available for AS4.0 and higher versions
*/
#if (ADC_DEV_ERROR_DETECT == STD_ON)

#ifndef DET_AR_RELEASE_MAJOR_VERSION
  #error "DET_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif

#ifndef DET_AR_RELEASE_MINOR_VERSION
  #error "DET_AR_RELEASE_MINOR_VERSION is not defined. "
#endif

#if (IFX_DET_VERSION_CHECK == STD_ON)

#if ( DET_AR_RELEASE_MAJOR_VERSION != 4U )
  #error "DET_AR_RELEASE_MAJOR_VERSION does not match. "
#endif

#if ( DET_AR_RELEASE_MINOR_VERSION != 0U )
  #error "DET_AR_RELEASE_MINOR_VERSION does not match. "
#endif

#endif /* (IFX_DET_VERSION_CHECK == STD_ON) */

#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

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

#define ADC_START_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/* Enable/Disable the use of the function */
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/*******************************************************************************
** Syntax           : void Adc_lSchmEnterStartGroup                           **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Calls the SchM function to suspend the interrupts       **
**                                                                            **
*******************************************************************************/
void Adc_lSchmEnterStartGroup(void)
{
  SchM_Enter_Adc_StartGroup();
}
/*******************************************************************************
** Syntax           : void Adc_lSchmExitStartGroup                            **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Calls the SchM function to resume the interrupts        **
**                                                                            **
*******************************************************************************/
void Adc_lSchmExitStartGroup(void)
{
  SchM_Exit_Adc_StartGroup();
}
/*******************************************************************************
** Syntax           : void Adc_lSchmEnterStopGroup                            **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Calls the SchM function to suspend the interrupts       **
**                                                                            **
*******************************************************************************/
void Adc_lSchmEnterStopGroup(void)
{
  SchM_Enter_Adc_StopGroup();
}
/*******************************************************************************
** Syntax           : void Adc_lSchmExitStopGroup                             **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Calls the SchM function to resume the interrupts        **
**                                                                            **
*******************************************************************************/
void Adc_lSchmExitStopGroup(void)
{
  SchM_Exit_Adc_StopGroup();
}
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

/* Enable/Disable the use of the function */
#if (ADC_HW_TRIGGER_API == STD_ON)
/*******************************************************************************
** Syntax           : void Adc_lSchmEnterEnableHwTrig                         **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Calls the SchM function to suspend the interrupts       **
**                                                                            **
*******************************************************************************/
void Adc_lSchmEnterEnableHwTrig(void)
{
  SchM_Enter_Adc_EnableHwTrig();
}
/*******************************************************************************
** Syntax           : void Adc_lSchmExitEnableHwTrig                          **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Calls the SchM function to resume the interrupts        **
**                                                                            **
*******************************************************************************/
void Adc_lSchmExitEnableHwTrig(void)
{
  SchM_Exit_Adc_EnableHwTrig();
}
/*******************************************************************************
** Syntax           : void Adc_lSchmEnterDisableHwTrig                        **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Calls the SchM function to suspend the interrupts       **
**                                                                            **
*******************************************************************************/
void Adc_lSchmEnterDisableHwTrig(void)
{
  SchM_Enter_Adc_DisableHwTrig();
}
/*******************************************************************************
** Syntax           : void Adc_lSchmExitDisableHwTrig                         **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Calls the SchM function to resume the interrupts        **
**                                                                            **
*******************************************************************************/
void Adc_lSchmExitDisableHwTrig(void)
{
  SchM_Exit_Adc_DisableHwTrig();
}
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
/*******************************************************************************
** Syntax           : void Adc_lSchmEnterGetGrpStatus                         **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Calls the SchM function to suspend the interrupts       **
**                                                                            **
*******************************************************************************/
void Adc_lSchmEnterGetGrpStatus(void)
{
  SchM_Enter_Adc_GetGrpStatus();
}
/*******************************************************************************
** Syntax           : void Adc_lSchmExitGetGrpStatus                          **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Calls the SchM function to resume the interrupts        **
**                                                                            **
*******************************************************************************/
void Adc_lSchmExitGetGrpStatus(void)
{
  SchM_Exit_Adc_GetGrpStatus();
}

#if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
/*******************************************************************************
** Syntax           : void Adc_lSchmEnterGetStreamLastPtr                     **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Calls the SchM function to suspend the interrupts       **
**                                                                            **
*******************************************************************************/
void Adc_lSchmEnterGetStreamLastPtr(void)
{
  SchM_Enter_Adc_GetStreamLastPtr();
}
/*******************************************************************************
** Syntax           : void Adc_lSchmExitGetStreamLastPtr                      **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Calls the SchM function to resume the interrupts        **
**                                                                            **
*******************************************************************************/
void Adc_lSchmExitGetStreamLastPtr(void)
{
  SchM_Exit_Adc_GetStreamLastPtr();
}

#if (ADC_READ_GROUP_API == STD_ON)
/*******************************************************************************
** Syntax           : void Adc_lSchmEnterReadGroup                            **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Calls the SchM function to suspend the interrupts       **
**                                                                            **
*******************************************************************************/
void Adc_lSchmEnterReadGroup(void)
{
  SchM_Enter_Adc_ReadGroup();
}
/*******************************************************************************
** Syntax           : void Adc_lSchmExitReadGroup                             **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Calls the SchM function to resume the interrupts        **
**                                                                            **
*******************************************************************************/
void Adc_lSchmExitReadGroup(void)
{
  SchM_Exit_Adc_ReadGroup();
}
#endif /* (ADC_READ_GROUP_API == STD_ON) */
#endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */

/* Queue Enable is STD_ON only during No priority */
#if (ADC_ENABLE_QUEUING == STD_ON)
/*******************************************************************************
** Syntax           : void Adc_lSchmEnterPopQueue                             **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Calls the SchM function to suspend the interrupts       **
**                                                                            **
*******************************************************************************/
void Adc_lSchmEnterPopQueue(void)
{
  SchM_Enter_Adc_PopQueue();
}
/*******************************************************************************
** Syntax           : void Adc_lSchmExitPopQueue                              **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Calls the SchM function to resume the interrupts        **
**                                                                            **
*******************************************************************************/
void Adc_lSchmExitPopQueue(void)
{
  SchM_Exit_Adc_PopQueue();
}
/*******************************************************************************
** Syntax           : void Adc_lSchmEnterPushQueue                            **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Calls the SchM function to suspend the interrupts       **
**                                                                            **
*******************************************************************************/
void Adc_lSchmEnterPushQueue(void)
{
  SchM_Enter_Adc_PushQueue();
}
/*******************************************************************************
** Syntax           : void Adc_lSchmExitPushQueue                             **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Calls the SchM function to resume the interrupts        **
**                                                                            **
*******************************************************************************/
void Adc_lSchmExitPushQueue(void)
{
  SchM_Exit_Adc_PushQueue();
}
#endif /* (ADC_ENABLE_QUEUING == STD_ON) */

/* Full priority considered */
#if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)
/*******************************************************************************
** Syntax           : void Adc_lSchmEnterScheduleNext                         **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Calls the SchM function to suspend the interrupts       **
**                                                                            **
*******************************************************************************/
void Adc_lSchmEnterScheduleNext(void)
{
  SchM_Enter_Adc_ScheduleNext();
}
/*******************************************************************************
** Syntax           : void Adc_lSchmExitScheduleNext                          **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Calls the SchM function to resume the interrupts        **
**                                                                            **
*******************************************************************************/
void Adc_lSchmExitScheduleNext(void)
{
  SchM_Exit_Adc_ScheduleNext();
}
/*******************************************************************************
** Syntax           : void Adc_lSchmEnterScheduleStart                        **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Calls the SchM function to suspend the interrupts       **
**                                                                            **
*******************************************************************************/
void Adc_lSchmEnterScheduleStart(void)
{
  SchM_Enter_Adc_ScheduleStart();
}
/*******************************************************************************
** Syntax           : void Adc_lSchmExitScheduleStart                         **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Calls the SchM function to resume the interrupts        **
**                                                                            **
*******************************************************************************/
void Adc_lSchmExitScheduleStart(void)
{
  SchM_Exit_Adc_ScheduleStart();
}
/*******************************************************************************
** Syntax           : void Adc_lSchmEnterScheduleStop                         **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Calls the SchM function to suspend the interrupts       **
**                                                                            **
*******************************************************************************/
void Adc_lSchmEnterScheduleStop(void)
{
  SchM_Enter_Adc_ScheduleStop();
}
/*******************************************************************************
** Syntax           : void Adc_lSchmExitScheduleStop                          **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Calls the SchM function to resume the interrupts        **
**                                                                            **
*******************************************************************************/
void Adc_lSchmExitScheduleStop(void)
{
  SchM_Exit_Adc_ScheduleStop();
}
#endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) */

#define ADC_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
allowed only for MemMap.h*/
#include "MemMap.h"
/*******************************************************************************
**                            General Notes                                   **
*******************************************************************************/


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
**   $FILENAME   : SchM.c $                                                   **
**                                                                            **
**   $CC VERSION : \main\39 $                                                 **
**                                                                            **
**   $DATE       : 2016-04-05 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : This file contains                                         **
**                 - stub for OS functionality.                               **
**                                                                            **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of Platform_Types.h and Compiler.h */
#include <Std_Types.h>
#include <McalOsConfig.h>
#include <Os.h>

/*******************************************************************************
**                      Imported Compiler Switch Checks                       **
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
**                      Private Function Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/********************************ADC*******************************************/

void SchM_Enter_Adc_StartGroup(void)
{
  SuspendAllInterrupts();
}

void SchM_Enter_Adc_StopGroup(void)
{
  SuspendAllInterrupts();
}

void SchM_Enter_Adc_ReadGroup(void)
{
  SuspendAllInterrupts();
}

void SchM_Enter_Adc_EnableHwTrig(void)
{
  SuspendAllInterrupts();
}

void SchM_Enter_Adc_DisableHwTrig(void)
{
  SuspendAllInterrupts();
}

void SchM_Enter_Adc_GetGrpStatus(void)
{
  SuspendAllInterrupts();
}

void SchM_Enter_Adc_GetStreamLastPtr(void)
{
  SuspendAllInterrupts();
}

void SchM_Enter_Adc_ScheduleStart(void)
{
  SuspendAllInterrupts();
}

void SchM_Enter_Adc_ScheduleStop(void)
{
  SuspendAllInterrupts();
}

void SchM_Enter_Adc_ScheduleNext(void)
{
  SuspendAllInterrupts();
}

void SchM_Enter_Adc_PushQueue(void)
{
  SuspendAllInterrupts();
}

void SchM_Enter_Adc_PopQueue(void)
{
  SuspendAllInterrupts();
}

void SchM_Exit_Adc_StartGroup(void)
{
  ResumeAllInterrupts();
}

void SchM_Exit_Adc_StopGroup(void)
{
  ResumeAllInterrupts();
}

void SchM_Exit_Adc_ReadGroup(void)
{
  ResumeAllInterrupts();
}

void SchM_Exit_Adc_EnableHwTrig(void)
{
  ResumeAllInterrupts();
}

void SchM_Exit_Adc_DisableHwTrig(void)
{
  ResumeAllInterrupts();
}

void SchM_Exit_Adc_GetGrpStatus(void)
{
  ResumeAllInterrupts();
}

void SchM_Exit_Adc_GetStreamLastPtr(void)
{
  ResumeAllInterrupts();
}

void SchM_Exit_Adc_ScheduleStart(void)
{
  ResumeAllInterrupts();
}

void SchM_Exit_Adc_ScheduleStop(void)
{
  ResumeAllInterrupts();
}

void SchM_Exit_Adc_ScheduleNext(void)
{
  ResumeAllInterrupts();
}

void SchM_Exit_Adc_PushQueue(void)
{
  ResumeAllInterrupts();
}

void SchM_Exit_Adc_PopQueue(void)
{
  ResumeAllInterrupts();
}

/********************************ICU*******************************************/
void SchM_Enter_Icu_17_GtmCcu6_EnableWakeup(void)
{
  SuspendAllInterrupts();
}

void SchM_Exit_Icu_17_GtmCcu6_EnableWakeup(void)
{
  ResumeAllInterrupts();
}

void SchM_Enter_Icu_17_GtmCcu6_EnableNotification(void)
{
  SuspendAllInterrupts();
}

void SchM_Exit_Icu_17_GtmCcu6_EnableNotification(void)
{
  ResumeAllInterrupts();
}

void SchM_Enter_Icu_17_GtmCcu6_ResetEdgeCount(void)
{
  SuspendAllInterrupts();
}

void SchM_Exit_Icu_17_GtmCcu6_ResetEdgeCount(void)
{
  ResumeAllInterrupts();
}

void SchM_Enter_Icu_17_GtmCcu6_Ccu6IenUpdate(void)
{
  SuspendAllInterrupts();
}

void SchM_Exit_Icu_17_GtmCcu6_Ccu6IenUpdate(void)
{
  ResumeAllInterrupts();
}

void SchM_Enter_Icu_17_GtmCcu6_CcuInterruptHandle(void)
{
  SuspendAllInterrupts();
}

void SchM_Exit_Icu_17_GtmCcu6_CcuInterruptHandle(void)
{
  ResumeAllInterrupts();
}

void SchM_Enter_Icu_17_GtmCcu6_CcuVariableupdate(void)
{
  SuspendAllInterrupts();
}

void SchM_Exit_Icu_17_GtmCcu6_CcuVariableupdate(void)
{
  ResumeAllInterrupts();
}

/********************************CAN*******************************************/

void SchM_Enter_Can_17_MCanP_CanDisInt(void)
{
  SuspendAllInterrupts();
}

void SchM_Exit_Can_17_MCanP_CanDisInt(void)
{
  ResumeAllInterrupts();
}

void SchM_Enter_Can_17_MCanP_CanEnInt(void)
{
  SuspendAllInterrupts();
}

void SchM_Exit_Can_17_MCanP_CanEnInt(void)
{
  ResumeAllInterrupts();
}

void SchM_Enter_Can_17_MCanP_CanWrMO(void)
{
  SuspendAllInterrupts();
}

void SchM_Exit_Can_17_MCanP_CanWrMO(void)
{
  ResumeAllInterrupts();
}

/********************************FlexRay***************************************/

void SchM_Enter_Fr_17_Eray_ControllerInit(void)
{
  SuspendAllInterrupts();
}

void SchM_Exit_Fr_17_Eray_ControllerInit(void)
{
  ResumeAllInterrupts();
}

void SchM_Enter_Fr_17_Eray_SetWakeupChannel(void)
{
  SuspendAllInterrupts();
}

void SchM_Exit_Fr_17_Eray_SetWakeupChannel(void)
{
  ResumeAllInterrupts();
}

/********************************SPI*******************************************/

void SchM_Enter_Spi_WriteIB(void)
{
  SuspendAllInterrupts();
}
void SchM_Exit_Spi_WriteIB(void)
{
  ResumeAllInterrupts();
}

void SchM_Enter_Spi_AsyncTransmit(void)
{
  SuspendAllInterrupts();
}
void SchM_Exit_Spi_AsyncTransmit(void)
{
  ResumeAllInterrupts();
}

void SchM_Enter_Spi_GetSequenceResult(void)
{
  SuspendAllInterrupts();
}
void SchM_Exit_Spi_GetSequenceResult(void)
{
  ResumeAllInterrupts();
}
void SchM_Enter_Spi_Cancel(void)
{
  SuspendAllInterrupts();
}
void SchM_Exit_Spi_Cancel(void)
{
  ResumeAllInterrupts();
}
void SchM_Enter_Spi_Init(void)
{
  SuspendAllInterrupts();
}
void SchM_Exit_Spi_Init(void)
{
  ResumeAllInterrupts();
}
void SchM_Enter_Spi_DeInit(void)
{
  SuspendAllInterrupts();
}
void SchM_Exit_Spi_DeInit(void)
{
  ResumeAllInterrupts();
}
void SchM_Enter_Spi_SyncTransmit(void)
{
  SuspendAllInterrupts();
}
void SchM_Exit_Spi_SyncTransmit(void)
{
  ResumeAllInterrupts();
}


/********************************WatchDog**************************************/


void SchM_Enter_Wdg_17_Scu_TimerHandling(void)
{
  SuspendAllInterrupts();
}
void SchM_Enter_Wdg_17_Scu_Trigger(void)
{
  SuspendAllInterrupts();
}
void SchM_Enter_Wdg_17_Scu_ChangeMode(void)
{
  SuspendAllInterrupts();
}
void SchM_Enter_Wdg_17_Scu_SafetyInit(void)
{
  SuspendAllInterrupts();
} 
void SchM_Enter_Wdg_17_Scu_SafetyTrigger(void)
{
  SuspendAllInterrupts();
}
void SchM_Enter_Wdg_17_Scu_SafetyOffMode(void)
{
  SuspendAllInterrupts();
}

void SchM_Exit_Wdg_17_Scu_TimerHandling(void)
{
  ResumeAllInterrupts();
}
void SchM_Exit_Wdg_17_Scu_Trigger(void)
{
  ResumeAllInterrupts();
}
void SchM_Exit_Wdg_17_Scu_ChangeMode(void)
{
  ResumeAllInterrupts();
}
void SchM_Exit_Wdg_17_Scu_SafetyInit(void)
{
  ResumeAllInterrupts();
} 
void SchM_Exit_Wdg_17_Scu_SafetyTrigger(void)
{
  ResumeAllInterrupts();
}
void SchM_Exit_Wdg_17_Scu_SafetyOffMode(void)
{
  ResumeAllInterrupts();
}

/********************************FLS**************************************/


void SchM_Enter_Fls_17_Pmu_Init(void)
{
  SuspendAllInterrupts();
}

void SchM_Exit_Fls_17_Pmu_Init(void)
{
  ResumeAllInterrupts();
}

void SchM_Enter_Fls_17_Pmu_Erase(void)
{
  SuspendAllInterrupts();
}

void SchM_Exit_Fls_17_Pmu_Erase(void)
{
  ResumeAllInterrupts();
}

void SchM_Enter_Fls_17_Pmu_Write(void)
{
  SuspendAllInterrupts();
}

void SchM_Exit_Fls_17_Pmu_Write(void)
{
  ResumeAllInterrupts();
}

void SchM_Enter_Fls_17_Pmu_Main(void)
{
  SuspendAllInterrupts();
}

void SchM_Exit_Fls_17_Pmu_Main(void)
{
  ResumeAllInterrupts();
}

void SchM_Enter_Fls_17_Pmu_ResumeErase(void)
{
  SuspendAllInterrupts();
}

void SchM_Exit_Fls_17_Pmu_ResumeErase(void)
{
  ResumeAllInterrupts();
}

/*******************************FLSLOADER**************************************/


void SchM_Enter_FlsLoader_Erase(void)
{
  SuspendAllInterrupts();
}

void SchM_Enter_FlsLoader_Write(void)
{
  SuspendAllInterrupts();
}

void SchM_Enter_FlsLoader_lLock(void)
{
  SuspendAllInterrupts();
}

void SchM_Exit_FlsLoader_lLock(void)
{
  ResumeAllInterrupts();
}

void SchM_Exit_FlsLoader_Write(void)
{
  ResumeAllInterrupts();
}

void SchM_Exit_FlsLoader_Erase(void)
{
  ResumeAllInterrupts();
}

/********************************ETH*******************************************/


void SchM_Enter_Eth_17_EthMac_Transmit(void)
{
  SuspendAllInterrupts();
}

void SchM_Exit_Eth_17_EthMac_Transmit(void)
{
  ResumeAllInterrupts();
}

void SchM_Enter_Eth_17_EthMac_ProvideTxBuffer(void)
{
  SuspendAllInterrupts();
}

void SchM_Exit_Eth_17_EthMac_ProvideTxBuffer(void)
{
  ResumeAllInterrupts();
}

void SchM_Enter_Eth_17_EthMac_SetControllerMode(void)
{
  SuspendAllInterrupts();
}

void SchM_Exit_Eth_17_EthMac_SetControllerMode(void)
{
  ResumeAllInterrupts();
}

void SchM_Enter_Eth_17_EthMac_TxRxIrqHandler(void)
{
  SuspendAllInterrupts();
}

void SchM_Exit_Eth_17_EthMac_TxRxIrqHandler(void)
{
  ResumeAllInterrupts();
}


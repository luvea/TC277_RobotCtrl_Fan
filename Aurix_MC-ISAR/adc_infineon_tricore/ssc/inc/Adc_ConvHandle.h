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
**   $FILENAME   : Adc_ConvHandle.h $                                         **
**                                                                            **
**   $CC VERSION : \main\8 $                                                  **
**                                                                            **
**   $DATE       : 2015-04-16 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : This file contains                                         **
**                 - declaration of functions called from Adc.c               **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*******************************************************************************/

#ifndef ADC_CONVHANDLE_H
#define ADC_CONVHANDLE_H

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

#define ADC_START_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Syntax           : extern void Adc_lInitGlobalVariables(void)              **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called from Init to initialise the Drive global      **
**                    variables                                               **
*******************************************************************************/
extern void Adc_lInitGlobalVariables(void);

#if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
/*******************************************************************************
** Syntax           : extern void Adc_lUpdateRsGroupData                      **
**                    (                                                       **
**                       uint8 AdcKernel,                                     **
**                       const Adc_GroupCfgType* GrpPtr                       **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : AdcKernel - Group Kernel (ADC0/1/2) ,                   **
**                    GrpPtr - pointer to Group configuration                 **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called to update the Group channels and their        **
**                    resolution in the RS data variable on start of          **
**                    new conversion                                          **
*******************************************************************************/
extern void Adc_lUpdateRsGroupData
(
  uint8 AdcKernel, 
  const Adc_GroupCfgType* GrpPtr
);
#endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */

#if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)
/*******************************************************************************
** Syntax           : extern void Adc_lSchedulerOnStart                       **
**                           (uint8 AdcKernel, Adc_GroupType Group)           **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : re-entrant                                              **
**                                                                            **
** Parameters(in)   : ADC HW Unit ID, Group - Group Id                        **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Local funtion :                                         **
**                    This is a scheduler function called on start/Enable     **
**                    group                                                   **
**                    This will schedule the requested group for Start/Enable **
**                    group depending on its priority                         **
**                    ADC310: The ADC Driver priority mechanism shall allow   **
**                    aborting/suspending and restarting/resuming             **
**                    of conversions.                                         **
**                    ADC311: The ADC Driver priority mechanism shall allow   **
**                    the queuing of requests for different groups.           **
**                    Note: Higher priority groups can abort/suspend lower    **
**                    priority groups. In this case the priority handler      **
**                    should put the interrupted conversion in the queue      **
**                    and this conversion will be resumed later,              **
**                    transparently to the user.                              **
**                    ADC312: In the ADC Driver priority mechanism the        **
**                    lowest priority shall be 0.                             **
*******************************************************************************/
extern void Adc_lSchedulerOnStart(uint8 AdcKernel, Adc_GroupType Group);

/*******************************************************************************
** Syntax           : extern void Adc_lSchedulerOnStop                        **
**                           (uint8 AdcKernel, Adc_GroupType Group)           **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : re-entrant                                              **
**                                                                            **
** Parameters(in)   : Group - Group Id                                        **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Local funtion :                                         **
**                    This is a scheduler function called on                  **
**                    Stop/Disable group                                      **
**                    On stop/Disable Group this function will update the     **
**                    Queue                                                   **
**                    ADC310: The ADC Driver priority mechanism shall allow   **
**                    aborting/suspending and restarting/resuming             **
**                    of conversions.                                         **
**                    ADC311: The ADC Driver priority mechanism shall allow   **
**                    the queuing of requests for different groups.           **
**                    Note: Higher priority groups can abort/suspend lower    **
**                    priority groups. In this case the priority handler      **
**                    should put the interrupted conversion in the queue      **
**                    and this conversion will be resumed later,              **
**                    transparently to the user.                              **
**                    ADC312: In the ADC Driver priority mechanism the        **
**                    lowest priority shall be 0.                             **
*******************************************************************************/
extern void Adc_lSchedulerOnStop(uint8 AdcKernel, Adc_GroupType Group);

/*******************************************************************************
** Syntax           : extern void Adc_lScheduleNext                           **
**                       (uint8 AdcKernel, uint8 HwTriggSource)               **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : re-entrant                                              **
**                                                                            **
** Parameters(in)   : Adc Hw Unit ID                                          **
**                    HwTriggSource: Schedule for the requested trigger source**
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Local funtion :                                         **
**                    This function shall schedule the next group in queue for**
**                    conversion in the requested trigger source              **
**                    This function is called on Stop group API and on        **
**                    conversion stop ISR                                     **
**                    ADC310: The ADC Driver priority mechanism shall allow   **
**                    aborting/suspending and restarting/resuming             **
**                    of conversions.                                         **
**                    ADC312: In the ADC Driver priority mechanism the        **
**                    lowest priority shall be 0.                             **
*******************************************************************************/
extern void Adc_lScheduleNext(uint8 AdcKernel, uint8 GrpReqSource);

#endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) */

#if (ADC_ENABLE_QUEUING == STD_ON)
/*******************************************************************************
** Syntax           : extern void Adc_lPushOnQueue                            **
**                    (                                                       **
**                      uint8 AdcKernel,                                      **
**                      Adc_GroupType  Group                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Adc HW Unit ID, Group ID                                **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : New requested group is placed in Queue and Queue data   **
**                    updated. If Queue is empty, the requested Group is      **
**                    started for conversion                                  **
*******************************************************************************/
extern void Adc_lPushOnQueue(uint8 AdcKernel, Adc_GroupType Group);

/*******************************************************************************
** Syntax           : extern void Adc_lPopFromQueue                           **
**                    (                                                       **
**                      uint8 AdcKernel,                                      **
**                      Adc_GroupType  Group                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : ADC HW Unit ID, Group ID                                **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Requested group is removed from Queue and Queue data    **
**                    updated. If requested Group is currently converting,    **
**                    the Group is stopped and the next Group in Queue is     **
**                    started for conversion (if any).                        **
*******************************************************************************/
extern void Adc_lPopFromQueue(uint8 AdcKernel, Adc_GroupType Group);

/*******************************************************************************
** Syntax           : extern void Adc_lScheduleFromQueue                      **
**                    (                                                       **
**                      uint8 AdcKernel                                       **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : ADC HW Unit ID                                          **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Schedule the Group for conversion which is pointed      **
**                    by Pop index                                            **
*******************************************************************************/
extern void Adc_lScheduleFromQueue(uint8 AdcKernel);

/*******************************************************************************
** Syntax           : extern void Adc_lRemoveFromQueue                        **
**                    (                                                       **
**                      Adc_GlobalDataType *DataPtr,                          **
**                      Adc_GroupType Group                                   **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : Pointer to data variable, Group ID                      **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Remove the Group from Queue which has just completed    **
**                    the conversion / implicitly stopped. Update the         **
**                    Pop index                                               **
*******************************************************************************/
extern void Adc_lRemoveFromQueue
(
  Adc_GlobalDataType *DataPtr,
  Adc_GroupType Group
);

#endif /* (ADC_ENABLE_QUEUING == STD_ON) */

#if((ADC_ENABLE_START_STOP_GROUP_API == STD_ON)||(ADC_HW_TRIGGER_API == STD_ON))
/*******************************************************************************
** Syntax           : extern void Adc_lStopConvRequestSource                  **
**                    (                                                       **
**                       const Adc_GroupCfgType* GrpPtr                       **
**                       uint8 AdcKernel                                      **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Pointer to Group configuration                          **
**                    Adc HW Unit ID                                          **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called when Group has to be stopped                  **
*******************************************************************************/
extern void Adc_lStopConvRequestSource
(
  const Adc_GroupCfgType* GrpPtr,
  uint8 AdcKernel
);
#endif /* ADC_ENABLE_START_STOP_GROUP_API or ADC_HW_TRIGGER_API is STD_ON */

#if (ADC_GROUP_EMUX_SCAN == STD_ON)
/*******************************************************************************
** Syntax           : extern void Adc_lDmaTransResUpdate(uint8 AdcKernel)     **
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
** Description      : Is called from ADC DMA ISR to update results from       **
**                    Adc_DmaBuffer to Group Buffer                           **
*******************************************************************************/
extern void Adc_lDmaTransResUpdate(uint8 AdcKernel);

#endif /* (ADC_GROUP_EMUX_SCAN == STD_ON) */

#if ((ADC_ERU_TRIGG == STD_ON) || (ADC_ERU_GATING == STD_ON))
/*******************************************************************************
** Syntax           : extern uint32 Adc_lGetEruUnit                           **
**                    (                                                       **
**                       uint32 HwCfgData                                     **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : HwCfgData - HW Trigger and gate configured data         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : uint32                                                  **
**                                                                            **
** Description      : Get Eru Unit used for trigger                           **
**                                                                            **
*******************************************************************************/
extern uint32 Adc_lGetEruUnit
(
  uint32 HwCfgData
);

/*******************************************************************************
** Syntax           : extern uint32 Adc_lGetEruOguUnit                        **
**                    (                                                       **
**                       uint32 HwCfgData                                     **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : HwCfgData - HW Trigger and gate configured data         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : uint32                                                  **
**                                                                            **
** Description      : Get Eru OGU Unit used for trigger / Gate                **
**                                                                            **
*******************************************************************************/
extern uint32 Adc_lGetEruOguUnit
(
  uint32 HwCfgData
);

#if (ADC_RESET_SFR_INIT == STD_ON)
/*******************************************************************************
** Syntax           : extern void Adc_lResetEruSfr                            **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called from Init to reset the used ERU SFRs          **
**                                                                            **
*******************************************************************************/
extern void Adc_lResetEruSfr(void);
#endif /* (ADC_RESET_SFR_INIT == STD_ON) */

#endif /* ((ADC_ERU_TRIGG == STD_ON) || (ADC_ERU_GATING == STD_ON)) */

/*******************************************************************************
** Syntax           : extern void Adc_lIsr(uint8 Kernel, uint8 ReqSrc)        **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters (in)  : Kernel - Adc Hw unit ID                                 **
**                    ReqSrc - Request src used                               **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function                                           **
**  - Handles common functionality of ADC interrupts                          **
**                                                                            **
**                                                                            **
*******************************************************************************/
extern void Adc_lIsr(uint8 Kernel, uint8 ReqSrc);

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/*******************************************************************************
** Syntax           : extern void Adc_lIsrLimitCheck(uint8 AdcKernel)         **
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
** Description      : This function                                           **
**  - Handles the interrupts from Channel event on conversion complete        **
**  - Must be called in ISR of ADCx SRN2                                      **
*******************************************************************************/
extern void Adc_lIsrLimitCheck(uint8 AdcKernel);

#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

/*******************************************************************************
** Syntax           : extern Adc_GlobalDataType *Adc_lGetDataAddress          **
**                    (                                                       **
**                       uint8 Kernel                                         **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Kernel - Adc HW unit number                             **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Adc_GlobalDataType*                                     **
**                                                                            **
** Description      : Is called to Get Address of the kernel variable         **
**                                                                            **
*******************************************************************************/
extern Adc_GlobalDataType *Adc_lGetDataAddress
(
  uint8 Kernel
);

#if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
/*******************************************************************************
** Syntax           : extern uint32 Adc_lCheckInitParam                       **
**                                          (const Adc_ConfigType *ConfigPtr) **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters(in)   : ConfigPtr - Pointer to ADC configuration Set            **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Error code if error detected else ADC_E_DET_NO_ERR      **
**                                                                            **
** Description      : Local inline funtion :                                  **
**                    Service for ADC_E_ALREADY_INITIALIZED and               **
**                    ADC_E_PARAM_CONFIG DET / SAFE error check and reporting **
**                                                                            **
*******************************************************************************/
extern uint32 Adc_lCheckInitParam(const Adc_ConfigType *ConfigPtr);

#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */

#if (ADC_INITCHECK_API == STD_ON)
/*******************************************************************************
** Syntax           : extern Std_ReturnType Adc_lInitGlobalVarCheck(void)     **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Std_ReturnType                                          **
**                                                                            **
** Description      : Is called from InitCheck to verify the Driver global    **
**                    variables                                               **
*******************************************************************************/
extern Std_ReturnType Adc_lInitGlobalVarCheck(void);
#endif /* (ADC_INITCHECK_API == STD_ON) */

#if (ADC_GROUP_EMUX_SCAN == STD_ON)
/*******************************************************************************
** Syntax           : extern void Adc_lUpdateDmaData                          **
**                    (                                                       **
**                       uint8 AdcKernel,                                     **
**                       Adc_GroupType Group                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Group on request                                        **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Updata Dma data for the Group which uses EMUX SCAN      **
*******************************************************************************/
extern void Adc_lUpdateDmaData(uint8 AdcKernel, Adc_GroupType Group);

/*******************************************************************************
** Syntax           : extern void Adc_lDmaChInit                              **
**                    (                                                       **
**                       uint8 AdcKernel, uint32 ResultRegNum,                **
**                       Dma_ChannelType DmaChannel                           **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : On Which Result Register                                **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called when EMUX SCAN Group has requested for start  **
**                    of conversion                                           **
*******************************************************************************/
extern void Adc_lDmaChInit
(
  const uint8 AdcKernel, 
  const uint32 ResultRegNum,
  const Dma_ChannelType DmaChannel
);

#endif /* (ADC_GROUP_EMUX_SCAN == STD_ON) */

#if (ADC_HW_TRIGGER_API == STD_ON)
/*******************************************************************************
** Syntax           : extern uint32 Adc_lGetEngtVal                           **
**                    (                                                       **
**                       uint32 HwCfgData                                     **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : HwCfgData - HW Trigger and gate configured data         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : uint32                                                  **
**                                                                            **
** Description      : Get ENGT value of Request source from user              **
**                    configured hw data                                      **
**                                                                            **
*******************************************************************************/
extern uint32 Adc_lGetEngtVal
(
  uint32 HwCfgData
);

/*******************************************************************************
** Syntax           : extern uint32 Adc_lGetTriggSelData                      **
**                    (                                                       **
**                       uint32 HwCfgData,                                    **
**                       uint32 DataPos,                                      **
**                       uint32 ShiftPos                                      **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : HwCfgData - Hw trigg config data ,                      **
**                    DataPos - Position of the data to be extracted,         **
**                    ShiftPos - No of position to be shifted                 **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : uint32                                                  **
**                                                                            **
** Description      : Is called when HW trigg type Group has to be started    **
**                                                                            **
*******************************************************************************/
extern uint32 Adc_lGetTriggSelData
(
  uint32 HwCfgData,
  uint32 DataPos,
  uint32 ShiftPos
);

/*******************************************************************************
** Syntax           : extern uint32 Adc_lGetRsCtrlData                        **
**                    (                                                       **
**                       uint32 HwCfgData,                                    **
**                       uint32 DataPos,                                      **
**                       uint32 ShiftPos                                      **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : HwCfgData - Hw trigg config data ,                      **
**                    DataPos - Position of the data to be extracted,         **
**                    ShiftPos - No of position to be shifted                 **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : uint32                                                  **
**                                                                            **
** Description      : Is called when HW trigg type Group has to be started    **
**                                                                            **
*******************************************************************************/
extern uint32 Adc_lGetRsCtrlData
(
  uint32 HwCfgData,
  uint32 DataPos,
  uint32 ShiftPos
);

#if (ADC_TIMER_ERU_TRIGG == STD_ON)
/*******************************************************************************
** Syntax           : extern void Adc_lSetHwTrigger                           **
**                    (                                                       **
**                       const Adc_GroupCfgType* GrpPtr                       **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Pointer to Group configuration                          **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called when HW trigg type Group has to be started    **
*******************************************************************************/
extern void Adc_lSetHwTrigger
(
  const Adc_GroupCfgType* GrpPtr
);
#endif /* (ADC_TIMER_ERU_TRIGG == STD_ON) */

#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

/*******************************************************************************
** Syntax           : extern Adc_ChannelType Adc_lGetKernelChNum              **
**                    (                                                       **
**                       uint32 ChConfigData                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : ChConfigData - Adc channel number                       **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Adc_ChannelType                                         **
**                                                                            **
** Description      : Is called to Get ADC Kernel Channel number.             **
**                    Bit 12 to 15 gives the channel number                   **
**                                                                            **
*******************************************************************************/
extern Adc_ChannelType Adc_lGetKernelChNum
(
  uint32 ChConfigData
);

/*******************************************************************************
** Syntax           : extern uint32 Adc_lClearEventFlag                       **
**                    (                                                       **
**                       uint8 ReqSrc                                         **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : ReqSrc - Request Source number                          **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : unsigned_int                                            **
**                                                                            **
** Description      : Is called to Clear request source event flag.           **
**                    bit 1 positioning for clearing RS event flag            **
**                                                                            **
*******************************************************************************/
extern uint32 Adc_lClearEventFlag
(
  uint8 ReqSrc
);

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#define ADC_STOP_SEC_CODE
#include "MemMap.h"
  
#endif /* ADC_CONVHANDLE_H */

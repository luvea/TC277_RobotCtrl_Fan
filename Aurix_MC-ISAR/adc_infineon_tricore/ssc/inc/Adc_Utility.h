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
**   $FILENAME   : Adc_Utility.h $                                            **
**                                                                            **
**   $CC VERSION : \main\15 $                                                 **
**                                                                            **
**   $DATE       : 2016-03-23 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : This file contains                                         **
**                 - functionality of Adc driver.                             **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*******************************************************************************/

#ifndef ADC_UTILITY_H
#define ADC_UTILITY_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Import the Hw handle functions */
#include "Adc_HwHandle.h"
#if (ADC_GROUP_EMUX_SCAN == STD_ON)
/* Import DMA channel information */
#include "Mcal_DmaLib.h"
#endif /* (ADC_GROUP_EMUX_SCAN == STD_ON) */
/* Import the Conversion handle functions */
#include "Adc_ConvHandle.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* Invalid values for Global variables */
#if (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR)

#define ADC_INVALID_CHANNEL              ((Adc_ChannelType)0xFF)

#endif /* (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR) */

#define ADC_INVALID_PRIORITY             ((Adc_GroupPriorityType)0xFF)

/* Flag value to disable interrupt service */
#define ADC_NO_SERVICE                   ((uint8)0x01)

/*
  Macros to define the Position of channel configuration parameters 
*/
#define ADC_POS_CH_CFG_INT_CH       (16U)

/* Status of group in scheduler either in No priority with Queue or 
   HW SW Priority
*/
#define ADC_START_CONVERSION        ((uint32)0x01)

#if (ADC_ENABLE_QUEUING == STD_ON)
#define ADC_STOP_CONVERSION         ((uint32)0x01)
#endif /* (ADC_ENABLE_QUEUING == STD_ON) */

/* SW priority considered */
#if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)

/* Macro for Maximum Group Possible */
#define ADC_MAX_GROUP_POSSIBLE      ((uint32)32)

#endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) */

/* Group ID which is invalid */
#define ADC_INVALID_GROUP_ID        ((Adc_GroupType)0xFF)

#if (ADC_GROUP_EMUX_SCAN == STD_ON)

/* DMA Related macros */

/* Dma usage flag set */
#define ADC_DMA_IN_USE              ((uint8)1)

/* Dma usage flag reset */
#define ADC_DMA_NOT_IN_USE          ((uint8)0)

#endif /* (ADC_GROUP_EMUX_SCAN == STD_ON) */

#if (ADC_USE_EMUX == STD_ON)
#define ADC_POS_EMUX_ENABLE    (3U)
#endif /* (ADC_USE_EMUX == STD_ON) */

/*
Get ADC Kernel number from Group Id. Bit 5 , 6 , 7 and 8 will give the 
5 - start from bit number 5
4 - no. of bits to extract 
*/ 
#define ADC_KERNEL_NUM_START_BIT    (5U)
#define ADC_KERNEL_NUM_OF_BITS      (4U)

/*
Get ADC Kernel Group Id. Bit 0 to 4 will give the Kernel Group Id
*/ 
#define ADC_KERNEL_GROUP_ID_MASK    (0x1FU)

/*
Get ADC Kernel Channel number. Bit 12 to 15 will give the channel number
*/ 
#define ADC_CHANNEL_ID_MASK         (0x0FU)

#if ((ADC_HW_TRIGGER_API == STD_ON) && (ADC_TIMER_TRIGG == STD_ON))
/*
Get Group for HW trigger source type (Timer or External Request)
4U - From bit number 4 to be extracted
1U - 1 bit to be extracted
*/ 
#define ADC_TIMER_ENABLE_START_BIT   (4U)
#define ADC_TIMER_ENABLE_NUM_OF_BITS (1U)

#endif /*(ADC_HW_TRIGGER_API == STD_ON && ADC_TIMER_TRIGG == STD_ON)*/

/*
Get ENGT value of Request source from user configured hw data
5U - From bit number 5 to be extracted
2U - 2 bits to be extracted
*/ 
#define ADC_ENGT_START_BIT          (5U)
#define ADC_ENGT_NUM_OF_BITS        (2U)

#if ((ADC_HW_TRIGGER_API == STD_ON) && ((ADC_ERU_TRIGG == STD_ON) || \
                                                  (ADC_ERU_GATING == STD_ON)) )
/* Get Flag for Eru trigger/Gate type */ 
#define ADC_ERU_SELECT_NUM_OF_BITS  (1U)
/* Get Eru Unit used for trigger */ 
#define ADC_ERU_UNIT_NUM_OF_BITS    (3U)

#endif /* (ADC_HW_TRIGGER_API == STD_ON && ADC_ERU_TRIGG == STD_ON) */

#if (ADC_USE_EMUX == STD_ON)
/* Get Emux Select value from EmuxData */ 
#define ADC_EMUX_SELECT_MASK        (0x07U)

/* Get Emux enabled or not from EmuxData */ 
#define ADC_EMUX_ENABLE_NUM_OF_BITS (1U)

#endif /* (ADC_USE_EMUX == STD_ON) */

#if (ADC_DEV_ERROR_DETECT == STD_ON)
/* Status to indicate that ADC is initialized */
#define ADC_INITIALIZED  ((uint8)1)
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/
#define ADC_START_SEC_VAR_8BIT
#include "MemMap.h"

#if (ADC_REQSRC2 == ADC_REQSRC_USED)
/*IFX_MISRA_RULE_08_08_STATUS=Adc_BgndScanData is declared extern only here and
 is defined in Adc.c. This violation is reported incorrectly by PC-lint tool*/
extern uint8 Adc_BgndScanData;
/*IFX_MISRA_RULE_08_08_STATUS=Adc_BgndGrpCnt is declared extern only here and
 is defined in Adc.c. This violation is reported incorrectly by PC-lint tool*/
extern uint8 Adc_BgndGrpCnt;
#endif /* (ADC_REQSRC2 == ADC_REQSRC_USED) */

#if (ADC_DEV_ERROR_DETECT == STD_ON)
/*IFX_MISRA_RULE_08_08_STATUS=Adc_InitStatus is declared extern only here and
 is defined in Adc.c. This violation is reported incorrectly by PC-lint tool*/
extern uint8 Adc_InitStatus;
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

#define ADC_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#if (ADC_PB_FIXED_ADDRESS == STD_OFF)
#define ADC_START_SEC_VAR_32BIT
#include "MemMap.h"

/* To store the Adc driver configuration pointer */
/*IFX_MISRA_RULE_08_08_STATUS=Adc_kConfigPtr is declared extern only here and
 is defined in Adc.c. This violation is reported incorrectly by PC-lint tool*/
extern const Adc_ConfigType  *Adc_kConfigPtr;

#define ADC_STOP_SEC_VAR_32BIT
#include "MemMap.h"
#endif /*(ADC_PB_FIXED_ADDRESS == STD_OFF)*/

#if(ADC_PB_FIXED_ADDRESS == STD_ON)
#define ADC_START_SEC_CONST_32BIT
#include "MemMap.h"
  
/* To store the Adc driver configuration pointer */
extern const Adc_ConfigType * const Adc_kConfigPtr;
  
#define ADC_STOP_SEC_CONST_32BIT
#include "MemMap.h"
#endif /*(ADC_PB_FIXED_ADDRESS == STD_ON) */

#if ( (ADC_QM_KERNEL_USED_COUNT != 0U ) && (ADC_REQSRC2 == ADC_REQSRC_USED) )
#define ADC_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

/* data variable for QM signals */
/*IFX_MISRA_RULE_08_08_STATUS=Adc_QmSignal is declared extern only here and
 is defined in Adc_ConvHandle.c. This violation is reported incorrectly by 
 PC-lint tool*/
extern Adc_GlobalDataType Adc_QmSignal[ADC_QM_KERNEL_USED_COUNT];

#define ADC_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
#endif /* (ADC_QM_KERNEL_USED_COUNT != 0U )&&(ADC_REQSRC2 == ADC_REQSRC_USED) */


#define ADC_START_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/* Enable/Disable the use of the function */
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/*******************************************************************************
** Syntax           : extern void Adc_lSchmEnterStartGroup                    **
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
extern void Adc_lSchmEnterStartGroup(void);

/*******************************************************************************
** Syntax           : extern void Adc_lSchmExitStartGroup                     **
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
extern void Adc_lSchmExitStartGroup(void);

/*******************************************************************************
** Syntax           : extern void Adc_lSchmEnterStopGroup                     **
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
extern void Adc_lSchmEnterStopGroup(void);

/*******************************************************************************
** Syntax           : extern void Adc_lSchmExitStopGroup                      **
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
extern void Adc_lSchmExitStopGroup(void);

#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

/* Enable/Disable the use of the function */
#if (ADC_HW_TRIGGER_API == STD_ON)
/*******************************************************************************
** Syntax           : extern void Adc_lSchmEnterEnableHwTrig                  **
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
extern void Adc_lSchmEnterEnableHwTrig(void);

/*******************************************************************************
** Syntax           : extern void Adc_lSchmExitEnableHwTrig                   **
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
extern void Adc_lSchmExitEnableHwTrig(void);

/*******************************************************************************
** Syntax           : extern void Adc_lSchmEnterDisableHwTrig                 **
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
extern void Adc_lSchmEnterDisableHwTrig(void);

/*******************************************************************************
** Syntax           : extern void Adc_lSchmExitDisableHwTrig                  **
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
extern void Adc_lSchmExitDisableHwTrig(void);

#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
/*******************************************************************************
** Syntax           : extern void Adc_lSchmEnterGetGrpStatus                  **
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
extern void Adc_lSchmEnterGetGrpStatus(void);

/*******************************************************************************
** Syntax           : extern void Adc_lSchmExitGetGrpStatus                   **
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
extern void Adc_lSchmExitGetGrpStatus(void);

#if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
/*******************************************************************************
** Syntax           : extern void Adc_lSchmEnterGetStreamLastPtr              **
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
extern void Adc_lSchmEnterGetStreamLastPtr(void);

/*******************************************************************************
** Syntax           : extern void Adc_lSchmExitGetStreamLastPtr               **
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
extern void Adc_lSchmExitGetStreamLastPtr(void);

#if (ADC_READ_GROUP_API == STD_ON)
/*******************************************************************************
** Syntax           : extern void Adc_lSchmEnterReadGroup                     **
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
extern void Adc_lSchmEnterReadGroup(void);

/*******************************************************************************
** Syntax           : extern void Adc_lSchmExitReadGroup                      **
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
extern void Adc_lSchmExitReadGroup(void);

#endif /* (ADC_READ_GROUP_API == STD_ON) */
#endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */

/* Queue Enable is STD_ON only during No priority */
#if (ADC_ENABLE_QUEUING == STD_ON)
/*******************************************************************************
** Syntax           : extern void Adc_lSchmEnterPopQueue                      **
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
extern void Adc_lSchmEnterPopQueue(void);

/*******************************************************************************
** Syntax           : extern void Adc_lSchmExitPopQueue                       **
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
extern void Adc_lSchmExitPopQueue(void);

/*******************************************************************************
** Syntax           : extern void Adc_lSchmEnterPushQueue                     **
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
extern void Adc_lSchmEnterPushQueue(void);

/*******************************************************************************
** Syntax           : extern void Adc_lSchmExitPushQueue                      **
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
extern void Adc_lSchmExitPushQueue(void);
#endif /* (ADC_ENABLE_QUEUING == STD_ON) */

/* Full priority considered */
#if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)
/*******************************************************************************
** Syntax           : extern void Adc_lSchmEnterScheduleNext                  **
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
extern void Adc_lSchmEnterScheduleNext(void);

/*******************************************************************************
** Syntax           : extern void Adc_lSchmExitScheduleNext                   **
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
extern void Adc_lSchmExitScheduleNext(void);

/*******************************************************************************
** Syntax           : extern void Adc_lSchmEnterScheduleStart                 **
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
extern void Adc_lSchmEnterScheduleStart(void);

/*******************************************************************************
** Syntax           : extern void Adc_lSchmExitScheduleStart                  **
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
extern void Adc_lSchmExitScheduleStart(void);

/*******************************************************************************
** Syntax           : extern void Adc_lSchmEnterScheduleStop                  **
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
extern void Adc_lSchmEnterScheduleStop(void);

/*******************************************************************************
** Syntax           : extern void Adc_lSchmExitScheduleStop                   **
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
extern void Adc_lSchmExitScheduleStop(void);

#endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) */

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
  
/*******************************************************************************
** Syntax           : _IFXEXTERN_ IFX_INLINE uint16 Adc_lKernelConfigured     **
**                    (                                                       **
**                      uint8 Kernel                                          **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Kernel - Adc Kernel to be checked                       **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function is to check if the Adc kernel is configured or not          **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE uint16 Adc_lKernelConfigured(uint8 Kernel)
{
  /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
   files*/
  uint16 RetVal;

  RetVal = (uint16)( (uint16)((1UL) << (Kernel)) & ((uint16)ADC_USED_KERNELS) );

  if (RetVal != 0U)
  {
    /* UTP AI00133878 */
    if (Adc_kConfigPtr->CfgPtr[Kernel] == NULL_PTR)
    {
      RetVal = 0U;
    }
  }
  return(RetVal);
}

/*******************************************************************************
** Syntax           : _IFXEXTERN_ IFX_INLINE uint16 Adc_lQueueRSConfigured    **
**                    (                                                       **
**                      uint16 Kernel                                         **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Kernel - Adc Kernel to be checked                       **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function is to check if the Queue RS is configured or not            **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE uint16 Adc_lQueueRSConfigured(uint8 Kernel)
{
  /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
   files*/
  uint16 RetVal;

  RetVal = (uint16)( (uint16)((1UL) << (Kernel)) &                   \
                              ((uint16)ADC_KERNEL_REQSRC0_USED)     \
                   );
  return(RetVal);
}

/*******************************************************************************
** Syntax           : _IFXEXTERN_ IFX_INLINE uint16 Adc_lAutoScanConfigured   **
**                    (                                                       **
**                      uint8 Kernel                                          **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Kernel - Adc Kernel to be checked                       **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function is to check if the Auto scan RS is configured or not        **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE uint16 Adc_lAutoScanConfigured(uint8 Kernel)
{
  /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
   files*/
  uint16 RetVal;

  RetVal = (uint16)( (uint16)((1UL) << (Kernel)) &                   \
                              ((uint16)ADC_KERNEL_REQSRC1_USED)     \
                   );
  return(RetVal);
}

/*******************************************************************************
** Syntax           : _IFXEXTERN_ IFX_INLINE uint16 Adc_lBackgndScanConfigured**
**                    (                                                       **
**                      uint8 Kernel                                          **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Kernel - Adc Kernel to be checked                       **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function is to check if the Background scan RS is configured or not  **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE uint16 Adc_lBackgndScanConfigured(uint8 Kernel)
{
  /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
   files*/
  uint16 RetVal;

  RetVal = (uint16)( (uint16)((1UL) << (Kernel)) &                  \
                              ((uint16)ADC_KERNEL_REQSRC2_USED)     \
                   );
  return(RetVal);
}

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/*******************************************************************************
** Syntax           : _IFXEXTERN_ IFX_INLINE uint16 Adc_lLimitChkConfigured   **
**                    (                                                       **
**                      uint8 Kernel                                          **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Kernel - Adc Kernel to be checked                       **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function is to check if the Limit checking is configured or not      **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE uint16 Adc_lLimitChkConfigured(uint8 Kernel)
{
  /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
   files*/
  uint16 RetVal;

  RetVal = (uint16)( (uint16)((1UL) << (Kernel)) &                   \
                                 ((uint16)ADC_LIMIT_CHECK_USED)     \
                   );
  return(RetVal);
}
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

#if ( ADC_GROUP_EMUX_SCAN == STD_ON )
/*******************************************************************************
** Syntax           : _IFXEXTERN_ IFX_INLINE uint8 Adc_lGetEmuxKernel         **
**                    (                                                       **
**                       uint32 AdcEmuxKernel,                                **
**                       uint8 Pos                                            **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : AdcEmuxKernel - Adc kernels configured for Emux         **
**                    Pos - Adc Emux group number                             **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : uint16                                                  **
**                                                                            **
** Description      : Is called to Get Emux selected Emux kernels             **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE uint8 Adc_lGetEmuxKernel
(
  uint32 AdcEmuxKernel, 
  uint8 Pos
)
{
  /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
   files*/
  uint8 RetValue;
  /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
   files*/
  uint8  Position;

  Position = (uint8)((uint32)Pos * ADC_EMUX_GROUP_BITS);
  
  RetValue = (uint8)EXTRACT((AdcEmuxKernel),(Position),(ADC_EMUX_GROUP_BITS));
  
  return(RetValue);
  
} /* Adc_lGetEmuxKernel */

#endif /* ( ADC_GROUP_EMUX_SCAN == STD_ON ) */

/*******************************************************************************
** Syntax           : _IFXEXTERN_ IFX_INLINE uint32 Adc_lGetAdcKernel         **
**                    (                                                       **
**                       Adc_GroupType Group                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Group - Adc group number                                **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : uint32                                                  **
**                                                                            **
** Description      : Is called to Get ADC Kernel number from Group Id.       **
**                      Bit 5 , 6 , 7 and 8 gives the Kernel number           **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE uint32 Adc_lGetAdcKernel
(
  Adc_GroupType Group
)
{
  /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
   files*/
  uint32 RetValue;
  
  RetValue = 
     (uint32)EXTRACT((uint32)Group, ADC_KERNEL_NUM_START_BIT, 
                                                    ADC_KERNEL_NUM_OF_BITS);
  
  return(RetValue);
  
} /* Adc_lGetAdcKernel */

/*******************************************************************************
** Syntax           : _IFXEXTERN_ IFX_INLINE Adc_GroupType                    **
**                    Adc_lGetKernelGroupId(Adc_GroupType Group)              **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Group - Adc group number                                **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Adc_GroupType                                           **
**                                                                            **
** Description      : Is called to Get ADC Kernel Group Id. Bit 0 to 4        **
**                    gives the Kernel Group Id                               **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE Adc_GroupType Adc_lGetKernelGroupId
(
  Adc_GroupType Group
)
{
  /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
   files*/
  Adc_GroupType RetValue;
  
  RetValue = (Group & (Adc_GroupType)ADC_KERNEL_GROUP_ID_MASK);
  
  return(RetValue);
  
} /* Adc_lGetKernelGroupId */

#if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
/*******************************************************************************
** Syntax           : _IFXEXTERN_ IFX_INLINE void Adc_lSetGroupResultAtomic   **
**                    (                                                       **
**                       const Adc_GlobalDataType *DataPtr,                   **
**                       Adc_GroupType Group                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : DataPtr - Pointer to an data variable                   **
**                    Group - Adc group number                                **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called to Set Group Result Status to Result Available**
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE void Adc_lSetGroupResultAtomic
(
  Adc_GlobalDataType *DataPtr, 
  Adc_GroupType Group
)
{
  Mcal_SetAtomic
             ( ((sint32*)(void *)&(DataPtr->GroupResultStatus)),
               (uint32)(1U), (sint32)(Group), 1
             );
  /*IFX_MISRA_RULE_16_07_STATUS=Pointer parameter could be declared as pointing 
   to const, Ignored as MISRA doesn't understand Mcal_SetAtomic() function */
} /* Adc_lSetGroupResultAtomic */

/*******************************************************************************
** Syntax           : _IFXEXTERN_ IFX_INLINE void Adc_lClrGroupResultAtomic   **
**                    (                                                       **
**                       const Adc_GlobalDataType *DataPtr,                   **
**                       Adc_GroupType Group                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : DataPtr - Pointer to an data variable                   **
**                    Group - Adc group number                                **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called to Clear Group Result Status to               **
**                                         Result Not Available               **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE void Adc_lClrGroupResultAtomic
(
  Adc_GlobalDataType *DataPtr, 
  Adc_GroupType Group
)
{
  Mcal_SetAtomic
             ( ((sint32*)(void *)&(DataPtr->GroupResultStatus)),
               (uint32)(0U), (sint32)(Group), 1
             );
  /*IFX_MISRA_RULE_16_07_STATUS=Pointer parameter could be declared as pointing 
   to const, Ignored as MISRA doesn't understand Mcal_SetAtomic() function */
} /* Adc_lClrGroupResultAtomic */

/*******************************************************************************
** Syntax           : _IFXEXTERN_ IFX_INLINE Adc_StatusType                   **
**                    Adc_lGetGroupResult                                     **
**                    (                                                       **
**                       const Adc_GlobalDataType *DataPtr,                   **
**                       Adc_GroupType Group                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : DataPtr - Pointer to an data variable                   **
**                    Group - Adc group number                                **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Adc_StatusType                                          **
**                                                                            **
** Description      : Is called to GGet GroupResult Status                    **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE Adc_StatusType Adc_lGetGroupResult
(
  const Adc_GlobalDataType *DataPtr, 
  Adc_GroupType Group
)
{
  /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
   files*/
  Adc_StatusType RetValue;
  
  RetValue = (Adc_StatusType)EXTRACT((DataPtr->GroupResultStatus),(Group),(1U));
  
  return(RetValue);
  
} /* Adc_lGetGroupResult */
#endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */

/*******************************************************************************
** Syntax           : _IFXEXTERN_ IFX_INLINE void                             **
**                    Adc_lSetGroupStatusBusyAtomic                           **
**                    (                                                       **
**                       const Adc_GlobalDataType *DataPtr,                   **
**                       Adc_GroupType Group                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : DataPtr - Pointer to an data variable                   **
**                    Group - Adc group number                                **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called to Set Group Status to ADC_BUSY               **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE void Adc_lSetGroupStatusBusyAtomic
(
  Adc_GlobalDataType *DataPtr, 
  Adc_GroupType Group
)
{
  Mcal_SetAtomic( ((sint32*)(void*)&(DataPtr->GroupStatus)),
                  (uint32)(ADC_BUSY),(sint32)(Group), 1
                );
  /*IFX_MISRA_RULE_16_07_STATUS=Pointer parameter could be declared as pointing 
   to const, Ignored as MISRA doesn't understand Mcal_SetAtomic() function */
} /* Adc_lSetGroupStatusBusyAtomic */

/*******************************************************************************
** Syntax           : _IFXEXTERN_ IFX_INLINE void                             **
**                    Adc_lClrResBuffEndStatusAtomic                          **
**                    (                                                       **
**                       const Adc_GlobalDataType *DataPtr,                   **
**                       Adc_GroupType Group                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : DataPtr - Pointer to an data variable                   **
**                    Group - Adc group number                                **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called to Clear Group Result buffer end Status       **
**                                               to Result Not full           **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE void Adc_lClrResBuffEndStatusAtomic
(
  Adc_GlobalDataType *DataPtr, 
  Adc_GroupType Group
)
{
  Mcal_SetAtomic
      ( ((sint32*)(void *)&(DataPtr->GrpBufferEndResultStatus)),
        (uint32)(0U), (sint32)(Group), 1
      );
  /*IFX_MISRA_RULE_16_07_STATUS=Pointer parameter could be declared as pointing 
   to const, Ignored as MISRA doesn't understand Mcal_SetAtomic() function */
} /* Adc_lClrResBuffEndStatusAtomic */

/*******************************************************************************
** Syntax           : _IFXEXTERN_ IFX_INLINE void                             **
**                    Adc_lSetGroupStatusIdleAtomic                           **
**                    (                                                       **
**                       const Adc_GlobalDataType *DataPtr,                   **
**                       Adc_GroupType Group                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : DataPtr - Pointer to an data variable                   **
**                    Group - Adc group number                                **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called to Reset the Group Status to ADC_IDLE         **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE void Adc_lSetGroupStatusIdleAtomic
(
  Adc_GlobalDataType *DataPtr, 
  Adc_GroupType Group
)
{
  Mcal_SetAtomic( ((sint32*)(void *)&(DataPtr->GroupStatus)),
                  (uint32)(ADC_IDLE),(sint32)(Group), 1
                );
  /*IFX_MISRA_RULE_16_07_STATUS=Pointer parameter could be declared as pointing 
   to const, Ignored as MISRA doesn't understand Mcal_SetAtomic() function */
} /* Adc_lSetGroupStatusIdleAtomic */

/*******************************************************************************
** Syntax           : _IFXEXTERN_ IFX_INLINE Adc_StatusType                   **
**                    Adc_lGetGroupStatus                                     **
**                    (                                                       **
**                       const Adc_GlobalDataType *DataPtr,                   **
**                       Adc_GroupType Group                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : DataPtr - Pointer to an data variable                   **
**                    Group - Adc group number                                **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Adc_StatusType                                          **
**                                                                            **
** Description      : Is called to Get Group Status                           **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE Adc_StatusType Adc_lGetGroupStatus
(
  const Adc_GlobalDataType *DataPtr, 
  Adc_GroupType Group
)
{
  /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
   files*/
  Adc_StatusType RetValue;
  
  RetValue = (Adc_StatusType)EXTRACT((DataPtr->GroupStatus),(Group),1U);
  
  return(RetValue);
  
} /* Adc_lGetGroupStatus */

/*******************************************************************************
** Syntax      : _IFXEXTERN_ IFX_INLINE Adc_StatusType                        **
**               Adc_lGetResBuffEndStatus                                     **
**                    (                                                       **
**                       const Adc_GlobalDataType *DataPtr,                   **
**                       Adc_GroupType Group                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : DataPtr - Pointer to an data variable                   **
**                    Group - Adc group number                                **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Adc_StatusType                                          **
**                                                                            **
** Description      : Is called to Get Group Result buffer end Status         **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE Adc_StatusType Adc_lGetResBuffEndStatus
(
  const Adc_GlobalDataType *DataPtr, 
  Adc_GroupType Group
)
{
  /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
   files*/
  Adc_StatusType RetValue;
  
  RetValue = 
    (Adc_StatusType)EXTRACT((DataPtr->GrpBufferEndResultStatus),
                      (Group),(1U) 
                    );
  
  return(RetValue);
  
} /* Adc_lGetResBuffEndStatus */

/*******************************************************************************
** Syntax           : _IFXEXTERN_ IFX_INLINE void Adc_lResetTrigSrcData       **
**                         (                                                  **
**                           const Adc_GroupCfgType *GrpPtr,                  **
**                           const Adc_GlobalDataType *DataPtr                **
**                         )                                                  **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters(in)   : GrpPtr - Pointer to the Group configuration             **
**                    DataPtr - Pointer to the data variable                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Local funtion :                                         **
**                    Service for Reset the HW Trigger source data            **
**                    and Adc_AllRunningCh for checking of channel sharing    **
**                    in partial priority mechanism                           **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE void Adc_lResetTrigSrcData
( 
  const Adc_GroupCfgType *GrpPtr,
  Adc_GlobalDataType *DataPtr
)
{
  /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
   files*/
  uint8 GrpReqSource;

  /* Get the requested Group request source */
  GrpReqSource   = GrpPtr->GrpRequestSrc;

  /* Update the Trigger source data */
  /* GrpId is reset to indicate trigger source is free */
  /* lowest channel number is reset to invalid */
  DataPtr->TriggSrcData[GrpReqSource].GrpId = ADC_GRP_REQ_SRC_FREE;
  DataPtr->TriggSrcData[GrpReqSource].GrpPriority = ADC_INVALID_PRIORITY;
  #if (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR)
  DataPtr->TriggSrcData[GrpReqSource].GrpLastChannel = ADC_INVALID_CHANNEL;
  #endif /* (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR) */

  /* Hardware priority or Full Priority considered */
  #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Clears the currently running channel mask with the channels that are 
     part of the stomped group */
  DataPtr->AllRunningCh &= (uint16)(~(GrpPtr->IntChMask));
  #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
  #endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) */

  #if (ADC_REQSRC2 == ADC_REQSRC_USED)
  
  if( (GrpReqSource == ADC_REQSRC2_BGND_SCAN) &&  
                  (GrpPtr->TriggSrc == ADC_TRIGG_SRC_SW) )
  {
    Adc_BgndScanData = ADC_BGND_REQ_SRC_FREE;
  }
  #endif /* (ADC_REQSRC2 == ADC_REQSRC_USED) */
  
           
  return;
  
}/* Adc_lResetTrigSrcData */

#if (ADC_USE_EMUX == STD_ON)
/*******************************************************************************
** Syntax           : _IFXEXTERN_ IFX_INLINE uint32 Adc_lGetEmuxSelect        **
**                    (                                                       **
**                       uint32 EmuxData                                      **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : EmuxData - Group Emux Data                              **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : uint32                                                  **
**                                                                            **
** Description      : Get Group EMUX select value                             **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE uint32 Adc_lGetEmuxSelect
(
  uint32 EmuxData
)
{
  /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
   files*/
  uint32 RetValue;
  
  RetValue = (EmuxData & ADC_EMUX_SELECT_MASK);
  
  return(RetValue);
  
} /* Adc_lGetEmuxSelect */

/*******************************************************************************
** Syntax           : _IFXEXTERN_ IFX_INLINE uint32 Adc_lGetEmuxEnable        **
**                    (                                                       **
**                       uint32 EmuxData                                      **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : EmuxData - Group Emux Data                              **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : uint32                                                  **
**                                                                            **
** Description      : Get Emux enabled or not from EmuxData                   **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE uint32 Adc_lGetEmuxEnable
(
  uint32 EmuxData
)
{
  /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
   files*/
  uint32 RetValue;
  
  RetValue = ((EmuxData) >> (ADC_POS_EMUX_ENABLE)) & \
              (ADC_EMUX_ENABLE_NUM_OF_BITS);

  return(RetValue);
  
} /* Adc_lGetEmuxEnable */

#endif /* (ADC_USE_EMUX == STD_ON) */

#if (ADC_GROUP_EMUX_SCAN == STD_ON)
/*******************************************************************************
** Syntax           : _IFXEXTERN_ IFX_INLINE uint32 Adc_lGetEmuxScan          **
**                    (                                                       **
**                       uint32 EmuxData                                      **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : EmuxData - Group Emux Data                              **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : uint32                                                  **
**                                                                            **
** Description      : Get Emux Scan enabled or not from EmuxData              **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE uint32 Adc_lGetEmuxScan
(
  uint32 EmuxData
)
{
  /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
   files*/
  uint32 RetValue;
  
  RetValue = (EmuxData & ADC_GROUP_EMUX_SCAN_ENABLE);
  
  return(RetValue);
  
} /* Adc_lGetEmuxScan */

#endif/*(ADC_GROUP_EMUX_SCAN == STD_ON)*/

/*******************************************************************************
** Syntax           : _IFXEXTERN_ IFX_INLINE uint32 Adc_lGetGroupStatusAll    **
**                    (                                                       **
**                       const Adc_GlobalDataType *DataPtr                    **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : DataPtr - Pointer to an data variable                   **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Adc_StatusType                                          **
**                                                                            **
** Description      : Is called to Get Group Status of all the groups         **
**                    Adc_lGetGroupStatusAll() == 0 => ADC_IDLE               **
**                    Adc_lGetGroupStatusAll() != 0 => ADC_BUSY               **
**                                          (Atleast one group is busy)       **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE uint32 Adc_lGetGroupStatusAll
(
  const Adc_GlobalDataType *DataPtr 
)
{
  /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
   files*/
  uint32 RetValue;
  
  RetValue = (uint32)DataPtr->GroupStatus;
  
  return(RetValue);
  
} /* Adc_lGetGroupStatusAll */

#if (ADC_TIMER_TRIGG == STD_ON)
/*******************************************************************************
** Syntax           : _IFXEXTERN_ IFX_INLINE uint32 Adc_lGetTimEnData         **
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
** Description      : Is called to Get Group for HW trigger source type       **
**                    (Timer or External Request)                             **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE uint32 Adc_lGetTimEnData
(
  uint32 HwCfgData
)
{
  /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
   files*/
  uint32 RetValue;
  
  RetValue = (uint32)EXTRACT( (HwCfgData), (ADC_TIMER_ENABLE_START_BIT),
                              (ADC_TIMER_ENABLE_NUM_OF_BITS)
                            );
  
  return(RetValue);
  
} /* Adc_lGetTimEnData */
#endif /* ADC_TIMER_TRIGG == STD_ON */

#if ((ADC_ERU_TRIGG == STD_ON) || (ADC_ERU_GATING == STD_ON))
/*******************************************************************************
** Syntax           : _IFXEXTERN_ IFX_INLINE uint32 Adc_lGetEruData           **
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
** Description      : Get Flag for Eru trigger / Gate type                    **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
 files*/
_IFXEXTERN_ IFX_INLINE uint32 Adc_lGetEruData
(
  uint32 HwCfgData
)
{
  /*IFX_MISRA_RULE_08_05_STATUS=Allowed for inline functions defined in header
   files*/
  uint32 RetValue;
  
  RetValue = (uint32)EXTRACT( (HwCfgData), (ADC_POS_HW_CFG_ERU_SELECT),
                              (ADC_ERU_SELECT_NUM_OF_BITS)
                            );
  
  return(RetValue);
  
} /* Adc_lGetEruData */

#endif /* ((ADC_ERU_TRIGG == STD_ON) || (ADC_ERU_GATING == STD_ON)) */


#define ADC_STOP_SEC_CODE
#include "MemMap.h"
  
#endif /* ADC_UTILITY_H */

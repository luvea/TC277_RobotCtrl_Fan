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
**   $FILENAME   : Adc_ConvHandle.c $                                         **
**                                                                            **
**   $CC VERSION : \main\26 $                                                 **
**                                                                            **
**   $DATE       : 2016-05-01 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : This file contains                                         **
**                 - functions called from Adc.c                              **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**  TRACEABILITY: [cover parentID=DS_MCAL_ADC_0408,DS_MCAL_ADC_0436,
SAS_MCAL_ADC_0409,DS_NAS_ADC_PR3054]                                          **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - functions called from Adc.c                              **
**                                                                            **
**  [/cover]                                                                  **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Own header file, this includes own configuration file also */
/* Inclusion structure */
#include "Adc_Utility.h"
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
#define ADC_START_SEC_CODE
#include "MemMap.h"
  
#if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
#if ( (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || \
                                               (ADC_HW_TRIGGER_API == STD_ON) )
/* Update of Group results into user buffer */
static void Adc_lUpdateResBuffer(uint8 AdcKernel,Adc_GroupType Group);

#if( ADC_MASTER_SLAVE_SYNC == STD_ON )
/* Update of slave channel results into user buffer */
IFX_LOCAL_INLINE void Adc_lUpdateSlaveResult
(
  uint8 AdcKernel, 
  Adc_GroupType Group,
  Adc_ValueGroupType *CurrentResBufPtr 
);
#endif /* ( ADC_MASTER_SLAVE_SYNC == STD_ON ) */

#endif
/* ( (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || 
                                            (ADC_HW_TRIGGER_API == STD_ON) ) */
#endif
/* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */

#if ( (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR) && \
      (ADC_SWOSM_INTERRUPT_HANDLER == STD_ON) \
    )
static void Adc_lNonAutosarRSIntHandler(uint8 AdcKernel,Adc_GroupType Group);
#endif /* Non AUTOSAR SW OSM interrupt handler */

#if (ADC_GROUP_EMUX_SCAN == STD_ON)

/* Resetting DMA Channel registers from DMA transfer */
IFX_LOCAL_INLINE void Adc_lDmaChDeInit(const Dma_ChannelType DmaChannel);

/* Reset of ADC DMA data variable */
IFX_LOCAL_INLINE void Adc_lResetDmaData(uint8 AdcKernel);

#endif /* (ADC_GROUP_EMUX_SCAN == STD_ON) */

/* Sets the group buffer end status */
IFX_LOCAL_INLINE void Adc_lSetResBuffEndStatusAtomic
(
  const Adc_GlobalDataType *DataPtr, 
  Adc_GroupType Group
);

#if (ADC_INITCHECK_API == STD_ON)

/* Status variable check function */
IFX_LOCAL_INLINE Std_ReturnType Adc_lInitStatusVarCheck
(
  const Adc_GlobalDataType *DataPtr
);

/* TrigSrc data variable check function */
IFX_LOCAL_INLINE Std_ReturnType Adc_lInitDataVarCheck
(
  const Adc_GlobalDataType *DataPtr
);

#endif /* (ADC_INITCHECK_API == STD_ON) */

#define ADC_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#if( (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || \
                                                (ADC_HW_TRIGGER_API == STD_ON) )
/*
  Constant for getting  the variable array index for particular ADC Kernel
  These constants are derived from config tool.
  If any of the ADC are not used, its index will be 0.
  If Kernel is not used, the corresponding Index will be invalid value
  Eg: If ADC0 and ADC2 are used, then 
  ADC0_KERNEL_INDEX = 0
  ADC2_KERNEL_INDEX = 1
  and ADC_KERNEL_USED_COUNT = 2
*/

#if ( ADC_SAFETY_ENABLE == STD_ON )
#if (ADC_ASIL0_KERNEL_USED_COUNT != 0U )
#define ADC_START_SEC_ASIL0_CONST_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
/*IFX_MISRA_RULE_08_07_STATUS=The variable Adc_kAsilSignal0Index is made 
 global to optimize the code generation and to reduce the code complexity*/
static const uint8 Adc_kAsilSignal0Index[] = 
{
  ADC_ASIL0_KERNEL_INDEX
};
#define ADC_STOP_SEC_ASIL0_CONST_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
#endif /* (ADC_ASIL0_KERNEL_USED_COUNT != 0U ) */

#if (ADC_ASIL1_KERNEL_USED_COUNT != 0U )
#define ADC_START_SEC_ASIL1_CONST_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
/*IFX_MISRA_RULE_08_07_STATUS=The variable Adc_kAsilSignal1Index is made 
 global to optimize the code generation and to reduce the code complexity*/
static const uint8 Adc_kAsilSignal1Index[] = 
{
  ADC_ASIL1_KERNEL_INDEX
};
#define ADC_STOP_SEC_ASIL1_CONST_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
#endif /* (ADC_ASIL1_KERNEL_USED_COUNT != 0U ) */
#endif /* ( ADC_SAFETY_ENABLE == STD_ON ) */

#if (ADC_QM_KERNEL_USED_COUNT != 0U )
#define ADC_START_SEC_CONST_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
/*IFX_MISRA_RULE_08_07_STATUS=The variable Adc_kQmSignalIndex is made 
 global to optimize the code generation and to reduce the code complexity*/
static const uint8 Adc_kQmSignalIndex[] = 
{
  ADC_QM_KERNEL_INDEX
};
#define ADC_STOP_SEC_CONST_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
#endif /* (ADC_QM_KERNEL_USED_COUNT != 0U ) */
  
#endif 
/*(ADC_ENABLE_START_STOP_GROUP_API == STD_ON) ||(ADC_HW_TRIGGER_API == STD_ON)*/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
#if ( ADC_SAFETY_ENABLE == STD_ON )
#if (ADC_ASIL0_KERNEL_USED_COUNT != 0U )
#define ADC_START_SEC_ASIL0_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/* data variable for ASIL0 signals */
#if  ( ADC_DEBUG_SUPPORT == STD_OFF )
static Adc_GlobalDataType Adc_AsilSignal0[ADC_ASIL0_KERNEL_USED_COUNT];
#else
/*IFX_MISRA_RULE_08_10_STATUS="Adc_AsilSignal0" variable is declared extern in
  Adc_Dbg.h, which will be included by application for debugging*/
Adc_GlobalDataType Adc_AsilSignal0[ADC_ASIL0_KERNEL_USED_COUNT];
#endif  /* ( ADC_DEBUG_SUPPORT == STD_OFF ) */

#define ADC_STOP_SEC_ASIL0_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
#endif /* (ADC_ASIL0_KERNEL_USED_COUNT != 0U ) */

#if (ADC_ASIL1_KERNEL_USED_COUNT != 0U )
#define ADC_START_SEC_ASIL1_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/* data variable for ASIL1 signals */
#if  ( ADC_DEBUG_SUPPORT == STD_OFF )
static Adc_GlobalDataType Adc_AsilSignal1[ADC_ASIL1_KERNEL_USED_COUNT];
#else
/*IFX_MISRA_RULE_08_10_STATUS="Adc_AsilSignal1" variable is declared extern in
  Adc_Dbg.h, which will be included by application for debugging*/
Adc_GlobalDataType Adc_AsilSignal1[ADC_ASIL1_KERNEL_USED_COUNT];
#endif  /* ( ADC_DEBUG_SUPPORT == STD_OFF ) */

#define ADC_STOP_SEC_ASIL1_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
#endif /* (ADC_ASIL1_KERNEL_USED_COUNT != 0U ) */
#endif /* ( ADC_SAFETY_ENABLE == STD_ON ) */

#if (ADC_QM_KERNEL_USED_COUNT != 0U )
#define ADC_START_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
/* data variable for QM signals */
#if ( (ADC_REQSRC2 == ADC_REQSRC_USED) || ( ADC_DEBUG_SUPPORT == STD_ON ) )
/*IFX_MISRA_RULE_08_07_STATUS=The variable Adc_QmSignal is used in more than 
 one function with priority configuration. Hence can not be made local to a
 function*/
/*IFX_MISRA_RULE_08_10_STATUS="Adc_QmSignal" variable is declared extern in
  Adc_Dbg.h, which will be included by application for debugging*/
Adc_GlobalDataType Adc_QmSignal[ADC_QM_KERNEL_USED_COUNT];
#else
static Adc_GlobalDataType Adc_QmSignal[ADC_QM_KERNEL_USED_COUNT];
#endif
/* (ADC_REQSRC2 == ADC_REQSRC_USED) || ( ADC_DEBUG_SUPPORT == STD_ON ) */

#define ADC_STOP_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
#endif /* (ADC_QM_KERNEL_USED_COUNT != 0U ) */

#if (ADC_GROUP_EMUX_SCAN == STD_ON)
#define ADC_START_SEC_VAR_DMABUFFER
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/* dma buffer variable */
static uint16 Adc_DmaBuffer[ADC_DMA_MAX_TRANSFER];

#define ADC_STOP_SEC_VAR_DMABUFFER
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
#endif /* (ADC_GROUP_EMUX_SCAN == STD_ON) */

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define ADC_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
** Traceabilty      :[cover parentID=DS_AS_ADC078,DS_AS_ADC060,
                     DS_AS_ADC083_ADC416]
** Syntax           : void Adc_lIsr(uint8 Kernel, uint8 ReqSrc)               **
**[/cover]                                                                    **
**                                                                            **
** Service ID       : 0x28                                                    **
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
void Adc_lIsr(uint8 Kernel, uint8 ReqSrc)
{
  Adc_GlobalDataType         *DataPtr;
  uint32                     SfrValue;
  Adc_GroupType              GrpNr;
  #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
  const Adc_GroupCfgType     *GrpPtr;
  #endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
  
  /* ADC078: Reset the interrupt request bit */
  /* Reset the source interrupt flag */
  #if (ADC_SAFETY_ENABLE == STD_OFF)
  
  if(ReqSrc == ADC_REQSRC2_BGND_SCAN)
  {
    /* Background request source */
    Adc_lWriteGlobEvntFlagSfr(ADC_BACKGRND_RS_EVNT_CLEAR);
    
  }
  else
  #endif /* (ADC_SAFETY_ENABLE == STD_OFF) */
  {
    /* Auto scan and Queue request source */
    SfrValue = Adc_lClearEventFlag(ReqSrc);
    Adc_lWriteSrcEvntClrFlagSfr(Kernel, SfrValue);
  }
 
  /* Get ADC Kernel index for variables */
  /* Assign the address of ASIL or QM signal variable to global data pointer*/
  DataPtr = Adc_lGetDataAddress(Kernel);

  /* If Trigger service request is not been disabled, then service the ISR
     Else return with out any action
  */
  if (DataPtr->TriggSrcData[ReqSrc].IsrDoNothing != ADC_NO_SERVICE)
  {
    /* Get the ADC0:Group Id from the TriggSrcData */
    GrpNr = DataPtr->TriggSrcData[ReqSrc].GrpId;

    #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)

    /* Update result buffer for the group */
    /* After Read of result register, the new conversion round 
       will start if configured for continuous conversion */
    Adc_lUpdateResBuffer(Kernel,GrpNr);

    /* Update the status of group to ADC_COMPLETED */
    Adc_lSetGroupResultAtomic(DataPtr,GrpNr);

    /* Call Request source interrupt handler */
    Adc_lRSInterruptHandler(Kernel,GrpNr);

    #else /* Non AUTOSAR result handling */
    
    /* Set Group status as ADC_STREAM_COMPLETED */
    Adc_lSetResBuffEndStatusAtomic(DataPtr,GrpNr);
    
    #if (ADC_SWOSM_INTERRUPT_HANDLER == STD_ON)
    /* Call Non AUTOSAR Request source interrupt handler */
    Adc_lNonAutosarRSIntHandler(Kernel,GrpNr);
    #endif /* (ADC_SWOSM_INTERRUPT_HANDLER == STD_ON) */

    #endif /* check for result handling mode  */

    #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    /*-------------------------------------------------------**
    ** If notification is enabled call notification function ** 
    **-------------------------------------------------------*/
    if (( DataPtr->GrpNotifStatus & ((uint32)1 << GrpNr) ) > 0U)
    {
       /* Get the address of Group configuration structure */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range*/
      GrpPtr = (Adc_kConfigPtr->CfgPtr[Kernel]->GrpCfgPtr) + GrpNr;

      /* ADC060: Call to notification function */
      GrpPtr->NotifFctPtr();
    }
    #endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

  } /* Check for Stop flag */ 
}

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/*******************************************************************************
** Traceabilty      :[cover parentID=DS_AS_ADC446,DS_AS_ADC447,
                      DS_AS_ADC448,DS_AS_ADC449,,DS_AS_ADC450]
** Syntax           : void Adc_lIsrLimitCheck(uint8 AdcKernel)                **
**[/cover]                                                                    **
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
void Adc_lIsrLimitCheck(uint8 AdcKernel)
{
  Adc_GlobalDataType         *DataPtr;
  #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
  const Adc_GroupCfgType     *GrpPtr;
  #endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
  Adc_GroupType              GrpNr;
  
  /* Get ADC Kernel index for variables */
  /* Assign the address of ASIL or QM signal variable to global data pointer*/
  DataPtr = Adc_lGetDataAddress(AdcKernel);
  
  /*-----------------------------------------------**
  ** Interrupt is because of Limit check Group     **
  **-----------------------------------------------*/
  
  /* Get the ADC:Group Id from the LimitChkGroup */
  GrpNr = DataPtr->LimitChkGroup;
  
  #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
  /* Get the address of Group configuration structure */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
   PBConfigStructure and is within allowed range*/
  GrpPtr = (Adc_kConfigPtr->CfgPtr[AdcKernel]->GrpCfgPtr) + GrpNr;
  #endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

  /* Update result buffer for the group */
  /* After Read of result register, the new conversion round 
     will start if configured for continuous conversion */
  Adc_lUpdateResBuffer(AdcKernel,GrpNr);

  /* Update the status of group to ADC_COMPLETED */
  Adc_lSetGroupResultAtomic(DataPtr,GrpNr);
  
  /* Call Request source interrupt handler */
  Adc_lRSInterruptHandler(AdcKernel,GrpNr);

  #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
  /*-------------------------------------------------------**
  ** If notification is enabled call notification function ** 
  **-------------------------------------------------------*/
  if (( DataPtr->GrpNotifStatus & ((uint32)1 << GrpNr) ) > 0U)
  {
    /* ADC060: Call to notification function */
    GrpPtr->NotifFctPtr();
  }
  #endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

} /* Adc_lIsrLimitCheck */

#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

#if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
/*******************************************************************************
** Syntax           : uint32 Adc_lCheckInitParam                              **
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
uint32 Adc_lCheckInitParam(const Adc_ConfigType *ConfigPtr)
{
  uint32 RetErr;
  
  RetErr = ADC_E_DET_NO_ERR;

  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  
  if (Adc_InitStatus == ADC_INITIALIZED)
  {
    /* ADC107: Adc Driver initialization is called twice before De-init */
    Det_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE, 
                     ADC_SID_INIT, ADC_E_ALREADY_INITIALIZED
                   );    
    RetErr = (uint32)ADC_E_ALREADY_INITIALIZED;
  }
  else
  #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
  #if (ADC_PB_FIXED_ADDRESS == STD_ON)
  if (ConfigPtr != Adc_kConfigPtr)
  #else
  if (ConfigPtr == NULL_PTR)
  #endif      
  {
    /* ADC343: ConfigPtr is NULL_PTR, report DET error for variant PB */
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    Det_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE,
                     ADC_SID_INIT, ADC_E_PARAM_CONFIG
                   );
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
    
    #if (ADC_SAFETY_ENABLE == STD_ON)
    /* Report an safety error */
    SafeMcal_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE,
                          ADC_SID_INIT, ADC_E_PARAM_CONFIG
                        );
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

    RetErr = (uint32)ADC_E_PARAM_CONFIG;
  }
  else
  {
    /* Do Nothing */
  }
  #if (ADC_SAFETY_ENABLE == STD_ON)
  if ((RetErr == ADC_E_DET_NO_ERR) &&
      (ConfigPtr->CfgMarker != ((uint32)ADC_MODULE_ID << 16U)))
  {
    /* report to upper layer */
    SafeMcal_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE,
                          ADC_SID_INIT, ADC_E_PARAM_CONFIG
                        );
    
    RetErr = (uint32)ADC_E_PARAM_CONFIG;
  }
  #endif /* (ADC_SAFETY_ENABLE == STD_ON) */

  return RetErr;

} /* Adc_lCheckInitParam */

#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */



/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#if ( (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR) && \
      (ADC_SWOSM_INTERRUPT_HANDLER == STD_ON) \
    )
/*******************************************************************************
** Syntax           : static void Adc_lNonAutosarRSIntHandler                 **
**                           (uint8 AdcKernel, Adc_GroupType Group)           **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : ADC HW Unit ID, ADC Group ID                            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Interrupt handler for any Request source                **
*******************************************************************************/
static void Adc_lNonAutosarRSIntHandler(uint8 AdcKernel,Adc_GroupType Group)
{
  Adc_GlobalDataType      *DataPtr;
  const Adc_GroupCfgType  *GrpPtr;
  Adc_ChannelType         LastChannel;
  uint8                   GrpRequestSrc;

  /* Get the address of Group configuration structure */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
   PBConfigStructure and is within allowed range*/
  GrpPtr = (Adc_kConfigPtr->CfgPtr[AdcKernel]->GrpCfgPtr) + Group;

  /* Get ADC Kernel index for variables */
  /* Assign the address of ASIL or QM signal variable to global data pointer*/
  DataPtr = Adc_lGetDataAddress(AdcKernel);

  /* Get the Group request source */
  GrpRequestSrc = GrpPtr->GrpRequestSrc;


  /* Any request source can be configured in SW trigger type and 
     HW trigger type
  */
  /* Note: Groups of HW trigger type are always configured for Oneshot but not 
     disabled untill user request. Hence these Groups acts like 
     continuous conversion mode on continuous trigger signal.
  */ 
  if ((GrpPtr->TriggSrc == ADC_TRIGG_SRC_SW) && 
      (GrpPtr->ConvMode == ADC_CONV_MODE_ONESHOT)
     )
  {

    /* On implicit stop of the Group, Disable the Result interrupt */
    /* Get the channel of the Group enabled for interrupt */
    LastChannel = DataPtr->TriggSrcData[GrpRequestSrc].GrpLastChannel;

    /* The corresponding result registers is disabled for result interrupt */
    Adc_lDisableResultInt(AdcKernel,LastChannel);

    /* ADC001: Group is configured in one shot mode, 
       conversion is done only once */
    Adc_lSetGroupStatusIdleAtomic(DataPtr,Group);

    /* Reset the HW Trigger source data on conversion stop and
       Adc_AllRunningCh */
    Adc_lResetTrigSrcData(GrpPtr,DataPtr);

    /* Note:
       Reset of Group RS Group data (RsGroupData) is not required
       as its been initialised with start of group conversion before reading
    */

    #if (ADC_USE_EMUX == STD_ON)
    if (DataPtr->EmuxGroup == Group)
    {
      /* Reset ADC EMUXCTR register */
      Adc_lWriteEmuxCtrSfr(AdcKernel, 0U);

      /* Reset Emux variable */
      DataPtr->EmuxGroup = ADC_INVALID_GROUP_ID;
    }
    #endif /* (ADC_USE_EMUX == STD_ON) */

  }/* Oneshot conversion mode */

}/* Adc_lNonAutosarRSIntHandler */
#endif /* Non AUTOSAR SW OSM interrupt handler */

#if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
#if ( (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || \
                                                (ADC_HW_TRIGGER_API == STD_ON) )
/*******************************************************************************
** Traceabilty      :[cover parentID=DS_AS_ADC140,DS_AS_ADC335]
** Syntax           : static void Adc_lUpdateResBuffer                        **
**                           (uint8 AdcKernel, Adc_GroupType Group)           **
**[/cover]                                                                    **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : re-entrant                                              **
**                                                                            **
** Parameters(in)   : AdcKernel - Group HW Unit ID                            **
**                    Group - Group Id                                        **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Local funtion :                                         **
**                    Update the Group Result buffer on conversion complete   **
*******************************************************************************/
static void Adc_lUpdateResBuffer(uint8 AdcKernel, Adc_GroupType Group)
{
  Adc_GlobalDataType        *DataPtr;
  const Adc_GroupCfgType    *GrpPtr;
  uint32                    NoOfChannels;
  uint32                    LoopCnt;
  uint32                    ResVal;
  uint32                    GroupRs;
  Adc_ValueGroupType        *CurrentResBufPtr;
  Adc_ValueGroupType        *GrpBufferBasePtr;
  Adc_ChannelType           ChannelNum;
  Adc_StreamNumSampleType   NoOfSamples;
  Adc_StreamNumSampleType   CurrentBufferLocation;
  #if( ADC_MASTER_SLAVE_SYNC == STD_ON )
  uint8                     SynchChCnt;
  #endif /* ( ADC_MASTER_SLAVE_SYNC == STD_ON ) */
  
  /* Get ADC Kernel index for variables */
  /* Assign the address of ASIL or QM signal variable to global data pointer*/
  DataPtr = Adc_lGetDataAddress(AdcKernel);
  
  /* Get the number of valid conversion result to find the write
     location to buffer
  */
  CurrentBufferLocation = DataPtr->NumValidConRes[Group];
  /* Get the Group result buffer base address */
  GrpBufferBasePtr = DataPtr->GroupResultBuffer[Group];

  /* Get the Group Config data pointer */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
   PBConfigStructure and is within allowed range*/
  GrpPtr = (Adc_kConfigPtr->CfgPtr[AdcKernel]->GrpCfgPtr) + Group;

  /* Get the Group RS */
  GroupRs = (uint32)(GrpPtr->GrpRequestSrc);

  /* Streaming number of samples will decide the ResBufPtr increment value */
  NoOfSamples = (GrpPtr->NumSamples);

  /*--------------------------**
  ** Get location to write to **
  **--------------------------*/
  if (CurrentBufferLocation == NoOfSamples)
  {
    /* When the buffer index has reached no. of configured samples, 
       set the initial index to base address 
    */
    CurrentBufferLocation = (Adc_StreamNumSampleType)0;
  }

  /* Get the result buffer pointer for updating the result */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
   result buffer and is within allowed range*/
  CurrentResBufPtr = GrpBufferBasePtr + CurrentBufferLocation;

  /* Update Converted Value in to SW Buffer */
  
  /* Note: First element of the Group defination array will give the 
     no. of configured channels and the remaining elements will give 
     the channel ID 
  */
  
  /* Get the Group's number of configured channels */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
   Group Configuration Structure and is within allowed range*/
  NoOfChannels = (uint32)(GrpPtr->GroupDefinition)[0];

  /* Initialise the Index to first Group channel which is 
     read from RS Group Data
  */
  LoopCnt = (uint32)0;

  /*------------------------------------------------**
  ** loop till the NoOfChannels decremented to zero **
  **------------------------------------------------*/
  do
  {
    /* Get the Internal channel number from RS Group data variable */
    ChannelNum = DataPtr->RsGroupData[GroupRs].GrpChannels[LoopCnt];

    /* Get the conversion Result of the channel from RESy Reg */
    ResVal = Adc_lReadResult(AdcKernel, ChannelNum);

    Adc_lAlignResultBuffer(AdcKernel, Group, CurrentResBufPtr, ResVal);

    /* Point to the next channel result element of the group */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
     result buffer and is within allowed range*/
    CurrentResBufPtr = (CurrentResBufPtr + NoOfSamples);
    
    /* Decrement the NoOfChannels by 1 */
    NoOfChannels--;

    LoopCnt++;

  } while (NoOfChannels > 0U);

  #if( ADC_MASTER_SLAVE_SYNC == STD_ON )
  
  SynchChCnt = DataPtr->RsGroupData[GroupRs].NoOfSynchCh;

  if(SynchChCnt != 0U)
  {
    Adc_lUpdateSlaveResult(AdcKernel, Group, CurrentResBufPtr);
  }
  
  #endif /* ( ADC_MASTER_SLAVE_SYNC == STD_ON ) */
  
  /* Increment the no. of valid conversion result */
  CurrentBufferLocation++;

  /*Note: No critical section as ISR priority is higher than  
    Adc_GetStreamLastPointer/Adc_ReadGroup API priority 
  */
  
  /*---------------------------------------------------------------------**
  ** update the Number of conversion result and Result buffer end status **
  **---------------------------------------------------------------------*/
  DataPtr->NumValidConRes[Group] = CurrentBufferLocation;

  /* check if the current updated buffer location has reached maximum */
  if (CurrentBufferLocation == NoOfSamples)
  {
    /* Then set the status of End buffer which will indicate all the buffer 
       values are valid
    */
    Adc_lSetResBuffEndStatusAtomic(DataPtr,Group);
  }

  return;
} /* Adc_lUpdateResBuffer */

#if( ADC_MASTER_SLAVE_SYNC == STD_ON )
/*******************************************************************************
** Traceabilty      :[cover parentID=DS_NAS_ADC_PR1783]                       **
** Syntax           : IFX_LOCAL_INLINE void Adc_lUpdateSlaveResult            **
**                              (AdcKernel, Group, CurrentResBufPtr )         **
**[/cover]                                                                    **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : re-entrant                                              **
**                                                                            **
** Parameters(in)   : AdcKernel - Group HW Unit ID                            **
**                    Group - Group Id                                        **
**                    CurrentResBufPtr - Result Buffer                        **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Local funtion :                                         **
**                    Update the Group Result buffer with the slave channels  **
**                    on conversion complete                                  **
*******************************************************************************/
IFX_LOCAL_INLINE void Adc_lUpdateSlaveResult
(
  uint8 AdcKernel, 
  Adc_GroupType Group,
  Adc_ValueGroupType *CurrentResBufPtr 
)
{
  Adc_GlobalDataType          *DataPtr;
  const Adc_KernelConfigType  *KernelPtr;
  const Adc_HwUnitCfgType     *HwCfgPtr;
  const Adc_GroupCfgType      *GrpPtr;
  uint32                      NoOfChannels;
  uint32                      ResVal;
  uint32                      GroupRs;
  Adc_ChannelType             ChannelNum;
  uint8                       LoopCnt;
  uint8                       KernelCtr;
  uint8                       MaxKerCluster;

  /* Get ADC Kernel index for variables */
  /* Assign the address of ASIL or QM signal variable to global data pointer*/
  DataPtr = Adc_lGetDataAddress(AdcKernel);

  /* Identifying the starting & ending Kernel numbers of the cluster */
  KernelCtr = (AdcKernel / ADC_KERNELS_PER_SYNGRP) * ADC_KERNELS_PER_SYNGRP;
  MaxKerCluster = KernelCtr + ADC_KERNELS_PER_SYNGRP;
  
  /* if condtion is written because TC29x has 11 kernels */
  if(MaxKerCluster >= ADC_MAX_KERNELS)
  {
    MaxKerCluster = ADC_MAX_KERNELS;
  }

  /* Get the Group Config data pointer */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
   PBConfigStructure and is within allowed range*/
  GrpPtr = (Adc_kConfigPtr->CfgPtr[AdcKernel]->GrpCfgPtr) + Group;

  /* Get the Group RS */
  GroupRs = (uint32)(GrpPtr->GrpRequestSrc);
  
  do
  {
    KernelPtr = Adc_kConfigPtr->CfgPtr[KernelCtr];
    
    if(KernelPtr != NULL_PTR)
    {
      HwCfgPtr = KernelPtr->HwCfgPtr;
      
      if(HwCfgPtr->SyncConvMode != ADC_MASTER)
      {
        /* Get the Group's number of configured channels */
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
          Group Configuration Structure and is within allowed range*/
        NoOfChannels = (uint32)(GrpPtr->GroupDefinition)[0];
        
        LoopCnt = 0U;
        do
        {
          ChannelNum = DataPtr->RsGroupData[GroupRs].GrpSynchCh[LoopCnt];
        
          if ( ChannelNum != ADC_NO_SYNC_CHANNEL )
          {
            /* Get the conversion Result of the channel from RESy Reg */
            ResVal = Adc_lReadResult(KernelCtr, ChannelNum);

            Adc_lAlignResultBuffer(AdcKernel, Group, CurrentResBufPtr, ResVal);

            /* Point to the next channel result element of the group */
            /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
              result buffer and is within allowed range*/
            CurrentResBufPtr++;
          }
          
          /* Decrement the NoOfChannels by 1 */
          NoOfChannels--;
        
          LoopCnt++;
        } while (NoOfChannels > 0U);
      }
    }
    KernelCtr++;
    
  }while(KernelCtr < MaxKerCluster);

} /* Adc_lUpdateSlaveResult */
#endif /* ( ADC_MASTER_SLAVE_SYNC == STD_ON ) */

#endif /* ADC_ENABLE_START_STOP_GROUP_API or ADC_HW_TRIGGER_API is STD_ON */
#endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */

/* Full priority considered */
#if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)
/*******************************************************************************
** Syntax           : void Adc_lSchedulerOnStart                              **
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
void Adc_lSchedulerOnStart(uint8 AdcKernel, Adc_GroupType Group)
{
  Adc_GlobalDataType         *DataPtr;
  const Adc_GroupCfgType     *GrpPtr;
  const Adc_GroupCfgType     *StopGrpPtr;
  uint32                     GroupReqStatus;
  Adc_GroupType              StopGroup;
  uint8                      GrpReqSource;
  #if (ADC_REQSRC2 == ADC_REQSRC_USED)
  uint8                      LoopCnt;
  #endif /* (ADC_REQSRC2 == ADC_REQSRC_USED) */

  GroupReqStatus = (uint32)0;

  /* Get ADC Kernel index for variables */
  /* Assign the address of ASIL or QM signal variable to global data pointer*/
  DataPtr = Adc_lGetDataAddress(AdcKernel);

  #if (ADC_DEV_ERROR_DETECT == STD_OFF)
  /* Enter Critical Section */
  Adc_lSchmEnterScheduleStart(); 
  /*Note: With DET = STD_ON entering to critical section is already at API.
    When a group is preparing for start, Another higher priority group may also
    be called for start and will enter the ADC Hardware unit. Hence suspend all 
    interrupts till the first enter to start is completed
  */
  #endif /* (ADC_DEV_ERROR_DETECT == STD_OFF) */

  /* Group status of given group is made ADC_BUSY */
  Adc_lSetGroupStatusBusyAtomic(DataPtr,Group);
  /* Clear ADC Group Result Status */
  Adc_lClrGroupResultAtomic(DataPtr,Group);

  /* Initialize the number of conversion result set available to 0 */
  DataPtr->NumValidConRes[Group] = (Adc_StreamNumSampleType)0;

  /*Note: The Result Status is cleared at every start even if it is also 
    cleared at every Stop. This is because we assume that the user may call 
    Adc_StartGroup twice without explicitly calling Adc_StopGroup 
    essentially in the case of One Shot Mode
  */
  /* Reset the End result status to 0 */
  Adc_lClrResBuffEndStatusAtomic(DataPtr,Group);

  /* Get the Group Config data pointer */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
   PBConfigStructure and is within allowed range*/
  GrpPtr = (Adc_kConfigPtr->CfgPtr[AdcKernel]->GrpCfgPtr) + Group;

  /* Get the Group request source */
  GrpReqSource = GrpPtr->GrpRequestSrc;

  /* Check if the requested Group trigger source is free */
  if (DataPtr->TriggSrcData[GrpReqSource].GrpId == 
        ADC_GRP_REQ_SRC_FREE
     )
  {
    /* Group is allowed to start the conversion */ 
    GroupReqStatus = ADC_START_CONVERSION;    
  }
  else /* Already trigger source is occupied by some other group */
  {
    /* Note:
       DataPtr->TriggSrcData[GrpRequestSource].GrpPriority for HW
       trigger group is ADC_INVALID_PRIORITY (i.e. 0xFF) which is greater than 
       any of the SW groups priority levels. 
       Here HW trigger group is of higher priority compared to 
       SW trigger groups under same RS
    */
    if ((GrpPtr->PriorityLevel) > 
         DataPtr->TriggSrcData[GrpReqSource].GrpPriority 
       )
    {
      /* Abort/Suspend the on going conversion */
      /* On Abort/Suspend the Group status and 
         result buffer status will not be changed. */

      /* Get the group config data pointer for the group to be 
         aborted/Suspended
      */
      StopGroup = DataPtr->TriggSrcData[GrpReqSource].GrpId;

      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
       PBConfigStructure and is within allowed range*/
      StopGrpPtr = (Adc_kConfigPtr->CfgPtr[AdcKernel]->GrpCfgPtr) + StopGroup;
  
      /* Note: It is required to clear the Group Stop Flag as stopping the 
         conversion will not clear the SRR for the SRN
      */
      /*
        Set a trigger source service req flag for the suspended Group. 
        If set, ISR now on will not be serviced.
        By this disabling the service request for the node is not required.
        Note: There is a chance that the Group has already stopped in ISR and 
        new Group of same trigger source might have started. 
        While going ahead in stop may reset the trigger souce data.
        To avoid this cause, service the Stop depending upon the Group status
      */
      DataPtr->TriggSrcData[GrpReqSource].IsrDoNothing = ADC_NO_SERVICE;

      /* ongoing conversion is suspended/Aborted */
      Adc_lStopConvRequestSource(StopGrpPtr,AdcKernel);

      /* Note:
         Reset of Group RS Group data (RsGroupData) is not required
         as its been initialised with start of group conversion before reading
      */

      #if (ADC_USE_EMUX == STD_ON)
      if (DataPtr->EmuxGroup == StopGroup)
      {
        /* Reset ADC EMUXCTR register */
        Adc_lWriteEmuxCtrSfr(AdcKernel, 0U);

        /* Reset Emux variable */
        DataPtr->EmuxGroup = ADC_INVALID_GROUP_ID;
      }
      #endif /* (ADC_USE_EMUX == STD_ON) */

      /* Reset HW Trigger source data and Adc_AllRunningCh */
      Adc_lResetTrigSrcData(StopGrpPtr,DataPtr);
             
      /* Return the status of the group to start the conversion */
      GroupReqStatus = ADC_START_CONVERSION;
    }

  }

  if (GroupReqStatus == ADC_START_CONVERSION)
  {
    /* GrpId is updated with the requested Group */
    DataPtr->TriggSrcData[GrpReqSource].GrpId = Group;
    
    /* Update the Trigger src data with group priority level */
    DataPtr->TriggSrcData[GrpReqSource].GrpPriority = GrpPtr->PriorityLevel;

    #if (ADC_REQSRC2 == ADC_REQSRC_USED)
    /* Background request source is triggered */
    if(GrpReqSource == ADC_REQSRC2_BGND_SCAN)
    {
      Adc_BgndScanData = ADC_TRIGG_SRC_SW;
      /*IsrDoNothing is set to 1. One-Shot Single access group UTP AI00132372*/
      LoopCnt = 0U;
      #if (ADC_QM_KERNEL_USED_COUNT > 1U)
      do
      #endif
      {
        Adc_QmSignal[LoopCnt].TriggSrcData[GrpReqSource].IsrDoNothing = 
                                                                ADC_NO_SERVICE;

        #if (ADC_QM_KERNEL_USED_COUNT > 1U)
        LoopCnt++;
        #endif
      
      }
      #if (ADC_QM_KERNEL_USED_COUNT > 1U)
      while (LoopCnt < ADC_QM_KERNEL_USED_COUNT);
      #endif
    }
    #endif /* (ADC_REQSRC2 == ADC_REQSRC_USED) */

    /* Prepare Group channels by configuring in CHCTR register and 
       update TriggSrcData
    */
    Adc_lPrepareGrpForStart(AdcKernel,Group);

    /* Update the RS Group data */
    Adc_lUpdateRsGroupData(AdcKernel,GrpPtr);

    /*
      Clear the No ISR service flag for the trigger source. 
      Which might have set if Stop API is called.
    */
    DataPtr->TriggSrcData[GrpReqSource].IsrDoNothing = (uint8)0;
    /* Note: In case of short conversion time, ISR no service flag has to be 
       cleared before the first conversion complete interrupt
    */

    /* Trigger the Conversion Request Source */
    Adc_lStartSwConversionRS(GrpPtr,AdcKernel);               
  }

  Adc_lSchmExitScheduleStart(); 
  /* Exit Critical Section */

  /*Note: With DET = STD_ON or DET = STD_OFF.*/

  return;
}/* Adc_lSchedulerOnStart */

/*******************************************************************************
** Syntax           : void Adc_lSchedulerOnStop                               **
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
void Adc_lSchedulerOnStop(uint8 AdcKernel, Adc_GroupType Group)
{
  Adc_GlobalDataType         *DataPtr;
  const Adc_GroupCfgType     *GrpPtr;
  uint8                      GrpReqSource;

  /* Get ADC Kernel index for variables */
  /* Assign the address of ASIL or QM signal variable to global data pointer*/
  DataPtr = Adc_lGetDataAddress(AdcKernel);

  /*Note:
    Set a no ISR service flag for the trigger source. 
    By this disabing the service request for the node is not required.
    Note: There is a chance that the Group has already stopped in ISR and 
    new Group of same trigger source might have started. While going ahead in 
    stop may reset the trigger source data. To avoid this cause, service the 
    Stop depending upon the Group status
  */
  /* Note: 
     There is a chance that, an ISR of this Group - Oneshot, 
     continuous - Linear 
     will change the status of the Group to IDLE and 
     sets the trigger source data free and allow to start 
     an another Group with same trigger source as which 
     has called for stop. 
     1. After new start the control in Stop/Disable API may clear the 
        service request if its been set
     2. Also for the new start we will be going to reset the trigger source 
        data in this function
     3. A continuous conversion of a group (SW) can restart the Group in ISR
        after the stop-while loop which will cause the interrupt again after
        stop
  */

  /* Enter Critical section */
  Adc_lSchmEnterScheduleStop(); 

  /* During the Group status check, interrupt should not be serviced */
  /*Note: To avoid the same group or Group with same trigger source
    to be started when its status is set to Idle but not yet stopped in 
    the ADC HW */

  /*With DET STD_ON/STD_OFF:
    Check if Group status status is IDLE, if not IDLE, allow to stop
    If Idle, return back by just resetting the result. 
    If Idle but not stopped, there will not be DET reoported and will allow
    to service the API 
  */
  if (Adc_lGetGroupStatus(DataPtr,Group) != ADC_IDLE)
  {
    /* Note: Group Status needs to be cleared first before stopping the 
       conversion since in the if condition the Schedule next is called 
       which uses the Group status to schedule next group for conversion
    */
    /* Group status of given group is made ADC_IDLE */
    Adc_lSetGroupStatusIdleAtomic(DataPtr,Group);

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
     PBConfigStructure and is within allowed range*/
    GrpPtr = (Adc_kConfigPtr->CfgPtr[AdcKernel]->GrpCfgPtr) + Group;

    /* Get the Group configured trigger source */
    GrpReqSource = GrpPtr->GrpRequestSrc;

    /* The group is currently on conversion */
    if (DataPtr->TriggSrcData[GrpReqSource].GrpId == Group)
    {
      /* Get the group config data pointer for the requested group */
      DataPtr->TriggSrcData[GrpReqSource].IsrDoNothing = ADC_NO_SERVICE;
    
      /* Trigger the Conversion Request Source */
      Adc_lStopConvRequestSource(GrpPtr, AdcKernel);

      /* Note:
         Reset of Group RS Group data (RsGroupData) is not required
         as its been initialised with start of group conversion before reading
      */

      #if (ADC_USE_EMUX == STD_ON)
      if (DataPtr->EmuxGroup == Group)
      {
        /* Reset ADC EMUXCTR register */
        Adc_lWriteEmuxCtrSfr(AdcKernel, 0U);

        /* Reset Emux variable */
        DataPtr->EmuxGroup = ADC_INVALID_GROUP_ID;
      }
      #endif /* (ADC_USE_EMUX == STD_ON) */

      /* Reset HW Trigger source data and Adc_AllRunningCh */
      Adc_lResetTrigSrcData(GrpPtr,DataPtr);
      
      /* Schedule the next conversion in the stopped trigger source */
      Adc_lScheduleNext(AdcKernel,GrpReqSource);
    } /* Going to stop the current Group */
  }/* Group not Idle */

  /* Note: Incase Group has implicitly stopped, Group status will be 
     ADC_STREAM_COMPLETED but removed from Queue by scheduler function.
     Hence on stop request, Group result status and result buffers must be 
     reset to Idle. Notification must be disabled for the Group. 
  */

  /* Schedule next will definately schedule the other group than which has 
     requested for Stop */

  /* Set the Group status to ADC_IDLE, but the converted result data
     are avilable for the user */

  /* Clear ADC Group Result Status */
  Adc_lClrGroupResultAtomic(DataPtr,Group);

  /* Reset the End result status to 0 */
  Adc_lClrResBuffEndStatusAtomic(DataPtr,Group);

  #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
  /* ADC155, ADC157: Disable the group notification for the requested group */
  Mcal_SetAtomic(
  (sint32 *)(void *)&DataPtr->GrpNotifStatus, 
  (uint32)0, 
  (sint32)Group,
  1);
  #endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */       

  Adc_lSchmExitScheduleStop(); 
  /* Exit Critical Section */
 
  return;
}/* Adc_lSchedulerOnStop */

/*******************************************************************************
** Syntax           : void Adc_lScheduleNext                                  **
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
void Adc_lScheduleNext(uint8 AdcKernel, uint8 GrpReqSource)
{
  Adc_GlobalDataType         *DataPtr;
  const Adc_GroupCfgType     *GrpPtr;
  const Adc_KernelConfigType *ConfigPtr;
  uint32                     LocalAdcGroupStatus;
  uint32                     GrpTriggerMask;
  sint32                     CurrentGroupPriority;
  Adc_GroupType              GrpId;
  Adc_GroupType              CurrentGroupId;
  Adc_GroupPriorityType      GroupPriority;

  /* Get ADC Kernel index for variables */
  /* Assign the address of ASIL or QM signal variable to global data pointer*/
  DataPtr = Adc_lGetDataAddress(AdcKernel);

  ConfigPtr = Adc_kConfigPtr->CfgPtr[AdcKernel];

  /* Initialize the current group priority and Group Id to invalid */
  CurrentGroupPriority = (sint32)(-1);
  CurrentGroupId = ADC_GRP_REQ_SRC_FREE;
  
  /* Initialize with No groups are for conversion in the 
     requested trigger source */
  DataPtr->TriggSrcData[GrpReqSource].GrpId = ADC_GRP_REQ_SRC_FREE;
  DataPtr->TriggSrcData[GrpReqSource].GrpPriority = ADC_INVALID_PRIORITY;
  DataPtr->TriggSrcData[GrpReqSource].IsrDoNothing = ADC_NO_SERVICE;
 
  /* Get the Group mask for a reuested trigger source */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
   PBConfigStructure and is within allowed range*/
  GrpTriggerMask = 
    (ConfigPtr->TriggSrcGroupMask[GrpReqSource]);
  
  /* Extract the Group status of the requested trigger source */
  LocalAdcGroupStatus = (Adc_lGetGroupStatusAll(DataPtr) & GrpTriggerMask);

  /* On conversion complete and stopping of a group in ISR will check for 
     the next group in queue to be started
  */

  /* Using __clz intrinsic function, get the next Group in SW Queue from 
     Maximum Group number */
  /* Eg:
     GrpId = 0, if Adc_GroupStatus = 0;
     GrpId = 1, if Adc_GroupStatus = 1;
     GrpId = 3, if Adc_GroupStatus = 5;
  */
  GrpId = (Adc_GroupType)(ADC_MAX_GROUP_POSSIBLE -
            (uint32)Mcal_CountLeadingZeros(LocalAdcGroupStatus));

  /* Check if any Groups are in Queue */
  /* If GrpId is 0, then no Groups are in SW Queue */
  while (GrpId > (Adc_GroupType)0)
  {
    
    /* Group ID is the bit number starting from bit0 */ 
    GrpId--;
    
    /* Get the Group Config data pointer */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
     PBConfigStructure and is within allowed range*/
    GrpPtr = (ConfigPtr->GrpCfgPtr) + GrpId;
    GroupPriority = GrpPtr->PriorityLevel;
    if ((sint32)GroupPriority > CurrentGroupPriority)
    { 
      CurrentGroupId = GrpId;
      CurrentGroupPriority = (sint32)GroupPriority;     
    }
    LocalAdcGroupStatus &= (~((uint32)ADC_BUSY << GrpId));
    GrpId = (Adc_GroupType)(ADC_MAX_GROUP_POSSIBLE -
              (uint32)Mcal_CountLeadingZeros(LocalAdcGroupStatus));
  }/* Loop when any Groups are in Queue */

  /* Enter critical section */
  Adc_lSchmEnterScheduleNext(); 
  
  /*Note: During a start of the group no other request for start or stop are 
    allowed */
  if ((CurrentGroupId != ADC_GRP_REQ_SRC_FREE) && 
      (DataPtr->TriggSrcData[GrpReqSource].GrpId == ADC_GRP_REQ_SRC_FREE)
     )
  {

    /* Update the TriggSrcData for next group in the priority queue */

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
     PBConfigStructure and is within allowed range*/
    GrpPtr = ConfigPtr->GrpCfgPtr + CurrentGroupId;

    /* GrpId is updated with the next Group for conversion */
    DataPtr->TriggSrcData[GrpReqSource].GrpId = CurrentGroupId;

    /* GrpPriority is updated with the next Group priority level */
    DataPtr->TriggSrcData[GrpReqSource].GrpPriority = 
                                   (Adc_GroupPriorityType)CurrentGroupPriority;

    /* Prepare Group channels by configuring in CHCON register and 
       update TriggSrcData for lowest channel number
    */
    Adc_lPrepareGrpForStart(AdcKernel,CurrentGroupId);
  
    /* Update the RS Group data */
    Adc_lUpdateRsGroupData(AdcKernel,GrpPtr);
    
    /*
      Clear the No ISR service flag for the trigger source. 
      Which might have set if Stop API is called.
    */
    DataPtr->TriggSrcData[GrpReqSource].IsrDoNothing = (uint8)0;
    /* Note: In case of short conversion time, ISR no service flag has to be 
       cleared before the first conversion complete interrupt
    */

    /* Start the next group in the priority queue */
    Adc_lStartSwConversionRS(GrpPtr,AdcKernel);

  }
  Adc_lSchmExitScheduleNext(); 
  /* Exit critical section */
  
  return;
}/* Adc_lScheduleNext */

#endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) */

#if((ADC_ENABLE_START_STOP_GROUP_API == STD_ON)||(ADC_HW_TRIGGER_API == STD_ON))
/*******************************************************************************
** Syntax           : void Adc_lStopConvRequestSource                         **
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
void Adc_lStopConvRequestSource
(
  const Adc_GroupCfgType* GrpPtr,
  uint8 AdcKernel
)
{
  #if (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR)
  Adc_GlobalDataType *DataPtr;
  #endif /* (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR) */
  #if (ADC_ERU_GATING == STD_ON)
  uint32 HwGateData;
  #endif /* (ADC_ERU_GATING == STD_ON) */
  #if (ADC_TIMER_ERU_TRIGG == STD_ON)
  uint32 HwCfgData;
  #if (ADC_TIMER_TRIGG == STD_ON)
  uint32 TimEnableFlag;
  #endif /* (ADC_TIMER_TRIGG == STD_ON) */
  #if (ADC_ERU_TRIGG == STD_ON)
  uint32 EruTrigFlag;
  #endif /* (ADC_ERU_TRIGG == STD_ON) */
  #if (ADC_ERU_GATING == STD_ON)
  uint32 EruGateFlag;
  #endif  /*ADC_ERU_GATING == STD_ON*/
  #endif /* (ADC_HW_TRIGGER_API == STD_ON) */
  #if (ADC_GROUP_EMUX_SCAN == STD_ON)
  const Adc_HwUnitCfgType   *HwCfgPtr;
  Dma_ChannelType           AdcDmaChannel;
  #endif /* (ADC_GROUP_EMUX_SCAN == STD_ON) */
  #if (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR)
  Adc_ChannelType LastChannel;
  #endif /* (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR) */
  uint8  GrpReqSrc;
  
  GrpReqSrc = GrpPtr->GrpRequestSrc;
  
  #if (ADC_TIMER_ERU_TRIGG == STD_ON)
  if (GrpPtr->TriggSrc == ADC_TRIGG_SRC_HW)
  {
    /* Get the user config data for HW trigger */
    HwCfgData = GrpPtr->HwTrigConfig;
    #if (ADC_ERU_TRIGG == STD_ON)
    /* Get the Group ERU trigger flag */
    EruTrigFlag = (uint32)Adc_lGetEruData(HwCfgData);
    #endif /* (ADC_ERU_TRIGG == STD_ON) */

    #if (ADC_ERU_GATING == STD_ON)
    /* Get the user config data for HW Gate */
    HwGateData = (uint32)GrpPtr->HwGateConfig;
    /* Get the Group ERU gate flag */
    EruGateFlag = (uint32)Adc_lGetEruData(HwGateData);
    #endif /* (ADC_ERU_GATING == STD_ON) */

    #if (ADC_TIMER_TRIGG == STD_ON)
    /* Get the Timer Enable bit */
    TimEnableFlag = (uint32)Adc_lGetTimEnData(HwCfgData);
    /* Timer trigger type selected */
    if ( (TimEnableFlag == (uint32)ADC_GROUP_TIMER_ENABLE) &&
                                   (GrpReqSrc != ADC_REQSRC2_BGND_SCAN)
       )
    {
      Adc_lStopGtmTimer(GrpPtr);
    }
    else 
    #endif  /* (ADC_TIMER_TRIGG == STD_ON) */ 
    #if (ADC_ERU_TRIGG == STD_ON)
    /* Eru trigger type selected */
    if ( (EruTrigFlag == (uint32)ADC_TRIG_ERU_SELECTED) &&
                                   (GrpReqSrc != ADC_REQSRC2_BGND_SCAN)
       )
    {
      /* Resetting ERU IOUT Signal */
      Adc_lResetEruCfg(HwCfgData, ADC_RUNTIME_ACCESS);
    }
    else
    #endif  /*(ADC_ERU_TRIGG == STD_ON)*/
    {
      /* Do Nothing */
    }
    #if (ADC_ERU_GATING== STD_ON)
    if (EruGateFlag == (uint32)ADC_GATE_ERU_SELECTED)
    {
      /* Resetting ERU PDOUT Signal */
      Adc_lResetEruGateCfg(HwGateData, ADC_RUNTIME_ACCESS);
    }
    #endif /* (ADC_ERU_GATING== STD_ON) */
    
  }
  #endif /* (ADC_TIMER_ERU_TRIGG == STD_ON) */
  
  #if (ADC_GROUP_EMUX_SCAN == STD_ON)
  if ((uint32)Adc_lGetEmuxScan((uint32)GrpPtr->GroupEmuxData) == 
       (uint32)ADC_GROUP_EMUX_SCAN_ENABLE
     )
  {
    HwCfgPtr = Adc_kConfigPtr->CfgPtr[AdcKernel]->HwCfgPtr;
    /* Get the configured Dma channel for the ADC Kernel; the corresponding 
       service request line will trigger the DMA channel
    */
    AdcDmaChannel = (Dma_ChannelType)(HwCfgPtr->DmaChannel);
    /* De Initialise the DMA Channel */
    Adc_lDmaChDeInit(AdcDmaChannel);
    /* Reset DMA data */
    Adc_lResetDmaData(AdcKernel);
  }
  #endif /* (ADC_GROUP_EMUX_SCAN == STD_ON) */

  #if (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR)
  /* Get ADC Kernel index for variables */
  /* Assign the address of ASIL or QM signal variable to global data pointer*/
  DataPtr = Adc_lGetDataAddress(AdcKernel);
  /* Get the Group last channel stored in trigger src data */
  LastChannel = DataPtr->TriggSrcData[GrpReqSrc].GrpLastChannel;

  /* The corresponding result registers is disabled for result interrupt */
  Adc_lDisableResultInt(AdcKernel,LastChannel);
  #endif /* (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR) */
  
  /* Clear the Request source SFRs */
  Adc_lClearReqSrcSfr(GrpPtr, GrpReqSrc, AdcKernel);

}/* Adc_lStopConvRequestSource */
#endif /* ADC_ENABLE_START_STOP_GROUP_API or ADC_HW_TRIGGER_API is STD_ON */

#if (ADC_HW_TRIGGER_API == STD_ON)

#if (ADC_TIMER_ERU_TRIGG == STD_ON)
/*******************************************************************************
** Syntax           : void Adc_lSetHwTrigger                                  **
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
void Adc_lSetHwTrigger
(
  const Adc_GroupCfgType* GrpPtr
)
{

  uint32 HwCfgData;
  #if (ADC_TIMER_TRIGG == STD_ON)
  uint32 TimEnableFlag;
  #endif /*ADC_TIMER_TRIGG == STD_ON*/
  #if (ADC_ERU_TRIGG == STD_ON)
  uint32 EruTrigFlag;
  #endif  /*ADC_ERU_TRIGG == STD_ON*/
  #if (ADC_ERU_GATING == STD_ON)
  uint32 EruGateFlag;
  #endif  /*ADC_ERU_GATING == STD_ON*/
  #if (ADC_ERU_GATING == STD_ON)
  uint32 HwGateData;
  #endif /* (ADC_ERU_GATING == STD_ON) */
  uint8  GrpReqSrc;

  GrpReqSrc = GrpPtr->GrpRequestSrc;
  
  /* Get the user config data for HW trigger */
  HwCfgData = (uint32)GrpPtr->HwTrigConfig;

  #if (ADC_ERU_GATING == STD_ON)
  /* Get the user config data for HW Gate */
  HwGateData = (uint32)GrpPtr->HwGateConfig;
  #endif /* (ADC_ERU_GATING == STD_ON) */

  #if (ADC_TIMER_TRIGG == STD_ON)
  /* Get the Timer Enable bit */
  TimEnableFlag = (uint32)Adc_lGetTimEnData(HwCfgData);
  #endif /*ADC_TIMER_TRIGG == STD_ON*/

  #if (ADC_ERU_TRIGG == STD_ON)
  /* Get the Group ERU trigger flag */
  EruTrigFlag = (uint32)Adc_lGetEruData(HwCfgData);
  #endif  /*ADC_ERU_TRIGG == STD_ON*/

  #if (ADC_ERU_GATING == STD_ON)
  /* Get the Group ERU gate flag */
  EruGateFlag = (uint32)Adc_lGetEruData(HwGateData);
  #endif  /*ADC_ERU_TRIGG == STD_ON*/
    
  /* After enabling the Request source, start the external timer
     If Timer enabled, configure GTM timer 
  */
  #if (ADC_TIMER_TRIGG == STD_ON)
  /* Only when timer trigger selected */
  if ( (TimEnableFlag == (uint32)ADC_GROUP_TIMER_ENABLE) && 
                                  (GrpReqSrc != ADC_REQSRC2_BGND_SCAN)
     )
  {
    Adc_lGtmTimerCfg(GrpPtr);
  }
  else /*ADC_TIMER_TRIGG == STD_ON*/
  #endif    
  #if (ADC_ERU_TRIGG == STD_ON)
  if ( (EruTrigFlag == (uint32)ADC_TRIG_ERU_SELECTED) &&
                                  (GrpReqSrc != ADC_REQSRC2_BGND_SCAN)
     )
  {
    /* Trigger is by ERU IOUT Signal */
    Adc_lEruTrigCfg(HwCfgData);
  }
  else
  #endif /*(ADC_ERU_TRIGG == STD_ON)*/  
  {
    /* Do Nothing */
  }
  #if (ADC_ERU_GATING == STD_ON)
  if (EruGateFlag == (uint32)ADC_GATE_ERU_SELECTED)
  {
    /* Gate is by ERU PDOUT Signal */
    Adc_lEruGateCfg(HwGateData);
  }
  #endif  /*ADC_ERU_TRIGG == STD_ON*/

} /* Adc_lSetHwTrigger */
#endif /* (ADC_TIMER_ERU_TRIGG == STD_ON ) */

#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

/* Queue Enable is STD_ON only during No priority */
#if (ADC_ENABLE_QUEUING == STD_ON)
/*******************************************************************************
** Syntax           : void Adc_lPushOnQueue                                   **
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
void Adc_lPushOnQueue
(
  uint8 AdcKernel,
  Adc_GroupType Group
)
{
  Adc_GlobalDataType *DataPtr;
  Adc_GroupType  PushGrpId;

  /* Get ADC Kernel index for variables */
  /* Assign the address of ASIL or QM signal variable to global data pointer*/
  DataPtr = Adc_lGetDataAddress(AdcKernel);

  #if (ADC_DEV_ERROR_DETECT == STD_OFF)
  /* Enter Critical Section */
  Adc_lSchmEnterPushQueue(); 
  /*Note: With DET = ON entering to critical section is already at API.
    When a group is preparing for start, Another group request may also
    be called for start and will enter the ADC Hardware unit. Hence suspend all 
    interrupts till the first enter to start is completed
  */
  #endif /* (ADC_DEV_ERROR_DETECT == OFF) */

  /* Group status of given group is made ADC_BUSY */
  Adc_lSetGroupStatusBusyAtomic(DataPtr,Group);
  /* Clear ADC Group Result Status */
  Adc_lClrGroupResultAtomic(DataPtr,Group);

  /* Initialize the number of conversion result set available to 0 */
  DataPtr->NumValidConRes[Group] = (Adc_StreamNumSampleType)0;
  /*Note: The Result Status is cleared at every start even if it is also 
    cleared at every Stop. This is because we assume that the user may call 
    Adc_StartGroup twice without explicitly calling Adc_StopGroup 
    essentially in the case of One Shot Mode
  */
  /* Reset the End result status to 0 */
  Adc_lClrResBuffEndStatusAtomic(DataPtr,Group);

  /* check if Queue is empty */
  if (DataPtr->PushGroupId == ADC_INVALID_GROUP_ID)
  {
    /* Initialise the Pop Index and Push Index to the Requested Group */
    DataPtr->PushGroupId = Group;
    DataPtr->PopGroupId = Group;

    /* Request for starting the conversion pointed by PopGroupId */
    Adc_lScheduleFromQueue(AdcKernel);
  }
  else
  {
    PushGrpId = DataPtr->PushGroupId;

    /* latest Group in Queue will point the NextGroup as requested Group */
    DataPtr->QueueOfSwGroup[PushGrpId].NextGroup = Group;
    
    /* Requested Group in Queue will point the PreviousGroup as 
       latest group which is given by Push index
    */
    DataPtr->QueueOfSwGroup[Group].PreviousGroup = PushGrpId;

    /* The latest Group in Queue now is updated to requested group in push 
       index 
    */
    DataPtr->PushGroupId = Group;
  }/* Queue was not empty */

  Adc_lSchmExitPushQueue(); 
  /* Exit Critical Section */

  return;
}/* Adc_lPushOnQueue */

/*******************************************************************************
** Syntax           : void Adc_lPopFromQueue                                  **
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
void Adc_lPopFromQueue
(
  uint8 AdcKernel,
  Adc_GroupType Group
)
{
  Adc_GlobalDataType      *DataPtr;
  const Adc_GroupCfgType  *GrpPtr;
  uint32                  GroupReqStatus;
  uint32                  NextStartStatus;
  uint8                   GrpReqSource;
  Adc_GroupType           TempGroupId;
  Adc_GroupType           PopGrpId;

  /* Initialise group request flag to 0 */
  GroupReqStatus = (uint32)0;

  /* Initialise next start status to 0 */
  NextStartStatus = (uint32)0;

  /* Get ADC Kernel index for variables */
  /* Assign the address of ASIL or QM signal variable to global data pointer*/
  DataPtr = Adc_lGetDataAddress(AdcKernel);

  /* Enter Critical Section */
  Adc_lSchmEnterPopQueue(); 
  /* During the Group status check, interrupt should not be serviced */
  /*Note: To avoid the same group or any other Group 
    to be started when its status is set to Idle but not yet stopped in 
    the ADC HW 
  */
  
  /* If the requested Group is pointed by pop index i.e. the Group which 
     is the first element in the Queue and enabled in hardware 
  */
  if (DataPtr->PopGroupId == Group)
  {
    /* Group needs to be stopped */
    GroupReqStatus = ADC_STOP_CONVERSION;

    /* Pop index will be the next Group in Queue */
    DataPtr->PopGroupId = DataPtr->QueueOfSwGroup[Group].NextGroup;

    /* If Pop index has valid Group Id, request for start conversion */
    if (DataPtr->PopGroupId != ADC_INVALID_GROUP_ID)
    {
      /* Reset, next Group to invalid */
      DataPtr->QueueOfSwGroup[Group].NextGroup = ADC_INVALID_GROUP_ID;
    
      PopGrpId = DataPtr->PopGroupId;

      DataPtr->QueueOfSwGroup[PopGrpId].PreviousGroup = ADC_INVALID_GROUP_ID;
      
      NextStartStatus = ADC_START_CONVERSION;
    }
    else /* If Pop Group ID is invalid, then there is no Group in the Queue,
            Reset Push Group Id to invalid */
    {
      DataPtr->PushGroupId = ADC_INVALID_GROUP_ID;
    }
  }
  /* Check if Group has implicitly stopped and been removed from Queue */
  /* If not, only then remove the Group from Queue and rearrange the next 
     and Previous pointers
  */  
  else
  {
    /* Link through Previous and Next are rearranged in Queue */
    TempGroupId = DataPtr->QueueOfSwGroup[Group].PreviousGroup;

    if (TempGroupId != ADC_INVALID_GROUP_ID)
    {
      DataPtr->QueueOfSwGroup[TempGroupId].NextGroup = \
                         DataPtr->QueueOfSwGroup[Group].NextGroup;
    }
    TempGroupId = DataPtr->QueueOfSwGroup[Group].NextGroup;

    if (TempGroupId != ADC_INVALID_GROUP_ID)
    {
      DataPtr->QueueOfSwGroup[TempGroupId].PreviousGroup = \
                     DataPtr->QueueOfSwGroup[Group].PreviousGroup;
    }
    /* Group is delinked from Queue */
    DataPtr->QueueOfSwGroup[Group].PreviousGroup = ADC_INVALID_GROUP_ID;

    DataPtr->QueueOfSwGroup[Group].NextGroup = ADC_INVALID_GROUP_ID;
  }

  if (GroupReqStatus == ADC_STOP_CONVERSION)
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
     PBConfigStructure and is within allowed range*/
    GrpPtr = (Adc_kConfigPtr->CfgPtr[AdcKernel]->GrpCfgPtr) + Group;

    /* Get the Group configured trigger source */
    GrpReqSource = GrpPtr->GrpRequestSrc;

    /* Get the group config data pointer for the requested group */
    DataPtr->TriggSrcData[GrpReqSource].IsrDoNothing = ADC_NO_SERVICE;
    
    /* Trigger the Conversion Request Source */
    Adc_lStopConvRequestSource(GrpPtr,AdcKernel);

    /* Note:
       Reset of Group RS Group data (RsGroupData) is not required
       as its been initialised with start of group conversion before reading
    */

    #if (ADC_USE_EMUX == STD_ON)
    if (DataPtr->EmuxGroup == Group)
    {
      /* Reset ADC EMUXCTR register */
      Adc_lWriteEmuxCtrSfr(AdcKernel, 0U);

      /* Reset Emux variable */
      DataPtr->EmuxGroup = ADC_INVALID_GROUP_ID;
    }
    #endif /* (ADC_USE_EMUX == STD_ON) */

    /* Reset HW Trigger source data and Adc_AllRunningCh */
    Adc_lResetTrigSrcData(GrpPtr,DataPtr);
    
    /* Scheduler function needs to be called only when Group is not Idle.
       If Group has implicitly become Idle, it would have scheduled 
       the next group for conversion. 
    */
    if (NextStartStatus == ADC_START_CONVERSION)
    {
      /* Schedule the next Group conversion pointed by Pop index */
      Adc_lScheduleFromQueue(AdcKernel);
    }
  }

  /* Group status of stop reuest group is made ADC_IDLE */
  Adc_lSetGroupStatusIdleAtomic(DataPtr,Group);

  /* Note: Incase Group has implicitly stopped, Group status will be 
     ADC_STREAM_COMPLETED but removed from Queue by scheduler function.
     Hence on stop request, Group result status and result buffers must be 
     reset to Idle. Notification must be disabled for the Group. 
  */
  /* Set the Group status to ADC_IDLE, but the converted result data
     are avilable for the user */

  /* Clear ADC Group Result Status */
  Adc_lClrGroupResultAtomic(DataPtr,Group);

  /* Reset the End result status to 0 */
  Adc_lClrResBuffEndStatusAtomic(DataPtr,Group);

  #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
  /* ADC155, ADC157: Disable the group notification for the requested group
  */
  Mcal_SetAtomic(
  (sint32 *)(void *)&(DataPtr->GrpNotifStatus), 
  (uint32)0, 
  (sint32)Group,
  1);
  #endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */       

  Adc_lSchmExitPopQueue(); 
  /* Exit Critical Section */

  return;
}/* Adc_lPopFromQueue */

/*******************************************************************************
** Syntax           : void Adc_lScheduleFromQueue                             **
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
void Adc_lScheduleFromQueue(uint8 AdcKernel)
{
  Adc_GlobalDataType      *DataPtr;
  const Adc_GroupCfgType  *GrpPtr;
  uint8                   GrpReqSource;
  #if (ADC_REQSRC2 == ADC_REQSRC_USED)
  uint8                   LoopCnt;
  #endif /* (ADC_REQSRC2 == ADC_REQSRC_USED) */

  /* Get ADC Kernel index for variables */
  /* Assign the address of ASIL or QM signal variable to global data pointer*/
  DataPtr = Adc_lGetDataAddress(AdcKernel);

  /* Pop index of Queue will give the next Group ID to be started */
  /* Get the Group Config data pointer */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
   PBConfigStructure and is within allowed range*/
  GrpPtr = 
   (Adc_kConfigPtr->CfgPtr[AdcKernel]->GrpCfgPtr) + DataPtr->PopGroupId;
  
  /* Get the Group trigger source */
  GrpReqSource = GrpPtr->GrpRequestSrc;

  /* GrpId is updated with the requested Group */
  DataPtr->TriggSrcData[GrpReqSource].GrpId = DataPtr->PopGroupId;

  #if (ADC_REQSRC2 == ADC_REQSRC_USED)
  /* Background request source is triggered */
  if(GrpReqSource == ADC_REQSRC2_BGND_SCAN)
  {
    Adc_BgndScanData = ADC_TRIGG_SRC_SW;
    /*IsrDoNothing is set to 1. One-Shot Single access group UTP AI00132372*/
    LoopCnt = 0U;
    #if (ADC_QM_KERNEL_USED_COUNT > 1U)
    do
    #endif
    {
      Adc_QmSignal[LoopCnt].TriggSrcData[GrpReqSource].IsrDoNothing = 
                                                                ADC_NO_SERVICE;
    
      #if (ADC_QM_KERNEL_USED_COUNT > 1U)
      LoopCnt++;
      #endif
    
    }
    #if (ADC_QM_KERNEL_USED_COUNT > 1U)
    while (LoopCnt < ADC_QM_KERNEL_USED_COUNT);
    #endif
  }
  #endif /* (ADC_REQSRC2 == ADC_REQSRC_USED) */
  
  /* Prepare Group channels by configuring in CHCTR register and 
     update TriggSrcData
  */
  Adc_lPrepareGrpForStart(AdcKernel,DataPtr->PopGroupId);

  /* Update the RS Group data */
  Adc_lUpdateRsGroupData(AdcKernel,GrpPtr);

  /*
    Clear the No ISR service flag for the trigger source. 
    Which might have set if Stop API is called.
  */
  DataPtr->TriggSrcData[GrpReqSource].IsrDoNothing = (uint8)0;
  /* Note: In case of short conversion time, ISR no service flag has to be 
     cleared before the first conversion complete interrupt
  */

  /* Trigger the Conversion Request Source */
  Adc_lStartSwConversionRS(GrpPtr,AdcKernel);               

  return;

}/* Adc_lScheduleFromQueue */

/*******************************************************************************
** Syntax           : void Adc_lRemoveFromQueue                               **
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
void Adc_lRemoveFromQueue
(
  Adc_GlobalDataType *DataPtr,
  Adc_GroupType Group
)
{
  /* Pop Index is updated to next Group */
  DataPtr->PopGroupId = DataPtr->QueueOfSwGroup[Group].NextGroup;

  /* Release the Group from Queue by resetting the Group next pointer in 
    Queue to invalid Group Id
    The Group Privious pointer is already released as the Group was first
    element in Queue (since just completed conversion).
  */
  DataPtr->QueueOfSwGroup[Group].NextGroup = ADC_INVALID_GROUP_ID;

  return;

}/* Adc_lRemoveFromQueue */

#endif /* (ADC_ENABLE_QUEUING == STD_ON) */

#if (ADC_INITCHECK_API == STD_ON)

/*******************************************************************************
** Syntax           :  Std_ReturnType Adc_lInitGlobalVarCheck(void)           **
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
Std_ReturnType Adc_lInitGlobalVarCheck(void)
{
  Adc_GlobalDataType          *DataPtr;
  #if ( ((ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) && \
                 (ADC_DEV_ERROR_DETECT == STD_ON)) || (ADC_USE_EMUX == STD_ON) )
  uint32                      ReadValue;
  #endif
  volatile uint32             CompareValue;
  Std_ReturnType              RetVal;
  uint8                       KernelCtr;

  CompareValue = ADC_INITCHK_COMP_VALUE;
  RetVal = E_OK;
  /* Atleast one ADC Kernel will be in use */
  /* KernelCtr gives the variable array index */
  KernelCtr = (uint8)0;
  /* Loop for all used ADC HW Unit */
  do
  {
    if( Adc_lKernelConfigured(KernelCtr) )
    {
      /* Get ADC Kernel index for variables */
      /* Assign the address of ASIL or QM signal variable to 
         global data pointer */
      DataPtr = Adc_lGetDataAddress(KernelCtr);

      if( Adc_lInitDataVarCheck(DataPtr) != E_OK )
      {
        RetVal = E_NOT_OK;
      }

      if( Adc_lInitStatusVarCheck(DataPtr) != E_OK )
      {
        RetVal = E_NOT_OK;
      }

      /* For Partial priority considered */
      #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
      #if (ADC_DEV_ERROR_DETECT == STD_ON)
      /* Checking the variable AllRunningCh */
      ReadValue = (uint32)DataPtr->AllRunningCh;
      CompareValue &= (ReadValue ^ (~(uint32)(0)));

      #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
      #endif /* (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) */

      #if (ADC_USE_EMUX == STD_ON)
      /* Checking the variable EmuxGroup */
      ReadValue = (uint32)DataPtr->EmuxGroup;
      CompareValue &= (ReadValue ^ (~(uint32)(ADC_INVALID_GROUP_ID)));
      #endif /* (ADC_USE_EMUX == STD_ON) */
    }
    
    KernelCtr++;
    
  }while (KernelCtr < ADC_MAX_KERNELS);

  if ( (CompareValue != ADC_INITCHK_COMP_VALUE) || (RetVal != E_OK) )
  {
    RetVal = E_NOT_OK;
  }

  return(RetVal);

}/* Adc_lInitGlobalVarCheck */

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE Std_ReturnType Adc_lInitStatusVarCheck **
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
** Return value     : Std_ReturnType                                          **
**                                                                            **
** Description      : Is called from Adc_InitCheck to check the initialization**
                      is done properly for the Status variables               **
*******************************************************************************/
IFX_LOCAL_INLINE Std_ReturnType Adc_lInitStatusVarCheck
(
  const Adc_GlobalDataType *DataPtr
)
{
  #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
  uint32                      LoopCtr;
  #endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */
  uint32                      ReadValue;
  volatile uint32             CompareValue;
  Std_ReturnType              RetVal;

  CompareValue = ADC_INITCHK_COMP_VALUE;
  RetVal = E_OK;
  
  /* Checking the variable GrpBufferEndResultStatus */
  ReadValue = (uint32)DataPtr->GrpBufferEndResultStatus;
  CompareValue &= (ReadValue ^ (~(uint32)(0)));
  
  /* ADC_COMPLETED status is not supported in Non AUTOSAR result handling */
  #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
  /* Checking the variable GroupResultStatus */
  ReadValue = (uint32)DataPtr->GroupResultStatus;
  CompareValue &= (ReadValue ^ (~(uint32)(0)));
  
  LoopCtr = (uint32)0;
  #if (ADC_MAX_GROUPS > 1U)
  do
  #endif /*loop only when (ADC_MAX_SW_TRIGG_GROUP > 1U) */
  {
    /* LoopCtr will give the Group ID */
    /* Checking the variable GroupResultBuffer */
    if( DataPtr->GroupResultBuffer[LoopCtr] != NULL_PTR )
    {
      RetVal = E_NOT_OK;
    }
  
    #if (ADC_MAX_GROUPS > 1U)
    LoopCtr++;
    #endif 
  }
  #if (ADC_MAX_GROUPS > 1U)
  while (LoopCtr < ADC_MAX_GROUPS);
  #endif /*loop only when (ADC_MAX_SW_TRIGG_GROUP > 1U) */
  
  
  #endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */
  
  /* Checking the variable GroupStatus */
  ReadValue = (uint32)DataPtr->GroupStatus;
  CompareValue &= (ReadValue ^ (~(uint32)(0)));

  #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
  /* Checking the variable GrpNotifStatus */
  ReadValue = (uint32)DataPtr->GrpNotifStatus;
  CompareValue &= (ReadValue ^ (~(uint32)(0)));

  #endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

  #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
  if (RetVal == E_OK)
  #endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */
  { 
    if (CompareValue != ADC_INITCHK_COMP_VALUE)
    {
      RetVal = E_NOT_OK;
    }
  }

  return(RetVal);
} /* Adc_lInitStatusVarCheck */
/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE Std_ReturnType Adc_lInitDataVarCheck   **
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
** Return value     : Std_ReturnType                                          **
**                                                                            **
** Description      : Is called from Adc_InitCheck to check the initialization**
                      is done properly for the TrigSrc data variables         **
*******************************************************************************/
IFX_LOCAL_INLINE Std_ReturnType Adc_lInitDataVarCheck
(
  const Adc_GlobalDataType *DataPtr
)
{
  uint32                      LoopCtr;
  uint32                      ReadValue;
  volatile uint32             CompareValue;
  Std_ReturnType              RetVal;

  CompareValue = ADC_INITCHK_COMP_VALUE;
  RetVal = E_NOT_OK;
  LoopCtr = (uint32)0;
  do
  {
    /* Checking the variable TriggSrcData[LoopCtr].GrpId */
    ReadValue = (uint32)DataPtr->TriggSrcData[LoopCtr].GrpId;
    CompareValue &= (ReadValue ^ (~(uint32)(ADC_GRP_REQ_SRC_FREE)));
    
    /* Checking the variable TriggSrcData[LoopCtr].GrpPriority */
    ReadValue = (uint32)DataPtr->TriggSrcData[LoopCtr].GrpPriority;
    CompareValue &= (ReadValue ^ (~(uint32)(ADC_INVALID_PRIORITY)));
    
    /* Checking the variable TriggSrcData[LoopCtr].IsrDoNothing */
    ReadValue = (uint32)DataPtr->TriggSrcData[LoopCtr].IsrDoNothing;
    CompareValue &= (ReadValue ^ (~(uint32)(ADC_NO_SERVICE)));
    
    LoopCtr++;
  } while (LoopCtr < ADC_REQSRC_COUNT );

  /* Queue Enable is STD_ON only during No priority */
  #if (ADC_ENABLE_QUEUING == STD_ON)
  
  LoopCtr = (uint32)0;
  #if (ADC_MAX_GROUPS > 1U)
  do
  #endif /*loop only when (ADC_MAX_SW_TRIGG_GROUP > 1U) */
  {
    /* Checking the variable QueueOfSwGroup[LoopCtr].NextGroup */
    ReadValue = (uint32)DataPtr->QueueOfSwGroup[LoopCtr].NextGroup;
    CompareValue &= (ReadValue ^ (~(uint32)(ADC_INVALID_GROUP_ID)));
    
    /* Checking the variable QueueOfSwGroup[LoopCtr].PreviousGroup */
    ReadValue = (uint32)DataPtr->QueueOfSwGroup[LoopCtr].PreviousGroup;
    CompareValue &= (ReadValue ^ (~(uint32)(ADC_INVALID_GROUP_ID)));
    
    #if (ADC_MAX_GROUPS > 1U)
    LoopCtr++;
    #endif 
  }
  #if (ADC_MAX_GROUPS > 1U)
  while (LoopCtr < ADC_MAX_GROUPS);
  #endif /*loop only when (ADC_MAX_SW_TRIGG_GROUP > 1U) */
  
  /* Checking the variable PopGroupId */
  ReadValue = (uint32)DataPtr->PopGroupId;
  CompareValue &= (ReadValue ^ (~(uint32)(ADC_INVALID_GROUP_ID)));
  
  /* Checking the variable PushGroupId */
  ReadValue = (uint32)DataPtr->PushGroupId;
  CompareValue &= (ReadValue ^ (~(uint32)(ADC_INVALID_GROUP_ID)));
  
  #endif /* (ADC_ENABLE_QUEUING == STD_ON) */
  
  if (CompareValue == ADC_INITCHK_COMP_VALUE)
  {
    RetVal = E_OK;
  }

  return(RetVal);
} /* Adc_lInitDataVarCheck */

#endif /* (ADC_INITCHECK_API == STD_ON) */

#if (ADC_GROUP_EMUX_SCAN == STD_ON)
/*******************************************************************************
** Syntax           : void Adc_lUpdateDmaData                                 **
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
void Adc_lUpdateDmaData(uint8 AdcKernel, Adc_GroupType Group)
{
  Adc_GlobalDataType         *DataPtr;
  
  /* Get ADC Kernel index for variables */
  /* Assign the address of ASIL or QM signal variable to global data pointer*/
  DataPtr = Adc_lGetDataAddress(AdcKernel);

  DataPtr->DmaData.Group = Group;

  /* Dma usage flag is set */
  DataPtr->DmaData.DmaUse = ADC_DMA_IN_USE;

} /* Adc_lUpdateDmaData */
#endif /* (ADC_GROUP_EMUX_SCAN == STD_ON) */

#if (ADC_GROUP_EMUX_SCAN == STD_ON)
/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Adc_lResetDmaData(uint8 AdcKernel)**
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Adc HW Unit ID                                          **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Reset Dma data i.e. no Group is using DMA               **
*******************************************************************************/
IFX_LOCAL_INLINE void Adc_lResetDmaData(uint8 AdcKernel)
{
  Adc_GlobalDataType *DataPtr;
  uint32 LoopCtr;
  
  /* Get ADC Kernel index for variables */
  /* Assign the address of ASIL or QM signal variable to global data pointer*/
  DataPtr = Adc_lGetDataAddress(AdcKernel);
  
  DataPtr->DmaData.Group = ADC_INVALID_GROUP_ID;

  DataPtr->DmaData.DmaUpdateCount = (uint32)0;

  /* Dma usage flag is reset */
  DataPtr->DmaData.DmaUse = ADC_DMA_NOT_IN_USE;

  LoopCtr = 0U;
  do
  {
    Adc_DmaBuffer[LoopCtr] = 0U;
    LoopCtr++;
    
  }while(LoopCtr < ADC_DMA_MAX_TRANSFER );
  
} /* Adc_lResetDmaData */
#endif /* (ADC_GROUP_EMUX_SCAN == STD_ON) */

#if (ADC_GROUP_EMUX_SCAN == STD_ON)
/*******************************************************************************
** Syntax           : void Adc_lDmaChInit                                     **
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
void Adc_lDmaChInit
(
  const uint8 AdcKernel, 
  const uint32 ResultRegNum,
  const Dma_ChannelType DmaChannel
)
{
  Adc_GlobalDataType *DataPtr;
  uint32 Address;
  uint32 SrcAddress;
  
  /* Get ADC Kernel index for variables */
  /* Assign the address of ASIL or QM signal variable to global data pointer*/
  DataPtr = Adc_lGetDataAddress(AdcKernel);

  /* Set Source Address */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
   access the SFRs of multiple ADC kernels.*/
  SrcAddress = (uint32)&(ADC_MODULE[AdcKernel].RES[ResultRegNum].U);
  /*IFX_MISRA_RULE_11_01_STATUS=integer to pointer typecasting is done for the  
  the Adc_DmaBuffer to set as destination address in DMA channel*/
  /*IFX_MISRA_RULE_11_03_STATUS=integer to pointer typecasting is done for the  
  the Adc_DmaBuffer to set as destination address in DMA channel*/
  Address = (uint32)(&Adc_DmaBuffer[0U]);
  /* Set Source Address */ 
  ADC_SFR_RUNTIME_MCAL_DMASETSOURCEADDR(DmaChannel, SrcAddress);
  /* Set Destination Address */ 
  ADC_SFR_RUNTIME_MCAL_DMASETDESTADDR(DmaChannel, Address);
  /* Clear channel control register */
  ADC_SFR_RUNTIME_MCAL_DMACHCLRCTLCFG(DmaChannel); 
  /* Clear interrupt on DMA Channel */
  ADC_SFR_RUNTIME_MCAL_DMACHCLRINTRFLAGS(DmaChannel);
  /* Set Interrupt Control and Interrupt Pointer */
  ADC_SFR_RUNTIME_MCAL_DMACFGINTCONTROL(DmaChannel, ADC_DMA_CH_INTCT);
  /* Set DMA Channel control register */
  /* After the configured number of transfer, DMA interrupt is generated */
  ADC_SFR_RUNTIME_MCAL_DMASETDATAWIDTH(DmaChannel, ADC_DMA_CH_WIDTH);
  ADC_SFR_RUNTIME_MCAL_DMASETTXCOUNT(DmaChannel, \
                                           DataPtr->DmaData.DmaUpdateCount);
  /* Enable DMA Interrupt */
  ADC_SFR_RUNTIME_MCAL_DMAENABLECHINTRTRIGGER(DmaChannel);
  ADC_SFR_RUNTIME_MCAL_DMAENABLEINTR(DmaChannel);
  /* DMA Address control */
  ADC_SFR_RUNTIME_MCAL_DMASETADICR(DmaChannel, ADC_DMA_ADR_CTR);
  /* Enable ADC HW trigg on selected DMA Channel */
  ADC_SFR_RUNTIME_MCAL_DMAENABLEHWTRANSFER(DmaChannel);

} /* Adc_lDmaChInit */

#endif /* (ADC_GROUP_EMUX_SCAN == STD_ON) */

#if (ADC_GROUP_EMUX_SCAN == STD_ON)
/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Adc_lDmaChDeInit                  **
**                                   (const uint32 DmaChannel)                **
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
** Description      : Is called when EMUX SCAN Group has requested for stop   **
**                    of conversion                                           **
*******************************************************************************/
IFX_LOCAL_INLINE void Adc_lDmaChDeInit(const Dma_ChannelType DmaChannel)
{
  /* Disable ADC HW trigg on DMA Channel */
  ADC_SFR_RUNTIME_MCAL_DMADISABLEHWTRANSFER(DmaChannel);
  
  /* Reset DMA Channel control register */
  ADC_SFR_RUNTIME_MCAL_DMACHCLRCTLCFG(DmaChannel);

  /* ReSet Interrupt Control and Interrupt Pointer */
  ADC_SFR_RUNTIME_MCAL_DMACHCLRINTCTETRLFLAGS(DmaChannel);

  /* Disable DMA Interrupt */
  ADC_SFR_RUNTIME_MCAL_DMADISABLEINTR(DmaChannel);
  /* DMA Address control */
  ADC_SFR_RUNTIME_MCAL_DMACLRADCR(DmaChannel);

  /* Clear interrupt on DMA Channel */
  ADC_SFR_RUNTIME_MCAL_DMACHCLRINTRFLAGS(DmaChannel);

} /* Adc_lDmaChDeInit */

#endif /* (ADC_GROUP_EMUX_SCAN == STD_ON) */

#if (ADC_GROUP_EMUX_SCAN == STD_ON)
/*******************************************************************************
** Syntax           : void Adc_lDmaTransResUpdate(uint8 AdcKernel)            **
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
void Adc_lDmaTransResUpdate(uint8 AdcKernel)
{
  Adc_GlobalDataType        *DataPtr;
  Adc_ValueGroupType        *CurrentResBufPtr;
  const Adc_GroupCfgType    *GrpPtr;
  uint32                    NoOfChannels;
  uint32                    ResVal;
  uint32                    DmaBuffIndex;
  uint32                    NumSampLoopCnt;
  uint32                    NumChLoopCnt;
  Adc_ValueGroupType        *GrpBufferBasePtr;
  Adc_StreamNumSampleType   NoOfSamples;
  Adc_GroupType             Group;

  /* Get ADC Kernel index for variables */
  /* Assign the address of ASIL or QM signal variable to global data pointer*/
  DataPtr = Adc_lGetDataAddress(AdcKernel);

  /*Get the Group which uses DMA */
  Group = DataPtr->DmaData.Group;

  /* After ADC_STREAM_COMPLETED, Group result buffer is updated */
  /* Initialise with base value */

  /* Get the Group result buffer base address */
  GrpBufferBasePtr = DataPtr->GroupResultBuffer[Group];

  /* Get the Group Config data pointer */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
   PBConfigStructure and is within allowed range*/
  GrpPtr = (Adc_kConfigPtr->CfgPtr[AdcKernel]->GrpCfgPtr) + Group;

  /* Streaming number of samples will decide the ResBufPtr increment value */
  NoOfSamples = (GrpPtr->NumSamples);

  /* Note: EMUX select value of Group channel will give the number of channels 
     scaned by HW.
     GroupDefinition will explicitly have only one channel
  */

  /* Get the Group's number of configured channels */
  /* Note: Group with EMUX SCAN will implicitly convert for configured 
     channel EMUX select to count down 0 
  */
  NoOfChannels = 
    ((uint32)Adc_lGetEmuxSelect((uint32)GrpPtr->GroupEmuxData) + (uint32)1);

  /* Update Converted Value from DMA buffer in to Group Buffer */
  /* Initialise the Loop variables */
  DmaBuffIndex = 0U;
  NumSampLoopCnt = 0U;
  /*-----------------------------------------------**
  ** loop till the NoOfSamples decremented to zero **
  **-----------------------------------------------*/
  do
  {
    /* Initialise the channel loop varaibles */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
     result buffer and is within allowed range*/
    CurrentResBufPtr = GrpBufferBasePtr + NumSampLoopCnt;
    NumChLoopCnt = 0U;
    /*------------------------------------------------**
    ** loop till the NoOfChannels decremented to zero **
    **------------------------------------------------*/
    do
    {

      /* Get the conversion Result of the channel from CHSTAT Reg */
      ResVal = (uint32)Adc_DmaBuffer[DmaBuffIndex];

      DmaBuffIndex++;

      Adc_lAlignResultBuffer(AdcKernel, Group, CurrentResBufPtr, ResVal);
      
      /* Point to the next channel result element of the group */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
       result buffer and is within allowed range*/
      CurrentResBufPtr = (CurrentResBufPtr + NoOfSamples);
      
      /* Increment the Ch loop cnt by 1 */
      NumChLoopCnt++;

    } while (NumChLoopCnt < NoOfChannels);
    
    /* Increment the sample loop count */
    NumSampLoopCnt++;

  } while (NumSampLoopCnt < (uint32)NoOfSamples);

  /*Note: No critical section as ISR priority is higher than  
    Adc_GetStreamLastPointer/Adc_ReadGroup API priority 
  */

  /*---------------------------------------------------------------------**
  ** update the Number of conversion result and Result buffer end status **
  **---------------------------------------------------------------------*/
  DataPtr->NumValidConRes[Group] = NoOfSamples;

  /* Set the status of End buffer which will indicate all the buffer 
     values are valid and Buffer is full
  */
  Adc_lSetResBuffEndStatusAtomic(DataPtr,Group);
  
  return;

}/* Adc_lDmaTransResUpdate */
#endif /* (ADC_GROUP_EMUX_SCAN == STD_ON) */

/*******************************************************************************
** Syntax           : void Adc_lInitGlobalVariables(void)                     **
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
void Adc_lInitGlobalVariables(void)
{
  Adc_GlobalDataType          *DataPtr;
  uint32                      LoopCtr;
  uint8                       KernelCtr;

  /* Atleast one ADC Kernel will be in use */
  /* KernelCtr will give the variable array index */
  KernelCtr = (uint8)0;

  /* Initialization done to remove Misra 8.7 */
  #if ( ADC_SAFETY_ENABLE == STD_ON )
  #if (ADC_ASIL0_KERNEL_USED_COUNT != 0U )
  Adc_AsilSignal0[KernelCtr].TriggSrcData[KernelCtr].GrpId = 
                                                         ADC_GRP_REQ_SRC_FREE;
  #endif /* (ADC_ASIL0_KERNEL_USED_COUNT != 0U ) */
  #if (ADC_ASIL1_KERNEL_USED_COUNT != 0U )
  Adc_AsilSignal1[KernelCtr].TriggSrcData[KernelCtr].GrpId = 
                                                         ADC_GRP_REQ_SRC_FREE;
  #endif /* (ADC_ASIL1_KERNEL_USED_COUNT != 0U ) */
  #endif /* ( ADC_SAFETY_ENABLE == STD_ON ) */
  
  #if( (ADC_QM_KERNEL_USED_COUNT != 0U ) && (ADC_REQSRC2 == ADC_REQSRC_UNUSED) )
  Adc_QmSignal[KernelCtr].TriggSrcData[KernelCtr].GrpId = 
                                                         ADC_GRP_REQ_SRC_FREE;
  #endif 
  /* (ADC_QM_KERNEL_USED_COUNT != 0U ) && (ADC_REQSRC2 == ADC_REQSRC_UNUSED) */
  
  /* Loop for all ADC HW Unit */
  do
  {
    /* if kernel configured, initialize the data variables */
    if( Adc_lKernelConfigured(KernelCtr) )
    {
      /* Get ADC Kernel index for variables */
      /* Assign the address of ASIL or QM signal variable to 
         global data pointer */
      DataPtr = Adc_lGetDataAddress(KernelCtr);

      /* Initialize the trigger source data */
      LoopCtr = (uint32)0;
      do
      {
        /* No Group on request and hence this request source is free */
        /* No Group on request and hence this Internal channel is invalid */
        /* No Group on request and hence this Group Priority is invalid */
        /* Initialise Do nothing in trigger source service request */
        DataPtr->TriggSrcData[LoopCtr].GrpId = ADC_GRP_REQ_SRC_FREE;
        
        DataPtr->TriggSrcData[LoopCtr].GrpPriority = ADC_INVALID_PRIORITY;
        
        DataPtr->TriggSrcData[LoopCtr].IsrDoNothing= ADC_NO_SERVICE;
        
        #if (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR)
        DataPtr->TriggSrcData[LoopCtr].GrpLastChannel = 
                                                    ADC_INVALID_CHANNEL;
        #endif /* (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR) */


        /* Note:
           Reset of Group RS Group data (RsGroupData) is not required
           as its been initialised with start of group conversion before reading
        */
        LoopCtr++;
      } while (LoopCtr < ADC_REQSRC_COUNT );

      /* Initialize the group result buffer-end status for all groups */
      DataPtr->GrpBufferEndResultStatus = (uint32)0;

      /* ADC_COMPLETED status is not supported in Non AUTOSAR result handling */
      #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
      /* Reset Group Result Status. Set to no result available*/
      DataPtr->GroupResultStatus = (uint32)0;


      LoopCtr = (uint32)0;
      #if (ADC_MAX_GROUPS > 1U)
      do
      #endif /*loop only when (ADC_MAX_SW_TRIGG_GROUP > 1U) */
      {
        /* LoopCtr will give the Group ID */
        /* Reset the Group result buffer address */
        DataPtr->GroupResultBuffer[LoopCtr] = NULL_PTR;

        #if (ADC_MAX_GROUPS > 1U)
        LoopCtr++;
        #endif 
      }
      #if (ADC_MAX_GROUPS > 1U)
      while (LoopCtr < ADC_MAX_GROUPS);
      #endif /*loop only when (ADC_MAX_SW_TRIGG_GROUP > 1U) */


      #endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */
      
      /* Reset Group Status. Set To ADC_IDLE */
      DataPtr->GroupStatus = (uint32)0;

      #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
      /* ADC077: Notification status are disabled for all the group */
      DataPtr->GrpNotifStatus = (uint32)0;
      #endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

      /* For Partial priority considered */
      #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
      #if (ADC_DEV_ERROR_DETECT == STD_ON)
      /* Initialize all running channels for channel sharing checking to 0 */
      DataPtr->AllRunningCh = (uint16)0;
      #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
      #endif /* (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) */

      /* Queue Enable is STD_ON only during No priority */
      #if (ADC_ENABLE_QUEUING == STD_ON)

      LoopCtr = (uint32)0;
      #if (ADC_MAX_GROUPS > 1U)
      do
      #endif /*loop only when (ADC_MAX_SW_TRIGG_GROUP > 1U) */
      {
        /* LoopCtr will give the Group ID */
        /* Reset the Queue array to Invalid data */
        DataPtr->QueueOfSwGroup[LoopCtr].NextGroup = ADC_INVALID_GROUP_ID;
        DataPtr->QueueOfSwGroup[LoopCtr].PreviousGroup = ADC_INVALID_GROUP_ID;

        #if (ADC_MAX_GROUPS > 1U)
        LoopCtr++;
        #endif 
      }
      #if (ADC_MAX_GROUPS > 1U)
      while (LoopCtr < ADC_MAX_GROUPS);
      #endif /*loop only when (ADC_MAX_SW_TRIGG_GROUP > 1U) */

      /* Reset the Poping Group Id to Invalid */
      DataPtr->PopGroupId = ADC_INVALID_GROUP_ID;

      /* Reset the Pushed Group Id to Invalid */
      DataPtr->PushGroupId = ADC_INVALID_GROUP_ID;

      #endif /* (ADC_ENABLE_QUEUING == STD_ON) */

      #if (ADC_USE_EMUX == STD_ON)
      /* Reset Emux variable for each Kernel */
      DataPtr->EmuxGroup = ADC_INVALID_GROUP_ID;
      #endif /* (ADC_USE_EMUX == STD_ON) */
      
    } /* end of kernel configured check */
    
    KernelCtr++;

  }while (KernelCtr < ADC_MAX_KERNELS);

  #if (ADC_REQSRC2 == ADC_REQSRC_USED)
  
  Adc_BgndScanData = ADC_BGND_REQ_SRC_FREE;
  Adc_BgndGrpCnt = 0U;
  
  #endif /* (ADC_REQSRC2 == ADC_REQSRC_USED) */

  #if (ADC_GROUP_EMUX_SCAN == STD_ON)

  KernelCtr = 0U;
  #if (ADC_KERNEL_USED_COUNT > 1U)
  /* Loop for all used ADC HW Unit */
  do
  #endif /* loop only when (ADC_KERNEL_USED_COUNT > 1U) */
  {
    /* Reset DMA Data */
    Adc_lResetDmaData((uint8)KernelCtr);
    #if (ADC_KERNEL_USED_COUNT > 1U)
    KernelCtr++;
    #endif
  }
  #if (ADC_KERNEL_USED_COUNT > 1U)
  while (KernelCtr < ADC_KERNEL_USED_COUNT);
  #endif /* loop only when (ADC_KERNEL_USED_COUNT > 1U) */
  
  #endif /* (ADC_GROUP_EMUX_SCAN == STD_ON) */

}/* Adc_lInitGlobalVariables */

#if (ADC_HW_TRIGGER_API == STD_ON)
/*******************************************************************************
** Syntax           : uint32 Adc_lGetRsCtrlData                               **
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
uint32 Adc_lGetRsCtrlData
(
  uint32 HwCfgData,
  uint32 DataPos,
  uint32 ShiftPos
)
{
  uint32                  RetValue;

  
  RetValue = ((HwCfgData & DataPos ) >> ShiftPos);
  
  return (RetValue);
     
} /* Adc_lGetRsCtrlData */

/*******************************************************************************
** Syntax           : uint32 Adc_lGetTriggSelData                             **
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
uint32 Adc_lGetTriggSelData
(
  uint32 HwCfgData,
  uint32 DataPos,
  uint32 ShiftPos
)
{
  uint32                  RetValue;

  
  RetValue = ((HwCfgData & DataPos ) >> ShiftPos);
  
  return (RetValue);
     
} /* Adc_lGetTriggSelData */
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Adc_lSetResBuffEndStatusAtomic    **
**                    (                                                       **
**                       Adc_GlobalDataType *DataPtr,                         **
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
** Description      : Is called to Set Group Result buffer end Status         **
**                                               to Result full               **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE void Adc_lSetResBuffEndStatusAtomic
(
  const Adc_GlobalDataType *DataPtr, 
  Adc_GroupType Group
)
{
  Mcal_SetAtomic
      ( ((sint32*)(void *)&(DataPtr->GrpBufferEndResultStatus)),
        (uint32)(1U), (sint32)(Group), 1
      );
     
} /* Adc_lSetResBuffEndStatusAtomic */

/*******************************************************************************
** Syntax           : Adc_ChannelType Adc_lGetKernelChNum                     **
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
Adc_ChannelType Adc_lGetKernelChNum
(
  uint32 ChConfigData
)
{
  Adc_ChannelType RetValue;
  
  RetValue = 
    (Adc_ChannelType)( (ChConfigData >> ADC_POS_CH_CFG_INT_CH ) & 
                                                         ADC_CHANNEL_ID_MASK
                     );
  
  return(RetValue);
  
} /* Adc_lGetKernelChNum */

/*******************************************************************************
** Syntax           : uint32 Adc_lClearEventFlag                              **
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
uint32 Adc_lClearEventFlag
(
  uint8 ReqSrc
)
{
  uint32 RetValue;
  
  RetValue = (uint32)((uint32)0x1 <<(ReqSrc));
  
  return(RetValue);
  
} /* Adc_lClearEventFlag */

#if (ADC_HW_TRIGGER_API == STD_ON)
/*******************************************************************************
** Syntax           : uint32 Adc_lGetEngtVal                                  **
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
uint32 Adc_lGetEngtVal
(
  uint32 HwCfgData
)
{
  uint32 RetValue;
  
  RetValue = (uint32)EXTRACT( (HwCfgData), (ADC_ENGT_START_BIT),
                              (ADC_ENGT_NUM_OF_BITS)
                            );
  
  return(RetValue);
  
} /* Adc_lGetEngtVal */

#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

#if ((ADC_ERU_TRIGG == STD_ON) || (ADC_ERU_GATING == STD_ON))
/*******************************************************************************
** Syntax           : uint32 Adc_lGetEruUnit                                  **
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
uint32 Adc_lGetEruUnit
(
  uint32 HwCfgData
)
{
  uint32 RetValue;
  
  RetValue = (uint32)EXTRACT( (HwCfgData), (ADC_POS_HW_CFG_ERU_UNIT),
                              (ADC_ERU_UNIT_NUM_OF_BITS)
                            );
  
  return(RetValue);
  
} /* Adc_lGetEruUnit */

/*******************************************************************************
** Syntax           : uint32 Adc_lGetEruOguUnit                               **
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
uint32 Adc_lGetEruOguUnit
(
  uint32 HwCfgData
)
{
  uint32 RetValue;
  
  RetValue = (uint32)EXTRACT( (HwCfgData), (ADC_POS_HW_CFG_ERU_OGU_UNIT),
                              (ADC_ERU_UNIT_NUM_OF_BITS)
                            );
  
  return(RetValue);
  
} /* Adc_lGetEruOguUnit */

#if (ADC_RESET_SFR_INIT == STD_ON)
/*******************************************************************************
** Syntax           : void Adc_lResetEruSfr                                   **
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
void Adc_lResetEruSfr(void)
{
  const Adc_GroupCfgType* GrpPtr;

  uint32 HwCfgData;

  #if (ADC_ERU_GATING == STD_ON)
  uint32 HwGateData;
  uint32 EruGateFlag;
  #endif /* (ADC_ERU_GATING == STD_ON) */
  #if (ADC_ERU_TRIGG == STD_ON)
  uint32 EruTrigFlag;
  #endif /* (ADC_ERU_TRIGG == STD_ON) */

  uint8 LoopCtr;
  uint8 GrpCtr;
  uint8 TotGrps;
  
  /* Resetting ERU registers */
  LoopCtr = 0U;
  do
  {
    if(Adc_lKernelConfigured((uint8)LoopCtr) != 0U)
    {
      /* Configured number of groups */
      TotGrps = Adc_kConfigPtr->CfgPtr[LoopCtr]->TotCfgGrps;
      
      GrpCtr = 0U;
      do
      {
        /* Get ADC kernel HW Unit Config pointer */
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
        PBConfigStructure and is within allowed range*/
        GrpPtr = (Adc_kConfigPtr->CfgPtr[LoopCtr]->GrpCfgPtr) + GrpCtr;
        
        if (GrpPtr->TriggSrc == ADC_TRIGG_SRC_HW)
        {
          /* Get the user config data for HW trigger */
          HwCfgData = GrpPtr->HwTrigConfig;
          #if (ADC_ERU_TRIGG == STD_ON)
          /* Get the Group ERU trigger flag */
          EruTrigFlag = (uint32)Adc_lGetEruData(HwCfgData);
          #endif /* (ADC_ERU_TRIGG == STD_ON) */
      
          #if (ADC_ERU_GATING == STD_ON)
          /* Get the user config data for HW Gate */
          HwGateData = (uint32)GrpPtr->HwGateConfig;
          /* Get the Group ERU gate flag */
          EruGateFlag = (uint32)Adc_lGetEruData(HwGateData);
          #endif /* (ADC_ERU_GATING == STD_ON) */
      
          #if (ADC_ERU_TRIGG == STD_ON)
          /* Eru trigger type selected */
          if (EruTrigFlag == (uint32)ADC_TRIG_ERU_SELECTED)
          {
            /* Resetting ERU IOUT Signal */
            Adc_lResetEruCfg(HwCfgData, ADC_INIT_ACCESS);
          }
          #endif  /*(ADC_ERU_TRIGG == STD_ON)*/

          #if (ADC_ERU_GATING== STD_ON)
          if (EruGateFlag == (uint32)ADC_GATE_ERU_SELECTED)
          {
            /* Resetting ERU PDOUT Signal */
            Adc_lResetEruGateCfg(HwGateData, ADC_INIT_ACCESS);
          }
          #endif /* (ADC_ERU_GATING== STD_ON) */
        }
        GrpCtr++;
        
      }while (GrpCtr < TotGrps);
    }
    LoopCtr++;
    
  } while (LoopCtr < ADC_MAX_KERNELS);

} /* Adc_lResetEruSfr */
#endif /* (ADC_RESET_SFR_INIT == STD_ON) */

#endif /* (ADC_ERU_GATING == STD_ON || ADC_ERU_TRIGG == STD_ON) */

/*******************************************************************************
** Syntax           : Adc_GlobalDataType *Adc_lGetDataAddress                 **
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
Adc_GlobalDataType *Adc_lGetDataAddress
(
  uint8 Kernel
)
{
  Adc_GlobalDataType *LocalDataPtr;
  #if ( ADC_SAFETY_ENABLE == STD_ON )
  const Adc_HwUnitCfgType   *HwCfgPtr;
  #endif /* ( ADC_SAFETY_ENABLE == STD_ON ) */
  uint8 KernelIndex;

  #if ( ADC_SAFETY_ENABLE == STD_ON )
  
  #if ( ( ADC_ASIL0_KERNEL_USED_COUNT == 0U ) || \
        ( ADC_ASIL1_KERNEL_USED_COUNT == 0U ) || \
        ( ADC_QM_KERNEL_USED_COUNT == 0U ) \
      )
  LocalDataPtr = NULL_PTR;

  #endif 
  /*(ADC_ASIL0_KERNEL_USED_COUNT == 0U)||(ADC_ASIL1_KERNEL_USED_COUNT == 0U)*/
  
  HwCfgPtr = Adc_kConfigPtr->CfgPtr[Kernel]->HwCfgPtr;

  if( (HwCfgPtr->SignalType) == ADC_ASIL_SIGNAL_0 )
  {
    #if (ADC_ASIL0_KERNEL_USED_COUNT != 0U )
    KernelIndex = Adc_kAsilSignal0Index[Kernel];
    LocalDataPtr = &Adc_AsilSignal0[KernelIndex];
    #endif /* (ADC_ASIL0_KERNEL_USED_COUNT != 0U ) */
  }
  else if( (HwCfgPtr->SignalType) == ADC_ASIL_SIGNAL_1 )
  {
    #if (ADC_ASIL1_KERNEL_USED_COUNT != 0U )
    KernelIndex = Adc_kAsilSignal1Index[Kernel - ADC_KERNELS_PER_CLUSTER];
    LocalDataPtr = &Adc_AsilSignal1[KernelIndex];
    #endif /* (ADC_ASIL1_KERNEL_USED_COUNT != 0U ) */
  }
  else
  #endif /* ( ADC_SAFETY_ENABLE == STD_ON ) */
  {
    #if (ADC_QM_KERNEL_USED_COUNT != 0U )
    KernelIndex = Adc_kQmSignalIndex[Kernel];
    LocalDataPtr = &Adc_QmSignal[KernelIndex];
    #endif /* (ADC_QM_KERNEL_USED_COUNT != 0U ) */
  }
  
  return(LocalDataPtr);
} /* Adc_lGetDataAddress */
  

#define ADC_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
**                            General Notes                                   **
*******************************************************************************/
/*
Notification prototype for the notification callback function. It has to
be implemented by the user.

When the notification mechanism is disabled, no notification
shall be sent. When the notifications are re-enabled again, 
the user will not be notified of events that occurred while 
notifications have been disabled.

The ADC Driver shall allow the assignment of identical channels to
more than one group. However parallel operation of groups with same 
channel are not allowed. 

All channels of a group share the same configuration related to group.

The symbolic names of ADC channels and ADC channel groups for use by
the upper layer shall be defined by the configurator. They are not 
published by the ADC driver.

There are no registers related to ADC that can be written only one time.

The callback functions are running in the interrupt context. It's the 
responsibility of the user to keep the code short inside this function.
This is note for the user of ADC driver.
*/

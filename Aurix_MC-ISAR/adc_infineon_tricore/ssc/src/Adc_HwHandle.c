/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : Adc_HwHandle.c $                                           **
**                                                                            **
**   $CC VERSION : \main\dev_tc2xx_ca\33 $                                    **
**                                                                            **
**   $DATE       : 2016-09-08 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : This file contains                                         **
**                 - functions related to Hardware access of Adc.             **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*******************************************************************************/
  
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion structure */
#include "Adc_Utility.h"

#if (ADC_TIMER_TRIGG == STD_ON)
/* Inclusion of GTM sfr */
#include "Gtm.h"
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

#if (ADC_CCU6_SYNCHRONIZATION == STD_ON)
/* Inclusion of Ccu6 sfr file */
#include "IfxCcu6_reg.h"
#endif /* (ADC_CCU6_SYNCHRONIZATION == STD_ON) */
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#if(ADC_ENABLE_LIMIT_CHECK == STD_ON)
/* Bit position of BNDSELL bit field */
#define ADC_BNDSELL_BIT_POS  (4U)
/* Bit position of BNDSELU bit field */
#define ADC_BNDSELU_BIT_POS  (6U)
/* Bit position of CHEVMODE bit field */
#define ADC_CHEVMODE_BIT_POS (8U)
/* Bit position of BNDSELX bit field */
#define ADC_BNDSELX_BIT_POS  (12U)
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

#if (ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT)  
/* Shift to match the 16 bit Left align */
#define ADC_LEFT_ALIGN_SHIFT                 (4U)
#endif /* (ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT) */

#if ( ADC_INITCHECK_API == STD_ON )
/* Value of the CALS bitfield of ARBCFG register after Init */
#define ADC_CALS_BIT_VAL        (0x20000000U)
/* postion of ANONS bitfield of ARBCFG register */
#define ADC_ANONS_BIT_POS       (16U)
/* Mask value of the ARBCFG register */
#define ADC_ARBCFG_MASK         (0x200300B3U)
#if (ADC_CCU6_SYNCHRONIZATION == STD_ON)
/* Mask value for T13R, T13PRE, T13CLK bit fields of CCU6x_TCTR0 register */
#define ADC_TCTR0_SFR_CHK_MSK   (0x00001F00U)
/* Mask value for T13R bit field of CCU6x_TCTR0 register */
#define ADC_TCTR0_T13R_MASK     (0x00001000U)
/* Mask value for TRIG1SEL bit field of MOSEL register */
#define ADC_MOSEL_SFR_CHK_MSK   (0x00000038U)
/* DCMSB bitfield value for the devices with Metal Fix */
#define ADC_DCMSB_BIT_VALUE     ((uint32)0x00000080)
#else
/* DCMSB bitfield value */
#define ADC_DCMSB_BIT_VALUE     ((uint32)0x0)
#endif /* (ADC_CCU6_SYNCHRONIZATION == STD_ON) */
#endif /* ( ADC_INITCHECK_API == STD_ON ) */

#if ((ADC_HW_TRIGGER_API == STD_ON) && (ADC_TIMER_TRIGG == STD_ON))
#define ADC_GTM_TIMER_MASK            (0x00FFFFFFU)
/* Defines used for Channel Identifier Api */
/* Module No */
#define ADC_GTM_CHAN_ID_MOD_NO_POS    (2)
#define ADC_GTM_CHAN_ID_MOD_ID_POS    (6)

#define ADC_GTM_ATOM_MODULE           (2U)
#define ADC_GTM_ATOM_ENABLE           (2UL)
#define ADC_GTM_ATOM_BITS_PER_CHAN    (2U)
#define ADC_GTM_ATOM_CHAN_DISABLE     (1UL)

#define ADC_GTM_TOM_MODULE            (1U)
#define ADC_GTM_TOM_TGC0_CHOSEN       (8U)
#define ADC_GTM_TOM_ENABLE            (2UL)
#define ADC_GTM_TOM_BITS_PER_CHAN     (2U)
#define ADC_GTM_TOM_CHAN_DISABLE      (1UL)
#define ADC_GTM_TGC0                  (0U)
#define ADC_GTM_TGC1                  (1U)

#define ADC_GTM_MODULE_ID_POS         (6U)
#define ADC_GTM_MODULE_NO_POS         (2U)

/* To derive information from the Global Channel Number Type Structure */
#define ADC_GTM_MODULE_ID_MSK         (0xC0U)
#define ADC_GTM_MODULE_NO_MSK         (0x3CU)

#endif /*(ADC_HW_TRIGGER_API == STD_ON && ADC_TIMER_TRIGG == STD_ON)*/

#if (ADC_ERU_TRIGG == STD_ON)

/* Shift value to get ERU EICR Register bit position for programming */
#define ADC_ERU_EICR_PROG_POS       (4U)

/* Shift value to get ERU IGCR Register bit position for programming */
#define ADC_ERU_IGCR_PROG_POS       (4U)

/* ERU config data position in HW Cfg data */
#define ADC_ERU_DATA_POS            (16U)

/* ERU config data bits */
/* This value should not have subscript 'U'since its used in
   ADC_SFR_RUNTIME_USER_MODE_MCAL_SETATOMIC */
#define ADC_ERU_DATA_BITS           (16)

/*ERU Cfg bits : EXIS(External input select), Trigg Edge, EIEN = 1b, 
  INP (selection of Output channel)
*/
#define ADC_ERU_CFG_BITS             (0x7F30)
#define ADC_ERU_RESET_DATA           (0U)
/* level detection enable LDEN = 1, REN = 1 for Patter detection */
#define ADC_ERU_LEVEL_DETECTION      (0x0600)
/* IGP bit position of IGCR register */
#define ADC_ERU_IGP_POS              (14U)
/* Activate IOUT in IGP bit of IGCR register */
#define ADC_ERU_IGP_ACTIVATE         (0x4000)

#endif /* (ADC_ERU_TRIGG == STD_ON) */

#if (ADC_WAIT_ON_STOP == STD_ON)
/* BUSY and SAMPLE bit mask value */
#define ADC_BUSY_SAMPLE_MASK         ((uint32)0xC0000000U)

#endif /* (ADC_WAIT_ON_STOP == STD_ON) */

#if (ADC_CCU6_SYNCHRONIZATION == STD_ON)
/* bit ECT130 = 1 serves to route  CC63ST signals out to  COUT63 */
#define ADC_CCU6_MODCTR_VAL          ((uint32)0x00008000)
/* set bit T13STR  & T13RS  -> enable shadow transfer & start timer T13 */
#define ADC_CCU6_TCTR4_VAL           ((uint32)0x00004200)
/* passive state level of COUT63 = 1 */
#define ADC_CCU6_PSLR_VAL            ((uint32)0x00000080)
#endif /* (ADC_CCU6_SYNCHRONIZATION == STD_ON) */
/* Macro to clear CHCTR except BWD bitfields */
#define ADC_CLR_CHCTR_EXCEPT_BWD     ((uint32)0x70000000)
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define ADC_START_SEC_CODE
#include "MemMap.h"

static void Adc_lKernelInit
(
  const Adc_KernelConfigType  *AdcKernelPtr,
  uint8 AdcKernel
);

#if (ADC_INITCHECK_API == STD_ON)

/* Kernel speific Initcheck function */
IFX_LOCAL_INLINE Std_ReturnType Adc_lKernelInitCheck
(
  const Adc_KernelConfigType  *AdcKernelPtr,
  uint8 AdcKernel
);

#if (ADC_RESULT_POLLING_MODE == STD_OFF)
/* SRE register speific Initcheck function */
IFX_LOCAL_INLINE Std_ReturnType Adc_lSetSreCheck(void);
#endif /* (ADC_RESULT_POLLING_MODE == STD_OFF) */

#if (ADC_CCU6_SYNCHRONIZATION == STD_ON)
/* CCU6 register specific Initcheck function */
static Std_ReturnType Adc_lCcu6InitCheck(void);
#endif /* (ADC_CCU6_SYNCHRONIZATION == STD_ON) */

#endif /* (ADC_INITCHECK_API == STD_ON) */

#if( (ADC_MASTER_SLAVE_SYNC == STD_ON) || (ADC_ENABLE_LIMIT_CHECK == STD_ON) )
IFX_LOCAL_INLINE void Adc_lEnableSynchLimitChkCh
(
  uint8 AdcKernel,
  Adc_GroupType GroupId,
  Adc_ChannelType IntChNr,
  Adc_ChannelType ChIdx
);
#endif 
/* ((ADC_MASTER_SLAVE_SYNC == STD_ON) || (ADC_ENABLE_LIMIT_CHECK == STD_ON)) */

#if (ADC_WAIT_ON_STOP == STD_ON)
/* Wait for hadware to be Idle on resetting the request source */
IFX_LOCAL_INLINE void Adc_lWaitForChConversion
(
  uint8 AdcKernel
);
#endif /* (ADC_WAIT_ON_STOP == STD_ON) */

#if (ADC_HW_TRIGGER_API == STD_ON)

#if (ADC_TIMER_TRIGG == STD_ON)
/* Function to extract TOM / ATOM module id*/
IFX_LOCAL_INLINE uint8 Adc_lGetGtmModuleNo(Adc_GtmChIdentifierType ChannelId);

/* Function to identify TOM / ATOM module used*/
IFX_LOCAL_INLINE uint8 Adc_lGetGtmModuleId(Adc_GtmChIdentifierType ChannelId);

IFX_LOCAL_INLINE Adc_GtmChIdentifierType Adc_lGtmChannelIdentifier
(
  uint8 GlobalChannelNumber
);

#endif /* ADC_TIMER_TRIGG == STD_ON */

#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

#if (ADC_CCU6_SYNCHRONIZATION == STD_ON)
/* Ccu6 initialization */
static uint8 Adc_lCcu6Init(void);
#endif /* (ADC_CCU6_SYNCHRONIZATION == STD_ON) */

#if (ADC_RESET_SFR_INIT == STD_ON)
/* resetting the used SFRs */
static void Adc_lResetSfr(void);
#endif /* (ADC_RESET_SFR_INIT == STD_ON) */

#define ADC_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
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

#define ADC_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
** Traceabilty      :[cover parentID=DS_AS_ADC365,DS_AS_ADC067_ADC234_1,
                     DS_AS_ADC107,DS_AS_ADC343,DS_AS_ADC054_ADC056,DS_AS_ADC307,
                     DS_AS_ADC077,DS_MCAL_ADC_0413_1]
** Syntax           : void Adc_Init                                           **
**                    (                                                       **
**                      const Adc_ConfigType *ConfigPtr                       **
**                    )                                                       **
**[/cover]                                                                    **
**                                                                            **
** Service ID       : 0x00                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : ConfigPtr - Pointer to ADC configuration Set            **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - ADC054: This service shall initialize the ADC hardware unit and driver **
**             according to the configuration set referenced by ConfigPtr.    **
**   - ADC056: This function shall only initialize the configured resources.  **
**   - ADC077: notifications and hardware trigger capability shall be         **
**             disabled after module initialization                           **
**   - ADC307: All configured Groups are set to ADC_IDLE state                **
**   - ADC107: This function should be called first and once in order to      **
**     initialize the ADC driver for use                                      **
**                                                                            **
*******************************************************************************/
void Adc_Init
(
  const Adc_ConfigType *ConfigPtr
)
{
  const Adc_KernelConfigType  *KernelPtr;
  uint32                      LoopCtr;
  uint32                      SfrValue;
  uint8                       ClcStatus;
/*-------------------------------------**
** Check for Development Errors        **
**-------------------------------------*/

/* ADC234, ADC067: Detected development errors shall be reported to the 
   Det_ReportError service 
*/
  #if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )

  uint32 Err;

  Err = Adc_lCheckInitParam(ConfigPtr);

  if (Err == ADC_E_DET_NO_ERR)
  #endif
  /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */
  {

    #if(ADC_PB_FIXED_ADDRESS == STD_OFF)
    Adc_kConfigPtr = ConfigPtr; /* Store ConfigPtr to use any other APIs */
    #else
    UNUSED_PARAMETER(ConfigPtr)
    #endif  /*(PORT_PB_FIXEDADDR == STD_OFF)*/

    /* If ADC Driver is not yet initialized, then initialize with the data 
       pointed by the user
    */

    /* Available as one set for all ADC Kernel */
    /* Enable ADC module, and Configure ADC Module Sleep mode */ 
    SfrValue = (uint32)( ADC_MODULE_ENABLE | \
                        ((uint32)Adc_kConfigPtr->SleepMode << ADC_EDIS_BIT_POS)\
                       );

    ClcStatus = Adc_lInitWriteClcSfr(SfrValue, ADC_SID_INIT);

    if(ClcStatus != 0U)
    {
      #if (ADC_RESET_SFR_INIT == STD_ON)
      /* Resetting the used SFRs */
      Adc_lResetSfr();

      #endif /* (ADC_RESET_SFR_INIT == STD_ON) */

      /* Configuration of DIVA, DIVD, DPCAL, DCMSB  */
      SfrValue =  ( ADC_DIV_PARAM_WRITE_ENABLE | \
                  (Adc_kConfigPtr->GlobCfgPtr->ClkPrescale) | \
                  (Adc_kConfigPtr->GlobCfgPtr->RefPrechargeCtrl) | \
                  (Adc_kConfigPtr->GlobCfgPtr->LowPowerSupply) | \
                  (Adc_kConfigPtr->GlobCfgPtr->PostCalEnable) \
                  );

      Adc_lWriteGlobCfgSfr(SfrValue);

      /* Configuration of 2 Global Input class control register */
      LoopCtr = 0U;
      do
      {
        SfrValue = (uint32)Adc_kConfigPtr->GlobCfgPtr->GlobInputClass[LoopCtr];

        Adc_lWriteGlobIpClassSfr((uint8)LoopCtr, SfrValue);

        LoopCtr++;
      } while (LoopCtr < ADC_NO_GLOB_INP_CLASS);

      /* Initialise the Event Node Pointer Register as per the design */
      /* Event node pointer for request source 2 is initialised with designed
         value even if the request source is not in use */

      Adc_lWriteGlobEvntNpSfr(ADC_RS2_NODEPOINTER);
   
      #if(ADC_USE_EMUX == STD_ON)
      /* Emux groups interfaced to the set Kerenels */
      Adc_lWriteEmuxSelSfr((uint32)Adc_kConfigPtr->GlobCfgPtr->EmuxSelectGrp);

      #endif /* (ADC_USE_EMUX == STD_ON) */

      LoopCtr = 0U;
      do
      {
        if(Adc_lKernelConfigured((uint8)LoopCtr) != 0U)
        {
          /* Assign the ADC Kernel Configuration pointer to the local pointer */
          KernelPtr = Adc_kConfigPtr->CfgPtr[LoopCtr];

          #if( ADC_MASTER_SLAVE_SYNC == STD_ON )
          if(KernelPtr->HwCfgPtr->SyncConvMode != ADC_MASTER)
          #endif /* ( ADC_MASTER_SLAVE_SYNC == STD_ON ) */
          {
            /* Initialise ADC Kernels */
            Adc_lKernelInit(KernelPtr, (uint8)LoopCtr);
          }
        }

        LoopCtr++;

      } while (LoopCtr < ADC_MAX_KERNELS);

      /* intializing Master and Standalone kernels */
      #if( ADC_MASTER_SLAVE_SYNC == STD_ON )
      LoopCtr = 0U;
      do
      {
        if(Adc_lKernelConfigured((uint8)LoopCtr) != 0U)
        {
          /* Assign the ADC Kernel Configuration pointer to the local pointer */
          KernelPtr = Adc_kConfigPtr->CfgPtr[LoopCtr];

          if(KernelPtr->HwCfgPtr->SyncConvMode == ADC_MASTER)
          {
            /* Initialise ADC Kernels */
            Adc_lKernelInit(KernelPtr, (uint8)LoopCtr);
          }
        }

        LoopCtr++;

      } while (LoopCtr < ADC_MAX_KERNELS);
      #endif /* ( ADC_MASTER_SLAVE_SYNC == STD_ON ) */

      #if (ADC_CCU6_SYNCHRONIZATION  == STD_OFF)
      /***** Start: Wrokaround for Cross coupling effect *****/
      /* Disable ADC Module */
      ClcStatus = Adc_lInitWriteClcSfr((uint32)ADC_MODULE_DISABLE, \
                                                               ADC_SID_INIT);

      #if (IFX_ADC_DEBUG_CLC_DISABLE  == STD_ON)
      /* Debug variable to set the ClcStatus value to 0,
         to cover the false condition */
      ClcStatus &= TestAdc_DebugVarClc;
      #endif

      if(ClcStatus != 0U)
      {
        /* Enable ADC module, and Configure ADC Module Sleep mode */
        SfrValue = (uint32)\
                   ( ADC_MODULE_ENABLE | \
                      ((uint32)Adc_kConfigPtr->SleepMode << ADC_EDIS_BIT_POS)\
                   );
        ClcStatus = Adc_lInitWriteClcSfr(SfrValue, ADC_SID_INIT);
      }

      /***** End: Wrokaround for Cross coupling effect *****/
      #else /* (ADC_CCU6_SYNCHRONIZATION  == STD_ON) */
      /***** Start: Wrokaround for Cross coupling effect with Metal Fix *****/

      ClcStatus = Adc_lCcu6Init();

      /***** End: Wrokaround for Cross coupling effect with Metal Fix *****/
      #endif /* (ADC_CCU6_SYNCHRONIZATION  == STD_OFF) */

      if(ClcStatus != 0U)
      {
        /* Start of Start-Up calibration */
        /* This should be done after reset before starting the 
           first conversion to reduce analog errors.
        */
        ADC_SFR_INIT_USER_MODE_MODIFY32( \
             (ADC_MODULE_GLOB.GLOBCFG.U),ADC_GLOBCFG_SFR_MSK,\
             ((uint32)IFX_VADC_GLOBCFG_SUCAL_MSK << IFX_VADC_GLOBCFG_SUCAL_OFF))

        #if (ADC_RESULT_POLLING_MODE == STD_OFF)
        /* Priorities will be set by OS */

        /* ADC HW Unit Service Request Control Register.
        One set of SRN Available for all ADC Kernel
        Service request enable bit settings
        */
        Adc_lInitSetResetSre(ADC_ENABLE_INTERRUPT);
        #endif /* (ADC_RESULT_POLLING_MODE == STD_OFF) */

        /*------------------------------------**
        ** Initialize module global variable  **
        **------------------------------------*/
        Adc_lInitGlobalVariables();

        /*-------------------------------------------**
        ** Store the configuration structure pointer **
        **-------------------------------------------*/
        #if (ADC_DEV_ERROR_DETECT == STD_ON)
        /* Set Status to indicate that initialization is done */
        Adc_InitStatus = ADC_INITIALIZED;
        #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
      }
    }
  }
  return;
}/* Adc_Init */


/* ADC SRN0 is used by request source 0 of ADC kernel*/
#if (ADC_REQSRC0 == ADC_REQSRC_USED)
/*******************************************************************************
** Traceabilty      :[cover parentID=DS_MCAL_ADC_0402_1]
** Syntax           : void Adc_IsrSrn0AdcRS0(uint8 AdcKernel)                 **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function                                           **
**  - Handles the interrupts from ADC kernel Request source 0                 **
**  - Must be called in ISR of ADC_SRC0                                       **
**                                                                            **
*******************************************************************************/
void Adc_IsrSrn0AdcRS0(uint8 AdcKernel)
{
  /* Check if the interrupt is by Kernel RS0 */
  if ( (Adc_lReadSrcEvntFlagSfr(AdcKernel,ADC_REQSRC0_EVENT_OCCURED)) \
                                               == ADC_REQSRC0_EVENT_OCCURED )
  {
    Adc_lIsr(AdcKernel, ADC_REQSRC0_8STG_QUE);
  }
  #if (ADC_SAFETY_ENABLE == STD_ON)
  else
  {
    /* Report an safety error */
    SafeMcal_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE,
                          ADC_SID_ISR, ADC_E_INTR_SRC_ERROR
                        );
  }
  #endif /* (ADC_SAFETY_ENABLE == STD_ON) */

  return;
}/* Adc_IsrSrn0AdcRS0 */
#endif /* ADC_REQSRC0 */

/* ADC SRN1 is used by request source 1 of ADC kernel */
#if (ADC_REQSRC1 == ADC_REQSRC_USED)
/*******************************************************************************
** Traceabilty      :[cover parentID=DS_MCAL_ADC_0402_2]
** Syntax           : void Adc_IsrSrn1AdcRS1(uint8 AdcKernel)                 **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters (in)  : AdcKernel number                                        **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function                                           **
**  - Handles the interrupts from ADC kernel Request source 1                 **
**  - Must be called in ISR of ADC_SRC1                                       **
**                                                                            **
*******************************************************************************/
void Adc_IsrSrn1AdcRS1(uint8 AdcKernel)
{

  if ( (Adc_lReadSrcEvntFlagSfr(AdcKernel,ADC_REQSRC1_EVENT_OCCURED)) \
                                               == ADC_REQSRC1_EVENT_OCCURED )
  {
    Adc_lIsr(AdcKernel, ADC_REQSRC1_NCH_SCAN);
  }
  #if (ADC_SAFETY_ENABLE == STD_ON)
  else
  {
    /* Report an safety error */
    SafeMcal_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE,
                          ADC_SID_ISR, ADC_E_INTR_SRC_ERROR
                        );
  }
  #endif /* (ADC_SAFETY_ENABLE == STD_ON) */

  return;
}/* Adc_IsrSrn1AdcRS1 */
#endif /* ADC_REQSRC1 */

/* ADC SRN2 is used by request source 2 of All ADC kernels */
#if ( (ADC0_REQSRC2 == ADC_REQSRC_USED) || (ADC1_REQSRC2 == ADC_REQSRC_USED)||\
      (ADC2_REQSRC2 == ADC_REQSRC_USED) || (ADC3_REQSRC2 == ADC_REQSRC_USED)||\
      (ADC4_REQSRC2 == ADC_REQSRC_USED) || (ADC5_REQSRC2 == ADC_REQSRC_USED)||\
      (ADC6_REQSRC2 == ADC_REQSRC_USED) || (ADC7_REQSRC2 == ADC_REQSRC_USED)||\
      (ADC8_REQSRC2 == ADC_REQSRC_USED) || (ADC9_REQSRC2 == ADC_REQSRC_USED)||\
      (ADC10_REQSRC2 == ADC_REQSRC_USED) )
/*******************************************************************************
** Syntax           : void Adc_IsrSrn0CG0AdcRS2(void)                         **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non reentrant                                           **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function                                           **
**  - Handles the interrupts from All ADC kernal's Request source 2           **
**  - Must be called in ISR of Shared service request line 0 of CG0           **
**                                                                            **
*******************************************************************************/
void Adc_IsrSrn0CG0AdcRS2(void)
{
  Adc_GlobalDataType *DataPtr;
  uint32 LoopCtr;
  
  LoopCtr = 0U;
  
  if((Adc_lReadGlobEvntFlagSfr(ADC_REQSRC2_EVENT_OCCURED) ) \
                                              == ADC_REQSRC2_EVENT_OCCURED)
  {
    do
    {
      if(Adc_lBackgndScanConfigured((uint8)LoopCtr) != 0U)
      {
        /* Get ADC Kernel index for variables */
        /* Assign the address of ASIL or QM signal variable to global data
           pointer */
        DataPtr = Adc_lGetDataAddress((uint8)LoopCtr);
        
        /* If Trigger service request is not been disabled, then service the 
           ISR Else return with out any action
        */
        if (DataPtr->TriggSrcData[ADC_REQSRC2_BGND_SCAN].IsrDoNothing 
             != ADC_NO_SERVICE
           )
        {
          Adc_lIsr((uint8)LoopCtr, ADC_REQSRC2_BGND_SCAN);
        }
      }
    
      LoopCtr++;
      
    } while (LoopCtr < ADC_MAX_KERNELS);
    
  }
  
  return;
}/* Adc_IsrSrn0AdcRS2 */
#endif

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/*******************************************************************************
** Traceabilty      :[cover parentID=DS_MCAL_ADC_0402_3]
** Syntax           : void Adc_IsrSrn2AdcChEvnt(uint8 AdcKernel)              **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters (in)  : AdcKernel number                                        **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function                                           **
**  - Handles the interrupts from ADC Channel Event                           **
**  - Must be called in ISR of ADC SRN2                                       **
**                                                                            **
*******************************************************************************/
void Adc_IsrSrn2AdcChEvnt(uint8 AdcKernel)
{

  if(Adc_lReadChEvntFlagSfr(AdcKernel) != 0U)
  {
    /* Clear the Channel register event flag */
    Adc_lWriteChEvntClrFlagSfr(AdcKernel, ADC_CHANNEL_EVENT_CLEAR);
    Adc_lIsrLimitCheck(AdcKernel);
  }
  #if (ADC_SAFETY_ENABLE == STD_ON)
  else
  {
    /* Report an safety error */
    SafeMcal_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE,
                          ADC_SID_ISR, ADC_E_INTR_SRC_ERROR
                        );
  }
  #endif /* (ADC_SAFETY_ENABLE == STD_ON) */

  return;
}/* Adc_IsrSrn2AdcChEvnt */

#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */

#if (ADC_INITCHECK_API == STD_ON)
/*******************************************************************************
** Traceabilty      :[cover parentID=DS_MCAL_ADC_0400,DS_MCAL_ADC_0403,
DS_MCAL_ADC_0401_0447,DS_MCAL_ADC_0403]                                       **
** Syntax           : Std_ReturnType Adc_InitCheck                            **
**                    (                                                       **
**                      const Adc_ConfigType *ConfigPtr                       **
**                    )                                                       **
**[/cover]                                                                    **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK - Initialization comparison successful             **
**                   E_NOT_OK - Initialization not properly done by ADC driver**
**                                                                            **
** Description      : This function checks is the initialization of the       **
**                    ADC hardware unit and driver done according to the      **
**                    configuration set referenced by ConfigPtr.              **
**                                                                            **
*******************************************************************************/
Std_ReturnType Adc_InitCheck( const Adc_ConfigType *ConfigPtr )
{
  const Adc_KernelConfigType  *KernelPtr;
  uint32                      LoopCtr;
  uint32                      ReadValue;
  volatile uint32             CompareValue;
  uint32                      ConfigValue;
  Std_ReturnType              RetVal;

  CompareValue = ADC_INITCHK_COMP_VALUE;
  RetVal = E_NOT_OK;
  
  if ( Adc_kConfigPtr == ConfigPtr )
  {
    RetVal = E_OK;
  
    /* To avoid multiple if conditions, storing in CompareFlag */
    /* Comparison to be done for initialization done by Adc_Init() */   

    /* Checking CLC register */
    ReadValue = (uint32)(ADC_SFR_INIT_USER_MODE_READ32(ADC_MODULE_GLOB.CLC.U) &\
                        ((uint32)IFX_VADC_CLC_DISR_MSK<<IFX_VADC_CLC_DISR_OFF));
    CompareValue &= (ReadValue ^ ~((uint32)0));
    
    ReadValue = (uint32)(ADC_SFR_INIT_USER_MODE_READ32(ADC_MODULE_GLOB.CLC.U) &\
                        ((uint32)IFX_VADC_CLC_EDIS_MSK<<IFX_VADC_CLC_EDIS_OFF));
    ReadValue = (uint32)(ReadValue >> IFX_VADC_CLC_EDIS_OFF);
    CompareValue &= (ReadValue ^ ~((uint32)Adc_kConfigPtr->SleepMode));
    
    /* Checking GLOBCFG register */
    
    ConfigValue = (uint32) ( ADC_DCMSB_BIT_VALUE | \
                             (Adc_kConfigPtr->GlobCfgPtr->ClkPrescale) | \
                             (Adc_kConfigPtr->GlobCfgPtr->RefPrechargeCtrl) | \
                             (Adc_kConfigPtr->GlobCfgPtr->LowPowerSupply) | \
                             (Adc_kConfigPtr->GlobCfgPtr->PostCalEnable) \
                           );

    ReadValue = (uint32)(
                      ADC_SFR_INIT_USER_MODE_READ32(ADC_MODULE_GLOB.GLOBCFG.U));

    CompareValue &= (ReadValue ^ (~(ConfigValue & ADC_GLOBCFG_SFR_MSK)));

    /* Checking GLOBICLASS register */
    LoopCtr = 0U;
    do
    {
      ReadValue = (uint32)(ADC_SFR_INIT_USER_MODE_READ32( \
                             ADC_MODULE_GLOB.GLOBICLASS[LoopCtr].U));

      CompareValue &= (ReadValue ^ ( \
               ~((uint32)Adc_kConfigPtr->GlobCfgPtr->GlobInputClass[LoopCtr])));
      
      LoopCtr++;
    } while (LoopCtr < ADC_NO_GLOB_INP_CLASS);

    /* Checking GLOBEVNP register */
    ReadValue = (uint32)(
                     ADC_SFR_INIT_USER_MODE_READ32(ADC_MODULE_GLOB.GLOBEVNP.U));
    CompareValue &= (ReadValue ^ (~(uint32)(ADC_RS2_NODEPOINTER)));

    #if(ADC_USE_EMUX == STD_ON)
  
    /* Checking EMUXSEL register */
    ReadValue = (uint32)(
                      ADC_SFR_INIT_USER_MODE_READ32(ADC_MODULE_GLOB.EMUXSEL.U));
    CompareValue &= (ReadValue ^ ( \
                         ~(uint32)(Adc_kConfigPtr->GlobCfgPtr->EmuxSelectGrp)));

    #endif /* (ADC_USE_EMUX == STD_ON) */

    /* Checking Kernel specific registers */
    LoopCtr = 0U;
    do
    {
      if(Adc_lKernelConfigured((uint8)LoopCtr) != 0U)
      {
        /* Assign the ADC Kernel Configuration pointer to the local pointer */
        KernelPtr = Adc_kConfigPtr->CfgPtr[LoopCtr];
          
        /* Initialise ADC Kernels */
        if( Adc_lKernelInitCheck(KernelPtr, (uint8)LoopCtr) != E_OK )
        {
          RetVal = E_NOT_OK;
        }
      }
    
      LoopCtr++;
      
    } while (LoopCtr < ADC_MAX_KERNELS);
    
    #if (ADC_CCU6_SYNCHRONIZATION == STD_ON)
    if( Adc_lCcu6InitCheck() != E_OK )
    {
      RetVal = E_NOT_OK;
    }
    #endif /* (ADC_CCU6_SYNCHRONIZATION == STD_ON) */
    
    #if (ADC_RESULT_POLLING_MODE == STD_OFF)
    if( Adc_lSetSreCheck() != E_OK )
    {
      RetVal = E_NOT_OK;
    }
    #endif /* (ADC_RESULT_POLLING_MODE == STD_OFF) */
    
    if( Adc_lInitGlobalVarCheck() != E_OK )
    {
      RetVal = E_NOT_OK;
    }
    
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    /* Checking Adc_InitStatus variable */
    CompareValue &= (((uint32)Adc_InitStatus) ^ (~(uint32)(ADC_INITIALIZED)));

    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */   
    

    if ( (CompareValue != ADC_INITCHK_COMP_VALUE) || (RetVal != E_OK) )
    {
      RetVal = E_NOT_OK;
    }
  }
  return(RetVal);
} /* Adc_InitCheck */
#endif /* (ADC_INITCHECK_API == STD_ON) */

#if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
/*******************************************************************************
** Syntax           :  void Adc_lRSInterruptHandler                           **
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
void Adc_lRSInterruptHandler(uint8 AdcKernel, Adc_GroupType Group)
{
  Adc_GlobalDataType      *DataPtr;
  const Adc_GroupCfgType  *GrpPtr;
  #if (ADC_ENABLE_QUEUING == STD_ON)
  Adc_GroupType           PopGrpId;
  #endif /* (ADC_ENABLE_QUEUING == STD_ON) */
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

    #if (ADC_SAME_CHANNEL_QUEUING == STD_ON)
    if (GrpRequestSrc == ADC_REQSRC0_8STG_QUE) 
    {
      /* Insted of Dummy read, Clear result valid flag */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].VFR.U,\
                                (uint32)GrpPtr->IntChMask);
    }
    #endif /* (ADC_SAME_CHANNEL_QUEUING == STD_ON) */

    #if (ADC_USE_EMUX == STD_ON)
    if (DataPtr->EmuxGroup == Group)
    {
      /* Reset ADC EMUXCTR register */
      Adc_lWriteEmuxCtrSfr(AdcKernel, 0U);
      
      /* Reset Emux variable */
      DataPtr->EmuxGroup = ADC_INVALID_GROUP_ID;
    }
    #endif /* (ADC_USE_EMUX == STD_ON) */

    /* Full priority considered */
    #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)
    /* Call to schedule next group */
    Adc_lScheduleNext(AdcKernel,GrpRequestSrc);
    #endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) */

    /* Queue Enable is STD_ON only during No priority */
    #if (ADC_ENABLE_QUEUING == STD_ON)

    Adc_lRemoveFromQueue(DataPtr,Group);
    
    PopGrpId = DataPtr->PopGroupId;

    if (PopGrpId != ADC_INVALID_GROUP_ID)
    {
      /* The Previous Group pointer of Group which is for scheduling has to
         be reset to invalid 
      */
      DataPtr->QueueOfSwGroup[PopGrpId].PreviousGroup = 
                                                       ADC_INVALID_GROUP_ID;

      /* Schedule the next Group conversion pointed by Pop index */
      Adc_lScheduleFromQueue(AdcKernel);
    }
    else/* If Pop Group ID is invalid, then there is no Group in the Queue,
           Reset Push Group Id to invalid */
    {
      DataPtr->PushGroupId = ADC_INVALID_GROUP_ID;
    }
    #endif /* (ADC_ENABLE_QUEUING == STD_ON) */

  }/* Oneshot conversion mode */
  else
  {
    /* Continuous Mode - Single result access will be default Circular buffer */
    /* So, check for only linearity */
    if (GrpPtr->StreamBufferMode == ADC_STREAM_BUFFER_LINEAR)
    {
      /* Streaming and Liner buffer mode considered */
      
      /* No. of conversion reaches no. of samples configured */
      if (Adc_lGetResBuffEndStatus(DataPtr,Group))
      {
        /*---------------------**
        ** Stop the conversion **
        **---------------------*/

        /* ADC316: The ADC Driver stops the conversion as soon as the
           stream buffer is full (number of samples reached).
           - for Liner buffer
        */
        /* Note: Need to set the Trigger source stop flag
        */
        DataPtr->TriggSrcData[GrpRequestSrc].IsrDoNothing = ADC_NO_SERVICE;
        
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

        Adc_lSetGroupStatusIdleAtomic(DataPtr,Group);

        /* Reset HW Trigger source data and Adc_AllRunningCh */
        Adc_lResetTrigSrcData(GrpPtr,DataPtr);

        /* Full priority considered */
        #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)
        /* Call to schedule next group */
        Adc_lScheduleNext(AdcKernel,GrpRequestSrc);
        #endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) */
        
        /* Queue Enable is STD_ON only during No priority */
        #if (ADC_ENABLE_QUEUING == STD_ON)
        
        Adc_lRemoveFromQueue(DataPtr,Group);
        
        PopGrpId = DataPtr->PopGroupId;
        
        if (PopGrpId != ADC_INVALID_GROUP_ID)
        {
          /* The Previous Group pointer of Group which is for 
             scheduling has to be reset to invalid 
          */
          DataPtr->QueueOfSwGroup[PopGrpId].PreviousGroup = 
                                                        ADC_INVALID_GROUP_ID;
        
          /* Schedule the next Group conversion pointed by Pop index */
          Adc_lScheduleFromQueue(AdcKernel);
        }
        else/* If Pop Group ID is invalid, then there is no Group 
               in the Queue, Reset Push Group Id to invalid */
        {
          DataPtr->PushGroupId = ADC_INVALID_GROUP_ID;
        }
        #endif /* (ADC_ENABLE_QUEUING == STD_ON) */
      }/* No. of conversion reaches no. of samples configured */
      else
      {
        #if (ADC_SAME_CHANNEL_QUEUING == STD_ON)
        if (GrpRequestSrc == ADC_REQSRC0_8STG_QUE)  
        {
          /* Insted of Dummy read, Clear result valid flag */
          /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to 
          efficiently access the SFRs of multiple ADC kernels*/
          ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].VFR.U,\
                                  (uint32)GrpPtr->IntChMask);
        }
        #endif /* (ADC_SAME_CHANNEL_QUEUING == STD_ON) */
      }
    }/* Streaming and Liner buffer mode considered */
  }/* Continuous conversion mode */

} /* Adc_lRSInterruptHandler */
#endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */


/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#if (ADC_INITCHECK_API == STD_ON)

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE Std_ReturnType Adc_lKernelInitCheck    **
**                    (                                                       **
**                       const Adc_KernelConfigType  *AdcKernelPtr,           **
**                       uint8 AdcKernel                                      **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : AdcKernelPtr - Kernel cfg ptr ,                         **
**                    AdcKernel - kernel to be initialised                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Std_ReturnType                                          **
**                                                                            **
** Description      : Is called from Adc_InitCheck to check the initialization**
                      is done properly for the kernel specific register       **
*******************************************************************************/
IFX_LOCAL_INLINE Std_ReturnType Adc_lKernelInitCheck
(
  const Adc_KernelConfigType  *AdcKernelPtr,
  uint8 AdcKernel
)
{
  #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
  Adc_GlobalDataType      *DataPtr;
  #endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */
  const Adc_HwUnitCfgType *HwCfgPtr;
  uint32                  LoopCtr;
  uint32                  ReadValue;
  volatile uint32         CompareValue;
  uint32                  ConfigValue;
  uint32                  OpMode;
  Std_ReturnType          RetVal;


  CompareValue = ADC_INITCHK_COMP_VALUE;
  RetVal = E_NOT_OK;
  /* Get ADC kernel HW Unit Config pointer */
  HwCfgPtr = AdcKernelPtr->HwCfgPtr;
  /* Reading converter operation mode */
  OpMode = (uint32)(Adc_kConfigPtr->GlobCfgPtr->OperationMode);
  /* Checking ARBCFG register */
  ConfigValue = (uint32)((HwCfgPtr->ArbitrationLength) | (OpMode) | \
                         (ADC_CALS_BIT_VAL) | (OpMode << ADC_ANONS_BIT_POS) \
                        );
  /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently 
  access the SFRs of multiple ADC kernels*/
  ReadValue = (uint32)(
              (ADC_SFR_INIT_USER_MODE_READ32(ADC_MODULE[AdcKernel].ARBCFG.U)) &\
                                                               ADC_ARBCFG_MASK);
  CompareValue &= (ReadValue ^ (~(uint32)(ConfigValue)));

  /* Checking ARBPR register */
  ConfigValue = (uint32)( (HwCfgPtr->TriggSrcArbLevel) | \
                          (ADC_REQSRC_ARB_ENABLE << ADC_REQ_ARB_SLOT_SHIFT) \
                        );
  /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently 
  access the SFRs of multiple ADC kernels*/
  ReadValue = (uint32)(
                  ADC_SFR_INIT_USER_MODE_READ32(ADC_MODULE[AdcKernel].ARBPR.U));
  CompareValue &= (ReadValue ^ (~(uint32)(ConfigValue)));

  /* Checking the 2 kernel Input class registers */
  LoopCtr = (uint32)0;
  do
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently 
    access the SFRs of multiple ADC kernels*/
    ReadValue = (uint32)(ADC_SFR_INIT_USER_MODE_READ32(\
                              ADC_MODULE[AdcKernel].ICLASS[LoopCtr].U));
    CompareValue &= (ReadValue ^ ( \
                              ~(uint32)(HwCfgPtr->KernelInputClass[LoopCtr])));
    
    LoopCtr++;
  } while (LoopCtr < ADC_NO_KERNEL_INP_CLASS);

  #if( ADC_MASTER_SLAVE_SYNC == STD_ON )
  /* Checking SYNCTR register */
  ConfigValue = (uint32)((uint32)HwCfgPtr->SyncConvMode | \
                                                 (uint32)HwCfgPtr->SlaveReady);
  /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently 
  access the SFRs of multiple ADC kernels*/
  ReadValue = (uint32)(
                 ADC_SFR_INIT_USER_MODE_READ32(ADC_MODULE[AdcKernel].SYNCTR.U));
  CompareValue &= (ReadValue ^ (~(uint32)(ConfigValue)));

  #endif /* ( ADC_MASTER_SLAVE_SYNC == STD_ON ) */

  /* Checking SEVNP register */
  /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently 
  access the SFRs of multiple ADC kernels*/
  ReadValue = (uint32)(
                 ADC_SFR_INIT_USER_MODE_READ32(ADC_MODULE[AdcKernel].SEVNP.U));
  CompareValue &= (ReadValue ^ (~(uint32)(ADC_RS0_RS1_NODEPOINTER)));

  #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)

  /* Get ADC Kernel index for variables */
  /* Assign the address of ASIL or QM signal variable to global data pointer*/
  DataPtr = Adc_lGetDataAddress(AdcKernel);

  /* Initialisation of ADC0 Global variable */
  LoopCtr = (uint32)0;
  #if (ADC_MAX_GROUPS > 1U)
  do
  #endif /* loop only when (ADC_MAX_GROUPS > 1U) */
  {
    /* Checking the variable which holds the number of conversion result  */
    ReadValue = (uint32)DataPtr->NumValidConRes[LoopCtr];
    CompareValue &= (ReadValue ^ (~(uint32)0));

    #if (ADC_MAX_GROUPS > 1U)
    LoopCtr++;
    #endif 
  }
  #if (ADC_MAX_GROUPS > 1U)
  while (LoopCtr < ADC_MAX_GROUPS);
  #endif /* loop only when (ADC_MAX_GROUPS > 1U) */
  
  #endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */
  
  if (CompareValue == ADC_INITCHK_COMP_VALUE)
  {
    RetVal = E_OK;
  }

  return(RetVal);
} /* Adc_lKernelInitCheck */

#if (ADC_RESULT_POLLING_MODE == STD_OFF)
/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE Std_ReturnType Adc_lSetSreCheck        **
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
** Return value     : Std_ReturnType                                          **
**                                                                            **
** Description      : Is called from Adc_InitCheck to check that              **
**                    initialization done properly for SRE bit of SRC register**
*******************************************************************************/
IFX_LOCAL_INLINE Std_ReturnType Adc_lSetSreCheck(void)
{
  uint32                  LoopCtr;
  uint32                  ReadValue;
  volatile uint32         CompareValue;
  #if ( ADC_GROUP_EMUX_SCAN == STD_ON )
  uint32                  EmuxKernel;
  uint16                  AdcKernel;
  #endif /* ( ADC_GROUP_EMUX_SCAN == STD_ON ) */
  Std_ReturnType          RetVal;

  CompareValue = ADC_INITCHK_COMP_VALUE;
  RetVal = E_NOT_OK;
  LoopCtr = 0U;
  do
  {
    if(Adc_lQueueRSConfigured((uint8)LoopCtr) != 0U)
    {
      /* Checking ADC SRN0 register */
      ReadValue = (uint32)(((uint32)ADC_SFR_INIT_USER_MODE_READ32( \
                              MODULE_SRC.VADC.G[LoopCtr].SR0.U)) & \
                    ((uint32)IFX_SRC_SRCR_SRE_MSK << IFX_SRC_SRCR_SRE_OFF));
      ReadValue =  (uint32)(ReadValue >> IFX_SRC_SRCR_SRE_OFF);
      CompareValue &= (ReadValue ^ (~(uint32)(1)));
    }
  
    LoopCtr++;
    
  } while (LoopCtr < ADC_MAX_KERNELS);
  
  LoopCtr = 0U;
  do
  {
    if(Adc_lAutoScanConfigured((uint8)LoopCtr) != 0U)
    {
      /* Checking ADC SRN1 register */
      ReadValue = (uint32)(((uint32)ADC_SFR_INIT_USER_MODE_READ32( \
                                MODULE_SRC.VADC.G[LoopCtr].SR1.U)) &  \
                    ((uint32)IFX_SRC_SRCR_SRE_MSK << IFX_SRC_SRCR_SRE_OFF));
      ReadValue =  (uint32)(ReadValue >> IFX_SRC_SRCR_SRE_OFF);
      CompareValue &= (ReadValue ^ (~(uint32)(1)));
    }
  
    LoopCtr++;
    
  } while (LoopCtr < ADC_MAX_KERNELS);
  
  #if (ADC_REQSRC2 == ADC_REQSRC_USED)
  
  /* Checking ADC Common Group 0 SRN0 register */
  ReadValue = (uint32)(((uint32)ADC_SFR_INIT_USER_MODE_READ32(  \
                                MODULE_SRC.VADC.CG[0].SR0.U)) & \
                        ((uint32)IFX_SRC_SRCR_SRE_MSK << IFX_SRC_SRCR_SRE_OFF));
  ReadValue =  (uint32)(ReadValue >> IFX_SRC_SRCR_SRE_OFF);
  CompareValue &= (ReadValue ^ (~(uint32)(1)));
  
  #endif /* (ADC_REQSRC2 is used) */
  
  #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
  
  LoopCtr = 0U;
  do
  {
    if(Adc_lLimitChkConfigured((uint8)LoopCtr) != 0U)
    {
      /* Checking ADC SRN2 register */
      ReadValue = (uint32)(((uint32)ADC_SFR_INIT_USER_MODE_READ32(  \
                                  MODULE_SRC.VADC.G[LoopCtr].SR2.U)) & \
                        ((uint32)IFX_SRC_SRCR_SRE_MSK << IFX_SRC_SRCR_SRE_OFF));
      ReadValue =  (uint32)(ReadValue >> IFX_SRC_SRCR_SRE_OFF);
      CompareValue &= (ReadValue ^ (~(uint32)(1)));
    }
  
    LoopCtr++;
    
  } while (LoopCtr < ADC_MAX_KERNELS);
  
  #endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  
  if (CompareValue == ADC_INITCHK_COMP_VALUE)
  {
    RetVal = E_OK;
  }
    
  return(RetVal);
} /* Adc_lSetSreCheck */
#endif /* (ADC_RESULT_POLLING_MODE == STD_OFF) */

#if (ADC_CCU6_SYNCHRONIZATION == STD_ON)
/*******************************************************************************
** Syntax           : static Std_ReturnType Adc_lCcu6InitCheck                **
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
** Return value     : Std_ReturnType                                          **
**                                                                            **
** Description      : Is called from InitCheck to validate the initialisation **
**                    of the CCU6 module                                      **
*******************************************************************************/
static Std_ReturnType Adc_lCcu6InitCheck(void)
{
  volatile Ifx_CCU6 *Ccu6BaseRegPtr;/* Variable to hold the CCU6 base address */
  volatile Ifx_CCU6 *Ccu6RegPtr; /* Variable to hold the current CCU6 address */
  volatile uint32   CompareValue;
  uint32            ConfigValue;
  uint32            ReadValue;
  Std_ReturnType    RetVal;

  CompareValue = ADC_INITCHK_COMP_VALUE;
  RetVal = E_NOT_OK;
  
  Ccu6BaseRegPtr = &MODULE_CCU60;
  /* Get the base address of the Kernal */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
  PBConfigStructure and is within allowed range*/
  Ccu6RegPtr = Ccu6BaseRegPtr + (Adc_kConfigPtr->GlobCfgPtr->Ccu6Kernel);

  /* Checking CLC register */
  ReadValue = (uint32)(ADC_SFR_INIT_USER_MODE_READ32(Ccu6RegPtr->CLC.U));
  CompareValue &= (ReadValue ^ (~(uint32)(0)));
  /* Checking the 20MHz clock period */
  ReadValue = (uint32)(ADC_SFR_INIT_USER_MODE_READ32(Ccu6RegPtr->T13PR.U));
  ConfigValue = (uint32)Adc_kConfigPtr->GlobCfgPtr->PeriodValue;
  CompareValue &= (ReadValue ^ (~(uint32)(ConfigValue)));
  /* Checking duty cycle value */
  ReadValue = (uint32)(ADC_SFR_INIT_USER_MODE_READ32(Ccu6RegPtr->CC63SR.U));
  ConfigValue = (uint32)Adc_kConfigPtr->GlobCfgPtr->DutyValue;
  CompareValue &= (ReadValue ^ (~(uint32)(ConfigValue)));
  ReadValue = (uint32)((ADC_SFR_INIT_USER_MODE_READ32(Ccu6RegPtr->PSLR.U)) \
                                                       & ADC_CCU6_PSLR_VAL);
  CompareValue &= (ReadValue ^ (~(uint32)(ADC_CCU6_PSLR_VAL)));
  /* Checking MODCTR value */
  ReadValue = (uint32)((ADC_SFR_INIT_USER_MODE_READ32(Ccu6RegPtr->MODCTR.U)) \
                                                       & ADC_CCU6_MODCTR_VAL);
  CompareValue &= (ReadValue ^ (~(uint32)(ADC_CCU6_MODCTR_VAL)));
  /* Checking Divider values of T13 input clock */
  ReadValue = (uint32)((ADC_SFR_INIT_USER_MODE_READ32(Ccu6RegPtr->TCTR0.U)) \
                                                    & ADC_TCTR0_SFR_CHK_MSK);
  ConfigValue = (uint32)(Adc_kConfigPtr->GlobCfgPtr->T13Clock | \
                                                        ADC_TCTR0_T13R_MASK);
  CompareValue &= (ReadValue ^ (~(uint32)(ConfigValue)));
  /* TCTR4 is write only register, hence not checked  */
  /* CCU60_COUT63 routed to output signal CCU6061 TRIG1 */
  ReadValue = (uint32)((ADC_SFR_INIT_USER_MODE_READ32(MODULE_CCU60.MOSEL.U)) \
                                                     & ADC_MOSEL_SFR_CHK_MSK);
  ConfigValue = (uint32)Adc_kConfigPtr->GlobCfgPtr->TrigSel;
  CompareValue &= (ReadValue ^ (~(uint32)(ConfigValue)));

  if (CompareValue == ADC_INITCHK_COMP_VALUE)
  {
    RetVal = E_OK;
  }

  return(RetVal);
} /* Adc_lCcu6InitCheck */
#endif /* (ADC_CCU6_SYNCHRONIZATION == STD_ON) */

#endif /* (ADC_INITCHECK_API == STD_ON) */

/*******************************************************************************
** Syntax           : void Adc_lAlignResultBuffer                             **
**                              (AdcKernel, Group, CurrentResBufPtr, ResVal)  **
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
**                    ResVal - Conversion result                              **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Local funtion :                                         **
**                    Align and Update the Group Result buffer on conversion  **
**                    complete                                                **
*******************************************************************************/
void Adc_lAlignResultBuffer
(
  uint8 AdcKernel, 
  Adc_GroupType Group,
  Adc_ValueGroupType *ResBufPtr, 
  uint32 ResVal
)
{
  #if( (ADC_SAME_CHANNEL_QUEUING == STD_ON) && \
                        (ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT) )
  const Adc_GroupCfgType    *GrpPtr;
  uint32                    GroupRs;

  /* Get the Group Config data pointer */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
  PBConfigStructure and is within allowed range*/
  GrpPtr = (Adc_kConfigPtr->CfgPtr[AdcKernel]->GrpCfgPtr) + Group;

  /* Get the Group RS */
  GroupRs = (uint32)(GrpPtr->GrpRequestSrc);
  #else
  
  /* to remove the unused param warning in GNU */
  UNUSED_PARAMETER(AdcKernel)
  UNUSED_PARAMETER(Group)
  
  #endif /*( ADC_SAME_CHANNEL_QUEUING == STD_ON )*/

  #if (ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT)  
  /* Update the conversion result into Result buffer */

  #if( ADC_SAME_CHANNEL_QUEUING == STD_ON )
  if(GroupRs == ADC_REQSRC0_8STG_QUE)
  {
    *ResBufPtr = (Adc_ValueGroupType)(ResVal);
  }
  else
  #endif /*( ADC_SAME_CHANNEL_QUEUING == STD_ON )*/
  {
    #if( ADC_VALUE_GROUP_TYPE == ADC_VALUE_SIXTEEN_BIT )

    /* Left shift by 4 bits to match the 16 bit data buffer */
    *ResBufPtr = (Adc_ValueGroupType)(ResVal << ADC_LEFT_ALIGN_SHIFT);

    #elif( ADC_VALUE_GROUP_TYPE == ADC_VALUE_EIGHT_BIT )

    /* Right shift by 4 bits to match the 8 bit data buffer */
    *ResBufPtr = (Adc_ValueGroupType)(ResVal >> ADC_LEFT_ALIGN_SHIFT);

    #endif /* ( ADC_VALUE_GROUP_TYPE == ADC_VALUE_SIXTEEN_BIT ) */
  }
  #endif /* (ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT) */

  #if (ADC_RESULT_ALIGNMENT == ADC_ALIGN_RIGHT) 

  *ResBufPtr = (Adc_ValueGroupType)(ResVal);

  #endif /* (ADC_RESULT_ALIGNMENT == ADC_ALIGN_RIGHT) */

} /* Adc_lAlignResultBuffer */

#if ( (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || \
                                               (ADC_HW_TRIGGER_API == STD_ON) )
/*******************************************************************************
** Traceabilty      :[cover parentID=DS_NAS_HE2_ADC_PR3034,DS_NAS_EP_ADC_PR3034,
                     DS_NAS_HE2_ADC_PR3036,DS_NAS_EP_ADC_PR3036]              **
** Syntax           : void Adc_lPrepareGrpForStart                            **
**                     (uint8 AdcKernel, Adc_GroupType GroupId)               **
**[/cover]                                                                    **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters(in)   : ADC Group ID of the Kernel                              **
**                    ADC Kernel for which the Grp belongs                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Local funtion :                                         **
**                    Service for preparing all the channels of the group for **
**                    conversion                                              **
**                    Update TriggSrcData for Group Id                        **
**                    Update for Adc_AllRunningCh                             **
*******************************************************************************/
void Adc_lPrepareGrpForStart
(
  uint8 AdcKernel,
  Adc_GroupType GroupId
)
{
  #if(((ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR) && \
       (ADC_RESULT_POLLING_MODE == STD_OFF)) || (ADC_USE_EMUX == STD_ON)\
                                          || (ADC_MASTER_SLAVE_SYNC == STD_ON) )
  Adc_GlobalDataType        *DataPtr;
  #endif
  const Adc_GroupCfgType    *GrpPtr;
  const Adc_GroupDefType    *ChIdxPtr;
  const Adc_ChannelCfgType  *ChCfgPtr;
  #if (ADC_GROUP_EMUX_SCAN == STD_ON)
  const Adc_HwUnitCfgType   *HwCfgPtr;
  #endif /* (ADC_GROUP_EMUX_SCAN == STD_ON) */
  #if (ADC_USE_EMUX == STD_ON)
  uint32                    EmuxSelect;
  uint32                    EmuxEnable;
  uint32                    SfrValue;
  #endif /* (ADC_USE_EMUX == STD_ON) */
  uint32                    NoOfChannels;
  uint32                    ChConfigData;
  #if (ADC_GROUP_EMUX_SCAN == STD_ON)
  uint32                    GrpNumOfSamples;
  uint32                    GrpEmuxScanFlag;
  Dma_ChannelType           AdcDmaChannel;
  #endif /* (ADC_GROUP_EMUX_SCAN == STD_ON) */
  Adc_ChannelType           IntChNr;
  Adc_ChannelType           ChIdx;
  #if(((ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR) && \
       (ADC_RESULT_POLLING_MODE == STD_OFF)) || (ADC_USE_EMUX == STD_ON)\
                                          || (ADC_MASTER_SLAVE_SYNC == STD_ON) )
                                           

  /* Get ADC Kernel index for variables */
  /* Assign the address of ASIL or QM signal variable to global data pointer*/
  DataPtr = Adc_lGetDataAddress(AdcKernel);
  #endif /* Non AUTOSAR result handling or use of EMUX */

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
  PBConfigStructure and is within allowed range*/
  GrpPtr = Adc_kConfigPtr->CfgPtr[AdcKernel]->GrpCfgPtr + GroupId;

  #if (ADC_USE_EMUX == STD_ON)
  /* Get Group EMUX Flag */
  EmuxEnable = (uint32)Adc_lGetEmuxEnable((uint32)GrpPtr->GroupEmuxData);

  #if (ADC_GROUP_EMUX_SCAN == STD_ON)
  HwCfgPtr = Adc_kConfigPtr->CfgPtr[AdcKernel]->HwCfgPtr;
  /* Initialise EmuxSelect variable to reset value */
  EmuxSelect = (uint32)0;
  /* Get Group EMUX Scan flag */
  GrpEmuxScanFlag = (uint32)Adc_lGetEmuxScan((uint32)GrpPtr->GroupEmuxData);
  #endif /* (ADC_GROUP_EMUX_SCAN == STD_ON) */
  #endif /* (ADC_USE_EMUX == STD_ON) */

  /* Get the starting address of the Channel configuration data structure 
     array */
  ChCfgPtr = Adc_kConfigPtr->CfgPtr[AdcKernel]->ChCfgPtr;
  
  /* Note: First element of the Group defination array will give the 
     no. of configured channels and the remaining elements will give 
     the channel ID 
  */
  
  /* Get the Group's number of configured channels */
  /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
  Group Configuration Structure and is within allowed range*/
  NoOfChannels = (uint32)(GrpPtr->GroupDefinition)[0];

  /* Get the Requested group's first channel Channels ID location */
  /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
  Group Configuration Structure and is within allowed range*/
  ChIdxPtr = &((GrpPtr->GroupDefinition)[1U]);
  
  #if( ADC_MASTER_SLAVE_SYNC == STD_ON )

  DataPtr->RsGroupData[GrpPtr->GrpRequestSrc].NoOfSynchCh = 0U;

  #endif /* ( ADC_MASTER_SLAVE_SYNC == STD_ON ) */
  
  /* ADC091: Group contains at least one channel */
  do
  {
    /* Get the First channel Index of the requested group and then increment 
       the pointer */
    ChIdx = *ChIdxPtr;
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    Channel Configuration Structure and is within allowed range*/
    ChIdxPtr++;
    
    /* Get the channel conf data for the channel index in group definition */
    /*IFX_MISRA_RULE_17_04_STATUS=Array indexting used due to 
    Channel Configuration Structure and is within allowed range*/
    ChConfigData = ChCfgPtr[ChIdx].AdcChConfigValue;

    /* Get the internal Channel number from the Channel configuration */
    IntChNr = (Adc_ChannelType)(Adc_lGetKernelChNum(ChConfigData));

    ChConfigData |= ((uint32)ADC_RESULT_ALIGNMENT << ADC_RESPOS_BIT_POS);
    /* Configure CHCTRx register with Inputclass selction, Reference voltage,
       Result register selction except Broken Wire Detection bitfields to allow 
       user to configure the BWD.
    */
    /*IFX_MISRA_RULE_17_04_STATUS=Array indexting is used to efficiently
    access the SFRs of multiple ADC kernels*/
    ADC_SFR_RUNTIME_USER_MODE_MODIFY32(ADC_MODULE[AdcKernel].CHCTR[IntChNr].U, \
                                 (uint32)ADC_CLR_CHCTR_EXCEPT_BWD, ChConfigData)

    #if((ADC_MASTER_SLAVE_SYNC == STD_ON) || (ADC_ENABLE_LIMIT_CHECK == STD_ON))
    
    Adc_lEnableSynchLimitChkCh(AdcKernel, GroupId, IntChNr, ChIdx);
    
    #endif 
    /*((ADC_MASTER_SLAVE_SYNC == STD_ON)||(ADC_ENABLE_LIMIT_CHECK == STD_ON))*/
    
    #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)

    #if (ADC_GROUP_EMUX_SCAN == STD_ON)
    /* If Group is of EMUX SCAN, Result register WFR mode is not set
       Note: As observed, DMA read from result register will 
       not be recognised as read by ADC HW and hence WFR is not set.
    */
    if (GrpEmuxScanFlag != (uint32)ADC_GROUP_EMUX_SCAN_ENABLE)
    #endif /* (ADC_GROUP_EMUX_SCAN == STD_ON) */
    {
      #if(ADC_ENABLE_LIMIT_CHECK == STD_ON)
      /* channel limit checking enabled */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
      Channel Configuration Structure and is within allowed range*/
      if(ChCfgPtr[ChIdx].AdcIsChLimitChkEnabled == 0U)
      #endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
      {
        /* The corresponding result registers are configurd for WFR mode */
        /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
        access the SFRs of multiple ADC kernels*/
        ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].RCR[IntChNr].U,\
                                                         ADC_RESREG_WFR_ENABLE);
      }
    }

    #else /* (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR) */
    /* If Group is one shot SW triggered, the result accumulation is none */
    if(!( (GrpPtr->ConvMode == ADC_CONV_MODE_ONESHOT) && 
          (GrpPtr->TriggSrc == ADC_TRIGG_SRC_SW)
        )
      )
    {
      /* initialise the Group for Data Accumulation */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].RCR[IntChNr].U, \
                                                      ADC_RESULT_ACCUMULATION);
    }
    else
    {
      /* initialise the Group for Data Reduction disabled */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(
                                      ADC_MODULE[AdcKernel].RCR[IntChNr].U, 0U);
    }
    #endif /* Check for Group result handling mode */

    /* Decrement the NoOfChannels by one */
    NoOfChannels--;

  } while (NoOfChannels > 0U);

  #if( (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR) && \
                                      (ADC_RESULT_POLLING_MODE == STD_OFF) )
  /* Get the Last (Lowest) channel Index of the requested group */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
  Channel Configuration Structure and is within allowed range*/
  ChIdxPtr--;
  ChIdx = *ChIdxPtr;
  /* Get the channel conf data for the channel index in group definition */
  /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
  Channel Configuration Structure and is within allowed range*/
  ChConfigData = ChCfgPtr[ChIdx].AdcChConfigValue;

  /* Get the internal Channel number from the Channel configuration */
  IntChNr = (Adc_ChannelType)(Adc_lGetKernelChNum((uint32)ChConfigData));
  
  /* Store the lowest channel number in Trigger source data variable */
  DataPtr->TriggSrcData[GrpPtr->GrpRequestSrc].GrpLastChannel = IntChNr;

  /* DMA is used to transfer the result from Res reg to driver buffer */
  Adc_lSetResEventNode(AdcKernel,(uint32)IntChNr);
  
  /* The corresponding result registers is enabled for result interrupt */
  /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
   access the SFRs of multiple ADC kernels*/
  ADC_SFR_RUNTIME_USER_MODE_MODIFY32(ADC_MODULE[AdcKernel].RCR[IntChNr].U,  \
                                                          ADC_RCR_SFR_MSK,  \
           ((uint32)ADC_ENABLE_RES_INTERRUPT << IFX_VADC_G_RCR_SRGEN_OFF))
  #endif /* (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR) */

  #if (ADC_USE_EMUX == STD_ON)
  if (EmuxEnable == (uint32)1)
  {
    /* Initialise the Emux data */
    DataPtr->EmuxGroup = GroupId;
  
    /* Get Group EMUX select value */
    EmuxSelect = (uint32)Adc_lGetEmuxSelect((uint32)GrpPtr->GroupEmuxData);

    /* EMUXWC = 1: EMXST = 1: */
    SfrValue = \
        (uint32)( (ADC_EMUX_CFG_WRITE_ENABLE) | (ADC_EMUX_STCE_EACH_CONV) | \
                  ((uint32)IntChNr << ADC_EMUXCH_BIT_POS) | (EmuxSelect) \
                );
    Adc_lWriteEmuxCtrSfr(AdcKernel, SfrValue);

    /* Mode(EMUXMODE)value is written after the EmuxSelect value is configured.
       values are repeated since the bitwise write is not supported 
       UTP AI00081746 */
    /* EMUXWC = 1: EMXST = 1: EMUXMODE = 1 */
    SfrValue = \
        (uint32)( (ADC_EMUX_CFG_WRITE_ENABLE) | (ADC_EMUX_STCE_EACH_CONV) | \
                  (ADC_EMUX_STEADY_MODE) | \
                  ((uint32)IntChNr << ADC_EMUXCH_BIT_POS) | (EmuxSelect) \
                );
    Adc_lWriteEmuxCtrSfr(AdcKernel, SfrValue);
  }

  #if (ADC_GROUP_EMUX_SCAN == STD_ON)

  if (GrpEmuxScanFlag == (uint32)ADC_GROUP_EMUX_SCAN_ENABLE)
  {
    /* Group is configured for EMUX Scan mode:
       For selected Group channel EMUX select value will decrement from
       programmed input down to input 0.
    */

    /* Updata Group of DmaData */
    Adc_lUpdateDmaData(AdcKernel,GroupId);

    /* Enable scan mode for ADC in EMUXCTR register */

    /* EMUXWC = 1: EMXST = 1 */
    SfrValue = \
          (uint32)( (ADC_EMUX_CFG_WRITE_ENABLE) | (ADC_EMUX_STCE_EACH_CONV) | \
                    ((uint32)IntChNr << ADC_EMUXCH_BIT_POS) | (EmuxSelect) \
                  );
    Adc_lWriteEmuxCtrSfr(AdcKernel, SfrValue);
    /* Mode(EMUXMODE)value is written after the EmuxSelect value is configured.
       values are repeated since the bitwise write is not supported 
       UTP AI00065618 */
    /* EMUXWC = 1: EMXST = 1: EMUXMODE = 2 */
    SfrValue = \
        (uint32)( (ADC_EMUX_CFG_WRITE_ENABLE) | (ADC_EMUX_STCE_EACH_CONV) | \
                  (ADC_EMUX_SINGLE_STEP_MODE) |  \
                  ((uint32)IntChNr << ADC_EMUXCH_BIT_POS) | (EmuxSelect) \
                );
    Adc_lWriteEmuxCtrSfr(AdcKernel, SfrValue);

    /* Number of results to be updated by DMA */
    /* Implicit num of channels = (EmuxSelect + 1U) */
    /* Adc_DmaUpdateCount is used in Adc_lDmaChInit fn for DMA initialization */
    GrpNumOfSamples = (uint32)GrpPtr->NumSamples;
    DataPtr->DmaData.DmaUpdateCount = 
                                 (uint32)((EmuxSelect + 1U) * GrpNumOfSamples);

    /* DMA is used to transfer the result from Res reg to driver buffer */
    /* Group with EMUX SCAN mode enabled will have only one channel 
       and hence last channel IntChNr is nothing but the channel 
       result register */
    AdcDmaChannel = (Dma_ChannelType)(HwCfgPtr->DmaChannel);
       
    Adc_lDmaChInit(AdcKernel,(uint32)IntChNr, AdcDmaChannel);

    Adc_lSetResEventNode(AdcKernel,(uint32)IntChNr);
    
    /* The corresponding result registers interrupt is enabled */
    /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
    access the SFRs of multiple ADC kernels*/
    ADC_SFR_RUNTIME_USER_MODE_MODIFY32(ADC_MODULE[AdcKernel].RCR[IntChNr].U,  \
                                                            ADC_RCR_SFR_MSK,  \
               ((uint32)ADC_ENABLE_RES_INTERRUPT << IFX_VADC_G_RCR_SRGEN_OFF))

  }
  #endif /* (ADC_GROUP_EMUX_SCAN == STD_ON) */

  #endif /* (ADC_USE_EMUX == STD_ON) */
  return;
}/* Adc_lPrepareGrpForStart */

#if( (ADC_MASTER_SLAVE_SYNC == STD_ON) || (ADC_ENABLE_LIMIT_CHECK == STD_ON) )
/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Adc_lEnableSynchLimitChkCh        **
**                     (uint8 AdcKernel, Adc_GroupType GroupId,               **
**                     Adc_ChannelType IntChNr, Adc_ChannelType ChIdx)        **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters(in)   : ADC Group ID of the Kernel                              **
**                    ADC Kernel for which the Grp belongs                    **
**                    Analog channel number                                   **
**                    Index of the channel configuration structure            **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Local funtion :                                         **
**                    Service for preparing the slave and limit checking      **
**                    channels of the group for conversion                    **
*******************************************************************************/
IFX_LOCAL_INLINE void Adc_lEnableSynchLimitChkCh
(
  uint8 AdcKernel,
  Adc_GroupType GroupId,
  Adc_ChannelType IntChNr,
  Adc_ChannelType ChIdx
)
{
  Adc_GlobalDataType          *DataPtr;
  const Adc_ChannelCfgType    *ChCfgPtr;

  #if (ADC_MASTER_SLAVE_SYNC == STD_ON) 
  const Adc_KernelConfigType  *KernelPtr;
  const Adc_GroupCfgType      *GrpPtr;
  const Adc_HwUnitCfgType     *HwCfgPtr;
  uint32                      ChConfigData;
  #endif /* ( ADC_MASTER_SLAVE_SYNC == STD_ON ) */
  #if(ADC_ENABLE_LIMIT_CHECK == STD_ON)
  uint32                      SfrValue;
  #endif/* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  #if (ADC_MASTER_SLAVE_SYNC == STD_ON) 
  uint8                       LoopCtr;
  uint8                       MaxKerCluster;
  #endif /* ( ADC_MASTER_SLAVE_SYNC == STD_ON ) */

  /* Get ADC Kernel index for variables */
  /* Assign the address of ASIL or QM signal variable to global data pointer*/
  DataPtr = Adc_lGetDataAddress(AdcKernel);

  /* Get the starting address of the Channel configuration data structure 
     array */
  ChCfgPtr = Adc_kConfigPtr->CfgPtr[AdcKernel]->ChCfgPtr;


  #if( ADC_MASTER_SLAVE_SYNC == STD_ON )
  
  HwCfgPtr = Adc_kConfigPtr->CfgPtr[AdcKernel]->HwCfgPtr;

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
  PBConfigStructure and is within allowed range*/
  GrpPtr = Adc_kConfigPtr->CfgPtr[AdcKernel]->GrpCfgPtr + GroupId;

  /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
  PBConfigStructure and is within allowed range*/
  if( (HwCfgPtr->SyncConvMode == ADC_MASTER) && 
      (ChCfgPtr[ChIdx].AdcSyncChannel == ADC_SYNC_CHANNEL)
    )
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
    access the SFRs of multiple ADC kernels*/
    ADC_SFR_RUNTIME_USER_MODE_MODIFY32(ADC_MODULE[AdcKernel].CHCTR[IntChNr].U, \
                                                            ADC_CHCTR_SFR_MSK, \
                      ((uint32)ADC_SYNC_CHANNEL << IFX_VADC_G_CHCTR_SYNC_OFF))

    /* increment and store the number of synch cannel variable */
    DataPtr->RsGroupData[GrpPtr->GrpRequestSrc].NoOfSynchCh++;
    
    LoopCtr = (AdcKernel / ADC_KERNELS_PER_SYNGRP) * ADC_KERNELS_PER_SYNGRP;
    MaxKerCluster = LoopCtr + ADC_KERNELS_PER_SYNGRP;
  
    /* if condtion is written because TC29x has 11 kernels */
    if(MaxKerCluster >= ADC_MAX_KERNELS)
    {
      MaxKerCluster = ADC_MAX_KERNELS;
    }
    
    do
    {
      KernelPtr = Adc_kConfigPtr->CfgPtr[LoopCtr];
      if(KernelPtr != NULL_PTR)
      {
        HwCfgPtr = KernelPtr->HwCfgPtr;
        
        if(HwCfgPtr->SyncConvMode != ADC_MASTER)
        {
          /* Get the channel conf data for the channel index in group 
             definition */


        	/*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to
        	          efficiently access the SFRs of multiple ADC kernels*/
        	          ADC_SFR_RUNTIME_USER_MODE_MODIFY32(  \
        	                                       ADC_MODULE[LoopCtr].CHCTR[IntChNr].U,\
        	                                (uint32)ADC_CLR_CHCTR_EXCEPT_BWD, ChConfigData)
        	          /* Modified by HU  Enable WFR, set Result accumulation times*/
        	          ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[LoopCtr].RCR[IntChNr].U, ChCfgPtr[ChIdx].AdcChResAccumulation);

        	        }
        	      }
        	      LoopCtr++;
      
    }while(LoopCtr < MaxKerCluster);
  }
  #endif /* ( ADC_MASTER_SLAVE_SYNC == STD_ON ) */
  
  /* limit checking enabled globally */
  #if(ADC_ENABLE_LIMIT_CHECK == STD_ON)
  
  /* channel limit checking enabled */
  /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used due to 
  Channel Configuration Structure and is within allowed range*/
  if(ChCfgPtr[ChIdx].AdcIsChLimitChkEnabled != 0U)
  {

    /* Upper and Lower Boundary values of Limit check.
       Concatenated values of BNDSELU and BNDSELL are used as Lower boundary
       when the Result register is selected as upper boundary in 
       BNDSELX register.
    */
    /* boundary value select in Standard compare mode limit checking*/
    /* Limit check event generation*/
    /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
    Channel Configuration Structure and is within allowed range*/
    /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
    Channel Configuration Structure and is within allowed range*/
    SfrValue = \
      (uint32)( ((uint32)ADC_GRP_BOUND1 << ADC_BNDSELL_BIT_POS) | \
                ((uint32)ADC_GRP_BOUND0 << ADC_BNDSELU_BIT_POS) | \
                (ChCfgPtr[ChIdx].AdcChBndSelxValue << ADC_BNDSELX_BIT_POS) | \
                ( (ChCfgPtr[ChIdx].AdcLimitChkRange & ADC_CHEVMODE_BITS) \
                                                    << ADC_CHEVMODE_BIT_POS )\
               );
    /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
    access the SFRs of multiple ADC kernels*/
    ADC_SFR_RUNTIME_USER_MODE_MODIFY32(ADC_MODULE[AdcKernel].CHCTR[IntChNr].U, \
                                     (uint32)ADC_CHCTR_SFR_MSK,(uint32)SfrValue)
    /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
    access the SFRs of multiple ADC kernels*/
    ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].BOUND.U, \
                                                ChCfgPtr[ChIdx].AdcLimitChkBnd);
    
    Adc_lSetChEvntNodePtr(AdcKernel,IntChNr);
  
    DataPtr->LimitChkGroup = GroupId;
  }
  #endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  
} /* Adc_lEnableSynchLimitChkCh */

#endif 
/* ((ADC_MASTER_SLAVE_SYNC == STD_ON) || (ADC_ENABLE_LIMIT_CHECK == STD_ON)) */

/*******************************************************************************
** Syntax           : void Adc_lClearReqSrcSfr                                **
**                    (                                                       **
**                       const Adc_GroupCfgType* GrpPtr                       **
**                       uint8 GrpReqSrc                                      **
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
**                    Rquest source in conversion                             **
**                    Adc HW Unit ID                                          **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called when Group has to be stopped                  **
*******************************************************************************/
void Adc_lClearReqSrcSfr
(
  const Adc_GroupCfgType* GrpPtr,
  uint8 GrpReqSrc,
  uint8 AdcKernel
)
{
  uint32                    ReadVfFlag;
  #if((ADC_REQSRC0 == ADC_REQSRC_USED) || (ADC_REQSRC1 == ADC_REQSRC_USED))

  uint32                    ReadValue;
  #endif/* REQSRC0 or REQSRC1 used */
  #if( (ADC_REQSRC0 == ADC_REQSRC_USED) && \
                                       (ADC_SAME_CHANNEL_QUEUING ==  STD_ON) )
  const Adc_ChannelCfgType  *ChCfgPtr;
  uint32                    TotalGrpCh;
  uint32                    LoopCount;
  uint32                    ChConfigData;
  Adc_ChannelType           IntChNr;
  Adc_ChannelType           ChIdx;
  #endif /* REQSRC0  used */
  
  switch (GrpReqSrc)
  {
    #if (ADC_REQSRC2 == ADC_REQSRC_USED)
    /* ADC Background SCAN request source RS2 */
    case ADC_REQSRC2_BGND_SCAN:
    {
      /* Clear channel select register */
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE_GLOB.BRSSEL[AdcKernel].U, \
                              ADC_SCAN_EMPTY);
      
      if( (Adc_BgndGrpCnt == 0U) || (GrpPtr->TriggSrc == ADC_TRIGG_SRC_SW) )
      {
        /* Close RS Gate */
        /* Clear pending bits */
        ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE_GLOB.BRSMR.U,  \
                                                     ADC_SCAN_CLR_PENDING_BITS);

        
        /* Write access is enabled for gate input selection for RS2 */
        /* Reset gate input selection for RS2*/
        /* Reset request source data */
        ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE_GLOB.BRSCTRL.U,  \
                                                     ADC_WRITE_GATE_SEL_ENABLE);
      }
      /* Note: How ever the ongoing channel conversion will not stop and 
        generates the service request (if channel interrupt enabled) */

      #if (ADC_WAIT_ON_STOP == STD_ON)
      /* Wait till the ADC conversion state becomes Idle. This will make sure
         the channel under conversion is completed and its service request
         is set (if enabled).
      */
      Adc_lWaitForChConversion(AdcKernel);
      #endif /* (ADC_WAIT_ON_STOP == STD_ON) */

      /* Clear source service request event flag if any */
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE_GLOB.GLOBEFLAG.U,  \
                                                    ADC_BACKGRND_RS_EVNT_CLEAR);
      /* Clear the Result register event flag */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].REFCLR.U,  \
                                                     (uint32)GrpPtr->IntChMask);
      /* Clear the Channel register event flag */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].CEFCLR.U,  \
                                                     (uint32)GrpPtr->IntChMask);
    }
    break; /* Background SCAN request source  */
    #endif /* RS2 used by any of the ADC kernel */ 

    #if (ADC_REQSRC1 == ADC_REQSRC_USED)
    /* ADC SCAN request source RS1 */
    case ADC_REQSRC1_NCH_SCAN:
    {

      /* Clear channel select register */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(
                                 ADC_MODULE[AdcKernel].ASSEL.U, ADC_SCAN_EMPTY);

      /* Close RS Gate */
      /* Clear pending bits */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].ASMR.U,  \
                                                     ADC_SCAN_CLR_PENDING_BITS);

      
      /* Write access is enabled for timer mode */
      /* Reset timer mode */
      /* Reset request source data */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].ASCTRL.U,  \
                                                   ADC_WRITE_TIMER_MODE_ENABLE);

      /* Note: How ever the ongoing channel conversion will not stop and 
        generates the service request (if channel interrupt enabled) */

      #if (ADC_WAIT_ON_STOP == STD_ON)
      /* Wait till the ADC conversion state becomes Idle. This will make sure
         the channel under conversion is completed and its service request
         is set (if enabled).
      */
      Adc_lWaitForChConversion(AdcKernel);
      #endif /* (ADC_WAIT_ON_STOP == STD_ON) */

      ReadValue = (uint32)Adc_lClearEventFlag(GrpReqSrc);
      /* Clear source service request event flag if any */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(
                                     ADC_MODULE[AdcKernel].SEFCLR.U, ReadValue);
      /* Clear the Result register event flag */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].REFCLR.U,  \
                                                     (uint32)GrpPtr->IntChMask);
      /* Clear the Channel register event flag */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].CEFCLR.U,  \
                                                     (uint32)GrpPtr->IntChMask);
    }
    break; /* SCAN request source  */
    #endif /* RS1 used by any of the ADC kernel */ 

    /* ADC_REQSRC0_8STG_QUE is used as default case */
    default:
    #if (ADC_REQSRC0 == ADC_REQSRC_USED)
    /* Queue request source */
    {
      /* Stop the sequence by closing the gate */
      /* The next and all Queue entry are cleared */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].QMR0.U, \
                                                          ADC_QUEUE_MODE_CLEAR);

      /* Reset request source data */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(
                              ADC_MODULE[AdcKernel].QCTRL0.U, ADC_REQSRC_RESET);

      /* Note: How ever the ongoing channel conversion will not stop and 
        generates the service request (if channel interrupt enabled) */

      #if (ADC_WAIT_ON_STOP == STD_ON)
      /* Wait till the ADC conversion state becomes Idle. This will make sure
         the channel under conversion is completed and its service request
         is set (if enabled).
      */
      Adc_lWaitForChConversion(AdcKernel);
      #endif /* (ADC_WAIT_ON_STOP == STD_ON) */

      ReadValue = (uint32)Adc_lClearEventFlag(GrpReqSrc);
      /* Clear source service request event flag if any */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(
                                     ADC_MODULE[AdcKernel].SEFCLR.U, ReadValue);
      /* Clear the Result register event flag */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].REFCLR.U,  \
                                                     (uint32)GrpPtr->IntChMask);
      /* Clear the Channel register event flag */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].CEFCLR.U,  \
                                                     (uint32)GrpPtr->IntChMask);
      
      #if( ADC_SAME_CHANNEL_QUEUING ==  STD_ON )
      /* The first element in the Group defination will give total 
         number of channels in Group
      */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      TotalGrpCh = (uint32)(GrpPtr->GroupDefinition)[0];

      /* Get the address of channel configuration array */
      ChCfgPtr = (Adc_kConfigPtr->CfgPtr[AdcKernel]->ChCfgPtr);
      
      /*Note: First channel in the GroupDefinition will be converted first
        followed by the fallowing channels
      */ 
      /* The Group channels in GroupDefinition will start from 
         second elenemt of the array
      */
      LoopCount = (uint32)1;

      while (LoopCount <= TotalGrpCh)
      {
        /* Get the channel conf data for the channel index 
           in group definition */
        /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
        Group Configuration Structure and is within allowed range*/
        ChIdx = (GrpPtr->GroupDefinition)[LoopCount];
        /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
        channel Configuration Structure and is within allowed range*/
        ChConfigData = ChCfgPtr[ChIdx].AdcChConfigValue;

        /* Get the internal Channel number from the Channel configuration */
        IntChNr = (Adc_ChannelType)Adc_lGetKernelChNum(ChConfigData);

        /* Clear RCR register */
        /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
        access the SFRs of multiple ADC kernels*/
        ADC_SFR_RUNTIME_USER_MODE_WRITE32(
                                      ADC_MODULE[AdcKernel].RCR[IntChNr].U, 0U);
        
        /* Increment the loop count */
        LoopCount++;
      }/* While */
      #endif /* ( ADC_SAME_CHANNEL_QUEUING == STD_ON ) */

    } /* Queue request source */
    #endif /* RS0 used by any of the ADC Kernel */

    break; 
    
  /*IFX_MISRA_RULE_15_05_STATUS=Switch statement doesn't have case clause,
  only in case if Resquest Sources 0(RS0) is used and other 
  Resquest Sources are not not used*/
  }/*switch on request source */

  /* When new conversion starts,
     Dummy read for result register becomes necessary when 
     result register is configured for WFR 
  */
  /* Insted of Dummy read, Clear result valid flag */
  /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
  access the SFRs of multiple ADC kernels*/
  ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].VFR.U,  \
                                                 (uint32)GrpPtr->IntChMask);

  /* Reading VFR to make sure the result valid flags are cleared */
  /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
  access the SFRs of multiple ADC kernels*/
  ReadVfFlag = ADC_SFR_RUNTIME_USER_MODE_READ32(ADC_MODULE[AdcKernel].VFR.U);

  UNUSED_PARAMETER(ReadVfFlag)

} /* Adc_lClearReqSrcSfr */

#endif /* ADC_ENABLE_START_STOP_GROUP_API or ADC_HW_TRIGGER_API is STD_ON */

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/*******************************************************************************
** Syntax           : void Adc_lStartSwConversionRS                           **
**                    (                                                       **
**                       const Adc_GroupCfgType* GrpPtr,                      **
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
**                    Adc HW Unit Id                                          **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called when SW trigger type Group has to be started  **
*******************************************************************************/
void Adc_lStartSwConversionRS
(
  const Adc_GroupCfgType* GrpPtr,
  uint8                   AdcKernel
)
{
  uint32                    ConversionMode;
  uint32                    EnableSrcInt;
  #if ( (ADC_REQSRC0 == ADC_REQSRC_USED ) || (ADC_REQSRC1 == ADC_REQSRC_USED) )
  uint32                    ReadValue;
  #endif/* REQSRC0 or REQSRC1  used */
  #if ( (ADC_REQSRC0 == ADC_REQSRC_USED ) || (ADC_REQSRC2 == ADC_REQSRC_USED) )
  uint32                    LoopCount;
  #endif /* REQSRC0 or REQSRC2  used */
  #if (ADC_REQSRC0 == ADC_REQSRC_USED )
  uint32                    TotalGrpCh;
  uint32                    ChConfigData;
  Adc_ChannelType           IntChNr;
  #endif /* REQSRC0  used */

  #if ((ADC_REQSRC0 == ADC_REQSRC_USED) || (ADC_ENABLE_LIMIT_CHECK == STD_ON))
  const Adc_ChannelCfgType  *ChCfgPtr;
  Adc_ChannelType           ChIdx;
  #endif 

  uint8  GrpReqSrc;


  /* Initialise conversion mode to be one shot */
  ConversionMode = (uint32)ADC_CONV_MODE_ONESHOT;

  /* To remove dead assignment warning, put EnableSrcInt under EMUX scan */
  #if ((ADC_GROUP_EMUX_SCAN == STD_ON) || (ADC_ENABLE_LIMIT_CHECK == STD_ON))
  /* Initialise Enable source interrupt to be false */
  EnableSrcInt = ADC_REQSRC_INT_DISABLE;
  #endif

  GrpReqSrc = GrpPtr->GrpRequestSrc;

  switch (GrpReqSrc)
  {
    #if (ADC_REQSRC2 == ADC_REQSRC_USED)
        
    /* SCAN request source */
    case ADC_REQSRC2_BGND_SCAN:
    {
      /* New conversion is starting in Request source, 
         any pending source interrupt is cleared
      */
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE_GLOB.GLOBEFLAG.U, \
                                                    ADC_BACKGRND_RS_EVNT_CLEAR);
      /* Clear the Result register event flag */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].REFCLR.U,  \
                                                     (uint32)GrpPtr->IntChMask);
      /* Clear the Channel register event flag */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].CEFCLR.U,  \
                                                     (uint32)GrpPtr->IntChMask);
      /* Insted of Dummy read, Clear result valid flag */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].VFR.U,  \
                                                     (uint32)GrpPtr->IntChMask);

      /* Get the conversion mode, if continuous SCAN bit is set */
      if (GrpPtr->ConvMode == ADC_CONV_MODE_CONTINUOUS)
      {
        ConversionMode = ADC_SCAN_CONTINUOUS;
      }

      #if (ADC_GROUP_EMUX_SCAN == STD_ON)
      /* IF Group is not configured for EMUX SCAN, enable Src interrupt */
      if ((uint32)Adc_lGetEmuxScan((uint32)GrpPtr->GroupEmuxData) == 
           (uint32)ADC_GROUP_EMUX_SCAN_DISABLE
         )
      {
        EnableSrcInt = ADC_SCAN_INT_ENABLE;
      }
      /* (ADC_GROUP_EMUX_SCAN == STD_ON) */

      #elif (ADC_ENABLE_LIMIT_CHECK == STD_ON)

      /* Get the Requested group's first channel Channels ID location */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
      Group Configuration Structure and is within allowed range*/
      ChIdx = (GrpPtr->GroupDefinition)[1U];

      /* Get the starting address of the Channel configuration data structure 
         array */
      ChCfgPtr = Adc_kConfigPtr->CfgPtr[AdcKernel]->ChCfgPtr;
      
      /* IF Group is not configured for Limit check, enable Src interrupt */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
      Channel Configuration Structure and is within allowed range*/
      if(ChCfgPtr[ChIdx].AdcIsChLimitChkEnabled == 0U)
      {
        EnableSrcInt = ADC_SCAN_INT_ENABLE;
      }
      /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
      #elif (ADC_RESULT_POLLING_MODE == STD_ON)
      /* Enable source interrupt to be false in polling mode */
      EnableSrcInt = ADC_REQSRC_INT_DISABLE;
      
      #else

      EnableSrcInt = ADC_SCAN_INT_ENABLE;
      
      /* (ADC_ENABLE_LIMIT_CHECK == STD_OFF) &&  
                                     (ADC_GROUP_EMUX_SCAN == STD_OFF) */
      #endif 

      LoopCount = 0U;
      do
      {
        if(Adc_lKernelConfigured((uint8)LoopCount) != 0U)
        {
          /* Clear channel select register. UTP AI00132372 */
          ADC_SFR_RUNTIME_USER_MODE_WRITE32(
                           ADC_MODULE_GLOB.BRSSEL[LoopCount].U, ADC_SCAN_EMPTY);
        }
      
        LoopCount++;
        
      } while (LoopCount < ADC_MAX_KERNELS);


      /* Enables the group channels in BRSSEL */
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE_GLOB.BRSSEL[AdcKernel].U,  \
                                                   (uint32)(GrpPtr->IntChMask));

      /* Conversion mode register is programmed for SW trigger */
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE_GLOB.BRSMR.U,  \
                            (ADC_SCAN_SW_TRIG | ConversionMode | EnableSrcInt));
    }
    break; /* Scan Request source */
    #endif /* RS2 used by any of the ADC kernel */

    #if (ADC_REQSRC1 == ADC_REQSRC_USED)
        
    /* SCAN request source */
    case ADC_REQSRC1_NCH_SCAN:
    {
      
      ReadValue = (uint32)Adc_lClearEventFlag(GrpReqSrc);
      /* New conversion is starting in Request source, 
         any pending source interrupt is cleared
      */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(
                                     ADC_MODULE[AdcKernel].SEFCLR.U, ReadValue);
      /* Clear the Result register event flag */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].REFCLR.U,  \
                                                     (uint32)GrpPtr->IntChMask);
      /* Clear the Channel register event flag */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].CEFCLR.U,  \
                                                     (uint32)GrpPtr->IntChMask);
      /* Insted of Dummy read, Clear result valid flag */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].VFR.U,  \
                                                     (uint32)GrpPtr->IntChMask);

      /* Get the conversion mode, if continuous SCAN bit is set */
      if (GrpPtr->ConvMode == ADC_CONV_MODE_CONTINUOUS)
      {
        ConversionMode = ADC_SCAN_CONTINUOUS;
      }

      #if (ADC_GROUP_EMUX_SCAN == STD_ON)
      /* IF Group is not configured for EMUX SCAN, enable Src interrupt */
      if ((uint32)Adc_lGetEmuxScan((uint32)GrpPtr->GroupEmuxData) == 
           (uint32)ADC_GROUP_EMUX_SCAN_DISABLE
         )
      {
        EnableSrcInt = ADC_SCAN_INT_ENABLE;
      }
      /* (ADC_GROUP_EMUX_SCAN == STD_ON) */

      #elif (ADC_ENABLE_LIMIT_CHECK == STD_ON)

      /* Get the Requested group's first channel Channels ID location */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
      Group Configuration Structure and is within allowed range*/
      ChIdx = (GrpPtr->GroupDefinition)[1U];

      /* Get the starting address of the Channel configuration data structure 
         array */
      ChCfgPtr = Adc_kConfigPtr->CfgPtr[AdcKernel]->ChCfgPtr;
      
      /* IF Group is not configured for Limit check, enable Src interrupt */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
      Channel Configuration Structure and is within allowed range*/
      if(ChCfgPtr[ChIdx].AdcIsChLimitChkEnabled == 0U)
      {
        EnableSrcInt = ADC_SCAN_INT_ENABLE;
      }
      /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
      #elif (ADC_RESULT_POLLING_MODE == STD_ON)
      /* Enable source interrupt to be false in polling mode */
      EnableSrcInt = ADC_REQSRC_INT_DISABLE;
      
      #else

      EnableSrcInt = ADC_SCAN_INT_ENABLE;
      
      /* (ADC_ENABLE_LIMIT_CHECK == STD_OFF) &&  
                                     (ADC_GROUP_EMUX_SCAN == STD_OFF) */
      #endif 

      /* Enables the group channels in ASSEL */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].ASSEL.U,  \
                                                   (uint32)(GrpPtr->IntChMask));
       
      /* Conversion mode register is programmed for SW trigger */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].ASMR.U,  \
                            (ADC_SCAN_SW_TRIG | ConversionMode | EnableSrcInt));
    }
    break; /* Scan Request source */
    #endif /* RS1 used by any of the ADC kernel */

    /* Queue request source ADC_REQSRC0_8STG_QUE is used as default case */
    default:
    #if (ADC_REQSRC0 == ADC_REQSRC_USED )
    {
      ReadValue = (uint32)Adc_lClearEventFlag(GrpReqSrc);
      /* New conversion is starting in Request source , 
         any pending source interrupt is cleared
      */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(
                                     ADC_MODULE[AdcKernel].SEFCLR.U, ReadValue);
      /* Clear the Result register event flag */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].REFCLR.U,  \
                                                     (uint32)GrpPtr->IntChMask);
      /* Clear the Channel register event flag */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].CEFCLR.U,  \
                                                     (uint32)GrpPtr->IntChMask);
      /* Insted of Dummy read, Clear result valid flag */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].VFR.U,  \
                                                     (uint32)GrpPtr->IntChMask);

      /* Get the conversion mode, if continuous Refill bit is set */
      if (GrpPtr->ConvMode == ADC_CONV_MODE_CONTINUOUS)
      {
        ConversionMode = ADC_QUEUE_REFILL;
      }

      #if (ADC_GROUP_EMUX_SCAN == STD_ON)
      /* IF Group is not configured for EMUX SCAN, enable Src interrupt */
      if ((uint32)Adc_lGetEmuxScan((uint32)GrpPtr->GroupEmuxData) == 
           (uint32)ADC_GROUP_EMUX_SCAN_DISABLE
         )
      {
        EnableSrcInt = ADC_QUEUE_INT_ENABLE;
      }
      /* (ADC_GROUP_EMUX_SCAN == STD_ON) */

      #elif (ADC_ENABLE_LIMIT_CHECK == STD_ON)

      /* Get the Requested group's first channel Channels ID location */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
      Group Configuration Structure and is within allowed range*/
      ChIdx = (GrpPtr->GroupDefinition)[1U];

      /* Get the starting address of the Channel configuration data structure 
         array */
      ChCfgPtr = Adc_kConfigPtr->CfgPtr[AdcKernel]->ChCfgPtr;
      
      /* IF Group is not configured for Limit check, enable Src interrupt */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
      Channel Configuration Structure and is within allowed range*/
      if(ChCfgPtr[ChIdx].AdcIsChLimitChkEnabled == 0U)
      {
        EnableSrcInt = ADC_QUEUE_INT_ENABLE;
      }
      /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
      #elif (ADC_RESULT_POLLING_MODE == STD_ON)
      /* Enable source interrupt to be false in polling mode */
      EnableSrcInt = ADC_REQSRC_INT_DISABLE;
      
      #else

      EnableSrcInt = ADC_QUEUE_INT_ENABLE;
      
      /* (ADC_ENABLE_LIMIT_CHECK == STD_OFF) &&  
                                     (ADC_GROUP_EMUX_SCAN == STD_OFF) */
      #endif 

      /* New start of the Que RS should flush the Que for new entries*/
      /* Flush the Que */
      /* The next and all Queue entry are cleared */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].QMR0.U, \
                                                          ADC_QUEUE_MODE_CLEAR);

      /* The first element in the Group defination will give total 
         number of channels in Group
      */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
      Group Configuration Structure and is within allowed range*/
      TotalGrpCh = (uint32)(GrpPtr->GroupDefinition)[0];

      /* Get the address of channel configuration array */
      ChCfgPtr = (Adc_kConfigPtr->CfgPtr[AdcKernel]->ChCfgPtr);
      
      /*Note: First channel in the GroupDefinition will be converted first
        followed by the fallowing channels
      */ 
      /* The Group channels in GroupDefinition will start from 
         second elenemt of the array
      */
      LoopCount = (uint32)1;

      while (LoopCount < TotalGrpCh)
      {
        /* Get the channel conf data for the channel index 
           in group definition */
        /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
        Group Configuration Structure and is within allowed range*/
        ChIdx = (GrpPtr->GroupDefinition)[LoopCount];
        /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
        Channel Configuration Structure and is within allowed range*/
        ChConfigData = ChCfgPtr[ChIdx].AdcChConfigValue;

        /* Get the internal Channel number from the Channel configuration */
        IntChNr = (Adc_ChannelType)Adc_lGetKernelChNum(ChConfigData);

        /* Prepare queue input register */
        /* Request source interrupt is not enabled for all the channels */ 
        /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
        access the SFRs of multiple ADC kernels*/
        ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].QINR0.U,  \
                                            ((uint32)IntChNr | ConversionMode));

        #if( ADC_SAME_CHANNEL_QUEUING ==  STD_ON )
        /* initialise the channel for Data Accumulation */
        /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
        access the SFRs of multiple ADC kernels*/
        ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].RCR[IntChNr].U,\
                                          ChCfgPtr[ChIdx].AdcChResAccumulation);
        #endif /* ( ADC_SAME_CHANNEL_QUEUING ==  STD_ON ) */
        
        /* Increment the loop count */
        LoopCount++;
      }/* While */

      /* The last channel is programmed for Source interrupt */
      
      /* Get the channel conf data for the channel index 
         in group definition */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
      Group Configuration Structure and is within allowed range*/
      ChIdx = (GrpPtr->GroupDefinition)[LoopCount];
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
      Channel Configuration Structure and is within allowed range*/
      ChConfigData = ChCfgPtr[ChIdx].AdcChConfigValue;

      /* Get the internal Channel number from the Channel configuration */
      IntChNr = (Adc_ChannelType)Adc_lGetKernelChNum(ChConfigData);

      /* Prepare queue input register */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].QINR0.U,  \
                             ((uint32)IntChNr | ConversionMode | EnableSrcInt));
    
      #if( ADC_SAME_CHANNEL_QUEUING ==  STD_ON )
      /* initialise the channel for Data Accumulation */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].RCR[IntChNr].U,  \
                                          ChCfgPtr[ChIdx].AdcChResAccumulation);
      #endif /* ( ADC_SAME_CHANNEL_QUEUING ==  STD_ON ) */
    
      /* Queue trigger by software */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(
                               ADC_MODULE[AdcKernel].QMR0.U, ADC_QUEUE_SW_TRIG);
    }/* Queue request source */
    #endif /* RS0 used by any of the ADC kernel */
    
    break;

  /*IFX_MISRA_RULE_15_05_STATUS=Switch statement doesn't have case clause,
  only in case if Resquest Sources 0(RS0) is used and other 
  Resquest Sources are not not used*/
  }/*switch on request source */
}/* Adc_lStartSwConversionRS */

#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

#if (ADC_HW_TRIGGER_API == STD_ON)
/*******************************************************************************
** Syntax           : void Adc_lStartHwConversionRS                           **
**                    (                                                       **
**                       const Adc_GroupCfgType* GrpPtr,                      **
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
**                    Adc HW Unit Id                                          **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called when HW trigg type Group has to be started    **
*******************************************************************************/
void Adc_lStartHwConversionRS
(
  const Adc_GroupCfgType* GrpPtr,
  uint8                   AdcKernel
)
{
  uint32 HwCfgData;
  #if (ADC_TIMER_TRIGG == STD_ON)
  uint32 TimEnableFlag;
  #endif /*ADC_TIMER_TRIGG == STD_ON*/
  uint32 GateEnable;
  uint32 EnableSrcInt;
  uint32 TriggSel;
  uint32 TriggMode;
  uint32 GateSel;
  #if( (ADC_REQSRC1 == ADC_REQSRC_USED) || (ADC_REQSRC0 == ADC_REQSRC_USED) )
  uint32 TimerEnable;
  uint32 ReadValue;
  #endif/* REQSRC0 or REQSRC1  used */
  #if (ADC_REQSRC0 == ADC_REQSRC_USED )
  uint32                    TotalGrpCh;
  uint32                    LoopCount;
  uint32                    ChConfigData;
  Adc_ChannelType           IntChNr;
  #endif /* REQSRC0 used */
  #if ((ADC_REQSRC0 == ADC_REQSRC_USED) || (ADC_ENABLE_LIMIT_CHECK == STD_ON) )
  const Adc_ChannelCfgType  *ChCfgPtr;
  Adc_ChannelType           ChIdx;
  #endif 
  uint8  GrpReqSrc;

  /* To remove dead assignment warning, put EnableSrcInt under EMUX scan */
  #if ((ADC_GROUP_EMUX_SCAN == STD_ON) || (ADC_ENABLE_LIMIT_CHECK == STD_ON))
  /* Initialise Enable source interrupt to be false */
  EnableSrcInt = ADC_REQSRC_INT_DISABLE;
  #endif

  /* Get the user config data for HW trigger */
  HwCfgData = (uint32)GrpPtr->HwTrigConfig;

  #if (ADC_TIMER_TRIGG == STD_ON)
  /* Get the Timer Enable bit */
  TimEnableFlag = (uint32)Adc_lGetTimEnData(HwCfgData);
  #endif /*ADC_TIMER_TRIGG == STD_ON*/
    
  /* Get the Gate enable selection */
  GateEnable = (uint32)Adc_lGetEngtVal(HwCfgData);

  #if (ADC_TIMER_TRIGG == STD_ON)
  /* Only when timer trigger selected */
  if (TimEnableFlag == (uint32)ADC_GROUP_TIMER_ENABLE)
  {
    /* conversion request are issued atleast one channel is pending */
    GateEnable = 1U;
  }
  #endif /* (ADC_TIMER_TRIGG == STD_ON) */
    
  GrpReqSrc = GrpPtr->GrpRequestSrc;
  /* Hardware trigger type */
  switch (GrpReqSrc)
  {
    #if (ADC_REQSRC2 == ADC_REQSRC_USED)
    /* Background SCAN request source */
    case ADC_REQSRC2_BGND_SCAN:
    {

      if(Adc_BgndGrpCnt == 1U)
      {
        /* New conversion is starting in Request source, 
           any pending source interrupt is cleared
        */
        ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE_GLOB.GLOBEFLAG.U,  \
                                                    ADC_BACKGRND_RS_EVNT_CLEAR);
      }
      /* Clear the Result register event flag */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].REFCLR.U,  \
                                                     (uint32)GrpPtr->IntChMask);
      /* Clear the Channel register event flag */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].CEFCLR.U,  \
                                                     (uint32)GrpPtr->IntChMask);
      /* Insted of Dummy read, Clear result valid flag */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].VFR.U,  \
                                                     (uint32)GrpPtr->IntChMask);

      #if (ADC_RESULT_POLLING_MODE == STD_ON)
      /* Enable source interrupt to be false in polling mode */
      EnableSrcInt = ADC_REQSRC_INT_DISABLE;
      
      #else
      
      EnableSrcInt = ADC_SCAN_INT_ENABLE;
      #endif /* (ADC_RESULT_POLLING_MODE == STD_ON) */
      
      /* External trigger input selection */
      TriggSel = Adc_lGetTriggSelData(HwCfgData,ADC_XTSEL_POS,0U);
      /* Trigger event upon falling / rising edge */
      TriggMode = ( Adc_lGetRsCtrlData(HwCfgData,ADC_XTMODE_POS,0U) <<
                                                (uint32)(ADC_XTMODE_SHIFT_POS)
                  );
      /* Gate input selection */
      GateSel = ( Adc_lGetRsCtrlData(HwCfgData,ADC_GTSEL_POS,0U) <<
                                                 (uint32)(ADC_GTSEL_SHIFT_POS)
                );

      /* Enables the group channels in BRSSEL */
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE_GLOB.BRSSEL[AdcKernel].U,  \
                                                   (uint32)(GrpPtr->IntChMask));
       
      if(Adc_BgndGrpCnt == 1U)
      {
        /* XTWC = 1, GTWC = 1 */
        ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE_GLOB.BRSCTRL.U,  \
                        ( (uint32)ADC_WRITE_GAT_TRG_MODE_ENABLE | (TriggSel) | 
                          (TriggMode) | (GateSel)
                        ));
        
        /* Conversion mode register is programmed for HW trigger.
           Scan is disabled. On every trigger new set of conversion will
           happen
        */
        ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE_GLOB.BRSMR.U,  \
                           (ADC_SCAN_EXT_TRIG | (uint32)ADC_CONV_MODE_ONESHOT | 
            (GateEnable) | (EnableSrcInt)
          ));
      }
    }
    break; /* Background Scan request source */
    #endif /* RS2 used by any of the ADC kernel */

    #if (ADC_REQSRC1 == ADC_REQSRC_USED)
    /* AUTO SCAN request source */
    case ADC_REQSRC1_NCH_SCAN:
    {
      ReadValue = (uint32)Adc_lClearEventFlag(GrpReqSrc);
      /* New conversion is starting in Request source, 
         any pending source interrupt is cleared
      */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(
                                     ADC_MODULE[AdcKernel].SEFCLR.U, ReadValue);
      /* Clear the Result register event flag */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].REFCLR.U,  \
                                                     (uint32)GrpPtr->IntChMask);
      /* Clear the Channel register event flag */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].CEFCLR.U,  \
                                                     (uint32)GrpPtr->IntChMask);
      /* Insted of Dummy read, Clear result valid flag */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].VFR.U,  \
                                                     (uint32)GrpPtr->IntChMask);

      #if (ADC_GROUP_EMUX_SCAN == STD_ON)
      /* IF Group is not configured for EMUX SCAN, enable Src interrupt */
      if ((uint32)Adc_lGetEmuxScan((uint32)GrpPtr->GroupEmuxData) == 
           (uint32)ADC_GROUP_EMUX_SCAN_DISABLE
         )
      {
        EnableSrcInt = ADC_SCAN_INT_ENABLE;
      }
      /* (ADC_GROUP_EMUX_SCAN == STD_ON) */

      #elif (ADC_ENABLE_LIMIT_CHECK == STD_ON)

      /* Get the Requested group's first channel Channels ID location */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
      Group Configuration Structure and is within allowed range*/
      ChIdx = (GrpPtr->GroupDefinition)[1U];

      /* Get the starting address of the Channel configuration data structure 
         array */
      ChCfgPtr = Adc_kConfigPtr->CfgPtr[AdcKernel]->ChCfgPtr;
      
      /* IF Group is not configured for Limit check, enable Src interrupt */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
      Channel Configuration Structure and is within allowed range*/
      if(ChCfgPtr[ChIdx].AdcIsChLimitChkEnabled == 0U)
      {
        EnableSrcInt = ADC_SCAN_INT_ENABLE;
      }
      /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
      #elif (ADC_RESULT_POLLING_MODE == STD_ON)
      /* Enable source interrupt to be false in polling mode */
      EnableSrcInt = ADC_REQSRC_INT_DISABLE;
      #else

      EnableSrcInt = ADC_SCAN_INT_ENABLE;
      
      /* (ADC_ENABLE_LIMIT_CHECK == STD_OFF) &&  
                                     (ADC_GROUP_EMUX_SCAN == STD_OFF) */
      #endif 

      /* External trigger input selection */
      TriggSel = Adc_lGetTriggSelData(HwCfgData,ADC_XTSEL_POS,0U);
      /* Trigger event upon falling / rising edge */
      TriggMode = ( Adc_lGetRsCtrlData(HwCfgData,ADC_XTMODE_POS,0U) <<
                                                (uint32)(ADC_XTMODE_SHIFT_POS)
                  );
      /* Gate input selection */
      GateSel = ( Adc_lGetRsCtrlData(HwCfgData,ADC_GTSEL_POS,0U) <<
                                                 (uint32)(ADC_GTSEL_SHIFT_POS)
                );
      /* Timer mode enabled / disabled */
      TimerEnable =  ( Adc_lGetRsCtrlData(HwCfgData,ADC_TMEN_POS,0U) << 
                                                  (uint32)ADC_TMEN_SHIFT_POS );

      /* XTWC = 1, GTWC = 1, TMWC = 1 */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].ASCTRL.U,  \
                    ( (uint32)ADC_WRITE_TIM_GAT_TRG_MODE_ENABLE | (TriggSel) | \
                        (TriggMode) | (GateSel) | (TimerEnable) ));
      
      /* Enables the group channels in ASSEL */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].ASSEL.U,  \
                                                   (uint32)(GrpPtr->IntChMask));
       
      /* Conversion mode register is programmed for HW trigger.
         Scan is disabled. On every trigger new set of conversion will
         happen
      */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].ASMR.U,  \
                  (ADC_SCAN_EXT_TRIG | (uint32)ADC_CONV_MODE_ONESHOT | \
                                       (GateEnable) | (EnableSrcInt) ));
    }
    break; /* Scan request source */
    #endif /* RS1 used by any of the ADC kernel */

    /* Queue request source ADC_REQSRC0_8STG_QUE is used as default case */
    default:
    #if (ADC_REQSRC0 == ADC_REQSRC_USED )
    {
      ReadValue = (uint32)Adc_lClearEventFlag(GrpReqSrc);
      /* New conversion is starting in Request source, 
         any pending source interrupt is cleared
      */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(
                                     ADC_MODULE[AdcKernel].SEFCLR.U, ReadValue);
      /* Clear the Result register event flag */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].REFCLR.U,  \
                                                     (uint32)GrpPtr->IntChMask);
      /* Clear the Channel register event flag */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].CEFCLR.U,  \
                                                     (uint32)GrpPtr->IntChMask);
      /* Insted of Dummy read, Clear result valid flag */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].VFR.U,  \
                                                     (uint32)GrpPtr->IntChMask);

      #if (ADC_GROUP_EMUX_SCAN == STD_ON)
      /* IF Group is not configured for EMUX SCAN, enable Src interrupt */
      if ((uint32)Adc_lGetEmuxScan((uint32)GrpPtr->GroupEmuxData) == 
           (uint32)ADC_GROUP_EMUX_SCAN_DISABLE
         )
      {
        EnableSrcInt = ADC_QUEUE_INT_ENABLE;
      }
      /* (ADC_GROUP_EMUX_SCAN == STD_ON) */

      #elif (ADC_ENABLE_LIMIT_CHECK == STD_ON)

      /* Get the Requested group's first channel Channels ID location */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
      Group Configuration Structure and is within allowed range*/
      ChIdx = (GrpPtr->GroupDefinition)[1U];

      /* Get the starting address of the Channel configuration data structure 
         array */
      ChCfgPtr = Adc_kConfigPtr->CfgPtr[AdcKernel]->ChCfgPtr;
      
      /* IF Group is not configured for Limit check, enable Src interrupt */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
      Channel Configuration Structure and is within allowed range*/
      if(ChCfgPtr[ChIdx].AdcIsChLimitChkEnabled == 0U)
      {
        EnableSrcInt = ADC_QUEUE_INT_ENABLE;
      }
      /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
      #elif (ADC_RESULT_POLLING_MODE == STD_ON)
      /* Enable source interrupt to be false in polling mode */
      EnableSrcInt = ADC_REQSRC_INT_DISABLE;
      #else

      EnableSrcInt = ADC_QUEUE_INT_ENABLE;
      
      /* (ADC_ENABLE_LIMIT_CHECK == STD_OFF) &&  
                                     (ADC_GROUP_EMUX_SCAN == STD_OFF) */
      #endif 

      /* New start of the Que RS should flush the Que for new entries */
      /* Flush the Que */
      /* The next and all Queue entry are cleared */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].QMR0.U, \
                                                        ADC_QUEUE_MODE_CLEAR);

      /* External trigger input selection */
      TriggSel = Adc_lGetTriggSelData(HwCfgData,ADC_XTSEL_POS,0U);
      /* Trigger event upon falling / rising edge */
      TriggMode = ( Adc_lGetRsCtrlData(HwCfgData,ADC_XTMODE_POS,0U) <<
                                                (uint32)(ADC_XTMODE_SHIFT_POS)
                  );
      /* Gate input selection */
      GateSel = ( Adc_lGetRsCtrlData(HwCfgData,ADC_GTSEL_POS,0U) <<
                                                 (uint32)(ADC_GTSEL_SHIFT_POS)
                );
      /* Timer mode enabled / disabled */
      TimerEnable =  ( Adc_lGetRsCtrlData(HwCfgData,ADC_TMEN_POS,0U) << 
                                                  (uint32)ADC_TMEN_SHIFT_POS );

      /* XTWC = 1, GTWC = 1, TMWC = 1 */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently 
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].QCTRL0.U,  \
               ( (uint32)ADC_WRITE_TIM_GAT_TRG_MODE_ENABLE | (TriggSel) | \
                        (TriggMode) | (GateSel) | (TimerEnable) ));
      
      /* The first element in the Group defination will give total 
         number of channels in Group
      */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
      Group Configuration Structure and is within allowed range*/
      TotalGrpCh = (uint32)(GrpPtr->GroupDefinition)[0];

      /* Get the address of channel configuration array */
      ChCfgPtr = (Adc_kConfigPtr->CfgPtr[AdcKernel]->ChCfgPtr);
      
      /*Note: First channel in the GroupDefinition will be converted first
        fallowed by the fallowing channels
        Only the first channel is enabled for the wait for trigger mode. 
        The remaining channels in the group will fallow first channel 
        without waiting for trigger.
      */ 
      /* The Group channels in GroupDefinition will start from 
         second elenemt of the array
      */
      /* Atleast one channel will be there in a group. 
         If TotalGrpCh != 1 means there is only one channel in a group */
      if (TotalGrpCh != 1U)
      {
        /* First channel is asked to wait for trigger */
        /* Get the channel conf data for the channel index 
           in group definition */
        /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
        Group Configuration Structure and is within allowed range*/
        ChIdx = (GrpPtr->GroupDefinition)[ADC_GROUP_FIRST_CH_INDEX];

        /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
        Channel Configuration Structure and is within allowed range*/
        ChConfigData = ChCfgPtr[ChIdx].AdcChConfigValue;

        /* Get the internal Channel number from the Channel configuration */
        IntChNr = (Adc_ChannelType)Adc_lGetKernelChNum(ChConfigData);

        /* Prepare queue input register */
        /* Request source interrupt is not enabled for all the channels */ 
        /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
        access the SFRs of multiple ADC kernels*/
        ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].QINR0.U,  \
              ((uint32)IntChNr | ADC_QUEUE_REFILL | ADC_QUEUE_WAIT_TRIGGEVENT));

        /* Remaining channels will not wait for trigger. Instead will fallow 
           first channel
        */
        
        #if( ADC_SAME_CHANNEL_QUEUING ==  STD_ON )
        /* initialise the channel for Data Accumulation */
        /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
        access the SFRs of multiple ADC kernels*/
        ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].RCR[IntChNr].U,\
                                                ChCfgPtr->AdcChResAccumulation);
        #endif /* ( ADC_SAME_CHANNEL_QUEUING ==  STD_ON ) */
        
        /* D0-While is not used because if there is only two channel 
           in a group, then while loop is not required
        */
        /* Loop from 2nd channel in the Group */
        LoopCount = (uint32)2;
        while (LoopCount < TotalGrpCh)
        {
          /* Get the channel conf data for the channel index 
             in group definition */
          /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
          Group Configuration Structure and is within allowed range*/
          ChIdx = (GrpPtr->GroupDefinition)[LoopCount];
          
          /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
          Channel Configuration Structure and is within allowed range*/
          ChConfigData = ChCfgPtr[ChIdx].AdcChConfigValue;

          /* Get the internal Channel number from the Channel configuration */
          IntChNr = (Adc_ChannelType)Adc_lGetKernelChNum(ChConfigData);

          /* Prepare queue input register */
          /* Request source interrupt is not enabled for all the channels */ 
          /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to 
          efficiently access the SFRs of multiple ADC kernels*/
          ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].QINR0.U,  \
                                          ((uint32)IntChNr | ADC_QUEUE_REFILL));

          #if( ADC_SAME_CHANNEL_QUEUING ==  STD_ON )
          /* initialise the channel for Data Accumulation */
          /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to 
          efficiently access the SFRs of multiple ADC kernels*/
          ADC_SFR_RUNTIME_USER_MODE_WRITE32(
                                         ADC_MODULE[AdcKernel].RCR[IntChNr].U, \
                                          ChCfgPtr[ChIdx].AdcChResAccumulation);
          #endif /* ( ADC_SAME_CHANNEL_QUEUING ==  STD_ON ) */
          
          /* Increment the loop count */
          LoopCount++;
        }/* While */

        /* The last channel is programmed for Source interrupt */
        /* Get the channel conf data for the channel index 
           in group definition */
        /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
        Group Configuration Structure and is within allowed range*/
        ChIdx = (GrpPtr->GroupDefinition)[LoopCount];
          
        /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
        Channel Configuration Structure and is within allowed range*/
        ChConfigData = ChCfgPtr[ChIdx].AdcChConfigValue;

        /* Get the internal Channel number from the Channel configuration */
        IntChNr = (Adc_ChannelType)Adc_lGetKernelChNum(ChConfigData);

        /* Prepare queue input register */
        /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
        access the SFRs of multiple ADC kernels*/
        ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].QINR0.U,  \
                           ((uint32)IntChNr | ADC_QUEUE_REFILL | EnableSrcInt));
        
        #if( ADC_SAME_CHANNEL_QUEUING ==  STD_ON )
        /* initialise the channel for Data Accumulation */
        /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
        access the SFRs of multiple ADC kernels*/
        ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].RCR[IntChNr].U,\
                                          ChCfgPtr[ChIdx].AdcChResAccumulation);
        #endif /* ( ADC_SAME_CHANNEL_QUEUING ==  STD_ON ) */
        
      }
      else /* Only one channel in a group */
      {
        /* Since there is only one channel in a group, the channel is 
           programmed for wait for trigger mode and enabled for interrupt */
        /* Get the channel conf data for the channel index 
           in group definition */
        /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
        Group Configuration Structure and is within allowed range*/
        ChIdx = (GrpPtr->GroupDefinition)[ADC_GROUP_FIRST_CH_INDEX];
          
        /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
        Channel Configuration Structure and is within allowed range*/
        ChConfigData = ChCfgPtr[ChIdx].AdcChConfigValue;

        /* Get the internal Channel number from the Channel configuration */
        IntChNr = (Adc_ChannelType)Adc_lGetKernelChNum(ChConfigData);

        /* Prepare queue input register */
        /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
        access the SFRs of multiple ADC kernels*/
        ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].QINR0.U,  \
                      ((uint32)IntChNr | ADC_QUEUE_REFILL | EnableSrcInt | \
                                               ADC_QUEUE_WAIT_TRIGGEVENT ));
        
        #if( ADC_SAME_CHANNEL_QUEUING ==  STD_ON )
        /* initialise the channel for Data Accumulation */
        /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
        access the SFRs of multiple ADC kernels*/
        ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].RCR[IntChNr].U,\
                                          ChCfgPtr[ChIdx].AdcChResAccumulation);
        #endif /* ( ADC_SAME_CHANNEL_QUEUING ==  STD_ON ) */
        
      }

      /* Queue trigger by HW event */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32(ADC_MODULE[AdcKernel].QMR0.U,  \
                                         (ADC_QUEUE_EXT_TRIG | (GateEnable)));
    } /* Queue request source */
    #endif /* RS0 used by any of the ADC kernel */

    break;
  /*IFX_MISRA_RULE_15_05_STATUS=Switch statement doesn't have case clause,
  only in case if Resquest Sources 0(RS0) is used and other 
  Resquest Sources are not not used*/
  }/*switch on request source */
  
  #if (ADC_TIMER_ERU_TRIGG == STD_ON )
  /* Enable the HW trigger for RS0 & RS1 */
  Adc_lSetHwTrigger(GrpPtr);
  #endif  /* (ADC_TIMER_ERU_TRIGG == STD_ON) */
} /* Adc_lStartHwConversionRS */

#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

#if (ADC_WAIT_ON_STOP == STD_ON)
/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Adc_lWaitForChConversion          **
**                    (                                                       **
**                      uint8 AdcKernel                                       **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters (in)  : Adc HW Unit ID                                          **
**                    Group request source stopped                            **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function                                           **
**  - Wait till the ADC conversion state becomes Idle. This will make sure    **
**    the channel under conversion is completed and its service request       **
**    is set (if enabled).                                                    **
**    If ADC Busy status is not reset even after Maximum channel conversion,  **
**    Report DEM                                                              **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE void Adc_lWaitForChConversion(uint8 AdcKernel)
{
  uint32          TimeOut;
  volatile uint32 SfrValue;

  TimeOut = ADC_MAX_CH_CON_TIME_COUNT;
  
  SfrValue = Adc_lReadArbCfgSfr(AdcKernel);
  
  while((( SfrValue & ADC_BUSY_SAMPLE_MASK ) != 0U ) && (TimeOut > 0U))
  {
    SfrValue = Adc_lReadArbCfgSfr(AdcKernel);

    TimeOut--;
  }
  
  return;
} /* Adc_lWaitForChConversion */
#endif /* (ADC_WAIT_ON_STOP == STD_ON) */

#if ( ADC_TIMER_TRIGG == STD_ON )
/*******************************************************************************
** Syntax           : void Adc_lGtmTimerCfg                                   **
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
** Description      : Is called when Timer trigger Group has requested for    **
**                    Enable Hardware                                         **
*******************************************************************************/
void Adc_lGtmTimerCfg(const Adc_GroupCfgType* GrpPtr)
{
  uint32 ReloadVal;
  Adc_GtmChIdentifierType GlobalChannelId; /* Structure to get Module info  */
  uint8  TimerChannel;
  uint8  ModuleNum;                       /* Holds the module number  */ 
  uint8  ChannelNum;                      /* Holds the channel number */ 

  /* Timer trigger selected */
  ReloadVal = GrpPtr->HwTimerValue;
  
  TimerChannel = (uint8)GrpPtr->HwTimerChannel;

  /* Extract the Module specific information */   
  GlobalChannelId = Adc_lGtmChannelIdentifier(TimerChannel);
  /* Extract the Module specific information */   
  ModuleNum = Adc_lGetGtmModuleNo(GlobalChannelId);
  ChannelNum = GlobalChannelId.ChannelNo;

  if(Adc_lGetGtmModuleId(GlobalChannelId) == ADC_GTM_ATOM_MODULE)
  {
    /* Reset the counter CN0 of ATOM */
    /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
    ADC_SFR_RUNTIME_USER_MODE_WRITE32(((*(Ifx_GTM_ATOMx*)(void*)               \
               (MODULE_GTM.ATOM)).ATOM_CH[ModuleNum].CH[ChannelNum].CN0.U), 0U);
    /* Set the Compare register CM0 of ATOM */
    /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
    ADC_SFR_RUNTIME_USER_MODE_WRITE32(((*(Ifx_GTM_ATOMx*)(void*)               \
         (MODULE_GTM.ATOM)).ATOM_CH[ModuleNum].CH[ChannelNum].CM0.U),          \
                                              (ReloadVal & ADC_GTM_TIMER_MASK));
    /* Set the Compare register CM1 of ATOM */
    /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
    ADC_SFR_RUNTIME_USER_MODE_WRITE32(((*(Ifx_GTM_ATOMx*)(void*)               \
            (MODULE_GTM.ATOM)).ATOM_CH[ModuleNum].CH[ChannelNum].CM1.U),       \
                        ((ReloadVal/ADC_TIMER_VALUE_DIV) & ADC_GTM_TIMER_MASK));
    /* Set the Shadow register SR0 of ATOM */
    /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
    ADC_SFR_RUNTIME_USER_MODE_WRITE32(((*(Ifx_GTM_ATOMx*)(void*)               \
         (MODULE_GTM.ATOM)).ATOM_CH[ModuleNum].CH[ChannelNum].SR0.U),          \
                                              (ReloadVal & ADC_GTM_TIMER_MASK));
    /* Set the Shadow register SR1 of ATOM */
    /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
    ADC_SFR_RUNTIME_USER_MODE_WRITE32(((*(Ifx_GTM_ATOMx*)(void*)               \
            (MODULE_GTM.ATOM)).ATOM_CH[ModuleNum].CH[ChannelNum].SR1.U),       \
                        ((ReloadVal/ADC_TIMER_VALUE_DIV) & ADC_GTM_TIMER_MASK));
    /* Enable the Atom channel */
    ADC_SFR_RUNTIME_USER_MODE_WRITE32(                                         \
            (MODULE_GTM.ATOM[ModuleNum].AGC.ENDIS_STAT.U),                     \
            (ADC_GTM_ATOM_ENABLE << (ADC_GTM_ATOM_BITS_PER_CHAN * ChannelNum)));

  }
  else
  {
    /* Reset the counter CN0 of TOM */
    /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
    ADC_SFR_RUNTIME_USER_MODE_WRITE32(((*(Ifx_GTM_TOMx*)(void*)               \
                (MODULE_GTM.TOM)).TOM_CH[ModuleNum].CH[ChannelNum].CN0.U), 0U);
    /* Set the Compare register CM0 of TOM */
    /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
    ADC_SFR_RUNTIME_USER_MODE_WRITE32(((*(Ifx_GTM_TOMx*)(void*)               \
         (MODULE_GTM.TOM)).TOM_CH[ModuleNum].CH[ChannelNum].CM0.U), ReloadVal);
    /* Set the Compare register CM1 of TOM */
    /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
    ADC_SFR_RUNTIME_USER_MODE_WRITE32(((*(Ifx_GTM_TOMx*)(void*)               \
            (MODULE_GTM.TOM)).TOM_CH[ModuleNum].CH[ChannelNum].CM1.U),        \
                                              (ReloadVal/ADC_TIMER_VALUE_DIV));
    
    /* Set the Shadow register SR0 of TOM */
    /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
    ADC_SFR_RUNTIME_USER_MODE_WRITE32(((*(Ifx_GTM_TOMx*)(void*)               \
         (MODULE_GTM.TOM)).TOM_CH[ModuleNum].CH[ChannelNum].SR0.U), ReloadVal);
    
    /* Set the Shadow register SR1 of TOM */
    /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
    ADC_SFR_RUNTIME_USER_MODE_WRITE32(((*(Ifx_GTM_TOMx*)(void*)               \
            (MODULE_GTM.TOM)).TOM_CH[ModuleNum].CH[ChannelNum].SR1.U),        \
                                              (ReloadVal/ADC_TIMER_VALUE_DIV));

    /* Enable the Tom channel */
    if(ChannelNum < ADC_GTM_TOM_TGC0_CHOSEN)
    {
     /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
     gives compile time warning in windriver compiler*/
     ADC_SFR_RUNTIME_USER_MODE_WRITE32((*(Ifx_GTM_TOMx*)(void*)               \
         (MODULE_GTM.TOM)).TOM_TGC[ModuleNum].TGC[ADC_GTM_TGC0].ENDIS_STAT.U, \
              (ADC_GTM_TOM_ENABLE <<(ADC_GTM_TOM_BITS_PER_CHAN * ChannelNum)));
    }
    else
    {
     /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
     gives compile time warning in windriver compiler*/
     ADC_SFR_RUNTIME_USER_MODE_WRITE32((*(Ifx_GTM_TOMx*)(void*)               \
         (MODULE_GTM.TOM)).TOM_TGC[ModuleNum].TGC[ADC_GTM_TGC1].ENDIS_STAT.U, \
         (ADC_GTM_TOM_ENABLE <<  (ADC_GTM_TOM_BITS_PER_CHAN *                 \
                                (ChannelNum - ADC_GTM_TOM_CHANNELS_PER_TGC))));
    }
  }

} /* Adc_lGtmTimerCfg */

/*******************************************************************************
** Syntax           : void Adc_lStopGtmTimer                                  **
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
** Description      : Is called when Timer trigger Group has requested for    **
**                    Disable Hardware                                        **
*******************************************************************************/
void Adc_lStopGtmTimer(const Adc_GroupCfgType* GrpPtr)
{
  Adc_GtmChIdentifierType GlobalChannelId; /* Structure to get Module info  */
  uint8  TimerChannel;
  uint8  ModuleNum;                       /* Holds the module number  */ 
  uint8  ChannelNum;                      /* Holds the channel number */ 

  TimerChannel = (uint8)GrpPtr->HwTimerChannel;

  /* Extract the Module specific information */   
  GlobalChannelId = Adc_lGtmChannelIdentifier(TimerChannel);
  /* Extract the Module specific information */   
  ModuleNum = Adc_lGetGtmModuleNo(GlobalChannelId);
  ChannelNum = GlobalChannelId.ChannelNo;

  if(Adc_lGetGtmModuleId(GlobalChannelId) == ADC_GTM_ATOM_MODULE)
  {
    /* Disable the Atom channel */
    ADC_SFR_RUNTIME_USER_MODE_WRITE32(                                         \
      (MODULE_GTM.ATOM[ModuleNum].AGC.ENDIS_STAT.U),                           \
      (ADC_GTM_ATOM_CHAN_DISABLE << (ADC_GTM_ATOM_BITS_PER_CHAN * ChannelNum)));
    /* Reset the counter CN0 */
    /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
    ADC_SFR_RUNTIME_USER_MODE_WRITE32(((*(Ifx_GTM_ATOMx*)(void*)               \
               (MODULE_GTM.ATOM)).ATOM_CH[ModuleNum].CH[ChannelNum].CN0.U), 0U);
    /* Reset the Compare register CM0*/
    /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
    ADC_SFR_RUNTIME_USER_MODE_WRITE32(((*(Ifx_GTM_ATOMx*)(void*)               \
               (MODULE_GTM.ATOM)).ATOM_CH[ModuleNum].CH[ChannelNum].CM0.U), 0U);
    /* Reset the Compare register CM1*/
    /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
    ADC_SFR_RUNTIME_USER_MODE_WRITE32(((*(Ifx_GTM_ATOMx*)(void*)               \
               (MODULE_GTM.ATOM)).ATOM_CH[ModuleNum].CH[ChannelNum].CM1.U), 0U);
    /* Reset the Shadow register SR0*/
    /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
    ADC_SFR_RUNTIME_USER_MODE_WRITE32(((*(Ifx_GTM_ATOMx*)(void*)               \
               (MODULE_GTM.ATOM)).ATOM_CH[ModuleNum].CH[ChannelNum].SR0.U), 0U);
    /* Reset the Shadow register SR1*/
    /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
    ADC_SFR_RUNTIME_USER_MODE_WRITE32(((*(Ifx_GTM_ATOMx*)(void*)               \
               (MODULE_GTM.ATOM)).ATOM_CH[ModuleNum].CH[ChannelNum].SR1.U), 0U);
  }
  else
  {
    /* Disable the Tom channel */
    if(ChannelNum < ADC_GTM_TOM_TGC0_CHOSEN)
    {
      /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
      gives compile time warning in windriver compiler*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32((*(Ifx_GTM_TOMx*)(void*)               \
      (MODULE_GTM.TOM)).TOM_TGC[ModuleNum].TGC[ADC_GTM_TGC0].ENDIS_STAT.U,     \
        (ADC_GTM_TOM_CHAN_DISABLE << (ADC_GTM_TOM_BITS_PER_CHAN * ChannelNum)));
    }
    else
    {
      /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
      gives compile time warning in windriver compiler*/
      ADC_SFR_RUNTIME_USER_MODE_WRITE32((*(Ifx_GTM_TOMx*)(void*)               \
      (MODULE_GTM.TOM)).TOM_TGC[ModuleNum].TGC[ADC_GTM_TGC1].ENDIS_STAT.U,     \
                       (ADC_GTM_TOM_CHAN_DISABLE <<(ADC_GTM_TOM_BITS_PER_CHAN *\
                                 (ChannelNum - ADC_GTM_TOM_CHANNELS_PER_TGC))));
    }

    /* Reset the counter CN0 of TOM */
    /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
    ADC_SFR_RUNTIME_USER_MODE_WRITE32(((*(Ifx_GTM_TOMx*)(void*)                \
                 (MODULE_GTM.TOM)).TOM_CH[ModuleNum].CH[ChannelNum].CN0.U), 0U);
    /* Reset the Compare register CM0 of TOM */
    /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
    ADC_SFR_RUNTIME_USER_MODE_WRITE32(((*(Ifx_GTM_TOMx*)(void*)                \
                 (MODULE_GTM.TOM)).TOM_CH[ModuleNum].CH[ChannelNum].CM0.U), 0U);
    /* Reset the Compare register CM1 of TOM */
    /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
    ADC_SFR_RUNTIME_USER_MODE_WRITE32(((*(Ifx_GTM_TOMx*)(void*)                \
                 (MODULE_GTM.TOM)).TOM_CH[ModuleNum].CH[ChannelNum].CM1.U), 0U);
    
    /* Reset the Shadow register SR0 of TOM */
    /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
    ADC_SFR_RUNTIME_USER_MODE_WRITE32(((*(Ifx_GTM_TOMx*)(void*)                \
                 (MODULE_GTM.TOM)).TOM_CH[ModuleNum].CH[ChannelNum].SR0.U), 0U);
    
    /* Reset the Shadow register SR1 of TOM */
    /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
    ADC_SFR_RUNTIME_USER_MODE_WRITE32(((*(Ifx_GTM_TOMx*)(void*)                \
                 (MODULE_GTM.TOM)).TOM_CH[ModuleNum].CH[ChannelNum].SR1.U), 0U);
  }
} /* Adc_lStopGtmTimer */

/*******************************************************************************
** Syntax: IFX_LOCAL_INLINE Adc_GtmChIdentifierType Adc_lGtmChannelIdentifier **
**                                               (uint8 GlobalChannelNumber)  **
**                                                                            **
** Service ID:    None                                                        **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Reentrant                                                   **
**                                                                            **
** Parameters (in):    GlobalChannelNumber - Channel Number                   **
**                                                                            **
** Parameters (out):   None                                                   **
**                                                                            **
** Return value:  Structure which gives Module Number, Channel Number etc     **
**                                                                            **
** Description :  This routine converts the Global Channel Number to its      **
**                corresponding Channel Number, Module Number, TGC/AGC number.**
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE Adc_GtmChIdentifierType Adc_lGtmChannelIdentifier
(
  uint8 GlobalChannelNumber
)
{
  Adc_GtmChIdentifierType ChannelIdentifier;
  uint8 TempChannelNumber;
  
  ChannelIdentifier.ChannelNo = ADC_GTM_CHANNEL_INVALID;
  ChannelIdentifier.ModuleId = ADC_GTM_CHANNEL_INVALID;


  /* Check if its a TOM channel */    
  if(GlobalChannelNumber < (ADC_GTM_MAX_TOM_CHANNELS + 
                                                   ADC_GTM_MAX_TIM_CHANNELS))
  {
    TempChannelNumber = GlobalChannelNumber - ADC_GTM_MAX_TIM_CHANNELS;
    /* Calculate Module Id of the TOM channel */    
    ChannelIdentifier.ModuleId  =                    \
   (uint8)((TempChannelNumber / ADC_GTM_CHANNELS_PER_TOM_MODULE)               \
                                             << ADC_GTM_CHAN_ID_MOD_NO_POS) |  \
   (uint8)(((uint8)ADC_GTM_TOM_MODULE) << ADC_GTM_CHAN_ID_MOD_ID_POS)       |  \
   ((TempChannelNumber / ADC_GTM_TOM_CHANNELS_PER_TGC) % \
                                                 ADC_GTM_NO_OF_TGC_PER_MODULE );

    /* Calculate Channel number of the TOM channel */
    ChannelIdentifier.ChannelNo = 
                           TempChannelNumber % ADC_GTM_CHANNELS_PER_TOM_MODULE;
  } 

  /* Check if its a ATOM channel */   
  if((GlobalChannelNumber >= (ADC_GTM_MAX_TOM_CHANNELS + 
                                                    ADC_GTM_MAX_TIM_CHANNELS)) 
    )
  {

    TempChannelNumber =  GlobalChannelNumber - \
                         (ADC_GTM_MAX_TIM_CHANNELS + ADC_GTM_MAX_TOM_CHANNELS);
    /* Calculate Module Id of the ATOM channel */    
    ChannelIdentifier.ModuleId  =                                   \
    ((uint8)((TempChannelNumber / ADC_GTM_CHANNELS_PER_ATOM_MODULE)           \
                                            << ADC_GTM_CHAN_ID_MOD_NO_POS)   |\
    ((TempChannelNumber/ADC_GTM_ATOM_CHANNELS_PER_AGC) % \
                                                ADC_GTM_NO_OF_AGC_PER_MODULE)|\
    (uint8)(((uint8)ADC_GTM_ATOM_MODULE) << ADC_GTM_CHAN_ID_MOD_ID_POS ));

    /* Calculate Channel number of the ATOM channel */
    ChannelIdentifier.ChannelNo = 
                           TempChannelNumber % ADC_GTM_CHANNELS_PER_ATOM_MODULE;
  }
  
  return (ChannelIdentifier);
}

/*******************************************************************************
** Syntax :           IFX_LOCAL_INLINE uint8 Adc_lGetGtmModuleNo              **
**                                (                                           **
**                                  Adc_GtmChIdentifierType ChannelId         **
**                                )                                           **
**                                                                            **
** Service ID:        none                                                    **
**                                                                            **
** Sync/Async:        Synchronous                                             **
**                                                                            **
** Reentrancy:        reentrant                                               **
**                                                                            **
** Parameters (in):   ChannelId : GTM Global Channel Number                   **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:      none                                                    **
**                                                                            **
** Description :      Local function :To derive the TOM/ATOM Module number    **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE uint8 Adc_lGetGtmModuleNo(Adc_GtmChIdentifierType ChannelId)
{
  return((ChannelId.ModuleId & ADC_GTM_MODULE_NO_MSK) >> ADC_GTM_MODULE_NO_POS);
}

/*******************************************************************************
** Syntax :           IFX_LOCAL_INLINE uint8 Adc_lGetGtmModuleId              **
**                                (                                           **
**                                  Adc_GtmChIdentifierType ChannelId         **
**                                )                                           **
**                                                                            **
** Service ID:        none                                                    **
**                                                                            **
** Sync/Async:        Synchronous                                             **
**                                                                            **
** Reentrancy:        reentrant                                               **
**                                                                            **
** Parameters (in):   ChannelId : GTM Global Channel Number                   **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:      none                                                    **
**                                                                            **
** Description :      Local function :To identify if it is TOM or ATOM        **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE uint8 Adc_lGetGtmModuleId(Adc_GtmChIdentifierType ChannelId)
{
  return((ChannelId.ModuleId & ADC_GTM_MODULE_ID_MSK) >> ADC_GTM_MODULE_ID_POS);
}

#endif /*  ADC_TIMER_TRIGG == STD_ON */

#if ( ADC_ERU_TRIGG == STD_ON )
/*******************************************************************************
** Syntax           : void Adc_lEruTrigCfg                                    **
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
** Parameters(in)   : Group HW Configuration                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called when ERU trigger Group has requested for      **
**                    Enable Hardware                                         **
*******************************************************************************/
void Adc_lEruTrigCfg(uint32 HwCfgData)
{
  uint32 EruUnit;
  uint32 EruRegPos;
  uint32 EruReg;
  uint32 EruCfgData;
  uint32 TriggMode;
  uint32 EruOguUnit;
  uint32 EruOguReg;
  uint32 EruOguRegPos;

  /* Trigger event upon falling / rising edge */
  TriggMode = 
         Adc_lGetRsCtrlData(HwCfgData,ADC_XTMODE_POS,ADC_ERU_EDGE_SHIFT_POS);

  /* Get the Configured ERU Unit */
  EruUnit = (uint32)Adc_lGetEruUnit(HwCfgData);

  EruRegPos = ((EruUnit & (uint32)0x1) << ADC_ERU_EICR_PROG_POS);

  EruReg = ((EruUnit >> 1U) & (uint32)ADC_ERU_UNIT_REG_CALC);

  EruCfgData = ( ((HwCfgData >> ADC_ERU_DATA_POS) | TriggMode ) & 
                                                   (uint32)ADC_ERU_CFG_BITS);
  /* Get the Configured ERU OGU Unit */
  EruOguUnit = (uint32)Adc_lGetEruOguUnit(HwCfgData);

  EruOguReg = ((EruOguUnit >> 1U) & (uint32)ADC_ERU_UNIT_REG_CALC);

  EruOguRegPos = ((EruOguUnit & (uint32)0x1) << ADC_ERU_IGCR_PROG_POS);

  /* Set the EICR */
  ADC_SFR_RUNTIME_USER_MODE_MCAL_SETATOMIC(
    ((sint32 *)(void *)&(MODULE_SCU.EICR[EruReg])), 
    (uint32)EruCfgData, 
    (sint32)EruRegPos,
    ADC_ERU_DATA_BITS );

  /* Set the IGCR */
  ADC_SFR_RUNTIME_USER_MODE_MCAL_SETATOMIC(
    ((sint32 *)(void *)&MODULE_SCU.IGCR[EruOguReg]), 
    (uint32)ADC_ERU_IGP_ACTIVATE, 
    (sint32)EruOguRegPos,
    ADC_ERU_DATA_BITS );


} /* Adc_lEruTrigCfg */
#endif /*  ADC_ERU_TRIGG == STD_ON */

#if ( ADC_ERU_GATING == STD_ON )
/*******************************************************************************
** Syntax           : void Adc_lEruGateCfg                                    **
**                    (                                                       **
**                       uint32 HwGateData                                    **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Group HW Configuration                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called when ERU Gate Group has requested for         **
**                    Enable Hardware                                         **
*******************************************************************************/
void Adc_lEruGateCfg(uint32 HwGateData)
{
  uint32 EruUnit;
  uint32 EruRegPos;
  uint32 EruReg;
  uint32 EruCfgData;
  uint32 EruPatternData;
  uint32 GatePattern; 
  uint32 EruOguUnit;
  uint32 EruOguReg;
  uint32 EruOguRegPos;


  /* Get the Configured ERU Unit */
  EruUnit = (uint32)Adc_lGetEruUnit(HwGateData);

  EruRegPos = ((EruUnit & (uint32)0x1) << ADC_ERU_EICR_PROG_POS);

  EruReg = ((EruUnit >> 1U) & (uint32)ADC_ERU_UNIT_REG_CALC);

  EruCfgData = ( ((HwGateData >> ADC_ERU_DATA_POS) | \
                (uint32)ADC_ERU_LEVEL_DETECTION ) &  (uint32)ADC_ERU_CFG_BITS);

  /* Get the Gate enable selection */
  GatePattern = ((uint32)Adc_lGetEngtVal(HwGateData))<< (uint32)ADC_ERU_IGP_POS;

  EruPatternData = ((1UL << EruUnit) | GatePattern );

  /* Get the Configured ERU OGU Unit */
  EruOguUnit = (uint32)Adc_lGetEruOguUnit(HwGateData);

  EruOguReg = ((EruOguUnit >> 1U) & (uint32)ADC_ERU_UNIT_REG_CALC);

  EruOguRegPos = ((EruOguUnit & (uint32)0x1) << ADC_ERU_IGCR_PROG_POS);

  /* Set the EICR */
  ADC_SFR_RUNTIME_USER_MODE_MCAL_SETATOMIC(
    (sint32 *)(void *)&MODULE_SCU.EICR[EruReg], 
    (uint32)EruCfgData, 
    (sint32)EruRegPos,
    ADC_ERU_DATA_BITS );

  /* Set the IGCR */
  ADC_SFR_RUNTIME_USER_MODE_MCAL_SETATOMIC(
    (sint32 *)(void *)&MODULE_SCU.IGCR[EruOguReg], 
    (uint32)EruPatternData, 
    (sint32)EruOguRegPos,
    ADC_ERU_DATA_BITS );
  
} /* Adc_lEruGateCfg */
#endif /*  ADC_ERU_GATING == STD_ON */

#if ( ADC_ERU_TRIGG == STD_ON )
/*******************************************************************************
** Syntax           : void Adc_lResetEruCfg                                   **
**                    (                                                       **
**                       uint32 HwCfgData                                     **
**                       uint8 ApiAccessId                                    **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Group HW Configuration                                  **
**                    Id to identify the type of called api                   **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called when ERU trigger Group has requested for      **
**                    Disable Hardware                                        **
*******************************************************************************/
void Adc_lResetEruCfg(uint32 HwCfgData, uint8 ApiAccessId)
{
  uint32 EruUnit;
  uint32 EruRegPos;
  uint32 EruReg;
  uint32 EruOguUnit;
  uint32 EruOguReg;
  uint32 EruOguRegPos;

  /* Get the Configured ERU Unit */
  EruUnit = (uint32)Adc_lGetEruUnit(HwCfgData);

  EruRegPos = ((EruUnit & (uint32)0x1) << ADC_ERU_EICR_PROG_POS);

  EruReg = ((EruUnit >> 1U) & (uint32)ADC_ERU_UNIT_REG_CALC);

  /* Get the Configured ERU OGU Unit */
  EruOguUnit = (uint32)Adc_lGetEruOguUnit(HwCfgData);

  EruOguReg = ((EruOguUnit >> 1U) & (uint32)ADC_ERU_UNIT_REG_CALC);

  EruOguRegPos = ((EruOguUnit & (uint32)0x1) << ADC_ERU_IGCR_PROG_POS);

  /* Reset the EICR */
  if(ApiAccessId == ADC_RUNTIME_ACCESS)
  { 
    ADC_SFR_RUNTIME_USER_MODE_MCAL_SETATOMIC(
      ((sint32 *)(void *)&MODULE_SCU.EICR[EruReg]), 
      (uint32)ADC_ERU_RESET_DATA, 
      (sint32)EruRegPos,
      ADC_ERU_DATA_BITS );

    /* Reset the IGCR */
    ADC_SFR_RUNTIME_USER_MODE_MCAL_SETATOMIC(
      ((sint32 *)(void *)&MODULE_SCU.IGCR[EruOguReg]), 
      (uint32)ADC_ERU_RESET_DATA, 
      (sint32)EruOguRegPos,
      ADC_ERU_DATA_BITS );
  }
  else
  {
    ADC_SFR_INIT_USER_MODE_MCAL_SETATOMIC(
      ((sint32 *)(void *)&MODULE_SCU.EICR[EruReg]), 
      (uint32)ADC_ERU_RESET_DATA, 
      (sint32)EruRegPos,
      ADC_ERU_DATA_BITS );

    /* Reset the IGCR */
    ADC_SFR_INIT_USER_MODE_MCAL_SETATOMIC(
      ((sint32 *)(void *)&MODULE_SCU.IGCR[EruOguReg]), 
      (uint32)ADC_ERU_RESET_DATA, 
      (sint32)EruOguRegPos,
      ADC_ERU_DATA_BITS );
      
  }
    
} /* Adc_lResetEruCfg */
#endif /*  ADC_ERU_TRIGG == STD_ON  */

#if ( ADC_ERU_GATING == STD_ON )
/*******************************************************************************
** Syntax           : void Adc_lResetEruGateCfg                               **
**                    (                                                       **
**                       uint32 HwGateData                                    **
**                       uint8 ApiAccessId                                    **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Group HW Configuration                                  **
**                    Id to identify the type of called api                   **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called when ERU gate Group has requested for         **
**                    Disable Hardware                                        **
*******************************************************************************/
void Adc_lResetEruGateCfg(uint32 HwGateData, uint8 ApiAccessId)
{
  uint32 EruUnit;
  uint32 EruRegPos;
  uint32 EruReg;
  uint32 EruOguUnit;
  uint32 EruOguReg;
  uint32 EruOguRegPos;

  /* Get the Configured ERU Unit */
  EruUnit = (uint32)Adc_lGetEruUnit(HwGateData);

  EruRegPos = ((EruUnit & (uint32)0x1) << ADC_ERU_EICR_PROG_POS);

  EruReg = ((EruUnit >> 1U) & (uint32)ADC_ERU_UNIT_REG_CALC);

  /* Get the Configured ERU OGU Unit */
  EruOguUnit = (uint32)Adc_lGetEruOguUnit(HwGateData);

  EruOguReg = ((EruOguUnit >> 1U) & (uint32)ADC_ERU_UNIT_REG_CALC);

  EruOguRegPos = ((EruOguUnit & (uint32)0x1) << ADC_ERU_IGCR_PROG_POS);

  if(ApiAccessId == ADC_RUNTIME_ACCESS)
  {
    /* Reset the EICR */
    ADC_SFR_RUNTIME_USER_MODE_MCAL_SETATOMIC(
      (sint32 *)(void *)&MODULE_SCU.EICR[EruReg], 
      (uint32)ADC_ERU_RESET_DATA, 
      (sint32)EruRegPos,
      ADC_ERU_DATA_BITS );

    /* Reset the IGCR */
    ADC_SFR_RUNTIME_USER_MODE_MCAL_SETATOMIC(
      (sint32 *)(void *)&MODULE_SCU.IGCR[EruOguReg], 
      (uint32)ADC_ERU_RESET_DATA, 
      (sint32)EruOguRegPos,
      ADC_ERU_DATA_BITS );
  }
  else
  {
    /* Reset the EICR */
    ADC_SFR_INIT_USER_MODE_MCAL_SETATOMIC(
      (sint32 *)(void *)&MODULE_SCU.EICR[EruReg], 
      (uint32)ADC_ERU_RESET_DATA, 
      (sint32)EruRegPos,
      ADC_ERU_DATA_BITS );

    /* Reset the IGCR */
    ADC_SFR_INIT_USER_MODE_MCAL_SETATOMIC(
      (sint32 *)(void *)&MODULE_SCU.IGCR[EruOguReg], 
      (uint32)ADC_ERU_RESET_DATA, 
      (sint32)EruOguRegPos,
      ADC_ERU_DATA_BITS );
  }
  
} /* Adc_lResetEruGateCfg */
#endif /*  ADC_ERU_GATING == STD_ON  */

#if ( (ADC_DEV_ERROR_DETECT == STD_ON) && \
                                   (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) )
/*******************************************************************************
** Syntax           : uint32 Adc_lSwConvDetCheck                              **
**                    (                                                       **
**                      uint8 ServiceId,                                      **
**                      uint8 AdcKernel,                                      **
**                      Adc_GroupType Group                                   **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters(in)   : ServiceId - Service ID of the calling API               **
**                    AdcKernel - Group HW Unit ID                            **
**                    Group - Group Number                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Error code if error detected else ADC_E_DET_NO_ERR      **
**                                                                            **
** Description      : Local funtion :                                         **
**                    Service for validating the group parameters and         **
**                    reporting DET                                           **
**                                                                            **
*******************************************************************************/
uint32 Adc_lSwConvDetCheck
(
  uint8 ServiceId, 
  uint8 AdcKernel,
  Adc_GroupType Group
)
{
  #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
  Adc_GlobalDataType         *DataPtr;
  #endif
  const Adc_GroupCfgType     *GrpPtr;
  const Adc_KernelConfigType *CfgPtr;
  uint32                     RetErr;

  RetErr = ADC_E_DET_NO_ERR;

  #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
  /* Get ADC Kernel index for variables */
  /* Assign the address of ASIL or QM signal variable to global data pointer*/
  DataPtr = Adc_lGetDataAddress(AdcKernel);
  #endif
  CfgPtr = Adc_kConfigPtr->CfgPtr[AdcKernel];
  
  /* Parameter Group ID is valid check for other errors */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
  Group Configuration Structure and is within allowed range*/
  GrpPtr = (CfgPtr->GrpCfgPtr + Group);
  
  
  if ( GrpPtr->TriggSrc != ADC_TRIGG_SRC_SW)
  {
    /* ADC133: Group with trigger source not configured as Software */
    Det_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE, 
                     ServiceId, ADC_E_WRONG_TRIGG_SRC
                   );    
    RetErr = (uint32)ADC_E_WRONG_TRIGG_SRC;
  }
  #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
  else if (DataPtr->GroupResultBuffer[Group] == NULL_PTR)
  {
    /* ADC133: Group is not initialised for Result buffer */
    Det_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE, 
                     ServiceId, ADC_E_BUFFER_UNINIT
                   );    
    RetErr = (uint32)ADC_E_BUFFER_UNINIT;
  }
  else
  {
    /* Do Nothing */
  }
  #endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */
  
  return(RetErr);
} /* Adc_lSwConvDetCheck */
#endif
/*(ADC_DEV_ERROR_DETECT==STD_ON) And (ADC_ENABLE_START_STOP_GROUP_API==STD_ON)*/

#if ( (ADC_DEV_ERROR_DETECT == STD_ON) && (ADC_HW_TRIGGER_API == STD_ON) )
/*******************************************************************************
** Syntax           : uint32 Adc_lValParamGrpEnableHwTrigg                    **
**                    (                                                       **
**                      uint8 ServiceId,                                      **
**                      Adc_GroupType Group,                                  **
**                      uint8 AdcKernel                                       **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters(in)   : ServiceId - Service ID of the calling API               **
**                    Group - Numeric ID of requested ADC Channel group       **
**                    AdcKernel - Group HW Unit ID                            **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Error code if error detected else ADC_E_DET_NO_ERR      **
**                                                                            **
** Description      : Local funtion :                                         **
**                    Service for validating the group parameters and         **
**                    reporting DET for Enable Hardware Trigger API           **
**                                                                            **
** Traceability:                                                              **
** [cover parentID=DS_NAS_ADC_PR127_3] [/cover]                               **
**                                                                            **
*******************************************************************************/
uint32 Adc_lValParamGrpEnableHwTrigg
(uint8 ServiceId, Adc_GroupType Group, uint8 AdcKernel)
{
  #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
  Adc_GlobalDataType         *DataPtr;
  #endif
  const Adc_GroupCfgType     *GrpPtr;
  const Adc_KernelConfigType *CfgPtr;
  uint32                     RetErr;

  RetErr = ADC_E_DET_NO_ERR;

  #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
  /* Get ADC Kernel index for variables */
  /* Assign the address of ASIL or QM signal variable to global data pointer*/
  DataPtr = Adc_lGetDataAddress(AdcKernel);
  #endif
  CfgPtr = Adc_kConfigPtr->CfgPtr[AdcKernel];
  
  /* Parameter Group ID is valid check for other errors */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
  Group Configuration Structure and is within allowed range*/
  GrpPtr = (CfgPtr->GrpCfgPtr + Group);
  

  if ( GrpPtr->TriggSrc != ADC_TRIGG_SRC_HW)
  {
    /* ADC136: Group with trigger source not configured as Hardware */
    Det_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE, 
                     ServiceId, ADC_E_WRONG_TRIGG_SRC
                   );    
    RetErr = (uint32)ADC_E_WRONG_TRIGG_SRC;
  }
  else if (GrpPtr->ConvMode == ADC_CONV_MODE_CONTINUOUS)
  {
    /* ADC281: Service is called for group with continuous mode, 
       report the DET error */
    Det_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE, 
                     ServiceId, ADC_E_WRONG_CONV_MODE
                   );    
    RetErr = ADC_E_WRONG_CONV_MODE;
  }
  #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
  else if (DataPtr->GroupResultBuffer[Group] == NULL_PTR)
  {
    /* ADC133: Group with trigger source not configured as Software */
    Det_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE, 
                     ServiceId, ADC_E_BUFFER_UNINIT
                   );    
    RetErr = (uint32)ADC_E_BUFFER_UNINIT;
  }
  #endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */
  else
  {
    /* Do Nothing */
  }

  return RetErr;
  
} /* Adc_lValParamGrpEnableHwTrigg */

#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) And (ADC_HW_TRIGGER_API == STD_ON)*/

/*******************************************************************************
** Traceabilty      :[cover parentID=DS_AS_ADC311]                            **
** Syntax           : static void Adc_lKernelInit                             **
**                    (                                                       **
**                       const Adc_KernelConfigType  *AdcKernelPtr,           **
**                       uint8 AdcKernel                                      **
**                    )                                                       **
**[/cover]                                                                    **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : AdcKernelPtr - Kernel cfg ptr ,                         **
**                    AdcKernel - kernel to be initialised                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called from Init to initialise the kernel specific   **
**                    register                                                **
*******************************************************************************/
static void Adc_lKernelInit
(
  const Adc_KernelConfigType  *AdcKernelPtr,
  uint8 AdcKernel
)
{
  #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
  Adc_GlobalDataType      *DataPtr;
  #endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */
  const Adc_HwUnitCfgType *HwCfgPtr;
  uint32                  LoopCtr;
  uint32                  SfrValue;

  /* Initialise ADC Kernel */
  
  /* Get ADC kernel HW Unit Config pointer */
  HwCfgPtr = AdcKernelPtr->HwCfgPtr;
  
  /* Configuration of ANONC, ARBRND, ARBM */
  SfrValue =  ((HwCfgPtr->ArbitrationLength) | \
               (uint32)(Adc_kConfigPtr->GlobCfgPtr->OperationMode));
  
  Adc_lWriteArbCfgSfr(AdcKernel, SfrValue);
  
  /* Enable all the request sources for arbitration
     Request source priority configuration
     Cancel inject repeat mode */
  SfrValue =  ( (HwCfgPtr->TriggSrcArbLevel) | 
                (ADC_REQSRC_ARB_ENABLE << ADC_REQ_ARB_SLOT_SHIFT)
              );
  
  Adc_lWriteArbPrSfr(AdcKernel, SfrValue);

  /* Configuration of 2 kernel Input class control register */
  LoopCtr = (uint32)0;
  do
  {
    SfrValue = HwCfgPtr->KernelInputClass[LoopCtr];
    
    Adc_lWriteGrpIpClassSfr(AdcKernel, (uint8)LoopCtr, SfrValue);
    
    LoopCtr++;
  } while (LoopCtr < ADC_NO_KERNEL_INP_CLASS);

  #if( ADC_MASTER_SLAVE_SYNC == STD_ON )

  SfrValue = ((uint32)HwCfgPtr->SyncConvMode | (uint32)HwCfgPtr->SlaveReady);
  
  Adc_lWriteSynCtrSfr(AdcKernel, SfrValue);
  
  #endif /* ( ADC_MASTER_SLAVE_SYNC == STD_ON ) */


  /* Initialise the Event Node Pointer Register as per the design */
  /* Event node pointer for all request source is initialised with designed 
   value even when some of the request source is not in use */

  Adc_lWriteSrcEvntNpSfr(AdcKernel, ADC_RS0_RS1_NODEPOINTER);

  #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)

  /* Get ADC Kernel index for variables */
  /* Assign the address of ASIL or QM signal variable to global data pointer*/
  DataPtr = Adc_lGetDataAddress(AdcKernel);

  /* Initialisation of ADC0 Global variable */
  LoopCtr = (uint32)0;
  #if (ADC_MAX_GROUPS > 1U)
  do
  #endif /* loop only when (ADC_MAX_GROUPS > 1U) */
  {
    /* Initialize the number of conversion result set available to 0 */
    DataPtr->NumValidConRes[LoopCtr] = (Adc_StreamNumSampleType)0;

    #if (ADC_MAX_GROUPS > 1U)
    LoopCtr++;
    #endif 
  }
  #if (ADC_MAX_GROUPS > 1U)
  while (LoopCtr < ADC_MAX_GROUPS);
  #endif /* loop only when (ADC_MAX_GROUPS > 1U) */
  
  #endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */
  
} /* Adc_lKernelInit */

#if (ADC_RESULT_POLLING_MODE == STD_OFF)
/*******************************************************************************
** Syntax           : void Adc_lInitSetResetSre                               **
**                    (                                                       **
**                       uint32 AdcSreValue                                   **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : AdcSreValue - Value to be written in SRE bit of SRC reg **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called from Init to initialise the SRE bit of SRC    **
                      registers                                               **
*******************************************************************************/
void Adc_lInitSetResetSre(uint32 AdcSreValue)
{
  uint32                  LoopCtr;
  #if ( ADC_GROUP_EMUX_SCAN == STD_ON )
  uint32                  EmuxKernel;
  uint16                  AdcKernel;
  #endif /* ( ADC_GROUP_EMUX_SCAN == STD_ON ) */
  
  LoopCtr = 0U;
  do
  {
    if(Adc_lQueueRSConfigured((uint8)LoopCtr) != 0U)
    {
      /* ADC SRN0 is used by request source 0 of ADC kernel */
      ADC_SFR_INIT_MODIFY32(MODULE_SRC.VADC.G[LoopCtr].SR0.U,  \
                ADC_SRC_SRCR_MSK, ((uint32)AdcSreValue << IFX_SRC_SRCR_SRE_OFF))
    }
  
    LoopCtr++;
    
  } while (LoopCtr < ADC_MAX_KERNELS);
  
  LoopCtr = 0U;
  do
  {
    if(Adc_lAutoScanConfigured((uint8)LoopCtr) != 0U)
    {
      /* ADC SRN1 is used by request source 1 of ADC kernel */
      ADC_SFR_INIT_MODIFY32(MODULE_SRC.VADC.G[LoopCtr].SR1.U,  \
                ADC_SRC_SRCR_MSK, ((uint32)AdcSreValue << IFX_SRC_SRCR_SRE_OFF))
    }
  
    LoopCtr++;
    
  } while (LoopCtr < ADC_MAX_KERNELS);
  
  
  /* Common Group 0 SRN0 is used by request source 2 */
  #if (ADC_REQSRC2 == ADC_REQSRC_USED)
  
  ADC_SFR_INIT_MODIFY32(MODULE_SRC.VADC.CG[0].SR0.U,  \
                ADC_SRC_SRCR_MSK, ((uint32)AdcSreValue << IFX_SRC_SRCR_SRE_OFF))
  
  #endif /* (ADC_REQSRC2 is used) */
  
  #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
  
  LoopCtr = 0U;
  do
  {
    if(Adc_lLimitChkConfigured((uint8)LoopCtr) != 0U)
    {
      /* ADC SRN2 is used by Channel Event - Limit check of ADC kernel */
      ADC_SFR_INIT_MODIFY32(MODULE_SRC.VADC.G[LoopCtr].SR2.U,  \
                ADC_SRC_SRCR_MSK, ((uint32)AdcSreValue << IFX_SRC_SRCR_SRE_OFF))
    }
  
    LoopCtr++;
    
  } while (LoopCtr < ADC_MAX_KERNELS);
  
  #endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  
  #if ( ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR ) 
  
  LoopCtr = 0U;
  do
  {
    if(Adc_lKernelConfigured((uint8)LoopCtr) != 0U)
    {
      /* ADC SRN3 is used for Non AS Dma transfer of ADC kernel */
      ADC_SFR_INIT_MODIFY32(MODULE_SRC.VADC.G[LoopCtr].SR3.U,  \
                ADC_SRC_SRCR_MSK, ((uint32)AdcSreValue << IFX_SRC_SRCR_SRE_OFF))
    }
  
    LoopCtr++;
    
  } while (LoopCtr < ADC_MAX_KERNELS);
  
  #elif ( ADC_GROUP_EMUX_SCAN == STD_ON )
  
  EmuxKernel = Adc_kConfigPtr->GlobCfgPtr->EmuxSelectGrp;
  LoopCtr = 0U;
  do
  {
    AdcKernel = Adc_lGetEmuxKernel(EmuxKernel,(uint8)LoopCtr);

    /* ADC SRN3 is used for Non AS Dma transfer of ADC kernel */
    ADC_SFR_INIT_MODIFY32(MODULE_SRC.VADC.G[AdcKernel].SR3.U,  \
                ADC_SRC_SRCR_MSK, ((uint32)AdcSreValue << IFX_SRC_SRCR_SRE_OFF))

    LoopCtr++;
    
  } while (LoopCtr < ADC_MAX_EMUX_KERNELS);

  #endif 
  /* (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR) || 
                                             (ADC_GROUP_EMUX_SCAN == STD_ON)*/
} /* Adc_lInitSetResetSre */
#if (ADC_DEINIT_API == STD_ON)
/*******************************************************************************
** Syntax           : void Adc_lDeInitSetResetSre                             **
**                    (                                                       **
**                       uint32 AdcSreValue                                   **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : AdcSreValue - Value to be written in SRE bit of SRC reg **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called from DeInit to Deinitialize the SRE bit of    **
                      SRC registers                                           **
*******************************************************************************/
void Adc_lDeInitSetResetSre(uint32 AdcSreValue)
{
  uint32                  LoopCtr;
  #if ( ADC_GROUP_EMUX_SCAN == STD_ON )
  uint32                  EmuxKernel;
  uint16                  AdcKernel;
  #endif /* ( ADC_GROUP_EMUX_SCAN == STD_ON ) */
  
  LoopCtr = 0U;
  do
  {
    if(Adc_lQueueRSConfigured((uint8)LoopCtr) != 0U)
    {
      /* ADC SRN0 is used by request source 0 of ADC kernel */
      ADC_SFR_DEINIT_MODIFY32(MODULE_SRC.VADC.G[LoopCtr].SR0.U,  \
                ADC_SRC_SRCR_MSK, ((uint32)AdcSreValue << IFX_SRC_SRCR_SRE_OFF))
    }
  
    LoopCtr++;
    
  } while (LoopCtr < ADC_MAX_KERNELS);
  
  LoopCtr = 0U;
  do
  {
    if(Adc_lAutoScanConfigured((uint8)LoopCtr) != 0U)
    {
      /* ADC SRN1 is used by request source 1 of ADC kernel */
      ADC_SFR_DEINIT_MODIFY32(MODULE_SRC.VADC.G[LoopCtr].SR1.U,  \
                ADC_SRC_SRCR_MSK, ((uint32)AdcSreValue << IFX_SRC_SRCR_SRE_OFF))
    }
  
    LoopCtr++;
    
  } while (LoopCtr < ADC_MAX_KERNELS);
  
  
  /* Common Group 0 SRN0 is used by request source 2 */
  #if (ADC_REQSRC2 == ADC_REQSRC_USED)
  
  ADC_SFR_DEINIT_MODIFY32(MODULE_SRC.VADC.CG[0].SR0.U,  \
                ADC_SRC_SRCR_MSK, ((uint32)AdcSreValue << IFX_SRC_SRCR_SRE_OFF))
  
  #endif /* (ADC_REQSRC2 is used) */
  
  
  
  #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
  
  LoopCtr = 0U;
  do
  {
    if(Adc_lLimitChkConfigured((uint8)LoopCtr) != 0U)
    {
      /* ADC SRN2 is used by Channel Event - Limit check of ADC kernel */
      ADC_SFR_DEINIT_MODIFY32(MODULE_SRC.VADC.G[LoopCtr].SR2.U,  \
                ADC_SRC_SRCR_MSK, ((uint32)AdcSreValue << IFX_SRC_SRCR_SRE_OFF))
    }
  
    LoopCtr++;
    
  } while (LoopCtr < ADC_MAX_KERNELS);
  
  #endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  
  #if ( ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR ) 
  
  LoopCtr = 0U;
  do
  {
    if(Adc_lKernelConfigured((uint8)LoopCtr) != 0U)
    {
      /* ADC SRN3 is used for Non AS Dma transfer of ADC kernel */
      ADC_SFR_DEINIT_MODIFY32(MODULE_SRC.VADC.G[LoopCtr].SR3.U,  \
                ADC_SRC_SRCR_MSK, ((uint32)AdcSreValue << IFX_SRC_SRCR_SRE_OFF))
    }
  
    LoopCtr++;
    
  } while (LoopCtr < ADC_MAX_KERNELS);
  
  #elif ( ADC_GROUP_EMUX_SCAN == STD_ON )
  
  EmuxKernel = Adc_kConfigPtr->GlobCfgPtr->EmuxSelectGrp;
  LoopCtr = 0U;
  do
  {
    AdcKernel = Adc_lGetEmuxKernel(EmuxKernel,(uint8)LoopCtr);

    /* ADC SRN3 is used for Non AS Dma transfer of ADC kernel */
    ADC_SFR_DEINIT_MODIFY32(MODULE_SRC.VADC.G[AdcKernel].SR3.U,  \
                ADC_SRC_SRCR_MSK, ((uint32)AdcSreValue << IFX_SRC_SRCR_SRE_OFF))

    LoopCtr++;
    
  } while (LoopCtr < ADC_MAX_EMUX_KERNELS);

  #endif 
  /* (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR) || 
                                             (ADC_GROUP_EMUX_SCAN == STD_ON)*/
} /* Adc_lDeInitSetResetSre */
#endif /* (ADC_DEINIT_API == STD_OFF) */
#endif /* (ADC_RESULT_POLLING_MODE == STD_OFF) */

#if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
/*******************************************************************************
** Syntax           : void Adc_lUpdateRsGroupData                             **
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
void Adc_lUpdateRsGroupData
(
  uint8 AdcKernel, 
  const Adc_GroupCfgType* GrpPtr
)
{
  Adc_GlobalDataType        *DataPtr;
  uint32                    GroupRs;
  uint32                    LoopCnt;
  uint32                    ChInpClass;
  uint32                    ChResol;
  uint32                    ChCfgData;
  uint32                    GrpNumOfChannels;
  #if (ADC_MASTER_SLAVE_SYNC == STD_ON)
  const Adc_HwUnitCfgType   *HwCfgPtr;
  #endif /* (ADC_MASTER_SLAVE_SYNC == STD_ON) */
  const Adc_ChannelCfgType  *ChPtr;
  Adc_GroupDefType          ChIdx;
  Adc_ChannelType           ChannelNum;

  /* Get ADC Kernel index for variables */
  /* Assign the address of ASIL or QM signal variable to global data pointer*/
  DataPtr = Adc_lGetDataAddress(AdcKernel);

  GroupRs = (uint32)(GrpPtr->GrpRequestSrc);

  #if( ADC_MASTER_SLAVE_SYNC == STD_ON )
  HwCfgPtr = Adc_kConfigPtr->CfgPtr[AdcKernel]->HwCfgPtr;
  #endif /* (ADC_MASTER_SLAVE_SYNC == STD_ON) */

  /* Get the starting address of the Channel Config data array */
  ChPtr = (Adc_kConfigPtr->CfgPtr[AdcKernel]->ChCfgPtr);

  /* First element of the Group defination gives the number of channes */
  /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
  Group Configuration Structure and is within allowed range*/
  GrpNumOfChannels = (uint32)(GrpPtr->GroupDefinition)[0];

  /* Assign the Group channels and its resolution in the Group data variable */
  LoopCnt = 0U;
  do
  {
    /* Get the Channel Index from group definition */
    /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
    Group Configuration Structure and is within allowed range*/
    ChIdx = (GrpPtr->GroupDefinition)[(LoopCnt + 1U)];

    /* Get the Channel configuration data value for ChIdx */
    /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
    Channel Configuration Structure and is within allowed range*/
    ChCfgData = ChPtr[ChIdx].AdcChConfigValue;

    /* Get the Internal channel number from Channel config data */
    ChannelNum = (Adc_ChannelType)Adc_lGetKernelChNum(ChCfgData);
    
    /* Assign the Analog channel number into RS Group data variable */
    DataPtr->RsGroupData[GroupRs].GrpChannels[LoopCnt] = ChannelNum;

    #if( ADC_MASTER_SLAVE_SYNC == STD_ON )
    /*IFX_MISRA_RULE_17_04_STATUS=Array indexing used due to 
    Channel Configuration Structure and is within allowed range*/
    if( (HwCfgPtr->SyncConvMode == ADC_MASTER) && 
        (ChPtr[ChIdx].AdcSyncChannel == ADC_SYNC_CHANNEL)
      )
    {
      /* Store the Synch channel to be used while reading result */
      DataPtr->RsGroupData[GroupRs].GrpSynchCh[LoopCnt] = ChannelNum;
    }
    else
    {
      DataPtr->RsGroupData[GroupRs].GrpSynchCh[LoopCnt] = ADC_NO_SYNC_CHANNEL;
    }
    #endif /* ( ADC_MASTER_SLAVE_SYNC == STD_ON ) */
    
    /* Get the channel Input class from CHCTR Reg */
    /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
    access the SFRs of multiple ADC kernels*/
    ChInpClass=(uint32)(((uint32)ADC_SFR_RUNTIME_USER_MODE_READ32(  \
               ADC_MODULE[AdcKernel].CHCTR[ChannelNum].U)) &  \
        ((uint32)IFX_VADC_G_CHCTR_ICLSEL_MSK << IFX_VADC_G_CHCTR_ICLSEL_OFF));

    if( (ChInpClass & ADC_GLOBAL_INPUT_CLASS) )
    {
      ChInpClass = ChInpClass - ADC_GLOBAL_INPUT_CLASS;
      /* Get the resolution of the channel from selected global input class */
      ChResol = (uint32)(((uint32)ADC_SFR_RUNTIME_USER_MODE_READ32(  \
                                ADC_MODULE_GLOB.GLOBICLASS[ChInpClass].U)) & \
              ((uint32)IFX_VADC_ICLASS_CMS_MSK << IFX_VADC_ICLASS_CMS_OFF));
      ChResol = (uint32)(ChResol >> IFX_VADC_ICLASS_CMS_OFF);
    }
    else
    {
      /* Get the resolution of the channel from selected kernel input class */
      /*IFX_MISRA_RULE_17_04_STATUS=Array indexing is used to efficiently
      access the SFRs of multiple ADC kernels*/
      ChResol = (uint32)(((uint32)ADC_SFR_RUNTIME_USER_MODE_READ32(  \
                                ADC_MODULE[AdcKernel].ICLASS[ChInpClass].U)) & \
                  ((uint32)IFX_VADC_ICLASS_CMS_MSK << IFX_VADC_ICLASS_CMS_OFF));
      ChResol = (uint32)(ChResol >> IFX_VADC_ICLASS_CMS_OFF);
    }

    /* Assign the Analog channel resolution into RS Group data variable */
    DataPtr->RsGroupData[GroupRs].GrpChannelRes[LoopCnt] = (uint8)ChResol;

    LoopCnt++;

  } while (LoopCnt < GrpNumOfChannels);

} /* Adc_lUpdateRsGroupData */
#endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */

#if (ADC_CCU6_SYNCHRONIZATION == STD_ON)
/*******************************************************************************
** Syntax           : static void Adc_lCcu6Init                               **
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
** Parameters (out) : uint8                                                   **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called from Init to initialise the CCU6 module       **
**                    to generate 20MHz signal to all VADCs                   **
*******************************************************************************/
static uint8 Adc_lCcu6Init(void)
{
  volatile Ifx_CCU6 *Ccu6BaseRegPtr;/* Variable to hold the CCU6 base address */
  volatile Ifx_CCU6 *Ccu6RegPtr; /* Variable to hold the current CCU6 address */
  volatile uint8    ClcStatus; /* Variable to hold the CLC register status */
  uint8             RetValue; /* Return variable for the CCU6 CLC init status*/
  
  Ccu6BaseRegPtr = &MODULE_CCU60;

  RetValue = 0U;
  ClcStatus = 0U;
  
  /* Checking CCU61 is used for 20MHz synchronization */
  if(Adc_kConfigPtr->GlobCfgPtr->Ccu6Kernel == 1U)
  {
    /* Since the CCU60_MOSEL register is common for CCU60 and CCU61, 
    even though T13 of CCU61 is used to generate 20MHz synchronization 
    signal to VADC, CCU60_CLC register is initialized to enable the CCU60 
    module to avoid getting trap while accessing CCU60_MOSEL register. */
    ADC_SFR_INIT_RESETENDINIT();
    ADC_SFR_INIT_WRITE32(Ccu6BaseRegPtr->CLC.U, 0U);
    ADC_SFR_INIT_SETENDINIT();

    ClcStatus = (uint8)(((uint32) \
                       ADC_SFR_INIT_USER_MODE_READ32(Ccu6BaseRegPtr->CLC.U)) & \
                      ((uint32)IFX_VADC_CLC_DISS_MSK << IFX_VADC_CLC_DISS_OFF));
    ClcStatus = (uint8)((uint32)ClcStatus >> IFX_VADC_CLC_DISS_OFF);

    #if( IFX_ADC_DEBUG_CCU60_CLC == STD_ON )
    ClcStatus = (uint8)(ClcStatus | TestAdc_DebugVarClc);
    #endif
  }
  
  /* Check the status bit DISS for Enable */
  if (ClcStatus == 0U)
  {
    /* Get the base address of the Kernal */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    Channel Configuration Structure and is within allowed range*/
    Ccu6RegPtr = Ccu6BaseRegPtr + (Adc_kConfigPtr->GlobCfgPtr->Ccu6Kernel);
  
    ADC_SFR_INIT_RESETENDINIT();
    ADC_SFR_INIT_WRITE32(Ccu6RegPtr->CLC.U, 0U);
    ADC_SFR_INIT_SETENDINIT();

    ClcStatus = (uint8)(((uint32) \
                        ADC_SFR_INIT_USER_MODE_READ32(Ccu6RegPtr->CLC.U)) &  \
                      ((uint32)IFX_VADC_CLC_DISS_MSK << IFX_VADC_CLC_DISS_OFF));
    ClcStatus = (uint8)((uint32)ClcStatus >> IFX_VADC_CLC_DISS_OFF);

    #if( IFX_ADC_DEBUG_CCU6_CLC == STD_ON )
    ClcStatus = (uint8)(ClcStatus | TestAdc_DebugVarClc);
    #endif
    /* Check the status bit DISS for Enable */
    if (ClcStatus == 0U)
    {
      /* 20MHz clock period */
      /* actual peiod value is PeriodValue + 1 */
      ADC_SFR_INIT_USER_MODE_WRITE32(Ccu6RegPtr->T13PR.U,  \
                               (uint32)Adc_kConfigPtr->GlobCfgPtr->PeriodValue);
      /* configures duty cycle */
      ADC_SFR_INIT_USER_MODE_WRITE32(Ccu6RegPtr->CC63SR.U,  \
                                 (uint32)Adc_kConfigPtr->GlobCfgPtr->DutyValue);
      /* setting passive state level of COUT63 to 1 */
      ADC_SFR_INIT_USER_MODE_MODIFY32(Ccu6RegPtr->PSLR.U, ADC_PSLR_SFR_MSK, \
                                                              ADC_CCU6_PSLR_VAL)
      /* bit ECT130 = 1 serves to route  CC63ST signals out to  COUT63 */
      ADC_SFR_INIT_USER_MODE_MODIFY32(Ccu6RegPtr->MODCTR.U, ADC_MODCTR_SFR_MSK,\
                                                            ADC_CCU6_MODCTR_VAL)
      /* set bit T13PRE  & T13CLK */
      ADC_SFR_INIT_USER_MODE_MODIFY32(Ccu6RegPtr->TCTR0.U, ADC_TCTR0_SFR_MSK, \
                                          Adc_kConfigPtr->GlobCfgPtr->T13Clock)
      /* set bit T13STR  & T13RS  -> enable shadow transfer & start timer T13 */
      ADC_SFR_INIT_USER_MODE_MODIFY32(Ccu6RegPtr->TCTR4.U, ADC_TCTR4_SFR_MSK, \
                                                            ADC_CCU6_TCTR4_VAL)
      /* CCU60_COUT63 routed to output signal CCU6061 TRIG1 */
      ADC_SFR_INIT_USER_MODE_MODIFY32(MODULE_CCU60.MOSEL.U, ADC_MOSEL_SFR_MSK, \
                                           Adc_kConfigPtr->GlobCfgPtr->TrigSel)
      /* CCU6 module initialized */
      RetValue = 1U;
    }
  }
  
  #if (ADC_SAFETY_ENABLE == STD_ON)
  if (ClcStatus == 1U)
  {
    /* Report an safety error */
    SafeMcal_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE,
                          ADC_SID_INIT, ADC_E_CLC_ERROR
                        );
  }
  #endif /* (ADC_SAFETY_ENABLE == STD_ON) */
  
  return(RetValue);
} /* Adc_lCcu6Init */

#if (ADC_DEINIT_API == STD_ON)
/*******************************************************************************
** Syntax           : uint8 Adc_lCcu6DeInit                                   **
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
** Parameters (out) : uint8                                                   **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called from DeInit to deinitialise the CCU6 module   **
**                                                                            **
*******************************************************************************/
uint8 Adc_lCcu6DeInit(void)
{
  volatile Ifx_CCU6 *Ccu6BaseRegPtr;/* Variable to hold the CCU6 base address */
  volatile Ifx_CCU6 *Ccu6RegPtr; /* Variable to hold the current CCU6 address */
  volatile uint8    ClcStatus; /* Variable to hold the CLC register status */
  
  Ccu6BaseRegPtr = &MODULE_CCU60;

  ClcStatus = 0U;

  /* Get the base address of the Kernal */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
  Channel Configuration Structure and is within allowed range*/
  Ccu6RegPtr = Ccu6BaseRegPtr + (Adc_kConfigPtr->GlobCfgPtr->Ccu6Kernel);

  /* Clearing the MOSEL */
  ADC_SFR_DEINIT_USER_MODE_WRITE32(MODULE_CCU60.MOSEL.U, 0U);
  ADC_SFR_DEINIT_RESETENDINIT();
  /* Reset the Kernel0 registers */
  ADC_SFR_DEINIT_WRITE32(Ccu6RegPtr->KRST0.U, 1U);
  ADC_SFR_DEINIT_SETENDINIT();
  /*UTP:AI00252310:- Endinit protection is disabled to avoid trap 
  due to timeout*/
  ADC_SFR_DEINIT_RESETENDINIT();
  /* Reset the Kernel0 registers */
  ADC_SFR_DEINIT_WRITE32(Ccu6RegPtr->KRST1.U, 1U);
  ADC_SFR_DEINIT_SETENDINIT();
  /*UTP:AI00252310:- Endinit protection is disabled to avoid trap 
  due to timeout*/
  ADC_SFR_DEINIT_RESETENDINIT();
  /* Disable the module */
  ADC_SFR_DEINIT_WRITE32(Ccu6RegPtr->CLC.U, 1U);
  ADC_SFR_DEINIT_SETENDINIT();

  ClcStatus = (uint8)(ADC_SFR_DEINIT_USER_MODE_READ32(Ccu6RegPtr->CLC.U) &  \
                     ((uint32)IFX_VADC_CLC_DISS_MSK << IFX_VADC_CLC_DISS_OFF));
  ClcStatus = (uint8)((uint32)ClcStatus >> IFX_VADC_CLC_DISS_OFF);

  #if( IFX_ADC_DEBUG_CCU6_CLC == STD_ON )
  ClcStatus = (uint8)(ClcStatus & TestAdc_DebugVarClc);
  #endif

  #if (ADC_SAFETY_ENABLE == STD_ON)
  if (ClcStatus == 0U)
  {
    /* Report an safety error */
    SafeMcal_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE,
                          ADC_SID_DEINIT, ADC_E_CLC_ERROR
                        );
  }
  #endif /* (ADC_SAFETY_ENABLE == STD_ON) */

  return(ClcStatus);
} /* Adc_lCcu6DeInit */
#endif /* (ADC_DEINIT_API == STD_ON) */

#endif /* (ADC_CCU6_SYNCHRONIZATION == STD_ON) */

#if (ADC_RESET_SFR_INIT == STD_ON)
/*******************************************************************************
** Traceabilty      :[cover parentID=DS_NAS_HE2_ADC_PR3018,
                     DS_NAS_EP_ADC_PR3018]                                    **
** Syntax           : static void Adc_lResetSfr                               **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**[/cover]                                                                    **
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
** Description      : Is called from Init to reset the used SFRs              **
**                                                                            **
*******************************************************************************/
static void Adc_lResetSfr(void)
{
  /* ADC kernel reset requested through KRST0/1 SFR */
  Adc_lInitWriteKernelRstSfr( ADC_KERNEL_RESET );
  
  /* Clear Reset Status */
  ADC_SFR_INIT_RESETENDINIT();
  ADC_SFR_INIT_WRITE32(ADC_MODULE_GLOB.KRSTCLR.U, ADC_KRSTCLR_SFR_MSK);
  ADC_SFR_INIT_SETENDINIT();
  
  #if ((ADC_ERU_TRIGG == STD_ON) || (ADC_ERU_GATING == STD_ON))
  /* Resetting ERU registers */
  Adc_lResetEruSfr();
  #endif /* ((ADC_ERU_TRIGG == STD_ON) || (ADC_ERU_GATING == STD_ON)) */
  
  /* GTM SFR reset is done in Gtm_Init(), 
  hence resetting is not done for the used GTM SFRs in Adc_Init() */
  /* All used CCU6 SFRs are initalised in Adc_Init(), 
  hence resetting is not done for CCU6 SFRs */
  
} /* Adc_lResetSfr */
#endif /* (ADC_RESET_SFR_INIT == STD_ON) */


#define ADC_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
/*******************************************************************************
**                            General Notes                                   **
*******************************************************************************/
  


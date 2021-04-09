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
**   $FILENAME   : Adc_Calibration.c $                                        **
**                                                                            **
**   $CC VERSION : \main\dev_tc23x\6 $                                        **
**                                                                            **
**   $DATE       : 2016-03-29 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : This file contains                                         **
**                 - calibration function of Adc.                             **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of Adc_Utility.h */
#include "Adc_Utility.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
  /* Macros to read CAL and CALS Bitfield of ARBCFG sfr */
#define ADC_CAL_CALS_MASK       (0x30000000U)
#define ADC_CAL_CALS_VALUE      (0x20000000U)
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

#define ADC_START_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Traceabilty      :[cover parentID=DS_NAS_HE2_ADC_PR1784,
DS_NAS_EP_ADC_PR1784]                                                         **
** Syntax           : Std_ReturnType Adc_17_GetStartupCalStatus               **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
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
** Return value     : E_OK: Startup calibration is completed                  **
**                    E_NOT_OK: Startup calibration is ongoing                **
**                                                                            **
** Description      : Api checks the end of startup calibration               **
**                                                                            **
*******************************************************************************/
Std_ReturnType Adc_17_GetStartupCalStatus(void)
{
  Std_ReturnType Status;
  uint8          LoopCtr;

  Status = E_OK;
  
  LoopCtr = 0U;
  do
  {
    if(Adc_lKernelConfigured(LoopCtr) != 0U)
    {
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
      access the SFRs of multiple ADC kernels.*/
      if ( ( (ADC_SFR_RUNTIME_USER_MODE_READ32(ADC_MODULE[LoopCtr].ARBCFG.U)) &\
              (ADC_CAL_CALS_MASK) ) != ADC_CAL_CALS_VALUE )
      {
        Status = E_NOT_OK;
      }
    }
  
    LoopCtr++;
    
  } while (LoopCtr < ADC_MAX_KERNELS);

  return (Status);
} /* Adc_17_GetStartupCalStatus */

#define ADC_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives
 is allowed only for MemMap.h*/
#include "MemMap.h"

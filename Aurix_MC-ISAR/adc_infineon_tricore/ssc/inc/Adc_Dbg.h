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
**   $FILENAME   : Adc_Dbg.h $                                                **
**                                                                            **
**   $CC VERSION : \main\8 $                                                  **
**                                                                            **
**   $DATE       : 2013-08-16 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : This file contains                                         **
**                 - debug variables of Adc driver.                           **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
** Traceabilty      :[cover parentID=DS_AS402_ADC443,DS_AS40X_ADC439,
                      DS_AS40X_ADC440_ADC441,DS_AS40X_ADC442]
**[/cover]                                                                    **
*******************************************************************************/

#ifndef ADC_DBG_H
#define ADC_DBG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of Platform_Types.h and Compiler.h */
#include "Adc.h"

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

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#if ( ADC_DEBUG_SUPPORT == STD_ON )

#if ( ADC_SAFETY_ENABLE == STD_ON )
#if (ADC_ASIL0_KERNEL_USED_COUNT != 0U )
#define ADC_START_SEC_ASIL0_VAR_UNSPECIFIED
#include "MemMap.h"

/* data variable for ASIL0 signals */
extern Adc_GlobalDataType Adc_AsilSignal0[ADC_ASIL0_KERNEL_USED_COUNT];

#define ADC_STOP_SEC_ASIL0_VAR_UNSPECIFIED
#include "MemMap.h"
#endif /* (ADC_ASIL0_KERNEL_USED_COUNT != 0U ) */

#if (ADC_ASIL1_KERNEL_USED_COUNT != 0U )
#define ADC_START_SEC_ASIL1_VAR_UNSPECIFIED
#include "MemMap.h"

/* data variable for ASIL1 signals */
extern Adc_GlobalDataType Adc_AsilSignal1[ADC_ASIL1_KERNEL_USED_COUNT];

#define ADC_STOP_SEC_ASIL1_VAR_UNSPECIFIED
#include "MemMap.h"
#endif /* (ADC_ASIL1_KERNEL_USED_COUNT != 0U ) */
#endif /* ( ADC_SAFETY_ENABLE == STD_ON ) */

#if (ADC_QM_KERNEL_USED_COUNT != 0U )
#define ADC_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/* data variable for QM signals */
extern Adc_GlobalDataType Adc_QmSignal[ADC_QM_KERNEL_USED_COUNT];

#define ADC_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
#endif /* (ADC_QM_KERNEL_USED_COUNT != 0U ) */

#endif /* ( ADC_DEBUG_SUPPORT == STD_ON ) */

#endif /* ADC_DBG_H */

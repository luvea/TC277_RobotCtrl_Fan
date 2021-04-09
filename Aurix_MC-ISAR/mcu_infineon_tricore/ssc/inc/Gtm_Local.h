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
**  $FILENAME   : Gtm_Local.h $                                              **
**                                                                           **
**  $CC VERSION : \main\11 $                                                 **
**                                                                           **
**  $DATE       : 2016-06-20 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                functionality of <> driver.                                **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
  /* Include Standard Types */
#include "Std_Types.h"
#include "IfxGtm_regdef.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define GTM_TOM_CH_CTRL_CLR_MASK (0x5F07800U)
#define GTM_TOM_CH_CTRL_CLK_MASK (0x0007000U)
#define GTM_TOM_CH_CTRL_CLK_CLR_MASK (0xDF00800U)

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/*Memory Map of the GTM Code*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#define GTM_START_SEC_CODE
#include "MemMap.h"

extern void Gtm_lAdcConnectionsConfig(void);
extern void Gtm_lTomComplexConfig(void);
extern void Gtm_lAtomComplexConfig(void);
extern void Gtm_lAtomClockSetting(void);
extern void Gtm_lTomClockSetting(void);

#if (GTM_DEINIT_API_ENABLE == STD_ON)

extern void Gtm_lResetGtmSRCReg(void);

#endif

#define GTM_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/


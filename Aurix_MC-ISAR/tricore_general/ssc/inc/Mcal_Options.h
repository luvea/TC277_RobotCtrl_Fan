/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2014)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Mcal_Options.h $                                           **
**                                                                           **
**  $CC VERSION : \main\22 $                                                 **
**                                                                           **
**  $DATE       : 2016-05-02 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This header file configures pre-compile switches          **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/

#ifndef MCAL_OPTIONS_H
#define MCAL_OPTIONS_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/*
   Configuration:
   IFX_MCAL_USED :
   Pre-Compile switch to enable stand alone Mcal
   IFX_SAFETLIB_USED:
   Pre-Compile switch to enable Standalone safeTlib
*/

#define IFX_MCAL_USED          (STD_ON)
#define IFX_SAFETLIB_USED      (STD_OFF)
/* Pre-Compile switch to enable/disable DEM module version check */
#define IFX_DEM_VERSION_CHECK  (STD_ON)
/* Pre-Compile switch to enable/disable DET module version check */
#define IFX_DET_VERSION_CHECK  (STD_ON)
#define STM_RUNNING_IN_USER_0_MODE_ENABLE  (STD_OFF)
#define STM_USER_MODE_RUNTIME_API_ENABLE   (STD_OFF)

#if ((STM_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON) &&                          \
(STM_USER_MODE_RUNTIME_API_ENABLE == STD_OFF))
#error "STM_RUNNING_IN_USER_0_MODE_ENABLE is (STD_ON) then                     \
    STM_USER_MODE_RUNTIME_API_ENABLE also should be (STD_ON)"
#endif


/* TIN(Trap 6) for Endinit protected register and Safety EndInit Protected
registers*/
/* If IFX_MCAL_RUN_MODE_DEFINE is 1 or 2, these TIN no shall be configured by
used and are reseved for MCAL. Allowed range is 0-255
*/
#define MCAL_TIN_NO_ENDINIT (0U)
#define MCAL_TIN_CPU_ENDINIT (1U)
#define MCAL_TIN_SAFETY_ENDINIT (2U)

#define MCAL_TIN_CALL_RESET_ENDINIT               (0U)
#define MCAL_TIN_CALL_SET_ENDINIT                 (1U)
#define MCAL_TIN_CALL_WRITE32                     (2U)
#define MCAL_TIN_CALL_MODIFY32                    (3U)
#define MCAL_TIN_CALL_SAFETY_RESET_ENDINIT_TIMED  (4U)
#define MCAL_TIN_CALL_SAFETY_SET_ENDINIT_TIMED    (5U)
#define MCAL_TIN_CALL_READ32                      (6U)
#define MCAL_TIN_CALL_MCAL_COREID                 (7U)
#define MCAL_CALL_TIN_SET_ATOMIC                  (8U)
#define MCAL_CALL_TIN_EXTRACT                     (9U)
#define MCAL_CALL_TIN_DMA_RESETCHANNEL            (10U)
#define MCAL_CALL_TIN_DMA_CHANNELCLR_INTRFLG      (11U)
#define MCAL_CALL_TIN_DMA_GET_TRANSFERINTSTATS    (12U)
#define MCAL_CALL_TIN_DMA_DISABL_HWTRFR (13U)
#define MCAL_CALL_TIN_DMA_SETSRC_ADDRS (14U)
#define MCAL_CALL_TIN_DMA_SETDST_ADDRS  (15U)
#define MCAL_CALL_TIN_DMA_CHACLR_CTRLFLG (16U)
#define MCAL_CALL_TIN_DMA_CFGINT_CTRL    (17U)
#define MCAL_CALL_TIN_DMA_SET_DATAWDTH  (18U)
#define MCAL_CALL_TIN_DMA_SET_TXCOUNT    (19U)
#define MCAL_CALL_TIN_DMA_ENABLE_CHINT_TRGR (20U)
#define MCAL_CALL_TIN_DMA_ENABLE_INTR       (21U)
#define MCAL_CALL_TIN_DMA_ADICR             (22U)
#define MCAL_CALL_TIN_ENABLE_HWTRANSFER     (23U)
#define MCAL_CALL_TIN_CLR_ADCR              (24U)
#define MCAL_CALL_TIN_DMA_DISABLE_INTR       (25U)
#define MCAL_CALL_TIN_DMACHCLR_INTCTETR_FLGS (26U)
#define MCAL_CALL_TIN_GET_DSPR_REMAPADDRS    (27U)
#define MCAL_CALL_TIN_DMAGET_TRANSREQLOSTFLG (28U)
#define MCAL_CALL_TIN_DMA_CLRERRFLG          (29U)
#define  MCAL_CALL_TIN_DMA_DISABLE_INTRTRGR  (30U)
#define MCAL_CALL_TIN_RELEASESPIN_LOCK (31U)
#define MCAL_CALL_TIN_GETSPIN_LOCK (32U)
#define MCAL_CALL_TIN_UNLOCK_RESOURCE (33U)
#define MCAL_CALL_TIN_LOCK_RESOURCE (34U)

#define MCAL_CALL_TIN_DMACFG_MVPR_TRSFR (35U)
#define MCAL_CALL_TIN_RESUME_ALLINTRPT (37U)
#define MCAL_CALL_TIN_SSPEND_ALLINTRPT (38U)
#define MCAL_CALL_TIN_CPUWDG_MODIFYACCES (39U)
#define MCAL_CALL_TIN_SAFETY_CHECKACCES (40U)
#define MCAL_CALL_TIN_SAFETY_PWSQNCE (41U)
#define MCAL_CALL_TIN_CPUWDT_PWSQNCE (42U)

#define MCAL_CALL_TIN_CALC_SEQ_PSWD (43U)
#define MCAL_CALL_TIN_DMA_START_TRANSCTION  (44U)
#define MCAL_CALL_TIN_DMAGET_MOVENGERR_FLGS (45U)
#define MCAL_CALL_TIN_DMAGET_INITSTATUS     (46U)
#define MCAL_CALL_TIN_DMAENTRAS_LOSTINTR    (47U)

#define MCAL_CALL_TIN_CFGME_ERRINTR        (48U)
#define MCAL_CALL_TIN_DMAGET_TRANSFERCOUNT (49U)
#define MCAL_CALL_TIN_DMA_STARTTRSCTION    (50U)
#define MCAL_CALL_TIN_SET_CPUPC            (51U)
#define MCAL_CALL_TIN_CLRINTR_TRIGGRFLAG   (52U)

#define MCAL_CALL_TEST_INIT_TIME      (53U)
#define MCAL_CALL_TEST_TIME_SETALARM  (54U)

/* Macro to define the type of the implementaion
Following values for macro IFX_MCAL_RUN_MODE_DEFINE is permitted
0U MCAL runs in Supervisor mode
1U MCAL runs in User-1 mode without OS
2U MCAL runs in User-1 mode with OS
*/
/* This macro can also be defined via command line during compilation */
#ifndef IFX_MCAL_RUN_MODE_DEFINE
#define IFX_MCAL_RUN_MODE_DEFINE (0U)
#endif /* End For IFX_MCAL_RUN_MODE_DEFINE */
/* This macro can also be defined via command line during compilation */
#ifndef IFX_MCAL_TEST_USER_MODE_DEFINE
#define IFX_MCAL_TEST_USER_MODE_DEFINE (1U)
#endif /* End For IFX_MCAL_TEST_USER_MODE_DEFINE */

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/


/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
#endif /* MCAL_OPTIONS_H */
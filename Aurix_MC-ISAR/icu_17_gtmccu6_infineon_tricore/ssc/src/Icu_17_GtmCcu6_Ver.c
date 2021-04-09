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
**  $FILENAME   : Icu_17_GtmCcu6_Ver.c $                                     **
**                                                                           **
**  $CC VERSION : \main\22 $                                                 **
**                                                                           **
**  $DATE       : 2016-08-04 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                - functionality of ICU driver.                             **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                     **
**                                                                           **
******************************************************************************/

 #include "Icu_17_GtmCcu6_Ver.h"
 
/*
  Exports specific definitions and services of the BSW Scheduler for ICU
*/
#include "SchM_17_McalCfg.h"
#include SCHM_ICU_17_GTMCCU6_HEADER

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/** Traceability: [cover parentID=DS_NAS_ICU_PR730]
 */
/* ICU005: Icu.c will check if the correct version of Icu.h is included */
/* Check for definition of the AS Version */
/* ICU005: Icu.c will check if the correct version of Icu.h is included */

#ifndef ICU_17_GTMCCU6_AR_RELEASE_MAJOR_VERSION
  #error "ICU_17_GTMCCU6_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif

#ifndef ICU_17_GTMCCU6_AR_RELEASE_MINOR_VERSION
  #error "ICU_17_GTMCCU6_AR_RELEASE_MINOR_VERSION is not defined. "
#endif

#ifndef ICU_17_GTMCCU6_AR_RELEASE_REVISION_VERSION
  #error "ICU_17_GTMCCU6_AR_RELEASE_REVISION_VERSION is not defined. "
#endif

#if ( ICU_17_GTMCCU6_AR_RELEASE_MAJOR_VERSION != 4U )
  #error "ICU_17_GTMCCU6_AR_RELEASE_MAJOR_VERSION does not match. "
#endif

#if ( ICU_17_GTMCCU6_AR_RELEASE_MINOR_VERSION != 0U )
  #error "ICU_17_GTMCCU6_AR_RELEASE_MINOR_VERSION does not match. "
#endif

/* Check for definition of SW version Information */
#ifndef ICU_17_GTMCCU6_SW_MAJOR_VERSION
  #error "ICU_17_GTMCCU6_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef ICU_17_GTMCCU6_SW_MINOR_VERSION
  #error "ICU_17_GTMCCU6_SW_MINOR_VERSION is not defined. "
#endif

#ifndef ICU_17_GTMCCU6_SW_PATCH_VERSION
  #error "ICU_17_GTMCCU6_SW_PATCH_VERSION is not defined. "
#endif

#if ( ICU_17_GTMCCU6_SW_MAJOR_VERSION != 3U )
  #error "ICU_17_GTMCCU6_SW_MAJOR_VERSION does not match. "
#endif

#if ( ICU_17_GTMCCU6_SW_MINOR_VERSION != 11U )
  #error "ICU_17_GTMCCU6_SW_MINOR_VERSION does not match. "
#endif

/*
  ICU005: Inter Module Checks to avoid integration of incompatible files
*/
#if (ICU_DEV_ERROR_DETECT == STD_ON)

#ifndef  DET_AR_RELEASE_MAJOR_VERSION
 #error "DET_AR_RELEASE_MAJOR_VERSION is not defined."
#endif

#ifndef  DET_AR_RELEASE_MINOR_VERSION
 #error "DET_AR_RELEASE_MINOR_VERSION is not defined."
#endif

/* Updated for AI00251674 IFX_DET_VERSION_CHECK and IFX_DEM_VERSION_CHECK
   are defined in Mcal_Options.h */
#if (IFX_DET_VERSION_CHECK == STD_ON)

#if ( DET_AR_RELEASE_MAJOR_VERSION != 4U )
  #error "DET_AR_RELEASE_MAJOR_VERSION does not match. "
#endif
#if ( DET_AR_RELEASE_MINOR_VERSION != 0U )
  #error "DET_AR_RELEASE_MINOR_VERSION does not match. "
#endif
#endif 
/* End Of IFX_DET_VERSION_CHECK */
#endif
/* End Of ICU_DEV_ERROR_DETECT */

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
**                      Global Function Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                            General Notes                                   **
*******************************************************************************/


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
**  $FILENAME   : MemMap.h $                                                 **
**                                                                           **
**  $CC VERSION : \main\101 $                                                **
**                                                                           **
**  $DATE       : 2016-06-30 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION :                                                            **
**                                                                           **
**             This file allows to map variables, constants and code         **
**             of modules to individual memory sections. The user can        **
**             adapt the memory mapping to their ECU specific needs.         **
**                                                                           **
**             Important note 1: if specific variables and constants are     **
**             mapped to banked/paged memory, the related compiler           **
**             abstraction symbols must fit to these locations!              **
**                                                                           **
**             Important note 2: The section names passed via #pragmas must  **
**             be defined in the linker control and section map files!       **
**  SPECIFICATION(S) : AUTOSAR_SWS_MemoryMapping.pdf,Release 1.0.0           **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/

/******************************************************************************
**  TRACEABILITY : [cover parentID= SAS_NAS_ALL_PR756,SAS_NAS_ALL_PR755] 
                   [/cover]
******************************************************************************/

/******************************************************************************
**                      Module section mapping                               **
******************************************************************************/
/*
 * The symbol 'START_WITH_IF' is undefined.
 *
 * Thus, the preprocessor continues searching for defined symbols
 * This first #ifdef makes integration of delivered parts of MemMap.h
 * easier because every supplier starts with #elif
 */
/*
 * MemMap 019 published information
 */

#ifndef MEMMAP_H
#define MEMMAP_H


/* Mem Vendor ID */
#define MEM_VENDOR_ID         ((uint16)17)

/* MEM SW Major Version */
#define MEM_SW_MAJOR_VERSION  (1U)
/* MEM SW Minor Version */
#define MEM_SW_MINOR_VERSION  (0)
/* MEM SW Patch Version */
#define MEM_SW_PATCH_VERSION  (0)

/* MEM AR Major Version */
#define MEM_AR_MAJOR_VERSION  (1U)
/* MEM AR Minor Version */
#define MEM_AR_MINOR_VERSION  (0)
/* MEM AR Patch Version */
#define MEM_AR_PATCH_VERSION  (13U)

#endif
/*
  Identifier clash , upto 60 characters allowed
  MISRA Rule 92 violation : #undef should not be used.
  MemMap works with undefine and redefine principle.
*/
/*lint -idlen(60) -esym(961,92) */

/*lint -esym(960,19.6)   */  /* Allow usage of #undef */
#if defined (START_WITH_IF)



/*****************************************************************************
**                                 MCU                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (MCU_START_SEC_CODE)
   #undef      MCU_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (MCU_STOP_SEC_CODE)
   #undef      MCU_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (MCU_START_SEC_SAFETY_CODE)
   #undef      MCU_START_SEC_SAFETY_CODE
   #define   DEFAULT_START_SEC_SAFETY_CODE_SHARED
#elif defined (MCU_STOP_SEC_SAFETY_CODE)
   #undef      MCU_STOP_SEC_SAFETY_CODE
   #define DEFAULT_STOP_SEC_SAFETY_CODE_SHARED


#elif defined (MCU_START_SEC_QM_CODE)
   #undef      MCU_START_SEC_QM_CODE
   #define   DEFAULT_START_SEC_QM_CODE_SHARED
#elif defined (MCU_STOP_SEC_QM_CODE)
   #undef      MCU_STOP_SEC_QM_CODE
   #define DEFAULT_STOP_SEC_QM_CODE_SHARED


#elif defined (MCU_START_SEC_VAR_NOINIT_8BIT)
   #undef      MCU_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (MCU_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      MCU_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (MCU_START_SEC_VAR_NOINIT_16BIT)
   #undef      MCU_START_SEC_VAR_NOINIT_16BIT
   #define   MCU_START_SEC_USER_VAR_16BIT
#elif defined (MCU_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      MCU_STOP_SEC_VAR_NOINIT_16BIT
   #define MCU_STOP_SEC_USER_VAR_16BIT


#elif defined (MCU_START_SEC_VAR_NOINIT_32BIT)
   #undef      MCU_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (MCU_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      MCU_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (MCU_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      MCU_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (MCU_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      MCU_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (MCU_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      MCU_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (MCU_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      MCU_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (MCU_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      MCU_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (MCU_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      MCU_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (MCU_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      MCU_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (MCU_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      MCU_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (MCU_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      MCU_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (MCU_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      MCU_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (MCU_START_SEC_VAR_FAST_8BIT)
   #undef      MCU_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (MCU_STOP_SEC_VAR_FAST_8BIT)
   #undef      MCU_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (MCU_START_SEC_VAR_FAST_16BIT)
   #undef      MCU_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (MCU_STOP_SEC_VAR_FAST_16BIT)
   #undef      MCU_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (MCU_START_SEC_VAR_FAST_32BIT)
   #undef      MCU_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (MCU_STOP_SEC_VAR_FAST_32BIT)
   #undef      MCU_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (MCU_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      MCU_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (MCU_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      MCU_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (MCU_START_SEC_VAR_8BIT)
   #undef      MCU_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (MCU_STOP_SEC_VAR_8BIT)
   #undef      MCU_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (MCU_START_SEC_VAR_16BIT)
   #undef      MCU_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (MCU_STOP_SEC_VAR_16BIT)
   #undef      MCU_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (MCU_START_SEC_VAR_32BIT)
   #undef      MCU_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (MCU_STOP_SEC_VAR_32BIT)
   #undef      MCU_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (MCU_START_SEC_VAR_INIT_32BIT)
   #undef      MCU_START_SEC_VAR_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_INIT_32BIT_SHARED
#elif defined (MCU_STOP_SEC_VAR_INIT_32BIT)
   #undef      MCU_STOP_SEC_VAR_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_INIT_32BIT_SHARED


#elif defined (MCU_START_SEC_VAR_UNSPECIFIED)
   #undef      MCU_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (MCU_STOP_SEC_VAR_UNSPECIFIED)
   #undef      MCU_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (MCU_START_SEC_CONST_8BIT)
   #undef      MCU_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (MCU_STOP_SEC_CONST_8BIT)
   #undef      MCU_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (MCU_START_SEC_CONST_16BIT)
   #undef      MCU_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (MCU_STOP_SEC_CONST_16BIT)
   #undef      MCU_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (MCU_START_SEC_CONST_32BIT)
   #undef      MCU_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (MCU_STOP_SEC_CONST_32BIT)
   #undef      MCU_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (MCU_START_SEC_CONST_UNSPECIFIED)
   #undef      MCU_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (MCU_STOP_SEC_CONST_UNSPECIFIED)
   #undef      MCU_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (MCU_START_SEC_POSTBUILDCFG)
   #undef      MCU_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (MCU_STOP_SEC_POSTBUILDCFG)
   #undef      MCU_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 BFX                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (BFX_START_SEC_CODE)
   #undef      BFX_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (BFX_STOP_SEC_CODE)
   #undef      BFX_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED

/*****************************************************************************
**                                 DIO                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (DIO_START_SEC_CODE)
   #undef      DIO_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (DIO_STOP_SEC_CODE)
   #undef      DIO_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (DIO_START_SEC_VAR_NOINIT_8BIT)
   #undef      DIO_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (DIO_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      DIO_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (DIO_START_SEC_VAR_NOINIT_16BIT)
   #undef      DIO_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (DIO_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      DIO_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (DIO_START_SEC_VAR_NOINIT_32BIT)
   #undef      DIO_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (DIO_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      DIO_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (DIO_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      DIO_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (DIO_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      DIO_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (DIO_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      DIO_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (DIO_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      DIO_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (DIO_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      DIO_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (DIO_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      DIO_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (DIO_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      DIO_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (DIO_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      DIO_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (DIO_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      DIO_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (DIO_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      DIO_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (DIO_START_SEC_VAR_FAST_8BIT)
   #undef      DIO_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (DIO_STOP_SEC_VAR_FAST_8BIT)
   #undef      DIO_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (DIO_START_SEC_VAR_FAST_16BIT)
   #undef      DIO_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (DIO_STOP_SEC_VAR_FAST_16BIT)
   #undef      DIO_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (DIO_START_SEC_VAR_FAST_32BIT)
   #undef      DIO_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (DIO_STOP_SEC_VAR_FAST_32BIT)
   #undef      DIO_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (DIO_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      DIO_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (DIO_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      DIO_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (DIO_START_SEC_VAR_8BIT)
   #undef      DIO_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (DIO_STOP_SEC_VAR_8BIT)
   #undef      DIO_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (DIO_START_SEC_VAR_16BIT)
   #undef      DIO_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (DIO_STOP_SEC_VAR_16BIT)
   #undef      DIO_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (DIO_START_SEC_VAR_32BIT)
   #undef      DIO_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (DIO_STOP_SEC_VAR_32BIT)
   #undef      DIO_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (DIO_START_SEC_VAR_UNSPECIFIED)
   #undef      DIO_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (DIO_STOP_SEC_VAR_UNSPECIFIED)
   #undef      DIO_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (DIO_START_SEC_CONST_8BIT)
   #undef      DIO_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (DIO_STOP_SEC_CONST_8BIT)
   #undef      DIO_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (DIO_START_SEC_CONST_16BIT)
   #undef      DIO_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (DIO_STOP_SEC_CONST_16BIT)
   #undef      DIO_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (DIO_START_SEC_CONST_32BIT)
   #undef      DIO_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (DIO_STOP_SEC_CONST_32BIT)
   #undef      DIO_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (DIO_START_SEC_CONST_UNSPECIFIED)
   #undef      DIO_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (DIO_STOP_SEC_CONST_UNSPECIFIED)
   #undef      DIO_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (DIO_START_SEC_POSTBUILDCFG)
   #undef      DIO_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (DIO_STOP_SEC_POSTBUILDCFG)
   #undef      DIO_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 GPT                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (GPT_START_SEC_CODE)
   #undef      GPT_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_CODE)
   #undef      GPT_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_NOINIT_8BIT)
   #undef      GPT_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      GPT_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_NOINIT_16BIT)
   #undef      GPT_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      GPT_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_NOINIT_32BIT)
   #undef      GPT_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      GPT_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      GPT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      GPT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      GPT_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      GPT_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      GPT_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      GPT_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      GPT_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      GPT_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      GPT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      GPT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_FAST_8BIT)
   #undef      GPT_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_FAST_8BIT)
   #undef      GPT_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_FAST_16BIT)
   #undef      GPT_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_FAST_16BIT)
   #undef      GPT_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_FAST_32BIT)
   #undef      GPT_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_FAST_32BIT)
   #undef      GPT_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      GPT_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      GPT_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_8BIT)
   #undef      GPT_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_8BIT)
   #undef      GPT_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_16BIT)
   #undef      GPT_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_16BIT)
   #undef      GPT_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_32BIT)
   #undef      GPT_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_32BIT)
   #undef      GPT_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_UNSPECIFIED)
   #undef      GPT_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_UNSPECIFIED)
   #undef      GPT_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE1_PRIVATE


#elif defined (GPT_START_SEC_ASIL0_VAR_8BIT)
   #undef      GPT_START_SEC_ASIL0_VAR_8BIT
   #define   DEFAULT_START_SEC_ASIL0_VAR_8BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_ASIL0_VAR_8BIT)
   #undef      GPT_STOP_SEC_ASIL0_VAR_8BIT
   #define DEFAULT_STOP_SEC_ASIL0_VAR_8BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_CONST_8BIT)
   #undef      GPT_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_CONST_8BIT)
   #undef      GPT_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_CONST_16BIT)
   #undef      GPT_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_CONST_16BIT)
   #undef      GPT_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_CONST_32BIT)
   #undef      GPT_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_CONST_32BIT)
   #undef      GPT_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_CONST_UNSPECIFIED)
   #undef      GPT_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_CONST_UNSPECIFIED)
   #undef      GPT_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE1_PRIVATE


#elif defined (GPT_START_SEC_POSTBUILDCFG)
   #undef      GPT_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_POSTBUILDCFG)
   #undef      GPT_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_CORE1_PRIVATE

/*****************************************************************************
**                                 ICU_17_GTMCCU6                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (ICU_17_GTMCCU6_START_SEC_CODE)
   #undef      ICU_17_GTMCCU6_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_CODE)
   #undef      ICU_17_GTMCCU6_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_NOINIT_8BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_NOINIT_16BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_NOINIT_32BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_FAST_8BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_FAST_8BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_FAST_16BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_FAST_16BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_FAST_32BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_FAST_32BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_8BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_8BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_16BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_16BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_32BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_32BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_UNSPECIFIED)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_UNSPECIFIED)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_ASIL0_VAR_UNSPECIFIED)
   #undef      ICU_17_GTMCCU6_START_SEC_ASIL0_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_ASIL0_VAR_UNSPECIFIED_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_ASIL0_VAR_UNSPECIFIED)
   #undef      ICU_17_GTMCCU6_STOP_SEC_ASIL0_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_ASIL0_VAR_UNSPECIFIED_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_ASIL1_VAR_UNSPECIFIED)
   #undef      ICU_17_GTMCCU6_START_SEC_ASIL1_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_ASIL1_VAR_UNSPECIFIED_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_ASIL1_VAR_UNSPECIFIED)
   #undef      ICU_17_GTMCCU6_STOP_SEC_ASIL1_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_ASIL1_VAR_UNSPECIFIED_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_CONST_8BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_CONST_8BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_CONST_16BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_CONST_16BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_CONST_32BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_CONST_32BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_CONST_UNSPECIFIED)
   #undef      ICU_17_GTMCCU6_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_CONST_UNSPECIFIED)
   #undef      ICU_17_GTMCCU6_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_POSTBUILDCFG)
   #undef      ICU_17_GTMCCU6_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_POSTBUILDCFG)
   #undef      ICU_17_GTMCCU6_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 PWM_17_GTM                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (PWM_17_GTM_START_SEC_CODE)
   #undef      PWM_17_GTM_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_CODE)
   #undef      PWM_17_GTM_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_NOINIT_8BIT)
   #undef      PWM_17_GTM_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      PWM_17_GTM_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_NOINIT_16BIT)
   #undef      PWM_17_GTM_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      PWM_17_GTM_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_NOINIT_32BIT)
   #undef      PWM_17_GTM_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      PWM_17_GTM_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      PWM_17_GTM_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      PWM_17_GTM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      PWM_17_GTM_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      PWM_17_GTM_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      PWM_17_GTM_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      PWM_17_GTM_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      PWM_17_GTM_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      PWM_17_GTM_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      PWM_17_GTM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      PWM_17_GTM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_FAST_8BIT)
   #undef      PWM_17_GTM_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_FAST_8BIT)
   #undef      PWM_17_GTM_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_FAST_16BIT)
   #undef      PWM_17_GTM_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_FAST_16BIT)
   #undef      PWM_17_GTM_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_FAST_32BIT)
   #undef      PWM_17_GTM_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_FAST_32BIT)
   #undef      PWM_17_GTM_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      PWM_17_GTM_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      PWM_17_GTM_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_8BIT)
   #undef      PWM_17_GTM_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_8BIT)
   #undef      PWM_17_GTM_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_16BIT)
   #undef      PWM_17_GTM_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_16BIT)
   #undef      PWM_17_GTM_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_32BIT)
   #undef      PWM_17_GTM_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_32BIT)
   #undef      PWM_17_GTM_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_ASIL0_VAR_32BIT)
   #undef      PWM_17_GTM_START_SEC_ASIL0_VAR_32BIT
   #define   DEFAULT_START_SEC_ASIL0_VAR_32BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_ASIL0_VAR_32BIT)
   #undef      PWM_17_GTM_STOP_SEC_ASIL0_VAR_32BIT
   #define DEFAULT_STOP_SEC_ASIL0_VAR_32BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_UNSPECIFIED)
   #undef      PWM_17_GTM_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_UNSPECIFIED)
   #undef      PWM_17_GTM_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (PWM_17_GTM_START_SEC_CONST_8BIT)
   #undef      PWM_17_GTM_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_CONST_8BIT)
   #undef      PWM_17_GTM_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_CONST_16BIT)
   #undef      PWM_17_GTM_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_CONST_16BIT)
   #undef      PWM_17_GTM_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_CONST_32BIT)
   #undef      PWM_17_GTM_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_CONST_32BIT)
   #undef      PWM_17_GTM_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_CONST_UNSPECIFIED)
   #undef      PWM_17_GTM_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_CONST_UNSPECIFIED)
   #undef      PWM_17_GTM_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (PWM_17_GTM_START_SEC_POSTBUILDCFG)
   #undef      PWM_17_GTM_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_POSTBUILDCFG)
   #undef      PWM_17_GTM_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 GTM                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (GTM_START_SEC_CODE)
   #undef      GTM_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (GTM_STOP_SEC_CODE)
   #undef      GTM_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (GTM_START_SEC_SAFETY_CODE)
   #undef      GTM_START_SEC_SAFETY_CODE
   #define   DEFAULT_START_SEC_SAFETY_CODE_SHARED
#elif defined (GTM_STOP_SEC_SAFETY_CODE)
   #undef      GTM_STOP_SEC_SAFETY_CODE
   #define DEFAULT_STOP_SEC_SAFETY_CODE_SHARED


#elif defined (GTM_START_SEC_VAR_NOINIT_8BIT)
   #undef      GTM_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (GTM_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      GTM_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (GTM_START_SEC_VAR_NOINIT_16BIT)
   #undef      GTM_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (GTM_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      GTM_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (GTM_START_SEC_VAR_NOINIT_32BIT)
   #undef      GTM_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (GTM_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      GTM_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (GTM_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      GTM_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (GTM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      GTM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (GTM_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      GTM_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (GTM_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      GTM_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (GTM_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      GTM_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (GTM_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      GTM_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (GTM_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      GTM_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (GTM_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      GTM_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (GTM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      GTM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (GTM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      GTM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (GTM_START_SEC_VAR_FAST_8BIT)
   #undef      GTM_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (GTM_STOP_SEC_VAR_FAST_8BIT)
   #undef      GTM_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (GTM_START_SEC_VAR_FAST_16BIT)
   #undef      GTM_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (GTM_STOP_SEC_VAR_FAST_16BIT)
   #undef      GTM_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (GTM_START_SEC_VAR_FAST_32BIT)
   #undef      GTM_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (GTM_STOP_SEC_VAR_FAST_32BIT)
   #undef      GTM_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (GTM_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      GTM_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (GTM_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      GTM_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (GTM_START_SEC_VAR_8BIT)
   #undef      GTM_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (GTM_STOP_SEC_VAR_8BIT)
   #undef      GTM_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (GTM_START_SEC_VAR_16BIT)
   #undef      GTM_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (GTM_STOP_SEC_VAR_16BIT)
   #undef      GTM_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (GTM_START_SEC_VAR_32BIT)
   #undef      GTM_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (GTM_STOP_SEC_VAR_32BIT)
   #undef      GTM_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (GTM_START_SEC_VAR_UNSPECIFIED)
   #undef      GTM_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (GTM_STOP_SEC_VAR_UNSPECIFIED)
   #undef      GTM_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (GTM_START_SEC_CONST_8BIT)
   #undef      GTM_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (GTM_STOP_SEC_CONST_8BIT)
   #undef      GTM_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (GTM_START_SEC_CONST_16BIT)
   #undef      GTM_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (GTM_STOP_SEC_CONST_16BIT)
   #undef      GTM_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (GTM_START_SEC_CONST_32BIT)
   #undef      GTM_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (GTM_STOP_SEC_CONST_32BIT)
   #undef      GTM_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (GTM_START_SEC_CONST_UNSPECIFIED)
   #undef      GTM_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (GTM_STOP_SEC_CONST_UNSPECIFIED)
   #undef      GTM_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (GTM_START_SEC_POSTBUILDCFG)
   #undef      GTM_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (GTM_STOP_SEC_POSTBUILDCFG)
   #undef      GTM_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 PORT                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (PORT_START_SEC_CODE)
   #undef      PORT_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (PORT_STOP_SEC_CODE)
   #undef      PORT_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (PORT_START_SEC_VAR_NOINIT_8BIT)
   #undef      PORT_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (PORT_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      PORT_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (PORT_START_SEC_VAR_NOINIT_16BIT)
   #undef      PORT_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (PORT_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      PORT_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (PORT_START_SEC_VAR_NOINIT_32BIT)
   #undef      PORT_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (PORT_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      PORT_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (PORT_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      PORT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (PORT_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      PORT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (PORT_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      PORT_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (PORT_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      PORT_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (PORT_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      PORT_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (PORT_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      PORT_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (PORT_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      PORT_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (PORT_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      PORT_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (PORT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      PORT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (PORT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      PORT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (PORT_START_SEC_VAR_FAST_8BIT)
   #undef      PORT_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (PORT_STOP_SEC_VAR_FAST_8BIT)
   #undef      PORT_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (PORT_START_SEC_VAR_FAST_16BIT)
   #undef      PORT_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (PORT_STOP_SEC_VAR_FAST_16BIT)
   #undef      PORT_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (PORT_START_SEC_VAR_FAST_32BIT)
   #undef      PORT_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (PORT_STOP_SEC_VAR_FAST_32BIT)
   #undef      PORT_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (PORT_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      PORT_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (PORT_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      PORT_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (PORT_START_SEC_VAR_8BIT)
   #undef      PORT_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (PORT_STOP_SEC_VAR_8BIT)
   #undef      PORT_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (PORT_START_SEC_VAR_16BIT)
   #undef      PORT_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (PORT_STOP_SEC_VAR_16BIT)
   #undef      PORT_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (PORT_START_SEC_VAR_32BIT)
   #undef      PORT_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (PORT_STOP_SEC_VAR_32BIT)
   #undef      PORT_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (PORT_START_SEC_VAR_UNSPECIFIED)
   #undef      PORT_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (PORT_STOP_SEC_VAR_UNSPECIFIED)
   #undef      PORT_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (PORT_START_SEC_CONST_8BIT)
   #undef      PORT_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (PORT_STOP_SEC_CONST_8BIT)
   #undef      PORT_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (PORT_START_SEC_CONST_16BIT)
   #undef      PORT_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (PORT_STOP_SEC_CONST_16BIT)
   #undef      PORT_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (PORT_START_SEC_CONST_32BIT)
   #undef      PORT_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (PORT_STOP_SEC_CONST_32BIT)
   #undef      PORT_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (PORT_START_SEC_CONST_UNSPECIFIED)
   #undef      PORT_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (PORT_STOP_SEC_CONST_UNSPECIFIED)
   #undef      PORT_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (PORT_START_SEC_POSTBUILDCFG)
   #undef      PORT_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (PORT_STOP_SEC_POSTBUILDCFG)
   #undef      PORT_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 CAN_17_MCANP                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (CAN_17_MCANP_START_SEC_CODE)
   #undef      CAN_17_MCANP_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_CODE)
   #undef      CAN_17_MCANP_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_NOINIT_8BIT)
   #undef      CAN_17_MCANP_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_NOINIT_16BIT)
   #undef      CAN_17_MCANP_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_NOINIT_32BIT)
   #undef      CAN_17_MCANP_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      CAN_17_MCANP_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      CAN_17_MCANP_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      CAN_17_MCANP_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      CAN_17_MCANP_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      CAN_17_MCANP_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_FAST_8BIT)
   #undef      CAN_17_MCANP_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_FAST_8BIT)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_FAST_16BIT)
   #undef      CAN_17_MCANP_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_FAST_16BIT)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_FAST_32BIT)
   #undef      CAN_17_MCANP_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_FAST_32BIT)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      CAN_17_MCANP_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_8BIT)
   #undef      CAN_17_MCANP_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_8BIT)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_16BIT)
   #undef      CAN_17_MCANP_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_16BIT)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_32BIT)
   #undef      CAN_17_MCANP_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_32BIT)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_UNSPECIFIED)
   #undef      CAN_17_MCANP_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_UNSPECIFIED)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (CAN_17_MCANP_START_SEC_CONST_8BIT)
   #undef      CAN_17_MCANP_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_CONST_8BIT)
   #undef      CAN_17_MCANP_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_CONST_16BIT)
   #undef      CAN_17_MCANP_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_CONST_16BIT)
   #undef      CAN_17_MCANP_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_CONST_32BIT)
   #undef      CAN_17_MCANP_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_CONST_32BIT)
   #undef      CAN_17_MCANP_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_CONST_UNSPECIFIED)
   #undef      CAN_17_MCANP_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_CONST_UNSPECIFIED)
   #undef      CAN_17_MCANP_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (CAN_17_MCANP_START_SEC_POSTBUILDCFG)
   #undef      CAN_17_MCANP_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_POSTBUILDCFG)
   #undef      CAN_17_MCANP_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 SPI                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (SPI_START_SEC_CODE)
   #undef      SPI_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (SPI_STOP_SEC_CODE)
   #undef      SPI_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (SPI_START_SEC_VAR_NOINIT_8BIT)
   #undef      SPI_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (SPI_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      SPI_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (SPI_START_SEC_VAR_NOINIT_16BIT)
   #undef      SPI_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (SPI_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      SPI_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (SPI_START_SEC_VAR_NOINIT_32BIT)
   #undef      SPI_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (SPI_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      SPI_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (SPI_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      SPI_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (SPI_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      SPI_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (SPI_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      SPI_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (SPI_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      SPI_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (SPI_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      SPI_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (SPI_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      SPI_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (SPI_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      SPI_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (SPI_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      SPI_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (SPI_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      SPI_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (SPI_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      SPI_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (SPI_START_SEC_VAR_FAST_8BIT)
   #undef      SPI_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (SPI_STOP_SEC_VAR_FAST_8BIT)
   #undef      SPI_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (SPI_START_SEC_VAR_FAST_16BIT)
   #undef      SPI_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (SPI_STOP_SEC_VAR_FAST_16BIT)
   #undef      SPI_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (SPI_START_SEC_VAR_FAST_32BIT)
   #undef      SPI_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (SPI_STOP_SEC_VAR_FAST_32BIT)
   #undef      SPI_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (SPI_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      SPI_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (SPI_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      SPI_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (SPI_START_SEC_VAR_8BIT)
   #undef      SPI_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (SPI_STOP_SEC_VAR_8BIT)
   #undef      SPI_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (SPI_START_SEC_VAR_16BIT)
   #undef      SPI_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (SPI_STOP_SEC_VAR_16BIT)
   #undef      SPI_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (SPI_START_SEC_VAR_32BIT)
   #undef      SPI_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (SPI_STOP_SEC_VAR_32BIT)
   #undef      SPI_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (SPI_START_SEC_VAR_UNSPECIFIED)
   #undef      SPI_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (SPI_STOP_SEC_VAR_UNSPECIFIED)
   #undef      SPI_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (SPI_START_SEC_CONST_8BIT)
   #undef      SPI_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (SPI_STOP_SEC_CONST_8BIT)
   #undef      SPI_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (SPI_START_SEC_CONST_16BIT)
   #undef      SPI_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (SPI_STOP_SEC_CONST_16BIT)
   #undef      SPI_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (SPI_START_SEC_CONST_32BIT)
   #undef      SPI_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (SPI_STOP_SEC_CONST_32BIT)
   #undef      SPI_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (SPI_START_SEC_CONST_UNSPECIFIED)
   #undef      SPI_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (SPI_STOP_SEC_CONST_UNSPECIFIED)
   #undef      SPI_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (SPI_START_SEC_ASIL0_VAR_UNSPECIFIED)
   #undef      SPI_START_SEC_ASIL0_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_ASIL0_VAR_UNSPECIFIED_SHARED
#elif defined (SPI_STOP_SEC_ASIL0_VAR_UNSPECIFIED)
   #undef      SPI_STOP_SEC_ASIL0_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_ASIL0_VAR_UNSPECIFIED_SHARED


#elif defined (SPI_START_SEC_ASIL0_VAR_32BIT)
   #undef      SPI_START_SEC_ASIL0_VAR_32BIT
   #define   DEFAULT_START_SEC_ASIL0_VAR_32BIT_SHARED
#elif defined (SPI_STOP_SEC_ASIL0_VAR_32BIT)
   #undef      SPI_STOP_SEC_ASIL0_VAR_32BIT
   #define DEFAULT_STOP_SEC_ASIL0_VAR_32BIT_SHARED


#elif defined (SPI_START_SEC_ASIL1_VAR_8BIT)
   #undef      SPI_START_SEC_ASIL1_VAR_8BIT
   #define   DEFAULT_START_SEC_ASIL1_VAR_8BIT_SHARED
#elif defined (SPI_STOP_SEC_ASIL1_VAR_8BIT)
   #undef      SPI_STOP_SEC_ASIL1_VAR_8BIT
   #define DEFAULT_STOP_SEC_ASIL1_VAR_8BIT_SHARED


#elif defined (SPI_START_SEC_ASIL1_VAR_UNSPECIFIED)
   #undef      SPI_START_SEC_ASIL1_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_ASIL1_VAR_UNSPECIFIED_SHARED
#elif defined (SPI_STOP_SEC_ASIL1_VAR_UNSPECIFIED)
   #undef      SPI_STOP_SEC_ASIL1_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_ASIL1_VAR_UNSPECIFIED_SHARED


#elif defined (SPI_START_SEC_ASIL1_VAR_FAST_32BIT)
   #undef      SPI_START_SEC_ASIL1_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_ASIL1_VAR_FAST_32BIT_SHARED
#elif defined (SPI_STOP_SEC_ASIL1_VAR_FAST_32BIT)
   #undef      SPI_STOP_SEC_ASIL1_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_ASIL1_VAR_FAST_32BIT_SHARED


#elif defined (SPI_START_SEC_POSTBUILDCFG)
   #undef      SPI_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (SPI_STOP_SEC_POSTBUILDCFG)
   #undef      SPI_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 ADC                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (ADC_START_SEC_CODE)
   #undef      ADC_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (ADC_STOP_SEC_CODE)
   #undef      ADC_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (ADC_START_SEC_VAR_NOINIT_8BIT)
   #undef      ADC_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (ADC_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      ADC_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (ADC_START_SEC_VAR_NOINIT_16BIT)
   #undef      ADC_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (ADC_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      ADC_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (ADC_START_SEC_VAR_NOINIT_32BIT)
   #undef      ADC_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (ADC_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      ADC_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (ADC_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      ADC_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (ADC_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      ADC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (ADC_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      ADC_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (ADC_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      ADC_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (ADC_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      ADC_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (ADC_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      ADC_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (ADC_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      ADC_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (ADC_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      ADC_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (ADC_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      ADC_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (ADC_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      ADC_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (ADC_START_SEC_VAR_FAST_8BIT)
   #undef      ADC_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (ADC_STOP_SEC_VAR_FAST_8BIT)
   #undef      ADC_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (ADC_START_SEC_VAR_FAST_16BIT)
   #undef      ADC_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (ADC_STOP_SEC_VAR_FAST_16BIT)
   #undef      ADC_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (ADC_START_SEC_VAR_FAST_32BIT)
   #undef      ADC_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (ADC_STOP_SEC_VAR_FAST_32BIT)
   #undef      ADC_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (ADC_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      ADC_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (ADC_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      ADC_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (ADC_START_SEC_VAR_8BIT)
   #undef      ADC_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (ADC_STOP_SEC_VAR_8BIT)
   #undef      ADC_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (ADC_START_SEC_VAR_16BIT)
   #undef      ADC_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (ADC_STOP_SEC_VAR_16BIT)
   #undef      ADC_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (ADC_START_SEC_VAR_32BIT)
   #undef      ADC_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (ADC_STOP_SEC_VAR_32BIT)
   #undef      ADC_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (ADC_START_SEC_VAR_UNSPECIFIED)
   #undef      ADC_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (ADC_STOP_SEC_VAR_UNSPECIFIED)
   #undef      ADC_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (ADC_START_SEC_CONST_8BIT)
   #undef      ADC_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (ADC_STOP_SEC_CONST_8BIT)
   #undef      ADC_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (ADC_START_SEC_CONST_16BIT)
   #undef      ADC_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (ADC_STOP_SEC_CONST_16BIT)
   #undef      ADC_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (ADC_START_SEC_CONST_32BIT)
   #undef      ADC_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (ADC_STOP_SEC_CONST_32BIT)
   #undef      ADC_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (ADC_START_SEC_CONST_UNSPECIFIED)
   #undef      ADC_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (ADC_STOP_SEC_CONST_UNSPECIFIED)
   #undef      ADC_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (ADC_START_SEC_ASIL0_CONST_8BIT)
   #undef      ADC_START_SEC_ASIL0_CONST_8BIT
   #define   DEFAULT_START_SEC_ASIL0_CONST_8BIT_SHARED
#elif defined (ADC_STOP_SEC_ASIL0_CONST_8BIT)
   #undef      ADC_STOP_SEC_ASIL0_CONST_8BIT
   #define DEFAULT_STOP_SEC_ASIL0_CONST_8BIT_SHARED


#elif defined (ADC_START_SEC_ASIL1_CONST_8BIT)
   #undef      ADC_START_SEC_ASIL1_CONST_8BIT
   #define   DEFAULT_START_SEC_ASIL1_CONST_8BIT_SHARED
#elif defined (ADC_STOP_SEC_ASIL1_CONST_8BIT)
   #undef      ADC_STOP_SEC_ASIL1_CONST_8BIT
   #define DEFAULT_STOP_SEC_ASIL1_CONST_8BIT_SHARED


#elif defined (ADC_START_SEC_ASIL0_VAR_UNSPECIFIED)
   #undef      ADC_START_SEC_ASIL0_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_ASIL0_VAR_UNSPECIFIED_SHARED
#elif defined (ADC_STOP_SEC_ASIL0_VAR_UNSPECIFIED)
   #undef      ADC_STOP_SEC_ASIL0_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_ASIL0_VAR_UNSPECIFIED_SHARED


#elif defined (ADC_START_SEC_ASIL1_VAR_UNSPECIFIED)
   #undef      ADC_START_SEC_ASIL1_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_ASIL1_VAR_UNSPECIFIED_SHARED
#elif defined (ADC_STOP_SEC_ASIL1_VAR_UNSPECIFIED)
   #undef      ADC_STOP_SEC_ASIL1_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_ASIL1_VAR_UNSPECIFIED_SHARED


#elif defined (ADC_START_SEC_POSTBUILDCFG)
   #undef      ADC_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (ADC_STOP_SEC_POSTBUILDCFG)
   #undef      ADC_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 WDG_17_SCU                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (WDG_17_SCU_START_SEC_CODE)
   #undef      WDG_17_SCU_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_CODE)
   #undef      WDG_17_SCU_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_NOINIT_8BIT)
   #undef      WDG_17_SCU_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      WDG_17_SCU_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_NOINIT_16BIT)
   #undef      WDG_17_SCU_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      WDG_17_SCU_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_NOINIT_32BIT)
   #undef      WDG_17_SCU_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      WDG_17_SCU_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      WDG_17_SCU_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      WDG_17_SCU_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      WDG_17_SCU_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      WDG_17_SCU_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      WDG_17_SCU_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      WDG_17_SCU_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      WDG_17_SCU_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      WDG_17_SCU_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      WDG_17_SCU_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      WDG_17_SCU_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_FAST_8BIT)
   #undef      WDG_17_SCU_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_FAST_8BIT)
   #undef      WDG_17_SCU_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_FAST_16BIT)
   #undef      WDG_17_SCU_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_FAST_16BIT)
   #undef      WDG_17_SCU_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_FAST_32BIT)
   #undef      WDG_17_SCU_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_FAST_32BIT)
   #undef      WDG_17_SCU_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      WDG_17_SCU_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      WDG_17_SCU_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_8BIT)
   #undef      WDG_17_SCU_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_8BIT)
   #undef      WDG_17_SCU_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_16BIT)
   #undef      WDG_17_SCU_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_16BIT)
   #undef      WDG_17_SCU_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_32BIT)
   #undef      WDG_17_SCU_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_32BIT)
   #undef      WDG_17_SCU_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_UNSPECIFIED)
   #undef      WDG_17_SCU_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_UNSPECIFIED)
   #undef      WDG_17_SCU_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (WDG_17_SCU_START_SEC_CONST_8BIT)
   #undef      WDG_17_SCU_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_CONST_8BIT)
   #undef      WDG_17_SCU_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_CONST_16BIT)
   #undef      WDG_17_SCU_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_CONST_16BIT)
   #undef      WDG_17_SCU_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_CONST_32BIT)
   #undef      WDG_17_SCU_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_CONST_32BIT)
   #undef      WDG_17_SCU_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_CONST_UNSPECIFIED)
   #undef      WDG_17_SCU_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_CONST_UNSPECIFIED)
   #undef      WDG_17_SCU_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (WDG_17_SCU_START_SEC_POSTBUILDCFG)
   #undef      WDG_17_SCU_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_POSTBUILDCFG)
   #undef      WDG_17_SCU_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 CANTRCV_17_6250GV33                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (CANTRCV_17_6250GV33_START_SEC_CODE)
   #undef      CANTRCV_17_6250GV33_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_CODE)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_NOINIT_8BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_NOINIT_16BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_NOINIT_32BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_FAST_8BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_FAST_8BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_FAST_16BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_FAST_16BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_FAST_32BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_FAST_32BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_8BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_8BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_16BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_16BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_32BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_32BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_UNSPECIFIED)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_UNSPECIFIED)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_CONST_8BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_CONST_8BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_CONST_16BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_CONST_16BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_CONST_32BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_CONST_32BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_CONST_UNSPECIFIED)
   #undef      CANTRCV_17_6250GV33_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_CONST_UNSPECIFIED)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED

/*****************************************************************************
**                                 CANTRCV_17_6251G                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (CANTRCV_17_6251G_START_SEC_CODE)
   #undef      CANTRCV_17_6251G_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_CODE)
   #undef      CANTRCV_17_6251G_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_NOINIT_8BIT)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_NOINIT_16BIT)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_NOINIT_32BIT)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_FAST_8BIT)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_FAST_8BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_FAST_16BIT)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_FAST_16BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_FAST_32BIT)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_FAST_32BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_8BIT)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_8BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_16BIT)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_16BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_32BIT)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_32BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_UNSPECIFIED)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_UNSPECIFIED)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_CONST_8BIT)
   #undef      CANTRCV_17_6251G_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_CONST_8BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_CONST_16BIT)
   #undef      CANTRCV_17_6251G_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_CONST_16BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_CONST_32BIT)
   #undef      CANTRCV_17_6251G_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_CONST_32BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_CONST_UNSPECIFIED)
   #undef      CANTRCV_17_6251G_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_CONST_UNSPECIFIED)
   #undef      CANTRCV_17_6251G_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED

/*****************************************************************************
**                                 DMA                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (DMA_START_SEC_CODE)
   #undef      DMA_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (DMA_STOP_SEC_CODE)
   #undef      DMA_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (DMA_START_SEC_VAR_NOINIT_8BIT)
   #undef      DMA_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (DMA_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      DMA_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (DMA_START_SEC_VAR_NOINIT_16BIT)
   #undef      DMA_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (DMA_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      DMA_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (DMA_START_SEC_VAR_NOINIT_32BIT)
   #undef      DMA_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (DMA_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      DMA_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (DMA_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      DMA_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (DMA_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      DMA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (DMA_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      DMA_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (DMA_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      DMA_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (DMA_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      DMA_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (DMA_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      DMA_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (DMA_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      DMA_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (DMA_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      DMA_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (DMA_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      DMA_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (DMA_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      DMA_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (DMA_START_SEC_VAR_FAST_8BIT)
   #undef      DMA_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (DMA_STOP_SEC_VAR_FAST_8BIT)
   #undef      DMA_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (DMA_START_SEC_VAR_FAST_16BIT)
   #undef      DMA_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (DMA_STOP_SEC_VAR_FAST_16BIT)
   #undef      DMA_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (DMA_START_SEC_VAR_FAST_32BIT)
   #undef      DMA_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (DMA_STOP_SEC_VAR_FAST_32BIT)
   #undef      DMA_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (DMA_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      DMA_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (DMA_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      DMA_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (DMA_START_SEC_VAR_8BIT)
   #undef      DMA_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (DMA_STOP_SEC_VAR_8BIT)
   #undef      DMA_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (DMA_START_SEC_VAR_16BIT)
   #undef      DMA_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (DMA_STOP_SEC_VAR_16BIT)
   #undef      DMA_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (DMA_START_SEC_VAR_32BIT)
   #undef      DMA_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (DMA_STOP_SEC_VAR_32BIT)
   #undef      DMA_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (DMA_START_SEC_VAR_UNSPECIFIED)
   #undef      DMA_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (DMA_STOP_SEC_VAR_UNSPECIFIED)
   #undef      DMA_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (DMA_START_SEC_CONST_8BIT)
   #undef      DMA_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (DMA_STOP_SEC_CONST_8BIT)
   #undef      DMA_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (DMA_START_SEC_CONST_16BIT)
   #undef      DMA_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (DMA_STOP_SEC_CONST_16BIT)
   #undef      DMA_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (DMA_START_SEC_CONST_32BIT)
   #undef      DMA_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (DMA_STOP_SEC_CONST_32BIT)
   #undef      DMA_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (DMA_START_SEC_CONST_UNSPECIFIED)
   #undef      DMA_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (DMA_STOP_SEC_CONST_UNSPECIFIED)
   #undef      DMA_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (DMA_START_SEC_POSTBUILDCFG)
   #undef      DMA_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (DMA_STOP_SEC_POSTBUILDCFG)
   #undef      DMA_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 FLSLOADER                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (FLSLOADER_START_SEC_CODE)
   #undef      FLSLOADER_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (FLSLOADER_STOP_SEC_CODE)
   #undef      FLSLOADER_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (FLSLOADER_START_SEC_WRITE_CODE)
   #undef      FLSLOADER_START_SEC_WRITE_CODE
   #define   FLSLOADER_START_SEC_RAMCODE
#elif defined (FLSLOADER_STOP_SEC_WRITE_CODE)
   #undef      FLSLOADER_STOP_SEC_WRITE_CODE
   #define FLSLOADER_STOP_SEC_RAMCODE


#elif defined (FLSLOADER_START_SEC_VAR_NOINIT_8BIT)
   #undef      FLSLOADER_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      FLSLOADER_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_NOINIT_16BIT)
   #undef      FLSLOADER_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      FLSLOADER_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_NOINIT_32BIT)
   #undef      FLSLOADER_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      FLSLOADER_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      FLSLOADER_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      FLSLOADER_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      FLSLOADER_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      FLSLOADER_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      FLSLOADER_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      FLSLOADER_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      FLSLOADER_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      FLSLOADER_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      FLSLOADER_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      FLSLOADER_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_FAST_8BIT)
   #undef      FLSLOADER_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_FAST_8BIT)
   #undef      FLSLOADER_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_FAST_16BIT)
   #undef      FLSLOADER_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_FAST_16BIT)
   #undef      FLSLOADER_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_FAST_32BIT)
   #undef      FLSLOADER_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_FAST_32BIT)
   #undef      FLSLOADER_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      FLSLOADER_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      FLSLOADER_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_8BIT)
   #undef      FLSLOADER_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_8BIT)
   #undef      FLSLOADER_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_16BIT)
   #undef      FLSLOADER_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_16BIT)
   #undef      FLSLOADER_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_32BIT)
   #undef      FLSLOADER_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_32BIT)
   #undef      FLSLOADER_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_UNSPECIFIED)
   #undef      FLSLOADER_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_UNSPECIFIED)
   #undef      FLSLOADER_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (FLSLOADER_START_SEC_CONST_8BIT)
   #undef      FLSLOADER_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_CONST_8BIT)
   #undef      FLSLOADER_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (FLSLOADER_START_SEC_CONST_16BIT)
   #undef      FLSLOADER_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_CONST_16BIT)
   #undef      FLSLOADER_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (FLSLOADER_START_SEC_CONST_32BIT)
   #undef      FLSLOADER_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_CONST_32BIT)
   #undef      FLSLOADER_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (FLSLOADER_START_SEC_CONST_UNSPECIFIED)
   #undef      FLSLOADER_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (FLSLOADER_STOP_SEC_CONST_UNSPECIFIED)
   #undef      FLSLOADER_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED

/*****************************************************************************
**                                 IRQ                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (IRQ_START_SEC_CODE)
   #undef      IRQ_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (IRQ_STOP_SEC_CODE)
   #undef      IRQ_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (IRQ_START_SEC_VAR_NOINIT_8BIT)
   #undef      IRQ_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (IRQ_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      IRQ_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (IRQ_START_SEC_VAR_NOINIT_16BIT)
   #undef      IRQ_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (IRQ_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      IRQ_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (IRQ_START_SEC_VAR_NOINIT_32BIT)
   #undef      IRQ_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (IRQ_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      IRQ_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (IRQ_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      IRQ_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (IRQ_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      IRQ_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (IRQ_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      IRQ_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (IRQ_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      IRQ_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (IRQ_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      IRQ_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (IRQ_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      IRQ_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (IRQ_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      IRQ_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (IRQ_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      IRQ_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (IRQ_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      IRQ_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (IRQ_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      IRQ_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (IRQ_START_SEC_VAR_FAST_8BIT)
   #undef      IRQ_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (IRQ_STOP_SEC_VAR_FAST_8BIT)
   #undef      IRQ_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (IRQ_START_SEC_VAR_FAST_16BIT)
   #undef      IRQ_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (IRQ_STOP_SEC_VAR_FAST_16BIT)
   #undef      IRQ_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (IRQ_START_SEC_VAR_FAST_32BIT)
   #undef      IRQ_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (IRQ_STOP_SEC_VAR_FAST_32BIT)
   #undef      IRQ_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (IRQ_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      IRQ_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (IRQ_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      IRQ_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (IRQ_START_SEC_VAR_8BIT)
   #undef      IRQ_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (IRQ_STOP_SEC_VAR_8BIT)
   #undef      IRQ_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (IRQ_START_SEC_VAR_16BIT)
   #undef      IRQ_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (IRQ_STOP_SEC_VAR_16BIT)
   #undef      IRQ_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (IRQ_START_SEC_VAR_32BIT)
   #undef      IRQ_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (IRQ_STOP_SEC_VAR_32BIT)
   #undef      IRQ_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (IRQ_START_SEC_VAR_UNSPECIFIED)
   #undef      IRQ_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (IRQ_STOP_SEC_VAR_UNSPECIFIED)
   #undef      IRQ_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (IRQ_START_SEC_CONST_8BIT)
   #undef      IRQ_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (IRQ_STOP_SEC_CONST_8BIT)
   #undef      IRQ_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (IRQ_START_SEC_CONST_16BIT)
   #undef      IRQ_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (IRQ_STOP_SEC_CONST_16BIT)
   #undef      IRQ_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (IRQ_START_SEC_CONST_32BIT)
   #undef      IRQ_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (IRQ_STOP_SEC_CONST_32BIT)
   #undef      IRQ_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (IRQ_START_SEC_CONST_UNSPECIFIED)
   #undef      IRQ_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (IRQ_STOP_SEC_CONST_UNSPECIFIED)
   #undef      IRQ_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED

/*****************************************************************************
**                                 FEE                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (FEE_START_SEC_CODE)
   #undef      FEE_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (FEE_STOP_SEC_CODE)
   #undef      FEE_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (FEE_START_SEC_VAR_NOINIT_8BIT)
   #undef      FEE_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (FEE_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      FEE_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (FEE_START_SEC_VAR_NOINIT_16BIT)
   #undef      FEE_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (FEE_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      FEE_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (FEE_START_SEC_VAR_NOINIT_32BIT)
   #undef      FEE_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (FEE_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      FEE_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (FEE_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      FEE_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (FEE_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      FEE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (FEE_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      FEE_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (FEE_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      FEE_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (FEE_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      FEE_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (FEE_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      FEE_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (FEE_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      FEE_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (FEE_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      FEE_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (FEE_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      FEE_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (FEE_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      FEE_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (FEE_START_SEC_VAR_FAST_8BIT)
   #undef      FEE_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (FEE_STOP_SEC_VAR_FAST_8BIT)
   #undef      FEE_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (FEE_START_SEC_VAR_FAST_16BIT)
   #undef      FEE_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (FEE_STOP_SEC_VAR_FAST_16BIT)
   #undef      FEE_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (FEE_START_SEC_VAR_FAST_32BIT)
   #undef      FEE_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (FEE_STOP_SEC_VAR_FAST_32BIT)
   #undef      FEE_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (FEE_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      FEE_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (FEE_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      FEE_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (FEE_START_SEC_VAR_8BIT)
   #undef      FEE_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (FEE_STOP_SEC_VAR_8BIT)
   #undef      FEE_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (FEE_START_SEC_VAR_16BIT)
   #undef      FEE_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (FEE_STOP_SEC_VAR_16BIT)
   #undef      FEE_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (FEE_START_SEC_VAR_32BIT)
   #undef      FEE_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (FEE_STOP_SEC_VAR_32BIT)
   #undef      FEE_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (FEE_START_SEC_SPL_VAR_32BIT)
   #undef      FEE_START_SEC_SPL_VAR_32BIT
   #define   DEFAULT_START_SEC_SPL_VAR_32BIT_SHARED
#elif defined (FEE_STOP_SEC_SPL_VAR_32BIT)
   #undef      FEE_STOP_SEC_SPL_VAR_32BIT
   #define DEFAULT_STOP_SEC_SPL_VAR_32BIT_SHARED


#elif defined (FEE_START_SEC_VAR_UNSPECIFIED)
   #undef      FEE_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (FEE_STOP_SEC_VAR_UNSPECIFIED)
   #undef      FEE_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (FEE_START_SEC_CONST_8BIT)
   #undef      FEE_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (FEE_STOP_SEC_CONST_8BIT)
   #undef      FEE_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (FEE_START_SEC_CONST_16BIT)
   #undef      FEE_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (FEE_STOP_SEC_CONST_16BIT)
   #undef      FEE_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (FEE_START_SEC_CONST_32BIT)
   #undef      FEE_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (FEE_STOP_SEC_CONST_32BIT)
   #undef      FEE_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (FEE_START_SEC_CONST_UNSPECIFIED)
   #undef      FEE_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (FEE_STOP_SEC_CONST_UNSPECIFIED)
   #undef      FEE_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED

/*****************************************************************************
**                                 SENT                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (SENT_START_SEC_POSTBUILDCFG)
   #undef      SENT_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (SENT_STOP_SEC_POSTBUILDCFG)
   #undef      SENT_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED


#elif defined (SENT_START_SEC_CONST_UNSPECIFIED)
   #undef      SENT_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (SENT_STOP_SEC_CONST_UNSPECIFIED)
   #undef      SENT_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (SENT_START_SEC_VAR_32BIT)
   #undef      SENT_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (SENT_STOP_SEC_VAR_32BIT)
   #undef      SENT_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (SENT_START_SEC_VAR_8BIT)
   #undef      SENT_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (SENT_STOP_SEC_VAR_8BIT)
   #undef      SENT_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (SENT_START_SEC_CODE)
   #undef      SENT_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (SENT_STOP_SEC_CODE)
   #undef      SENT_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED

/*****************************************************************************
**                                 IOM                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (IOM_START_SEC_POSTBUILDCFG)
   #undef      IOM_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (IOM_STOP_SEC_POSTBUILDCFG)
   #undef      IOM_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED


#elif defined (IOM_START_SEC_CODE)
   #undef      IOM_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (IOM_STOP_SEC_CODE)
   #undef      IOM_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (IOM_START_SEC_VAR_8BIT)
   #undef      IOM_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (IOM_STOP_SEC_VAR_8BIT)
   #undef      IOM_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (IOM_START_SEC_VAR_32BIT)
   #undef      IOM_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (IOM_STOP_SEC_VAR_32BIT)
   #undef      IOM_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED

/*****************************************************************************
**                                 FLS_17_PMU                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (FLS_17_PMU_START_SEC_CODE)
   #undef      FLS_17_PMU_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_CODE)
   #undef      FLS_17_PMU_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_NOINIT_8BIT)
   #undef      FLS_17_PMU_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      FLS_17_PMU_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_NOINIT_16BIT)
   #undef      FLS_17_PMU_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      FLS_17_PMU_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_NOINIT_32BIT)
   #undef      FLS_17_PMU_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      FLS_17_PMU_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      FLS_17_PMU_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      FLS_17_PMU_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      FLS_17_PMU_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      FLS_17_PMU_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      FLS_17_PMU_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      FLS_17_PMU_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      FLS_17_PMU_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      FLS_17_PMU_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      FLS_17_PMU_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      FLS_17_PMU_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_FAST_8BIT)
   #undef      FLS_17_PMU_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_FAST_8BIT)
   #undef      FLS_17_PMU_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_FAST_16BIT)
   #undef      FLS_17_PMU_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_FAST_16BIT)
   #undef      FLS_17_PMU_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_FAST_32BIT)
   #undef      FLS_17_PMU_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_FAST_32BIT)
   #undef      FLS_17_PMU_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      FLS_17_PMU_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      FLS_17_PMU_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_8BIT)
   #undef      FLS_17_PMU_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_8BIT)
   #undef      FLS_17_PMU_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_16BIT)
   #undef      FLS_17_PMU_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_16BIT)
   #undef      FLS_17_PMU_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_32BIT)
   #undef      FLS_17_PMU_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_32BIT)
   #undef      FLS_17_PMU_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_UNSPECIFIED)
   #undef      FLS_17_PMU_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_UNSPECIFIED)
   #undef      FLS_17_PMU_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (FLS_17_PMU_START_SEC_CONST_8BIT)
   #undef      FLS_17_PMU_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_CONST_8BIT)
   #undef      FLS_17_PMU_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_CONST_16BIT)
   #undef      FLS_17_PMU_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_CONST_16BIT)
   #undef      FLS_17_PMU_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_CONST_32BIT)
   #undef      FLS_17_PMU_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_CONST_32BIT)
   #undef      FLS_17_PMU_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_CONST_UNSPECIFIED)
   #undef      FLS_17_PMU_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_CONST_UNSPECIFIED)
   #undef      FLS_17_PMU_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (FLS_17_PMU_START_SEC_POSTBUILDCFG)
   #undef      FLS_17_PMU_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_POSTBUILDCFG)
   #undef      FLS_17_PMU_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 ERU                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (ERU_START_SEC_CODE)
   #undef      ERU_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (ERU_STOP_SEC_CODE)
   #undef      ERU_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (ERU_START_SEC_VAR_NOINIT_8BIT)
   #undef      ERU_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (ERU_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      ERU_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (ERU_START_SEC_VAR_NOINIT_16BIT)
   #undef      ERU_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (ERU_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      ERU_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (ERU_START_SEC_VAR_NOINIT_32BIT)
   #undef      ERU_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (ERU_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      ERU_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (ERU_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      ERU_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (ERU_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      ERU_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (ERU_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      ERU_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (ERU_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      ERU_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (ERU_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      ERU_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (ERU_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      ERU_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (ERU_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      ERU_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (ERU_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      ERU_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (ERU_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      ERU_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (ERU_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      ERU_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (ERU_START_SEC_VAR_FAST_8BIT)
   #undef      ERU_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (ERU_STOP_SEC_VAR_FAST_8BIT)
   #undef      ERU_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (ERU_START_SEC_VAR_FAST_16BIT)
   #undef      ERU_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (ERU_STOP_SEC_VAR_FAST_16BIT)
   #undef      ERU_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (ERU_START_SEC_VAR_FAST_32BIT)
   #undef      ERU_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (ERU_STOP_SEC_VAR_FAST_32BIT)
   #undef      ERU_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (ERU_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      ERU_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (ERU_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      ERU_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (ERU_START_SEC_VAR_8BIT)
   #undef      ERU_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (ERU_STOP_SEC_VAR_8BIT)
   #undef      ERU_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (ERU_START_SEC_VAR_16BIT)
   #undef      ERU_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (ERU_STOP_SEC_VAR_16BIT)
   #undef      ERU_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (ERU_START_SEC_VAR_32BIT)
   #undef      ERU_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (ERU_STOP_SEC_VAR_32BIT)
   #undef      ERU_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (ERU_START_SEC_VAR_UNSPECIFIED)
   #undef      ERU_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (ERU_STOP_SEC_VAR_UNSPECIFIED)
   #undef      ERU_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (ERU_START_SEC_CONST_8BIT)
   #undef      ERU_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (ERU_STOP_SEC_CONST_8BIT)
   #undef      ERU_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (ERU_START_SEC_CONST_16BIT)
   #undef      ERU_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (ERU_STOP_SEC_CONST_16BIT)
   #undef      ERU_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (ERU_START_SEC_CONST_32BIT)
   #undef      ERU_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (ERU_STOP_SEC_CONST_32BIT)
   #undef      ERU_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (ERU_START_SEC_CONST_UNSPECIFIED)
   #undef      ERU_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (ERU_STOP_SEC_CONST_UNSPECIFIED)
   #undef      ERU_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED

/*****************************************************************************
**                                 MSC                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (MSC_START_SEC_CODE)
   #undef      MSC_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (MSC_STOP_SEC_CODE)
   #undef      MSC_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (MSC_START_SEC_VAR_NOINIT_8BIT)
   #undef      MSC_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (MSC_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      MSC_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (MSC_START_SEC_VAR_NOINIT_16BIT)
   #undef      MSC_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (MSC_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      MSC_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (MSC_START_SEC_VAR_NOINIT_32BIT)
   #undef      MSC_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (MSC_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      MSC_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (MSC_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      MSC_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (MSC_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      MSC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (MSC_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      MSC_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (MSC_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      MSC_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (MSC_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      MSC_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (MSC_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      MSC_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (MSC_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      MSC_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (MSC_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      MSC_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (MSC_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      MSC_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (MSC_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      MSC_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (MSC_START_SEC_VAR_FAST_8BIT)
   #undef      MSC_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (MSC_STOP_SEC_VAR_FAST_8BIT)
   #undef      MSC_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (MSC_START_SEC_VAR_FAST_16BIT)
   #undef      MSC_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (MSC_STOP_SEC_VAR_FAST_16BIT)
   #undef      MSC_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (MSC_START_SEC_VAR_FAST_32BIT)
   #undef      MSC_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (MSC_STOP_SEC_VAR_FAST_32BIT)
   #undef      MSC_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (MSC_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      MSC_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (MSC_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      MSC_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (MSC_START_SEC_VAR_8BIT)
   #undef      MSC_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (MSC_STOP_SEC_VAR_8BIT)
   #undef      MSC_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (MSC_START_SEC_VAR_16BIT)
   #undef      MSC_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (MSC_STOP_SEC_VAR_16BIT)
   #undef      MSC_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (MSC_START_SEC_VAR_32BIT)
   #undef      MSC_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (MSC_STOP_SEC_VAR_32BIT)
   #undef      MSC_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (MSC_START_SEC_VAR_UNSPECIFIED)
   #undef      MSC_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (MSC_STOP_SEC_VAR_UNSPECIFIED)
   #undef      MSC_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (MSC_START_SEC_CONST_8BIT)
   #undef      MSC_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (MSC_STOP_SEC_CONST_8BIT)
   #undef      MSC_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (MSC_START_SEC_CONST_16BIT)
   #undef      MSC_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (MSC_STOP_SEC_CONST_16BIT)
   #undef      MSC_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (MSC_START_SEC_CONST_32BIT)
   #undef      MSC_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (MSC_STOP_SEC_CONST_32BIT)
   #undef      MSC_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (MSC_START_SEC_CONST_UNSPECIFIED)
   #undef      MSC_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (MSC_STOP_SEC_CONST_UNSPECIFIED)
   #undef      MSC_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (MSC_START_SEC_POSTBUILDCFG)
   #undef      MSC_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (MSC_STOP_SEC_POSTBUILDCFG)
   #undef      MSC_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 STDLIN                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (STDLIN_START_SEC_CODE)
   #undef      STDLIN_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (STDLIN_STOP_SEC_CODE)
   #undef      STDLIN_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (STDLIN_START_SEC_VAR_NOINIT_8BIT)
   #undef      STDLIN_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (STDLIN_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      STDLIN_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (STDLIN_START_SEC_VAR_NOINIT_16BIT)
   #undef      STDLIN_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (STDLIN_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      STDLIN_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (STDLIN_START_SEC_VAR_NOINIT_32BIT)
   #undef      STDLIN_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (STDLIN_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      STDLIN_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (STDLIN_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      STDLIN_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (STDLIN_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      STDLIN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (STDLIN_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      STDLIN_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (STDLIN_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      STDLIN_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (STDLIN_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      STDLIN_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (STDLIN_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      STDLIN_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (STDLIN_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      STDLIN_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (STDLIN_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      STDLIN_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (STDLIN_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      STDLIN_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (STDLIN_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      STDLIN_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (STDLIN_START_SEC_VAR_FAST_8BIT)
   #undef      STDLIN_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (STDLIN_STOP_SEC_VAR_FAST_8BIT)
   #undef      STDLIN_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (STDLIN_START_SEC_VAR_FAST_16BIT)
   #undef      STDLIN_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (STDLIN_STOP_SEC_VAR_FAST_16BIT)
   #undef      STDLIN_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (STDLIN_START_SEC_VAR_FAST_32BIT)
   #undef      STDLIN_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (STDLIN_STOP_SEC_VAR_FAST_32BIT)
   #undef      STDLIN_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (STDLIN_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      STDLIN_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (STDLIN_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      STDLIN_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (STDLIN_START_SEC_VAR_8BIT)
   #undef      STDLIN_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (STDLIN_STOP_SEC_VAR_8BIT)
   #undef      STDLIN_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (STDLIN_START_SEC_VAR_16BIT)
   #undef      STDLIN_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (STDLIN_STOP_SEC_VAR_16BIT)
   #undef      STDLIN_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (STDLIN_START_SEC_VAR_32BIT)
   #undef      STDLIN_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (STDLIN_STOP_SEC_VAR_32BIT)
   #undef      STDLIN_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (STDLIN_START_SEC_VAR_UNSPECIFIED)
   #undef      STDLIN_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (STDLIN_STOP_SEC_VAR_UNSPECIFIED)
   #undef      STDLIN_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (STDLIN_START_SEC_CONST_8BIT)
   #undef      STDLIN_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (STDLIN_STOP_SEC_CONST_8BIT)
   #undef      STDLIN_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (STDLIN_START_SEC_CONST_16BIT)
   #undef      STDLIN_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (STDLIN_STOP_SEC_CONST_16BIT)
   #undef      STDLIN_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (STDLIN_START_SEC_CONST_32BIT)
   #undef      STDLIN_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (STDLIN_STOP_SEC_CONST_32BIT)
   #undef      STDLIN_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (STDLIN_START_SEC_CONST_UNSPECIFIED)
   #undef      STDLIN_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (STDLIN_STOP_SEC_CONST_UNSPECIFIED)
   #undef      STDLIN_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (STDLIN_START_SEC_POSTBUILDCFG)
   #undef      STDLIN_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (STDLIN_STOP_SEC_POSTBUILDCFG)
   #undef      STDLIN_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 LIN_17_ASCLIN                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (LIN_17_ASCLIN_START_SEC_CODE)
   #undef      LIN_17_ASCLIN_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_CODE)
   #undef      LIN_17_ASCLIN_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_NOINIT_8BIT)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_NOINIT_16BIT)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_NOINIT_32BIT)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_FAST_8BIT)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_FAST_8BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_FAST_16BIT)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_FAST_16BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_FAST_32BIT)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_FAST_32BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_8BIT)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_8BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_16BIT)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_16BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_32BIT)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_32BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_UNSPECIFIED)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_UNSPECIFIED)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_CONST_8BIT)
   #undef      LIN_17_ASCLIN_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_CONST_8BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_CONST_16BIT)
   #undef      LIN_17_ASCLIN_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_CONST_16BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_CONST_32BIT)
   #undef      LIN_17_ASCLIN_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_CONST_32BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_CONST_UNSPECIFIED)
   #undef      LIN_17_ASCLIN_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_CONST_UNSPECIFIED)
   #undef      LIN_17_ASCLIN_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_POSTBUILDCFG)
   #undef      LIN_17_ASCLIN_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_POSTBUILDCFG)
   #undef      LIN_17_ASCLIN_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 UART                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (UART_START_SEC_CODE)
   #undef      UART_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (UART_STOP_SEC_CODE)
   #undef      UART_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (UART_START_SEC_VAR_NOINIT_8BIT)
   #undef      UART_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (UART_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      UART_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (UART_START_SEC_VAR_NOINIT_16BIT)
   #undef      UART_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (UART_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      UART_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (UART_START_SEC_VAR_NOINIT_32BIT)
   #undef      UART_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (UART_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      UART_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (UART_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      UART_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (UART_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      UART_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (UART_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      UART_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (UART_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      UART_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (UART_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      UART_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (UART_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      UART_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (UART_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      UART_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (UART_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      UART_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (UART_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      UART_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (UART_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      UART_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (UART_START_SEC_VAR_FAST_8BIT)
   #undef      UART_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (UART_STOP_SEC_VAR_FAST_8BIT)
   #undef      UART_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (UART_START_SEC_VAR_FAST_16BIT)
   #undef      UART_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (UART_STOP_SEC_VAR_FAST_16BIT)
   #undef      UART_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (UART_START_SEC_VAR_FAST_32BIT)
   #undef      UART_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (UART_STOP_SEC_VAR_FAST_32BIT)
   #undef      UART_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (UART_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      UART_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (UART_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      UART_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (UART_START_SEC_VAR_8BIT)
   #undef      UART_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (UART_STOP_SEC_VAR_8BIT)
   #undef      UART_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (UART_START_SEC_VAR_16BIT)
   #undef      UART_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (UART_STOP_SEC_VAR_16BIT)
   #undef      UART_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (UART_START_SEC_VAR_32BIT)
   #undef      UART_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (UART_STOP_SEC_VAR_32BIT)
   #undef      UART_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (UART_START_SEC_VAR_INIT_8BIT)
   #undef      UART_START_SEC_VAR_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_INIT_8BIT_SHARED
#elif defined (UART_STOP_SEC_VAR_INIT_8BIT)
   #undef      UART_STOP_SEC_VAR_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_INIT_8BIT_SHARED


#elif defined (UART_START_SEC_VAR_UNSPECIFIED)
   #undef      UART_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (UART_STOP_SEC_VAR_UNSPECIFIED)
   #undef      UART_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (UART_START_SEC_CONST_8BIT)
   #undef      UART_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (UART_STOP_SEC_CONST_8BIT)
   #undef      UART_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (UART_START_SEC_CONST_16BIT)
   #undef      UART_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (UART_STOP_SEC_CONST_16BIT)
   #undef      UART_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (UART_START_SEC_CONST_32BIT)
   #undef      UART_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (UART_STOP_SEC_CONST_32BIT)
   #undef      UART_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (UART_START_SEC_CONST_UNSPECIFIED)
   #undef      UART_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (UART_STOP_SEC_CONST_UNSPECIFIED)
   #undef      UART_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (UART_START_SEC_POSTBUILDCFG)
   #undef      UART_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (UART_STOP_SEC_POSTBUILDCFG)
   #undef      UART_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 CANTRCV6251G                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (CANTRCV6251G_START_SEC_CODE)
   #undef      CANTRCV6251G_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_CODE)
   #undef      CANTRCV6251G_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_NOINIT_8BIT)
   #undef      CANTRCV6251G_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      CANTRCV6251G_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_NOINIT_16BIT)
   #undef      CANTRCV6251G_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      CANTRCV6251G_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_NOINIT_32BIT)
   #undef      CANTRCV6251G_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      CANTRCV6251G_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      CANTRCV6251G_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      CANTRCV6251G_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      CANTRCV6251G_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      CANTRCV6251G_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      CANTRCV6251G_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      CANTRCV6251G_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      CANTRCV6251G_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      CANTRCV6251G_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      CANTRCV6251G_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      CANTRCV6251G_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_FAST_8BIT)
   #undef      CANTRCV6251G_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_FAST_8BIT)
   #undef      CANTRCV6251G_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_FAST_16BIT)
   #undef      CANTRCV6251G_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_FAST_16BIT)
   #undef      CANTRCV6251G_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_FAST_32BIT)
   #undef      CANTRCV6251G_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_FAST_32BIT)
   #undef      CANTRCV6251G_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      CANTRCV6251G_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      CANTRCV6251G_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_8BIT)
   #undef      CANTRCV6251G_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_8BIT)
   #undef      CANTRCV6251G_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_16BIT)
   #undef      CANTRCV6251G_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_16BIT)
   #undef      CANTRCV6251G_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_32BIT)
   #undef      CANTRCV6251G_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_32BIT)
   #undef      CANTRCV6251G_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_UNSPECIFIED)
   #undef      CANTRCV6251G_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_UNSPECIFIED)
   #undef      CANTRCV6251G_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (CANTRCV6251G_START_SEC_CONST_8BIT)
   #undef      CANTRCV6251G_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_CONST_8BIT)
   #undef      CANTRCV6251G_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_CONST_16BIT)
   #undef      CANTRCV6251G_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_CONST_16BIT)
   #undef      CANTRCV6251G_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_CONST_32BIT)
   #undef      CANTRCV6251G_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_CONST_32BIT)
   #undef      CANTRCV6251G_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_CONST_UNSPECIFIED)
   #undef      CANTRCV6251G_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_CONST_UNSPECIFIED)
   #undef      CANTRCV6251G_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED

/*****************************************************************************
**                                 ETH_17_ETHMAC                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (ETH_17_ETHMAC_START_SEC_CODE)
   #undef      ETH_17_ETHMAC_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_CORE0_PRIVATE
#elif defined (ETH_17_ETHMAC_STOP_SEC_CODE)
   #undef      ETH_17_ETHMAC_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_CORE0_PRIVATE


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_NOINIT_8BIT)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_NOINIT_16BIT)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_NOINIT_32BIT)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_FAST_16BIT)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_CORE0_PRIVATE
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_FAST_16BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE0_PRIVATE


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_8BIT)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_CORE0_PRIVATE
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_8BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_CORE0_PRIVATE


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_16BIT)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_CORE0_PRIVATE
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_16BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_CORE0_PRIVATE


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_32BIT)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_CORE0_PRIVATE
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_32BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_CORE0_PRIVATE


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_UNSPECIFIED)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_UNSPECIFIED)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE


#elif defined (ETH_17_ETHMAC_START_SEC_CONST_8BIT)
   #undef      ETH_17_ETHMAC_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_CORE0_PRIVATE
#elif defined (ETH_17_ETHMAC_STOP_SEC_CONST_8BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_CORE0_PRIVATE


#elif defined (ETH_17_ETHMAC_START_SEC_CONST_16BIT)
   #undef      ETH_17_ETHMAC_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_CORE0_PRIVATE
#elif defined (ETH_17_ETHMAC_STOP_SEC_CONST_16BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_CORE0_PRIVATE


#elif defined (ETH_17_ETHMAC_START_SEC_CONST_32BIT)
   #undef      ETH_17_ETHMAC_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_CORE0_PRIVATE
#elif defined (ETH_17_ETHMAC_STOP_SEC_CONST_32BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_CORE0_PRIVATE


#elif defined (ETH_17_ETHMAC_START_SEC_CONST_UNSPECIFIED)
   #undef      ETH_17_ETHMAC_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE
#elif defined (ETH_17_ETHMAC_STOP_SEC_CONST_UNSPECIFIED)
   #undef      ETH_17_ETHMAC_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE


#elif defined (ETH_17_ETHMAC_START_SEC_POSTBUILDCFG)
   #undef      ETH_17_ETHMAC_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_CORE0_PRIVATE
#elif defined (ETH_17_ETHMAC_STOP_SEC_POSTBUILDCFG)
   #undef      ETH_17_ETHMAC_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_CORE0_PRIVATE


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_INIT_32BIT)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_INIT_32BIT_CORE0_PRIVATE
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_INIT_32BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_INIT_32BIT_CORE0_PRIVATE

/*****************************************************************************
**                                 CRC                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (CRC_START_SEC_POSTBUILDCFG)
   #undef      CRC_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (CRC_STOP_SEC_POSTBUILDCFG)
   #undef      CRC_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED


#elif defined (CRC_START_SEC_CODE)
   #undef      CRC_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (CRC_STOP_SEC_CODE)
   #undef      CRC_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (CRC_START_SEC_VAR_NOINIT_8BIT)
   #undef      CRC_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (CRC_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      CRC_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (CRC_START_SEC_VAR_NOINIT_16BIT)
   #undef      CRC_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (CRC_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      CRC_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (CRC_START_SEC_VAR_NOINIT_32BIT)
   #undef      CRC_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (CRC_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      CRC_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (CRC_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      CRC_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (CRC_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      CRC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (CRC_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      CRC_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (CRC_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      CRC_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (CRC_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      CRC_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (CRC_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      CRC_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (CRC_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      CRC_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (CRC_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      CRC_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (CRC_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      CRC_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (CRC_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      CRC_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (CRC_START_SEC_VAR_FAST_16BIT)
   #undef      CRC_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (CRC_STOP_SEC_VAR_FAST_16BIT)
   #undef      CRC_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (CRC_START_SEC_VAR_FAST1_32BIT)
   #undef      CRC_START_SEC_VAR_FAST1_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST1_32BIT_SHARED
#elif defined (CRC_STOP_SEC_VAR_FAST1_32BIT)
   #undef      CRC_STOP_SEC_VAR_FAST1_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST1_32BIT_SHARED


#elif defined (CRC_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      CRC_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (CRC_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      CRC_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (CRC_START_SEC_VAR_8BIT)
   #undef      CRC_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (CRC_STOP_SEC_VAR_8BIT)
   #undef      CRC_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (CRC_START_SEC_VAR_16BIT)
   #undef      CRC_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (CRC_STOP_SEC_VAR_16BIT)
   #undef      CRC_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (CRC_START_SEC_VAR_32BIT)
   #undef      CRC_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (CRC_STOP_SEC_VAR_32BIT)
   #undef      CRC_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (CRC_START_SEC_VAR_UNSPECIFIED)
   #undef      CRC_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (CRC_STOP_SEC_VAR_UNSPECIFIED)
   #undef      CRC_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (CRC_START_SEC_CONST_8BIT)
   #undef      CRC_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (CRC_STOP_SEC_CONST_8BIT)
   #undef      CRC_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (CRC_START_SEC_CONST_16BIT)
   #undef      CRC_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (CRC_STOP_SEC_CONST_16BIT)
   #undef      CRC_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (CRC_START_SEC_CONST_32BIT)
   #undef      CRC_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (CRC_STOP_SEC_CONST_32BIT)
   #undef      CRC_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (CRC_START_SEC_CONST_UNSPECIFIED)
   #undef      CRC_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (CRC_STOP_SEC_CONST_UNSPECIFIED)
   #undef      CRC_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED

/*****************************************************************************
**                                 FR_17_ERAY                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (FR_17_ERAY_START_SEC_CODE)
   #undef      FR_17_ERAY_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_CODE)
   #undef      FR_17_ERAY_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_NOINIT_8BIT)
   #undef      FR_17_ERAY_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      FR_17_ERAY_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_NOINIT_16BIT)
   #undef      FR_17_ERAY_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      FR_17_ERAY_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_NOINIT_32BIT)
   #undef      FR_17_ERAY_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      FR_17_ERAY_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      FR_17_ERAY_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      FR_17_ERAY_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      FR_17_ERAY_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      FR_17_ERAY_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      FR_17_ERAY_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      FR_17_ERAY_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      FR_17_ERAY_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      FR_17_ERAY_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      FR_17_ERAY_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      FR_17_ERAY_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_FAST_8BIT)
   #undef      FR_17_ERAY_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_FAST_8BIT)
   #undef      FR_17_ERAY_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_FAST_16BIT)
   #undef      FR_17_ERAY_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_FAST_16BIT)
   #undef      FR_17_ERAY_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_FAST_32BIT)
   #undef      FR_17_ERAY_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_FAST_32BIT)
   #undef      FR_17_ERAY_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      FR_17_ERAY_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      FR_17_ERAY_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_8BIT)
   #undef      FR_17_ERAY_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_8BIT)
   #undef      FR_17_ERAY_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_16BIT)
   #undef      FR_17_ERAY_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_16BIT)
   #undef      FR_17_ERAY_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_32BIT)
   #undef      FR_17_ERAY_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_32BIT)
   #undef      FR_17_ERAY_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_INIT_8BIT)
   #undef      FR_17_ERAY_START_SEC_VAR_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_INIT_8BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_INIT_8BIT)
   #undef      FR_17_ERAY_STOP_SEC_VAR_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_INIT_8BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_INIT_32BIT)
   #undef      FR_17_ERAY_START_SEC_VAR_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_INIT_32BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_INIT_32BIT)
   #undef      FR_17_ERAY_STOP_SEC_VAR_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_INIT_32BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_UNSPECIFIED)
   #undef      FR_17_ERAY_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_UNSPECIFIED)
   #undef      FR_17_ERAY_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (FR_17_ERAY_START_SEC_CONST_8BIT)
   #undef      FR_17_ERAY_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_CONST_8BIT)
   #undef      FR_17_ERAY_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_CONST_16BIT)
   #undef      FR_17_ERAY_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_CONST_16BIT)
   #undef      FR_17_ERAY_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_CONST_32BIT)
   #undef      FR_17_ERAY_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_CONST_32BIT)
   #undef      FR_17_ERAY_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_CONST_UNSPECIFIED)
   #undef      FR_17_ERAY_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_CONST_UNSPECIFIED)
   #undef      FR_17_ERAY_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (FR_17_ERAY_START_SEC_POSTBUILDCFG)
   #undef      FR_17_ERAY_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_POSTBUILDCFG)
   #undef      FR_17_ERAY_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 STM                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (STM_START_SEC_CODE)
   #undef      STM_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (STM_STOP_SEC_CODE)
   #undef      STM_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (STM_START_SEC_VAR_NOINIT_8BIT)
   #undef      STM_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (STM_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      STM_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (STM_START_SEC_VAR_NOINIT_16BIT)
   #undef      STM_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (STM_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      STM_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (STM_START_SEC_VAR_NOINIT_32BIT)
   #undef      STM_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (STM_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      STM_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (STM_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      STM_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (STM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      STM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (STM_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      STM_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (STM_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      STM_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (STM_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      STM_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (STM_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      STM_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (STM_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      STM_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (STM_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      STM_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (STM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      STM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (STM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      STM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (STM_START_SEC_VAR_FAST_8BIT)
   #undef      STM_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (STM_STOP_SEC_VAR_FAST_8BIT)
   #undef      STM_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (STM_START_SEC_VAR_FAST_16BIT)
   #undef      STM_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (STM_STOP_SEC_VAR_FAST_16BIT)
   #undef      STM_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (STM_START_SEC_VAR_FAST_32BIT)
   #undef      STM_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (STM_STOP_SEC_VAR_FAST_32BIT)
   #undef      STM_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (STM_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      STM_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (STM_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      STM_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (STM_START_SEC_VAR_8BIT)
   #undef      STM_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (STM_STOP_SEC_VAR_8BIT)
   #undef      STM_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (STM_START_SEC_VAR_16BIT)
   #undef      STM_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (STM_STOP_SEC_VAR_16BIT)
   #undef      STM_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (STM_START_SEC_VAR_32BIT)
   #undef      STM_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (STM_STOP_SEC_VAR_32BIT)
   #undef      STM_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (STM_START_SEC_VAR_UNSPECIFIED)
   #undef      STM_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (STM_STOP_SEC_VAR_UNSPECIFIED)
   #undef      STM_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (STM_START_SEC_CONST_8BIT)
   #undef      STM_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (STM_STOP_SEC_CONST_8BIT)
   #undef      STM_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (STM_START_SEC_CONST_16BIT)
   #undef      STM_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (STM_STOP_SEC_CONST_16BIT)
   #undef      STM_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (STM_START_SEC_CONST_32BIT)
   #undef      STM_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (STM_STOP_SEC_CONST_32BIT)
   #undef      STM_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (STM_START_SEC_CONST_UNSPECIFIED)
   #undef      STM_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (STM_STOP_SEC_CONST_UNSPECIFIED)
   #undef      STM_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (STM_START_SEC_POSTBUILDCFG)
   #undef      STM_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (STM_STOP_SEC_POSTBUILDCFG)
   #undef      STM_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 HSSL                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (HSSL_START_SEC_CODE)
   #undef      HSSL_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (HSSL_STOP_SEC_CODE)
   #undef      HSSL_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (HSSL_START_SEC_VAR_8BIT)
   #undef      HSSL_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (HSSL_STOP_SEC_VAR_8BIT)
   #undef      HSSL_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (HSSL_START_SEC_VAR_32BIT)
   #undef      HSSL_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (HSSL_STOP_SEC_VAR_32BIT)
   #undef      HSSL_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (HSSL_START_SEC_VAR_FAST_32BIT)
   #undef      HSSL_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (HSSL_STOP_SEC_VAR_FAST_32BIT)
   #undef      HSSL_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED

/*****************************************************************************
**                                 HSM                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (HSM_START_SEC_CODE)
   #undef      HSM_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (HSM_STOP_SEC_CODE)
   #undef      HSM_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED

/*****************************************************************************
**                                 DSADC                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (DSADC_START_SEC_CODE)
   #undef      DSADC_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (DSADC_STOP_SEC_CODE)
   #undef      DSADC_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (DSADC_START_SEC_VAR_8BIT)
   #undef      DSADC_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (DSADC_STOP_SEC_VAR_8BIT)
   #undef      DSADC_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (DSADC_START_SEC_VAR_32BIT)
   #undef      DSADC_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (DSADC_STOP_SEC_VAR_32BIT)
   #undef      DSADC_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (DSADC_START_SEC_CONST_32BIT)
   #undef      DSADC_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (DSADC_STOP_SEC_CONST_32BIT)
   #undef      DSADC_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (DSADC_START_SEC_POSTBUILDCFG)
   #undef      DSADC_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (DSADC_STOP_SEC_POSTBUILDCFG)
   #undef      DSADC_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 I2C                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (I2C_START_SEC_CODE)
   #undef      I2C_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (I2C_STOP_SEC_CODE)
   #undef      I2C_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (I2C_START_SEC_VAR_8BIT)
   #undef      I2C_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (I2C_STOP_SEC_VAR_8BIT)
   #undef      I2C_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (I2C_START_SEC_VAR_32BIT)
   #undef      I2C_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (I2C_STOP_SEC_VAR_32BIT)
   #undef      I2C_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (I2C_START_SEC_VAR_UNSPECIFIED)
   #undef      I2C_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (I2C_STOP_SEC_VAR_UNSPECIFIED)
   #undef      I2C_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (I2C_START_SEC_CONST_32BIT)
   #undef      I2C_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (I2C_STOP_SEC_CONST_32BIT)
   #undef      I2C_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (I2C_START_SEC_POSTBUILDCFG)
   #undef      I2C_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (I2C_STOP_SEC_POSTBUILDCFG)
   #undef      I2C_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED
   
#elif defined (I2C_START_SEC_VAR_UNSPECIFIED)
   #undef      I2C_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (I2C_STOP_SEC_VAR_UNSPECIFIED)
   #undef      I2C_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED

/*****************************************************************************
**                                 ECUM                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
 #elif defined (ECUM_START_SEC_CODE)
   #undef      ECUM_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (ECUM_STOP_SEC_CODE)
   #undef      ECUM_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED
 
 
#elif defined (ECUM_START_SEC_CONST_32BIT)
   #undef      ECUM_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (ECUM_STOP_SEC_CONST_32BIT)
   #undef      ECUM_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (ECUM_START_SEC_VAR_32BIT)
   #undef      ECUM_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (ECUM_STOP_SEC_VAR_32BIT)
   #undef      ECUM_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (ECUM_START_SEC_POSTBUILDCFG)
   #undef      ECUM_START_SEC_POSTBUILDCFG
   #define   ECUM_START_SEC_POSTBUILDCFG_SHARED
#elif defined (ECUM_STOP_SEC_POSTBUILDCFG)
   #undef      ECUM_STOP_SEC_POSTBUILDCFG
   #define ECUM_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 MCAL                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (MCAL_START_SEC_CODE)
   #undef      MCAL_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (MCAL_STOP_SEC_CODE)
   #undef      MCAL_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (MCAL_START_SEC_VAR_FAST_32BIT)
   #undef      MCAL_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (MCAL_STOP_SEC_VAR_FAST_32BIT)
   #undef      MCAL_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (MCAL_START_SEC_CONST_UNSPECIFIED)
   #undef      MCAL_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (MCAL_STOP_SEC_CONST_UNSPECIFIED)
   #undef      MCAL_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED

/*****************************************************************************
**                                 MCAL_TCLIB                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (MCAL_TCLIB_START_SEC_CODE)
   #undef      MCAL_TCLIB_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (MCAL_TCLIB_STOP_SEC_CODE)
   #undef      MCAL_TCLIB_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (MCAL_TCLIB_START_SEC_CONST_32BIT)
   #undef      MCAL_TCLIB_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (MCAL_TCLIB_STOP_SEC_CONST_32BIT)
   #undef      MCAL_TCLIB_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (MCAL_TCLIB_START_SEC_VAR_32BIT)
   #undef      MCAL_TCLIB_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (MCAL_TCLIB_STOP_SEC_VAR_32BIT)
   #undef      MCAL_TCLIB_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (MCAL_TCLIB_START_SEC_VAR_8BIT)
   #undef      MCAL_TCLIB_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (MCAL_TCLIB_STOP_SEC_VAR_8BIT)
   #undef      MCAL_TCLIB_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (MCAL_TCLIB_START_SEC_VAR_INIT_32BIT)
   #undef      MCAL_TCLIB_START_SEC_VAR_INIT_32BIT
   #define   MCAL_TCLIB_START_SEC_VAR_NONZERO_INIT_32BIT
#elif defined (MCAL_TCLIB_STOP_SEC_VAR_INIT_32BIT)
   #undef      MCAL_TCLIB_STOP_SEC_VAR_INIT_32BIT
   #define MCAL_TCLIB_STOP_SEC_VAR_NONZERO_INIT_32BIT

/*****************************************************************************
**                                 MCAL_WDGLIB                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (MCAL_WDGLIB_START_SEC_CODE)
   #undef      MCAL_WDGLIB_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (MCAL_WDGLIB_STOP_SEC_CODE)
   #undef      MCAL_WDGLIB_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (MCAL_WDGLIB_START_SEC_CONST_32BIT)
   #undef      MCAL_WDGLIB_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (MCAL_WDGLIB_STOP_SEC_CONST_32BIT)
   #undef      MCAL_WDGLIB_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (MCAL_WDGLIB_START_SEC_VAR_8BIT)
   #undef      MCAL_WDGLIB_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (MCAL_WDGLIB_STOP_SEC_VAR_8BIT)
   #undef      MCAL_WDGLIB_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (MCAL_WDGLIB_START_SEC_VAR_32BIT)
   #undef      MCAL_WDGLIB_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (MCAL_WDGLIB_STOP_SEC_VAR_32BIT)
   #undef      MCAL_WDGLIB_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (MCAL_WDGLIB_START_SEC_VAR_INIT_32BIT)
   #undef      MCAL_WDGLIB_START_SEC_VAR_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_INIT_32BIT_SHARED
#elif defined (MCAL_WDGLIB_STOP_SEC_VAR_INIT_32BIT)
   #undef      MCAL_WDGLIB_STOP_SEC_VAR_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_INIT_32BIT_SHARED

/*****************************************************************************
**                                 MCAL_DMALIB                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (MCAL_DMALIB_START_SEC_CODE)
   #undef      MCAL_DMALIB_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (MCAL_DMALIB_STOP_SEC_CODE)
   #undef      MCAL_DMALIB_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (MCAL_DMALIB_START_SEC_CONST_32BIT)
   #undef      MCAL_DMALIB_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (MCAL_DMALIB_STOP_SEC_CONST_32BIT)
   #undef      MCAL_DMALIB_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (MCAL_DMALIB_START_SEC_VAR_8BIT)
   #undef      MCAL_DMALIB_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (MCAL_DMALIB_STOP_SEC_VAR_8BIT)
   #undef      MCAL_DMALIB_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (MCAL_DMALIB_START_SEC_VAR_32BIT)
   #undef      MCAL_DMALIB_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (MCAL_DMALIB_STOP_SEC_VAR_32BIT)
   #undef      MCAL_DMALIB_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED

/*****************************************************************************
**                                 MCAL_TRAP                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (MCAL_TRAP_START_SEC_CODE)
   #undef      MCAL_TRAP_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (MCAL_TRAP_STOP_SEC_CODE)
   #undef      MCAL_TRAP_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (MCAL_TRAP_START_SEC_CODE_CPU0_TRAP)
   #undef      MCAL_TRAP_START_SEC_CODE_CPU0_TRAP
   #define   MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU0
#elif defined (MCAL_TRAP_STOP_SEC_CODE_CPU0_TRAP)
   #undef      MCAL_TRAP_STOP_SEC_CODE_CPU0_TRAP
   #define MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU0


#elif defined (MCAL_TRAP_START_SEC_CODE_CPU1_TRAP)
   #undef      MCAL_TRAP_START_SEC_CODE_CPU1_TRAP
   #define   MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU1
#elif defined (MCAL_TRAP_STOP_SEC_CODE_CPU1_TRAP)
   #undef      MCAL_TRAP_STOP_SEC_CODE_CPU1_TRAP
   #define MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU1


#elif defined (MCAL_TRAP_START_SEC_CODE_CPU2_TRAP)
   #undef      MCAL_TRAP_START_SEC_CODE_CPU2_TRAP
   #define   MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU2
#elif defined (MCAL_TRAP_STOP_SEC_CODE_CPU2_TRAP)
   #undef      MCAL_TRAP_STOP_SEC_CODE_CPU2_TRAP
   #define MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU2


#elif defined (MCAL_TRAP_START_SEC_VAR_32BIT)
   #undef      MCAL_TRAP_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (MCAL_TRAP_STOP_SEC_VAR_32BIT)
   #undef      MCAL_TRAP_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED

/*****************************************************************************
**                                 SMU                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (SMU_START_SEC_CODE)
   #undef      SMU_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (SMU_STOP_SEC_CODE)
   #undef      SMU_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (SMU_START_SEC_VAR_INIT_8BIT)
   #undef      SMU_START_SEC_VAR_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_INIT_8BIT_SHARED
#elif defined (SMU_STOP_SEC_VAR_INIT_8BIT)
   #undef      SMU_STOP_SEC_VAR_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_INIT_8BIT_SHARED


#elif defined (SMU_START_SEC_BACKUP_VAR_INIT_8BIT)
   #undef      SMU_START_SEC_BACKUP_VAR_INIT_8BIT
   #define   DEFAULT_START_SEC_BACKUP_VAR_INIT_8BIT_SHARED
#elif defined (SMU_STOP_SEC_BACKUP_VAR_INIT_8BIT)
   #undef      SMU_STOP_SEC_BACKUP_VAR_INIT_8BIT
   #define DEFAULT_STOP_SEC_BACKUP_VAR_INIT_8BIT_SHARED


#elif defined (SMU_START_SEC_VAR_8BIT)
   #undef      SMU_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (SMU_STOP_SEC_VAR_8BIT)
   #undef      SMU_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (SMU_START_SEC_BACKUP_VAR_8BIT)
   #undef      SMU_START_SEC_BACKUP_VAR_8BIT
   #define   DEFAULT_START_SEC_BACKUP_VAR_8BIT_SHARED
#elif defined (SMU_STOP_SEC_BACKUP_VAR_8BIT)
   #undef      SMU_STOP_SEC_BACKUP_VAR_8BIT
   #define DEFAULT_STOP_SEC_BACKUP_VAR_8BIT_SHARED


#elif defined (SMU_START_SEC_POSTBUILDCFG)
   #undef      SMU_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (SMU_STOP_SEC_POSTBUILDCFG)
   #undef      SMU_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 APPL                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (APPL_START_SEC_CODE)
   #undef      APPL_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (APPL_STOP_SEC_CODE)
   #undef      APPL_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (APPL_START_SEC_VAR_32BIT)
   #undef      APPL_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (APPL_STOP_SEC_VAR_32BIT)
   #undef      APPL_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


/* -------------------------------------------------------------------------- */
/* End of module section mapping                                              */
/* -------------------------------------------------------------------------- */
    #elif defined (IRQ_START_SEC_IVT_CODE)
       #undef      IRQ_START_SEC_IVT_CODE
       #define   DEFAULT_START_SEC_IVT_CODE
    #elif defined (IRQ_STOP_SEC_IVT_CODE)
       #undef      IRQ_STOP_SEC_IVT_CODE
       #define DEFAULT_STOP_SEC_IVT_CODE
    
    #elif defined (ADC_START_SEC_VAR_DMABUFFER)
       #undef      ADC_START_SEC_VAR_DMABUFFER
       #define ADC_DMA_START_SEC_EMUXSCAN_BUFFER
    #elif defined (ADC_STOP_SEC_VAR_DMABUFFER)
       #undef      ADC_STOP_SEC_VAR_DMABUFFER
       #define ADC_DMA_STOP_SEC_EMUXSCAN_BUFFER

    #elif defined (FEE_START_SEC_JOBENDNOTIF_CODE)
       #undef   FEE_START_SEC_JOBENDNOTIF_CODE
       #define FEE_START_JOBENDNOTIF
    #elif defined (FEE_STOP_SEC_JOBENDNOTIF_CODE)
       #undef   FEE_STOP_SEC_JOBENDNOTIF_CODE
       #define FEE_STOP_JOBENDNOTIF
    
    #elif defined (FEE_START_SEC_JOBERRNOTIF_CODE)
       #undef   FEE_START_SEC_JOBERRNOTIF_CODE
       #define FEE_START_JOBERRNOTIF
    #elif defined (FEE_STOP_SEC_JOBERRNOTIF_CODE)
       #undef   FEE_STOP_SEC_JOBERRNOTIF_CODE
       #define FEE_STOP_JOBERRNOTIF

    #elif defined (FEE_START_SEC_ILLEGALNOTIF_CODE)
       #undef   FEE_START_SEC_ILLEGALNOTIF_CODE
       #define FEE_START_ILLEGALNOTIF
    #elif defined (FEE_STOP_SEC_ILLEGALNOTIF_CODE)
       #undef   FEE_STOP_SEC_ILLEGALNOTIF_CODE
       #define FEE_STOP_ILLEGALNOTIF

/* 
 * To be used for mapping FLS Write and Erase API's to user defined address 
 * external flash etc 
 */
#elif defined (FLS_17_PMU_START_SEC_SPL_CODE_WRITECMD_BEGIN)
   #undef      FLS_17_PMU_START_SEC_SPL_CODE_WRITECMD_BEGIN
   #define   FLS_17_PMU_START_SEC_SPL_CODE_WRITECMD_BEGIN_API
#elif defined (FLS_17_PMU_STOP_SEC_SPL_CODE_WRITECMD_BEGIN)
   #undef      FLS_17_PMU_STOP_SEC_SPL_CODE_WRITECMD_BEGIN
   #define   FLS_17_PMU_STOP_SEC_SPL_CODE_WRITECMD_BEGIN_API

#elif defined (FLS_17_PMU_START_SEC_SPL_CODE_WRITECMD_END)
   #undef      FLS_17_PMU_START_SEC_SPL_CODE_WRITECMD_END
   #define   FLS_17_PMU_START_SEC_SPL_CODE_WRITECMD_END_API
#elif defined (FLS_17_PMU_STOP_SEC_SPL_CODE_WRITECMD_END)
   #undef      FLS_17_PMU_STOP_SEC_SPL_CODE_WRITECMD_END
   #define   FLS_17_PMU_STOP_SEC_SPL_CODE_WRITECMD_END_API

#elif defined (FLS_17_PMU_START_SEC_SPL_CODE_ERASECMD_BEGIN)
   #undef      FLS_17_PMU_START_SEC_SPL_CODE_ERASECMD_BEGIN
   #define   FLS_17_PMU_START_SEC_SPL_CODE_ERASECMD_BEGIN_API
#elif defined (FLS_17_PMU_STOP_SEC_SPL_CODE_ERASECMD_BEGIN)
   #undef      FLS_17_PMU_STOP_SEC_SPL_CODE_ERASECMD_BEGIN
   #define   FLS_17_PMU_STOP_SEC_SPL_CODE_ERASECMD_BEGIN_API

#elif defined (FLS_17_PMU_START_SEC_SPL_CODE_ERASECMD_END)
   #undef      FLS_17_PMU_START_SEC_SPL_CODE_ERASECMD_END
   #define   FLS_17_PMU_START_SEC_SPL_CODE_ERASECMD_END_API
#elif defined (FLS_17_PMU_STOP_SEC_SPL_CODE_ERASECMD_END)
   #undef      FLS_17_PMU_STOP_SEC_SPL_CODE_ERASECMD_END
   #define   FLS_17_PMU_STOP_SEC_SPL_CODE_ERASECMD_END_API

/*
 * To be used for all global or static variables (32 bits )
 * that have atleast one of  the following properties
 * 1. accessed bitwise  2. frequently used
 * 3. high number of accesses in source code
 */ 
#elif defined (CRC_START_SEC_VAR_FAST_32BIT)
   #undef      CRC_START_SEC_VAR_FAST_32BIT
   #define CRC_RES_START_SEC_VAR_FAST_32BIT
#elif defined (CRC_STOP_SEC_VAR_FAST_32BIT)
   #undef      CRC_STOP_SEC_VAR_FAST_32BIT
   #define CRC_RES_STOP_SEC_VAR_FAST_32BIT


/* -------------------------------------------------------------------------- */
/* End of module section mapping                                              */
/* -------------------------------------------------------------------------- */

   #elif defined (PWM_17_GTM_START_SEC_CALLOUT_CODE)
   #undef      PWM_17_GTM_START_SEC_CALLOUT_CODE
   #define PWM_17_GTM_START_SEC_NOTIFICATION
   #elif defined (PWM_17_GTM_STOP_SEC_CALLOUT_CODE)
   #undef      PWM_17_GTM_STOP_SEC_CALLOUT_CODE
   #define   PWM_17_GTM_STOP_SEC_NOTIFICATION   

   #elif defined (ICU_17_GTMCCU6_START_SEC_CALLOUT_CODE)
   #undef      ICU_17_GTMCCU6_START_SEC_CALLOUT_CODE
   #define ICU_17_GTMCCU6_START_SEC_NOTIFICATION
   #elif defined (ICU_17_GTMCCU6_STOP_SEC_CALLOUT_CODE)
   #undef      ICU_17_GTMCCU6_STOP_SEC_CALLOUT_CODE
   #define   ICU_17_GTMCCU6_STOP_SEC_NOTIFICATION  
   
   #elif defined (WDG_17_SCU_START_SEC_CALLOUT_CODE)
   #undef      WDG_17_SCU_START_SEC_CALLOUT_CODE
   #define WDG_17_SCU_START_SEC_NOTIFICATION
   #elif defined (WDG_17_SCU_STOP_SEC_CALLOUT_CODE)
   #undef      WDG_17_SCU_STOP_SEC_CALLOUT_CODE
   #define   WDG_17_SCU_STOP_SEC_NOTIFICATION  
   
   #elif defined (STM_START_SEC_CALLOUT_CODE)
   #undef      STM_START_SEC_CALLOUT_CODE
   #define STM_START_SEC_NOTIFICATION
   #elif defined (STM_STOP_SEC_CALLOUT_CODE)
   #undef      STM_STOP_SEC_CALLOUT_CODE
   #define   STM_STOP_SEC_NOTIFICATION    
   
   #elif defined (GPT_START_SEC_CALLOUT_CODE)
   #undef      GPT_START_SEC_CALLOUT_CODE
   #define GPT_START_SEC_NOTIFICATION
   #elif defined (GPT_STOP_SEC_CALLOUT_CODE)
   #undef      GPT_STOP_SEC_CALLOUT_CODE
   #define   GPT_STOP_SEC_NOTIFICATION   


   #elif defined (LIN_17_ASCLIN_START_CHCFG)
   #undef      LIN_17_ASCLIN_START_CHCFG
   #define LIN_17_ASCLIN_START_LOADABLECFG
   #elif defined (LIN_17_ASCLIN_STOP_CHCFG)
   #undef      LIN_17_ASCLIN_STOP_CHCFG
   #define   LIN_17_ASCLIN_STOP_LOADABLECFG        



/* -------------------------------------------------------------------------- */
/* End of module Notification function section mapping                        */
/* -------------------------------------------------------------------------- */
/* The Source and Destination pointers passed to the SPI are 
   handled by the DMA in the asynchronous mode. It is necesarry 
   that these variables fullfill the following addressing constarints.
   1. In case of transfer width > 8, the data type is 16bits. Therefore
      it is necesarry to have the source and destination pointers
      word aligned. (On a Even Boundary). Use of #pragma align 2 will
      ensure word alignment.
   2. DMA implements a Circular Buffer with a maximum width of 32KB.
      So the Src/Des Ptrs (Starting Address + Length Of data) should not 
      span the 32KB Boundary if Sequential data are to be transferred.
      The start address of this section must be selected so that the 
      variables donot exceed the 32KB boundary.
      [(DMA_Address & 0x00007FFFU) + Length <= 0x00008000U] 
      
   So it has to be ensured that the section "SPI_START_SEC_VAR_DMA_ACCESS" 
   fullfills the above stated criteria*/
#elif defined (SPI_START_SEC_VAR_DMA_ACCESS)
   #undef      SPI_START_SEC_VAR_DMA_ACCESS
#ifdef _DIABDATA_C_TRICORE_
   #define SPI_START_SEC_VAR_FAST_32BIT
#else
/* In the Demo App supplied with AUTOSAR_MCAL2,
   the section:DEFAULT_START_SEC_VAR_FAST_32BIT is sufficient to satisfy the
   memory requirements for DMA. This may not be true for other applications and 
   the user should ensure this. */ 
   #define DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#endif   
#elif defined (SPI_STOP_SEC_VAR_DMA_ACCESS)
   #undef      SPI_STOP_SEC_VAR_DMA_ACCESS
#ifdef _DIABDATA_C_TRICORE_
   #define SPI_STOP_SEC_VAR_FAST_32BIT
#else
/* In the Demo App supplied with AUTOSAR_MCAL2,
   the section:DEFAULT_START_SEC_VAR_FAST_32BIT is sufficient to satisfy the
   memory requirements for DMA. This may not be true for other applications and 
   the user should ensure this. */ 
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED
#endif 


/* The Source and Destination pointers passed to the SPI are 
   handled by the DMA in the asynchronous mode. It is necesarry 
   that these variables fullfill the following addressing constarints.
   1. In case of transfer width > 8, the data type is 16bits. Therefore
      it is necesarry to have the source and destination pointers
      word aligned. (On a Even Boundary). Use of #pragma align 2 will
      ensure word alignment.
   2. DMA implements a Circular Buffer with a maximum width of 32KB.
      So the Src/Des Ptrs (Starting Address + Length Of data) should not 
      span the 32KB Boundary if Sequential data are to be transferred.
      The start address of this section must be selected so that the 
      variables donot exceed the 32KB boundary.
      [(DMA_Address & 0x00007FFFU) + Length <= 0x00008000U] 
      
   So it has to be ensured that the section "DMA_START_SEC_VAR_DMA_ACCESS" 
   fullfills the above stated criteria*/
#elif defined (DMA_START_SEC_VAR_DMA_ACCESS)
   #undef      DMA_START_SEC_VAR_DMA_ACCESS
/* In the Demo App supplied with AUTOSAR_MCAL2,
   the section:DEFAULT_START_SEC_VAR_FAST_16BIT is sufficient to satisfy the
   memory requirements for DMA. This may not be true for other applications and 
   the user should ensure this. */ 
   #define DEFAULT_START_SEC_VAR_FAST_16BIT
#elif defined (DMA_STOP_SEC_VAR_DMA_ACCESS)
   #undef      DMA_STOP_SEC_VAR_DMA_ACCESS
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (FLS_17_PMU_START_SPL_SEC_CODE_CMDWRITE)
   #undef      FLS_17_PMU_START_SPL_SEC_CODE_CMDWRITE
   #define   DEFAULT_START_SEC_CODE 
#elif defined (FLS_17_PMU_STOP_SPL_SEC_CODE_CMDWRITE)
   #undef      FLS_17_PMU_STOP_SPL_SEC_CODE_CMDWRITE
   #define DEFAULT_STOP_SEC_CODE

/*
 * To be used for global or static vars alignnment to 16 bit boundary
 *
 */
#elif defined (FLS_17_PMU_START_VAR_ALIGN_16_BIT)
   #undef      FLS_17_PMU_START_VAR_ALIGN_16_BIT
   #define DEFAULT_START_VAR_ALIGN_16_BIT
#elif defined (FLS_17_PMU_STOP_VAR_ALIGN_16_BIT)
   #undef      FLS_17_PMU_STOP_VAR_ALIGN_16_BIT
   #define DEFAULT_STOP_VAR_ALIGN_16_BIT

/*
 * To be used for global or static vars alignnment to 16 bit boundary
 *
 */
#elif defined (FEE_START_VAR_ALIGN_16_BIT)
   #undef      FEE_START_VAR_ALIGN_16_BIT
   #define DEFAULT_START_VAR_ALIGN_16_BIT
#elif defined (FEE_STOP_VAR_ALIGN_16_BIT)
   #undef      FEE_STOP_VAR_ALIGN_16_BIT
   #define DEFAULT_STOP_VAR_ALIGN_16_BIT

/*
 * To be used for global or static vars packing 
 *
 */
#elif defined (FEE_START_VAR_PACK_2)
   #undef      FEE_START_VAR_PACK_2
   #define DEFAULT_START_VAR_PACK_2
#elif defined (FEE_STOP_VAR_PACK_2)
   #undef      FEE_STOP_VAR_PACK_2
   #define DEFAULT_STOP_VAR_PACK_2



   #elif defined (BMD_HDR_START_SEC_CONST_UNSPECIFIED)
   #undef      BMD_HDR_START_SEC_CONST_UNSPECIFIED
   #define BMD_HDR_START_SEC_BMI_HEADER
   #elif defined (BMD_HDR_STOP_SEC_CONST_UNSPECIFIED)
   #undef      BMD_HDR_STOP_SEC_CONST_UNSPECIFIED
   #define   BMD_HDR_STOP_SEC_BMI_HEADER        
#else
//  #error "MemMap.h: No valid section define found"
#endif  /* START_WITH_IF */
/*******************************************************************************
**                      Default section mapping                               **
*******************************************************************************/
/* general start of #elif chain whith #if                                     */
#if defined (START_WITH_IF)

/*****************************************************************************
**                                 ROM CONFIG DATA                          **
******************************************************************************/
/* 
Memory Section of Post Build Configuration 
*/

#elif defined (DEFAULT_START_SEC_POSTBUILDCFG_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_POSTBUILDCFG_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU0.Private.CONFIGURATION_PB"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU0.Private.CONFIGURATION_PB" a 
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU0.Private.CONFIGURATION_PB" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_POSTBUILDCFG_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_POSTBUILDCFG_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_POSTBUILDCFG_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_POSTBUILDCFG_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU1.Private.CONFIGURATION_PB"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU1.Private.CONFIGURATION_PB" a 
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU1.Private.CONFIGURATION_PB" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_POSTBUILDCFG_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_POSTBUILDCFG_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_POSTBUILDCFG_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_POSTBUILDCFG_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU2.Private.CONFIGURATION_PB"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU2.Private.CONFIGURATION_PB" a 
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU2.Private.CONFIGURATION_PB" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_POSTBUILDCFG_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_POSTBUILDCFG_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_POSTBUILDCFG_SHARED)
   #undef      DEFAULT_START_SEC_POSTBUILDCFG_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="Shared.CONFIGURATION_PB"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.Shared.CONFIGURATION_PB" a 
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.Shared.CONFIGURATION_PB" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED)
   #undef      DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (ECUM_START_SEC_POSTBUILDCFG_CORE0_PRIVATE)
   #undef      ECUM_START_SEC_POSTBUILDCFG_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU0.Private.CONFIGURATION_ECUM_PB"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU0.Private.CONFIGURATION_ECUM_PB" a 
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU0.Private.CONFIGURATION_ECUM_PB" far-absolute R
   #endif
   #endif
#elif defined (ECUM_STOP_SEC_POSTBUILDCFG_CORE0_PRIVATE)
   #undef      ECUM_STOP_SEC_POSTBUILDCFG_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (ECUM_START_SEC_POSTBUILDCFG_CORE1_PRIVATE)
   #undef      ECUM_START_SEC_POSTBUILDCFG_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU1.Private.CONFIGURATION_ECUM_PB"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU1.Private.CONFIGURATION_ECUM_PB" a 
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU1.Private.CONFIGURATION_ECUM_PB" far-absolute R
   #endif
   #endif
#elif defined (ECUM_STOP_SEC_POSTBUILDCFG_CORE1_PRIVATE)
   #undef      ECUM_STOP_SEC_POSTBUILDCFG_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (ECUM_START_SEC_POSTBUILDCFG_CORE2_PRIVATE)
   #undef      ECUM_START_SEC_POSTBUILDCFG_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU2.Private.CONFIGURATION_ECUM_PB"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU2.Private.CONFIGURATION_ECUM_PB" a 
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU2.Private.CONFIGURATION_ECUM_PB" far-absolute R
   #endif
   #endif
#elif defined (ECUM_STOP_SEC_POSTBUILDCFG_CORE2_PRIVATE)
   #undef      ECUM_STOP_SEC_POSTBUILDCFG_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (ECUM_START_SEC_POSTBUILDCFG_SHARED)
   #undef      ECUM_START_SEC_POSTBUILDCFG_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="Shared.CONFIGURATION_ECUM_PB"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.Shared.CONFIGURATION_ECUM_PB" a 
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.Shared.CONFIGURATION_ECUM_PB" far-absolute R
   #endif
   #endif
#elif defined (ECUM_STOP_SEC_POSTBUILDCFG_SHARED)
   #undef      ECUM_STOP_SEC_POSTBUILDCFG_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU0)
   #undef      MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU0
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="CPU0_TRAP_HANDLER_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.CPU0_TRAP_HANDLER_CODE_ROM" ax 32
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.CPU0_TRAP_HANDLER_CODE_ROM" RX
   #pragma align_functions 32
   #endif
   #endif
#elif defined (MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU0)
   #undef      MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU0
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
    #pragma section CODE RX
    #pragma align_functions
   #endif
   #endif


#elif defined (MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU1)
   #undef      MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU1
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="CPU1_TRAP_HANDLER_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.CPU1_TRAP_HANDLER_CODE_ROM" ax 32
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   /* Memory section not defined since 32 byte alignment is not supported through #pragma */ 
   #endif
   #endif
#elif defined (MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU1)
   #undef      MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU1
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   /* Memory section not defined since 32 byte alignment is not supported through #pragma */ 
   #endif
   #endif
   

#elif defined (MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU2)
   #undef      MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU2
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="CPU2_TRAP_HANDLER_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.CPU2_TRAP_HANDLER_CODE_ROM" ax 32
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   /* Memory section not defined since 32 byte alignment is not supported through #pragma */ 
   #endif
   #endif
#elif defined (MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU2)
   #undef      MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU2
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   /* Memory section not defined since 32 byte alignment is not supported through #pragma */ 
   #endif
   #endif

   
#elif defined (DEFAULT_START_SEC_CODE_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_CODE_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="CPU0.Private.DEFAULT_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.CPU0.Private.DEFAULT_CODE_ROM" ax 
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.CPU0.Private.DEFAULT_CODE_ROM" RX
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CODE_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CODE_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CODE_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_CODE_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="CPU1.Private.DEFAULT_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.CPU1.Private.DEFAULT_CODE_ROM" ax 
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.CPU1.Private.DEFAULT_CODE_ROM" RX
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CODE_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CODE_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CODE_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_CODE_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="CPU2.Private.DEFAULT_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.CPU2.Private.DEFAULT_CODE_ROM" ax 
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.CPU2.Private.DEFAULT_CODE_ROM" RX
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CODE_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CODE_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CODE_SHARED)
   #undef      DEFAULT_START_SEC_CODE_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="Shared.DEFAULT_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.Shared.DEFAULT_CODE_ROM" ax 
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.Shared.DEFAULT_CODE_ROM" RX
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CODE_SHARED)
   #undef      DEFAULT_STOP_SEC_CODE_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif

#elif defined (DEFAULT_START_SEC_SAFETY_CODE_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_SAFETY_CODE_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="CPU0.Private.DEFAULT_SAFETY_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.CPU0.Private.DEFAULT_SAFETY_CODE_ROM" ax 
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.CPU0.Private.DEFAULT_SAFETY_CODE_ROM" RX
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_SAFETY_CODE_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_SAFETY_CODE_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_SAFETY_CODE_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_SAFETY_CODE_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="CPU1.Private.DEFAULT_SAFETY_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.CPU1.Private.DEFAULT_SAFETY_CODE_ROM" ax 
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.CPU1.Private.DEFAULT_SAFETY_CODE_ROM" RX
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_SAFETY_CODE_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_SAFETY_CODE_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_SAFETY_CODE_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_SAFETY_CODE_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="CPU2.Private.DEFAULT_SAFETY_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.CPU2.Private.DEFAULT_SAFETY_CODE_ROM" ax 
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.CPU2.Private.DEFAULT_SAFETY_CODE_ROM" RX
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_SAFETY_CODE_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_SAFETY_CODE_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_SAFETY_CODE_SHARED)
   #undef      DEFAULT_START_SEC_SAFETY_CODE_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="Shared.DEFAULT_SAFETY_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.Shared.DEFAULT_SAFETY_CODE_ROM" ax 
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.Shared.DEFAULT_SAFETY_CODE_ROM" RX
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_SAFETY_CODE_SHARED)
   #undef      DEFAULT_STOP_SEC_SAFETY_CODE_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_QM_CODE_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_QM_CODE_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="CPU0.Private.DEFAULT_QM_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.CPU0.Private.DEFAULT_QM_CODE_ROM" ax 
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.CPU0.Private.DEFAULT_QM_CODE_ROM" RX
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_QM_CODE_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_QM_CODE_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_QM_CODE_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_QM_CODE_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="CPU1.Private.DEFAULT_QM_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.CPU1.Private.DEFAULT_QM_CODE_ROM" ax 
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.CPU1.Private.DEFAULT_QM_CODE_ROM" RX
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_QM_CODE_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_QM_CODE_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_QM_CODE_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_QM_CODE_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="CPU2.Private.DEFAULT_QM_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.CPU2.Private.DEFAULT_QM_CODE_ROM" ax 
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.CPU2.Private.DEFAULT_QM_CODE_ROM" RX
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_QM_CODE_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_QM_CODE_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_QM_CODE_SHARED)
   #undef      DEFAULT_START_SEC_QM_CODE_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="Shared.DEFAULT_QM_CODE_ROM"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.Shared.DEFAULT_QM_CODE_ROM" ax 
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.Shared.DEFAULT_QM_CODE_ROM" RX
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_QM_CODE_SHARED)
   #undef      DEFAULT_STOP_SEC_QM_CODE_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="CPU0.Private.DEFAULT_RAM_NOINIT_8BIT"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_NOINIT_8BIT" ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_8BIT" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="CPU1.Private.DEFAULT_RAM_NOINIT_8BIT"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.CPU1.Private.DEFAULT_RAM_NOINIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_NOINIT_8BIT" ".bss.CPU1.Private.DEFAULT_RAM_NOINIT_8BIT" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="CPU2.Private.DEFAULT_RAM_NOINIT_8BIT"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.CPU2.Private.DEFAULT_RAM_NOINIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_NOINIT_8BIT" ".bss.CPU2.Private.DEFAULT_RAM_NOINIT_8BIT" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="Shared.DEFAULT_RAM_NOINIT_8BIT"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.Shared.DEFAULT_RAM_NOINIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_NOINIT_8BIT" ".bss.Shared.DEFAULT_RAM_NOINIT_8BIT" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="CPU0.Private.DEFAULT_RAM_NOINIT_16BIT"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_NOINIT_16BIT" ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_16BIT" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="CPU1.Private.DEFAULT_RAM_NOINIT_16BIT"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.CPU1.Private.DEFAULT_RAM_NOINIT_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_NOINIT_16BIT" ".bss.CPU1.Private.DEFAULT_RAM_NOINIT_16BIT" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="CPU2.Private.DEFAULT_RAM_NOINIT_16BIT"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.CPU2.Private.DEFAULT_RAM_NOINIT_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_NOINIT_16BIT" ".bss.CPU2.Private.DEFAULT_RAM_NOINIT_16BIT" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="Shared.DEFAULT_RAM_NOINIT_16BIT"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.Shared.DEFAULT_RAM_NOINIT_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_NOINIT_16BIT" ".bss.Shared.DEFAULT_RAM_NOINIT_16BIT" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="CPU0.Private.DEFAULT_RAM_NOINIT_32BIT"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_NOINIT_32BIT" ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_32BIT" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="CPU1.Private.DEFAULT_RAM_NOINIT_32BIT"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.CPU1.Private.DEFAULT_RAM_NOINIT_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_NOINIT_32BIT" ".bss.CPU1.Private.DEFAULT_RAM_NOINIT_32BIT" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="CPU2.Private.DEFAULT_RAM_NOINIT_32BIT"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.CPU2.Private.DEFAULT_RAM_NOINIT_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_NOINIT_32BIT" ".bss.CPU2.Private.DEFAULT_RAM_NOINIT_32BIT" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="Shared.DEFAULT_RAM_NOINIT_32BIT"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.Shared.DEFAULT_RAM_NOINIT_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_NOINIT_32BIT" ".bss.Shared.DEFAULT_RAM_NOINIT_32BIT" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="CPU0.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="CPU1.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.CPU1.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" ".bss.CPU1.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="CPU2.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.CPU2.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" ".bss.CPU2.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farnoclear="Shared.DEFAULT_RAM_NOINIT_UNSPECIFIED"
   /* noclear section is not used due to --eabi-compliant compiler option*/
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.Shared.DEFAULT_RAM_NOINIT_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_NOINIT_UNSPECIFIED" ".bss.Shared.DEFAULT_RAM_NOINIT_UNSPECIFIED" RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   /* clear section is not used due to --eabi-compliant compiler option*/
   #pragma section farnoclear restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_8BIT" ".bss.CPU0.Private.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_8BIT" ".bss.CPU1.Private.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_8BIT" ".bss.CPU2.Private.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_8BIT" ".bss.Shared.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_VAR_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL0_VAR_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_ASIL0_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_ASIL0_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_ASIL0_8BIT" ".bss.CPU0.Private.DEFAULT_RAM_ASIL0_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_VAR_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL0_VAR_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_VAR_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL0_VAR_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_ASIL0_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_ASIL0_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_ASIL0_8BIT" ".bss.CPU1.Private.DEFAULT_RAM_ASIL0_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_VAR_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL0_VAR_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_VAR_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL0_VAR_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_ASIL0_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_ASIL0_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_ASIL0_8BIT" ".bss.CPU2.Private.DEFAULT_RAM_ASIL0_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_VAR_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL0_VAR_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_VAR_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_ASIL0_VAR_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_ASIL0_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_ASIL0_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_ASIL0_8BIT" ".bss.Shared.DEFAULT_RAM_ASIL0_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_VAR_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_ASIL0_VAR_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_VAR_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_ASIL1_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_ASIL1_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_ASIL1_8BIT" ".bss.CPU0.Private.DEFAULT_RAM_ASIL1_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_VAR_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_ASIL1_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_ASIL1_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_ASIL1_8BIT" ".bss.CPU1.Private.DEFAULT_RAM_ASIL1_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_VAR_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_ASIL1_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_ASIL1_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_ASIL1_8BIT" ".bss.CPU2.Private.DEFAULT_RAM_ASIL1_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_VAR_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_ASIL1_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_ASIL1_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_ASIL1_8BIT" ".bss.Shared.DEFAULT_RAM_ASIL1_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif



#elif defined (DEFAULT_START_SEC_BACKUP_VAR_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_BACKUP_VAR_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_BACKUP_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_BACKUP_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_BACKUP_8BIT" ".bss.CPU0.Private.DEFAULT_RAM_BACKUP_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_BACKUP_VAR_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_BACKUP_VAR_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_BACKUP_VAR_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_BACKUP_VAR_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_BACKUP_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_BACKUP_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_BACKUP_8BIT" ".bss.CPU1.Private.DEFAULT_RAM_BACKUP_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_BACKUP_VAR_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_BACKUP_VAR_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_BACKUP_VAR_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_BACKUP_VAR_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_BACKUP_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_BACKUP_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_BACKUP_8BIT" ".bss.CPU2.Private.DEFAULT_RAM_BACKUP_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_BACKUP_VAR_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_BACKUP_VAR_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_BACKUP_VAR_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_BACKUP_VAR_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_BACKUP_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_BACKUP_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_BACKUP_8BIT" ".bss.Shared.DEFAULT_RAM_BACKUP_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_BACKUP_VAR_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_BACKUP_VAR_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_16BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_16BIT" ".bss.CPU0.Private.DEFAULT_RAM_16BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_16BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_16BIT" ".bss.CPU1.Private.DEFAULT_RAM_16BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_16BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_16BIT" ".bss.CPU2.Private.DEFAULT_RAM_16BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_16BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_16BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_16BIT" ".bss.Shared.DEFAULT_RAM_16BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_16BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_32BIT" ".bss.CPU0.Private.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_32BIT" ".bss.CPU1.Private.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_32BIT" ".bss.CPU2.Private.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_32BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_32BIT" ".bss.Shared.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_32BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_SPL_VAR_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_SPL_VAR_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_32BIT" ".bss.CPU0.Private.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_SPL_VAR_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_SPL_VAR_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_SPL_VAR_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_SPL_VAR_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_32BIT" ".bss.CPU1.Private.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_SPL_VAR_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_SPL_VAR_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_SPL_VAR_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_SPL_VAR_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_32BIT" ".bss.CPU2.Private.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_SPL_VAR_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_SPL_VAR_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_SPL_VAR_32BIT_SHARED)
   #undef      DEFAULT_START_SEC_SPL_VAR_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_32BIT" ".bss.Shared.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_SPL_VAR_32BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_SPL_VAR_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_INIT_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_INIT_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="CPU0.Private.DEFAULT_RAM_INIT_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_INIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_INIT_8BIT" ".bss.CPU0.Private.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_INIT_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_INIT_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_INIT_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_INIT_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="CPU1.Private.DEFAULT_RAM_INIT_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_INIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_INIT_8BIT" ".bss.CPU1.Private.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_INIT_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_INIT_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_INIT_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_INIT_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="CPU2.Private.DEFAULT_RAM_INIT_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_INIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_INIT_8BIT" ".bss.CPU2.Private.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_INIT_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_INIT_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_INIT_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_INIT_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="Shared.DEFAULT_RAM_INIT_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_INIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_INIT_8BIT" ".bss.Shared.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_INIT_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_INIT_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_BACKUP_VAR_INIT_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_BACKUP_VAR_INIT_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="CPU0.Private.DEFAULT_RAM_BACKUP_INIT_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_BACKUP_INIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_BACKUP_INIT_8BIT" ".bss.CPU0.Private.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_BACKUP_VAR_INIT_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_BACKUP_VAR_INIT_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_BACKUP_VAR_INIT_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_BACKUP_VAR_INIT_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="CPU1.Private.DEFAULT_RAM_BACKUP_INIT_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_BACKUP_INIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_BACKUP_INIT_8BIT" ".bss.CPU1.Private.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_BACKUP_VAR_INIT_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_BACKUP_VAR_INIT_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_BACKUP_VAR_INIT_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_BACKUP_VAR_INIT_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="CPU2.Private.DEFAULT_RAM_BACKUP_INIT_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_BACKUP_INIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_BACKUP_INIT_8BIT" ".bss.CPU2.Private.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_BACKUP_VAR_INIT_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_BACKUP_VAR_INIT_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_BACKUP_VAR_INIT_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_BACKUP_VAR_INIT_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="Shared.DEFAULT_RAM_BACKUP_INIT_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_BACKUP_INIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_BACKUP_INIT_8BIT" ".bss.Shared.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_BACKUP_VAR_INIT_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_BACKUP_VAR_INIT_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_INIT_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_INIT_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="CPU0.Private.DEFAULT_RAM_INIT_16BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_INIT_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_INIT_16BIT" ".bss.CPU0.Private.DEFAULT_RAM_16BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_INIT_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_INIT_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_INIT_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_INIT_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="CPU1.Private.DEFAULT_RAM_INIT_16BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_INIT_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_INIT_16BIT" ".bss.CPU1.Private.DEFAULT_RAM_16BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_INIT_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_INIT_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_INIT_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_INIT_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="CPU2.Private.DEFAULT_RAM_INIT_16BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_INIT_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_INIT_16BIT" ".bss.CPU2.Private.DEFAULT_RAM_16BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_INIT_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_INIT_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_INIT_16BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_INIT_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="Shared.DEFAULT_RAM_INIT_16BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_INIT_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_INIT_16BIT" ".bss.Shared.DEFAULT_RAM_16BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_INIT_16BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_INIT_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_INIT_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_INIT_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="CPU0.Private.DEFAULT_RAM_INIT_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_INIT_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_INIT_32BIT" ".bss.CPU0.Private.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_INIT_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_INIT_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_INIT_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_INIT_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="CPU1.Private.DEFAULT_RAM_INIT_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_INIT_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_INIT_32BIT" ".bss.CPU1.Private.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_INIT_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_INIT_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_INIT_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_INIT_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="CPU2.Private.DEFAULT_RAM_INIT_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_INIT_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_INIT_32BIT" ".bss.CPU2.Private.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_INIT_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_INIT_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_INIT_32BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_INIT_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="Shared.DEFAULT_RAM_INIT_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_INIT_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_INIT_32BIT" ".bss.Shared.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_INIT_32BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_INIT_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_VAR_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL0_VAR_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_ASIL0_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_ASIL0_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_ASIL0_32BIT" ".bss.CPU0.Private.DEFAULT_RAM_ASIL0_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_VAR_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL0_VAR_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_VAR_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL0_VAR_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_ASIL0_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_ASIL0_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_ASIL0_32BIT" ".bss.CPU1.Private.DEFAULT_RAM_ASIL0_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_VAR_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL0_VAR_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_VAR_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL0_VAR_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_ASIL0_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_ASIL0_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_ASIL0_32BIT" ".bss.CPU2.Private.DEFAULT_RAM_ASIL0_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_VAR_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL0_VAR_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_VAR_32BIT_SHARED)
   #undef      DEFAULT_START_SEC_ASIL0_VAR_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_ASIL0_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_ASIL0_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_ASIL0_32BIT" ".bss.Shared.DEFAULT_RAM_ASIL0_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_VAR_32BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_ASIL0_VAR_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif



#elif defined (DEFAULT_START_SEC_ASIL1_VAR_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_ASIL1_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_ASIL1_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_ASIL1_32BIT" ".bss.CPU0.Private.DEFAULT_RAM_ASIL1_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_VAR_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_ASIL1_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_ASIL1_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_ASIL1_32BIT" ".bss.CPU1.Private.DEFAULT_RAM_ASIL1_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_VAR_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_ASIL1_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_ASIL1_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_ASIL1_32BIT" ".bss.CPU2.Private.DEFAULT_RAM_ASIL1_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_VAR_32BIT_SHARED)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_ASIL1_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_ASIL1_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_ASIL1_32BIT" ".bss.Shared.DEFAULT_RAM_ASIL1_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_32BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif



#elif defined (DEFAULT_START_SEC_ASIL1_VAR_FAST_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_FAST_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU0.Private.DEFAULT_RAM_ASIL1_32BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU0.Private.DEFAULT_RAM_ASIL1_32BIT" awBz 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU0.Private.DEFAULT_RAM_ASIL1_32BIT" ".zbss.CPU0.Private.DEFAULT_RAM_ASIL1_32BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_FAST_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_FAST_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_VAR_FAST_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_FAST_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU1.Private.DEFAULT_RAM_ASIL1_32BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU1.Private.DEFAULT_RAM_ASIL1_32BIT" awBz 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU1.Private.DEFAULT_RAM_ASIL1_32BIT" ".zbss.CPU1.Private.DEFAULT_RAM_ASIL1_32BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_FAST_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_FAST_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory near
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_VAR_FAST_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_FAST_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU2.Private.DEFAULT_RAM_ASIL1_32BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU2.Private.DEFAULT_RAM_ASIL1_32BIT" awBz 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU2.Private.DEFAULT_RAM_ASIL1_32BIT" ".zbss.CPU2.Private.DEFAULT_RAM_ASIL1_32BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_FAST_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_FAST_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory near
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_VAR_FAST_32BIT_SHARED)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_FAST_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="Shared.DEFAULT_RAM_ASIL1_32BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.Shared.DEFAULT_RAM_ASIL1_32BIT" awBz 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.Shared.DEFAULT_RAM_ASIL1_32BIT" ".zbss.Shared.DEFAULT_RAM_ASIL1_32BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_FAST_32BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_FAST_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory near
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif



#elif defined (DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_UNSPECIFIED" ".bss.CPU0.Private.DEFAULT_RAM_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_UNSPECIFIED" ".bss.CPU1.Private.DEFAULT_RAM_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_UNSPECIFIED" ".bss.CPU2.Private.DEFAULT_RAM_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED)
   #undef      DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_UNSPECIFIED" ".bss.Shared.DEFAULT_RAM_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_VAR_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL0_VAR_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_ASIL0_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_ASIL0_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_ASIL0_UNSPECIFIED" ".bss.CPU0.Private.DEFAULT_RAM_ASIL0_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_VAR_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL0_VAR_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_VAR_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL0_VAR_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_ASIL0_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_ASIL0_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_ASIL0_UNSPECIFIED" ".bss.CPU1.Private.DEFAULT_RAM_ASIL0_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_VAR_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL0_VAR_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_VAR_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL0_VAR_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_ASIL0_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_ASIL0_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_ASIL0_UNSPECIFIED" ".bss.CPU2.Private.DEFAULT_RAM_ASIL0_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_VAR_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL0_VAR_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_VAR_UNSPECIFIED_SHARED)
   #undef      DEFAULT_START_SEC_ASIL0_VAR_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_ASIL0_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_ASIL0_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_ASIL0_UNSPECIFIED" ".bss.Shared.DEFAULT_RAM_ASIL0_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_VAR_UNSPECIFIED_SHARED)
   #undef      DEFAULT_STOP_SEC_ASIL0_VAR_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_VAR_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_ASIL1_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_ASIL1_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_ASIL1_UNSPECIFIED" ".bss.CPU0.Private.DEFAULT_RAM_ASIL1_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_VAR_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_ASIL1_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_ASIL1_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_ASIL1_UNSPECIFIED" ".bss.CPU1.Private.DEFAULT_RAM_ASIL1_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_VAR_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_ASIL1_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_ASIL1_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_ASIL1_UNSPECIFIED" ".bss.CPU2.Private.DEFAULT_RAM_ASIL1_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_VAR_UNSPECIFIED_SHARED)
   #undef      DEFAULT_START_SEC_ASIL1_VAR_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_ASIL1_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_ASIL1_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_ASIL1_UNSPECIFIED" ".bss.Shared.DEFAULT_RAM_ASIL1_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_VAR_UNSPECIFIED_SHARED)
   #undef      DEFAULT_STOP_SEC_ASIL1_VAR_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU0.Private.DEFAULT_RAM_FAST_8BIT"
   #pragma for_uninitialized_data_use_memory near
      #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU0.Private.DEFAULT_RAM_FAST_8BIT" awBz 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU0.Private.DEFAULT_RAM_FAST_8BIT" ".zbss.CPU0.Private.DEFAULT_RAM_FAST_8BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU1.Private.DEFAULT_RAM_FAST_8BIT"
   #pragma for_uninitialized_data_use_memory near
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU1.Private.DEFAULT_RAM_FAST_8BIT" awBz 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU1.Private.DEFAULT_RAM_FAST_8BIT" ".zbss.CPU1.Private.DEFAULT_RAM_FAST_8BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU2.Private.DEFAULT_RAM_FAST_8BIT"
   #pragma for_uninitialized_data_use_memory near
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU2.Private.DEFAULT_RAM_FAST_8BIT" awBz 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU2.Private.DEFAULT_RAM_FAST_8BIT" ".zbss.CPU2.Private.DEFAULT_RAM_FAST_8BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="Shared.DEFAULT_RAM_FAST_8BIT"
   #pragma for_uninitialized_data_use_memory near
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.Shared.DEFAULT_RAM_FAST_8BIT" awBz 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.Shared.DEFAULT_RAM_FAST_8BIT" ".zbss.Shared.DEFAULT_RAM_FAST_8BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU0.Private.DEFAULT_RAM_FAST_16BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU0.Private.DEFAULT_RAM_FAST_16BIT" awBz 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU0.Private.DEFAULT_RAM_FAST_16BIT" ".zbss.CPU0.Private.DEFAULT_RAM_FAST_16BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU1.Private.DEFAULT_RAM_FAST_16BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU1.Private.DEFAULT_RAM_FAST_16BIT" awBz 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU1.Private.DEFAULT_RAM_FAST_16BIT" ".zbss.CPU1.Private.DEFAULT_RAM_FAST_16BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU2.Private.DEFAULT_RAM_FAST_16BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU2.Private.DEFAULT_RAM_FAST_16BIT" awBz 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU2.Private.DEFAULT_RAM_FAST_16BIT" ".zbss.CPU2.Private.DEFAULT_RAM_FAST_16BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="Shared.DEFAULT_RAM_FAST_16BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.Shared.DEFAULT_RAM_FAST_16BIT" awBz 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.Shared.DEFAULT_RAM_FAST_16BIT" ".zbss.Shared.DEFAULT_RAM_FAST_16BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU0.Private.DEFAULT_RAM_FAST_32BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU0.Private.DEFAULT_RAM_FAST_32BIT" awBz 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU0.Private.DEFAULT_RAM_FAST_32BIT" ".zbss.CPU0.Private.DEFAULT_RAM_FAST_32BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU1.Private.DEFAULT_RAM_FAST_32BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU1.Private.DEFAULT_RAM_FAST_32BIT" awBz 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU1.Private.DEFAULT_RAM_FAST_32BIT" ".zbss.CPU1.Private.DEFAULT_RAM_FAST_32BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU2.Private.DEFAULT_RAM_FAST_32BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU2.Private.DEFAULT_RAM_FAST_32BIT" awBz 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU2.Private.DEFAULT_RAM_FAST_32BIT" ".zbss.CPU2.Private.DEFAULT_RAM_FAST_32BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="Shared.DEFAULT_RAM_FAST_32BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.Shared.DEFAULT_RAM_FAST_32BIT" awBz 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.Shared.DEFAULT_RAM_FAST_32BIT" ".zbss.Shared.DEFAULT_RAM_FAST_32BIT" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif

#elif defined (MCAL_TCLIB_START_SEC_VAR_NONZERO_INIT_32BIT)
   #undef      MCAL_TCLIB_START_SEC_VAR_NONZERO_INIT_32BIT
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="DEFAULT_RAM_32BIT_NONZERO_INIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.DEFAULT_RAM_32BIT_NONZERO_INIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.DEFAULT_RAM_NONZERO_32BIT" ".bss.DEFAULT_RAM_NONZERO_32BIT" RW
   #endif
   #endif
#elif defined (MCAL_TCLIB_STOP_SEC_VAR_NONZERO_INIT_32BIT)
   #undef      MCAL_TCLIB_STOP_SEC_VAR_NONZERO_INIT_32BIT
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif

#elif defined (DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU0.Private.DEFAULT_RAM_FAST_UNSPECIFIED"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU0.Private.DEFAULT_RAM_FAST_UNSPECIFIED" awBz 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU0.Private.DEFAULT_RAM_FAST_UNSPECIFIED" ".zbss.CPU0.Private.DEFAULT_RAM_FAST_UNSPECIFIED" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU1.Private.DEFAULT_RAM_FAST_UNSPECIFIED"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU1.Private.DEFAULT_RAM_FAST_UNSPECIFIED" awBz 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU1.Private.DEFAULT_RAM_FAST_UNSPECIFIED" ".zbss.CPU1.Private.DEFAULT_RAM_FAST_UNSPECIFIED" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="CPU2.Private.DEFAULT_RAM_FAST_UNSPECIFIED"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.CPU2.Private.DEFAULT_RAM_FAST_UNSPECIFIED" awBz 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.CPU2.Private.DEFAULT_RAM_FAST_UNSPECIFIED" ".zbss.CPU2.Private.DEFAULT_RAM_FAST_UNSPECIFIED" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED)
   #undef      DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="Shared.DEFAULT_RAM_FAST_UNSPECIFIED"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".zbss.Shared.DEFAULT_RAM_FAST_UNSPECIFIED" awBz 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".zdata.Shared.DEFAULT_RAM_FAST_UNSPECIFIED" ".zbss.Shared.DEFAULT_RAM_FAST_UNSPECIFIED" near-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" ".bss.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" ".bss.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" ".bss.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_POWER_ON_INIT_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_POWER_ON_INIT_8BIT" aw 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_POWER_ON_INIT_8BIT" ".bss.Shared.DEFAULT_RAM_POWER_ON_INIT_8BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" ".bss.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" ".bss.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" ".bss.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_POWER_ON_INIT_16BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_POWER_ON_INIT_16BIT" aw 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_POWER_ON_INIT_16BIT" ".bss.Shared.DEFAULT_RAM_POWER_ON_INIT_16BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" ".bss.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" ".bss.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" ".bss.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_POWER_ON_INIT_32BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_POWER_ON_INIT_32BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_POWER_ON_INIT_32BIT" ".bss.Shared.DEFAULT_RAM_POWER_ON_INIT_32BIT" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" ".bss.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" ".bss.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" ".bss.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="Shared.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.Shared.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.Shared.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" ".bss.Shared.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" far-absolute RW
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU0.Private.DEFAULT_CONST_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU0.Private.DEFAULT_CONST_8BIT" a 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU0.Private.DEFAULT_CONST_8BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU1.Private.DEFAULT_CONST_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU1.Private.DEFAULT_CONST_8BIT" a 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU1.Private.DEFAULT_CONST_8BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU2.Private.DEFAULT_CONST_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU2.Private.DEFAULT_CONST_8BIT" a 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU2.Private.DEFAULT_CONST_8BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_CONST_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="Shared.DEFAULT_CONST_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.Shared.DEFAULT_CONST_8BIT" a 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.Shared.DEFAULT_CONST_8BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_CONST_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_CONST_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL0_CONST_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU0.Private.DEFAULT_ASIL0_CONST_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU0.Private.DEFAULT_ASIL0_CONST_8BIT" a 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU0.Private.DEFAULT_ASIL0_CONST_8BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_CONST_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL0_CONST_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_CONST_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL0_CONST_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU1.Private.DEFAULT_ASIL0_CONST_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU1.Private.DEFAULT_ASIL0_CONST_8BIT" a 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU1.Private.DEFAULT_ASIL0_CONST_8BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_CONST_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL0_CONST_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_CONST_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL0_CONST_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU2.Private.DEFAULT_ASIL0_CONST_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU2.Private.DEFAULT_ASIL0_CONST_8BIT" a 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU2.Private.DEFAULT_ASIL0_CONST_8BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_CONST_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL0_CONST_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL0_CONST_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_ASIL0_CONST_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="Shared.DEFAULT_ASIL0_CONST_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.Shared.DEFAULT_ASIL0_CONST_8BIT" a 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.Shared.DEFAULT_ASIL0_CONST_8BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL0_CONST_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_ASIL0_CONST_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_CONST_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_CONST_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU0.Private.DEFAULT_ASIL1_CONST_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU0.Private.DEFAULT_ASIL1_CONST_8BIT" a 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU0.Private.DEFAULT_ASIL1_CONST_8BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_CONST_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_CONST_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_CONST_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_CONST_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU1.Private.DEFAULT_ASIL1_CONST_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU1.Private.DEFAULT_ASIL1_CONST_8BIT" a 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU1.Private.DEFAULT_ASIL1_CONST_8BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_CONST_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_CONST_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_CONST_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_ASIL1_CONST_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU2.Private.DEFAULT_ASIL1_CONST_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU2.Private.DEFAULT_ASIL1_CONST_8BIT" a 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU2.Private.DEFAULT_ASIL1_CONST_8BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_CONST_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_ASIL1_CONST_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_ASIL1_CONST_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_ASIL1_CONST_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="Shared.DEFAULT_ASIL1_CONST_8BIT"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.Shared.DEFAULT_ASIL1_CONST_8BIT" a 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.Shared.DEFAULT_ASIL1_CONST_8BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_ASIL1_CONST_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_ASIL1_CONST_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU0.Private.DEFAULT_CONST_16BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU0.Private.DEFAULT_CONST_16BIT" a 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU0.Private.DEFAULT_CONST_16BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU1.Private.DEFAULT_CONST_16BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU1.Private.DEFAULT_CONST_16BIT" a 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU1.Private.DEFAULT_CONST_16BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU2.Private.DEFAULT_CONST_16BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU2.Private.DEFAULT_CONST_16BIT" a 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU2.Private.DEFAULT_CONST_16BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_16BIT_SHARED)
   #undef      DEFAULT_START_SEC_CONST_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="Shared.DEFAULT_CONST_16BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.Shared.DEFAULT_CONST_16BIT" a 2
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.Shared.DEFAULT_CONST_16BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_16BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_CONST_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU0.Private.DEFAULT_CONST_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU0.Private.DEFAULT_CONST_32BIT" a 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU0.Private.DEFAULT_CONST_32BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU1.Private.DEFAULT_CONST_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU1.Private.DEFAULT_CONST_32BIT" a 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU1.Private.DEFAULT_CONST_32BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU2.Private.DEFAULT_CONST_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU2.Private.DEFAULT_CONST_32BIT" a 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU2.Private.DEFAULT_CONST_32BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_32BIT_SHARED)
   #undef      DEFAULT_START_SEC_CONST_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="Shared.DEFAULT_CONST_32BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.Shared.DEFAULT_CONST_32BIT" a 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.Shared.DEFAULT_CONST_32BIT" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_32BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_CONST_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU0.Private.DEFAULT_CONST_FAR_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU0.Private.DEFAULT_CONST_FAR_UNSPECIFIED" a 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU0.Private.DEFAULT_CONST_FAR_UNSPECIFIED" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU1.Private.DEFAULT_CONST_FAR_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU1.Private.DEFAULT_CONST_FAR_UNSPECIFIED" a 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU1.Private.DEFAULT_CONST_FAR_UNSPECIFIED" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="CPU2.Private.DEFAULT_CONST_FAR_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.CPU2.Private.DEFAULT_CONST_FAR_UNSPECIFIED" a 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.CPU2.Private.DEFAULT_CONST_FAR_UNSPECIFIED" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif


#elif defined (DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED)
   #undef      DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="Shared.DEFAULT_CONST_FAR_UNSPECIFIED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.Shared.DEFAULT_CONST_FAR_UNSPECIFIED" a 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.Shared.DEFAULT_CONST_FAR_UNSPECIFIED" far-absolute R
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED)
   #undef      DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif

/*****************************************************************************
**                                 EXTRAS                                   **
******************************************************************************/

#elif defined (LIN_17_ASCLIN_START_LOADABLECFG)
   #undef   LIN_17_ASCLIN_START_LOADABLECFG
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)   
   #pragma section farrom="Shared.LIN_LOADABLE_CHANCFG"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.Shared.LIN_LOADABLE_CHANCFG" a
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".rodata.Shared.LIN_LOADABLE_CHANCFG" far-absolute R
   #endif
   #endif
#elif defined (LIN_17_ASCLIN_STOP_LOADABLECFG)
   #undef   LIN_17_ASCLIN_STOP_LOADABLECFG
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif

#elif defined (DEFAULT_START_SEC_IVT_CODE)
   #undef      DEFAULT_START_SEC_IVT_CODE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code "inttab"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".inttab" ax 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".inttab" X
   #endif
   #endif
#elif defined (DEFAULT_STOP_SEC_IVT_CODE)
   #undef      DEFAULT_STOP_SEC_IVT_CODE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE X
   #endif
   #endif

#elif defined (PWM_17_GTM_START_SEC_NOTIFICATION)
   #undef      PWM_17_GTM_START_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code "PWM_NOTIFICATION"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.PWM_NOTIFICATION" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.PWM_NOTIFICATION" RX
   #endif
   #endif
#elif defined (PWM_17_GTM_STOP_SEC_NOTIFICATION)
   #undef      PWM_17_GTM_STOP_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif

#elif defined (ICU_17_GTMCCU6_START_SEC_NOTIFICATION)
   #undef      ICU_17_GTMCCU6_START_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code "ICU_NOTIFICATION"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.ICU_NOTIFICATION" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.ICU_NOTIFICATION" RX
   #endif
   #endif
#elif defined (ICU_17_GTMCCU6_STOP_SEC_NOTIFICATION)
   #undef      ICU_17_GTMCCU6_STOP_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif
   
#elif defined (WDG_17_SCU_START_SEC_NOTIFICATION)
   #undef      WDG_17_SCU_START_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code "WDG_NOTIFICATION"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.WDG_NOTIFICATION" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.WDG_NOTIFICATION" RX
   #endif
   #endif
#elif defined (WDG_17_SCU_STOP_SEC_NOTIFICATION)
   #undef      WDG_17_SCU_STOP_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif
   
#elif defined (STM_START_SEC_NOTIFICATION)
   #undef      STM_START_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code "STM_NOTIFICATION"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.STM_NOTIFICATION" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.STM_NOTIFICATION" RX
   #endif
   #endif
#elif defined (STM_STOP_SEC_NOTIFICATION)
   #undef      STM_STOP_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif
   
#elif defined (GPT_START_SEC_NOTIFICATION)
   #undef      GPT_START_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code "GPT_NOTIFICATION"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.GPT_NOTIFICATION" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".text.GPT_NOTIFICATION" RX
   #endif
   #endif
#elif defined (GPT_STOP_SEC_NOTIFICATION)
   #undef      GPT_STOP_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif

/* ---The following sections attempt to locate FLS Write and Erase command-----
   ---Cycles in an order. It is essential to enforce the correct sequence------
   ---so that the FLS driver can perform as requird.-------------------------*/
#elif defined (FLS_17_PMU_START_SEC_SPL_CODE_WRITECMD_BEGIN_API)
   #undef     FLS_17_PMU_START_SEC_SPL_CODE_WRITECMD_BEGIN_API
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code "FLS_AC_WRITE_SOURCE"
   #pragma optimize R
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.FLS_AC_WRITE_SOURCE" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".FLS_AC_WRITE_SOURCE" far-absolute RX
   #endif
   #endif
   
#elif defined (FLS_17_PMU_STOP_SEC_SPL_CODE_WRITECMD_BEGIN_API)
   #undef     FLS_17_PMU_STOP_SEC_SPL_CODE_WRITECMD_BEGIN_API
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #pragma endoptimize
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif   

#elif defined (FLS_17_PMU_START_SEC_SPL_CODE_ERASECMD_BEGIN_API)
   #undef     FLS_17_PMU_START_SEC_SPL_CODE_ERASECMD_BEGIN_API
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code "FLS_AC_ERASE_SOURCE"
   #pragma optimize R
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.FLS_AC_ERASE_SOURCE" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".FLS_AC_ERASE_SOURCE" far-absolute RX
   #endif
   #endif
   
#elif defined (FLS_17_PMU_STOP_SEC_SPL_CODE_ERASECMD_BEGIN_API)
   #undef     FLS_17_PMU_STOP_SEC_SPL_CODE_ERASECMD_BEGIN_API
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #pragma endoptimize
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif   

#elif defined (FEE_START_JOBENDNOTIF)
   #undef   FEE_START_JOBENDNOTIF
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code "FEE_JOBENDNOTIF_CODE"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.FEE_JOBENDNOTIF_CODE" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".FEE_JOBENDNOTIF_CODE" RX
   #endif
   #endif
#elif defined (FEE_STOP_JOBENDNOTIF)
   #undef   FEE_STOP_JOBENDNOTIF
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif

#elif defined (FEE_START_JOBERRNOTIF)
   #undef   FEE_START_JOBERRNOTIF
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code "FEE_JOBERRNOTIF_CODE"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.FEE_JOBERRNOTIF_CODE" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".FEE_JOBERRNOTIF_CODE" RX
   #endif
   #endif
#elif defined (FEE_STOP_JOBERRNOTIF)
   #undef   FEE_STOP_JOBERRNOTIF
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif

#elif defined (FEE_START_ILLEGALNOTIF)
   #undef   FEE_START_ILLEGALNOTIF
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code "FEE_ILLEGALNOTIF_CODE"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".text.FEE_ILLEGALNOTIF_CODE" ax
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".FEE_ILLEGALNOTIF_CODE" RX
   #endif
   #endif
#elif defined (FEE_STOP_ILLEGALNOTIF)
   #undef   FEE_STOP_ILLEGALNOTIF
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif
   
   
#elif defined (FLS_17_PMU_START_CONFIG)
   #undef      FLS_17_PMU_START_CONFIG
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section fardata="FLS_RESERVED"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.FLS_RESERVED" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".FLS_RESERVED" far-absolute RW
   #endif
   #endif
#elif defined (FLS_17_PMU_STOP_CONFIG)
   #undef      FLS_17_PMU_STOP_CONFIG
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section fardata restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif
   
#elif defined (ETH_17_ETHMAC_RES_START_SEC_VAR_FAST_8BIT)
   #undef      ETH_17_ETHMAC_RES_START_SEC_VAR_FAST_8BIT
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="ETH_RAM_FAST_8BIT"
   #pragma for_uninitialized_data_use_memory near
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.ETH_RAM_FAST_8BIT" awB 1
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".error" ".ETH_RAM_FAST_8BIT" RW
   #endif
   #endif
#elif defined (ETH_17_ETHMAC_RES_STOP_SEC_VAR_FAST_8BIT)
   #undef      ETH_17_ETHMAC_RES_STOP_SEC_VAR_FAST_8BIT
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif

#elif defined (ETH_17_ETHMAC_RES_START_SEC_VAR_FAST_32BIT)
   #undef      ETH_17_ETHMAC_RES_START_SEC_VAR_FAST_32BIT
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section nearbss="ETH_RAM_FAST_32BIT"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".bss.ETH_RAM_FAST_32BIT" awB 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".error" ".ETH_RAM_FAST_32BIT" RW
   #endif
   #endif
#elif defined (ETH_17_ETHMAC_RES_STOP_SEC_VAR_FAST_32BIT)
   #undef      ETH_17_ETHMAC_RES_STOP_SEC_VAR_FAST_32BIT
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif
   
 #elif defined (ADC_DMA_START_SEC_EMUXSCAN_BUFFER)
   #undef      ADC_DMA_START_SEC_EMUXSCAN_BUFFER
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farbss="ADC_DMA_EMUXSCAN_RAM_16BIT"
   #pragma align 4
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".data.ADC_DMA_EMUXSCAN_RAM_16BIT" aw 4
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".ADC_DMA_EMUXSCAN_RAM_16BIT" far-absolute RW
   #endif
   #endif
#elif defined (ADC_DMA_STOP_SEC_EMUXSCAN_BUFFER)
   #undef      ADC_DMA_STOP_SEC_EMUXSCAN_BUFFER
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma align restore
   #pragma section farbss restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif
   
#elif defined (FLSLOADER_START_SEC_RAMCODE)
   #undef      FLSLOADER_START_SEC_RAMCODE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code="FLSLOADERRAMCODE"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".FLSLOADERRAMCODE" ax 
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE ".FLSLOADERRAMCODE" far-absolute RX
   #endif
   #endif
#elif defined (FLSLOADER_STOP_SEC_RAMCODE)
   #undef      FLSLOADER_STOP_SEC_RAMCODE
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section code restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CODE RX
   #endif
   #endif
   
#elif defined (BMD_HDR_START_SEC_BMI_HEADER)
   #undef      BMD_HDR_START_SEC_BMI_HEADER
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom="BMD_HDR_CONST_FAR_UNSPECIFIED"
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section ".rodata.BMD_HDR_CONST_FAR_UNSPECIFIED" a
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST ".BMD_HDR_CONST_FAR_UNSPECIFIED" far-absolute R
   #endif
   #endif
#elif defined (BMD_HDR_STOP_SEC_BMI_HEADER)
   #undef      BMD_HDR_STOP_SEC_BMI_HEADER
   #ifdef _TASKING_C_TRICORE_
   #if(_TASKING_C_TRICORE_ == 1U)
   #pragma section farrom restore
   #endif
   #elif defined _GNU_C_TRICORE_
   #if(_GNU_C_TRICORE_ == 1U)
   #pragma section
   #endif
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section CONST R
   #endif
   #endif
   
#elif defined (SPI_START_SEC_VAR_FAST_32BIT)
   #undef      SPI_START_SEC_VAR_FAST_32BIT
   #pragma section DATA ".error" ".SPI_RAM_FAST_32BIT" RW
#elif defined (SPI_STOP_SEC_VAR_FAST_32BIT)
   #undef      SPI_STOP_SEC_VAR_FAST_32BIT
   #pragma section DATA RW   
   
/* -------------------------------------------------------------------------- */
/* End of default section mapping                                             */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/* Begin alignment mapping                                                    */
/* -------------------------------------------------------------------------- */

#elif defined (DEFAULT_START_VAR_ALIGN_16_BIT)
   #undef      DEFAULT_START_VAR_ALIGN_16_BIT
   #pragma align 4
#elif defined (DEFAULT_STOP_VAR_ALIGN_16_BIT)
   #undef      DEFAULT_STOP_VAR_ALIGN_16_BIT
   #pragma align restore
/* -------------------------------------------------------------------------- */
/* End of alignment mapping                                                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/* Begin Packing                                                              */
/* -------------------------------------------------------------------------- */

#elif defined (DEFAULT_START_VAR_PACK_2)
   #undef      DEFAULT_START_VAR_PACK_2
   #pragma pack 2
#elif defined (DEFAULT_STOP_VAR_PACK_2)
   #undef      DEFAULT_STOP_VAR_PACK_2
   #pragma pack 0
/* -------------------------------------------------------------------------- */
/* End of Packing                                                             */
/* -------------------------------------------------------------------------- */

/*lint +idlen(60) +esym(961,92) */
/*lint +esym(960,19.6)   */  /* Allow usage of #undef */

#endif  /* START_WITH_IF */     
         

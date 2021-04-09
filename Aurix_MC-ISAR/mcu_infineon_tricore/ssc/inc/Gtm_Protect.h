/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2016)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : Gtm_Protect.h $                                            **
**                                                                            **
**   $CC VERSION : \main\5 $                                                  **
**                                                                            **
**   $DATE       : 2016-04-21 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : This file file define all the first level                  **
**                 indirection macros for Protected mode support              **
**                                                                            **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: Yes                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** Traceabilty      :                                                         **
**                                                                            **
*******************************************************************************/

#ifndef  GTM_PROTECT_CFG_H
#define  GTM_PROTECT_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of McalOsConfig.h */
#include "McalOsConfig.h"
#include MCAL_OS_HEADER
#include "Gtm_Cfg.h"

#define OS_AREA_DRV_GTM (01U)
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

#if (GTM_USER_MODE_INIT_API_ENABLE == STD_ON) 
#define GTM_INIT_RESETENDINIT()                                              \
        TRUSTED_ApplResetEndInit()
#define GTM_INIT_SETENDINIT()                                                \
        TRUSTED_ApplSetEndInit()
#define GTM_INIT_WRITE32(reg,value)                                          \
  OS_WritePeripheral32(OS_AREA_DRV_GTM,(volatile uint32*)(volatile void*)    \
        (&(reg)),(value))
#define GTM_INIT_MODIFY32(reg,clearmask,setmask)                             \
  OS_ModifyPeripheral32(OS_AREA_DRV_GTM,(volatile uint32*)(volatile void*)   \
        (&(reg)),(clearmask),(setmask))
#define GTM_INIT_RESETSAFETYENDINIT_TIMED(Time)                              \
        TRUSTED_ApplSafetyResetEndInit_Timed((Time))
#define GTM_INIT_SETSAFETYENDINIT_TIMED()                                    \
        TRUSTED_ApplSafetySetEndInit_Timed()
#if (GTM_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  #define GTM_INIT_USER_MODE_OS_API_WRITE32(reg,value)                       \
    OS_WritePeripheral32(OS_AREA_DRV_GTM,(volatile uint32*)(volatile void*)  \
        (&(reg)),(value))
  #define GTM_INIT_USER_MODE_OS_API_READ32(reg)                              \
    OS_ReadPeripheral32(OS_AREA_DRV_GTM,(volatile uint32*)(volatile void*)   \
        (&(reg)))
  #define GTM_INIT_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)          \
    OS_ModifyPeripheral32(OS_AREA_DRV_GTM,(volatile uint32*)(volatile void*) \
        (&(reg)),(clearmask),(setmask))
#endif
#endif /* GTM_USER_MODE_INIT_API_ENABLE == STD_ON  */

#if (GTM_USER_MODE_DEINIT_API_ENABLE == STD_ON)
#define GTM_DEINIT_RESETENDINIT()                                            \
        TRUSTED_ApplResetEndInit()
#define GTM_DEINIT_SETENDINIT()                                              \
        TRUSTED_ApplSetEndInit()
#define GTM_DEINIT_WRITE32(reg,value)                                        \
  OS_WritePeripheral32(OS_AREA_DRV_GTM,(volatile uint32*)(volatile void*)    \
        (&(reg)),(value))
#define GTM_DEINIT_MODIFY32(reg,clearmask,setmask)                           \
  OS_ModifyPeripheral32(OS_AREA_DRV_GTM,(volatile uint32*)(volatile void*)   \
        (&(reg)),(clearmask),(setmask))
#if (GTM_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  #define GTM_DEINIT_USER_MODE_OS_API_READ32(reg)                            \
    OS_ReadPeripheral32(OS_AREA_DRV_GTM,(volatile uint32*)(volatile void*)   \
        (&(reg)))
#endif 
#endif /* GTM_USER_MODE_DEINIT_API_ENABLE == STD_ON  */

#if (GTM_USER_MODE_RUNTIME_API_ENABLE == STD_ON) 
#define GTM_RUNTIME_WRITE32(reg,value)                                       \
  OS_WritePeripheral32(OS_AREA_DRV_GTM,(volatile uint32*)(volatile void*)    \
        (&(reg)),(value))
#define GTM_RUNTIME_READ32(reg)                                              \
  OS_ReadPeripheral32(OS_AREA_DRV_GTM,(volatile uint32*)(volatile void*)     \
        (&(reg)))
#define GTM_RUNTIME_MODIFY32(reg,clearmask,setmask)                          \
  OS_ModifyPeripheral32(OS_AREA_DRV_GTM,(volatile uint32*)(volatile void*)   \
        (&(reg)),(clearmask),(setmask))
#if (GTM_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  #define GTM_RUNTIME_USER_MODE_OS_API_WRITE32(reg,value)                    \
    OS_WritePeripheral32(OS_AREA_DRV_GTM,(volatile uint32*)(volatile void*)  \
        (&(reg)),(value))
  #define GTM_RUNTIME_USER_MODE_OS_API_READ32(reg)                           \
    OS_ReadPeripheral32(OS_AREA_DRV_GTM,(volatile uint32*)(volatile void*)   \
        (&(reg)))
  #define GTM_RUNTIME_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)       \
    OS_ModifyPeripheral32(OS_AREA_DRV_GTM,(volatile uint32*)(volatile void*) \
        (&(reg)),(clearmask),(setmask))
  #define GTM_RUNTIME_USER_MODE_OS_API_READ_REG32(regptr)                    \
    OS_ReadPeripheral32(OS_AREA_DRV_GTM,(volatile uint32*)(volatile void*)   \
        (regptr))
#endif                                                                       
#endif /* GTM_USER_MODE_RUNTIME_API_ENABLE == STD_ON  */                        
#endif 
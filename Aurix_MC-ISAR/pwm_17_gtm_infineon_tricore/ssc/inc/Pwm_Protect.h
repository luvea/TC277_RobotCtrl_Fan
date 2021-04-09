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
**  $FILENAME   : Pwm_Protect.h $                                            **
**                                                                            **
**   $CC VERSION : \main\4 $                                                  **
**                                                                            **
**   $DATE       : 2016-07-27 $                                               **
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

#ifndef  PWM_PROTECT_CFG_H
#define  PWM_PROTECT_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of McalOsConfig.h */
#include "McalOsConfig.h"
#include MCAL_OS_HEADER
#include "Pwm_17_Gtm_Cfg.h"

#define OS_AREA_DRV_PWM (01U)
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

#if (PWM_USER_MODE_INIT_API_ENABLE == STD_ON)
#if (PWM_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  #define PWM_INIT_USER_MODE_OS_API_WRITE32(reg,value)                    \
   OS_WritePeripheral32(OS_AREA_DRV_PWM,(volatile uint32*)(volatile void*)\
        (&(reg)),(value))
  #define PWM_INIT_USER_MODE_OS_API_READ32(reg)                           \
  OS_ReadPeripheral32(OS_AREA_DRV_PWM,(volatile uint32*)(volatile void*)  \
        (&(reg)))
  #define PWM_INIT_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)       \
  OS_ModifyPeripheral32(OS_AREA_DRV_PWM,(volatile uint32*)                \
        (volatile void*)(&(reg)),(clearmask),(setmask))
#endif
#endif /* PWM_USER_MODE_INIT_API_ENABLE == STD_ON  */

#if (PWM_USER_MODE_DEINIT_API_ENABLE == STD_ON)
#if (PWM_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  #define PWM_DEINIT_USER_MODE_OS_API_WRITE32(reg,value)                  \
  OS_WritePeripheral32(OS_AREA_DRV_PWM,(volatile uint32*)(volatile void*) \
         (&(reg)),(value))
  #define PWM_DEINIT_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)     \
  OS_ModifyPeripheral32(OS_AREA_DRV_PWM,(volatile uint32*)                \
         (volatile void*)(&(reg)),(clearmask),(setmask))
#endif
#endif /* PWM_USER_MODE_DEINIT_API_ENABLE == STD_ON  */

#if (PWM_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
#if (PWM_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  #define PWM_RUNTIME_USER_MODE_OS_API_WRITE32(reg,value)                 \
  OS_WritePeripheral32(OS_AREA_DRV_PWM,(volatile uint32*)(volatile void*) \
        (&(reg)),(value))
  #define PWM_RUNTIME_USER_MODE_OS_API_READ32(reg)                        \
  OS_ReadPeripheral32(OS_AREA_DRV_PWM,(volatile uint32*)(volatile void*)  \
         (&(reg)))
  #define PWM_RUNTIME_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)    \
  OS_ModifyPeripheral32(OS_AREA_DRV_PWM,(volatile uint32*)                \
        (volatile void*)(&(reg)),(clearmask),(setmask))
#endif
#endif /* PWM_USER_MODE_RUNTIME_API_ENABLE == STD_ON  */

#endif
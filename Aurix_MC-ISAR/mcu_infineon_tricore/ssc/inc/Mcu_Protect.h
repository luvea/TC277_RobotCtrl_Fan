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
**  $FILENAME   : Mcu_Protect.h $                                            **
**                                                                            **
**   $CC VERSION : \main\11 $                                                 **
**                                                                            **
**   $DATE       : 2016-09-21 $                                               **
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

#ifndef  MCU_PROTECT_CFG_H
#define  MCU_PROTECT_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of McalOsConfig.h */
#include "McalOsConfig.h"
#include MCAL_OS_HEADER
#include "Mcu_Cfg.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

#if ( MCU_SAFETY_ENABLE == STD_ON ) 
 #if (MCU_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
/* These MACRO calls should be handled by User when Safety is ON, to 
   ensure that TRUSTED call is made by an Application to get required 
   Access to an API */
 #define MCU_SAFETY_RESETSAFETYENDINIT_TIMED(ServiceId,Time) \
                                (TRUSTED_ApplSafetyResetEndInit_Timed((Time)))
   #define MCU_SAFETY_SETSAFETYENDINIT_TIMED(ServiceId) \
                       (TRUSTED_ApplSafetySetEndInit_Timed())
   #define MCU_RESETENDINIT(ServiceId) (TRUSTED_ApplResetEndInit())  
   #define MCU_SETENDINIT(ServiceId) (TRUSTED_ApplSetEndInit())
 #else
   #define MCU_SAFETY_RESETSAFETYENDINIT_TIMED(ServiceId,Time) \
                                (Mcal_ResetSafetyENDINIT_Timed(Time))
   #define MCU_SAFETY_SETSAFETYENDINIT_TIMED(ServiceId) \
                       (Mcal_SetSafetyENDINIT_Timed())
   #define MCU_RESETENDINIT(ServiceId) (Mcal_ResetENDINIT()) 
   #define MCU_SETENDINIT(ServiceId) (Mcal_SetENDINIT()) 
 #endif
#endif

#define OS_AREA_DRV_MCU                  (101U)
#if (MCU_USER_MODE_INIT_API_ENABLE == STD_ON)
#define MCU_INIT_RESETENDINIT() (TRUSTED_ApplResetEndInit())
#define MCU_INIT_SETENDINIT()  (TRUSTED_ApplSetEndInit())
#define MCU_INIT_WRITE32(reg,value) \
                                      (OS_WritePeripheral32((OS_AREA_DRV_MCU),\
                            (volatile uint32*)(volatile void*)(&(reg)),(value)))
#define MCU_INIT_MODIFY32(reg,clearmask,setmask) \
                                    OS_ModifyPeripheral32((OS_AREA_DRV_MCU),\
             (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
#define MCU_INIT_RESETSAFETYENDINIT_TIMED(Time)\
                                  (TRUSTED_ApplSafetyResetEndInit_Timed((Time)))
#define MCU_INIT_SETSAFETYENDINIT_TIMED() \
                                          (TRUSTED_ApplSafetySetEndInit_Timed())
#if (MCU_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  #define MCU_INIT_USER_MODE_OS_API_READ32(reg) \
                                    (OS_ReadPeripheral32((OS_AREA_DRV_MCU),\
                                    (volatile uint32*)(volatile void*)(&(reg))))
#endif
#endif /* MCU_USER_MODE_INIT_API_ENABLE == STD_ON  */

#if (MCU_USER_MODE_DEINIT_API_ENABLE == STD_ON)
#define MCU_DEINIT_RESETENDINIT() (TRUSTED_ApplResetEndInit())
#define MCU_DEINIT_SETENDINIT() (TRUSTED_ApplSetEndInit())
#define MCU_DEINIT_WRITE32(reg,value)  \
                                   (OS_WritePeripheral32((OS_AREA_DRV_MCU),\
                           (volatile uint32*)(volatile void*)(&(reg)),(value)))

#define MCU_DEINIT_MODIFY32(reg,clearmask,setmask) \
                                   (OS_ModifyPeripheral32((OS_AREA_DRV_MCU),\
            (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask)))
#define MCU_DEINIT_RESETSAFETYENDINIT_TIMED(Time) \
                                  (TRUSTED_ApplSafetyResetEndInit_Timed((Time)))
#define MCU_DEINIT_SETSAFETYENDINIT_TIMED() \
                                          (TRUSTED_ApplSafetySetEndInit_Timed())
#if (MCU_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
#define MCU_DEINIT_USER_MODE_OS_API_READ32(reg) \
          (OS_ReadPeripheral32((OS_AREA_DRV_MCU),\
          (volatile uint32*)(volatile void*)(&(reg))))
#endif
#endif /* MCU_USER_MODE_DEINIT_API_ENABLE == STD_ON  */

#if (MCU_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
#define MCU_RUNTIME_RESETENDINIT() (TRUSTED_ApplResetEndInit())
#define MCU_RUNTIME_SETENDINIT()    (TRUSTED_ApplSetEndInit())
#define MCU_RUNTIME_WRITE32(reg, value)    \
                                    (OS_WritePeripheral32((OS_AREA_DRV_MCU),\
                           (volatile uint32*)(volatile void*)(&(reg)),(value)))
#define MCU_RUNTIME_MODIFY32(reg,clearmask,setmask) \
                                   OS_ModifyPeripheral32((OS_AREA_DRV_MCU),\
              (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
#define MCU_RUNTIME_RESETSAFETYENDINIT_TIMED(Time) \
                                  (TRUSTED_ApplSafetyResetEndInit_Timed((Time)))
#define MCU_RUNTIME_SETSAFETYENDINIT_TIMED() \
                                          (TRUSTED_ApplSafetySetEndInit_Timed())
#if (MCU_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  #define MCU_RUNTIME_USER_MODE_OS_API_READ32(reg) \
                                        (OS_ReadPeripheral32((OS_AREA_DRV_MCU),\
                                    (volatile uint32*)(volatile void*)(&(reg))))
#endif
#endif /* MCU_USER_MODE_RUNTIME_API_ENABLE == STD_ON  */
 #endif
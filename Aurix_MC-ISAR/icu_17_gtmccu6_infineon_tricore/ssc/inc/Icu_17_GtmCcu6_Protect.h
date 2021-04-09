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
**  $FILENAME   : Icu_17_GtmCcu6_Protect.h $                                 **
**                                                                            **
**   $CC VERSION : \main\2 $                                                  **
**                                                                            **
**   $DATE       : 2016-04-15 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : This file file define all the first level                  **
**                 indirection macros for Protected mode supICU              **
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

#ifndef  ICU_PROTECT_CFG_H
#define  ICU_PROTECT_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of McalOsConfig.h */
#include "McalOsConfig.h"
#include MCAL_OS_HEADER
#include "Icu_17_GtmCcu6_Cfg.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define OS_AREA_DRV_ICU                  (17U)
#if (ICU_USER_MODE_INIT_API_ENABLE == STD_ON) 
#define ICU_INIT_RESETENDINIT()                     (TRUSTED_ApplResetEndInit())
#define ICU_INIT_SETENDINIT()                        (TRUSTED_ApplSetEndInit())
#define ICU_INIT_WRITE32(reg,value) \
(OS_WritePeripheral32((OS_AREA_DRV_ICU),(volatile uint32*)(volatile void*)(&(reg)),(value)))
#define ICU_INIT_MODIFY32(reg,clearmask,setmask) \
(OS_ModifyPeripheral32((OS_AREA_DRV_ICU),(volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask)))
#define ICU_INIT_SETATOMIC(Address,Value,Offset,Bits) \
                            (TRUSTED_Mcal_SetAtomic(Address,Value,Offset,Bits))
#if (ICU_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)                            
  #define ICU_INIT_USER_MODE_OS_API_WRITE32(reg,value) \
  (OS_WritePeripheral32((OS_AREA_DRV_ICU),(volatile uint32*)(volatile void*)(&(reg)),(value)))
  #define ICU_INIT_USER_MODE_OS_API_READ32(reg) \
  (OS_ReadPeripheral32((OS_AREA_DRV_ICU),(volatile uint32*)(volatile void*)(&(reg))))
  #define ICU_INIT_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask) \
  (OS_ModifyPeripheral32((OS_AREA_DRV_ICU),(volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask)))
#endif                                                                       
#endif /* ICU_USER_MODE_INIT_API_ENABLE == STD_ON  */                        

#if (ICU_USER_MODE_RUNTIME_API_ENABLE == STD_ON) 
#define ICU_RUNTIME_SETATOMIC(Address,Value,Offset,Bits) \
                             (TRUSTED_Mcal_SetAtomic(Address,Value,Offset,Bits))
#if (ICU_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)                            
  #define ICU_RUNTIME_USER_MODE_OS_API_WRITE32(reg,value) \
  (OS_WritePeripheral32((OS_AREA_DRV_ICU),(volatile uint32*)(volatile void*)(&(reg)),(value)))
  #define ICU_RUNTIME_USER_MODE_OS_API_READ32(reg) \
  (OS_ReadPeripheral32((OS_AREA_DRV_ICU),(volatile uint32*)(volatile void*)(&(reg))))
  #define ICU_RUNTIME_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask) \
  (OS_ModifyPeripheral32((OS_AREA_DRV_ICU),(volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask)))
#endif                                                                       
#endif /* ICU_USER_MODE_RUNTIME_API_ENABLE == STD_ON  */                        
 
#if (ICU_USER_MODE_DEINIT_API_ENABLE == STD_ON) 
#define ICU_DEINIT_RESETENDINIT()                   (TRUSTED_ApplResetEndInit())
#define ICU_DEINIT_SETENDINIT()                      (TRUSTED_ApplSetEndInit())
#define ICU_DEINIT_WRITE32(reg,value) \
(OS_WritePeripheral32((OS_AREA_DRV_ICU),(volatile uint32*)(volatile void*)(&(reg)),(value)))
#define ICU_DEINIT_MODIFY32(reg,clearmask,setmask) \
(OS_ModifyPeripheral32((OS_AREA_DRV_ICU),(volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask)))
#define ICU_DEINIT_SETATOMIC(Address,Value,Offset,Bits) \
                            (TRUSTED_Mcal_SetAtomic(Address,Value,Offset,Bits))
#if (ICU_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)                            
  #define ICU_DEINIT_USER_MODE_OS_API_WRITE32(reg,value) \
  (OS_WritePeripheral32((OS_AREA_DRV_ICU),(volatile uint32*)(volatile void*)(&(reg)),(value)))
  #define ICU_DEINIT_USER_MODE_OS_API_READ32(reg) \
  (OS_ReadPeripheral32((OS_AREA_DRV_ICU),(volatile uint32*)(volatile void*)(&(reg))))
  #define ICU_DEINIT_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask) \
  (OS_ModifyPeripheral32((OS_AREA_DRV_ICU),(volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask)))
#endif                                                                       
#endif /* ICU_USER_MODE_DEINIT_API_ENABLE == STD_ON  */ 

#endif 
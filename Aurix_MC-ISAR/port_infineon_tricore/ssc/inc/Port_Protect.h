/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2016)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. This is a demo file and the contents of this file            **
** if required shall be modified by the customer.                             **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : Port_Protect.h $                                           **
**                                                                            **
**   $CC VERSION : \main\7 $                                                  **
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

#ifndef  PORT_PROTECT_CFG_H
#define  PORT_PROTECT_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of McalOsConfig.h */
#include "McalOsConfig.h"
#include MCAL_OS_HEADER
#include "Port_Cfg.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define OS_AREA_DRV_PORT               (124U)
#if (PORT_USER_MODE_INIT_API_ENABLE == STD_ON)
#define PORT_INIT_RESETENDINIT()       TRUSTED_ApplResetEndInit()
#define PORT_INIT_SETENDINIT()         TRUSTED_ApplSetEndInit()
#define PORT_INIT_WRITE32(reg, value)  OS_WritePeripheral32((OS_AREA_DRV_PORT),\
                             (volatile uint32*)(volatile void*)(&(reg)),(value))
#define PORT_INIT_RESETSAFETYENDINIT_TIMED(Time) \
                                   TRUSTED_ApplSafetyResetEndInit_Timed((Time))
#define PORT_INIT_SETSAFETYENDINIT_TIMED()  \
                                        TRUSTED_ApplSafetySetEndInit_Timed()

#if (PORT_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  #define PORT_INIT_USER_MODE_OS_API_WRITE32(reg, value)                       \
                                       OS_WritePeripheral32((OS_AREA_DRV_PORT),\
                             (volatile uint32*)(volatile void*)(&(reg)),(value))
  #define PORT_INIT_USER_MODE_OS_API_READ32(reg)                               \
                                       OS_ReadPeripheral32((OS_AREA_DRV_PORT), \
                                     (volatile uint32*)(volatile void*)(&(reg)))

#endif
#endif /* PORT_USER_MODE_INIT_API_ENABLE == STD_ON  */

#if (PORT_USER_MODE_RUNTIME_API_ENABLE == STD_ON)

#if (PORT_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)

  #define PORT_RUNTIME_USER_MODE_OS_API_READ32(reg)                            \
                                        OS_ReadPeripheral32((OS_AREA_DRV_PORT),\
                                     (volatile uint32*)(volatile void*)(&(reg)))
  #define PORT_RUNTIME_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)        \
                    OS_ModifyPeripheral32((OS_AREA_DRV_PORT),(volatile uint32*)\
                                (volatile void*)(&(reg)),(clearmask),(setmask));
#endif
#endif /* PORT_USER_MODE_RUNTIME_API_ENABLE == STD_ON  */
#endif
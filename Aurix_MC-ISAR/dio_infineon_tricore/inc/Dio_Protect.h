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
**  $FILENAME   : Dio_Protect.h $                                            **
**                                                                            **
**   $CC VERSION : \main\3 $                                                  **
**                                                                            **
**   $DATE       : 2016-04-15 $                                               **
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

#ifndef  DIO_PROTECT_CFG_H
#define  DIO_PROTECT_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of McalOsConfig.h */
#include "McalOsConfig.h"
#include MCAL_OS_HEADER
#include "Dio_Cfg.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define OS_AREA_DRV_DIO                (120U)

#if (DIO_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
#if (DIO_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  #define DIO_RUNTIME_USER_MODE_OS_API_WRITE32(reg, value)                     \
                                        OS_WritePeripheral32((OS_AREA_DRV_DIO),\
                             (volatile uint32*)(volatile void*)(&(reg)),(value))
  #define DIO_RUNTIME_USER_MODE_OS_API_READ32(reg)                             \
                                         OS_ReadPeripheral32((OS_AREA_DRV_DIO),\
                                     (volatile uint32*)(volatile void*)(&(reg)))
#endif
#endif /* DIO_USER_MODE_RUNTIME_API_ENABLE == STD_ON  */
#endif
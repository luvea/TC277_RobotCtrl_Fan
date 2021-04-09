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
**  $FILENAME   : Uart_Protect.h $                                           **
**                                                                            **
**   $CC VERSION : \main\4 $                                                  **
**                                                                            **
**   $DATE       : 2016-04-18 $                                               **
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

#ifndef UART_PROTECT_CFG_H
#define UART_PROTECT_CFG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of McalOsConfig.h */
#include "McalOsConfig.h"
#include MCAL_OS_HEADER
#include "Uart_Cfg.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define OS_AREA_DRV_UART                  (80U)
#if (UART_USER_MODE_INIT_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define UART_INIT_RESETENDINIT()        TRUSTED_ApplResetEndInit()
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define UART_INIT_SETENDINIT()          TRUSTED_ApplSetEndInit()
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define UART_INIT_WRITE32(reg, value) OS_WritePeripheral32((OS_AREA_DRV_UART),\
                            (volatile uint32*)(volatile void*)(&(reg)),(value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define UART_INIT_MODIFY32(reg,clearmask,setmask)                             \
                                   OS_ModifyPeripheral32((OS_AREA_DRV_UART),\
          (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));

#if (UART_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)

  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
  #define UART_INIT_USER_MODE_OS_API_READ32(reg)                              \
                                      OS_ReadPeripheral32((OS_AREA_DRV_UART),\
                                    (volatile uint32*)(volatile void*)(&(reg)))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
  #define UART_INIT_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)          \
                                     OS_ModifyPeripheral32((OS_AREA_DRV_UART),\
             (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
#endif
#endif /* UART_USER_MODE_INIT_API_ENABLE == STD_ON  */

#if (UART_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define UART_RUNTIME_MODIFY32(reg,clearmask,setmask)                          \
                                     OS_ModifyPeripheral32((OS_AREA_DRV_UART),\
             (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));

#if (UART_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
  #define UART_RUNTIME_USER_MODE_OS_API_WRITE32(reg, value)                   \
                                      OS_WritePeripheral32((OS_AREA_DRV_UART),\
                            (volatile uint32*)(volatile void*)(&(reg)),(value))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
  #define UART_RUNTIME_USER_MODE_OS_API_READ32(reg)                           \
                                       OS_ReadPeripheral32((OS_AREA_DRV_UART),\
                                   (volatile uint32*)(volatile void*)(&(reg)))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
  #define UART_RUNTIME_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)       \
                   OS_ModifyPeripheral32((OS_AREA_DRV_UART),(volatile uint32*)\
                               (volatile void*)(&(reg)),(clearmask),(setmask));
#endif
#endif /* UART_USER_MODE_RUNTIME_API_ENABLE == STD_ON  */

#if (UART_USER_MODE_DEINIT_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define UART_DEINIT_RESETENDINIT()     TRUSTED_ApplResetEndInit()
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define UART_DEINIT_SETENDINIT()       TRUSTED_ApplSetEndInit()
#define UART_DEINIT_WRITE32(reg, value)    \
                                   OS_WritePeripheral32((OS_AREA_DRV_UART),\
                             (volatile uint32*)(volatile void*)(&(reg)),(value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define UART_DEINIT_MODIFY32(reg,clearmask,setmask)                            \
                                      OS_ModifyPeripheral32((OS_AREA_DRV_UART),\
              (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));

#if (UART_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
  #define UART_DEINIT_USER_MODE_OS_API_READ32(reg)                           \
                                    OS_ReadPeripheral32((OS_AREA_DRV_UART),\
                                   (volatile uint32*)(volatile void*)(&(reg)))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
  #define UART_DEINIT_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)       \
                  OS_ModifyPeripheral32((OS_AREA_DRV_UART),(volatile uint32*)\
                             (volatile void*)(&(reg)),(clearmask),(setmask));
#endif
#endif /* UART_USER_MODE_DEINIT_API_ENABLE == STD_ON  */
#endif
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2016)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This is a demo file and the contents of this file has to be modified by 
** the customer                                                               **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : Can_17_MCanP_Protect.h $                                   **
**                                                                            **
**   $CC VERSION : \main\6 $                                                  **
**                                                                            **
**   $DATE       : 2016-05-29 $                                               **
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

#ifndef  CAN_PROTECT_CFG_H
#define  CAN_PROTECT_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of McalOsConfig.h */
#include "McalOsConfig.h"
#include MCAL_OS_HEADER
#include "Can_17_MCanP_Cfg.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define OS_AREA_DRV_CAN                  (101U)
#if (CAN_USER_MODE_INIT_API_ENABLE == STD_ON) 
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define CAN_INIT_RESETENDINIT()  (TRUSTED_ApplResetEndInit())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define CAN_INIT_SETENDINIT()     (TRUSTED_ApplSetEndInit())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define CAN_INIT_WRITE32(reg,value)   \
    OS_WritePeripheral32((OS_AREA_DRV_CAN),\
                            (volatile uint32*)(volatile void*)(&(reg)),(value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define CAN_INIT_MODIFY32(reg,clearmask,setmask) \
        OS_ModifyPeripheral32((OS_AREA_DRV_CAN),\
            (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
#if (CAN_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)  
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/    
  #define CAN_INIT_USER_MODE_OS_API_WRITE32(reg,value)  \
    OS_WritePeripheral32((OS_AREA_DRV_CAN),\
                            (volatile uint32*)(volatile void*)(&(reg)),(value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
  #define CAN_INIT_USER_MODE_OS_API_READ32(reg) \
                    OS_ReadPeripheral32((OS_AREA_DRV_CAN),\
                                    (volatile uint32*)(volatile void*)(&(reg)))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
  #define CAN_INIT_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask) \
                                OS_ModifyPeripheral32((OS_AREA_DRV_CAN),\
             (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
#endif                                                                       
#endif /* CAN_USER_MODE_INIT_API_ENABLE == STD_ON  */                        
                                                                             
#if (CAN_USER_MODE_DEINIT_API_ENABLE == STD_ON)     
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define CAN_DEINIT_RESETENDINIT()   TRUSTED_ApplResetEndInit()
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define CAN_DEINIT_SETENDINIT()    TRUSTED_ApplSetEndInit()
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define CAN_DEINIT_WRITE32(reg, value)  \
                        OS_WritePeripheral32((OS_AREA_DRV_CAN),\
                            (volatile uint32*)(volatile void*)(&(reg)),(value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define CAN_DEINIT_MODIFY32(reg,clearmask,setmask) \
                    OS_ModifyPeripheral32((OS_AREA_DRV_CAN),\
             (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
#if (CAN_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)      
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
  #define CAN_DEINIT_USER_MODE_OS_API_READ32(reg) \
        OS_ReadPeripheral32((OS_AREA_DRV_CAN),\
                                    (volatile uint32*)(volatile void*)(&(reg)))
#endif 
#endif /* CAN_USER_MODE_DEINIT_API_ENABLE == STD_ON  */

#if (CAN_USER_MODE_RUNTIME_API_ENABLE == STD_ON) 
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define CAN_RUNTIME_WRITE32(reg, value) \
        OS_WritePeripheral32((OS_AREA_DRV_CAN),\
                            (volatile uint32*)(volatile void*)(&(reg)),(value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define CAN_RUNTIME_READ32(reg)  \
        OS_ReadPeripheral32((OS_AREA_DRV_CAN),\
                                    (volatile uint32*)(volatile void*)(&(reg)))
#define CAN_RUNTIME_MODIFY32(reg,clearmask,setmask)\
                        OS_ModifyPeripheral32((OS_AREA_DRV_CAN),\
              (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
#if (CAN_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)   
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/    
  #define CAN_RUNTIME_USER_MODE_OS_API_WRITE32(reg,value)   \
                OS_WritePeripheral32((OS_AREA_DRV_CAN),\
                            (volatile uint32*)(volatile void*)(&(reg)),(value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
  #define CAN_RUNTIME_USER_MODE_OS_API_READ32(reg) \
                        OS_ReadPeripheral32((OS_AREA_DRV_CAN),\
                                    (volatile uint32*)(volatile void*)(&(reg)))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
  #define CAN_RUNTIME_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)   \
            OS_ModifyPeripheral32((OS_AREA_DRV_CAN),\
             (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
#endif                                                                       
#endif /* CAN_USER_MODE_RUNTIME_API_ENABLE == STD_ON  */                        
 #endif 
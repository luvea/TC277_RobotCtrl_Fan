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
**  $FILENAME   : Adc_Protect.h $                                            **
**                                                                            **
**   $CC VERSION : \main\11 $                                                 **
**                                                                            **
**   $DATE       : 2016-06-20 $                                               **
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

#ifndef  ADC_PROTECT_CFG_H
#define  ADC_PROTECT_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of McalOsConfig.h */
#include "McalOsConfig.h"
#include MCAL_OS_HEADER
#include "Adc_Cfg.h"

#define OS_AREA_DRV_ADC ((uint16)123)
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*
  The below Macros are used when INIT API is executed in User-1 mode
*/
#if (ADC_USER_MODE_INIT_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define ADC_INIT_RESETENDINIT()                       TRUSTED_ApplResetEndInit()
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define ADC_INIT_SETENDINIT()                           TRUSTED_ApplSetEndInit()
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define ADC_INIT_WRITE32(reg, value)                                           \
                     OS_WritePeripheral32((OS_AREA_DRV_ADC),                   \
                             (volatile uint32*)(volatile void*)(&(reg)),(value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define ADC_INIT_MODIFY32(reg,clearmask,setmask)                               \
                     OS_ModifyPeripheral32((OS_AREA_DRV_ADC),                  \
              (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
/*
  The below Macros are used when INIT API is executed in User-0 mode
*/
#if (ADC_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
   calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
   modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
  #define ADC_INIT_USER_MODE_OS_API_WRITE32(reg,value)                         \
                     OS_WritePeripheral32((OS_AREA_DRV_ADC),                   \
                             (volatile uint32*)(volatile void*)(&(reg)),(value))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
   calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
   modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
  #define ADC_INIT_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)            \
                     OS_ModifyPeripheral32((OS_AREA_DRV_ADC),                  \
              (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
   calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
   modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
  #define ADC_INIT_USER_MODE_OS_API_READ32(reg)                                \
                     OS_ReadPeripheral32((OS_AREA_DRV_ADC),                    \
                                     (volatile uint32*)(volatile void*)(&(reg)))
  #if (( ADC_ERU_TRIGG == STD_ON ) || ( ADC_ERU_GATING == STD_ON ))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
   calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
   modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
  #define ADC_INIT_MCAL_SETATOMIC(Address,Value,Offset,Bits)                \
                       TRUSTED_Mcal_SetAtomic((Address),(Value),(Offset),(Bits))
 #endif /*  ADC_ERU_TRIGG == STD_ON */
#endif /* (ADC_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)*/
#endif /* (ADC_USER_MODE_INIT_API_ENABLE == STD_ON)  */

/*
  The below Macros are used when DEINIT API is executed in User-1 mode
*/
#if (ADC_DEINIT_API == STD_ON)
#if (ADC_USER_MODE_DEINIT_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define ADC_DEINIT_RESETENDINIT()                     TRUSTED_ApplResetEndInit()
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define ADC_DEINIT_SETENDINIT()                         TRUSTED_ApplSetEndInit()
#if (ADC_GROUP_EMUX_SCAN == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define ADC_DEINIT_MCAL_DMARESETDMACHANNEL(Channel)                            \
                                        TRUSTED_Mcal_DmaResetDmaChannel(Channel)
#endif /* (ADC_GROUP_EMUX_SCAN == STD_ON) */
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define ADC_DEINIT_WRITE32(reg, value)                                         \
                     OS_WritePeripheral32((OS_AREA_DRV_ADC),                   \
                             (volatile uint32*)(volatile void*)(&(reg)),(value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define ADC_DEINIT_MODIFY32(reg,clearmask,setmask)                             \
                     OS_ModifyPeripheral32((OS_AREA_DRV_ADC),                  \
              (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
/*
  The below Macros are used when DEINIT API is executed in User-0 mode
*/
#if (ADC_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
   calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
   modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
  #define ADC_DEINIT_USER_MODE_OS_API_WRITE32(reg,value)                       \
                     OS_WritePeripheral32((OS_AREA_DRV_ADC),                   \
                             (volatile uint32*)(volatile void*)(&(reg)),(value))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
   calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
   modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
  #define ADC_DEINIT_USER_MODE_OS_API_READ32(reg)                              \
                     OS_ReadPeripheral32((OS_AREA_DRV_ADC),                    \
                                     (volatile uint32*)(volatile void*)(&(reg)))
#endif /* (ADC_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)*/
#endif /* (ADC_USER_MODE_DEINIT_API_ENABLE == STD_ON)  */
#endif /* (ADC_DEINIT_API == STD_ON) */

/*
  The below Macros are used when RUNTIME APIs are executed in User-1 mode
*/
#if (ADC_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
#if (ADC_GROUP_EMUX_SCAN == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define ADC_RUNTIME_MCAL_DMACHCLRINTRFLAGS(Channel)                            \
                                         TRUSTED_Mcal_DmaChClrIntrFlags(Channel)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define ADC_RUNTIME_MCAL_DMACLRADCR(Channel)    TRUSTED_Mcal_DmaClrAdcr(Channel)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define ADC_RUNTIME_MCAL_DMADISABLEINTR(Channel)                               \
                                            TRUSTED_Mcal_DmaDisableIntr(Channel)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define ADC_RUNTIME_MCAL_DMACHCLRINTCTETRLFLAGS(Channel)                       \
                                    TRUSTED_Mcal_DmaChClrIntctEtrlFlags(Channel)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define ADC_RUNTIME_MCAL_DMACHCLRCTLCFG(Channel)                               \
                                            TRUSTED_Mcal_DmaChClrCtlCfg(Channel)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define ADC_RUNTIME_MCAL_DMADISABLEHWTRANSFER(Channel)                         \
                                      TRUSTED_Mcal_DmaDisableHwTransfer(Channel)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define ADC_RUNTIME_MCAL_DMAENABLEHWTRANSFER(Channel)                          \
                                       TRUSTED_Mcal_DmaEnableHwTransfer(Channel)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define ADC_RUNTIME_MCAL_DMASETADICR(Channel, Value)                           \
                                     TRUSTED_Mcal_DmaSetAdicr((Channel),(Value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define ADC_RUNTIME_MCAL_DMAENABLEINTR(Channel)                                \
                                             TRUSTED_Mcal_DmaEnableIntr(Channel)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define ADC_RUNTIME_MCAL_DMAENABLECHINTRTRIGGER(Channel)                       \
                                    TRUSTED_Mcal_DmaEnableChIntrTrigger(Channel)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define ADC_RUNTIME_MCAL_DMASETTXCOUNT(Channel,ReloadValue)                    \
                             TRUSTED_Mcal_DmaSetTxCount((Channel),(ReloadValue))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define ADC_RUNTIME_MCAL_DMASETDATAWIDTH(Channel,DataWidth)                    \
                             TRUSTED_Mcal_DmaSetDataWidth((Channel),(DataWidth))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define ADC_RUNTIME_MCAL_DMACFGINTCONTROL(Channel,Value)                       \
                                TRUSTED_Mcal_DmaCfgIntControl((Channel),(Value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define ADC_RUNTIME_MCAL_DMASETDESTADDR(Channel,Address)                       \
                                TRUSTED_Mcal_DmaSetDestAddr((Channel),(Address))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define ADC_RUNTIME_MCAL_DMASETSOURCEADDR(Channel,Address)                     \
                              TRUSTED_Mcal_DmaSetSourceAddr((Channel),(Address))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define ADC_RUNTIME_MCAL_DMAGETTRANSFERINTSTATUS(Channel)                      \
                                   TRUSTED_Mcal_DmaGetTransferIntStatus(Channel)
#endif /* (ADC_GROUP_EMUX_SCAN == STD_ON) */

/*
  The below Macros are used when RUNTIME APIs are executed in User-0 mode
*/
#if (ADC_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
   calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
   modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
  #define ADC_RUNTIME_USER_MODE_OS_API_WRITE32(reg,value)                      \
                     OS_WritePeripheral32((OS_AREA_DRV_ADC),                   \
                             (volatile uint32*)(volatile void*)(&(reg)),(value))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
   calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
   modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
  #define ADC_RUNTIME_USER_MODE_OS_API_READ32(reg)                             \
                     OS_ReadPeripheral32((OS_AREA_DRV_ADC),                    \
                                     (volatile uint32*)(volatile void*)(&(reg)))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
   calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
   modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
  #define ADC_RUNTIME_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)         \
                     OS_ModifyPeripheral32((OS_AREA_DRV_ADC),                  \
              (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));

 #if (( ADC_ERU_TRIGG == STD_ON ) || ( ADC_ERU_GATING == STD_ON ))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
   calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
   modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
  #define ADC_RUNTIME_MCAL_SETATOMIC(Address,Value,Offset,Bits)                \
                       TRUSTED_Mcal_SetAtomic((Address),(Value),(Offset),(Bits))
 #endif /*  ADC_ERU_TRIGG == STD_ON */
#endif /* (ADC_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)  */
#endif /* (ADC_USER_MODE_RUNTIME_API_ENABLE == STD_ON)  */
#endif

/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2014)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Uart.h $                                                   **
**                                                                           **
**  $CC VERSION : \main\38 $                                                 **
**                                                                           **
**  $DATE       : 2016-07-22 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file exports                                          **
**                functionality of UART driver.                              **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
   Traceability   : [cover parentID=SAS_NAS_ALL_PR746,
   SAS_NAS_ALL_PR630_PR631, DS_NAS_UART_PR3054] [/cover]
*******************************************************************************/

#ifndef UART_H
#define UART_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"

/* Inclusion of Mcal Specific Global Header File */
#include "Mcal.h"

/* Pre-compile/static configuration parameters for UART */
#include "Uart_Cfg.h"

/* Conditional Inclusion of Development Error Tracer File */
#if (UART_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* (UART_DEV_ERROR_DETECT == STD_ON) */

#if ((UART_USER_MODE_INIT_API_ENABLE == STD_ON) || \
     (UART_USER_MODE_RUNTIME_API_ENABLE == STD_ON) || \
     (UART_USER_MODE_DEINIT_API_ENABLE == STD_ON) || \
     (UART_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON))
       #include "Uart_Protect.h"
#endif
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/* Vendor ID */
#define UART_VENDOR_ID                (17U)

/* UART Module ID 255 */
#define UART_MODULE_ID                ((uint16)255U)

/* UART Instance ID */
#define UART_MODULE_INSTANCE          ((uint8)UART_INDEX)

/*
  Macro UART_PB_FIXEDADDR is Set OFF, if fixed address feature is
   de-selected
*/
#ifndef UART_PB_FIXEDADDR
#define UART_PB_FIXEDADDR             (STD_OFF)
#endif

#if (UART_DEV_ERROR_DETECT == STD_ON)
/*
  Development error values
*/

/* API service used without module initialization */
#define UART_E_UNINIT                 ((uint8)0x00)

/* API service used with an invalid channel Identifier */
#define UART_E_INVALID_CHANNEL        ((uint8)0x01)

/* API service used with an invalid pointer */
#define UART_E_INVALID_POINTER        ((uint8)0x02)

/* API service called in an invalid state */
#define UART_E_STATE_TRANSITION       ((uint8)0x03)

/*API Service called with NULL parameter.*/
#define UART_E_PARAM_POINTER          ((uint8)0x04)

/*API Service called with Invalid Data length param*/
#define UART_E_INVALID_SIZE           ((uint8)0x05)

/*
  API Service ID's
*/
/* API Service ID for Uart_Init() */
#define UART_SID_INIT                 ((uint8)0)

/* API Service ID for Uart_DeInit() */
#define UART_SID_DEINIT               ((uint8)1)

/* API Service ID for Uart_Read() */
#define UART_SID_READ                 ((uint8)2)

/* API Service ID for Uart_Write() */
#define UART_SID_WRITE                ((uint8)3)

/* API Service ID for Uart_AbortRead() */
#define UART_SID_ABORT_READ           ((uint8)4)

/* API Service ID for Uart_AbortWrite() */
#define UART_SID_ABORT_WRITE          ((uint8)5)

/* API Service ID for Uart_GetStatus() */
#define UART_SID_GETSTATUS            ((uint8)6)

/* API Service ID for Uart_GetVersionInfo() */
#define UART_SID_VERINFO              ((uint8)7)

#endif /* (UART_DEV_ERROR_DETECT == ON) */

/* UART FIFO Buffer Size */
#define UART_BUFFER_SIZE              (16U)

/******************************************************************************/

#define UART_KRST0_RST_CLEARMASK            0xFFFFFFFEU
#define UART_KRST1_RST_CLEARMASK            0xFFFFFFFEU
#define UART_KRSTCLR_CLR_CLEARMASK          0xFFFFFFFEU
#define UART_CSR_CLKSEL_CLEARMASK           0xFFFFFFE0U
#define UART_CSR_CON_MASK                   0x80000000U
#define UART_FRAMECON_MODE_CLEARMASK        0xFFFCFFFFU
#define UART_KRST0_RSTSTAT_MASK             0x00000002U
#define UART_CLC_DISS_MASK                  0x00000002U
#define UART_BRG_NUMERATOR_CLEARMASK        0xF000FFFFU
#define UART_BRG_DENOMINATOR_CLEARMASK      0xFFFFF000U
#define UART_BITCON_PRESCALER_CLEARMASK     0xFFFFF000U
#define UART_BITCON_OVERSAMPLING_CLEARMASK  0xFFF0FFFFU
#define UART_IOCR_DEPTH_CLEARMASK           0xFFFFFC0FU
#define UART_IOCR_CTSEN_CLEARMASK           0xDFFFFFFFU
#define UART_IOCR_RCPOL_CLEARMASK           0xFDFFFFFFU
#define UART_IOCR_LB_CLEARMASK              0xEFFFFFFFU
#define UART_IOCR_ALTI_CLEARMASK            0xFFFFFFF8U
#define UART_BITCON_SM_CLEARMASK            0x7FFFFFFFU
#define UART_BITCON_SAMPLEPOINT_CLEARMASK   0xF0FFFFFFU
#define UART_FRAMECON_PEN_CLEARMASK         0xBFFFFFFFU
#define UART_FRAMECON_ODD_CLEARMASK         0x7FFFFFFFU
#define UART_FRAMECON_IDLE_CLEARMASK        0xFFFFFE3FU
#define UART_FRAMECON_STOP_CLEARMASK        0xFFFFF1FFU
#define UART_TXFIFOCON_INW_CLEARMASK        0xFFFFFF3FU
#define UART_TXFIFOCON_FLUSH_CLEARMASK      0xFFFFFFFEU
#define UART_TXFIFOCON_ENO_CLEARMASK        0xFFFFFFFDU
#define UART_TXFIFOCON_INTLEVEL_CLEARMASK   0xFFFFF0FFU
#define UART_TXFIFOCON_FILL_MASK            0x001F0000U
#define UART_TXFIFOCON_ENO_MASK             0xFFFFFFFDU
#define UART_TXFIFOCON_FLUSH_MASK           0xFFFFFFFEU
#define UART_RXFIFOCON_OUTW_CLEARMASK       0xFFFFFF3FU
#define UART_RXFIFOCON_INTLEVEL_CLEARMASK   0xFFFFF0FFU
#define UART_RXFIFOCON_FLUSH_CLEARMASK      0xFFFFFFFEU
#define UART_RXFIFOCON_ENI_CLEARMASK        0xFFFFFFFDU
#define UART_DATCON_DATLEN_CLEARMASK        0xFFFFFFF0U
#define UART_DATCON_DATLEN_MASK             0x0000000FU
#define UART_FLAGSENABLE_PEE_CLEARMASK      0xFFFEFFFFU
#define UART_FLAGSENABLE_FEE_CLEARMASK      0xFFFBFFFFU
#define UART_FLAGSENABLE_RFLE_CLEARMASK     0xEFFFFFFFU
#define UART_FLAGSENABLE_RFUE_CLEARMASK     0xF7FFFFFFU
#define UART_FLAGSENABLE_TCE_CLEARMASK      0xFFFDFFFFU
#define UART_FLAGSENABLE_TFLE_CLEARMASK     0x7FFFFFFFU
#define UART_FLAGSENABLE_TFOE_CLEARMASK     0xBFFFFFFFU
#define UART_FLAGSENABLE_TFOE_MASK          0xBFFFFFFFU
#define UART_FLAGSENABLE_TCE_MASK           0xFFFDFFFFU
#define UART_FLAGSCLEAR_PEC_CLEARMASK       0xFFFEFFFFU
#define UART_FLAGSCLEAR_FEC_CLEARMASK       0xFFFBFFFFU
#define UART_FLAGSCLEAR_RFLC_CLEARMASK      0xEFFFFFFFU
#define UART_FLAGSCLEAR_RFUC_CLEARMASK      0xF7FFFFFFU
#define UART_FLAGSCLEAR_TCC_CLEARMASK       0xFFFDFFFFU
#define UART_FLAGSCLEAR_TFLC_CLEARMASK      0x7FFFFFFFU
#define UART_FLAGSCLEAR_TFOC_CLEARMASK      0xBFFFFFFFU
#define UART_FLAGSCLEAR_TFOC_MASK           0xBFFFFFFFU
#define UART_FLAGSCLEAR_RFOC_MASK           0xFBFFFFFFU
#define UART_FLAGSCLEAR_PEC_MASK            0xFFFEFFFFU
#define UART_FLAGSCLEAR_FEC_MASK            0xFFFBFFFFU
#define UART_FLAGSCLEAR_RFUC_MASK           0xF7FFFFFFU
#define UART_FLAGSCLEAR_TCC_MASK            0xFFFDFFFFU
#define UART_FLAGS_PE_MASK                  0x00010000U
#define UART_FLAGS_FE_MASK                  0x00040000U
#define UART_FLAGS_TFO_MASK                 0x40000000U
#define UART_FLAGS_RFO_MASK                 0x04000000U
#define UART_FLAGS_RFU_MASK                 0x08000000U
#define UART_FLAGS_TC_MASK                  0x00020000U
#define UART_FLAGSENABLE_TFLE_MASK          0x7FFFFFFFU
#define UART_CSR_CON_BITPOS                    31U
#define UART_BRG_NUMERATOR_BITPOS              16U
#define UART_BITCON_OVERSAMPLING_BITPOS        16U
#define UART_IOCR_CTSEN_BITPOS                 29U
#define UART_IOCR_RCPOL_BITPOS                 25U
#define UART_BITCON_SM_BITPOS                  31U
#define UART_BITCON_SAMPLEPOINT_BITPOS         24U
#define UART_FRAMECON_PEN_BITPOS               30U
#define UART_FRAMECON_ODD_BITPOS               31U
#define UART_FRAMECON_IDLE_BITPOS              6U
#define UART_FRAMECON_STOP_BITPOS              9U
#define UART_TXFIFOCON_INW_BITPOS              6U
#define UART_RXFIFOCON_OUTW_BITPOS             6U
#define UART_RXFIFOCON_INTLEVEL_BITPOS         8U
#define UART_RXFIFOCON_ENI_BITPOS              1U
#define UART_FLAGSENABLE_PEE_BITPOS            16U
#define UART_FLAGSENABLE_FEE_BITPOS            18U
#define UART_FLAGSENABLE_RFLE_BITPOS           28U
#define UART_FLAGSENABLE_RFUE_BITPOS           27U    
#define UART_FLAGSCLEAR_PEC_BITPOS             16U
#define UART_FLAGSCLEAR_FEC_BITPOS             18U
#define UART_FLAGSCLEAR_RFLC_BITPOS            28U
#define UART_FLAGSCLEAR_RFUC_BITPOS            27U
#define UART_FLAGSCLEAR_TCC_BITPOS             17U
#define UART_FLAGSENABLE_TCE_BITPOS            17U
#define UART_TXFIFOCON_ENO_BITPOS              1U
#define UART_FLAGSENABLE_TFLE_BITPOS           31U
#define UART_FLAGSENABLE_TFOE_BITPOS           30U
#define UART_FLAGSCLEAR_TFLC_BITPOS            31U
#define UART_FLAGSCLEAR_TFOC_BITPOS            30U
#define UART_KRST0_RSTSTAT_BITPOS              1U
#define UART_CLC_DISS_BITPOS                   1U
#define UART_TXFIFOCON_FILL_BITPOS             16U
#define UART_FLAGS_PE_BITPOS                   16U
#define UART_FLAGS_FE_BITPOS                   18U
#define UART_FLAGS_TFO_BITPOS                  30U
#define UART_FLAGS_RFO_BITPOS                  26U
#define UART_FLAGSCLEAR_RFOC_BITPOS            26U
#define UART_FLAGS_RFU_BITPOS                  27U
#define UART_FLAGS_TC_BITPOS                   17U
#define UART_ISR_ACCESS                        0U
#define UART_INIT_ACCESS                       1U
#define UART_DEINIT_ACCESS                     2U
#define UART_RUNTIME_ACCESS                    3U

#if (UART_USER_MODE_INIT_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define UART_SFR_INIT_RESETENDINIT()           (UART_INIT_RESETENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define UART_SFR_INIT_SETENDINIT()             (UART_INIT_SETENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define UART_SFR_INIT_WRITE32(reg,value)       (UART_INIT_WRITE32(reg, value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define UART_SFR_INIT_MODIFY32(reg,clearmask,setmask)     \
                                    UART_INIT_MODIFY32(reg,clearmask,setmask)
#if (UART_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define UART_SFR_INIT_USER_MODE_READ32(reg)                 \
                                      (UART_INIT_USER_MODE_OS_API_READ32(reg))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
    modification of OS protected calls, so it cannot be expand to a braced
    initialiser*/
  #define UART_SFR_INIT_USER_MODE_MODIFY32(reg,clearmask,setmask) \
                   UART_INIT_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)
  #else
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define UART_SFR_INIT_USER_MODE_READ32(reg)                (reg)
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
    modification of OS protected calls, so it cannot be expand to a braced
    initialiser*/
  #define UART_SFR_INIT_USER_MODE_MODIFY32(reg, clearmask ,setmask) \
       { uint32 val ; (val) = (reg) ; (val) &= (clearmask); \
                                           (val) |= (setmask); (reg) = (val);}
#endif /* UART_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON  */
#else
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define UART_SFR_INIT_RESETENDINIT()                   (Mcal_ResetENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define UART_SFR_INIT_WRITE32(reg, value)              ((reg) = (value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define UART_SFR_INIT_MODIFY32(reg, clearmask,setmask) \
                        { uint32 val ; (val) = (reg) ; (val) &= (clearmask); \
                                           (val) |= (setmask); (reg) = (val);}
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define UART_SFR_INIT_SETENDINIT()                      (Mcal_SetENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define UART_SFR_INIT_USER_MODE_READ32(reg)             (reg)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define UART_SFR_INIT_USER_MODE_MODIFY32(reg, clearmask ,setmask)  \
     { uint32 val ; (val) = (reg) ; (val) &= (clearmask); \
                                           (val) |= (setmask); (reg) = (val);}
#endif /* UART_USER_MODE_INIT_API_ENABLE == STD_ON  */

#if (UART_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define UART_SFR_RUNTIME_MODIFY32(reg,clearmask,setmask)   \
                                 UART_RUNTIME_MODIFY32(reg,clearmask,setmask)
#if (UART_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
    /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
    calls definition, it is declared as a function like macro*/
    #define UART_SFR_RUNTIME_USER_MODE_WRITE32(reg, value) \
                             (UART_RUNTIME_USER_MODE_OS_API_WRITE32(reg, value))
    /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
    calls definition, it is declared as a function like macro*/
    #define UART_SFR_RUNTIME_USER_MODE_READ32(reg)        \
                                    (UART_RUNTIME_USER_MODE_OS_API_READ32(reg))
    /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
    calls definition, it is declared as a function like macro*/
    /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
    modification of OS protected calls, so it cannot be expand to a braced
    initialiser*/
    #define UART_SFR_RUNTIME_USER_MODE_MODIFY32(reg,clearmask,setmask) \
                UART_RUNTIME_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)
#else
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define UART_SFR_RUNTIME_USER_MODE_WRITE32(reg, value)    ((reg) = (value))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define UART_SFR_RUNTIME_USER_MODE_READ32(reg)                 (reg)
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
    modification of OS protected calls, so it cannot be expand to a braced
    initialiser*/
  #define UART_SFR_RUNTIME_USER_MODE_MODIFY32(reg, clearmask ,setmask) \
     { uint32 val ; (val) = (reg) ; (val) &= (clearmask); \
                                           (val) |= (setmask); (reg) = (val);}
#endif /* UART_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON  */
#else
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define UART_SFR_RUNTIME_MODIFY32(reg, clearmask,setmask) \
     { uint32 val ; (val) = (reg) ; (val) &= (clearmask); \
                                           (val) |= (setmask); (reg) = (val);}
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define UART_SFR_RUNTIME_USER_MODE_WRITE32(reg, value)     ((reg) = (value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define UART_SFR_RUNTIME_USER_MODE_READ32(reg)      (reg)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define UART_SFR_RUNTIME_USER_MODE_MODIFY32(reg, clearmask ,setmask)  \
    { uint32 val ; (val) = (reg) ; (val) &= (clearmask); \
                                           (val) |= (setmask); (reg) = (val);}
#endif /* UART_USER_MODE_RUNTIME_API_ENABLE = STD_ON */

#if (UART_USER_MODE_DEINIT_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define UART_SFR_DEINIT_RESETENDINIT()           (UART_DEINIT_RESETENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define UART_SFR_DEINIT_SETENDINIT()             (UART_DEINIT_SETENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define UART_SFR_DEINIT_WRITE32(reg,value)    (UART_DEINIT_WRITE32(reg, value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define UART_SFR_DEINIT_MODIFY32(reg,clearmask,setmask)     \
                                  UART_DEINIT_MODIFY32(reg,clearmask,setmask)
#if (UART_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
    /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
      calls definition, it is declared as a function like macro*/
    #define UART_SFR_DEINIT_USER_MODE_READ32(reg)            \
                                      (UART_DEINIT_USER_MODE_OS_API_READ32(reg))
    /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
      calls definition, it is declared as a function like macro*/
    /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
      modification of OS protected calls, so it cannot be expand to a braced
      initialiser*/
    #define UART_SFR_DEINIT_USER_MODE_MODIFY32(reg,clearmask,setmask)\
                  UART_DEINIT_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)
#else
    /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
      calls definition, it is declared as a function like macro*/
    #define UART_SFR_DEINIT_USER_MODE_READ32(reg)             (reg)
    /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
      calls definition, it is declared as a function like macro*/
    /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
      modification of OS protected calls, so it cannot be expand to a braced
      initialiser*/
    #define UART_SFR_DEINIT_USER_MODE_MODIFY32(reg, clearmask ,setmask) \
                 { uint32 val ; (val) = (reg) ; (val) &= (clearmask); \
                                           (val) |= (setmask); (reg) = (val);}
    #endif /* UART_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON  */
#else
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define UART_SFR_DEINIT_RESETENDINIT()            (Mcal_ResetENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define UART_SFR_DEINIT_WRITE32(reg, value)        ((reg) = (value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define UART_SFR_DEINIT_MODIFY32(reg,clearmask,setmask) \
                       { uint32 val ; (val) = (reg) ; (val) &= (clearmask); \
                                           (val) |= (setmask); (reg) = (val);}
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define UART_SFR_DEINIT_SETENDINIT()               (Mcal_SetENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
#define UART_SFR_DEINIT_USER_MODE_READ32(reg)              (reg)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define UART_SFR_DEINIT_USER_MODE_MODIFY32(reg, clearmask ,setmask)  \
                { uint32 val ; (val) = (reg) ; (val) &= (clearmask); \
                                         (val) |= (setmask); (reg) = (val);}
#endif  /* UART_USER_MODE_DEINIT_API_ENABLE == STD_ON  */

/* MISRA Rule Violation 19.7:Function-like macro defined.this can not be avoided
*/

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*
Type: Uart_MemPtrType
This type specifies the pointer to the data type of the buffer used by
the UART channels for Data reception/transmission. If all channels in the
config set have 7 Bit data or 8 Bit Data size, this will be uint8*
else if any Channel is 9 Bit data size, this will be uint16*
*/
#if (UART_NINEBITS_USED == STD_ON)
typedef uint16* Uart_MemPtrType;
typedef uint16 Uart_MemType;
#else
typedef uint8* Uart_MemPtrType;
typedef uint8 Uart_MemType;
#endif

/*
Type: Uart_SizeType
The Uart_SizeType specifies the number of data
bytes to be transmitted / received.
*/
typedef uint16 Uart_SizeType;

/*
Type: Uart_ChannelIdType
The Uart_ChannelIdType specifies the Datatype of the Logical Channel Ids
*/
typedef uint8 Uart_ChannelIdType;

/*
Type: Uart_ErrorIdType
This type definition specifies the error if they have occured
during the data transmission and reception on a particular Uart Channel
*/
typedef enum Uart_ErrorIdType
{
  UART_NO_ERR = 0,
  UART_PARITY_ERR,
  UART_FRAME_ERR,
  UART_TXOVERFLOW_ERR,
  UART_RXOVERFLOW_ERR,
  UART_RXUNDERFLOW_ERR
}Uart_ErrorIdType;

typedef void(*Uart_NotificationPtrType)(Uart_ErrorIdType ErrorId);

/*
Type: UartNotifType
This type definition contains the Call back function pointers
which would be called after completion of a particular Operation
*/
typedef struct UartNotifType
{
  Uart_NotificationPtrType UartTransmitNotifPtr;
  Uart_NotificationPtrType UartReceiveNotifPtr;
  Uart_NotificationPtrType UartAbortTransmitNotifPtr;
  Uart_NotificationPtrType UartAbortReceiveNotifPtr;
}UartNotifType;

/*
Type: Uart_ChannelType
This type definition holds complete
configuration data needed for a channel
*/
typedef struct Uart_ChannelType
{
   /* Structure Containing Call-back function pointers*/
   UartNotifType UartNotif;
   /* BRG.NUMERATOR value  */
   uint16 HwBrgNumerator;
   /* BRG.DENOMINATOR value  */
   uint16 HwBrgDenominator;
   /* BITCON.PRESCALAR value  */
   uint16 HwBitconPrescalar;
   /* BRG.NUMERATOR value  */
   uint8 HwBitconOversampling;
   /* Identifies the ASCLINx HW Unit*/
   uint8 HwModule;
   /* Number of stop Bits */
   uint8 StopBits;
   /* Number of Data Bits */
   uint8 DataLength;
   /* Alternate Receive pin selection*/
   uint8 RxPinSelection;
   /* Identifies the parity is enabled*/
   uint8 ParityEnable;
   /* Identifies the parity is even or odd*/
   uint8 Parity;
   /* Identifies the CTS is enabled*/
   uint8 CtsEnable;
   /* Identifies the RTS/CTS polarity if CTS is enabled*/
   uint8 CtsPolarity;
}Uart_ChannelType;

/*
Type: Uart_ConfigType
This type definition holds the Uart driver configuration data
*/
typedef struct Uart_ConfigType
{
  /* Pointer to Uart Channel Config */
  const Uart_ChannelType *ChannelConfigPtr;
  /* No of Uart channels Configured */
  uint8 NoOfChannels;
}Uart_ConfigType;

/*
Type: Uart_ReturnType
This type specifies whether a given API(read/write) was called without
any errors for a given channel or not or the channel was busy was with
some other(read/write) operation on the same channel
*/
typedef enum Uart_ReturnType
{
  UART_OK = 0,
  UART_NOT_OK,
  UART_IS_BUSY
}Uart_ReturnType;

/*
Type: Uart_StatusType
This type definition specifies the Status of the particular
channel at the time of request.
*/
typedef enum Uart_StatusType
{
  UART_IDLE = 0,
  UART_UNINIT,
  UART_BUSY
}Uart_StatusType;

/*
Type: Uart_StateType
The Uart StateType specifies the current state of the channel
in a particular operation(tx/rx)
(uninitialized or initialized or operation is in progress)
*/
typedef enum Uart_StateType
{
  UART_UNINITIALISED = 0,
  UART_INITIALISED,
  UART_OPERATION_IN_PROGRESS,
}Uart_StateType;

/*
Type: Uart_ChannelInfoType:
This type definition holds all the relevant/debug
information for a particular Uart Channel
*/
typedef struct Uart_ChannelInfoType
 {
   Uart_MemPtrType Uart_RxBuffPtr;
   Uart_MemPtrType Uart_TxBuffPtr;
   Uart_StateType Uart_TxState;
   Uart_StateType Uart_RxState;
   Uart_SizeType Uart_TxDataLeft;
   Uart_SizeType Uart_RxDataLeft;
   Uart_SizeType Uart_TotalDataTxd;
   Uart_SizeType Uart_TotalDataRxd;
   uint8 Uart_AssignedHW;
   uint8 Uart_TxDataCopyCntr;
 }Uart_ChannelInfoType;

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
#define UART_START_SEC_POSTBUILDCFG
#include "MemMap.h"

/* Declaration of Uart Post Build Configuration */
extern const Uart_ConfigType Uart_ConfigRoot[UART_CONFIG_COUNT];

#define UART_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*Memory Map of the UART Code*/
#define UART_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Syntax : void Uart_Init( const Uart_ConfigType* Config )                   **
**                                                                            **
** Service ID:  0x00                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  Config - Pointer to Uart driver configuration set       **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Driver Module Initialization function.                       **
** Service for UART initialization. The Initialization function shall         **
** initialize all common relevant registers of UART channels with the values  **
** of the structure referenced by the parameter ConfigPtr.                    **
*******************************************************************************/
extern void Uart_Init(const Uart_ConfigType* ConfigPtr);

/*******************************************************************************
** Syntax : void Uart_DeInit( void )                                          **
**                                                                            **
** Service ID:  0x01                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Driver Module DeInitialization function.                     **
** Service for UART de initialization. The DeInit function shall de initialize**
** all common relevant registers of UART channels                             **
*******************************************************************************/
#if (UART_DEINIT_API == STD_ON)
extern void Uart_DeInit(void);
#else
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to generate compile time
 error in case of incorrect configuration*/
#define Uart_DeInit(void)  (ERROR_Uart_DeInit_NOT_SELECTED)
#endif /* End of UART_DEINIT_API */

/*******************************************************************************
** Syntax : Std_ReturnType Uart_Read                                          **
**  (                                                                         **
**    Uart_ChannelIdType Channel,Uart_MemPtrType MemPtr,Uart_SizeType Size    **
**  )                                                                         **
**                                                                            **
** Service ID:  0x02                                                          **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  Reentrant(Not for same channel)                               **
**                                                                            **
** Parameters (in): Channel - Uart channel to be addressed .                  **
**                  MemPtr - Pointer to location where data needs to be stored**
**                  Size - No of data that needs to be recieved               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : UART_OK - Read operation was initiaited successfully     **
**                   UART_NOT_OK - Read operation couldn't be initiated       **
**                   due to developement errors                               **
**                   UART_IS_BUSY - Uart channel is busy with other           **
**                   read operation                                           **
**                                                                            **
** Description : Api to configure the given UART Channel for reception of the **
**       specified number of data bytes and the memory location (App Rx Buff) **
**        to be used to store the received data                               **
*******************************************************************************/
extern Uart_ReturnType Uart_Read \
  ( Uart_ChannelIdType Channel,Uart_MemPtrType MemPtr,Uart_SizeType Size);

/*******************************************************************************
** Syntax : Std_ReturnType Uart_Write                                         **
**  (                                                                         **
**    Uart_ChannelIdType Channel,Uart_MemPtrType MemPtr,Uart_SizeType Size    **
**  )                                                                         **
**                                                                            **
** Service ID:  0x03                                                          **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  Reentrant  (Not for the same channel)                         **
**                                                                            **
** Parameters (in): Channel - Uart channel to be addressed                    **
**                  MemPtr - Pointer to location where transmit data is stored**
**                  Size - No. of data bytes that needs to be transmitted     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : UART_OK - Write operation was initiaited successfully    **
**                   UART_NOT_OK - Write operation couldn't performed         **
**                                 due to developement error                  **
**                   UART_IS_BUSY - Uart channel is busy with other           **
**                                  write operation                           **
**                                                                            **
** Description : Api to transmit data from user memory location(App Buffer)   **
**               on to the given channel                                      **
**                                                                            **
*******************************************************************************/
extern Uart_ReturnType Uart_Write \
  ( Uart_ChannelIdType Channel,Uart_MemPtrType MemPtr,Uart_SizeType Size  );

/*******************************************************************************
** Syntax : Uart_SizeType Uart_AbortRead( Uart_ChannelIdType Channel )        **
**                                                                            **
** Service ID:  0x04                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant  (Not for the same channel)                         **
**                                                                            **
** Parameters (in): Channel - Uart channel to be addressed                    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value  : UartRetSize - Number of bytes that have been successfully  **
**                               recieved and stored to the memory location   **
**                               before the read operation was aborted        **
** Description : Api to Abort the read operation on the specified channel     **
**                                                                            **
*******************************************************************************/
#if (UART_ABORT_READ_API == STD_ON)
extern Uart_SizeType Uart_AbortRead(Uart_ChannelIdType Channel);
#else
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to generate compile time
 error in case of incorrect configuration*/
#define Uart_AbortRead(Channel)  (ERROR_Uart_AbortRead_NOT_SELECTED)
#endif /* End of UART_ABORT_READ_API */


/*******************************************************************************
** Syntax : Uart_SizeType Uart_AbortWrite( Uart_ChannelIdType channel )       **
**                                                                            **
** Service ID:  0x05                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant  (Not for the same channel)                         **
**                                                                            **
** Parameters (in): Channel - Uart channel to be addressed                    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value  : UartRetSize - Number of bytes that have been successfully  **
**                       transmitted before the write operation was aborted   **
**                                                                            **
** Description : Api to Abort Transmission of data on the specified channel   **
**                                                                            **
*******************************************************************************/
#if (UART_ABORT_WRITE_API == STD_ON)
extern Uart_SizeType Uart_AbortWrite(Uart_ChannelIdType Channel);
#else
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to generate compile time
 error in case of incorrect configuration*/
#define Uart_AbortWrite(Channel)  (ERROR_Uart_AbortWrite_NOT_SELECTED)
#endif /* End of UART_ABORT_WRITE_API */


/*******************************************************************************
** Syntax : Uart_StatusType Uart_GetStatus(Uart_ChannelIdType Channel)        **
**                                                                            **
** Service ID:      0x06                                                      **
**                                                                            **
** Sync/Async:      Synchronous                                               **
**                                                                            **
** Reentrancy:      Re-entrant                                                **
**                                                                            **
** Parameters (in): Channel    : Uart channel to be addressed                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:                                                              **
**                  UART_BUSY : Uart channel is busy with transmission        **
**                              or Reception operation                        **
**                  UART_IDLE : Uart channel is currently free to use         **
**                                                                            **
**                  UART_UNINIT: Uart channel is not uninitialised            **
**                                                                            **
** Description :    Indicates the current driver status for the UART channel  **
**                                                                            **
*******************************************************************************/
extern Uart_StatusType Uart_GetStatus(Uart_ChannelIdType Channel);

/*******************************************************************************
** Syntax :          void Uart_IsrReceive( uint8  HwUnit)                     **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Asynchronous                                             **
**                                                                            **
** Reentrancy:  Reentrant  (Not for the same HW Unit)                         **
**                                                                            **
** Parameters (in):  HwUnit : Represents ASCLIN hw module number              **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     This ISR will be called whenever  data                   **
**                   is completely received by the ASCLIN w/o any errors      **
*******************************************************************************/
extern void Uart_IsrReceive(uint8 HwUnit);

/*******************************************************************************
** Syntax :          void Uart_IsrTransmit( uint8  HwUnit)                    **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Asynchronous                                             **
**                                                                            **
** Reentrancy:  Reentrant  (Not for the same HW Unit)                         **
**                                                                            **
** Parameters (in):  HwUnit : Represents Hw Module number                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     This ISR will be called whenever the data                **
**                   is successfully transmitted by the ASCLIN w/o any errors **
**                                                                            **
*******************************************************************************/
extern void Uart_IsrTransmit(uint8 HwUnit);

/*******************************************************************************
** Syntax :          void Uart_IsrError( uint8  HwUnit)                       **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Asynchronous                                             **
**                                                                            **
** Reentrancy:  Reentrant  (Not for the same HW Unit)                         **
**                                                                            **
** Parameters (in):  HwUnit : Represents Hw Module number                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     This ISR will be called whenever there is an data        **
**                   transmission or reception error in ASCLIN                **
*******************************************************************************/
extern void Uart_IsrError(uint8 HwUnit);

/*******************************************************************************
** Traceability:[cover parentID=DS_NAS_UART_PR128,DS_NAS_UART_PR63_13]
**                                                                            **
** Syntax           : #define Uart_GetVersionInfo(VersionInfoPtr)             **
**                                                                            **
** Service ID       : 0x07                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : VersionInfoPtr - Pointer to store the                   **
**                    version information of this module                      **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description  : This service returns the version information of this module.**
**               The version information includes:                            **
**               - Module Id                                                  **
**               - Vendor Id                                                  **
**               - Instance Id                                                **
**               - Vendor specific version numbers                            **
*******************************************************************************/
#if ((UART_VERSION_INFO_API == STD_ON) && (UART_DEV_ERROR_DETECT == STD_ON))
/*IFX_MISRA_RULE_19_07_STATUS=GetVersionInfo is declared as a function like
macro as per AUTOSAR*/
/*IFX_MISRA_RULE_19_04_STATUS=GetVersionInfo cannot be expand to a braced
 initialiser*/
#define Uart_GetVersionInfo(VersionInfoPtr)                               \
{                                                                         \
  if ((VersionInfoPtr) == NULL_PTR)                                       \
  {                                                                       \
     /* Report to DET */                                                  \
    Det_ReportError(                                                      \
                     UART_MODULE_ID,                                      \
                     UART_MODULE_INSTANCE,                                \
                     UART_SID_VERINFO,                                    \
                     UART_E_PARAM_POINTER                                 \
                   );                                                     \
  }                                                                       \
  else                                                                    \
  {                                                                       \
  /* UART Module ID */                                                    \
  ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = UART_MODULE_ID;    \
  /* UART vendor ID */                                                    \
  ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = UART_VENDOR_ID;    \
  /* major version of UART */                                             \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =            \
                               (uint8)UART_SW_MAJOR_VERSION;              \
  /* minor version of UART */                                             \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =            \
                               (uint8)UART_SW_MINOR_VERSION;              \
  /* patch version of UART */                                             \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =            \
                               (uint8)UART_SW_PATCH_VERSION;              \
  }                                                                       \
}
#elif (UART_VERSION_INFO_API == STD_ON) && (UART_DEV_ERROR_DETECT == STD_OFF)
/*IFX_MISRA_RULE_19_07_STATUS=GetVersionInfo is declared as a function like
macro as per AUTOSAR*/
/*IFX_MISRA_RULE_19_04_STATUS=GetVersionInfo cannot be expand to a braced
 initialiser*/
#define Uart_GetVersionInfo(VersionInfoPtr)                               \
{                                                                         \
  /* Note that versioninfo pointer is not checked for NULL as the user is \
     supposed to send the memory allocated pointer */                     \
  /* UART Module ID */                                                    \
  ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = UART_MODULE_ID;    \
  /* UART vendor ID */                                                    \
  ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = UART_VENDOR_ID;    \
  /* major version of UART */                                             \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =            \
                               (uint8)UART_SW_MAJOR_VERSION;              \
  /* minor version of UART */                                             \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =            \
                               (uint8)UART_SW_MINOR_VERSION;              \
  /* patch version of UART */                                             \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =            \
                               (uint8)UART_SW_PATCH_VERSION;              \
}/* end of Uart_GetVersionInfo() */
#else
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to generate compile time
 error in case of incorrect configuration*/
#define Uart_GetVersionInfo(VersionInfo) \
           (ERROR_Uart_GetVersionInfo_NOT_SELECTED)
#endif
/*((UART_VERSION_INFO_API == STD_ON) && (UART_DEV_ERROR_DETECT == STD_ON))*/

#define UART_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif /* UART_H */


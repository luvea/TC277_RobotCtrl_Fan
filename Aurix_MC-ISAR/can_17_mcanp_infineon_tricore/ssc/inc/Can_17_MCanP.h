/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Can_17_MCanP.h $                                           **
**                                                                           **
**  $CC VERSION : \main\dev_tc23x_as4.0.3\25 $                               **
**                                                                           **
**  $DATE       : 2016-12-08 $                                               **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : This file exports                                         **
**                    - functionality of CAN driver                          **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: no                                      **
**                                                                           **
******************************************************************************/

/**  TRACEABILITY: [cover parentID=DS_NAS_CAN_PR734,
                   DS_AS403_CAN448,DS_AS_CAN037,DS_AS_CAN413,DS_AS403_CAN414,
                   DS_AS_CAN415,DS_AS_CAN416,DS_AS_CAN429,DS_AS_CAN417,
                   DS_AS_CAN039,DS_AS_CAN043_CAN284_CAN385,DS_AS_CAN080,
                   DS_AS_CAN104,DS_AS403_CAN224,DS_AS_CAN177,DS_AS_CAN105,
                   DS_AS_CAN251,DS_AS_CAN252,DS_AS403_CAN222,
                   DS_AS403_CAN366_CAN367,SAS_NAS_ALL_PR746,SAS_NAS_ALL_PR748,
                   SAS_NAS_ALL_PR630_PR631,SAS_AS_CAN034_CAN036_CAN078,
SAS_AS403_CAN388_CAN389_CAN390_CAN392_CAN393_CAN394_CAN406_CAN435_CAN436_CAN437_CAN438,
                   DS_NAS_CAN_PR3054] [/cover]            **/

#ifndef CAN_17_MCANP_H
#define CAN_17_MCANP_H

/******************************************************************************
**                      Include Section                                      **
******************************************************************************/

/* Include Communication Stack Types */
#include "ComStack_Types.h"

/* Include CAN driver configuratino header file */
#include "Can_17_MCanP_Cfg.h"

/* Includes all types and constants that are shared among the
   AUTOSAR CAN modules Can, CanIf and CanTrcv */
#include "Can_GeneralTypes.h"

/* MCAL header file containing global macros, type definitions and functions
needed by all MCAL drivers */
#include "Mcal.h"

/* Include Development Error Tracer header file */
/* This is needed for GetVersionInfo Macro */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

#if ((CAN_USER_MODE_INIT_API_ENABLE == STD_ON) || \
     (CAN_USER_MODE_RUNTIME_API_ENABLE == STD_ON) || \
     (CAN_USER_MODE_DEINIT_API_ENABLE == STD_ON) ||\
     (CAN_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON))
           #include "Can_17_MCanP_Protect.h"
#endif
/******************************************************************************
**                      Global Macro Definitions                             **
******************************************************************************/
/*
  Macros used in protected mode support.
*/

#define    CAN_SRC_CLEARMASK            0x7FFFFFFFU
#define CAN_CLC_DISR_CLEARMASK          0xFFFFFFFEU
#define CAN_NCR_INIT                    0x00000001U
#define CAN_CLC_EDIS_CLEARMASK          0xFFFFFFF7U
#define CAN_MCR_CLKSEL_CLEARMASK        0xFFFFFFF0U
#define CAN_KRST0_RST_CLEARMASK         0xFFFFFFFEU
#define CAN_KRST1_RST_CLEARMASK         0xFFFFFFFEU
#define CAN_CLC_DISS                    0x00000002U
#define CAN_KRSTCLR_CLR_CLEARMASK       0xFFFFFFFEU
#define CAN_PANCTR_BUSY                 0x00000100U
#define CAN_NCR_CLEARMASK               0xFFFFFFFFU
#define CAN_NCR_FDEN_CLEARMASK          0xFFFFFDFFU
#define CAN_IPR_ALINP_CLEARMASK         0xFFFFFFF0U
#define CAN_NECNT_EWRNLVL_CLEARMASK     0xFF00FFFFU
#define CAN_NCR_CCE_CLEARMASK           0xFFFFFFBFU
#define CAN_NCR_FDEN                    0x00000200U
#define CAN_MOFCR_BRS_CLEARMASK         0x0FFF0F5FU
#define CAN_MOFCR_MMC_CLEARMASK         0x0FFF0F70U
#define CAN_MOFGPR_BOT_CLEARMASK        0xFFFFFF00U
#define CAN_MOFGPR_TOP_CLEARMASK        0xFFFF00FFU
#define CAN_MOIPR_MPN_CLEARMASK         0xFFFF00FFU
#define CAN_MOIPR_TXINP_CLEARMASK       0xFFFFFF0FU
#define CAN_MOFCR_TXIE_CLEARMASK        0x0FF50F7FU
#define CAN_MOAR_PRI_CLEARMASK          0x3FFFFFFFU
#define CAN_MOFCR_FDF_CLEARMASK         0x0FF70F3FU
#define CAN_MOAMR_AM_CLEARMASK          0x20000000U
#define CAN_MOAMR_MIDE_CLEARMASK        0x1FFFFFFFU
#define CAN_MOIPR_RXINP_CLEARMASK       0xFFFFFFF0U
#define CAN_MOFCR_RXIE_CLEARMASK        0x0FF60F7FU
#define CAN_NCR_TXDIS_CLEARMASK         0xFFFFFFDFU
#define CAN_NCR_INIT_CLEARMASK          0xFFFFFFFEU
#define CAN_MSID_INDEX                  0x0000003FU
#define CAN_SRC_SRE                     0x00000400U
#define CAN_SRC_SRE_CLEARMASK           0x80000400U
#define CAN_MOAR_ID_CLEARMASK           0xE0000000U
#define CAN_MOFCR_DLC_CLEARMASK         0x00F70F7FU
#define CAN_MOFCR_MMC                   0x0000000FU
#define CAN_MOAR_IDE                    0x20000000U
#define CAN_MOAR_ID                     0x1FFFFFFFU
#define CAN_MOFGPR_SEL_CLEARMASK        0x00FFFFFFU
#define CAN_MOFCR_DLC                   0x0F000000U
#define CAN_PANCTR_PANAR2_CLEARMASK     0x00FFFFFFU
#define CAN_PANCTR_PANAR1_CLEARMASK     0xFF00FFFFU
#define CAN_PANCTR_PANCMD_CLEARMASK     0xFFFFFF00U
#define CAN_PANCTR_BUSY                 0x00000100U
#define CAN_CTR_CLEARMASK               0xFFFFFFFFU
#define CAN_CLC_EDIS_BITPOS             3U
#define CAN_CLC_DISS_BITPOS             1U
#define CAN_KRST0_RSTSTAT_BITPOS        1U
#define CAN_PANCTR_BUSY_BITPOS          8U
#define CAN_NCR_FDEN_BITPOS             9U
#define CAN_NECNT_EWRNLVL_BITPOS        16U
#define CAN_NCR_CCE_BITPOS              6U
#define CAN_MOFCR_BRS_BITPOS            5U
#define CAN_MOFGPR_TOP_BITPOS           8U
#define CAN_MOIPR_MPN_BITPOS            8U
#define CAN_MOIPR_TXINP_BITPOS          4U
#define CAN_MOFCR_TXIE_BITPOS           17U
#define CAN_MOAR_PRI_BITPOS             30U
#define CAN_MOFCR_FDF_BITPOS            6U
#define CAN_MOAMR_MIDE_BITPOS           29U
#define CAN_MOFCR_RXIE_BITPOS           16U
#define CAN_NCR_TXDIS_BITPOS            5U
#define CAN_SRC_SRE_BITPOS              10U
#define CAN_MOFCR_DLC_BITPOS            24U
#define CAN_MOAR_IDE_BITPOS             29U
#define CAN_MOFGPR_SEL_BITPOS           24U
#define CAN_PANCTR_PANAR2_BITPOS        24U
#define CAN_PANCTR_PANAR1_BITPOS        16U
#define CAN_PANCTR_BUSY_BITPOS          8U

#define CAN_RUNTIME_ACCESS              0x01U
#define CAN_ISR_ACCESS                  0x02U
#define CAN_INIT_ACCESS                0x03U
#define CAN_DEINIT_ACCESS              0x04U

#if (CAN_USER_MODE_INIT_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define CAN_SFR_INIT_RESETENDINIT()                 (CAN_INIT_RESETENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define CAN_SFR_INIT_SETENDINIT()                   (CAN_INIT_SETENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define CAN_SFR_INIT_WRITE32(reg,value)           (CAN_INIT_WRITE32(reg,value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define CAN_SFR_INIT_MODIFY32(reg,clearmask,setmask) \
                                       CAN_INIT_MODIFY32(reg,clearmask,setmask)
#if (CAN_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
    /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
    #define CAN_SFR_INIT_USER_MODE_WRITE32(reg,value) \
                                  (CAN_INIT_USER_MODE_OS_API_WRITE32(reg,value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
    #define CAN_SFR_INIT_USER_MODE_READ32(reg) \
                                        (CAN_INIT_USER_MODE_OS_API_READ32(reg))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
    #define CAN_SFR_INIT_USER_MODE_MODIFY32(reg,clearmask,setmask) \
                      CAN_INIT_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)
#else
    /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define CAN_SFR_INIT_USER_MODE_WRITE32(reg,value)         ((reg) = (value))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
    #define CAN_SFR_INIT_USER_MODE_READ32(reg)                 (reg)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
    #define CAN_SFR_INIT_USER_MODE_MODIFY32(reg,clearmask,setmask) \
  { uint32 val ; (val) = (reg); (val) &= (clearmask); (val) |= (setmask); \
                                                                (reg) = (val);}
#endif /* CAN_RUNNING_IN_USER_MODE_ENABLE == STD_ON  */
#else
    /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define CAN_SFR_INIT_RESETENDINIT()                   (Mcal_ResetENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define CAN_SFR_INIT_WRITE32(reg,value)              ((reg) = (value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define CAN_SFR_INIT_MODIFY32(reg,clearmask,setmask) \
    { uint32 val ; val = (reg) ; (val) &= (clearmask); (val) |= (setmask);\
                                                               (reg) = (val);}
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define CAN_SFR_INIT_SETENDINIT()                      (Mcal_SetENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define CAN_SFR_INIT_USER_MODE_WRITE32(reg,value)     ((reg) = (value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define CAN_SFR_INIT_USER_MODE_READ32(reg)             (reg)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define CAN_SFR_INIT_USER_MODE_MODIFY32(reg,clearmask,setmask)  \
{ uint32 val ;(val) = (uint32)(reg); (val) &= (clearmask); (val) |= (setmask); \
                                                                (reg) = (val);}
#endif /* CAN_USER_MODE_INIT_API_ENABLE == STD_ON  */

#if (CAN_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define CAN_SFR_RUNTIME_WRITE32(reg,value)      (CAN_RUNTIME_WRITE32(reg,value))
#define CAN_SFR_RUNTIME_READ32(reg)               (CAN_RUNTIME_READ32(reg))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define CAN_SFR_RUNTIME_MODIFY32(reg,clearmask,setmask)\
                                    CAN_RUNTIME_MODIFY32(reg,clearmask,setmask)
#if (CAN_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
    /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
      #define CAN_SFR_RUNTIME_USER_MODE_WRITE32(reg,value) \
                               (CAN_RUNTIME_USER_MODE_OS_API_WRITE32(reg,value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
      #define CAN_SFR_RUNTIME_USER_MODE_READ32(reg)  \
                               (CAN_RUNTIME_USER_MODE_OS_API_READ32(reg))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
      #define CAN_SFR_RUNTIME_USER_MODE_MODIFY32(reg,clearmask,setmask) \
                  CAN_RUNTIME_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)
#else
    /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define CAN_SFR_RUNTIME_USER_MODE_WRITE32(reg,value)      ((reg) = (value))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
    #define CAN_SFR_RUNTIME_USER_MODE_READ32(reg)               (reg)
    /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
    #define CAN_SFR_RUNTIME_USER_MODE_MODIFY32(reg,clearmask,setmask) \
      { uint32 val ; val = (reg) ; val &= (clearmask); val |= (setmask); \
                                                               (reg) = val;}
#endif /* CAN_RUNNING_IN_USER_MODE_ENABLE == STD_ON  */
#else
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define CAN_SFR_RUNTIME_WRITE32(reg,value)      ((reg) = (value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define CAN_SFR_RUNTIME_READ32(reg)              (reg)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define CAN_SFR_RUNTIME_MODIFY32(reg,clearmask,setmask) \
      { uint32 val ; val = (reg) ; val &= (clearmask); val |= (setmask); \
                                                                (reg) = val;}
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define CAN_SFR_RUNTIME_USER_MODE_WRITE32(reg,value)    ((reg) = (value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define CAN_SFR_RUNTIME_USER_MODE_READ32(reg)      (reg)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define CAN_SFR_RUNTIME_USER_MODE_MODIFY32(reg,clearmask,setmask)  \
     { uint32 val ; val = (reg) ; val &= (clearmask); val |= (setmask); \
                                                               (reg) = val;}
#endif /* CAN_USER_MODE_RUNTIME_API_ENABLE = STD_ON */

#if (CAN_USER_MODE_DEINIT_API_ENABLE == STD_ON)
    /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define CAN_SFR_DEINIT_RESETENDINIT()            (CAN_DEINIT_RESETENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define CAN_SFR_DEINIT_SETENDINIT()              (CAN_DEINIT_SETENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define CAN_SFR_DEINIT_WRITE32(reg,value)        (CAN_DEINIT_WRITE32(reg,value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define CAN_SFR_DEINIT_MODIFY32(reg,clearmask,setmask)  \
                                     CAN_DEINIT_MODIFY32(reg,clearmask,setmask)
#if (CAN_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
 #define CAN_SFR_DEINIT_USER_MODE_READ32(reg)  \
                                    (CAN_DEINIT_USER_MODE_OS_API_READ32(reg))
#else
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define CAN_SFR_DEINIT_USER_MODE_READ32(reg)             (reg)

#endif /* CAN_RUNNING_IN_USER_MODE_ENABLE == STD_ON  */

#else
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define CAN_SFR_DEINIT_RESETENDINIT()            (Mcal_ResetENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define CAN_SFR_DEINIT_WRITE32(reg,value)       ((reg) = (value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define CAN_SFR_DEINIT_MODIFY32(reg,clearmask,setmask) \
     { uint32 val ; val = (reg) ; val &= (clearmask); val |= (setmask); \
                                                               (reg) = val;}
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define CAN_SFR_DEINIT_SETENDINIT()               (Mcal_SetENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define CAN_SFR_DEINIT_USER_MODE_READ32(reg)            (reg)
#endif  /* CAN_USER_MODE_DEINIT_API_ENABLE == STD_ON  */

/*
  Published parameters
*/

/* CAN Vendor ID - Vendor ID of the dedicated implementation of this
module according to the AUTOSAR vendor list */
#define CAN_17_MCANP_VENDOR_ID                  ((uint16)17)
/* CAN Module ID - Module ID of this module from Module List */
#define CAN_17_MCANP_MODULE_ID                  ((uint16)80)

#if (CAN_DEV_ERROR_DETECT == STD_ON)

/* API Service called with wrong parameter: Config is a null pointer */
#define CAN_E_PARAM_POINTER    ((uint8)1)
/* API called with wrong parameter: Handle parameter is not a
   configured Hardware Transmit Handle */
#define CAN_E_PARAM_HANDLE     ((uint8)2)
/* API called with wrong parameter : Prameter Data length is
  more than 8 bytes   */
#define CAN_E_PARAM_DLC        ((uint8)3)
/* API called with wrong parameter : Parameter Controller is out of range  */
#define CAN_E_PARAM_CONTROLLER ((uint8)4)
/* API Service used without initialization */
#define CAN_E_UNINIT           ((uint8)5)
/* Invalid invalid transition requested OR Invalid CAN controller state for
   API service call */
#define CAN_E_TRANSITION       ((uint8)6)
/* DET for Over write error in receive ISR */
#define CAN_E_DATALOST         ((uint8)7)
/* API called with invalid value of Can_IdType w.r.t. configured CanIdType */
/* i.e., Can_IdType with MSB 1 for STANDARD HTH  */
/*   or  Can_IdType with MSB 0 for EXTENDED HTH  */
#define CAN_E_PARAM_MSGID      ((uint8)20)
/* API called with invalid / unsupported baudrate */
#define CAN_E_PARAM_BAUDRATE   ((uint8)8)
/* Invalid size of Can_IdType */
#define CAN_E_CAN_IDTYPE       ((uint8)21)

/* Service IDs. Used while reporting development errors */
#define CAN_SID_INIT                        ((uint8)0x00)
#define CAN_SID_MAINFUNCTION_WRITE          ((uint8)0x01)
#define CAN_SID_SETCONTROLLERMODE           ((uint8)0x03)
#define CAN_SID_DISABLECONTROLLERINTERRUPTS ((uint8)0x04)
#define CAN_SID_ENABLECONTROLLERINTERRUPTS  ((uint8)0x05)
#define CAN_SID_WRITE                       ((uint8)0x06)
#define CAN_SID_GETVERSIONINFO              ((uint8)0x07)
#define CAN_SID_MAINFUNCTION_READ           ((uint8)0x08)
#define CAN_SID_MAINFUNCTION_BUSOFF         ((uint8)0x09)
#define CAN_SID_MAINFUNCTION_WAKEUP         ((uint8)0x0a)
#define CAN_SID_CHECKWAKEUP                 ((uint8)0x0b)
#define CAN_SID_MAINFUNCTION_MODE           ((uint8)0x0c)
#define CAN_SID_CHANGE_BAUDRATE             ((uint8)0x0d)
#define CAN_SID_CHECK_BAUDRATE              ((uint8)0x0e)
#define CAN_SID_DEINIT                      ((uint8)0x0f)
#define CAN_SID_RECEIVEISR                  ((uint8)0x20)

#endif /* #if (CAN_DEV_ERROR_DETECT == STD_ON) */

/* Symbolic names for CAN controllers */
#define CAN_HWCONTROLLER0   (0U) /* CAN Node 0 */
#define CAN_HWCONTROLLER1   (1U) /* CAN Node 1 */
#define CAN_HWCONTROLLER2   (2U) /* CAN Node 2 */
#define CAN_HWCONTROLLER3   (3U) /* CAN Node 3 */
#define CAN_HWCONTROLLER4   (4U) /* CAN Node 4 */
#define CAN_HWCONTROLLER5   (5U) /* CAN Node 5 */



/* Identifier types of an L-PDU */
#define CAN_ID_STANDARD ((Can_FrameType)0)  /* Standard ID */
#define CAN_ID_EXTENDED ((Can_FrameType)1)  /* Extended ID */
#define CAN_ID_MIXED    ((Can_FrameType)2)  /* Both Standard and Extended ID */

/**** CAN controller event processing mechanism ****/

/* Events are notified in interrupt mode */
#define  CAN_INTERRUPT      (1U)
/* Events are notified in polling mode */
#define  CAN_POLLING        (2U)
/* Events are not processed */
#define  CAN_NO_PROCESSING  (3U)

/* to be deleted */
#define CAN_ENABLE_DEM_REPORT (1U)
#define CAN_DISABLE_DEM_REPORT (0U)

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/* Type for CAN Driver states */
typedef uint8 Can_17_MCanP_DriverStateType;

/* Type to reperesent identifier type of an L-PDU */
typedef uint8 Can_FrameType;

#if (CAN_LPDU_RX_CALLOUT == STD_ON)
/* Type for Receive L-PDU callout function */
typedef boolean (*Can_LPduRxCalloutFnPtrType)(uint8 Hrh,
                                              Can_IdType CanId,
                                              uint8 CanDlc,
                                              const uint8 *CanSduPtr);
#endif

#if (CAN_TX_HARDWARE_OBJECTS_MAX > 0U)
/* Data type for CAN Transmit Hardware object configuration */
typedef struct Can_TxHwObjectConfigType
{
  /* Hardware object Id */
  uint8 MsgObjId;

  #if (CAN_MULTIPLEXED_TRANSMISSION == STD_ON)

  /* Number of multiplexed message objects */
  uint8 MsgObjIdLast;
  #endif

  /* Controller to which this hardware object is assigned */
  uint8 HwControllerId;

  #if (CAN_STANDARD_ID_ONLY == STD_OFF)
  /* CAN Identifier type */
  Can_FrameType FrameType;
  #endif
} Can_TxHwObjectConfigType;
#endif

#if (CAN_RX_HARDWARE_OBJECTS_MAX > 0U)
/* Data type for CAN Receive Hardware object configuration */
typedef struct Can_RxHwObjectConfigType
{
  /* Filter mask */
  uint32 MaskRef;

  /* CAN Message Id */
  Can_IdType MsgId;

  /* Hardware object Id */
  uint8 MsgObjId;

  /* Controller to which this hardware object is assigned */
  uint8  HwControllerId;

  #if (CAN_STANDARD_ID_ONLY == STD_OFF)
  /* CAN Identifier type */
  Can_FrameType FrameType;
  #endif
} Can_RxHwObjectConfigType;
#endif

#if (CAN_NUM_RX_FIFO_MAX > 0U)
/* Data type for CAN Receive receive FIFO configuration */
typedef struct Can_RxFifoConfigType
{
  /* Filter mask */
  uint32 MaskRef;

  /* CAN Identifier value */
  Can_IdType MsgId;

  /* hardware object Id */
  uint16 HwObjectId;

  /* Controller to which this hardware object is assigned */
  uint8 HwControllerId;

  #if (CAN_STANDARD_ID_ONLY == STD_OFF)
  /* CAN Identifier type */
  Can_FrameType FrameType;
  #endif

  /* Size of the Rx FIFO  */
  uint8 RxFifoSize;

  /* Threshold of the Rx FIFO  */
  uint8 RxFifoThreshold;

} Can_RxFifoConfigType;
#endif

/* CAN Controller <-> CAN Hardware Object Mapping */
typedef struct Can_ControllerMOMapConfigType
{
  uint8 ControllerMOMap[4];
} Can_ControllerMOMapConfigType;

/* Data type for CAN_NPCR register setting value */
/* Includes RXSEL and LBM settings */
typedef struct Can_NPCRValueType
{
  uint16 Can_NPCRValue;
} Can_NPCRValueType;

/* CAN controller baudrate configuration type */
typedef struct Can_17_MCanP_ControllerBaudrateConfigType
{
  uint32 CanControllerBaudrate;
  uint16 CanControllerBaudrateCfg;
} Can_17_MCanP_ControllerBaudrateConfigType;


typedef struct Can_BaudrateConfigPtrType
{
  const Can_17_MCanP_ControllerBaudrateConfigType *Can_kBaudrateConfigPtr;
} Can_BaudrateConfigPtrType;

#if(CAN_FD_ENABLE == STD_ON)

/*CAN Controller FD Configuration Parameter type*/
typedef struct Can_FDConfigParamType
{
  uint16 CanControllerFDBaudrate;
  uint16 CanControllerTxDelayComp;
  uint8 CanControllerTxBRS;
} Can_FDConfigParamType;

typedef struct Can_FDConfigParamPtrType
{
  const Can_FDConfigParamType *Can_kFDConfigParamPtr;
} Can_FDConfigParamPtrType;

#endif



/* CAN controller baudrate configuration type */
typedef struct Can_EventHandlingType
{
  uint8 CanEventType[4];
} Can_EventHandlingType;


/* Type of CAN external data structure containing the overall
   initialization data for the CAN Driver and SFR settings affecting
   all controllers */

typedef struct Can_17_MCanP_ConfigType
{
  /* Pointer to Loopback and receive input pin selection setting */
  const Can_NPCRValueType *CanNpcrPtr;

  #if(CAN_WAKEUP_CONFIGURED == STD_ON)
  /* Pointer to Wakeup Source Id Configuration */
  const uint32 *CanWakeupSourceIdPtr;
  #endif

  /* Pointer to CAN Controller <-> Hardware Objects Mapping */
  const Can_ControllerMOMapConfigType *CanControllerMOMapConfigPtr;

  /* Pointer to CAN Controller Handling of Events : Interrupt/Polling */
  const Can_EventHandlingType *CanEventHandlingConfigPtr;

  /* Pointer to Controller Baudrate Configuration */
  const Can_BaudrateConfigPtrType *CanBaudrateConfigPtr;

  /* Pointer to default baudrate configuration */
  const Can_17_MCanP_ControllerBaudrateConfigType *CanDefaultBaudrateConfigPtr;

  #if(CAN_FD_ENABLE == STD_ON)
  /* Pointer to CAN Controller FD Configuration Parameters*/
  const Can_FDConfigParamPtrType *CanFDConfigParamPtr;
  #endif

  #if (CAN_LPDU_RX_CALLOUT == STD_ON)
  const Can_LPduRxCalloutFnPtrType Can_LPduRxCalloutFuncPtr;
  #endif

  #if (CAN_TX_HARDWARE_OBJECTS_MAX > 0U)
  /* Pointer to Configuration of transmit hardware objects */
  const Can_TxHwObjectConfigType *CanTxHwObjectConfigPtr;
  #endif

  #if (CAN_RX_HARDWARE_OBJECTS_MAX > 0U)
  /* Pointer to Configuration of receive hardware objects */
  const Can_RxHwObjectConfigType *CanRxHwObjectConfigPtr;
  #endif

  #if (CAN_NUM_RX_FIFO_MAX > 0U)
  /* Pointer to Configuration of receive FIFO objects */
  const Can_RxFifoConfigType *RxFifoConfigPtr;
  #endif

  #if (CAN_TX_OBJECT_KER0 > 0U)
  /* Pointer to Configuration of Hth Mapping */
  const uint8 *CanTxObjectHthKer0MapPtr;
  #endif

  #if (CAN_TX_OBJECT_KER1 > 0U)
  /* Pointer to Configuration of Hth Mapping */
  const uint8 *CanTxObjectHthKer1MapPtr;
  #endif

  #if (CAN_RX_OBJECT_KER0 > 0U)
  /* Pointer to Configuration of Hrh Mapping */
   const uint8 *CanRxObjectHrhKer0MapPtr;
  #endif


  #if (CAN_RX_OBJECT_KER1 > 0U)
  /* Pointer to Configuration of Hrh Mapping */
   const uint8 *CanRxObjectHrhKer1MapPtr;
  #endif

  /* CAN Module clock configuration : Fractional Divider Register setting */
  uint16 CanFdrSetting;

  /* Number of configured CAN Controllers */
  uint8 CanNumController;

  /* Mapping of configured CAN ControllerId to actual MultiCAN+ ControllerId */
  uint8 CanHwControllerIdMap[CAN_NUM_CONTROLLER_MAX];

  /* CAN Controller-wise number of baudrate configurations */
  uint8 CanNumBaudrateCfgs[CAN_NUM_CONTROLLER_MAX];

  #if (CAN_TX_HARDWARE_OBJECTS_MAX > 0U)
  /* Total number of Transmit Hardware Objects */
  uint16 CanNumTxHwObj;
  #endif

  #if (CAN_RX_HARDWARE_OBJECTS_MAX > 0U)
  /* Total number of Receive Hardware Objects */
  uint16 CanNumRxHwObj;
  #endif

  /* Number of Receive Rx MOs + Rx FIFO MOs */
  uint16 CanNumRxFifoMsgObj;

  #if (CAN_TX_HARDWARE_OBJECTS_MAX > 0U)
  /* Transmit Hardware Objects Offset Kernel wise */
  uint8 CanTxHwObjCntKer[CAN_NUM_KERNELS_IN_DEVICE];
  #endif

  #if (CAN_RX_HARDWARE_OBJECTS_MAX > 0U)
  /* Receive Hardware Objects Offset Kernel wise */
  uint8 CanRxHwObjCntKer[CAN_NUM_KERNELS_IN_DEVICE];
  #endif

  /* Number of Rx FIFO MOs Kernel wise*/
  uint8 CanFifoMsgObjCntKer[CAN_NUM_KERNELS_IN_DEVICE];

  #if ((CAN_RX_HARDWARE_OBJECTS_MAX > 0U)||(CAN_NUM_RX_FIFO_MAX > 0U))
  /* Last MSPND register to be scanned for Rx MOs */
  uint8 CanRxLastMspndIdx;
  #endif

  #if (CAN_TX_HARDWARE_OBJECTS_MAX > 0U)
  /* First MSPND register to be scanned for Tx MOs */
  uint8 CanTxFirstMspndIdx;

  /* Last MSPND register to be scanned for Tx MOs */
  uint8 CanTxLastMspndIdx;
  #endif

  #if (CAN_NUM_RX_FIFO_MAX > 0U)
  /* Number of Receive FIFOs configured */
  uint8 CanNumRxFifo;
  #endif

} Can_17_MCanP_ConfigType;


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define CAN_17_MCANP_START_SEC_POSTBUILDCFG
#include "MemMap.h"
/* Declaration of CAN driver Post Build Configuration */
extern const Can_17_MCanP_ConfigType Can_17_MCanP_ConfigRoot[CAN_CONFIG_COUNT];
#define CAN_17_MCANP_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#define CAN_17_MCANP_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Syntax           : void Can_17_MCanP_Init(const Can_17_MCanP_ConfigType*   **
*                                                  Config)                    **
**                                                                            **
** Service ID       : 0x00                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : Config - Pointer to CAN driver configuration            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Driver Module Initialization function                   **
**                    - This function initializes:                            **
**                    * Static variables, including flags                     **
**                    * CAN HW Unit global hardware settings                  **
**                    * Controller specific settings for each CAN Controller  **
**  All CAN Controllers will be in state CAN_CS_STOPPED after initialization  **
**                                                                            **
*******************************************************************************/
extern void Can_17_MCanP_Init
(
  const Can_17_MCanP_ConfigType* Config
);
/*******************************************************************************
** Syntax         : void Can_17_MCanP_DeInit(void)                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x0f                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function De-initializes the CAN Driver.           **
**                                                                            **
*******************************************************************************/
extern void Can_17_MCanP_DeInit (void);



#if (CAN_CHANGE_BAUDRATE_API == STD_ON)
/*******************************************************************************
** Syntax           : Std_ReturnType Can_17_MCanP_CheckBaudrate               **
**                          (                                                 **
**                            uint8 Controller,                               **
**                            const uint16 Baudrate                           **
**                          )                                                 **
**                                                                            **
** Service ID       : 0x0e                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Controller - Associated CAN Controller                  **
**                    Baudrate -  Baudrate to be checked                      **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Std_ReturnType                                          **
**                    - E_OK: Baudrate is supported by the CAN Controller     **
**                    - E_NOT_OK: Baudrate is not supported / invalid CAN     **
**                                controller                                  **
**                                                                            **
** Description      : Checks CAN Controller Baudrate                          **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Can_17_MCanP_CheckBaudrate
(
  uint8 Controller,
  const uint16 Baudrate
);
#else
/*IFX_MISRA_RULE_19_04_STATUS=Function like macro used generate
compile time error in case of incorrect configuration*/
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used generate
compile time error in case of incorrect configuration*/
#define Can_17_MCanP_CheckBaudrate(Controller,Baudrate)  \
        ERROR_CanChangeBaudrateApi_NOT_SELECTED
#endif /* #if (CAN_CHANGE_BAUDRATE_API == STD_ON) */

#if (CAN_CHANGE_BAUDRATE_API == STD_ON)
/*******************************************************************************
** Syntax           : Std_ReturnType Can_17_MCanP_ChangeBaudrate              **
**                          (                                                 **
**                            uint8 Controller,                               **
**                            const uint16 Baudrate                           **
**                          )                                                 **
**                                                                            **
** Service ID       : 0x0d                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : Controller - Associated CAN Controller                  **
**                    Baudrate -  Baudrate to be checked                      **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Std_ReturnType                                          **
**                    - E_OK: Baudrate change accepted                        **
**                    - E_NOT_OK: Baudrate is not accepted                    **
**                                                                            **
** Description      : Changes the CAN Controller Baudrate                     **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Can_17_MCanP_ChangeBaudrate
(
  uint8 Controller,
  const uint16 Baudrate
);
#else
/*IFX_MISRA_RULE_19_04_STATUS=Function like macro used generate
compile time error in case of incorrect configuration*/
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used generate
compile time error in case of incorrect configuration*/
#define Can_17_MCanP_ChangeBaudrate(Controller,Baudrate)  \
        ERROR_CanChangeBaudrateApi_NOT_SELECTED
#endif /* #if (CAN_CHANGE_BAUDRATE_API == STD_ON) */

/*******************************************************************************
** Syntax           : Can_ReturnType Can_17_MCanP_SetControllerMode           **
**                                   (                                        **
**                                     uint8 Controller,                      **
**                                     Can_StateTransitionType Transition     **
**                                   )                                        **
**                                                                            **
** Service ID       : 0x03                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : Controller - Associated CAN Controller                  **
**                    Transition - Requested transition                       **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : CAN_OK - Valid transition                               **
**                    CAN_NOT_OK - Invalid transition                         **
**                                                                            **
** Description      : Performs software triggered state transitions of the    **
**                    CAN Controller State machine                            **
**                                                                            **
*******************************************************************************/
extern Can_ReturnType Can_17_MCanP_SetControllerMode
(
  uint8 Controller,
  Can_StateTransitionType Transition
);

/*******************************************************************************
** Syntax         : void Can_17_MCanP_DisableControllerInterrupts             **
**                                                         (uint8 Controller) **
**                                                                            **
** Service ID       : 0x04                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Controller - Associated CAN Controller                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Disables CAN Controller Interrupts                      **
**                                                                            **
*******************************************************************************/
extern void Can_17_MCanP_DisableControllerInterrupts
(
  uint8 Controller
);

/*******************************************************************************
** Syntax          : void Can_17_MCanP_EnableControllerInterrupts             **
**                                                         (uint8 Controller) **
**                                                                            **
** Service ID       : 0x05                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Controller - Associated CAN Controller                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Enables CAN Controller Interrupts                       **
**                                                                            **
*******************************************************************************/
extern void Can_17_MCanP_EnableControllerInterrupts
(
  uint8 Controller
);

/*******************************************************************************
** Syntax           : Can_ReturnType Can_17_MCanP_Write                       **
**                                            (                               **
**                                              Can_HwHandleType Hth,         **
**                                              const Can_PduType *PduInfo    **
**                                            )                               **
**                                                                            **
** Service ID       : 0x06                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant(thread-safe)                                  **
**                                                                            **
** Parameters (in)  : Hth - Hardware Transmit Handler                         **
**                    PduInfo - Pointer to SDU user memory, DLC and Identifier**
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : CAN_OK - Write command has been accepted                **
**                    CAN_BUSY - No message object available or pre-emptive   **
**                               call of Can_17_MCanP_Write that can't be     **
**                               implemented re-entrant                       **
**                    CAN_NOT_OK - development error occured                  **
**                                                                            **
** Description      : Service to transmit CAN frame                           **
**                                                                            **
*******************************************************************************/
extern Can_ReturnType Can_17_MCanP_Write
(
  Can_HwHandleType Hth,
  const Can_PduType* PduInfo
);

/*******************************************************************************
** Syntax           : void Can_17_MCanP_MainFunction_Write(void)              **
**                                                                            **
** Service ID       : 0x01                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Timing           : Variable Cyclic                                         **
**                                                                            **
** Description      : This function performs the polling of TX confirmation   **
**                    when CAN_TX_PROCESSING is set to POLLING                **
**                                                                            **
*******************************************************************************/
extern void Can_17_MCanP_MainFunction_Write
(
  void
);

/*******************************************************************************
** Syntax           : void Can_17_MCanP_MainFunction_Read(void)               **
**                                                                            **
** Service ID       : 0x08                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Timing           : Variable Cyclic                                         **
**                                                                            **
** Description      : This function performs the polling of RX indication     **
**                    when CAN_RX_PROCESSING is set to POLLING                **
**                                                                            **
*******************************************************************************/
extern void Can_17_MCanP_MainFunction_Read
(
  void
);

/*******************************************************************************
** Syntax           : void Can_17_MCanP_MainFunction_BusOff(void)             **
**                                                                            **
** Service ID       : 0x09                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Timing           : Variable Cyclic                                         **
**                                                                            **
** Description      : This function performs the polling of bus-off events    **
**                    that are configured statically as 'to be polled'        **
**                                                                            **
*******************************************************************************/
extern void Can_17_MCanP_MainFunction_BusOff
(
  void
);

/*******************************************************************************
** Syntax           : void Can_17_MCanP_MainFunction_Wakeup(void)             **
**                                                                            **
** Service ID       : 0x0A                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Timing           : Variable Cyclic                                         **
**                                                                            **
** Description      : This function performs the polling of wake-up events    **
**                    that are configured statically as 'to be polled'        **
**                                                                            **
*******************************************************************************/
extern void Can_17_MCanP_MainFunction_Wakeup
(
  void
);

/*******************************************************************************
** Syntax           : void Can_17_MCanP_MainFunction_Mode(void)               **
**                                                                            **
** Service ID       : 0x0C                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Timing           : Variable Cyclic                                         **
**                                                                            **
** Description      : This function performs the polling of CAN Controller    **
**                    mode transitions                                        **
**                                                                            **
*******************************************************************************/
extern void Can_17_MCanP_MainFunction_Mode
(
  void
);

/*******************************************************************************
** Syntax           : Can_ReturnType Can_17_MCanP_CheckWakeup                 **
**                                                         (uint8 Controller) **
**                                                                            **
** Service ID       : 0x0B                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : Controller - Associated CAN Controller                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : CAN_OK - Wakeup was detected for the given controller   **
**                    CAN_NOT_OK - No wakeup was detected for the given       **
**                                 CAN Controller                             **
**                                                                            **
** Description      : This function checks if a wakeup has occurred for the   **
**                    given CAN Controller                                    **
**                                                                            **
*******************************************************************************/
extern Can_ReturnType Can_17_MCanP_CheckWakeup
(
  uint8 Controller
);

/*******************************************************************************
**                      Interrupt Service Routines                            **
*******************************************************************************/

/*******************************************************************************
** Syntax           : void Can_17_MCanP_IsrBusOffHandler(uint8 HwControllerId)**
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : HwControllerId - Associated CAN Controller              **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : - This function is the core part of the interrupt       **
**                    service routine for handling and reporting bus-off event**
**                    - This function is also called by the polling function  **
**                    Can_17_MCanP_MainFunction_BusOff for controllers        **
**                    configured with CanBusoffProcessing as POLLING          **
**                                                                            **
*******************************************************************************/
extern void Can_17_MCanP_IsrBusOffHandler(uint8 HwControllerId);

/*******************************************************************************
** Syntax           : void Can_17_MCanP_IsrBusOffRuntime\                     **
**                                                      (uint8 HwControllerId)**
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : HwControllerId - Associated CAN Controller              **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : - This function is the core part of the interrupt       **
**                    service routine for handling and reporting bus-off event**
**                    - This function is also called by the polling function  **
**                    Can_17_MCanP_MainFunction_BusOff for controllers        **
**                    configured with CanBusoffProcessing as POLLING          **
**                                                                            **
*******************************************************************************/
extern void Can_17_MCanP_IsrBusOffRuntime(uint8 HwControllerId);

/*******************************************************************************
** Syntax           : void Can_17_MCanP_IsrReceiveHandler                     **
**                                                     (uint8 HwControllerId) **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : HwControllerId - Associated CAN Controller              **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : - This is the interrupt service routine for Receive     **
**                    Interrupt                                               **
**                    - This function checks the CAN Controller status and    **
**                    calls appropriate handler function                      **
**                                                                            **
*******************************************************************************/
extern void Can_17_MCanP_IsrReceiveHandler(uint8 HwControllerId);

/*******************************************************************************
** Syntax           : void Can_17_MCanP_IsrTransmitHandler                    **
**                                                     (uint8 HwControllerId) **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : HwControllerId - Associated CAN Controller              **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : - This is the interrupt service routine for Transmit    **
**                    Interrupt                                               **
**                    - In case of successful transmission event, this        **
**                    funciton notifies the upper layer                       **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
*******************************************************************************/
extern void Can_17_MCanP_IsrTransmitHandler(uint8 HwControllerId);

/*******************************************************************************
** Syntax           : void Can_17_MCanP_IsrTransmitRuntime                    **
**                                                     (uint8 HwControllerId) **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : HwControllerId - Associated CAN Controller              **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      :   This function is also called by the polling function  **
**                      Can_17_MCanP_MainFunction_Write for controllers       **
**                      configured with CanTxProcessing as POLLING            **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
*******************************************************************************/
extern void Can_17_MCanP_IsrTransmitRuntime(uint8 HwControllerId);

#define CAN_17_MCANP_STOP_SEC_CODE
#include "MemMap.h"

#if ( (CAN_VERSION_INFO_API == STD_ON) && (CAN_DEV_ERROR_DETECT == STD_ON) )
/*******************************************************************************
** Syntax           : void  Can_17_MCanP_GetVersionInfo                       **
**                    (                                                       **
**                      Std_VersionInfoType *versioninfo                      **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x07                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : versioninfo - Pointer to store the                      **
**                    version information of this module.                     **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      :                                                         **
**   - This function returns the version information of this module           **
**     The version information include : Module ID, Vendor ID,                **
**     Vendor specific version numbers                                        **
**   - This function is available if the CAN_VERSION_INFO_API is STD_ON       **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_19_04_STATUS=GetVersionInfo cannot be expanded to a
braced initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=GetVersionInfo is declared as
function like macro as per AUTOSAR.*/
#define Can_17_MCanP_GetVersionInfo(versioninfo)                               \
{                                                                              \
  /* Check for DET: CAN_E_PARAM_POINTER */                                     \
  if (NULL_PTR == (versioninfo))                                               \
  {                                                                            \
    /* Report CAN_E_PARAM_POINTER DET if service called with                   \
       NULL_PTR                                                                \
    */                                                                         \
    Det_ReportError(                                                           \
                     CAN_17_MCANP_MODULE_ID,                                   \
                     CAN_17_MCANP_INSTANCE_ID,                                 \
                     CAN_SID_GETVERSIONINFO,                                   \
                     CAN_E_PARAM_POINTER                                       \
                   );                                                          \
  }                                                                            \
  else                                                                         \
  {                                                                            \
    /* Vendor ID information */                                                \
    ((Std_VersionInfoType*)(versioninfo))->vendorID = CAN_17_MCANP_VENDOR_ID;  \
    /* Can module ID information */                                            \
    ((Std_VersionInfoType*)(versioninfo))->moduleID = CAN_17_MCANP_MODULE_ID;  \
    /* Can module Software major version information */                        \
    ((Std_VersionInfoType*)(versioninfo))->sw_major_version =                  \
                                       (uint8)CAN_17_MCANP_SW_MAJOR_VERSION;   \
    /* Can module Software minor version information */                        \
    ((Std_VersionInfoType*)(versioninfo))->sw_minor_version =                  \
                                       (uint8)CAN_17_MCANP_SW_MINOR_VERSION;   \
    /* Can module Software patch version information */                        \
    ((Std_VersionInfoType*)(versioninfo))->sw_patch_version =                  \
                                       (uint8)CAN_17_MCANP_SW_PATCH_VERSION;   \
  }                                                                            \
}
#elif((CAN_VERSION_INFO_API == STD_ON) && (CAN_DEV_ERROR_DETECT == STD_OFF))
/*IFX_MISRA_RULE_19_04_STATUS=GetVersionInfo cannot be expanded to a
braced initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=GetVersionInfo is declared as
function like macro as per AUTOSAR.*/
#define Can_17_MCanP_GetVersionInfo(versioninfo)                               \
{                                                                              \
  /* Vendor ID information */                                                  \
  ((Std_VersionInfoType*)(versioninfo))->vendorID = CAN_17_MCANP_VENDOR_ID;    \
  /* Can module ID information */                                              \
  ((Std_VersionInfoType*)(versioninfo))->moduleID = CAN_17_MCANP_MODULE_ID;    \
  /* Can module Software major version information */                          \
  ((Std_VersionInfoType*)(versioninfo))->sw_major_version =                    \
                                     (uint8)CAN_17_MCANP_SW_MAJOR_VERSION;     \
  /* Can module Software minor version information */                          \
  ((Std_VersionInfoType*)(versioninfo))->sw_minor_version =                    \
                                     (uint8)CAN_17_MCANP_SW_MINOR_VERSION;     \
  /* Can module Software patch version information */                          \
  ((Std_VersionInfoType*)(versioninfo))->sw_patch_version =                    \
                                     (uint8)CAN_17_MCANP_SW_PATCH_VERSION;     \
}/* Can_GetVersionInfo */
#else /*(CAN_VERSION_INFO_API == STD_OFF)&&(CAN_DEV_ERROR_DETECT == STD_OFF)*/
/*IFX_MISRA_RULE_19_04_STATUS=Function like macro used generate
compile time error in case of incorrect configuration*/
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used generate
compile time error in case of incorrect configuration*/
#define Can_17_MCanP_GetVersionInfo(versioninfo)                               \
  ERROR_CanVersionInfoApi_NOT_SELECTED
#endif /* (CAN_VERSION_INFO_API) */

#endif /* #ifndef CAN_17_MCANP_H */

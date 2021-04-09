/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2016)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Can_17_MCanP_Platform.h $                                  **
**                                                                           **
**  $CC VERSION : \main\10 $                                                 **
**                                                                           **
**  $DATE       : 2016-12-02 $                                               **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : This file contains                                        **
**                - CAN driver API implementation                            **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
#ifndef CAN_17_MCANP_PLATFORM_H
#define CAN_17_MCANP_PLATFORM_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Can_17_MCanP.h"


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

#define CAN_17_MCANP_START_SEC_CONST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"

#ifdef CAN_MOD_R_AVAILABLE
#if (CAN_NUM_CONTROLLERS_IN_KERNEL1 == 3U )
/* CAN base address Kernel wise */
extern Ifx_CAN* const CAN_KER[2];
#else
/* CAN base address Kernel wise */
extern Ifx_CAN* const CAN_KER[2];
#endif
#else
/* CAN base address Kernel wise */
extern Ifx_CAN* const CAN_KER[1];
#endif

#define CAN_17_MCANP_STOP_SEC_CONST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"

#define  CAN_CR_INIT_CLEARMASK                     (0xFFFFFFFEU)
#define  CAN_CR_CCE_CLEARMASK                      (0xFFFFFFFFU)
#define  CAN_CR_CCE_SETMASK                        (0x00000040U)
#define  CAN_BTR_EXCPT_DIV8_CLEARMASK              (0x00008000U)
#define  CAN_BTR_DIV8_CLEARMASK                    (0xFFFF7FFFU)
#define  CAN_BTR_DIV8_SHIFT                        (15U)

/*
27xCA:
There is only 1 Kernel containing 4 controllers.Hence 4 controllers belong
to Kernel 0

TC26x:
There is only 1 Kernel containing 5 controllers.Hence 5 controllers belong
to Kernel 0

29x:
There are 2 Kernels containing 4 controllers in one and 2 controllers in
the other. First 4 Controllers belong to Kernel 0 and the next 2
controllers belong to Kernel 1

23x:
There are 2 Kernels containing 3 controllers in one and 3 controllers in
the other. First 3 Controllers belong to Kernel 0 and the next 3
controllers belong to Kernel 1

22x, 21x:
There is only 1 Kernel containing 3 controllers.Hence 3 controllers belong
to Kernel 0
*/

#if (CAN_NUM_CONTROLLERS_IN_KERNEL1 == 3U )
/* EP Device */
#define CAN_HEDEVICE                   (0U)
/* Following Macro calculates (x/3) only for x = {0,1,2,3,4,5} */
/*IFX_MISRA_RULE_19_07_STATUS=Function-like macro is used to have a
generic code across devices*/
#define CAN_CALC_KERIDX(x)           ((uint8)(((x)* 3U)>> 3U))
/* Following Macro calculates (x%3) only for x = {0,1,2,3,4,5} */
/*IFX_MISRA_RULE_19_07_STATUS=Function-like macro is used to have a
generic code across devices*/
#define CAN_CALC_HWCTRLID(x)       ((uint8)((x)- ((((x)* 3U)>> 3U)*3U)))
#endif

#if (CAN_NUM_CONTROLLERS_IN_KERNEL1 == 4U )
/* HE Device */
#define CAN_HEDEVICE                   (1U)
/* Following Macro calculates (x/4) */
/*IFX_MISRA_RULE_19_07_STATUS=Function-like macro is used to have a
generic code across devices*/
#define CAN_CALC_KERIDX(x)          ((uint8)((x)>> 2U))
/* Following Macro calculates (x%4) */
/*IFX_MISRA_RULE_19_07_STATUS=Function-like macro is used to have a
generic code across devices*/
#define CAN_CALC_HWCTRLID(x)       ((uint8)(((x))& 3U))
#endif

#if (CAN_NUM_CONTROLLERS_IN_KERNEL1 == 5U )
/* HE Device */
#define CAN_HEDEVICE                   (1U)
/* Following Macro calculates (x/5) only for x = {0,1,2,3,4} */
/*IFX_MISRA_RULE_19_07_STATUS=Function-like macro is used to have a
generic code across devices*/
#define CAN_CALC_KERIDX(x)           ((uint8)(((x)* 7U)>> 5U))
/* Following Macro calculates (x%5) only for x = {0,1,2,3,4} */
/*IFX_MISRA_RULE_19_07_STATUS=Function-like macro is used to have a
generic code across devices*/
#define CAN_CALC_HWCTRLID(x)       ((uint8)((x)- ((((x)* 7U)>> 5U)*5U)))
#endif

/*******************************************************************************
**                      Global Function Declaration                           **
*******************************************************************************/
/* Memory map of the CAN driver code */
#define CAN_17_MCANP_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"
extern void Can_lFrameInitialise(uint8 KerIdx,uint8 HwCtrlIDKer,\
                uint16 CanControllerFDBaudrate,uint16 CanControllerTxDelayComp);
/* Function to set CAN controller baudrate */
extern void Can_lSetBaudrate(uint8 HwControllerId,
                             uint32 ControllerBaudrate,uint8 ApiAccesId );

extern uint8 Can_lGetHthIndex(uint8 KerIdx,uint8 HthIdx);
extern uint8 Can_lGetHrhIndex(uint8 KerIdx,uint8 HrhOffset);

#define CAN_17_MCANP_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"

#endif
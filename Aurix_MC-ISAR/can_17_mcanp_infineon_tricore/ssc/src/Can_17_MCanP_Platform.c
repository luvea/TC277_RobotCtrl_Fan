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
**  $FILENAME   : Can_17_MCanP_Platform.c $                                  **
**                                                                           **
**  $CC VERSION : \main\dev_tc29xbc_as4.0.3\dev_tc29xbc_as4.0.3_kernel0\3 $  **
**                                                                           **
**  $DATE       : 2017-02-04 $                                               **
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
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Register definition file for Aurix target */
#include "IfxCan_reg.h"
#include "IfxSrc_reg.h"
/*for proctected mode support macros */
#include "Can_17_MCanP.h"
/*including header file for Can_17_MCanP_Platform.c*/
#include "Can_17_MCanP_Platform.h"


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define CAN_ONE                         (1U)
#define CAN_ZERO                        (0U)
#define CAN_17_MCANP_START_SEC_CONST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"

#ifdef CAN_MOD_R_AVAILABLE
#if (CAN_NUM_CONTROLLERS_IN_KERNEL1 == 3U )
/* CAN base address Kernel wise */
Ifx_CAN* const CAN_KER[] = { &MODULE_CAN, &MODULE_CAN1 };
#else
/* CAN base address Kernel wise */
Ifx_CAN* const CAN_KER[] = { &MODULE_CAN, &MODULE_CANR };
#endif
#else
/* CAN base address Kernel wise */
Ifx_CAN* const CAN_KER[] = { &MODULE_CAN };
#endif

#if(CAN_PB_FIXEDADDR == STD_ON)
/* The config pointer is initialised to first instance of configuration */
extern const Can_17_MCanP_ConfigType* const Can_kConfigPtr;
#endif

#define CAN_17_MCANP_STOP_SEC_CONST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"

#define CAN_17_MCANP_START_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"

#if(CAN_PB_FIXEDADDR == STD_OFF)
/* Pointer to store config pointer */
extern const Can_17_MCanP_ConfigType* Can_kConfigPtr;
#endif

#define CAN_17_MCANP_STOP_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"

/* Memory map of the CAN driver code */
#define CAN_17_MCANP_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"

static void Can_lSetBaudrateRuntime(uint8 HwControllerId,\
                                                   uint32 ControllerBaudrate);

#define CAN_17_MCANP_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/* Memory map of the CAN driver code */
#define CAN_17_MCANP_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"
/*******************************************************************************
** Syntax           :                  void Can_lFrameInitialise              **
**                                           (                                **
**                                             uint8 KerIdx,                  **
**                                             uint8 HwCtrlIDKer              **
**                                             uint16 CanControllerFDBaudrate **
**                                             uint16 CanControllerTxDelayComp**
**                                           )                                **
**                                                                            **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : KerIdx - Associated CAN Kernal Id                       **
**                    HwCtrlIDKer - Associated CAN Hardwarecontroller ID      **
**                    CanControllerFDBaudrate                                 **
**                      CanControllerTxDelayComp                              **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      :  this api is for FD frame ISO support                   **
**                                                                            **
*******************************************************************************/
void Can_lFrameInitialise(uint8 KerIdx,uint8 HwCtrlIDKer,\
                 uint16 CanControllerFDBaudrate,uint16 CanControllerTxDelayComp)
{
    volatile uint8 KerIndex = CAN_ZERO;

    CAN_SFR_INIT_USER_MODE_MODIFY32(CAN_KER[KerIdx]->N[HwCtrlIDKer].CR.U,\
                  CAN_NCR_FDEN_CLEARMASK,(uint32)CAN_ONE << CAN_NCR_FDEN_BITPOS)

    #if(CAN_HARDWARE_ISO_SUPPORT == STD_ON)
    /*Depending on the configuration enable or disable the support of ISO frame
    and protocol exception feature */

    while(KerIndex < CAN_ISO_NUM_KERNEL)
    {
        CAN_SFR_INIT_USER_MODE_MODIFY32(CAN_KER[KerIndex]->N[CAN_ZERO].CR.U,\
                                      CAN_CR_CCE_CLEARMASK,CAN_CR_CCE_SETMASK)
        CAN_SFR_INIT_USER_MODE_MODIFY32(CAN_KER[KerIndex]->N[CAN_ZERO].BTR.U,\
             CAN_BTR_DIV8_CLEARMASK,(uint32)CAN_ISO_FRAME<<CAN_BTR_DIV8_SHIFT)
        CAN_SFR_INIT_USER_MODE_MODIFY32(CAN_KER[KerIndex]->N[CAN_ZERO].CR.U,\
                                       CAN_NCR_CCE_CLEARMASK,(uint32)CAN_ZERO)
        CAN_SFR_INIT_USER_MODE_MODIFY32(CAN_KER[KerIndex]->N[CAN_ONE].CR.U,\
                                       CAN_CR_CCE_CLEARMASK,CAN_CR_CCE_SETMASK)
        CAN_SFR_INIT_USER_MODE_MODIFY32(CAN_KER[KerIndex]->N[CAN_ONE].BTR.U,\
                           CAN_BTR_DIV8_CLEARMASK,\
                           (uint32)CAN_PROTOCAL_EXCEPTION<<CAN_BTR_DIV8_SHIFT)
        CAN_SFR_INIT_USER_MODE_MODIFY32(CAN_KER[KerIndex]->N[CAN_ONE].CR.U,\
                                       CAN_NCR_CCE_CLEARMASK,(uint32)CAN_ZERO)
        KerIndex++;
    }

    /*Unlocking CCE bit if it was locked while setting PED and ISO bit*/
    CAN_SFR_INIT_USER_MODE_MODIFY32(CAN_KER[KerIdx]->N[HwCtrlIDKer].CR.U,\
                                      CAN_CR_CCE_CLEARMASK,CAN_CR_CCE_SETMASK)
    #endif
    /* Set Fast Node Bit Timing value */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
    CAN_SFR_INIT_USER_MODE_WRITE32(CAN_KER[KerIdx]->N[HwCtrlIDKer].FBTR.U,\
                                        (unsigned_int)CanControllerFDBaudrate);

    /* Set Transceiver Delay Compensation Offset values */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
    CAN_SFR_INIT_USER_MODE_WRITE32(CAN_KER[KerIdx]->N[HwCtrlIDKer].TDCR.U,\
                                        (unsigned_int)CanControllerTxDelayComp);
}

/*******************************************************************************
** TRACEABILITY: [cover parentID=DS_AS_CAN419]                                **
**                                                                            **
** Syntax           : void Can_lSetBaudrate                                   **
**                                               (                            **
**                                                 uint8 HwControllerId,      **
**                                                 uint32 ControllerBaudrate  **
**                                                 uint8 ApiAccesId           **
**                                               )                            **
**                                                                            **
**                    [/cover]                                                **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : ControllerId - CAN Controller Id                        **
**                    ControllerBaudrate - Register setting corresponding     **
**                                         to the baudrate                    **
**                    ApiAccesId  - To select from where it get called        **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Initializes the Node Bit Timing Register                **
**                                                                            **
*******************************************************************************/
void Can_lSetBaudrate(uint8 HwControllerId,
                             uint32 ControllerBaudrate,uint8 ApiAccesId )
{
  uint8 KerIdx;
  uint8 HwCtrlIDKer;

  /* Calculate to which kernel, the controller belongs to*/
  KerIdx = CAN_CALC_KERIDX(HwControllerId);
  HwCtrlIDKer = CAN_CALC_HWCTRLID(HwControllerId);

  if (CAN_RUNTIME_ACCESS == ApiAccesId)
  {
    Can_lSetBaudrateRuntime(HwControllerId,ControllerBaudrate);
  }
  else
  {
    /*
    - Enable Configuration Change - NBTR, NPCR, NECNT can be written
    - Take controller out of CAN traffic i.e put it in "stopped" state
    - Enable Alert Interrupt. Used to detect bus off
    */
    CAN_SFR_INIT_USER_MODE_MODIFY32(CAN_KER[KerIdx]->N[HwCtrlIDKer].CR.U,\
                   CAN_NCR_CCE_CLEARMASK,(uint32)CAN_ONE << CAN_NCR_CCE_BITPOS)

    /* Set Node Bit Timing value */
    if((KerIdx < CAN_ISO_NUM_KERNEL)\
           && ((HwCtrlIDKer == CAN_ZERO) || (HwCtrlIDKer == CAN_ONE)))
    {
      CAN_SFR_INIT_USER_MODE_MODIFY32(CAN_KER[KerIdx]->N[HwCtrlIDKer].BTR.U,\
                             CAN_BTR_EXCPT_DIV8_CLEARMASK, ControllerBaudrate)
    }
    else
    {
      CAN_SFR_INIT_USER_MODE_WRITE32(CAN_KER[KerIdx]->N[HwCtrlIDKer].BTR.U,\
                                                           ControllerBaudrate);
    }

    /* Disable Configuration Change - NBTR, NPCR, NECNT can only be read */
    CAN_SFR_INIT_USER_MODE_MODIFY32(CAN_KER[KerIdx]->N[HwCtrlIDKer].CR.U,\
                                       CAN_NCR_CCE_CLEARMASK,(uint32)CAN_ZERO)
  }
}
/*******************************************************************************
** TRACEABILITY: [cover parentID=]                                            **
**                                                                            **
** Syntax           : static void Can_lSetBaudrateRuntime                     **
**                                               (                            **
**                                                 uint8 HwControllerId,      **
**                                                 uint32 ControllerBaudrate  **
**                                               )                            **
**                                                                            **
**                    [/cover]                                                **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : ControllerId - CAN Controller Id                        **
**                    ControllerBaudrate - Register setting corresponding     **
**                                         to the baudrate                    **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Initializes the Node Bit Timing Register                **
**                                                                            **
*******************************************************************************/
static void Can_lSetBaudrateRuntime(uint8 HwControllerId,\
                                                      uint32 ControllerBaudrate)
{
  uint8 KerIdx;
  uint8 HwCtrlIDKer;

  /* Calculate to which kernel, the controller belongs to*/
  KerIdx = CAN_CALC_KERIDX(HwControllerId);
  HwCtrlIDKer = CAN_CALC_HWCTRLID(HwControllerId);
  /*
  - Enable Configuration Change - NBTR, NPCR, NECNT can be written
  - Take controller out of CAN traffic i.e put it in "stopped" state
  - Enable Alert Interrupt. Used to detect bus off
  */
  CAN_SFR_RUNTIME_USER_MODE_MODIFY32(CAN_KER[KerIdx]->N[HwCtrlIDKer].CR.U,\
                 CAN_NCR_CCE_CLEARMASK,(uint32)CAN_ONE << CAN_NCR_CCE_BITPOS)

  /* Set Node Bit Timing value */
  if((KerIdx < CAN_ISO_NUM_KERNEL)\
           && ((HwCtrlIDKer == CAN_ZERO) || (HwCtrlIDKer == CAN_ONE)))
  {
    CAN_SFR_RUNTIME_USER_MODE_MODIFY32(CAN_KER[KerIdx]->N[HwCtrlIDKer].BTR.U,\
                             CAN_BTR_EXCPT_DIV8_CLEARMASK, ControllerBaudrate)
  }
  else
  {
    CAN_SFR_RUNTIME_USER_MODE_WRITE32(CAN_KER[KerIdx]->N[HwCtrlIDKer].BTR.U,\
                                                         ControllerBaudrate);
  }
  /* Disable Configuration Change - NBTR, NPCR, NECNT can only be read */
  CAN_SFR_RUNTIME_USER_MODE_MODIFY32(CAN_KER[KerIdx]->N[HwCtrlIDKer].CR.U,\
                                       CAN_NCR_CCE_CLEARMASK,(uint32)CAN_ZERO)
}
/*******************************************************************************
** TRACEABILITY: [cover parentID=]                                            **
**                                                                            **
** Syntax           :  uint8 Can_lGetHthIndex                                 **
**                                               (                            **
**                                                 uint8 KerIdx,              **
**                                                 uint8 HthIdx               **
**                                               )                            **
**                                                                            **
**                    [/cover]                                                **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : KerIdx - kernel ID                                      **
**                    HthIdx - Starting value of HwObjectId                   **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : TxMOIdx                                                 **
**                                                                            **
** Description      : Getting HTH index                                       **
**                                                                            **
*******************************************************************************/
uint8 Can_lGetHthIndex(uint8 KerIdx,uint8 HthIdx)
{
  uint8 TxMOIdx = CAN_ZERO;
  #if (CAN_TX_OBJECT_KER0 > CAN_ZERO)
  /* Calculate the HTH Id mapped to corresponding HW Object ID */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
  PBConfigStructure and is within allowed range.*/
  TxMOIdx = Can_kConfigPtr->CanTxObjectHthKer0MapPtr[HthIdx];
  #endif
  #if((CAN_TX_OBJECT_KER0 < CAN_ONE))
  UNUSED_PARAMETER(HthIdx)
  #endif
  UNUSED_PARAMETER(KerIdx)
  return TxMOIdx;
}
/*******************************************************************************
** TRACEABILITY: [cover parentID=]                                            **
**                                                                            **
** Syntax           :  uint8 Can_lGetHrhIndex                                 **
**                                               (                            **
**                                                 uint8 KerIdx,              **
**                                                 uint8 HrhOffset            **
**                                               )                            **
**                                                                            **
**                    [/cover]                                                **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : KerIdx - kernel ID                                      **
**                    HrhOffset - Starting value of HwObjectId                **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Hrh                                                     **
**                                                                            **
** Description      : Getting Hrh index                                       **
**                                                                            **
*******************************************************************************/
uint8 Can_lGetHrhIndex(uint8 KerIdx,uint8 HrhOffset)
{
  uint8 Hrh = 0U;
  #if (CAN_RX_OBJECT_KER0 > CAN_ZERO)
  /* Calculate the HTH Id mapped to corresponding HW Object ID */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
  PBConfigStructure and is within allowed range.*/
  Hrh = Can_kConfigPtr->CanRxObjectHrhKer0MapPtr[HrhOffset];
  #endif
  #if((CAN_RX_OBJECT_KER0 < CAN_ONE))
  UNUSED_PARAMETER(HrhOffset)
  #endif
  UNUSED_PARAMETER(KerIdx)
  return Hrh;
}
#define CAN_17_MCANP_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"
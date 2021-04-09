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
**  $FILENAME   : McalOsConfig.h $                                           **
**                                                                           **
**  $CC VERSION : \main\11 $                                                 **
**                                                                           **
**  $DATE       : 2016-04-20 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This header file configures on required OS                **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/

#ifndef MCAL_OS_CONFIG_H
#define MCAL_OS_CONFIG_H

#include "../../tricore_general/ssc/inc/Mcal_DmaLib.h"
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/


/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/*
   Configuration:
   MCAL_OS_HEADER :
   Supply the required header file here
   default is Os.h, user can change to "osek.h" if required
*/
#define MCAL_OS_HEADER      "Os.h"

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/


/*******************************************************************************
**        Global Function Declarations                                        **
*******************************************************************************/

/* This are functions used for testing. These functions are not productive.*/

extern void TRUSTED_ApplResetEndInit(void);
extern void TRUSTED_ApplSetEndInit(void);
extern void OS_WritePeripheral32(uint32 Area,volatile uint32* Address,uint32 value);
extern uint32 OS_ReadPeripheral32(uint32 Area,volatile uint32* Address);
extern void OS_ModifyPeripheral32(uint32 Area,volatile uint32* address,uint32 clearmask,uint32 setmask);
extern void TRUSTED_ApplSafetyResetEndInit_Timed(uint32 Time);
extern void TRUSTED_ApplSafetySetEndInit_Timed(void);
extern uint8 TRUSTED_Mcal_GetCoreId(void);
extern void TRUSTED_Mcal_SetAtomic(sint32* Address, uint32 Value, sint32 Offset, sint32 Bits);
extern uint32 TRUSTED_Mcal_Extract(uint32 Value,uint32 Pos,uint32 Width);
extern void TRUSTED_Mcal_DmaResetDmaChannel(Dma_ChannelType Channel);
extern void TRUSTED_Mcal_DmaChClrIntrFlags(Dma_ChannelType Channel);
extern void TRUSTED_Mcal_DmaResetDmaChannel(Dma_ChannelType Channel);
extern Dma_StatusType TRUSTED_Mcal_DmaGetTransferIntStatus(Dma_ChannelType Channel);
extern void TRUSTED_Mcal_DmaDisableHwTransfer(Dma_ChannelType Channel);
extern void TRUSTED_Mcal_DmaSetSourceAddr(Dma_ChannelType Channel,uint32 Address);
extern void TRUSTED_Mcal_DmaSetDestAddr(Dma_ChannelType Channel,uint32 Address);
extern void TRUSTED_Mcal_DmaCfgIntControl(Dma_ChannelType Channel,uint32 Value);
extern void TRUSTED_Mcal_DmaChClrCtlCfg(Dma_ChannelType Channel);
extern void TRUSTED_Mcal_DmaSetDataWidth(Dma_ChannelType Channel,uint32 DataWidth);
extern void TRUSTED_Mcal_DmaSetTxCount(Dma_ChannelType Channel ,uint32 ReloadValue);
extern void TRUSTED_Mcal_DmaEnableChIntrTrigger(Dma_ChannelType Channel);
extern void TRUSTED_Mcal_DmaSetAdicr(Dma_ChannelType Channel,uint32 Value);
extern void TRUSTED_Mcal_DmaEnableHwTransfer(Dma_ChannelType Channel);
extern void TRUSTED_Mcal_DmaClrAdcr(Dma_ChannelType Channel);
extern void TRUSTED_Mcal_DmaDisableIntr(Dma_ChannelType Channel);
extern void TRUSTED_Mcal_DmaEnableIntr(Dma_ChannelType Channel);
extern void TRUSTED_Mcal_DmaChClrIntctEtrlFlags(Dma_ChannelType Channel);
extern uint32 TRUSTED_Mcal_GetDsprReMapAddress(uint32 Address);
extern Dma_ErrorStatusType TRUSTED_Mcal_DmaGetTransReqLostFlag(Dma_ChannelType Channel);
extern void TRUSTED_Mcal_DmaClrErrFlags(Dma_ChannelType Channel);
extern void TRUSTED_Mcal_DmaDisableChIntrTrigger(Dma_ChannelType Channel);
extern void TRUSTED_Mcal_ReleaseSpinLock(uint32* SpinLckPtr);
extern Std_ReturnType TRUSTED_Mcal_GetSpinLock(uint32* SpinLckPtr,uint32 Timeout);
extern uint32 TRUSTED_Mcal_LockResource(uint32 *ResourcePtr);
extern void  TRUSTED_Mcal_UnlockResource(uint32* ResourcePtr);
extern void TRUSTED_Mcal_DmaCfgNoOfMovesPerTransfer(Dma_ChannelType Channel, uint8 NoOfMoves);
extern void TRUSTED_SuspendAllInterrupts(void);
extern void TRUSTED_ResumeAllInterrupts(void);
extern void TRUSTED_Mcal_CpuWdtModifyAccess(const uint32 NewPassword,const uint32 NewReload);
extern void TRUSTED_Mcal_SafetyCheckAccess(const uint32 CheckPassword,const uint32 CheckTimer);
extern void TRUSTED_Mcal_CpuWdtCheckAccess(const uint32 CheckPassword,const uint32 CheckTimer);
extern uint32 TRUSTED_Mcal_SafetyPwSequence(const uint32 Password);
extern uint32 TRUSTED_Mcal_CpuWdtPwSequence(const uint32 Password);
extern uint16 TRUSTED_Mcal_WdtCalcSeqPassword(uint16 SeqPassword);
extern void TRUSTED_Mcal_DmaStartTransaction(Dma_ChannelType Channel);
extern Dma_ErrorStatusType TRUSTED_Mcal_DmaGetMoveEngErrFlags(uint8 MoveEngine);
extern Dma_StatusType TRUSTED_Mcal_DmaGetIntStatus(Dma_ChannelType Channel);
extern void TRUSTED_Mcal_DmaEnTransReqLostIntr(Dma_ChannelType Channel);
extern void TRUSTED_Mcal_DmaCfgMeErrIntr(void);
extern uint32 TRUSTED_Mcal_DmaGetTransferCount(Dma_ChannelType Channel);
extern void TRUSTED_Mcal_DmaClrIntrTriggerFlag(Dma_ChannelType Channel);

#endif /* MCAL_OS_CONFIG_H */
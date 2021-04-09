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
**  $FILENAME   : OsStub.c $                                                 **
**                                                                           **
**  $CC VERSION : \main\11 $                                                 **
**                                                                           **
**  $DATE       : 2016-04-20 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                - stub for OS functionality.                               **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Include Mcal for Library */
#include "McalOsConfig.h"
#include <McalOsConfig.h>
#include <Mcal.h>
#include <Mcal_DmaLib.h>

/*******************************************************************************
**                      Imported Compiler Switch Checks                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
extern volatile uint32 SFR_Return_Value;
extern volatile uint32 SV_Return_Value;


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/


/*******************************************************************************
** Syntax           : void TRUSTED_ApplResetEndInit(void)                     **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call McalResetENDINIT from user mode   **
**                                                                            **
*******************************************************************************/
void TRUSTED_ApplResetEndInit(void)
{
    SYSCALL(MCAL_TIN_CALL_RESET_ENDINIT);
}


/*******************************************************************************
** Syntax           : void TRUSTED_ApplSetEndInit(void)                       **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call McalSetENDINIT from user mode     **
**                                                                            **
*******************************************************************************/
void TRUSTED_ApplSetEndInit(void)
{
    SYSCALL(MCAL_TIN_CALL_SET_ENDINIT);
}


/*******************************************************************************
** Syntax           : void OS_WritePeripheral32(uint32 Area,                  **
**                                               volatile uint32* Address,    **
**                                               uint32 value)                **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non -reentrant                                          **
**                                                                            **
** Parameters(in)   : Area     : Identification for the Module                **
**                    Address  : Address of SFR to be written                 **
**                    value    : Value to be written to the SFR               **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function Write the value into the SFR in user mode **
**                                                                            **
*******************************************************************************/
void OS_WritePeripheral32(uint32 Area,volatile uint32* Address,uint32 value)
{
    SYSCALL(MCAL_TIN_CALL_WRITE32);
    UNUSED_PARAMETER(Area)
    UNUSED_PARAMETER(Address)
    UNUSED_PARAMETER(value)
}

/*******************************************************************************
** Syntax           : void OS_ModifyPeripheral32(uint32 Area,                 **
**                                               volatile uint32* Address,    **
**                                               uint32 clearmask             **
**                                               uint32  setmask)             **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non -reentrant                                          **
**                                                                            **
** Parameters(in)   : Area     : Identification for the Module                **
**                    Address  : Address of SFR to be written                 **
**                    clearmask: This value will be "anded" with SFR content  **
**                    setmask  : This value will be "ored" with SFR content   **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function Write the value into the SFR in user mode **
**                                                                            **
*******************************************************************************/
void OS_ModifyPeripheral32(uint32 area,volatile uint32* address, \
                             uint32 clearmask, uint32  setmask)
{
    SYSCALL(MCAL_TIN_CALL_MODIFY32);
    UNUSED_PARAMETER(area)
    UNUSED_PARAMETER(address)
    UNUSED_PARAMETER(clearmask)
    UNUSED_PARAMETER(setmask)
}

/*******************************************************************************
** Syntax           : void OS_ReadPeripheral32(uint32 Area,                   **
**                                               volatile uint32* Address,    **
**                                               uint32 value)                **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Area     : Identification for the Module                **
**                    Address  : Address of SFR to be written                 **
**                                                                            **
** Parameters (out) : value    : Value to be written to the SFR               **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function Read the value into the SFR in user mode  **
**                                                                            **
*******************************************************************************/
uint32 OS_ReadPeripheral32(uint32 Area,volatile uint32* Address)
{
    volatile uint32 value =0U;
    SYSCALL(MCAL_TIN_CALL_READ32);
    value = SFR_Return_Value;
    UNUSED_PARAMETER(Area)
    UNUSED_PARAMETER(Address)
    return value;
}

/*******************************************************************************
** Syntax           : void TRUSTED_ApplSafetyResetEndInit(void)               **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Time: value to be loaded                                **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call McalSafetysetEndInit from user    **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
void TRUSTED_ApplSafetyResetEndInit_Timed(uint32 Time)
{
    SYSCALL(MCAL_TIN_CALL_SAFETY_RESET_ENDINIT_TIMED);
    UNUSED_PARAMETER(Time)
}


/*******************************************************************************
** Syntax           : void TRUSTED_ApplSafetysetEndInit(void)                 **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call McalSafetysetEndInit from user    **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
void TRUSTED_ApplSafetySetEndInit_Timed(void)
{
    SYSCALL(MCAL_TIN_CALL_SAFETY_SET_ENDINIT_TIMED);
}
/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_GetCoreId(void)                       **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_GetCoreId from user          **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
uint8 TRUSTED_Mcal_GetCoreId()
{
  volatile uint8 value =0U;
  SYSCALL(MCAL_TIN_CALL_MCAL_COREID);
  value= (uint8)SV_Return_Value;
  return(value);
}
/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_SetAtomic(void)                       **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Address, Value, Offset, Bits                            **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call MCAL_SetAtomic() from user        **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
void  TRUSTED_Mcal_SetAtomic(sint32* Address, uint32 Value, sint32 Offset, sint32 Bits)
{
    SYSCALL(MCAL_CALL_TIN_SET_ATOMIC);
    UNUSED_PARAMETER(Address);
    UNUSED_PARAMETER(Value);
    UNUSED_PARAMETER(Offset);
    UNUSED_PARAMETER(Bits);
}
/*******************************************************************************
** Syntax           : uint32 TRUSTED_Mcal_Extract(void)                       **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Value,Pos,Width                                         **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_Extract from user            **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/

uint32 TRUSTED_Mcal_Extract(uint32 Value,uint32 Pos,uint32 Width)
{
    volatile uint32 ret_value =0U;
    SYSCALL(MCAL_CALL_TIN_EXTRACT);
    UNUSED_PARAMETER(Value);
    UNUSED_PARAMETER(Pos);
    UNUSED_PARAMETER(Width);
    ret_value= SV_Return_Value;
    return(ret_value);
}
/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_DmaResetDmaChannel(void)              **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_DmaResetDmaChannel from user **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/

void TRUSTED_Mcal_DmaResetDmaChannel(Dma_ChannelType Channel)
{
   SYSCALL(MCAL_CALL_TIN_DMA_RESETCHANNEL);
   UNUSED_PARAMETER(Channel);
}

/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_DmaChClrIntrFlags(void)               **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_DmaChClrIntrFlags from user  **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
void TRUSTED_Mcal_DmaChClrIntrFlags(Dma_ChannelType Channel)
{

    SYSCALL(MCAL_CALL_TIN_DMA_CHANNELCLR_INTRFLG);
    UNUSED_PARAMETER(Channel);

}
/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_DmaGetTransferIntStatus(void)         **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_DmaGetTransferIntStatus from **
**                    user mode                                               **
**                                                                            **
*******************************************************************************/

Dma_StatusType TRUSTED_Mcal_DmaGetTransferIntStatus(Dma_ChannelType Channel)
{
    volatile Dma_StatusType value =0U;
    SYSCALL(MCAL_CALL_TIN_DMA_GET_TRANSFERINTSTATS);
    UNUSED_PARAMETER(Channel);
    value= SV_Return_Value;
    return(value);
}

/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_DmaGetTransferIntStatus(void)         **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_DmaGetTransferIntStatus from **
**                    user mode                                               **
**                                                                            **
*******************************************************************************/

void TRUSTED_Mcal_DmaDisableHwTransfer(Dma_ChannelType Channel)
{
    SYSCALL(MCAL_CALL_TIN_DMA_DISABL_HWTRFR);
    UNUSED_PARAMETER(Channel);
}

/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_DmaSetSourceAddr(void)                **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Channel,    Address                                     **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_DmaSetSourceAddr from user   **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/

void TRUSTED_Mcal_DmaSetSourceAddr(Dma_ChannelType Channel,uint32 Address)
{

    SYSCALL(MCAL_CALL_TIN_DMA_SETSRC_ADDRS);
    UNUSED_PARAMETER(Channel);
    UNUSED_PARAMETER(Address);
}



/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_DmaSetDestAddr(void)                  **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Channel,Address                                         **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_DmaSetDestAddr from user     **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/

void TRUSTED_Mcal_DmaSetDestAddr(Dma_ChannelType Channel,uint32 Address)
{

    SYSCALL(MCAL_CALL_TIN_DMA_SETDST_ADDRS);
    UNUSED_PARAMETER(Channel);
    UNUSED_PARAMETER(Address);

}

/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_DmaChClrCtlCfg(void)                  **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Channel                                                 **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_DmaChClrCtlCfg from user     **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
void TRUSTED_Mcal_DmaChClrCtlCfg(Dma_ChannelType Channel)
{
    SYSCALL(MCAL_CALL_TIN_DMA_CHACLR_CTRLFLG);
    UNUSED_PARAMETER(Channel);

}


/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_DmaChClrCtlCfg(void)                  **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Channel,  Value                                         **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_DmaChClrCtlCfg from user    **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
void TRUSTED_Mcal_DmaCfgIntControl(Dma_ChannelType Channel,uint32 Value)
{
    SYSCALL(MCAL_CALL_TIN_DMA_CFGINT_CTRL);
    UNUSED_PARAMETER(Channel);
    UNUSED_PARAMETER(Value);
}


/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_DmaSetDataWidth(void)                 **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Channel  ,DataWidth                                     **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_DmaSetDataWidth from user    **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
void TRUSTED_Mcal_DmaSetDataWidth(Dma_ChannelType Channel,uint32 DataWidth)
{
    SYSCALL(MCAL_CALL_TIN_DMA_SET_DATAWDTH);
    UNUSED_PARAMETER(Channel);
    UNUSED_PARAMETER(DataWidth);
}


/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_DmaSetTxCount(void)                   **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Channel,ReloadValue                                     **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_DmaSetDataWidth from user    **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
void TRUSTED_Mcal_DmaSetTxCount(Dma_ChannelType Channel,uint32 ReloadValue)
{
    SYSCALL(MCAL_CALL_TIN_DMA_SET_TXCOUNT);
    UNUSED_PARAMETER(Channel);
    UNUSED_PARAMETER(ReloadValue);
}

/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_DmaEnableChIntrTrigger(void)          **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Channel                                                 **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_DmaSetDataWidth from user    **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
void TRUSTED_Mcal_DmaEnableChIntrTrigger(Dma_ChannelType Channel)
{
    SYSCALL(MCAL_CALL_TIN_DMA_ENABLE_CHINT_TRGR);
    UNUSED_PARAMETER(Channel);
}
/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_DmaEnableIntr(void)                   **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Channel                                                 **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_Mcal_DmaEnableIntr from user **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
void TRUSTED_Mcal_DmaEnableIntr(Dma_ChannelType Channel)
{
    SYSCALL(MCAL_CALL_TIN_DMA_ENABLE_INTR);
    UNUSED_PARAMETER(Channel);
}

/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_DmaSetAdicr(void)                     **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Channel                                                 **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_DmaSetAdicr from user        **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
void TRUSTED_Mcal_DmaSetAdicr(Dma_ChannelType Channel,uint32 Value)
{
    SYSCALL(MCAL_CALL_TIN_DMA_ADICR);
    UNUSED_PARAMETER(Channel)
    UNUSED_PARAMETER(Value)
}
/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_DmaEnableHwTransfer(void)             **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Channel                                                 **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_DmaEnableHwTransfer from user**
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
void TRUSTED_Mcal_DmaEnableHwTransfer(Dma_ChannelType Channel)
{
    SYSCALL(MCAL_CALL_TIN_ENABLE_HWTRANSFER);
    UNUSED_PARAMETER(Channel);
}
/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_DmaClrAdcr(void)                      **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Channel                                                 **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_DmaClrAdcr from user         **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
void TRUSTED_Mcal_DmaClrAdcr(Dma_ChannelType Channel)
{
    SYSCALL(MCAL_CALL_TIN_CLR_ADCR);
    UNUSED_PARAMETER(Channel);
}

/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_DmaDisableIntr(void)                 **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Channel                                                 **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_DmaDisableIntr from user     **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
void TRUSTED_Mcal_DmaDisableIntr(Dma_ChannelType Channel)
{
    SYSCALL(MCAL_CALL_TIN_DMA_DISABLE_INTR);
    UNUSED_PARAMETER(Channel);
}
/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_DmaChClrIntctEtrlFlags(void)          **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Channel                                                 **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_DmaChClrIntctEtrlFlags from  **
**                    user mode                                               **
**                                                                            **
*******************************************************************************/
void TRUSTED_Mcal_DmaChClrIntctEtrlFlags(Dma_ChannelType Channel)
{
    SYSCALL(MCAL_CALL_TIN_DMACHCLR_INTCTETR_FLGS);
    UNUSED_PARAMETER(Channel);
}

/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_GetDsprReMapAddress(void)             **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Channel                                                 **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_GetDsprReMapAddress from user**
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
uint32 TRUSTED_Mcal_GetDsprReMapAddress(uint32 Address)
{
    volatile uint32 value =0U;
    SYSCALL(MCAL_CALL_TIN_GET_DSPR_REMAPADDRS);
    UNUSED_PARAMETER(Address);
    value =SV_Return_Value;
    return(value);
}

/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_DmaGetTransReqLostFlag(void)          **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Channel                                                 **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_DmaGetTransReqLostFlag from  **
**                    user  mode                                              **
**                                                                            **
*******************************************************************************/
Dma_ErrorStatusType TRUSTED_Mcal_DmaGetTransReqLostFlag(Dma_ChannelType Channel)
{
    volatile Dma_ErrorStatusType value =0U;
    SYSCALL(MCAL_CALL_TIN_DMAGET_TRANSREQLOSTFLG);
    UNUSED_PARAMETER(Channel);
    value= SV_Return_Value;
    return(value);
}
/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_DmaClrErrFlags(void)                  **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Channel                                                 **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_DmaClrErrFlags from user**
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
void TRUSTED_Mcal_DmaClrErrFlags(Dma_ChannelType Channel)
{
    SYSCALL(MCAL_CALL_TIN_DMA_CLRERRFLG);
    UNUSED_PARAMETER(Channel);
}

/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_DmaDisableChIntrTrigger(void)         **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Channel                                                 **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_DmaDisableChIntrTrigger(     **
**                    from user mode                                          **
**                                                                            **
*******************************************************************************/
void TRUSTED_Mcal_DmaDisableChIntrTrigger(Dma_ChannelType Channel)
{

    SYSCALL(MCAL_CALL_TIN_DMA_DISABLE_INTRTRGR);
    UNUSED_PARAMETER(Channel);

}
/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_ReleaseSpinLock(void)                 **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : uint32* SpinLckPtr                                      **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_ReleaseSpinLock from user    **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
void TRUSTED_Mcal_ReleaseSpinLock(uint32* SpinLckPtr)
{
    SYSCALL(MCAL_CALL_TIN_RELEASESPIN_LOCK);
    UNUSED_PARAMETER(SpinLckPtr);
}

/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_GetSpinLock(void)                     **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : uint32* SpinLckPtr,uint32 Timeout                       **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : value                                                   **
**                                                                            **
** Description      : This function to call Mcal_GetSpinLock from user        **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
Std_ReturnType TRUSTED_Mcal_GetSpinLock(uint32* SpinLckPtr,uint32 Timeout)
{
    volatile Std_ReturnType value =0U;
    SYSCALL(MCAL_CALL_TIN_GETSPIN_LOCK);
    UNUSED_PARAMETER(SpinLckPtr);
    UNUSED_PARAMETER(Timeout);
    value = (Std_ReturnType)SV_Return_Value;
    return(value);

}
/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_LockResource(void)                    **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : uint32 *ResourcePtr,uint32* SpinLckPtr                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_LockResource from user    **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
uint32 TRUSTED_Mcal_LockResource(uint32 *ResourcePtr)
{
    volatile uint32 value =0U;
    SYSCALL(MCAL_CALL_TIN_LOCK_RESOURCE);
    UNUSED_PARAMETER(ResourcePtr);
    value= SV_Return_Value;
    return(value);
}
/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_UnLockResource(void)           **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : uint32 *ResourcePtr                                              **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_UnLockResource from user    **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
void TRUSTED_Mcal_UnLockResource(uint32 *ResourcePtr)
{
    SYSCALL(MCAL_CALL_TIN_UNLOCK_RESOURCE);
    UNUSED_PARAMETER(ResourcePtr);
}

/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_DmaCfgNoOfMovesPerTransfer(void)           **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Dma_ChannelType Channel, uint8 NoOfMoves                **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_DmaCfgNoOfMovesPerTransfer   **
**                    from user mode                                          **
**                                                                            **
*******************************************************************************/
void  TRUSTED_Mcal_DmaCfgNoOfMovesPerTransfer(Dma_ChannelType Channel, uint8 \
          NoOfMoves)
{
    SYSCALL(MCAL_CALL_TIN_DMACFG_MVPR_TRSFR);
    UNUSED_PARAMETER(Channel);
    UNUSED_PARAMETER(NoOfMoves);
}

/*******************************************************************************
** Syntax           : void TRUSTED_SuspendAllInterrupts(void)                 **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : void                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_SuspendAllInterrupts from    **
**                    user mode                                               **
**                                                                            **
*******************************************************************************/
void TRUSTED_SuspendAllInterrupts (void)
{
    SYSCALL(MCAL_CALL_TIN_SSPEND_ALLINTRPT);

}
/*******************************************************************************
** Syntax           : void TRUSTED_ResumeAllInterrupts(void)                  **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : void                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call ResumeAllInterrupts from user     **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
void TRUSTED_ResumeAllInterrupts (void)
{
    SYSCALL(MCAL_CALL_TIN_RESUME_ALLINTRPT);

}
/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_CpuWdtModifyAccess(void)              **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : uint32 NewPassword, uint32 NewReload                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_CpuWdtModifyAccess( from user**
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
 void TRUSTED_Mcal_CpuWdtModifyAccess(const uint32 NewPassword,const uint32
                           NewReload)
{
    SYSCALL(MCAL_CALL_TIN_CPUWDG_MODIFYACCES);
    UNUSED_PARAMETER(NewPassword);
    UNUSED_PARAMETER(NewReload);
}

/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_SafetyCheckAccess(void)               **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : uint32 CheckPassword,const uint32 CheckTimer            **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_SafetyCheckAccess( from user **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
 void TRUSTED_Mcal_SafetyCheckAccess(const uint32 CheckPassword,const uint32 \
                  CheckTimer)
{
    SYSCALL(MCAL_CALL_TIN_SAFETY_CHECKACCES);
    UNUSED_PARAMETER(CheckPassword);
    UNUSED_PARAMETER(CheckTimer);
}
/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_CpuWdtCheckAccess(void)               **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : uint32 CheckPassword,uint32 CheckTimer                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_CpuWdtCheckAccess( from user **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
void TRUSTED_Mcal_CpuWdtCheckAccess(const uint32 CheckPassword,const uint32 \
        CheckTimer)
{
    SYSCALL(MCAL_CALL_TIN_UNLOCK_RESOURCE);
    UNUSED_PARAMETER(CheckPassword);
    UNUSED_PARAMETER(CheckTimer);
}
/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_SafetyPwSequence(void)                **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : uint32 Password                                         **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_SafetyPwSequence( from user  **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
uint32  TRUSTED_Mcal_SafetyPwSequence(const uint32 Password)
{

    volatile uint32 ret_value =0U;
    SYSCALL(MCAL_CALL_TIN_SAFETY_PWSQNCE);
    UNUSED_PARAMETER(Password);
    ret_value= SV_Return_Value;
    return(ret_value);

}

/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_CpuWdtPwSequence(void)           **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : uint32 Password                                         **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_CpuWdtPwSequence from user   **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
uint32 TRUSTED_Mcal_CpuWdtPwSequence(const uint32 Password)
{
    volatile uint32 ret_value =0U;
    SYSCALL(MCAL_CALL_TIN_CPUWDT_PWSQNCE);
    UNUSED_PARAMETER(Password);
    ret_value= SV_Return_Value;
    return(ret_value);
}


/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_WdtCalcSeqPassword(uint16 SeqPassword)**
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : uint32 Password                                         **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_WdtCalcSeqPassword from user **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
uint16 TRUSTED_Mcal_WdtCalcSeqPassword(uint16 SeqPassword)
{
    volatile uint16 ret_value =0U;
    SYSCALL(MCAL_CALL_TIN_CALC_SEQ_PSWD);
    UNUSED_PARAMETER(SeqPassword);
    ret_value = (uint16)SV_Return_Value;
    return(ret_value);
}


/*******************************************************************************
** Syntax           : void TRUSTED_Mcal_DmaStartTransaction(Dma_ChannelType   **
**                                                                  Channel)  **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Dma_ChannelType SeqPassword                             **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function to call Mcal_DmaStartTransaction          **
**                      from user mode                                        **
**                                                                            **
*******************************************************************************/
void TRUSTED_Mcal_DmaStartTransaction(Dma_ChannelType Channel)
{
    SYSCALL(MCAL_CALL_TIN_DMA_START_TRANSCTION);
    UNUSED_PARAMETER(Channel);
}
/*******************************************************************************
** Syntax           :Dma_ErrorStatusType TRUSTED_Mcal_DmaGetMoveEngErrFlags
**                                                          (uint8 MoveEngine)**
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Dma_ChannelType SeqPassword                             **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function tocall Mcal_DmaGetMoveEngErrFlags from    **
**                    user mode                                               **
**                                                                            **
*******************************************************************************/
Dma_ErrorStatusType TRUSTED_Mcal_DmaGetMoveEngErrFlags(uint8 MoveEngine)
{
    Dma_ErrorStatusType ret_val;
    SYSCALL(MCAL_CALL_TIN_DMAGET_MOVENGERR_FLGS);
    UNUSED_PARAMETER(MoveEngine);
    ret_val= (Dma_ErrorStatusType)SV_Return_Value;
    return(ret_val);
}
/*******************************************************************************
** Syntax           : Dma_StatusType TRUSTED_Mcal_DmaGetIntStatus             **
**                                                 (Dma_ChannelType Channel)  **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Dma_ChannelType SeqPassword                             **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function tocall Mcal_DmaGetIntStatus(from user     **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
 Dma_StatusType TRUSTED_Mcal_DmaGetIntStatus(Dma_ChannelType Channel)
{
    Dma_StatusType ret_val;
    SYSCALL(MCAL_CALL_TIN_DMAGET_INITSTATUS);
    UNUSED_PARAMETER(Channel);
    ret_val= (Dma_StatusType)SV_Return_Value;
    return(ret_val);

}

/*******************************************************************************
** Syntax           : TRUSTED_Mcal_DmaEnTransReqLostIntr                      **
**                                                 (Dma_ChannelType Channel)  **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Dma_ChannelType SeqPassword                             **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function tocall cal_DmaEnTransReqLostIntr(from user**
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
void TRUSTED_Mcal_DmaEnTransReqLostIntr(Dma_ChannelType Channel)
{
    SYSCALL(MCAL_CALL_TIN_DMAENTRAS_LOSTINTR);
    UNUSED_PARAMETER(Channel);
}



/*******************************************************************************
** Syntax           : TRUSTED_Mcal_DmaCfgMeErrIntr   (void)                   **
**                                                                            **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Dma_ChannelType SeqPassword                             **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function tocall cal Mcal_DmaCfgMeErrIntr from user **
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
void TRUSTED_Mcal_DmaCfgMeErrIntr(void)
{
    SYSCALL(MCAL_CALL_TIN_CFGME_ERRINTR);
}


/*******************************************************************************
** Syntax           : TRUSTED_Mcal_DmaGetTransferCount   (void)                **
**                                                                            **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Dma_ChannelType SeqPassword                              **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function tocall cal Mcal_DmaGetTransferCount from user**
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
uint32 TRUSTED_Mcal_DmaGetTransferCount(Dma_ChannelType Channel)
{
    volatile uint32 ret_val= 0;
    SYSCALL(MCAL_CALL_TIN_DMAGET_TRANSFERCOUNT);
    UNUSED_PARAMETER(Channel);
    ret_val = (uint32)SV_Return_Value;
    return(ret_val);

}

/*******************************************************************************
** Syntax           : TRUSTED_Mcal_DmaClrIntrTriggerFlag (Dma_ChannelType     **
**                                                                     Channel) **
**                                                                            **
**                                                                            **
** Service ID       :  none                                                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Dma_ChannelType SeqPassword                              **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function tocall cal Mcal_DmaClrIntrTriggerFlag from user**
**                    mode                                                    **
**                                                                            **
*******************************************************************************/
void TRUSTED_Mcal_DmaClrIntrTriggerFlag(Dma_ChannelType Channel)
{
    SYSCALL(MCAL_CALL_TIN_DMA_STARTTRSCTION);
    UNUSED_PARAMETER(Channel);
}

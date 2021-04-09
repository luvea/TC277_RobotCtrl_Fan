/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : Mcu_Dma.c $                                                **
**                                                                            **
**  $CC VERSION : \main\19 $                                                 **
**                                                                            **
**  $DATE       : 2016-05-06 $                                               **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This file contains basic initialization of DMA module.      **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
  /* Inclusion of controller sfr file */
#include "Mcu.h"
#include "Mcu_Local.h"
#include "Mcal_DmaLib.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

#define MCU_DMA_CLC_DISR_CLEARMASK            0xFFFFFFFEU
#define MCU_DMA_CLC_DISR_CLEARMASK1           0xFFFFFFFEU
#define MCU_DMA_CLC_DISR_SETMASK              0x00000001U
#define MCU_DMA_CLC_DISS_CLEARMASK            0x00000002U
#define MCU_DMA_CLC_DISS_BITPOS               1U

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
#ifdef IFX_MCU_DEBUG03
extern volatile uint32 TestMcu_DebugMask03;
#endif
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/


/*Memory Map of the MCU Code*/
#define MCU_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Syntax : Std_ReturnType Mcu_lDmaInit (void)                                **
**                                                                            **
** Service ID:    None                                                        **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non-reentrant                                               **
**                                                                            **
** Parameters (in):   None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value: E_OK - CLC is enabled                                        **
**               E_NOT_OK - Enabling of CLC failed                            **
**                                                                            **
** Description :  This service shall initialize DMA clock for other drivers   **
**                to use DMA if DMA Complex driver is not used.               **
**                                                                            **
*******************************************************************************/
Std_ReturnType Mcu_lDmaInit(void)
{
  Std_ReturnType RetVal = E_OK;
  uint32 Readback;

  MCU_SFR_INIT_RESETENDINIT();
  /* Enable the DMA clock */
  MCU_SFR_INIT_MODIFY32(MODULE_DMA.CLC.U,MCU_DMA_CLC_DISR_CLEARMASK,0U)
  MCU_SFR_INIT_SETENDINIT();

  Readback = (uint32)((MCU_SFR_INIT_USER_MODE_READ32(MODULE_DMA.CLC.U)\
                        & MCU_DMA_CLC_DISS_CLEARMASK)>>MCU_DMA_CLC_DISS_BITPOS);
  #ifdef IFX_MCU_DEBUG03
  Readback |= TestMcu_DebugMask03;
  #endif

  if(Readback == 1U)
  {
    RetVal = E_NOT_OK;
  }

return(RetVal);
}/*End of Mcu_lDmaInit()*/

#if (MCU_DEINIT_API == STD_ON)

/*******************************************************************************
** Syntax : void Mcu_lDmaDeInit (void)                                        **
**                                                                            **
** Service ID:    None                                                        **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non-reentrant                                               **
**                                                                            **
** Parameters (in):   None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value:      None                                                    **
**                                                                            **
** Description :  This service shall de-initialize DMA clock                  **
**                                                                            **
*******************************************************************************/
void Mcu_lDmaDeInit(void)
{
  /* Disable the DMA clock */
  MCU_SFR_DEINIT_RESETENDINIT();
  MCU_SFR_DEINIT_MODIFY32(MODULE_DMA.CLC.U,MCU_DMA_CLC_DISR_CLEARMASK1,\
                                                     MCU_DMA_CLC_DISR_SETMASK)
  MCU_SFR_DEINIT_SETENDINIT();

}/*End of Mcu_lDmaDeInit()*/
#endif
#if (MCU_SAFETY_ENABLE == STD_ON)
/*******************************************************************************
** Syntax : Std_ReturnType Mcu_lDmaInitCheck (void)                           **
**                                                                            **
** Service ID:    None                                                        **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non-reentrant                                               **
**                                                                            **
** Parameters (in):   None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :    E_OK - if initialization comparison is success        **
**                      E_NOT_OK - if initialization comparison fails         **
**                                                                            **
** Description :  This service shall verify the DMA specific                  **
**                initialization done by MCU.                                 **
**                                                                            **
*******************************************************************************/
Std_ReturnType Mcu_lDmaInitCheck(void)
{
  Std_ReturnType ErrorFlag;

  ErrorFlag = E_OK;

  if (((MCU_SFR_INIT_USER_MODE_READ32(MODULE_DMA.CLC.U) & \
                   MCU_DMA_CLC_DISS_CLEARMASK)>>MCU_DMA_CLC_DISS_BITPOS)  != 0U)
  {
    ErrorFlag = E_NOT_OK;
  }

  return ErrorFlag;
}/*End of Mcu_lDmaInitCheck()*/

#endif /*End Of MCU_SAFETY_ENABLE*/

#define MCU_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives
 is allowed only for MemMap.h*/
#include "MemMap.h"
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
**  $FILENAME   : Mcal_DmaLib.c $                                            **
**                                                                           **
**  $CC VERSION : \main\26 $                                                 **
**                                                                           **
**  $DATE       : 2016-08-04 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains Mcal Dma library routines               **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**  TRACEABILITY : [cover parentID= SAS_NAS_ALL_PR455,SAS_NAS_ALL_PR128,
SAS_NAS_ALL_PR70,SAS_NAS_ALL_PR1652,SAS_NAS_ALL_PR630_PR631,SAS_NAS_ALL_PR470,
DS_NAS_MCALLIB_PR131,DS_NAS_MCALLIB_PR115]
                   [/cover]
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "IfxDma_reg.h"
#include "IfxScu_reg.h"
#include "IfxCpu_reg.h"
#include "IfxSrc_reg.h"
/* Own header file */
#include "Mcal.h"
#include "Mcal_TcLib.h"
#include "Mcal_WdgLib.h"
#include "Mcal_DmaLib.h"

/*******************************************************************************
**                      File Inclusion Check                                  **
*******************************************************************************/
#ifndef MCAL_SW_MAJOR_VERSION
#error "MCAL_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef MCAL_SW_MINOR_VERSION
  #error "MCAL_SW_MINOR_VERSION is not defined. "
#endif

#ifndef MCAL_SW_PATCH_VERSION
#error "MCAL_SW_PATCH_VERSION is not defined. "
#endif

#if ( MCAL_SW_MAJOR_VERSION != 1 )
  #error "MCAL_SW_MAJOR_VERSION does not match. "
#endif

#if ( MCAL_SW_MINOR_VERSION != 0 )
  #error "MCAL_SW_MINOR_VERSION does not match. "
#endif


/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*Memory Map of the Code*/
#define MCAL_DMALIB_START_SEC_CODE
/*
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
#include "MemMap.h"

/*******************************************************************************
** Traceability     : [cover parentID=SAS_NAS_MCALLIB_PR122_7,
SAS_NAS_MCALLIB_PR472]                                         [/cover]       **
** Syntax           : void Mcal_DmaEnableIntr                                 **
** (                                                                          **
**   uint32 Module                                                            **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module no.                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Enable Dma Hw channel Interrupt             **
*******************************************************************************/
void  Mcal_DmaEnableIntr(Dma_ChannelType Channel)
{
  volatile uint32 *lAddress;

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
  access the SFRs of multiple DMA channels*/
  lAddress = (volatile uint32 *)(volatile void *)(SRC_DMACH0ADDR + Channel);

  /* Set SRC.SRE and SRC.CLRR */
  MCAL_REG_MODIFY32(*lAddress,(SRC_CLRR_SRE_CLRMSK),(SRC_CLRR_SRE_SETMSK))
  
}

/*******************************************************************************
** Traceability     : [cover parentID=SAS_NAS_MCALLIB_PR122_8,
SAS_NAS_MCALLIB_PR472]                                                [/cover]**
** Syntax           :  void Mcal_DmaDisableIntr                               **
** (                                                                          **
**   uint32 Module                                                            **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module no.                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Enable Dma Hw channel Interrupt             **
*******************************************************************************/
void Mcal_DmaDisableIntr(Dma_ChannelType Channel)
{
  volatile uint32 *lAddress;

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
  access the SFRs of multiple DMA channels*/
  lAddress = (volatile uint32 *)(volatile void *)(SRC_DMACH0ADDR + Channel);
  /* Check if SRE is enabled */
  if(((*lAddress)&((uint32)IFX_SRC_SRCR_SRE_MSK<<IFX_SRC_SRCR_SRE_OFF))==\
               ((uint32)IFX_SRC_SRCR_SRE_MSK<<IFX_SRC_SRCR_SRE_OFF))
  {
    /* Set SRC.IOVCLR, SRC.SWSCLR, SRC.CLRR  Clear SRC.SRE */
    MCAL_REG_MODIFY32(*lAddress,SRC_IOVCLR_SWSCLR_CLRR_SRE_CLRMSK,\
                           SRC_IOVCLR_SWSCLR_CLRR_SRE_SETMSK)
  }
}

/*******************************************************************************
** Traceability     : [cover parentID=SAS_NAS_MCALLIB_PR75_4,
SAS_NAS_MCALLIB_PR472]                                               [/cover] **
** Syntax           :  void Mcal_DmaCfgNoOfMovesPerTransfer                   **
** (                                                                          **
**   Dma_ChannelType Channel, uint8 NoOfMoves                                 **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Channel - Dma channel no.                               **
**                    NoOfMoves - No of Dma Moves (logical no)                **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to configure the No of Dma moves per transfer  **
*******************************************************************************/
void Mcal_DmaCfgNoOfMovesPerTransfer(Dma_ChannelType Channel, uint8 NoOfMoves)
{
  volatile uint32 *lAddress;
  uint32 lSetMask,lClearMask;
  uint8 BlkmVal;

  switch(NoOfMoves)
  {
    case 1:
    {
      BlkmVal = 0U;
      break;
    }

    case 2:
    {
      BlkmVal = 1U;
      break;
    }

    case 4:
    {
      BlkmVal = 2U;
      break;
    }

    case 8:
    {
      BlkmVal = 3U;
      break;
    }

    case 16:
    {
      BlkmVal = 4U;
      break;
    }
    case 3:
    {
      BlkmVal = 5U;
      break;
    }
    case 5:
    {
      BlkmVal = 6U;
      break;
    }
    case 9:
    {
      BlkmVal = 7U;
      break;
    }
    default:
    {
      BlkmVal = 0U;
      break;
    }
  }
  lSetMask=Mcal_GetSetMask((uint32)BlkmVal,IFX_DMA_CH_CHCFGR_BLKM_MSK,\
                                           IFX_DMA_CH_CHCFGR_BLKM_OFF);
  lClearMask=Mcal_GetClearMask((uint32)BlkmVal,IFX_DMA_CH_CHCFGR_BLKM_MSK,\
                                               IFX_DMA_CH_CHCFGR_BLKM_OFF);
  lAddress = (volatile uint32 *)(volatile void *)\
                           (&MODULE_DMA.CH[Channel].CHCFGR.U);

  MCAL_REG_MODIFY32(*lAddress,(~lClearMask),lSetMask)
}

/*Memory Map of the Code*/
#define MCAL_DMALIB_STOP_SEC_CODE
/*
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

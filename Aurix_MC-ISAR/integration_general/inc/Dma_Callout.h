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
**  $FILENAME   : Dma_Callout.h $                                            **
**                                                                           **
**  $CC VERSION : \main\2 $                                                  **
**                                                                           **
**  $DATE       : 2013-10-03 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This file contains                                        **
**                 - Implementation of DMA callback function                 **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/

#ifndef DMA_CALLOUT_H
#define DMA_CALLOUT_H

#include "Dma.h"
/*******************************************************************************
** Syntax : void Dma_ErrorCallOut(uint8 Channel,uint8 Error)                  **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in) :  Channel - Channel ID                                    **
**                    Error - Error that caused this api call                 **
**                            e.g. DMA_CALLOUT_CH_RESET_ERR is used when      **
**                            channel reset operation isn't yet complete and  **
**                            user is trying to initialize channel registers  **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  void                                                    **
**                                                                            **
** Description :  For Dma_ErrorCallOut function defined in Dma_Callout.c      **
**                                                                            **
*******************************************************************************/
extern void Dma_ErrorCallOut(uint8 Channel, uint8 Error);

#endif

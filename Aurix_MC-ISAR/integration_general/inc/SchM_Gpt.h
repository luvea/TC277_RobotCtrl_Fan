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
**  $FILENAME   : SchM_Gpt.h $                                               **
**                                                                           **
**  $CC VERSION : \main\2 $                                                  **
**                                                                           **
**  $DATE       : 2013-06-20 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This header file exports the exclusive area               **
**                  functions.                                               **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/

#ifndef SCHM_GPT_H
#define SCHM_GPT_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "../../general/inc/Std_Types.h"
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define GPT_EA_GET_TIMEELAPSED           ((uint8)0) 
#define GPT_EA_GET_TIMEREMAINING         ((uint8)1)
#define GPT_EA_GPT_ISR                   ((uint8)2)

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
** Syntax           : void SchM_Enter_Gpt(uint8 Instance, uint8 ExclusiveArea)**
**                                                                            **
** Service ID       : 0x03                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : Instance : Instance Id of the GPT Module                **
**                    ExclusiveArea: Unique Internal resource of GPT Module   **
**                                   to be protected                          **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Enters Module exclusive area                            **
**                                                                            **
*******************************************************************************/
extern void SchM_Enter_Gpt(uint8 Instance, uint8 ExclusiveArea);


/*******************************************************************************
** Syntax           : void SchM_Enter_Gpt(uint8 Instance, uint8 ExclusiveArea)**
**                                                                            **
** Service ID       : 0x04                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : Instance : Instance Id of the GPT Module                **
**                    ExclusiveArea: Unique Internal resource of GPT Module   **
**                                    to be protected                         **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Exits Module exclusive area                             **
**                                                                            **
*******************************************************************************/
extern void SchM_Exit_Gpt(uint8 Instance, uint8 ExclusiveArea);

#endif /* SCHM_GPT_H */

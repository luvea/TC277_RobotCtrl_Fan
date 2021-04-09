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
**  $FILENAME   : SchM_Can_17_MCanP.h $                                      **
**                                                                           **
**  $CC VERSION : \main\6 $                                                  **
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

#ifndef SCHM_CAN_17_MCANP_H
#define SCHM_CAN_17_MCANP_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "../../general/inc/Std_Types.h"
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

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
** Syntax           : void SchM_Enter_Can_17_MCanP_CanDisInt(void)            **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Enters Module exclusive area                            **
**                                                                            **
*******************************************************************************/
extern void SchM_Enter_Can_17_MCanP_CanDisInt(void);

/*******************************************************************************
** Syntax           : void SchM_Exit_Can_17_MCanP_CanDisInt(void)             **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Exits Module exclusive area                             **
**                                                                            **
*******************************************************************************/
extern void SchM_Exit_Can_17_MCanP_CanDisInt(void);

/*******************************************************************************
** Syntax           : void SchM_Enter_Can_17_MCanP_CanEnInt(void)             **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Enters Module exclusive area                            **
**                                                                            **
*******************************************************************************/
extern void SchM_Enter_Can_17_MCanP_CanEnInt(void);

/*******************************************************************************
** Syntax           : void SchM_Exit_Can_17_MCanP_CanEnInt(void)              **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Exits Module exclusive area                             **
**                                                                            **
*******************************************************************************/
extern void SchM_Exit_Can_17_MCanP_CanEnInt(void);

/*******************************************************************************
** Syntax           : void SchM_Enter_Can_17_MCanP_CanWrMO(void)              **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Enters Module exclusive area                            **
**                                                                            **
*******************************************************************************/
extern void SchM_Enter_Can_17_MCanP_CanWrMO(void);

/*******************************************************************************
** Syntax           : void SchM_Exit_Can_17_MCanP_CanWrMO(void)               **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Exits Module exclusive area                             **
**                                                                            **
*******************************************************************************/
extern void SchM_Exit_Can_17_MCanP_CanWrMO(void);

#endif /* SCHM_CAN_17_MCANP_H */

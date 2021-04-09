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
**  $FILENAME   : SchM_Fr_17_Eray.h $                                        **
**                                                                           **
**  $CC VERSION : \main\4 $                                                  **
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

#ifndef SCHM_FR_17_ERAY_H
#define SCHM_FR_17_ERAY_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Std_Types.h"
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
** Syntax           : void SchM_Enter_Fr_17_Eray_ControllerInit(void)         **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Enters Module exclusive area for ControllerInit API     **
**                                                                            **
*******************************************************************************/
extern void SchM_Enter_Fr_17_Eray_ControllerInit(void);


/*******************************************************************************
** Syntax           : void SchM_Enter_Fr_17_Eray_SetWakeupChannel(void)       **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Enters Module exclusive area for SetWakeupChannel API   **
**                                                                            **
*******************************************************************************/
extern void SchM_Enter_Fr_17_Eray_SetWakeupChannel(void);

/*******************************************************************************
** Syntax           : void SchM_Exit_Fr_17_Eray_ControllerInit(void)         **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Exits Module exclusive area for ControllerInit API      **
**                                                                            **
*******************************************************************************/
extern void SchM_Exit_Fr_17_Eray_ControllerInit(void);


/*******************************************************************************
** Syntax           : void SchM_Exit_Fr_17_Eray_SetWakeupChannel(void)       **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Exits Module exclusive area for SetWakeupChannel API    **
**                                                                            **
*******************************************************************************/
extern void SchM_Exit_Fr_17_Eray_SetWakeupChannel(void);

#endif /* SCHM_FR_17_ERAY_H */

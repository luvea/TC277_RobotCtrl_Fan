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
**  $FILENAME   : SchM_Wdg_17_Scu.h $                                        **
**                                                                           **
**  $CC VERSION : \main\7 $                                                  **
**                                                                           **
**  $DATE       : 2013-07-25 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This header file exports the exclusive area                **
**                 functions.                                                **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/
#ifndef SCHM_WDG_H
#define SCHM_WDG_H

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
** Syntax           : void SchM_Enter_Wdg_17_Scu_TimerHandling(void)          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : Instance : Instance Id of the Wdg Module                **
**                    ExclusiveArea: Unique Internal resource of Wdg Module   **
**                                   to be protected                          **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Enters Module exclusive area                            **
**                                                                            **
*******************************************************************************/
extern void SchM_Enter_Wdg_17_Scu_TimerHandling(void);
/*******************************************************************************
** Syntax           : void SchM_Enter_Wdg_17_Scu_Trigger(void)                **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : Instance : Instance Id of the Wdg Module                **
**                    ExclusiveArea: Unique Internal resource of Wdg Module   **
**                                   to be protected                          **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Enters Module exclusive area                            **
**                                                                            **
*******************************************************************************/
extern void SchM_Enter_Wdg_17_Scu_Trigger(void);
/*******************************************************************************
** Syntax           : void SchM_Enter_Wdg_17_Scu_ChangeMode(void)             **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : Instance : Instance Id of the Wdg Module                **
**                    ExclusiveArea: Unique Internal resource of Wdg Module   **
**                                   to be protected                          **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Enters Module exclusive area                            **
**                                                                            **
*******************************************************************************/
extern void SchM_Enter_Wdg_17_Scu_ChangeMode(void);

/*******************************************************************************
** Syntax           : void SchM_Exit_Wdg_17_Scu_TimerHandling(void)           **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : Instance : Instance Id of the Wdg Module                **
**                    ExclusiveArea: Unique Internal resource of Wdg Module   **
**                                   to be protected                          **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Exit Module exclusive area                              **
**                                                                            **
*******************************************************************************/
extern void SchM_Exit_Wdg_17_Scu_TimerHandling(void);
/*******************************************************************************
** Syntax           : void SchM_Exit_Wdg_17_Scu_Trigger(void)                 **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : Instance : Instance Id of the Wdg Module                **
**                    ExclusiveArea: Unique Internal resource of Wdg Module   **
**                                   to be protected                          **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Exit Module exclusive area                              **
**                                                                            **
*******************************************************************************/
extern void SchM_Exit_Wdg_17_Scu_Trigger(void);
/*******************************************************************************
** Syntax           : void SchM_Exit_Wdg_17_Scu_ChangeMode(void)              **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : Instance : Instance Id of the Wdg Module                **
**                    ExclusiveArea: Unique Internal resource of Wdg Module   **
**                                   to be protected                          **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Exit Module exclusive area                              **
**                                                                            **
*******************************************************************************/
extern void SchM_Exit_Wdg_17_Scu_ChangeMode(void);

/*******************************************************************************
** Syntax           : extern void SchM_Enter_Wdg_17_Scu_SafetyInit(void)      **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : Instance : Instance Id of the Wdg Module                **
**                    ExclusiveArea: Unique Internal resource of Wdg Module   **
**                                   to be protected                          **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Enter Module exclusive area                              **
**                                                                            **
*******************************************************************************/

extern void SchM_Enter_Wdg_17_Scu_SafetyInit(void);
/*******************************************************************************
** Syntax           : extern void SchM_Enter_Wdg_17_Scu_SafetyTrigger(void)   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : Instance : Instance Id of the Wdg Module                **
**                    ExclusiveArea: Unique Internal resource of Wdg Module   **
**                                   to be protected                          **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Exit Module exclusive area                              **
**                                                                            **
*******************************************************************************/

extern void SchM_Enter_Wdg_17_Scu_SafetyTrigger(void);
/*******************************************************************************
** Syntax           : extern void SchM_Enter_Wdg_17_Scu_SafetyOffMode(void)   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : Instance : Instance Id of the Wdg Module                **
**                    ExclusiveArea: Unique Internal resource of Wdg Module   **
**                                   to be protected                          **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Exit Module exclusive area                              **
**                                                                            **
*******************************************************************************/

extern void SchM_Enter_Wdg_17_Scu_SafetyOffMode(void);
/*******************************************************************************
** Syntax           : extern void SchM_Exit_Wdg_17_Scu_SafetyInit(void)       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : Instance : Instance Id of the Wdg Module                **
**                    ExclusiveArea: Unique Internal resource of Wdg Module   **
**                                   to be protected                          **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Exit Module exclusive area                              **
**                                                                            **
*******************************************************************************/

extern void SchM_Exit_Wdg_17_Scu_SafetyInit(void);
/*******************************************************************************
** Syntax           : extern void SchM_Exit_Wdg_17_Scu_SafetyTrigger(void)    **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : Instance : Instance Id of the Wdg Module                **
**                    ExclusiveArea: Unique Internal resource of Wdg Module   **
**                                   to be protected                          **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Exit Module exclusive area                              **
**                                                                            **
*******************************************************************************/

extern void SchM_Exit_Wdg_17_Scu_SafetyTrigger(void); 
/*******************************************************************************
** Syntax           : extern void SchM_Exit_Wdg_17_Scu_SafetyOffMode(void)    **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : Instance : Instance Id of the Wdg Module                **
**                    ExclusiveArea: Unique Internal resource of Wdg Module   **
**                                   to be protected                          **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Exit Module exclusive area                              **
**                                                                            **
*******************************************************************************/

extern void SchM_Exit_Wdg_17_Scu_SafetyOffMode(void);




#endif /* SCHM_WDG_H */

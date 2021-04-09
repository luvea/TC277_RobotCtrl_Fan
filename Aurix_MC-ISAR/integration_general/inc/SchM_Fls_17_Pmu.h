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
**  $FILENAME   : SchM_Fls_17_Pmu.h $                                        **
**                                                                           **
**  $CC VERSION : \main\7 $                                                  **
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

#ifndef SCHM_FLS_17_PMU_H
#define SCHM_FLS_17_PMU_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "../../general/inc/Std_Types.h"
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define FLS_EA_INIT           ((uint8)0)
#define FLS_EA_WRITE          ((uint8)1)
#define FLS_EA_ERASE          ((uint8)2)
#define FLS_EA_WRITE_REPAIR   ((uint8)3)
#define FLS_EA_MAIN           ((uint8)4)
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
** Syntax           : void SchM_Enter_Fls_17_Pmu_Init(void)                       **
**                                                                            **
** Service ID       : 0x03                                                    **
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
** Description      : Enters Module exclusive area for Fls_17_Pmu_Init        **
**                                                                            **
*******************************************************************************/
extern void SchM_Enter_Fls_17_Pmu_Init(void);


/*******************************************************************************
** Syntax           : void SchM_Exit_Fls_17_Pmu_Init(void)                    **
**                                                                            **
** Service ID       : 0x04                                                    **
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
** Description      : Exits Module exclusive area for Fls_17_Pmu_Init         **
**                                                                            **
*******************************************************************************/
extern void SchM_Exit_Fls_17_Pmu_Init(void);

/*******************************************************************************
** Syntax           : void SchM_Enter_Fls_17_Pmu_Erase(void)                  **
**                                                                            **
** Service ID       : 0x03                                                    **
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
** Description      : Enters Module exclusive area for Fls_17_Pmu_Erase       **
**                                                                            **
*******************************************************************************/
extern void SchM_Enter_Fls_17_Pmu_Erase(void);


/*******************************************************************************
** Syntax           : void SchM_Exit_Fls_17_Pmu_Erase(void)                   **
**                                                                            **
** Service ID       : 0x04                                                    **
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
** Description      : Exits Module exclusive area for Fls_17_Pmu_Erase        **
**                                                                            **
*******************************************************************************/
extern void SchM_Exit_Fls_17_Pmu_Erase(void);

/*******************************************************************************
** Syntax           : void SchM_Enter_Fls_17_Pmu_Write(void)                  **
**                                                                            **
** Service ID       : 0x03                                                    **
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
** Description      : Enters Module exclusive area for Fls_17_Pmu_Write       **
**                                                                            **
*******************************************************************************/
extern void SchM_Enter_Fls_17_Pmu_Write(void);


/*******************************************************************************
** Syntax           : void SchM_Exit_Fls_17_Pmu_Write(void)                   **
**                                                                            **
** Service ID       : 0x04                                                    **
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
** Description      : Exits Module exclusive area for Fls_17_Pmu_Write        **
**                                                                            **
*******************************************************************************/
extern void SchM_Exit_Fls_17_Pmu_Write(void);

/*******************************************************************************
** Syntax           : void SchM_Enter_Fls_17_Pmu_Main(void)                   **
**                                                                            **
** Service ID       : 0x03                                                    **
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
** Description      : Enters Module exclusive area for Fls_17_Pmu_MainFunction**
**                                                                            **
*******************************************************************************/
extern void SchM_Enter_Fls_17_Pmu_Main(void);


/*******************************************************************************
** Syntax           : void SchM_Exit_Fls_17_Pmu_Main(void)                    **
**                                                                            **
** Service ID       : 0x04                                                    **
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
** Description      : Exits Module exclusive area for Fls_17_Pmu_MainFunction **
**                                                                            **
*******************************************************************************/
extern void SchM_Exit_Fls_17_Pmu_Main(void);

/*******************************************************************************
** Syntax           : void SchM_Enter_Fls_17_Pmu_ResumeErase(void)            **
**                                                                            **
** Service ID       : 0x03                                                    **
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
** Description      : Enters Module exclusive area for 
                      Fls_17_Pmu_ResumeErase                                  **
**                                                                            **
*******************************************************************************/
extern void SchM_Enter_Fls_17_Pmu_ResumeErase(void);


/*******************************************************************************
** Syntax           : void SchM_Exit_Fls_17_Pmu_ResumeErase(void)             **
**                                                                            **
** Service ID       : 0x04                                                    **
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
** Description      : Exits Module exclusive area for Fls_17_Pmu_ResumeErase  **
**                                                                            **
*******************************************************************************/
extern void SchM_Exit_Fls_17_Pmu_ResumeErase(void);
#endif /* SCHM_FLS_H */

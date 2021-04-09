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
**  $FILENAME   : Fee_Fcpt.h $                                               **
**                                                                           **
**  $CC VERSION : \main\6 $                                                  **
**                                                                           **
**  $DATE       : 2013-06-19 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This file contains function pointer table for Fee module, **
**                 required for integration with upper layers or for         ** 
**                 application sharing.                                      **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/
#ifndef  FEE_FCPT_H
#define  FEE_FCPT_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/*
 Inclusion of Fls header file, for access to FLS API interface
*/
#include "Fls_17_Pmu.h"
/*
 Inclusion of Fee header file, for access to FEE API interface
*/
#include "Fee.h"
 
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro like functions                          **
*******************************************************************************/

/*******************************************************************************
**                      GlobalType Definitions                                **
*******************************************************************************/

/* Fee_Header_Const_Type: Generic declaration for saving addresses of APIs 
   in an array of pointers to functions */
typedef void (*Fee_Header_Const_Type)(void);

/*   Typedefs for FEE APIs to be used by MEMIF module */

typedef Std_ReturnType (*Fee_Write_Type)(uint16, uint8 *);

typedef Std_ReturnType (*Fee_Read_Type)(uint16, uint16, uint8 *, uint16);

typedef Std_ReturnType (*Fee_InvalidateBlock_Type)(uint16);

typedef void (*Fee_Cancel_Type)(void);

typedef MemIf_StatusType (*Fee_GetStatus_Type)(void);

typedef MemIf_JobResultType (*Fee_GetJobResult_Type)(void);

typedef Std_ReturnType (*Fee_EraseImmediateBlock_Type)(uint16);

typedef void (*Fee_Init_Type)(void);

typedef void (*Fls_17_Pmu_Init_Type)(const Fls_17_Pmu_ConfigType *);

typedef void (*Fls_17_Pmu_MainFunction_Type)(void);

typedef void (*Fee_MainFunction_Type)(void);

typedef void (*Fee_17_EnableGcStart_Type)(void);

typedef void (*Fee_17_DisableGcStart_Type)(void);

#if (FEE_SET_MODE_SUPPORTED == STD_ON)
typedef void (*Fee_SetMode_Type)(MemIf_ModeType);
#endif

#if (FEE_GET_CYCLE_COUNT_API == STD_ON)
typedef Std_ReturnType (*Fee_GetCycleCount_Type)(uint16, uint32 * const);
#endif

#if (FEE_GET_PREV_DATA_API == STD_ON)
typedef Std_ReturnType (*Fee_17_GetPrevData_Type)(uint16, uint16, uint8 *, uint16);
#endif

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
extern const Fee_Header_Const_Type Fee_Header_Const[];

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

#endif /* FEE_FCPT_H */

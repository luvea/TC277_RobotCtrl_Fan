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
**  $FILENAME   : MemIf.h $                                                  **
**                                                                           **
**  $CC VERSION : \main\2 $                                                  **
**                                                                           **
**  $DATE       : 2013-06-19 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This file exports funtionality of Memory Abstraction      **
**                 Interface                                                 **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/
#ifndef  MEMIF_H_
#define  MEMIF_H_

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Fee_Fcpt.h"


/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/*
    Published paramters
*/ 
/* 
File version information   
*/
#define MEMIF_MAJOR_VERSION  (1U)
#define MEMIF_MINOR_VERSION  (0U)
#define MEMIF_PATCH_VERSION  (0U)

#define MEMIF_MODULE_ID      (0x15)



/*******************************************************************************
**                      Function Like Macro Definitions                       **
*******************************************************************************/

#define  MemIf_Write(DeviceIndex, BlockNumber,DataBufferPtr) \
          ((*(Fee_Write_Type)Fee_Header_Const[0])(BlockNumber,DataBufferPtr))
#define  MemIf_Read(DeviceIndex,BlockNumber,BlockOffset,DataBufferPtr,Length) \
          ((*(Fee_Read_Type)Fee_Header_Const[1])(BlockNumber,BlockOffset,DataBufferPtr,Length))
#define  MemIf_InvalidateBlock(DeviceIndex,BlockNumber) \
          ((*(Fee_InvalidateBlock_Type)Fee_Header_Const[2])(BlockNumber))
#define  MemIf_Cancel(DeviceIndex)         \
          ((*(Fee_Cancel_Type)Fee_Header_Const[3])())
#define  MemIf_GetStatus(DeviceIndex)      \
          ((*(Fee_GetStatus_Type)Fee_Header_Const[4])())
#define  MemIf_GetJobResult(DeviceIndex)   \
          ((*(Fee_GetJobResult_Type)Fee_Header_Const[5])())
#define  MemIf_SetMode(DeviceIndex, Mode) \
          ((*(Fee_SetMode_Type)Fee_Header_Const[6])(mode))
#define  MemIf_EraseImmediateBlock(DeviceIndex, BlockNumber) \
          ((*(Fee_EraseImmediateBlock_Type)Fee_Header_Const[7])(BlockNumber))
#define  MemIf_FeeInit(ConfigPtr) \
          ((*(Fee_Init_Type)Fee_Header_Const[8])(ConfigPtr))
#define  MemIf_FlsInit(ConfigPtr) \
          ((*(Fls_Init_Type)Fee_Header_Const[9])(ConfigPtr))
#define  MemIf_MainFunction() \
          ((*(Fls_MainFunction_Type)Fee_Header_Const[10])())
#define  MemIf_GetCycleCount(DeviceIndex,BlockNumber,CountPtr) \
          ((*(Fee_GetCycleCount_Type)Fee_Header_Const[11])(BlockNumber,CountPtr))
#define  MemIf_GetDetailedStatus(status) \
          ((*(Fee_GetDetailedStatus_Type)Fee_Header_Const[12])(status))
#define  MemIf_GetVersionInfo(versioninfo) \
          ((*(Fee_GetVersionInfo_Type)Fee_Header_Const[13])(versioninfo))



/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/


/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/


/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

 
/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/


#endif /* MEMIF_H_ */

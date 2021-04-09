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
**  $FILENAME   : Det.h $                                                    **
**                                                                           **
**  $CC VERSION : \main\3 $                                                  **
**                                                                           **
**  $DATE       : 2013-06-19 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : Test stub files for Det_ReportError                       **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/

#ifndef _DET_H
#define _DET_H

/******************************************************************************
**                      Include Section                                      **
******************************************************************************/

/* This header file includes all the standard data types, platform dependent
   header file and common return types */
#include "Std_Types.h"

/* This header file includes all the configurable parameters  */
/*#include "Det_Cfg.h"*/

/*This header file includes all the OS resources needed to maintain reentrancy*/
/*#include "os.h"*/

/******************************************************************************
**                      Macro Definitions                                    **
******************************************************************************/

/* Declaring the Vendor ID */
#define DET_VENDOR_ID                                 40U

/* Declaring the module id for DET */
#define DET_MODULE_ID                                 15U

/* File version Information to perform the version check */

#define DET_AR_RELEASE_MAJOR_VERSION                  4U
#define DET_AR_RELEASE_MINOR_VERSION                  0U
#define DET_AR_RELEASE_REVISION_VERSION               2U
  
#define DET_SW_MAJOR_VERSION                          1U
#define DET_SW_MINOR_VERSION                          0U
#define DET_SW_PATCH_VERSION                          0U
                                                             

/******************************************************************************
**                      Global Symbols                                       **
******************************************************************************/

/*Defining the structure to store the parameters of Det Report Error function*/

typedef struct
{  /* It will store the ModuleId of the reporting module */
   uint16 ModuleId;

   /* It will store the index based InstanceId of the reporting module */
   uint8 InstanceId;

   /* It will store the ApiId of the reporting function */
   uint8 ApiId;

   /* It will store the ErrorId of the reporting error */
   uint8 ErrorId;

}tDet_Error ;


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

/* This function is used to clear the logged errors and the reported
   error count */
extern void Det_Init(void);

/* This function is used to log the reported errors and count the reported
   errors */
extern void Det_ReportError(uint16 ModuleId,uint8 InstanceId,uint8 ApiId,uint8 ErrorId);

/* This function is used to return the oldest error logged */
extern uint8 Det_ReadError (tDet_Error* Det_Error );

/* This function is the service for starting after the Det_Init() is called */
extern void Det_Start(void);

#endif /* End of #ifndef _DET_H */

/**************************END OF DET.H******************************************/






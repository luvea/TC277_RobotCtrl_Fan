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
**  $FILENAME   : Dem.h $                                                    **
**                                                                           **
**  $CC VERSION : \main\6 $                                                  **
**                                                                           **
**  $DATE       : 2013-06-19 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : Test Stub file for Dem Module                             **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/

#ifndef     _DEM_H
#define     _DEM_H                

/*******************************************************************************
**                      Includes
*******************************************************************************/
#include "Std_Types.h"
//#include "Dem_PBcfg.h"
#include "Dem_Types.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define DEM_AR_RELEASE_MAJOR_VERSION      (4U)
#define DEM_AR_RELEASE_MINOR_VERSION      (0U)
#define DEM_AR_RELEASE_REVISION_VERSION   (2U)

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
extern void Dem_ReportErrorStatus ( Dem_EventIdType EventId,
                          Dem_EventStatusType EventStatus);

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#endif

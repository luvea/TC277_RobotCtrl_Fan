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
**  $FILENAME   : SafetyReport.h $                                           **
**                                                                           **
**  $CC VERSION : \main\2 $                                                  **
**                                                                           **
**  $DATE       : 2013-06-10 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains prototype of the reporting              **
**                mechanism for safety checks.                               **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/
#include "../../general/inc/Std_Types.h"
#include "../../tricore_general/ssc/inc/Mcal.h"

extern void SafeMcal_ReportError (uint16 ModuleId,uint8 InstanceId,
                                                uint8 ApiId,uint8 ErrorId);




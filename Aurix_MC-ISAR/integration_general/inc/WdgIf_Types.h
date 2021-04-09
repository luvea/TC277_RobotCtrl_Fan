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
**  $FILENAME   : WdgIf_Types.h $                                            **
**                                                                           **
**  $CC VERSION : \main\7 $                                                  **
**                                                                           **
**  $DATE       : 2013-09-05 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file is used for the definitions of types used        **
**                                          by the interface.                **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/

/*---- Protection against multiple inclusion -------------------------------*/
#ifndef WDGIF_TYPES_H
#define WDGIF_TYPES_H

#include "Std_Types.h"

/*---- Version identification - --------------------------------------------*/

  /*refer to WDGIF023*/
#define WDGIF_TYPES_MAJOR_VERSION      (3U)
#define WDGIF_TYPES_MINOR_VERSION      (0U)
#define WDGIF_TYPES_PATCH_VERSION      (0U)

/*---- Switch between external and forward declaration ---------------------*/

/*---- API Type definitions ------------------------------------------------*/

typedef enum
{
    WDGIF_OFF_MODE = 0,
    WDGIF_SLOW_MODE,
    WDGIF_FAST_MODE,
    WDGIF_NO_MODE
} WdgIf_ModeType; /*refer to WDGIF016*/

/*---- Include of configuration (public section) ---------------------------*/

/* #include "WdgIf_Cfg.h" */
/*--------------------------------------------------------------------------*/
#endif  /* End of WdgIf_Types.h */

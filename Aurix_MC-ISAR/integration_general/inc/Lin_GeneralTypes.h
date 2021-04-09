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
**  $FILENAME   : Lin_GeneralTypes.h $                                       **
**                                                                           **
**  $CC VERSION : \main\8 $                                                  **
**                                                                           **
**  $DATE       : 2014-09-02 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This header file exports                                  **
**                 - functionality of Lin driver.                            **
**  [/cover]                                                                 **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/
#ifndef LIN_GENERALTYPES_H
#define LIN_GENERALTYPES_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of Platform_Types.h and Compiler.h */
#include "../../general/inc/Std_Types.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* Ifx Header / response timeout feature support in the Lin driver */
/* uncomment the below define to enable the feature. */
/*
#define LIN_17_TIMEOUT_SUPPORT
*/
/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/* [cover parentID=DS_AS_LIN228,DS_AS403_LIN242,DS_AS403_LIN244] */
/*
Type : Lin_FramePidType  
Represents all valid protected Identifier used by Lin_SendFrame().  
*/
typedef uint8 Lin_FramePidType;
/* [/cover] */

/* [cover parentID=DS_AS_LIN230] */
/*
Type : Lin_FrameResponseType  
This type is used to specify whether the frame processor is required to 
transmit the response part of the LIN frame   
*/
typedef enum 
{
  LIN_MASTER_RESPONSE = 0,
  LIN_SLAVE_RESPONSE,
  LIN_SLAVE_TO_SLAVE
}Lin_FrameResponseType;
/* [/cover] */

/* [cover parentID=DS_AS_LIN229] */
/*
Type : Lin_FrameCsModelType  
This type is used to specify the Checksum model to be used for the LIN Frame   
*/
typedef enum 
{
  LIN_ENHANCED_CS = 0, 
  LIN_CLASSIC_CS
}Lin_FrameCsModelType;
/* [/cover] */

/* [cover parentID=DS_AS_LIN231] */
/*
Type : Lin_FrameDlType   
This type is used to specify the number of SDU data bytes to copy    
*/
typedef uint8 Lin_FrameDlType;
/* [/cover] */

/* [cover parentID=DS_AS_LIN232, DS_AS_LIN014, DS_AS_LIN015, DS_AS_LIN096] */
/*
Type : Lin_PduType   
This Type is used to provide PID, checksum model, data length and SDU pointer 
from the LIN Interface to the LIN driver     
*/
typedef struct Lin_Pdu
{
  Lin_FramePidType         Pid; 
  Lin_FrameCsModelType     Cs;         
  Lin_FrameResponseType    Drc;        
  Lin_FrameDlType          Dl;    
  uint8                    *SduPtr;
}Lin_PduType;
/* [/cover] */

/* [cover parentID=DS_AS_LIN233, DS_AS403_LIN200,DS_NAS_PR228_10] */
/*
Type : Lin_StatusType   
LIN operation states for a LIN channel or frame, as returned by the API 
service Lin_17_GetStatus().      
*/
typedef enum
{
  LIN_NOT_OK = 0,
  LIN_TX_OK,
  LIN_TX_BUSY,
  LIN_TX_HEADER_ERROR,
  LIN_TX_ERROR,
  LIN_RX_OK,
  LIN_RX_BUSY,
  LIN_RX_ERROR,
  LIN_RX_NO_RESPONSE,
  LIN_OPERATIONAL,
  LIN_CH_SLEEP,
#ifdef LIN_17_TIMEOUT_SUPPORT
  LIN_TX_HEADER_TIMEOUT_ERROR,
  LIN_RX_RESPONSE_TIMEOUT_ERROR
#endif
}Lin_StatusType;
/* [/cover] */


/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif /* LIN_GENERALTYPES_H */


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
**  $FILENAME   : CanIf.h $                                                  **
**                                                                           **
**  $CC VERSION : \main\9 $                                                  **
**                                                                           **
**  $DATE       : 2014-12-09 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This header file exports                                  **
**                    -  CAN interface function declaration                  **
**                    -  CAN Interface global type definitions               **
**                 Note: This file is for Evaluation Purpose Only            **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/


#ifndef CANIF_H 
#define CANIF_H 

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "CanIf_Types.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

#define CANIF_AR_RELEASE_MAJOR_VERSION     (4U)
#define CANIF_AR_RELEASE_MINOR_VERSION     (0U)
#define CANIF_AR_RELEASE_REVISION_VERSION  (2U)


#define CANIF_TRCV_WU_ERROR            ((CanIf_TrcvWakeupReasonType)(0))
#define CANIF_TRCV_WU_NOT_SUPPORTED    ((CanIf_TrcvWakeupReasonType)(1))
#define CANIF_TRCV_WU_BY_BUS           ((CanIf_TrcvWakeupReasonType)(2))
#define CANIF_TRCV_WU_INTERNALLY       ((CanIf_TrcvWakeupReasonType)(3))
#define CANIF_TRCV_WU_RESET            ((CanIf_TrcvWakeupReasonType)(4))
#define CANIF_TRCV_WU_POWER_ON         ((CanIf_TrcvWakeupReasonType)(5))



/* CanTrcv Modes */
#define CANIF_TRCV_MODE_NORMAL         ((CanIf_TransceiverModeType)(0))
#define CANIF_TRCV_MODE_STANDBY        ((CanIf_TransceiverModeType)(1))
#define CANIF_TRCV_MODE_SLEEP          ((CanIf_TransceiverModeType)(2))

#define CANIF_TRCV_WU_ENABLE           ((CanIf_TrcvWakeupModeType)(0))
#define CANIF_TRCV_WU_DISABLE          ((CanIf_TrcvWakeupModeType)(1))
#define CANIF_TRCV_WU_CLEAR            ((CanIf_TrcvWakeupModeType)(2))

#define CANIF_CONTROLLER_WAKEUP        ((CanIf_WakeupSourceType)(0))
#define CANIF_TRANSCEIVER_WAKEUP       ((CanIf_WakeupSourceType)(0))

#define CANIF_CS_UNINIT   ((CanIf_ControllerModeType)0)
#define CANIF_CS_SLEEP    ((CanIf_ControllerModeType)1)
#define CANIF_CS_STARTED  ((CanIf_ControllerModeType)2)
#define CANIF_CS_STOPPED  ((CanIf_ControllerModeType)3)


#define CANTRCV_WU_ERROR            ((CanTrcv_TrcvWakeupReasonType)(0))
#define CANTRCV_WU_NOT_SUPPORTED    ((CanTrcv_TrcvWakeupReasonType)(1))
#define CANTRCV_WU_BY_BUS           ((CanTrcv_TrcvWakeupReasonType)(2))
#define CANTRCV_WU_INTERNALLY       ((CanTrcv_TrcvWakeupReasonType)(3))
#define CANTRCV_WU_RESET            ((CanTrcv_TrcvWakeupReasonType)(4))
#define CANTRCV_WU_POWER_ON         ((CanTrcv_TrcvWakeupReasonType)(5))
#define CANTRCV_WU_BY_PIN           ((CanTrcv_TrcvWakeupReasonType)(6))


/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

extern void CanIf_CheckWakeup(CanIf_WakeupSourceType WakeupSource );
                                   
extern void CanIf_SetWakeupEvent(uint8 CanNetwork,
                                   CanIf_WakeupSourceType WakeupSource );
                                   
extern void CanIf_TrcvModeIndication(uint8 Transceiver,CanTrcv_TrcvModeType OpMode );

void CanIf_CheckTrcvWakeFlagIndication(uint8 Transceiver);

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#endif
  /*END OF  CANIF_H */



/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $ FILENAME  : Pwm_17_Gtm_PBCfg.c $                                        **
**                                                                            **
**  $CC VERSION : \main\39 $                                                 **
**                                                                            **
**  DATE, TIME: 2021-04-08, 20:15:41                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**   AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                            **
**   VENDOR    : Infineon Technologies                                        **
**                                                                            **
**  DESCRIPTION  : PWM configuration generated out of ECU configuration       **
**                   file                                                     **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Include module header File */ 
#include "Pwm_17_Gtm.h"
#include "Gtm.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*Notes on Requirements:
PWM040: General Limitation: All Channels should have same frequency
        to be observed by the user.
*/
/*
Configuration:
PWM Channel Configuration:
Elements / Attributes
1. Notification function pointer (if required)
2. Shift Value, only for PWM_FIXED_PERIOD_SHIFTED Class
   Input a value between 0 and 0x8000.
3. Default Duty Cycle ( duty cycle value between
   0 and 0x8000)
4. Pwm_Period:
   Enter in ticks
   PWM070: All time units should be in ticks.
5. Pwm_ConfigChannel:
   Go in the following parameter order
   a) Reference to Channel Number, for a Shifted, Center Aligned and
   Zero Shifted channel, a reference must be given. For a variable
   and Fixed Period channel class, reference should not be given.
   Reference should be given in the form of channel number index.
   b) Channel Class
      Possible Options: PWM_FIXED_PERIOD, PWM_FIXED_PERIOD_SHIFTED,
      PWM_FIXED_PERIOD_CENTER_ALIGNED, PWM_VARIABLE_PERIOD
   c) Channel Idle State:
      Possible Options: PWM_LOW, PWM_HIGH
      Output line goes into Idle state either after Pwm_SetOutputtoIdle
      or Pwm_DeInit.
   d) Channel Polarity:
      Possible Options: PWM_LOW, PWM_HIGH
      Initial Polarity state of the channel.
   e) Assigned HW Resource:
      TOM/ATOM Channel Number.
6. PwmSafetySignalType to indicate Chanel is ASIL or QM
   Needed only when safety is enabled
7. PwmSafetyChannelIndex to store the channel index of
   ASIL or QM signal.
 */

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*
Function Like Macro:Pwm_lConfigChannel
Macro that packs the PWM Channel Information.
Input Parameters:
ShiftReset: Shifted channel is reset by itself or by other channel
ShiftedSpl: Special handling of shifted channel is enabled or not
IsReferenceChannel:Is the channel reference to other channel or not
ReferenceChannel : Reference Channel
ChannelClass : Channel Class
ChannelCoherency : Channel Coherency
IdleState : Idle State
Polarity : Channel Polarity
AssignedHwUnit : Hardware Unit Used
*/ 
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro is uded to reduce the 
  memory usage*/
#define Pwm_lConfigChannel(ShiftReset,                   \
                           ShiftedSpl,                   \
                           IsReferenceChannel,           \
                           ReferenceChannel,             \
                           ChannelClass,                 \
                           ChannelCoherency,             \
                           IdleState,                    \
                           Polarity,                     \
                           AssignedHwUnit)               \
              ((uint32)( ((uint32)(ShiftReset) << 22UL)         |   \
                         ((uint32)(ShiftedSpl) << 21UL)         |   \
                         ((uint32)(IsReferenceChannel) << 20UL) |   \
                         ((uint32)(ReferenceChannel) << 13UL)   |   \
                         ((uint32)(ChannelClass) << 11UL)       |   \
                         ((uint32)(ChannelCoherency) << 10UL)   |   \
                         ((uint32)(IdleState) << 9UL)           |   \
                         ((uint32)(Polarity) << 8UL)            |   \
                         ((uint32)(AssignedHwUnit))                 \
                       )) 

/******************************************************************************/
#define PWM_17_GTM_START_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
  allowed only for MemMap.h*/
#include "MemMap.h"
/******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
static const Pwm_17_Gtm_ChannelConfigType Pwm_kChannelConfiguration0[] = 
{

/* 
 *  Channel Number        : 0
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_REF_RES 
 *  Channel Class         : PWM_FIXED_PERIOD
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        0U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        1U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        PWM_NOT_REFERENCED,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_ATOM1_CHANNEL0 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)5000, /* Default Period */
    (uint32)16384, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)0  /*Qm Channel Index*/
  },

/* 
 *  Channel Number        : 1
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_UH 
 *  Channel Class         : PWM_FIXED_PERIOD_CENTER_ALIGNED
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        1U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        0U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_REF_RES,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD_CENTER_ALIGNED,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_ATOM1_CHANNEL1 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)0, /* Default Period */
    (uint32)16384, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)1  /*Qm Channel Index*/
  },

/* 
 *  Channel Number        : 2
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_UL 
 *  Channel Class         : PWM_FIXED_PERIOD_CENTER_ALIGNED
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        1U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        0U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_REF_RES,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD_CENTER_ALIGNED,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_ATOM1_CHANNEL2 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)0, /* Default Period */
    (uint32)16384, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)2  /*Qm Channel Index*/
  },

/* 
 *  Channel Number        : 3
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_VH 
 *  Channel Class         : PWM_FIXED_PERIOD_CENTER_ALIGNED
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        1U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        0U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_REF_RES,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD_CENTER_ALIGNED,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_ATOM1_CHANNEL3 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)0, /* Default Period */
    (uint32)16384, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)3  /*Qm Channel Index*/
  },

/* 
 *  Channel Number        : 4
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_VL 
 *  Channel Class         : PWM_FIXED_PERIOD_CENTER_ALIGNED
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        1U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        0U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_REF_RES,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD_CENTER_ALIGNED,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_ATOM1_CHANNEL4 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)0, /* Default Period */
    (uint32)16384, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)4  /*Qm Channel Index*/
  },

/* 
 *  Channel Number        : 5
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_WH 
 *  Channel Class         : PWM_FIXED_PERIOD_CENTER_ALIGNED
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        1U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        0U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_REF_RES,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD_CENTER_ALIGNED,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_ATOM1_CHANNEL5 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)0, /* Default Period */
    (uint32)16384, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)5  /*Qm Channel Index*/
  },

/* 
 *  Channel Number        : 6
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_WL 
 *  Channel Class         : PWM_FIXED_PERIOD_CENTER_ALIGNED
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        1U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        0U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_REF_RES,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD_CENTER_ALIGNED,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_ATOM1_CHANNEL6 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)0, /* Default Period */
    (uint32)16384, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)6  /*Qm Channel Index*/
  },

/* 
 *  Channel Number        : 7
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M2_PWM_REF_RES 
 *  Channel Class         : PWM_FIXED_PERIOD
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        0U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        1U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        PWM_NOT_REFERENCED,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_TOM0_CHANNEL0 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)5000, /* Default Period */
    (uint32)16384, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)7  /*Qm Channel Index*/
  },

/* 
 *  Channel Number        : 8
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M2_PWM_UH 
 *  Channel Class         : PWM_FIXED_PERIOD_CENTER_ALIGNED
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        1U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        0U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        Pwm_17_GtmConf_PwmChannel_DPO_M2_PWM_REF_RES,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD_CENTER_ALIGNED,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_TOM0_CHANNEL1 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)0, /* Default Period */
    (uint32)16384, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)8  /*Qm Channel Index*/
  },

/* 
 *  Channel Number        : 9
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M2_PWM_UL 
 *  Channel Class         : PWM_FIXED_PERIOD_CENTER_ALIGNED
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        1U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        0U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        Pwm_17_GtmConf_PwmChannel_DPO_M2_PWM_REF_RES,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD_CENTER_ALIGNED,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_TOM0_CHANNEL2 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)0, /* Default Period */
    (uint32)16384, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)9  /*Qm Channel Index*/
  },

/* 
 *  Channel Number        : 10
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M2_PWM_VH 
 *  Channel Class         : PWM_FIXED_PERIOD_CENTER_ALIGNED
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        1U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        0U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        Pwm_17_GtmConf_PwmChannel_DPO_M2_PWM_REF_RES,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD_CENTER_ALIGNED,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_TOM0_CHANNEL3 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)0, /* Default Period */
    (uint32)16384, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)10  /*Qm Channel Index*/
  },

/* 
 *  Channel Number        : 11
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M2_PWM_VL 
 *  Channel Class         : PWM_FIXED_PERIOD_CENTER_ALIGNED
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        1U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        0U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        Pwm_17_GtmConf_PwmChannel_DPO_M2_PWM_REF_RES,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD_CENTER_ALIGNED,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_TOM0_CHANNEL4 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)0, /* Default Period */
    (uint32)16384, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)11  /*Qm Channel Index*/
  },

/* 
 *  Channel Number        : 12
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M2_PWM_WH 
 *  Channel Class         : PWM_FIXED_PERIOD_CENTER_ALIGNED
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        1U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        0U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        Pwm_17_GtmConf_PwmChannel_DPO_M2_PWM_REF_RES,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD_CENTER_ALIGNED,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_TOM0_CHANNEL5 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)0, /* Default Period */
    (uint32)16384, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)12  /*Qm Channel Index*/
  },

/* 
 *  Channel Number        : 13
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M2_PWM_WL 
 *  Channel Class         : PWM_FIXED_PERIOD_CENTER_ALIGNED
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        1U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        0U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        Pwm_17_GtmConf_PwmChannel_DPO_M2_PWM_REF_RES,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD_CENTER_ALIGNED,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_TOM0_CHANNEL6 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)0, /* Default Period */
    (uint32)16384, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)13  /*Qm Channel Index*/
  },

/* 
 *  Channel Number        : 14
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M3_PWM_REF_RES 
 *  Channel Class         : PWM_FIXED_PERIOD
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        0U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        1U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        PWM_NOT_REFERENCED,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_ATOM4_CHANNEL0 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)5000, /* Default Period */
    (uint32)16384, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)14  /*Qm Channel Index*/
  },

/* 
 *  Channel Number        : 15
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M3_PWM_UH 
 *  Channel Class         : PWM_FIXED_PERIOD_CENTER_ALIGNED
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        1U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        0U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        Pwm_17_GtmConf_PwmChannel_DPO_M3_PWM_REF_RES,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD_CENTER_ALIGNED,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_ATOM4_CHANNEL1 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)0, /* Default Period */
    (uint32)16384, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)15  /*Qm Channel Index*/
  },

/* 
 *  Channel Number        : 16
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M3_PWM_UL 
 *  Channel Class         : PWM_FIXED_PERIOD_CENTER_ALIGNED
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        1U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        0U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        Pwm_17_GtmConf_PwmChannel_DPO_M3_PWM_REF_RES,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD_CENTER_ALIGNED,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_ATOM4_CHANNEL2 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)0, /* Default Period */
    (uint32)16384, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)16  /*Qm Channel Index*/
  },

/* 
 *  Channel Number        : 17
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M3_PWM_VH 
 *  Channel Class         : PWM_FIXED_PERIOD_CENTER_ALIGNED
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        1U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        0U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        Pwm_17_GtmConf_PwmChannel_DPO_M3_PWM_REF_RES,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD_CENTER_ALIGNED,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_ATOM4_CHANNEL3 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)0, /* Default Period */
    (uint32)16384, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)17  /*Qm Channel Index*/
  },

/* 
 *  Channel Number        : 18
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M3_PWM_VL 
 *  Channel Class         : PWM_FIXED_PERIOD_CENTER_ALIGNED
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        1U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        0U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        Pwm_17_GtmConf_PwmChannel_DPO_M3_PWM_REF_RES,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD_CENTER_ALIGNED,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_ATOM4_CHANNEL4 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)0, /* Default Period */
    (uint32)16384, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)18  /*Qm Channel Index*/
  },

/* 
 *  Channel Number        : 19
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M3_PWM_WH 
 *  Channel Class         : PWM_FIXED_PERIOD_CENTER_ALIGNED
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        1U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        0U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        Pwm_17_GtmConf_PwmChannel_DPO_M3_PWM_REF_RES,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD_CENTER_ALIGNED,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_ATOM4_CHANNEL5 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)0, /* Default Period */
    (uint32)16384, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)19  /*Qm Channel Index*/
  },

/* 
 *  Channel Number        : 20
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M3_PWM_WL 
 *  Channel Class         : PWM_FIXED_PERIOD_CENTER_ALIGNED
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        1U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        0U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        Pwm_17_GtmConf_PwmChannel_DPO_M3_PWM_REF_RES,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD_CENTER_ALIGNED,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_ATOM4_CHANNEL6 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)0, /* Default Period */
    (uint32)16384, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)20  /*Qm Channel Index*/
  },

/* 
 *  Channel Number        : 21
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M4_PWM_REF_RES 
 *  Channel Class         : PWM_FIXED_PERIOD
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        0U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        1U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        PWM_NOT_REFERENCED,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_ATOM0_CHANNEL0 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)5000, /* Default Period */
    (uint32)16384, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)21  /*Qm Channel Index*/
  },

/* 
 *  Channel Number        : 22
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M4_PWM_UH 
 *  Channel Class         : PWM_FIXED_PERIOD_CENTER_ALIGNED
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        1U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        0U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        Pwm_17_GtmConf_PwmChannel_DPO_M4_PWM_REF_RES,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD_CENTER_ALIGNED,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_ATOM0_CHANNEL1 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)0, /* Default Period */
    (uint32)16384, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)22  /*Qm Channel Index*/
  },

/* 
 *  Channel Number        : 23
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M4_PWM_UL 
 *  Channel Class         : PWM_FIXED_PERIOD_CENTER_ALIGNED
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        1U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        0U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        Pwm_17_GtmConf_PwmChannel_DPO_M4_PWM_REF_RES,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD_CENTER_ALIGNED,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_ATOM0_CHANNEL2 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)0, /* Default Period */
    (uint32)16384, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)23  /*Qm Channel Index*/
  },

/* 
 *  Channel Number        : 24
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M4_PWM_VH 
 *  Channel Class         : PWM_FIXED_PERIOD_CENTER_ALIGNED
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        1U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        0U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        Pwm_17_GtmConf_PwmChannel_DPO_M4_PWM_REF_RES,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD_CENTER_ALIGNED,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_ATOM0_CHANNEL3 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)0, /* Default Period */
    (uint32)16384, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)24  /*Qm Channel Index*/
  },

/* 
 *  Channel Number        : 25
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M4_PWM_VL 
 *  Channel Class         : PWM_FIXED_PERIOD_CENTER_ALIGNED
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        1U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        0U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        Pwm_17_GtmConf_PwmChannel_DPO_M4_PWM_REF_RES,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD_CENTER_ALIGNED,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_ATOM0_CHANNEL4 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)0, /* Default Period */
    (uint32)16384, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)25  /*Qm Channel Index*/
  },

/* 
 *  Channel Number        : 26
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M4_PWM_WH 
 *  Channel Class         : PWM_FIXED_PERIOD_CENTER_ALIGNED
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        1U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        0U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        Pwm_17_GtmConf_PwmChannel_DPO_M4_PWM_REF_RES,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD_CENTER_ALIGNED,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_ATOM0_CHANNEL5 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)0, /* Default Period */
    (uint32)16384, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)26  /*Qm Channel Index*/
  },

/* 
 *  Channel Number        : 27
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M4_PWM_WL 
 *  Channel Class         : PWM_FIXED_PERIOD_CENTER_ALIGNED
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        1U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        0U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        Pwm_17_GtmConf_PwmChannel_DPO_M4_PWM_REF_RES,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD_CENTER_ALIGNED,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_ATOM0_CHANNEL6 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)0, /* Default Period */
    (uint32)16384, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)27  /*Qm Channel Index*/
  },

/* 
 *  Channel Number        : 28
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_ADCTRIGGER 
 *  Channel Class         : PWM_FIXED_PERIOD_CENTER_ALIGNED
*/
  {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
NULL_PTR, /* Notification function */
#endif
    Pwm_lConfigChannel(
                        1U,/* Channel reset from other channel or not*/
                        0U,/*Shift special handling*/
                        0U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_REF_RES,
                        /* reference to the channel number */
                        PWM_FIXED_PERIOD_CENTER_ALIGNED,/* Channel Class */
                        STD_ON,/* Coherency */
                        PWM_LOW, /* channel Idle state */
                        PWM_LOW, /* channel polarity */
                        GTM_ATOM1_CHANNEL7 /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)0, /* Default Period */
    (uint32)4000, /* Default Duty Cycle */
    (uint32)0, /* Shift Value */
    (uint8)28  /*Qm Channel Index*/
  }
};





/*
Configuration:
1. Marker (if safety is enabled)
2. Address of Channel Configuration structure.
3. No of channels
4. Address of Group Configuration(if SyncGroup is enabled)
5. Number of groups(if SyncGroup is enabled)
*/

const Pwm_17_Gtm_ConfigType Pwm_ConfigRoot[1] =
{
  {
    /* No of channels */
    (Pwm_17_Gtm_ChannelType)29U, 
    /* Pwm Channel Configuration */
    &Pwm_kChannelConfiguration0[0]  }
};


#define PWM_17_GTM_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
  allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

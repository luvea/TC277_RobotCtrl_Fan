/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2015)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME  : Pwm_17_Gtm.c $                                              **
**                                                                           **
**  $CC VERSION : \main\123 $                                                **
**                                                                           **
**   $DATE       : 2016-07-27 $                                               **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : This file contains functionality of Pwm driver            **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

/******************************************************************************
**                                                                           **
** Traceabilty      :                                                        **
** [cover parentID=SAS_MCAL_SWSC_0108] [/cover]                              **
** [cover parentID=DS_MCAL_PWM_0912] [/cover]                                **
** [cover parentID=SAS_AS_PWM075a] [/cover]                                  **
** [cover parentID=SAS_AS_PWM075b] [/cover]                                  **
** [cover parentID=SAS_AS_PWM075c] [/cover]                                  **
** [cover parentID=SAS_AS_PWM075e] [/cover]                                  **
** [cover parentID=SAS_AS_PWM075f] [/cover]                                  **
** [cover parentID=DS_NAS_PWM_PR912] [/cover]                                **
** [cover parentID=DS_NAS_PWM_PR69_PR469] [/cover]                           **
** [cover parentID=DS_NAS_PWM_PR734] [/cover]                                **
** [cover parentID=SAS_MCAL_PWM_0900] [/cover]                               **
** [cover parentID=SAS_NAS_ALL_PR749] [/cover]                               **
** [cover parentID=SAS_NAS_ALL_PR470] [/cover]                               **
** [cover parentID=SAS_NAS_ALL_PR70] [/cover]                                **
** [cover parentID=SAS_NAS_ALL_PR1652] [/cover]                              **
** [cover parentID=SAS_NAS_ALL_PR630_PR631] [/cover]                         **
**                                                                           **
** [cover parentID=DS_NAS_EP_PWM_PR3054] [/cover]                            **
**                                                                           **
** [cover parentID=DS_NAS_HE2_PWM_PR3054] [/cover]                           **
**                                                                           **
******************************************************************************/

/******************************************************************************
**                      Includes                                             **
******************************************************************************/
/* Inclusion of Tasking sfr file */
#include "IfxGtm_reg.h"
/* Include Mcal.h to import the library functions */
#include "Mcal.h"
/* GTM Header file */
#include "Gtm.h"
/* Pwm Module header file, this includes Pwm Static configuration file also */
#include "Pwm_17_Gtm.h"
/*Pwm module's version details */
#include "Pwm_17_Gtm_Ver.h"
/* Coding Guideline violation */
/*
Brackets are not used in case of Mcal_SetAtomic.
This is mainly due to the usage of inline assembly statement
for ldmst. Also the last parameter will not have U subscript
or any specific typecast, as the generated assembly statement
would not compile.
*/

/******************************************************************************
**                      Imported Compiler Switch Check                       **
******************************************************************************/
/******************************************************************************
**                                                                           **
** Traceabilty      :                                                        **
** [cover parentID=DS_AS4XX_PWM029] [/cover]                                 **
** [cover parentID=DS_AS_PWM104] [/cover]                                    **
** [cover parentID=DS_NAS_PWM_PR730] [/cover]                                **
** [cover parentID=DS_NAS_PWM_PR915] [/cover]                                **
**                                                                           **
******************************************************************************/
/* General Notes on Requirments:
PWM077: PWM module supports Variant PB delivery.
PWM079: Variant PC is limited to pre-compile configuration parameters only.
        This delivery deals with Variant PB.
PWM001: PWM Driver doesnt cover a PWM emulation on a general purpose I/O.
PWM073: Lower level interfaces are not required in PWM.
PWM065: Code file structure shall not be defined within specification.
PWM066: Inclusion of Dem.h file, as there are no run time errors, the
        file need not be included.
PWM067: Production of DEM Error Codes cannot be switched off. Not Applicable
        here.
PWM005: Reporting of DEM. NA here.
PWM006: Additional errors to be documented. No additional errors in this
        delivery.
PWM074: Calling of Optional Interfaces like Det_ReportError.
*/


/******************************************************************************
**                      Private Macro Definitions                            **
******************************************************************************/
#if (PWM_DUTY_SHIFT_IN_TICKS == STD_OFF)
  /* To shift by 15 */
#define PWM_SHIFT_BY15             ((uint32)(15))
#endif

/* To Enable any bit of register */
#define PWM_BIT_SET                (1U)

/* To Disable any bit of register */
#define PWM_BIT_RESET              (0U)

/* if DET enabled */
#if  ((PWM_DEV_ERROR_DETECT == STD_ON)|| (PWM_SAFETY_ENABLE == STD_ON))
/* PWM003: */
/* To indicate error found or not */
#define PWM_ERROR_FOUND            ((uint32)1)
#endif /* PWM_DEV_ERROR_DETECT */

#if ( (PWM_DUTY_SHIFT_IN_TICKS == STD_OFF) || \
                                   (PWM_NOTIFICATION_SUPPORTED == STD_ON))
/* Maximum Duty Cycle value  PWM059: */
#define PWM_MAX_DUTY               ((uint16)0x8000)
#endif
/* ( (PWM_DUTY_SHIFT_IN_TICKS == STD_OFF) ||
                                   (PWM_NOTIFICATION_SUPPORTED == STD_ON)) */

/*Pwm Channel Info has the following positions */
/* Channel Mode Positions */
#define PWM_CHANNEL_MODE_POS          ((uint32)0xB)
#define PWM_CHANNEL_MODE_MAX          ((uint32)0x3)
/* Idle state  Position */
#define PWM_IDLESTATE_POS             (0x9U)
#define PWM_IDLESTATE_MAX             ((uint32)0x1)
/* Polarity Position */
#define PWM_POLSTATE_POS              (0x8U)
#define PWM_POLSTATE_MAX              ((uint32)0x1)
/*Special shift handling*/
#define PWM_SPLSHFT_POS              (21U)
#define PWM_SPLSHFTSTATE_MAX         ((uint32)0x1)
/*Channel Reset Information*/
#define PWM_RSTSHFT_POS              (22U)
#define PWM_RSTSHFTSTATE_MAX         ((uint32)0x1)
/* Idle state  Position */
#define PWM_COHERENCY_POS             (0xAU)
#define PWM_COHERENCY_MAX             ((uint32)0x1)

#if ( (PWM_FIXED_PERIOD_USED == STD_ON) || (PWM_SET_DUTY_CYCLE_API == STD_ON) )
/* Reference state Position */
#define PWM_ISREFERENCE_POS           (0x14U)
#define PWM_ISREFERENCE_MAX           ((uint32)0x1)
#endif /* (PWM_FIXED_PERIOD_USED == STD_ON) */

#if ((PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON) || \
                              (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON))
/* Reference Channel Position */
#define PWM_REFERENCE_CHAN_POS        (13U)
/* lower 7-Bit mask to get the channel ID */
#define PWM_7BIT_MASK                 (0x7FU)
#endif

/* Assigned Hw unit Position */
#define PWM_HWUNIT_POS                ((uint8)(0xFF))

/* Not required for ChannelKind as it will be asserted during
   call of Pwm_Init() and Pwm_DeInit() functions */
#if  (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/* The following flags are used within
   Pwm_GlobChn variable, each bit position signifies
   a specific property
   */

/* Position of Notification Status Bit */
#define PWM_NOTIFI_STATUS_POS                 (4U)
/* Position of Notification edges */
#define PWM_NOTIFI_EDGE_POS                   (5)
/* Duty update Flag position */
#define PWM_DUTY_0_OR_100_UPDATE_FLGPOS       (7U)
/* No of Notification edge bits
Value should not have subscript 'U' as it is used
in Mcal_SetAtomic.*/
#define PWM_NOTIFI_EDGE_BITS                  (2)
/*  Mask to obtain Notification Edge Position */
#define PWM_NOTIFICATION_EDGE_MASK            ((uint32)(0x00000060))
/* Mask to obtain Duty Update bit */
#define PWM_DUTY_0_OR_100_UPDATE_MASK         ((uint32)(0x00000080))
/* Mask to obtain Notification Status bit */
#define PWM_NOTIFI_STATUS_MASK                ((uint32)(0x00000010))

#define PWM_NO_NOTIFICATION             ((Pwm_17_Gtm_EdgeNotificationType)0)
#endif /* PWM_NOTIFICATION_SUPPORTED */

/* Clear all pending interrupts */
#define PWM_CLR_PENDING_INTERRUPTS            (0x00000003UL)

/* Duty update Flag position */
#define PWM_IDLE_CHANNEL_FLAG_POS             (8U)
/*  Mask to obtain Idle Status Position */
#define PWM_IDLE_STATUS_MASK                  ((uint32)(0x00000100))

/* Maximum Timer Value */
#define PWM_MAX_TIMER            ((uint32)0xFFFFFEU)
#define PWM_MAX_TIMER_TOM          ((uint32)0xFFFEU)

#if ( (PWM_PB_FIXEDADDR == STD_ON) && (PWM_DEV_ERROR_DETECT == STD_ON) )
/* Status to indicate that PWM is initialized */
#define PWM_INITIALIZED                ((uint8)1)

#if (PWM_DE_INIT_API == STD_ON)
/* Status to indicate that PWM is de-initailized */
#define PWM_DEINITIALIZED              ((uint8)0)
#endif /* (PWM_DE_INIT_API == STD_ON) */

#endif /* (PWM_PB_FIXEDADDR == STD_ON) && (PWM_DEV_ERROR_DETECT == STD_ON) */

/* TOM Bit positions */
#define PWM_GTM_CTRL_SL             ((uint32)11)
#define PWM_GTM_CTRL_TRIGOUT        (24U)
#define PWM_GTM_CTRL_RST_CCU0       (20U)

/* Used for referring Pwm_17_Gtm_PropertyType */
#define PWM_SHIFTED_RELATED_CHANNEL (1U)
#define PWM_SHIFTED_CHANNEL         (1U)
#define PWM_NORMAL_CHANNEL          (0U)

#define PWM_IDLE_CHANNEL            (1U)

#define PWM_NON_COHERENT            (0U)
#define PWM_COHERENT                (1U)

/* PWM Channel ID's status bits, used to change the status os the channel */
#define PWM_CHAN_ID_STAT_BITS       (1)

#define PWM_CONST_32                (32U)
#define PWM_CONST_16                (16U)

#if  (PWM_NOTIFICATION_SUPPORTED == STD_ON)
#define PWM_CONST_3                 (3U)
#endif

#define PWM_CONST_2                 (2U)

#define PWM_INVALID_NUMBER (0xFFU)

/* Tgc global control register mask for Update Enable for Coherant update */

#define PWM_TGC_GLB_CLR_MASK        (0xFFFFFF01U)
#define PWM_ZERO_U                  (0U)
#define PWM_ONE_U                   (1U)
#define PWM_ENDIS_CLR_MASK          (0x0000FFFFUL)
#define PWM_OUTEN_CLR_MASK          (0x0000FFFFUL)
#define PWM_CTRL_SL_SET_CL_MASK      (0x01107800U)
#define PWM_ATOM_CTRL_SL_SET_CL_MASK (0x01107803U)
#define PWM_CTRL_SL_SET_ST_MASK      (0x00000800U)
#define PWM_CTRL_SL_CLR_CL_MASK      (0x01107000U)
#define PWM_CTRL_RST_CLR_CL_MASK     (0x01007800U)
#define PWM_ATOM_CTRL_SL_CLR_CL_MASK (0x01107003U)
#define PWM_ATOM_CTRL_RST_CLR_MASK   (0x01007803U)
/******************************************************************************
**                      Private Macro like functions                         **
******************************************************************************/
/******************************************************************************
**                      Private Type Definitions                             **
******************************************************************************/
/* Type for PwmPropery */
typedef struct
  {
    unsigned_int Polarity:1;     /* PWM_POLARITY_HIGH or PWM_POLARITY_LOW    */
    unsigned_int Coherency:1;    /* PWM_NON_COHERENT or PWM_COHERENT         */
    unsigned_int ChannelType:1;  /* PWM_SHIFTED_CHANNEL or PWM_NORMAL_CHANNEL*/
    unsigned_int IsReference:1;  /* PWM_REFERENCE_CHANNEL or
                                    PWM_NOT_REFERENCE_CHANNEL                */
    unsigned_int PreviousState:1;/* PWM_IDLE_CHANNEL or PWM_ACTIVE_CHANNEL   */
    unsigned_int ShiftedSpl:1;   /*Specially handled shifted channel         */
    unsigned_int ResetShift:1;   /*Reset value for shifted channel           */
    unsigned_int Padding:1;
    unsigned_int RefChannelId:8; /*Channel Id of reference channel           */
    unsigned_int Reserved:16;
  }Pwm_17_Gtm_PropertyType;

/* Structure to hold channel details and the values to be updated to the 
   TOM/ATOM registers */  
typedef struct
  {
    /*Array holding TOM/ATOM channel numbers in the group*/
    Pwm_17_Gtm_ChannelType             ChannelUsed[8];
    /*Array holding values to be updated to SR0/CM0 registers*/
    uint32                             SR0_VAL[8];
    /*Array holding values to be updated to SR1/CM1 registers*/
    uint32                             SR1_VAL[8];
  }Pwm_ArrayStructureType;

/******************************************************************************
**                      Private Function Declarations                        **
******************************************************************************/

#define PWM_17_GTM_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"

#if ((PWM_DEV_ERROR_DETECT == STD_ON)|| (PWM_SAFETY_ENABLE == STD_ON))
/* PWM003: */

/* To check DET errors in Pwm_Init API */
static uint32 Pwm_lInitDetCheck
(
  const Pwm_17_Gtm_ConfigType *DetConfigPtr
);

/* To verify on channel number passed */
IFX_LOCAL_INLINE uint32 Pwm_lVerChannel
(
  uint8 ServiceID,
  Pwm_17_Gtm_ChannelType ChannelNumber
);
/* To verify whether Init has been called or not */
IFX_LOCAL_INLINE uint32 Pwm_lVerUnInit
(
  uint8 ServiceID
);
/* To verify whether Init has been called or not and channel number passed */
IFX_LOCAL_INLINE uint32 Pwm_lVerUnInitAndChannel
(
  uint8 ServiceID,
  Pwm_17_Gtm_ChannelType ChannelNumber
);

#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
/* To verify Init called or not and whether proper period type */
IFX_LOCAL_INLINE uint32 Pwm_lVerUnInitChanAndPer
(
  uint8 ServiceID,
  Pwm_17_Gtm_ChannelType ChannelNumber
);
#endif
/* (PWM_SET_PERIOD_AND_DUTY_API == STD_ON) */

#endif
/* PWM_DEV_ERROR_DETECT */

/* To get absolute value as per period (used for edge aligned type ) */
IFX_LOCAL_INLINE Pwm_17_Gtm_PeriodType Pwm_lGetAbsvalEdge
(
  Pwm_17_Gtm_PeriodType Period,
  uint32 Value
);

#if (PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON)
/* To get absolute value as per period (used for Center and Shift Type) */
IFX_LOCAL_INLINE Pwm_17_Gtm_PeriodType Pwm_lGetAbsvalShCen
(
  Pwm_17_Gtm_PeriodType Period,
  Pwm_17_Gtm_PeriodType Value
);
#endif
/* Center and Shift type cells */


#if (PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON)
/* To get scaled Shift Lead value */
IFX_LOCAL_INLINE Pwm_17_Gtm_PeriodType Pwm_lGetShiftLead
(
  Pwm_17_Gtm_PeriodType Period,
  Pwm_17_Gtm_PeriodType Shift
);
#endif

#if (PWM_VARIABLE_PERIOD_USED == STD_ON)
static void Pwm_lInitVariablePeriod
(
  uint8 CellUsed,
  uint32 ChannelNumber
);
#endif

#if (PWM_FIXED_PERIOD_USED == STD_ON)
static void Pwm_lInitFixedPeriod
(
  uint8 CellUsed,
  uint32 ChannelNumber
);
#endif
#if (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON)
static void Pwm_lInitCentreAligned
(
  uint8 CellUsed,
  uint32 ChannelNumber
);
#endif
#if (PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON)
static void Pwm_lInitFixedPeriodShifted
(
  uint8 CellUsed,
  uint32 ChannelNumber
);
#endif

#if (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON)
/* To get Center Lead value */
IFX_LOCAL_INLINE Pwm_17_Gtm_PeriodType Pwm_lGetCenterLead
(
  Pwm_17_Gtm_PeriodType Period,
  Pwm_17_Gtm_PeriodType ScaledDuty
);
#endif


#if((PWM_SET_PERIOD_AND_DUTY_API == STD_ON) || \
   (PWM_SET_DUTY_CYCLE_API == STD_ON) ||(PWM_SET_OUTPUT_TO_IDLE_API == STD_ON))
static void Pwm_lGtmStartChannel
(
  Pwm_GlobalChannelNumberType GlobalChannelNumber,
  uint32 Period,
  uint32 Dutycycle,
  uint32 Shift,
  Pwm_17_Gtm_PropertyType PwmProperty
);
static void Pwm_lGtmStartTomChannel
(
  Pwm_ChannelIdentifierType GlobalChannelId,
  uint32 Period,
  uint32 Dutycycle,
  uint32 Shift,
  Pwm_17_Gtm_PropertyType PwmProperty
);
static void Pwm_lGtmStartAtomChannel
(
  Pwm_ChannelIdentifierType GlobalChannelId,
  uint32 Period,
  uint32 Dutycycle,
  uint32 Shift,
  Pwm_17_Gtm_PropertyType PwmProperty
);
#endif

#if(PWM_DE_INIT_API == STD_ON)
static void Pwm_lGtmIdleChannelDeInit
(
  Pwm_GlobalChannelNumberType GlobalChannelNumber,
  uint32 Period,
  uint32 Dutycycle
);
static void Pwm_lGtmIdleTomChannelDeInit
(
  Pwm_ChannelIdentifierType GlobalChannelId,
  uint32 Period,
  uint32 Dutycycle
);
static void Pwm_lGtmIdleAtomChannelDeInit
(
  Pwm_ChannelIdentifierType GlobalChannelId,
  uint32 Period,
  uint32 Dutycycle
);
#endif

#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
static boolean Pwm_lGtmGetOutputState
(
  Pwm_GlobalChannelNumberType GlobalChannelNumber
);
#endif
/* (PWM_GET_OUTPUT_STATE_API == STD_ON) */
static void Pwm_lGtmStartChannelsInit
(
  Pwm_GlobalChannelNumberType GlobalChannelNumber,
  uint32 Period,
  uint32 Dutycycle,
  uint32 Shift,
  Pwm_17_Gtm_PropertyType PwmProperty
);
static void Pwm_lGtmTomChannelsInit
(
  Pwm_ChannelIdentifierType GlobalChannelId,
  uint32 Period,
  uint32 Dutycycle,
  uint32 Shift,
  Pwm_17_Gtm_PropertyType PwmProperty
);
static void Pwm_lGtmAtomChannelsInit
(
  Pwm_ChannelIdentifierType GlobalChannelId,
  uint32 Period,
  uint32 Dutycycle,
  uint32 Shift,
  Pwm_17_Gtm_PropertyType PwmProperty
);
static void Pwm_lGtmSLBitConfigInit
(
  Pwm_ChannelIdentifierType GlobalChannelId,
  Pwm_17_Gtm_PropertyType PwmProperty
);
#if (PWM_DE_INIT_API == STD_ON)
static void Pwm_lGtmSLBitConfigDeInit
(
  Pwm_ChannelIdentifierType GlobalChannelId,
  Pwm_17_Gtm_PropertyType PwmProperty
);
#endif
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)

static void Pwm_lGtmIrqModify(Pwm_GlobalChannelNumberType GlobalChannelNumber,
                         uint8 InterruptFlag);

#endif /* (PWM_NOTIFICATION_SUPPORTED == STD_ON) */

#if (PWM_DE_INIT_API == STD_ON)

static void Pwm_lGtmIrqModifyDeInit(Pwm_GlobalChannelNumberType \
      GlobalChannelNumber,uint8 InterruptFlag);

#endif /* (PWM_DE_INIT_API == STD_ON) */

/* Inline function to obtain the channel class */
IFX_LOCAL_INLINE Pwm_17_Gtm_ChannelClassType Pwm_lChanClass(uint32 Value);

/*
Inline function to obtain the Idle state from PwmChannelInfo
*/
#if((PWM_DE_INIT_API == STD_ON) ||(PWM_SET_OUTPUT_TO_IDLE_API == STD_ON))
IFX_LOCAL_INLINE Pwm_17_Gtm_OutputStateType Pwm_lIdle(uint32 Value);
#endif
/*
Inline function to obtain the Polarity from PwmChannelInfo
*/
IFX_LOCAL_INLINE uint8 Pwm_lPolarity(uint32  Value);
/*
Inline function to obtain the Shift handling info from PwmChannelInfo
*/
IFX_LOCAL_INLINE uint8 Pwm_lShiftSpl(uint32  Value);
/*
Inline function to obtain the channel reset details from PwmChannelInfo
*/
IFX_LOCAL_INLINE uint8 Pwm_lResetShift(uint32  Value);

/*
Inline function to obtain the Coherency from PwmChannelInfo
*/
IFX_LOCAL_INLINE  Pwm_17_Gtm_OutputStateType Pwm_lCoherency(uint32 Value);

#if ((PWM_FIXED_PERIOD_USED == STD_ON)|| (PWM_SET_DUTY_CYCLE_API == STD_ON) )
/*
Inline function to obtain the weather channel is being refered from
PwmChannelInfo
*/
IFX_LOCAL_INLINE Pwm_17_Gtm_OutputStateType Pwm_lIsReference(uint32 Value);

#endif

/*
Inline function to obtain the Assigned HW Unit from PwmChannelInfo
*/
IFX_LOCAL_INLINE uint8 Pwm_lAssignedHW(uint32 Value);

#if ((PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON) || \
                             (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON))
/*
Inline function to obtain the Reference channel Number from PwmChannelInfo
*/
IFX_LOCAL_INLINE Pwm_17_Gtm_ChannelType Pwm_lReferChan(uint32 Value);
#endif

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/*
Function to to Set the Notification status in the global channel variable.
*/
IFX_LOCAL_INLINE void Pwm_lSetNotificationStatus(
                                    Pwm_17_Gtm_ChannelType Channel
                                    );

/*
Function to Clear the Notification status in the global channel variable.
*/
IFX_LOCAL_INLINE void Pwm_lClearNotificationStatus(
                                    Pwm_17_Gtm_ChannelType Channel
                                    );

/*
Function to Set the Duty Notification status in the global channel variable.
*/
IFX_LOCAL_INLINE void Pwm_lSetDuty_0_Or_100_Status(
                                    Pwm_17_Gtm_ChannelType Channel
                                    );

/*
Function to clear the Duty Notification status in the global channel variable.
*/
IFX_LOCAL_INLINE void Pwm_lClearDuty_0_Or_100_Status(
                                    Pwm_17_Gtm_ChannelType Channel
                                    );

/*
Function to clear the Notification edges in the global channel variable.
*/
IFX_LOCAL_INLINE void Pwm_lClearNotificationEdges(
                                    Pwm_17_Gtm_ChannelType Channel
                                    );

/*
Function to set the Notification edges in the global channel variable.
*/
IFX_LOCAL_INLINE void Pwm_lSetNotificationEdges(
                                     Pwm_17_Gtm_ChannelType Channel,
                                     Pwm_17_Gtm_EdgeNotificationType Edge
                                     );
/*
Function to get the Notification kind in the global channel variable.
*/
IFX_LOCAL_INLINE Pwm_17_Gtm_EdgeNotificationType
                Pwm_lGetNotificationKind(Pwm_17_Gtm_ChannelType Channel);

#endif /* PWM_NOTIFICATION_SUPPORTED == STD_ON */

#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
/*
Inline function to Set the idle status in the global channel variable.
*/
IFX_LOCAL_INLINE void Pwm_lSetChannelIdleStatus(Pwm_17_Gtm_ChannelType Channel);

#endif /* (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) */

#if((PWM_SET_DUTY_CYCLE_API == STD_ON)||(PWM_SET_PERIOD_AND_DUTY_API == STD_ON))
/*
Inline function to clear the Notification edges in the global channel variable.
*/
IFX_LOCAL_INLINE void Pwm_lClearIdleStatus(
                                     Pwm_17_Gtm_ChannelType Channel
                                     );


/*
Inline function to get the idle status  from the global channel variable.
*/
IFX_LOCAL_INLINE uint32 Pwm_lGetChannelIdleStatus(
                                     Pwm_17_Gtm_ChannelType Channel
                                     );

#endif
IFX_LOCAL_INLINE uint32 Pwm_lGtmCounterVal
(
  uint32 Shift,
  uint32 Period,
  uint32 DutyCycle
);

/*Function to extract details like module number,module type...*/
static Pwm_ChannelIdentifierType Pwm_lGtmChannelIdentifier(
                               Pwm_GlobalChannelNumberType GlobalChannelNumber
                               );

#if (PWM_SAFETY_ENABLE == STD_ON)
/*Function to check the range of Duty cycle parameter passed*/
IFX_LOCAL_INLINE uint32 Pwm_lSafetyDutyRangeCheck(uint8           ServiceID,\
                                 Pwm_17_Gtm_ChannelType ChannelNumber,
                                 uint32          Duty
                                 );
/*Function to check the range of Period parameter passed*/
IFX_LOCAL_INLINE uint32 Pwm_lSafetyPeriodRangeCheck(
                             uint8           ServiceID,
                             Pwm_17_Gtm_ChannelType ChannelNumber,
                             Pwm_17_Gtm_PeriodType Period
                            );
/*Function to extract the channel type corresponding to channel number passed*/
IFX_LOCAL_INLINE uint8 Pwm_lFindChannelSignal (
                                      Pwm_17_Gtm_ChannelType ChannelNumber);
#endif
#if((PWM_DE_INIT_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_API == STD_ON) || \
   (PWM_SET_DUTY_CYCLE_API == STD_ON) ||(PWM_SET_OUTPUT_TO_IDLE_API == STD_ON))
IFX_LOCAL_INLINE uint32 Pwm_lMaxDuty(Pwm_ChannelIdentifierType GlobalChannelId);
#endif
/*Function to extract the channel index corresponding to channel number passed*/
IFX_LOCAL_INLINE Pwm_17_Gtm_ChannelType Pwm_lFindChannelIndex (
                                      Pwm_17_Gtm_ChannelType ChannelNumber);

#if ((PWM_NOTIFICATION_SUPPORTED == STD_ON)&& \
((PWM_SET_DUTY_CYCLE_API == STD_ON)|| \
         (PWM_17_GTM_SYNCGRPUPDATEDUTIES_ENABLE == STD_ON)))
IFX_LOCAL_INLINE void Pwm_lHandleNotif(
                            Pwm_17_Gtm_ChannelClassType ChannelKind,
                            uint32 Period,
                            uint32 DutyCycle,
                            Pwm_17_Gtm_ChannelType ChannelNumber,
                            uint8 CellUsed);
#endif
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
#if (PWM_SAFETY_ENABLE == STD_ON)
#if (PWM_MAX_ASIL_CHANNELS != 0)
IFX_LOCAL_INLINE void Pwm_lEnableAsilNotif( 
                     Pwm_17_Gtm_ChannelClassType ChannelKind,
                     Pwm_17_Gtm_ChannelType ChannelNumber,
                     uint8 CellUsed,
                     Pwm_17_Gtm_EdgeNotificationType Notification,
                     Pwm_17_Gtm_ChannelType ChIndex);
#endif
#endif
#if (PWM_MAX_QM_CHANNELS != 0)
IFX_LOCAL_INLINE void Pwm_lEnableQmNotif( 
                     Pwm_17_Gtm_ChannelClassType ChannelKind,
                     Pwm_17_Gtm_ChannelType ChannelNumber,
                     uint8 CellUsed,
                     Pwm_17_Gtm_EdgeNotificationType Notification,
                     Pwm_17_Gtm_ChannelType ChIndex);
#endif
#endif

#if (PWM_17_GTM_SYNCGRPUPDATEDUTIES_ENABLE == STD_ON)
/* Local function to update TOM registers of channels in a group 
   in a single function */
IFX_LOCAL_INLINE void Pwm_lUpdateTomReg(uint8   ModuleNumber,
                                  const Pwm_ArrayStructureType  Regptr,
                                        uint16  CohAndMax);
/* Local function to update ATOM registers of channels in a group 
   in a single function */
IFX_LOCAL_INLINE void Pwm_lUpdateAtomReg(uint8  ModuleNumber,
                                  const Pwm_ArrayStructureType  Regptr,
                                         uint16 CohAndMax);
#if ((PWM_DEV_ERROR_DETECT == STD_ON)|| (PWM_SAFETY_ENABLE == STD_ON))
/* Local function to check the DET and Safety errors in the function
   Pwm_17_Gtm_SyncGrpUpdateDuties */
IFX_LOCAL_INLINE Std_ReturnType Pwm_lSyncGroupErrorChecks(uint8 PwmGroupId,
                                    const uint32 *PwmChDutyPtr);
/* Local function to check the if GroupId is out of range or not */
IFX_LOCAL_INLINE Std_ReturnType Pwm_lVerGroupId( uint8 ServiceID,
                                          uint8 GroupId);
#endif
#if (PWM_SAFETY_ENABLE == STD_ON)
/* Local function to check the if the Duty cycle values are above the range
   or not*/
IFX_LOCAL_INLINE Std_ReturnType Pwm_lSafetyGrpDutyRangeCheck(
                                         uint8 ServiceID,
                                   const uint32 *Duty,
                                         uint8 GroupId);
/* Local function to check the if the Marker values in the Dutycycle array 
   passed and in the configuration are same or not,for the given GroupId*/
IFX_LOCAL_INLINE Std_ReturnType Pwm_lSafetyDutyMarkerCheck(
                                         uint8 ServiceID,
                                   const uint32 *DutyCycle,
                                         uint8 GroupId);
#endif
#endif

#define PWM_17_GTM_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
  allowed only for MemMap.h*/
#include "MemMap.h"

/******************************************************************************
**                      Global Constant Definitions                          **
******************************************************************************/
/******************************************************************************
**                      Global Variable Definitions                          **
******************************************************************************/

/******************************************************************************
**                      Private Constant Definitions                         **
******************************************************************************/

/******************************************************************************
**                      Private Variable Definitions                         **
******************************************************************************/
/* To store the PWM driver configuration pointer */
#if (PWM_PB_FIXEDADDR == STD_OFF)
#define PWM_17_GTM_START_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
  allowed only for MemMap.h*/
#include "MemMap.h"
static const Pwm_17_Gtm_ConfigType *Pwm_kConfigPtr;
#define PWM_17_GTM_STOP_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
  allowed only for MemMap.h*/
#include "MemMap.h"
#endif
/* (PWM_PB_FIXEDADDR == STD_OFF)*/

#if (PWM_PB_FIXEDADDR == STD_ON)
#define PWM_17_GTM_START_SEC_CONST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
  allowed only for MemMap.h*/
#include "MemMap.h"
static const Pwm_17_Gtm_ConfigType * const Pwm_kConfigPtr = &Pwm_ConfigRoot[0];
#define PWM_17_GTM_STOP_SEC_CONST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
  allowed only for MemMap.h*/
#include "MemMap.h"

#if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
#define PWM_17_GTM_START_SEC_VAR_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
  allowed only for MemMap.h*/
#include "MemMap.h"
/* Driver Init Status Variable */
static uint8 Pwm_InitStatus;
#define PWM_17_GTM_STOP_SEC_VAR_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
  allowed only for MemMap.h*/
#include "MemMap.h"
#endif
/* (PWM_DEV_ERROR_DETECT == STD_ON) */
#endif
/* (PWM_PB_FIXEDADDR == STD_ON)*/


/*
 * Pwm_GlobChn is array of uint32 variable the length of this array depends on
 * the configured Maximum number of PWM channels.
 */
 /* To store or read Private PWM channel information */
/*
Bit 0,1,2 Pwm_Channelkind.
Bit 3   PWM_NOTIFICATION_STATUS (Notification is enabled Or Disable)
Bit 4,5 Pwm_NotificationAsked
( Edges configured by the user , Rising / Falling / Both)
Bit 6   Pwm_DutyNotifyFlag
( when user sets a duty of 0 % or 100 % , then calls
  Enable Notification, the notification should not be set
)
rest    reserved
*/
/* To store or read Private PWM channel information */
/* [cover parentID=DS_MCAL_PWM_0910] [/cover]  */
#if (PWM_SAFETY_ENABLE == STD_ON)
#if (PWM_MAX_ASIL_CHANNELS != 0)
#define PWM_17_GTM_START_SEC_ASIL0_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"
static uint32  Pwm_GlobChn_Asil[PWM_MAX_ASIL_CHANNELS];
#define PWM_17_GTM_STOP_SEC_ASIL0_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"
#endif
#endif

#if (PWM_MAX_QM_CHANNELS != 0)
#define PWM_17_GTM_START_SEC_VAR_FAST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"
static uint32  Pwm_GlobChn_Qm[PWM_MAX_QM_CHANNELS];
#define PWM_17_GTM_STOP_SEC_VAR_FAST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"
#endif

#if (PWM_SAFETY_ENABLE == STD_ON)
#if (PWM_MAX_ASIL_CHANNELS != 0)
#define PWM_17_GTM_START_SEC_ASIL0_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"
#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
/*IFX_MISRA_RULE_08_07_STATUS= Variable used in multiple functions when 
Variable period channels are configured*/
static uint32  Pwm_CurrentPeriodVal_Asil[PWM_MAX_ASIL_CHANNELS];
#endif
/* (PWM_SET_PERIOD_AND_DUTY_API == STD_ON) */
#define PWM_17_GTM_STOP_SEC_ASIL0_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"
#endif
#endif

#if (PWM_MAX_QM_CHANNELS != 0)
#define PWM_17_GTM_START_SEC_VAR_FAST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"
#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
/*IFX_MISRA_RULE_08_07_STATUS= Variable used in multiple functions when 
Variable period channels are configured*/
static uint32  Pwm_CurrentPeriodVal_Qm[PWM_MAX_QM_CHANNELS];
#endif
/* (PWM_SET_PERIOD_AND_DUTY_API == STD_ON) */
#define PWM_17_GTM_STOP_SEC_VAR_FAST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"
#endif
/******************************************************************************
**                      Global Function Definitions                          **
******************************************************************************/
#define PWM_17_GTM_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"

/******************************************************************************
** Syntax : void Pwm_17_Gtm_Init(const Pwm_17_Gtm_ConfigType *ConfigPtr)     **
**                                                                           **
** Service ID:      0x00                                                     **
**                                                                           **
** Sync/Async:      Synchronous                                              **
**                                                                           **
** Reentrancy:      non reentrant (PWM034:)                                  **
**                                                                           **
** Parameters (in): ConfigPtr - Expected valid address pointing to config    **
**                                                                           **
** Parameters (out):none                                                     **
**                                                                           **
** Return value:    none                                                     **
**                                                                           **
** Description : Driver Module Initialization (PWM007:)                      **
**               1.This function will initialize all relevant registers of   **
**                 configured hardware (Assigned_HW_Unit) with the values of **
**                 structure given by ConfigPtr.                             **
**               2. This service will disable all notifications.             **
**               3. Resources that are not configured in the configuration   **
**                  file will not be changed.                                **
**               4. This function shall initialize all internals variables   **
**               5. After initialization the PWM driver will start generate  **
**                  PWM signal(s) with the configured default values         **
**               6. Service should not be called during a running operation. **
**                REQ ID : PWM007, PWM062, PWM009, PWM052 PWM046, PWM051     **
**                                                                           **
** Traceabilty      :                                                        **
** [cover parentID=DS_AS_PWM095] [/cover]                                    **
** [cover parentID=DS_AS_PWM007_PWM062] [/cover]                             **
** [cover parentID=DS_AS_PWM009a] [/cover]                                   **
** [cover parentID=DS_AS_PWM009b] [/cover]                                   **
** [cover parentID=DS_AS_PWM009c] [/cover]                                   **
** [cover parentID=DS_AS_PWM052] [/cover]                                    **
** [cover parentID=DS_AS_PWM064_1] [/cover]                                  **
** [cover parentID=DS_AS_PWM002a_PWM046] [/cover]                            **
** [cover parentID=DS_AS_PWM002e_PWM118_PWM121] [/cover]                     **
** [cover parentID=DS_AS_PWM051b_1] [/cover]                                 **
** [cover parentID=DS_AS_PWM051a_PWM078_1] [/cover]                          **
** [cover parentID=DS_NAS_PWM_PR2965] [/cover]                               **
**                                                                           **
******************************************************************************/
void Pwm_17_Gtm_Init
(
  const Pwm_17_Gtm_ConfigType *ConfigPtr
)
{
  /* Local variables */
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  /*Error flag to indicate errors*/
  uint8                              ErrStatus;
  #endif
  /* End of PWM_DEV_ERROR_DETECT */
  uint8                              CellUsed;
  Pwm_17_Gtm_ChannelType             ChannelNumber;
  Pwm_17_Gtm_ChannelClassType        ChannelKind;
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr;
  /* ROM pointer */
  Pwm_17_Gtm_ChannelType             ChIndex;
  #if (PWM_HANDLE_SHIFT_BY_OFFSET == STD_ON)
  Pwm_ChannelIdentifierType GlobalChannelId;
  uint32 PwmTomTgcTrigger;
  uint32 PwmAtomAgcTrigger;
  /* Ptr to TOM TGC Reg         */
  Ifx_GTM_TOM_TGC_TYPE* TomTgcRegPtr;
  Ifx_GTM_ATOM* AtomRegPtr;           /* Ptr to ATOM AGC Reg           */
  uint32 ShiftVal;
  uint32 TgcNumber;
  uint32 ModuleNumber;
  uint8 GroupNumber;
  #endif
  #if (PWM_SAFETY_ENABLE == STD_ON)
  uint8                              ChSignal;
  #endif
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  ErrStatus = (uint8)E_OK;
  #endif
  /* PWM_DEV_ERROR_DETECT */
   #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  /* PWM003: */
  /* PWM046 check for the validity of configPtr */
  if(PWM_ERROR_FOUND == (Pwm_lInitDetCheck(ConfigPtr)))
  {
    /* Return without executing any of functionality */
    ErrStatus = (uint8)E_NOT_OK;
  }
  #endif
  /* End of PWM_DEV_ERROR_DETECT and PWM_SAFETY_ENABLE */

  #if (PWM_SAFETY_ENABLE == STD_ON)
  /* Marker check for safety */
  if ((ErrStatus != E_NOT_OK) &&\
      (ConfigPtr->Marker != ((uint32)PWM_17_GTM_MODULE_ID << 16U)))
  {
    /* Report Safety error to upper layer */
    ErrStatus = E_NOT_OK;
    SafeMcal_ReportError(
                          PWM_17_GTM_MODULE_ID,
                          PWM_17_GTM_INSTANCE_ID,
                          PWM_SID_INIT,
                          PWM_E_PARAM_CONFIG
                        );

  }
  #endif /*End Of PWM_SAFETY_ENABLE*/

  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  if(ErrStatus == (uint8)E_OK)
  #endif
  /* End of PWM_DEV_ERROR_DETECT and PWM_SAFETY_ENABLE*/
  {
    /* As per caveat Pwm_Init should not be called during running operation. */
    /* PWM007: Initialize all registers as per the configuration data. */
    #if (PWM_PB_FIXEDADDR == STD_OFF)
    /*PWM_PB_FIXEDADDR is STD_OFF : Assign ConfigPtr to the global variable*/
    Pwm_kConfigPtr = ConfigPtr;
    #else
    UNUSED_PARAMETER(ConfigPtr)
    #endif
    /* (PWM_PB_FIXEDADDR == STD_OFF) */
    /* Initialize PWM configured channel ROM pointer */
    LocalPwmChanPtr = Pwm_kConfigPtr->ChannelConfigPtr;
    #if (PWM_HANDLE_SHIFT_BY_OFFSET == STD_ON)
    PwmTomTgcTrigger = 0U;
    PwmAtomAgcTrigger = 0U;
    #endif
    /* Verify for the configured channels */
    for (
         ChannelNumber = (Pwm_17_Gtm_ChannelType)0;
         ChannelNumber < Pwm_kConfigPtr->MaxChannels;
         ChannelNumber++
        )
    {
      /* Extract Cell Number */
      CellUsed = Pwm_lAssignedHW(LocalPwmChanPtr->ChannelInfo);
      /* Extract the Module specific information */
      #if (PWM_HANDLE_SHIFT_BY_OFFSET == STD_ON)
      GlobalChannelId = Pwm_lGtmChannelIdentifier(CellUsed);
      ModuleNumber = GlobalChannelId.ModuleNo;
      GroupNumber = GlobalChannelId.GroupNo;
      /* Detect the Sub-Module type */
      if((GlobalChannelId.ModuleId) == GTM_TOM_MODULE)
      {
        /* Store the TGC's which have to be triggered by Host trigger*/
        PwmTomTgcTrigger |= ((uint32)1U << ((ModuleNumber*2U)+GroupNumber));
      }
      if((GlobalChannelId.ModuleId) == GTM_ATOM_MODULE)
      {
        /* Store the TGC's which have to be triggered by Host trigger*/
        PwmAtomAgcTrigger |= ((uint32)1U << (ModuleNumber));
      }
      #endif
      /* Get the type of channel used */
      ChannelKind = Pwm_lChanClass(LocalPwmChanPtr->ChannelInfo);
      ChIndex = Pwm_lFindChannelIndex(ChannelNumber);
      #if (PWM_SAFETY_ENABLE == STD_ON)
      ChSignal = Pwm_lFindChannelSignal(ChannelNumber);
      /*Check if the channel is Asil if it is ASIL
        then update the ASIL global variable*/
      if (ChSignal == PWM_ASIL_TYPE)
      {
        #if (PWM_MAX_ASIL_CHANNELS != 0)
        Pwm_GlobChn_Asil[ChIndex]=(uint32)0U;
        Pwm_GlobChn_Asil[ChIndex] |= (uint32)ChannelKind;
        #endif
      }
      else
      /*Update the QM  variable if the channel is the type QM*/
      #endif
      {
        /* PWM012: Reset Notifications */
        /* Notification and status goes to zero */
        #if (PWM_MAX_QM_CHANNELS != 0)
        Pwm_GlobChn_Qm[ChIndex]=0U;
        /* PWM007: Store the type of channel used */
        Pwm_GlobChn_Qm[ChIndex] |= (uint32)ChannelKind;
        #endif
      }
      /* Requirements on PWM062: , PWM009:, PWM052: are taking care in the
         below calling local functions */
      switch (ChannelKind)
      {
        #if (PWM_VARIABLE_PERIOD_USED == STD_ON)
        case PWM_VARIABLE_PERIOD:
        /* Variable Period */
          Pwm_lInitVariablePeriod(CellUsed,ChannelNumber);
          break;
        #endif
        #if (PWM_FIXED_PERIOD_USED == STD_ON)
        case PWM_FIXED_PERIOD:
          /* Fixed Period */
          Pwm_lInitFixedPeriod(CellUsed,ChannelNumber);
          break;
        #endif
        #if (PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON)
        case PWM_FIXED_PERIOD_SHIFTED:
          Pwm_lInitFixedPeriodShifted(CellUsed,ChannelNumber);
          break;
        #endif
        default:
        #if (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON)
          Pwm_lInitCentreAligned(CellUsed,ChannelNumber);
        #endif
        break;
      }
      /* End of Switch condition */
      /* Increase the Pwm channel pointer */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
        PBConfigStructure and is within allowed range.*/
      LocalPwmChanPtr++;
    }
    /* End of for loop in Pwm_Init() function */
    #if (PWM_HANDLE_SHIFT_BY_OFFSET == STD_ON)
    /* Set host trigger to configured TOM TGC */
    for(ShiftVal = 0U;ShiftVal < (uint32)(GTM_NO_OF_TOM_MODULES*2U);ShiftVal++)
    {
      if(((PwmTomTgcTrigger>>ShiftVal)&0x1U) == 1U)
      {
        TgcNumber = (ShiftVal%2U);
        ModuleNumber = (ShiftVal/2U);
        /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
          Permitted for special function registers.*/
        TomTgcRegPtr = &((*(Ifx_GTM_TOMx*)(volatile void*)\
                      (MODULE_GTM.TOM)).TOM_TGC[ModuleNumber].TGC[TgcNumber]);
        PWM_SFR_INIT_USER_MODE_MODIFY32((TomTgcRegPtr->GLB_CTRL.U),\
                       PWM_TGC_GLB_CLR_MASK,PWM_BIT_SET)
      }
    }
    for(ShiftVal = 0U;ShiftVal < (uint32)(GTM_NO_OF_ATOM_MODULES);ShiftVal++)
    {
      if(((PwmAtomAgcTrigger>>ShiftVal)&0x1U) == 1U)
      {
        AtomRegPtr = &(MODULE_GTM.ATOM[ShiftVal]);
        PWM_SFR_INIT_USER_MODE_MODIFY32((AtomRegPtr->AGC.GLB_CTRL.U),\
                       PWM_TGC_GLB_CLR_MASK,PWM_BIT_SET)
      }
    }
    #endif
    #if ( (PWM_PB_FIXEDADDR == STD_ON) && (PWM_DEV_ERROR_DETECT == STD_ON) )
    /* Set Status to indicate that initialization is done */
    Pwm_InitStatus = PWM_INITIALIZED;
    #endif
    /*(PWM_PB_FIXEDADDR == STD_ON) && (PWM_DEV_ERROR_DETECT == STD_ON)*/
  }
  return;
} /* End of Pwm_17_Init API */

/* Bugzilla 11769 , configuration for Pwm_DeInit API */
#if (PWM_DE_INIT_API == STD_ON) /* PWM080 */
/******************************************************************************
** Syntax : void Pwm_17_Gtm_DeInit(void)                                     **
**                                                                           **
** Service ID: 0x01                                                          **
**                                                                           **
** Sync/Async:Synchronous                                                    **
**                                                                           **
** Reentrancy:non reentrant (PWM034:)                                        **
**                                                                           **
** Parameters (in): none                                                     **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:none                                                         **
**                                                                           **
** Description : Service for PWM De-Initialization PWM010:                   **
**               1.After the call of this service, the state of the used     **
**                 peripherals/registers will set to power on reset state.   **
**               2.This service will disable all used interrupts and         **
**                  notifications.                                           **
**               3.This service clear all pending interrupt flags            **
**               4.All global variables will get reset                       **
**               5.All channel output signal state will set to Idle State    **
**               Req Id's: PWM010, PWM011, PWM012 , PWM044, PWM051           **
**                                                                           **
** Traceabilty      :                                                        **
** [cover parentID=DS_AS_PWM096] [/cover]                                    **
** [cover parentID=DS_AS_PWM010] [/cover]                                    **
** [cover parentID=DS_AS_PWM011] [/cover]                                    **
** [cover parentID=DS_AS_PWM012] [/cover]                                    **
** [cover parentID=DS_AS_PWM080a_PWM080b] [/cover]                           **
** [cover parentID=DS_AS_PWM064_2] [/cover]                                  **
** [cover parentID=DS_AS_PWM002b_PWM117_1] [/cover]                          **
** [cover parentID=DS_AS_PWM051b_2] [/cover]                                 **
** [cover parentID=DS_AS_PWM051a_PWM078_2] [/cover]                          **
**                                                                           **
******************************************************************************/
/*PWM010 Service for Pwm_Deinitialization */
void Pwm_17_Gtm_DeInit(void)
{
  /* Local variables */
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  uint8                              ErrStatus;
  #endif
  /* PWM_DEV_ERROR_DETECT */
  uint8                              CellUsed;
  Pwm_17_Gtm_ChannelType             ChannelNumber;
  Pwm_17_Gtm_OutputStateType         IdleState;
  uint32                             Duty;
  Pwm_17_Gtm_PeriodType              Period;
  Pwm_17_Gtm_PeriodType              ScaledDuty;
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr;
  /* ROM pointer */
  Pwm_17_Gtm_PropertyType            PwmProperty;
  #if ((PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON) || \
         (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON) || \
         (PWM_VARIABLE_PERIOD_USED == STD_ON))
  Pwm_17_Gtm_ChannelClassType        ChannelKind;
  #endif
  #if ((PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON) || \
                    (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON))
  Pwm_17_Gtm_ChannelType             MainChannel;
  #endif
  Pwm_ChannelIdentifierType          GlobalChannelId;
  Pwm_17_Gtm_ChannelType             ChIndex;
  #if ((PWM_SAFETY_ENABLE == STD_ON)&& (PWM_MAX_ASIL_CHANNELS != 0))
  uint8                              ChSignal;
  #endif
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  ErrStatus                 =        (uint8)E_OK;
  #endif
  /* PWM_DEV_ERROR_DETECT */

  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  /* PWM003: */
  if (PWM_ERROR_FOUND == Pwm_lVerUnInit(PWM_SID_DEINIT))
  {
    /* PWM051: Return without executing any of functionality */
    ErrStatus = (uint8)E_NOT_OK;
  }
  #endif
  /* PWM_DEV_ERROR_DETECT */
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  if(ErrStatus == (uint8)E_OK)
  #endif
  /* PWM_DEV_ERROR_DETECT */
  {
    /* Initialize PWM configured channel ROM pointer */
    LocalPwmChanPtr = Pwm_kConfigPtr->ChannelConfigPtr;
    /* Verify for the configured channels */
    for ( ChannelNumber = (Pwm_17_Gtm_ChannelType)0;
          ChannelNumber < Pwm_kConfigPtr->MaxChannels;
          ChannelNumber++
         )
    {
      CellUsed = Pwm_lAssignedHW(LocalPwmChanPtr->ChannelInfo);
      /* Disable Interrupts for each channel */
      Pwm_lGtmIrqModifyDeInit(CellUsed,0U);
      /*Clear global variable used to store notification details*/
      ChIndex = Pwm_lFindChannelIndex(ChannelNumber);         
      /*If safety is Enabled then check for ASIL channels*/
      #if (PWM_SAFETY_ENABLE == STD_ON)
      #if (PWM_MAX_ASIL_CHANNELS != 0)
      ChSignal = Pwm_lFindChannelSignal(ChannelNumber);
      if (ChSignal == PWM_ASIL_TYPE)
      {
        Pwm_GlobChn_Asil[ChIndex]=(uint32)0U;
      }
      else
      #endif
      #endif
      {
      #if (PWM_MAX_QM_CHANNELS != 0)
        Pwm_GlobChn_Qm[ChIndex]=(uint32)0U;
      #endif
        /*If QM channels are equal to zero do nothing */
      }
      /*Extract the period value for each channel*/
      #if ((PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON) || \
        (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON) || \
        (PWM_VARIABLE_PERIOD_USED == STD_ON))

      ChannelKind = Pwm_lChanClass(LocalPwmChanPtr->ChannelInfo);
      #endif
      #if ((PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON) || \
             (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON))
      if ((ChannelKind == PWM_FIXED_PERIOD_SHIFTED) || \
             (ChannelKind == PWM_FIXED_PERIOD_CENTER_ALIGNED))
      {
        MainChannel = Pwm_lReferChan(LocalPwmChanPtr->ChannelInfo);
              /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
        PBConfigStructure and is within allowed range.*/
        Period =
               ((Pwm_kConfigPtr->ChannelConfigPtr)+MainChannel)->PeriodDefault;
      }
      else
      #endif
      {
        Period = LocalPwmChanPtr->PeriodDefault;
      }
     /*In case of variable period channel get the period values from the array
     and clear the contents of the array if set period and duty API is enabled*/
      #if (PWM_VARIABLE_PERIOD_USED == STD_ON) 
      if(ChannelKind == PWM_VARIABLE_PERIOD)
      {
        #if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
        /*If safety is Enabled then check for ASIL channels*/
        #if (PWM_SAFETY_ENABLE == STD_ON)
        #if (PWM_MAX_ASIL_CHANNELS != 0)
        if (ChSignal == PWM_ASIL_TYPE)
        {
          Period = Pwm_CurrentPeriodVal_Asil[ChIndex];
          Pwm_CurrentPeriodVal_Asil[ChIndex] = 0UL;
        }
        else
        #endif
        #endif
        {
          #if (PWM_MAX_QM_CHANNELS != 0)
          Period = Pwm_CurrentPeriodVal_Qm[ChIndex];
          Pwm_CurrentPeriodVal_Qm[ChIndex] = 0UL;
          #endif
          /*If QM channels are equal to zero do nothing */
        }
        #endif
        /*If set period and Duty API is not enabled then do nothing*/
      }
      #endif
      PwmProperty.Coherency = 0x0U;
      PwmProperty.ChannelType = 0x0U;
      PwmProperty.IsReference = 0x0U;
      PwmProperty.PreviousState = 0x0U;
      PwmProperty.RefChannelId = 0x0U;

      /* Extract IdleState and polarity details */
      IdleState = Pwm_lIdle(LocalPwmChanPtr->ChannelInfo);
      PwmProperty.Polarity  = Pwm_lPolarity(LocalPwmChanPtr->ChannelInfo);

      GlobalChannelId = Pwm_lGtmChannelIdentifier(CellUsed);
      /* Initialize  Duty as 100 % */
      #if (PWM_DUTY_SHIFT_IN_TICKS == STD_ON)
      Duty = Pwm_lMaxDuty(GlobalChannelId);
      #else
      Duty = PWM_MAX_DUTY;
      #endif
      if (IdleState != PwmProperty.Polarity)
      {
        /* Idlestate and Polarity mismatches then 0 % duty desired */
        Duty = 0U;
      }
      /* Get Scale value of Duty according to period */
      ScaledDuty = (uint32)Pwm_lGetAbsvalEdge(Period,(uint32)Duty);
      Pwm_lGtmSLBitConfigDeInit(GlobalChannelId,PwmProperty);
      Pwm_lGtmIdleChannelDeInit(CellUsed,Period,ScaledDuty);

      /* Increment Global channel ROM pointer */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
        PBConfigStructure and is within allowed range.*/
      LocalPwmChanPtr++;
    }
    /* End of for loop in Pwm_DeInit() function */
    #if (PWM_PB_FIXEDADDR == STD_OFF)
    /*PWM_PB_FIXEDADDR is STD_OFF : Clear ConfigPtr */
    Pwm_kConfigPtr = NULL_PTR;
    #else
    #if (PWM_DEV_ERROR_DETECT == STD_ON)
    /* Clear the Status to indicate that Deinitialization is done */
    Pwm_InitStatus = PWM_DEINITIALIZED;
    #endif
    /* (PWM_DEV_ERROR_DETECT == STD_ON */
    #endif
    /* (PWM_PB_FIXEDADDR == STD_OFF) */
  }
  return;
}
/* End of Pwm_17_Gtm_DeInit API */
#endif
/* PWM_DE_INIT_API */

#if (PWM_SET_DUTY_CYCLE_API == STD_ON) /* PWM082 */
/******************************************************************************
** Syntax : void Pwm_17_Gtm_SetDutyCycle(                                    **
**                            Pwm_17_Gtm_ChannelType ChannelNumber,          **
**                                 uint16             DutyCycle)             **
**     Duty cycle is uint32 if DutyCycle is given in ticks                   **
** Service ID:0x02                                                           **
**                                                                           **
** Sync/Async:Synchronous                                                    **
**                                                                           **
** Reentrancy:reentrant                                                      **
**                                                                           **
** Parameters (in): ChannelNumber : Numeric identifier of the PWM channel    **
**                   DutyCycle     : To set Duty Cycle for a PWM channel     **
**                                   PWM059:Min=0x0000 Max=0x8000            **
**                                                                           **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value: none                                                        **
**                                                                           **
** Description : Service to set Duty cycle PWM013:                           **
**               1.This service will allow to set the duty cycle of the PWM  **
**                 channel.                                                  **
**               2.If the duty cycle = 0% (value=0x0000), then the PWM output**
**                 state will set to opposite level of polarity.             **
**               3.If the duty cycle=100% (value=0x8000), then the PWM output**
**                 state will set to polarity level.                         **
**               4.If the duty cycle>100%(value>0x8000), then the PWM output **
**                 will be undefined behavior (recommended that, user not to **
**                 provide this range of value)                              **
**               5 If the duty cycle >0% and <100%,then the PWM output will  **
**                 set to active state according to duty cycle and period    **
**                 parameters , polarity state.                              **
**               6.Dependency on PWM_DUTYCYCLE_UPDATED_ENDPERIOD config      **
**                 parameter.                                                **
**                 REq's: PWM013, PWm014, PWM016, PWm017, PWM058, PWM059     **
**                        PWM018, PWM044, PWM047, PWM051                     **
**                                                                           **
** Traceabilty      :                                                        **
** [cover parentID=DS_AS_PWM097_PWM058] [/cover]                             **
** [cover parentID=DS_AS_PWM013] [/cover]                                    **
** [cover parentID=DS_AS_PWM088_1] [/cover]                                  **
** [cover parentID=DS_AS_PWM014] [/cover]                                    **
** [cover parentID=DS_AS_PWM016] [/cover]                                    **
** [cover parentID=DS_AS_PWM017] [/cover]                                    **
** [cover parentID=DS_AS_PWM018] [/cover]                                    **
** [cover parentID=DS_AS_PWM064_3] [/cover]                                  **
** [cover parentID=DS_AS_PWM002b_PWM117_2] [/cover]                          **
** [cover parentID=DS_AS_PWM051b_3] [/cover]                                 **
** [cover parentID=DS_AS_PWM051a_PWM078_3] [/cover]                          **
** [cover parentID=DS_AS_PWM002c_PWM047_1] [/cover]                          **
** [cover parentID=DS_AS_PWM082a_PWM082b] [/cover]                           **
** [cover parentID=DS_MCAL_PWM_0911_a] [/cover]                              **
** [cover parentID=DS_NAS_HE2_PWM_PR2938_1] [/cover]                         **
** [cover parentID=DS_NAS_EP_PWM_PR2938_1] [/cover]                          **
**                                                                           **
******************************************************************************/
#if (PWM_DUTY_SHIFT_IN_TICKS == STD_OFF)
void Pwm_17_Gtm_SetDutyCycle
(
  Pwm_17_Gtm_ChannelType ChannelNumber,
  uint16          DutyCycle
)
#else
void Pwm_17_Gtm_SetDutyCycle
(
  Pwm_17_Gtm_ChannelType ChannelNumber,
  uint32          DutyCycle
)
#endif
{
  /* Local variables */
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  uint8                               ErrStatus;
  #endif
  /* PWM_DEV_ERROR_DETECT */
  uint8                               CellUsed;
  Pwm_17_Gtm_ChannelClassType         ChannelKind;
  const Pwm_17_Gtm_ChannelConfigType  *LocalPwmChanPtr;
  /* ROM pointer */
  Pwm_17_Gtm_PropertyType             PwmProperty;
  uint32                              Period     = 0U;
  uint32                              ScaledDuty = 0U;
  uint32                              ShiftVal;
  #if ((PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON) || \
       (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON))
  Pwm_17_Gtm_ChannelType              MainChannel;
  #endif

  #if (PWM_VARIABLE_PERIOD_USED == STD_ON)
  Pwm_17_Gtm_ChannelType              ChIndex;
  #if ((PWM_SAFETY_ENABLE == STD_ON)&&(PWM_MAX_ASIL_CHANNELS != 0))
  uint8                               ChSignal;
  #endif
  #endif
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  ErrStatus = (uint8)E_OK;
  #endif /* PWM_DEV_ERROR_DETECT */
  /* PWM013: Service to Set the Duty Cycle */
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  /* PWM003: */
  if (PWM_ERROR_FOUND ==
            Pwm_lVerUnInitAndChannel(PWM_SID_SETDUTY, ChannelNumber))
  {
    /* Return without executing any of functionality */
    ErrStatus = (uint8)E_NOT_OK;
  }
  #endif
  /* PWM_DEV_ERROR_DETECT */

  #if (PWM_SAFETY_ENABLE == STD_ON)
  if(ErrStatus == (uint8)E_OK)
  {
    if (PWM_ERROR_FOUND == Pwm_lSafetyDutyRangeCheck(
              PWM_SID_SETDUTY,ChannelNumber,(uint32)DutyCycle))
    {
      /* Return without executing any of functionality */
      ErrStatus = (uint8)E_NOT_OK;
    }
  }
  #endif
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  if(ErrStatus == (uint8)E_OK)
  #endif
  /* PWM_DEV_ERROR_DETECT and PWM_SAFETY_ENABLE*/
  {
    /* Initialize PWM configured channel ROM pointer */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
      PBConfigStructure and is within allowed range.*/
    LocalPwmChanPtr = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
    CellUsed = Pwm_lAssignedHW(LocalPwmChanPtr->ChannelInfo);
    ChannelKind = Pwm_lChanClass(LocalPwmChanPtr->ChannelInfo);
    /* Setup Output to LOW or HIGH Depending on Polarity (Duty start)
       for timer cell */
    PwmProperty.Coherency = 0x0U;
    PwmProperty.ChannelType = 0x0U;
    PwmProperty.PreviousState = 0x0U;
    PwmProperty.RefChannelId = 0x0U;
    PwmProperty.Polarity = Pwm_lPolarity(LocalPwmChanPtr->ChannelInfo);
    PwmProperty.IsReference  = Pwm_lIsReference(LocalPwmChanPtr->ChannelInfo);
    PwmProperty.ShiftedSpl = Pwm_lShiftSpl(LocalPwmChanPtr->ChannelInfo);
    /* Get the coherency */
    #if(PWM_DUTYCYCLE_UPDATED_ENDPERIOD == STD_OFF)
    PwmProperty.Coherency = Pwm_lCoherency(LocalPwmChanPtr->ChannelInfo);
    #else
    PwmProperty.Coherency = PWM_COHERENT;
    #endif
    ShiftVal = 0U;

    /* (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_OFF) */
    switch (ChannelKind)
    {
      #if (PWM_VARIABLE_PERIOD_USED == STD_ON)
      case PWM_VARIABLE_PERIOD:
        ChIndex = Pwm_lFindChannelIndex(ChannelNumber);
        #if (PWM_SAFETY_ENABLE == STD_ON)
        #if (PWM_MAX_ASIL_CHANNELS != 0)
        ChSignal = Pwm_lFindChannelSignal(ChannelNumber);
        if (ChSignal == PWM_ASIL_TYPE)
        {
          Period = Pwm_CurrentPeriodVal_Asil[ChIndex] ;
        }
        else
        #endif
        #endif
        {
          #if (PWM_MAX_QM_CHANNELS != 0)
          Period = Pwm_CurrentPeriodVal_Qm[ChIndex];
          #endif
          /*If QM channels are equal to zero do nothing */
        }
        ScaledDuty = (uint32)Pwm_lGetAbsvalEdge(Period,(uint32)DutyCycle);
        break;
      #endif
      #if (PWM_FIXED_PERIOD_USED == STD_ON)
      case PWM_FIXED_PERIOD:
       /* Variable Period */
      Period = LocalPwmChanPtr->PeriodDefault;
      ScaledDuty = (uint32)Pwm_lGetAbsvalEdge(Period,(uint32)DutyCycle);
      break;
      #endif
      #if (PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON)
      case PWM_FIXED_PERIOD_SHIFTED:
      PwmProperty.ChannelType = PWM_SHIFTED_CHANNEL;
      MainChannel = Pwm_lReferChan(LocalPwmChanPtr->ChannelInfo);
      /* Get main period */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
        PBConfigStructure and is within allowed range.*/
      Period =
             ((Pwm_kConfigPtr->ChannelConfigPtr) + MainChannel )->PeriodDefault;
      /* Get Scale value of Duty according to period */
      ScaledDuty = (uint32)Pwm_lGetAbsvalEdge(Period,(uint32)DutyCycle);
      /* Get the Shift lead value */
      ShiftVal =
        (uint32)Pwm_lGetShiftLead(Period,
                         (Pwm_17_Gtm_PeriodType)(LocalPwmChanPtr->ShiftValue));
      break;
      #endif
      default:
      #if (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON)
       /* Fixed Period shifted : Additional 3 cells :
           reference to a 4 cell fixed period solution*/
      PwmProperty.ChannelType = PWM_SHIFTED_CHANNEL;
      MainChannel = Pwm_lReferChan(LocalPwmChanPtr->ChannelInfo);
      /* Get main period */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
        PBConfigStructure and is within allowed range.*/
      Period =
           ((Pwm_kConfigPtr->ChannelConfigPtr) + MainChannel )->PeriodDefault;
      /* Get Scale value of Duty according to period */
      ScaledDuty = (uint32)Pwm_lGetAbsvalEdge(Period,(uint32)DutyCycle);
      /* Get the Shift lead value */
      ShiftVal = (uint32)Pwm_lGetCenterLead(Period, ScaledDuty);
      #endif
      break;
    }/* End of Switch condition */
    /* Updated the previous state */
    if(Pwm_lGetChannelIdleStatus(ChannelNumber) != 0U)
    {
      PwmProperty.PreviousState = PWM_IDLE_CHANNEL;
      /* Set the Channel Status to Idle */
      Pwm_lClearIdleStatus(ChannelNumber);
    }
    /* Local function to set or clear the flags and enable/disable interrupts
      based on duty cycle value */
    #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    Pwm_lHandleNotif(ChannelKind,Period,ScaledDuty,ChannelNumber,CellUsed);
    #endif
    /* PWM_NOTIFICATION_SUPPORTED */
    Pwm_lGtmStartChannel(CellUsed,Period,ScaledDuty,ShiftVal,PwmProperty);
  }
  return;
}
/* End of Pwm_17_Gtm_SetDutyCycle() function */
#endif
/* PWM_SET_DUTY_CYCLE_API */

#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
 /* PWM083 */
/******************************************************************************
** Syntax : void Pwm_17_Gtm_SetPeriodAndDuty(                                **
**                                   Pwm_17_Gtm_ChannelType ChannelNumber,   **
**                                    Pwm_17_Gtm_PeriodType  Period,         **
**                                    uint16              DutyCycle)         **
**                DutyCycle is uint32 if DutyCycle is given in ticks         **
**                                                                           **
** Service ID: 0x03                                                          **
**                                                                           **
** Sync/Async: Synchronous                                                   **
**                                                                           **
** Reentrancy: reentrant                                                     **
**                                                                           **
** Parameters (in):  ChannelNumber : Numeric identifier of the PWM channel   **
**                   Period        : Period of the PWM signal                **
**                   DutyCycle     : To set Duty Cycle for a PWM channel     **
**                                  PWM059:Min=0x0000 Max=0x8000             **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:  none                                                       **
**                                                                           **
** Description : Service to set period and Duty cycle (PWM019:)              **
**               1.This service will allow to set the Period and duty cycle  **
**                 of the PWM channel.                                       **
**               2.Valid only for variable period                            **
**               3.If the duty cycle=0% (value=0x8000), then the PWM output  **
**                 state will set to opposite of Polarity level.             **
**               4.If the duty cycle=100% (value=0x8000), then the PWM       **
**                 output state will set to Polarity level.                  **
**               5.If the duty cycle>100%(value>0x8000), then the PWM output **
**                 will be undefined behavior (recommended that, user not to **
**                 provide this range of value)                              **
**               6 If the duty cycle >0% and <100%,then the PWM output will  **
**                 set to active state according to duty cycle and period    **
**                 parameters Polarity state.                                **
**               7.To scale the duty cycle passed period  will be used       **
**                 Req's: PWM019, PWM076, PWM020, PWM041, PWM060             **
**                                                                           **
** Traceabilty      :                                                        **
** [cover parentID=DS_AS_PWM098] [/cover]                                    **
** [cover parentID=DS_AS_PWM019] [/cover]                                    **
** [cover parentID=DS_AS_PWM088_2] [/cover]                                  **
** [cover parentID=DS_AS_PWM076] [/cover]                                    **
** [cover parentID=DS_AS_PWM020] [/cover]                                    **
** [cover parentID=DS_AS_PWM064_4] [/cover]                                  **
** [cover parentID=DS_AS_PWM002b_PWM117_3] [/cover]                          **
** [cover parentID=DS_AS_PWM002c_PWM047_2] [/cover]                          **
** [cover parentID=DS_AS_PWM002d_PWM045] [/cover]                            **
** [cover parentID=DS_AS_PWM041] [/cover]                                    **
** [cover parentID=DS_AS_PWM083a_PWM083b] [/cover]                           **
** [cover parentID=DS_AS_PWM051b_4] [/cover]                                 **
** [cover parentID=DS_AS_PWM051a_PWM078_4] [/cover]                          **
** [cover parentID=DS_MCAL_PWM_0911_b] [/cover]                              **
** [cover parentID=DS_NAS_HE2_PWM_PR2938_2] [/cover]                         **
** [cover parentID=DS_NAS_EP_PWM_PR2938_2] [/cover]                          **
**                                                                           **
******************************************************************************/
#if (PWM_DUTY_SHIFT_IN_TICKS == STD_OFF)
void Pwm_17_Gtm_SetPeriodAndDuty
(
  Pwm_17_Gtm_ChannelType ChannelNumber,
  Pwm_17_Gtm_PeriodType  Period,
  uint16    DutyCycle
)
#else
/*Duty cycle is uint32 when duty is given in ticks*/
void Pwm_17_Gtm_SetPeriodAndDuty
(
  Pwm_17_Gtm_ChannelType ChannelNumber,
  Pwm_17_Gtm_PeriodType  Period,
  uint32    DutyCycle
)
#endif
{
  /* Local variables */
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  uint8                       ErrStatus;
  #endif
  /* PWM_DEV_ERROR_DETECT */
  uint8                       CellUsed;
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr;
   /* ROM pointer */
  Pwm_17_Gtm_PropertyType            PwmProperty;
  uint32                      ScaledDuty;
  uint32                      ScaledShiftValue;
  #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
  Pwm_17_Gtm_EdgeNotificationType NotifValue = 0U;
  #endif
  Pwm_17_Gtm_ChannelType             ChIndex;
  #if (PWM_SAFETY_ENABLE == STD_ON)
  #if (PWM_MAX_ASIL_CHANNELS != 0)
  uint8                              ChSignal;
  #endif
  #endif
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  ErrStatus = (uint8)E_OK;
  #endif
  /* PWM_DEV_ERROR_DETECT */

  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  /* PWM003: PWM041: */
  if (PWM_ERROR_FOUND ==
        ( Pwm_lVerUnInitChanAndPer( PWM_SID_SET_PERIOD_DUTY,ChannelNumber ))
     )
  {
    /* PWM051: Return without executing any of functionality */
    ErrStatus = (uint8)E_NOT_OK;
  }
  #if (PWM_SAFETY_ENABLE == STD_ON)
  if (ErrStatus == (uint8)E_OK)
  {
    if (PWM_ERROR_FOUND == Pwm_lSafetyDutyRangeCheck(
                      PWM_SID_SET_PERIOD_DUTY,ChannelNumber,(uint32)DutyCycle))
    {
      /* PWM051: Return without executing any of functionality */
      ErrStatus = (uint8)E_NOT_OK;
    }
    else if (PWM_ERROR_FOUND ==
      Pwm_lSafetyPeriodRangeCheck(PWM_SID_SET_PERIOD_DUTY,ChannelNumber,Period))
    {
        /* PWM051: Return without executing any of functionality */
        ErrStatus = (uint8)E_NOT_OK;
    }
    else
    {
      /*Added to avoid misra warning*/
    }
  }
  #endif
  #endif
  /* PWM_DEV_ERROR_DETECT */

  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  if(ErrStatus == (uint8)E_OK)
  #endif
  /* PWM_DEV_ERROR_DETECT */
  {
    /* Initialize PWM configured channel ROM pointer */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
      PBConfigStructure and is within allowed range.*/
    LocalPwmChanPtr = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
    CellUsed = Pwm_lAssignedHW(LocalPwmChanPtr->ChannelInfo);
    /* Extract Cell number */
    PwmProperty.Coherency = 0x0U;
    PwmProperty.ChannelType = 0x0U;
    PwmProperty.IsReference = 0x0U;
    PwmProperty.PreviousState = 0x0U;
    PwmProperty.RefChannelId = 0x0U;
    PwmProperty.ShiftedSpl = Pwm_lShiftSpl(LocalPwmChanPtr->ChannelInfo);
    PwmProperty.Polarity = Pwm_lPolarity(LocalPwmChanPtr->ChannelInfo);
    /* Get the coherency */
    #if(PWM_DUTY_PERIOD_UPDATED_ENDPERIOD == STD_OFF)
    PwmProperty.Coherency = Pwm_lCoherency(LocalPwmChanPtr->ChannelInfo);
    #else
    PwmProperty.Coherency = PWM_COHERENT;
    #endif
    ChIndex = Pwm_lFindChannelIndex(ChannelNumber);
    #if (PWM_SAFETY_ENABLE == STD_ON)
    #if (PWM_MAX_ASIL_CHANNELS != 0)
    ChSignal = Pwm_lFindChannelSignal(ChannelNumber);
    if (ChSignal == PWM_ASIL_TYPE)
    {
      Pwm_CurrentPeriodVal_Asil[ChIndex] = Period;
    }
    else
    #endif
    #endif
    {
      #if (PWM_MAX_QM_CHANNELS != 0)
      Pwm_CurrentPeriodVal_Qm[ChIndex] = Period;
      #endif
      /*If QM channels are equal to zero do nothing */
    }
    /* Get Scale value of Duty according to period */
    ScaledDuty = (uint32)Pwm_lGetAbsvalEdge(Period,(uint32)DutyCycle);
    ScaledShiftValue = 0U;
    /* Updated the previous state */
    if(Pwm_lGetChannelIdleStatus(ChannelNumber) != 0U)
    {
      PwmProperty.PreviousState = PWM_IDLE_CHANNEL;
      /* Set the Channel Status to Idle */
      Pwm_lClearIdleStatus(ChannelNumber);
    }
    #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    /* Get the details of notification asked */
    NotifValue = Pwm_lGetNotificationKind(ChannelNumber);
    NotifValue = NotifValue >> 5U;
    #if (PWM_NOTIF_FOR_100_0_ENABLE == STD_OFF)
    /* Don't provide notification, if Duty asked for 0% or 100% */
    if ( (ScaledDuty == 0U) || (ScaledDuty == Period) )
    {
      /* Clear the interrupt if duty is 0% or 100%*/
      Pwm_lGtmIrqModify(CellUsed,0U);
      /* Clear notification status in global register */
      Pwm_lClearNotificationStatus(ChannelNumber);
      /* Set the flag in global register to indicate the duty is 0% or 100%*/
      Pwm_lSetDuty_0_Or_100_Status(ChannelNumber);
    }
    else
    {
      /* See whether notification was asked earlier */
      if ( NotifValue != PWM_NO_NOTIFICATION )
      {
        /* Set the notification status since notification is asked*/
        Pwm_lSetNotificationStatus(ChannelNumber);
        /* Enable notification */
        Pwm_lGtmIrqModify(CellUsed,NotifValue);
      }
      /* Clear the flag in global register to indicate the duty is 0% or 100%*/
      Pwm_lClearDuty_0_Or_100_Status(ChannelNumber);
    }
    #else
    if ( NotifValue != PWM_NO_NOTIFICATION )
    {
      /* Set the notification status since notification is asked*/
      Pwm_lSetNotificationStatus(ChannelNumber);
      /* Enable notification */
      Pwm_lGtmIrqModify(CellUsed,NotifValue);
    }
    #endif
    #endif/* PWM_NOTIFICATION_SUPPORTED */

    Pwm_lGtmStartChannel
                      (CellUsed,Period,ScaledDuty,ScaledShiftValue,PwmProperty);
  }
  return;
}

/* End of Pwm_17_Gtm_SetPeriodAndDuty() function */
#endif
/* PWM_SET_PERIOD_AND_DUTY_API */


#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
/* PWM084 */
/******************************************************************************
** Syntax : void Pwm_17_Gtm_SetOutputToIdle                                  **
**                              (Pwm_17_Gtm_ChannelType ChannelNumber)       **
**                                                                           **
** Service ID: 0x04                                                          **
**                                                                           **
** Sync/Async: Synchronous                                                   **
**                                                                           **
** Reentrancy: reentrant                                                     **
**                                                                           **
** Parameters (in):  ChannelNumber : Numeric identifier of the PWM channel   **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:  none                                                       **
**                                                                           **
** Description : Service for to set PWM output to Idle State PWM021:         **
**               1.This API will be useful to set out to Idle immediately and**
**                 during emergency condition                                **
**               Req: PWM021, PWM048, PWM045, PWM047, PWM044, PWM051         **
**                                                                           **
** Traceabilty      :                                                        **
** [cover parentID=DS_AS_PWM099] [/cover]                                    **
** [cover parentID=DS_AS_PWM021] [/cover]                                    **
** [cover parentID=DS_AS_PWM088_3] [/cover]                                  **
** [cover parentID=DS_AS_PWM064_5] [/cover]                                  **
** [cover parentID=DS_AS_PWM002b_PWM117_4] [/cover]                          **
** [cover parentID=DS_AS_PWM002c_PWM047_3] [/cover]                          **
** [cover parentID=DS_AS_PWM086a] [/cover]                                   **
** [cover parentID=DS_AS_PWM086b] [/cover]                                   **
** [cover parentID=DS_AS_PWM084a_PWM084b] [/cover]                           **
** [cover parentID=DS_AS_PWM119] [/cover]                                    **
** [cover parentID=DS_AS_PWM051b_5] [/cover]                                 **
** [cover parentID=DS_AS_PWM051a_PWM078_5] [/cover]                          **
**                                                                           **
******************************************************************************/
void Pwm_17_Gtm_SetOutputToIdle
(
  Pwm_17_Gtm_ChannelType ChannelNumber
)
{
  /*PWM021 : Service to set the Output state */
  /* Local variables */
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  uint8                               ErrStatus;
  #endif
  /* PWM_DEV_ERROR_DETECT */
  uint8                               CellUsed;
  Pwm_17_Gtm_OutputStateType          IdleState;
  uint32                              Period;
  uint32                              ScaledDuty;
  uint32                              ScaledShiftValue;
  Pwm_17_Gtm_PropertyType             PwmProperty;
  #if ((PWM_SET_PERIOD_AND_DUTY_API == STD_ON)&& \
                        (PWM_VARIABLE_PERIOD_USED == STD_ON))
  #if ((PWM_SAFETY_ENABLE == STD_ON)&& (PWM_MAX_ASIL_CHANNELS != 0))
  uint8                              ChSignal;
  #endif
  Pwm_17_Gtm_ChannelType             ChIndex;
  #endif
  uint32                              Duty;
  #if (PWM_DUTY_SHIFT_IN_TICKS == STD_ON)
  Pwm_ChannelIdentifierType           GlobalChannelId;
  #endif
  /* Local pointers */
  const Pwm_17_Gtm_ChannelConfigType  *LocalPwmChanPtr;
  /* ROM pointer */
  #if ((PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON) || \
       (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON) || \
       (PWM_VARIABLE_PERIOD_USED == STD_ON))
  Pwm_17_Gtm_ChannelClassType         ChannelKind;
  #endif
  #if ((PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON) || \
       (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON))
  Pwm_17_Gtm_ChannelType              MainChannel;
  #endif
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  ErrStatus = (uint8)E_OK;
  #endif /* PWM_DEV_ERROR_DETECT */

  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  /* PWM003: PWM048: */
  if ( PWM_ERROR_FOUND ==
             Pwm_lVerUnInitAndChannel(PWM_SID_SETOP2IDLE,ChannelNumber) )
  {
    /*PWM051 : return on any errors found */
    ErrStatus = (uint8)E_NOT_OK;
  }
  #endif /* PWM_DEV_ERROR_DETECT */

  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  if(ErrStatus == (uint8)E_OK)
  #endif /* PWM_DEV_ERROR_DETECT */
  {

    /* Initialize ROM pointer */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
      PBConfigStructure and is within allowed range.*/
    LocalPwmChanPtr = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;

    /* Extract Cell number */
    CellUsed = Pwm_lAssignedHW(LocalPwmChanPtr->ChannelInfo);

    /* Store OCM value */
    IdleState = Pwm_lIdle(LocalPwmChanPtr->ChannelInfo);

    /* Setup Output to LOW or High Depending on Polarity (Duty start)
       for timer cell */
    PwmProperty.IsReference = 0x0U;
    PwmProperty.RefChannelId = 0x0U;

    PwmProperty.Polarity = Pwm_lPolarity(LocalPwmChanPtr->ChannelInfo);
    PwmProperty.ShiftedSpl = Pwm_lShiftSpl(LocalPwmChanPtr->ChannelInfo);
    #if (PWM_FIXED_PERIOD_USED == STD_ON)
    PwmProperty.IsReference  = Pwm_lIsReference(LocalPwmChanPtr->ChannelInfo);
    #endif
    PwmProperty.Coherency = Pwm_lCoherency(LocalPwmChanPtr->ChannelInfo);
    PwmProperty.PreviousState = 0U;
    PwmProperty.ChannelType  = PWM_NORMAL_CHANNEL;
    #if ((PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON) || \
         (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON) || \
         (PWM_VARIABLE_PERIOD_USED == STD_ON))
    ChannelKind = Pwm_lChanClass(LocalPwmChanPtr->ChannelInfo);
    #endif

    #if ((PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON) || \
         (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON))
    /* Get the type of channel used */
    if ((ChannelKind == PWM_FIXED_PERIOD_SHIFTED) || \
        (ChannelKind == PWM_FIXED_PERIOD_CENTER_ALIGNED))
    {
      MainChannel = Pwm_lReferChan(LocalPwmChanPtr->ChannelInfo);
      /* Get main period */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
        PBConfigStructure and is within allowed range.*/
      Period = ((Pwm_kConfigPtr->ChannelConfigPtr)+MainChannel)->PeriodDefault;
      PwmProperty.ChannelType = PWM_SHIFTED_CHANNEL;
    }
    else
    #endif
    {
      /* Get period and duty cycles */
      Period = LocalPwmChanPtr->PeriodDefault;
    }
    #if (PWM_VARIABLE_PERIOD_USED == STD_ON) 
    if(ChannelKind == PWM_VARIABLE_PERIOD)
    {
      #if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
      ChIndex = Pwm_lFindChannelIndex(ChannelNumber);
      /*If safety is Enabled then check for ASIL channels*/
      #if (PWM_SAFETY_ENABLE == STD_ON)
      #if (PWM_MAX_ASIL_CHANNELS != 0)
      ChSignal = Pwm_lFindChannelSignal(ChannelNumber);
      if (ChSignal == PWM_ASIL_TYPE)
      {
        Period = Pwm_CurrentPeriodVal_Asil[ChIndex];
      }
      else
      #endif
      #endif
      {
        #if (PWM_MAX_QM_CHANNELS != 0)
        Period = Pwm_CurrentPeriodVal_Qm[ChIndex];
        #endif
        /*If QM channels are equal to zero do nothing */
      }
      #endif
      /*If set period and Duty API is not enabled then do nothing*/
    }
    #endif
    /* Initialize  Duty as 100 % */
    #if (PWM_DUTY_SHIFT_IN_TICKS == STD_ON)
    GlobalChannelId = Pwm_lGtmChannelIdentifier(CellUsed);
    Duty = Pwm_lMaxDuty(GlobalChannelId);
    #else
    Duty = (uint32)PWM_MAX_DUTY;
    #endif
    if (IdleState != PwmProperty.Polarity)
    {
      /* Idlestate and Polarity mismatches then 0 % duty desired */
      Duty = 0U;
    }
    /* Get Scale value of Duty according to period */
    ScaledDuty = Pwm_lGetAbsvalEdge(Period,(uint32) Duty);
    ScaledShiftValue = 0U;
    #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    #if (PWM_NOTIF_FOR_100_0_ENABLE == STD_ON)
    /* Condition to be checked only if notification for 
       0 % or 100% is enabled */
    #if ((PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON) || \
         (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON))
     /* Check this condition only if Shifted channels or
        Center Aligned channels are used */
     if ((ChannelKind == PWM_FIXED_PERIOD_SHIFTED) || \
          (ChannelKind == PWM_FIXED_PERIOD_CENTER_ALIGNED))
    {
      /* Clear the interrupt since duty is 0% or 100% based on
         Idle state */
      Pwm_lGtmIrqModify(CellUsed,0U);
      /* Clear notification status in global register */
      Pwm_lClearNotificationStatus(ChannelNumber);
      /* Set the flag in global register to indicate the duty is 0% or 100%*/
     Pwm_lSetDuty_0_Or_100_Status(ChannelNumber);
    }
    #endif /* End of check for shifted and CA channels*/
    #else  /* In case PWM_NOTIF_FOR_100_0_ENABLE is STD_OFF */
    {
       /* Clear the interrupt since duty is 0% or 100% based on
        Idle state */
       Pwm_lGtmIrqModify(CellUsed,0U);
       /* Clear notification status in global register */
       Pwm_lClearNotificationStatus(ChannelNumber);
       /* Set the flag in global register to indicate the duty is 0% or 100%*/
       Pwm_lSetDuty_0_Or_100_Status(ChannelNumber);
    }
    #endif /* End of precompile check PWM_NOTIF_FOR_100_0_ENABLE is STD_ON */
    #endif /* End of precompile check PWM_NOTIFICATION_SUPPORTED is STD_ON */
    Pwm_lGtmStartChannel
                     (CellUsed,Period,ScaledDuty,ScaledShiftValue,PwmProperty);
    /* PWM011: Make output immediate to Idle state */
    /* 100% duty with Polarity and 0 % duty with opposite of polarity
      will make the output to given Idlestate */
    /* Set Duty value to zero %age */

    /* Set the Channel Status to Idle */
    Pwm_lSetChannelIdleStatus(ChannelNumber);
  }
  return;
}/* End of Pwm_17_Gtm_SetOutputToIdle() function */
#endif /* PWM_SET_OUTPUT_TO_IDLE_API */


#if (PWM_GET_OUTPUT_STATE_API == STD_ON)  /* PWM085 */
/******************************************************************************
** Syntax : Pwm_17_Gtm_OutputStateType Pwm_17_Gtm_GetOutputState             **
**                                    (Pwm_17_Gtm_ChannelType ChannelNumber) **
**                                                                           **
** Service ID:  0x05                                                         **
**                                                                           **
** Sync/Async:  Synchronous                                                  **
**                                                                           **
** Reentrancy:  reentrant                                                    **
**                                                                           **
** Parameters (in):  ChannelNumber : Numeric identifier of the PWM channel   **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     Pwm_17_Gtm_OutputStateType                              **
**                                                                           **
** Description : Service to read the PWM output state                        **
**               1.If development error detection is enabled and an error is **
**                  detected the service returns PWM_LOW.                    **
**               2.Output state of a PWM channel. Note that this will be read**
**            from the output state on the TOM/ATOM Channel (Assigned_HwUnit)**
**                 connected to the port pin. This will not be read directly **
**                 from the Port Pin. However both will be the same          **
**               Req: PWM022, PWM044, PWm047, PWM051                         **
**                                                                           **
** Traceabilty      :                                                        **
** [cover parentID=DS_AS_PWM100] [/cover]                                    **
** [cover parentID=DS_AS_PWM088_4] [/cover]                                  **
** [cover parentID=DS_AS_PWM064_6] [/cover]                                  **
** [cover parentID=DS_AS_PWM051c] [/cover]                                   **
** [cover parentID=DS_AS_PWM002b_PWM117_5] [/cover]                          **
** [cover parentID=DS_AS_PWM022] [/cover]                                    **
** [cover parentID=DS_AS_PWM002c_PWM047_4] [/cover]                          **
** [cover parentID=DS_AS_PWM085a_PWM085b] [/cover]                           **
** [cover parentID=DS_AS_PWM119] [/cover]                                    **
** [cover parentID=DS_AS_PWM051b_6] [/cover]                                 **
** [cover parentID=DS_AS_PWM051a_PWM078_6] [/cover]                          **
**                                                                           **
******************************************************************************/
Pwm_17_Gtm_OutputStateType Pwm_17_Gtm_GetOutputState
                               (Pwm_17_Gtm_ChannelType ChannelNumber)
{
  /* Local variables */
  /* Service to get the Output State */
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  uint8                       ErrStatus;
  #endif
  /* PWM_DEV_ERROR_DETECT */
  uint8              CellUsed;
  Pwm_17_Gtm_OutputStateType ReturnState;

  /* Local pointers */
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr;
  /* ROM pointer */


  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  ReturnState = (Pwm_17_Gtm_OutputStateType)STD_LOW;
  ErrStatus = (uint8)E_OK;
  #endif
  /* PWM_DEV_ERROR_DETECT */

  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
    /* PWM003: */
  if ( PWM_ERROR_FOUND == Pwm_lVerUnInitAndChannel( PWM_SID_GETOPSTATE,
                                                       ChannelNumber )
     )
  {
    /* In this case, we can satisfy returning of
       PWM_LOW as per PWM051: */
    ErrStatus = (uint8)E_NOT_OK;
  }
  #endif /* PWM_DEV_ERROR_DETECT */

  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  if(ErrStatus == (uint8)E_OK)
  #endif /* PWM_DEV_ERROR_DETECT */
  {
    /* Initialize ROM pointer */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
      PBConfigStructure and is within allowed range.*/
    LocalPwmChanPtr =  (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
    /* Extract Cell number */
    CellUsed = Pwm_lAssignedHW( LocalPwmChanPtr->ChannelInfo );
    ReturnState = Pwm_lGtmGetOutputState(CellUsed);
  }
  /*  Just return the Current State */
  return (ReturnState);
}/* End of Pwm_17_Gtm_GetOutputState API */
#endif /* PWM_GET_OUTPUT_STATE_API */


#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/******************************************************************************
** Syntax : void Pwm_17_Gtm_DisableNotification                              **
**                                  (Pwm_17_Gtm_ChannelType ChannelNumber)   **
**                                                                           **
** Service ID: 0x06                                                          **
**                                                                           **
** Sync/Async: Synchronous                                                   **
**                                                                           **
** Reentrancy: reentrant                                                     **
**                                                                           **
** Parameters (in):  ChannelNumber : Numeric identifier of the PWM channel   **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:  none                                                       **
**                                                                           **
** Description : This service will disable all PWM signal notifications of   **
**               this channel. (PWM023:)                                     **
**                                                                           **
** Traceabilty      :                                                        **
** [cover parentID=DS_AS_PWM101] [/cover]                                    **
** [cover parentID=DS_AS_PWM088_5] [/cover]                                  **
** [cover parentID=DS_AS_PWM023] [/cover]                                    **
** [cover parentID=DS_AS_PWM112a_PWM112b_PWM115b] [/cover]                   **
** [cover parentID=DS_AS_PWM064_7] [/cover]                                  **
** [cover parentID=DS_AS_PWM002b_PWM117_6] [/cover]                          **
** [cover parentID=DS_AS_PWM002c_PWM047_5] [/cover]                          **
** [cover parentID=DS_AS_PWM051b_7] [/cover]                                 **
** [cover parentID=DS_AS_PWM051a_PWM078_7] [/cover]                          **
**                                                                           **
******************************************************************************/
void Pwm_17_Gtm_DisableNotification(Pwm_17_Gtm_ChannelType ChannelNumber)
{
  /* PWM023 : Service to disable the notifications */
  /* Local variables */
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  uint8                       ErrStatus;
  #endif /* PWM_DEV_ERROR_DETECT */
  uint8               CellUsed;
  /* Local pointers */
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; /* ROM pointer */
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  ErrStatus = (uint8)E_OK;
  #endif /* PWM_DEV_ERROR_DETECT */

  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
    /* PWM003: */
  if ( PWM_ERROR_FOUND == Pwm_lVerUnInitAndChannel( PWM_SID_DISABLENOTIFI,
                                                      ChannelNumber )
     )
  {
    /* Return without executing any of functionality */
    ErrStatus = (uint8)E_NOT_OK;
  }
  #endif /* PWM_DEV_ERROR_DETECT */

  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  if(ErrStatus == (uint8)E_OK)
  #endif /* PWM_DEV_ERROR_DETECT */
  {
    /* Initialize PWM configured channel ROM pointer */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
      PBConfigStructure and is within allowed range.*/
    LocalPwmChanPtr = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
    /* Extract Cell number */
    CellUsed = Pwm_lAssignedHW(LocalPwmChanPtr->ChannelInfo);
    Pwm_lGtmIrqModify(CellUsed,0U);
    /* Disable Notification */
    Pwm_lClearNotificationStatus(ChannelNumber);
    /* Reset notification edges */
    Pwm_lClearNotificationEdges(ChannelNumber);
  }
}/* End of Pwm_17_Gtm_DisableNotification() function */

/******************************************************************************
** Syntax : void Pwm_17_Gtm_EnableNotification(                              **
**                               Pwm_17_Gtm_ChannelType       ChannelNumber, **
**                               Pwm_17_Gtm_EdgeNotificationType Notification**
**                               )                                           **
** Service ID: 0x07                                                          **
**                                                                           **
** Sync/Async: Synchronous                                                   **
**                                                                           **
** Reentrancy: reentrant                                                     **
**                                                                           **
** Parameters (in):  ChannelNumber : Numeric identifier of the PWM channel   **
**                   Notification  : PWM_RISING_EDGE or                      **
**                                   PWM_FALLING_EDGE or                     **
**                                   PWM_BOTH_EDGES                          **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:  none                                                       **
**                                                                           **
** Description : This service will enable the PWM signal notification        **
**               according to notification parameter. PWM024:                **
**                                                                           **
** Traceabilty      :                                                        **
** [cover parentID=DS_AS_PWM102] [/cover]                                    **
** [cover parentID=DS_AS_PWM088_6] [/cover]                                  **
** [cover parentID=DS_AS_PWM024] [/cover]                                    **
** [cover parentID=DS_AS_PWM113a_PWM113b_PWM115a] [/cover]                   **
** [cover parentID=DS_AS_PWM081] [/cover]                                    **
** [cover parentID=DS_AS_PWM064_8] [/cover]                                  **
** [cover parentID=DS_AS_PWM002b_PWM117_7] [/cover]                          **
** [cover parentID=DS_AS_PWM002c_PWM047_6] [/cover]                          **
** [cover parentID=DS_AS_PWM051b_8] [/cover]                                 **
** [cover parentID=DS_AS_PWM051a_PWM078_8] [/cover]                          **
**                                                                           **
******************************************************************************/
void Pwm_17_Gtm_EnableNotification
(
  Pwm_17_Gtm_ChannelType          ChannelNumber,
  Pwm_17_Gtm_EdgeNotificationType Notification
)
{
  /* Local variables */
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  uint8                       ErrStatus;
  #endif /* PWM_DEV_ERROR_DETECT */
  Pwm_17_Gtm_ChannelClassType        ChannelKind;
  uint8 CellUsed;
  uint8 Polarity;
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; /* ROM pointer */
  Pwm_17_Gtm_ChannelType ChIndex;
  #if ((PWM_SAFETY_ENABLE == STD_ON)&&(PWM_MAX_ASIL_CHANNELS != 0))
  uint8 ChSignal;
  #endif
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  ErrStatus = (uint8)E_OK;
  #endif /* PWM_DEV_ERROR_DETECT */

  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  /* PWM003: */
  if ( PWM_ERROR_FOUND == Pwm_lVerUnInitAndChannel( PWM_SID_ENABLENOTIFI,
                                                       ChannelNumber )
     )
  {
    /* Return without executing any of functionality */
    ErrStatus = (uint8)E_NOT_OK;
  }
  #endif /* PWM_DEV_ERROR_DETECT */

  #if (PWM_SAFETY_ENABLE == STD_ON)
  if(ErrStatus == (uint8)E_OK)
  {
    if ((Notification < PWM_RISING_EDGE) || (Notification > PWM_BOTH_EDGES))
    {
      /* Report Safety Error */
      SafeMcal_ReportError(
                            PWM_17_GTM_MODULE_ID,
                            PWM_17_GTM_INSTANCE_ID,
                            PWM_SID_ENABLENOTIFI,
                            PWM_E_PARAM_EDGE
                          );
    }
  }
  #endif
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  if(ErrStatus == (uint8)E_OK)
  #endif /* PWM_DEV_ERROR_DETECT */
  {
    ChIndex = Pwm_lFindChannelIndex(ChannelNumber);
    /* Initialize PWM configured channel ROM pointer */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
      PBConfigStructure and is within allowed range.*/
    LocalPwmChanPtr = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
    /* PWM 033 If a callback notification is configured as
    null pointer, no callback shall be executed. */
    if ( ( LocalPwmChanPtr->Notification ) !=  NULL_PTR)
    {
      /* Extract Cell number */
      CellUsed = Pwm_lAssignedHW(LocalPwmChanPtr->ChannelInfo);
      Polarity = Pwm_lPolarity(LocalPwmChanPtr->ChannelInfo);
      ChannelKind = Pwm_lChanClass(LocalPwmChanPtr->ChannelInfo);
      if ((ChannelKind == PWM_FIXED_PERIOD_SHIFTED) || \
           (ChannelKind == PWM_FIXED_PERIOD_CENTER_ALIGNED))
      {
        Polarity = Polarity ^ 1U;
      }
      if( Polarity == PWM_LOW )
      {
        if((Notification == PWM_RISING_EDGE)||(Notification ==PWM_FALLING_EDGE))
        {
          Notification =
               ((Pwm_17_Gtm_EdgeNotificationType)(~Notification) & PWM_CONST_3);
        }
      }
      Pwm_lSetNotificationEdges(ChannelNumber,Notification);
      /* Enable notification if Duty is not equal to 0% or 100% */
      #if (PWM_SAFETY_ENABLE == STD_ON)
      #if (PWM_MAX_ASIL_CHANNELS != 0)
      ChSignal = Pwm_lFindChannelSignal(ChannelNumber);
      if (ChSignal == PWM_ASIL_TYPE)
      {
       Pwm_lEnableAsilNotif(ChannelKind,ChannelNumber,\
                                CellUsed,Notification,ChIndex);
      }
      else
      #endif
      #endif
      {
      #if (PWM_MAX_QM_CHANNELS != 0)
      Pwm_lEnableQmNotif(ChannelKind,ChannelNumber,\
                                CellUsed,Notification,ChIndex);
      #endif
      /*If QM channels are equal to zero do nothing */
      }
    }
  }
}/* End of Pwm_17_Gtm_EnableNotification() function */
#endif /* PWM_NOTIFICATION_SUPPORTED */

/******************************************************************************
**                      Private Function Definitions                         **
******************************************************************************/

/******************************************************************************
** Syntax : IFX_LOCAL_INLINE Pwm_17_Gtm_PeriodType Pwm_lGetAbsvalEdge(       **
**                                             Pwm_17_Gtm_PeriodType Period, **
**                                                          uint32 Value)    **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Period : Period Value in terms of Timer Count          **
**                    Value : Relative Value (0x0000 to 0x8000 ) (PWM059:)   **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      Absolute Value : Returns the converted value           **
**                                                                           **
** Description :      Local function : This function will convert the passed **
**                                    value to scaled value as per Period    **
**                                    This will be utilized for edge aligned **
**                                    Type PWM channels                      **
**                                                                           **
** Traceabilty      :                                                        **
** [cover parentID=DS_AS4XX_PWM150] [/cover]                                 **
** [cover parentID=DS_AS_PWM070] [/cover]                                    **
** [cover parentID=DS_AS_PWM059] [/cover]                                    **
**                                                                           **
******************************************************************************/
IFX_LOCAL_INLINE Pwm_17_Gtm_PeriodType Pwm_lGetAbsvalEdge  \
                                   (Pwm_17_Gtm_PeriodType Period, uint32 Value)
{
  Pwm_17_Gtm_PeriodType ScaledValue;
  #if (PWM_DUTY_SHIFT_IN_TICKS == STD_ON)
  /* Dutycycle is in absolute ticks, use this directly */
  ScaledValue = Value;
  #else
  /* Dutycycle is in percentage */
  /* Covert the passed Relative value to absolute value as mentioned in SWS
  (AbsoluteDutyCycle=(((uint32)AbsolutePeriodTime * relativeDutyCycle)))>>15)*/
  ScaledValue = (Pwm_17_Gtm_PeriodType)((Value * Period) >> PWM_SHIFT_BY15);
  #endif /* (PWM_DUTY_SHIFT_IN_TICKS == STD_ON) */

  /* Verify Scaled value is greater or equal to Period? */
  if (Period <= ScaledValue)
  {
    /* Make scaled value with full range of timer max */
    ScaledValue = Period;
  }
  if (Period == 0U)
  {
    /* Make scaled value zero for zero period */
    ScaledValue = 0U;
  }

  return (ScaledValue);
}/* End of Pwm_lGetAbsvalEdge() function */

#if (PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON)
/******************************************************************************
** Syntax : IFX_LOCAL_INLINE Pwm_17_Gtm_PeriodType Pwm_lGetAbsvalShCen(      **
**                                            Pwm_17_Gtm_PeriodType Period,  **
**                                            Pwm_17_Gtm_PeriodType Value    **
**                                            )                              **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Period : Period Value in terms of Timer Count          **
**                    Value : Relative Value (0x0000 to 0x8000 ) (PWM059:)   **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      Absolute Value : Returns the converted value           **
**                                                                           **
** Description :      Local function : This function will convert the passed **
**                                    value to scaled value as per Period    **
**                                    This will be utilized for Shift and    **
**                                    Center aligned Type PWM channels       **
**                                                                           **
******************************************************************************/
IFX_LOCAL_INLINE Pwm_17_Gtm_PeriodType Pwm_lGetAbsvalShCen
                     (Pwm_17_Gtm_PeriodType Period,Pwm_17_Gtm_PeriodType Value)
{
  Pwm_17_Gtm_PeriodType ScaledValue;

  #if (PWM_DUTY_SHIFT_IN_TICKS == STD_ON)
  /* Duty and Shift are in absolute ticks, use these directly */
  ScaledValue = Value;
  #else
  /* Duty and Shift are in percentage */
  /* Covert the passed Relative value to absolute value as mentioned in SWS
  (AbsoluteDutyCycle=
   (((uint32)AbsolutePeriodTime * relativeDutyCycle)))>> 15)*/
  ScaledValue = (Pwm_17_Gtm_PeriodType)
                         (((Value * (uint32)Period)) >> PWM_SHIFT_BY15);
  #endif /* (PWM_DUTY_SHIFT_IN_TICKS == STD_ON) */

  /* Verify Scaled value is greater or equal to Period? */
  if (Period <= ScaledValue)
  {
    /* Make scaled value with full range of timer max */
    ScaledValue = PWM_MAX_TIMER;
  }
  if (Period == 0U)
  {
    /* Make scaled value zero for zero period */
    ScaledValue = 0U;
  }

  return (ScaledValue);
}/* End of Pwm_lGetAbsvalShCen() function */

/******************************************************************************
** Syntax : IFX_LOCAL_INLINE Pwm_17_Gtm_PeriodType Pwm_lGetShiftLead(        **
**                                             Pwm_17_Gtm_PeriodType Period, **
**                                             Pwm_17_Gtm_PeriodType Shift)  **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Period : Period Value in terms of Timer Count          **
**                    Shift : Relative Value (0x0000 to 0x8000 )             **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      Absolute Value : Returns the converted value           **
**                                                                           **
** Description :      Local function : This function will convert the passed **
**                                    shift value to Absolute value in scale **
**                                    of Period passed. The value informs    **
**                                    leading timer count to position the    **
**                                    edge                                   **
******************************************************************************/
IFX_LOCAL_INLINE Pwm_17_Gtm_PeriodType Pwm_lGetShiftLead(
                     Pwm_17_Gtm_PeriodType Period,Pwm_17_Gtm_PeriodType Shift)
{
  Pwm_17_Gtm_PeriodType ScaledShiftLead;

  /* Get Scaled value of Shift */
  ScaledShiftLead = Pwm_lGetAbsvalShCen(Period, Shift);

  /* Verify ScaledShiftLead is greater or equal to Period? */
  if (ScaledShiftLead >= Period)
  {
    /* Make scaled value with 0 */
    ScaledShiftLead = (Pwm_17_Gtm_PeriodType)0;
  }

  return ScaledShiftLead;
}/* End of Pwm_lGetShiftLead() function */
#endif /* (PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON) */

  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  /* PWM003: */
/*
 * Functions when PWM_DEV_ERROR_DETECT defined
 */
/******************************************************************************
** Syntax : IFX_LOCAL_INLINE uint32 Pwm_lVerChannel( uint8 ServiceID,        **
**                                    Pwm_17_Gtm_ChannelType ChannelNumber ) **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Service ID    : Informs Service ID of an API           **
**                    ChannelNumber : PWM Channel number                     **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      ErrorFlag (uint32)                                     **
**                                                                           **
** Description :      Local function :Service to detect whether the passed   **
**                                   channel number is valid or not          **
**                                                                           **
** Traceability:                                                             **
** [cover parentID=DS_NAS_PWM_PR127_1] [/cover]                              **
**                                                                           **
******************************************************************************/
IFX_LOCAL_INLINE uint32 Pwm_lVerChannel
(
  uint8           ServiceID,
  Pwm_17_Gtm_ChannelType ChannelNumber
)
{
  uint32 ErrorFlag;
  ErrorFlag = (uint32)0;

  /* Verify whether Invalid channel number has been sent */
  if ( ChannelNumber >= Pwm_kConfigPtr->MaxChannels )
  {
    /* PWM002: Report to DET upon error */
    #if (PWM_DEV_ERROR_DETECT == STD_ON)
    Det_ReportError(
                     PWM_17_GTM_MODULE_ID,
                     PWM_17_GTM_INSTANCE_ID,
                     ServiceID,
                     PWM_E_PARAM_CHANNEL
                   );/* PWM047: End of report to  DET */
    #endif
    #if (PWM_SAFETY_ENABLE == STD_ON)
    /* Report Safety Error */
    SafeMcal_ReportError(
                         PWM_17_GTM_MODULE_ID,
                         PWM_17_GTM_INSTANCE_ID,
                         ServiceID,
                         PWM_E_PARAM_CHANNEL
                         );
    #endif
    ErrorFlag = PWM_ERROR_FOUND; /* Set Error Flag */
  }
  return ErrorFlag;
}/* End of Pwm_lVerChannel() function */

/******************************************************************************
** Syntax : IFX_LOCAL_INLINE uint32 Pwm_lVerUnInit( uint8 ServiceID )        **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Service ID : Informs Service ID of an API              **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      ErrorFlag (uint32)                                     **
**                                                                           **
** Description :      Local function :Service to detect UnInit               **
**                                                                           **
** Traceability:                                                             **
** [cover parentID=DS_NAS_PWM_PR127_2] [/cover]                              **
**                                                                           **
******************************************************************************/
IFX_LOCAL_INLINE uint32 Pwm_lVerUnInit( uint8 ServiceID )
{
  uint32      ErrorFlag;
  ErrorFlag = (uint32)0;

  /* Verify whether Init has been called */
  #if (PWM_PB_FIXEDADDR == STD_OFF)
  if (NULL_PTR == Pwm_kConfigPtr)
  #else
  if (PWM_INITIALIZED != Pwm_InitStatus)
  #endif /* (PWM_PB_FIXEDADDR == STD_OFF) */
  {
    /* PWM002: Report to DET upon error */
    #if (PWM_DEV_ERROR_DETECT == STD_ON)
    Det_ReportError(
                     PWM_17_GTM_MODULE_ID,
                     PWM_17_GTM_INSTANCE_ID,
                     ServiceID,
                     PWM_E_UNINIT
                   );/* PWM044: End of report to  DET */
    #else
    UNUSED_PARAMETER(ServiceID)
    #endif
    ErrorFlag = PWM_ERROR_FOUND; /* Set Error Flag */
  }
  return ErrorFlag;
}/* End of Pwm_lVerUnInit() function */

/******************************************************************************
** Syntax : IFX_LOCAL_INLINE uint32 Pwm_lVerUnInitAndChannel (               **
**                                      uint8 ServiceID           ,          **
**                                      Pwm_17_Gtm_ChannelType ChannelNumber)**
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Service ID    : Informs Service ID of an API           **
**                    ChannelNumber : PWM Channel number                     **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      ErrorFlag (uint32)                                     **
**                                                                           **
** Description :      Local function :Service to detect UnInit and wrong     **
**                                   channel number                          **
**                                                                           **
** Traceability:                                                             **
** [cover parentID=DS_NAS_PWM_PR127_3] [/cover]                              **
**                                                                           **
******************************************************************************/
IFX_LOCAL_INLINE uint32 Pwm_lVerUnInitAndChannel
(
  uint8           ServiceID,
  Pwm_17_Gtm_ChannelType ChannelNumber
)
{
  uint32      ErrorFlag;
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  /* Verify whether Init has been called */
  ErrorFlag = Pwm_lVerUnInit(ServiceID);
  if (ErrorFlag != PWM_ERROR_FOUND)
  #endif /* PWM_DEV_ERROR_DETECT */
  {
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
    /* Verify whether Invalid channel number has been sent */
    ErrorFlag = Pwm_lVerChannel(ServiceID,ChannelNumber);
  #endif
  }
  return ErrorFlag;
} /* End of Pwm_lVerUnInitAndChannel() function */

/******************************************************************************
** Syntax : static uint32 Pwm_lInitDetCheck                                  **
**                                (const Pwm_17_Gtm_ConfigType *DetConfigPtr)**
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        non reentrant                                          **
**                                                                           **
** Parameters (in):   DetConfigPtr - Pointer to configuration set            **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      ErrorFlag (uint32)                                     **
**                                                                           **
** Description :      Local function :Service for DET check in Pwm_Init()    **
**                                   function PWM046,PWM002                  **
**                                                                           **
** Traceability:                                                             **
** [cover parentID=DS_NAS_PWM_PR127_4] [/cover]                              **
**                                                                           **
******************************************************************************/
static uint32 Pwm_lInitDetCheck( const Pwm_17_Gtm_ConfigType *DetConfigPtr )
{
  uint32      ErrorFlag;
  ErrorFlag = (uint32)0;

  /* Verify whether Init has already been called */
  #if ( PWM_PB_FIXEDADDR == STD_OFF )
  if (NULL_PTR != Pwm_kConfigPtr)
  #else
  if (PWM_INITIALIZED == Pwm_InitStatus)
  #endif /* End Of PWM_PB_FIXEDADDR */
  {
    #if (PWM_DEV_ERROR_DETECT == STD_ON)
    /* PWM002: Report to DET upon error */
    Det_ReportError(
                     PWM_17_GTM_MODULE_ID,
                     PWM_17_GTM_INSTANCE_ID,
                     PWM_SID_INIT,
                     PWM_E_ALREADY_INITIALIZED
                   );/* PWM118: End of report to DET */

    /*Error flag is set*/
    ErrorFlag = PWM_ERROR_FOUND; /* Set Error Flag */
    #endif
  }
  /*PWM046:If development error detection is enabled,
           the parameter ConfigPtr shall
            be checked for not being a NULL pointer. */
  /* To verify whether Init has been called with wrong parameter */
  else
  #if ( PWM_PB_FIXEDADDR == STD_OFF )
  /* Det Check for NULL pointer  */
  if ( NULL_PTR == DetConfigPtr )
  #else
    /* Passed ConfigPtr and Pwm_kConfigPtr should match*/
    /* Parameter check for init */
  if (Pwm_kConfigPtr != DetConfigPtr)
  #endif  /*End Of PWM_PB_FIXEDADDR */
  {
    /*
     PWM002: Report to DET upon error, Init has been called with wrong
      parameter NULL Config Pointer
    */
    #if (PWM_DEV_ERROR_DETECT == STD_ON)
    Det_ReportError(
                     PWM_17_GTM_MODULE_ID,
                     PWM_17_GTM_INSTANCE_ID,
                     PWM_SID_INIT,
                     PWM_E_PARAM_CONFIG
                   ); /* PWM046: Report to  DET */
    #endif
    #if(PWM_SAFETY_ENABLE == STD_ON)
    SafeMcal_ReportError(
                          PWM_17_GTM_MODULE_ID,
                          PWM_17_GTM_INSTANCE_ID,
                          PWM_SID_INIT,
                          PWM_E_PARAM_CONFIG
                        );
    #endif
    ErrorFlag = PWM_ERROR_FOUND;
  }
  else
  {
    /* Do nothing - added for Misra check */
  }
  return (ErrorFlag);
} /* End of Pwm_lInitDetCheck() function */

#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
/******************************************************************************
** Syntax : IFX_LOCAL_INLINE uint32 Pwm_lVerUnInitChanAndPer (               **
**                                     uint8 ServiceID,                      **
**                                     Pwm_17_Gtm_ChannelType ChannelNumber) **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Service ID    : Informs Service ID of an API           **
**                    ChannelNumber : PWM Channel number                     **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      ErrorFlag (uint32)                                     **
**                                                                           **
** Description :      Local function :Service to verify DET for UnInit,      **
**                                   channel No and not variable period      **
**                                   [period and duty range checks for asil  **
**                                    signal if safety is enabled ]          **
** Traceability:                                                             **
** [cover parentID=DS_NAS_PWM_PR127_5] [/cover]                              **
**                                                                           **
******************************************************************************/
IFX_LOCAL_INLINE uint32 Pwm_lVerUnInitChanAndPer
(
  uint8           ServiceID,
  Pwm_17_Gtm_ChannelType ChannelNumber
)
{
  uint32          ErrorFlag;
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  Pwm_17_Gtm_ChannelClassType        ChannelKind;
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; /* ROM pointer */
  #endif
  #if (PWM_DEV_ERROR_DETECT == STD_ON)
  /* Verify whether Init has been called */
  ErrorFlag = Pwm_lVerUnInit(ServiceID);
  if (ErrorFlag != PWM_ERROR_FOUND)
  #endif
  {
    #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
    /* Verify whether Invalid channel number has been sent */
    ErrorFlag = Pwm_lVerChannel(ServiceID,ChannelNumber);
    #endif
    #if (PWM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorFlag != PWM_ERROR_FOUND)
    {
      /* Initialize local config pointer according to channel passed */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
        PBConfigStructure and is within allowed range.*/
      LocalPwmChanPtr = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
      /* Get the type of channel used */
      ChannelKind = Pwm_lChanClass(LocalPwmChanPtr->ChannelInfo);
      /* Verify whether channel provided for not variable period */
      if ( PWM_VARIABLE_PERIOD != ChannelKind )
      {
        /* PWM002: Error Classified to report to DET */

        Det_ReportError(
                      PWM_17_GTM_MODULE_ID,
                      PWM_17_GTM_INSTANCE_ID,
                      ServiceID,
                      PWM_E_PERIOD_UNCHANGEABLE
                    );/* PWM045: End of report to  DET */

        ErrorFlag = PWM_ERROR_FOUND; /* Set Error Flag */
      }
      /* end of if PWM_VARIABLE_PERIOD != ChannelKind */
    }
    /* end of if ( ErrorFlag != PWM_ERROR_FOUND) */
    #endif
  }
  /* end of if ( ErrorFlag != PWM_ERROR_FOUND) */
  return ErrorFlag;
}/* End of function Pwm_lVerUnInitChanAndPer */
#endif /* (PWM_SET_PERIOD_AND_DUTY_API == STD_ON) */

#endif /* PWM_DEV_ERROR_DETECT */

#if (PWM_VARIABLE_PERIOD_USED == STD_ON)
/******************************************************************************
** Syntax : static void Pwm_lInitVariablePeriod (                            **
**                                           uint8 CellUsed,                 **
**                                           uint32 ChannelNumber)           **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   CellUsed      :  Used GTM channel                      **
**                    ChannelNumber : PWM Channel number                     **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Local function :Service to initialize variable period  **
**                                   channel                                 **
**                                                                           **
******************************************************************************/
static void Pwm_lInitVariablePeriod
(
  uint8 CellUsed,
  uint32 ChannelNumber
)
{
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; /* ROM pointer */
  Pwm_17_Gtm_PropertyType            PwmProperty;
  uint32                      Period;
  uint32                      ScaledDuty;
  uint32                      ShiftVal;
  uint32                      Duty;
  Pwm_17_Gtm_ChannelType      ChIndex;
  #if (PWM_SAFETY_ENABLE == STD_ON)
  #if (PWM_MAX_ASIL_CHANNELS != 0)
  uint8                       ChSignal;
  #endif
  #endif
  /* Initialize PWM configured channel ROM pointer */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    PBConfigStructure and is within allowed range.*/
  LocalPwmChanPtr          = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
  PwmProperty.Polarity     = Pwm_lPolarity(LocalPwmChanPtr->ChannelInfo);
  PwmProperty.Coherency    = Pwm_lCoherency(LocalPwmChanPtr->ChannelInfo);
  PwmProperty.IsReference  = PWM_NORMAL_CHANNEL;
  PwmProperty.PreviousState = PWM_IDLE_CHANNEL;
  PwmProperty.ChannelType  = PWM_NORMAL_CHANNEL;
  PwmProperty.ShiftedSpl   = Pwm_lShiftSpl(LocalPwmChanPtr->ChannelInfo);
  PwmProperty.ResetShift   = Pwm_lResetShift(LocalPwmChanPtr->ChannelInfo);
  Period                   = LocalPwmChanPtr->PeriodDefault;
  Duty                     = (uint32)LocalPwmChanPtr->DutycycleDefault;
  /* Get Scale value of Duty according to period */
  ScaledDuty = (uint32)Pwm_lGetAbsvalEdge(Period, Duty);
  ShiftVal = 0U;
  ChIndex = Pwm_lFindChannelIndex(ChannelNumber);
  #if (PWM_SAFETY_ENABLE == STD_ON)
  #if (PWM_MAX_ASIL_CHANNELS != 0)
  ChSignal = Pwm_lFindChannelSignal(ChannelNumber);
  if (ChSignal == PWM_ASIL_TYPE)
  {
    Pwm_CurrentPeriodVal_Asil[ChIndex] = Period;
  }
  else
  #endif
  #endif
  {
    #if (PWM_MAX_QM_CHANNELS != 0)
    Pwm_CurrentPeriodVal_Qm[ChIndex] = Period;
    #endif
    /*If QM channels are equal to zero do nothing */
  }
  #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
  #if (PWM_NOTIF_FOR_100_0_ENABLE == STD_OFF) 
  if ((ScaledDuty == 0U) || ( ScaledDuty == Period)) 
  {
    /* Set the flag in global register to indicate the duty is 0% or 100% */
    Pwm_lSetDuty_0_Or_100_Status(ChannelNumber);
  }
  #endif
  #endif

  Pwm_lGtmStartChannelsInit(CellUsed,Period,ScaledDuty,ShiftVal,PwmProperty);

} /* End of function Pwm_lInitVariablePeriod */
#endif /* PWM_VARIABLE_PERIOD_USED */

#if (PWM_FIXED_PERIOD_USED == STD_ON)
/******************************************************************************
** Syntax : static void Pwm_lInitFixedPeriod (                               **
**                                           uint8 CellUsed,                 **
**                                           uint32 ChannelNumber)           **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   CellUsed    : Used GTM channel                         **
**                    ChannelNumber : PWM Channel number                     **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Local function :Service to initialize fixed period     **
**                                   channel                                 **
**                                                                           **
******************************************************************************/
static void Pwm_lInitFixedPeriod
(
  uint8 CellUsed,
  uint32 ChannelNumber
)
{
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; /* ROM pointer */
  Pwm_17_Gtm_PropertyType         PwmProperty;
  uint32                      Period;
  uint32                      ScaledDuty;
  uint32                      ShiftVal;
  uint32                      Duty;

  /* Initialize PWM configured channel ROM pointer */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    PBConfigStructure and is within allowed range.*/
  LocalPwmChanPtr          = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
  PwmProperty.Polarity     = Pwm_lPolarity(LocalPwmChanPtr->ChannelInfo);
  PwmProperty.Coherency    = Pwm_lCoherency(LocalPwmChanPtr->ChannelInfo);
  PwmProperty.IsReference  = Pwm_lIsReference(LocalPwmChanPtr->ChannelInfo);
  PwmProperty.PreviousState = PWM_IDLE_CHANNEL;
  PwmProperty.ChannelType  = PWM_NORMAL_CHANNEL;
  PwmProperty.ShiftedSpl   = Pwm_lShiftSpl(LocalPwmChanPtr->ChannelInfo);
  PwmProperty.ResetShift   = Pwm_lResetShift(LocalPwmChanPtr->ChannelInfo);
  Period                   = LocalPwmChanPtr->PeriodDefault;
  Duty                     = LocalPwmChanPtr->DutycycleDefault;
  /* Get Scale value of Duty according to period */
  ScaledDuty = (uint32)Pwm_lGetAbsvalEdge(Period, Duty);
  ShiftVal = 0U;
  #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
  #if (PWM_NOTIF_FOR_100_0_ENABLE == STD_OFF)
  if ((ScaledDuty == 0U) || ( ScaledDuty == Period))
  {
    /* Set the flag in global register to indicate the duty is 0% or 100% */
    Pwm_lSetDuty_0_Or_100_Status(ChannelNumber);
  }
  #endif
  #endif
  Pwm_lGtmStartChannelsInit(CellUsed,Period,ScaledDuty,ShiftVal,PwmProperty);

} /* End of function Pwm_lInitFixedPeriod */
#endif /* PWM_FIXED_PERIOD_USED */

#if (PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON)
/******************************************************************************
** Syntax : static void Pwm_lInitFixedPeriodShifted (                        **
**                                           uint8 CellUsed,                 **
**                                           uint32 ChannelNumber)           **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   CellUsed    : Used GTM channel                         **
**                    ChannelNumber : PWM Channel number                     **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Local function :Service to initialize shifted period   **
**                                   channel                                 **
**                                                                           **
******************************************************************************/
static void Pwm_lInitFixedPeriodShifted
(
  uint8 CellUsed,
  uint32 ChannelNumber
)
{
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; /* ROM pointer */
  Pwm_17_Gtm_PropertyType         PwmProperty;
  uint32                      Period;
  uint32                      ScaledDuty;
  uint32                      ShiftVal;
  uint32                      MainChannel;
  uint32                      Duty;

  /* Initialize PWM configured channel ROM pointer */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    PBConfigStructure and is within allowed range.*/
  LocalPwmChanPtr          = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
  PwmProperty.Polarity     = Pwm_lPolarity(LocalPwmChanPtr->ChannelInfo);
  PwmProperty.Coherency    = Pwm_lCoherency(LocalPwmChanPtr->ChannelInfo);
  PwmProperty.IsReference  = PWM_NORMAL_CHANNEL;
  PwmProperty.PreviousState = PWM_IDLE_CHANNEL;
  PwmProperty.ChannelType  = PWM_SHIFTED_CHANNEL;
  PwmProperty.ShiftedSpl   = Pwm_lShiftSpl(LocalPwmChanPtr->ChannelInfo);
  PwmProperty.ResetShift   = Pwm_lResetShift(LocalPwmChanPtr->ChannelInfo);
  Duty                     = LocalPwmChanPtr->DutycycleDefault;
  MainChannel = Pwm_lReferChan(LocalPwmChanPtr->ChannelInfo);
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    PBConfigStructure and is within allowed range.*/
  PwmProperty.RefChannelId = Pwm_lAssignedHW
            (((Pwm_kConfigPtr->ChannelConfigPtr) + MainChannel )->ChannelInfo);
  /* Get main period */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    PBConfigStructure and is within allowed range.*/
  Period = ((Pwm_kConfigPtr->ChannelConfigPtr) + MainChannel )->PeriodDefault;

  /* Get Scale value of Duty according to period */
  ScaledDuty = (uint32)Pwm_lGetAbsvalEdge(Period, Duty);
  /* Get the Shift lead value */
  #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
  if ((ScaledDuty == 0U) || ( ScaledDuty == Period))
  {
    /* Set the flag in global register to indicate the duty is 0% or 100% */
    Pwm_lSetDuty_0_Or_100_Status(ChannelNumber);
  }
  #endif
  ShiftVal = (uint32)Pwm_lGetShiftLead( Period,
                      (Pwm_17_Gtm_PeriodType)(LocalPwmChanPtr->ShiftValue) );
  Pwm_lGtmStartChannelsInit(CellUsed,Period,ScaledDuty,ShiftVal,PwmProperty);

} /* End of function Pwm_lInitFixedPeriodShifted */
#endif /* PWM_FIXED_PERIOD_SHIFTED_USED */

#if (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON)
/******************************************************************************
** Syntax : static void Pwm_lInitCentreAligned (                             **
**                                           uint8 CellUsed,                 **
**                                           uint32 ChannelNumber)           **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   CellUsed    : Used GTM channel                         **
**                    ChannelNumber : PWM Channel number                     **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Local function :Service to initialize centre aligned   **
**                                   channel                                 **
**                                                                           **
******************************************************************************/
static void Pwm_lInitCentreAligned
(
  uint8 CellUsed,
  uint32 ChannelNumber
)
{
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; /* ROM pointer */
  Pwm_17_Gtm_PropertyType         PwmProperty;
  uint32                      Period;
  uint32                      ScaledDuty;
  uint32                      ShiftVal;
  uint32                      MainChannel;
  uint32                      Duty;

  /* Initialize PWM configured channel ROM pointer */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    PBConfigStructure and is within allowed range.*/
  LocalPwmChanPtr          = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
  PwmProperty.Polarity     = Pwm_lPolarity(LocalPwmChanPtr->ChannelInfo);
  PwmProperty.Coherency    = Pwm_lCoherency(LocalPwmChanPtr->ChannelInfo);
  PwmProperty.IsReference  = PWM_NORMAL_CHANNEL;
  PwmProperty.PreviousState = PWM_IDLE_CHANNEL;
  PwmProperty.ChannelType  = PWM_SHIFTED_CHANNEL;
  PwmProperty.ShiftedSpl   = Pwm_lShiftSpl(LocalPwmChanPtr->ChannelInfo);
  PwmProperty.ResetShift   = Pwm_lResetShift(LocalPwmChanPtr->ChannelInfo);
  Duty                     = LocalPwmChanPtr->DutycycleDefault;
  MainChannel = Pwm_lReferChan(LocalPwmChanPtr->ChannelInfo);
  /* UTP AI00134683 */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    PBConfigStructure and is within allowed range.*/
  PwmProperty.RefChannelId = Pwm_lAssignedHW
            (((Pwm_kConfigPtr->ChannelConfigPtr) + MainChannel )->ChannelInfo);
  /* Get main period,  */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    PBConfigStructure and is within allowed range.*/
  Period = ((Pwm_kConfigPtr->ChannelConfigPtr) + MainChannel )->PeriodDefault;

  /* Get Scale value of Duty according to period */
  ScaledDuty = (uint32)Pwm_lGetAbsvalEdge(Period, Duty);
  #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
  if ((ScaledDuty == 0U) || ( ScaledDuty == Period))
  {
    /* Set the flag in global register to indicate the duty is 0% or 100% */
    Pwm_lSetDuty_0_Or_100_Status(ChannelNumber);
  }
  #endif
  /* Get Centre Lead value */
  ShiftVal = (uint32)Pwm_lGetCenterLead(Period, ScaledDuty);
  Pwm_lGtmStartChannelsInit(CellUsed,Period,ScaledDuty,ShiftVal,PwmProperty);

} /* End of function Pwm_lInitCentreAligned */
#endif /* PWM_USED_FIXED_PERIOD_CENTER_ALIGNED */

#if (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON)
/******************************************************************************
** Syntax : IFX_LOCAL_INLINE Pwm_17_Gtm_PeriodType Pwm_lGetCenterLead(       **
**                                          Pwm_17_Gtm_PeriodType Period,    **
**                                          Pwm_17_Gtm_PeriodType ScaledDuty)**
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Period : Period Value in terms of Timer Count          **
**                    ScaledDuty : Duty Value (Scaled as per Period)         **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      Absolute Value : Returns the converted lead value      **
**                                                                           **
** Description :      Local function : This function will convert the passed **
**                                    scaled Duty value to Center aligned    **
**                                    Absolute lead value in scale of period **
**                                    passed. The value informs the leading  **
**                                    timer count to position the edge.      **
**                                    To get Scaled Center Lead value as per **
**                                    Period and ScaledDuty                  **
**                                                                           **
******************************************************************************/
IFX_LOCAL_INLINE Pwm_17_Gtm_PeriodType Pwm_lGetCenterLead
(
  Pwm_17_Gtm_PeriodType Period,
  Pwm_17_Gtm_PeriodType ScaledDuty
)
{
  Pwm_17_Gtm_PeriodType ScaledCenterLead;

  /* Initialize local variable with Max Timer Minus  */
  ScaledCenterLead = PWM_MAX_TIMER;

  /* if Duty is less than period -1 */
  if ( ScaledDuty < (Period) )
  {
    /* Calculate the timer count for lead edge */
    ScaledCenterLead =
      (Pwm_17_Gtm_PeriodType)(( ( ((Period) - (ScaledDuty))
                  + ((Pwm_17_Gtm_PeriodType)1)
                 )
                  / ((Pwm_17_Gtm_PeriodType)PWM_CONST_2)
               )
                - ((Pwm_17_Gtm_PeriodType)1)
              );
  }
  return ScaledCenterLead;
}/* End of Pwm_lGetCenterLead() function */

#endif


/*******************************************************************************
** Syntax : void Pwm_lGtmStartChannelsInit(                                   **
**                            Pwm_GlobalChannelNumberType GlobalChannelNumber,**
**                            uint32 Period,                                  **
**                            uint32 Dutycycle,                               **
**                            uint32 Shift,                                   **
**                            Pwm_17_Gtm_PropertyType PwmProperty)            **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber - Channel number                     **
**                   Period - Period of the signal                            **
**                   Dutycycle - Dutycycle                                    **
**                   Shift - Shift desired                                    **
**                   PwmProperty - Property of the PWM signal                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This function starts the PWM channel as given by the     **
**                   Input parameters with the desired properties.            **
**                                                                            **
*******************************************************************************/
static void Pwm_lGtmStartChannelsInit
(
   Pwm_GlobalChannelNumberType GlobalChannelNumber,
   uint32 Period,
   uint32 Dutycycle,
   uint32 Shift,
   Pwm_17_Gtm_PropertyType PwmProperty
)
{

  Pwm_ChannelIdentifierType GlobalChannelId; /* Structure to get Module info  */

  /* Extract the Module specific information */
  GlobalChannelId = Pwm_lGtmChannelIdentifier(GlobalChannelNumber);

  /* Detect the Sub-Module type */
  if((GlobalChannelId.ModuleId) == GTM_TOM_MODULE)
  {
    Pwm_lGtmTomChannelsInit(GlobalChannelId,Period,Dutycycle,Shift,PwmProperty);
  }

  /* Detect the Sub-Module type */
  if((GlobalChannelId.ModuleId) == GTM_ATOM_MODULE)
  {
   Pwm_lGtmAtomChannelsInit(GlobalChannelId,Period,Dutycycle,Shift,PwmProperty);
  }
}

/*******************************************************************************
** Syntax : void Pwm_lGtmTomChannelsInit(                                     **
**                            Pwm_ChannelIdentifierType GlobalChannelId,      **
**                            uint32 Period,                                  **
**                            uint32 Dutycycle,                               **
**                            uint32 Shift,                                   **
**                            Pwm_17_Gtm_PropertyType PwmProperty)            **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelId - Channel Id                             **
**                   Period - Period of the signal                            **
**                   Dutycycle - Dutycycle                                    **
**                   Shift - Shift desired                                    **
**                   PwmProperty - Property of the PWM signal                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This function starts the PWM channel as given by the     **
**                   Input parameters with the desired properties.            **
**                                                                            **
*******************************************************************************/
static void Pwm_lGtmTomChannelsInit
(
   Pwm_ChannelIdentifierType GlobalChannelId,
   uint32 Period,
   uint32 Dutycycle,
   uint32 Shift,
   Pwm_17_Gtm_PropertyType PwmProperty
)
{
  Ifx_GTM_TOM_CH_TYPE* TomChannelRegPtr;   /* Ptr to TOM Channel Reg          */
  Ifx_GTM_TOM_CH_TYPE* RefTomChannelRegPtr;   /* Ptr to TOM Channel Reg       */
  Ifx_GTM_TOM_TGC_TYPE* TomTgcRegPtr;           /* Ptr to TOM TGC Reg         */
  Pwm_ChannelIdentifierType RefGlobChanId; /* Structure to get Module info    */
  uint32 RegVal;                             /* For Temp storage of Reg Value */
  uint8 ModuleNumber;                        /* Holds the module number       */
  uint8 ChannelNumber;                       /* Holds the channel number      */
  uint8 GroupNumber;                         /* Holds the group number        */
  uint8 RefModNumber;
  uint8 RefChannelNumber;
  uint32 TempPeriod;
  uint32 TempRegValue;
  /* Extract the Module specific information */
  ModuleNumber = GlobalChannelId.ModuleNo;
  ChannelNumber = GlobalChannelId.ChannelNo;
  GroupNumber = GlobalChannelId.GroupNo;

  TomTgcRegPtr = &((*(Ifx_GTM_TOMx*)(volatile void*)\
                    (MODULE_GTM.TOM)).TOM_TGC[ModuleNumber].TGC[GroupNumber]);

  /* Configure the Irq Mode, Irq Enable and Channel Ctrl register     */
  TomChannelRegPtr = &(((*(Ifx_GTM_TOMx*)(volatile void*) \
                    (MODULE_GTM.TOM)).TOM_CH[ModuleNumber].CH[ChannelNumber]));

  /*Clear interrupts for the channel and disable interrupts for the channel*/
  PWM_SFR_INIT_USER_MODE_WRITE32((TomChannelRegPtr->IRQ_NOTIFY.U), \
                                 PWM_CLR_PENDING_INTERRUPTS);
  PWM_SFR_INIT_USER_MODE_WRITE32((TomChannelRegPtr->IRQ_EN.U),PWM_BIT_RESET);
  /* Set the property of the PWM signal */
  TempRegValue = (((uint32)PwmProperty.IsReference << PWM_GTM_CTRL_TRIGOUT) |
                  ((uint32)PwmProperty.ResetShift << PWM_GTM_CTRL_RST_CCU0));

  PWM_SFR_INIT_USER_MODE_MODIFY32((TomChannelRegPtr->CTRL.U),\
                PWM_CTRL_SL_SET_CL_MASK,TempRegValue)
                
  /*Clear the FUPD register*/
  RegVal = PWM_SFR_INIT_USER_MODE_READ32((TomTgcRegPtr->FUPD_CTRL.U));
  TempRegValue = ((uint32)1U << (uint16)(PWM_CONST_2 * \
                      ((uint16)ChannelNumber % GTM_TOM_CHANNELS_PER_TGC)));
  TempRegValue = RegVal & TempRegValue;
  PWM_SFR_INIT_USER_MODE_WRITE32((TomTgcRegPtr->FUPD_CTRL.U),TempRegValue);
  /* Update Enable for the channel must be enabled if Coherant update is
       desired */
  if(PwmProperty.Coherency == PWM_COHERENT)
  {
    RegVal = ((uint32)PWM_CONST_2 << (uint16)(PWM_CONST_16 + (\
    PWM_CONST_2 * ((uint16)ChannelNumber % GTM_TOM_CHANNELS_PER_TGC))));
    PWM_SFR_INIT_USER_MODE_MODIFY32((TomTgcRegPtr->GLB_CTRL.U),\
        PWM_TGC_GLB_CLR_MASK,RegVal)
  }
  Pwm_lGtmSLBitConfigInit(GlobalChannelId,PwmProperty);
  if(PwmProperty.ChannelType != PWM_SHIFTED_CHANNEL)
  {
    /* Update CM0 with Period*/
    PWM_SFR_INIT_USER_MODE_WRITE32((TomChannelRegPtr->CM0.U),Period);
    /* Update CM1 with DCycle*/
    PWM_SFR_INIT_USER_MODE_WRITE32((TomChannelRegPtr->CM1.U),Dutycycle);
    /* Update CN0 with a value slightly behind CM0 value because if CN0 is
       configured with 0, then no signal will be present for 1 cycle, now,
       with this change, there will be no signal for 10 ticks */
    PWM_SFR_INIT_USER_MODE_WRITE32((TomChannelRegPtr->CN0.U),Period);
    PWM_SFR_INIT_USER_MODE_WRITE32((TomChannelRegPtr->SR0.U),Period);
    PWM_SFR_INIT_USER_MODE_WRITE32((TomChannelRegPtr->SR1.U),Dutycycle);
  }
  else
  {
    /* If shifted channel is desired */
    RefGlobChanId = Pwm_lGtmChannelIdentifier
                   ((Pwm_GlobalChannelNumberType)PwmProperty.RefChannelId);
    RefModNumber = RefGlobChanId.ModuleNo;
    RefChannelNumber = RefGlobChanId.ChannelNo;
    RefTomChannelRegPtr = &(((*(Ifx_GTM_TOMx*)(volatile void*) \
              (MODULE_GTM.TOM)).TOM_CH[RefModNumber].CH[RefChannelNumber]));

    if(PwmProperty.ShiftedSpl == PWM_SHIFTED_RELATED_CHANNEL)
    {
      if (Period == 0U)
      {
      /*If period = 0 or Shift greater than period set CN0 = 0*/
        PWM_SFR_INIT_USER_MODE_WRITE32((TomChannelRegPtr->CN0.U),PWM_ZERO_U);
      }
      else
      {
        TempRegValue = (Period - Shift);
        PWM_SFR_INIT_USER_MODE_WRITE32((TomChannelRegPtr->CN0.U),TempRegValue);
      }
      /* Update CM0 with Period*/
      PWM_SFR_INIT_USER_MODE_WRITE32((TomChannelRegPtr->CM0.U),Period);
      /* Update CM1 with DCycle*/
      PWM_SFR_INIT_USER_MODE_WRITE32((TomChannelRegPtr->CM1.U),Dutycycle);
      PWM_SFR_INIT_USER_MODE_WRITE32((TomChannelRegPtr->SR0.U),Period);
      PWM_SFR_INIT_USER_MODE_WRITE32((TomChannelRegPtr->SR1.U),Dutycycle);
    }
    else
    {
      TempRegValue = PWM_SFR_INIT_USER_MODE_READ32(RefTomChannelRegPtr->CN0.U);
      PWM_SFR_INIT_USER_MODE_WRITE32((TomChannelRegPtr->CN0.U),TempRegValue);
      if((Dutycycle == 0U))
      {
        PWM_SFR_INIT_USER_MODE_WRITE32((TomChannelRegPtr->CM0.U),PWM_SR0_VALUE);
        /*     Added to remove misra 10.1     */
        TempPeriod=Period+1U;
        PWM_SFR_INIT_USER_MODE_WRITE32((TomChannelRegPtr->CM1.U),TempPeriod);
        PWM_SFR_INIT_USER_MODE_WRITE32((TomChannelRegPtr->SR0.U),PWM_SR0_VALUE);
        PWM_SFR_INIT_USER_MODE_WRITE32((TomChannelRegPtr->SR1.U),TempPeriod);
      }
      else if(Dutycycle == Period)
      {
        /*     Added to remove misra 10.1     */
        TempPeriod=Period+1U;
        PWM_SFR_INIT_USER_MODE_WRITE32((TomChannelRegPtr->CM0.U),TempPeriod);
        PWM_SFR_INIT_USER_MODE_WRITE32((TomChannelRegPtr->CM1.U),PWM_SR1_VALUE);
        PWM_SFR_INIT_USER_MODE_WRITE32((TomChannelRegPtr->SR0.U),TempPeriod);
        PWM_SFR_INIT_USER_MODE_WRITE32((TomChannelRegPtr->SR1.U),PWM_SR1_VALUE);
      }
      else
      {
        /* Update CM1 with Shift + Dutycycle. To enable automatic wrap around in
           case if this value goes beyond Period length, this value is mod with
           Period value */
        PWM_SFR_INIT_USER_MODE_WRITE32((TomChannelRegPtr->CM0.U),\
        (Pwm_lGtmCounterVal(Shift, Period, Dutycycle)));
        PWM_SFR_INIT_USER_MODE_WRITE32((TomChannelRegPtr->CM1.U),Shift);
        PWM_SFR_INIT_USER_MODE_WRITE32((TomChannelRegPtr->SR0.U),\
        (Pwm_lGtmCounterVal(Shift, Period, Dutycycle)));
        PWM_SFR_INIT_USER_MODE_WRITE32((TomChannelRegPtr->SR1.U),Shift);
      }
    }
  }

  /*Check if the channel is related to channel those are to be enabled
  on Host tigger if not then enable the channel immediately*/
  if(PwmProperty.ShiftedSpl != PWM_SHIFTED_RELATED_CHANNEL)
  {
  /* Enable the channel and its output */
  PWM_SFR_INIT_USER_MODE_MODIFY32((TomTgcRegPtr->ENDIS_STAT.U),\
            PWM_ENDIS_CLR_MASK,((uint32)PWM_CONST_2 <<\
            (PWM_CONST_2*(ChannelNumber % GTM_TOM_CHANNELS_PER_TGC))))
  PWM_SFR_INIT_USER_MODE_MODIFY32((TomTgcRegPtr->OUTEN_STAT.U),\
            PWM_OUTEN_CLR_MASK,((uint32)PWM_CONST_2 <<\
            (PWM_CONST_2*(ChannelNumber % GTM_TOM_CHANNELS_PER_TGC))))
  }
  PWM_SFR_INIT_USER_MODE_MODIFY32((TomTgcRegPtr->ENDIS_CTRL.U),\
         PWM_ENDIS_CLR_MASK,((uint32)PWM_CONST_2 <<
         (PWM_CONST_2*(ChannelNumber % GTM_TOM_CHANNELS_PER_TGC))))
  PWM_SFR_INIT_USER_MODE_MODIFY32((TomTgcRegPtr->OUTEN_CTRL.U),\
         PWM_OUTEN_CLR_MASK,((uint32)PWM_CONST_2 <<
         (PWM_CONST_2*(ChannelNumber % GTM_TOM_CHANNELS_PER_TGC))))

}
/*******************************************************************************
** Syntax : void Pwm_lGtmAtomChannelsInit(                                    **
**                            Pwm_ChannelIdentifierType GlobalChannelId,      **
**                            uint32 Period,                                  **
**                            uint32 Dutycycle,                               **
**                            uint32 Shift,                                   **
**                            Pwm_17_Gtm_PropertyType PwmProperty)            **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelId - Channel Id                             **
**                   Period - Period of the signal                            **
**                   Dutycycle - Dutycycle                                    **
**                   Shift - Shift desired                                    **
**                   PwmProperty - Property of the PWM signal                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This function starts the PWM channel as given by the     **
**                   Input parameters with the desired properties.            **
**                                                                            **
*******************************************************************************/
static void Pwm_lGtmAtomChannelsInit
(
   Pwm_ChannelIdentifierType GlobalChannelId,
   uint32 Period,
   uint32 Dutycycle,
   uint32 Shift,
   Pwm_17_Gtm_PropertyType PwmProperty
)
{
  Ifx_GTM_ATOM_CH_TYPE* AtomChannelRegPtr; /* Ptr to ATOM Channel Reg       */
  Ifx_GTM_ATOM_CH_TYPE* RefAtomChannelRegPtr; /* Ptr to ATOM Channel Reg    */
  Ifx_GTM_ATOM* AtomRegPtr;           /* Ptr to ATOM AGC Reg           */
  Pwm_ChannelIdentifierType RefGlobChanId; /* Structure to get Module info  */
  uint32 RegVal;                             /* For Temp storage of Reg Value */
  uint8 ModuleNumber;                        /* Holds the module number       */
  uint8 ChannelNumber;                       /* Holds the channel number      */
  uint8 RefModNumber;
  uint8 RefChannelNumber;
  uint32 TempPeriod;
  uint32 TempRegValue;

  /* Extract the Module specific information */
  ModuleNumber = GlobalChannelId.ModuleNo;
  ChannelNumber = GlobalChannelId.ChannelNo;

  AtomRegPtr = &(MODULE_GTM.ATOM[ModuleNumber]);

  AtomChannelRegPtr = &((*(Ifx_GTM_ATOMx*)(volatile void*)  \
              (MODULE_GTM.ATOM)).ATOM_CH[ModuleNumber].CH[ChannelNumber]);
  /*Clear interrupts for the channel and disable interrupts for the channel*/
  PWM_SFR_INIT_USER_MODE_WRITE32((AtomChannelRegPtr->IRQ_NOTIFY.U), \
                                 PWM_CLR_PENDING_INTERRUPTS);
  PWM_SFR_INIT_USER_MODE_WRITE32((AtomChannelRegPtr->IRQ_EN.U),PWM_BIT_RESET);
  /* Set the property of the PWM signal */
  TempRegValue = (((uint32)PwmProperty.IsReference << PWM_GTM_CTRL_TRIGOUT) |
                  ((uint32)PwmProperty.ResetShift << PWM_GTM_CTRL_RST_CCU0));

  PWM_SFR_INIT_USER_MODE_MODIFY32((AtomChannelRegPtr->CTRL.U),\
                PWM_ATOM_CTRL_SL_SET_CL_MASK,TempRegValue)


  RegVal = PWM_SFR_INIT_USER_MODE_READ32((AtomRegPtr->AGC.FUPD_CTRL.U));
  TempRegValue = ((uint32)1U << (uint16)(PWM_CONST_2 * \
                      ((uint16)ChannelNumber % GTM_TOM_CHANNELS_PER_TGC)));
  TempRegValue = RegVal & TempRegValue;
  PWM_SFR_INIT_USER_MODE_WRITE32((AtomRegPtr->AGC.FUPD_CTRL.U),TempRegValue);
  /* Update Enable for the channel must be enabled if Coherant update is
     desired */
  if(PwmProperty.Coherency == PWM_COHERENT)
  {
    RegVal = ((uint32)PWM_CONST_2 << (uint16)(PWM_CONST_16 + (\
    PWM_CONST_2 * ((uint16)ChannelNumber % GTM_ATOM_CHANNELS_PER_AGC))));
    PWM_SFR_INIT_USER_MODE_MODIFY32((AtomRegPtr->AGC.GLB_CTRL.U),\
        PWM_TGC_GLB_CLR_MASK,RegVal)
  }
  Pwm_lGtmSLBitConfigInit(GlobalChannelId,PwmProperty);
  if(PwmProperty.ChannelType != PWM_SHIFTED_CHANNEL)
  {
    /* Update CM0 with Period*/
    PWM_SFR_INIT_USER_MODE_WRITE32((AtomChannelRegPtr->CM0.U),Period);
    /* Update CM1 with DCycle*/
    PWM_SFR_INIT_USER_MODE_WRITE32((AtomChannelRegPtr->CM1.U),Dutycycle);
    /* Update CN0 with a value slightly behind CM0 value because if CN0 is
       configured with 0, then no signal will be present for 1 cycle, now,
       with this change, there will be no signal for 10 ticks */
    PWM_SFR_INIT_USER_MODE_WRITE32((AtomChannelRegPtr->CN0.U),Period);
    PWM_SFR_INIT_USER_MODE_WRITE32((AtomChannelRegPtr->SR0.U),Period);
    PWM_SFR_INIT_USER_MODE_WRITE32((AtomChannelRegPtr->SR1.U),Dutycycle);
  }
  else
  {
    RefGlobChanId = Pwm_lGtmChannelIdentifier
                     ((Pwm_GlobalChannelNumberType)PwmProperty.RefChannelId);
    RefModNumber = RefGlobChanId.ModuleNo;
    RefChannelNumber = RefGlobChanId.ChannelNo;
    RefAtomChannelRegPtr =&((*(Ifx_GTM_ATOMx*)(volatile void*) \
          (MODULE_GTM.ATOM)).ATOM_CH[RefModNumber].CH[RefChannelNumber]);

    if(PwmProperty.ShiftedSpl == PWM_SHIFTED_RELATED_CHANNEL)
    {
      if (Period == 0U)
      {
        /*If period = 0 or Shift greater than period set CN0 = 0*/
        PWM_SFR_INIT_USER_MODE_WRITE32((AtomChannelRegPtr->CN0.U),PWM_ZERO_U);
      }
      else
      {
        TempRegValue = (Period - Shift);
        PWM_SFR_INIT_USER_MODE_WRITE32((AtomChannelRegPtr->CN0.U),TempRegValue);
      }
      /* Update CM0 with Period*/
      PWM_SFR_INIT_USER_MODE_WRITE32((AtomChannelRegPtr->CM0.U),Period);
      /* Update CM1 with DCycle*/
      PWM_SFR_INIT_USER_MODE_WRITE32((AtomChannelRegPtr->CM1.U),Dutycycle);
      PWM_SFR_INIT_USER_MODE_WRITE32((AtomChannelRegPtr->SR0.U),Period);
      PWM_SFR_INIT_USER_MODE_WRITE32((AtomChannelRegPtr->SR1.U),Dutycycle);
    }
    else
    {
      TempRegValue = PWM_SFR_INIT_USER_MODE_READ32(RefAtomChannelRegPtr->CN0.U);
      PWM_SFR_INIT_USER_MODE_WRITE32((AtomChannelRegPtr->CN0.U),TempRegValue);
      if((Dutycycle == 0U))
      {
        PWM_SFR_INIT_USER_MODE_WRITE32((AtomChannelRegPtr->CM0.U),\
               PWM_SR0_VALUE);
        /*     Added to remove misra 10.1     */
        TempPeriod=Period+1U;
        PWM_SFR_INIT_USER_MODE_WRITE32((AtomChannelRegPtr->CM1.U),TempPeriod);
        PWM_SFR_INIT_USER_MODE_WRITE32((AtomChannelRegPtr->SR0.U),\
               PWM_SR0_VALUE);
        PWM_SFR_INIT_USER_MODE_WRITE32((AtomChannelRegPtr->SR1.U),TempPeriod);
      }
      else if(Dutycycle == Period)
      {
        /*     Added to remove misra 10.1     */
        TempPeriod=Period+1U;
        PWM_SFR_INIT_USER_MODE_WRITE32((AtomChannelRegPtr->CM0.U),TempPeriod);
        PWM_SFR_INIT_USER_MODE_WRITE32((AtomChannelRegPtr->CM1.U),\
                PWM_SR1_VALUE);
        PWM_SFR_INIT_USER_MODE_WRITE32((AtomChannelRegPtr->SR0.U),TempPeriod);
        PWM_SFR_INIT_USER_MODE_WRITE32((AtomChannelRegPtr->SR1.U),\
                PWM_SR1_VALUE);
      }
      else
      {
        /* Update CM1 with Shift + Dutycycle. To enable automatic wrap around in
           case if this value goes beyond Period length, this value is mod with
           Period value */
        PWM_SFR_INIT_USER_MODE_WRITE32((AtomChannelRegPtr->CM0.U),\
        (Pwm_lGtmCounterVal(Shift, Period, Dutycycle)));
        PWM_SFR_INIT_USER_MODE_WRITE32((AtomChannelRegPtr->CM1.U),Shift);
        PWM_SFR_INIT_USER_MODE_WRITE32((AtomChannelRegPtr->SR0.U),\
        (Pwm_lGtmCounterVal(Shift, Period, Dutycycle)));
        PWM_SFR_INIT_USER_MODE_WRITE32((AtomChannelRegPtr->SR1.U),Shift);
      }
    }
  }
   /*Check if the channel is related to channel those are to be enabled
    on Host tigger if not then enable the channel immediately*/
  if(PwmProperty.ShiftedSpl != PWM_SHIFTED_RELATED_CHANNEL)
  {
  /* Enable the channel and its output */
  PWM_SFR_INIT_USER_MODE_MODIFY32((AtomRegPtr->AGC.ENDIS_STAT.U),\
            PWM_ENDIS_CLR_MASK,((uint32)PWM_CONST_2 <<\
            (PWM_CONST_2*(ChannelNumber % GTM_TOM_CHANNELS_PER_TGC))))
  PWM_SFR_INIT_USER_MODE_MODIFY32((AtomRegPtr->AGC.OUTEN_STAT.U),\
            PWM_OUTEN_CLR_MASK,((uint32)PWM_CONST_2 <<\
            (PWM_CONST_2*(ChannelNumber % GTM_TOM_CHANNELS_PER_TGC))))
  }
  PWM_SFR_INIT_USER_MODE_MODIFY32((AtomRegPtr->AGC.ENDIS_CTRL.U),\
         PWM_ENDIS_CLR_MASK,((uint32)PWM_CONST_2 <<
         (PWM_CONST_2*(ChannelNumber % GTM_TOM_CHANNELS_PER_TGC))))
  PWM_SFR_INIT_USER_MODE_MODIFY32((AtomRegPtr->AGC.OUTEN_CTRL.U),\
         PWM_OUTEN_CLR_MASK,((uint32)PWM_CONST_2 <<
         (PWM_CONST_2*(ChannelNumber % GTM_TOM_CHANNELS_PER_TGC))))
}
/*******************************************************************************
** Syntax : void Pwm_lGtmSLBitConfigInit(                                     **
**                            Pwm_ChannelIdentifierType GlobalChannelId,      **
**                            Pwm_17_Gtm_PropertyType PwmProperty)            **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelId - Channel Id                             **
**                   PwmProperty - Property of the PWM signal                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This function configure the SL bit of the control        **
**                   register based on the duty cycle and the Idle state.     **
**                                                                            **
*******************************************************************************/
static void Pwm_lGtmSLBitConfigInit
(
  Pwm_ChannelIdentifierType GlobalChannelId,
  Pwm_17_Gtm_PropertyType PwmProperty
)
{
  Ifx_GTM_TOM_CH_TYPE* TomChannelRegPtr;   /* Ptr to TOM Channel Reg   */
  Ifx_GTM_ATOM_CH_TYPE* AtomChannelRegPtr; /* Ptr to ATOM Channel Reg  */
  uint32 Polarity;
  uint8  ModuleNumber;                       /* Holds the module number  */
  uint8  ChannelNumber;                      /* Holds the channel number */

  /* Extract the Module specific information */
  ModuleNumber = GlobalChannelId.ModuleNo;
  ChannelNumber = GlobalChannelId.ChannelNo;

  Polarity = (uint32)PwmProperty.Polarity;
  if((PwmProperty.ChannelType == PWM_SHIFTED_CHANNEL) && \
             (PwmProperty.ShiftedSpl != PWM_SHIFTED_RELATED_CHANNEL))
  {
    Polarity = Polarity ^ 1UL;
  }
  /* Configure the Irq Mode, Irq Enable and Channel Ctrl register     */
  if((GlobalChannelId.ModuleId) == GTM_TOM_MODULE)
  {
    /* Configure the SL bit in the Channel Ctrl register     */
    TomChannelRegPtr =&(((*(Ifx_GTM_TOMx*)(volatile void*)\
                (MODULE_GTM.TOM)).TOM_CH[ModuleNumber].CH[ChannelNumber]));
    if(Polarity == 1UL)
    {
      PWM_SFR_INIT_USER_MODE_MODIFY32((TomChannelRegPtr->CTRL.U),
                  PWM_CTRL_SL_SET_CL_MASK,PWM_CTRL_SL_SET_ST_MASK)
    }
    else
    {
      PWM_SFR_INIT_USER_MODE_MODIFY32((TomChannelRegPtr->CTRL.U),
                  PWM_CTRL_SL_CLR_CL_MASK,PWM_ZERO_U)
    }
  }
  if((GlobalChannelId.ModuleId) == GTM_ATOM_MODULE)
  {
    AtomChannelRegPtr =  &((*(Ifx_GTM_ATOMx*)(volatile void*)\
           (MODULE_GTM.ATOM)).ATOM_CH[ModuleNumber].CH[ChannelNumber]);
    if(Polarity == 1UL)
    {
      PWM_SFR_INIT_USER_MODE_MODIFY32((AtomChannelRegPtr->CTRL.U),
                  PWM_ATOM_CTRL_SL_SET_CL_MASK,PWM_CTRL_SL_SET_ST_MASK)
    }
    else
    {
      PWM_SFR_INIT_USER_MODE_MODIFY32((AtomChannelRegPtr->CTRL.U),
                  PWM_ATOM_CTRL_SL_CLR_CL_MASK,PWM_ZERO_U)
    }
  }
}

#if(PWM_DE_INIT_API == STD_ON)
/*******************************************************************************
** Syntax : void Pwm_lGtmSLBitConfigDeInit(                                   **
**                            Pwm_ChannelIdentifierType GlobalChannelId,      **
**                            Pwm_17_Gtm_PropertyType PwmProperty)            **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelId - Channel Id                             **
**                   PwmProperty - Property of the PWM signal                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This function configure the SL bit of the control        **
**                   register based on the duty cycle and the Idle state.     **
**                                                                            **
*******************************************************************************/
static void Pwm_lGtmSLBitConfigDeInit
(
  Pwm_ChannelIdentifierType GlobalChannelId,
  Pwm_17_Gtm_PropertyType PwmProperty
)
{
  Ifx_GTM_TOM_CH_TYPE* TomChannelRegPtr;     /* Ptr to TOM Channel Reg   */
  Ifx_GTM_ATOM_CH_TYPE* AtomChannelRegPtr; /* Ptr to ATOM Channel Reg  */
  uint32 Polarity;
  uint8  ModuleNumber;                       /* Holds the module number  */
  uint8  ChannelNumber;                      /* Holds the channel number */

  /* Extract the Module specific information */
  ModuleNumber = GlobalChannelId.ModuleNo;
  ChannelNumber = GlobalChannelId.ChannelNo;

  Polarity = (uint32)PwmProperty.Polarity;
    /* Configure the Irq Mode, Irq Enable and Channel Ctrl register     */
  if((GlobalChannelId.ModuleId) == GTM_TOM_MODULE)
  {
    /* Configure the SL bit in the Channel Ctrl register     */
    TomChannelRegPtr =&(((*(Ifx_GTM_TOMx*)(volatile void*)\
                (MODULE_GTM.TOM)).TOM_CH[ModuleNumber].CH[ChannelNumber]));
    if(Polarity == 1UL)
    {
      PWM_SFR_DEINIT_USER_MODE_MODIFY32((TomChannelRegPtr->CTRL.U),
                  PWM_CTRL_SL_SET_CL_MASK,PWM_CTRL_SL_SET_ST_MASK)
    }
    else
    {
      PWM_SFR_DEINIT_USER_MODE_MODIFY32((TomChannelRegPtr->CTRL.U),
                  PWM_CTRL_SL_CLR_CL_MASK,PWM_ZERO_U)
    }
  }
  if((GlobalChannelId.ModuleId) == GTM_ATOM_MODULE)
  {
    AtomChannelRegPtr =  &((*(Ifx_GTM_ATOMx*)(volatile void*)\
           (MODULE_GTM.ATOM)).ATOM_CH[ModuleNumber].CH[ChannelNumber]);
    if(Polarity == 1UL)
    {
      PWM_SFR_DEINIT_USER_MODE_MODIFY32((AtomChannelRegPtr->CTRL.U),
                  PWM_ATOM_CTRL_SL_SET_CL_MASK,PWM_CTRL_SL_SET_ST_MASK)
    }
    else
    {
      PWM_SFR_DEINIT_USER_MODE_MODIFY32((AtomChannelRegPtr->CTRL.U),
                  PWM_ATOM_CTRL_SL_CLR_CL_MASK,PWM_ZERO_U)
    }
  }
}
#endif /* (PWM_DE_INIT_API == STD_ON) */

#if((PWM_SET_PERIOD_AND_DUTY_API == STD_ON) || \
    (PWM_SET_DUTY_CYCLE_API == STD_ON) ||(PWM_SET_OUTPUT_TO_IDLE_API == STD_ON))
/*******************************************************************************
** Syntax : void Pwm_lGtmStartChannel(                                        **
**                            Pwm_GlobalChannelNumberType GlobalChannelNumber,**
**                            uint32 Period,                                  **
**                            uint32 Dutycycle,                               **
**                            uint32 Shift,                                   **
**                            Pwm_17_Gtm_PropertyType PwmProperty)            **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber - Channel number                     **
**                   Period - Period of the signal                            **
**                   Dutycycle - Dutycycle                                    **
**                   Shift - Shift desired                                    **
**                   PwmProperty - Property of the PWM signal                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This function starts the PWM channel as given by the     **
**                   Input parameters with the desired properties.            **
**                                                                            **
*******************************************************************************/
static void Pwm_lGtmStartChannel
(
  Pwm_GlobalChannelNumberType GlobalChannelNumber,
  uint32 Period,
  uint32 Dutycycle,
  uint32 Shift,
  Pwm_17_Gtm_PropertyType PwmProperty
)
{
  Pwm_ChannelIdentifierType GlobalChannelId; /* Structure to get Module info  */

  /* Extract the Module specific information */
  GlobalChannelId = Pwm_lGtmChannelIdentifier(GlobalChannelNumber);

  /* Detect the Sub-Module type */
  if((GlobalChannelId.ModuleId) == GTM_TOM_MODULE)
  {
    Pwm_lGtmStartTomChannel(GlobalChannelId,Period,Dutycycle,Shift,PwmProperty);
  }
  /* Detect the Sub-Module type */
  if((GlobalChannelId.ModuleId) == GTM_ATOM_MODULE)
  {
   Pwm_lGtmStartAtomChannel(GlobalChannelId,Period,Dutycycle,Shift,PwmProperty);
  }
}

/*******************************************************************************
** Syntax : void Pwm_lGtmStartTomChannel(                                     **
**                            Pwm_ChannelIdentifierType GlobalChannelId,      **
**                            uint32 Period,                                  **
**                            uint32 Dutycycle,                               **
**                            uint32 Shift,                                   **
**                            Pwm_17_Gtm_PropertyType PwmProperty)            **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelId - Channel Id                             **
**                   Period - Period of the signal                            **
**                   Dutycycle - Dutycycle                                    **
**                   Shift - Shift desired                                    **
**                   PwmProperty - Property of the PWM signal                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This function starts the PWM channel as given by the     **
**                   Input parameters with the desired properties.            **
**                                                                            **
*******************************************************************************/
static void Pwm_lGtmStartTomChannel
(
  Pwm_ChannelIdentifierType GlobalChannelId,
  uint32 Period,
  uint32 Dutycycle,
  uint32 Shift,
  Pwm_17_Gtm_PropertyType PwmProperty
)
{
  Ifx_GTM_TOM_CH_TYPE* TomChannelRegPtr;     /* Ptr to TOM Channel Reg        */
  uint8 ModuleNumber;                        /* Holds the module number       */
  uint8 ChannelNumber;                       /* Holds the channel number      */
  uint32 TempPeriod;

  /* Extract the Module specific information */
  ModuleNumber = GlobalChannelId.ModuleNo;
  ChannelNumber = GlobalChannelId.ChannelNo;

  /* Configure the Irq Mode, Irq Enable and Channel Ctrl register     */

  TomChannelRegPtr = &(((*(Ifx_GTM_TOMx*)(volatile void*)\
                    (MODULE_GTM.TOM)).TOM_CH[ModuleNumber].CH[ChannelNumber]));

  if((PwmProperty.ChannelType != PWM_SHIFTED_CHANNEL) || \
            (PwmProperty.ShiftedSpl == PWM_SHIFTED_RELATED_CHANNEL))
  {
    PWM_SFR_RUNTIME_USER_MODE_MODIFY32((TomChannelRegPtr->CTRL.U),\
       PWM_CTRL_RST_CLR_CL_MASK,PWM_ZERO_U)
    if(PwmProperty.Coherency == PWM_NON_COHERENT)
    {
      PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->CM0.U),Period);
      PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->CM1.U),Dutycycle);
      PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->SR0.U),Period);
      PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->SR1.U),Dutycycle);
    }
    else
    {
      /* Update SR0 with Period*/
      PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->SR0.U),Period);
      /* Update SR1 with DCycle*/
      PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->SR1.U),Dutycycle); 
    }
  }
  else
  { /* If shifted channel is desired */
    PWM_SFR_RUNTIME_USER_MODE_MODIFY32((TomChannelRegPtr->CTRL.U),\
       PWM_CTRL_SL_SET_CL_MASK,((uint32)(1UL << PWM_GTM_CTRL_RST_CCU0)))
    if(PwmProperty.Coherency == PWM_NON_COHERENT)
    {
      if(Dutycycle == 0U)
      {
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->CM0.U),\
          PWM_SR0_VALUE);
        /*     Added to remove misra 10.1     */
        TempPeriod=Period+1U;
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->CM1.U),TempPeriod);
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->SR0.U),\
          PWM_SR0_VALUE);
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->SR1.U),TempPeriod);
      }
      else if(Dutycycle == Period)
      {
        /*     Added to remove misra 10.1     */
        TempPeriod=Period+1U;
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->CM0.U),TempPeriod);
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->CM1.U),\
          PWM_SR1_VALUE);
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->SR0.U),TempPeriod);
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->SR1.U),\
          PWM_SR1_VALUE);
      }
      else
      {
        /* Update CM1 with Shift + Dutycycle. To enable automatic wrap around in
         case if this value goes beyond Period length, this value is mod with
         Period value */
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->CM0.U),\
          (Pwm_lGtmCounterVal(Shift, Period, Dutycycle)));
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->CM1.U),Shift);
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->SR0.U),\
          (Pwm_lGtmCounterVal(Shift, Period, Dutycycle)));
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->SR1.U),Shift);
      }
    }
    else
    {
      if (Dutycycle == 0U)
      {
        /*     Added to remove misra 10.1     */
        TempPeriod=Period+1U;
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->SR1.U),TempPeriod);
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->SR0.U),\
           PWM_SR0_VALUE);
      }
      else if (Dutycycle == Period)
      {
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->SR1.U),0U);
        /*     Added to remove misra 10.1     */
        TempPeriod=Period+1U;
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->SR0.U),TempPeriod);
      }
      else
      {
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->SR0.U),\
          (Pwm_lGtmCounterVal(Shift, Period, Dutycycle)));
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->SR1.U),Shift);
      }
    }
  }
}
/*******************************************************************************
** Syntax : void Pwm_lGtmStartAtomChannel(                                    **
**                            Pwm_ChannelIdentifierType GlobalChannelId,      **
**                            uint32 Period,                                  **
**                            uint32 Dutycycle,                               **
**                            uint32 Shift,                                   **
**                            Pwm_17_Gtm_PropertyType PwmProperty)            **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelId - Channel Id                             **
**                   Period - Period of the signal                            **
**                   Dutycycle - Dutycycle                                    **
**                   Shift - Shift desired                                    **
**                   PwmProperty - Property of the PWM signal                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This function starts the PWM channel as given by the     **
**                   Input parameters with the desired properties.            **
**                                                                            **
*******************************************************************************/
static void Pwm_lGtmStartAtomChannel
(
  Pwm_ChannelIdentifierType GlobalChannelId,
  uint32 Period,
  uint32 Dutycycle,
  uint32 Shift,
  Pwm_17_Gtm_PropertyType PwmProperty
)
{
  Ifx_GTM_ATOM_CH_TYPE* AtomChannelRegPtr;   /* Ptr to ATOM Channel Reg      */
  uint8 ModuleNumber;                        /* Holds the module number      */
  uint8 ChannelNumber;                       /* Holds the channel number     */
  uint32 TempPeriod;

  /* Extract the Module specific information */
  ModuleNumber = GlobalChannelId.ModuleNo;
  ChannelNumber = GlobalChannelId.ChannelNo;

  /* Configure the Irq Mode, Irq Enable and Channel Ctrl register     */
  
  AtomChannelRegPtr =&((*(Ifx_GTM_ATOMx*)(volatile void*)\
              (MODULE_GTM.ATOM)).ATOM_CH[ModuleNumber].CH[ChannelNumber]);

  if((PwmProperty.ChannelType != PWM_SHIFTED_CHANNEL) || \
            (PwmProperty.ShiftedSpl == PWM_SHIFTED_RELATED_CHANNEL))
  {
    PWM_SFR_RUNTIME_USER_MODE_MODIFY32((AtomChannelRegPtr->CTRL.U),\
       PWM_ATOM_CTRL_RST_CLR_MASK,PWM_ZERO_U)
    if(PwmProperty.Coherency == PWM_NON_COHERENT)
    {
      PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->CM0.U),Period);
      PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->CM1.U),Dutycycle);
      PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->SR0.U),Period);
      PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->SR1.U),Dutycycle);
    }
    else
    {
      /* Update SR0 with Period*/
      PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->SR0.U),Period);
      /* Update SR1 with DCycle*/
      PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->SR1.U),Dutycycle); 
    }
  }
  else
  { /* If shifted channel is desired */
    PWM_SFR_RUNTIME_USER_MODE_MODIFY32((AtomChannelRegPtr->CTRL.U),\
       PWM_ATOM_CTRL_SL_SET_CL_MASK,((uint32)(1UL << PWM_GTM_CTRL_RST_CCU0)))
    if(PwmProperty.Coherency == PWM_NON_COHERENT)
    {
      if(Dutycycle == 0U)
      {
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->CM0.U),\
          PWM_SR0_VALUE);
        /*     Added to remove misra 10.1     */
        TempPeriod=Period+1U;
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->CM1.U),\
          TempPeriod);
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->SR0.U),\
          PWM_SR0_VALUE);
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->SR1.U),\
          TempPeriod);
      }
      else if(Dutycycle == Period)
      {
        /*     Added to remove misra 10.1     */
        TempPeriod=Period+1U;
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->CM0.U),\
          TempPeriod);
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->CM1.U),\
          PWM_SR1_VALUE);
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->SR0.U),\
          TempPeriod);
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->SR1.U),\
          PWM_SR1_VALUE);
      }
      else
      {
        /* Update CM1 with Shift + Dutycycle. To enable automatic wrap around in
         case if this value goes beyond Period length, this value is mod with
         Period value */
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->CM0.U),\
          (Pwm_lGtmCounterVal(Shift, Period, Dutycycle)));
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->CM1.U),Shift);
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->SR0.U),\
          (Pwm_lGtmCounterVal(Shift, Period, Dutycycle)));
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->SR1.U),Shift);
      }
    }
    else
    {
      if (Dutycycle == 0U)
      {
        /*     Added to remove misra 10.1     */
        TempPeriod=Period+1U;
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->SR1.U),\
          TempPeriod);
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->SR0.U),\
           PWM_SR0_VALUE);
      }
      else if (Dutycycle == Period)
      {
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->SR1.U),0U);
        /*     Added to remove misra 10.1     */
        TempPeriod = Period+1U;
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->SR0.U),\
          TempPeriod);
      }
      else
      {
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->SR0.U),\
          (Pwm_lGtmCounterVal(Shift, Period, Dutycycle)));
        PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->SR1.U),Shift);
      }
    }
  }
}
#endif /* (PWM_SET_PERIOD_AND_DUTY_API == STD_ON) */

#if(PWM_DE_INIT_API == STD_ON)
/*******************************************************************************
** Syntax : void Pwm_lGtmIdleChannelDeInit(                                   **
**                            Pwm_GlobalChannelNumberType GlobalChannelNumber,**
**                            uint32 Period,                                  **
**                            uint32 Dutycycle)                               **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber - Channel number                     **
**                   Period - Period of the signal                            **
**                   Dutycycle - Dutycycle                                    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This function sets the PWM channel to Idle state         **
**                                                                            **
*******************************************************************************/
static void Pwm_lGtmIdleChannelDeInit
(
  Pwm_GlobalChannelNumberType GlobalChannelNumber,
  uint32 Period,
  uint32 Dutycycle
)
{
  Pwm_ChannelIdentifierType GlobalChannelId; /* Structure to get Module info  */

  /* Extract the Module specific information */
  GlobalChannelId = Pwm_lGtmChannelIdentifier(GlobalChannelNumber);

  /* Detect the Sub-Module type */
  if((GlobalChannelId.ModuleId) == GTM_TOM_MODULE)
  {
    Pwm_lGtmIdleTomChannelDeInit(GlobalChannelId,Period,Dutycycle);
  }
  /* Detect the Sub-Module type */
  if((GlobalChannelId.ModuleId) == GTM_ATOM_MODULE)
  {
    Pwm_lGtmIdleAtomChannelDeInit(GlobalChannelId,Period,Dutycycle);
  }
}


/*******************************************************************************
** Syntax : void Pwm_lGtmIdleTomChannelDeInit(                               **
**                            Pwm_ChannelIdentifierType GlobalChannelId,      **
**                            uint32 Period,                                  **
**                            uint32 Dutycycle)                               **

**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelId - Channel Id                             **
**                   Period - Period of the signal                            **
**                   Dutycycle - Dutycycle                                    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This function set the PWM TOM channel to Idle state.     **
**                                                                            **
*******************************************************************************/
static void Pwm_lGtmIdleTomChannelDeInit
(
  Pwm_ChannelIdentifierType GlobalChannelId,
  uint32 Period,
  uint32 Dutycycle
)
{
  Ifx_GTM_TOM_CH_TYPE* TomChannelRegPtr;     /* Ptr to TOM Channel Reg        */
  uint8 ModuleNumber;                        /* Holds the module number       */
  uint8 ChannelNumber;                       /* Holds the channel number      */

  /* Extract the Module specific information */
  ModuleNumber = GlobalChannelId.ModuleNo;
  ChannelNumber = GlobalChannelId.ChannelNo;

  /* Configure the Irq Mode, Irq Enable and Channel Ctrl register     */

  TomChannelRegPtr = &(((*(Ifx_GTM_TOMx*)(volatile void*)\
                    (MODULE_GTM.TOM)).TOM_CH[ModuleNumber].CH[ChannelNumber]));

  PWM_SFR_DEINIT_USER_MODE_MODIFY32((TomChannelRegPtr->CTRL.U),\
       PWM_CTRL_RST_CLR_CL_MASK,PWM_ZERO_U)
  PWM_SFR_DEINIT_USER_MODE_WRITE32((TomChannelRegPtr->CM0.U),Period);
  PWM_SFR_DEINIT_USER_MODE_WRITE32((TomChannelRegPtr->CM1.U),Dutycycle);
  PWM_SFR_DEINIT_USER_MODE_WRITE32((TomChannelRegPtr->SR0.U),Period);
  PWM_SFR_DEINIT_USER_MODE_WRITE32((TomChannelRegPtr->SR1.U),Dutycycle);
}

/*******************************************************************************
** Syntax : void Pwm_lGtmIdleAtomChannelDeInit(                               **
**                            Pwm_ChannelIdentifierType GlobalChannelId,      **
**                            uint32 Period,                                  **
**                            uint32 Dutycycle)                               **

**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelId - Channel Id                             **
**                   Period - Period of the signal                            **
**                   Dutycycle - Dutycycle                                    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This function set the PWM ATOM channel to Idle state.    **
**                                                                            **
*******************************************************************************/
static void Pwm_lGtmIdleAtomChannelDeInit
(
  Pwm_ChannelIdentifierType GlobalChannelId,
  uint32 Period,
  uint32 Dutycycle
)
{
  Ifx_GTM_ATOM_CH_TYPE* AtomChannelRegPtr;   /* Ptr to TOM Channel Reg       */
  uint8 ModuleNumber;                        /* Holds the module number      */
  uint8 ChannelNumber;                       /* Holds the channel number     */

  /* Extract the Module specific information */
  ModuleNumber = GlobalChannelId.ModuleNo;
  ChannelNumber = GlobalChannelId.ChannelNo;

  /* Configure the Irq Mode, Irq Enable and Channel Ctrl register     */

  AtomChannelRegPtr = &((*(Ifx_GTM_ATOMx*)(volatile void*)\
              (MODULE_GTM.ATOM)).ATOM_CH[ModuleNumber].CH[ChannelNumber]);

  PWM_SFR_DEINIT_USER_MODE_MODIFY32((AtomChannelRegPtr->CTRL.U),\
       PWM_ATOM_CTRL_RST_CLR_MASK,PWM_ZERO_U)
  PWM_SFR_DEINIT_USER_MODE_WRITE32((AtomChannelRegPtr->CM0.U),Period);
  PWM_SFR_DEINIT_USER_MODE_WRITE32((AtomChannelRegPtr->CM1.U),Dutycycle);
  PWM_SFR_DEINIT_USER_MODE_WRITE32((AtomChannelRegPtr->SR0.U),Period);
  PWM_SFR_DEINIT_USER_MODE_WRITE32((AtomChannelRegPtr->SR1.U),Dutycycle);
}

#endif /* (PWM_DE_INIT_API == STD_ON) */

#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
/*******************************************************************************
** Syntax : boolean Pwm_lGtmGetOutputState(                                   **
**                            Pwm_GlobalChannelNumberType GlobalChannelNumber **
**                                       )                                    **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber - Channel number                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This function returns the output state of the channel    **
**                                                                            **
*******************************************************************************/
static boolean Pwm_lGtmGetOutputState
(
  Pwm_GlobalChannelNumberType GlobalChannelNumber
)
{
  Pwm_ChannelIdentifierType GlobalChannelId; /* Structure to get Module info */
  Ifx_GTM_TOM_CH_TYPE* TomChannelRegPtr;   /* Ptr to TOM Channel Reg         */
  Ifx_GTM_ATOM_CH_TYPE* AtomChannelRegPtr; /* Ptr to ATOM Channel Reg        */
  boolean RetVal;                            /* Stores the output state      */
  uint8 ModuleNumber;                        /* Holds the module number      */
  uint8 ChannelNumber;                       /* Holds the channel number     */

  /* Extract the Module specific information */
  GlobalChannelId = Pwm_lGtmChannelIdentifier(GlobalChannelNumber);
  ModuleNumber = GlobalChannelId.ModuleNo;
  ChannelNumber = GlobalChannelId.ChannelNo;

  RetVal = 0U;

  /* Detect the Sub-Module type */
  if((GlobalChannelId.ModuleId) == GTM_TOM_MODULE)
  {
    TomChannelRegPtr = &(((*(Ifx_GTM_TOMx*)(volatile void*)\
                    (MODULE_GTM.TOM)).TOM_CH[ModuleNumber].CH[ChannelNumber]));

    /* Returns the OUT bit of the channel Status register */
    RetVal = (boolean)(((
    PWM_SFR_RUNTIME_USER_MODE_READ32(TomChannelRegPtr->STAT.U)& 1UL) > \
               0UL)?TRUE:FALSE);
  }
  /* Detect the Sub-Module type */
  if((GlobalChannelId.ModuleId) == GTM_ATOM_MODULE)
  {
    AtomChannelRegPtr =  &((*(Ifx_GTM_ATOMx*)(volatile void*)\
              (MODULE_GTM.ATOM)).ATOM_CH[ModuleNumber].CH[ChannelNumber]);

    /* Returns the OUT bit of the channel Status register */
    RetVal = (boolean)(((
    PWM_SFR_RUNTIME_USER_MODE_READ32(AtomChannelRegPtr->STAT.U)& 1UL) > \
               0UL)?TRUE:FALSE);
  }
  return (RetVal);
}
#endif /* (PWM_GET_OUTPUT_STATE_API == STD_ON) */

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/*******************************************************************************
** Syntax :void Pwm_lGtmIrqModify   (                                         **
**                           Pwm_GlobalChannelNumberType GlobalChannelNumber  **
**                           uint8 InterruptFlag                              **
**                                    )                                       **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber- Channel Number                      **
**                   InterruptFlag - Interrupt bits to set/reset              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to Enable/Disable CCU0/CCU1 Interrupt           **
**                                                                            **
*******************************************************************************/
static void Pwm_lGtmIrqModify(Pwm_GlobalChannelNumberType GlobalChannelNumber,
                         uint8 InterruptFlag)
{
  Pwm_ChannelIdentifierType GlobalChannelId; /* Structure to get Module info  */
  Ifx_GTM_TOM_CH_TYPE *TomChannelRegPtr;   /* Ptr to TOM Channel Register   */
  Ifx_GTM_ATOM_CH_TYPE *AtomChannelRegPtr; /* Ptr to ATOM Channel Register  */
  uint8 ModuleNumber;                        /* Holds the module number       */
  uint8 ChannelNumber;                       /* Holds the channel number      */

  GlobalChannelId = Pwm_lGtmChannelIdentifier(GlobalChannelNumber);
  ModuleNumber = GlobalChannelId.ModuleNo;
  ChannelNumber = GlobalChannelId.ChannelNo;

  if((GlobalChannelId.ModuleId) == GTM_TOM_MODULE)
  {
    /* Configure the Irq Mode, Irq Enable and Channel Ctrl register     */
    TomChannelRegPtr =   &(((*(Ifx_GTM_TOMx*) (volatile void*)\
        (MODULE_GTM.TOM)).TOM_CH[ModuleNumber].CH[ChannelNumber]));
    /* Clear all Pending Interrupts */
    PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->IRQ_NOTIFY.U),\
        PWM_CLR_PENDING_INTERRUPTS);
    PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->IRQ_EN.U),\
        InterruptFlag);
  }

  if((GlobalChannelId.ModuleId) == GTM_ATOM_MODULE)
  {
    AtomChannelRegPtr =   &((*(Ifx_GTM_ATOMx*)(volatile void*)\
        (MODULE_GTM.ATOM)).ATOM_CH[ModuleNumber].CH[ChannelNumber]);
    /* Clear all Pending Interrupts */
    PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->IRQ_NOTIFY.U),\
        PWM_CLR_PENDING_INTERRUPTS);
    PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->IRQ_EN.U),\
        InterruptFlag);
  }
}
#endif /* (PWM_NOTIFICATION_SUPPORTED == STD_ON) */
#if (PWM_DE_INIT_API == STD_ON)
/*******************************************************************************
** Syntax :void Pwm_lGtmIrqModifyDeInit(                                      **
**                           Pwm_GlobalChannelNumberType GlobalChannelNumber  **
**                           uint8 InterruptFlag                              **
**                                    )                                       **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  GlobalChannelNumber- Channel Number                      **
**                   InterruptFlag - Interrupt bits to set/reset              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to Enable/Disable CCU0/CCU1 Interrupt           **
**                                                                            **
*******************************************************************************/
static void Pwm_lGtmIrqModifyDeInit(\
                         Pwm_GlobalChannelNumberType GlobalChannelNumber,\
                         uint8 InterruptFlag)
{
  Pwm_ChannelIdentifierType GlobalChannelId; /* Structure to get Module info  */
  Ifx_GTM_TOM_CH_TYPE *TomChannelRegPtr;   /* Ptr to TOM Channel Register   */
  Ifx_GTM_ATOM_CH_TYPE *AtomChannelRegPtr; /* Ptr to ATOM Channel Register  */
  uint8 ModuleNumber;                        /* Holds the module number       */
  uint8 ChannelNumber;                       /* Holds the channel number      */

  GlobalChannelId = Pwm_lGtmChannelIdentifier(GlobalChannelNumber);
  ModuleNumber = GlobalChannelId.ModuleNo;
  ChannelNumber = GlobalChannelId.ChannelNo;

  if((GlobalChannelId.ModuleId) == GTM_TOM_MODULE)
  {
    /* Configure the Irq Mode, Irq Enable and Channel Ctrl register     */
    TomChannelRegPtr =   &(((*(Ifx_GTM_TOMx*) (volatile void*)\
         (MODULE_GTM.TOM)).TOM_CH[ModuleNumber].CH[ChannelNumber]));
    /* Clear all Pending Interrupts */
    PWM_SFR_DEINIT_USER_MODE_WRITE32((TomChannelRegPtr->IRQ_NOTIFY.U),\
              PWM_CLR_PENDING_INTERRUPTS);
   PWM_SFR_DEINIT_USER_MODE_WRITE32((TomChannelRegPtr->IRQ_EN.U),InterruptFlag);
  }

  if((GlobalChannelId.ModuleId) == GTM_ATOM_MODULE)
  {
    AtomChannelRegPtr =   &((*(Ifx_GTM_ATOMx*)(volatile void*)\
        (MODULE_GTM.ATOM)).ATOM_CH[ModuleNumber].CH[ChannelNumber]);
    /* Clear all Pending Interrupts */
    PWM_SFR_DEINIT_USER_MODE_WRITE32((AtomChannelRegPtr->IRQ_NOTIFY.U),\
        PWM_CLR_PENDING_INTERRUPTS);
    PWM_SFR_DEINIT_USER_MODE_WRITE32((AtomChannelRegPtr->IRQ_EN.U),\
        InterruptFlag);
  }
}
#endif /* (PWM_DE_INIT_API == STD_ON) */
/******************************************************************************
** Syntax :    IFX_LOCAL_INLINE Pwm_17_Gtm_ChannelClassType Pwm_lChanClass   **
**                                                         (uint32 Value)    **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Value : PwmChannelInfo                                 **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      Pwm_17_Gtm_ChannelClassType                            **
**                                                                           **
** Description :      Local function to obtain the channel class             **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE Pwm_17_Gtm_ChannelClassType Pwm_lChanClass(uint32 Value)
{
  Pwm_17_Gtm_ChannelClassType RetVal;

  RetVal = (Pwm_17_Gtm_ChannelClassType) \
        (((uint32)(Value) >> PWM_CHANNEL_MODE_POS) & (PWM_CHANNEL_MODE_MAX));
  return(RetVal);
}

#if((PWM_DE_INIT_API == STD_ON) ||(PWM_SET_OUTPUT_TO_IDLE_API == STD_ON))
/******************************************************************************
** Syntax :           IFX_LOCAL_INLINE Pwm_17_Gtm_OutputStateType Pwm_lIdle  **
**                                                          (uint32 Value)   **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Value : PwmChannelInfo                                 **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      Pwm_17_Gtm_OutputStateType                             **
**                                                                           **
** Description :      Local function to obtain the Idle state from           **
**                                                           PwmChannelInfo  **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE Pwm_17_Gtm_OutputStateType Pwm_lIdle(uint32 Value)
{
 Pwm_17_Gtm_OutputStateType RetVal;

 RetVal = (Pwm_17_Gtm_OutputStateType)(((uint32)(Value) >> PWM_IDLESTATE_POS) &
                                (PWM_IDLESTATE_MAX)
           );
 return(RetVal);
}
#endif
/******************************************************************************
** Syntax :           IFX_LOCAL_INLINE uint8 Pwm_lPolarity(uint32  Value)    **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Value : PwmChannelInfo                                 **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      uint8                                                  **
**                                                                           **
** Description :      Local function to obtain the Polarity from             **
**                                                           PwmChannelInfo  **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE uint8 Pwm_lPolarity(uint32  Value)
{
 uint8 RetVal;
 RetVal = (Pwm_17_Gtm_OutputStateType)(((uint32)(Value) >> PWM_POLSTATE_POS) &
                                  (PWM_POLSTATE_MAX)
                                );
 return(RetVal);
}

/******************************************************************************
** Syntax :           IFX_LOCAL_INLINE uint8 Pwm_lShiftSpl(uint32  Value)    **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Value : PwmChannelInfo                                 **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      uint8                                                  **
**                                                                           **
** Description :      Local function to obtain the ShiftSpl from             **
**                                                           PwmChannelInfo  **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE uint8 Pwm_lShiftSpl(uint32  Value)
{
 uint8 RetVal;
 RetVal = (uint8)(((uint32)(Value) >> PWM_SPLSHFT_POS)&(PWM_SPLSHFTSTATE_MAX));
 return(RetVal);
}

/******************************************************************************
** Syntax :           IFX_LOCAL_INLINE uint8 Pwm_lResetShift(uint32 Value)   **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Value : PwmChannelInfo                                 **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      uint8                                                  **
**                                                                           **
** Description :      Local function to obtain the ResertShift from          **
**                                                           PwmChannelInfo  **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE uint8 Pwm_lResetShift(uint32 Value)
{
 uint8 RetVal;
 RetVal = (uint8)(((uint32)(Value) >> PWM_RSTSHFT_POS)&(PWM_RSTSHFTSTATE_MAX));
 return(RetVal);
}


/******************************************************************************
** Syntax :  IFX_LOCAL_INLINE Pwm_17_Gtm_OutputStateType Pwm_lCoherency(     **
**                                                          uint32 Value)    **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Value : PwmChannelInfo                                 **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      Pwm_17_Gtm_OutputStateType                             **
**                                                                           **
** Description :      Local function to obtain the Coherency from            **
**                                                           PwmChannelInfo  **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE Pwm_17_Gtm_OutputStateType Pwm_lCoherency (uint32 Value)
{
  Pwm_17_Gtm_OutputStateType RetVal;

  RetVal = (Pwm_17_Gtm_OutputStateType) \
             ( ((uint32)(Value) >> PWM_COHERENCY_POS) & (PWM_COHERENCY_MAX) );
  return(RetVal);
}

#if ( (PWM_FIXED_PERIOD_USED == STD_ON) || (PWM_SET_DUTY_CYCLE_API == STD_ON) )
/******************************************************************************
** Syntax :    IFX_LOCAL_INLINE Pwm_17_Gtm_OutputStateType Pwm_lIsReference  **
**                                                          (uint32 Value)   **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Value : PwmChannelInfo                                 **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      Pwm_17_Gtm_OutputStateType                             **
**                                                                           **
** Description :      Local function to obtain whether channel is being      **
**                                              refered from PwmChannelInfo  **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE Pwm_17_Gtm_OutputStateType Pwm_lIsReference(uint32 Value)
{
  Pwm_17_Gtm_OutputStateType RetVal;

  RetVal = (Pwm_17_Gtm_OutputStateType) \
            (((uint32)(Value) >> PWM_ISREFERENCE_POS) & (PWM_ISREFERENCE_MAX));
  return(RetVal);
}
#endif /* (PWM_FIXED_PERIOD_USED == STD_ON) */
/******************************************************************************
** Syntax :           IFX_LOCAL_INLINE uint8 Pwm_lAssignedHW(uint32 Value)   **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Value : PwmChannelInfo                                 **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      uint8                                                  **
**                                                                           **
** Description :      Local function to obtain the Assigned HW Unit from     **
**                                                           PwmChannelInfo  **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE uint8 Pwm_lAssignedHW(uint32 Value)
{
  uint8 RetVal;

  RetVal = ((uint8)((Value) & (uint32)PWM_HWUNIT_POS));
  return(RetVal);
}

#if ((PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON) || \
                              (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON))
/******************************************************************************
** Syntax :    IFX_LOCAL_INLINE Pwm_17_Gtm_ChannelType Pwm_lReferChan        **
**                                                          (uint32 Value)   **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Value : PwmChannelInfo                                 **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      Pwm_17_Gtm_ChannelType                                 **
**                                                                           **
** Description :      Local function to obtain Reference channel Number from **
**                                                           PwmChannelInfo  **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE Pwm_17_Gtm_ChannelType Pwm_lReferChan(uint32 Value)
{
  Pwm_17_Gtm_ChannelType RetVal;

  RetVal = (((uint32)(Value) >> PWM_REFERENCE_CHAN_POS) & (PWM_7BIT_MASK));
  return(RetVal);
}
#endif

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/******************************************************************************
** Syntax :       IFX_LOCAL_INLINE void Pwm_lSetNotificationStatus           **
**                                         (Pwm_17_Gtm_ChannelType Channel)  **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Channel : Channel Number                               **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Function to Set the Notification status in the global  **
**                                                      channel variable     **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE void Pwm_lSetNotificationStatus \
                                              (Pwm_17_Gtm_ChannelType Channel)
{
  Pwm_17_Gtm_ChannelType ChIndex ;
  #if (PWM_SAFETY_ENABLE == STD_ON)
  uint8 ChSignal ;
  #endif
  ChIndex = Pwm_lFindChannelIndex( Channel);
  #if (PWM_SAFETY_ENABLE == STD_ON)
  ChSignal = Pwm_lFindChannelSignal(Channel);
  if (ChSignal == PWM_ASIL_TYPE)
  {
  #if (PWM_MAX_ASIL_CHANNELS != 0)
  Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Asil[(ChIndex)]),
                (PWM_BIT_SET),
                (sint32)(PWM_NOTIFI_STATUS_POS),
                (PWM_CHAN_ID_STAT_BITS)
                );
  #endif
  }
  else
  #endif
  {
    #if (PWM_MAX_QM_CHANNELS != 0)
    Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Qm[(ChIndex)]),
                    (PWM_BIT_SET),
                    (sint32)(PWM_NOTIFI_STATUS_POS),
                    (PWM_CHAN_ID_STAT_BITS)
                  );
    #endif
    /*If QM channels are equal to zero do nothing */
  }
}

/******************************************************************************
** Syntax :     IFX_LOCAL_INLINE void Pwm_lClearNotificationStatus           **
**                                         (Pwm_17_Gtm_ChannelType Channel)  **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Channel : Channel Number                               **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Function to Clear the Notification status in the global**
**                                                      channel variable     **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE void Pwm_lClearNotificationStatus \
                                              (Pwm_17_Gtm_ChannelType Channel)
{
  #if (PWM_SAFETY_ENABLE == STD_ON)
  uint8 ChSignal ;
  #endif
  Pwm_17_Gtm_ChannelType ChIndex ;
  ChIndex = Pwm_lFindChannelIndex(Channel);
  #if (PWM_SAFETY_ENABLE == STD_ON)
  ChSignal = Pwm_lFindChannelSignal( Channel);
  if (ChSignal == PWM_ASIL_TYPE)
  {
    #if (PWM_MAX_ASIL_CHANNELS != 0)
    Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Asil[(ChIndex)]),
                   (PWM_BIT_RESET),
                   (sint32)(PWM_NOTIFI_STATUS_POS),
                   (PWM_CHAN_ID_STAT_BITS)
                  );
    #endif
  }
  else
  #endif
  {
    #if (PWM_MAX_QM_CHANNELS != 0)
    Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Qm[(ChIndex)]),
                   (PWM_BIT_RESET),
                   (sint32)(PWM_NOTIFI_STATUS_POS),
                   (PWM_CHAN_ID_STAT_BITS)
                  );
    #endif
    /*If QM channels are equal to zero do nothing */
  }
}

/******************************************************************************
** Syntax :     IFX_LOCAL_INLINE void Pwm_lSetDuty_0_Or_100_Status           **
**                                         (Pwm_17_Gtm_ChannelType Channel)  **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Channel : Channel Number                               **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Function to Set the Duty Notification status in the    **
**                                                 global channel variable   **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE void Pwm_lSetDuty_0_Or_100_Status
                                              (Pwm_17_Gtm_ChannelType Channel)
{
  #if (PWM_SAFETY_ENABLE == STD_ON)
  uint8 ChSignal;
  #endif
  Pwm_17_Gtm_ChannelType ChIndex ;
  ChIndex = Pwm_lFindChannelIndex(Channel);
  #if (PWM_SAFETY_ENABLE == STD_ON)
  ChSignal = Pwm_lFindChannelSignal(Channel);
  if (ChSignal == PWM_ASIL_TYPE)
  {
    #if (PWM_MAX_ASIL_CHANNELS != 0)
    Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Asil[(ChIndex)]),
                   (PWM_BIT_SET),
                   (sint32)(PWM_DUTY_0_OR_100_UPDATE_FLGPOS),
                   (PWM_CHAN_ID_STAT_BITS)
                  );
    #endif
  }
  else
  #endif
  {
    #if (PWM_MAX_QM_CHANNELS != 0)
    Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Qm[(ChIndex)]),
                   (PWM_BIT_SET),
                   (sint32)(PWM_DUTY_0_OR_100_UPDATE_FLGPOS),
                   (PWM_CHAN_ID_STAT_BITS)
                  );
    #endif
    /*If QM channels are equal to zero do nothing */
  }
}

/******************************************************************************
** Syntax :     IFX_LOCAL_INLINE void Pwm_lClearDuty_0_Or_100_Status         **
**                                         (Pwm_17_Gtm_ChannelType Channel)  **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Channel : Channel Number                               **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Function to clear the Duty Notification status in the  **
**                                                 global channel variable   **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE void Pwm_lClearDuty_0_Or_100_Status \
                                              (Pwm_17_Gtm_ChannelType Channel)
{
  #if (PWM_SAFETY_ENABLE == STD_ON)
  uint8 ChSignal;
  #endif
  Pwm_17_Gtm_ChannelType ChIndex;
  ChIndex = Pwm_lFindChannelIndex(Channel);
  #if (PWM_SAFETY_ENABLE == STD_ON)
  ChSignal = Pwm_lFindChannelSignal(Channel);
  if (ChSignal == PWM_ASIL_TYPE)
  {
    #if (PWM_MAX_ASIL_CHANNELS != 0)
    Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Asil[(ChIndex)]),
                   (PWM_BIT_RESET),
                   (sint32)(PWM_DUTY_0_OR_100_UPDATE_FLGPOS),
                   (PWM_CHAN_ID_STAT_BITS)
                  );
    #endif
  }
  else
  #endif
  {
    #if (PWM_MAX_QM_CHANNELS != 0)
    Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Qm[(ChIndex)]),
                   (PWM_BIT_RESET),
                   (sint32)(PWM_DUTY_0_OR_100_UPDATE_FLGPOS),
                   (PWM_CHAN_ID_STAT_BITS)
                   );
    #endif
    /*If QM channels are equal to zero do nothing */
  }
}

/******************************************************************************
** Syntax :      IFX_LOCAL_INLINE void Pwm_lClearNotificationEdges           **
**                                         (Pwm_17_Gtm_ChannelType Channel)  **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Channel : Channel Number                               **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Function to clear the Notification edges in the        **
**                                                 global channel variable   **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE void Pwm_lClearNotificationEdges  \
                                              (Pwm_17_Gtm_ChannelType Channel)
{
  #if (PWM_SAFETY_ENABLE == STD_ON)
  uint8 ChSignal;
  #endif
  Pwm_17_Gtm_ChannelType ChIndex;
  ChIndex = Pwm_lFindChannelIndex(Channel);
  #if (PWM_SAFETY_ENABLE == STD_ON)
  ChSignal = Pwm_lFindChannelSignal(Channel);
  if (ChSignal == PWM_ASIL_TYPE)
  {
    #if (PWM_MAX_ASIL_CHANNELS != 0)
    Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Asil[(ChIndex)]),
                   (PWM_BIT_RESET),
                   (sint32)(PWM_NOTIFI_EDGE_POS),
                    PWM_NOTIFI_EDGE_BITS
                  );
    #endif
  }
  else
  #endif
  {
    #if (PWM_MAX_QM_CHANNELS != 0)
    Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Qm[(ChIndex)]),
                   (PWM_BIT_RESET),
                   (sint32)(PWM_NOTIFI_EDGE_POS),
                    PWM_NOTIFI_EDGE_BITS
                  );
    #endif
    /*If QM channels are equal to zero do nothing */
  }
}

/******************************************************************************
** Syntax :           IFX_LOCAL_INLINE void Pwm_lSetNotificationEdges        **
**                    (                                                      **
**                      Pwm_17_Gtm_ChannelType Channel,                      **
**                      Pwm_17_Gtm_EdgeNotificationType Edge                 **
**                    )                                                      **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Channel : Channel Number                               **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Function to set the Notification edges in the          **
**                                                 global channel variable   **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE void Pwm_lSetNotificationEdges(
                                         Pwm_17_Gtm_ChannelType Channel,\
                                         Pwm_17_Gtm_EdgeNotificationType Edge)
{
  #if (PWM_SAFETY_ENABLE == STD_ON)
  uint8 ChSignal;
  #endif
  Pwm_17_Gtm_ChannelType ChIndex;
  ChIndex = Pwm_lFindChannelIndex(Channel);
  #if (PWM_SAFETY_ENABLE == STD_ON)
  ChSignal = Pwm_lFindChannelSignal(Channel);
  if (ChSignal == PWM_ASIL_TYPE)
  {
    #if (PWM_MAX_ASIL_CHANNELS != 0)
    Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Asil[(ChIndex)]),
                   (uint32)(Edge),
                   (sint32)(PWM_NOTIFI_EDGE_POS),
                    PWM_NOTIFI_EDGE_BITS
                  );
    #endif
  }
  else
  #endif
  {
    #if (PWM_MAX_QM_CHANNELS != 0)
    Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Qm[(ChIndex)]),
                   (uint32)(Edge),
                   (sint32)(PWM_NOTIFI_EDGE_POS),
                    PWM_NOTIFI_EDGE_BITS
                  );
    #endif
    /*If QM channels are equal to zero do nothing */
  }
}

/******************************************************************************
** Syntax :    IFX_LOCAL_INLINE Pwm_17_Gtm_EdgeNotificationType              **
**                   Pwm_lGetNotificationKind(Pwm_17_Gtm_ChannelType Channel)**
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Channel : Channel Number                               **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Function to get the Notification kind in the           **
**                                                 global channel variable   **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE Pwm_17_Gtm_EdgeNotificationType
                Pwm_lGetNotificationKind(Pwm_17_Gtm_ChannelType Channel)
{
  Pwm_17_Gtm_EdgeNotificationType RetVal;
  #if (PWM_SAFETY_ENABLE == STD_ON)
  uint8 ChSignal;
  #endif
  Pwm_17_Gtm_ChannelType ChIndex;
  ChIndex = Pwm_lFindChannelIndex(Channel);
  #if (PWM_SAFETY_ENABLE == STD_ON)
  #if ( (PWM_MAX_ASIL_CHANNELS == 0) || (PWM_MAX_QM_CHANNELS == 0) )
  RetVal = 0U;
  #endif
  ChSignal = Pwm_lFindChannelSignal(Channel);
  if (ChSignal == PWM_ASIL_TYPE)
  {
    #if (PWM_MAX_ASIL_CHANNELS != 0)
    RetVal = ((Pwm_17_Gtm_EdgeNotificationType)(Pwm_GlobChn_Asil[(ChIndex)] &
                                         PWM_NOTIFICATION_EDGE_MASK)
             );
    #endif
  }
  else
  #endif
  {
    #if (PWM_MAX_QM_CHANNELS != 0)
    RetVal = ((Pwm_17_Gtm_EdgeNotificationType)(Pwm_GlobChn_Qm[(ChIndex)] &
                                       PWM_NOTIFICATION_EDGE_MASK)
             );
    #endif
    /*If QM channels are equal to zero do nothing */
  }
  return(RetVal);
}

#endif /* PWM_NOTIFICATION_SUPPORTED */

#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
/******************************************************************************
** Syntax :        IFX_LOCAL_INLINE void Pwm_lSetChannelIdleStatus           **
**                                           (Pwm_17_Gtm_ChannelType Channel)**
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Channel : Channel Number                               **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Function to Set the idle status in the                 **
**                                                 global channel variable   **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE void Pwm_lSetChannelIdleStatus(
                           Pwm_17_Gtm_ChannelType Channel)
{
  #if (PWM_SAFETY_ENABLE == STD_ON)
  uint8 ChSignal;
  #endif
  Pwm_17_Gtm_ChannelType ChIndex;
  ChIndex = Pwm_lFindChannelIndex(Channel);
  #if (PWM_SAFETY_ENABLE == STD_ON)
  ChSignal = Pwm_lFindChannelSignal(Channel);
  if (ChSignal == PWM_ASIL_TYPE)
  {
    #if (PWM_MAX_ASIL_CHANNELS != 0)
    Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Asil[(ChIndex)]),
                   (1),
                   (sint32)(PWM_IDLE_CHANNEL_FLAG_POS),
                   (PWM_CHAN_ID_STAT_BITS)
                  );
    #endif
  }
  else
  #endif
  {
    #if (PWM_MAX_QM_CHANNELS != 0)
    Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Qm[(ChIndex)]),
                   (1),
                   (sint32)(PWM_IDLE_CHANNEL_FLAG_POS),
                   (PWM_CHAN_ID_STAT_BITS)
                  );
    #endif
    /*If QM channels are equal to zero do nothing */
  }
}
#endif /* (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) */

#if((PWM_SET_DUTY_CYCLE_API == STD_ON)||(PWM_SET_PERIOD_AND_DUTY_API == STD_ON))
/******************************************************************************
** Syntax :        IFX_LOCAL_INLINE uint32 Pwm_lGetChannelIdleStatus         **
**                                           (Pwm_17_Gtm_ChannelType Channel)**
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Channel : Channel Number                               **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      uint8                                                  **
**                                                                           **
** Description :      Function to get the idle status  from the              **
**                                                 global channel variable   **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE uint32 Pwm_lGetChannelIdleStatus
                                               (Pwm_17_Gtm_ChannelType Channel)
{
  uint32 RetVal;
  #if (PWM_SAFETY_ENABLE == STD_ON)
  uint8 ChSignal;
  #endif
  Pwm_17_Gtm_ChannelType ChIndex;
  ChIndex = Pwm_lFindChannelIndex(Channel);

  #if (PWM_SAFETY_ENABLE == STD_ON)

  #if ( (PWM_MAX_ASIL_CHANNELS == 0) || (PWM_MAX_QM_CHANNELS == 0) )
  RetVal = 0U;
  #endif

  ChSignal = Pwm_lFindChannelSignal(Channel);
  if (ChSignal == PWM_ASIL_TYPE)
  {
    #if (PWM_MAX_ASIL_CHANNELS != 0)
    RetVal = (uint32)(Pwm_GlobChn_Asil[(ChIndex)] & PWM_IDLE_STATUS_MASK );
    #endif
  }
  else
  #endif
  {
    #if (PWM_MAX_QM_CHANNELS != 0)
    RetVal = (uint32)(Pwm_GlobChn_Qm[(ChIndex)] & PWM_IDLE_STATUS_MASK );
    #endif
    /*If QM channels are equal to zero do nothing */
  }
  return(RetVal);
}
#endif
#if((PWM_SET_DUTY_CYCLE_API == STD_ON)||(PWM_SET_PERIOD_AND_DUTY_API == STD_ON))
/******************************************************************************
** Syntax :           IFX_LOCAL_INLINE void Pwm_lClearIdleStatus             **
**                                           (Pwm_17_Gtm_ChannelType Channel)**
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Channel : Channel Number                               **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Function to clear the Notification edges in the        **
**                                                 global channel variable   **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE void Pwm_lClearIdleStatus(Pwm_17_Gtm_ChannelType Channel)
{
  #if (PWM_SAFETY_ENABLE == STD_ON)
  uint8 ChSignal;
  #endif
  Pwm_17_Gtm_ChannelType ChIndex;
  ChIndex = Pwm_lFindChannelIndex(Channel);
  #if (PWM_SAFETY_ENABLE == STD_ON)
  ChSignal = Pwm_lFindChannelSignal(Channel);
  if (ChSignal == PWM_ASIL_TYPE)
  {
    #if (PWM_MAX_ASIL_CHANNELS != 0)
    Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Asil[(ChIndex)]),
                    (PWM_BIT_RESET),(sint32)(PWM_IDLE_CHANNEL_FLAG_POS),
                    (PWM_CHAN_ID_STAT_BITS)
                   );
    #endif
  }
  else
  #endif
  {
    #if (PWM_MAX_QM_CHANNELS != 0)
    Mcal_SetAtomic((sint32*)(void *)(&Pwm_GlobChn_Qm[(ChIndex)]),
                    (PWM_BIT_RESET),(sint32)(PWM_IDLE_CHANNEL_FLAG_POS),
                    (PWM_CHAN_ID_STAT_BITS)
                   );
    #endif
    /*If QM channels are equal to zero do nothing */
  }
}
#endif

/******************************************************************************
** Syntax :           IFX_LOCAL_INLINE uint32 Pwm_lGtmCounterVal             **
**                          (uint32 Shift, uint32 Period, uint32 DutyCycle)  **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Shift : Channel shift value                            **
**                    Period : Channel period value                          **
**                    DutyCycle : Channel duty value                         **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      uint32                                                 **
**                                                                           **
** Description :      Function to calculate the gtm counter value            **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE uint32 Pwm_lGtmCounterVal
(
  uint32 Shift,
  uint32 Period,
  uint32 DutyCycle
)
{
  uint32 RetVal;
  if((Shift + DutyCycle) == Period)
  {
    RetVal = Period;
  }
  else
  {
    /*IFX_MISRA_RULE_01_02_STATUS=For the condition Period is equal to 0 then
     the dutycycle and shift values also have the value 0.So the condition 
     divide by zero is avoided by the above if statement.*/
    RetVal = (uint32)((Shift + DutyCycle) % Period);
  }
  return(RetVal);
}

/*******************************************************************************
**                                                                            **
** Syntax : Pwm_ChannelIdentifierType Pwm_lGtmChannelIdentifier               **
**                           (Pwm_GlobalChannelNumberType GlobalChannelNumber)**
**                                                                            **
** Service ID:    None                                                        **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Reentrant                                                   **
**                                                                            **
** Parameters (in):    GlobalChannelNumber - Channel Number                   **
**                                                                            **
** Parameters (out):   None                                                   **
**                                                                            **
** Return value:  Structure which gives Module Number, Channel Number etc     **
**                                                                            **
** Description :  This routine converts the Global Channel Number to its      **
**                corresponding Channel Number, Module Number, TGC/AGC number.**
**                                                                            **
*******************************************************************************/
Pwm_ChannelIdentifierType Pwm_lGtmChannelIdentifier(
                               Pwm_GlobalChannelNumberType GlobalChannelNumber )
{
  Pwm_ChannelIdentifierType ChannelIdentifier;
  Pwm_GlobalChannelNumberType TempChannelNumber;
  ChannelIdentifier.ChannelNo = PWM_INVALID_NUMBER;
  ChannelIdentifier.ModuleId = PWM_INVALID_NUMBER;
  ChannelIdentifier.ModuleNo = PWM_INVALID_NUMBER;
  ChannelIdentifier.GroupNo = PWM_INVALID_NUMBER;

  #if(GTM_TOM_USED_BY_OTHER_DRIVERS == STD_ON)
  /* Check if its a TOM channel */
  if(GlobalChannelNumber < (GTM_MAX_TOM_CHANNELS + GTM_MAX_TIM_CHANNELS))
  {
    TempChannelNumber = GlobalChannelNumber - GTM_MAX_TIM_CHANNELS;
    /* Calculate Module Id of the TOM channel */
    ChannelIdentifier.ModuleId = GTM_TOM_MODULE;
    ChannelIdentifier.ModuleNo  =                    \
                 (uint8)(TempChannelNumber / GTM_CHANNELS_PER_TOM_MODULE);

    /* Calculate Channel number of the TOM channel */
    ChannelIdentifier.ChannelNo= TempChannelNumber %GTM_CHANNELS_PER_TOM_MODULE;
    ChannelIdentifier.GroupNo =
                       (ChannelIdentifier.ChannelNo)/GTM_TOM_CHANNELS_PER_TGC;
  }
  #endif /*   #if(GTM_TOM_USED_BY_OTHER_DRIVERS == STD_ON)   */

  #if(GTM_ATOM_USED_BY_OTHER_DRIVERS == STD_ON)
  /* Check if its a ATOM channel */
  if(GlobalChannelNumber >= (GTM_MAX_TOM_CHANNELS + GTM_MAX_TIM_CHANNELS))
  {
    TempChannelNumber =
            GlobalChannelNumber - (GTM_MAX_TIM_CHANNELS + GTM_MAX_TOM_CHANNELS);
    /* Calculate Module Id of the ATOM channel */
    ChannelIdentifier.ModuleId = GTM_ATOM_MODULE;
    ChannelIdentifier.ModuleNo  =                                   \
                    (uint8)(TempChannelNumber / GTM_CHANNELS_PER_ATOM_MODULE);

    /* Calculate Channel number of the ATOM channel */
    ChannelIdentifier.ChannelNo =
                               TempChannelNumber%GTM_CHANNELS_PER_ATOM_MODULE;
  }
  #endif
  /*   #if(GTM_ATOM_USED_BY_OTHER_DRIVERS == STD_ON)   */

  return (ChannelIdentifier);
}

#if (PWM_SAFETY_ENABLE == STD_ON)
/******************************************************************************
** Syntax :           IFX_LOCAL_INLINE uint32 Pwm_lSafetyPeriodRangeCheck(   **
**                                      uint8           ServiceID,           **
**                                      Pwm_17_Gtm_ChannelType ChannelNumber,**
**                                      Pwm_17_Gtm_PeriodType Period  )      **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   ServiceID    : Informs Service ID of an API            **
**                    ChannelNumber: Numeric identifier of the PWM channel   **
**                    Period       : Channel period value                    **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      uint32  ErrStatus indicates error has occured or not   **
**                                                                           **
** Description :      Function to Check if Period is within specified range  **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE uint32 Pwm_lSafetyPeriodRangeCheck(
                                   uint8                   ServiceID,
                                   Pwm_17_Gtm_ChannelType  ChannelNumber,
                                   Pwm_17_Gtm_PeriodType   Period
                                 )
{
  Pwm_ChannelIdentifierType GlobalChannelId;
  uint8                     CellUsed;
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; /* ROM pointer */
  uint32                    ErrStatus;
  ErrStatus = (uint32)0;
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    PBConfigStructure and is within allowed range.*/
  LocalPwmChanPtr = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
  /* Get the type of channel used */
  CellUsed = Pwm_lAssignedHW(LocalPwmChanPtr->ChannelInfo);
  GlobalChannelId = Pwm_lGtmChannelIdentifier(CellUsed);
  if((GlobalChannelId.ModuleId) == GTM_TOM_MODULE)
  {
    if (Period > (Pwm_17_Gtm_PeriodType)0xFFFE)
    {
      /* Report Safety Error */
      SafeMcal_ReportError(
                            PWM_17_GTM_MODULE_ID,
                            PWM_17_GTM_INSTANCE_ID,
                            ServiceID,
                            PWM_E_PERIOD_OUT_OF_RANGE
                          );
    ErrStatus = PWM_ERROR_FOUND;
    }
  }
  if((GlobalChannelId.ModuleId) == GTM_ATOM_MODULE)
  {
    if (Period > (Pwm_17_Gtm_PeriodType)0xFFFFFE)
    {
      SafeMcal_ReportError(
                            PWM_17_GTM_MODULE_ID,
                            PWM_17_GTM_INSTANCE_ID,
                            ServiceID,
                            PWM_E_PERIOD_OUT_OF_RANGE
                           );
       ErrStatus = PWM_ERROR_FOUND;
    }
  }
  return ErrStatus;
}
/******************************************************************************
** Syntax :           IFX_LOCAL_INLINE uint32 Pwm_lSafetyDutyRangeCheck(     **
**                                     uint8           ServiceID,            **
**                                      Pwm_17_Gtm_ChannelType ChannelNumber,**
**                                      Pwm_17_Gtm_DutyType Duty  )          **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   ServiceID    : Informs Service ID of an API            **
**                    ChannelNumber: Numeric identifier of the PWM channel   **
**                    Duty         : Channel Duty cycle value                **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      uint32  ErrStatus indicates error has occured or not   **
**                                                                           **
** Description :      Function to Check if Duty is within specified range    **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE uint32 Pwm_lSafetyDutyRangeCheck( uint8   ServiceID,\
                                 Pwm_17_Gtm_ChannelType   ChannelNumber,\
                                 uint32                   Duty)
{

  uint32                       ErrStatus;
  #if (PWM_DUTY_SHIFT_IN_TICKS == STD_ON)
  Pwm_ChannelIdentifierType   GlobalChannelId;
  uint8                       CellUsed;
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; /* ROM pointer */
  #endif
  ErrStatus = (uint32)0;
  #if (PWM_DUTY_SHIFT_IN_TICKS == STD_OFF)
  if (Duty > (uint32)0x8000)
  {
  /* Report Safety Error */
  SafeMcal_ReportError(
                        PWM_17_GTM_MODULE_ID,
                        PWM_17_GTM_INSTANCE_ID,
                        ServiceID,
                        PWM_E_DUTY_OUT_OF_RANGE
                       );
  ErrStatus = PWM_ERROR_FOUND;
  UNUSED_PARAMETER(ChannelNumber)
  }
  #else
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    PBConfigStructure and is within allowed range.*/
  LocalPwmChanPtr = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
  /* Get the type of channel used */
  CellUsed = Pwm_lAssignedHW(LocalPwmChanPtr->ChannelInfo);
  GlobalChannelId = Pwm_lGtmChannelIdentifier(CellUsed);
  if((GlobalChannelId.ModuleId) == GTM_TOM_MODULE)
  {
    if (Duty > (uint32)0xFFFE)
    {
      /* Report Safety Error */
      SafeMcal_ReportError(
                            PWM_17_GTM_MODULE_ID,
                            PWM_17_GTM_INSTANCE_ID,
                            ServiceID,
                            PWM_E_DUTY_OUT_OF_RANGE
                          );
     ErrStatus = PWM_ERROR_FOUND;
    }
  }
  if((GlobalChannelId.ModuleId) == GTM_ATOM_MODULE)
  {
    if (Duty > (uint32)0xFFFFFE)
    {
      SafeMcal_ReportError(
                            PWM_17_GTM_MODULE_ID,
                            PWM_17_GTM_INSTANCE_ID,
                            ServiceID,
                            PWM_E_DUTY_OUT_OF_RANGE
                           );
       ErrStatus = PWM_ERROR_FOUND;
    }
  }
  #endif
  return ErrStatus;
}

/******************************************************************************
** Syntax :           IFX_LOCAL_INLINE uint8 Pwm_lFindChannelSignal(         **
**                                      Pwm_17_Gtm_ChannelType ChannelNumber)**
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):                                                          **
**                    ChannelNumber: Numeric identifier of the PWM channel   **
**                                                                           **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      uint8 ChannelSignal: Returns if channel is ASIL or QM  **
**                                                                           **
** Description :      Function to Find channel Signal Type for safety signals**
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE uint8 Pwm_lFindChannelSignal(
                                 Pwm_17_Gtm_ChannelType ChannelNumber)
{
  uint8 ChannelSignal;
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; /* ROM pointer */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    PBConfigStructure and is within allowed range.*/
  LocalPwmChanPtr = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
  /* Get the type of channel used */
  ChannelSignal = LocalPwmChanPtr->SafetyChannelSignal;
  return (ChannelSignal);
}
#endif

/******************************************************************************
** Syntax :         IFX_LOCAL_INLINE uint32 Pwm_lMaxDuty(                    **
**                                 Pwm_ChannelIdentifierType GlobalChannelId)**
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):                                                          **
**              GlobalChannelId: Global channel Identifier for the channel   **
**                                                                           **
**                                                                           **
** Parameters (out):   None                                                  **
**                                                                           **
** Return value:      Duty:Maximum duty for the type of the channel          **
**                                                                           **
** Description :      Function to Find Maximum duty for the channel          **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE uint32 Pwm_lMaxDuty(Pwm_ChannelIdentifierType GlobalChannelId)
{
  uint32 Duty;
  if(GlobalChannelId.ModuleId==GTM_TOM_MODULE)
  {
    Duty = (uint32)PWM_MAX_TIMER_TOM;
  }
  else
  {
    Duty = (uint32)PWM_MAX_TIMER;
  }
  return Duty;
}
/******************************************************************************
** Syntax :   IFX_LOCAL_INLINE Pwm_17_Gtm_ChannelType Pwm_lFindChannelIndex  **
**                                    (                                      **
**                                      Pwm_17_Gtm_ChannelType ChannelNumber **
**                                    )                                      **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):                                                          **
**                    ChannelNumber: Numeric identifier of the PWM channel   **
**                                                                           **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      uint8 ChannelIndex: Channel index to access global     **
**                    variable                                               **
**                                                                           **
** Description :      Function to Find channel Index for safety signals      **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE Pwm_17_Gtm_ChannelType Pwm_lFindChannelIndex (
                                       Pwm_17_Gtm_ChannelType ChannelNumber)
{
  Pwm_17_Gtm_ChannelType ChannelIndex;
  #if (PWM_SAFETY_ENABLE == STD_ON)
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; /* ROM pointer */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    PBConfigStructure and is within allowed range.*/
  LocalPwmChanPtr = (Pwm_kConfigPtr->ChannelConfigPtr) + ChannelNumber;
  /* Get the type of channel used */
  ChannelIndex = LocalPwmChanPtr->SafetyChannelIndex;
  #else
  ChannelIndex = ChannelNumber;
  #endif
  return (ChannelIndex);
}
#if ((PWM_NOTIFICATION_SUPPORTED == STD_ON)&& \
  ((PWM_SET_DUTY_CYCLE_API == STD_ON)|| \
       (PWM_17_GTM_SYNCGRPUPDATEDUTIES_ENABLE == STD_ON)))
/******************************************************************************
** Syntax :           IFX_LOCAL_INLINE void Pwm_lHandleNotif(                **
**                                   Pwm_17_Gtm_ChannelClassType ChannelKind,**
**                                   uint32 Period,                          **
**                                   uint32 DutyCycle,                       **
**                                   Pwm_17_Gtm_ChannelType ChannelNumber,   **
**                                   uint8 CellUsed)                         **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   ChannelKind  : Type of channel                         **
**                    Period       : Period value of Channel                 **
**                    DutyCycle    : Duty cycle value                        **
**                    ChannelNumber: Numeric identifier of the PWM channel   **
**                    CellUsed     : Hardware channel used                   **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Function to Set the global variables for notification  **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE void Pwm_lHandleNotif(
      Pwm_17_Gtm_ChannelClassType ChannelKind,
      uint32 Period,
      uint32 DutyCycle,
      Pwm_17_Gtm_ChannelType ChannelNumber,
      uint8 CellUsed)
{
  Pwm_17_Gtm_EdgeNotificationType NotifValue = 0U;
  /* Get the type of notification asked */
  NotifValue = Pwm_lGetNotificationKind(ChannelNumber);
  NotifValue = NotifValue >> 5U;
  #if (PWM_NOTIF_FOR_100_0_ENABLE == STD_ON)
  if ((ChannelKind == PWM_FIXED_PERIOD_SHIFTED) || \
          (ChannelKind == PWM_FIXED_PERIOD_CENTER_ALIGNED))
  {
    if ( (DutyCycle == 0U) || (DutyCycle == Period) )
    {
      /* Disable notification if duty is 0% or 100% */
      Pwm_lGtmIrqModify(CellUsed,0U);
      /* Clear the flag in global variable which indicates notification
         is enabled*/
      Pwm_lClearNotificationStatus(ChannelNumber);
      /*Set the flag to indicate Duty is 0% or 100%*/
      Pwm_lSetDuty_0_Or_100_Status(ChannelNumber);
    }
    else
    {
      /* See whether notification was asked earlier */
      if ( NotifValue != PWM_NO_NOTIFICATION )
      {
        /* Set the flag in global variable which indicates notification
          is enabled*/
        Pwm_lSetNotificationStatus(ChannelNumber);
        /* Enable notification*/
        Pwm_lGtmIrqModify(CellUsed,NotifValue);
      }
      /*Clear the flag to indicate Duty is 0% or 100%*/
      Pwm_lClearDuty_0_Or_100_Status(ChannelNumber);
    }
  }
  else
  {
    if ( NotifValue != PWM_NO_NOTIFICATION )
    {
      /* Set the flag in global variable which indicates notification
         is enabled*/
      Pwm_lSetNotificationStatus(ChannelNumber);
      /* Enable notification*/
      Pwm_lGtmIrqModify(CellUsed,NotifValue);
    }
    UNUSED_PARAMETER(Period)
    UNUSED_PARAMETER(DutyCycle)
  }
  #else
  {
    if ( (DutyCycle == 0U) || (DutyCycle == Period) )
    {
      /* Disable notification if duty is 0% or 100% */
      Pwm_lGtmIrqModify(CellUsed,0U);
      /* Clear the flag in global variable which indicates notification
         is enabled*/
      Pwm_lClearNotificationStatus(ChannelNumber);
      /*Set the flag to indicate Duty is 0% or 100%*/
      Pwm_lSetDuty_0_Or_100_Status(ChannelNumber);
    }
    else
    {
      /* See whether notification was asked earlier */
      if ( NotifValue != PWM_NO_NOTIFICATION )
      {
        /* Set the flag in global variable which indicates notification
           is enabled*/
        Pwm_lSetNotificationStatus(ChannelNumber);
        /* Enable notificatio */
        Pwm_lGtmIrqModify(CellUsed,NotifValue);
      }
      /*Clear the flag to indicate Duty is 0% or 100%*/
      Pwm_lClearDuty_0_Or_100_Status(ChannelNumber);
    }
    /* to remove unused param warning in GNU */
    UNUSED_PARAMETER(ChannelKind)
  }
  #endif
}
#endif
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
#if (PWM_SAFETY_ENABLE == STD_ON)
#if (PWM_MAX_ASIL_CHANNELS != 0)
/******************************************************************************
** Syntax :           IFX_LOCAL_INLINE void Pwm_lEnableAsilNotif(            **
**                                   Pwm_17_Gtm_ChannelClassType ChannelKind,**
**                     Pwm_17_Gtm_ChannelType ChannelNumber,                 **
**                     uint8 CellUsed,                                       **
**                     Pwm_17_Gtm_EdgeNotificationType Notification,         **
**                     Pwm_17_Gtm_ChannelType ChIndex)                       **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   ChannelKind :Type of channel                           **
**                    ChannelNumber: Numeric identifier of the PWM channel   **
**                    CellUsed : Hardware channel used                       **
**                    Notification : Type of notification requested          **
**                    ChIndex : Channel indes to access global array         **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Function to Set the global variables for notification  **
*                     and enable notification                                **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE void Pwm_lEnableAsilNotif( 
                     Pwm_17_Gtm_ChannelClassType ChannelKind,
                     Pwm_17_Gtm_ChannelType ChannelNumber,
                     uint8 CellUsed,
                     Pwm_17_Gtm_EdgeNotificationType Notification,
                     Pwm_17_Gtm_ChannelType ChIndex)
{
   #if (PWM_NOTIF_FOR_100_0_ENABLE == STD_ON)
   if ((ChannelKind != PWM_FIXED_PERIOD_SHIFTED) && \
          (ChannelKind != PWM_FIXED_PERIOD_CENTER_ALIGNED))
   {
     /* Enable Notification */
     Pwm_lSetNotificationStatus(ChannelNumber);
     Pwm_lGtmIrqModify(CellUsed,Notification);
   }
   else
   {
     /* Enable notification if Duty is not equal to 0% or 100% */
     if ((Pwm_GlobChn_Asil[ChIndex] & PWM_DUTY_0_OR_100_UPDATE_MASK) == 0U)
     /* Enable notification if Duty is not equal to 0% or 100% */
     {
        /* Enable Notification */
       Pwm_lSetNotificationStatus(ChannelNumber);
       Pwm_lGtmIrqModify(CellUsed,Notification);
     }
   }
   #else
   /* Enable notification if Duty is not equal to 0% or 100% */
   if ((Pwm_GlobChn_Asil[ChIndex] & PWM_DUTY_0_OR_100_UPDATE_MASK) == 0U)
   /* Enable notification if Duty is not equal to 0% or 100% */
   {
     /* Enable Notification */
     Pwm_lSetNotificationStatus(ChannelNumber);
     Pwm_lGtmIrqModify(CellUsed,Notification);
   }
   /* to remove unused param warning in GNU */
   UNUSED_PARAMETER(ChannelKind)
   #endif
}
#endif
#endif
#if (PWM_MAX_QM_CHANNELS != 0)
/******************************************************************************
** Syntax :           IFX_LOCAL_INLINE void Pwm_lEnableQmNotif(              **
**                                   Pwm_17_Gtm_ChannelClassType ChannelKind,**
**                     Pwm_17_Gtm_ChannelType ChannelNumber,                 **
**                     uint8 CellUsed,                                       **
**                     Pwm_17_Gtm_EdgeNotificationType Notification,         **
**                     Pwm_17_Gtm_ChannelType ChIndex)                       **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   ChannelKind :Type of channel                           **
**                    ChannelNumber: Numeric identifier of the PWM channel   **
**                    CellUsed : Hardware channel used                       **
**                    Notification : Type of notification requested          **
**                    ChIndex : Channel indes to access global array         **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Function to Set the global variables for notification  **
*                     and enable notification                                **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE void Pwm_lEnableQmNotif(
                     Pwm_17_Gtm_ChannelClassType ChannelKind,
                     Pwm_17_Gtm_ChannelType ChannelNumber,
                     uint8 CellUsed,
                     Pwm_17_Gtm_EdgeNotificationType Notification,
                     Pwm_17_Gtm_ChannelType ChIndex)
{
  #if (PWM_NOTIF_FOR_100_0_ENABLE == STD_ON)
  if ((ChannelKind != PWM_FIXED_PERIOD_SHIFTED) && \
         (ChannelKind != PWM_FIXED_PERIOD_CENTER_ALIGNED))
  {
    Pwm_lSetNotificationStatus(ChannelNumber);
    Pwm_lGtmIrqModify(CellUsed,Notification);
  }
  else
  {
    if ((Pwm_GlobChn_Qm[ChIndex] & PWM_DUTY_0_OR_100_UPDATE_MASK) == 0U)
    {
      /* Enable Notification */
      Pwm_lSetNotificationStatus(ChannelNumber);
      Pwm_lGtmIrqModify(CellUsed,Notification);
    }
  }
  #else
  if ((Pwm_GlobChn_Qm[ChIndex] & PWM_DUTY_0_OR_100_UPDATE_MASK) == 0U)
  {
    /* Enable Notification */
    Pwm_lSetNotificationStatus(ChannelNumber);
    Pwm_lGtmIrqModify(CellUsed,Notification);
  }
  /* to remove unused param warning in GNU */
  UNUSED_PARAMETER(ChannelKind)
  #endif
}
#endif
#endif

#if (PWM_17_GTM_SYNCGRPUPDATEDUTIES_ENABLE == STD_ON) 
/******************************************************************************
** Syntax : Std_ReturnType Pwm_17_Gtm_SyncGrpUpdateDuties(                   **
**                                            uint8           PwmGroupId,    **
**                                            uint32          *PwmChDutyPtr) **
** Service ID:0x15                                                           **
**                                                                           **
** Sync/Async:Synchronous                                                   **
**                                                                           **
** Reentrancy:Reentrant for Different Groups                                 **
**                                                                           **
** Parameters (in):  PwmGroupId  : Numeric identifier of the PWM channel     **
**                                 Group                                     **
**                   PwmChDutyPtr: Pointer to the Array holding duty cycle   **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value: E_OK/E_NOT_OK                                               **
**                                                                           **
** Description : Service to set Duty cycle PWM013:                           **
**               1.This service will allow to set the duty cycle of multiple **
**                 PWM channels in a group.                                  **
**               2.If the duty cycle>100%(value>0x8000), then the PWM output **
**                 will be undefined behavior (recommended that, user not to **
**                 provide this range of value)                              **
**               3 If the duty cycle >0% and <100%,then the PWM output will  **
**                 set to active state according to duty cycle and period    **
**                 parameters , polarity state.                              **
**               4.Dependency on PWM_DUTYCYCLE_UPDATED_ENDPERIOD config      **
**                 parameter.                                                **
**                                                                           **
** Traceabilty      :                                                        **
** [cover parentID=DS_NAS_HE2_PWM_PR3028] [/cover]                           **
** [cover parentID=SAS_MCAL_HE2_PWM_0926] [/cover]                           **
******************************************************************************/
Std_ReturnType Pwm_17_Gtm_SyncGrpUpdateDuties(
                                      uint8              PwmGroupId,
                                      uint32             *PwmChDutyPtr) 
{
  Std_ReturnType                     ErrStatus;
  Pwm_ArrayStructureType             RegPtr={{0U,0U,0U,0U,0U,0U,0U,0U}, \
                                             {0U,0U,0U,0U,0U,0U,0U,0U}, \
                                             {0U,0U,0U,0U,0U,0U,0U,0U}};
  const Pwm_17_Gtm_GroupConfigType   *LocalPwmGroupPtr;
  const Pwm_17_Gtm_GrpChanConfigType *LocalPwmGroupChPtr;
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr;
  Pwm_17_Gtm_ChannelType             PwmChannelNumber;
  Pwm_17_Gtm_ChannelClassType        ChannelKind;
  uint16                             CohAndMax;
  uint8                              MaxChannels;
  uint8                              ModuleNumber;
  uint8                              TomOrAtom;
  uint8                              ChannelIndex;
  #if ((PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON)|| \
       (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON))  
  Pwm_17_Gtm_ChannelType             MainChannel;
  uint32                             Period; 
  uint32                             ScaledDuty;
  uint32                             ShiftVal=0U; 
  #endif
  #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
  uint8                             CellUsed;
  #endif
  #if (PWM_VARIABLE_PERIOD_USED == STD_ON)
  Pwm_17_Gtm_ChannelType             ChIndex;
  #endif

  /* PWM_DEV_ERROR_DETECT and PWM_SAFETY_ENABLE*/
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  /* Local API to check for safety and DET errors */
  ErrStatus = Pwm_lSyncGroupErrorChecks(PwmGroupId,PwmChDutyPtr);
  #endif
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  /* Check for any errors and if there are no errors then proceed */
  if(ErrStatus == (uint8)E_OK)
  #endif
  /* PWM_DEV_ERROR_DETECT and PWM_SAFETY_ENABLE*/
  {

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
      PBConfigStructure and is within allowed range.*/
    LocalPwmGroupPtr = ((Pwm_kConfigPtr->GroupConfigPtr) + PwmGroupId);
    /*Maximum channels in the group*/
    MaxChannels =  LocalPwmGroupPtr->MaxGroupChannels;
    /*Extract the TOM/ATOM details*/
    ModuleNumber = LocalPwmGroupPtr->TomOrAtomModuleNumber;
    TomOrAtom = LocalPwmGroupPtr-> TomOrAtom;
    CohAndMax=0U;
    /*Loop for each channel in the PWM group*/
    for(ChannelIndex=0U;ChannelIndex<MaxChannels;ChannelIndex++)
    {
      /*Extract the pointer for each channel in the group*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
        PBConfigStructure and is within allowed range.*/
      LocalPwmGroupChPtr = (LocalPwmGroupPtr->GrpChanConfigPtr) + ChannelIndex;
      PwmChannelNumber = LocalPwmGroupChPtr->PwmChannelNumber;
      /*Extract the local channel configuration*/  
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
        PBConfigStructure and is within allowed range.*/
      LocalPwmChanPtr = (Pwm_kConfigPtr->ChannelConfigPtr) + PwmChannelNumber;
      /*This Array is used to update the Tom or Atom Shadow registers*/
      RegPtr.ChannelUsed[ChannelIndex] = LocalPwmGroupChPtr->TomAtomNum;
      /* Extract the channel Kind */
      ChannelKind = Pwm_lChanClass(LocalPwmChanPtr->ChannelInfo);
      #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
      CellUsed = Pwm_lAssignedHW(LocalPwmChanPtr->ChannelInfo);
      #endif
      /* PWM_NOTIFICATION_SUPPORTED */
      /* Update the coherency of each channel*/
      #if(PWM_DUTYCYCLE_UPDATED_ENDPERIOD == STD_ON)
      CohAndMax = (CohAndMax|(uint16)( \
                          (uint16)0x1U<<(uint8)(ChannelIndex&0x7U)));
      #else
      if (1U == Pwm_lCoherency(LocalPwmChanPtr->ChannelInfo))
      {
        CohAndMax = (CohAndMax|(uint16)( \
                          (uint16)0x1U<<(uint8)(ChannelIndex&0x7U)));
      }
      #endif
      switch (ChannelKind)
      {
        #if (PWM_VARIABLE_PERIOD_USED == STD_ON)
        case PWM_VARIABLE_PERIOD:
          ChIndex = Pwm_lFindChannelIndex(PwmChannelNumber);
          #if (PWM_SAFETY_ENABLE == STD_ON)
          #if (PWM_MAX_ASIL_CHANNELS != 0)
          if (PWM_ASIL_TYPE == Pwm_lFindChannelSignal(PwmChannelNumber))
          {
            RegPtr.SR0_VAL[ChannelIndex] = Pwm_CurrentPeriodVal_Asil[ChIndex] ;
          }
          else
          #endif
          #endif
          {
            #if (PWM_MAX_QM_CHANNELS != 0)
            RegPtr.SR0_VAL[ChannelIndex] = Pwm_CurrentPeriodVal_Qm[ChIndex];
            #endif
            /*If QM channels are equal to zero do nothing */
          }
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
           Duty cycle Array passed and is within allowed range.*/
          RegPtr.SR1_VAL[ChannelIndex] = (uint32)Pwm_lGetAbsvalEdge( \
                 RegPtr.SR0_VAL[ChannelIndex],PwmChDutyPtr[ChannelIndex]);
          /* Local function to set or clear the flags and enable/disable 
             interrupts based on duty cycle value */
          #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
          Pwm_lHandleNotif(ChannelKind,RegPtr.SR0_VAL[ChannelIndex], \
               RegPtr.SR1_VAL[ChannelIndex],PwmChannelNumber,CellUsed);
          #endif
          break;
        #endif
        #if (PWM_FIXED_PERIOD_USED == STD_ON)
        case PWM_FIXED_PERIOD:
          RegPtr.SR0_VAL[ChannelIndex]=LocalPwmChanPtr->PeriodDefault;
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
           Duty cycle Array passed and is within allowed range.*/
          RegPtr.SR1_VAL[ChannelIndex]=(uint32)Pwm_lGetAbsvalEdge( \
                 RegPtr.SR0_VAL[ChannelIndex],PwmChDutyPtr[ChannelIndex]);
          /* Local function to set or clear the flags and enable/disable 
             interrupts based on duty cycle value */
          #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
          Pwm_lHandleNotif(ChannelKind,RegPtr.SR0_VAL[ChannelIndex], \
                 RegPtr.SR1_VAL[ChannelIndex],PwmChannelNumber,CellUsed);
          #endif
        break;
        #endif
        #if (PWM_FIXED_PERIOD_SHIFTED_USED == STD_ON)
        case PWM_FIXED_PERIOD_SHIFTED:
          MainChannel = Pwm_lReferChan(LocalPwmChanPtr->ChannelInfo);
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
          PBConfigStructure and is within allowed range.*/
          Period   =
             ((Pwm_kConfigPtr->ChannelConfigPtr) + MainChannel )->PeriodDefault;
          /* Get Scale value of Duty according to period */
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
           Duty cycle Array passed and is within allowed range.*/
          ScaledDuty = (uint32)Pwm_lGetAbsvalEdge( \
                                 Period,PwmChDutyPtr[ChannelIndex]);
          /* Get the Shift lead value */
          if(Pwm_lShiftSpl(LocalPwmChanPtr->ChannelInfo) == \
                                                PWM_SHIFTED_RELATED_CHANNEL)
          {
            RegPtr.SR0_VAL[ChannelIndex]=Period;
            RegPtr.SR1_VAL[ChannelIndex]=ScaledDuty;      
          }
          else
          {
            ShiftVal =
              (uint32)Pwm_lGetShiftLead(Period,
                          (Pwm_17_Gtm_PeriodType)(LocalPwmChanPtr->ShiftValue));
             if (ScaledDuty == 0U)
             {
               RegPtr.SR1_VAL[ChannelIndex] = Period+1U;
               RegPtr.SR0_VAL[ChannelIndex] = PWM_SR0_VALUE;
             }
             else if (ScaledDuty == Period)
             {
               RegPtr.SR1_VAL[ChannelIndex] = PWM_SR1_VALUE;
               RegPtr.SR0_VAL[ChannelIndex] = Period+1U;
             }
             else
             {
              RegPtr.SR0_VAL[ChannelIndex] = Pwm_lGtmCounterVal(ShiftVal, \
                                       Period, ScaledDuty);
              RegPtr.SR1_VAL[ChannelIndex] = ShiftVal;
             }
          }
          /* Local function to set or clear the flags and enable/disable 
             interrupts based on duty cycle value */
          #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
          Pwm_lHandleNotif(ChannelKind,Period, \
                 ScaledDuty,PwmChannelNumber,CellUsed);
          #endif
          break;
        #endif
        default:
        #if (PWM_USED_FIXED_PERIOD_CENTER_ALIGNED == STD_ON)
          MainChannel = Pwm_lReferChan(LocalPwmChanPtr->ChannelInfo);
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
            PBConfigStructure and is within allowed range.*/
          Period =
           ((Pwm_kConfigPtr->ChannelConfigPtr) + MainChannel )->PeriodDefault;
          /* Get Scale value of Duty according to period */
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
           Duty cycle Array passed and is within allowed range.*/
          ScaledDuty = (uint32)Pwm_lGetAbsvalEdge(Period, \
                                      PwmChDutyPtr[ChannelIndex]);
          /* Get the Shift lead value */
          ShiftVal = (uint32)Pwm_lGetCenterLead(Period, ScaledDuty);
             if (ScaledDuty == 0U)
             {
               RegPtr.SR1_VAL[ChannelIndex] = Period+1U;
               RegPtr.SR0_VAL[ChannelIndex] = PWM_SR0_VALUE;
             }
             else if (ScaledDuty == Period)
             {
               RegPtr.SR1_VAL[ChannelIndex] = PWM_SR1_VALUE;
               RegPtr.SR0_VAL[ChannelIndex] = Period+1U;
             }
             else
             {
              RegPtr.SR0_VAL[ChannelIndex] = Pwm_lGtmCounterVal(ShiftVal, \
                               Period, ScaledDuty);
              RegPtr.SR1_VAL[ChannelIndex] = ShiftVal;
             }
          /* Local function to set or clear the flags and enable/disable 
             interrupts based on duty cycle value */
          #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
          Pwm_lHandleNotif(ChannelKind,Period, \
                 ScaledDuty,PwmChannelNumber,CellUsed);
          #endif
        #endif
        break;
      }/* End of Switch condition */
      if(Pwm_lGetChannelIdleStatus(PwmChannelNumber) != 0U)
      {
        Pwm_lClearIdleStatus(PwmChannelNumber);
      }
    }
    /*Combining max channels and coherency variables*/
    CohAndMax=(uint16)(((uint16)CohAndMax)|(uint16)((uint16)MaxChannels<<8U));
    if(0U == TomOrAtom)
    {
      /* Local function to update Tom channel registers */
      Pwm_lUpdateTomReg(ModuleNumber,RegPtr,CohAndMax);
    }
    else
    {
      /* Local function to update Atom channel registers */
      Pwm_lUpdateAtomReg(ModuleNumber,RegPtr,CohAndMax);
    }
    ErrStatus = (uint8)E_OK;
  }
return ErrStatus;
/*IFX_MISRA_RULE_16_07_STATUS=Adding const qualification may give 
  warning to the user*/
}

/******************************************************************************
** Syntax :           IFX_LOCAL_INLINE void Pwm_lUpdateTomReg(               **
**                                      uint8 ModuleNumber,                  **
**                                      const Pwm_ArrayStructureType Regptr  **
**                                      uint16 CohAndMax)                    **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   ModuleNumber: TOM Module number                        **
**                    Regptr      : Structure holding details like           **
**                                  Channel number,Values to be updated into **
**                                  shadow registers                         **
**                    CohAndMax   : Variable holding coherency details for   **
**                                  the group of channels and  Maximum       **
**                                  channels in the group                    **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Function to Update compare registers for TOM channels  **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE void Pwm_lUpdateTomReg(uint8 ModuleNumber,
                                    const Pwm_ArrayStructureType Regptr,
                                    uint16 CohAndMax)
{
  Ifx_GTM_TOM_CH_TYPE * TomChannelRegPtr;
  uint32 ChannelNumber;
  uint16 LoopVar;
  uint16 MaxGroupChannels;
  /* Get the maximum number of channels in the group */
  MaxGroupChannels = (uint16)((CohAndMax & 0xFF00U)>>8U);
  /* Get the coherency details */
  CohAndMax = (uint16)((CohAndMax & 0x00FFU));
  for(LoopVar=0U;LoopVar<MaxGroupChannels;LoopVar++)
  {
    /* Extract the Tom channel number */
    ChannelNumber = Regptr.ChannelUsed[LoopVar];
    TomChannelRegPtr = &(((*(Ifx_GTM_TOMx*)(volatile void*) \
                   (MODULE_GTM.TOM)).TOM_CH[ModuleNumber].CH[ChannelNumber]));
    if (0U == ((uint16)((uint16)((uint16)0x1U<<(LoopVar&0x7U)))&CohAndMax))
    {
     PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->CM1.U),\
                            Regptr.SR1_VAL[LoopVar]);
     PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->CM0.U),\
                            Regptr.SR0_VAL[LoopVar]);
     PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->SR1.U),\
                            Regptr.SR1_VAL[LoopVar]);
     PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->SR0.U),\
                            Regptr.SR0_VAL[LoopVar]);
    }
   else
    {
      PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->SR1.U),\
                            Regptr.SR1_VAL[LoopVar]);
      PWM_SFR_RUNTIME_USER_MODE_WRITE32((TomChannelRegPtr->SR0.U),\
                            Regptr.SR0_VAL[LoopVar]);
    }
  }
}

/******************************************************************************
** Syntax :           IFX_LOCAL_INLINE void Pwm_lUpdateAtomReg(              **
**                                      uint8 ModuleNumber,                  **
**                                      const Pwm_ArrayStructureType Regptr, **
**                                      uint16 CohAndMax)                    **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   ModuleNumber: ATOM Module number                       **
**                    Regptr      : Structure holding details like           **
**                                  Channel number,Values to be updated into **
**                                  shadow registers                         **
**                    CohAndMax   : Variable holding coherency details for   **
**                                  the group of channels and  Maximum       **
**                                  channels in the group                    **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      none                                                   **
**                                                                           **
** Description :      Function to Update compare registers for TOM channels  **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE void Pwm_lUpdateAtomReg(uint8 ModuleNumber,
                                    const Pwm_ArrayStructureType Regptr,
                                    uint16 CohAndMax)
{
  Ifx_GTM_ATOM_CH_TYPE * AtomChannelRegPtr;
  Pwm_17_Gtm_ChannelType ChannelNumber;
  uint16 LoopVar;
  uint16 MaxGroupChannels;
  /* Get the maximum number of channels in the group */
  MaxGroupChannels = (uint16)((CohAndMax & 0xFF00U)>>8U);
  /* Get the coherency details */
  CohAndMax = (uint16)((CohAndMax & 0x00FFU));
  for(LoopVar=0U;LoopVar<MaxGroupChannels;LoopVar++)
  {
    /* Extract the Atom channel number */
    ChannelNumber = Regptr.ChannelUsed[LoopVar];
    AtomChannelRegPtr =  &(((*(Ifx_GTM_ATOMx*)(volatile void*)\
              (MODULE_GTM.ATOM)).ATOM_CH[ModuleNumber].CH[ChannelNumber]));
    if (0U == ((uint16)((uint16)((uint16)0x1U<<(LoopVar&7U)))&CohAndMax))
    {
      PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->CM1.U),\
                            Regptr.SR1_VAL[LoopVar]);
      PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->CM0.U),\
                            Regptr.SR0_VAL[LoopVar]);
      PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->SR1.U),\
                            Regptr.SR1_VAL[LoopVar]);
      PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->SR0.U),\
                            Regptr.SR0_VAL[LoopVar]);
    }
    else
    {
      PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->SR1.U),\
                            Regptr.SR1_VAL[LoopVar]);
      PWM_SFR_RUNTIME_USER_MODE_WRITE32((AtomChannelRegPtr->SR0.U),\
                            Regptr.SR0_VAL[LoopVar]);
    }
  }
}

#if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
/******************************************************************************
** Syntax :           IFX_LOCAL_INLINE uint32 Pwm_lSyncGroupErrorChecks(     **
**                                              uint8  PwmGroupId,           **
**                                              uint32 *PwmChDutyPtr)        **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
**                    PwmGroupId   : Array holding Duty cycle values         **
**                    PwmGroupId   : Numeric identifier of the PWM Group     **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      Std_ReturnType                                         **
**                            ErrStatus indicates error has occured or not   **
**                                                                           **
** Description :      Function to Check if Duty is within specified range    **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE Std_ReturnType Pwm_lSyncGroupErrorChecks(uint8 PwmGroupId,
                                     const    uint32 *PwmChDutyPtr)
{
  Std_ReturnType ErrStatus = E_OK;
  #if ((PWM_DEV_ERROR_DETECT == STD_ON)||(PWM_SAFETY_ENABLE == STD_ON))
  if (PWM_ERROR_FOUND == Pwm_lVerUnInit(PWM_SID_SYNCGRPUPDATEDUTIES))
  {
    /* Return without executing any of functionality */
     ErrStatus = (uint8)E_NOT_OK;
  }
  else 
  {
    ErrStatus = Pwm_lVerGroupId( \
                    PWM_SID_SYNCGRPUPDATEDUTIES,PwmGroupId);
  }
  #endif
  #if (PWM_SAFETY_ENABLE == STD_ON)
  if(ErrStatus == (uint8)E_OK)
  {
    if (PWM_ERROR_FOUND == Pwm_lSafetyDutyMarkerCheck( \
                       PWM_SID_SYNCGRPUPDATEDUTIES,PwmChDutyPtr,PwmGroupId))
    {
      /* Return without executing any of functionality */
      ErrStatus = (uint8)E_NOT_OK;
    }
    else
    {
      if (PWM_ERROR_FOUND == Pwm_lSafetyGrpDutyRangeCheck( \
                      PWM_SID_SYNCGRPUPDATEDUTIES,PwmChDutyPtr,PwmGroupId))
      {
        /* Return without executing any of functionality */
        ErrStatus = (uint8)E_NOT_OK;
      }
    }
  }
  #else
  UNUSED_PARAMETER(PwmChDutyPtr)
  #endif
  return ErrStatus;
}
/******************************************************************************
** Syntax : IFX_LOCAL_INLINE Std_ReturnType Pwm_lVerGroupId( uint8 ServiceID,**
**                                 uint8 GroupId)                            **
**                                                                           **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   Service ID : Informs Service ID of an API              **
**                    GroupId  : GroupId of the channel                      **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      ErrStatus (Std_ReturnType)                             **
**                                                                           **
** Description :      Local function :Service to detect Wrong GroupId        **
**                                                                           **
** Traceability:                                                             **
**                                                                           **
******************************************************************************/
IFX_LOCAL_INLINE Std_ReturnType Pwm_lVerGroupId( uint8 ServiceID,uint8 GroupId)
{
  Std_ReturnType      ErrStatus;
  ErrStatus = E_OK;
  if(GroupId >= Pwm_kConfigPtr->MaxGroups) 
  {
    #if (PWM_DEV_ERROR_DETECT == STD_ON)
    Det_ReportError(
                     PWM_17_GTM_MODULE_ID,
                     PWM_17_GTM_INSTANCE_ID,
                     ServiceID,
                     PWM_E_GROUPID
                   ); 
    #endif
    #if(PWM_SAFETY_ENABLE == STD_ON)
    SafeMcal_ReportError(
                          PWM_17_GTM_MODULE_ID,
                          PWM_17_GTM_INSTANCE_ID,
                          ServiceID,
                          PWM_E_GROUPID
                        );
    #endif
    ErrStatus = E_NOT_OK;
  }
  return ErrStatus;
}/* End of Pwm_lVerGroupId() function */
#endif
#if (PWM_SAFETY_ENABLE == STD_ON)
/******************************************************************************
** Syntax :           IFX_LOCAL_INLINE uint32 Pwm_lSafetyGrpDutyRangeCheck(  **
**                                              uint8  ServiceID,            **
**                                              uint32 *Duty,                **
**                                              uint8 GroupId  )             **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   ServiceID    : Informs Service ID of an API            **
**                    Duty         : Array holding Duty cycle values         **
**                    GroupId      : Numeric identifier of the PWM Group     **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      uint32  ErrStatus indicates error has occured or not   **
**                                                                           **
** Description :      Function to Check if Duty is within specified range    **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE Std_ReturnType Pwm_lSafetyGrpDutyRangeCheck( 
                          uint8 ServiceID,const uint32 *Duty,uint8 GroupId)
{
  Std_ReturnType                       ErrStatus;
  const Pwm_17_Gtm_GroupConfigType *LocalPwmGrpPtr; /* ROM pointer */
  uint8 MaxChannel;
  uint8 TomOrAtom;
  uint8 ChannelIndex;
  ErrStatus = E_OK;
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    PBConfigStructure and is within allowed range.*/
  LocalPwmGrpPtr = (Pwm_kConfigPtr->GroupConfigPtr) + GroupId;
  MaxChannel = LocalPwmGrpPtr->MaxGroupChannels;
  TomOrAtom = LocalPwmGrpPtr-> TomOrAtom;
  for(ChannelIndex = 0U; \
       ((ChannelIndex < MaxChannel) && (ErrStatus != E_NOT_OK)); \
       ChannelIndex++)
  {
    #if (PWM_DUTY_SHIFT_IN_TICKS == STD_OFF)
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
        Duty cycle Array passed and is within allowed range.*/
    if (Duty[ChannelIndex] > (uint32)PWM_MAX_DUTY)
    {
      /* Report Safety Error */
      SafeMcal_ReportError(
                            PWM_17_GTM_MODULE_ID,
                            PWM_17_GTM_INSTANCE_ID,
                            ServiceID,
                            PWM_E_DUTY_OUT_OF_RANGE
                          );
      ErrStatus = E_NOT_OK;
      UNUSED_PARAMETER(TomOrAtom)
    }
    #else
    if(0U == TomOrAtom)
    {
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
        Duty cycle Array passed and is within allowed range.*/
      if (Duty[ChannelIndex] > PWM_MAX_TIMER_TOM)
      {
        /* Report Safety Error */
        SafeMcal_ReportError(
                              PWM_17_GTM_MODULE_ID,
                              PWM_17_GTM_INSTANCE_ID,
                              ServiceID,
                              PWM_E_DUTY_OUT_OF_RANGE
                            );
        ErrStatus = E_NOT_OK;
      }
    }
    if(1U == TomOrAtom)
    {
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
        Duty cycle Array passed and is within allowed range.*/
      if (Duty[ChannelIndex] > PWM_MAX_TIMER)
      {
        SafeMcal_ReportError(
                              PWM_17_GTM_MODULE_ID,
                              PWM_17_GTM_INSTANCE_ID,
                              ServiceID,
                              PWM_E_DUTY_OUT_OF_RANGE
                             );
        ErrStatus = E_NOT_OK;
      }
    }
    #endif
  }
  return ErrStatus;
}
/******************************************************************************
** Syntax :           IFX_LOCAL_INLINE uint32 Pwm_lSafetyDutyMarkerCheck(    **
**                                              uint8  ServiceID,            **
**                                              uint32 *DutyCycle,           **
**                                              uint8 GroupId  )             **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   ServiceID    : Informs Service ID of an API            **
**                    DutyCycle    : Array holding Duty cycle values         **
**                    GroupId      : Numeric identifier of the PWM Group     **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:      uint32  ErrStatus indicates error has occured or not   **
**                                                                           **
** Description :      Function to Check if Duty passed is correct by verifing** 
**                    with the marker in the configuration.                  **
**                                                                           **
*****************************************************************************/
IFX_LOCAL_INLINE Std_ReturnType Pwm_lSafetyDutyMarkerCheck(
                         uint8 ServiceID,const uint32 *DutyCycle,uint8 GroupId)
{
  Std_ReturnType                       ErrStatus;
  const Pwm_17_Gtm_GroupConfigType *LocalPwmGroupPtr; /* ROM pointer */
  uint8 ArrayLast;
  
  ErrStatus = E_OK;
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
  PBConfigStructure and is within allowed range.*/
  LocalPwmGroupPtr = (Pwm_kConfigPtr->GroupConfigPtr) + GroupId;
  ArrayLast = LocalPwmGroupPtr->MaxGroupChannels;
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    Duty cycle Array passed and is within allowed range.*/
  if (DutyCycle[ArrayLast] != LocalPwmGroupPtr->PwmDutyBufMarker)
  {
    ErrStatus = E_NOT_OK;
    /* Report an error */
    SafeMcal_ReportError ((uint16)PWM_17_GTM_MODULE_ID,
                              PWM_17_GTM_INSTANCE_ID,
                              ServiceID,PWM_E_PARAM_BUFFER_MARKER);
  }
  return ErrStatus;
} 
#endif
#endif

#define PWM_17_GTM_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
  allowed only for MemMap.h*/
#include "MemMap.h"

#define PWM_17_GTM_START_SEC_CALLOUT_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
  allowed only for MemMap.h*/
#include "MemMap.h"
/******************************************************************************
** Syntax :          void Pwm_17_Gtm_Isr  ( uint8 ChannelNumber )            **
**                                                                           **
** Service ID:       0x09                                                    **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       Depends on the implementation of Notification function  **
**                                                                           **
** Parameters (in):  ChannelNumber : PWM Channel number which caused the     **
**                                          interrpt                         **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : 1. This service will be used only in an interrupt           **
**               2. In this service depending on conditions Notification will**
**                   be provided                                             **
**                                                                           **
** Traceabilty      :                                                        **
** [cover parentID=DS_AS_PWM025] [/cover]                                    **
** [cover parentID=DS_AS_PWM026_PWM115c] [/cover]                            **
**                                                                           **
******************************************************************************/
void Pwm_17_Gtm_Isr(uint8 ChannelNumber)
{
  #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
  /* Even by mistake interrupt occurs for immediate update type,
     don't provide notification */
  const Pwm_17_Gtm_ChannelConfigType *LocalPwmChanPtr; /* ROM pointer */
  /* Here only notification has to be provided */
  Pwm_17_Gtm_ChannelType ChIndex;
  #if (PWM_SAFETY_ENABLE == STD_ON)
  uint8 ChSignal;
  uint8 ErrorFlag;
  #endif
  Pwm_17_Gtm_ChannelType PwmChannelnumber = ChannelNumber;
  #if (PWM_SAFETY_ENABLE == STD_ON)
  ErrorFlag = 0U;
  if( PwmChannelnumber > Pwm_kConfigPtr->MaxChannels)
  {
    /* Report Safety Error */
    SafeMcal_ReportError(
                          PWM_17_GTM_MODULE_ID,
                          PWM_17_GTM_INSTANCE_ID,
                          PWM_SID_ISR,
                          PWM_E_PARAM_CHANNEL
                         );
    ErrorFlag = 1U;
  }
  if(ErrorFlag == 0U)
  #endif
  {
    ChIndex = Pwm_lFindChannelIndex(PwmChannelnumber);
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
      PBConfigStructure and is within allowed range.*/
    LocalPwmChanPtr = (Pwm_kConfigPtr->ChannelConfigPtr) + PwmChannelnumber;
    #if (PWM_SAFETY_ENABLE == STD_ON)
    ChSignal=Pwm_lFindChannelSignal(PwmChannelnumber);
    if (ChSignal == PWM_ASIL_TYPE)
    {
      #if (PWM_MAX_ASIL_CHANNELS != 0)
      if ((Pwm_GlobChn_Asil[ChIndex] & PWM_NOTIFI_STATUS_MASK) ==
                       PWM_NOTIFI_STATUS_MASK)
      {
        /* PWM025: PWM035: Provide Notification */
        /* PWM032: Call back functions has no parameters */
        (LocalPwmChanPtr->Notification)();
      }
      else
      {
        SafeMcal_ReportError(
                             PWM_17_GTM_MODULE_ID,
                             PWM_17_GTM_INSTANCE_ID,
                             PWM_SID_ISR,
                             PWM_E_WRONG_NOTIF
                            );
      }
      #endif
    }
    else
    #endif
    {
      #if (PWM_MAX_QM_CHANNELS != 0)
      if ((Pwm_GlobChn_Qm[ChIndex] & PWM_NOTIFI_STATUS_MASK) ==
                       PWM_NOTIFI_STATUS_MASK)
      {
        /* PWM025: PWM035: Provide Notification */
        /* PWM032: Call back functions has no parameters */
        (LocalPwmChanPtr->Notification)();
      }
      #if (PWM_SAFETY_ENABLE == STD_ON)
      else
      {
        SafeMcal_ReportError(
                             PWM_17_GTM_MODULE_ID,
                             PWM_17_GTM_INSTANCE_ID,
                             PWM_SID_ISR,
                             PWM_E_WRONG_NOTIF
                            );
      }
      #endif
      #endif
    }
  }  /* PWM_NOTIFICATION_SUPPORTED */
  #else
  /* to remove unused param warning in GNU */
  UNUSED_PARAMETER(ChannelNumber)
  #endif
}

/* End of Pwm_17_Gtm_Isr() function */
#define PWM_17_GTM_STOP_SEC_CALLOUT_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
  allowed only for MemMap.h*/
#include "MemMap.h"

/***************** End of PWM driver module **********************************/

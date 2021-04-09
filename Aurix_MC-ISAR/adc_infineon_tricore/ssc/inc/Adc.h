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
**   $FILENAME   : Adc.h $                                                    **
**                                                                            **
**   $CC VERSION : \main\40 $                                                 **
**                                                                            **
**   $DATE       : 2016-03-23 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : This file contains                                         **
**                 - functionality of Adc driver.                             **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
**  TRACEABILITY: [cover parentID=DS_AS_ADC364,DS_AS40X_ADC001_PI,
DS_AS40X_ADC065_ADC269,DS_AS_ADC229,DS_NAS_ADC_PR746,SAS_NAS_ALL_PR748,
DS_NAS_ADC_PR734]                                                             **
**                                                                            **
**  This file contains functionality of ADC driver                            **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
*******************************************************************************/

#ifndef ADC_H
#define ADC_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
/* static configuration parameters for ADC  */
#include "Adc_Cfg.h"  
#if (ADC_DEV_ERROR_DETECT == STD_ON)
/* Import of DET functionality */
#include "Det.h"
#endif /* ADC_DEV_ERROR_DETECT */

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/*
  ADC030: Published parameters
*/

/* ADC Vendor ID */
#define ADC_VENDOR_ID                     ((uint16)17)

/* ADC module id 123 -> 0x7B */
#define ADC_MODULE_ID                     ((uint16)123)

#if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
/*
  ADC230, ADC065, ADC229: Development error values
*/
#if (ADC_DEV_ERROR_DETECT == STD_ON)
/* service is called without Adc Driver initialization */
#define ADC_E_UNINIT                   ((uint8)0x0A)

/* Start service is called while conversion is on going */
#define ADC_E_BUSY                     ((uint8)0x0B)

/* Stop service is called while no conversion is on going */
#define ADC_E_IDLE                     ((uint8)0x0C)

/* Initialization service called twice without deinit */
#define ADC_E_ALREADY_INITIALIZED      ((uint8)0x0D)

#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

/* Initialization service is called with configPtr as NULL*/
#define ADC_E_PARAM_CONFIG             ((uint8)0x0E)

/* Service is called with NULL_PTR  */
#define ADC_E_PARAM_POINTER            ((uint8)0x14)

/* Service is called with invalid group ID  */
#define ADC_E_PARAM_GROUP              ((uint8)0x15)

#if (ADC_DEV_ERROR_DETECT == STD_ON)
/* service is called for a group with wrong conversion mode */
#define ADC_E_WRONG_CONV_MODE          ((uint8)0x16)

/* service is called for a group with wrong trigger source */
#define ADC_E_WRONG_TRIGG_SRC          ((uint8)0x17)

/* Enable/disable notification function for a group whose configuration set 
   has no notification available */
#define ADC_E_NOTIF_CAPABILITY         ((uint8)0x18)

#if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
/* Conversion request service is called before initialising the result buffer */
#define ADC_E_BUFFER_UNINIT            ((uint8)0x19)
#endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */

#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

#if( (ADC_SAFETY_ENABLE == STD_ON) && (ADC_RESULT_POLLING_MODE == STD_ON) )
/* Service is called with invalid analog channel number  */
#define ADC_E_PARAM_CHANNEL            ((uint8)0x29)
#endif /*(ADC_SAFETY_ENABLE == STD_ON)&&(ADC_RESULT_POLLING_MODE == STD_ON)*/

#if( ADC_SAFETY_ENABLE == STD_ON )
/* Clock enable/disable failed during initisalization or de-initialization */
#define ADC_E_CLC_ERROR                ((uint8)0x2A)
/* Interrupt service with wrong interrupt source */
#define ADC_E_INTR_SRC_ERROR           ((uint8)0x2B)
#endif /*(ADC_SAFETY_ENABLE == STD_ON)*/

#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */

/* ADC068: No production errors reported by ADC driver */

/* API Service ID for Adc_Init() */
#define ADC_SID_INIT                              ((uint8)0x00)
#if (ADC_DEINIT_API == STD_ON)
/* API Service ID for Adc_DeInit() */
#define ADC_SID_DEINIT                            ((uint8)0x01)
#endif /* (ADC_DEINIT_API == STD_ON) */
/* API Service ID's */
#if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
/* API Service ID for Adc_StartGroupConversion() */
#define ADC_SID_START_GROUP_CONVERSION            ((uint8)0x02)
/* API Service ID for Adc_StopGroupConversion() */
#define ADC_SID_STOP_GROUP_CONVERSION             ((uint8)0x03)
/* API Service ID for Adc_ReadGroup() */
#define ADC_SID_READ_GROUP                        ((uint8)0x04)
/* API Service ID for Adc_EnableHardwareTrigger() */
#define ADC_SID_ENABLE_HARDWARE_TRIGGER           ((uint8)0x05)
/* API Service ID for Adc_DisableHardwareTrigger() */
#define ADC_SID_DISABLE_HARDWARE_TRIGGER          ((uint8)0x06)
/* API Service ID for Adc_EnableGroupNotification() */
#define ADC_SID_ENABLE_GROUP_NOTIFICATION         ((uint8)0x07)
/* API Service ID for Adc_DisableGroupNotification() */
#define ADC_SID_DISABLE_GROUP_NOTIFICATION        ((uint8)0x08)
/* API Service ID for Adc_GetGroupStatus() */
#define ADC_SID_GET_GROUP_STATUS                  ((uint8)0x09)
#if (ADC_DEV_ERROR_DETECT == STD_ON)
/* API Service ID for Adc_GetVersionInfo() */
#define ADC_SID_GET_VERSION_INFO                  ((uint8)0x0a)
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
/* API Service ID for Adc_GetStreamLastPointer() */
#define ADC_SID_GET_STREAM_LAST_POINTER           ((uint8)0x0b)
/* API Service ID for Adc_SetupResultBuffer() */
#define ADC_SID_SETUP_RESULT_BUFFER               ((uint8)0x0c)
#if (ADC_SAFETY_ENABLE == STD_ON)
/* API Service ID for Adc_lIsr() */
#define ADC_SID_ISR                               ((uint8)0x28)
#endif /* (ADC_SAFETY_ENABLE == STD_ON) */
#if (ADC_RESULT_POLLING_MODE == STD_ON)
/* API Service ID for Adc_17_GetGroupResult() */
#define ADC_SID_GET_GROUP_RESULT                  ((uint8)0x2e)
/* API Service ID for Adc_17_GetChannelStatus() */
#define ADC_SID_GET_CHANNEL_STATUS                ((uint8)0x2f)
#endif /* (ADC_RESULT_POLLING_MODE == STD_ON) */
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */

/* ADC MODULE INSTANCE ID */
#define ADC_MODULE_INSTANCE                       ((uint8)0) 

/* Adc Group Status */
#define ADC_IDLE                  ((Adc_StatusType)0)
#define ADC_BUSY                  ((Adc_StatusType)1)
#if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
#define ADC_COMPLETED             ((Adc_StatusType)2)
#endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */ 
#define ADC_STREAM_COMPLETED      ((Adc_StatusType)3)

/* Configuration Options: ADC_GROUP_ACCESS_MODE
   ADC317: Type of access mode to group conversion results. 
*/
/* Single value access mode */
#define ADC_ACCESS_MODE_SINGLE    ((Adc_GroupAccessModeType)0)
/* Streaming access mode */
#define ADC_ACCESS_MODE_STREAMING ((Adc_GroupAccessModeType)1U)

/*
  Configuration Options: ADC_STREAMING_BUFFER_MODE
  ADC316: Configure streaming buffer as "linear buffer" or as "ring buffer" 
*/
/* The ADC Driver stops the conversion as soon as the stream buffer is full */
#define ADC_STREAM_BUFFER_LINEAR   ((Adc_StreamBufferModeType)0)
/* The ADC Driver continue the conversion even if the stream buffer is full */
#define ADC_STREAM_BUFFER_CIRCULAR ((Adc_StreamBufferModeType)1) 

/*
  Configuration Options: ADC_GROUP_TRIGG_SRC
  ADC253: Type of source event that starts a group conversion
*/
/* ADC094: Group with this trigger source is started using API
   Adc_StartGroupConversion */
#define ADC_TRIGG_SRC_SW          ((Adc_TriggerSourceType)0)
/* AADC095: Group is triggered by a hardware event.
   Adc_EnableHardwareTrigger. Actual conversion starts when external event 
   happens */
/* Trigger event is by external trigger source */   
#define ADC_TRIGG_SRC_HW          ((Adc_TriggerSourceType)1)

/*
  Configuration Options: uC request source
  Macros for microcontroller request source definitions
*/
#define ADC_REQSRC0_8STG_QUE         ((uint8)0)
#define ADC_REQSRC1_NCH_SCAN         ((uint8)1)
#define ADC_REQSRC2_BGND_SCAN        ((uint8)2)
#define ADC_REQSRC3_8STG_QUE         ((uint8)3)

/*
  Configuration Options: ADC_GROUP_CONV_MODE
  Type of conversion mode supported by the driver.
*/
/* ADC001: The conversion of an ADC channel group is performed once 
   after a trigger. */
#define ADC_CONV_MODE_ONESHOT        ((Adc_GroupConvModeType)0)
/* ADC002: Conversions of an ADC channel group are performed continuously 
   after a software API call (start). */
#define ADC_CONV_MODE_CONTINUOUS     ((Adc_GroupConvModeType)1)

/*
  Configuration Options: Group Replacement mechanism
*/
/* Abort/Restart mechanism - The complete conversion round of the 
   interrupted group (all group channels) is restarted after the higher 
   priority group conversion is finished 
*/
#define ADC_GROUP_REPL_ABORT_RESTART  ((Adc_GroupReplacementType)0)
/* Suspend/Resume mechanism - The conversion round of the interrupted group 
   is completed after the higher priority group conversion is finished. 
*/
#define ADC_GROUP_REPL_SUSPEND_RESUME ((Adc_GroupReplacementType)1)

/*
  Configuration Options: ADC_HWUNIT_ID
  ADC HW Unit Id in a microcontroller
*/
#define ADC_HWUNIT_ADC0        ((Adc_HwUnitType)0)
#define ADC_HWUNIT_ADC1        ((Adc_HwUnitType)1)
#define ADC_HWUNIT_ADC2        ((Adc_HwUnitType)2)
#define ADC_HWUNIT_ADC3        ((Adc_HwUnitType)3)
#define ADC_HWUNIT_ADC4        ((Adc_HwUnitType)4)
#define ADC_HWUNIT_ADC5        ((Adc_HwUnitType)5)
#define ADC_HWUNIT_ADC6        ((Adc_HwUnitType)6)
#define ADC_HWUNIT_ADC7        ((Adc_HwUnitType)7)
#define ADC_HWUNIT_ADC8        ((Adc_HwUnitType)8)
#define ADC_HWUNIT_ADC9        ((Adc_HwUnitType)9)
#define ADC_HWUNIT_ADC10       ((Adc_HwUnitType)10)

/* Macros to define the Group Adc Emux Scan switch */
#define ADC_GROUP_EMUX_SCAN_ENABLE    (0x10U) 
#define ADC_GROUP_EMUX_SCAN_DISABLE   (0U)

#if (ADC_ERU_TRIGG == STD_ON)
/* Flag in ADC Group when it is triggered by ERU IOUT signal */
#define ADC_TRIG_ERU_SELECTED         (1U)
#endif /* (ADC_ERU_TRIGG == STD_ON) */
#define ADC_TRIG_ERU_NOT_SELECTED     (0U)

#if (ADC_ERU_GATING == STD_ON)
/* Flag in ADC Group when it is gated by ERU PDOUT signal */
#define ADC_GATE_ERU_SELECTED         (1U)
#endif /* (ADC_ERU_GATING == STD_ON) */

/*
  Configuration Options: ADC_HW_TRIG_SIGNAL
  Configures on which edge of the hardware trigger signal the Group should 
  start the conversion 
*/
/* React on the rising edge of the hardware trigger signal */
#define ADC_HW_TRIG_RISING_EDGE       ((Adc_HwTriggerSignalType)0x2U)
/* React on the falling edge of the hardware trigger signal */
#define ADC_HW_TRIG_FALLING_EDGE      ((Adc_HwTriggerSignalType)0x1U)
/* React on both edges of the hardware trigger signal */
#define ADC_HW_TRIG_BOTH_EDGES        ((Adc_HwTriggerSignalType)0x3U)

/*
  Configuration Options: ADC_CHANNEL_REF_VOLTSRC_HIGH
  ADC089: Upper reference voltage source for each channel.
*/
#define ADC_REF_VOLTAGE_VAREF         ((Adc_VoltageSourceType)0U)
#define ADC_REF_VOLTAGE_CH0           ((Adc_VoltageSourceType)0x1U)
/*
  Configuration Options: ADC_CHANNEL_REF_VOLTSRC_LOW
  ADC023: Lower reference voltage source for each channel.
*/
#define ADC_REF_VOLTAGE_VAGND         ((Adc_VoltageSourceType)0U)

/* 
  Configuration Options: ADC_CLK_SRC
  Hardware supports only system clock for the ADC module 
*/
#define ADC_CLK_SRC_SYS_CLK           ((Adc_ClockSourceType)1)

/*
  Configuration Options: ADC_CHANNEL_RESOLUTION
  ADC019: Channel resolution in bits.
*/
#define ADC_CH_RES_12BIT              ((Adc_ResolutionType)0x0U)
#define ADC_CH_RES_10BIT              ((Adc_ResolutionType)0x1U)
#define ADC_CH_RES_8BIT               ((Adc_ResolutionType)0x2U)

#if (ADC_MASTER_SLAVE_SYNC == STD_ON)
/* Channel enabled for synchronized conversion */
#define ADC_SYNC_CHANNEL              (1U)
#define ADC_MASTER                    (0U)
#endif /* (ADC_MASTER_SLAVE_SYNC == STD_ON) */

/* Safety signal macros */
#define ADC_ASIL_SIGNAL_0            (0U)
#define ADC_ASIL_SIGNAL_1            (1U)
#define ADC_QM_SIGNAL                (2U)

/* For reducing the complexity , simple forms of macros defined */
#if ((ADC_TIMER_TRIGG == STD_ON) || (ADC_ERU_TRIGG == STD_ON))
#define ADC_TIMER_ERU_TRIGG         (STD_ON)
#else
#define ADC_TIMER_ERU_TRIGG         (STD_OFF)
#endif /*(ADC_TIMER_TRIGG == STD_ON) || (ADC_ERU_TRIGG == STD_ON)*/

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/* Type definitions */

/*******************************************************************************
** Traceabilty      :[cover parentID=DS_AS_ADC_PR227,DS_AS_ADC085,
DS_AS_ADC_PR226,DS_AS_ADC_PR234,DS_AS_ADC_PR246,DS_AS_ADC_PR237,DS_AS_ADC_PR228,
DS_AS_ADC_PR241,DS_AS_ADC_PR239,DS_AS_ADC_PR242,DS_AS_ADC_PR245,DS_AS_ADC_PR230,
DS_AS_ADC_PR232,DS_AS_ADC_PR231,DS_AS_ADC_PR244,DS_AS_ADC_PR243,DS_AS_ADC_PR229,
DS_AS_ADC_PR235,DS_AS_ADC_PR236,DS_AS_ADC_PR238,DS_AS_ADC_PR233,DS_AS_ADC_PR225,
DS_AS_ADC_PR240]                                                              **
**[/cover]                                                                    **
*******************************************************************************/

/* 
  Numeric ID of an ADC channel.
  TC1797: AN0 - AN43 (Without EMUX)
*/
typedef uint8 Adc_ChannelType;

/* 
  Numeric ID of an ADC channel group.
  For each Adc Kernel, maximum of 32 channel groups are supported
*/
typedef uint16 Adc_GroupType;

/*
  converted values of a channel group 
  (raw, without further scaling, right aligned)
  ADC320: The dimensions of each buffer element
  Adc Driver supporting 8-, 10- and 12-bit resolution
  If all the configured channels are for 8-bit resolution, 
  the Adc_ValueGroupType will be uint8 else uint16
*/

#if (ADC_VALUE_GROUP_TYPE == ADC_VALUE_EIGHT_BIT)
typedef uint8  Adc_ValueGroupType;
#else
typedef uint16 Adc_ValueGroupType;
#endif

/*
  Type of clock input for ADC kernel to select different clock sources
  Aurix supports only system clock for ADC module (ADC_CLK_SRC_SYS_CLK)
*/
typedef uint8 Adc_ClockSourceType;

/*
  Type definition for ADC clock prescale type
  Divider Factor for Analog Internal Clock (fADCI)
  00H fADCI = fADC
  01H fADCI = fADC / 2
  02H fADCI = fADC / 3
  ...
  3FH fADCI = fADC / 64
  Divider Factor for Digital Arbiter Clock (fADCD)
  It is recommended to use the default setting 00B to
  obtain the minimum arbiter reaction time.
  00B fADCD = fADC
  01B fADCD = fADC / 2
  10B fADCD = fADC / 3
  11B fADCD = fADC / 4
*/
typedef uint32 Adc_PrescaleType;


/*
  The time during which the sampled analog value is converted into 
  digital representation by fADCI (Analog internal clock) which is already 
  configured as part of ClkPrescale
  Not supported by the hardware channel wise. It is globally controlled for 
  ADC HW unit
  This type is never used by ADC Driver
*/
typedef uint8 Adc_ConversionTimeType;

/*
  The time during which the value is sampled, (in clock-cycles)
  additional length of the sample phase, given in analog clock cycles fADCI.
  A minimum sample phase of 2 analog clock cycles is extended by the 
  programmed value.
  sample phase length = (2 + STC) / fADCI
*/
typedef uint8 Adc_SamplingTimeType;

/*
  Type of reference voltage source
  TC1797 supports fallowing reference voltage high 
  ADC_REF_VOLTAGE_VAREF
  ADC_REF_VOLTAGE_AN0 
  and only ADC_REF_VOLTAGE_VAGND reference voltage low 
*/
typedef uint8 Adc_VoltageSourceType;

/*
  Type of channel resolution in number of bits
  TC2Dx supports fallowing resolutions
  ADC_CH_RES_8BIT 
  ADC_CH_RES_10BIT
  ADC_CH_RES_12BIT
*/
typedef uint8 Adc_ResolutionType;

/*
  Current status of the conversion of the requested ADC Channel group
  Adc driver supports fallowing status
  ADC_IDLE
  ADC_BUSY
  ADC_COMPLETED
  ADC_STREAM_COMPLETED
*/
typedef uint8 Adc_StatusType;

/*
  Type for configuring the trigger source for an ADC Channel group
  Adc driver supports fallowing trigger source
  ADC_TRIGG_SRC_SW
  ADC_TRIGG_SRC_HW
*/
typedef uint8 Adc_TriggerSourceType;

/*
   Type for configuring the conversion mode of an ADC Channel group
   Adc driver supports the fallowing conversion mode
   ADC_CONV_MODE_ONESHOT
   ADC_CONV_MODE_CONTINUOUS
*/
typedef uint8 Adc_GroupConvModeType;

/*
  Priority level of the channel. Lowest priority is 0.
  Adc driver supports 32 priority levels which is equal to maximum number of
  groups on each ADC Kernel 
*/
typedef uint8 Adc_GroupPriorityType;

/*
  Type for configuring the prioritization mechanism. 
  Adc driver supports 3 priority levels
  ADC_PRIORITY_NONE 
  ADC_PRIORITY_HW   
  ADC_PRIORITY_HW_SW
*/
/* typedef uint8 Adc_ChannelRangeSelectType; */

/*
  Type of channel range select
*/

typedef enum
{
  ADC_RANGE_UNDER_LOW = 0xAU,
  ADC_RANGE_BETWEEN = 0x1U,
  ADC_RANGE_OVER_HIGH = 0x6U,
  ADC_RANGE_ALWAYS = 0x3U,
  ADC_RANGE_NEVER = 0x0U,
  ADC_RANGE_NOT_UNDER_LOW = 0x9U,
  ADC_RANGE_NOT_BETWEEN = 0x2U,
  ADC_RANGE_NOT_OVER_HIGH = 0x5U
  
}Adc_ChannelRangeSelectType;

/*
  Type for Alignment of ADC Raw results in ADC result buffer
*/
typedef uint8 Adc_ResultAlignmentType;

/*
  Type for configuring the prioritization mechanism
*/
typedef uint8 Adc_PriorityImplementationType;

/*
  Type for assignment of channels to a channel group
  Pointer to the array of channel ID in a group
  First element being the number of channels in Group
*/
typedef Adc_ChannelType Adc_GroupDefType;

/*
  Type for the number of samples of a streaming conversion buffer
*/
typedef uint8 Adc_StreamNumSampleType;

/*
  Numeric ID of an ADC Hw Unit
*/
typedef uint8 Adc_HwUnitType;

/*
  Type for configuring the streaming access mode buffer type.
  ADC driver supports the fallowing buffer types
  ADC_STREAM_BUFFER_LINEAR
  ADC_STREAM_BUFFER_CIRCULAR
*/
typedef uint8 Adc_StreamBufferModeType;

/*
  Type for configuring the access mode to group conversion results
  ADC driver supports the fallowing result access mode
  ADC_ACCESS_MODE_SINGLE
  ADC_ACCESS_MODE_STREAMING
*/
typedef uint8 Adc_GroupAccessModeType;

/*
  Type for configuring Trigger pin and on which edge of the 
  hardware trigger signal the driver should reach, i.e. start the conversion 
  ADC driver supports the fallowing trigger edges
  ADC_HW_TRIG_RISING_EDGE
  ADC_HW_TRIG_FALLING_EDGE
  ADC_HW_TRIG_BOTH_EDGES
*/
typedef uint32 Adc_HwTriggerSignalType;

/*
  Type for the Timer trigger type
*/
typedef uint32 Adc_HwTriggerTimerType;

/* 
  Type for Trigger source Arbitration level values 
  00B Lowest priority is selected.
  ...
  11B Highest priority is selected.
*/
typedef uint32 Adc_TriggSrcArbLevelType;

/* Type for Group level replacement nechanism. When Group is interrupted by 
   higher priorty, Group channel conversion can be handled by the
   configuration as:
   ADC_GROUP_REPL_ABORT_RESTART
   ADC_GROUP_REPL_SUSPEND_RESUME
*/
typedef uint8 Adc_GroupReplacementType;

/* Gtm Channel Identifier Type */
typedef struct
{
  /* MODULE_ID   MODULE_NO  TGC_AGC_NO  */
  /*  2 bits      4 bits     2 bits     */
  uint8 ModuleId;
  uint8 ChannelNo;       /* Specifies the Channel Number       */
}Adc_GtmChIdentifierType;


/*
  Type definition for each ADC HW unit Trigger source data
  Group ID indicating the group requested in the particular 
  HW Trigger source
  GrpLastChannel indicating the lowest channel number of that group 
*/
typedef struct Adc_TriggSrcData
{
  /* Group ID indicating the group requested in the particular 
     HW Trigger source
  */
  Adc_GroupType   GrpId;
  
  /* priority level of the Group */
  Adc_GroupPriorityType GrpPriority;

  /* Trigger source service request flag */
  uint8  IsrDoNothing;

  #if (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR)
  /* Least analog channel of the Group */
  Adc_ChannelType GrpLastChannel;
  #endif /* (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR) */

}Adc_TriggSrcDataType;

#if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
/*
  Type definition for the Groups which are enabled in the 
  ADC HW unit request source
  Added for the optimisation of ISR
*/

typedef struct Adc_GroupData
{
  /* Group channels in a sequence as configured
     Maximum number of channels in a group can be 16
  */
  Adc_ChannelType   GrpChannels[16];
  
  /* Resolution of each channels in a group  */
  uint8 GrpChannelRes[16];

  #if( ADC_MASTER_SLAVE_SYNC == STD_ON )
  /* Synch channels in a group */
  Adc_ChannelType   GrpSynchCh[8];

  /* No of Sync channels in a group  */
  uint8 NoOfSynchCh;
  #endif /* ( ADC_MASTER_SLAVE_SYNC == STD_ON ) */
  
}Adc_GroupDataType;
#endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */

#if (ADC_ENABLE_QUEUING == STD_ON)

typedef struct Adc_QueueData
{
  /* This variable will give the Group ID which is previous in the Queue */ 
  Adc_GroupType      PreviousGroup;

  /* This variable will give the Group ID which is Next in the Queue */ 
  Adc_GroupType      NextGroup;

}Adc_QueueDataType;

#endif /* (ADC_ENABLE_QUEUING == STD_ON) */

#if (ADC_GROUP_EMUX_SCAN == STD_ON)
typedef struct Adc_DmaData
{
  /* Number of DMA transfer for Group */
  /* Configure in DMA_CHCR.TREL - no. of transfer on each ADC trigger */
  uint32                  DmaUpdateCount;

  /* Flag to determine if ADC-DMA is in use or not */
  uint8                   DmaUse;

  /* Group which uses EMUX SCAN */
  Adc_GroupType           Group;

}Adc_DmaDataType;

#endif /* (ADC_GROUP_EMUX_SCAN == STD_ON) */


typedef struct Adc_GlobalData
{
  #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
  /* Array of Pointers which stores the Group Result buffer starting location 
     on Adc_SetupResultBuffer
  */
  Adc_ValueGroupType* GroupResultBuffer[ADC_MAX_GROUPS];
  
  #endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */

  #if (ADC_GROUP_EMUX_SCAN == STD_ON)
  
  Adc_DmaDataType DmaData;
  
  #endif /* (ADC_GROUP_EMUX_SCAN == STD_ON) */
  
  /* Variable to Hold Group Status */
  uint32 GroupStatus;
  
  /* Variable to Hold Group Result Status*/
  uint32 GroupResultStatus;
  
  /*Variable which states the buffer is full with valid results for each group*/
  uint32 GrpBufferEndResultStatus;
  
  #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
  /* Notification status for all the groups, maximum 32 groups 
    Bit 0: Status of Adc channel group 0
    Bit 1: Status of Adc Channel group 1
    ...
    ...
    Bit 31: Status of Adc Channel group 31
  */
  uint32 GrpNotifStatus;
  #endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
  
  #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Mask for all running internal channels */
  /* Used to Check if any channels in different HW Trigger source are  
     overlapping with the requested group channels
  */
  uint16 AllRunningCh;
  #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
  #endif /* (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) */

  /* Aurix request source related data */
  Adc_TriggSrcDataType TriggSrcData[ADC_REQSRC_COUNT];
  
  
  #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
  /* Group data which is enabled in the RS */
  Adc_GroupDataType RsGroupData[ADC_REQSRC_COUNT];
  #endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */

  #if (ADC_ENABLE_QUEUING == STD_ON)
  /* Array of Queue information 
     Each Element will give the Corresponding Group ID information.
     If Group enters Queue, the element of array at Group ID index will hold 
     Previous and next Group in the Queue.
     If Group is the first entery in Queue, then its PreviousGroup is 
     set to ADC_INVALID_GROUP_ID.
     If Group is the last entery in Queue, then its NextGroup is 
     set to ADC_INVALID_GROUP_ID.
     If Group is not enetred the Queue, its Previous and Next Group is set to
     ADC_INVALID_GROUP_ID.
  */
  Adc_QueueDataType QueueOfSwGroup[ADC_MAX_GROUPS];
  
  /* Group Id which will be taken for conversion from Queue */
  Adc_GroupType PopGroupId;
  
  /* Group Id which is last in the Queue */
  Adc_GroupType PushGroupId;
  #endif /* (ADC_ENABLE_QUEUING == STD_ON) */

  #if (ADC_USE_EMUX == STD_ON)
  /* variable for each Kernel to specify which Group is enabled for EMUX */
  Adc_GroupType EmuxGroup;
  #endif /* (ADC_USE_EMUX == STD_ON) */

  #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
  /* Group which uses Limit checking */
  Adc_GroupType  LimitChkGroup;
  #endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  
  #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
  /* Number of conversion result set available for each Adc channel group 
     in the each kernel
     The array elements will be initialized to 0
     Array element will be incremented on each conversion completion
     Put into reset state on stop conversion by Stop API or Disable API
     and also when the buffer has reached full.
  */  
  Adc_StreamNumSampleType NumValidConRes[ADC_MAX_GROUPS];
  #endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */

  
}Adc_GlobalDataType;


#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
/* Type definition for ADC notification function pointer */
typedef void (*Adc_NotifFctPtrType)(void);
#endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

/*
  ADC242: Type definition for AdcHWUnitConfiguration 
*/
typedef struct Adc_HwUnitCfgType
{
  /* Arbitration Round Length: 00b - 11b
     ANON : 11b
     ARBM : 1b
  */
  uint32 ArbitrationLength;
  
  /* Request source arbitration level control */
  Adc_TriggSrcArbLevelType TriggSrcArbLevel;

  /*Kernel Input class configuration */
  uint32 KernelInputClass[2];

  /* Kernel mode for parallel sampling */
  uint8 SyncConvMode;
  
  /* Ready signal of Slave kernel */
  uint8 SlaveReady;
  
  /* IFX_ADC029: Selection DMA channel in Non AUTOSAR result handling */
  uint8 DmaChannel;

#if (ADC_SAMPLE_HOLD_UNIT == STD_ON)
  /* Enhanced conversion timing */
  uint8 AcceleratedTiming;
  
  /* Duration of the sample phase */
  uint8 ShortSampleTime;
#endif /* (ADC_SAMPLE_HOLD_UNIT == STD_ON) */

#if ( ADC_SAFETY_ENABLE == STD_ON )
  /* ASIL or QM signal */
  uint8 SignalType;
#endif /*( ADC_SAFETY_ENABLE == STD_ON ) */ 
  
}Adc_HwUnitCfgType;

/* ADC028: Type definition for AdcGroupConfiguration */
typedef struct Adc_GroupCfgType
{

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
  /* ADC079: ADC081: ADC084: ADC085: ADC104: Notification function pointer */
  Adc_NotifFctPtrType NotifFctPtr;
#endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

  /* ADC090: Pointer to assignment of channels to a channel group */
  /* First element is the number of configured channels in the group */
  const Adc_GroupDefType* GroupDefinition;

#if (ADC_HW_TRIGGER_API == STD_ON)  
  /* Selection of external pin and trigger edge if group is 
     configured for HW external trigger */
  /* Selection of Timer if group is configured for HW Timer trigger */
  uint32 HwTrigConfig;
  /* If Timer request is selected, configure for reload value */
  uint32 HwTimerValue;
  /* If Timer request is selected, configured Timer module and channel */
  uint32 HwTimerChannel;
  /* Selection of external pin and gate edge if group is 
     configured for HW external trigger */
  uint32 HwGateConfig;
  #if (ADC_REQSRC3_AVAILABLE == STD_ON)  
  /* Initial value of the Trigger Sequence Counter TSC */
  uint32 TrigSeqCount;
  /* Request Source 3 Internal Trigger */
  uint32 Rs3IntTrigger;
  #endif /* (ADC_REQSRC3_AVAILABLE == STD_ON) */ 
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

  /* Internal channel mask from group definition - derived from the tool */
  uint16 IntChMask;
  
#if ( ADC_SAFETY_ENABLE == STD_ON )
  /* Group Buffer Marker value*/
  Adc_ValueGroupType BufferMarker;
#endif /* ( ADC_SAFETY_ENABLE == STD_ON ) */
    
  /* Group trigger source type : SW / HW */
  Adc_TriggerSourceType TriggSrc;

  /* Group request source as in uC: RS0 - RS2 */
  uint8 GrpRequestSrc;

  /* Group conversion mode */
  Adc_GroupConvModeType ConvMode;

#if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) 
  /* Number of ADC values to be acquired in streaming access mode */
  Adc_StreamNumSampleType NumSamples;
  
  /* ADC316: Buffer mode type - Configure streaming buffer as 
     "linear buffer" or "ring buffer" */
  Adc_StreamBufferModeType StreamBufferMode;

/* ADC315: Switcing of Priority mechanism */
#if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)
  /* ADC289: Priority level of the group */
  Adc_GroupPriorityType PriorityLevel;

  /* ADC431: Group level Replacement mechanism - 
     Selection of Abort/Restart or Suspend/Resume mechanism.
     Vaild only when Group is interruptable
  */
  Adc_GroupReplacementType GroupReplacement;
#endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) */
#endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */

#if (ADC_USE_EMUX == STD_ON)
  /* Group EMUX data */
  uint8  GroupEmuxData;
#endif /* (ADC_USE_EMUX == STD_ON) */
  
} Adc_GroupCfgType;

/* ADC268: Type definition for AdcChannelConfiguration 
   Will accommodate Input Class selection, Reference voltage, 
   Adc Channel number (Used to derive Internal channel no, 
   Internal ADC HW Group no, and EMUX settings) 
*/
typedef  struct Adc_ChannelCfgType
{
  /* configuration of analog channel */
  uint32 AdcChConfigValue;
  
  /* configuration of channel result accumulation */
  uint32 AdcChResAccumulation;

  /* channel limit checking enabled or not */
  uint32 AdcIsChLimitChkEnabled;
  
  /* Range of the limit check */
  uint32 AdcLimitChkRange;
  
  /* boundary values limit check */
  uint32 AdcLimitChkBnd;
  
  /* register from where the boundary value is selected in
  standard compare mode */
  uint32 AdcChBndSelxValue;

  /* Sync conversion enabled/disabled for the channel */
  uint8 AdcSyncChannel;
  
} Adc_ChannelCfgType;

/* ADC Kernel configuration structure */
typedef  struct Adc_KernelConfigType
{
  /* Pointer to Adc Hw Unit configuration */
  const Adc_HwUnitCfgType  *HwCfgPtr;
  
  /* Pointer to the array of channel configuration */
  const Adc_ChannelCfgType *ChCfgPtr;
  
  /* Pointer to the array of group configuration */
  const Adc_GroupCfgType   *GrpCfgPtr;

#if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)
  /* Pointer to the array of Group mask for SW trigger sources */
  const uint32             *TriggSrcGroupMask;
#endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) */
  
  /* Total number of configured groups - Maximum 32 groups for each 
     ADC HW Unit 
  */
  uint8                    TotCfgGrps;
} Adc_KernelConfigType;

/* ADC global configuration structure */
typedef  struct Adc_GlobalCfgType
{
  /* ADC088: Module Clock control: 
     Divider Factor for Analog Internal Clock (fADCI)
     Divider Factor for Digital Arbiter Clock (fADCD)
  */
  Adc_PrescaleType ClkPrescale;
  
  /*Global Input class configuration */
  uint32 GlobInputClass[2];

  /* Control of post calibration */
  uint32 PostCalEnable;

  #if (ADC_USE_EMUX == STD_ON)
  /*EMUX select group configuration */
  uint32 EmuxSelectGrp;
  #endif /* (ADC_USE_EMUX == STD_ON) */

  #if (ADC_SAMPLE_HOLD_UNIT == STD_OFF)
  /* Low Power Supply voltage of the system to Adjust the analog circuitry */
  uint32 LowPowerSupply;
  /* Reference pre charge control of the converter */
  uint32 RefPrechargeCtrl;
  #endif /* (ADC_SAMPLE_HOLD_UNIT == STD_OFF) */

  #if (ADC_CCU6_SYNCHRONIZATION == STD_ON)
  /* T13 prescaler and clock configuration */
  uint32 T13Clock;
  /* routing output signal to CCU6061 TRIG1 */
  uint32 TrigSel;
  /* T13 period value */
  uint16 PeriodValue;
  /* T13 duty value */
  uint16 DutyValue;
  /* selected ccu6 kernel */
  uint8 Ccu6Kernel;
  #endif /* (ADC_CCU6_SYNCHRONIZATION == STD_ON) */
  
  /* Operating Mode of the converter */
  uint8 OperationMode;

  #if (ADC_SAMPLE_HOLD_UNIT == STD_ON)
  /* frequency of the clock for the SHS logic */
  uint8 SampleHoldClk;

  /* Calibration order of the converter */
  uint8 CalibrationOrder;

  /* maximum time until the next calibration */
  uint8 CalMaxTime;

  #if (ADC_ALTERNATE_REF_MODE == ADC_REF_GLOBAL_MODE)
  /* S&H unit whose alternate reference is be used within the cluster */
  uint8 AltRefDef[ADC_MAX_SHS_CLUSTERS];
  #endif /* (ADC_ALTERNATE_REF_MODE == ADC_REF_GLOBAL_MODE) */
  #endif /* (ADC_SAMPLE_HOLD_UNIT == STD_ON) */

} Adc_GlobalCfgType;

/* ADC054: ADC driver configuration for initializing the ADC Driver */
typedef  struct Adc_ConfigType
{
#if ( ADC_SAFETY_ENABLE == STD_ON )
  /* Configuration Marker value */
  uint32 CfgMarker;
#endif /* ( ADC_SAFETY_ENABLE == STD_ON ) */
  /* Pointer to ADC0 Hw Unit configuration */
  const Adc_KernelConfigType  *CfgPtr[ADC_MAX_KERNELS];

  /* Pointer to the Global configuration of all ADC Hw */
  const Adc_GlobalCfgType *GlobCfgPtr;

  /* Module sleep mode control */
  uint8 SleepMode;

} Adc_ConfigType;

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
#define ADC_START_SEC_POSTBUILDCFG
#include "MemMap.h"
/* Declaration of Adc Post Build Configuration */
extern const Adc_ConfigType Adc_ConfigRoot[ADC_CONFIG_COUNT];

#define ADC_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
#define ADC_START_SEC_CODE
#include "MemMap.h"
  
/*******************************************************************************
** Syntax           : extern void Adc_Init                                    **
**                    (                                                       **
**                      const Adc_ConfigType *ConfigPtr                       **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x00                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : ConfigPtr - Pointer to ADC configuration Set            **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - ADC054: This service shall initialize the ADC hardware unit and driver **
**             according to the configuration set referenced by ConfigPtr.    **
**   - ADC056: This function shall only initialize the configured resources.  **
**   - ADC077: notifications and hardware trigger capability shall be         **
**             disabled after module initialization                           **
**   - ADC107: This function should be called first in order to initialize    **
**     the ADC driver for use                                                 **
*******************************************************************************/
extern void Adc_Init
(
  const Adc_ConfigType *ConfigPtr
);

#if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
/*******************************************************************************
** Syntax           : extern Std_ReturnType Adc_SetupResultBuffer             **
**                    (                                                       **
**                      Adc_GroupType Group,                                  **
**                      Adc_ValueGroupType* DataBufferPtr                     **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x0C                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters(in)   : Group ID and Data buffer pointer                        **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK/E_NOT_OK                                           **
**                                                                            **
** Description      : This function:                                          **
**   - ADC420:  The function shall initialize the result buffer pointer       **
**              of the selected group with the address value                  **
**              passed as parameter.                                          **
**   - ADC421, ADC422 :  The ADC module's environment shall ensure that       **
**              result buffer are initialised before group conversions and    **
**              has size to hold streaming result if configured               **
**   - ADC423 : Checks for DET: ADC_E_PARAM_GROUP                             **
**   - Checks for DET: ADC_E_BUSY                                             **
*******************************************************************************/
extern Std_ReturnType Adc_SetupResultBuffer
(
  Adc_GroupType Group,
  Adc_ValueGroupType* DataBufferPtr 
);
#endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */

/* Enable/Disable the use of the function */
#if (ADC_DEINIT_API == STD_ON)
/*******************************************************************************
** Syntax           : extern void Adc_DeInit                                  **
**                    (                                                       **
**                      void                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x01                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - ADC110: This service shall return all ADC HW Units to a state          **
**             comparable to their power on reset state.                      **
**   - ADC111: The service shall disable all used interrupts and notifications**
**   - ADC077: notifications and hardware trigger capability shall be         **
**             disabled after module initialization                           **
**   - This service shall not be called while a conversion is ongoing.        **
**   - ADC228: This function shall available only if configuration parameter: **
**             ADC_DEINIT_API is switched On                                  **
*******************************************************************************/
extern void Adc_DeInit
(
  void
);
#else

#define Adc_DeInit() ERROR_Adc_DeInit_NOT_SELECTED 
                             
#endif /* (ADC_DEINIT_API == STD_ON) */

/* Enable/Disable the use of the function */
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/*******************************************************************************
** Syntax           : extern void Adc_StartGroupConversion                    **
**                    (                                                       **
**                      Adc_GroupType Group                                   **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x02                                                    **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : re-entrant                                              **
**                                                                            **
** Parameters(in)   : Group - Numeric ID of requested ADC Channel group.      **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - ADC061: This service shall start the conversion of all channels of the **
**             requested ADC Channel group.                                   **
**   - ADC146: This service can only be used for groups configured in software**
**             trigger mode ADC_GROUP_CONV_MODE                               **
**   - ADC259: This function shall available only if configuration parameter: **
**             ADC_ENABLE_START_STOP_GROUP_API is switched On                 **
*******************************************************************************/
extern void Adc_StartGroupConversion
(
  Adc_GroupType Group
);
#else

/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to generate compile time
 error in case of incorrect configuration*/
#define Adc_StartGroupConversion(Group) \
(ERROR_Adc_StartGroupConversion_NOT_SELECTED) 
                             
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

/* Enable/Disable the use of the function */
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/*******************************************************************************
** Syntax           : extern void Adc_StopGroupConversion                     **
**                    (                                                       **
**                      Adc_GroupType Group                                   **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x03                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : re-entrant                                              **
**                                                                            **
** Parameters(in)   : Group - Numeric ID of requested ADC Channel group.      **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - ADC072: This service shall stop the conversion of the requested ADC    **
**             Channel group.                                                 **
**   - ADC155: Stopping a group conversion shall automatically disable group  **
**             notification for the requested group.                          **
**   - ADC283: This service can only be used for groups configured in software**
**             trigger mode ADC_GROUP_CONV_MODE                               **
**   - ADC260: This function shall available only if configuration parameter: **
**             ADC_ENABLE_START_STOP_GROUP_API is switched On                 **
*******************************************************************************/
extern void Adc_StopGroupConversion
(
  Adc_GroupType Group
);
#else

/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to generate compile time
 error in case of incorrect configuration*/
#define Adc_StopGroupConversion(Group) \
(ERROR_Adc_StopGroupConversion_NOT_SELECTED) 
                             
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

#if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
#if (ADC_READ_GROUP_API == STD_ON)
/*******************************************************************************
** Syntax           : extern Std_ReturnType Adc_ReadGroup                     **
**                    (                                                       **
**                      Adc_GroupType Group                                   **
**                      Adc_ValueGroupType *DataBufferPtr                     **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x04                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : re-entrant                                              **
**                                                                            **
** Parameters(in)   : Group - Numeric ID of requested ADC Channel group.      **
**                                                                            **
** Parameters (out) : DataBufferPtr - Location to store the requested Group's **
**                    channels conversion result                              **
**                                                                            **
** Return value     : E_OK - Read command is accepted                         **
**                    E_NOT_OK - Read command is not accepted, or DET occurred**
**                                                                            **
** Description      : This function:                                          **
**   - ADC075: Adc_ReadGroup is a service for reading the latest available    **
**             conversion results of the requested group.                     **
**   - ADC113: The Adc_ReadGroup service shall return the raw converted values**
**             without further scaling.                                       **
**             The returned values shall be right-aligned.                    **
**   - ADC329, ADC330, ADC331: Reading the Group result will change the       **
**             Group status                                                   **
*******************************************************************************/
extern Std_ReturnType Adc_ReadGroup
(
    Adc_GroupType Group,
    Adc_ValueGroupType *DataBufferPtr 
);
#else

/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to generate compile time
 error in case of incorrect configuration*/
#define Adc_ReadGroup(Group,DataBufferPtr) \
(ERROR_Adc_ReadGroup_NOT_SELECTED) 
                             
#endif /* (ADC_READ_GROUP_API == STD_ON) */
#endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */

/* Enable/Disable the use of the function */
#if (ADC_HW_TRIGGER_API == STD_ON)
/*******************************************************************************
** Syntax           : extern void Adc_EnableHardwareTrigger                   **
**                    (                                                       **
**                      Adc_GroupType Group                                   **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x05                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : re-entrant                                              **
**                                                                            **
** Parameters(in)   : Group - Numeric ID of requested ADC Channel group.      **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - ADC114: This service shall enable the hardware trigger for the         **
**             requested ADC Channel group.                                   **
**   - ADC120: This service can only be used for groups configured in hardware**
**             trigger mode ADC_GROUP_TRIGG_SRC                               **
**   - ADC265: This function shall available only if configuration parameter: **
**             ADC_HW_TRIGGER_API is switched On                              **
*******************************************************************************/
extern void Adc_EnableHardwareTrigger
(                             
  Adc_GroupType Group         
);                             
#else

/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to generate compile time
 error in case of incorrect configuration*/
#define Adc_EnableHardwareTrigger(Group) \
(ERROR_Adc_EnableHardwareTrigger_NOT_SELECTED) 
                             
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

/* Enable/Disable the use of the function */
#if (ADC_HW_TRIGGER_API == STD_ON)
/*******************************************************************************
** Syntax           : extern void Adc_DisableHardwareTrigger                  **
**                    (                                                       **
**                      Adc_GroupType Group                                   **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x06                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : re-entrant                                              **
**                                                                            **
** Parameters(in)   : Group - Numeric ID of requested ADC Channel group.      **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - ADC116: This service shall disable the hardware trigger for the        **
**             requested ADC Channel group.                                   **
**   - ADC145: If applicable, an ongoing conversion shall be aborted.         **
**   - ADC157: If enabled, this function shall also disable the notification  **
**             mechanism for the requested group.                             **
**   - ADC121: This service can only be used for groups configured in hardware**
**             trigger mode ADC_GROUP_TRIGG_SRC                               **
**   - ADC266: This function shall available only if configuration parameter: **
**             ADC_HW_TRIGGER_API is switched On                              **
*******************************************************************************/
extern void Adc_DisableHardwareTrigger
(                             
  Adc_GroupType Group         
);
#else

/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to generate compile time
 error in case of incorrect configuration*/
#define Adc_DisableHardwareTrigger(Group) \
(ERROR_Adc_DisableHardwareTrigger_NOT_SELECTED) 
                             
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

/* Enable/Disable the use of the function */
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
/*******************************************************************************
** Syntax           : extern void Adc_EnableGroupNotification                 **
**                    (                                                       **
**                      Adc_GroupType Group                                   **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x07                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : re-entrant                                              **
**                                                                            **
** Parameters(in)   : Group - Numeric ID of requested ADC Channel group.      **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - ADC057: This service shall enable the notification mechanism for the   **
**             requested ADC Channel group.                                   **
**   - ADC100: This function shall available only if configuration parameter: **
**             ADC_GRP_NOTIF_CAPABILITY is switched On                        **
*******************************************************************************/
extern void Adc_EnableGroupNotification
(                             
  Adc_GroupType Group         
);                             
#else

/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to generate compile time
 error in case of incorrect configuration*/
#define Adc_EnableGroupNotification(Group) \
(ERROR_Adc_EnableGroupNotification_NOT_SELECTED) 
                             
#endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

/* Enable/Disable the use of the function */
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
/*******************************************************************************
** Syntax           : extern void Adc_DisableGroupNotification                **
**                    (                                                       **
**                      Adc_GroupType Group                                   **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x08                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : re-entrant                                              **
**                                                                            **
** Parameters(in)   : Group - Numeric ID of requested ADC Channel group.      **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - ADC058: This service shall disable the notification mechanism for the  **
**             requested ADC Channel group.                                   **
**   - ADC101: This function shall available only if configuration parameter: **
**             ADC_GRP_NOTIF_CAPABILITY is switched On                        **
*******************************************************************************/
extern void Adc_DisableGroupNotification
(                             
  Adc_GroupType Group         
);                             
#else

/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to generate compile time
 error in case of incorrect configuration*/
#define Adc_DisableGroupNotification(Group) \
(ERROR_Adc_DisableGroupNotification_NOT_SELECTED) 
                             
#endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

/*******************************************************************************
** Syntax           : extern Adc_StatusType Adc_GetGroupStatus                **
**                    (                                                       **
**                      Adc_GroupType Group                                   **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x09                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : re-entrant                                              **
**                                                                            **
** Parameters(in)   : Group - Numeric ID of requested ADC Channel group.      **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Adc_StatusType                                          **
**                    Conversion status for the requested group               **
**                                                                            **
** Description      : This function:                                          **
**   - AADC220: This service shall return the conversion status: ADC_IDLE /   **
**              ADC_BUSY / ADC_COMPLETED of the requested ADC Channel group   **
**   - ADC307: After Adc_Init all groups are in ADC_IDLE state.               **
**   - ADC308: Adc_StopGroupConversion or Adc_DisableHardwareTrigger is       **
**             called successfully, the group status shall be set to ADC_IDLE.**
*******************************************************************************/
extern Adc_StatusType Adc_GetGroupStatus
(                             
  Adc_GroupType Group         
);                             

#if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
/*******************************************************************************
** Syntax           : extern Adc_StreamNumSampleType Adc_GetStreamLastPointer **
**                    (                                                       **
**                      Adc_GroupType Group                                   **
**                      Adc_ValueGroupType** SamplePtr                        **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x0b                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : re-entrant                                              **
**                                                                            **
** Parameters(in)   : Group - Numeric ID of requested ADC Channel group.      **
**                                                                            **
** Parameters (out) : SamplePtr - Pointer to the last acquired value.         **
**                                                                            **
** Return value     : Adc_StreamNumSampleType                                 **
**                    Number of valid samples per channel.                    **
**                                                                            **
** Description      : This function:                                          **
**   - ADC214: This service shall return the pointer to the last converted    **
**             value. All values stored in the buffer are left without further**
**             scaling.                                                       **
**   - ADC215: Asking for a group buffer pointer prior to starting the        **
**             conversion of the group, will return a default value null.     **
**   - ADC216: Asking for a group buffer pointer while a conversion of the    **
**             group is in progress will return null                          **
*******************************************************************************/
extern Adc_StreamNumSampleType Adc_GetStreamLastPointer
(                                               
  Adc_GroupType Group,                           
  Adc_ValueGroupType** PtrToSamplePtr              
);                                                                    
#endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */

/*******************************************************************************
** Traceabilty      :[cover parentID=DS_AS_ADC376,DS_AS_ADC458,DS_AS_ADC236,
                     DS_AS_ADC237]
** Syntax           : #define Adc_GetVersionInfo(versioninfo)                 **
**[/cover]                                                                    **
**                                                                            **
** Service ID       : 0x0a                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : versioninfo                                             **
**                    Pointer to where to store the version information of    **
**                    this module                                             **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - ADC236: This service returns the version information of this module.   **
**   - ADC237: This function shall available only if configuration parameter: **
**             ADC_VERSION_INFO_API is switched On                            **
*******************************************************************************/
#if( (ADC_VERSION_INFO_API == STD_ON) && (ADC_DEV_ERROR_DETECT == STD_ON ) )
/*IFX_MISRA_RULE_19_07_STATUS=GetVersionInfo is declared as a function like 
 macro as per AUTOSAR*/
/*IFX_MISRA_RULE_19_04_STATUS=GetVersionInfo cannot be expand to a braced 
 initialiser*/
#define Adc_GetVersionInfo(versioninfo)                                        \
{                                                                              \
  /* ADC458: Check for DET: ADC_E_PARAM_POINTER */                             \
  if ((versioninfo) == NULL_PTR)                                               \
  {                                                                            \
    /* ADC458: Reporting of error ADC_E_PARAM_POINTER */                       \
    Det_ReportError((uint16)ADC_MODULE_ID,                                     \
                    ADC_MODULE_INSTANCE,                                       \
                    ADC_SID_GET_VERSION_INFO,                                  \
                    ADC_E_PARAM_POINTER                                        \
                   );                                                          \
  }                                                                            \
  else                                                                         \
  {                                                                            \
    /* ADC236 to retirve the id's of ADC driver */                             \
    ((Std_VersionInfoType*)(versioninfo))->moduleID = ADC_MODULE_ID;           \
    ((Std_VersionInfoType*)(versioninfo))->vendorID = ADC_VENDOR_ID;           \
    ((Std_VersionInfoType*)(versioninfo))->sw_major_version =                  \
                                                  (uint8)ADC_SW_MAJOR_VERSION; \
    ((Std_VersionInfoType*)(versioninfo))->sw_minor_version =                  \
                                                  (uint8)ADC_SW_MINOR_VERSION; \
    ((Std_VersionInfoType*)(versioninfo))->sw_patch_version =                  \
                                                  (uint8)ADC_SW_PATCH_VERSION; \
  }                                                                            \
}                                                                              
#elif( (ADC_VERSION_INFO_API == STD_ON) && (ADC_DEV_ERROR_DETECT == STD_OFF) )
/*IFX_MISRA_RULE_19_07_STATUS=GetVersionInfo is declared as a function like 
 macro as per AUTOSAR*/
/*IFX_MISRA_RULE_19_04_STATUS=GetVersionInfo cannot be expand to a braced 
 initialiser*/
#define Adc_GetVersionInfo(versioninfo)                                        \
{                                                                              \
  /* ADC236 to retirve the id's of ADC driver */                               \
  ((Std_VersionInfoType*)(versioninfo))->moduleID = ADC_MODULE_ID;             \
  ((Std_VersionInfoType*)(versioninfo))->vendorID = ADC_VENDOR_ID;             \
  ((Std_VersionInfoType*)(versioninfo))->sw_major_version =                    \
                                                (uint8)ADC_SW_MAJOR_VERSION;   \
  ((Std_VersionInfoType*)(versioninfo))->sw_minor_version =                    \
                                                (uint8)ADC_SW_MINOR_VERSION;   \
  ((Std_VersionInfoType*)(versioninfo))->sw_patch_version =                    \
                                                (uint8)ADC_SW_PATCH_VERSION;   \
}                                                                              
#else
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to generate compile time
 error in case of incorrect configuration*/
#define Adc_GetVersionInfo(versioninfo) (ERROR_Adc_GetVersionInfo_NOT_SELECTED)

#endif /* (ADC_VERSION_INFO_API == STD_ON) */

/* ADC SRN0 is used by request source 0 of ADC kernels */
#if( (ADC_REQSRC0 == ADC_REQSRC_USED) || (ADC1_REQSRC3 == ADC_REQSRC_USED) )
/*******************************************************************************
** Syntax           : extern void Adc_IsrSrn0AdcRS0(uint8 AdcKernel)          **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non reentrant                                           **
**                                                                            **
** Parameters (in)  : AdcKernel number                                        **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function                                           **
**  - Handles the interrupts from ADC kerenel Request source 0                **
**  - Must be called in ISR of ADC_SRC0                                       **
**                                                                            **
*******************************************************************************/
extern void Adc_IsrSrn0AdcRS0(uint8 AdcKernel);
#endif

/* ADC SRN1 is used by request source 1 of ADC Kernels */
#if (ADC_REQSRC1 == ADC_REQSRC_USED)
/*******************************************************************************
** Syntax           : extern void Adc_IsrSrn1AdcRS1(uint8 AdcKernel)          **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non reentrant                                           **
**                                                                            **
** Parameters (in)  : AdcKernel number                                        **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function                                           **
**  - Handles the interrupts from ADC kernel Request source 1                 **
**  - Must be called in ISR of ADC_SRC1                                      **
**                                                                            **
*******************************************************************************/
extern void Adc_IsrSrn1AdcRS1(uint8 AdcKernel);
#endif

/* ADC SRN2 is used by request source 2 of All ADC kernels */
#if ( (ADC0_REQSRC2 == ADC_REQSRC_USED) || (ADC1_REQSRC2 == ADC_REQSRC_USED)||\
      (ADC2_REQSRC2 == ADC_REQSRC_USED) || (ADC3_REQSRC2 == ADC_REQSRC_USED)||\
      (ADC4_REQSRC2 == ADC_REQSRC_USED) || (ADC5_REQSRC2 == ADC_REQSRC_USED)||\
      (ADC6_REQSRC2 == ADC_REQSRC_USED) || (ADC7_REQSRC2 == ADC_REQSRC_USED)||\
      (ADC8_REQSRC2 == ADC_REQSRC_USED) || (ADC9_REQSRC2 == ADC_REQSRC_USED)||\
      (ADC10_REQSRC2 == ADC_REQSRC_USED) )
/*******************************************************************************
** Syntax           : extern void Adc_IsrSrn0CG0AdcRS2(void)                  **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non reentrant                                           **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function                                           **
**  - Handles the interrupts from All ADC kernal's Request source 2           **
**  - Must be called in ISR of Shared service request line 0 of CG0           **
**                                                                            **
*******************************************************************************/
extern void Adc_IsrSrn0CG0AdcRS2(void);
#endif

#if (ADC0_REQSRC3 == ADC_REQSRC_USED)
/*******************************************************************************
** Syntax           : extern void Adc_IsrSrn1CG0AdcRS3(uint8 AdcKernel)       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non reentrant                                           **
**                                                                            **
** Parameters (in)  : AdcKernel number                                        **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function                                           **
**  - Handles the interrupts from ADC kernel Request source 3                 **
**  - Must be called in ISR of Shared service request line 1 of CG0           **
**                                                                            **
*******************************************************************************/
extern void Adc_IsrSrn1CG0AdcRS3(uint8 AdcKernel);
#endif

#if (ADC1_REQSRC3 == ADC_REQSRC_USED)
/*******************************************************************************
** Syntax           : extern void Adc_IsrSrn2CG0AdcRS3(uint8 AdcKernel)       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non reentrant                                           **
**                                                                            **
** Parameters (in)  : AdcKernel number                                        **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function                                           **
**  - Handles the interrupts from ADC kernel Request source 3                 **
**  - Must be called in ISR of Shared service request line 2 of CG0           **
**                                                                            **
*******************************************************************************/
extern void Adc_IsrSrn2CG0AdcRS3(uint8 AdcKernel);
#endif

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/*******************************************************************************
** Syntax           : extern void Adc_IsrSrn2AdcChEvnt(uint8 AdcKernel)       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non reentrant                                           **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function                                           **
**  - Handles the interrupts from ADC Channel Event                           **
**  - Must be called in ISR of ADC0 SRN2                                      **
**                                                                            **
*******************************************************************************/
extern void Adc_IsrSrn2AdcChEvnt(uint8 AdcKernel);

#endif

#if (ADC_GROUP_EMUX_SCAN == STD_ON)
/*******************************************************************************
** Syntax           : extern void Adc_IsrDmaSrn                               **
**                       (uint8 AdcKernel)                                    **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function                                           **
**  - Handles the interrupts from DMA on transfer complete                    **
**  - Must be called in ISR of DMA_SRC3                                       **
*******************************************************************************/
extern void Adc_IsrDmaSrn(uint8 AdcKernel);
#endif /* (ADC_GROUP_EMUX_SCAN == STD_ON) */

#if (ADC_REQSRC2 == ADC_REQSRC_USED)
#if ( ADC_TIMER_TRIGG == STD_ON )
/*******************************************************************************
** Syntax           : extern void Adc_17_StartGtmTimer                        **
**                    (                                                       **
**                       Adc_GroupType Group                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Adc Channel Group Id                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called when Timer trigger Group has requested for    **
**                    Enable Hardware - Background Request Source             **
*******************************************************************************/
extern void Adc_17_StartGtmTimer(Adc_GroupType Group);

/*******************************************************************************
** Syntax           : extern void Adc_17_StopGtmTimer                         **
**                    (                                                       **
**                       Adc_GroupType Group                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Adc Channel Group Id                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called when Timer trigger Group has requested for    **
**                    Disable Hardware - Background Request Source            **
*******************************************************************************/
extern void Adc_17_StopGtmTimer(Adc_GroupType Group);
#endif /* ADC_TIMER_TRIGG == STD_ON */

#if ( (ADC_ERU_TRIGG == STD_ON) || (ADC_ERU_GATING== STD_ON) )
/*******************************************************************************
** Syntax           : extern void Adc_17_SetEruTrigger                        **
**                    (                                                       **
**                       Adc_GroupType Group                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Adc Channel Group Id                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called when ERU trigger Group has requested for      **
**                    Enable Hardware - Background Request Source             **
*******************************************************************************/
extern void Adc_17_SetEruTrigger(Adc_GroupType Group);

/*******************************************************************************
** Syntax           : extern void Adc_17_ResetEruTrigger                      **
**                    (                                                       **
**                       Adc_GroupType Group                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Adc Channel Group Id                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called when ERU trigger Group has requested for      **
**                    Diable Hardware - Background Request Source             **
*******************************************************************************/
extern void Adc_17_ResetEruTrigger(Adc_GroupType Group);
#endif /*  ADC_ERU_GATING == STD_ON  && ADC_ERU_TRIGG == STD_ON*/

#endif /* (ADC_REQSRC2 == ADC_REQSRC_USED) */

#if (ADC_HW_STARTUP_CALIBRATION == STD_ON)
/*******************************************************************************
** Syntax           : extern Std_ReturnType Adc_17_GetStartupCalStatus        **
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : E_OK: Startup calibration is completed                  **
**                    E_NOT_OK: Startup calibration is ongoing                **
**                                                                            **
** Description      : Api checks the end of startup calibration               **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Adc_17_GetStartupCalStatus(void);
#endif /* (ADC_HW_STARTUP_CALIBRATION == STD_ON) */

#if (ADC_INITCHECK_API == STD_ON)
/*******************************************************************************
** Syntax           : extern Std_ReturnType Adc_InitCheck                     **
**                    (                                                       **
**                      const Adc_ConfigType *ConfigPtr                       **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Std_ReturnType                                          **
**                                                                            **
** Description      : This function checks is the initialization of the       **
**                    ADC hardware unit and driver done according to the      **
**                    configuration set referenced by ConfigPtr.              **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Adc_InitCheck(const Adc_ConfigType *ConfigPtr);

#endif /* (ADC_INITCHECK_API == STD_ON) */

#if (ADC_RESULT_POLLING_MODE == STD_ON)
/*******************************************************************************
** Syntax           : Std_ReturnType Adc_17_GetGroupResult                    **
**                    (                                                       **
**                      Adc_GroupType Group                                   **
**                      Adc_ValueGroupType *DataBufferPtr                     **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x2E                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : re-entrant                                              **
**                                                                            **
** Parameters(in)   : Group - Numeric ID of requested ADC Channel group.      **
**                                                                            **
** Parameters (out) : DataBufferPtr - Location to store the requested Group's **
**                    channels conversion result                              **
**                                                                            **
** Return value     : E_OK - DET or Safety errors not occured                 **
**                    E_NOT_OK - DET or Safety errors occured                 **
**                                                                            **
** Description      : This function: reads the latest available conversion    **
**                    results of the requested group in a polling mode        **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Adc_17_GetGroupResult
(
  Adc_GroupType Group,
  Adc_ValueGroupType *DataBufferPtr 
);

/*******************************************************************************
** Syntax           : Std_ReturnType Adc_17_GetChannelStatus                  **
**                    (                                                       **
**                      uint8 ChannelNumber                                   **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x2F                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : re-entrant                                              **
**                                                                            **
** Parameters(in)   : Group - Numeric ID of requested ADC Channel.            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : E_OK - Channel conversion is completed                  **
**                    E_NOT_OK - Channel conversion is ongoing                **
**                                                                            **
** Description      : This function: checks the end of requested analog       **
**                    channel conversion in a polling mode                    **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Adc_17_GetChannelStatus
(
  uint8 ChannelNumber
);
#endif /* (ADC_RESULT_POLLING_MODE == STD_ON) */

#define ADC_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif /* ADC_H */

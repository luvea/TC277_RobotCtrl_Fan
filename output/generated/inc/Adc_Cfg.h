/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : Adc_Cfg.h $                                                **
**                                                                            **
**   $CC VERSION : \main\dev_tc23x_as4.0.3\19 $                               **
**                                                                            **
**   DATE, TIME: 2021-04-08, 20:15:37                                         **
**                                                                            **
**   GENERATOR : Build b141014-0350                                           **
**                                                                            **
**   AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                            **
**   VENDOR    : Infineon Technologies                                        **
**                                                                            **
**   DESCRIPTION  : Adc configuration generated out of ECU configuration      **
**                 file                                                       **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*******************************************************************************/
#ifndef ADC_CFG_H
#define ADC_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define ADC_AR_RELEASE_MAJOR_VERSION      (4U)
#define ADC_AR_RELEASE_MINOR_VERSION      (0U)
#define ADC_AR_RELEASE_REVISION_VERSION   (3U)

#define ADC_SW_MAJOR_VERSION              (3U)
#define ADC_SW_MINOR_VERSION              (2U)
#define ADC_SW_PATCH_VERSION              (0U)

/* Maximum resolution possible */
#define ADC_MAX_CHANNEL_RESOLUTION        ((uint8)12)

/* ADC_CHANNEL_VALUESIGNED:  unsigned */
#define ADC_CHANNEL_VALUESIGNED           (STD_OFF)

/*
  Information whether the first channel of an ADC Channel group can be
  configured (FALSE) or is fixed (TRUE) to a value determined by 
  the ADC HW Unit 
*/
#define ADC_GROUP_FIRST_CHANNEL_FIXED     (STD_OFF)


/*
  Macros are defined to enable/disable the usage of debug variables
  Debug variables are added in the code for code coverage
*/
#define IFX_ADC_DEBUG_RESET               (STD_OFF)
#define IFX_ADC_DEBUG_CLC                 (STD_OFF)
#define IFX_ADC_DEBUG_CCU60_CLC           (STD_OFF)
#define IFX_ADC_DEBUG_CCU6_CLC            (STD_OFF)
#define IFX_ADC_DEBUG_CLC_DISABLE         (STD_OFF)

/*Configuration Options: ADC_RESULT_HANDLING_MODE
  Result handling as per AUTOSAR specification or 
  NonAUTOSAR specific DMA handling
*/
#define ADC_AUTOSAR                       (0U)
#define ADC_NON_AUTOSAR                   (1U)

/*
  Configuration Options: ADC_PRIORITY_IMPLEMENTATION
  Options for the Priority Mechanism supported in ADC Driver
*/
#define ADC_PRIORITY_NONE                 (0U)
#define ADC_PRIORITY_HW                   (1U)
#define ADC_PRIORITY_HW_SW                (2U) 

/*
  Configuration Options: ADC_RESULT_ALIGNMENT
  Options for the Alignment of raw results in ADC Driver
*/
#define ADC_ALIGN_LEFT                    (0U)
#define ADC_ALIGN_RIGHT                   (1U)

/* Configuration Options: ADC_VALUE_GROUP_TYPE 
ADC320: Only if all ADC channels of all ADC groups have 8 bit resolution, 
Adc_ValueGroupType can be configured as 8 bit data type.
Else, 16-bit is selected
*/

#define ADC_VALUE_EIGHT_BIT               (0U)
#define ADC_VALUE_SIXTEEN_BIT             (1U)

/* Configuration of channel & kernel mask to identify the 
channel & kernel number */ 
#define ADC_AN_CH_MASK                    (0x7U)
#define ADC_KERNEL_MASK                   (0x78U)
#define ADC_KERNEL_NUM_SHIFT_POS          (0x3U)

/* Configuration of wait count of checking reset status */
#define ADC_KERNEL_RESET_WAIT_COUNTS      (0x100U)

/* Configuration of ARM bitfield of CALCTR register */ 
#define ADC_REF_LOCAL_MODE                (0U)
#define ADC_REF_GLOBAL_MODE               (1U)

/* Total number of Configuration set */
#define ADC_CONFIG_COUNT                  (1U)
/*
                     Container : AdcDriverGeneralConfiguration
*/
/*
  The following macros will enable or disable a particular feature 
  in ADC module.
  Set the macro to ON to enable the feature and OFF to disable the same.
*/
/*
Configuration: ADC_DEV_ERROR_DETECT
Preprocessor switch for enabling the development error detection and 
reporting. 
- if STD_ON, DET is Enabled 
- if STD_OFF,DET is Disabled 
*/
#define ADC_DEV_ERROR_DETECT  (STD_OFF)

/*
Configuration: ADC_SAFETY_ENABLE
Preprocessor switch for enabling the Safety signals. 
- if STD_ON, Safety is Enabled 
- if STD_OFF,Safety is Disabled 
*/
#define ADC_SAFETY_ENABLE    (STD_OFF)

/*
Configuration: ADC_INITCHECK_API
Preprocessor switch for enabling the Adc_InitCheck Api. 
- if STD_ON, Adc_InitCheck Api is Enabled 
- if STD_OFF,Adc_InitCheck Api is Disabled 
*/
#define ADC_INITCHECK_API    (STD_OFF)

/* Mask value for the GLOBCFG sfr */
#define ADC_GLOBCFG_SFR_MSK               (0x00FFD39FU)


/* Mask value for the SRC Register */
#define ADC_SRC_SRCR_MSK                  (0x7F3F18FFU)

/*
Configuration: ADC_CCU6_SYNCHRONIZATION
Preprocessor switch for enabling the development CCU6x T13 to generate 20MHz  
Synchronization signal to all VADCs. 
- if STD_ON, Enables the CCU6x T13 to generate 20MHz Synchronization signal 
- if STD_OFF, Disables the CCU6x T13 to generate 20MHz Synchronization signal 
*/
#define ADC_CCU6_SYNCHRONIZATION      (STD_OFF)

/*
Configuration: ADC_ENABLE_LIMIT_CHECK
Preprocessor switch for enabling the limit checking feature of ADC. 
- if STD_ON, Limit checking feature of ADC is Enabled 
- if STD_OFF,Limit checking feature of ADC is Disabled 
*/
#define ADC_ENABLE_LIMIT_CHECK        (STD_OFF)

/* Preprocessor switch for enabling the code to access VADC_GxCEVNP1 SFR */
#define ADC_CH_EVNT_NPTR1_AVAILABLE   (STD_OFF)

/* Preprocessor switch for enabling the code to access VADC_GxREVNP1 SFR */
#define ADC_RES_EVNT_NPTR1_AVAILABLE  (STD_OFF)

/* Configuration: ADC_VERSION_INFO_API
Version Information API configuration 
- if STD_ON, VersionInfo API is Enabled 
- if STD_OFF, VersionInfo API is Disabled 
*/
#define ADC_VERSION_INFO_API  (STD_OFF)

/*
Configuration: ADC_RUNNING_IN_USER_0_MODE_ENABLE 
- if STD_ON, Enable User0 mode 
- if STD_OFF, Disable User0 mode 
*/
#define ADC_RUNNING_IN_USER_0_MODE_ENABLE     (STD_OFF)


/*
Configuration: ADC_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Disable Protected Mode(user mode) mode in Init API  
*/
#define ADC_USER_MODE_INIT_API_ENABLE     (STD_OFF)


/*
Configuration: ADC_USER_MODE_DEINIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in DeInit API 
- if STD_OFF, Disable Protected Mode(user mode) mode in DeInit API 
*/
#define ADC_USER_MODE_DEINIT_API_ENABLE     (STD_OFF)


/*
Configuration: ADC_USER_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in APIs other than Init/Deinit APIs
- if STD_OFF, Enable Protected Mode(user mode) mode in APIs other than Init/Deinit APIs
*/
#define ADC_USER_MODE_RUNTIME_API_ENABLE     (STD_OFF)


/* Configuration: ADC_DEINIT_API
Adc_DeInit API configuration 
- if STD_ON, DeInit API is Enabled 
- if STD_OFF, DeInit API is Disabled 
*/
#define ADC_DEINIT_API  (STD_OFF)

/* Configuration: ADC_ENABLE_START_STOP_GROUP_API
Start/Stop Group conversion API configuration 
- if STD_ON, Start/Stop Group conversion API is Enabled 
- if STD_OFF, Start/Stop Group conversion API is Disabled 
*/
#define ADC_ENABLE_START_STOP_GROUP_API  (STD_ON)

/* Configuration: ADC_HW_TRIGGER_API
Adc HW Trigger API configuration 
- if STD_ON, Adc HW Trigger API is Enabled 
- if STD_OFF, Adc HW Trigger API is Disabled 
*/
#define ADC_HW_TRIGGER_API  (STD_ON)


#if (ADC_HW_TRIGGER_API == STD_ON)
/* Configuration: ADC_TIMER_TRIGG , ADC_ERU_TRIGG, ADC_ERU_GATING 
   Determines if the HW trigger is through Timer or ERU trigger, or both 
- if ON, The Trigger Type is Enabled 
- if OFF, The Trigger Type is Disabled
*/
#define ADC_TIMER_TRIGG             (STD_OFF)
#define ADC_ERU_TRIGG               (STD_OFF)
#define ADC_ERU_GATING              (STD_OFF)
#endif

/* Configuration: ADC_PB_FIXED_ADDRESS (Vendor specific)
Fixed address confiuration as per HIS recommendatons
- if STD_ON, ConfigRoot[0] is used by default as the fixed configuration
- if STD_OFF, Dynamic usage of the selected configurations according to AUTOSAR 
*/
#define ADC_PB_FIXED_ADDRESS               (STD_OFF)


/* Configuration: ADC_MASTER_SLAVE_SYNC
Enables/Disables the Synchronization of conversion (Parallel sampling) feature 
- if STD_ON, Enables Parallel sampling 
- if STD_OFF, Disables Parallel sampling 
*/
#define ADC_MASTER_SLAVE_SYNC              (STD_OFF)

#if( ADC_MASTER_SLAVE_SYNC == STD_ON )
/* Configuration: ADC_KERNELS_PER_SYNGRP
Provides the number of kernels per synchronization group
*/
#define ADC_KERNELS_PER_SYNGRP             (4U)
#endif /* ( ADC_MASTER_SLAVE_SYNC == STD_ON ) */

/* Configuration: ADC_SAMPLE_HOLD_UNIT
- if STD_ON: Sample and Hold unit is available in the used ADC
- if STD_OFF: Sample and Hold unit is not available in the used ADC 
*/
#define ADC_SAMPLE_HOLD_UNIT               (STD_OFF)

/* Preprocessor switch for enabling the Adc_17_GetStartupCalStatus() API */
#define ADC_HW_STARTUP_CALIBRATION         (STD_ON)

/* Configuration: ADC_ALTERNATE_REF_MODE
- if ADC_REF_LOCAL_MODE: Channel 0 (CH0) of a Kernel is used as reference
- if ADC_REF_GLOBAL_MODE: Channel 0 (CH0) of a selected kernel of a 
  cluster is used as reference 
*/
#define ADC_ALTERNATE_REF_MODE       (ADC_REF_LOCAL_MODE)

/* Configuration: ADC_ALTERNATE_REF_CH_USED
- if STD_ON: Channel 0 (CH0) is used as reference
- if STD_OFF: Standard reference is used
*/
#define ADC_ALTERNATE_REF_CH_USED    (STD_OFF)

/* Configuration: ADC_RESULT_POLLING_MODE
Switches the ADC Group result handing between AUTOSAR specific and Non AUTOSAR polling mode 
- if STD_ON, enables the services Adc_17_GetGroupResult() and Adc_17_GetChannelStatus() from code 
- if STD_OFF, disables the services Adc_17_GetGroupResult() and Adc_17_GetChannelStatus() from code 
*/
#define ADC_RESULT_POLLING_MODE  (STD_OFF)

/* Configuration: ADC_SAME_CHANNEL_QUEUING
Adc same channel queing in request source que capability configuration 
- if STD_ON, Same channel queing is Enabled 
- if STD_OFF, Same channel queing is Disabled 
*/
#define ADC_SAME_CHANNEL_QUEUING   (STD_OFF)

/* Configuration: ADC_RESULT_HANDLING_MODE 
   ADC Group result handling selection
- if AdcNonAutosarDmaResultHandling = true, Result handling is ADC_NON_AUTOSAR
- if AdcNonAutosarDmaResultHandling = false, Result handling is ADC_AUTOSAR
*/
#define ADC_RESULT_HANDLING_MODE  (ADC_AUTOSAR)

/* ADC_RES_ACCUMULATION_NONE: No accumulation of the result. Result register 
                        will have only one conversion value/WFR mode enabled
*/
#define ADC_RES_ACCUMULATION_NONE     (0x01000000U)
#if ( (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR) ||\
                                        (ADC_SAME_CHANNEL_QUEUING ==  STD_ON) )
/*
  Configuration Options: ADC_RESULT_ACCUMULATION
  ADC_RES_ACCUMULATION_TWO: Accumulation of the results upto 2 conversions.
  ADC_RES_ACCUMULATION_THREE: Accumulation of the results upto 3 conversions.
  ADC_RES_ACCUMULATION_FOUR: Accumulation of the results upto 4 conversions.
  WFR mode enabled
*/
#define ADC_RES_ACCUMULATION_TWO      (0x01010000U)
#define ADC_RES_ACCUMULATION_THREE    (0x01020000U)
#define ADC_RES_ACCUMULATION_FOUR     (0x01030000U)

#endif 
/* (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR) || 
                                         (ADC_SAME_CHANNEL_QUEUING ==  STD_ON)*/


/* Configuration: ADC_READ_GROUP_API
Adc_ReadGroup API switch 
- if STD_ON, Adc_ReadGroup API is Enabled 
- if STD_OFF, Adc_ReadGroup API is Disabled 
*/
#define ADC_READ_GROUP_API  (STD_ON)

/* Configuration: ADC_RESET_SFR_INIT
Resetting SFR to its reset value 
- if STD_ON, resetting of SFRs to its reset value in the Adc_Init() is Enabled 
- if STD_OFF, resetting of SFRs to its reset value in the Adc_Init() is Disabled 
*/
#define ADC_RESET_SFR_INIT  (STD_OFF)

/* Configuration: ADC_GRP_NOTIF_CAPABILITY
Adc Notification capability configuration 
- if STD_ON, Adc Notification capability is Enabled 
- if STD_OFF, Adc Notification capability is Disabled 
*/
#define ADC_GRP_NOTIF_CAPABILITY  (STD_OFF)

/* Configuration: ADC_DEBUG_SUPPORT
Adc Debug capability configuration 
- if STD_ON, Debug support is Enabled 
- if STD_OFF, Debug support is Disabled 
*/
#define ADC_DEBUG_SUPPORT         (STD_OFF)

/* Configuration: ADC_RESULT_ALIGNMENT
Determines the ADC result alignment
*/
#define ADC_RESULT_ALIGNMENT      (ADC_ALIGN_RIGHT)

/* Configuration: ADC_PRIORITY_IMPLEMENTATION
Determines the type of prioritization mechanism
*/
#define ADC_PRIORITY_IMPLEMENTATION  (ADC_PRIORITY_HW)

/* Since ADC_PRIORITY_HW_SW has no meaning in case of AdcEnableStartStopGroupApi
   disabled, throw error */

/* Configuration: ADC_USE_EMUX (Vendor specific)
Micro controller specific static configuration
- if STD_ON, Adc External multiplexer is used by the user
- if STD_OFF, Adc External multiplexer is not used by the user 
*/
#define ADC_USE_EMUX               (STD_OFF)



/* Configuration: ADC_ENABLE_QUEUING
Determines, if the queuing mechanism is active in case of priority mechanism 
is disabled (PRIORITY_NONE).
Note: If priority mechanism is enabled, queuing mechanism is always active 
and the parameter ADC_ENABLE_QUEUING is not evaluated.
- if STD_ON, Queuing mechanism in no priority is Enabled 
- if STD_OFF, Queuing mechanism in no priority is Disabled 
*/
#define ADC_ENABLE_QUEUING  (STD_OFF)


#if((ADC_ENABLE_QUEUING == STD_ON) || (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR))
/* Configuration: ADC_MAX_GROUPS (Vendor Specific)
It is the maximum among the total number of groups configured in each 
Adc configuration.
This parameter is required for Queue mechanism in No Priority.
This parameter is automatically generated by the tool. 
For example if there are two post build configurations and 2 HW Units 
configured among each, with maximum 2, 3, 4 and 5 groups repectively in each 
HW Units, then ADC_MAX_GROUPS must be configured as 5. 
*/
#define ADC_MAX_GROUPS   (2U)
#endif /* (ADC_ENABLE_QUEUING == STD_ON) */


/* Configuration: ADCx_KERNEL_INDEX (Vendor Specific)
It is the variable array index of each Adc Hw Unit.
This parameter is automatically generated by the tool. 
For example if there are two ADC Hw units used, say ADC0 and ADC2,
ADC0_KERNEL_INDEX = 0, ADC2_KERNEL_INDEX = 1, ADC1_KERNEL_INDEX = Invalid
*/
#define ADC0_KERNEL_INDEX  (0U)
#define ADC1_KERNEL_INDEX  (1U)
#define ADC2_KERNEL_INDEX  (2U)
#define ADC3_KERNEL_INDEX  (3U)
#define ADC4_KERNEL_INDEX  (4U)
#define ADC5_KERNEL_INDEX  (5U)
#define ADC6_KERNEL_INDEX  (0U)
#define ADC7_KERNEL_INDEX  (0U)

/* Configuration: ADCx_QM_KERNEL_INDEX (Vendor Specific)
It is the variable array index of each Adc Hw Unit.
This parameter is automatically generated by the tool. 
For example if there are two ADC Hw units used, say ADC0 and ADC2,
ADC0_QM_KERNEL_INDEX = 0, ADC2_QM_KERNEL_INDEX = 1, 
ADC1_QM_KERNEL_INDEX = Invalid
*/
#define ADC0_QM_KERNEL_INDEX  (0U)
#define ADC1_QM_KERNEL_INDEX  (1U)
#define ADC2_QM_KERNEL_INDEX  (2U)
#define ADC3_QM_KERNEL_INDEX  (3U)
#define ADC4_QM_KERNEL_INDEX  (4U)
#define ADC5_QM_KERNEL_INDEX  (5U)
#define ADC6_QM_KERNEL_INDEX  (0U)
#define ADC7_QM_KERNEL_INDEX  (0U)



/* Number of ADC Kernels in the selected microcontroller */
#define ADC_MAX_KERNELS    (8U)
/* ADC Kernels Configured to use */
#define ADC_USED_KERNELS   (0x003fU)
/* Number of SHS Clusters in the selected microcontroller */
#define ADC_MAX_SHS_CLUSTERS  (2U)
/* Number of Kernels per Clusters in the selected microcontroller */
#define ADC_KERNELS_PER_CLUSTER  (4U)

/*
  Constant for getting  the variable array index for particular ADC Kernel
  If any of the ADCs are not used, its index will be 0.
  If Kernel is not used, the corresponding Index will be invalid value
  Eg: If ADC0 and ADC2 are used, then 
  ADC0_QM_KERNEL_INDEX = 0
  ADC2_QM_KERNEL_INDEX = 1
  and ADC_QM_KERNEL_USED_COUNT = 2
*/
/*IFX_MISRA_RULE_19_04_STATUS=ADC_QM_KERNEL_INDEX cannot be expand to a braced 
 initialiser*/
#define ADC_QM_KERNEL_INDEX   ADC0_QM_KERNEL_INDEX, \
                              ADC1_QM_KERNEL_INDEX, \
                              ADC2_QM_KERNEL_INDEX, \
                              ADC3_QM_KERNEL_INDEX, \
                              ADC4_QM_KERNEL_INDEX, \
                              ADC5_QM_KERNEL_INDEX, \
                              ADC6_QM_KERNEL_INDEX, \
                              ADC7_QM_KERNEL_INDEX


/* Configuration: ADCx_KERNEL_USED (Vendor Specific)
Define a macro for each Adc Hw Unit when Used in any of the configuration set
For example if there are two ADC Hw units used, say ADC0 and ADC2,
define ADC0_KERNEL_USED and ADC2_KERNEL_USED
ADC1_KERNEL_USED is not defined
*/
#define ADC0_KERNEL_USED         (STD_ON)
#define ADC1_KERNEL_USED         (STD_ON)
#define ADC2_KERNEL_USED         (STD_ON)
#define ADC3_KERNEL_USED         (STD_ON)
#define ADC4_KERNEL_USED         (STD_ON)
#define ADC5_KERNEL_USED         (STD_ON)
#define ADC6_KERNEL_USED         (STD_OFF)
#define ADC7_KERNEL_USED         (STD_OFF)
/* Configuration: ADC_KERNEL_USED_COUNT (Vendor Specific)
Define a macro for total number of Adc Hw Unit in use
For example if there are two ADC Hw units used across post build 
configurations , say ADC0 and ADC1,
ADC_KERNEL_USED_COUNT = 2
*/
#define ADC_KERNEL_USED_COUNT  (6U)
/* Configuration: ADC_QM_KERNEL_USED_COUNT (Vendor Specific)
Define a macro for total number of Adc Hw Unit in use
For example if there are two ADC Hw units used across post build 
configurations , say ADC0 and ADC1,
ADC_QM_KERNEL_USED_COUNT = 2
*/
#define ADC_QM_KERNEL_USED_COUNT  (6U) 

/* Configuration: ADC_VALUE_GROUP_TYPE (Vendor specific)
Macro to decide the Adc_ValueGroupType to be 8-bit or 16-bit
If all the Adc configured channels are of 8 bit resolution, 
8-bit is selected for Adc_ValueGroupType. Else, 16-bit is selected
This parameter is automatically ganerated by the tool
*/
#define ADC_VALUE_GROUP_TYPE     (ADC_VALUE_SIXTEEN_BIT)

#define ADC_SWOSM_INTERRUPT_HANDLER     (STD_OFF)

/*
  Macro indicating the total number of request sources used by the driver
*/
#define ADC_REQSRC_COUNT       (3U)

/*
  Macro indicating the availability of Request Source 3
*/
#define ADC_REQSRC3_AVAILABLE   (STD_OFF)

/* Configuration Options: ADCx_REQSRCy
   Options for request source of perticular ADC Hw Unit used or not
*/
#define ADC_REQSRC_USED        (1U)
#define ADC_REQSRC_UNUSED      (0U)

/* Configuration: ADC0_REQSRCy (Vendor specific)
   Request source (RS0 .. RS3) of perticular ADC0 Hw Unit used or not
   This parameter is automatically ganerated by the tool
*/


#define ADC0_REQSRC0  (ADC_REQSRC_USED)

#define ADC0_REQSRC1  (ADC_REQSRC_UNUSED)

#define ADC0_REQSRC2  (ADC_REQSRC_UNUSED)

#define ADC0_REQSRC3  (ADC_REQSRC_UNUSED)

/* Configuration: ADC1_REQSRCy (Vendor specific)
   Request source (RS0 .. RS2) of perticular ADC1 Hw Unit used or not
   This parameter is automatically ganerated by the tool
*/


#define ADC1_REQSRC0  (ADC_REQSRC_USED)

#define ADC1_REQSRC1  (ADC_REQSRC_UNUSED)

#define ADC1_REQSRC2  (ADC_REQSRC_UNUSED)

#define ADC1_REQSRC3  (ADC_REQSRC_UNUSED)

/* Configuration: ADC2_REQSRCy (Vendor specific)
   Request source (RS0 .. RS2) of perticular ADC2 Hw Unit used or not
   This parameter is automatically ganerated by the tool
*/


#define ADC2_REQSRC0  (ADC_REQSRC_USED)


#define ADC2_REQSRC1  (ADC_REQSRC_USED)

#define ADC2_REQSRC2  (ADC_REQSRC_UNUSED)

#define ADC2_REQSRC3  (ADC_REQSRC_UNUSED)

/* Configuration: ADC3_REQSRCy (Vendor specific)
   Request source (RS0 .. RS2) of perticular ADC3 Hw Unit used or not
   This parameter is automatically ganerated by the tool
*/


#define ADC3_REQSRC0  (ADC_REQSRC_USED)


#define ADC3_REQSRC1  (ADC_REQSRC_USED)

#define ADC3_REQSRC2  (ADC_REQSRC_UNUSED)

#define ADC3_REQSRC3  (ADC_REQSRC_UNUSED)

/* Configuration: ADC4_REQSRCy (Vendor specific)
   Request source (RS0 .. RS2) of perticular ADC4 Hw Unit used or not
   This parameter is automatically ganerated by the tool
*/


#define ADC4_REQSRC0  (ADC_REQSRC_USED)

#define ADC4_REQSRC1  (ADC_REQSRC_UNUSED)

#define ADC4_REQSRC2  (ADC_REQSRC_UNUSED)

/* Configuration: ADC5_REQSRCy (Vendor specific)
   Request source (RS0 .. RS2) of perticular ADC5 Hw Unit used or not
   This parameter is automatically ganerated by the tool
*/


#define ADC5_REQSRC0  (ADC_REQSRC_USED)

#define ADC5_REQSRC1  (ADC_REQSRC_UNUSED)

#define ADC5_REQSRC2  (ADC_REQSRC_UNUSED)

/* Configuration: ADC6_REQSRCy (Vendor specific)
   Request source (RS0 .. RS2) of perticular ADC6 Hw Unit used or not
   This parameter is automatically ganerated by the tool
*/

#define ADC6_REQSRC0  (ADC_REQSRC_UNUSED)

#define ADC6_REQSRC1  (ADC_REQSRC_UNUSED)

#define ADC6_REQSRC2  (ADC_REQSRC_UNUSED)

/* Configuration: ADC7_REQSRCy (Vendor specific)
   Request source (RS0 .. RS2) of perticular ADC7 Hw Unit used or not
   This parameter is automatically ganerated by the tool
*/

#define ADC7_REQSRC0  (ADC_REQSRC_UNUSED)

#define ADC7_REQSRC1  (ADC_REQSRC_UNUSED)

#define ADC7_REQSRC2  (ADC_REQSRC_UNUSED)


#define ADC8_REQSRC0  (ADC_REQSRC_UNUSED)

#define ADC8_REQSRC1  (ADC_REQSRC_UNUSED)

#define ADC8_REQSRC2  (ADC_REQSRC_UNUSED)


#define ADC9_REQSRC0  (ADC_REQSRC_UNUSED)

#define ADC9_REQSRC1  (ADC_REQSRC_UNUSED)
  
#define ADC9_REQSRC2  (ADC_REQSRC_UNUSED)
  

#define ADC10_REQSRC0  (ADC_REQSRC_UNUSED)

#define ADC10_REQSRC1  (ADC_REQSRC_UNUSED)
  
#define ADC10_REQSRC2  (ADC_REQSRC_UNUSED)

/* macros used to identify the Request sources configured */  
#define ADC_KERNEL_REQSRC0_USED  (0x003fU)
#define ADC_KERNEL_REQSRC1_USED  (0x000cU)
#define ADC_KERNEL_REQSRC2_USED  (0x0000U)
#define ADC_KERNEL_REQSRC3_USED  (0x0000U)


/* Configuration: ADC_REQSRCy (Vendor specific)
   Request source (RS0 .. RS2) of any ADC Hw Unit used or not
   This parameter is automatically ganerated by the tool
*/
#define ADC_REQSRC0  (ADC_REQSRC_USED)

#define ADC_REQSRC1  (ADC_REQSRC_USED)

#define ADC_REQSRC2  (ADC_REQSRC_UNUSED)

#define ADC_REQSRC3  (ADC_REQSRC_UNUSED)

/* Enable request sources for arbitration */
#define ADC_REQSRC_ARB_ENABLE          ((uint32)0x3)

/* Configuration: ADC_MAX_CH_CON_TIME_COUNT (Vendor specific)
  On stop of conversion request, the ongoing channel conversion in the 
  A/D converter can't be stopped. Insted the API / software needs to wait 
  for atleast the converter to become idle. 
  Only when the converter is idle, the stop request is completely serviced. 
  Inorder to ensure the converter is idle, a wait on coverter status polling 
  is required and its maximum wait time is defined by the value entered in 
  the AdcMaxChConvTimeCount.

  Conversion time = 2 * tADC + (4 + STC + n) * tADCI + sample phase length
  where: 
  n = 8, 10, 12 for n bit resolution
  tADC = ADC module clock = system clock
  tADCI = Analog clock
  STC = Sample time control (Value - 0, 1, 2 ... 16, 32, 48, 64, 80, 96, 112, 128,
        144, 160, 176, 192, 208, 224, 240, 256)

  sample phase length = (2 + STC) / fADCI
  STC = Sample time control (Value - 0, 1, 2 ... 16, 32, 48, 64, 80, 96, 112, 128,
        144, 160, 176, 192, 208, 224, 240, 256)
             fADCI : Analog clock frequency
             1/fADCI = tADCI

  Maximum sample phase length value:
  STC = 256
  tADCI = 32*tADC
  tADC = tSYS (System clock time)
  No. of sampling time count = 32*tSYS (2+256) / tSYS = 8256
  
  Minimum sample phase length value:
  STC = 0
  tADCI = 1*tADC
  tADC = tSYS (System clock time)
  No. of sampling time count = 1*tSYS (2+0) / tSYS = 2

  Maximum Conversion time value:
  tADC = tSYS (System clock time)
  tADCI = 32 * tADC
  STC = 256
  n =  12 bit resolution
  No. of conversion time count = tSYS (2+(4+256+12)32) / tSYS + 
                                 Maximum sample phase length value 
                               = 8706 + 8256 = 16962
  Minimum Conversion time value:
  tADC = tSYS (System clock time)
  tADCI = 1* tADC
  STC = 0
  n =  8 bit resolution
  No. of conversion time count = tSYS (2+(4+0+8)1) / tSYS + 
                                 Minimum sample phase length value 
                               = 14 + 2 = 16
*/
#define ADC_MAX_CH_CON_TIME_COUNT                 (10000U)

/* Configuration: ADC_WAIT_ON_STOP (Vendor specific)
   Macro to switch ON/OFF the wait for HW unit Idle state in the driver on 
   Stop / Disable request
   If the configured ADC_MAX_CH_CON_TIME_COUNT is less than the minimum value,
   ADC_WAIT_ON_STOP is set OFF. In this case,  user has to ensure that 
   new start of a Group is called only when ADC HW Unit is Idle. 
   Switching off of driver to wait on stop is applicable in 
   PRIORITY_NONE (Queue is OFF) and PRIORITY_HW_SW.
   This parameter is automatically ganerated by the tool
*/
#define ADC_WAIT_ON_STOP             (STD_ON)



/* Configuration: ADC_GROUP_EMUX_SCAN (Vendor specific)
Macro which tells if any of the Group uses EMUX scan feature or not. 
This parameter is automatically ganerated by the tool
*/

#define ADC_GROUP_EMUX_SCAN   (STD_OFF)


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*CHANNEL SYMBOLIC NAME */

/* ADC0 HW Unit */

#ifndef AdcConf_AdcChannel_AI_CUR_M1_U /* to prevent double declaration */
#define AdcConf_AdcChannel_AI_CUR_M1_U  ((Adc_ChannelType)0)
#endif /* AdcConf_AdcChannel_AI_CUR_M1_U */

#ifndef AdcConf_AdcChannel_AI_DRV1_VRO /* to prevent double declaration */
#define AdcConf_AdcChannel_AI_DRV1_VRO  ((Adc_ChannelType)1)
#endif /* AdcConf_AdcChannel_AI_DRV1_VRO */

#ifndef AdcConf_AdcChannel_AI_CUR_M2_U /* to prevent double declaration */
#define AdcConf_AdcChannel_AI_CUR_M2_U  ((Adc_ChannelType)2)
#endif /* AdcConf_AdcChannel_AI_CUR_M2_U */

#ifndef AdcConf_AdcChannel_AI_CUR_M3_U /* to prevent double declaration */
#define AdcConf_AdcChannel_AI_CUR_M3_U  ((Adc_ChannelType)3)
#endif /* AdcConf_AdcChannel_AI_CUR_M3_U */

#ifndef AdcConf_AdcChannel_AI_CUR_M4_U /* to prevent double declaration */
#define AdcConf_AdcChannel_AI_CUR_M4_U  ((Adc_ChannelType)4)
#endif /* AdcConf_AdcChannel_AI_CUR_M4_U */

#ifndef AdcConf_AdcChannel_AI_DRV2_VRO /* to prevent double declaration */
#define AdcConf_AdcChannel_AI_DRV2_VRO  ((Adc_ChannelType)5)
#endif /* AdcConf_AdcChannel_AI_DRV2_VRO */
/* ADC1 HW Unit */

#ifndef AdcConf_AdcChannel_AI_CUR_M1_V /* to prevent double declaration */
#define AdcConf_AdcChannel_AI_CUR_M1_V  ((Adc_ChannelType)0)
#endif /* AdcConf_AdcChannel_AI_CUR_M1_V */

#ifndef AdcConf_AdcChannel_AI_CUR_M2_V /* to prevent double declaration */
#define AdcConf_AdcChannel_AI_CUR_M2_V  ((Adc_ChannelType)1)
#endif /* AdcConf_AdcChannel_AI_CUR_M2_V */

#ifndef AdcConf_AdcChannel_AI_CUR_M3_V /* to prevent double declaration */
#define AdcConf_AdcChannel_AI_CUR_M3_V  ((Adc_ChannelType)2)
#endif /* AdcConf_AdcChannel_AI_CUR_M3_V */

#ifndef AdcConf_AdcChannel_AI_CUR_M4_V /* to prevent double declaration */
#define AdcConf_AdcChannel_AI_CUR_M4_V  ((Adc_ChannelType)3)
#endif /* AdcConf_AdcChannel_AI_CUR_M4_V */

#ifndef AdcConf_AdcChannel_AI_DRV3_VRO /* to prevent double declaration */
#define AdcConf_AdcChannel_AI_DRV3_VRO  ((Adc_ChannelType)4)
#endif /* AdcConf_AdcChannel_AI_DRV3_VRO */

#ifndef AdcConf_AdcChannel_AI_DRV4_VRO /* to prevent double declaration */
#define AdcConf_AdcChannel_AI_DRV4_VRO  ((Adc_ChannelType)5)
#endif /* AdcConf_AdcChannel_AI_DRV4_VRO */
/* ADC2 HW Unit */

#ifndef AdcConf_AdcChannel_AI_CUR_M1_W /* to prevent double declaration */
#define AdcConf_AdcChannel_AI_CUR_M1_W  ((Adc_ChannelType)0)
#endif /* AdcConf_AdcChannel_AI_CUR_M1_W */

#ifndef AdcConf_AdcChannel_AI_V_12V /* to prevent double declaration */
#define AdcConf_AdcChannel_AI_V_12V  ((Adc_ChannelType)1)
#endif /* AdcConf_AdcChannel_AI_V_12V */

#ifndef AdcConf_AdcChannel_AI_UPOWIN /* to prevent double declaration */
#define AdcConf_AdcChannel_AI_UPOWIN  ((Adc_ChannelType)2)
#endif /* AdcConf_AdcChannel_AI_UPOWIN */

#ifndef AdcConf_AdcChannel_AI_CUR_M2_W /* to prevent double declaration */
#define AdcConf_AdcChannel_AI_CUR_M2_W  ((Adc_ChannelType)3)
#endif /* AdcConf_AdcChannel_AI_CUR_M2_W */

#ifndef AdcConf_AdcChannel_AI_CUR_M3_W /* to prevent double declaration */
#define AdcConf_AdcChannel_AI_CUR_M3_W  ((Adc_ChannelType)4)
#endif /* AdcConf_AdcChannel_AI_CUR_M3_W */

#ifndef AdcConf_AdcChannel_AI_CUR_M4_W /* to prevent double declaration */
#define AdcConf_AdcChannel_AI_CUR_M4_W  ((Adc_ChannelType)5)
#endif /* AdcConf_AdcChannel_AI_CUR_M4_W */
/* ADC3 HW Unit */

#ifndef AdcConf_AdcChannel_AI_V_3V3V /* to prevent double declaration */
#define AdcConf_AdcChannel_AI_V_3V3V  ((Adc_ChannelType)0)
#endif /* AdcConf_AdcChannel_AI_V_3V3V */

#ifndef AdcConf_AdcChannel_AI_TEMP2 /* to prevent double declaration */
#define AdcConf_AdcChannel_AI_TEMP2  ((Adc_ChannelType)1)
#endif /* AdcConf_AdcChannel_AI_TEMP2 */

#ifndef AdcConf_AdcChannel_AI_DC_CH_2 /* to prevent double declaration */
#define AdcConf_AdcChannel_AI_DC_CH_2  ((Adc_ChannelType)2)
#endif /* AdcConf_AdcChannel_AI_DC_CH_2 */

#ifndef AdcConf_AdcChannel_AI_DC_CH_1 /* to prevent double declaration */
#define AdcConf_AdcChannel_AI_DC_CH_1  ((Adc_ChannelType)3)
#endif /* AdcConf_AdcChannel_AI_DC_CH_1 */

#ifndef AdcConf_AdcChannel_AI_TEMP1 /* to prevent double declaration */
#define AdcConf_AdcChannel_AI_TEMP1  ((Adc_ChannelType)4)
#endif /* AdcConf_AdcChannel_AI_TEMP1 */
/* ADC4 HW Unit */

#ifndef AdcConf_AdcChannel_AI_TEMP3 /* to prevent double declaration */
#define AdcConf_AdcChannel_AI_TEMP3  ((Adc_ChannelType)0)
#endif /* AdcConf_AdcChannel_AI_TEMP3 */
/* ADC5 HW Unit */

#ifndef AdcConf_AdcChannel_AI_V_5V_PSEN /* to prevent double declaration */
#define AdcConf_AdcChannel_AI_V_5V_PSEN  ((Adc_ChannelType)0)
#endif /* AdcConf_AdcChannel_AI_V_5V_PSEN */

#ifndef AdcConf_AdcChannel_AI_V_USS_PEN /* to prevent double declaration */
#define AdcConf_AdcChannel_AI_V_USS_PEN  ((Adc_ChannelType)1)
#endif /* AdcConf_AdcChannel_AI_V_USS_PEN */

#ifndef AdcConf_AdcChannel_AI_V_5V0V /* to prevent double declaration */
#define AdcConf_AdcChannel_AI_V_5V0V  ((Adc_ChannelType)2)
#endif /* AdcConf_AdcChannel_AI_V_5V0V */

#ifndef AdcConf_AdcChannel_AI_V_1V8V /* to prevent double declaration */
#define AdcConf_AdcChannel_AI_V_1V8V  ((Adc_ChannelType)3)
#endif /* AdcConf_AdcChannel_AI_V_1V8V */

/*GROUP SYMBOLIC NAME */

/* Configuration set 1 */

/* AdcHwUnit_0 */


 #ifndef AdcConf_AdcGroup_G0_FOC_CUR_M1_U /* to prevent double declaration */
 #define AdcConf_AdcGroup_G0_FOC_CUR_M1_U   ((Adc_GroupType)0)
 #endif /* AdcConf_AdcGroup_G0_FOC_CUR_M1_U */

/* AdcHwUnit_1 */


 #ifndef AdcConf_AdcGroup_G1_FOC_CUR_M1_V /* to prevent double declaration */
 #define AdcConf_AdcGroup_G1_FOC_CUR_M1_V   ((Adc_GroupType)32)
 #endif /* AdcConf_AdcGroup_G1_FOC_CUR_M1_V */

/* AdcHwUnit_2 */

 #ifndef AdcConf_AdcGroup_G2_VOL_UPOWIN /* to prevent double declaration */
 #define AdcConf_AdcGroup_G2_VOL_UPOWIN   ((Adc_GroupType)64)
 #endif /* AdcConf_AdcGroup_G2_VOL_UPOWIN */


 #ifndef AdcConf_AdcGroup_G2_FOC_CUR_M1_W /* to prevent double declaration */
 #define AdcConf_AdcGroup_G2_FOC_CUR_M1_W   ((Adc_GroupType)65)
 #endif /* AdcConf_AdcGroup_G2_FOC_CUR_M1_W */

/* AdcHwUnit_3 */

 #ifndef AdcConf_AdcGroup_G3_AI_3V3V /* to prevent double declaration */
 #define AdcConf_AdcGroup_G3_AI_3V3V   ((Adc_GroupType)96)
 #endif /* AdcConf_AdcGroup_G3_AI_3V3V */


 #ifndef AdcConf_AdcGroup_G3_AI_DC /* to prevent double declaration */
 #define AdcConf_AdcGroup_G3_AI_DC   ((Adc_GroupType)97)
 #endif /* AdcConf_AdcGroup_G3_AI_DC */

/* AdcHwUnit_4 */

 #ifndef AdcConf_AdcGroup_G4_RES /* to prevent double declaration */
 #define AdcConf_AdcGroup_G4_RES   ((Adc_GroupType)128)
 #endif /* AdcConf_AdcGroup_G4_RES */


/* AdcHwUnit_5 */

 #ifndef AdcConf_AdcGroup_G5_5V0_1V8 /* to prevent double declaration */
 #define AdcConf_AdcGroup_G5_5V0_1V8   ((Adc_GroupType)160)
 #endif /* AdcConf_AdcGroup_G5_5V0_1V8 */




/*******************************************************************************
**                      Global Macro Definitions                              **
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

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif  /* ADC_CFG_H */

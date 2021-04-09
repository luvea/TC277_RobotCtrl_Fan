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
**  $FILENAME  : Pwm_17_Gtm_Cfg.h  $                                          **
**                                                                            **
**   $CC VERSION : \main\38 $                                                 **
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
**   MAY BE CHANGED BY USER [yes/no]: No                                     **
**                                                                            **
*******************************************************************************/

#ifndef PWM_17_GTM_CFG_H
#define PWM_17_GTM_CFG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define PWM_17_GTM_AR_RELEASE_MAJOR_VERSION  (4U)
#define PWM_17_GTM_AR_RELEASE_MINOR_VERSION  (0U)
#define PWM_17_GTM_AR_RELEASE_REVISION_VERSION  (3U)

#define PWM_17_GTM_SW_MAJOR_VERSION  (5U)
#define PWM_17_GTM_SW_MINOR_VERSION  (1U)
#define PWM_17_GTM_SW_PATCH_VERSION  (0U)


/*
                    Container:PwmGeneral
*/
/* Instance ID for PWM_17_Gtm module */
#define PWM_17_GTM_INSTANCE_ID         ((uint8)0U)

/*
PWM075: Pre Compile time parameters are placed in Pwm_Cfg.h
*/
/*
  Configuration: PWM_DEV_ERROR_DETECT : PWM064 PWM078
  Configuration of Development Error Detection 
  PWM064: API Parameter Checking is enabled if this compiler
  switch is STD_ON.
  PWM078: All errors are reported to Det_ReportError if the
  switch is STD_ON.
  Adds/removes the Development error detection 
  from the code 
  - if STD_ON, Development error detection is enabled
  - if STD_OFF, Development error detection is disabled
*/
#define PWM_DEV_ERROR_DETECT                 (STD_OFF)


/*
  Configuration: PWM_DE_INIT_API
  Configuration of Pwm_DeInit API
  Adds/removes the service Pwm_DeInit() 
  from the code 
  - if STD_ON, Pwm_DeInit() can be used
  - if STD_OFF, Pwm_DeInit() cannot be used
*/
#define PWM_DE_INIT_API                      (STD_OFF)


/*
  Configuration: PWM_GET_OUTPUT_STATE_API
  Configuration of Pwm_Get_Output_State_Api
  Adds/removes the service Pwm_GetOutputState() 
  from the code 
  - if STD_ON, Pwm_GetOutputState() can be used
  - if STD_OFF, Pwm_GetOutputState() cannot be used
*/
#define PWM_GET_OUTPUT_STATE_API                       (STD_OFF)


/*
  Configuration: PWM_SET_DUTY_CYCLE_API
  Configuration of Pwm_Set_Duty_Cycle_Api
  Adds/removes the service Pwm_GetOutputState() 
  from the code 
  - if STD_ON, Pwm_SetDutyCycle() can be used
  - if STD_OFF,Pwm_SetDutyCycle() cannot be used
*/
#define PWM_SET_DUTY_CYCLE_API                       (STD_ON)


/*
  Configuration: PWM_SET_OUTPUT_TO_IDLE_API
  Configuration of Pwm_Set_Output_To_Idle_Api
  Adds/removes the service Pwm_SetOutputToIdle() 
  from the code 
  - if STD_ON, Pwm_SetOutputToIdle() can be used
  - if STD_OFF,Pwm_SetOutputToIdle() cannot be used
*/
#define PWM_SET_OUTPUT_TO_IDLE_API                       (STD_ON)


/*
  Configuration: PWM_SET_PERIOD_AND_DUTY_API
  Configuration of Pwm_Set_Period_And_Duty_Api
  Adds/removes the service Pwm_SetPeriodAndDuty() 
  from the code 
  - if STD_ON, Pwm_SetPeriodAndDuty() can be used
  - if STD_OFF,Pwm_SetPeriodAndDuty() cannot be used
*/
#define PWM_SET_PERIOD_AND_DUTY_API                       (STD_ON)


/* Enables the handling of Shifted channel by offset
  - if STD_ON, Shifted channel is handled by offset
  - if STD_OFF, Shifted channel andled by trigger from 
               referenced Fixed period channel
*/
#define PWM_HANDLE_SHIFT_BY_OFFSET                       (STD_OFF)

/*
  Enables/Disables the Safety features 
  - if STD_ON, Safety features are enabled
  - if STD_OFF, Safety features are disabled
*/

#define PWM_SAFETY_ENABLE                 (STD_OFF)

/*
  Configuration: PWM_NOTIFICATION_SUPPORTED
  Adds/removes the service Pwm_EnableNotification()
  and Pwm_DisableNotification() from the code 
  - if STD_ON, Notification API's can be used
  - if STD_OFF, Notification API's cannot be used
*/
#define PWM_NOTIFICATION_SUPPORTED           (STD_ON)


/*
  Configuration: PWM_NOTIFICATION_FOR_0_AND_100
  Enable Notification for 0% and 100% duty 
  - if STD_ON, Notification for 0% and 100% duty is supported
  - if STD_OFF, Notification for 0% and 100% duty is not supported
*/

#define PWM_NOTIF_FOR_100_0_ENABLE           (STD_OFF)


/*
Configuration: PWM_DUTYCYCLE_UPDATED_ENDPERIOD
Applicable for Fixed Period Channel Class.
Feature to have the duty cycle change, whether to update
the duty at the end period or not.
*/
#define PWM_DUTYCYCLE_UPDATED_ENDPERIOD      (STD_ON)



/*
  Configuration: PWM_DUTY_PERIOD_UPDATED_ENDPERIOD
   Applicable for Variable Period Channel Class.
   Feature to have the duty cycle / period change, whether to update
   the duty / period at the end period or not.
   */
#define PWM_DUTY_PERIOD_UPDATED_ENDPERIOD    (STD_ON)


/*
Configuration: PWM_RUNNING_IN_USER_0_MODE_ENABLE 
- if STD_ON, enable User0 mode 
- if STD_OFF, enable User1 mode 
*/
#define PWM_RUNNING_IN_USER_0_MODE_ENABLE     (STD_OFF)


/*
Configuration: PWM_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Enable Supervisor mode in Init API  
*/
#define PWM_USER_MODE_INIT_API_ENABLE     (STD_OFF)


/*
Configuration: PWM_USER_MODE_DEINIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in DeInit API 
- if STD_OFF, Enable Supervisor mode in DeInit API 
*/
#define PWM_USER_MODE_DEINIT_API_ENABLE     (STD_OFF)


/*
Configuration: PWM_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in APIs other than Init/Deinit APIs
- if STD_OFF, Enable Supervisor mode in APIs other than Init/Deinit APIs
*/
#define PWM_USER_MODE_RUNTIME_API_ENABLE     (STD_OFF)


/*
  Configuration: PWM_VERSION_INFO_API
  Adds/removes the service Pwm_GetVersionInfo() 
  from the code 
  - if STD_ON, Pwm_GetVersionInfo() can be used
  - if STD_OFF, Pwm_GetVersionInfo() cannot be used
*/
#define PWM_VERSION_INFO_API                 (STD_OFF)


/*
  Configuration: PWM_17_GTM_SYNCGRPUPDATEDUTIES_ENABLE
  Adds/removes the service Pwm_17_Gtm_SyncGrpUpdateDutiesApi() 
  from the code 
  - if STD_ON, Pwm_17_Gtm_SyncGrpUpdateDutiesApi() can be used
  - if STD_OFF, Pwm_17_Gtm_SyncGrpUpdateDutiesApi() cannot be used
*/
#define PWM_17_GTM_SYNCGRPUPDATEDUTIES_ENABLE                     (STD_OFF)



/* Total no. of config sets */
#define PWM_17_GTM_CONFIG_COUNT  (1U)
/* Configuration : PwmPBFixedAddress
   This parameter enables the user to switch STD_ON/STD_OFF the
   PostBuild Fixed Address Feature  
*/
#define PWM_PB_FIXEDADDR           (STD_OFF)


/* Configuration : PwmDutyShiftInTicks
   This parameter enables the user to enter the duty cycle and 
   shift value in absolute ticks, instead of percentage
*/
#define PWM_DUTY_SHIFT_IN_TICKS     (STD_OFF)


/* Configured PWM Channels Symbolic Names */
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_REF_RES
#define Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_REF_RES     ((Pwm_17_Gtm_ChannelType)0)
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_UH
#define Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_UH     ((Pwm_17_Gtm_ChannelType)1)
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_UL
#define Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_UL     ((Pwm_17_Gtm_ChannelType)2)
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_VH
#define Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_VH     ((Pwm_17_Gtm_ChannelType)3)
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_VL
#define Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_VL     ((Pwm_17_Gtm_ChannelType)4)
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_WH
#define Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_WH     ((Pwm_17_Gtm_ChannelType)5)
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_WL
#define Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_WL     ((Pwm_17_Gtm_ChannelType)6)
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M2_PWM_REF_RES
#define Pwm_17_GtmConf_PwmChannel_DPO_M2_PWM_REF_RES     ((Pwm_17_Gtm_ChannelType)7)
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M2_PWM_UH
#define Pwm_17_GtmConf_PwmChannel_DPO_M2_PWM_UH     ((Pwm_17_Gtm_ChannelType)8)
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M2_PWM_UL
#define Pwm_17_GtmConf_PwmChannel_DPO_M2_PWM_UL     ((Pwm_17_Gtm_ChannelType)9)
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M2_PWM_VH
#define Pwm_17_GtmConf_PwmChannel_DPO_M2_PWM_VH     ((Pwm_17_Gtm_ChannelType)10)
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M2_PWM_VL
#define Pwm_17_GtmConf_PwmChannel_DPO_M2_PWM_VL     ((Pwm_17_Gtm_ChannelType)11)
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M2_PWM_WH
#define Pwm_17_GtmConf_PwmChannel_DPO_M2_PWM_WH     ((Pwm_17_Gtm_ChannelType)12)
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M2_PWM_WL
#define Pwm_17_GtmConf_PwmChannel_DPO_M2_PWM_WL     ((Pwm_17_Gtm_ChannelType)13)
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M3_PWM_REF_RES
#define Pwm_17_GtmConf_PwmChannel_DPO_M3_PWM_REF_RES     ((Pwm_17_Gtm_ChannelType)14)
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M3_PWM_UH
#define Pwm_17_GtmConf_PwmChannel_DPO_M3_PWM_UH     ((Pwm_17_Gtm_ChannelType)15)
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M3_PWM_UL
#define Pwm_17_GtmConf_PwmChannel_DPO_M3_PWM_UL     ((Pwm_17_Gtm_ChannelType)16)
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M3_PWM_VH
#define Pwm_17_GtmConf_PwmChannel_DPO_M3_PWM_VH     ((Pwm_17_Gtm_ChannelType)17)
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M3_PWM_VL
#define Pwm_17_GtmConf_PwmChannel_DPO_M3_PWM_VL     ((Pwm_17_Gtm_ChannelType)18)
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M3_PWM_WH
#define Pwm_17_GtmConf_PwmChannel_DPO_M3_PWM_WH     ((Pwm_17_Gtm_ChannelType)19)
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M3_PWM_WL
#define Pwm_17_GtmConf_PwmChannel_DPO_M3_PWM_WL     ((Pwm_17_Gtm_ChannelType)20)
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M4_PWM_REF_RES
#define Pwm_17_GtmConf_PwmChannel_DPO_M4_PWM_REF_RES     ((Pwm_17_Gtm_ChannelType)21)
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M4_PWM_UH
#define Pwm_17_GtmConf_PwmChannel_DPO_M4_PWM_UH     ((Pwm_17_Gtm_ChannelType)22)
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M4_PWM_UL
#define Pwm_17_GtmConf_PwmChannel_DPO_M4_PWM_UL     ((Pwm_17_Gtm_ChannelType)23)
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M4_PWM_VH
#define Pwm_17_GtmConf_PwmChannel_DPO_M4_PWM_VH     ((Pwm_17_Gtm_ChannelType)24)
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M4_PWM_VL
#define Pwm_17_GtmConf_PwmChannel_DPO_M4_PWM_VL     ((Pwm_17_Gtm_ChannelType)25)
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M4_PWM_WH
#define Pwm_17_GtmConf_PwmChannel_DPO_M4_PWM_WH     ((Pwm_17_Gtm_ChannelType)26)
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M4_PWM_WL
#define Pwm_17_GtmConf_PwmChannel_DPO_M4_PWM_WL     ((Pwm_17_Gtm_ChannelType)27)
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_ADCTRIGGER
#define Pwm_17_GtmConf_PwmChannel_DPO_M1_PWM_ADCTRIGGER     ((Pwm_17_Gtm_ChannelType)28)
#endif

/* Configured PWM Groups Symbolic Names */


/*
   Configuration:Max channels configured for Pwm
   Maximum Channels is calculated based on the number of channels configured 
   for each configuration.For instance if configuration set 1 has 5 channels 
   and configuration set 2 has 7 channels then the Maxchannels is 7.
*/


#define PWM_MAX_CHANNELS   ((Pwm_17_Gtm_ChannelType)29)

#define PWM_MAX_QM_CHANNELS    (29)

/*
   Derived pre compile switches for optimization
   purpose
*/

#define PWM_VARIABLE_PERIOD_USED                     (STD_OFF)
#define PWM_FIXED_PERIOD_USED                        (STD_ON)
#define PWM_FIXED_PERIOD_SHIFTED_USED                (STD_OFF)
#define PWM_USED_FIXED_PERIOD_CENTER_ALIGNED         (STD_ON)

/* Values to be update Shadow register to get 0% and 100% duty*/
#define PWM_SR0_VALUE    (1U)
#define PWM_SR1_VALUE    (0U)

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

#endif

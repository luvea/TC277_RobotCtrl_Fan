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
**   $FILENAME   : Dio_Cfg.h $                                                **
**                                                                            **
**   $CC VERSION : \main\44 $                                                 **
**                                                                            **
**   DATE, TIME  : 2021-04-08, 20:15:41                                       **
**                                                                            **
**   GENERATOR   : Build b141014-0350                                         **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : DIO configuration generated out of ECU configuration       **
**                  file                                                      **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*******************************************************************************/

#ifndef DIO_CFG_H
#define DIO_CFG_H
/*
 Notes:
 - The runtime configuration is handled by the Port Driver Module.
 - The configuration and usage of the DIO Driver Module is adapted to
   the microcontroller and ECU.

*/

/*Version check macros */
#define DIO_AR_RELEASE_MAJOR_VERSION     (4U)
#define DIO_AR_RELEASE_MINOR_VERSION     (0U)
#define DIO_AR_RELEASE_REVISION_VERSION  (3U)

#define DIO_SW_MAJOR_VERSION  (3U)
#define DIO_SW_MINOR_VERSION  (1U)
#define DIO_SW_PATCH_VERSION  (0U)

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*                          Container: DioSafety                             */
/*
Configuration: DIO_SAFETY_ENABLE
- if STD_ON, Safety feature is available
- if STD_OFF, Safety feature is not available
*/
#define DIO_SAFETY_ENABLE                   (STD_OFF)

/*
Configuration: DIO_INITCHECK_API
- if STD_ON, Dio_InitCheck API is available
- if STD_OFF, Dio_InitCheck API is not available
*/
#define DIO_INITCHECK_API                   (STD_OFF)

/*                          Container: DioGeneral                            */
/*
Configuration: PORT_PB_FIXED_ADDRESS
- if STD_ON, PortPBFixedAddress feature is available
- if STD_OFF, PortPBFixedAddress feature is not available
*/
#define DIO_PB_FIXED_ADDRESS                (STD_OFF)

/*
  Pre-processor switch to enable/disable detection of Development errors.
  - if defined ON, Development error detection is enabled
  - if defined OFF, Development error detection is disabled
*/
#define DIO_DEV_ERROR_DETECT                (STD_OFF)

/*
  Pre-Compiler switch to include the API Dio_GetVersionInfo()
  - if defined ON, Dio_GetVersionInfo API available
  - if defined OFF, Dio_GetVersionInfo API not available
*/
#define DIO_VERSION_INFO_API                (STD_OFF)

/*
  Pre-Compiler switch to include the API Dio_FlipChannel()
  - if defined ON, Dio_FlipChannel API available
  - if defined OFF, Dio_FlipChannel API not available
*/
#define DIO_FLIP_CHANNEL_API                (STD_ON)

/*
Configuration: DIO_RUNNING_IN_USER_0_MODE_ENABLE
- if STD_ON, enable User0 mode
- if STD_OFF, enable User1 mode
*/
#define DIO_RUNNING_IN_USER_0_MODE_ENABLE   (STD_OFF)

/*
Configuration: DIO_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API
- if STD_OFF, Enable Supervisor mode in Init API
*/
#define DIO_USER_MODE_INIT_API_ENABLE         (STD_OFF)

/*
Configuration: DIO_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in APIs other than Init/Deinit APIs
- if STD_OFF, Enable Supervisor mode in APIs other than Init/Deinit APIs
*/
#define DIO_USER_MODE_RUNTIME_API_ENABLE           (STD_OFF)

/* No. of Configuration Sets */
#define DIO_CONFIG_COUNT                     (1U)

#define DIO_CH_GRP_SET_U                    (0U)

/* To specify if Loadable or Selectable configuration is used */
#define DIO_LOADABLE_USED      (STD_OFF)

/* The following macros are available only if development error detection
   or safety is on is enabled */


/* Values to mask the undefined port pins within a port */
#define DIO_MASK_UNDEF_PINS_PORT0             (0x1fffU)
#define DIO_MASK_UNDEF_PINS_PORT1             (0x00f8U)
#define DIO_MASK_UNDEF_PINS_PORT2             (0x0fffU)
#define DIO_MASK_UNDEF_PINS_PORT3             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT4             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT5             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT6             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT7             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT8             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT9             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT10             (0x01ffU)
#define DIO_MASK_UNDEF_PINS_PORT11             (0xffffU)
#define DIO_MASK_UNDEF_PINS_PORT12             (0x0003U)
#define DIO_MASK_UNDEF_PINS_PORT13             (0x000fU)
#define DIO_MASK_UNDEF_PINS_PORT14             (0x07ffU)
#define DIO_MASK_UNDEF_PINS_PORT15             (0x01ffU)
#define DIO_MASK_UNDEF_PINS_PORT16             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT17             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT18             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT19             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT20             (0x7fcfU)
#define DIO_MASK_UNDEF_PINS_PORT21             (0x00ffU)
#define DIO_MASK_UNDEF_PINS_PORT22             (0x0fffU)
#define DIO_MASK_UNDEF_PINS_PORT23             (0x00ffU)
#define DIO_MASK_UNDEF_PINS_PORT24             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT25             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT26             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT27             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT28             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT29             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT30             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT31             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT32             (0x00fdU)
#define DIO_MASK_UNDEF_PINS_PORT33             (0xffffU)
#define DIO_MASK_UNDEF_PINS_PORT34             (0x003eU)
#define DIO_MASK_UNDEF_PINS_PORT35             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT36             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT37             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT38             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT39             (0x0000U)
#define DIO_MASK_UNDEF_PINS_PORT40             (0x03ffU)
#define DIO_MASK_UNDEF_PINS_PORT41             (0x0000U)

/*******************************************************************************
**                           Global Symbols                                   **
*******************************************************************************/

/*
 Symbolic names for DIO Channels, Port & Channel groups
*/
/*
                       Symbolic names for Channels
*/
#define DIO_CHANNEL_0_0                    ((Dio_ChannelType)0x000)
#define DIO_CHANNEL_0_1                    ((Dio_ChannelType)0x001)
#define DIO_CHANNEL_0_2                    ((Dio_ChannelType)0x002)
#define DIO_CHANNEL_0_3                    ((Dio_ChannelType)0x003)
#define DIO_CHANNEL_0_4                    ((Dio_ChannelType)0x004)
#define DIO_CHANNEL_0_5                    ((Dio_ChannelType)0x005)
#define DIO_CHANNEL_0_6                    ((Dio_ChannelType)0x006)
#define DIO_CHANNEL_0_7                    ((Dio_ChannelType)0x007)
#define DIO_CHANNEL_0_8                    ((Dio_ChannelType)0x008)
#define DIO_CHANNEL_0_9                    ((Dio_ChannelType)0x009)
#define DIO_CHANNEL_0_10                    ((Dio_ChannelType)0x00a)
#define DIO_CHANNEL_0_11                    ((Dio_ChannelType)0x00b)
#define DIO_CHANNEL_0_12                    ((Dio_ChannelType)0x00c)
#define DIO_CHANNEL_1_3                    ((Dio_ChannelType)0x013)
#define DIO_CHANNEL_1_4                    ((Dio_ChannelType)0x014)
#define DIO_CHANNEL_1_5                    ((Dio_ChannelType)0x015)
#define DIO_CHANNEL_1_6                    ((Dio_ChannelType)0x016)
#define DIO_CHANNEL_1_7                    ((Dio_ChannelType)0x017)
#define DIO_CHANNEL_2_0                    ((Dio_ChannelType)0x020)
#define DIO_CHANNEL_2_1                    ((Dio_ChannelType)0x021)
#define DIO_CHANNEL_2_2                    ((Dio_ChannelType)0x022)
#define DIO_CHANNEL_2_3                    ((Dio_ChannelType)0x023)
#define DIO_CHANNEL_2_4                    ((Dio_ChannelType)0x024)
#define DIO_CHANNEL_2_5                    ((Dio_ChannelType)0x025)
#define DIO_CHANNEL_2_6                    ((Dio_ChannelType)0x026)
#define DIO_CHANNEL_2_7                    ((Dio_ChannelType)0x027)
#define DIO_CHANNEL_2_8                    ((Dio_ChannelType)0x028)
#define DIO_CHANNEL_2_9                    ((Dio_ChannelType)0x029)
#define DIO_CHANNEL_2_10                    ((Dio_ChannelType)0x02a)
#define DIO_CHANNEL_2_11                    ((Dio_ChannelType)0x02b)
#define DIO_CHANNEL_10_0                    ((Dio_ChannelType)0x0a0)
#define DIO_CHANNEL_10_1                    ((Dio_ChannelType)0x0a1)
#define DIO_CHANNEL_10_2                    ((Dio_ChannelType)0x0a2)
#define DIO_CHANNEL_10_3                    ((Dio_ChannelType)0x0a3)
#define DIO_CHANNEL_10_4                    ((Dio_ChannelType)0x0a4)
#define DIO_CHANNEL_10_5                    ((Dio_ChannelType)0x0a5)
#define DIO_CHANNEL_10_6                    ((Dio_ChannelType)0x0a6)
#define DIO_CHANNEL_10_7                    ((Dio_ChannelType)0x0a7)
#define DIO_CHANNEL_10_8                    ((Dio_ChannelType)0x0a8)
#define DIO_CHANNEL_11_0                    ((Dio_ChannelType)0x0b0)
#define DIO_CHANNEL_11_1                    ((Dio_ChannelType)0x0b1)
#define DIO_CHANNEL_11_2                    ((Dio_ChannelType)0x0b2)
#define DIO_CHANNEL_11_3                    ((Dio_ChannelType)0x0b3)
#define DIO_CHANNEL_11_4                    ((Dio_ChannelType)0x0b4)
#define DIO_CHANNEL_11_5                    ((Dio_ChannelType)0x0b5)
#define DIO_CHANNEL_11_6                    ((Dio_ChannelType)0x0b6)
#define DIO_CHANNEL_11_7                    ((Dio_ChannelType)0x0b7)
#define DIO_CHANNEL_11_8                    ((Dio_ChannelType)0x0b8)
#define DIO_CHANNEL_11_9                    ((Dio_ChannelType)0x0b9)
#define DIO_CHANNEL_11_10                    ((Dio_ChannelType)0x0ba)
#define DIO_CHANNEL_11_11                    ((Dio_ChannelType)0x0bb)
#define DIO_CHANNEL_11_12                    ((Dio_ChannelType)0x0bc)
#define DIO_CHANNEL_11_13                    ((Dio_ChannelType)0x0bd)
#define DIO_CHANNEL_11_14                    ((Dio_ChannelType)0x0be)
#define DIO_CHANNEL_11_15                    ((Dio_ChannelType)0x0bf)
#define DIO_CHANNEL_12_0                    ((Dio_ChannelType)0x0c0)
#define DIO_CHANNEL_12_1                    ((Dio_ChannelType)0x0c1)
#define DIO_CHANNEL_13_0                    ((Dio_ChannelType)0x0d0)
#define DIO_CHANNEL_13_1                    ((Dio_ChannelType)0x0d1)
#define DIO_CHANNEL_13_2                    ((Dio_ChannelType)0x0d2)
#define DIO_CHANNEL_13_3                    ((Dio_ChannelType)0x0d3)
#define DIO_CHANNEL_14_0                    ((Dio_ChannelType)0x0e0)
#define DIO_CHANNEL_14_1                    ((Dio_ChannelType)0x0e1)
#define DIO_CHANNEL_14_2                    ((Dio_ChannelType)0x0e2)
#define DIO_CHANNEL_14_3                    ((Dio_ChannelType)0x0e3)
#define DIO_CHANNEL_14_4                    ((Dio_ChannelType)0x0e4)
#define DIO_CHANNEL_14_5                    ((Dio_ChannelType)0x0e5)
#define DIO_CHANNEL_14_6                    ((Dio_ChannelType)0x0e6)
#define DIO_CHANNEL_14_7                    ((Dio_ChannelType)0x0e7)
#define DIO_CHANNEL_14_8                    ((Dio_ChannelType)0x0e8)
#define DIO_CHANNEL_14_9                    ((Dio_ChannelType)0x0e9)
#define DIO_CHANNEL_14_10                    ((Dio_ChannelType)0x0ea)
#define DIO_CHANNEL_15_0                    ((Dio_ChannelType)0x0f0)
#define DIO_CHANNEL_15_1                    ((Dio_ChannelType)0x0f1)
#define DIO_CHANNEL_15_2                    ((Dio_ChannelType)0x0f2)
#define DIO_CHANNEL_15_3                    ((Dio_ChannelType)0x0f3)
#define DIO_CHANNEL_15_4                    ((Dio_ChannelType)0x0f4)
#define DIO_CHANNEL_15_5                    ((Dio_ChannelType)0x0f5)
#define DIO_CHANNEL_15_6                    ((Dio_ChannelType)0x0f6)
#define DIO_CHANNEL_15_7                    ((Dio_ChannelType)0x0f7)
#define DIO_CHANNEL_15_8                    ((Dio_ChannelType)0x0f8)
#define DIO_CHANNEL_20_0                    ((Dio_ChannelType)0x140)
#define DIO_CHANNEL_20_1                    ((Dio_ChannelType)0x141)
#define DIO_CHANNEL_20_2                    ((Dio_ChannelType)0x142)
#define DIO_CHANNEL_20_3                    ((Dio_ChannelType)0x143)
#define DIO_CHANNEL_20_6                    ((Dio_ChannelType)0x146)
#define DIO_CHANNEL_20_7                    ((Dio_ChannelType)0x147)
#define DIO_CHANNEL_20_8                    ((Dio_ChannelType)0x148)
#define DIO_CHANNEL_20_9                    ((Dio_ChannelType)0x149)
#define DIO_CHANNEL_20_10                    ((Dio_ChannelType)0x14a)
#define DIO_CHANNEL_20_11                    ((Dio_ChannelType)0x14b)
#define DIO_CHANNEL_20_12                    ((Dio_ChannelType)0x14c)
#define DIO_CHANNEL_20_13                    ((Dio_ChannelType)0x14d)
#define DIO_CHANNEL_20_14                    ((Dio_ChannelType)0x14e)
#define DIO_CHANNEL_21_0                    ((Dio_ChannelType)0x150)
#define DIO_CHANNEL_21_1                    ((Dio_ChannelType)0x151)
#define DIO_CHANNEL_21_2                    ((Dio_ChannelType)0x152)
#define DIO_CHANNEL_21_3                    ((Dio_ChannelType)0x153)
#define DIO_CHANNEL_21_4                    ((Dio_ChannelType)0x154)
#define DIO_CHANNEL_21_5                    ((Dio_ChannelType)0x155)
#define DIO_CHANNEL_21_6                    ((Dio_ChannelType)0x156)
#define DIO_CHANNEL_21_7                    ((Dio_ChannelType)0x157)
#define DIO_CHANNEL_22_0                    ((Dio_ChannelType)0x160)
#define DIO_CHANNEL_22_1                    ((Dio_ChannelType)0x161)
#define DIO_CHANNEL_22_2                    ((Dio_ChannelType)0x162)
#define DIO_CHANNEL_22_3                    ((Dio_ChannelType)0x163)
#define DIO_CHANNEL_22_4                    ((Dio_ChannelType)0x164)
#define DIO_CHANNEL_22_5                    ((Dio_ChannelType)0x165)
#define DIO_CHANNEL_22_6                    ((Dio_ChannelType)0x166)
#define DIO_CHANNEL_22_7                    ((Dio_ChannelType)0x167)
#define DIO_CHANNEL_22_8                    ((Dio_ChannelType)0x168)
#define DIO_CHANNEL_22_9                    ((Dio_ChannelType)0x169)
#define DIO_CHANNEL_22_10                    ((Dio_ChannelType)0x16a)
#define DIO_CHANNEL_22_11                    ((Dio_ChannelType)0x16b)
#define DIO_CHANNEL_23_0                    ((Dio_ChannelType)0x170)
#define DIO_CHANNEL_23_1                    ((Dio_ChannelType)0x171)
#define DIO_CHANNEL_23_2                    ((Dio_ChannelType)0x172)
#define DIO_CHANNEL_23_3                    ((Dio_ChannelType)0x173)
#define DIO_CHANNEL_23_4                    ((Dio_ChannelType)0x174)
#define DIO_CHANNEL_23_5                    ((Dio_ChannelType)0x175)
#define DIO_CHANNEL_23_6                    ((Dio_ChannelType)0x176)
#define DIO_CHANNEL_23_7                    ((Dio_ChannelType)0x177)
#define DIO_CHANNEL_32_0                    ((Dio_ChannelType)0x200)
#define DIO_CHANNEL_32_2                    ((Dio_ChannelType)0x202)
#define DIO_CHANNEL_32_3                    ((Dio_ChannelType)0x203)
#define DIO_CHANNEL_32_4                    ((Dio_ChannelType)0x204)
#define DIO_CHANNEL_32_5                    ((Dio_ChannelType)0x205)
#define DIO_CHANNEL_32_6                    ((Dio_ChannelType)0x206)
#define DIO_CHANNEL_32_7                    ((Dio_ChannelType)0x207)
#define DIO_CHANNEL_33_0                    ((Dio_ChannelType)0x210)
#define DIO_CHANNEL_33_1                    ((Dio_ChannelType)0x211)
#define DIO_CHANNEL_33_2                    ((Dio_ChannelType)0x212)
#define DIO_CHANNEL_33_3                    ((Dio_ChannelType)0x213)
#define DIO_CHANNEL_33_4                    ((Dio_ChannelType)0x214)
#define DIO_CHANNEL_33_5                    ((Dio_ChannelType)0x215)
#define DIO_CHANNEL_33_6                    ((Dio_ChannelType)0x216)
#define DIO_CHANNEL_33_7                    ((Dio_ChannelType)0x217)
#define DIO_CHANNEL_33_8                    ((Dio_ChannelType)0x218)
#define DIO_CHANNEL_33_9                    ((Dio_ChannelType)0x219)
#define DIO_CHANNEL_33_10                    ((Dio_ChannelType)0x21a)
#define DIO_CHANNEL_33_11                    ((Dio_ChannelType)0x21b)
#define DIO_CHANNEL_33_12                    ((Dio_ChannelType)0x21c)
#define DIO_CHANNEL_33_13                    ((Dio_ChannelType)0x21d)
#define DIO_CHANNEL_33_14                    ((Dio_ChannelType)0x21e)
#define DIO_CHANNEL_33_15                    ((Dio_ChannelType)0x21f)
#define DIO_CHANNEL_34_1                    ((Dio_ChannelType)0x221)
#define DIO_CHANNEL_34_2                    ((Dio_ChannelType)0x222)
#define DIO_CHANNEL_34_3                    ((Dio_ChannelType)0x223)
#define DIO_CHANNEL_34_4                    ((Dio_ChannelType)0x224)
#define DIO_CHANNEL_34_5                    ((Dio_ChannelType)0x225)
#define DIO_CHANNEL_40_0                    ((Dio_ChannelType)0x280)
#define DIO_CHANNEL_40_1                    ((Dio_ChannelType)0x281)
#define DIO_CHANNEL_40_2                    ((Dio_ChannelType)0x282)
#define DIO_CHANNEL_40_3                    ((Dio_ChannelType)0x283)
#define DIO_CHANNEL_40_4                    ((Dio_ChannelType)0x284)
#define DIO_CHANNEL_40_5                    ((Dio_ChannelType)0x285)
#define DIO_CHANNEL_40_6                    ((Dio_ChannelType)0x286)
#define DIO_CHANNEL_40_7                    ((Dio_ChannelType)0x287)
#define DIO_CHANNEL_40_8                    ((Dio_ChannelType)0x288)
#define DIO_CHANNEL_40_9                    ((Dio_ChannelType)0x289)


/*
                      Symbolic names for DIO ports
*/
#define DIO_PORT_0                          ((Dio_PortType)0)
#define DIO_PORT_1                          ((Dio_PortType)1)
#define DIO_PORT_2                          ((Dio_PortType)2)
#define DIO_PORT_10                          ((Dio_PortType)10)
#define DIO_PORT_11                          ((Dio_PortType)11)
#define DIO_PORT_12                          ((Dio_PortType)12)
#define DIO_PORT_13                          ((Dio_PortType)13)
#define DIO_PORT_14                          ((Dio_PortType)14)
#define DIO_PORT_15                          ((Dio_PortType)15)
#define DIO_PORT_20                          ((Dio_PortType)20)
#define DIO_PORT_21                          ((Dio_PortType)21)
#define DIO_PORT_22                          ((Dio_PortType)22)
#define DIO_PORT_23                          ((Dio_PortType)23)
#define DIO_PORT_32                          ((Dio_PortType)32)
#define DIO_PORT_33                          ((Dio_PortType)33)
#define DIO_PORT_34                          ((Dio_PortType)34)
#define DIO_PORT_40                          ((Dio_PortType)40)


/* Number of Channel groups configured for the DioConfig1 */
#define DIO_CHANNELGROUPCOUNT_0   (0U)
/*
      User Defined Symbolic Names for the DIO Ports, Channels & Channel Groups
      DioConfig 1
*/


/*
  DIO PORT : (DioConf_DioPort_DioPort_22)
*/
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioPort_DioPort_22
#define DioConf_DioPort_DioPort_22 (DIO_PORT_22)
#endif


/* DIO Channel : (DioConf_DioChannel_DI_HALL_M1_A) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_DI_HALL_M1_A
#define DioConf_DioChannel_DI_HALL_M1_A (DIO_CHANNEL_22_2)
#endif


/* DIO Channel : (DioConf_DioChannel_DI_HALL_M1_B) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_DI_HALL_M1_B
#define DioConf_DioChannel_DI_HALL_M1_B (DIO_CHANNEL_22_3)
#endif


/* DIO Channel : (DioConf_DioChannel_DI_HALL_M4_B) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_DI_HALL_M4_B
#define DioConf_DioChannel_DI_HALL_M4_B (DIO_CHANNEL_22_4)
#endif


/* DIO Channel : (DioConf_DioChannel_DI_HALL_M4_C) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_DI_HALL_M4_C
#define DioConf_DioChannel_DI_HALL_M4_C (DIO_CHANNEL_22_5)
#endif


/*
  DIO PORT : (DioConf_DioPort_DioPort_23)
*/
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioPort_DioPort_23
#define DioConf_DioPort_DioPort_23 (DIO_PORT_23)
#endif


/* DIO Channel : (DioConf_DioChannel_DI_HALL_M1_C) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_DI_HALL_M1_C
#define DioConf_DioChannel_DI_HALL_M1_C (DIO_CHANNEL_23_1)
#endif


/* DIO Channel : (DioConf_DioChannel_GPIO_12V_PEN) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_GPIO_12V_PEN
#define DioConf_DioChannel_GPIO_12V_PEN (DIO_CHANNEL_23_6)
#endif


/* DIO Channel : (DioConf_DioChannel_DI_HALL_M4_A) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_DI_HALL_M4_A
#define DioConf_DioChannel_DI_HALL_M4_A (DIO_CHANNEL_23_3)
#endif


/*
  DIO PORT : (DioConf_DioPort_DioPort_2)
*/
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioPort_DioPort_2
#define DioConf_DioPort_DioPort_2 (DIO_PORT_2)
#endif


/* DIO Channel : (DioConf_DioChannel_DO_DRV_INH_N) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_DO_DRV_INH_N
#define DioConf_DioChannel_DO_DRV_INH_N (DIO_CHANNEL_2_7)
#endif


/* DIO Channel : (DioConf_DioChannel_JESTON_SLEEP_WAKE) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_JESTON_SLEEP_WAKE
#define DioConf_DioChannel_JESTON_SLEEP_WAKE (DIO_CHANNEL_2_0)
#endif


/* DIO Channel : (DioConf_DioChannel_GPIO_5V_SHUT_OFF) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_GPIO_5V_SHUT_OFF
#define DioConf_DioChannel_GPIO_5V_SHUT_OFF (DIO_CHANNEL_2_8)
#endif


/*
  DIO PORT : (DioConf_DioPort_DioPort_33)
*/
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioPort_DioPort_33
#define DioConf_DioPort_DioPort_33 (DIO_PORT_33)
#endif


/* DIO Channel : (DioConf_DioChannel_DO_DRV_ENA) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_DO_DRV_ENA
#define DioConf_DioChannel_DO_DRV_ENA (DIO_CHANNEL_33_13)
#endif


/*
  DIO PORT : (DioConf_DioPort_DioPort_0)
*/
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioPort_DioPort_0
#define DioConf_DioPort_DioPort_0 (DIO_PORT_0)
#endif


/* DIO Channel : (DioConf_DioChannel_DO_DRV_SOFT_N) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_DO_DRV_SOFT_N
#define DioConf_DioChannel_DO_DRV_SOFT_N (DIO_CHANNEL_0_11)
#endif


/* DIO Channel : (DioConf_DioChannel_GPIO_5V_JESTON_NEN) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_GPIO_5V_JESTON_NEN
#define DioConf_DioChannel_GPIO_5V_JESTON_NEN (DIO_CHANNEL_0_12)
#endif


/* DIO Channel : (DioConf_DioChannel_DI_HALL_M2_A) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_DI_HALL_M2_A
#define DioConf_DioChannel_DI_HALL_M2_A (DIO_CHANNEL_0_1)
#endif


/*
  DIO PORT : (DioConf_DioPort_DioPort_11)
*/
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioPort_DioPort_11
#define DioConf_DioPort_DioPort_11 (DIO_PORT_11)
#endif


/* DIO Channel : (DioConf_DioChannel_DO_SPI_DRIVER_CS1) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_DO_SPI_DRIVER_CS1
#define DioConf_DioChannel_DO_SPI_DRIVER_CS1 (DIO_CHANNEL_11_0)
#endif


/* DIO Channel : (DioConf_DioChannel_JESTON_EN) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_JESTON_EN
#define DioConf_DioChannel_JESTON_EN (DIO_CHANNEL_11_9)
#endif


/* DIO Channel : (DioConf_DioChannel_JESTON_RESET) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_JESTON_RESET
#define DioConf_DioChannel_JESTON_RESET (DIO_CHANNEL_11_8)
#endif


/* DIO Channel : (DioConf_DioChannel_JESTON_SHUTDOWN) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_JESTON_SHUTDOWN
#define DioConf_DioChannel_JESTON_SHUTDOWN (DIO_CHANNEL_11_2)
#endif


/* DIO Channel : (DioConf_DioChannel_GPIO_1V8_EN) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_GPIO_1V8_EN
#define DioConf_DioChannel_GPIO_1V8_EN (DIO_CHANNEL_11_7)
#endif


/* DIO Channel : (DioConf_DioChannel_D0_USS1_TX) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_D0_USS1_TX
#define DioConf_DioChannel_D0_USS1_TX (DIO_CHANNEL_11_1)
#endif


/* DIO Channel : (DioConf_DioChannel_DI_SEN_POW_PG) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_DI_SEN_POW_PG
#define DioConf_DioChannel_DI_SEN_POW_PG (DIO_CHANNEL_11_3)
#endif


/* DIO Channel : (DioConf_DioChannel_DI_UART_RESERVE_RX) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_DI_UART_RESERVE_RX
#define DioConf_DioChannel_DI_UART_RESERVE_RX (DIO_CHANNEL_11_10)
#endif


/* DIO Channel : (DioConf_DioChannel_DO_UART_RESERVE_TX) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_DO_UART_RESERVE_TX
#define DioConf_DioChannel_DO_UART_RESERVE_TX (DIO_CHANNEL_11_12)
#endif


/*
  DIO PORT : (DioConf_DioPort_DioPort_14)
*/
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioPort_DioPort_14
#define DioConf_DioPort_DioPort_14 (DIO_PORT_14)
#endif


/* DIO Channel : (DioConf_DioChannel_DO_SEN_POW_EN) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_DO_SEN_POW_EN
#define DioConf_DioChannel_DO_SEN_POW_EN (DIO_CHANNEL_14_9)
#endif


/* DIO Channel : (DioConf_DioChannel_DO_USS2_TX) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_DO_USS2_TX
#define DioConf_DioChannel_DO_USS2_TX (DIO_CHANNEL_14_10)
#endif


/*
  DIO PORT : (DioConf_DioPort_DioPort_15)
*/
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioPort_DioPort_15
#define DioConf_DioPort_DioPort_15 (DIO_PORT_15)
#endif


/* DIO Channel : (DioConf_DioChannel_DI_HALL_M2_B) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_DI_HALL_M2_B
#define DioConf_DioChannel_DI_HALL_M2_B (DIO_CHANNEL_15_1)
#endif


/* DIO Channel : (DioConf_DioChannel_DI_HALL_M2_C) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_DI_HALL_M2_C
#define DioConf_DioChannel_DI_HALL_M2_C (DIO_CHANNEL_15_2)
#endif


/* DIO Channel : (DioConf_DioChannel_DI_HALL_M3_A) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_DI_HALL_M3_A
#define DioConf_DioChannel_DI_HALL_M3_A (DIO_CHANNEL_15_3)
#endif


/* DIO Channel : (DioConf_DioChannel_DI_HALL_M3_B) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_DI_HALL_M3_B
#define DioConf_DioChannel_DI_HALL_M3_B (DIO_CHANNEL_15_4)
#endif


/* DIO Channel : (DioConf_DioChannel_DI_HALL_M3_C) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_DI_HALL_M3_C
#define DioConf_DioChannel_DI_HALL_M3_C (DIO_CHANNEL_15_5)
#endif


/*
  DIO PORT : (DioConf_DioPort_DioPort_13)
*/
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioPort_DioPort_13
#define DioConf_DioPort_DioPort_13 (DIO_PORT_13)
#endif


/* DIO Channel : (DioConf_DioChannel_DO_STB) */
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef DioConf_DioChannel_DO_STB
#define DioConf_DioChannel_DO_STB (DIO_CHANNEL_13_1)
#endif



/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Type                                      **
*******************************************************************************/

/* End of DIO_CFG_H */
#endif

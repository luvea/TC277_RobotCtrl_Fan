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
**  $FILENAME   : Can_17_MCanP_Cfg.h $                                       **
**                                                                            **
**  $CC VERSION : \main\dev_tc23x_as4.0.3\23 $                               **
**                                                                            **
**  DATE, TIME: 2021-04-08, 20:15:38                                      **
**                                                                            **
**  GENERATOR : Build b141014-0350                                          **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : CAN configuration generated out of ECU configuration       ** 
**                   file (Can_17_MCanP.bmd)                                  **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/

/**  TRACEABILITY: [cover parentID=DS_AS_CAN047,
                   DS_NAS_PR446,DS_AS4XX_CAN_PR2849,SAS_NAS_CAN_PR914,
                   SAS_NAS_CAN_PR915,SAS_AS4XX_CAN_PR678,SAS_NAS_CAN_PR916
                   DS_NAS_HE2_CAN_PR2893,DS_NAS_EP_CAN_PR2893,
                   DS_NAS_EP_CAN_PR3054_1,DS_NAS_EP_CAN_PR3054_2,
                   DS_NAS_EP_CAN_PR3054_3,DS_NAS_EP_CAN_PR3054_4]             **
**                                                                            **
**  [/cover]                                                                 **/


#ifndef CAN_17_MCANP_CFG_H
#define CAN_17_MCANP_CFG_H


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/

/* Autosar specification version */

#define CAN_17_MCANP_AS_VERSION (403)
#define CAN_17_MCANP_AR_RELEASE_MAJOR_VERSION  (4U)
#define CAN_17_MCANP_AR_RELEASE_MINOR_VERSION  (0U)
#define CAN_17_MCANP_AR_RELEASE_REVISION_VERSION  (3U)

/* Vendor specific implementation version information */
#define CAN_17_MCANP_SW_MAJOR_VERSION  (2U)
#define CAN_17_MCANP_SW_MINOR_VERSION  (6U)
#define CAN_17_MCANP_SW_PATCH_VERSION  (1U)


/*******************************************************************************
**                     Configuration options                                  **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/* Number of Config sets */
#define CAN_CONFIG_COUNT  (1U)

/* Number of Kernels available in the device */
#define CAN_NUM_KERNELS_IN_DEVICE  (1U)

/* Number of CAN Controllers available in the device */
#define CAN_NUM_CONTROLLERS_IN_DEVICE  (4U)

/* Number of CAN Controllers available in the First Kernel */
#define CAN_NUM_CONTROLLERS_IN_KERNEL1  (4U)

/* Maximum number of CAN Controllers configured in a ConfigSet */
#define CAN_NUM_CONTROLLER_MAX         (4U)

/* Maximum transmit hardware objects ID configured in a ConfigSet */
#define CAN_TX_HARDWARE_OBJECTID_MAX   (7U)

/* Maximum number of transmit hardware objects configured in a ConfigSet */
#define CAN_TX_HARDWARE_OBJECTS_MAX    (7U)

/* Maximum number of receive hardware objects configured in a ConfigSet */
#define CAN_RX_HARDWARE_OBJECTS_MAX    (0U)

/* Maximum number of Rx FIFO configurations in a ConfigSet */
#define CAN_NUM_RX_FIFO_MAX            (0U)

/* Configured Message Identifier Type */
/* STD_ON  : Only Standard Message Identifiers are configured */
/* STD_OFF : At least one Extended/Mixed Message Identifier is configured */
#define CAN_STANDARD_ID_ONLY           (STD_ON) 

/*******************************************************************************
**                      CAN General Information                               **
*******************************************************************************/
/* Is fOSC clock selected as the input source for CAN Baud rate calculations? */
#define CAN_BR_EXT_OSLTR_CLKSEL           (STD_OFF)

/* Is ERAY clock selected as the input source for CAN Baud rate calculations? */
#define CAN_BR_ERAY_PLL_CLKSEL           (STD_OFF)

/* Is FD enabled ? */
#define CAN_FD_ENABLE           (STD_OFF)

/* Is Any Recieve hardware object configured in Kernal 0 ? */
#define CAN_RX_OBJECT_KER0           (STD_OFF)

/* Is Any Recieve hardware object configured in Kernal 1 ? */
#define CAN_RX_OBJECT_KER1           (STD_OFF)

/* Is Any Transmit hardware object configured in Kernal 0 ? */
#define CAN_TX_OBJECT_KER0           (STD_ON)

/* Is Any Transmit hardware object configured in Kernal 1 ? */
#define CAN_TX_OBJECT_KER1           (STD_OFF)

/*Can ISO Hardware enable switch*/
#define CAN_HARDWARE_ISO_SUPPORT     (STD_ON)

/*Can ISO Supporting Kernals*/
#define CAN_ISO_NUM_KERNEL                      (1U)

/*Configuration value to enable or disable ISO or Non ISO frame feature*/
#define CAN_ISO_FRAME                           (0U)

/*Configuration value to enable or disable protocol exception feature*/
#define CAN_PROTOCAL_EXCEPTION                  (0U)

/* Configuration: CAN_17_MCANP_INSTANCE_ID
 - Specifies the InstanceId of this module instance
*/
#define CAN_17_MCANP_INSTANCE_ID                (0U)

/* Configuration: CAN_DEV_ERROR_DETECT
 - STD_ON  - DET is enabled
 - STD_OFF - DET is disabled
*/      
#define CAN_DEV_ERROR_DETECT           (STD_OFF)

/* Configuration: CAN_VERSION_INFO_API
 - STD_ON  - Can_17_MCanP_GetVersionInfo API is enabled
 - STD_OFF - Can_17_MCanP_GetVersionInfo API is disabled
*/      
#define CAN_VERSION_INFO_API           (STD_OFF)

/* Configuration: CAN_MULTIPLEXED_TRANSMISSION
 - STD_ON  - Multiplexed transmission feature is enabled
 - STD_OFF - Multiplexed transmission feature is disabled
*/      
#define CAN_MULTIPLEXED_TRANSMISSION   (STD_OFF)

/* Configuration: CAN_TIMEOUT_DURATION
 - Specifies the maximum number of loops for blocking function until 
   a timeout is raised in short term wait loops
*/
#define CAN_TIMEOUT_DURATION    (400U)

/* Configuration: CAN_PB_FIXEDADDR
 - STD_ON  - PB fixed address optimization is enabled 
 - STD_OFF - PB fixed address optimization is disabled 
*/
#define CAN_PB_FIXEDADDR               (STD_OFF)

/* Configuration: CAN_DEBUG_SUPPORT
 - STD_ON  - Debug support is enabled 
 - STD_OFF - Debug support is disabled 
*/
#define CAN_DEBUG_SUPPORT              (STD_OFF)

/* Configuration: CAN_CHANGE_BAUDRATE_API
 - STD_ON  - Can_17_MCanP_CheckBaudrate and Can_17_MCanP_ChangeBaudrate 
             APIs are enabled
 - STD_OFF - Can_17_MCanP_CheckBaudrate and Can_17_MCanP_ChangeBaudrate 
             APIs are disabled
*/
#define CAN_CHANGE_BAUDRATE_API              (STD_OFF)

#define CAN_RESET_SFR_AT_INIT              (STD_OFF)

/* Configuration: CAN_RESET_SFR_AT_INIT
 - STD_ON  - CAN Kernel Registers?reset feature is enabled
 - STD_OFF - CAN Kernel Registers?reset feature is not enabled
*/

#define CAN_DEINIT_API              (STD_OFF)

/* Configuration: CAN_DEINIT_API
 - STD_ON  - CAN De-initialization API is enabled
 - STD_OFF - CAN De-initialization API is not enabled
*/

/* CAN Hardware Timeout DEM */
#define CAN_E_TIMEOUT_DEM_REPORT   (CAN_DISABLE_DEM_REPORT)


#define  CAN_DEINIT_API (STD_OFF)


/*
Configuration: CAN_RUNNING_IN_USER_0_MODE_ENABLE 
- if STD_ON, enable User0 mode 
- if STD_OFF, enable User1 mode 
*/
#define CAN_RUNNING_IN_USER_0_MODE_ENABLE (STD_OFF)

/*
Configuration: CAN_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Enable Supervisor mode in Init API  
*/
#define  CAN_USER_MODE_INIT_API_ENABLE (STD_OFF)

/*Configuration: CAN_USER_MODE_DEINIT_API_ENABLE
- if STD_ON, Enable Protected mode in DeInit API 
- if STD_OFF, Disable Protected mode in DeInit API
*/
#define  CAN_USER_MODE_DEINIT_API_ENABLE (STD_OFF)

/*Configuration: CAN_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected mode in APIs other than Init/Deinit APIs
- if STD_OFF, Disable Protected mode in APIs other than Init/Deinit APIs
*/
#define  CAN_USER_MODE_RUNTIME_API_ENABLE (STD_OFF)


/******************************************************************************/
                    /* CAN Controller Configurations */
/******************************************************************************/

/******************************************************************************/
              /* CONTROLLER_0_MULTICANPLUS_NODE0 Configuration */
/******************************************************************************/

/* CONTROLLER_0_MULTICANPLUS_NODE0 Activation 
 - STD_ON  - Controller is used
 - STD_OFF - Controller is NOT used
*/      
#define CAN_HWCONTROLLER0_ACTIVATION           (STD_ON)

/* CONTROLLER_0_MULTICANPLUS_NODE0 Transmit Confirmation Event Processing
 - CAN_INTERRUPT - Transmission is notified through interrupt mechanism
 - CAN_POLLING   - Transmission is notified through polling mechanism  
*/      
#define CAN_TX_PROCESSING_HWCONTROLLER0        (CAN_INTERRUPT)

/* CONTROLLER_0_MULTICANPLUS_NODE0 Receive Indication Event Processing
 - CAN_INTERRUPT - Reception is notified through interrupt mechanism
 - CAN_POLLING   - Reception is notified through polling mechanism  
*/      
#define CAN_RX_PROCESSING_HWCONTROLLER0        (CAN_INTERRUPT)

/* CONTROLLER_0_MULTICANPLUS_NODE0 Wakeup Event Processing
 - CAN_INTERRUPT - Wakeup event is  notified through interrupt mechanism
 - CAN_POLLING   - Wakeup event is notified through polling mechanism  
*/      
#define CAN_WU_PROCESSING_HWCONTROLLER0        (CAN_NO_PROCESSING)

/* CONTROLLER_0_MULTICANPLUS_NODE0 Bus-Off Event Processing
 - CAN_INTERRUPT - Bus-off event notified through interrupt mechanism
 - CAN_POLLING   - Bus-off event notified through polling mechanism  
*/
#define CAN_BO_PROCESSING_HWCONTROLLER0        (CAN_INTERRUPT)

/******************************************************************************/
              /* CONTROLLER_1_MULTICANPLUS_NODE1 Configuration */
/******************************************************************************/

/* CONTROLLER_1_MULTICANPLUS_NODE1 Activation 
 - STD_ON  - Controller is used
 - STD_OFF - Controller is NOT used
*/      
#define CAN_HWCONTROLLER1_ACTIVATION           (STD_ON)

/* CONTROLLER_1_MULTICANPLUS_NODE1 Transmit Confirmation Event Processing
 - CAN_INTERRUPT - Transmission is notified through interrupt mechanism
 - CAN_POLLING   - Transmission is notified through polling mechanism  
*/      
#define CAN_TX_PROCESSING_HWCONTROLLER1        (CAN_INTERRUPT)

/* CONTROLLER_1_MULTICANPLUS_NODE1 Receive Indication Event Processing
 - CAN_INTERRUPT - Reception is notified through interrupt mechanism
 - CAN_POLLING   - Reception is notified through polling mechanism  
*/      
#define CAN_RX_PROCESSING_HWCONTROLLER1        (CAN_INTERRUPT)

/* CONTROLLER_1_MULTICANPLUS_NODE1 Wakeup Event Processing
 - CAN_INTERRUPT - Wakeup event is  notified through interrupt mechanism
 - CAN_POLLING   - Wakeup event is notified through polling mechanism  
*/      
#define CAN_WU_PROCESSING_HWCONTROLLER1        (CAN_NO_PROCESSING)

/* CONTROLLER_1_MULTICANPLUS_NODE1 Bus-Off Event Processing
 - CAN_INTERRUPT - Bus-off event notified through interrupt mechanism
 - CAN_POLLING   - Bus-off event notified through polling mechanism  
*/
#define CAN_BO_PROCESSING_HWCONTROLLER1        (CAN_INTERRUPT)

/******************************************************************************/
              /* CONTROLLER_2_MULTICANPLUS_NODE2 Configuration */
/******************************************************************************/

/* CONTROLLER_2_MULTICANPLUS_NODE2 Activation 
 - STD_ON  - Controller is used
 - STD_OFF - Controller is NOT used
*/      
#define CAN_HWCONTROLLER2_ACTIVATION           (STD_ON)

/* CONTROLLER_2_MULTICANPLUS_NODE2 Transmit Confirmation Event Processing
 - CAN_INTERRUPT - Transmission is notified through interrupt mechanism
 - CAN_POLLING   - Transmission is notified through polling mechanism  
*/      
#define CAN_TX_PROCESSING_HWCONTROLLER2        (CAN_INTERRUPT)

/* CONTROLLER_2_MULTICANPLUS_NODE2 Receive Indication Event Processing
 - CAN_INTERRUPT - Reception is notified through interrupt mechanism
 - CAN_POLLING   - Reception is notified through polling mechanism  
*/      
#define CAN_RX_PROCESSING_HWCONTROLLER2        (CAN_INTERRUPT)

/* CONTROLLER_2_MULTICANPLUS_NODE2 Wakeup Event Processing
 - CAN_INTERRUPT - Wakeup event is  notified through interrupt mechanism
 - CAN_POLLING   - Wakeup event is notified through polling mechanism  
*/      
#define CAN_WU_PROCESSING_HWCONTROLLER2        (CAN_NO_PROCESSING)

/* CONTROLLER_2_MULTICANPLUS_NODE2 Bus-Off Event Processing
 - CAN_INTERRUPT - Bus-off event notified through interrupt mechanism
 - CAN_POLLING   - Bus-off event notified through polling mechanism  
*/
#define CAN_BO_PROCESSING_HWCONTROLLER2        (CAN_INTERRUPT)

/******************************************************************************/
              /* CONTROLLER_3_MULTICANPLUS_NODE3 Configuration */
/******************************************************************************/

/* CONTROLLER_3_MULTICANPLUS_NODE3 Activation 
 - STD_ON  - Controller is used
 - STD_OFF - Controller is NOT used
*/      
#define CAN_HWCONTROLLER3_ACTIVATION           (STD_ON)

/* CONTROLLER_3_MULTICANPLUS_NODE3 Transmit Confirmation Event Processing
 - CAN_INTERRUPT - Transmission is notified through interrupt mechanism
 - CAN_POLLING   - Transmission is notified through polling mechanism  
*/      
#define CAN_TX_PROCESSING_HWCONTROLLER3        (CAN_INTERRUPT)

/* CONTROLLER_3_MULTICANPLUS_NODE3 Receive Indication Event Processing
 - CAN_INTERRUPT - Reception is notified through interrupt mechanism
 - CAN_POLLING   - Reception is notified through polling mechanism  
*/      
#define CAN_RX_PROCESSING_HWCONTROLLER3        (CAN_INTERRUPT)

/* CONTROLLER_3_MULTICANPLUS_NODE3 Wakeup Event Processing
 - CAN_INTERRUPT - Wakeup event is  notified through interrupt mechanism
 - CAN_POLLING   - Wakeup event is notified through polling mechanism  
*/      
#define CAN_WU_PROCESSING_HWCONTROLLER3        (CAN_NO_PROCESSING)

/* CONTROLLER_3_MULTICANPLUS_NODE3 Bus-Off Event Processing
 - CAN_INTERRUPT - Bus-off event notified through interrupt mechanism
 - CAN_POLLING   - Bus-off event notified through polling mechanism  
*/
#define CAN_BO_PROCESSING_HWCONTROLLER3        (CAN_INTERRUPT)

/****************** End Of CAN Controller Configurations **********************/

/* Configuration: CAN_WAKEUP_CONFIGURED
 - STD_ON  - At least one of the CAN controllers supports wakeup
 - STD_OFF - None of the CAN controllers supports wakeup
*/      
#define CAN_WAKEUP_CONFIGURED                  (STD_OFF)

/* Configuration: CAN_LPDU_RX_CALLOUT
 - STD_ON  - L-PDU receive callout support enabled
 - STD_OFF - L-PDU receive callout support disabled
*/      
#define CAN_LPDU_RX_CALLOUT                    (STD_OFF)

/*******************************************************************************
    Symbolic Name Defintions of CAN Controllers and CAN Hardware Objects
*******************************************************************************/

/*******************************************************************************
    CanConfigSet_0 -> Symbolic Name Defintions of CAN Controllers 
*******************************************************************************/

#ifdef Can_17_MCanPConf_CanController_CanController_0 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanController_CanController_0 != 0U)
    #error Can_17_MCanPConf_CanController_CanController_0 is already defined with a different value
  #endif  
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters 
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanController_CanController_0   (0U) 
#endif /* #ifdef Can_17_MCanPConf_CanController_CanController_0 */
#ifdef Can_17_MCanPConf_CanController_CanController_1 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanController_CanController_1 != 1U)
    #error Can_17_MCanPConf_CanController_CanController_1 is already defined with a different value
  #endif  
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters 
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanController_CanController_1   (1U) 
#endif /* #ifdef Can_17_MCanPConf_CanController_CanController_1 */
#ifdef Can_17_MCanPConf_CanController_CanController_2 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanController_CanController_2 != 2U)
    #error Can_17_MCanPConf_CanController_CanController_2 is already defined with a different value
  #endif  
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters 
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanController_CanController_2   (2U) 
#endif /* #ifdef Can_17_MCanPConf_CanController_CanController_2 */
#ifdef Can_17_MCanPConf_CanController_CanController_3 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanController_CanController_3 != 3U)
    #error Can_17_MCanPConf_CanController_CanController_3 is already defined with a different value
  #endif  
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters 
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanController_CanController_3   (3U) 
#endif /* #ifdef Can_17_MCanPConf_CanController_CanController_3 */

/*******************************************************************************
    CanConfigSet_0 -> Symbolic Name Defintions of CAN Hardware Objects 
*******************************************************************************/

#ifdef Can_17_MCanPConf_CanHardwareObject_Hall_Timestamp /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_Hall_Timestamp != 0U)
    #error Can_17_MCanPConf_CanHardwareObject_Hall_Timestamp is already defined with a different value
  #endif  
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters 
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_Hall_Timestamp   (0U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_Hall_Timestamp */
#ifdef Can_17_MCanPConf_CanHardwareObject_Adc3ph_U /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_Adc3ph_U != 1U)
    #error Can_17_MCanPConf_CanHardwareObject_Adc3ph_U is already defined with a different value
  #endif  
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters 
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_Adc3ph_U   (1U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_Adc3ph_U */
#ifdef Can_17_MCanPConf_CanHardwareObject_Adc3ph_V /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_Adc3ph_V != 2U)
    #error Can_17_MCanPConf_CanHardwareObject_Adc3ph_V is already defined with a different value
  #endif  
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters 
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_Adc3ph_V   (2U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_Adc3ph_V */
#ifdef Can_17_MCanPConf_CanHardwareObject_Adc3ph_W /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_Adc3ph_W != 3U)
    #error Can_17_MCanPConf_CanHardwareObject_Adc3ph_W is already defined with a different value
  #endif  
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters 
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_Adc3ph_W   (3U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_Adc3ph_W */
#ifdef Can_17_MCanPConf_CanHardwareObject_DC_Link_1 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_DC_Link_1 != 4U)
    #error Can_17_MCanPConf_CanHardwareObject_DC_Link_1 is already defined with a different value
  #endif  
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters 
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_DC_Link_1   (4U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_DC_Link_1 */
#ifdef Can_17_MCanPConf_CanHardwareObject_DC_Link_2 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_DC_Link_2 != 5U)
    #error Can_17_MCanPConf_CanHardwareObject_DC_Link_2 is already defined with a different value
  #endif  
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters 
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_DC_Link_2   (5U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_DC_Link_2 */
#ifdef Can_17_MCanPConf_CanHardwareObject_VRO_9180 /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_VRO_9180 != 6U)
    #error Can_17_MCanPConf_CanHardwareObject_VRO_9180 is already defined with a different value
  #endif  
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters 
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_VRO_9180   (6U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_VRO_9180 */


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

#endif  /* CAN_17_MCANP_CFG_H */

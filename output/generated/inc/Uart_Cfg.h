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
**  $FILENAME   : Uart_Cfg.h $                                               **
**                                                                            **
**  $CC VERSION : \main\20 $                                                 **
**                                                                            **
**  DATE, TIME: 2021-04-08, 20:15:41                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Uart configuration generated out of ECU configuration      **
**                 file                                                       **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/
#ifndef UART_CFG_H 
#define UART_CFG_H 

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*SW Version Information*/
#define UART_SW_MAJOR_VERSION   (1U)
#define UART_SW_MINOR_VERSION   (3U)
#define UART_SW_PATCH_VERSION   (0U)

/*
         Container : UartGeneral Configuration
*/

/*
Derived Configuration for UartDevErrorDetect 
- if STD_ON, DET is Enabled 
- if STD_OFF,DET is Disabled
The detection of all development errors is configurable (On / Off) 
at precompile time. The switch UART_DEV_ERROR_DETECT  shall
activate or deactivate the detection of all development errors.

If the switch UART_DEV_ERROR_DETECT is enabled API parameter checking
is also enabled. 
*/
#define UART_DEV_ERROR_DETECT  (STD_OFF)

/*
Derived Configuration for UartVersionInfoApi 
- if STD_ON, Function Uart_GetVersionInfo is available  
- if STD_OFF,Function Uart_GetVersionInfo is not available 
*/
#define UART_VERSION_INFO_API  (STD_OFF)

/*
Derived Configuration for UartPBFixedAddress 
- if STD_ON, Fixed Address feature is Enabled 
- if STD_OFF,Fixed Address feature is Disabled
*/
#define UART_PB_FIXEDADDR  (STD_OFF)

/*
Derived Configuration for UartDeinitApi 
- if STD_ON, Function UartDeinitApi is available  
- if STD_OFF,Function UartDeinitApi is not available 
*/
#define UART_DEINIT_API  (STD_OFF)
/*
Derived Configuration for UartAbortReadApi 
- if STD_ON, Function UartAbortReadApi is available  
- if STD_OFF,Function UartAbortReadApi is not available 
*/
#define UART_ABORT_READ_API  (STD_ON)
/*
Derived Configuration for UartAbortWriteApi
- if STD_ON, Function UartAbortWriteApi is available  
- if STD_OFF,Function UartAbortWriteApi is not available 
*/
#define UART_ABORT_WRITE_API  (STD_ON)

/* Derived Configuration for UartDebugSupport*/
#define UART_DEBUG_SUPPORT  (STD_OFF)

/* Derived Configuration for UartResetSfrAtInit*/
#define UART_RESET_SFR_INIT  (STD_OFF)


/*
Configuration: UART_RUNNING_IN_USER_0_MODE_ENABLE 
- if STD_ON, enable User0 mode 
- if STD_OFF, enable User1 mode 
*/
#define UART_RUNNING_IN_USER_0_MODE_ENABLE (STD_OFF)

/*
Configuration: UART_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Enable Supervisor mode in Init API  
*/
#define  UART_USER_MODE_INIT_API_ENABLE (STD_OFF)

/*Configuration: UART_USER_MODE_DEINIT_API_ENABLE
- if STD_ON, Enable Protected mode in DeInit API 
- if STD_OFF, Disable Protected mode in DeInit API
*/
#define  UART_USER_MODE_DEINIT_API_ENABLE (STD_OFF)

/*Configuration: UART_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected mode in APIs other than Init/Deinit APIs
- if STD_OFF, Disable Protected mode in APIs other than Init/Deinit APIs
*/
#define  UART_USER_MODE_RUNTIME_API_ENABLE (STD_OFF)

/* Derived Configuration for UartIndex*/
#define UART_INDEX  (0U)

/* Total no. of config sets */
#define UART_CONFIG_COUNT    (1U)

/* Total Number of ASCLIN HW Units Available*/
#define UART_MAX_HW_UNIT (4U)

#define UART_ASCLIN0 (0U)
#define UART_ASCLIN1 (1U)
#define UART_ASCLIN2 (2U)
#define UART_ASCLIN3 (3U)

/* 
Derived Configuration for UartDataLength  
Flag Indicating if 9 bit Datalength is used in Any Configuration Set
*/
#define UART_NINEBITS_USED (STD_OFF)

/* 
Configuration : UART_MAXIMUM_CHANNEL 
Maximum of No. of Uart channels configured in different PB Config Sets
*/
#define UART_MAXIMUM_CHANNEL (3U)


/*
Configuration: UART_ASCLINx_USED 
- if STD_ON, ASCLINx is used   
- if STD_OFF,ASCLINx is not used  
*/

#define UART_ASCLIN0_USED  (STD_ON)
#define UART_ASCLIN1_USED  (STD_ON)
#define UART_ASCLIN2_USED  (STD_OFF)
#define UART_ASCLIN3_USED  (STD_ON)

/* Derived Configuration for UartSleepEnable*/
#define UART_ASCLIN_CLC (0x08U)

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
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif  /* UART_CFG_H */


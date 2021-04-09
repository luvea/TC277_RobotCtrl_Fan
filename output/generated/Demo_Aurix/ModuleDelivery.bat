@ECHO OFF
REM ****************************************************************************
REM *                                                                         **
REM * Copyright (C) Infineon Technologies (2013)                              **
REM *                                                                         **
REM * All rights reserved.                                                    **
REM *                                                                         **
REM * This document contains proprietary information belonging to Infineon    **
REM * Technologies. Passing on and copying of this document, and communication**
REM * of its contents is not permitted without prior written authorization.   **
REM *                                                                         **
REM ****************************************************************************
REM *                                                                         **
REM *  FILENAME  : ModuleDelivery.bat                                         **
REM *                                                                         **
REM *  VERSION   : 1.1.0                                                      **
REM *                                                                         **
REM *  DATE,TIME : 2021-04-08, 20:15:40                                       **
REM *                                                                         **
REM *  AUTHOR    : DL-AUTOSAR-Engineering                                     **
REM *                                                                         **
REM *  VENDOR    : Infineon Technologies                                      **
REM *                                                                         **
REM *  DESCRIPTION  : This file creates the Demo Modules that are delivered.  **
REM *                                                                         **
REM *  MAY BE CHANGED BY USER [yes/no]: YES                                   **
REM *                                                                         **
REM ***************************************************************************/

SET MCU_DELIVERY=STD_ON
SET PORT_DELIVERY=STD_ON
SET DIO_DELIVERY=STD_ON
SET GPT_DELIVERY=STD_OFF
SET SPI_DELIVERY=STD_OFF
SET SPI_SLAVE_DELIVERY=STD_OFF
SET PWM_DELIVERY=STD_ON
SET ADC_DELIVERY=STD_ON
SET MLI_DELIVERY=STD_OFF
SET FADC_DELIVERY=STD_OFF
SET DMA_DELIVERY=STD_OFF
SET FEE_DELIVERY=STD_OFF
SET FLS_DELIVERY=STD_OFF
SET FLSLOADER_DELIVERY=STD_OFF
SET HSSL_DELIVERY=STD_OFF
SET GTM_DELIVERY=STD_ON
SET WDG_DELIVERY=STD_OFF
SET ICU_DELIVERY=STD_ON
SET ERU_DELIVERY=STD_OFF
SET CCU_DELIVERY=STD_OFF
SET CAN_DELIVERY=STD_ON
SET MSC_DELIVERY=STD_OFF
SET MCHK_DELIVERY=STD_OFF
SET SCI_DELIVERY=STD_OFF
SET FR_DELIVERY=STD_OFF
SET LIN_DELIVERY=STD_OFF
SET UART_DELIVERY=STD_ON
SET ETH_DELIVERY=STD_OFF
SET CRC_DELIVERY=STD_OFF
SET SENT_DELIVERY=STD_OFF
SET IOM_DELIVERY=STD_OFF
SET DEM_DELIVERY=STD_OFF
SET RAMTST_DELIVERY=STD_OFF
SET CANTRCV_6250GV33_DELIVERY=STD_OFF
SET CANTRCV_6251G_DELIVERY=STD_OFF
SET STM_DELIVERY=STD_OFF
SET STDLIN_DELIVERY=STD_OFF
SET DSADC_DELIVERY=STD_OFF
SET SMU_DELIVERY=STD_OFF
IF "%SAFETLIB_USED%" == "STD_ON" SET SMU_DELIVERY=STD_OFF
SET I2C_DELIVERY=STD_OFF
SET OS_DELIVERY=STD_OFF

:nextpart

SET CONTROLLER=TC27x

REM STD_OFF for Variant LT. STD_ON for Variant PB
SET DIO_TYPE=STD_ON

SET MCAL_AUTOSAR_VERSION=AS40X


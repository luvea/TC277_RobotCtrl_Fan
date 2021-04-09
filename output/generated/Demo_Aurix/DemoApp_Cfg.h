
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
**   $FILENAME   : DemoApp_Cfg.h $                                            **
**                                                                            **
**   $CC VERSION : \main\27 $                                                 **
**                                                                            **
**  DATE, TIME: 2021-04-08, 20:15:40                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : DemoApp configuration generated out of ECU configuration   **
**                 file                                                       **
**                                                                            **
**  SPECIFICATION(S) : NA                                                     **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#ifndef  DEMOAPP_CFG_H
#define  DEMOAPP_CFG_H

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/************************* Demo Application Configuration *********************/

#define PRE_COMPILE_DELIVERY           (1U)
#define POST_BUILD_DELIVERY            (2U)
#define LINK_TIME_DELIVERY             (3U) 
/*NOTE: At a time only one type of delivery for a particular module is possible 
and not both the deliveries*/ 
/************************** Basic Driver Modules ******************************/

#define MCU_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define PORT_DELIVERY_TYPE             (POST_BUILD_DELIVERY)
#define DIO_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define GPT_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define SPI_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define PWM_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define ADC_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define MLI_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define FADC_DELIVERY_TYPE             (POST_BUILD_DELIVERY)
#define DMA_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define FEE_DELIVERY_TYPE              (PRE_COMPILE_DELIVERY)
#define FLS_DELIVERY_TYPE              (PRE_COMPILE_DELIVERY)
#define FLSLOADER_DELIVERY_TYPE        (PRE_COMPILE_DELIVERY)
#define HSSL_DELIVERY_TYPE             (PRE_COMPILE_DELIVERY)
#define STDLIN_DELIVERY_TYPE           (PRE_COMPILE_DELIVERY)
#define CRC_DELIVERY_TYPE         	   (PRE_COMPILE_DELIVERY)
#define GTM_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define WDG_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define ICU_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define ERU_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define CAN_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define MSC_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define MCHK_DELIVERY_TYPE             (POST_BUILD_DELIVERY)
#define SCI_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define FR_DELIVERY_TYPE               (POST_BUILD_DELIVERY)
#define LIN_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define UART_DELIVERY_TYPE             (POST_BUILD_DELIVERY)
#define ETH_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define CCU_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define SENT_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define IOM_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define CANTRCV_6251G_DELIVERY_TYPE    (PRE_COMPILE_DELIVERY)
#define CANTRCV_6250GV33_DELIVERY_TYPE (PRE_COMPILE_DELIVERY)
#define SMU_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define I2C_DELIVERY_TYPE              (POST_BUILD_DELIVERY)



#define MCU_DELIVERY                   (STD_ON)
#define PORT_DELIVERY                  (STD_ON)
#define DIO_DELIVERY                   (STD_ON)
#define GTM_DELIVERY                   (STD_ON)
#define GPT_DELIVERY                   (STD_OFF)
#define SPI_DELIVERY                   (STD_OFF)
#define SPI_SLAVE_DELIVERY             (STD_OFF)
#define PWM_DELIVERY                   (STD_ON)
#define ADC_DELIVERY                   (STD_ON)
#define MLI_DELIVERY                   (STD_OFF)
#define FADC_DELIVERY                  (STD_OFF)
#define DMA_DELIVERY                   (STD_OFF)
/* Note that the FLS Delivery must be ON if FEE is ON */
#define FEE_DELIVERY                   (STD_OFF)
#define FLS_DELIVERY                   (STD_OFF)
#define FLSLOADER_DELIVERY             (STD_OFF)
#define HSSL_DELIVERY                  (STD_OFF)
#define WDG_DELIVERY                   (STD_OFF)
#define ICU_DELIVERY                   (STD_ON)
#define ERU_DELIVERY                   (STD_OFF)
#define CAN_DELIVERY                   (STD_ON)
#define MSC_DELIVERY                   (STD_OFF)
#define MCHK_DELIVERY                  (STD_OFF)
#define SCI_DELIVERY                   (STD_OFF)
#define FR_DELIVERY                    (STD_OFF)
#define ETH_DELIVERY                   (STD_OFF)
#define CRC_DELIVERY                   (STD_OFF)
#define LIN_DELIVERY                   (STD_OFF)
#define UART_DELIVERY                  (STD_ON)
#define RAMTST_DELIVERY                (STD_OFF)
#define CCU_DELIVERY                   (STD_OFF)
#define SENT_DELIVERY                  (STD_OFF)
#define IOM_DELIVERY                   (STD_OFF)
#define STM_DELIVERY                   (STD_OFF)
#define CANTRCV_6251G_DELIVERY         (STD_OFF)
#define CANTRCV_6250GV33_DELIVERY      (STD_OFF)
#define STDLIN_DELIVERY                (STD_OFF)
#define DSADC_DELIVERY                   (STD_OFF)
#define SMU_DELIVERY                   (STD_OFF)
#define I2C_DELIVERY                   (STD_OFF)
#define OS_DELIVERY                   (STD_OFF)

#endif /* DEMOAPP_CFG_H */

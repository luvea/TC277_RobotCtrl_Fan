
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
**   $FILENAME   : Irq_Cfg.h $                                                **
**                                                                            **
**   $CC VERSION : \main\38 $                                                 **
**                                                                            **
**   DATE, TIME: 2021-04-08, 20:15:41                                         **
**                                                                            **
**   GENERATOR : Build b141014-0350                                           **
**                                                                            **
**   AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                            **
**   VENDOR    : Infineon Technologies                                        **
**                                                                            **
**   DESCRIPTION  : Irq configuration generated out of ECU configuration      **
**                 file                                                       **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                            **
*******************************************************************************/
#ifndef IRQ_CFG_H 
#define IRQ_CFG_H 


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/************************* interrupt CATEGORY *********************************/
#define IRQ_CAT1                    (0)
#define IRQ_CAT23                   (1)
/************************* interrupt Type of Service **************************/
#define IRQ_TOS_CPU0                (0x0000)
#define IRQ_TOS_CPU1                (0x0800)
#define IRQ_TOS_CPU2                (0x1000)
#define IRQ_TOS_DMA                 (0x1800)
/*
                     Container : IrqGeneralConfiguration
*/

/*
Configuration: IRQ_OSEK_ENABLE 
- if TRUE, OSEK RTOS is used, 
  Both CAT1 and CAT23 interrupt categories can be configured 
  Any CAT23 interrupt priority should be greater than CAT1 interrupt priority
- if FALSE,OSEK RTOS is not used
  Only CAT1 interrupt category can be configured 
*/

#define IRQ_OSEK_ENABLE             (STD_OFF)


/*
                     Container : IrqAscLin interruptConfiguration
*/
/* ASC Lin Tx interrupt Category Setting*/
#define IRQ_ASCLIN0_TX_CAT          (IRQ_CAT1)
#define IRQ_ASCLIN1_TX_CAT          (IRQ_CAT1)
#define IRQ_ASCLIN2_TX_CAT          (IRQ_CAT1)
#define IRQ_ASCLIN3_TX_CAT          (IRQ_CAT1)

/* ASC Lin Tx interrupt Priority Setting*/
#define IRQ_ASCLIN0_TX_PRIO         0x7c
#define IRQ_ASCLIN1_TX_PRIO         0x7d
#define IRQ_ASCLIN2_TX_PRIO         0x0
#define IRQ_ASCLIN3_TX_PRIO         0x7e

/* ASC Lin Tx interrupt type of service Setting*/
#define IRQ_ASCLIN0_TX_TOS          (IRQ_TOS_CPU0)
#define IRQ_ASCLIN1_TX_TOS          (IRQ_TOS_CPU0)
#define IRQ_ASCLIN2_TX_TOS          (IRQ_TOS_CPU0)
#define IRQ_ASCLIN3_TX_TOS          (IRQ_TOS_CPU0)

/* ASC Lin Rx interrupt Category Setting*/
#define IRQ_ASCLIN0_RX_CAT          (IRQ_CAT1)
#define IRQ_ASCLIN1_RX_CAT          (IRQ_CAT1)
#define IRQ_ASCLIN2_RX_CAT          (IRQ_CAT1)
#define IRQ_ASCLIN3_RX_CAT          (IRQ_CAT1)

/* ASC Lin Rx interrupt Priority Setting*/
#define IRQ_ASCLIN0_RX_PRIO         0x7f
#define IRQ_ASCLIN1_RX_PRIO         0x80
#define IRQ_ASCLIN2_RX_PRIO         0x0
#define IRQ_ASCLIN3_RX_PRIO         0x81

/* ASC Lin Rx interrupt type of service Setting*/
#define IRQ_ASCLIN0_RX_TOS          (IRQ_TOS_CPU0)
#define IRQ_ASCLIN1_RX_TOS          (IRQ_TOS_CPU0)
#define IRQ_ASCLIN2_RX_TOS          (IRQ_TOS_CPU0)
#define IRQ_ASCLIN3_RX_TOS          (IRQ_TOS_CPU0)

/* ASC Lin Err interrupt Category Setting*/
#define IRQ_ASCLIN0_ERR_CAT         (IRQ_CAT1)
#define IRQ_ASCLIN1_ERR_CAT         (IRQ_CAT1)
#define IRQ_ASCLIN2_ERR_CAT         (IRQ_CAT1)
#define IRQ_ASCLIN3_ERR_CAT         (IRQ_CAT1)

/* ASC Lin Err interrupt Priority Setting*/
#define IRQ_ASCLIN0_ERR_PRIO        0x82
#define IRQ_ASCLIN1_ERR_PRIO        0x83
#define IRQ_ASCLIN2_ERR_PRIO        0x0
#define IRQ_ASCLIN3_ERR_PRIO        0x84

/* ASC Lin Err interrupt type of service Setting*/
#define IRQ_ASCLIN0_ERR_TOS         (IRQ_TOS_CPU0)
#define IRQ_ASCLIN1_ERR_TOS         (IRQ_TOS_CPU0)
#define IRQ_ASCLIN2_ERR_TOS         (IRQ_TOS_CPU0)
#define IRQ_ASCLIN3_ERR_TOS         (IRQ_TOS_CPU0)

/*
                     Container : IrqQspi interruptConfiguration
*/
/* Qspi Tx interrupt Category Setting*/
#define IRQ_QSPI0_TX_CAT            (IRQ_CAT1)
#define IRQ_QSPI1_TX_CAT            (IRQ_CAT1)
#define IRQ_QSPI2_TX_CAT            (IRQ_CAT1)
#define IRQ_QSPI3_TX_CAT            (IRQ_CAT1)

/* Qspi Tx interrupt Priority Setting*/
#define IRQ_QSPI0_TX_PRIO           0x0
#define IRQ_QSPI1_TX_PRIO           0x0
#define IRQ_QSPI2_TX_PRIO           0x0
#define IRQ_QSPI3_TX_PRIO           0x0

/* Qspi Tx interrupt type of service Setting*/
#define IRQ_QSPI0_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI1_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI2_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI3_TX_TOS            (IRQ_TOS_CPU0)

/* Qspi Rx interrupt Category Setting*/
#define IRQ_QSPI0_RX_CAT            (IRQ_CAT1)
#define IRQ_QSPI1_RX_CAT            (IRQ_CAT1)
#define IRQ_QSPI2_RX_CAT            (IRQ_CAT1)
#define IRQ_QSPI3_RX_CAT            (IRQ_CAT1)

/* Qspi Rx interrupt Priority Setting*/
#define IRQ_QSPI0_RX_PRIO           0x0
#define IRQ_QSPI1_RX_PRIO           0x0
#define IRQ_QSPI2_RX_PRIO           0x0
#define IRQ_QSPI3_RX_PRIO           0x0

/* Qspi Rx interrupt type of service Setting*/
#define IRQ_QSPI0_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI1_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI2_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI3_RX_TOS            (IRQ_TOS_CPU0)

/* Qspi Err interrupt Category Setting*/
#define IRQ_QSPI0_ERR_CAT           (IRQ_CAT1)
#define IRQ_QSPI1_ERR_CAT           (IRQ_CAT1)
#define IRQ_QSPI2_ERR_CAT           (IRQ_CAT1)
#define IRQ_QSPI3_ERR_CAT           (IRQ_CAT1)

/* Qspi Err interrupt Priority Setting*/
#define IRQ_QSPI0_ERR_PRIO          0x0
#define IRQ_QSPI1_ERR_PRIO          0x0
#define IRQ_QSPI2_ERR_PRIO          0x0
#define IRQ_QSPI3_ERR_PRIO          0x0

/* Qspi Err interrupt type of service Setting*/
#define IRQ_QSPI0_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_QSPI1_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_QSPI2_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_QSPI3_ERR_TOS           (IRQ_TOS_CPU0)

/* Qspi PT interrupt Category Setting*/
#define IRQ_QSPI0_PT_CAT            (IRQ_CAT1)
#define IRQ_QSPI1_PT_CAT            (IRQ_CAT1)
#define IRQ_QSPI2_PT_CAT            (IRQ_CAT1)
#define IRQ_QSPI3_PT_CAT            (IRQ_CAT1)

/* Qspi PT interrupt Priority Setting*/
#define IRQ_QSPI0_PT_PRIO           0x0
#define IRQ_QSPI1_PT_PRIO           0x0
#define IRQ_QSPI2_PT_PRIO           0x0
#define IRQ_QSPI3_PT_PRIO           0x0

/* Qspi PT interrupt type of service Setting*/
#define IRQ_QSPI0_PT_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI1_PT_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI2_PT_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI3_PT_TOS            (IRQ_TOS_CPU0)

/* Qspi HC interrupt Category Setting*/
#define IRQ_QSPI0_HC_CAT            (IRQ_CAT1)
#define IRQ_QSPI1_HC_CAT            (IRQ_CAT1)
#define IRQ_QSPI2_HC_CAT            (IRQ_CAT1)
#define IRQ_QSPI3_HC_CAT            (IRQ_CAT1)

/* Qspi HC interrupt Priority Setting*/
#define IRQ_QSPI0_HC_PRIO           0x0
#define IRQ_QSPI1_HC_PRIO           0x0
#define IRQ_QSPI2_HC_PRIO           0x0
#define IRQ_QSPI3_HC_PRIO           0x0

/* Qspi HC interrupt type of service Setting*/
#define IRQ_QSPI0_HC_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI1_HC_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI2_HC_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI3_HC_TOS            (IRQ_TOS_CPU0)

/* Qspi UD interrupt Category Setting*/
#define IRQ_QSPI0_UD_CAT            (IRQ_CAT1)
#define IRQ_QSPI1_UD_CAT            (IRQ_CAT1)
#define IRQ_QSPI2_UD_CAT            (IRQ_CAT1)
#define IRQ_QSPI3_UD_CAT            (IRQ_CAT1)

/* Qspi UD interrupt Priority Setting*/
#define IRQ_QSPI0_UD_PRIO           0x0
#define IRQ_QSPI1_UD_PRIO           0x0
#define IRQ_QSPI2_UD_PRIO           0x0
#define IRQ_QSPI3_UD_PRIO           0x0

/* Qspi UD interrupt type of service Setting*/
#define IRQ_QSPI0_UD_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI1_UD_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI2_UD_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI3_UD_TOS            (IRQ_TOS_CPU0)

/*
                     Container : IrqMSC interruptConfiguration
*/
/*MSC0 interrupt Category setting */
#define IRQ_MSC0_SR0_CAT            (IRQ_CAT1)
#define IRQ_MSC0_SR1_CAT            (IRQ_CAT1)
#define IRQ_MSC0_SR2_CAT            (IRQ_CAT1)
#define IRQ_MSC0_SR3_CAT            (IRQ_CAT1)
#define IRQ_MSC0_SR4_CAT            (IRQ_CAT1)
                                                                                                           
/*MSC0 interrupt Priority setting */ 
#define IRQ_MSC0_SR0_PRIO           0x0
#define IRQ_MSC0_SR1_PRIO           0x0
#define IRQ_MSC0_SR2_PRIO           0x0
#define IRQ_MSC0_SR3_PRIO           0x0
#define IRQ_MSC0_SR4_PRIO           0x0

/*MSC0 interrupt type of service setting */
#define IRQ_MSC0_SR0_TOS            (IRQ_TOS_CPU0)
#define IRQ_MSC0_SR1_TOS            (IRQ_TOS_CPU0)
#define IRQ_MSC0_SR2_TOS            (IRQ_TOS_CPU0)
#define IRQ_MSC0_SR3_TOS            (IRQ_TOS_CPU0)
#define IRQ_MSC0_SR4_TOS            (IRQ_TOS_CPU0)

/*MSC1 interrupt Category setting */
#define IRQ_MSC1_SR0_CAT            (IRQ_CAT1)
#define IRQ_MSC1_SR1_CAT            (IRQ_CAT1)
#define IRQ_MSC1_SR2_CAT            (IRQ_CAT1)
#define IRQ_MSC1_SR3_CAT            (IRQ_CAT1)
#define IRQ_MSC1_SR4_CAT            (IRQ_CAT1)
                                                                                                           
/*MSC1 interrupt Priority setting */ 
#define IRQ_MSC1_SR0_PRIO           0x0
#define IRQ_MSC1_SR1_PRIO           0x0
#define IRQ_MSC1_SR2_PRIO           0x0
#define IRQ_MSC1_SR3_PRIO           0x0
#define IRQ_MSC1_SR4_PRIO           0x0

/*MSC1 interrupt type of service setting */
#define IRQ_MSC1_SR0_TOS            (IRQ_TOS_CPU0)
#define IRQ_MSC1_SR1_TOS            (IRQ_TOS_CPU0)
#define IRQ_MSC1_SR2_TOS            (IRQ_TOS_CPU0)
#define IRQ_MSC1_SR3_TOS            (IRQ_TOS_CPU0)
#define IRQ_MSC1_SR4_TOS            (IRQ_TOS_CPU0)


/*
                     Container : IrqCCU6 interruptConfiguration
*/
/*CCU60 interrupt Category setting */
#define IRQ_CCU60_SR0_CAT           (IRQ_CAT1)
#define IRQ_CCU60_SR1_CAT           (IRQ_CAT1)
#define IRQ_CCU60_SR2_CAT           (IRQ_CAT1)
#define IRQ_CCU60_SR3_CAT           (IRQ_CAT1)
                                                                                                           
/*CCU60 interrupt Priority setting */ 
#define IRQ_CCU60_SR0_PRIO          0x0
#define IRQ_CCU60_SR1_PRIO          0x0
#define IRQ_CCU60_SR2_PRIO          0x0
#define IRQ_CCU60_SR3_PRIO          0x0

/*CCU60 interrupt type of service setting */
#define IRQ_CCU60_SR0_TOS           (IRQ_TOS_CPU0)
#define IRQ_CCU60_SR1_TOS           (IRQ_TOS_CPU0)
#define IRQ_CCU60_SR2_TOS           (IRQ_TOS_CPU0)
#define IRQ_CCU60_SR3_TOS           (IRQ_TOS_CPU0)

/*CCU61 interrupt Category setting */
#define IRQ_CCU61_SR0_CAT           (IRQ_CAT1)
#define IRQ_CCU61_SR1_CAT           (IRQ_CAT1)
#define IRQ_CCU61_SR2_CAT           (IRQ_CAT1)
#define IRQ_CCU61_SR3_CAT           (IRQ_CAT1)
                                                                                                           
/*CCU61 interrupt Priority setting */ 
#define IRQ_CCU61_SR0_PRIO          0x0
#define IRQ_CCU61_SR1_PRIO          0x0
#define IRQ_CCU61_SR2_PRIO          0x0
#define IRQ_CCU61_SR3_PRIO          0x0

/*CCU61 interrupt type of service setting */
#define IRQ_CCU61_SR0_TOS           (IRQ_TOS_CPU0)
#define IRQ_CCU61_SR1_TOS           (IRQ_TOS_CPU0)
#define IRQ_CCU61_SR2_TOS           (IRQ_TOS_CPU0)
#define IRQ_CCU61_SR3_TOS           (IRQ_TOS_CPU0)

/*
                     Container : IrqGPTinterruptConfiguration
*/
/* GPT120 interrupt Category setting */
#define IRQ_GPT120_CARPEL_CAT       (IRQ_CAT1)
#define IRQ_GPT120_T2_CAT           (IRQ_CAT1)
#define IRQ_GPT120_T3_CAT           (IRQ_CAT1)
#define IRQ_GPT120_T4_CAT           (IRQ_CAT1)
#define IRQ_GPT120_T5_CAT           (IRQ_CAT1)
#define IRQ_GPT120_T6_CAT           (IRQ_CAT1)

/*  GPT120 interrupt Priority setting  */
#define IRQ_GPT120_CARPEL_PRIO      0x0
#define IRQ_GPT120_T2_PRIO          0x0
#define IRQ_GPT120_T3_PRIO          0x0
#define IRQ_GPT120_T4_PRIO          0x0
#define IRQ_GPT120_T5_PRIO          0x0
#define IRQ_GPT120_T6_PRIO          0x0

/* GPT120 interrupt type of service setting */
#define IRQ_GPT120_CARPEL_TOS       (IRQ_TOS_CPU0)
#define IRQ_GPT120_T2_TOS           (IRQ_TOS_CPU0)
#define IRQ_GPT120_T3_TOS           (IRQ_TOS_CPU0)
#define IRQ_GPT120_T4_TOS           (IRQ_TOS_CPU0)
#define IRQ_GPT120_T5_TOS           (IRQ_TOS_CPU0)
#define IRQ_GPT120_T6_TOS           (IRQ_TOS_CPU0)


/*
                     Container : IrqSTMinterruptConfiguration
*/
/* STM0 interrupt Category Setting */ 
#define IRQ_STM0_SR0_CAT            (IRQ_CAT1)
#define IRQ_STM0_SR1_CAT            (IRQ_CAT1)
                                                                                                           
/* STM0 interrupt Priority Setting */  
#define IRQ_STM0_SR0_PRIO           0x0
#define IRQ_STM0_SR1_PRIO           0x0

/* STM0 interrupt type of service Setting */ 
#define IRQ_STM0_SR0_TOS            (IRQ_TOS_CPU0)
#define IRQ_STM0_SR1_TOS            (IRQ_TOS_CPU0)

/* STM1 interrupt Category Setting */ 
#define IRQ_STM1_SR0_CAT            (IRQ_CAT1)
#define IRQ_STM1_SR1_CAT            (IRQ_CAT1)
                                                                                                           
/* STM1 interrupt Priority Setting */  
#define IRQ_STM1_SR0_PRIO           0x0
#define IRQ_STM1_SR1_PRIO           0x0

/* STM1 interrupt type of service Setting */ 
#define IRQ_STM1_SR0_TOS            (IRQ_TOS_CPU0)
#define IRQ_STM1_SR1_TOS            (IRQ_TOS_CPU0)

/* STM2 interrupt Category Setting */ 
#define IRQ_STM2_SR0_CAT            (IRQ_CAT1)
#define IRQ_STM2_SR1_CAT            (IRQ_CAT1)
                                                                                                           
/* STM2 interrupt Priority Setting */  
#define IRQ_STM2_SR0_PRIO           0x0
#define IRQ_STM2_SR1_PRIO           0x0

/* STM2 interrupt type of service Setting */ 
#define IRQ_STM2_SR0_TOS            (IRQ_TOS_CPU0)
#define IRQ_STM2_SR1_TOS            (IRQ_TOS_CPU0)

/*
                     Container : IrqDMAinterruptConfiguration
*/
/* DMA interrupt Category settings */
#define IRQ_DMA_ERR_SR_CAT           (IRQ_CAT1)
#define IRQ_DMA_CHANNEL0_SR_CAT      (IRQ_CAT1)
#define IRQ_DMA_CHANNEL1_SR_CAT      (IRQ_CAT1)
#define IRQ_DMA_CHANNEL2_SR_CAT      (IRQ_CAT1)
#define IRQ_DMA_CHANNEL3_SR_CAT      (IRQ_CAT1)
#define IRQ_DMA_CHANNEL4_SR_CAT      (IRQ_CAT1)
#define IRQ_DMA_CHANNEL5_SR_CAT      (IRQ_CAT1)
#define IRQ_DMA_CHANNEL6_SR_CAT      (IRQ_CAT1)
#define IRQ_DMA_CHANNEL7_SR_CAT      (IRQ_CAT1)
#define IRQ_DMA_CHANNEL8_SR_CAT      (IRQ_CAT1)
#define IRQ_DMA_CHANNEL9_SR_CAT      (IRQ_CAT1)
#define IRQ_DMA_CHANNEL10_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL11_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL12_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL13_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL14_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL15_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL16_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL17_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL18_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL19_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL20_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL21_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL22_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL23_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL24_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL25_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL26_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL27_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL28_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL29_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL30_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL31_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL32_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL33_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL34_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL35_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL36_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL37_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL38_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL39_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL40_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL41_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL42_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL43_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL44_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL45_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL46_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL47_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL48_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL49_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL50_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL51_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL52_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL53_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL54_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL55_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL56_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL57_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL58_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL59_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL60_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL61_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL62_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL63_SR_CAT     (IRQ_CAT1)

/* DMA interrupt Priority settings */
#define IRQ_DMA_ERR_SR_PRIO          0x0
#define IRQ_DMA_CHANNEL0_SR_PRIO     0x0
#define IRQ_DMA_CHANNEL1_SR_PRIO     0x0
#define IRQ_DMA_CHANNEL2_SR_PRIO     0x0
#define IRQ_DMA_CHANNEL3_SR_PRIO     0x0
#define IRQ_DMA_CHANNEL4_SR_PRIO     0x0
#define IRQ_DMA_CHANNEL5_SR_PRIO     0x0
#define IRQ_DMA_CHANNEL6_SR_PRIO     0x0
#define IRQ_DMA_CHANNEL7_SR_PRIO     0x0
#define IRQ_DMA_CHANNEL8_SR_PRIO     0x0
#define IRQ_DMA_CHANNEL9_SR_PRIO     0x0
#define IRQ_DMA_CHANNEL10_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL11_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL12_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL13_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL14_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL15_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL16_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL17_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL18_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL19_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL20_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL21_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL22_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL23_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL24_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL25_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL26_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL27_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL28_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL29_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL30_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL31_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL32_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL33_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL34_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL35_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL36_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL37_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL38_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL39_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL40_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL41_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL42_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL43_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL44_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL45_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL46_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL47_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL48_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL49_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL50_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL51_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL52_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL53_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL54_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL55_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL56_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL57_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL58_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL59_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL60_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL61_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL62_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL63_SR_PRIO    0x0

/* DMA interrupt type of service settings */
#define IRQ_DMA_ERR_SR_TOS           (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL0_SR_TOS      (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL1_SR_TOS      (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL2_SR_TOS      (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL3_SR_TOS      (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL4_SR_TOS      (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL5_SR_TOS      (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL6_SR_TOS      (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL7_SR_TOS      (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL8_SR_TOS      (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL9_SR_TOS      (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL10_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL11_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL12_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL13_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL14_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL15_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL16_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL17_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL18_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL19_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL20_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL21_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL22_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL23_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL24_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL25_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL26_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL27_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL28_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL29_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL30_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL31_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL32_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL33_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL34_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL35_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL36_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL37_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL38_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL39_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL40_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL41_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL42_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL43_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL44_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL45_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL46_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL47_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL48_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL49_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL50_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL51_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL52_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL53_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL54_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL55_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL56_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL57_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL58_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL59_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL60_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL61_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL62_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL63_SR_TOS     (IRQ_TOS_CPU0)



/* Macro for Dma_Irq.c*/
#define IRQ_DMA_CHANNEL0_USED        (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL0_PARAM       (255U)
#define IRQ_DMA_CHANNEL1_USED        (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL1_PARAM       (255U)
#define IRQ_DMA_CHANNEL2_USED        (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL2_PARAM       (255U)
#define IRQ_DMA_CHANNEL3_USED        (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL3_PARAM       (255U)
#define IRQ_DMA_CHANNEL4_USED        (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL4_PARAM       (255U)
#define IRQ_DMA_CHANNEL5_USED        (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL5_PARAM       (255U)
#define IRQ_DMA_CHANNEL6_USED        (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL6_PARAM       (255U)
#define IRQ_DMA_CHANNEL7_USED        (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL7_PARAM       (255U)
#define IRQ_DMA_CHANNEL8_USED        (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL8_PARAM       (255U)
#define IRQ_DMA_CHANNEL9_USED        (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL9_PARAM       (255U)
#define IRQ_DMA_CHANNEL10_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL10_PARAM      (255U)
#define IRQ_DMA_CHANNEL11_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL11_PARAM      (255U)
#define IRQ_DMA_CHANNEL12_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL12_PARAM      (255U)
#define IRQ_DMA_CHANNEL13_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL13_PARAM      (255U)
#define IRQ_DMA_CHANNEL14_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL14_PARAM      (255U)
#define IRQ_DMA_CHANNEL15_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL15_PARAM      (255U)
#define IRQ_DMA_CHANNEL16_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL16_PARAM      (255U)
#define IRQ_DMA_CHANNEL17_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL17_PARAM      (255U)
#define IRQ_DMA_CHANNEL18_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL18_PARAM      (255U)
#define IRQ_DMA_CHANNEL19_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL19_PARAM      (255U)
#define IRQ_DMA_CHANNEL20_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL20_PARAM      (255U)
#define IRQ_DMA_CHANNEL21_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL21_PARAM      (255U)
#define IRQ_DMA_CHANNEL22_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL22_PARAM      (255U)
#define IRQ_DMA_CHANNEL23_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL23_PARAM      (255U)
#define IRQ_DMA_CHANNEL24_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL24_PARAM      (255U)
#define IRQ_DMA_CHANNEL25_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL25_PARAM      (255U)
#define IRQ_DMA_CHANNEL26_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL26_PARAM      (255U)
#define IRQ_DMA_CHANNEL27_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL27_PARAM      (255U)
#define IRQ_DMA_CHANNEL28_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL28_PARAM      (255U)
#define IRQ_DMA_CHANNEL29_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL29_PARAM      (255U)
#define IRQ_DMA_CHANNEL30_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL30_PARAM      (255U)
#define IRQ_DMA_CHANNEL31_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL31_PARAM      (255U)
#define IRQ_DMA_CHANNEL32_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL32_PARAM      (255U)
#define IRQ_DMA_CHANNEL33_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL33_PARAM      (255U)
#define IRQ_DMA_CHANNEL34_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL34_PARAM      (255U)
#define IRQ_DMA_CHANNEL35_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL35_PARAM      (255U)
#define IRQ_DMA_CHANNEL36_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL36_PARAM      (255U)
#define IRQ_DMA_CHANNEL37_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL37_PARAM      (255U)
#define IRQ_DMA_CHANNEL38_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL38_PARAM      (255U)
#define IRQ_DMA_CHANNEL39_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL39_PARAM      (255U)
#define IRQ_DMA_CHANNEL40_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL40_PARAM      (255U)
#define IRQ_DMA_CHANNEL41_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL41_PARAM      (255U)
#define IRQ_DMA_CHANNEL42_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL42_PARAM      (255U)
#define IRQ_DMA_CHANNEL43_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL43_PARAM      (255U)
#define IRQ_DMA_CHANNEL44_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL44_PARAM      (255U)
#define IRQ_DMA_CHANNEL45_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL45_PARAM      (255U)
#define IRQ_DMA_CHANNEL46_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL46_PARAM      (255U)
#define IRQ_DMA_CHANNEL47_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL47_PARAM      (255U)
#define IRQ_DMA_CHANNEL48_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL48_PARAM      (255U)
#define IRQ_DMA_CHANNEL49_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL49_PARAM      (255U)
#define IRQ_DMA_CHANNEL50_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL50_PARAM      (255U)
#define IRQ_DMA_CHANNEL51_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL51_PARAM      (255U)
#define IRQ_DMA_CHANNEL52_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL52_PARAM      (255U)
#define IRQ_DMA_CHANNEL53_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL53_PARAM      (255U)
#define IRQ_DMA_CHANNEL54_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL54_PARAM      (255U)
#define IRQ_DMA_CHANNEL55_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL55_PARAM      (255U)
#define IRQ_DMA_CHANNEL56_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL56_PARAM      (255U)
#define IRQ_DMA_CHANNEL57_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL57_PARAM      (255U)
#define IRQ_DMA_CHANNEL58_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL58_PARAM      (255U)
#define IRQ_DMA_CHANNEL59_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL59_PARAM      (255U)
#define IRQ_DMA_CHANNEL60_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL60_PARAM      (255U)
#define IRQ_DMA_CHANNEL61_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL61_PARAM      (255U)
#define IRQ_DMA_CHANNEL62_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL62_PARAM      (255U)
#define IRQ_DMA_CHANNEL63_USED       (IRQ_DMA_AVAILABLE)
#define IRQ_DMA_CHANNEL63_PARAM      (255U)

/* Macro for AscLin_Irq.c*/
#define IRQ_ASCLIN_CHANNEL0_USED      (IRQ_ASCLIN_USED_MCALUART)
#define IRQ_ASCLIN_CHANNEL1_USED      (IRQ_ASCLIN_USED_MCALUART)
#define IRQ_ASCLIN_CHANNEL2_USED      (IRQ_ASCLIN_AVAILABLE)
#define IRQ_ASCLIN_CHANNEL3_USED      (IRQ_ASCLIN_USED_MCALUART)



/*
                     Container : Ethernet interrupt Configuration
*/
/* Ethernet interrupt Category Setting*/
#define IRQ_ETH_SR_CAT              (IRQ_CAT1)

/* Ethernet interrupt Category Setting*/
#define IRQ_ETH_SR_PRIO             0x0

/* Ethernet interrupt type of service Setting*/
#define IRQ_ETH_SR_TOS              (IRQ_TOS_CPU0)

/*
                     Container : IrqCaninterruptConfiguration
*/
/* CAN interrupt Category setting */
#define IRQ_CAN_SR0_CAT             (IRQ_CAT1)
#define IRQ_CAN_SR1_CAT             (IRQ_CAT1)
#define IRQ_CAN_SR2_CAT             (IRQ_CAT1)
#define IRQ_CAN_SR3_CAT             (IRQ_CAT1)
#define IRQ_CAN_SR4_CAT             (IRQ_CAT1)
#define IRQ_CAN_SR5_CAT             (IRQ_CAT1)
#define IRQ_CAN_SR6_CAT             (IRQ_CAT1)
#define IRQ_CAN_SR7_CAT             (IRQ_CAT1)
#define IRQ_CAN_SR8_CAT             (IRQ_CAT1)
#define IRQ_CAN_SR9_CAT             (IRQ_CAT1)
#define IRQ_CAN_SR10_CAT            (IRQ_CAT1)
#define IRQ_CAN_SR11_CAT            (IRQ_CAT1)
#define IRQ_CAN_SR12_CAT            (IRQ_CAT1)
#define IRQ_CAN_SR13_CAT            (IRQ_CAT1)
#define IRQ_CAN_SR14_CAT            (IRQ_CAT1)
#define IRQ_CAN_SR15_CAT            (IRQ_CAT1)

/*  CAN interrupt Priority setting  */
#define IRQ_CAN_SR0_PRIO            0xa
#define IRQ_CAN_SR1_PRIO            0xb
#define IRQ_CAN_SR2_PRIO            0xc
#define IRQ_CAN_SR3_PRIO            0x0
#define IRQ_CAN_SR4_PRIO            0x0
#define IRQ_CAN_SR5_PRIO            0x0
#define IRQ_CAN_SR6_PRIO            0x0
#define IRQ_CAN_SR7_PRIO            0x0
#define IRQ_CAN_SR8_PRIO            0x0
#define IRQ_CAN_SR9_PRIO            0x0
#define IRQ_CAN_SR10_PRIO           0x0
#define IRQ_CAN_SR11_PRIO           0x0
#define IRQ_CAN_SR12_PRIO           0x0
#define IRQ_CAN_SR13_PRIO           0x0
#define IRQ_CAN_SR14_PRIO           0x0
#define IRQ_CAN_SR15_PRIO           0x0


/* CAN interrupt type of service setting */
#define IRQ_CAN_SR0_TOS             (IRQ_TOS_CPU0)
#define IRQ_CAN_SR1_TOS             (IRQ_TOS_CPU0)
#define IRQ_CAN_SR2_TOS             (IRQ_TOS_CPU0)
#define IRQ_CAN_SR3_TOS             (IRQ_TOS_CPU0)
#define IRQ_CAN_SR4_TOS             (IRQ_TOS_CPU0)
#define IRQ_CAN_SR5_TOS             (IRQ_TOS_CPU0)
#define IRQ_CAN_SR6_TOS             (IRQ_TOS_CPU0)
#define IRQ_CAN_SR7_TOS             (IRQ_TOS_CPU0)
#define IRQ_CAN_SR8_TOS             (IRQ_TOS_CPU0)
#define IRQ_CAN_SR9_TOS             (IRQ_TOS_CPU0)
#define IRQ_CAN_SR10_TOS            (IRQ_TOS_CPU0)
#define IRQ_CAN_SR11_TOS            (IRQ_TOS_CPU0)
#define IRQ_CAN_SR12_TOS            (IRQ_TOS_CPU0)
#define IRQ_CAN_SR13_TOS            (IRQ_TOS_CPU0)
#define IRQ_CAN_SR14_TOS            (IRQ_TOS_CPU0)
#define IRQ_CAN_SR15_TOS            (IRQ_TOS_CPU0)


/*
                     Container : IrqHSMinterruptConfiguration
*/
/* HSM interrupt Category setting */
#define IRQ_HSM_SR0_CAT             (IRQ_CAT1)
#define IRQ_HSM_SR1_CAT             (IRQ_CAT1)

/*  HSM interrupt Priority setting  */
#define IRQ_HSM_SR0_PRIO            0x0
#define IRQ_HSM_SR1_PRIO            0x0


/* HSM interrupt type of service setting */
#define IRQ_HSM_SR0_TOS             (IRQ_TOS_CPU0)
#define IRQ_HSM_SR1_TOS             (IRQ_TOS_CPU0)


/* Mcaro to identify SHS ADC or SAR ADC */
#define IRQ_ADC_CG0SR0_USED_FOR_BGNDRS   (STD_ON)
/*
                     Container : Irq ADC configuration
*/
/*ADC0 interrupt Category setting */
#define IRQ_ADC0_SR0_CAT            (IRQ_CAT1)
#define IRQ_ADC0_SR1_CAT            (IRQ_CAT1)
#define IRQ_ADC0_SR2_CAT            (IRQ_CAT1)
#define IRQ_ADC0_SR3_CAT            (IRQ_CAT1)

/*ADC0 interrupt Priority setting */
#define IRQ_ADC0_SR0_PRIO           0x32
#define IRQ_ADC0_SR1_PRIO           0x33
#define IRQ_ADC0_SR2_PRIO           0x0
#define IRQ_ADC0_SR3_PRIO           0x0

/*ADC0 interrupt type of service setting */
#define IRQ_ADC0_SR0_TOS            (IRQ_TOS_CPU1)
#define IRQ_ADC0_SR1_TOS            (IRQ_TOS_CPU2)
#define IRQ_ADC0_SR2_TOS            (IRQ_TOS_CPU1)
#define IRQ_ADC0_SR3_TOS            (IRQ_TOS_CPU2)

/*ADC1 interrupt Category setting */
#define IRQ_ADC1_SR0_CAT            (IRQ_CAT1)
#define IRQ_ADC1_SR1_CAT            (IRQ_CAT1)
#define IRQ_ADC1_SR2_CAT            (IRQ_CAT1)
#define IRQ_ADC1_SR3_CAT            (IRQ_CAT1)

/*ADC1 interrupt Priority setting */
#define IRQ_ADC1_SR0_PRIO           0x1e
#define IRQ_ADC1_SR1_PRIO           0x1f
#define IRQ_ADC1_SR2_PRIO           0x0
#define IRQ_ADC1_SR3_PRIO           0x0

/*ADC1 interrupt type of service setting */
#define IRQ_ADC1_SR0_TOS            (IRQ_TOS_CPU1)
#define IRQ_ADC1_SR1_TOS            (IRQ_TOS_CPU2)
#define IRQ_ADC1_SR2_TOS            (IRQ_TOS_CPU1)
#define IRQ_ADC1_SR3_TOS            (IRQ_TOS_CPU2)

/*ADC2 interrupt Category setting */
#define IRQ_ADC2_SR0_CAT            (IRQ_CAT1)
#define IRQ_ADC2_SR1_CAT            (IRQ_CAT1)
#define IRQ_ADC2_SR2_CAT            (IRQ_CAT1)
#define IRQ_ADC2_SR3_CAT            (IRQ_CAT1)

/*ADC2 interrupt Priority setting */
#define IRQ_ADC2_SR0_PRIO           0x20
#define IRQ_ADC2_SR1_PRIO           0x21
#define IRQ_ADC2_SR2_PRIO           0x0
#define IRQ_ADC2_SR3_PRIO           0x0

/*ADC2 interrupt type of service setting */
#define IRQ_ADC2_SR0_TOS            (IRQ_TOS_CPU1)
#define IRQ_ADC2_SR1_TOS            (IRQ_TOS_CPU2)
#define IRQ_ADC2_SR2_TOS            (IRQ_TOS_CPU1)
#define IRQ_ADC2_SR3_TOS            (IRQ_TOS_CPU2)

/*ADC3 interrupt Category setting */
#define IRQ_ADC3_SR0_CAT            (IRQ_CAT1)
#define IRQ_ADC3_SR1_CAT            (IRQ_CAT1)
#define IRQ_ADC3_SR2_CAT            (IRQ_CAT1)
#define IRQ_ADC3_SR3_CAT            (IRQ_CAT1)

/*ADC3 interrupt Priority setting */
#define IRQ_ADC3_SR0_PRIO           0x22
#define IRQ_ADC3_SR1_PRIO           0x23
#define IRQ_ADC3_SR2_PRIO           0x0
#define IRQ_ADC3_SR3_PRIO           0x0

/*ADC3 interrupt type of service setting */
#define IRQ_ADC3_SR0_TOS            (IRQ_TOS_CPU1)
#define IRQ_ADC3_SR1_TOS            (IRQ_TOS_CPU1)
#define IRQ_ADC3_SR2_TOS            (IRQ_TOS_CPU1)
#define IRQ_ADC3_SR3_TOS            (IRQ_TOS_CPU1)

/*ADC4 interrupt Category setting */
#define IRQ_ADC4_SR0_CAT            (IRQ_CAT1)
#define IRQ_ADC4_SR1_CAT            (IRQ_CAT1)
#define IRQ_ADC4_SR2_CAT            (IRQ_CAT1)
#define IRQ_ADC4_SR3_CAT            (IRQ_CAT1)

/*ADC4 interrupt Priority setting */
#define IRQ_ADC4_SR0_PRIO           0x24
#define IRQ_ADC4_SR1_PRIO           0x0
#define IRQ_ADC4_SR2_PRIO           0x0
#define IRQ_ADC4_SR3_PRIO           0x0

/*ADC4 interrupt type of service setting */
#define IRQ_ADC4_SR0_TOS            (IRQ_TOS_CPU1)
#define IRQ_ADC4_SR1_TOS            (IRQ_TOS_CPU1)
#define IRQ_ADC4_SR2_TOS            (IRQ_TOS_CPU1)
#define IRQ_ADC4_SR3_TOS            (IRQ_TOS_CPU1)

/*ADC5 interrupt Category setting */
#define IRQ_ADC5_SR0_CAT            (IRQ_CAT1)
#define IRQ_ADC5_SR1_CAT            (IRQ_CAT1)
#define IRQ_ADC5_SR2_CAT            (IRQ_CAT1)
#define IRQ_ADC5_SR3_CAT            (IRQ_CAT1)

/*ADC5 interrupt Priority setting */
#define IRQ_ADC5_SR0_PRIO           0x25
#define IRQ_ADC5_SR1_PRIO           0x0
#define IRQ_ADC5_SR2_PRIO           0x0
#define IRQ_ADC5_SR3_PRIO           0x0

/*ADC5 interrupt type of service setting */
#define IRQ_ADC5_SR0_TOS            (IRQ_TOS_CPU1)
#define IRQ_ADC5_SR1_TOS            (IRQ_TOS_CPU1)
#define IRQ_ADC5_SR2_TOS            (IRQ_TOS_CPU1)
#define IRQ_ADC5_SR3_TOS            (IRQ_TOS_CPU1)

/*ADC6 interrupt Category setting */
#define IRQ_ADC6_SR0_CAT            (IRQ_CAT1)
#define IRQ_ADC6_SR1_CAT            (IRQ_CAT1)
#define IRQ_ADC6_SR2_CAT            (IRQ_CAT1)
#define IRQ_ADC6_SR3_CAT            (IRQ_CAT1)

/*ADC6 interrupt Priority setting */
#define IRQ_ADC6_SR0_PRIO           0x0
#define IRQ_ADC6_SR1_PRIO           0x0
#define IRQ_ADC6_SR2_PRIO           0x0
#define IRQ_ADC6_SR3_PRIO           0x0

/*ADC6 interrupt type of service setting */
#define IRQ_ADC6_SR0_TOS            (IRQ_TOS_CPU0)
#define IRQ_ADC6_SR1_TOS            (IRQ_TOS_CPU0)
#define IRQ_ADC6_SR2_TOS            (IRQ_TOS_CPU0)
#define IRQ_ADC6_SR3_TOS            (IRQ_TOS_CPU0)

/*ADC7 interrupt Category setting */
#define IRQ_ADC7_SR0_CAT            (IRQ_CAT1)
#define IRQ_ADC7_SR1_CAT            (IRQ_CAT1)
#define IRQ_ADC7_SR2_CAT            (IRQ_CAT1)
#define IRQ_ADC7_SR3_CAT            (IRQ_CAT1)

/*ADC7 interrupt Priority setting */
#define IRQ_ADC7_SR0_PRIO           0x0
#define IRQ_ADC7_SR1_PRIO           0x0
#define IRQ_ADC7_SR2_PRIO           0x0
#define IRQ_ADC7_SR3_PRIO           0x0

/*ADC7 interrupt type of service setting */
#define IRQ_ADC7_SR0_TOS            (IRQ_TOS_CPU0)
#define IRQ_ADC7_SR1_TOS            (IRQ_TOS_CPU0)
#define IRQ_ADC7_SR2_TOS            (IRQ_TOS_CPU0)
#define IRQ_ADC7_SR3_TOS            (IRQ_TOS_CPU0)




/*ADC CG0 interrupt Category setting */
#define IRQ_ADCCG0_SR0_CAT          (IRQ_CAT1)
#define IRQ_ADCCG0_SR1_CAT          (IRQ_CAT1)
#define IRQ_ADCCG0_SR2_CAT          (IRQ_CAT1)
#define IRQ_ADCCG0_SR3_CAT          (IRQ_CAT1)

/*ADC CG0 interrupt Priority setting */
#define IRQ_ADCCG0_SR0_PRIO         0x0
#define IRQ_ADCCG0_SR1_PRIO         0x0
#define IRQ_ADCCG0_SR2_PRIO         0x0
#define IRQ_ADCCG0_SR3_PRIO         0x0

/*ADC CG0 interrupt type of service setting */
#define IRQ_ADCCG0_SR0_TOS          (IRQ_TOS_CPU0)
#define IRQ_ADCCG0_SR1_TOS          (IRQ_TOS_CPU0)
#define IRQ_ADCCG0_SR2_TOS          (IRQ_TOS_CPU0)
#define IRQ_ADCCG0_SR3_TOS          (IRQ_TOS_CPU0)

/*ADC CG1 interrupt Category setting */
#define IRQ_ADCCG1_SR0_CAT          (IRQ_CAT1)
#define IRQ_ADCCG1_SR1_CAT          (IRQ_CAT1)
#define IRQ_ADCCG1_SR2_CAT          (IRQ_CAT1)
#define IRQ_ADCCG1_SR3_CAT          (IRQ_CAT1)

/*ADC CG1 interrupt Priority setting */
#define IRQ_ADCCG1_SR0_PRIO         0x0
#define IRQ_ADCCG1_SR1_PRIO         0x0
#define IRQ_ADCCG1_SR2_PRIO         0x0
#define IRQ_ADCCG1_SR3_PRIO         0x0

/*ADC CG1 interrupt type of service setting */
#define IRQ_ADCCG1_SR0_TOS          (IRQ_TOS_CPU0)
#define IRQ_ADCCG1_SR1_TOS          (IRQ_TOS_CPU0)
#define IRQ_ADCCG1_SR2_TOS          (IRQ_TOS_CPU0)
#define IRQ_ADCCG1_SR3_TOS          (IRQ_TOS_CPU0)

/*
                     Container : IrqDSADCinterruptConfiguration
*/
/*DSADC interrupt Category setting */
#define IRQ_DSADC_SRM0_CAT          (IRQ_CAT1)
#define IRQ_DSADC_SRA0_CAT          (IRQ_CAT1)
#define IRQ_DSADC_SRM1_CAT          (IRQ_CAT1)
#define IRQ_DSADC_SRA1_CAT          (IRQ_CAT1)
#define IRQ_DSADC_SRM2_CAT          (IRQ_CAT1)
#define IRQ_DSADC_SRA2_CAT          (IRQ_CAT1)
#define IRQ_DSADC_SRM3_CAT          (IRQ_CAT1)
#define IRQ_DSADC_SRA3_CAT          (IRQ_CAT1)
#define IRQ_DSADC_SRM4_CAT          (IRQ_CAT1)
#define IRQ_DSADC_SRA4_CAT          (IRQ_CAT1)
#define IRQ_DSADC_SRM5_CAT          (IRQ_CAT1)
#define IRQ_DSADC_SRA5_CAT          (IRQ_CAT1)

/*DSADC interrupt Priority setting */
#define IRQ_DSADC_SRM0_PRIO          0x0
#define IRQ_DSADC_SRA0_PRIO          0x0
#define IRQ_DSADC_SRM1_PRIO          0x0
#define IRQ_DSADC_SRA1_PRIO          0x0
#define IRQ_DSADC_SRM2_PRIO          0x0
#define IRQ_DSADC_SRA2_PRIO          0x0
#define IRQ_DSADC_SRM3_PRIO          0x0
#define IRQ_DSADC_SRA3_PRIO          0x0
#define IRQ_DSADC_SRM4_PRIO          0x0
#define IRQ_DSADC_SRA4_PRIO          0x0
#define IRQ_DSADC_SRM5_PRIO          0x0
#define IRQ_DSADC_SRA5_PRIO          0x0

/*DSADC interrupt type of service setting */
#define IRQ_DSADC_SRM0_TOS           (IRQ_TOS_CPU0)
#define IRQ_DSADC_SRA0_TOS           (IRQ_TOS_CPU0)
#define IRQ_DSADC_SRM1_TOS           (IRQ_TOS_CPU0)
#define IRQ_DSADC_SRA1_TOS           (IRQ_TOS_CPU0)
#define IRQ_DSADC_SRM2_TOS           (IRQ_TOS_CPU0)
#define IRQ_DSADC_SRA2_TOS           (IRQ_TOS_CPU0)
#define IRQ_DSADC_SRM3_TOS           (IRQ_TOS_CPU0)
#define IRQ_DSADC_SRA3_TOS           (IRQ_TOS_CPU0)
#define IRQ_DSADC_SRM4_TOS           (IRQ_TOS_CPU0)
#define IRQ_DSADC_SRA4_TOS           (IRQ_TOS_CPU0)
#define IRQ_DSADC_SRM5_TOS           (IRQ_TOS_CPU0)
#define IRQ_DSADC_SRA5_TOS           (IRQ_TOS_CPU0)

/*
                     Container : IrqFLEXRAYinterruptConfiguration
*/
/* FLEXRAY0 interrupt Category Setting */
#define IRQ_FLEXRAY0_SR0_CAT         (IRQ_CAT1)
#define IRQ_FLEXRAY0_SR1_CAT         (IRQ_CAT1)
#define IRQ_FLEXRAY0_TIMER_INT0_CAT  (IRQ_CAT1)
#define IRQ_FLEXRAY0_TIMER_INT1_CAT  (IRQ_CAT1)
#define IRQ_FLEXRAY0_NEW_DATA0_CAT   (IRQ_CAT1)
#define IRQ_FLEXRAY0_NEW_DATA1_CAT   (IRQ_CAT1)
#define IRQ_FLEXRAY0_MBSC0_CAT       (IRQ_CAT1)
#define IRQ_FLEXRAY0_MBSC1_CAT       (IRQ_CAT1)
#define IRQ_FLEXRAY0_OB_BUSY_CAT     (IRQ_CAT1)
#define IRQ_FLEXRAY0_IB_BUSY_CAT     (IRQ_CAT1)

/* FLEXRAY0 interrupt Priority Setting */
#define IRQ_FLEXRAY0_SR0_PRIO        0x0
#define IRQ_FLEXRAY0_SR1_PRIO        0x0
#define IRQ_FLEXRAY0_TIMER_INT0_PRIO 0x0
#define IRQ_FLEXRAY0_TIMER_INT1_PRIO 0x0
#define IRQ_FLEXRAY0_NEW_DATA0_PRIO  0x0
#define IRQ_FLEXRAY0_NEW_DATA1_PRIO  0x0
#define IRQ_FLEXRAY0_MBSC0_PRIO      0x0
#define IRQ_FLEXRAY0_MBSC1_PRIO      0x0
#define IRQ_FLEXRAY0_OB_BUSY_PRIO    0x0
#define IRQ_FLEXRAY0_IB_BUSY_PRIO    0x0

/* FLEXRAY0 interrupt type of service Setting */
#define IRQ_FLEXRAY0_SR0_TOS         (IRQ_TOS_CPU0)
#define IRQ_FLEXRAY0_SR1_TOS         (IRQ_TOS_CPU0)
#define IRQ_FLEXRAY0_TIMER_INT0_TOS  (IRQ_TOS_CPU0)
#define IRQ_FLEXRAY0_TIMER_INT1_TOS  (IRQ_TOS_CPU0)
#define IRQ_FLEXRAY0_NEW_DATA0_TOS   (IRQ_TOS_CPU0)
#define IRQ_FLEXRAY0_NEW_DATA1_TOS   (IRQ_TOS_CPU0)
#define IRQ_FLEXRAY0_MBSC0_TOS       (IRQ_TOS_CPU0)
#define IRQ_FLEXRAY0_MBSC1_TOS       (IRQ_TOS_CPU0)
#define IRQ_FLEXRAY0_OB_BUSY_TOS     (IRQ_TOS_CPU0)
#define IRQ_FLEXRAY0_IB_BUSY_TOS     (IRQ_TOS_CPU0)


/*
                     Container : PMU0 interrupt Configuration
*/
/* PMU0 interrupt Category Setting*/
#define IRQ_PMU0_SR0_CAT            (IRQ_CAT1)
#define IRQ_PMU0_SR1_CAT            (IRQ_CAT1)

/* PMU0 interrupt Category Setting*/
#define IRQ_PMU0_SR0_PRIO           0x0
#define IRQ_PMU0_SR1_PRIO           0x0

/* PMU0 interrupt type of service Setting*/
#define IRQ_PMU0_SR0_TOS            (IRQ_TOS_CPU0)
#define IRQ_PMU0_SR1_TOS            (IRQ_TOS_CPU0)

/*
                     Container : Scu interrupt Configuration
*/
/* Scu interrupt Category Setting*/
#define IRQ_SCU_DTS_BUSY_SR_CAT     (IRQ_CAT1)
#define IRQ_SCU_ERU_SR0_CAT         (IRQ_CAT1)
#define IRQ_SCU_ERU_SR1_CAT         (IRQ_CAT1)
#define IRQ_SCU_ERU_SR2_CAT         (IRQ_CAT1)
#define IRQ_SCU_ERU_SR3_CAT         (IRQ_CAT1)

/* Scu interrupt Category Setting*/
#define IRQ_SCU_DTS_BUSY_SR_PRIO    0x0
#define IRQ_SCU_ERU_SR0_PRIO        0x0
#define IRQ_SCU_ERU_SR1_PRIO        0x0
#define IRQ_SCU_ERU_SR2_PRIO        0x0
#define IRQ_SCU_ERU_SR3_PRIO        0x0

/* Scu interrupt type of service Setting*/
#define IRQ_SCU_DTS_BUSY_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_SCU_ERU_SR0_TOS         (IRQ_TOS_CPU0)
#define IRQ_SCU_ERU_SR1_TOS         (IRQ_TOS_CPU0)
#define IRQ_SCU_ERU_SR2_TOS         (IRQ_TOS_CPU0)
#define IRQ_SCU_ERU_SR3_TOS         (IRQ_TOS_CPU0)

/*
                     Container : IrqGPSRGroupinterruptConfiguration
*/
/* GPSRGROUP0 interrupt Category Setting */ 
#define IRQ_GPSRGROUP0_SR0_CAT      (IRQ_CAT1)
#define IRQ_GPSRGROUP0_SR1_CAT      (IRQ_CAT1)
#define IRQ_GPSRGROUP0_SR2_CAT      (IRQ_CAT1)
#define IRQ_GPSRGROUP0_SR3_CAT      (IRQ_CAT1)
                                                                                                           
/* GPSRGROUP0 interrupt Priority Setting */  
#define IRQ_GPSRGROUP0_SR0_PRIO     0x0
#define IRQ_GPSRGROUP0_SR1_PRIO     0x0
#define IRQ_GPSRGROUP0_SR2_PRIO     0x0
#define IRQ_GPSRGROUP0_SR3_PRIO     0x0

/* GPSRGROUP0 interrupt type of service Setting */ 
#define IRQ_GPSRGROUP0_SR0_TOS      (IRQ_TOS_CPU0)
#define IRQ_GPSRGROUP0_SR1_TOS      (IRQ_TOS_CPU0)
#define IRQ_GPSRGROUP0_SR2_TOS      (IRQ_TOS_CPU0)
#define IRQ_GPSRGROUP0_SR3_TOS      (IRQ_TOS_CPU0)

/* GPSRGROUP1 interrupt Category Setting */ 
#define IRQ_GPSRGROUP1_SR0_CAT      (IRQ_CAT1)
#define IRQ_GPSRGROUP1_SR1_CAT      (IRQ_CAT1)
#define IRQ_GPSRGROUP1_SR2_CAT      (IRQ_CAT1)
#define IRQ_GPSRGROUP1_SR3_CAT      (IRQ_CAT1)
                                                                                                           
/* GPSRGROUP1 interrupt Priority Setting */  
#define IRQ_GPSRGROUP1_SR0_PRIO     0x0
#define IRQ_GPSRGROUP1_SR1_PRIO     0x0
#define IRQ_GPSRGROUP1_SR2_PRIO     0x0
#define IRQ_GPSRGROUP1_SR3_PRIO     0x0

/* GPSRGROUP1 interrupt type of service Setting */ 
#define IRQ_GPSRGROUP1_SR0_TOS      (IRQ_TOS_CPU0)
#define IRQ_GPSRGROUP1_SR1_TOS      (IRQ_TOS_CPU0)
#define IRQ_GPSRGROUP1_SR2_TOS      (IRQ_TOS_CPU0)
#define IRQ_GPSRGROUP1_SR3_TOS      (IRQ_TOS_CPU0)

/* GPSRGROUP2 interrupt Category Setting */ 
#define IRQ_GPSRGROUP2_SR0_CAT      (IRQ_CAT1)
#define IRQ_GPSRGROUP2_SR1_CAT      (IRQ_CAT1)
#define IRQ_GPSRGROUP2_SR2_CAT      (IRQ_CAT1)
#define IRQ_GPSRGROUP2_SR3_CAT      (IRQ_CAT1)
                                                                                                           
/* GPSRGROUP2 interrupt Priority Setting */  
#define IRQ_GPSRGROUP2_SR0_PRIO     0x0
#define IRQ_GPSRGROUP2_SR1_PRIO     0x0
#define IRQ_GPSRGROUP2_SR2_PRIO     0x0
#define IRQ_GPSRGROUP2_SR3_PRIO     0x0

/* GPSRGROUP2 interrupt type of service Setting */ 
#define IRQ_GPSRGROUP2_SR0_TOS      (IRQ_TOS_CPU0)
#define IRQ_GPSRGROUP2_SR1_TOS      (IRQ_TOS_CPU0)
#define IRQ_GPSRGROUP2_SR2_TOS      (IRQ_TOS_CPU0)
#define IRQ_GPSRGROUP2_SR3_TOS      (IRQ_TOS_CPU0)
/*
                     Container : Irq GTM interruptConfiguration
*/
/* GTM AEI interrupt Category Setting */ 
#define IRQ_GTM_AEI_CAT             (IRQ_CAT1)
                                                                                                           
/* GTM AEI interrupt Priority Setting */  
#define IRQ_GTM_AEI_PRIO            0x0

/* GTM AEI interrupt type of service Setting */ 
#define IRQ_GTM_AEI_TOS             (IRQ_TOS_CPU0)

/* GTM ARU interrupt Category Setting */ 
#define IRQ_GTM_ARU_SR0_CAT         (IRQ_CAT1)
#define IRQ_GTM_ARU_SR1_CAT         (IRQ_CAT1)
#define IRQ_GTM_ARU_SR2_CAT         (IRQ_CAT1)
                                                                                                           
/* GTM ARU interrupt Priority Setting */  
#define IRQ_GTM_ARU_SR0_PRIO        0x0
#define IRQ_GTM_ARU_SR1_PRIO        0x0
#define IRQ_GTM_ARU_SR2_PRIO        0x0

/* GTM ARU interrupt type of service Setting */ 
#define IRQ_GTM_ARU_SR0_TOS         (IRQ_TOS_CPU0)
#define IRQ_GTM_ARU_SR1_TOS         (IRQ_TOS_CPU0)
#define IRQ_GTM_ARU_SR2_TOS         (IRQ_TOS_CPU0)
                                                                                                           
/* GTM BRC interrupt Category Setting */ 
#define IRQ_GTM_BRC_CAT             (IRQ_CAT1)
                                                                                                           
/* GTM BRC interrupt Priority Setting */  
#define IRQ_GTM_BRC_PRIO            0x0

/* GTM BRC interrupt type of service Setting */ 
#define IRQ_GTM_BRC_TOS             (IRQ_TOS_CPU0)

/* GTM CMP interrupt Category Setting */ 
#define IRQ_GTM_CMP_CAT             (IRQ_CAT1)
                                                                                                           
/* GTM CMP interrupt Priority Setting */  
#define IRQ_GTM_CMP_PRIO            0x0

/* GTM CMP interrupt type of service Setting */ 
#define IRQ_GTM_CMP_TOS             (IRQ_TOS_CPU0)

/* GTM SPE interrupt Category Setting */ 
#define IRQ_GTM_SPE0_CAT            (IRQ_CAT1)
#define IRQ_GTM_SPE1_CAT            (IRQ_CAT1)
                                                                                                           
/* GTM SPE interrupt Priority Setting */  
#define IRQ_GTM_SPE0_PRIO           0x0
#define IRQ_GTM_SPE1_PRIO           0x0

/* GTM SPE interrupt type of service Setting */ 
#define IRQ_GTM_SPE0_TOS            (IRQ_TOS_CPU0)
#define IRQ_GTM_SPE1_TOS            (IRQ_TOS_CPU0)

/* GTM PSM0 interrupt Category Setting */ 
#define IRQ_GTM_PSM0_SR0_CAT        (IRQ_CAT1)
#define IRQ_GTM_PSM0_SR1_CAT        (IRQ_CAT1)
#define IRQ_GTM_PSM0_SR2_CAT        (IRQ_CAT1)
#define IRQ_GTM_PSM0_SR3_CAT        (IRQ_CAT1)
#define IRQ_GTM_PSM0_SR4_CAT        (IRQ_CAT1)
#define IRQ_GTM_PSM0_SR5_CAT        (IRQ_CAT1)
#define IRQ_GTM_PSM0_SR6_CAT        (IRQ_CAT1)
#define IRQ_GTM_PSM0_SR7_CAT        (IRQ_CAT1)
                                                                                                           
/* GTM PSM0 interrupt Priority Setting */  
#define IRQ_GTM_PSM0_SR0_PRIO       0x0
#define IRQ_GTM_PSM0_SR1_PRIO       0x0
#define IRQ_GTM_PSM0_SR2_PRIO       0x0
#define IRQ_GTM_PSM0_SR3_PRIO       0x0
#define IRQ_GTM_PSM0_SR4_PRIO       0x0
#define IRQ_GTM_PSM0_SR5_PRIO       0x0
#define IRQ_GTM_PSM0_SR6_PRIO       0x0
#define IRQ_GTM_PSM0_SR7_PRIO       0x0

/* GTM PSM0 interrupt type of service Setting */ 
#define IRQ_GTM_PSM0_SR0_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_PSM0_SR1_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_PSM0_SR2_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_PSM0_SR3_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_PSM0_SR4_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_PSM0_SR5_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_PSM0_SR6_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_PSM0_SR7_TOS        (IRQ_TOS_CPU0)


/* GTM DPLL interrupt Category Setting */ 
#define IRQ_GTM_DPLL_SR0_CAT        (IRQ_CAT1)
#define IRQ_GTM_DPLL_SR1_CAT        (IRQ_CAT1)
#define IRQ_GTM_DPLL_SR2_CAT        (IRQ_CAT1)
#define IRQ_GTM_DPLL_SR3_CAT        (IRQ_CAT1)
#define IRQ_GTM_DPLL_SR4_CAT        (IRQ_CAT1)
#define IRQ_GTM_DPLL_SR5_CAT        (IRQ_CAT1)
#define IRQ_GTM_DPLL_SR6_CAT        (IRQ_CAT1)
#define IRQ_GTM_DPLL_SR7_CAT        (IRQ_CAT1)
#define IRQ_GTM_DPLL_SR8_CAT        (IRQ_CAT1)
#define IRQ_GTM_DPLL_SR9_CAT        (IRQ_CAT1)
#define IRQ_GTM_DPLL_SR10_CAT       (IRQ_CAT1)
#define IRQ_GTM_DPLL_SR11_CAT       (IRQ_CAT1)
#define IRQ_GTM_DPLL_SR12_CAT       (IRQ_CAT1)
#define IRQ_GTM_DPLL_SR13_CAT       (IRQ_CAT1)
#define IRQ_GTM_DPLL_SR14_CAT       (IRQ_CAT1)
#define IRQ_GTM_DPLL_SR15_CAT       (IRQ_CAT1)
#define IRQ_GTM_DPLL_SR16_CAT       (IRQ_CAT1)
#define IRQ_GTM_DPLL_SR17_CAT       (IRQ_CAT1)
#define IRQ_GTM_DPLL_SR18_CAT       (IRQ_CAT1)
#define IRQ_GTM_DPLL_SR19_CAT       (IRQ_CAT1)
#define IRQ_GTM_DPLL_SR20_CAT       (IRQ_CAT1)
#define IRQ_GTM_DPLL_SR21_CAT       (IRQ_CAT1)
#define IRQ_GTM_DPLL_SR22_CAT       (IRQ_CAT1)
#define IRQ_GTM_DPLL_SR23_CAT       (IRQ_CAT1)
#define IRQ_GTM_DPLL_SR24_CAT       (IRQ_CAT1)
#define IRQ_GTM_DPLL_SR25_CAT       (IRQ_CAT1)
#define IRQ_GTM_DPLL_SR26_CAT       (IRQ_CAT1)
                                                                                                           
/* GTM DPLL interrupt Priority Setting */  
#define IRQ_GTM_DPLL_SR0_PRIO       0x0
#define IRQ_GTM_DPLL_SR1_PRIO       0x0
#define IRQ_GTM_DPLL_SR2_PRIO       0x0
#define IRQ_GTM_DPLL_SR3_PRIO       0x0
#define IRQ_GTM_DPLL_SR4_PRIO       0x0
#define IRQ_GTM_DPLL_SR5_PRIO       0x0
#define IRQ_GTM_DPLL_SR6_PRIO       0x0
#define IRQ_GTM_DPLL_SR7_PRIO       0x0
#define IRQ_GTM_DPLL_SR8_PRIO       0x0
#define IRQ_GTM_DPLL_SR9_PRIO       0x0
#define IRQ_GTM_DPLL_SR10_PRIO      0x0
#define IRQ_GTM_DPLL_SR11_PRIO      0x0
#define IRQ_GTM_DPLL_SR12_PRIO      0x0
#define IRQ_GTM_DPLL_SR13_PRIO      0x0
#define IRQ_GTM_DPLL_SR14_PRIO      0x0
#define IRQ_GTM_DPLL_SR15_PRIO      0x0
#define IRQ_GTM_DPLL_SR16_PRIO      0x0
#define IRQ_GTM_DPLL_SR17_PRIO      0x0
#define IRQ_GTM_DPLL_SR18_PRIO      0x0
#define IRQ_GTM_DPLL_SR19_PRIO      0x0
#define IRQ_GTM_DPLL_SR20_PRIO      0x0
#define IRQ_GTM_DPLL_SR21_PRIO      0x0
#define IRQ_GTM_DPLL_SR22_PRIO      0x0
#define IRQ_GTM_DPLL_SR23_PRIO      0x0
#define IRQ_GTM_DPLL_SR24_PRIO      0x0
#define IRQ_GTM_DPLL_SR25_PRIO      0x0
#define IRQ_GTM_DPLL_SR26_PRIO      0x0

/* GTM DPLL interrupt type of service Setting */ 
#define IRQ_GTM_DPLL_SR0_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_DPLL_SR1_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_DPLL_SR2_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_DPLL_SR3_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_DPLL_SR4_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_DPLL_SR5_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_DPLL_SR6_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_DPLL_SR7_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_DPLL_SR8_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_DPLL_SR9_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_DPLL_SR10_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_DPLL_SR11_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_DPLL_SR12_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_DPLL_SR13_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_DPLL_SR14_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_DPLL_SR15_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_DPLL_SR16_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_DPLL_SR17_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_DPLL_SR18_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_DPLL_SR19_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_DPLL_SR20_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_DPLL_SR21_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_DPLL_SR22_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_DPLL_SR23_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_DPLL_SR24_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_DPLL_SR25_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_DPLL_SR26_TOS       (IRQ_TOS_CPU0)

/* GTM ERR interrupt Category Setting */ 
#define IRQ_GTM_ERR_SR_CAT          (IRQ_CAT1)
                                                                                                           
/* GTM ERR interrupt Priority Setting */  
#define IRQ_GTM_ERR_SR_PRIO         0x0

/* GTM ERR interrupt type of service Setting */ 
#define IRQ_GTM_ERR_SR_TOS          (IRQ_TOS_CPU0)

/* GTM TIM0 interrupt Category Setting */ 
#define IRQ_GTM_TIM0_SR0_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM0_SR1_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM0_SR2_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM0_SR3_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM0_SR4_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM0_SR5_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM0_SR6_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM0_SR7_CAT        (IRQ_CAT1)
                                                                                                           
/* GTM TIM0 interrupt Priority Setting */  
#define IRQ_GTM_TIM0_SR0_PRIO       0x0
#define IRQ_GTM_TIM0_SR1_PRIO       0x0
#define IRQ_GTM_TIM0_SR2_PRIO       0x0
#define IRQ_GTM_TIM0_SR3_PRIO       0x0
#define IRQ_GTM_TIM0_SR4_PRIO       0x0
#define IRQ_GTM_TIM0_SR5_PRIO       0x0
#define IRQ_GTM_TIM0_SR6_PRIO       0x0
#define IRQ_GTM_TIM0_SR7_PRIO       0x0

/* GTM TIM0 interrupt type of service Setting */ 
#define IRQ_GTM_TIM0_SR0_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM0_SR1_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM0_SR2_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM0_SR3_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM0_SR4_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM0_SR5_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM0_SR6_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM0_SR7_TOS        (IRQ_TOS_CPU0)

/* GTM TIM1 interrupt Category Setting */ 
#define IRQ_GTM_TIM1_SR0_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM1_SR1_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM1_SR2_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM1_SR3_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM1_SR4_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM1_SR5_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM1_SR6_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM1_SR7_CAT        (IRQ_CAT1)
                                                                                                           
/* GTM TIM1 interrupt Priority Setting */  
#define IRQ_GTM_TIM1_SR0_PRIO       0x0
#define IRQ_GTM_TIM1_SR1_PRIO       0x0
#define IRQ_GTM_TIM1_SR2_PRIO       0x0
#define IRQ_GTM_TIM1_SR3_PRIO       0x0
#define IRQ_GTM_TIM1_SR4_PRIO       0x0
#define IRQ_GTM_TIM1_SR5_PRIO       0x0
#define IRQ_GTM_TIM1_SR6_PRIO       0x0
#define IRQ_GTM_TIM1_SR7_PRIO       0x0

/* GTM TIM1 interrupt type of service Setting */ 
#define IRQ_GTM_TIM1_SR0_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM1_SR1_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM1_SR2_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM1_SR3_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM1_SR4_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM1_SR5_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM1_SR6_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM1_SR7_TOS        (IRQ_TOS_CPU0)

/* GTM TIM2 interrupt Category Setting */ 
#define IRQ_GTM_TIM2_SR0_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM2_SR1_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM2_SR2_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM2_SR3_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM2_SR4_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM2_SR5_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM2_SR6_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM2_SR7_CAT        (IRQ_CAT1)
                                                                                                           
/* GTM TIM2 interrupt Priority Setting */  
#define IRQ_GTM_TIM2_SR0_PRIO       0x0
#define IRQ_GTM_TIM2_SR1_PRIO       0x0
#define IRQ_GTM_TIM2_SR2_PRIO       0x0
#define IRQ_GTM_TIM2_SR3_PRIO       0x0
#define IRQ_GTM_TIM2_SR4_PRIO       0x0
#define IRQ_GTM_TIM2_SR5_PRIO       0x0
#define IRQ_GTM_TIM2_SR6_PRIO       0x0
#define IRQ_GTM_TIM2_SR7_PRIO       0x0

/* GTM TIM2 interrupt type of service Setting */ 
#define IRQ_GTM_TIM2_SR0_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM2_SR1_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM2_SR2_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM2_SR3_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM2_SR4_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM2_SR5_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM2_SR6_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM2_SR7_TOS        (IRQ_TOS_CPU0)

/* GTM TIM3 interrupt Category Setting */ 
#define IRQ_GTM_TIM3_SR0_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM3_SR1_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM3_SR2_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM3_SR3_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM3_SR4_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM3_SR5_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM3_SR6_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM3_SR7_CAT        (IRQ_CAT1)
                                                                                                           
/* GTM TIM3 interrupt Priority Setting */  
#define IRQ_GTM_TIM3_SR0_PRIO       0x0
#define IRQ_GTM_TIM3_SR1_PRIO       0x0
#define IRQ_GTM_TIM3_SR2_PRIO       0x0
#define IRQ_GTM_TIM3_SR3_PRIO       0x0
#define IRQ_GTM_TIM3_SR4_PRIO       0x0
#define IRQ_GTM_TIM3_SR5_PRIO       0x0
#define IRQ_GTM_TIM3_SR6_PRIO       0x0
#define IRQ_GTM_TIM3_SR7_PRIO       0x0

/* GTM TIM3 interrupt type of service Setting */ 
#define IRQ_GTM_TIM3_SR0_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM3_SR1_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM3_SR2_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM3_SR3_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM3_SR4_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM3_SR5_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM3_SR6_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM3_SR7_TOS        (IRQ_TOS_CPU0)



/* GTM MCS0 interrupt Category Setting */ 
#define IRQ_GTM_MCS0_SR0_CAT        (IRQ_CAT1)
#define IRQ_GTM_MCS0_SR1_CAT        (IRQ_CAT1)
#define IRQ_GTM_MCS0_SR2_CAT        (IRQ_CAT1)
#define IRQ_GTM_MCS0_SR3_CAT        (IRQ_CAT1)
#define IRQ_GTM_MCS0_SR4_CAT        (IRQ_CAT1)
#define IRQ_GTM_MCS0_SR5_CAT        (IRQ_CAT1)
#define IRQ_GTM_MCS0_SR6_CAT        (IRQ_CAT1)
#define IRQ_GTM_MCS0_SR7_CAT        (IRQ_CAT1)
                                                                                                           
/* GTM MCS0 interrupt Priority Setting */  
#define IRQ_GTM_MCS0_SR0_PRIO       0x0
#define IRQ_GTM_MCS0_SR1_PRIO       0x0
#define IRQ_GTM_MCS0_SR2_PRIO       0x0
#define IRQ_GTM_MCS0_SR3_PRIO       0x0
#define IRQ_GTM_MCS0_SR4_PRIO       0x0
#define IRQ_GTM_MCS0_SR5_PRIO       0x0
#define IRQ_GTM_MCS0_SR6_PRIO       0x0
#define IRQ_GTM_MCS0_SR7_PRIO       0x0

/* GTM MCS0 interrupt type of service Setting */ 
#define IRQ_GTM_MCS0_SR0_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_MCS0_SR1_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_MCS0_SR2_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_MCS0_SR3_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_MCS0_SR4_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_MCS0_SR5_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_MCS0_SR6_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_MCS0_SR7_TOS        (IRQ_TOS_CPU0)

/* GTM MCS1 interrupt Category Setting */ 
#define IRQ_GTM_MCS1_SR0_CAT        (IRQ_CAT1)
#define IRQ_GTM_MCS1_SR1_CAT        (IRQ_CAT1)
#define IRQ_GTM_MCS1_SR2_CAT        (IRQ_CAT1)
#define IRQ_GTM_MCS1_SR3_CAT        (IRQ_CAT1)
#define IRQ_GTM_MCS1_SR4_CAT        (IRQ_CAT1)
#define IRQ_GTM_MCS1_SR5_CAT        (IRQ_CAT1)
#define IRQ_GTM_MCS1_SR6_CAT        (IRQ_CAT1)
#define IRQ_GTM_MCS1_SR7_CAT        (IRQ_CAT1)
                                                                                                           
/* GTM MCS1 interrupt Priority Setting */  
#define IRQ_GTM_MCS1_SR0_PRIO       0x0
#define IRQ_GTM_MCS1_SR1_PRIO       0x0
#define IRQ_GTM_MCS1_SR2_PRIO       0x0
#define IRQ_GTM_MCS1_SR3_PRIO       0x0
#define IRQ_GTM_MCS1_SR4_PRIO       0x0
#define IRQ_GTM_MCS1_SR5_PRIO       0x0
#define IRQ_GTM_MCS1_SR6_PRIO       0x0
#define IRQ_GTM_MCS1_SR7_PRIO       0x0

/* GTM MCS1 interrupt type of service Setting */ 
#define IRQ_GTM_MCS1_SR0_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_MCS1_SR1_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_MCS1_SR2_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_MCS1_SR3_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_MCS1_SR4_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_MCS1_SR5_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_MCS1_SR6_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_MCS1_SR7_TOS        (IRQ_TOS_CPU0)

/* GTM MCS2 interrupt Category Setting */ 
#define IRQ_GTM_MCS2_SR0_CAT        (IRQ_CAT1)
#define IRQ_GTM_MCS2_SR1_CAT        (IRQ_CAT1)
#define IRQ_GTM_MCS2_SR2_CAT        (IRQ_CAT1)
#define IRQ_GTM_MCS2_SR3_CAT        (IRQ_CAT1)
#define IRQ_GTM_MCS2_SR4_CAT        (IRQ_CAT1)
#define IRQ_GTM_MCS2_SR5_CAT        (IRQ_CAT1)
#define IRQ_GTM_MCS2_SR6_CAT        (IRQ_CAT1)
#define IRQ_GTM_MCS2_SR7_CAT        (IRQ_CAT1)
                                                                                                           
/* GTM MCS2 interrupt Priority Setting */  
#define IRQ_GTM_MCS2_SR0_PRIO       0x0
#define IRQ_GTM_MCS2_SR1_PRIO       0x0
#define IRQ_GTM_MCS2_SR2_PRIO       0x0
#define IRQ_GTM_MCS2_SR3_PRIO       0x0
#define IRQ_GTM_MCS2_SR4_PRIO       0x0
#define IRQ_GTM_MCS2_SR5_PRIO       0x0
#define IRQ_GTM_MCS2_SR6_PRIO       0x0
#define IRQ_GTM_MCS2_SR7_PRIO       0x0

/* GTM MCS2 interrupt type of service Setting */ 
#define IRQ_GTM_MCS2_SR0_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_MCS2_SR1_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_MCS2_SR2_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_MCS2_SR3_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_MCS2_SR4_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_MCS2_SR5_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_MCS2_SR6_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_MCS2_SR7_TOS        (IRQ_TOS_CPU0)

/* GTM MCS3 interrupt Category Setting */ 
#define IRQ_GTM_MCS3_SR0_CAT        (IRQ_CAT1)
#define IRQ_GTM_MCS3_SR1_CAT        (IRQ_CAT1)
#define IRQ_GTM_MCS3_SR2_CAT        (IRQ_CAT1)
#define IRQ_GTM_MCS3_SR3_CAT        (IRQ_CAT1)
#define IRQ_GTM_MCS3_SR4_CAT        (IRQ_CAT1)
#define IRQ_GTM_MCS3_SR5_CAT        (IRQ_CAT1)
#define IRQ_GTM_MCS3_SR6_CAT        (IRQ_CAT1)
#define IRQ_GTM_MCS3_SR7_CAT        (IRQ_CAT1)
                                                                                                           
/* GTM MCS3 interrupt Priority Setting */  
#define IRQ_GTM_MCS3_SR0_PRIO       0x0
#define IRQ_GTM_MCS3_SR1_PRIO       0x0
#define IRQ_GTM_MCS3_SR2_PRIO       0x0
#define IRQ_GTM_MCS3_SR3_PRIO       0x0
#define IRQ_GTM_MCS3_SR4_PRIO       0x0
#define IRQ_GTM_MCS3_SR5_PRIO       0x0
#define IRQ_GTM_MCS3_SR6_PRIO       0x0
#define IRQ_GTM_MCS3_SR7_PRIO       0x0

/* GTM MCS3 interrupt type of service Setting */ 
#define IRQ_GTM_MCS3_SR0_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_MCS3_SR1_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_MCS3_SR2_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_MCS3_SR3_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_MCS3_SR4_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_MCS3_SR5_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_MCS3_SR6_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_MCS3_SR7_TOS        (IRQ_TOS_CPU0)



/* GTM TOM0 interrupt Category Setting */ 
#define IRQ_GTM_TOM0_SR0_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM0_SR1_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM0_SR2_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM0_SR3_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM0_SR4_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM0_SR5_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM0_SR6_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM0_SR7_CAT        (IRQ_CAT1)
                                                                                                           
/* GTM TOM0 interrupt Priority Setting */  
#define IRQ_GTM_TOM0_SR0_PRIO       0x0
#define IRQ_GTM_TOM0_SR1_PRIO       0x0
#define IRQ_GTM_TOM0_SR2_PRIO       0x0
#define IRQ_GTM_TOM0_SR3_PRIO       0x0
#define IRQ_GTM_TOM0_SR4_PRIO       0x0
#define IRQ_GTM_TOM0_SR5_PRIO       0x0
#define IRQ_GTM_TOM0_SR6_PRIO       0x0
#define IRQ_GTM_TOM0_SR7_PRIO       0x0

/* GTM TOM0 interrupt type of service Setting */ 
#define IRQ_GTM_TOM0_SR0_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM0_SR1_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM0_SR2_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM0_SR3_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM0_SR4_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM0_SR5_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM0_SR6_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM0_SR7_TOS        (IRQ_TOS_CPU0)

/* GTM TOM1 interrupt Category Setting */ 
#define IRQ_GTM_TOM1_SR0_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM1_SR1_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM1_SR2_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM1_SR3_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM1_SR4_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM1_SR5_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM1_SR6_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM1_SR7_CAT        (IRQ_CAT1)
                                                                                                           
/* GTM TOM1 interrupt Priority Setting */  
#define IRQ_GTM_TOM1_SR0_PRIO       0x0
#define IRQ_GTM_TOM1_SR1_PRIO       0x0
#define IRQ_GTM_TOM1_SR2_PRIO       0x0
#define IRQ_GTM_TOM1_SR3_PRIO       0x0
#define IRQ_GTM_TOM1_SR4_PRIO       0x0
#define IRQ_GTM_TOM1_SR5_PRIO       0x0
#define IRQ_GTM_TOM1_SR6_PRIO       0x0
#define IRQ_GTM_TOM1_SR7_PRIO       0x0

/* GTM TOM1 interrupt type of service Setting */ 
#define IRQ_GTM_TOM1_SR0_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM1_SR1_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM1_SR2_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM1_SR3_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM1_SR4_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM1_SR5_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM1_SR6_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM1_SR7_TOS        (IRQ_TOS_CPU0)

/* GTM TOM2 interrupt Category Setting */ 
#define IRQ_GTM_TOM2_SR0_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM2_SR1_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM2_SR2_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM2_SR3_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM2_SR4_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM2_SR5_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM2_SR6_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM2_SR7_CAT        (IRQ_CAT1)
                                                                                                           
/* GTM TOM2 interrupt Priority Setting */  
#define IRQ_GTM_TOM2_SR0_PRIO       0x0
#define IRQ_GTM_TOM2_SR1_PRIO       0x0
#define IRQ_GTM_TOM2_SR2_PRIO       0x0
#define IRQ_GTM_TOM2_SR3_PRIO       0x0
#define IRQ_GTM_TOM2_SR4_PRIO       0x0
#define IRQ_GTM_TOM2_SR5_PRIO       0x0
#define IRQ_GTM_TOM2_SR6_PRIO       0x0
#define IRQ_GTM_TOM2_SR7_PRIO       0x0

/* GTM TOM2 interrupt type of service Setting */ 
#define IRQ_GTM_TOM2_SR0_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM2_SR1_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM2_SR2_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM2_SR3_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM2_SR4_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM2_SR5_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM2_SR6_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM2_SR7_TOS        (IRQ_TOS_CPU0)



/* GTM ATOM0 interrupt Category Setting */ 
#define IRQ_GTM_ATOM0_SR0_CAT       (IRQ_CAT1)
#define IRQ_GTM_ATOM0_SR1_CAT       (IRQ_CAT1)
#define IRQ_GTM_ATOM0_SR2_CAT       (IRQ_CAT1)
#define IRQ_GTM_ATOM0_SR3_CAT       (IRQ_CAT1)
                                                                                                           
/* GTM ATOM0 interrupt Priority Setting */  
#define IRQ_GTM_ATOM0_SR0_PRIO      0x0
#define IRQ_GTM_ATOM0_SR1_PRIO      0x0
#define IRQ_GTM_ATOM0_SR2_PRIO      0x0
#define IRQ_GTM_ATOM0_SR3_PRIO      0x0

/* GTM ATOM0 interrupt type of service Setting */ 
#define IRQ_GTM_ATOM0_SR0_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_ATOM0_SR1_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_ATOM0_SR2_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_ATOM0_SR3_TOS       (IRQ_TOS_CPU0)

/* GTM ATOM1 interrupt Category Setting */ 
#define IRQ_GTM_ATOM1_SR0_CAT       (IRQ_CAT1)
#define IRQ_GTM_ATOM1_SR1_CAT       (IRQ_CAT1)
#define IRQ_GTM_ATOM1_SR2_CAT       (IRQ_CAT1)
#define IRQ_GTM_ATOM1_SR3_CAT       (IRQ_CAT1)
                                                                                                           
/* GTM ATOM1 interrupt Priority Setting */  
#define IRQ_GTM_ATOM1_SR0_PRIO      0x0
#define IRQ_GTM_ATOM1_SR1_PRIO      0x0
#define IRQ_GTM_ATOM1_SR2_PRIO      0x0
#define IRQ_GTM_ATOM1_SR3_PRIO      0x0

/* GTM ATOM1 interrupt type of service Setting */ 
#define IRQ_GTM_ATOM1_SR0_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_ATOM1_SR1_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_ATOM1_SR2_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_ATOM1_SR3_TOS       (IRQ_TOS_CPU0)

/* GTM ATOM2 interrupt Category Setting */ 
#define IRQ_GTM_ATOM2_SR0_CAT       (IRQ_CAT1)
#define IRQ_GTM_ATOM2_SR1_CAT       (IRQ_CAT1)
#define IRQ_GTM_ATOM2_SR2_CAT       (IRQ_CAT1)
#define IRQ_GTM_ATOM2_SR3_CAT       (IRQ_CAT1)
                                                                                                           
/* GTM ATOM2 interrupt Priority Setting */  
#define IRQ_GTM_ATOM2_SR0_PRIO      0x0
#define IRQ_GTM_ATOM2_SR1_PRIO      0x0
#define IRQ_GTM_ATOM2_SR2_PRIO      0x0
#define IRQ_GTM_ATOM2_SR3_PRIO      0x0

/* GTM ATOM2 interrupt type of service Setting */ 
#define IRQ_GTM_ATOM2_SR0_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_ATOM2_SR1_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_ATOM2_SR2_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_ATOM2_SR3_TOS       (IRQ_TOS_CPU0)

/* GTM ATOM3 interrupt Category Setting */ 
#define IRQ_GTM_ATOM3_SR0_CAT       (IRQ_CAT1)
#define IRQ_GTM_ATOM3_SR1_CAT       (IRQ_CAT1)
#define IRQ_GTM_ATOM3_SR2_CAT       (IRQ_CAT1)
#define IRQ_GTM_ATOM3_SR3_CAT       (IRQ_CAT1)
                                                                                                           
/* GTM ATOM3 interrupt Priority Setting */  
#define IRQ_GTM_ATOM3_SR0_PRIO      0x0
#define IRQ_GTM_ATOM3_SR1_PRIO      0x0
#define IRQ_GTM_ATOM3_SR2_PRIO      0x0
#define IRQ_GTM_ATOM3_SR3_PRIO      0x0

/* GTM ATOM3 interrupt type of service Setting */ 
#define IRQ_GTM_ATOM3_SR0_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_ATOM3_SR1_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_ATOM3_SR2_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_ATOM3_SR3_TOS       (IRQ_TOS_CPU0)

/* GTM ATOM4 interrupt Category Setting */ 
#define IRQ_GTM_ATOM4_SR0_CAT       (IRQ_CAT1)
#define IRQ_GTM_ATOM4_SR1_CAT       (IRQ_CAT1)
#define IRQ_GTM_ATOM4_SR2_CAT       (IRQ_CAT1)
#define IRQ_GTM_ATOM4_SR3_CAT       (IRQ_CAT1)
                                                                                                           
/* GTM ATOM4 interrupt Priority Setting */  
#define IRQ_GTM_ATOM4_SR0_PRIO      0x0
#define IRQ_GTM_ATOM4_SR1_PRIO      0x0
#define IRQ_GTM_ATOM4_SR2_PRIO      0x0
#define IRQ_GTM_ATOM4_SR3_PRIO      0x0

/* GTM ATOM4 interrupt type of service Setting */ 
#define IRQ_GTM_ATOM4_SR0_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_ATOM4_SR1_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_ATOM4_SR2_TOS       (IRQ_TOS_CPU0)
#define IRQ_GTM_ATOM4_SR3_TOS       (IRQ_TOS_CPU0)






/*
                     Container : IrqSentInterruptConfiguration
*/
/* SENT Interrupt Category setting */
#define IRQ_SENT_SR0_CAT            (IRQ_CAT1)
#define IRQ_SENT_SR1_CAT            (IRQ_CAT1)
#define IRQ_SENT_SR2_CAT            (IRQ_CAT1)
#define IRQ_SENT_SR3_CAT            (IRQ_CAT1)
#define IRQ_SENT_SR4_CAT            (IRQ_CAT1)
#define IRQ_SENT_SR5_CAT            (IRQ_CAT1)
#define IRQ_SENT_SR6_CAT            (IRQ_CAT1)
#define IRQ_SENT_SR7_CAT            (IRQ_CAT1)
#define IRQ_SENT_SR8_CAT            (IRQ_CAT1)
#define IRQ_SENT_SR9_CAT           (IRQ_CAT1)

/*  SENT Interrupt Priority setting  */
#define IRQ_SENT_SR0_PRIO           0x0
#define IRQ_SENT_SR1_PRIO           0x0
#define IRQ_SENT_SR2_PRIO           0x0
#define IRQ_SENT_SR3_PRIO           0x0
#define IRQ_SENT_SR4_PRIO           0x0
#define IRQ_SENT_SR5_PRIO           0x0
#define IRQ_SENT_SR6_PRIO           0x0
#define IRQ_SENT_SR7_PRIO           0x0
#define IRQ_SENT_SR8_PRIO           0x0
#define IRQ_SENT_SR9_PRIO          0x0


/* SENT Interrupt type of service setting */
#define IRQ_SENT_SR0_TOS            (IRQ_TOS_CPU0)
#define IRQ_SENT_SR1_TOS            (IRQ_TOS_CPU0)
#define IRQ_SENT_SR2_TOS            (IRQ_TOS_CPU0)
#define IRQ_SENT_SR3_TOS            (IRQ_TOS_CPU0)
#define IRQ_SENT_SR4_TOS            (IRQ_TOS_CPU0)
#define IRQ_SENT_SR5_TOS            (IRQ_TOS_CPU0)
#define IRQ_SENT_SR6_TOS            (IRQ_TOS_CPU0)
#define IRQ_SENT_SR7_TOS            (IRQ_TOS_CPU0)
#define IRQ_SENT_SR8_TOS            (IRQ_TOS_CPU0)
#define IRQ_SENT_SR9_TOS           (IRQ_TOS_CPU0)

/*
                     Container : IrqI2C interruptConfiguration
*/
/*I2C0 interrupt Category setting */
#define IRQ_I2C0_BREQ_CAT            (IRQ_CAT1)
#define IRQ_I2C0_LBREQ_CAT           (IRQ_CAT1)
#define IRQ_I2C0_SREQ_CAT            (IRQ_CAT1)
#define IRQ_I2C0_LSREQ_CAT           (IRQ_CAT1)
#define IRQ_I2C0_ERR_CAT             (IRQ_CAT1)
#define IRQ_I2C0_P_CAT               (IRQ_CAT1)
                                                                                                           
/*I2C0 interrupt Priority setting */ 
#define IRQ_I2C0_BREQ_PRIO           0x0
#define IRQ_I2C0_LBREQ_PRIO          0x0
#define IRQ_I2C0_SREQ_PRIO           0x0
#define IRQ_I2C0_LSREQ_PRIO          0x0
#define IRQ_I2C0_ERR_PRIO            0x0
#define IRQ_I2C0_P_PRIO              0x0

/*I2C0 interrupt type of service setting */
#define IRQ_I2C0_BREQ_TOS            (IRQ_TOS_CPU0)
#define IRQ_I2C0_LBREQ_TOS           (IRQ_TOS_CPU0)
#define IRQ_I2C0_SREQ_TOS            (IRQ_TOS_CPU0)
#define IRQ_I2C0_LSREQ_TOS           (IRQ_TOS_CPU0)
#define IRQ_I2C0_ERR_TOS             (IRQ_TOS_CPU0)
#define IRQ_I2C0_P_TOS               (IRQ_TOS_CPU0)


/*
                     Container : IrqHssl interruptConfiguration
*/
/* HSSL Cok interrupt Category Setting*/
#define IRQ_HSSL0_COK_CAT          (IRQ_CAT1)
#define IRQ_HSSL1_COK_CAT          (IRQ_CAT1)
#define IRQ_HSSL2_COK_CAT          (IRQ_CAT1)
#define IRQ_HSSL3_COK_CAT          (IRQ_CAT1)

/* HSSL Cok interrupt Priority Setting*/
#define IRQ_HSSL0_COK_PRIO         0x0
#define IRQ_HSSL1_COK_PRIO         0x0
#define IRQ_HSSL2_COK_PRIO         0x0
#define IRQ_HSSL3_COK_PRIO         0x0

/* HSSL Cok interrupt type of service Setting*/
#define IRQ_HSSL0_COK_TOS          (IRQ_TOS_CPU0)
#define IRQ_HSSL1_COK_TOS          (IRQ_TOS_CPU0)
#define IRQ_HSSL2_COK_TOS          (IRQ_TOS_CPU0)
#define IRQ_HSSL3_COK_TOS          (IRQ_TOS_CPU0)

/* HSSL Trg interrupt Category Setting*/
#define IRQ_HSSL0_TRG_CAT          (IRQ_CAT1)
#define IRQ_HSSL1_TRG_CAT          (IRQ_CAT1)
#define IRQ_HSSL2_TRG_CAT          (IRQ_CAT1)
#define IRQ_HSSL3_TRG_CAT          (IRQ_CAT1)

/* HSSL Trg interrupt Priority Setting*/
#define IRQ_HSSL0_TRG_PRIO         0x0
#define IRQ_HSSL1_TRG_PRIO         0x0
#define IRQ_HSSL2_TRG_PRIO         0x0
#define IRQ_HSSL3_TRG_PRIO         0x0

/* HSSL Trg interrupt type of service Setting*/
#define IRQ_HSSL0_TRG_TOS          (IRQ_TOS_CPU0)
#define IRQ_HSSL1_TRG_TOS          (IRQ_TOS_CPU0)
#define IRQ_HSSL2_TRG_TOS          (IRQ_TOS_CPU0)
#define IRQ_HSSL3_TRG_TOS          (IRQ_TOS_CPU0)

/* HSSL Rdi interrupt Category Setting*/
#define IRQ_HSSL0_RDI_CAT          (IRQ_CAT1)
#define IRQ_HSSL1_RDI_CAT          (IRQ_CAT1)
#define IRQ_HSSL2_RDI_CAT          (IRQ_CAT1)
#define IRQ_HSSL3_RDI_CAT          (IRQ_CAT1)

/* HSSL Rdi interrupt Priority Setting*/
#define IRQ_HSSL0_RDI_PRIO         0x0
#define IRQ_HSSL1_RDI_PRIO         0x0
#define IRQ_HSSL2_RDI_PRIO         0x0
#define IRQ_HSSL3_RDI_PRIO         0x0

/* HSSL Rdi interrupt type of service Setting*/
#define IRQ_HSSL0_RDI_TOS          (IRQ_TOS_CPU0)
#define IRQ_HSSL1_RDI_TOS          (IRQ_TOS_CPU0)
#define IRQ_HSSL2_RDI_TOS          (IRQ_TOS_CPU0)
#define IRQ_HSSL3_RDI_TOS          (IRQ_TOS_CPU0)

/* HSSL Err interrupt Category Setting*/
#define IRQ_HSSL0_ERR_CAT         (IRQ_CAT1)
#define IRQ_HSSL1_ERR_CAT         (IRQ_CAT1)
#define IRQ_HSSL2_ERR_CAT         (IRQ_CAT1)
#define IRQ_HSSL3_ERR_CAT         (IRQ_CAT1)

/* HSSL Err interrupt Priority Setting*/
#define IRQ_HSSL0_ERR_PRIO        0x0
#define IRQ_HSSL1_ERR_PRIO        0x0
#define IRQ_HSSL2_ERR_PRIO        0x0
#define IRQ_HSSL3_ERR_PRIO        0x0

/* HSSL Err interrupt type of service Setting*/
#define IRQ_HSSL0_ERR_TOS         (IRQ_TOS_CPU0)
#define IRQ_HSSL1_ERR_TOS         (IRQ_TOS_CPU0)
#define IRQ_HSSL2_ERR_TOS         (IRQ_TOS_CPU0)
#define IRQ_HSSL3_ERR_TOS         (IRQ_TOS_CPU0)

/* HSSL Exi interrupt Category Setting*/
#define IRQ_HSSL_EXI_CAT          (IRQ_CAT1)

/* HSSL Exi interrupt Priority Setting*/
#define IRQ_HSSL_EXI_PRIO         0x0

/* HSSL Exi interrupt type of service Setting*/
#define IRQ_HSSL_EXI_TOS          (IRQ_TOS_CPU0)

/* Global macros that determines whether a module / SRN is in use or not
*/
#define IRQ_ASCLIN_EXIST            (STD_ON)
#define IRQ_ASCLIN0_EXIST           (STD_ON)
#define IRQ_ASCLIN1_EXIST           (STD_ON)
#define IRQ_ASCLIN2_EXIST           (STD_ON)
#define IRQ_ASCLIN3_EXIST           (STD_ON)

#define IRQ_QSPI_EXIST              (STD_OFF)
#define IRQ_QSPI0_EXIST             (STD_OFF)
#define IRQ_QSPI1_EXIST             (STD_OFF)
#define IRQ_QSPI2_EXIST             (STD_OFF)

#define IRQ_QSPI3_EXIST             (STD_OFF)
#define IRQ_QSPI4_EXIST             (STD_OFF)
#define IRQ_QSPI5_EXIST             (STD_OFF)
#define IRQ_QSPI_HC_SRN_EXIST       (STD_OFF)

#define IRQ_MSC_EXIST               (STD_OFF)
#define IRQ_MSC0_EXIST              (STD_OFF)
#define IRQ_MSC1_EXIST              (STD_OFF)
#define IRQ_MSC2_EXIST              (STD_OFF)

#define IRQ_CCU6_EXIST              (STD_ON)
#define IRQ_CCU60_EXIST             (STD_ON)
#define IRQ_CCU61_EXIST             (STD_ON)

#define IRQ_GPT_EXIST               (STD_ON)
#define IRQ_GPT120_EXIST            (STD_ON)

#define IRQ_STM_EXIST               (STD_ON)
#define IRQ_STM0_EXIST              (STD_ON)
#define IRQ_STM1_EXIST              (STD_ON)
#define IRQ_STM2_EXIST              (STD_ON)

#define IRQ_DMA_EXIST               (STD_ON)
#define IRQ_DMA_CH0TO47_EXIST       (STD_ON)
#define IRQ_DMA_CH48TO63_EXIST      (STD_ON)
#define IRQ_DMA_CH64TO127_EXIST     (STD_OFF)

#define IRQ_ETH_EXIST               (STD_OFF)

#define IRQ_CAN_EXIST               (STD_ON)
#define IRQ_CAN0_EXIST              (STD_ON)
#define IRQ_CAN1_EXIST              (STD_ON)
#define IRQ_CAN2_EXIST              (STD_ON)
#define IRQ_CAN3_EXIST              (STD_ON)
#define IRQ_CAN4_EXIST              (STD_ON)
#define IRQ_CAN5_EXIST              (STD_ON)
#define IRQ_CAN6_EXIST              (STD_ON)
#define IRQ_CAN7_EXIST              (STD_ON)
#define IRQ_CAN8_EXIST              (STD_ON)
#define IRQ_CAN9_EXIST              (STD_ON)
#define IRQ_CAN10_EXIST             (STD_ON)
#define IRQ_CAN11_EXIST             (STD_ON)
#define IRQ_CAN12_EXIST             (STD_ON)
#define IRQ_CAN13_EXIST             (STD_ON)
#define IRQ_CAN14_EXIST             (STD_ON)
#define IRQ_CAN15_EXIST             (STD_ON)
#define IRQ_CAN16_EXIST             (STD_OFF)
#define IRQ_CAN17_EXIST             (STD_OFF)
#define IRQ_CAN18_EXIST             (STD_OFF)
#define IRQ_CAN19_EXIST             (STD_OFF)
#define IRQ_CAN20_EXIST             (STD_OFF)
#define IRQ_CAN21_EXIST             (STD_OFF)
#define IRQ_CAN22_EXIST             (STD_OFF)
#define IRQ_CAN23_EXIST             (STD_OFF)


#define IRQ_HSM0_EXIST              (STD_ON)
#define IRQ_HSM1_EXIST              (STD_ON)


#define IRQ_ADC_EXIST               (STD_ON)
#define IRQ_ADC0_EXIST              (STD_ON)
#define IRQ_ADC1_EXIST              (STD_ON)
#define IRQ_ADC2_EXIST              (STD_ON)
#define IRQ_ADC3_EXIST              (STD_ON)
#define IRQ_ADC4_EXIST              (STD_ON)
#define IRQ_ADC5_EXIST              (STD_ON)
#define IRQ_ADC6_EXIST              (STD_ON)
#define IRQ_ADC7_EXIST              (STD_ON)
#define IRQ_ADC8_EXIST              (STD_OFF)
#define IRQ_ADC9_EXIST              (STD_OFF)
#define IRQ_ADC10_EXIST             (STD_OFF)
#define IRQ_ADCCG0_EXIST            (STD_ON)
#define IRQ_ADCCG1_EXIST            (STD_ON)

#define IRQ_DSADC_EXIST             (STD_OFF)
#define IRQ_DSADC_M0_EXIST          (STD_OFF)
#define IRQ_DSADC_A0_EXIST          (STD_OFF)
#define IRQ_DSADC_M1_EXIST          (STD_OFF)
#define IRQ_DSADC_A1_EXIST          (STD_OFF)
#define IRQ_DSADC_M2_EXIST          (STD_OFF)
#define IRQ_DSADC_A2_EXIST          (STD_OFF)
#define IRQ_DSADC_M3_EXIST          (STD_OFF)
#define IRQ_DSADC_A3_EXIST          (STD_OFF)
#define IRQ_DSADC_M4_EXIST          (STD_OFF)
#define IRQ_DSADC_A4_EXIST          (STD_OFF)
#define IRQ_DSADC_M5_EXIST          (STD_OFF)
#define IRQ_DSADC_A5_EXIST          (STD_OFF)
#define IRQ_DSADC_M6_EXIST          (STD_OFF)
#define IRQ_DSADC_A6_EXIST          (STD_OFF)
#define IRQ_DSADC_M7_EXIST          (STD_OFF)
#define IRQ_DSADC_A7_EXIST          (STD_OFF)
#define IRQ_DSADC_M8_EXIST          (STD_OFF)
#define IRQ_DSADC_A8_EXIST          (STD_OFF)
#define IRQ_DSADC_M9_EXIST          (STD_OFF)
#define IRQ_DSADC_A9_EXIST          (STD_OFF)

#define IRQ_FLEXRAY_EXIST           (STD_OFF)
#define IRQ_FLEXRAY0_EXIST          (STD_OFF)
#define IRQ_FLEXRAY1_EXIST          (STD_OFF)

#define IRQ_PMU0_EXIST              (STD_OFF)
#define IRQ_PMU0_SR0_EXIST          (STD_OFF)
#define IRQ_PMU0_SR1_EXIST          (STD_OFF)

#define IRQ_SCU_EXIST               (STD_ON)

#define IRQ_GPSRGROUP_EXIST         (STD_ON)
#define IRQ_GPSRGROUP0_EXIST        (STD_ON)
#define IRQ_GPSRGROUP1_EXIST        (STD_ON)
#define IRQ_GPSRGROUP2_EXIST        (STD_ON)


#define IRQ_GTM_EXIST               (STD_ON)
#define IRQ_GTM_AEI_EXIST           (STD_ON)
#define IRQ_GTM_ARU_EXIST           (STD_ON)
#define IRQ_GTM_BRC_EXIST           (STD_ON)
#define IRQ_GTM_CMP_EXIST           (STD_ON)
#define IRQ_GTM_SPE_EXIST           (STD_ON)
#define IRQ_GTM_SPE0_EXIST           (STD_ON)
#define IRQ_GTM_SPE1_EXIST           (STD_ON)
#define IRQ_GTM_SPE2_EXIST           (STD_OFF)
#define IRQ_GTM_SPE3_EXIST           (STD_OFF)
#define IRQ_GTM_PSM0_EXIST          (STD_ON)
#define IRQ_GTM_PSM1_EXIST          (STD_OFF)
#define IRQ_GTM_DPLL_EXIST          (STD_ON)
#define IRQ_GTM_ERR_EXIST           (STD_ON)
#define IRQ_GTM_TIM0_EXIST          (STD_ON)
#define IRQ_GTM_TIM1_EXIST          (STD_ON)
#define IRQ_GTM_TIM2_EXIST          (STD_ON)
#define IRQ_GTM_TIM3_EXIST          (STD_ON)
#define IRQ_GTM_TIM4_EXIST          (STD_OFF)
#define IRQ_GTM_TIM5_EXIST          (STD_OFF)
#define IRQ_GTM_MCS0_EXIST          (STD_ON)
#define IRQ_GTM_MCS1_EXIST          (STD_ON)
#define IRQ_GTM_MCS2_EXIST          (STD_ON)
#define IRQ_GTM_MCS3_EXIST          (STD_ON)
#define IRQ_GTM_MCS4_EXIST          (STD_OFF)
#define IRQ_GTM_MCS5_EXIST          (STD_OFF)
#define IRQ_GTM_TOM0_EXIST          (STD_ON)
#define IRQ_GTM_TOM1_EXIST          (STD_ON)
#define IRQ_GTM_TOM2_EXIST          (STD_ON)
#define IRQ_GTM_TOM3_EXIST          (STD_OFF)
#define IRQ_GTM_TOM4_EXIST          (STD_OFF)
#define IRQ_GTM_ATOM0_EXIST         (STD_ON)
#define IRQ_GTM_ATOM1_EXIST         (STD_ON)
#define IRQ_GTM_ATOM2_EXIST         (STD_ON)
#define IRQ_GTM_ATOM3_EXIST         (STD_ON)
#define IRQ_GTM_ATOM4_EXIST         (STD_ON)
#define IRQ_GTM_ATOM5_EXIST         (STD_OFF)
#define IRQ_GTM_ATOM6_EXIST         (STD_OFF)
#define IRQ_GTM_ATOM7_EXIST         (STD_OFF)
#define IRQ_GTM_ATOM8_EXIST         (STD_OFF)

#define IRQ_SENT_EXIST              (STD_OFF)
#define IRQ_SENT0_EXIST             (STD_OFF)
#define IRQ_SENT1_EXIST             (STD_OFF)
#define IRQ_SENT2_EXIST             (STD_OFF)
#define IRQ_SENT3_EXIST             (STD_OFF)
#define IRQ_SENT4_EXIST             (STD_OFF)
#define IRQ_SENT5_EXIST             (STD_OFF)
#define IRQ_SENT6_EXIST             (STD_OFF)
#define IRQ_SENT7_EXIST             (STD_OFF)
#define IRQ_SENT8_EXIST             (STD_OFF)
#define IRQ_SENT9_EXIST             (STD_OFF)
#define IRQ_SENT10_EXIST            (STD_OFF)
#define IRQ_SENT11_EXIST            (STD_OFF)
#define IRQ_SENT12_EXIST            (STD_OFF)
#define IRQ_SENT13_EXIST            (STD_OFF)
#define IRQ_SENT14_EXIST            (STD_OFF)

#define IRQ_I2C_EXIST               (STD_OFF)
#define IRQ_I2C0_EXIST              (STD_OFF)
#define IRQ_I2C1_EXIST              (STD_OFF)

#define IRQ_HSSL_EXIST              (STD_OFF)
#define IRQ_HSSL0_EXIST             (STD_OFF)
#define IRQ_HSSL1_EXIST             (STD_OFF)
#define IRQ_HSSL2_EXIST             (STD_OFF)

#define IRQ_HSSL3_EXIST             (STD_OFF)
#define IRQ_HSSL_EXI_SRN_EXIST       (STD_OFF)
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

/* IRQ_CFG_H */
#endif

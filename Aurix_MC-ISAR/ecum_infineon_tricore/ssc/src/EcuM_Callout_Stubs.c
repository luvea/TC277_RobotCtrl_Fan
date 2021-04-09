/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : EcuM_Callout_Stubs.c $                                     **
**                                                                           **
**  $CC VERSION : \main\53 $                                                 **
**                                                                           **
**  $DATE       : 2016-07-01 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : Contains a simple example of ECU State Manager Code       **
**                 This file is for Evaluation Purpose Only                  **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "EcuM.h"
#include "EcuM_Cbk.h"
/* Include Interrupt header file */
#include "Irq.h"
#include "Mcu.h"
/* Inclusion of controller sfr file */
#include "IfxSmu_reg.h"
#include "IfxScu_reg.h"

#ifdef ECUM_USES_GPT
#include "Gpt.h"
#endif
#ifdef ECUM_USES_PORT
#include "Port.h"
#endif
#ifdef ECUM_USES_DIO
#include "Dio.h"
#endif
#ifdef ECUM_USES_GTM
#include "Gtm.h"
#endif
#ifdef ECUM_USES_DMA
#include "Dma.h"
#endif
#ifdef ECUM_USES_SPI
#include "Spi.h"
#endif
#ifdef ECUM_USES_ADC
#include "Adc.h"
#endif
#ifdef ECUM_USES_FLS
#include "Fls_17_Pmu.h"
#endif
#ifdef ECUM_USES_FEE
#include "Fee.h"
#endif
#ifdef ECUM_USES_CAN
#include "Can_17_MCanP.h"
#endif
#ifdef ECUM_USES_PWM
#include "Pwm_17_Gtm.h"
#endif
#ifdef ECUM_USES_FADC
#include "Fadc.h"
#endif
#ifdef ECUM_USES_ICU
#include "Icu_17_GtmCcu6.h"
#endif
#ifdef ECUM_USES_WDG
#include "Wdg_17_Scu.h"
#endif
#ifdef ECUM_USES_MLI
#include "Mli.h"
#endif
#ifdef ECUM_USES_SCI
#include "Sci.h"
#endif
#ifdef ECUM_USES_MCHK
#include "Mchk.h"
#endif
#ifdef ECUM_USES_MSC
#include "Msc.h"
#endif

#ifdef ECUM_USES_LIN
#include "Lin_17_AscLin.h"
#endif

#ifdef ECUM_USES_UART
#include "Uart.h"
#endif

#ifdef ECUM_USES_ETH
#include "Eth_17_EthMac.h"
#endif

#ifdef ECUM_USES_RAMTST
#include "RamTst_Api.h"
#endif

#ifdef ECUM_USES_FR_17_ERAY
#include "Fr_17_Eray.h"
#endif

#ifdef ECUM_USES_FLSLOADER
#include "FlsLoader.h"
#endif

#ifdef ECUM_USES_SENT
#include "Sent.h"
#endif

#ifdef ECUM_USES_IOM
#include "Iom.h"
#endif

#ifdef ECUM_USES_CANTRCV_17_6250GV33
#include "CanTrcv_17_6250GV33.h"
#endif

#ifdef ECUM_USES_CANTRCV_17_6251G
#include "CanTrcv_17_6251G.h"
#endif

#ifdef ECUM_USES_HSSL
#include "Hssl.h"
#endif

#ifdef ECUM_USES_DSADC
#include "Dsadc.h"
#endif

#ifdef ECUM_USES_SMU
#include "SmuInt.h"
#endif

#ifdef ECUM_USES_I2C
#include "I2c.h"
#endif

/* Mcal Safety ENDINIT Timeout value */
#define ECUM_ENDINIT_TIMEOUT   (150000U)

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define ECUM_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives 
  is allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
** Syntax           : void EcuM_AL_DriverInitOne(const EcuM_ConfigType        **
                                                 *configptr)                  **
**                                                                            **
** Description      : initializes clock and interrupts                        **
**                                                                            **                                                                                                                                 **
*******************************************************************************/
void EcuM_AL_DriverInitOne(const EcuM_ConfigType *configptr) 
{
  /* Initialize MCU Clock*/
  /* parameter 0 is chosen here by default, the first clock configuration */
  Mcu_InitClock(0);    
  /* wait till PLL lock */
  while(Mcu_GetPllStatus() == 0);
  /* distribute the clock */
  Mcu_DistributePllClock();  
  
  /* SMU is configured for Reset on WDG timeout */

  Mcal_ResetENDINIT();
  SCU_TRAPDIS.B.SMUT = 0;
  Mcal_SetENDINIT();
  #if (IFX_SAFETLIB_USED == STD_OFF)
  Mcal_ResetSafetyENDINIT_Timed(ECUM_ENDINIT_TIMEOUT);
  SMU_KEYS.U = 0xbc; 
  SMU_CMD.U = 0x00;
  SMU_AGCF3_0.U = 0x00000000;
  SMU_AGCF3_1.U = 0x001E0000;
  SMU_AGCF3_2.U = 0x001E0000;
  Mcal_SetSafetyENDINIT_Timed();
  #endif

  Mcal_EnableAllInterrupts();       /* Enable Global Interrupt Flag. */
  /* Initialzie Interrupt Priority initialization*/
  #ifdef ECUM_USES_ADC
  IrqAdc_Init();    /* Initialise the interrupt priority for ADC */
  #endif  
  #ifdef ECUM_USES_SPI 
  IrqSpi_Init();    /* Assign priorities for SPI interrupts */
  #endif 
  IrqDma_Init();    /* Assign priorities for DMA interrupts */
  #ifdef ECUM_USES_MLI
  IrqMli_Init();    /* Assign priorities for MLI interrupts */
  #endif
  #ifdef ECUM_USES_FADC
  IrqFadc_Init();   /* Assign priorities for FADC interrupts */
  #endif
  #ifdef ECUM_USES_CAN
  IrqCan_Init();    /* Assign priorities for CAN interrupts */
  #endif  
  IrqStm_Init();    /* Assign priorities for STM interrupts */
  #ifdef ECUM_USES_FLS
  IrqPmu_Init();
  #endif  
  #if( defined( ECUM_USES_LIN ) || defined( ECUM_USES_UART) )
  IrqAscLin_Init();    /* Assign priorities for SCI interrupts */
  #endif
  #ifdef ECUM_USES_MSC
  IrqMsc_Init();    /* Assign priorities for MSC interrupts */
  #endif
  #ifdef ECUM_USES_ERU
  IrqScu_Init();     /* Assign priorities for ERU interrupts */
  #endif
  #ifdef ECUM_USES_GTM
  IrqGtm_Init();     /* Assign priorities for GTM interrupts */
  #endif  
  #ifdef ECUM_USES_ETH
  IrqEthernet_Init();     /* Assign priorities for GTM interrupts */
  #endif 
  #ifdef ECUM_USES_CCU
  IrqCcu6_Init();
  #endif 
  #ifdef ECUM_USES_SENT
  IrqSent_Init();
  #endif   
  #ifdef ECUM_USES_I2C
  IrqI2c_Init();
  #endif
  /* This is a macro defined in the EcuM_Cfg.h. The body of this call is 
     generated from the configuration tool*/
  EcuM_DriverInitListOneConfig(configptr);  
}


/*******************************************************************************
** Syntax           : void EcuM_AL_DriverInitTwo(const EcuM_ConfigType        **
**                                               *configptr)                  **
**                                                                            **
**                                                                            **
** Description      : list two driver intialization                           **
**                                                                            **                                                                                                                                 **
*******************************************************************************/
void EcuM_AL_DriverInitTwo(const EcuM_ConfigType *configptr) 
{
  /* This is a macro defined in the EcuM_Cfg.h. The body of this call is 
     generated from the configuration tool*/
  EcuM_DriverInitListTwoConfig(configptr);
	/* unused param warning removal for GNU */
	UNUSED_PARAMETER(configptr)
}

/*******************************************************************************
** Syntax           : void EcuM_AL_DriverInitThree(const EcuM_ConfigType      **
**                                                 *configptr)                **
**                                                                            **
**                                                                            **
** Description      : List three intialization                                **
**                                                                            **                                                                                                                                 **
*******************************************************************************/
void EcuM_AL_DriverInitThree(const EcuM_ConfigType *configptr) 
{
  /* This is a macro defined in the EcuM_Cfg.h. The body of this call is 
     generated from the configuration tool*/
  EcuM_DriverInitListThreeConfig(configptr);
	/* unused param warning removal for GNU */
	UNUSED_PARAMETER(configptr)
}

/*******************************************************************************
** Syntax           : void EcuM_AL_DriverInitZero()                           **
**                                                                            **
** Service ID       : 0                                                       **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : List zero, modules like DET can be initialized          **
**                    post build modules cannot be loaded from here           **
**                                                                            **                                                                                                                                 **
*******************************************************************************/
void EcuM_AL_DriverInitZero() 
{
  /* This is a macro defined in the EcuM_Cfg.h. The body of this call is
     generated from the configuration tool */
  EcuM_DriverInitListZeroConfig();

}
#define ECUM_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives 
  is allowed only for MemMap.h*/
#include "MemMap.h"

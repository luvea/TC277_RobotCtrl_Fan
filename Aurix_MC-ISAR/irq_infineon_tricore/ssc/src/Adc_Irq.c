/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2014)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Adc_Irq.c $                                                **
**                                                                           **
**  $CC VERSION : \main\dev_tc23x\7 $                                        **
**                                                                           **
**  $DATE       : 2016-06-27 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains the interrupt frames for the ADC Module.**
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Std_Types.h"
#include "Irq.h"
#include "Mcal.h"
#include "Adc.h"
#include "Notification_Adc3ph_Result.h"
/*******************************************************************************
**                      Private Macros Definitions                            **
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
**                      Private Function Definitions                          **
*******************************************************************************/
#define IRQ_START_SEC_CODE
#include "MemMap.h"

#if (IRQ_ADC0_EXIST == STD_ON)
/******************************************************************************
** Syntax :          void ADC0SR0_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC0_SR0_PRIO > 0) || (IRQ_ADC0_SR0_CAT == IRQ_CAT23))
#if((IRQ_ADC0_SR0_PRIO > 0) && (IRQ_ADC0_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC0SR0_ISR, 0, IRQ_ADC0_SR0_PRIO)
#elif IRQ_ADC0_SR0_CAT == IRQ_CAT23
ISR(ADC0SR0_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_ADC0_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

/* ADC0 SRN0 is used by request source 0 of ADC0 */
#if (ADC0_REQSRC0 == ADC_REQSRC_USED)
  /* Call Adc Interrupt function*/
  UVW_Complete_AdcNotification();

//  Adc_IsrSrn0AdcRS0(ADC_HWUNIT_ADC0);
#endif

}
#endif

/******************************************************************************
** Syntax :          void ADC0SR1_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC0_SR1_PRIO > 0) || (IRQ_ADC0_SR1_CAT == IRQ_CAT23))
#if((IRQ_ADC0_SR1_PRIO > 0) && (IRQ_ADC0_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC0SR1_ISR,0,IRQ_ADC0_SR1_PRIO)
#elif IRQ_ADC0_SR1_CAT == IRQ_CAT23
ISR(ADC0SR1_ISR)
#endif
{
     
  /* Enable Global Interrupts */
#if (IRQ_ADC0_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

/* ADC0 SRN1 is used by request source 1 of ADC0 */
#if (ADC0_REQSRC1 == ADC_REQSRC_USED)
  /* Call Adc Interrupt function*/
  Adc_IsrSrn1AdcRS1(ADC_HWUNIT_ADC0);
//  UVW_Complete_M3_AdcNotification();
//  UVW_Complete_M4_AdcNotification();

#endif
}
#endif

#endif /* (IRQ_ADC0_EXIST == STD_ON) */

#if (IRQ_ADC1_EXIST == STD_ON)
/******************************************************************************
** Syntax :          void ADC1SR0_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC1_SR0_PRIO > 0) || (IRQ_ADC1_SR0_CAT == IRQ_CAT23))
#if((IRQ_ADC1_SR0_PRIO > 0) && (IRQ_ADC1_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC1SR0_ISR,0,IRQ_ADC1_SR0_PRIO)
#elif IRQ_ADC1_SR0_CAT == IRQ_CAT23
ISR(ADC1SR0_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_ADC1_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

/* ADC1 SRN0 is used by request source 0 of ADC1 */
#if ( (ADC1_REQSRC0 == ADC_REQSRC_USED) || (ADC1_REQSRC3 == ADC_REQSRC_USED) )
  /* Call Adc Interrupt function*/
  Adc_IsrSrn0AdcRS0(ADC_HWUNIT_ADC1);
#endif

}
#endif

/******************************************************************************
** Syntax :          void ADC1SR1_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC1_SR1_PRIO > 0) || (IRQ_ADC1_SR1_CAT == IRQ_CAT23))
#if((IRQ_ADC1_SR1_PRIO > 0) && (IRQ_ADC1_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC1SR1_ISR,0,IRQ_ADC1_SR1_PRIO)
#elif IRQ_ADC1_SR1_CAT == IRQ_CAT23
ISR(ADC1SR1_ISR)
#endif
{
     
  /* Enable Global Interrupts */
#if (IRQ_ADC1_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

/* ADC1 SRN1 is used by request source 1 of ADC1 */
#if (ADC1_REQSRC1 == ADC_REQSRC_USED)
  /* Call Adc Interrupt function*/
  Adc_IsrSrn1AdcRS1(ADC_HWUNIT_ADC1);
#endif
}
#endif

#endif /* (IRQ_ADC1_EXIST == STD_ON) */

#if (IRQ_ADC2_EXIST == STD_ON)
/******************************************************************************
** Syntax :          void ADC2SR0_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC2_SR0_PRIO > 0) || (IRQ_ADC2_SR0_CAT == IRQ_CAT23))
#if((IRQ_ADC2_SR0_PRIO > 0) && (IRQ_ADC2_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC2SR0_ISR,0,IRQ_ADC2_SR0_PRIO)
#elif IRQ_ADC2_SR0_CAT == IRQ_CAT23
ISR(ADC2SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_ADC2_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

/* ADC2 SRN0 is used by request source 0 of ADC2 */
#if (ADC2_REQSRC0 == ADC_REQSRC_USED)
  /* Call Adc Interrupt function*/
  Adc_IsrSrn0AdcRS0(ADC_HWUNIT_ADC2);
#endif

}
#endif

/******************************************************************************
** Syntax :          void ADC2SR1_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC2_SR1_PRIO > 0) || (IRQ_ADC2_SR1_CAT == IRQ_CAT23))
#if((IRQ_ADC2_SR1_PRIO > 0) && (IRQ_ADC2_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC2SR1_ISR,0,IRQ_ADC2_SR1_PRIO)
#elif IRQ_ADC2_SR1_CAT == IRQ_CAT23
ISR(ADC2SR1_ISR)
#endif
{
     
  /* Enable Global Interrupts */
#if (IRQ_ADC2_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

/* ADC2 SRN1 is used by request source 1 of ADC2 */
#if (ADC2_REQSRC1 == ADC_REQSRC_USED)
  /* Call Adc Interrupt function*/
  Adc_IsrSrn1AdcRS1(ADC_HWUNIT_ADC2);
#endif
}
#endif

#endif /* (IRQ_ADC2_EXIST == STD_ON) */

#if (IRQ_ADC3_EXIST == STD_ON)
/******************************************************************************
** Syntax :          void ADC3SR0_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/

uint8 TestIrq3;
#if((IRQ_ADC3_SR0_PRIO > 0) || (IRQ_ADC3_SR0_CAT == IRQ_CAT23))
#if((IRQ_ADC3_SR0_PRIO > 0) && (IRQ_ADC3_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC3SR0_ISR,0,IRQ_ADC3_SR0_PRIO)
#elif IRQ_ADC3_SR0_CAT == IRQ_CAT23
ISR(ADC3SR0_ISR)
#endif
{
	TestIrq3++;
  /* Enable Global Interrupts */
#if (IRQ_ADC3_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

/* ADC3 SRN0 is used by request source 0 of ADC3 */
#if (ADC3_REQSRC0 == ADC_REQSRC_USED)
  /* Call Adc Interrupt function*/
  Adc_IsrSrn0AdcRS0(ADC_HWUNIT_ADC3);
#endif

}
#endif

/******************************************************************************
** Syntax :          void ADC3SR1_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC3_SR1_PRIO > 0) || (IRQ_ADC3_SR1_CAT == IRQ_CAT23))
#if((IRQ_ADC3_SR1_PRIO > 0) && (IRQ_ADC3_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC3SR1_ISR,0,IRQ_ADC3_SR1_PRIO)
#elif IRQ_ADC3_SR1_CAT == IRQ_CAT23
ISR(ADC3SR1_ISR)
#endif
{
     
  /* Enable Global Interrupts */
#if (IRQ_ADC3_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

/* ADC3 SRN1 is used by request source 1 of ADC3 */
#if (ADC3_REQSRC1 == ADC_REQSRC_USED)
  /* Call Adc Interrupt function*/
  Adc_IsrSrn1AdcRS1(ADC_HWUNIT_ADC3);
#endif
}
#endif

#endif /* (IRQ_ADC3_EXIST == STD_ON) */

#if (IRQ_ADC4_EXIST == STD_ON)
/******************************************************************************
** Syntax :          void ADC4SR0_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC4_SR0_PRIO > 0) || (IRQ_ADC4_SR0_CAT == IRQ_CAT23))
#if((IRQ_ADC4_SR0_PRIO > 0) && (IRQ_ADC4_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC4SR0_ISR,0,IRQ_ADC4_SR0_PRIO)
#elif IRQ_ADC4_SR0_CAT == IRQ_CAT23
ISR(ADC4SR0_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_ADC4_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

/* ADC4 SRN0 is used by request source 0 of ADC4 */
#if (ADC4_REQSRC0 == ADC_REQSRC_USED)
  /* Call Adc Interrupt function*/
  Adc_IsrSrn0AdcRS0(ADC_HWUNIT_ADC4);
#endif

}
#endif

/******************************************************************************
** Syntax :          void ADC4SR1_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC4_SR1_PRIO > 0) || (IRQ_ADC4_SR1_CAT == IRQ_CAT23))
#if((IRQ_ADC4_SR1_PRIO > 0) && (IRQ_ADC4_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC4SR1_ISR,0,IRQ_ADC4_SR1_PRIO)
#elif IRQ_ADC4_SR1_CAT == IRQ_CAT23
ISR(ADC4SR1_ISR)
#endif
{
     
  /* Enable Global Interrupts */
#if (IRQ_ADC4_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

/* ADC4 SRN1 is used by request source 1 of ADC4 */
#if (ADC4_REQSRC1 == ADC_REQSRC_USED)
  /* Call Adc Interrupt function*/
  Adc_IsrSrn1AdcRS1(ADC_HWUNIT_ADC4);
#endif
}
#endif

#endif /* (IRQ_ADC4_EXIST == STD_ON) */

#if (IRQ_ADC5_EXIST == STD_ON)
/******************************************************************************
** Syntax :          void ADC5SR0_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC5_SR0_PRIO > 0) || (IRQ_ADC5_SR0_CAT == IRQ_CAT23))
#if((IRQ_ADC5_SR0_PRIO > 0) && (IRQ_ADC5_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC5SR0_ISR,0,IRQ_ADC5_SR0_PRIO)
#elif IRQ_ADC5_SR0_CAT == IRQ_CAT23
ISR(ADC5SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_ADC5_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

/* ADC5 SRN0 is used by request source 0 of ADC5 */
#if (ADC5_REQSRC0 == ADC_REQSRC_USED)
  /* Call Adc Interrupt function*/
  Adc_IsrSrn0AdcRS0(ADC_HWUNIT_ADC5);
#endif

}
#endif

/******************************************************************************
** Syntax :          void ADC5SR1_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC5_SR1_PRIO > 0) || (IRQ_ADC5_SR1_CAT == IRQ_CAT23))
#if((IRQ_ADC5_SR1_PRIO > 0) && (IRQ_ADC5_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC5SR1_ISR,0,IRQ_ADC5_SR1_PRIO)
#elif IRQ_ADC5_SR1_CAT == IRQ_CAT23
ISR(ADC5SR1_ISR)
#endif
{
     
  /* Enable Global Interrupts */
#if (IRQ_ADC5_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

/* ADC5 SRN1 is used by request source 1 of ADC5 */
#if (ADC5_REQSRC1 == ADC_REQSRC_USED)
  /* Call Adc Interrupt function*/
  Adc_IsrSrn1AdcRS1(ADC_HWUNIT_ADC5);
#endif
}
#endif

#endif /* (IRQ_ADC5_EXIST == STD_ON) */

#if (IRQ_ADC6_EXIST == STD_ON)
/******************************************************************************
** Syntax :          void ADC6SR0_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC6_SR0_PRIO > 0) || (IRQ_ADC6_SR0_CAT == IRQ_CAT23))
#if((IRQ_ADC6_SR0_PRIO > 0) && (IRQ_ADC6_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC6SR0_ISR,0,IRQ_ADC6_SR0_PRIO)
#elif IRQ_ADC6_SR0_CAT == IRQ_CAT23
ISR(ADC6SR0_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_ADC6_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

/* ADC6 SRN0 is used by request source 0 of ADC6 */
#if (ADC6_REQSRC0 == ADC_REQSRC_USED)
  /* Call Adc Interrupt function*/
  Adc_IsrSrn0AdcRS0(ADC_HWUNIT_ADC6);
#endif

}
#endif

/******************************************************************************
** Syntax :          void ADC6SR1_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC6_SR1_PRIO > 0) || (IRQ_ADC6_SR1_CAT == IRQ_CAT23))
#if((IRQ_ADC6_SR1_PRIO > 0) && (IRQ_ADC6_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC6SR1_ISR,0,IRQ_ADC6_SR1_PRIO)
#elif IRQ_ADC6_SR1_CAT == IRQ_CAT23
ISR(ADC6SR1_ISR)
#endif
{
     
  /* Enable Global Interrupts */
#if (IRQ_ADC6_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

/* ADC6 SRN1 is used by request source 1 of ADC6 */
#if (ADC6_REQSRC1 == ADC_REQSRC_USED)
  /* Call Adc Interrupt function*/
  Adc_IsrSrn1AdcRS1(ADC_HWUNIT_ADC6);
#endif
}
#endif

#endif /* (IRQ_ADC6_EXIST == STD_ON) */

#if (IRQ_ADC7_EXIST == STD_ON)
/******************************************************************************
** Syntax :          void ADC7SR0_ISR(void)                                 **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC7_SR0_PRIO > 0) || (IRQ_ADC7_SR0_CAT == IRQ_CAT23))
#if((IRQ_ADC7_SR0_PRIO > 0) && (IRQ_ADC7_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC7SR0_ISR,0,IRQ_ADC7_SR0_PRIO)
#elif IRQ_ADC7_SR0_CAT == IRQ_CAT23
ISR(ADC7SR0_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_ADC7_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

/* ADC7 SRN0 is used by request source 0 of ADC7 */
#if (ADC7_REQSRC0 == ADC_REQSRC_USED)
  /* Call Adc Interrupt function*/
  Adc_IsrSrn0AdcRS0(ADC_HWUNIT_ADC7);
#endif

}
#endif

/******************************************************************************
** Syntax :          void ADC7SR1_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC7_SR1_PRIO > 0) || (IRQ_ADC7_SR1_CAT == IRQ_CAT23))
#if((IRQ_ADC7_SR1_PRIO > 0) && (IRQ_ADC7_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC7SR1_ISR,0,IRQ_ADC7_SR1_PRIO)
#elif IRQ_ADC7_SR1_CAT == IRQ_CAT23
ISR(ADC7SR1_ISR)
#endif
{
     
  /* Enable Global Interrupts */
#if (IRQ_ADC7_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

/* ADC7 SRN1 is used by request source 1 of ADC7 */
#if (ADC7_REQSRC1 == ADC_REQSRC_USED)
  /* Call Adc Interrupt function*/
  Adc_IsrSrn1AdcRS1(ADC_HWUNIT_ADC7);
#endif
}
#endif

#endif /* (IRQ_ADC7_EXIST == STD_ON) */

#if (IRQ_ADC8_EXIST == STD_ON)
/******************************************************************************
** Syntax :          void ADC8SR0_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC8_SR0_PRIO > 0) || (IRQ_ADC8_SR0_CAT == IRQ_CAT23))
#if((IRQ_ADC8_SR0_PRIO > 0) && (IRQ_ADC8_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC8SR0_ISR,0,IRQ_ADC8_SR0_PRIO)
#elif IRQ_ADC8_SR0_CAT == IRQ_CAT23
ISR(ADC8SR0_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_ADC8_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

/* ADC8 SRN0 is used by request source 0 of ADC8 */
#if (ADC8_REQSRC0 == ADC_REQSRC_USED)
  /* Call Adc Interrupt function*/
  Adc_IsrSrn0AdcRS0(ADC_HWUNIT_ADC8);
#endif

}
#endif

/******************************************************************************
** Syntax :          void ADC8SR1_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC8_SR1_PRIO > 0) || (IRQ_ADC8_SR1_CAT == IRQ_CAT23))
#if((IRQ_ADC8_SR1_PRIO > 0) && (IRQ_ADC8_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC8SR1_ISR,0,IRQ_ADC8_SR1_PRIO)
#elif IRQ_ADC8_SR1_CAT == IRQ_CAT23
ISR(ADC8SR1_ISR)
#endif
{
     
  /* Enable Global Interrupts */
#if (IRQ_ADC8_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

/* ADC8 SRN1 is used by request source 1 of ADC8 */
#if (ADC8_REQSRC1 == ADC_REQSRC_USED)
  /* Call Adc Interrupt function*/
  Adc_IsrSrn1AdcRS1(ADC_HWUNIT_ADC8);
#endif
}
#endif

#endif /* (IRQ_ADC8_EXIST == STD_ON) */

#if (IRQ_ADC9_EXIST == STD_ON)
/******************************************************************************
** Syntax :          void ADC9SR0_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC9_SR0_PRIO > 0) || (IRQ_ADC9_SR0_CAT == IRQ_CAT23))
#if((IRQ_ADC9_SR0_PRIO > 0) && (IRQ_ADC9_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC9SR0_ISR,0,IRQ_ADC9_SR0_PRIO)
#elif IRQ_ADC9_SR0_CAT == IRQ_CAT23
ISR(ADC9SR0_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_ADC9_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

/* ADC9 SRN0 is used by request source 0 of ADC9 */
#if (ADC9_REQSRC0 == ADC_REQSRC_USED)
  /* Call Adc Interrupt function*/
  Adc_IsrSrn0AdcRS0(ADC_HWUNIT_ADC9);
#endif

}
#endif

/******************************************************************************
** Syntax :          void ADC9SR1_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC9_SR1_PRIO > 0) || (IRQ_ADC9_SR1_CAT == IRQ_CAT23))
#if((IRQ_ADC9_SR1_PRIO > 0) && (IRQ_ADC9_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC9SR1_ISR,0,IRQ_ADC9_SR1_PRIO)
#elif IRQ_ADC9_SR1_CAT == IRQ_CAT23
ISR(ADC9SR1_ISR)
#endif
{
     
  /* Enable Global Interrupts */
#if (IRQ_ADC9_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

/* ADC9 SRN1 is used by request source 1 of ADC9 */
#if (ADC9_REQSRC1 == ADC_REQSRC_USED)
  /* Call Adc Interrupt function*/
  Adc_IsrSrn1AdcRS1(ADC_HWUNIT_ADC9);
#endif
}
#endif

#endif /* (IRQ_ADC9_EXIST == STD_ON) */

#if (IRQ_ADC10_EXIST == STD_ON)
/******************************************************************************
** Syntax :          void ADC10SR0_ISR(void)                                 **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC10_SR0_PRIO > 0) || (IRQ_ADC10_SR0_CAT == IRQ_CAT23))
#if((IRQ_ADC10_SR0_PRIO > 0) && (IRQ_ADC10_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC10SR0_ISR,0,IRQ_ADC10_SR0_PRIO)
#elif IRQ_ADC10_SR0_CAT == IRQ_CAT23
ISR(ADC10SR0_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_ADC10_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

/* ADC10 SRN0 is used by request source 0 of ADC10 */
#if (ADC10_REQSRC0 == ADC_REQSRC_USED)
  /* Call Adc Interrupt function*/
  Adc_IsrSrn0AdcRS0(ADC_HWUNIT_ADC10);
#endif

}
#endif

/******************************************************************************
** Syntax :          void ADC10SR1_ISR(void)                                 **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC10_SR1_PRIO > 0) || (IRQ_ADC10_SR1_CAT == IRQ_CAT23))
#if((IRQ_ADC10_SR1_PRIO > 0) && (IRQ_ADC10_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC10SR1_ISR,0,IRQ_ADC10_SR1_PRIO)
#elif IRQ_ADC10_SR1_CAT == IRQ_CAT23
ISR(ADC10SR1_ISR)
#endif
{
     
  /* Enable Global Interrupts */
#if (IRQ_ADC10_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

/* ADC10 SRN1 is used by request source 1 of ADC10 */
#if (ADC10_REQSRC1 == ADC_REQSRC_USED)
  /* Call Adc Interrupt function*/
  Adc_IsrSrn1AdcRS1(ADC_HWUNIT_ADC10);
#endif
}
#endif

#endif /* (IRQ_ADC10_EXIST == STD_ON) */

#if (IRQ_ADCCG0_EXIST == STD_ON)
/******************************************************************************
** Syntax :          void ADCCG0SR0_ISR(void)                                **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADCCG0_SR0_PRIO > 0) || (IRQ_ADCCG0_SR0_CAT == IRQ_CAT23))
#if((IRQ_ADCCG0_SR0_PRIO > 0) && (IRQ_ADCCG0_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADCCG0SR0_ISR,0,IRQ_ADCCG0_SR0_PRIO)
#elif IRQ_ADCCG0_SR0_CAT == IRQ_CAT23
ISR(ADCCG0SR0_ISR)
#endif
{
     
  /* Enable Global Interrupts */
#if (IRQ_ADCCG0_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

/* CG0 SRN0 is used by request source 2 of All ADC kernels */
#if ( (ADC0_REQSRC2 == ADC_REQSRC_USED) || (ADC1_REQSRC2 == ADC_REQSRC_USED)||\
      (ADC2_REQSRC2 == ADC_REQSRC_USED) || (ADC3_REQSRC2 == ADC_REQSRC_USED)||\
      (ADC4_REQSRC2 == ADC_REQSRC_USED) || (ADC5_REQSRC2 == ADC_REQSRC_USED)||\
      (ADC6_REQSRC2 == ADC_REQSRC_USED) || (ADC7_REQSRC2 == ADC_REQSRC_USED)||\
      (ADC8_REQSRC2 == ADC_REQSRC_USED) || (ADC9_REQSRC2 == ADC_REQSRC_USED)||\
      (ADC10_REQSRC2 == ADC_REQSRC_USED) )
  /* Call Adc Interrupt function*/
  Adc_IsrSrn0CG0AdcRS2();
#endif
}
#endif

/******************************************************************************
** Syntax :          void ADCCG0SR1_ISR(void)                                **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADCCG0_SR1_PRIO > 0) || (IRQ_ADCCG0_SR1_CAT == IRQ_CAT23))
#if((IRQ_ADCCG0_SR1_PRIO > 0) && (IRQ_ADCCG0_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADCCG0SR1_ISR,0,IRQ_ADCCG0_SR1_PRIO)
#elif IRQ_ADCCG0_SR1_CAT == IRQ_CAT23
ISR(ADCCG0SR1_ISR)
#endif
{
     
  /* Enable Global Interrupts */
#if (IRQ_ADCCG0_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

/* CG0 SRN1 is used by request source 3 of ADC0 */
#if (ADC0_REQSRC3 == ADC_REQSRC_USED)
  /* Call Adc Interrupt function*/
  Adc_IsrSrn1CG0AdcRS3(ADC_HWUNIT_ADC0);
#endif
}
#endif

#endif /* (IRQ_ADCCG0_EXIST == STD_ON) */

#if (IRQ_ADC0_EXIST == STD_ON)
/******************************************************************************
** Syntax :          void ADC0SR2_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC0_SR2_PRIO > 0) || (IRQ_ADC0_SR2_CAT == IRQ_CAT23))
#if((IRQ_ADC0_SR2_PRIO > 0) && (IRQ_ADC0_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC0SR2_ISR,0,IRQ_ADC0_SR2_PRIO)
#elif IRQ_ADC0_SR2_CAT == IRQ_CAT23
ISR(ADC0SR2_ISR)
#endif
{
     
  /* Enable Global Interrupts */
#if (IRQ_ADC0_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/* ADC0 SRN2 is used by Channel Event for Limit check */
/* Call Adc Interrupt function*/
  Adc_IsrSrn2AdcChEvnt(ADC_HWUNIT_ADC0);
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
}
#endif

#endif /* (IRQ_ADC0_EXIST == STD_ON) */

#if (IRQ_ADC1_EXIST == STD_ON)
/******************************************************************************
** Syntax :          void ADC1SR2_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC1_SR2_PRIO > 0) || (IRQ_ADC1_SR2_CAT == IRQ_CAT23))
#if((IRQ_ADC1_SR2_PRIO > 0) && (IRQ_ADC1_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC1SR2_ISR,0,IRQ_ADC1_SR2_PRIO)
#elif IRQ_ADC1_SR2_CAT == IRQ_CAT23
ISR(ADC1SR2_ISR)
#endif
{
     
  /* Enable Global Interrupts */
#if (IRQ_ADC1_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/* ADC1 SRN2 is used by Channel Event for Limit check */
/* Call Adc Interrupt function*/
  Adc_IsrSrn2AdcChEvnt(ADC_HWUNIT_ADC1);
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
}
#endif

#endif /* (IRQ_ADC1_EXIST == STD_ON) */

#if (IRQ_ADC2_EXIST == STD_ON)
/******************************************************************************
** Syntax :          void ADC2SR2_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC2_SR2_PRIO > 0) || (IRQ_ADC2_SR2_CAT == IRQ_CAT23))
#if((IRQ_ADC2_SR2_PRIO > 0) && (IRQ_ADC2_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC2SR2_ISR,0,IRQ_ADC2_SR2_PRIO)
#elif IRQ_ADC2_SR2_CAT == IRQ_CAT23
ISR(ADC2SR2_ISR)
#endif
{
     
  /* Enable Global Interrupts */
#if (IRQ_ADC2_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/* ADC2 SRN2 is used by Channel Event for Limit check */
/* Call Adc Interrupt function*/
  Adc_IsrSrn2AdcChEvnt(ADC_HWUNIT_ADC2);
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
}
#endif

#endif /* (IRQ_ADC2_EXIST == STD_ON) */

#if (IRQ_ADC3_EXIST == STD_ON)
/******************************************************************************
** Syntax :          void ADC3SR2_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC3_SR2_PRIO > 0) || (IRQ_ADC3_SR2_CAT == IRQ_CAT23))
#if((IRQ_ADC3_SR2_PRIO > 0) && (IRQ_ADC3_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC3SR2_ISR,0,IRQ_ADC3_SR2_PRIO)
#elif IRQ_ADC3_SR2_CAT == IRQ_CAT23
ISR(ADC3SR2_ISR)
#endif
{
     
  /* Enable Global Interrupts */
#if (IRQ_ADC3_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/* ADC3 SRN2 is used by Channel Event for Limit check */
/* Call Adc Interrupt function*/
  Adc_IsrSrn2AdcChEvnt(ADC_HWUNIT_ADC3);
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
}
#endif

#endif /* (IRQ_ADC3_EXIST == STD_ON) */

#if (IRQ_ADC4_EXIST == STD_ON)
/******************************************************************************
** Syntax :          void ADC4SR2_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC4_SR2_PRIO > 0) || (IRQ_ADC4_SR2_CAT == IRQ_CAT23))
#if((IRQ_ADC4_SR2_PRIO > 0) && (IRQ_ADC4_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC4SR2_ISR,0,IRQ_ADC4_SR2_PRIO)
#elif IRQ_ADC4_SR2_CAT == IRQ_CAT23
ISR(ADC4SR2_ISR)
#endif
{
     
  /* Enable Global Interrupts */
#if (IRQ_ADC4_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/* ADC4 SRN2 is used by Channel Event for Limit check */
/* Call Adc Interrupt function*/
  Adc_IsrSrn2AdcChEvnt(ADC_HWUNIT_ADC4);
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
}
#endif

#endif /* (IRQ_ADC4_EXIST == STD_ON) */

#if (IRQ_ADC5_EXIST == STD_ON)
/******************************************************************************
** Syntax :          void ADC5SR2_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC5_SR2_PRIO > 0) || (IRQ_ADC5_SR2_CAT == IRQ_CAT23))
#if((IRQ_ADC5_SR2_PRIO > 0) && (IRQ_ADC5_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC5SR2_ISR,0,IRQ_ADC5_SR2_PRIO)
#elif IRQ_ADC5_SR2_CAT == IRQ_CAT23
ISR(ADC5SR2_ISR)
#endif
{
     
  /* Enable Global Interrupts */
#if (IRQ_ADC5_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/* ADC5 SRN2 is used by Channel Event for Limit check */
/* Call Adc Interrupt function*/
  Adc_IsrSrn2AdcChEvnt(ADC_HWUNIT_ADC5);
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
}
#endif

#endif /* (IRQ_ADC5_EXIST == STD_ON) */

#if (IRQ_ADC6_EXIST == STD_ON)
/******************************************************************************
** Syntax :          void ADC6SR2_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC6_SR2_PRIO > 0) || (IRQ_ADC6_SR2_CAT == IRQ_CAT23))
#if((IRQ_ADC6_SR2_PRIO > 0) && (IRQ_ADC6_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC6SR2_ISR,0,IRQ_ADC6_SR2_PRIO)
#elif IRQ_ADC6_SR2_CAT == IRQ_CAT23
ISR(ADC6SR2_ISR)
#endif
{
     
  /* Enable Global Interrupts */
#if (IRQ_ADC6_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/* ADC6 SRN2 is used by Channel Event for Limit check */
/* Call Adc Interrupt function*/
  Adc_IsrSrn2AdcChEvnt(ADC_HWUNIT_ADC6);
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
}
#endif

#endif /* (IRQ_ADC6_EXIST == STD_ON) */

#if (IRQ_ADC7_EXIST == STD_ON)
/******************************************************************************
** Syntax :          void ADC7SR2_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC7_SR2_PRIO > 0) || (IRQ_ADC7_SR2_CAT == IRQ_CAT23))
#if((IRQ_ADC7_SR2_PRIO > 0) && (IRQ_ADC7_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC7SR2_ISR,0,IRQ_ADC7_SR2_PRIO)
#elif IRQ_ADC7_SR2_CAT == IRQ_CAT23
ISR(ADC7SR2_ISR)
#endif
{
     
  /* Enable Global Interrupts */
#if (IRQ_ADC7_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/* ADC7 SRN2 is used by Channel Event for Limit check */
/* Call Adc Interrupt function*/
  Adc_IsrSrn2AdcChEvnt(ADC_HWUNIT_ADC7);
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
}
#endif

#endif /* (IRQ_ADC7_EXIST == STD_ON) */

#if (IRQ_ADC8_EXIST == STD_ON)
/******************************************************************************
** Syntax :          void ADC8SR2_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC8_SR2_PRIO > 0) || (IRQ_ADC8_SR2_CAT == IRQ_CAT23))
#if((IRQ_ADC8_SR2_PRIO > 0) && (IRQ_ADC8_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC8SR2_ISR,0,IRQ_ADC8_SR2_PRIO)
#elif IRQ_ADC8_SR2_CAT == IRQ_CAT23
ISR(ADC8SR2_ISR)
#endif
{
     
  /* Enable Global Interrupts */
#if (IRQ_ADC8_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/* ADC8 SRN2 is used by Channel Event for Limit check */
/* Call Adc Interrupt function*/
  Adc_IsrSrn2AdcChEvnt(ADC_HWUNIT_ADC8);
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
}
#endif

#endif /* (IRQ_ADC8_EXIST == STD_ON) */

#if (IRQ_ADC9_EXIST == STD_ON)
/******************************************************************************
** Syntax :          void ADC9SR2_ISR(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC9_SR2_PRIO > 0) || (IRQ_ADC9_SR2_CAT == IRQ_CAT23))
#if((IRQ_ADC9_SR2_PRIO > 0) && (IRQ_ADC9_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC9SR2_ISR,0,IRQ_ADC9_SR2_PRIO)
#elif IRQ_ADC9_SR2_CAT == IRQ_CAT23
ISR(ADC9SR2_ISR)
#endif
{
     
  /* Enable Global Interrupts */
#if (IRQ_ADC9_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/* ADC9 SRN2 is used by Channel Event for Limit check */
/* Call Adc Interrupt function*/
  Adc_IsrSrn2AdcChEvnt(ADC_HWUNIT_ADC9);
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
}
#endif

#endif /* (IRQ_ADC9_EXIST == STD_ON) */

#if (IRQ_ADC10_EXIST == STD_ON)
/******************************************************************************
** Syntax :          void ADC10SR2_ISR(void)                                 **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       non reentrant                                           **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description :     Service on ADC Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
#if((IRQ_ADC10_SR2_PRIO > 0) || (IRQ_ADC10_SR2_CAT == IRQ_CAT23))
#if((IRQ_ADC10_SR2_PRIO > 0) && (IRQ_ADC10_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(ADC10SR2_ISR,0,IRQ_ADC10_SR2_PRIO)
#elif IRQ_ADC10_SR2_CAT == IRQ_CAT23
ISR(ADC10SR2_ISR)
#endif
{
     
  /* Enable Global Interrupts */
#if (IRQ_ADC10_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/* ADC10 SRN2 is used by Channel Event for Limit check */
/* Call Adc Interrupt function*/
  Adc_IsrSrn2AdcChEvnt(ADC_HWUNIT_ADC10);
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
}
#endif

#endif /* (IRQ_ADC10_EXIST == STD_ON) */

#define IRQ_STOP_SEC_CODE
#include "MemMap.h"


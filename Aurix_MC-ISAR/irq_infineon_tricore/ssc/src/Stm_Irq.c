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
**  $FILENAME   : Stm_Irq.c $                                                **
**                                                                           **
**  $CC VERSION : \main\19 $                                                 **
**                                                                           **
**  $DATE       : 2016-08-10 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains the interrupt frames for the STM Module.**
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
#include "Mcal_Options.h"


#ifdef STM_DEMO_ON
#include "Stm.h"
#else
#include "Test_Time.h"
#endif

/* Inclusion of controller sfr file */
#include "IfxStm_reg.h"
/* Inclusion of controller sfr file */
#include "IfxSrc_reg.h"

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
#if (IFX_MCAL_USED == STD_ON)
#define IRQ_START_SEC_CODE
#include "MemMap.h"
#endif

#define STM_CLEAR_MASK                0xFFFFFFFFU

#if (IRQ_STM0_EXIST == STD_ON)
/******************************************************************************
** Syntax :          void STM0SRN0_ISR(void)                                 **
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
** Description :     Service on STM Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
/* STM SRC0 Interrupt routine */
#if((IRQ_STM0_SR0_PRIO > 0) || (IRQ_STM0_SR0_CAT == IRQ_CAT23))
#if((IRQ_STM0_SR0_PRIO > 0) && (IRQ_STM0_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(STM0SRN0_ISR, 0, IRQ_STM0_SR0_PRIO)
#elif IRQ_STM0_SR0_CAT == IRQ_CAT23
ISR(STM0SRN0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_STM0_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
#ifdef STM_DEMO_ON
  Stm_Isr(0,0);

#else

   /* Reserve bit access is ensured for SRC register at all places accessed*/
   /* Set CLRR bit of SRC_STM0SR0 Reg */
   SRC_STM0SR0.U = ((SRC_STM0SR0.U & SRC_STM0SR0_CLRR_CLEARMASK)| \
                                                   (SRC_STM0SR0_CLRR_SETMASK));

  /* Test for the mode if one shot mode disable the SRN */
  if( ( TestTime_AlarmMode & 0x01U ) == 0 )
  {
    /* Reload the compare register */
    STM0_CMP0.U  = (STM0_CMP0.U & STM0_CMP_CLEARMASK) | \
                           ((Count_Timer[0] + STM0_TIM0.U) & (STM_CLEAR_MASK));
  }
  else
  {
    /* Clear SRE bit of SRC_STM0SR0 Reg */
   SRC_STM0SR0.U = (SRC_STM0SR0.U & SRC_STM0SR0_SRE_CLEARMASK); /*disable intr*/

  }

  /* Call the Function */
  TestTime_ArrayFnp[0]();
 #endif

}
#endif

/******************************************************************************
** Syntax :          void STM0SRN1_ISR(void)                                 **
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
** Description :     Service on STM Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
/* STM SRC1 Interrupt routine */
#if((IRQ_STM0_SR1_PRIO > 0) || (IRQ_STM0_SR1_CAT == IRQ_CAT23))
#if((IRQ_STM0_SR1_PRIO > 0) && (IRQ_STM0_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(STM0SRN1_ISR, 0, IRQ_STM0_SR1_PRIO)
#elif IRQ_STM0_SR1_CAT == IRQ_CAT23
ISR(STM0SRN1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_STM0_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
#ifdef STM_DEMO_ON
  Stm_Isr(0,1);
#else
    /* Set CLRR bit of SRC_STM0SR1 Reg */
    SRC_STM0SR1.U = ((SRC_STM0SR1.U & SRC_STM0SR1_CLRR_CLEARMASK)| \
                                                  (SRC_STM0SR1_CLRR_SETMASK));

  /* Test for the mode if one shot mode disable the SRN */
  if( ( TestTime_AlarmMode & 0x02U ) == 0 )
  {
    /* Reload the compare register */
  STM0_CMP1.U  = (STM0_CMP1.U & STM0_CMP_CLEARMASK) | \
                          ((Count_Timer[0] + STM0_TIM0.U)  & (STM_CLEAR_MASK));

  }
  else
  {
    /* Clear SRE bit of SRC_STM0SR1 Reg */
    SRC_STM0SR1.U = (SRC_STM0SR1.U & SRC_STM0SR1_SRE_CLEARMASK); /*disable intr*/

  }
  /* Call the Function */
  TestTime_ArrayFnp[1]();
#endif
}
#endif

#endif /* (IRQ_STM0_EXIST == STD_ON) */

#if (IRQ_STM1_EXIST == STD_ON)
/******************************************************************************
** Syntax :          void STM1SRN0_ISR(void)                                 **
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
** Description :     Service on STM Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
/* STM SRC0 Interrupt routine */
#if((IRQ_STM1_SR0_PRIO > 0) || (IRQ_STM1_SR0_CAT == IRQ_CAT23))
#if((IRQ_STM1_SR0_PRIO > 0) && (IRQ_STM1_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(STM1SRN0_ISR, 0, IRQ_STM1_SR0_PRIO)
#elif IRQ_STM1_SR0_CAT == IRQ_CAT23
ISR(STM1SRN0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_STM1_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
#ifdef STM_DEMO_ON
  Stm_Isr(1,0);
#endif
}
#endif

/******************************************************************************
** Syntax :          void STM1SRN1_ISR(void)                                 **
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
** Description :     Service on STM Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
/* STM SRC1 Interrupt routine */
#if((IRQ_STM1_SR1_PRIO > 0) || (IRQ_STM1_SR1_CAT == IRQ_CAT23))
#if((IRQ_STM1_SR1_PRIO > 0) && (IRQ_STM1_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(STM1SRN1_ISR, 0, IRQ_STM1_SR1_PRIO)
#elif IRQ_STM1_SR1_CAT == IRQ_CAT23
ISR(STM1SRN1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_STM1_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
#ifdef STM_DEMO_ON
    Stm_Isr(1,1);
#endif
}
#endif

#endif /* (IRQ_STM1_EXIST == STD_ON) */

#if (IRQ_STM2_EXIST == STD_ON)
/******************************************************************************
** Syntax :          void STM2SRN0_ISR(void)                                 **
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
** Description :     Service on STM Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
/* STM SRC0 Interrupt routine */
#if((IRQ_STM2_SR0_PRIO > 0) || (IRQ_STM2_SR0_CAT == IRQ_CAT23))
#if((IRQ_STM2_SR0_PRIO > 0) && (IRQ_STM2_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(STM2SRN0_ISR, 0, IRQ_STM2_SR0_PRIO)
#elif IRQ_STM2_SR0_CAT == IRQ_CAT23
ISR(STM2SRN0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_STM2_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
#ifdef STM_DEMO_ON
  Stm_Isr(2,0);
#endif
}
#endif

/******************************************************************************
** Syntax :          void STM2SRN1_ISR(void)                                 **
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
** Description :     Service on STM Request source conversion complete       **
**                   service request                                         **
**                                                                           **
******************************************************************************/
/* STM SRC1 Interrupt routine */
#if((IRQ_STM2_SR1_PRIO > 0) || (IRQ_STM2_SR1_CAT == IRQ_CAT23))
#if((IRQ_STM2_SR1_PRIO > 0) && (IRQ_STM2_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(STM2SRN1_ISR, 0, IRQ_STM2_SR1_PRIO)
#elif IRQ_STM2_SR1_CAT == IRQ_CAT23
ISR(STM2SRN1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_STM2_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
#ifdef STM_DEMO_ON
  Stm_Isr(2,1);
#endif
}
#endif

#endif /* (IRQ_STM2_EXIST == STD_ON) */

#if (IFX_MCAL_USED == STD_ON)
#define IRQ_STOP_SEC_CODE
#include "MemMap.h"
#endif


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
**  $FILENAME   : Gtm_Irq.c $                                                **
**                                                                           **
**  $CC VERSION : \main\17 $                                                 **
**                                                                           **
**  $DATE       : 2016-06-27 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains the interrupt frames for the GTM. This  **
**                file is given for evaluation purpose only.                 **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Include GTM header file */
#include <Hal_Sensor.h>
#include "Gtm.h"

/*Include Irq Module*/
#include "Irq.h"

#include "Mcal.h"

/*******************************************************************************
**                      Imported Compiler Switch Checks                       **
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
**                      Private Function Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define IRQ_START_SEC_CODE
#include "MemMap.h"

#if (IRQ_GTM_EXIST == (STD_ON))
/******************************************************************************
** Syntax : void GTM_ISR_<MOD>[x]_SRy(void)                                  **
**                                                                           **
** Service ID:       NA                                                      **
**                                                                           **
** Sync/Async:       Synchronous                                             **
**                                                                           **
** Reentrancy:       reentrant                                               **
**                                                                           **
** Parameters (in):  none                                                    **
**                                                                           **
** Parameters (out): none                                                    **
**                                                                           **
** Return value:     none                                                    **
**                                                                           **
** Description : Service for GTM Service request for Sub Modules             **
**                                                                           **
*****************************************************************************/
#if(IRQ_GTM_TOM0_EXIST == (STD_ON))
#if((IRQ_GTM_TOM0_SR0_PRIO > 0) || (IRQ_GTM_TOM0_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM0_SR0_PRIO > 0) && (IRQ_GTM_TOM0_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM0SR0_ISR, 0, IRQ_GTM_TOM0_SR0_PRIO)
#elif IRQ_GTM_TOM0_SR0_CAT == IRQ_CAT23
ISR(GTMTOM0SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM0_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(0, 0);
}
#endif

#if((IRQ_GTM_TOM0_SR1_PRIO > 0) || (IRQ_GTM_TOM0_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM0_SR1_PRIO > 0) && (IRQ_GTM_TOM0_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM0SR1_ISR, 0, IRQ_GTM_TOM0_SR1_PRIO)
#elif IRQ_GTM_TOM0_SR1_CAT == IRQ_CAT23
ISR(GTMTOM0SR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM0_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(0, 2);
}
#endif


#if((IRQ_GTM_TOM0_SR2_PRIO > 0) || (IRQ_GTM_TOM0_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM0_SR2_PRIO > 0) && (IRQ_GTM_TOM0_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM0SR2_ISR, 0, IRQ_GTM_TOM0_SR2_PRIO)
#elif IRQ_GTM_TOM0_SR2_CAT == IRQ_CAT23
ISR(GTMTOM0SR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM0_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(0, 4);
}
#endif

#if((IRQ_GTM_TOM0_SR3_PRIO > 0) || (IRQ_GTM_TOM0_SR3_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM0_SR3_PRIO > 0) && (IRQ_GTM_TOM0_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM0SR3_ISR, 0, IRQ_GTM_TOM0_SR3_PRIO)
#elif IRQ_GTM_TOM0_SR3_CAT == IRQ_CAT23
ISR(GTMTOM0SR3_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM0_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(0, 6);
}
#endif

#if((IRQ_GTM_TOM0_SR4_PRIO > 0) || (IRQ_GTM_TOM0_SR4_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM0_SR4_PRIO > 0) && (IRQ_GTM_TOM0_SR4_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM0SR4_ISR, 0, IRQ_GTM_TOM0_SR4_PRIO)
#elif IRQ_GTM_TOM0_SR4_CAT == IRQ_CAT23
ISR(GTMTOM0SR4_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM0_SR4_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(0, 8);
}
#endif

#if((IRQ_GTM_TOM0_SR5_PRIO > 0) || (IRQ_GTM_TOM0_SR5_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM0_SR5_PRIO > 0) && (IRQ_GTM_TOM0_SR5_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM0SR5_ISR, 0, IRQ_GTM_TOM0_SR5_PRIO)
#elif IRQ_GTM_TOM0_SR5_CAT == IRQ_CAT23
ISR(GTMTOM0SR5_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM0_SR5_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(0, 10);
}
#endif

#if((IRQ_GTM_TOM0_SR6_PRIO > 0) || (IRQ_GTM_TOM0_SR6_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM0_SR6_PRIO > 0) && (IRQ_GTM_TOM0_SR6_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM0SR6_ISR, 0, IRQ_GTM_TOM0_SR6_PRIO)
#elif IRQ_GTM_TOM0_SR6_CAT == IRQ_CAT23
ISR(GTMTOM0SR6_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM0_SR6_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(0, 12);
}
#endif

#if((IRQ_GTM_TOM0_SR7_PRIO > 0) || (IRQ_GTM_TOM0_SR7_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM0_SR7_PRIO > 0) && (IRQ_GTM_TOM0_SR7_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM0SR7_ISR, 0, IRQ_GTM_TOM0_SR7_PRIO)
#elif IRQ_GTM_TOM0_SR7_CAT == IRQ_CAT23
ISR(GTMTOM0SR7_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM0_SR7_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(0, 14);
}
#endif


#endif /* #if(IRQ_GTM_TOM0_EXIST == (STD_ON)) */


#if(IRQ_GTM_TOM1_EXIST == (STD_ON))

#if((IRQ_GTM_TOM1_SR0_PRIO > 0) || (IRQ_GTM_TOM1_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM1_SR0_PRIO > 0) && (IRQ_GTM_TOM1_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM1SR0_ISR, 0, IRQ_GTM_TOM1_SR0_PRIO)
#elif IRQ_GTM_TOM1_SR0_CAT == IRQ_CAT23
ISR(GTMTOM1SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM1_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(1, 0);
}
#endif

#if((IRQ_GTM_TOM1_SR1_PRIO > 0) || (IRQ_GTM_TOM1_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM1_SR1_PRIO > 0) && (IRQ_GTM_TOM1_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM1SR1_ISR, 0, IRQ_GTM_TOM1_SR1_PRIO)
#elif IRQ_GTM_TOM1_SR1_CAT == IRQ_CAT23
ISR(GTMTOM1SR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM1_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(1, 2);
}
#endif


#if((IRQ_GTM_TOM1_SR2_PRIO > 0) || (IRQ_GTM_TOM1_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM1_SR2_PRIO > 0) && (IRQ_GTM_TOM1_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM1SR2_ISR, 0, IRQ_GTM_TOM1_SR2_PRIO)
#elif IRQ_GTM_TOM1_SR2_CAT == IRQ_CAT23
ISR(GTMTOM1SR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM1_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(1, 4);
}
#endif

#if((IRQ_GTM_TOM1_SR3_PRIO > 0) || (IRQ_GTM_TOM1_SR3_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM1_SR3_PRIO > 0) && (IRQ_GTM_TOM1_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM1SR3_ISR, 0, IRQ_GTM_TOM1_SR3_PRIO)
#elif IRQ_GTM_TOM1_SR3_CAT == IRQ_CAT23
ISR(GTMTOM1SR3_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM1_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(1, 6);
}
#endif

#if((IRQ_GTM_TOM1_SR4_PRIO > 0) || (IRQ_GTM_TOM1_SR4_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM1_SR4_PRIO > 0) && (IRQ_GTM_TOM1_SR4_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM1SR4_ISR, 0, IRQ_GTM_TOM1_SR4_PRIO)
#elif IRQ_GTM_TOM1_SR4_CAT == IRQ_CAT23
ISR(GTMTOM1SR4_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM1_SR4_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(1, 8);
}
#endif

#if((IRQ_GTM_TOM1_SR5_PRIO > 0) || (IRQ_GTM_TOM1_SR5_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM1_SR5_PRIO > 0) && (IRQ_GTM_TOM1_SR5_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM1SR5_ISR, 0, IRQ_GTM_TOM1_SR5_PRIO)
#elif IRQ_GTM_TOM1_SR5_CAT == IRQ_CAT23
ISR(GTMTOM1SR5_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM1_SR5_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(1, 10);
}
#endif

#if((IRQ_GTM_TOM1_SR6_PRIO > 0) || (IRQ_GTM_TOM1_SR6_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM1_SR6_PRIO > 0) && (IRQ_GTM_TOM1_SR6_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM1SR6_ISR, 0, IRQ_GTM_TOM1_SR6_PRIO)
#elif IRQ_GTM_TOM1_SR6_CAT == IRQ_CAT23
ISR(GTMTOM1SR6_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM1_SR6_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(1, 12);
}
#endif

#if((IRQ_GTM_TOM1_SR7_PRIO > 0) || (IRQ_GTM_TOM1_SR7_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM1_SR7_PRIO > 0) && (IRQ_GTM_TOM1_SR7_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM1SR7_ISR, 0, IRQ_GTM_TOM1_SR7_PRIO)
#elif IRQ_GTM_TOM1_SR7_CAT == IRQ_CAT23
ISR(GTMTOM1SR7_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM1_SR7_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(1, 14);
}
#endif

#endif /* #if(IRQ_GTM_TOM1_EXIST == (STD_ON)) */

#if(IRQ_GTM_TOM2_EXIST == (STD_ON))

#if((IRQ_GTM_TOM2_SR0_PRIO > 0) || (IRQ_GTM_TOM2_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM2_SR0_PRIO > 0) && (IRQ_GTM_TOM2_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM2SR0_ISR, 0, IRQ_GTM_TOM2_SR0_PRIO)
#elif IRQ_GTM_TOM2_SR0_CAT == IRQ_CAT23
ISR(GTMTOM2SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM2_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(2, 0);
}
#endif

#if((IRQ_GTM_TOM2_SR1_PRIO > 0) || (IRQ_GTM_TOM2_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM2_SR1_PRIO > 0) && (IRQ_GTM_TOM2_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM2SR1_ISR, 0, IRQ_GTM_TOM2_SR1_PRIO)
#elif IRQ_GTM_TOM2_SR1_CAT == IRQ_CAT23
ISR(GTMTOM2SR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM2_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(2, 2);
}
#endif

#if((IRQ_GTM_TOM2_SR2_PRIO > 0) || (IRQ_GTM_TOM2_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM2_SR2_PRIO > 0) && (IRQ_GTM_TOM2_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM2SR2_ISR, 0, IRQ_GTM_TOM2_SR2_PRIO)
#elif IRQ_GTM_TOM2_SR2_CAT == IRQ_CAT23
ISR(GTMTOM2SR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM2_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(2, 4);
}
#endif

#if((IRQ_GTM_TOM2_SR3_PRIO > 0) || (IRQ_GTM_TOM2_SR3_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM2_SR3_PRIO > 0) && (IRQ_GTM_TOM2_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM2SR3_ISR, 0, IRQ_GTM_TOM2_SR3_PRIO)
#elif IRQ_GTM_TOM2_SR3_CAT == IRQ_CAT23
ISR(GTMTOM2SR3_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM2_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(2, 6);
}
#endif

#if((IRQ_GTM_TOM2_SR4_PRIO > 0) || (IRQ_GTM_TOM2_SR4_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM2_SR4_PRIO > 0) && (IRQ_GTM_TOM2_SR4_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM2SR4_ISR, 0, IRQ_GTM_TOM2_SR4_PRIO)
#elif IRQ_GTM_TOM2_SR4_CAT == IRQ_CAT23
ISR(GTMTOM2SR4_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM2_SR4_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(2, 8);
}
#endif

#if((IRQ_GTM_TOM2_SR5_PRIO > 0) || (IRQ_GTM_TOM2_SR5_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM2_SR5_PRIO > 0) && (IRQ_GTM_TOM2_SR5_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM2SR5_ISR, 0, IRQ_GTM_TOM2_SR5_PRIO)
#elif IRQ_GTM_TOM2_SR5_CAT == IRQ_CAT23
ISR(GTMTOM2SR5_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM2_SR5_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(2, 10);
}
#endif

#if((IRQ_GTM_TOM2_SR6_PRIO > 0) || (IRQ_GTM_TOM2_SR6_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM2_SR6_PRIO > 0) && (IRQ_GTM_TOM2_SR6_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM2SR6_ISR, 0, IRQ_GTM_TOM2_SR6_PRIO)
#elif IRQ_GTM_TOM2_SR6_CAT == IRQ_CAT23
ISR(GTMTOM2SR6_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM2_SR6_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(2, 12);
}
#endif

#if((IRQ_GTM_TOM2_SR7_PRIO > 0) || (IRQ_GTM_TOM2_SR7_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM2_SR7_PRIO > 0) && (IRQ_GTM_TOM2_SR7_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM2SR7_ISR, 0, IRQ_GTM_TOM2_SR7_PRIO)
#elif IRQ_GTM_TOM2_SR7_CAT == IRQ_CAT23
ISR(GTMTOM2SR7_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM2_SR7_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(2, 14);
}
#endif

#endif /* #if(IRQ_GTM_TOM2_EXIST == (STD_ON)) */



#if(IRQ_GTM_TOM3_EXIST == (STD_ON))

#if((IRQ_GTM_TOM3_SR0_PRIO > 0) || (IRQ_GTM_TOM3_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM3_SR0_PRIO > 0) && (IRQ_GTM_TOM3_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM3SR0_ISR, 0, IRQ_GTM_TOM3_SR0_PRIO)
#elif IRQ_GTM_TOM3_SR0_CAT == IRQ_CAT23
ISR(GTMTOM3SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM3_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(3, 0);
}
#endif

#if((IRQ_GTM_TOM3_SR1_PRIO > 0) || (IRQ_GTM_TOM3_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM3_SR1_PRIO > 0) && (IRQ_GTM_TOM3_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM3SR1_ISR, 0, IRQ_GTM_TOM3_SR1_PRIO)
#elif IRQ_GTM_TOM3_SR1_CAT == IRQ_CAT23
ISR(GTMTOM3SR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM3_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(3, 2);
}
#endif

#if((IRQ_GTM_TOM3_SR2_PRIO > 0) || (IRQ_GTM_TOM3_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM3_SR2_PRIO > 0) && (IRQ_GTM_TOM3_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM3SR2_ISR, 0, IRQ_GTM_TOM3_SR2_PRIO)
#elif IRQ_GTM_TOM3_SR2_CAT == IRQ_CAT23
ISR(GTMTOM3SR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM3_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(3, 4);
}
#endif

#if((IRQ_GTM_TOM3_SR3_PRIO > 0) || (IRQ_GTM_TOM3_SR3_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM3_SR3_PRIO > 0) && (IRQ_GTM_TOM3_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM3SR3_ISR, 0, IRQ_GTM_TOM3_SR3_PRIO)
#elif IRQ_GTM_TOM3_SR3_CAT == IRQ_CAT23
ISR(GTMTOM3SR3_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM3_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(3, 6);
}
#endif

#if((IRQ_GTM_TOM3_SR4_PRIO > 0) || (IRQ_GTM_TOM3_SR4_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM3_SR4_PRIO > 0) && (IRQ_GTM_TOM3_SR4_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM3SR4_ISR, 0, IRQ_GTM_TOM3_SR4_PRIO)
#elif IRQ_GTM_TOM3_SR4_CAT == IRQ_CAT23
ISR(GTMTOM3SR4_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM3_SR4_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(3, 8);
}
#endif

#if((IRQ_GTM_TOM3_SR5_PRIO > 0) || (IRQ_GTM_TOM3_SR5_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM3_SR5_PRIO > 0) && (IRQ_GTM_TOM3_SR5_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM3SR5_ISR, 0, IRQ_GTM_TOM3_SR5_PRIO)
#elif IRQ_GTM_TOM3_SR5_CAT == IRQ_CAT23
ISR(GTMTOM3SR5_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM3_SR5_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(3, 10);
}
#endif

#if((IRQ_GTM_TOM3_SR6_PRIO > 0) || (IRQ_GTM_TOM3_SR6_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM3_SR6_PRIO > 0) && (IRQ_GTM_TOM3_SR6_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM3SR6_ISR, 0, IRQ_GTM_TOM3_SR6_PRIO)
#elif IRQ_GTM_TOM3_SR6_CAT == IRQ_CAT23
ISR(GTMTOM3SR6_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM3_SR6_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(3, 12);
}
#endif

#if((IRQ_GTM_TOM3_SR7_PRIO > 0) || (IRQ_GTM_TOM3_SR7_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM3_SR7_PRIO > 0) && (IRQ_GTM_TOM3_SR7_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM3SR7_ISR, 0, IRQ_GTM_TOM3_SR7_PRIO)
#elif IRQ_GTM_TOM3_SR7_CAT == IRQ_CAT23
ISR(GTMTOM3SR7_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM3_SR7_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(3, 14);
}
#endif

#endif /* #if(IRQ_GTM_TOM3_EXIST == (STD_ON)) */



#if(IRQ_GTM_TOM4_EXIST == (STD_ON))

#if((IRQ_GTM_TOM4_SR0_PRIO > 0) || (IRQ_GTM_TOM4_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM4_SR0_PRIO > 0) && (IRQ_GTM_TOM4_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM4SR0_ISR, 0, IRQ_GTM_TOM4_SR0_PRIO)
#elif IRQ_GTM_TOM4_SR0_CAT == IRQ_CAT23
ISR(GTMTOM4SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM4_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(4, 0);
}
#endif

#if((IRQ_GTM_TOM4_SR1_PRIO > 0) || (IRQ_GTM_TOM4_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM4_SR1_PRIO > 0) && (IRQ_GTM_TOM4_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM4SR1_ISR, 0, IRQ_GTM_TOM4_SR1_PRIO)
#elif IRQ_GTM_TOM4_SR1_CAT == IRQ_CAT23
ISR(GTMTOM4SR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM4_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(4, 2);
}
#endif

#if((IRQ_GTM_TOM4_SR2_PRIO > 0) || (IRQ_GTM_TOM4_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM4_SR2_PRIO > 0) && (IRQ_GTM_TOM4_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM4SR2_ISR, 0, IRQ_GTM_TOM4_SR2_PRIO)
#elif IRQ_GTM_TOM4_SR2_CAT == IRQ_CAT23
ISR(GTMTOM4SR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM4_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(4, 4);
}
#endif

#if((IRQ_GTM_TOM4_SR3_PRIO > 0) || (IRQ_GTM_TOM4_SR3_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM4_SR3_PRIO > 0) && (IRQ_GTM_TOM4_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM4SR3_ISR, 0, IRQ_GTM_TOM4_SR3_PRIO)
#elif IRQ_GTM_TOM4_SR3_CAT == IRQ_CAT23
ISR(GTMTOM4SR3_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM4_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(4, 6);
}
#endif

#if((IRQ_GTM_TOM4_SR4_PRIO > 0) || (IRQ_GTM_TOM4_SR4_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM4_SR4_PRIO > 0) && (IRQ_GTM_TOM4_SR4_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM4SR4_ISR, 0, IRQ_GTM_TOM4_SR4_PRIO)
#elif IRQ_GTM_TOM4_SR4_CAT == IRQ_CAT23
ISR(GTMTOM4SR4_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM4_SR4_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(4, 8);
}
#endif

#if((IRQ_GTM_TOM4_SR5_PRIO > 0) || (IRQ_GTM_TOM4_SR5_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM4_SR5_PRIO > 0) && (IRQ_GTM_TOM4_SR5_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM4SR5_ISR, 0, IRQ_GTM_TOM4_SR5_PRIO)
#elif IRQ_GTM_TOM4_SR5_CAT == IRQ_CAT23
ISR(GTMTOM4SR5_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM4_SR5_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(4, 10);
}
#endif

#if((IRQ_GTM_TOM4_SR6_PRIO > 0) || (IRQ_GTM_TOM4_SR6_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM4_SR6_PRIO > 0) && (IRQ_GTM_TOM4_SR6_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM4SR6_ISR, 0, IRQ_GTM_TOM4_SR6_PRIO)
#elif IRQ_GTM_TOM4_SR6_CAT == IRQ_CAT23
ISR(GTMTOM4SR6_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM4_SR6_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(4, 12);
}
#endif

#if((IRQ_GTM_TOM4_SR7_PRIO > 0) || (IRQ_GTM_TOM4_SR7_CAT == IRQ_CAT23))
#if((IRQ_GTM_TOM4_SR7_PRIO > 0) && (IRQ_GTM_TOM4_SR7_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTOM4SR7_ISR, 0, IRQ_GTM_TOM4_SR7_PRIO)
#elif IRQ_GTM_TOM4_SR7_CAT == IRQ_CAT23
ISR(GTMTOM4SR7_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TOM4_SR7_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTomModule(4, 14);
}
#endif

#endif /* #if(IRQ_GTM_TOM4_EXIST == (STD_ON)) */





#if(IRQ_GTM_ATOM0_EXIST == (STD_ON))

#if((IRQ_GTM_ATOM0_SR0_PRIO > 0) || (IRQ_GTM_ATOM0_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM0_SR0_PRIO > 0) && (IRQ_GTM_ATOM0_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM0SR0_ISR, 0, IRQ_GTM_ATOM0_SR0_PRIO)
#elif IRQ_GTM_ATOM0_SR0_CAT == IRQ_CAT23
ISR(GTMATOM0SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM0_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(0, 0);
}
#endif

#if((IRQ_GTM_ATOM0_SR1_PRIO > 0) || (IRQ_GTM_ATOM0_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM0_SR1_PRIO > 0) && (IRQ_GTM_ATOM0_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM0SR1_ISR, 0, IRQ_GTM_ATOM0_SR1_PRIO)
#elif IRQ_GTM_ATOM0_SR1_CAT == IRQ_CAT23
ISR(GTMATOM0SR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM0_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(0, 2);
}
#endif

#if((IRQ_GTM_ATOM0_SR2_PRIO > 0) || (IRQ_GTM_ATOM0_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM0_SR2_PRIO > 0) && (IRQ_GTM_ATOM0_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM0SR2_ISR, 0, IRQ_GTM_ATOM0_SR2_PRIO)
#elif IRQ_GTM_ATOM0_SR2_CAT == IRQ_CAT23
ISR(GTMATOM0SR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM0_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(0, 4);
}
#endif

#if((IRQ_GTM_ATOM0_SR3_PRIO > 0) || (IRQ_GTM_ATOM0_SR3_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM0_SR3_PRIO > 0) && (IRQ_GTM_ATOM0_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM0SR3_ISR, 0, IRQ_GTM_ATOM0_SR3_PRIO)
#elif IRQ_GTM_ATOM0_SR3_CAT == IRQ_CAT23
ISR(GTMATOM0SR3_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM0_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(0, 6);
}
#endif


#endif /* #if(IRQ_GTM_ATOM0_EXIST == (STD_ON)) */

#if(IRQ_GTM_ATOM1_EXIST == (STD_ON))

#if((IRQ_GTM_ATOM1_SR0_PRIO > 0) || (IRQ_GTM_ATOM1_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM1_SR0_PRIO > 0) && (IRQ_GTM_ATOM1_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM1SR0_ISR, 0, IRQ_GTM_ATOM1_SR0_PRIO)
#elif IRQ_GTM_ATOM1_SR0_CAT == IRQ_CAT23
ISR(GTMATOM1SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM1_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(1, 0);
}
#endif

#if((IRQ_GTM_ATOM1_SR1_PRIO > 0) || (IRQ_GTM_ATOM1_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM1_SR1_PRIO > 0) && (IRQ_GTM_ATOM1_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM1SR1_ISR, 0, IRQ_GTM_ATOM1_SR1_PRIO)
#elif IRQ_GTM_ATOM1_SR1_CAT == IRQ_CAT23
ISR(GTMATOM1SR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM1_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(1, 2);
}
#endif

#if((IRQ_GTM_ATOM1_SR2_PRIO > 0) || (IRQ_GTM_ATOM1_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM1_SR2_PRIO > 0) && (IRQ_GTM_ATOM1_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM1SR2_ISR, 0, IRQ_GTM_ATOM1_SR2_PRIO)
#elif IRQ_GTM_ATOM1_SR2_CAT == IRQ_CAT23
ISR(GTMATOM1SR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM1_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(1, 4);
}
#endif

#if((IRQ_GTM_ATOM1_SR3_PRIO > 0) || (IRQ_GTM_ATOM1_SR3_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM1_SR3_PRIO > 0) && (IRQ_GTM_ATOM1_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM1SR3_ISR, 0, IRQ_GTM_ATOM1_SR3_PRIO)
#elif IRQ_GTM_ATOM1_SR3_CAT == IRQ_CAT23
ISR(GTMATOM1SR3_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM1_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(1, 6);
}
#endif

#endif /* #if(IRQ_GTM_ATOM1_EXIST == (STD_ON)) */
#if(IRQ_GTM_ATOM2_EXIST == (STD_ON))


#if((IRQ_GTM_ATOM2_SR0_PRIO > 0) || (IRQ_GTM_ATOM2_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM2_SR0_PRIO > 0) && (IRQ_GTM_ATOM2_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM2SR0_ISR, 0, IRQ_GTM_ATOM2_SR0_PRIO)
#elif IRQ_GTM_ATOM2_SR0_CAT == IRQ_CAT23
ISR(GTMATOM2SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM2_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(2, 0);
}
#endif

#if((IRQ_GTM_ATOM2_SR1_PRIO > 0) || (IRQ_GTM_ATOM2_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM2_SR1_PRIO > 0) && (IRQ_GTM_ATOM2_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM2SR1_ISR, 0, IRQ_GTM_ATOM2_SR1_PRIO)
#elif IRQ_GTM_ATOM2_SR1_CAT == IRQ_CAT23
ISR(GTMATOM2SR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM2_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(2, 2);
}
#endif

#if((IRQ_GTM_ATOM2_SR2_PRIO > 0) || (IRQ_GTM_ATOM2_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM2_SR2_PRIO > 0) && (IRQ_GTM_ATOM2_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM2SR2_ISR, 0, IRQ_GTM_ATOM2_SR2_PRIO)
#elif IRQ_GTM_ATOM2_SR2_CAT == IRQ_CAT23
ISR(GTMATOM2SR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM2_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(2, 4);
}
#endif

#if((IRQ_GTM_ATOM2_SR3_PRIO > 0) || (IRQ_GTM_ATOM2_SR3_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM2_SR3_PRIO > 0) && (IRQ_GTM_ATOM2_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM2SR3_ISR, 0, IRQ_GTM_ATOM2_SR3_PRIO)
#elif IRQ_GTM_ATOM2_SR3_CAT == IRQ_CAT23
ISR(GTMATOM2SR3_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM2_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(2, 6);
}
#endif

#endif /* #if(IRQ_GTM_ATOM2_EXIST == (STD_ON)) */

#if(IRQ_GTM_ATOM3_EXIST == (STD_ON))

#if((IRQ_GTM_ATOM3_SR0_PRIO > 0) || (IRQ_GTM_ATOM3_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM3_SR0_PRIO > 0) && (IRQ_GTM_ATOM3_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM3SR0_ISR, 0, IRQ_GTM_ATOM3_SR0_PRIO)
#elif IRQ_GTM_ATOM3_SR0_CAT == IRQ_CAT23
ISR(GTMATOM3SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM3_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(3, 0);
}
#endif

#if((IRQ_GTM_ATOM3_SR1_PRIO > 0) || (IRQ_GTM_ATOM3_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM3_SR1_PRIO > 0) && (IRQ_GTM_ATOM3_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM3SR1_ISR, 0, IRQ_GTM_ATOM3_SR1_PRIO)
#elif IRQ_GTM_ATOM3_SR1_CAT == IRQ_CAT23
ISR(GTMATOM3SR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM3_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(3, 2);
}
#endif

#if((IRQ_GTM_ATOM3_SR2_PRIO > 0) || (IRQ_GTM_ATOM3_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM3_SR2_PRIO > 0) && (IRQ_GTM_ATOM3_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM3SR2_ISR, 0, IRQ_GTM_ATOM3_SR2_PRIO)
#elif IRQ_GTM_ATOM3_SR2_CAT == IRQ_CAT23
ISR(GTMATOM3SR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM3_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(3, 4);
}
#endif

#if((IRQ_GTM_ATOM3_SR3_PRIO > 0) || (IRQ_GTM_ATOM3_SR3_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM3_SR3_PRIO > 0) && (IRQ_GTM_ATOM3_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM3SR3_ISR, 0, IRQ_GTM_ATOM3_SR3_PRIO)
#elif IRQ_GTM_ATOM3_SR3_CAT == IRQ_CAT23
ISR(GTMATOM3SR3_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM3_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(3, 6);
}
#endif

#endif /* #if(IRQ_GTM_ATOM3_EXIST == (STD_ON)) */

#if(IRQ_GTM_ATOM4_EXIST == (STD_ON))

#if((IRQ_GTM_ATOM4_SR0_PRIO > 0) || (IRQ_GTM_ATOM4_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM4_SR0_PRIO > 0) && (IRQ_GTM_ATOM4_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM4SR0_ISR, 0, IRQ_GTM_ATOM4_SR0_PRIO)
#elif IRQ_GTM_ATOM4_SR0_CAT == IRQ_CAT23
ISR(GTMATOM4SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM4_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(4, 0);
}
#endif

#if((IRQ_GTM_ATOM4_SR1_PRIO > 0) || (IRQ_GTM_ATOM4_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM4_SR1_PRIO > 0) && (IRQ_GTM_ATOM4_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM4SR1_ISR, 0, IRQ_GTM_ATOM4_SR1_PRIO)
#elif IRQ_GTM_ATOM4_SR1_CAT == IRQ_CAT23
ISR(GTMATOM4SR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM4_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(4, 2);
}
#endif

#if((IRQ_GTM_ATOM4_SR2_PRIO > 0) || (IRQ_GTM_ATOM4_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM4_SR2_PRIO > 0) && (IRQ_GTM_ATOM4_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM4SR2_ISR, 0, IRQ_GTM_ATOM4_SR2_PRIO)
#elif IRQ_GTM_ATOM4_SR2_CAT == IRQ_CAT23
ISR(GTMATOM4SR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM4_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(4, 4);
}
#endif

#if((IRQ_GTM_ATOM4_SR3_PRIO > 0) || (IRQ_GTM_ATOM4_SR3_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM4_SR3_PRIO > 0) && (IRQ_GTM_ATOM4_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM4SR3_ISR, 0, IRQ_GTM_ATOM4_SR3_PRIO)
#elif IRQ_GTM_ATOM4_SR3_CAT == IRQ_CAT23
ISR(GTMATOM4SR3_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM4_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(4, 6);
}
#endif

#endif /* #if(IRQ_GTM_ATOM4_EXIST == (STD_ON)) */



#if(IRQ_GTM_ATOM5_EXIST == (STD_ON))

#if((IRQ_GTM_ATOM5_SR0_PRIO > 0) || (IRQ_GTM_ATOM5_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM5_SR0_PRIO > 0) && (IRQ_GTM_ATOM5_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM5SR0_ISR, 0, IRQ_GTM_ATOM5_SR0_PRIO)
#elif IRQ_GTM_ATOM5_SR0_CAT == IRQ_CAT23
ISR(GTMATOM5SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM5_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(5, 0);
}
#endif

#if((IRQ_GTM_ATOM5_SR1_PRIO > 0) || (IRQ_GTM_ATOM5_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM5_SR1_PRIO > 0) && (IRQ_GTM_ATOM5_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM5SR1_ISR, 0, IRQ_GTM_ATOM5_SR1_PRIO)
#elif IRQ_GTM_ATOM5_SR1_CAT == IRQ_CAT23
ISR(GTMATOM5SR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM5_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(5, 2);
}
#endif

#if((IRQ_GTM_ATOM5_SR2_PRIO > 0) || (IRQ_GTM_ATOM5_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM5_SR2_PRIO > 0) && (IRQ_GTM_ATOM5_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM5SR2_ISR, 0, IRQ_GTM_ATOM5_SR2_PRIO)
#elif IRQ_GTM_ATOM5_SR2_CAT == IRQ_CAT23
ISR(GTMATOM5SR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM5_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(5, 4);
}
#endif

#if((IRQ_GTM_ATOM5_SR3_PRIO > 0) || (IRQ_GTM_ATOM5_SR3_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM5_SR3_PRIO > 0) && (IRQ_GTM_ATOM5_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM5SR3_ISR, 0, IRQ_GTM_ATOM5_SR3_PRIO)
#elif IRQ_GTM_ATOM5_SR3_CAT == IRQ_CAT23
ISR(GTMATOM5SR3_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM5_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(5, 6);
}
#endif

#endif /* #if(IRQ_GTM_ATOM5_EXIST == (STD_ON)) */


#if(IRQ_GTM_ATOM6_EXIST == (STD_ON))

#if((IRQ_GTM_ATOM6_SR0_PRIO > 0) || (IRQ_GTM_ATOM6_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM6_SR0_PRIO > 0) && (IRQ_GTM_ATOM6_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM6SR0_ISR, 0, IRQ_GTM_ATOM6_SR0_PRIO)
#elif IRQ_GTM_ATOM6_SR0_CAT == IRQ_CAT23
ISR(GTMATOM6SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM6_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(6, 0);
}
#endif

#if((IRQ_GTM_ATOM6_SR1_PRIO > 0) || (IRQ_GTM_ATOM6_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM6_SR1_PRIO > 0) && (IRQ_GTM_ATOM6_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM6SR1_ISR, 0, IRQ_GTM_ATOM6_SR1_PRIO)
#elif IRQ_GTM_ATOM6_SR1_CAT == IRQ_CAT23
ISR(GTMATOM6SR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM6_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(6, 2);
}
#endif

#if((IRQ_GTM_ATOM6_SR2_PRIO > 0) || (IRQ_GTM_ATOM6_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM6_SR2_PRIO > 0) && (IRQ_GTM_ATOM6_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM6SR2_ISR, 0, IRQ_GTM_ATOM6_SR2_PRIO)
#elif IRQ_GTM_ATOM6_SR2_CAT == IRQ_CAT23
ISR(GTMATOM6SR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM6_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(6, 4);
}
#endif

#if((IRQ_GTM_ATOM6_SR3_PRIO > 0) || (IRQ_GTM_ATOM6_SR3_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM6_SR3_PRIO > 0) && (IRQ_GTM_ATOM6_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM6SR3_ISR, 0, IRQ_GTM_ATOM6_SR3_PRIO)
#elif IRQ_GTM_ATOM6_SR3_CAT == IRQ_CAT23
ISR(GTMATOM6SR3_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM6_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(6, 6);
}
#endif

#endif /* #if(IRQ_GTM_ATOM6_EXIST == (STD_ON)) */


#if(IRQ_GTM_ATOM7_EXIST == (STD_ON))

#if((IRQ_GTM_ATOM7_SR0_PRIO > 0) || (IRQ_GTM_ATOM7_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM7_SR0_PRIO > 0) && (IRQ_GTM_ATOM7_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM7SR0_ISR, 0, IRQ_GTM_ATOM7_SR0_PRIO)
#elif IRQ_GTM_ATOM7_SR0_CAT == IRQ_CAT23
ISR(GTMATOM7SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM7_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(7, 0);
}
#endif

#if((IRQ_GTM_ATOM7_SR1_PRIO > 0) || (IRQ_GTM_ATOM7_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM7_SR1_PRIO > 0) && (IRQ_GTM_ATOM7_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM7SR1_ISR, 0, IRQ_GTM_ATOM7_SR1_PRIO)
#elif IRQ_GTM_ATOM7_SR1_CAT == IRQ_CAT23
ISR(GTMATOM7SR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM7_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(7, 2);
}
#endif

#if((IRQ_GTM_ATOM7_SR2_PRIO > 0) || (IRQ_GTM_ATOM7_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM7_SR2_PRIO > 0) && (IRQ_GTM_ATOM7_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM7SR2_ISR, 0, IRQ_GTM_ATOM7_SR2_PRIO)
#elif IRQ_GTM_ATOM7_SR2_CAT == IRQ_CAT23
ISR(GTMATOM7SR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM7_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(7, 4);
}
#endif

#if((IRQ_GTM_ATOM7_SR3_PRIO > 0) || (IRQ_GTM_ATOM7_SR3_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM7_SR3_PRIO > 0) && (IRQ_GTM_ATOM7_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM7SR3_ISR, 0, IRQ_GTM_ATOM7_SR3_PRIO)
#elif IRQ_GTM_ATOM7_SR3_CAT == IRQ_CAT23
ISR(GTMATOM7SR3_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM7_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(7, 6);
}
#endif

#endif /* #if(IRQ_GTM_ATOM7_EXIST == (STD_ON)) */



#if(IRQ_GTM_ATOM8_EXIST == (STD_ON))

#if((IRQ_GTM_ATOM8_SR0_PRIO > 0) || (IRQ_GTM_ATOM8_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM8_SR0_PRIO > 0) && (IRQ_GTM_ATOM8_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM8SR0_ISR, 0, IRQ_GTM_ATOM8_SR0_PRIO)
#elif IRQ_GTM_ATOM8_SR0_CAT == IRQ_CAT23
ISR(GTMATOM8SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM8_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(8, 0);
}
#endif

#if((IRQ_GTM_ATOM8_SR1_PRIO > 0) || (IRQ_GTM_ATOM8_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM8_SR1_PRIO > 0) && (IRQ_GTM_ATOM8_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM8SR1_ISR, 0, IRQ_GTM_ATOM8_SR1_PRIO)
#elif IRQ_GTM_ATOM8_SR1_CAT == IRQ_CAT23
ISR(GTMATOM8SR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM8_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(8, 2);
}
#endif

#if((IRQ_GTM_ATOM8_SR2_PRIO > 0) || (IRQ_GTM_ATOM8_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM8_SR2_PRIO > 0) && (IRQ_GTM_ATOM8_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM8SR2_ISR, 0, IRQ_GTM_ATOM8_SR2_PRIO)
#elif IRQ_GTM_ATOM8_SR2_CAT == IRQ_CAT23
ISR(GTMATOM8SR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM8_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(8, 4);
}
#endif

#if((IRQ_GTM_ATOM8_SR3_PRIO > 0) || (IRQ_GTM_ATOM8_SR3_CAT == IRQ_CAT23))
#if((IRQ_GTM_ATOM8_SR3_PRIO > 0) && (IRQ_GTM_ATOM8_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMATOM8SR3_ISR, 0, IRQ_GTM_ATOM8_SR3_PRIO)
#elif IRQ_GTM_ATOM8_SR3_CAT == IRQ_CAT23
ISR(GTMATOM8SR3_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ATOM8_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrAtomModule(8, 6);
}
#endif

#endif /* #if(IRQ_GTM_ATOM8_EXIST == (STD_ON)) */



#if(IRQ_GTM_TIM0_EXIST == (STD_ON))
/******************** TIM 0 *************************************/
#if((IRQ_GTM_TIM0_SR0_PRIO > 0) || (IRQ_GTM_TIM0_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM0_SR0_PRIO > 0) && (IRQ_GTM_TIM0_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM0SR0_ISR, 0, IRQ_GTM_TIM0_SR0_PRIO)
#elif IRQ_GTM_TIM0_SR0_CAT == IRQ_CAT23
ISR(GTMTIM0SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM0_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(0, 0);
}
#endif

#if((IRQ_GTM_TIM0_SR1_PRIO > 0) || (IRQ_GTM_TIM0_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM0_SR1_PRIO > 0) && (IRQ_GTM_TIM0_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM0SR1_ISR, 0, IRQ_GTM_TIM0_SR1_PRIO)
#elif IRQ_GTM_TIM0_SR1_CAT == IRQ_CAT23
ISR(GTMTIM0SR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM0_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(0, 1);
}
#endif

#if((IRQ_GTM_TIM0_SR2_PRIO > 0) || (IRQ_GTM_TIM0_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM0_SR2_PRIO > 0) && (IRQ_GTM_TIM0_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM0SR2_ISR, 0, IRQ_GTM_TIM0_SR2_PRIO)
#elif IRQ_GTM_TIM0_SR2_CAT == IRQ_CAT23
ISR(GTMTIM0SR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM0_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(0, 2);
}
#endif

#if((IRQ_GTM_TIM0_SR3_PRIO > 0) || (IRQ_GTM_TIM0_SR3_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM0_SR3_PRIO > 0) && (IRQ_GTM_TIM0_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM0SR3_ISR, 0, IRQ_GTM_TIM0_SR3_PRIO)
#elif IRQ_GTM_TIM0_SR3_CAT == IRQ_CAT23
ISR(GTMTIM0SR3_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM0_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(0, 3);
}
#endif

#if((IRQ_GTM_TIM0_SR4_PRIO > 0) || (IRQ_GTM_TIM0_SR4_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM0_SR4_PRIO > 0) && (IRQ_GTM_TIM0_SR4_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM0SR4_ISR, 0, IRQ_GTM_TIM0_SR4_PRIO)
#elif IRQ_GTM_TIM0_SR4_CAT == IRQ_CAT23
ISR(GTMTIM0SR4_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM0_SR4_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(0, 4);
}
#endif

#if((IRQ_GTM_TIM0_SR5_PRIO > 0) || (IRQ_GTM_TIM0_SR5_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM0_SR5_PRIO > 0) && (IRQ_GTM_TIM0_SR5_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM0SR5_ISR, 0, IRQ_GTM_TIM0_SR5_PRIO)
#elif IRQ_GTM_TIM0_SR5_CAT == IRQ_CAT23
ISR(GTMTIM0SR5_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM0_SR5_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(0, 5);
}
#endif

#if((IRQ_GTM_TIM0_SR6_PRIO > 0) || (IRQ_GTM_TIM0_SR6_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM0_SR6_PRIO > 0) && (IRQ_GTM_TIM0_SR6_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM0SR6_ISR, 0, IRQ_GTM_TIM0_SR6_PRIO)
#elif IRQ_GTM_TIM0_SR6_CAT == IRQ_CAT23
ISR(GTMTIM0SR6_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM0_SR6_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(0, 6);
}
#endif

#if((IRQ_GTM_TIM0_SR7_PRIO > 0) || (IRQ_GTM_TIM0_SR7_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM0_SR7_PRIO > 0) && (IRQ_GTM_TIM0_SR7_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM0SR7_ISR, 0, IRQ_GTM_TIM0_SR7_PRIO)
#elif IRQ_GTM_TIM0_SR7_CAT == IRQ_CAT23
ISR(GTMTIM0SR7_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM0_SR7_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(0, 7);
}
#endif

#endif /* #if(IRQ_GTM_TIM0_EXIST == (STD_ON)) */

#if(IRQ_GTM_TIM1_EXIST == (STD_ON))

/******************** TIM 1 *************************************/
#if((IRQ_GTM_TIM1_SR0_PRIO > 0) || (IRQ_GTM_TIM1_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM1_SR0_PRIO > 0) && (IRQ_GTM_TIM1_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM1SR0_ISR, 0, IRQ_GTM_TIM1_SR0_PRIO)
#elif IRQ_GTM_TIM1_SR0_CAT == IRQ_CAT23
ISR(GTMTIM1SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM1_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(1, 0);
}
#endif

#if((IRQ_GTM_TIM1_SR1_PRIO > 0) || (IRQ_GTM_TIM1_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM1_SR1_PRIO > 0) && (IRQ_GTM_TIM1_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM1SR1_ISR, 0, IRQ_GTM_TIM1_SR1_PRIO)
#elif IRQ_GTM_TIM1_SR1_CAT == IRQ_CAT23
ISR(GTMTIM1SR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM1_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(1, 1);
}
#endif



#if((IRQ_GTM_TIM1_SR2_PRIO > 0) || (IRQ_GTM_TIM1_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM1_SR2_PRIO > 0) && (IRQ_GTM_TIM1_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM1SR2_ISR, 0, IRQ_GTM_TIM1_SR2_PRIO)
#elif IRQ_GTM_TIM1_SR2_CAT == IRQ_CAT23
ISR(GTMTIM1SR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM1_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(1, 2);
}
#endif

//uint32 Test_IrqTim1_3_Cnt;
//uint32 Test_IrqTim1_4_Cnt;
//uint32 Test_IrqTim1_6_Cnt;

#if((IRQ_GTM_TIM1_SR3_PRIO > 0) || (IRQ_GTM_TIM1_SR3_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM1_SR3_PRIO > 0) && (IRQ_GTM_TIM1_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM1SR3_ISR, 0, IRQ_GTM_TIM1_SR3_PRIO)
#elif IRQ_GTM_TIM1_SR3_CAT == IRQ_CAT23
ISR(GTMTIM1SR3_ISR)
#endif
{
  /* Enable Global Interrupts */
//#if (IRQ_GTM_TIM1_SR3_CAT == IRQ_CAT1)
//
//	  Test_IrqTim1_3_Cnt++;
//	  Hal_GetStatus(MOTOT_M1, HAL_A);
//  Mcal_EnableAllInterrupts();
//#endif
//  /* Parameter is Channel Number */
//  Gtm_IsrTimModule(1, 3);
}
#endif

#if((IRQ_GTM_TIM1_SR4_PRIO > 0) || (IRQ_GTM_TIM1_SR4_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM1_SR4_PRIO > 0) && (IRQ_GTM_TIM1_SR4_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM1SR4_ISR, 0, IRQ_GTM_TIM1_SR4_PRIO)
#elif IRQ_GTM_TIM1_SR4_CAT == IRQ_CAT23
ISR(GTMTIM1SR4_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM1_SR4_CAT == IRQ_CAT1)
//	Test_IrqTim1_4_Cnt++;
//  Hal_GetStatus(MOTOT_M1, HAL_B);
//  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
//  Gtm_IsrTimModule(1, 4);
}
#endif


#if((IRQ_GTM_TIM1_SR5_PRIO > 0) || (IRQ_GTM_TIM1_SR5_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM1_SR5_PRIO > 0) && (IRQ_GTM_TIM1_SR5_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM1SR5_ISR, 0, IRQ_GTM_TIM1_SR5_PRIO)
#elif IRQ_GTM_TIM1_SR5_CAT == IRQ_CAT23
ISR(GTMTIM1SR5_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM1_SR5_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(1, 5);
}
#endif

#if((IRQ_GTM_TIM1_SR6_PRIO > 0) || (IRQ_GTM_TIM1_SR6_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM1_SR6_PRIO > 0) && (IRQ_GTM_TIM1_SR6_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM1SR6_ISR, 0, IRQ_GTM_TIM1_SR6_PRIO)
#elif IRQ_GTM_TIM1_SR6_CAT == IRQ_CAT23
ISR(GTMTIM1SR6_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM1_SR6_CAT == IRQ_CAT1)
//	Test_IrqTim1_6_Cnt++;
//	Hal_GetStatus(MOTOT_M1, HAL_C);
//  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
//  Gtm_IsrTimModule(1, 6);
}
#endif

#if((IRQ_GTM_TIM1_SR7_PRIO > 0) || (IRQ_GTM_TIM1_SR7_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM1_SR7_PRIO > 0) && (IRQ_GTM_TIM1_SR7_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM1SR7_ISR, 0, IRQ_GTM_TIM1_SR7_PRIO)
#elif IRQ_GTM_TIM1_SR7_CAT == IRQ_CAT23
ISR(GTMTIM1SR7_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM1_SR7_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(1, 7);
}
#endif

#endif /* #if(IRQ_GTM_TIM1_EXIST == (STD_ON)) */

#if(IRQ_GTM_TIM2_EXIST == (STD_ON))
/******************** TIM 2 *************************************/

#if((IRQ_GTM_TIM2_SR0_PRIO > 0) || (IRQ_GTM_TIM2_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM2_SR0_PRIO > 0) && (IRQ_GTM_TIM2_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM2SR0_ISR, 0, IRQ_GTM_TIM2_SR0_PRIO)
#elif IRQ_GTM_TIM2_SR0_CAT == IRQ_CAT23
ISR(GTMTIM2SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM2_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(2, 0);
}
#endif

#if((IRQ_GTM_TIM2_SR1_PRIO > 0) || (IRQ_GTM_TIM2_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM2_SR1_PRIO > 0) && (IRQ_GTM_TIM2_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM2SR1_ISR, 0, IRQ_GTM_TIM2_SR1_PRIO)
#elif IRQ_GTM_TIM2_SR1_CAT == IRQ_CAT23
ISR(GTMTIM2SR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM2_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(2, 1);
}
#endif


#if((IRQ_GTM_TIM2_SR2_PRIO > 0) || (IRQ_GTM_TIM2_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM2_SR2_PRIO > 0) && (IRQ_GTM_TIM2_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM2SR2_ISR, 0, IRQ_GTM_TIM2_SR2_PRIO)
#elif IRQ_GTM_TIM2_SR2_CAT == IRQ_CAT23
ISR(GTMTIM2SR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM2_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(2, 2);
}
#endif

#if((IRQ_GTM_TIM2_SR3_PRIO > 0) || (IRQ_GTM_TIM2_SR3_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM2_SR3_PRIO > 0) && (IRQ_GTM_TIM2_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM2SR3_ISR, 0, IRQ_GTM_TIM2_SR3_PRIO)
#elif IRQ_GTM_TIM2_SR3_CAT == IRQ_CAT23
ISR(GTMTIM2SR3_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM2_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(2, 3);
}
#endif


#if((IRQ_GTM_TIM2_SR4_PRIO > 0) || (IRQ_GTM_TIM2_SR4_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM2_SR4_PRIO > 0) && (IRQ_GTM_TIM2_SR4_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM2SR4_ISR, 0, IRQ_GTM_TIM2_SR4_PRIO)
#elif IRQ_GTM_TIM2_SR4_CAT == IRQ_CAT23
ISR(GTMTIM2SR4_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM2_SR4_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(2, 4);
}
#endif

#if((IRQ_GTM_TIM2_SR5_PRIO > 0) || (IRQ_GTM_TIM2_SR5_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM2_SR5_PRIO > 0) && (IRQ_GTM_TIM2_SR5_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM2SR5_ISR, 0, IRQ_GTM_TIM2_SR5_PRIO)
#elif IRQ_GTM_TIM2_SR5_CAT == IRQ_CAT23
ISR(GTMTIM2SR5_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM2_SR5_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(2, 5);
}
#endif


#if((IRQ_GTM_TIM2_SR6_PRIO > 0) || (IRQ_GTM_TIM2_SR6_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM2_SR6_PRIO > 0) && (IRQ_GTM_TIM2_SR6_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM2SR6_ISR, 0, IRQ_GTM_TIM2_SR6_PRIO)
#elif IRQ_GTM_TIM2_SR6_CAT == IRQ_CAT23
ISR(GTMTIM2SR6_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM2_SR6_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(2, 6);
}
#endif

#if((IRQ_GTM_TIM2_SR7_PRIO > 0) || (IRQ_GTM_TIM2_SR7_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM2_SR7_PRIO > 0) && (IRQ_GTM_TIM2_SR7_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM2SR7_ISR, 0, IRQ_GTM_TIM2_SR7_PRIO)
#elif IRQ_GTM_TIM2_SR7_CAT == IRQ_CAT23
ISR(GTMTIM2SR7_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM2_SR7_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(2, 7);
}
#endif

#endif /* #if(IRQ_GTM_TIM2_EXIST == (STD_ON)) */

#if(IRQ_GTM_TIM3_EXIST == (STD_ON))
/******************** TIM 3 *************************************/

#if((IRQ_GTM_TIM3_SR0_PRIO > 0) || (IRQ_GTM_TIM3_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM3_SR0_PRIO > 0) && (IRQ_GTM_TIM3_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM3SR0_ISR, 0, IRQ_GTM_TIM3_SR0_PRIO)
#elif IRQ_GTM_TIM3_SR0_CAT == IRQ_CAT23
ISR(GTMTIM3SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM3_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(3, 0);
}
#endif

#if((IRQ_GTM_TIM3_SR1_PRIO > 0) || (IRQ_GTM_TIM3_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM3_SR1_PRIO > 0) && (IRQ_GTM_TIM3_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM3SR1_ISR, 0, IRQ_GTM_TIM3_SR1_PRIO)
#elif IRQ_GTM_TIM3_SR1_CAT == IRQ_CAT23
ISR(GTMTIM3SR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM3_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(3, 1);
}
#endif


#if((IRQ_GTM_TIM3_SR2_PRIO > 0) || (IRQ_GTM_TIM3_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM3_SR2_PRIO > 0) && (IRQ_GTM_TIM3_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM3SR2_ISR, 0, IRQ_GTM_TIM3_SR2_PRIO)
#elif IRQ_GTM_TIM3_SR2_CAT == IRQ_CAT23
ISR(GTMTIM3SR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM3_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(3, 2);
}
#endif

#if((IRQ_GTM_TIM3_SR3_PRIO > 0) || (IRQ_GTM_TIM3_SR3_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM3_SR3_PRIO > 0) && (IRQ_GTM_TIM3_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM3SR3_ISR, 0, IRQ_GTM_TIM3_SR3_PRIO)
#elif IRQ_GTM_TIM3_SR3_CAT == IRQ_CAT23
ISR(GTMTIM3SR3_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM3_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(3, 3);
}
#endif


#if((IRQ_GTM_TIM3_SR4_PRIO > 0) || (IRQ_GTM_TIM3_SR4_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM3_SR4_PRIO > 0) && (IRQ_GTM_TIM3_SR4_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM3SR4_ISR, 0, IRQ_GTM_TIM3_SR4_PRIO)
#elif IRQ_GTM_TIM3_SR4_CAT == IRQ_CAT23
ISR(GTMTIM3SR4_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM3_SR4_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(3, 4);
}
#endif

#if((IRQ_GTM_TIM3_SR5_PRIO > 0) || (IRQ_GTM_TIM3_SR5_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM3_SR5_PRIO > 0) && (IRQ_GTM_TIM3_SR5_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM3SR5_ISR, 0, IRQ_GTM_TIM3_SR5_PRIO)
#elif IRQ_GTM_TIM3_SR5_CAT == IRQ_CAT23
ISR(GTMTIM3SR5_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM3_SR5_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(3, 5);
}
#endif


#if((IRQ_GTM_TIM3_SR6_PRIO > 0) || (IRQ_GTM_TIM3_SR6_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM3_SR6_PRIO > 0) && (IRQ_GTM_TIM3_SR6_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM3SR6_ISR, 0, IRQ_GTM_TIM3_SR6_PRIO)
#elif IRQ_GTM_TIM3_SR6_CAT == IRQ_CAT23
ISR(GTMTIM3SR6_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM3_SR6_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(3, 6);
}
#endif

#if((IRQ_GTM_TIM3_SR7_PRIO > 0) || (IRQ_GTM_TIM3_SR7_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM3_SR7_PRIO > 0) && (IRQ_GTM_TIM3_SR7_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM3SR7_ISR, 0, IRQ_GTM_TIM3_SR7_PRIO)
#elif IRQ_GTM_TIM3_SR7_CAT == IRQ_CAT23
ISR(GTMTIM3SR7_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM3_SR7_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(3, 7);
}
#endif

#endif /* #if(IRQ_GTM_TIM3_EXIST == (STD_ON)) */



#if(IRQ_GTM_TIM4_EXIST == (STD_ON))
/******************** TIM 4 *************************************/

#if((IRQ_GTM_TIM4_SR0_PRIO > 0) || (IRQ_GTM_TIM4_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM4_SR0_PRIO > 0) && (IRQ_GTM_TIM4_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM4SR0_ISR, 0, IRQ_GTM_TIM4_SR0_PRIO)
#elif IRQ_GTM_TIM4_SR0_CAT == IRQ_CAT23
ISR(GTMTIM4SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM4_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(4, 0);
}
#endif

#if((IRQ_GTM_TIM4_SR1_PRIO > 0) || (IRQ_GTM_TIM4_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM4_SR1_PRIO > 0) && (IRQ_GTM_TIM4_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM4SR1_ISR, 0, IRQ_GTM_TIM4_SR1_PRIO)
#elif IRQ_GTM_TIM4_SR1_CAT == IRQ_CAT23
ISR(GTMTIM4SR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM4_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(4, 1);
}
#endif


#if((IRQ_GTM_TIM4_SR2_PRIO > 0) || (IRQ_GTM_TIM4_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM4_SR2_PRIO > 0) && (IRQ_GTM_TIM4_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM4SR2_ISR, 0, IRQ_GTM_TIM4_SR2_PRIO)
#elif IRQ_GTM_TIM4_SR2_CAT == IRQ_CAT23
ISR(GTMTIM4SR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM4_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(4, 2);
}
#endif

#if((IRQ_GTM_TIM4_SR3_PRIO > 0) || (IRQ_GTM_TIM4_SR3_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM4_SR3_PRIO > 0) && (IRQ_GTM_TIM4_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM4SR3_ISR, 0, IRQ_GTM_TIM4_SR3_PRIO)
#elif IRQ_GTM_TIM4_SR3_CAT == IRQ_CAT23
ISR(GTMTIM4SR3_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM4_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(4, 3);
}
#endif


#if((IRQ_GTM_TIM4_SR4_PRIO > 0) || (IRQ_GTM_TIM4_SR4_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM4_SR4_PRIO > 0) && (IRQ_GTM_TIM4_SR4_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM4SR4_ISR, 0, IRQ_GTM_TIM4_SR4_PRIO)
#elif IRQ_GTM_TIM4_SR4_CAT == IRQ_CAT23
ISR(GTMTIM4SR4_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM4_SR4_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(4, 4);
}
#endif

#if((IRQ_GTM_TIM4_SR5_PRIO > 0) || (IRQ_GTM_TIM4_SR5_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM4_SR5_PRIO > 0) && (IRQ_GTM_TIM4_SR5_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM4SR5_ISR, 0, IRQ_GTM_TIM4_SR5_PRIO)
#elif IRQ_GTM_TIM4_SR5_CAT == IRQ_CAT23
ISR(GTMTIM4SR5_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM4_SR5_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(4, 5);
}
#endif


#if((IRQ_GTM_TIM4_SR6_PRIO > 0) || (IRQ_GTM_TIM4_SR6_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM4_SR6_PRIO > 0) && (IRQ_GTM_TIM4_SR6_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM4SR6_ISR, 0, IRQ_GTM_TIM4_SR6_PRIO)
#elif IRQ_GTM_TIM4_SR6_CAT == IRQ_CAT23
ISR(GTMTIM4SR6_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM4_SR6_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(4, 6);
}
#endif

#if((IRQ_GTM_TIM4_SR7_PRIO > 0) || (IRQ_GTM_TIM4_SR7_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM4_SR7_PRIO > 0) && (IRQ_GTM_TIM4_SR7_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM4SR7_ISR, 0, IRQ_GTM_TIM4_SR7_PRIO)
#elif IRQ_GTM_TIM4_SR7_CAT == IRQ_CAT23
ISR(GTMTIM4SR7_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM4_SR7_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(4, 7);
}
#endif

#endif /* #if(IRQ_GTM_TIM4_EXIST == (STD_ON)) */



#if(IRQ_GTM_TIM5_EXIST == (STD_ON))
/******************** TIM 5 *************************************/

#if((IRQ_GTM_TIM5_SR0_PRIO > 0) || (IRQ_GTM_TIM5_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM5_SR0_PRIO > 0) && (IRQ_GTM_TIM5_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM5SR0_ISR, 0, IRQ_GTM_TIM5_SR0_PRIO)
#elif IRQ_GTM_TIM5_SR0_CAT == IRQ_CAT23
ISR(GTMTIM5SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM5_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(5, 0);
}
#endif

#if((IRQ_GTM_TIM5_SR1_PRIO > 0) || (IRQ_GTM_TIM5_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM5_SR1_PRIO > 0) && (IRQ_GTM_TIM5_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM5SR1_ISR, 0, IRQ_GTM_TIM5_SR1_PRIO)
#elif IRQ_GTM_TIM5_SR1_CAT == IRQ_CAT23
ISR(GTMTIM5SR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM5_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(5, 1);
}
#endif


#if((IRQ_GTM_TIM5_SR2_PRIO > 0) || (IRQ_GTM_TIM5_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM5_SR2_PRIO > 0) && (IRQ_GTM_TIM5_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM5SR2_ISR, 0, IRQ_GTM_TIM5_SR2_PRIO)
#elif IRQ_GTM_TIM5_SR2_CAT == IRQ_CAT23
ISR(GTMTIM5SR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM5_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(5, 2);
}
#endif

#if((IRQ_GTM_TIM5_SR3_PRIO > 0) || (IRQ_GTM_TIM5_SR3_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM5_SR3_PRIO > 0) && (IRQ_GTM_TIM5_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM5SR3_ISR, 0, IRQ_GTM_TIM5_SR3_PRIO)
#elif IRQ_GTM_TIM5_SR3_CAT == IRQ_CAT23
ISR(GTMTIM5SR3_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM5_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(5, 3);
}
#endif


#if((IRQ_GTM_TIM5_SR4_PRIO > 0) || (IRQ_GTM_TIM5_SR4_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM5_SR4_PRIO > 0) && (IRQ_GTM_TIM5_SR4_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM5SR4_ISR, 0, IRQ_GTM_TIM5_SR4_PRIO)
#elif IRQ_GTM_TIM5_SR4_CAT == IRQ_CAT23
ISR(GTMTIM5SR4_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM5_SR4_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(5, 4);
}
#endif

#if((IRQ_GTM_TIM5_SR5_PRIO > 0) || (IRQ_GTM_TIM5_SR5_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM5_SR5_PRIO > 0) && (IRQ_GTM_TIM5_SR5_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM5SR5_ISR, 0, IRQ_GTM_TIM5_SR5_PRIO)
#elif IRQ_GTM_TIM5_SR5_CAT == IRQ_CAT23
ISR(GTMTIM5SR5_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM5_SR5_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(5, 5);
}
#endif


#if((IRQ_GTM_TIM5_SR6_PRIO > 0) || (IRQ_GTM_TIM5_SR6_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM5_SR6_PRIO > 0) && (IRQ_GTM_TIM5_SR6_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM5SR6_ISR, 0, IRQ_GTM_TIM5_SR6_PRIO)
#elif IRQ_GTM_TIM5_SR6_CAT == IRQ_CAT23
ISR(GTMTIM5SR6_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM5_SR6_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(5, 6);
}
#endif

#if((IRQ_GTM_TIM5_SR7_PRIO > 0) || (IRQ_GTM_TIM5_SR7_CAT == IRQ_CAT23))
#if((IRQ_GTM_TIM5_SR7_PRIO > 0) && (IRQ_GTM_TIM5_SR7_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMTIM5SR7_ISR, 0, IRQ_GTM_TIM5_SR7_PRIO)
#elif IRQ_GTM_TIM5_SR7_CAT == IRQ_CAT23
ISR(GTMTIM5SR7_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_TIM5_SR7_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  /* Parameter is Channel Number */
  Gtm_IsrTimModule(5, 7);
}
#endif
#endif /* #if(IRQ_GTM_TIM5_EXIST == (STD_ON)) */


#if(IRQ_GTM_AEI_EXIST == (STD_ON))

#if((IRQ_GTM_AEI_PRIO > 0) || (IRQ_GTM_AEI_CAT == IRQ_CAT23))
#if((IRQ_GTM_AEI_PRIO > 0) && (IRQ_GTM_AEI_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMAEI_ISR, 0, IRQ_GTM_AEI_PRIO)
#elif IRQ_GTM_AEI_CAT == IRQ_CAT23
ISR(GTMAEI_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_AEI_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif


}
#endif

#endif /* #if(IRQ_GTM_AEI_EXIST == (STD_ON)) */

#if(IRQ_GTM_ARU_EXIST == (STD_ON))
#if((IRQ_GTM_ARU_SR0_PRIO > 0) || (IRQ_GTM_ARU_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_ARU_SR0_PRIO > 0) && (IRQ_GTM_ARU_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMARUSR0_ISR, 0, IRQ_GTM_ARU_SR0_PRIO)
#elif IRQ_GTM_ARU_SR0_CAT == IRQ_CAT23
ISR(GTMARUSR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ARU_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif


#if((IRQ_GTM_ARU_SR1_PRIO > 0) || (IRQ_GTM_ARU_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_ARU_SR1_PRIO > 0) && (IRQ_GTM_ARU_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMARUSR1_ISR, 0, IRQ_GTM_ARU_SR1_PRIO)
#elif IRQ_GTM_ARU_SR1_CAT == IRQ_CAT23
ISR(GTMARUSR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ARU_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif


#if((IRQ_GTM_ARU_SR2_PRIO > 0) || (IRQ_GTM_ARU_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_ARU_SR2_PRIO > 0) && (IRQ_GTM_ARU_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMARUSR2_ISR, 0, IRQ_GTM_ARU_SR2_PRIO)
#elif IRQ_GTM_ARU_SR2_CAT == IRQ_CAT23
ISR(GTMARUSR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ARU_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#endif /* #if(IRQ_GTM_ARU_EXIST == (STD_ON)) */

#if (IRQ_GTM_BRC_EXIST == (STD_ON))

#if((IRQ_GTM_BRC_PRIO > 0) || (IRQ_GTM_BRC_CAT == IRQ_CAT23))
#if((IRQ_GTM_BRC_PRIO > 0) && (IRQ_GTM_BRC_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMBRC_ISR, 0, IRQ_GTM_BRC_PRIO)
#elif IRQ_GTM_BRC_CAT == IRQ_CAT23
ISR(GTMBRC_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_BRC_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif
#endif /* #if (IRQ_GTM_BRC_EXIST == (STD_ON)) */


#if(IRQ_GTM_CMP_EXIST == (STD_ON))
#if((IRQ_GTM_CMP_PRIO > 0) || (IRQ_GTM_CMP_CAT == IRQ_CAT23))
#if((IRQ_GTM_CMP_PRIO > 0) && (IRQ_GTM_CMP_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMCMP_ISR, 0, IRQ_GTM_CMP_PRIO)
#elif IRQ_GTM_CMP_CAT == IRQ_CAT23
ISR(GTMCMP_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_CMP_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#endif /* #if(IRQ_GTM_CMP_EXIST == (STD_ON)) */

#if(IRQ_GTM_SPE_EXIST == (STD_ON))

#if((IRQ_GTM_SPE0_PRIO > 0) || (IRQ_GTM_SPE0_CAT == IRQ_CAT23))
#if((IRQ_GTM_SPE0_PRIO > 0) && (IRQ_GTM_SPE0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMSPE0_ISR, 0, IRQ_GTM_SPE0_PRIO)
#elif IRQ_GTM_SPE0_CAT == IRQ_CAT23
ISR(GTMSPE0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_SPE0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_SPE1_PRIO > 0) || (IRQ_GTM_SPE1_CAT == IRQ_CAT23))
#if((IRQ_GTM_SPE1_PRIO > 0) && (IRQ_GTM_SPE1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMSPE1_ISR, 0, IRQ_GTM_SPE1_PRIO)
#elif IRQ_GTM_SPE1_CAT == IRQ_CAT23
ISR(GTMSPE1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_SPE1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#endif /* #if(IRQ_GTM_SPE_EXIST == (STD_ON)) */

#if(IRQ_GTM_PSM0_EXIST == (STD_ON))

#if((IRQ_GTM_PSM0_SR0_PRIO > 0) || (IRQ_GTM_PSM0_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_PSM0_SR0_PRIO > 0) && (IRQ_GTM_PSM0_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMPSM0SR0_ISR, 0, IRQ_GTM_PSM0_SR0_PRIO)
#elif IRQ_GTM_PSM0_SR0_CAT == IRQ_CAT23
ISR(GTMPSM0SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_PSM0_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_PSM0_SR1_PRIO > 0) || (IRQ_GTM_PSM0_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_PSM0_SR1_PRIO > 0) && (IRQ_GTM_PSM0_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMPSM0SR1_ISR, 0, IRQ_GTM_PSM0_SR1_PRIO)
#elif IRQ_GTM_PSM0_SR1_CAT == IRQ_CAT23
ISR(GTMPSM0SR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_PSM0_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif


#if((IRQ_GTM_PSM0_SR2_PRIO > 0) || (IRQ_GTM_PSM0_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_PSM0_SR2_PRIO > 0) && (IRQ_GTM_PSM0_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMPSM0SR2_ISR, 0, IRQ_GTM_PSM0_SR2_PRIO)
#elif IRQ_GTM_PSM0_SR2_CAT == IRQ_CAT23
ISR(GTMPSM0SR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_PSM0_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_PSM0_SR3_PRIO > 0) || (IRQ_GTM_PSM0_SR3_CAT == IRQ_CAT23))
#if((IRQ_GTM_PSM0_SR3_PRIO > 0) && (IRQ_GTM_PSM0_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMPSM0SR3_ISR, 0, IRQ_GTM_PSM0_SR3_PRIO)
#elif IRQ_GTM_PSM0_SR3_CAT == IRQ_CAT23
ISR(GTMPSM0SR3_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_PSM0_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif


#if((IRQ_GTM_PSM0_SR4_PRIO > 0) || (IRQ_GTM_PSM0_SR4_CAT == IRQ_CAT23))
#if((IRQ_GTM_PSM0_SR4_PRIO > 0) && (IRQ_GTM_PSM0_SR4_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMPSM0SR4_ISR, 0, IRQ_GTM_PSM0_SR4_PRIO)
#elif IRQ_GTM_PSM0_SR4_CAT == IRQ_CAT23
ISR(GTMPSM0SR4_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_PSM0_SR4_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_PSM0_SR5_PRIO > 0) || (IRQ_GTM_PSM0_SR5_CAT == IRQ_CAT23))
#if((IRQ_GTM_PSM0_SR5_PRIO > 0) && (IRQ_GTM_PSM0_SR5_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMPSM0SR5_ISR, 0, IRQ_GTM_PSM0_SR5_PRIO)
#elif IRQ_GTM_PSM0_SR5_CAT == IRQ_CAT23
ISR(GTMPSM0SR5_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_PSM0_SR5_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif


#if((IRQ_GTM_PSM0_SR6_PRIO > 0) || (IRQ_GTM_PSM0_SR6_CAT == IRQ_CAT23))
#if((IRQ_GTM_PSM0_SR6_PRIO > 0) && (IRQ_GTM_PSM0_SR6_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMPSM0SR6_ISR, 0, IRQ_GTM_PSM0_SR6_PRIO)
#elif IRQ_GTM_PSM0_SR6_CAT == IRQ_CAT23
ISR(GTMPSM0SR6_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_PSM0_SR6_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_PSM0_SR7_PRIO > 0) || (IRQ_GTM_PSM0_SR7_CAT == IRQ_CAT23))
#if((IRQ_GTM_PSM0_SR7_PRIO > 0) && (IRQ_GTM_PSM0_SR7_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMPSM0SR7_ISR, 0, IRQ_GTM_PSM0_SR7_PRIO)
#elif IRQ_GTM_PSM0_SR7_CAT == IRQ_CAT23
ISR(GTMPSM0SR7_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_PSM0_SR7_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif


#endif /* #if(IRQ_GTM_PSM0_EXIST == (STD_ON)) */

#if(IRQ_GTM_DPLL_EXIST == (STD_ON))

#if((IRQ_GTM_DPLL_SR0_PRIO > 0) || (IRQ_GTM_DPLL_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_DPLL_SR0_PRIO > 0) && (IRQ_GTM_DPLL_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMDPLLSR0_ISR, 0, IRQ_GTM_DPLL_SR0_PRIO)
#elif IRQ_GTM_DPLL_SR0_CAT == IRQ_CAT23
ISR(GTMDPLLSR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_DPLL_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif


#if((IRQ_GTM_DPLL_SR1_PRIO > 0) || (IRQ_GTM_DPLL_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_DPLL_SR1_PRIO > 0) && (IRQ_GTM_DPLL_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMDPLLSR1_ISR, 0, IRQ_GTM_DPLL_SR1_PRIO)
#elif IRQ_GTM_DPLL_SR1_CAT == IRQ_CAT23
ISR(GTMDPLLSR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_DPLL_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_DPLL_SR2_PRIO > 0) || (IRQ_GTM_DPLL_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_DPLL_SR2_PRIO > 0) && (IRQ_GTM_DPLL_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMDPLLSR2_ISR, 0, IRQ_GTM_DPLL_SR2_PRIO)
#elif IRQ_GTM_DPLL_SR2_CAT == IRQ_CAT23
ISR(GTMDPLLSR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_DPLL_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif



#if((IRQ_GTM_DPLL_SR3_PRIO > 0) || (IRQ_GTM_DPLL_SR3_CAT == IRQ_CAT23))
#if((IRQ_GTM_DPLL_SR3_PRIO > 0) && (IRQ_GTM_DPLL_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMDPLLSR3_ISR, 0, IRQ_GTM_DPLL_SR3_PRIO)
#elif IRQ_GTM_DPLL_SR3_CAT == IRQ_CAT23
ISR(GTMDPLLSR3_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_DPLL_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_DPLL_SR4_PRIO > 0) || (IRQ_GTM_DPLL_SR4_CAT == IRQ_CAT23))
#if((IRQ_GTM_DPLL_SR4_PRIO > 0) && (IRQ_GTM_DPLL_SR4_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMDPLLSR4_ISR, 0, IRQ_GTM_DPLL_SR4_PRIO)
#elif IRQ_GTM_DPLL_SR4_CAT == IRQ_CAT23
ISR(GTMDPLLSR4_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_DPLL_SR4_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif


#if((IRQ_GTM_DPLL_SR5_PRIO > 0) || (IRQ_GTM_DPLL_SR5_CAT == IRQ_CAT23))
#if((IRQ_GTM_DPLL_SR5_PRIO > 0) && (IRQ_GTM_DPLL_SR5_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMDPLLSR5_ISR, 0, IRQ_GTM_DPLL_SR5_PRIO)
#elif IRQ_GTM_DPLL_SR5_CAT == IRQ_CAT23
ISR(GTMDPLLSR5_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_DPLL_SR5_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_DPLL_SR6_PRIO > 0) || (IRQ_GTM_DPLL_SR6_CAT == IRQ_CAT23))
#if((IRQ_GTM_DPLL_SR6_PRIO > 0) && (IRQ_GTM_DPLL_SR6_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMDPLLSR6_ISR, 0, IRQ_GTM_DPLL_SR6_PRIO)
#elif IRQ_GTM_DPLL_SR6_CAT == IRQ_CAT23
ISR(GTMDPLLSR6_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_DPLL_SR6_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif



#if((IRQ_GTM_DPLL_SR7_PRIO > 0) || (IRQ_GTM_DPLL_SR7_CAT == IRQ_CAT23))
#if((IRQ_GTM_DPLL_SR7_PRIO > 0) && (IRQ_GTM_DPLL_SR7_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMDPLLSR7_ISR, 0, IRQ_GTM_DPLL_SR7_PRIO)
#elif IRQ_GTM_DPLL_SR7_CAT == IRQ_CAT23
ISR(GTMDPLLSR7_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_DPLL_SR7_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif


#if((IRQ_GTM_DPLL_SR8_PRIO > 0) || (IRQ_GTM_DPLL_SR8_CAT == IRQ_CAT23))
#if((IRQ_GTM_DPLL_SR8_PRIO > 0) && (IRQ_GTM_DPLL_SR8_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMDPLLSR8_ISR, 0, IRQ_GTM_DPLL_SR8_PRIO)
#elif IRQ_GTM_DPLL_SR8_CAT == IRQ_CAT23
ISR(GTMDPLLSR8_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_DPLL_SR8_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif



#if((IRQ_GTM_DPLL_SR9_PRIO > 0) || (IRQ_GTM_DPLL_SR9_CAT == IRQ_CAT23))
#if((IRQ_GTM_DPLL_SR9_PRIO > 0) && (IRQ_GTM_DPLL_SR9_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMDPLLSR9_ISR, 0, IRQ_GTM_DPLL_SR9_PRIO)
#elif IRQ_GTM_DPLL_SR9_CAT == IRQ_CAT23
ISR(GTMDPLLSR9_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_DPLL_SR9_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif


#if((IRQ_GTM_DPLL_SR10_PRIO > 0) || (IRQ_GTM_DPLL_SR10_CAT == IRQ_CAT23))
#if((IRQ_GTM_DPLL_SR10_PRIO > 0) && (IRQ_GTM_DPLL_SR10_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMDPLLSR10_ISR, 0, IRQ_GTM_DPLL_SR10_PRIO)
#elif IRQ_GTM_DPLL_SR10_CAT == IRQ_CAT23
ISR(GTMDPLLSR10_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_DPLL_SR10_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif


#if((IRQ_GTM_DPLL_SR11_PRIO > 0) || (IRQ_GTM_DPLL_SR11_CAT == IRQ_CAT23))
#if((IRQ_GTM_DPLL_SR11_PRIO > 0) && (IRQ_GTM_DPLL_SR11_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMDPLLSR11_ISR, 0, IRQ_GTM_DPLL_SR11_PRIO)
#elif IRQ_GTM_DPLL_SR11_CAT == IRQ_CAT23
ISR(GTMDPLLSR11_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_DPLL_SR11_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_DPLL_SR12_PRIO > 0) || (IRQ_GTM_DPLL_SR12_CAT == IRQ_CAT23))
#if((IRQ_GTM_DPLL_SR12_PRIO > 0) && (IRQ_GTM_DPLL_SR12_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMDPLLSR12_ISR, 0, IRQ_GTM_DPLL_SR12_PRIO)
#elif IRQ_GTM_DPLL_SR12_CAT == IRQ_CAT23
ISR(GTMDPLLSR12_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_DPLL_SR12_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_DPLL_SR13_PRIO > 0) || (IRQ_GTM_DPLL_SR13_CAT == IRQ_CAT23))
#if((IRQ_GTM_DPLL_SR13_PRIO > 0) && (IRQ_GTM_DPLL_SR13_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMDPLLSR13_ISR, 0, IRQ_GTM_DPLL_SR13_PRIO)
#elif IRQ_GTM_DPLL_SR13_CAT == IRQ_CAT23
ISR(GTMDPLLSR13_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_DPLL_SR13_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_DPLL_SR14_PRIO > 0) || (IRQ_GTM_DPLL_SR14_CAT == IRQ_CAT23))
#if((IRQ_GTM_DPLL_SR14_PRIO > 0) && (IRQ_GTM_DPLL_SR14_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMDPLLSR14_ISR, 0, IRQ_GTM_DPLL_SR14_PRIO)
#elif IRQ_GTM_DPLL_SR14_CAT == IRQ_CAT23
ISR(GTMDPLLSR14_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_DPLL_SR14_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_DPLL_SR15_PRIO > 0) || (IRQ_GTM_DPLL_SR15_CAT == IRQ_CAT23))
#if((IRQ_GTM_DPLL_SR15_PRIO > 0) && (IRQ_GTM_DPLL_SR15_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMDPLLSR15_ISR, 0, IRQ_GTM_DPLL_SR15_PRIO)
#elif IRQ_GTM_DPLL_SR15_CAT == IRQ_CAT23
ISR(GTMDPLLSR15_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_DPLL_SR15_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif


#if((IRQ_GTM_DPLL_SR16_PRIO > 0) || (IRQ_GTM_DPLL_SR16_CAT == IRQ_CAT23))
#if((IRQ_GTM_DPLL_SR16_PRIO > 0) && (IRQ_GTM_DPLL_SR16_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMDPLLSR16_ISR, 0, IRQ_GTM_DPLL_SR16_PRIO)
#elif IRQ_GTM_DPLL_SR16_CAT == IRQ_CAT23
ISR(GTMDPLLSR16_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_DPLL_SR16_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif


#if((IRQ_GTM_DPLL_SR17_PRIO > 0) || (IRQ_GTM_DPLL_SR17_CAT == IRQ_CAT23))
#if((IRQ_GTM_DPLL_SR17_PRIO > 0) && (IRQ_GTM_DPLL_SR17_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMDPLLSR17_ISR, 0, IRQ_GTM_DPLL_SR17_PRIO)
#elif IRQ_GTM_DPLL_SR17_CAT == IRQ_CAT23
ISR(GTMDPLLSR17_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_DPLL_SR17_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_DPLL_SR18_PRIO > 0) || (IRQ_GTM_DPLL_SR18_CAT == IRQ_CAT23))
#if((IRQ_GTM_DPLL_SR18_PRIO > 0) && (IRQ_GTM_DPLL_SR18_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMDPLLSR18_ISR, 0, IRQ_GTM_DPLL_SR18_PRIO)
#elif IRQ_GTM_DPLL_SR18_CAT == IRQ_CAT23
ISR(GTMDPLLSR18_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_DPLL_SR18_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif


#if((IRQ_GTM_DPLL_SR19_PRIO > 0) || (IRQ_GTM_DPLL_SR19_CAT == IRQ_CAT23))
#if((IRQ_GTM_DPLL_SR19_PRIO > 0) && (IRQ_GTM_DPLL_SR19_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMDPLLSR19_ISR, 0, IRQ_GTM_DPLL_SR19_PRIO)
#elif IRQ_GTM_DPLL_SR19_CAT == IRQ_CAT23
ISR(GTMDPLLSR19_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_DPLL_SR19_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif


#if((IRQ_GTM_DPLL_SR20_PRIO > 0) || (IRQ_GTM_DPLL_SR20_CAT == IRQ_CAT23))
#if((IRQ_GTM_DPLL_SR20_PRIO > 0) && (IRQ_GTM_DPLL_SR20_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMDPLLSR20_ISR, 0, IRQ_GTM_DPLL_SR20_PRIO)
#elif IRQ_GTM_DPLL_SR20_CAT == IRQ_CAT23
ISR(GTMDPLLSR20_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_DPLL_SR20_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif


#if((IRQ_GTM_DPLL_SR21_PRIO > 0) || (IRQ_GTM_DPLL_SR21_CAT == IRQ_CAT23))
#if((IRQ_GTM_DPLL_SR21_PRIO > 0) && (IRQ_GTM_DPLL_SR21_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMDPLLSR21_ISR, 0, IRQ_GTM_DPLL_SR21_PRIO)
#elif IRQ_GTM_DPLL_SR21_CAT == IRQ_CAT23
ISR(GTMDPLLSR21_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_DPLL_SR21_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_DPLL_SR22_PRIO > 0) || (IRQ_GTM_DPLL_SR22_CAT == IRQ_CAT23))
#if((IRQ_GTM_DPLL_SR22_PRIO > 0) && (IRQ_GTM_DPLL_SR22_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMDPLLSR22_ISR, 0, IRQ_GTM_DPLL_SR22_PRIO)
#elif IRQ_GTM_DPLL_SR22_CAT == IRQ_CAT23
ISR(GTMDPLLSR22_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_DPLL_SR22_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif


#if((IRQ_GTM_DPLL_SR23_PRIO > 0) || (IRQ_GTM_DPLL_SR23_CAT == IRQ_CAT23))
#if((IRQ_GTM_DPLL_SR23_PRIO > 0) && (IRQ_GTM_DPLL_SR23_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMDPLLSR23_ISR, 0, IRQ_GTM_DPLL_SR23_PRIO)
#elif IRQ_GTM_DPLL_SR23_CAT == IRQ_CAT23
ISR(GTMDPLLSR23_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_DPLL_SR23_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif


#if((IRQ_GTM_DPLL_SR24_PRIO > 0) || (IRQ_GTM_DPLL_SR24_CAT == IRQ_CAT23))
#if((IRQ_GTM_DPLL_SR24_PRIO > 0) && (IRQ_GTM_DPLL_SR24_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMDPLLSR24_ISR, 0, IRQ_GTM_DPLL_SR24_PRIO)
#elif IRQ_GTM_DPLL_SR24_CAT == IRQ_CAT23
ISR(GTMDPLLSR24_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_DPLL_SR24_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_DPLL_SR25_PRIO > 0) || (IRQ_GTM_DPLL_SR25_CAT == IRQ_CAT23))
#if((IRQ_GTM_DPLL_SR25_PRIO > 0) && (IRQ_GTM_DPLL_SR25_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMDPLLSR25_ISR, 0, IRQ_GTM_DPLL_SR25_PRIO)
#elif IRQ_GTM_DPLL_SR25_CAT == IRQ_CAT23
ISR(GTMDPLLSR25_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_DPLL_SR25_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif


#if((IRQ_GTM_DPLL_SR26_PRIO > 0) || (IRQ_GTM_DPLL_SR26_CAT == IRQ_CAT23))
#if((IRQ_GTM_DPLL_SR26_PRIO > 0) && (IRQ_GTM_DPLL_SR26_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMDPLLSR26_ISR, 0, IRQ_GTM_DPLL_SR26_PRIO)
#elif IRQ_GTM_DPLL_SR26_CAT == IRQ_CAT23
ISR(GTMDPLLSR26_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_DPLL_SR26_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#endif /*#if(IRQ_GTM_DPLL_EXIST == (STD_ON))*/


#if(IRQ_GTM_MCS0_EXIST == (STD_ON))
/****************** MCS0 *******************************************/
#if((IRQ_GTM_MCS0_SR0_PRIO > 0) || (IRQ_GTM_MCS0_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS0_SR0_PRIO > 0) && (IRQ_GTM_MCS0_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS0SR0_ISR, 0, IRQ_GTM_MCS0_SR0_PRIO)
#elif IRQ_GTM_MCS0_SR0_CAT == IRQ_CAT23
ISR(GTMMCS0SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS0_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS0_SR1_PRIO > 0) || (IRQ_GTM_MCS0_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS0_SR1_PRIO > 0) && (IRQ_GTM_MCS0_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS0SR1_ISR, 0, IRQ_GTM_MCS0_SR1_PRIO)
#elif IRQ_GTM_MCS0_SR1_CAT == IRQ_CAT23
ISR(GTMMCS0SR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS0_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS0_SR2_PRIO > 0) || (IRQ_GTM_MCS0_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS0_SR2_PRIO > 0) && (IRQ_GTM_MCS0_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS0SR2_ISR, 0, IRQ_GTM_MCS0_SR2_PRIO)
#elif IRQ_GTM_MCS0_SR2_CAT == IRQ_CAT23
ISR(GTMMCS0SR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS0_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif


#if((IRQ_GTM_MCS0_SR3_PRIO > 0) || (IRQ_GTM_MCS0_SR3_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS0_SR3_PRIO > 0) && (IRQ_GTM_MCS0_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS0SR3_ISR, 0, IRQ_GTM_MCS0_SR3_PRIO)
#elif IRQ_GTM_MCS0_SR3_CAT == IRQ_CAT23
ISR(GTMMCS0SR3_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS0_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS0_SR4_PRIO > 0) || (IRQ_GTM_MCS0_SR4_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS0_SR4_PRIO > 0) && (IRQ_GTM_MCS0_SR4_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS0SR4_ISR, 0, IRQ_GTM_MCS0_SR4_PRIO)
#elif IRQ_GTM_MCS0_SR4_CAT == IRQ_CAT23
ISR(GTMMCS0SR4_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS0_SR4_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS0_SR5_PRIO > 0) || (IRQ_GTM_MCS0_SR5_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS0_SR5_PRIO > 0) && (IRQ_GTM_MCS0_SR5_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS0SR5_ISR, 0, IRQ_GTM_MCS0_SR5_PRIO)
#elif IRQ_GTM_MCS0_SR5_CAT == IRQ_CAT23
ISR(GTMMCS0SR5_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS0_SR5_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS0_SR6_PRIO > 0) || (IRQ_GTM_MCS0_SR6_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS0_SR6_PRIO > 0) && (IRQ_GTM_MCS0_SR6_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS0SR6_ISR, 0, IRQ_GTM_MCS0_SR6_PRIO)
#elif IRQ_GTM_MCS0_SR6_CAT == IRQ_CAT23
ISR(GTMMCS0SR6_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS0_SR6_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS0_SR7_PRIO > 0) || (IRQ_GTM_MCS0_SR7_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS0_SR7_PRIO > 0) && (IRQ_GTM_MCS0_SR7_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS0SR7_ISR, 0, IRQ_GTM_MCS0_SR7_PRIO)
#elif IRQ_GTM_MCS0_SR7_CAT == IRQ_CAT23
ISR(GTMMCS0SR7_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS0_SR7_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#endif /* #if(IRQ_GTM_MCS0_EXIST == (STD_ON)) */

#if(IRQ_GTM_MCS1_EXIST == (STD_ON))
/****************** MCS1 *******************************************/

#if((IRQ_GTM_MCS1_SR0_PRIO > 0) || (IRQ_GTM_MCS1_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS1_SR0_PRIO > 0) && (IRQ_GTM_MCS1_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS1SR0_ISR, 0, IRQ_GTM_MCS1_SR0_PRIO)
#elif IRQ_GTM_MCS1_SR0_CAT == IRQ_CAT23
ISR(GTMMCS1SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS1_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS1_SR1_PRIO > 0) || (IRQ_GTM_MCS1_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS1_SR1_PRIO > 0) && (IRQ_GTM_MCS1_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS1SR1_ISR, 0, IRQ_GTM_MCS1_SR1_PRIO)
#elif IRQ_GTM_MCS1_SR1_CAT == IRQ_CAT23
ISR(GTMMCS1SR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS1_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS1_SR2_PRIO > 0) || (IRQ_GTM_MCS1_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS1_SR2_PRIO > 0) && (IRQ_GTM_MCS1_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS1SR2_ISR, 0, IRQ_GTM_MCS1_SR2_PRIO)
#elif IRQ_GTM_MCS1_SR2_CAT == IRQ_CAT23
ISR(GTMMCS1SR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS1_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif


#if((IRQ_GTM_MCS1_SR3_PRIO > 0) || (IRQ_GTM_MCS1_SR3_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS1_SR3_PRIO > 0) && (IRQ_GTM_MCS1_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS1SR3_ISR, 0, IRQ_GTM_MCS1_SR3_PRIO)
#elif IRQ_GTM_MCS1_SR3_CAT == IRQ_CAT23
ISR(GTMMCS1SR3_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS1_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS1_SR4_PRIO > 0) || (IRQ_GTM_MCS1_SR4_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS1_SR4_PRIO > 0) && (IRQ_GTM_MCS1_SR4_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS1SR4_ISR, 0, IRQ_GTM_MCS1_SR4_PRIO)
#elif IRQ_GTM_MCS1_SR4_CAT == IRQ_CAT23
ISR(GTMMCS1SR4_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS1_SR4_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS1_SR5_PRIO > 0) || (IRQ_GTM_MCS1_SR5_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS1_SR5_PRIO > 0) && (IRQ_GTM_MCS1_SR5_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS1SR5_ISR, 0, IRQ_GTM_MCS1_SR5_PRIO)
#elif IRQ_GTM_MCS1_SR5_CAT == IRQ_CAT23
ISR(GTMMCS1SR5_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS1_SR5_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS1_SR6_PRIO > 0) || (IRQ_GTM_MCS1_SR6_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS1_SR6_PRIO > 0) && (IRQ_GTM_MCS1_SR6_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS1SR6_ISR, 0, IRQ_GTM_MCS1_SR6_PRIO)
#elif IRQ_GTM_MCS1_SR6_CAT == IRQ_CAT23
ISR(GTMMCS1SR6_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS1_SR6_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS1_SR7_PRIO > 0) || (IRQ_GTM_MCS1_SR7_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS1_SR7_PRIO > 0) && (IRQ_GTM_MCS1_SR7_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS1SR7_ISR, 0, IRQ_GTM_MCS1_SR7_PRIO)
#elif IRQ_GTM_MCS1_SR7_CAT == IRQ_CAT23
ISR(GTMMCS1SR7_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS1_SR7_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#endif /* #if(IRQ_GTM_MCS1_EXIST == (STD_ON)) */

#if(IRQ_GTM_MCS2_EXIST == (STD_ON))
/****************** MCS2 *******************************************/

#if((IRQ_GTM_MCS2_SR0_PRIO > 0) || (IRQ_GTM_MCS2_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS2_SR0_PRIO > 0) && (IRQ_GTM_MCS2_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS2SR0_ISR, 0, IRQ_GTM_MCS2_SR0_PRIO)
#elif IRQ_GTM_MCS2_SR0_CAT == IRQ_CAT23
ISR(GTMMCS2SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS2_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS2_SR1_PRIO > 0) || (IRQ_GTM_MCS2_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS2_SR1_PRIO > 0) && (IRQ_GTM_MCS2_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS2SR1_ISR, 0, IRQ_GTM_MCS2_SR1_PRIO)
#elif IRQ_GTM_MCS2_SR1_CAT == IRQ_CAT23
ISR(GTMMCS2SR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS2_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS2_SR2_PRIO > 0) || (IRQ_GTM_MCS2_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS2_SR2_PRIO > 0) && (IRQ_GTM_MCS2_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS2SR2_ISR, 0, IRQ_GTM_MCS2_SR2_PRIO)
#elif IRQ_GTM_MCS2_SR2_CAT == IRQ_CAT23
ISR(GTMMCS2SR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS2_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif


#if((IRQ_GTM_MCS2_SR3_PRIO > 0) || (IRQ_GTM_MCS2_SR3_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS2_SR3_PRIO > 0) && (IRQ_GTM_MCS2_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS2SR3_ISR, 0, IRQ_GTM_MCS2_SR3_PRIO)
#elif IRQ_GTM_MCS2_SR3_CAT == IRQ_CAT23
ISR(GTMMCS2SR3_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS2_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS2_SR4_PRIO > 0) || (IRQ_GTM_MCS2_SR4_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS2_SR4_PRIO > 0) && (IRQ_GTM_MCS2_SR4_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS2SR4_ISR, 0, IRQ_GTM_MCS2_SR4_PRIO)
#elif IRQ_GTM_MCS2_SR4_CAT == IRQ_CAT23
ISR(GTMMCS2SR4_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS2_SR4_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS2_SR5_PRIO > 0) || (IRQ_GTM_MCS2_SR5_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS2_SR5_PRIO > 0) && (IRQ_GTM_MCS2_SR5_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS2SR5_ISR, 0, IRQ_GTM_MCS2_SR5_PRIO)
#elif IRQ_GTM_MCS2_SR5_CAT == IRQ_CAT23
ISR(GTMMCS2SR5_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS2_SR5_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS2_SR6_PRIO > 0) || (IRQ_GTM_MCS2_SR6_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS2_SR6_PRIO > 0) && (IRQ_GTM_MCS2_SR6_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS2SR6_ISR, 0, IRQ_GTM_MCS2_SR6_PRIO)
#elif IRQ_GTM_MCS2_SR6_CAT == IRQ_CAT23
ISR(GTMMCS2SR6_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS2_SR6_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS2_SR7_PRIO > 0) || (IRQ_GTM_MCS2_SR7_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS2_SR7_PRIO > 0) && (IRQ_GTM_MCS2_SR7_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS2SR7_ISR, 0, IRQ_GTM_MCS2_SR7_PRIO)
#elif IRQ_GTM_MCS2_SR7_CAT == IRQ_CAT23
ISR(GTMMCS2SR7_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS2_SR7_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#endif /* #if(IRQ_GTM_MCS2_EXIST == (STD_ON)) */

#if(IRQ_GTM_MCS3_EXIST == (STD_ON))
/****************** MCS3 *******************************************/

#if((IRQ_GTM_MCS3_SR0_PRIO > 0) || (IRQ_GTM_MCS3_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS3_SR0_PRIO > 0) && (IRQ_GTM_MCS3_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS3SR0_ISR, 0, IRQ_GTM_MCS3_SR0_PRIO)
#elif IRQ_GTM_MCS3_SR0_CAT == IRQ_CAT23
ISR(GTMMCS3SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS3_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS3_SR1_PRIO > 0) || (IRQ_GTM_MCS3_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS3_SR1_PRIO > 0) && (IRQ_GTM_MCS3_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS3SR1_ISR, 0, IRQ_GTM_MCS3_SR1_PRIO)
#elif IRQ_GTM_MCS3_SR1_CAT == IRQ_CAT23
ISR(GTMMCS3SR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS3_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS3_SR2_PRIO > 0) || (IRQ_GTM_MCS3_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS3_SR2_PRIO > 0) && (IRQ_GTM_MCS3_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS3SR2_ISR, 0, IRQ_GTM_MCS3_SR2_PRIO)
#elif IRQ_GTM_MCS3_SR2_CAT == IRQ_CAT23
ISR(GTMMCS3SR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS3_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif


#if((IRQ_GTM_MCS3_SR3_PRIO > 0) || (IRQ_GTM_MCS3_SR3_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS3_SR3_PRIO > 0) && (IRQ_GTM_MCS3_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS3SR3_ISR, 0, IRQ_GTM_MCS3_SR3_PRIO)
#elif IRQ_GTM_MCS3_SR3_CAT == IRQ_CAT23
ISR(GTMMCS3SR3_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS3_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS3_SR4_PRIO > 0) || (IRQ_GTM_MCS3_SR4_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS3_SR4_PRIO > 0) && (IRQ_GTM_MCS3_SR4_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS3SR4_ISR, 0, IRQ_GTM_MCS3_SR4_PRIO)
#elif IRQ_GTM_MCS3_SR4_CAT == IRQ_CAT23
ISR(GTMMCS3SR4_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS3_SR4_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS3_SR5_PRIO > 0) || (IRQ_GTM_MCS3_SR5_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS3_SR5_PRIO > 0) && (IRQ_GTM_MCS3_SR5_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS3SR5_ISR, 0, IRQ_GTM_MCS3_SR5_PRIO)
#elif IRQ_GTM_MCS3_SR5_CAT == IRQ_CAT23
ISR(GTMMCS3SR5_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS3_SR5_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS3_SR6_PRIO > 0) || (IRQ_GTM_MCS3_SR6_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS3_SR6_PRIO > 0) && (IRQ_GTM_MCS3_SR6_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS3SR6_ISR, 0, IRQ_GTM_MCS3_SR6_PRIO)
#elif IRQ_GTM_MCS3_SR6_CAT == IRQ_CAT23
ISR(GTMMCS3SR6_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS3_SR6_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS3_SR7_PRIO > 0) || (IRQ_GTM_MCS3_SR7_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS3_SR7_PRIO > 0) && (IRQ_GTM_MCS3_SR7_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS3SR7_ISR, 0, IRQ_GTM_MCS3_SR7_PRIO)
#elif IRQ_GTM_MCS3_SR7_CAT == IRQ_CAT23
ISR(GTMMCS3SR7_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS3_SR7_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#endif /* #if(IRQ_GTM_MCS3_EXIST == (STD_ON)) */


#if(IRQ_GTM_MCS4_EXIST == (STD_ON))
/****************** MCS4 *******************************************/

#if((IRQ_GTM_MCS4_SR0_PRIO > 0) || (IRQ_GTM_MCS4_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS4_SR0_PRIO > 0) && (IRQ_GTM_MCS4_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS4SR0_ISR, 0, IRQ_GTM_MCS4_SR0_PRIO)
#elif IRQ_GTM_MCS4_SR0_CAT == IRQ_CAT23
ISR(GTMMCS4SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS4_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS4_SR1_PRIO > 0) || (IRQ_GTM_MCS4_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS4_SR1_PRIO > 0) && (IRQ_GTM_MCS4_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS4SR1_ISR, 0, IRQ_GTM_MCS4_SR1_PRIO)
#elif IRQ_GTM_MCS4_SR1_CAT == IRQ_CAT23
ISR(GTMMCS4SR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS4_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS4_SR2_PRIO > 0) || (IRQ_GTM_MCS4_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS4_SR2_PRIO > 0) && (IRQ_GTM_MCS4_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS4SR2_ISR, 0, IRQ_GTM_MCS4_SR2_PRIO)
#elif IRQ_GTM_MCS4_SR2_CAT == IRQ_CAT23
ISR(GTMMCS4SR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS4_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif


#if((IRQ_GTM_MCS4_SR3_PRIO > 0) || (IRQ_GTM_MCS4_SR3_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS4_SR3_PRIO > 0) && (IRQ_GTM_MCS4_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS4SR3_ISR, 0, IRQ_GTM_MCS4_SR3_PRIO)
#elif IRQ_GTM_MCS4_SR3_CAT == IRQ_CAT23
ISR(GTMMCS4SR3_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS4_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS4_SR4_PRIO > 0) || (IRQ_GTM_MCS4_SR4_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS4_SR4_PRIO > 0) && (IRQ_GTM_MCS4_SR4_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS4SR4_ISR, 0, IRQ_GTM_MCS4_SR4_PRIO)
#elif IRQ_GTM_MCS4_SR4_CAT == IRQ_CAT23
ISR(GTMMCS4SR4_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS4_SR4_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS4_SR5_PRIO > 0) || (IRQ_GTM_MCS4_SR5_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS4_SR5_PRIO > 0) && (IRQ_GTM_MCS4_SR5_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS4SR5_ISR, 0, IRQ_GTM_MCS4_SR5_PRIO)
#elif IRQ_GTM_MCS4_SR5_CAT == IRQ_CAT23
ISR(GTMMCS4SR5_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS4_SR5_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS4_SR6_PRIO > 0) || (IRQ_GTM_MCS4_SR6_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS4_SR6_PRIO > 0) && (IRQ_GTM_MCS4_SR6_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS4SR6_ISR, 0, IRQ_GTM_MCS4_SR6_PRIO)
#elif IRQ_GTM_MCS4_SR6_CAT == IRQ_CAT23
ISR(GTMMCS4SR6_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS4_SR6_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS4_SR7_PRIO > 0) || (IRQ_GTM_MCS4_SR7_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS4_SR7_PRIO > 0) && (IRQ_GTM_MCS4_SR7_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS4SR7_ISR, 0, IRQ_GTM_MCS4_SR7_PRIO)
#elif IRQ_GTM_MCS4_SR7_CAT == IRQ_CAT23
ISR(GTMMCS4SR7_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS4_SR7_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#endif /* #if(IRQ_GTM_MCS4_EXIST == (STD_ON)) */


#if(IRQ_GTM_MCS5_EXIST == (STD_ON))
/****************** MCS5 *******************************************/

#if((IRQ_GTM_MCS5_SR0_PRIO > 0) || (IRQ_GTM_MCS5_SR0_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS5_SR0_PRIO > 0) && (IRQ_GTM_MCS5_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS5SR0_ISR, 0, IRQ_GTM_MCS5_SR0_PRIO)
#elif IRQ_GTM_MCS5_SR0_CAT == IRQ_CAT23
ISR(GTMMCS5SR0_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS5_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS5_SR1_PRIO > 0) || (IRQ_GTM_MCS5_SR1_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS5_SR1_PRIO > 0) && (IRQ_GTM_MCS5_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS5SR1_ISR, 0, IRQ_GTM_MCS5_SR1_PRIO)
#elif IRQ_GTM_MCS5_SR1_CAT == IRQ_CAT23
ISR(GTMMCS5SR1_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS5_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS5_SR2_PRIO > 0) || (IRQ_GTM_MCS5_SR2_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS5_SR2_PRIO > 0) && (IRQ_GTM_MCS5_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS5SR2_ISR, 0, IRQ_GTM_MCS5_SR2_PRIO)
#elif IRQ_GTM_MCS5_SR2_CAT == IRQ_CAT23
ISR(GTMMCS5SR2_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS5_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif


#if((IRQ_GTM_MCS5_SR3_PRIO > 0) || (IRQ_GTM_MCS5_SR3_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS5_SR3_PRIO > 0) && (IRQ_GTM_MCS5_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS5SR3_ISR, 0, IRQ_GTM_MCS5_SR3_PRIO)
#elif IRQ_GTM_MCS5_SR3_CAT == IRQ_CAT23
ISR(GTMMCS5SR3_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS5_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS5_SR4_PRIO > 0) || (IRQ_GTM_MCS5_SR4_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS5_SR4_PRIO > 0) && (IRQ_GTM_MCS5_SR4_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS5SR4_ISR, 0, IRQ_GTM_MCS5_SR4_PRIO)
#elif IRQ_GTM_MCS5_SR4_CAT == IRQ_CAT23
ISR(GTMMCS5SR4_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS5_SR4_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS5_SR5_PRIO > 0) || (IRQ_GTM_MCS5_SR5_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS5_SR5_PRIO > 0) && (IRQ_GTM_MCS5_SR5_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS5SR5_ISR, 0, IRQ_GTM_MCS5_SR5_PRIO)
#elif IRQ_GTM_MCS5_SR5_CAT == IRQ_CAT23
ISR(GTMMCS5SR5_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS5_SR5_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS5_SR6_PRIO > 0) || (IRQ_GTM_MCS5_SR6_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS5_SR6_PRIO > 0) && (IRQ_GTM_MCS5_SR6_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS5SR6_ISR, 0, IRQ_GTM_MCS5_SR6_PRIO)
#elif IRQ_GTM_MCS5_SR6_CAT == IRQ_CAT23
ISR(GTMMCS5SR6_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS5_SR6_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#if((IRQ_GTM_MCS5_SR7_PRIO > 0) || (IRQ_GTM_MCS5_SR7_CAT == IRQ_CAT23))
#if((IRQ_GTM_MCS5_SR7_PRIO > 0) && (IRQ_GTM_MCS5_SR7_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMMCS5SR7_ISR, 0, IRQ_GTM_MCS5_SR7_PRIO)
#elif IRQ_GTM_MCS5_SR7_CAT == IRQ_CAT23
ISR(GTMMCS5SR7_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_MCS5_SR7_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#endif /* #if(IRQ_GTM_MCS5_EXIST == (STD_ON)) */

#if((IRQ_GTM_ERR_SR_PRIO > 0) || (IRQ_GTM_ERR_SR_CAT == IRQ_CAT23))
#if((IRQ_GTM_ERR_SR_PRIO > 0) && (IRQ_GTM_ERR_SR_CAT == IRQ_CAT1))
IFX_INTERRUPT(GTMERRSR_ISR, 0, IRQ_GTM_ERR_SR_PRIO)
#elif IRQ_GTM_ERR_SR_CAT == IRQ_CAT23
ISR(GTMERRSR_ISR)
#endif
{
  /* Enable Global Interrupts */
#if (IRQ_GTM_ERR_SR_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

}
#endif

#endif /* #if (IRQ_GTM_EXIST == (STD_ON)) */

#define IRQ_STOP_SEC_CODE
#include "MemMap.h"

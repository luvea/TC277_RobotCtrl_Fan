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
**  $FILENAME   : Can_Irq.c $                                                **
**                                                                           **
**  $CC VERSION : \main\dev_tc2xx_ca\5 $                                     **
**                                                                           **
**  $DATE       : 2016-06-27 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains CAN Module interrupt frames             **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Can_17_MCanP.h"
#include "Std_Types.h"
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
/******************************************************************************
** Syntax : void CANSR0_ISR(void)                                          **
**                                                                           **
** Service ID: NA                                                            **
**                                                                           **
** Sync/Async: Synchronous                                                   **
**                                                                           **
** Reentrancy: Reentrant                                                     **
**                                                                           **
** Parameters (in): None                                                     **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value: None                                                        **
**                                                                           **
** Description : Service for CAN Controller 0 Transmission event                   **
**                                                                           **
******************************************************************************/
#if (IRQ_CAN0_EXIST == STD_ON)
#if((IRQ_CAN_SR0_PRIO > 0) || (IRQ_CAN_SR0_CAT == IRQ_CAT23))
#if((IRQ_CAN_SR0_PRIO > 0) && (IRQ_CAN_SR0_CAT == IRQ_CAT1))
IFX_INTERRUPT(CANSR0_ISR, 0, IRQ_CAN_SR0_PRIO)
#elif IRQ_CAN_SR0_CAT == IRQ_CAT23
ISR(CANSR0_ISR)
#endif
{
#if (IRQ_CAN_SR0_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  #ifdef CAN_TX_PROCESSING_HWCONTROLLER0
  #if (CAN_TX_PROCESSING_HWCONTROLLER0 == CAN_INTERRUPT)
  Can_17_MCanP_IsrTransmitHandler(CAN_HWCONTROLLER0);
  #endif
  #endif
}
#endif
#endif

/******************************************************************************
** Syntax : void CANSR1_ISR(void)                                          **
**                                                                           **
** Service ID: NA                                                            **
**                                                                           **
** Sync/Async: Synchronous                                                   **
**                                                                           **
** Reentrancy: Reentrant                                                     **
**                                                                           **
** Parameters (in): None                                                     **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value: None                                                        **
**                                                                           **
** Description : Service for CAN Controller 1 Transmission event                   **
**                                                                           **
******************************************************************************/
#if (IRQ_CAN1_EXIST == STD_ON)
#if((IRQ_CAN_SR1_PRIO > 0) || (IRQ_CAN_SR1_CAT == IRQ_CAT23))
#if((IRQ_CAN_SR1_PRIO > 0) && (IRQ_CAN_SR1_CAT == IRQ_CAT1))
IFX_INTERRUPT(CANSR1_ISR, 0, IRQ_CAN_SR1_PRIO)
#elif IRQ_CAN_SR1_CAT == IRQ_CAT23
ISR(CANSR1_ISR)
#endif
{
#if (IRQ_CAN_SR1_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  #ifdef CAN_TX_PROCESSING_HWCONTROLLER1
 #if (CAN_TX_PROCESSING_HWCONTROLLER1 == CAN_INTERRUPT)
  Can_17_MCanP_IsrTransmitHandler(CAN_HWCONTROLLER1);
  #endif
  #endif
}
#endif
#endif

/******************************************************************************
** Syntax : void CANSR2_ISR(void)                                          **
**                                                                           **
** Service ID: NA                                                            **
**                                                                           **
** Sync/Async: Synchronous                                                   **
**                                                                           **
** Reentrancy: Reentrant                                                     **
**                                                                           **
** Parameters (in): None                                                     **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value: None                                                        **
**                                                                           **
** Description : Service for CAN Controller 2 Transmission event                   **
**                                                                           **
******************************************************************************/
#if (IRQ_CAN2_EXIST == STD_ON)
#if((IRQ_CAN_SR2_PRIO > 0) || (IRQ_CAN_SR2_CAT == IRQ_CAT23))
#if((IRQ_CAN_SR2_PRIO > 0) && (IRQ_CAN_SR2_CAT == IRQ_CAT1))
IFX_INTERRUPT(CANSR2_ISR, 0, IRQ_CAN_SR2_PRIO)
#elif IRQ_CAN_SR2_CAT == IRQ_CAT23
ISR(CANSR2_ISR)
#endif
{
#if (IRQ_CAN_SR2_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  #ifdef CAN_TX_PROCESSING_HWCONTROLLER2
  #if (CAN_TX_PROCESSING_HWCONTROLLER2 == CAN_INTERRUPT)
  Can_17_MCanP_IsrTransmitHandler(CAN_HWCONTROLLER2);
  #endif
  #endif
}
#endif
#endif

/******************************************************************************
** Syntax : void CANSR3_ISR(void)                                          **
**                                                                           **
** Service ID: NA                                                            **
**                                                                           **
** Sync/Async: Synchronous                                                   **
**                                                                           **
** Reentrancy: Reentrant                                                     **
**                                                                           **
** Parameters (in): None                                                     **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value: None                                                        **
**                                                                           **
** Description : Service for CAN Controller 3 Transmission event                   **
**                                                                           **
******************************************************************************/
#if (IRQ_CAN3_EXIST == STD_ON)
#if((IRQ_CAN_SR3_PRIO > 0) || (IRQ_CAN_SR3_CAT == IRQ_CAT23))
#if((IRQ_CAN_SR3_PRIO > 0) && (IRQ_CAN_SR3_CAT == IRQ_CAT1))
IFX_INTERRUPT(CANSR3_ISR, 0, IRQ_CAN_SR3_PRIO)
#elif IRQ_CAN_SR3_CAT == IRQ_CAT23
ISR(CANSR3_ISR)
#endif
{
#if (IRQ_CAN_SR3_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  #ifdef CAN_TX_PROCESSING_HWCONTROLLER3
  #if (CAN_TX_PROCESSING_HWCONTROLLER3 == CAN_INTERRUPT)
  Can_17_MCanP_IsrTransmitHandler(CAN_HWCONTROLLER3);
  #endif
  #endif
}
#endif
#endif

/******************************************************************************
** Syntax : void CANSR4_ISR(void)                                          **
**                                                                           **
** Service ID: NA                                                            **
**                                                                           **
** Sync/Async: Synchronous                                                   **
**                                                                           **
** Reentrancy: Reentrant                                                     **
**                                                                           **
** Parameters (in): None                                                     **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value: None                                                        **
**                                                                           **
** Description : Service for CAN Controller 0 Reception/Wakeup event         **
**                                                                           **
******************************************************************************/
#if (IRQ_CAN4_EXIST == STD_ON)
#if((IRQ_CAN_SR4_PRIO > 0) || (IRQ_CAN_SR4_CAT == IRQ_CAT23))
#if((IRQ_CAN_SR4_PRIO > 0) && (IRQ_CAN_SR4_CAT == IRQ_CAT1))
IFX_INTERRUPT(CANSR4_ISR, 0, IRQ_CAN_SR4_PRIO)
#elif IRQ_CAN_SR4_CAT == IRQ_CAT23
ISR(CANSR4_ISR)
#endif
{
#if (IRQ_CAN_SR4_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  #ifdef CAN_RX_PROCESSING_HWCONTROLLER0
  #if (CAN_RX_PROCESSING_HWCONTROLLER0 == CAN_INTERRUPT)
  Can_17_MCanP_IsrReceiveHandler(CAN_HWCONTROLLER0);
  #endif
  #endif
}
#endif
#endif

/******************************************************************************
** Syntax : void CANSR5_ISR(void)                                          **
**                                                                           **
** Service ID: NA                                                            **
**                                                                           **
** Sync/Async: Synchronous                                                   **
**                                                                           **
** Reentrancy: Reentrant                                                     **
**                                                                           **
** Parameters (in): None                                                     **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value: None                                                        **
**                                                                           **
** Description : Service for CAN Controller 1 Reception/Wakeup event         **
**                                                                           **
******************************************************************************/
#if (IRQ_CAN5_EXIST == STD_ON)
#if((IRQ_CAN_SR5_PRIO > 0) || (IRQ_CAN_SR5_CAT == IRQ_CAT23))
#if((IRQ_CAN_SR5_PRIO > 0) && (IRQ_CAN_SR5_CAT == IRQ_CAT1))
IFX_INTERRUPT(CANSR5_ISR, 0, IRQ_CAN_SR5_PRIO)
#elif IRQ_CAN_SR5_CAT == IRQ_CAT23
ISR(CANSR5_ISR)
#endif
{
#if (IRQ_CAN_SR5_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  #ifdef CAN_RX_PROCESSING_HWCONTROLLER1
  #if (CAN_RX_PROCESSING_HWCONTROLLER1 == CAN_INTERRUPT)
  Can_17_MCanP_IsrReceiveHandler(CAN_HWCONTROLLER1);
  #endif
  #endif
}
#endif
#endif

/******************************************************************************
** Syntax : void CANSR6_ISR(void)                                          **
**                                                                           **
** Service ID: NA                                                            **
**                                                                           **
** Sync/Async: Synchronous                                                   **
**                                                                           **
** Reentrancy: Reentrant                                                     **
**                                                                           **
** Parameters (in): None                                                     **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value: None                                                        **
**                                                                           **
** Description : Service for CAN Controller 2 Reception/Wakeup event         **
**                                                                           **
******************************************************************************/
#if (IRQ_CAN6_EXIST == STD_ON)
#if((IRQ_CAN_SR6_PRIO > 0) || (IRQ_CAN_SR6_CAT == IRQ_CAT23))
#if((IRQ_CAN_SR6_PRIO > 0) && (IRQ_CAN_SR6_CAT == IRQ_CAT1))
IFX_INTERRUPT(CANSR6_ISR, 0, IRQ_CAN_SR6_PRIO)
#elif IRQ_CAN_SR6_CAT == IRQ_CAT23
ISR(CANSR6_ISR)
#endif
{
#if (IRQ_CAN_SR6_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  #ifdef CAN_RX_PROCESSING_HWCONTROLLER2
  #if (CAN_RX_PROCESSING_HWCONTROLLER2 == CAN_INTERRUPT)
  Can_17_MCanP_IsrReceiveHandler(CAN_HWCONTROLLER2);
  #endif
  #endif
}
#endif
#endif

/******************************************************************************
** Syntax : void CANSR7_ISR(void)                                          **
**                                                                           **
** Service ID: NA                                                            **
**                                                                           **
** Sync/Async: Synchronous                                                   **
**                                                                           **
** Reentrancy: Reentrant                                                     **
**                                                                           **
** Parameters (in): None                                                     **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value: None                                                        **
**                                                                           **
** Description : Service for CAN Controller 3 Reception/Wakeup event         **
**                                                                           **
******************************************************************************/
#if (IRQ_CAN7_EXIST == STD_ON)
#if((IRQ_CAN_SR7_PRIO > 0) || (IRQ_CAN_SR7_CAT == IRQ_CAT23))
#if((IRQ_CAN_SR7_PRIO > 0) && (IRQ_CAN_SR7_CAT == IRQ_CAT1))
IFX_INTERRUPT(CANSR7_ISR, 0, IRQ_CAN_SR7_PRIO)
#elif IRQ_CAN_SR7_CAT == IRQ_CAT23
ISR(CANSR7_ISR)
#endif
{
#if (IRQ_CAN_SR7_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  #ifdef CAN_RX_PROCESSING_HWCONTROLLER3
  #if (CAN_RX_PROCESSING_HWCONTROLLER3 == CAN_INTERRUPT)
  Can_17_MCanP_IsrReceiveHandler(CAN_HWCONTROLLER3);
  #endif
  #endif
}
#endif
#endif

/******************************************************************************
** Syntax : void CANSR8_ISR(void)                                          **
**                                                                           **
** Service ID: NA                                                            **
**                                                                           **
** Sync/Async: Synchronous                                                   **
**                                                                           **
** Reentrancy: Reentrant                                                     **
**                                                                           **
** Parameters (in): None                                                     **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value: None                                                        **
**                                                                           **
** Description : Service for CAN Controller 0 Busoff event             **
**                                                                           **
******************************************************************************/
#if (IRQ_CAN8_EXIST == STD_ON)
#if((IRQ_CAN_SR8_PRIO > 0) || (IRQ_CAN_SR8_CAT == IRQ_CAT23))
#if((IRQ_CAN_SR8_PRIO > 0) && (IRQ_CAN_SR8_CAT == IRQ_CAT1))
IFX_INTERRUPT(CANSR8_ISR, 0, IRQ_CAN_SR8_PRIO)
#elif IRQ_CAN_SR8_CAT == IRQ_CAT23
ISR(CANSR8_ISR)
#endif
{
#if (IRQ_CAN_SR8_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  #ifdef CAN_BO_PROCESSING_HWCONTROLLER0
  #if (CAN_BO_PROCESSING_HWCONTROLLER0 == CAN_INTERRUPT)
  Can_17_MCanP_IsrBusOffHandler(CAN_HWCONTROLLER0);
  #endif
  #endif
}
#endif
#endif

/******************************************************************************
** Syntax : void CANSR9_ISR(void)                                          **
**                                                                           **
** Service ID: NA                                                            **
**                                                                           **
** Sync/Async: Synchronous                                                   **
**                                                                           **
** Reentrancy: Reentrant                                                     **
**                                                                           **
** Parameters (in): None                                                     **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value: None                                                        **
**                                                                           **
** Description : Service for CAN Controller 1 Busoff event             **
**                                                                           **
******************************************************************************/
#if (IRQ_CAN9_EXIST == STD_ON)
#if((IRQ_CAN_SR9_PRIO > 0) || (IRQ_CAN_SR9_CAT == IRQ_CAT23))
#if((IRQ_CAN_SR9_PRIO > 0) && (IRQ_CAN_SR9_CAT == IRQ_CAT1))
IFX_INTERRUPT(CANSR9_ISR, 0, IRQ_CAN_SR9_PRIO)
#elif IRQ_CAN_SR9_CAT == IRQ_CAT23
ISR(CANSR9_ISR)
#endif
{
#if (IRQ_CAN_SR9_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  #ifdef CAN_BO_PROCESSING_HWCONTROLLER1
  #if (CAN_BO_PROCESSING_HWCONTROLLER1 == CAN_INTERRUPT)
  Can_17_MCanP_IsrBusOffHandler(CAN_HWCONTROLLER1);
  #endif
  #endif
}
#endif
#endif

/******************************************************************************
** Syntax : void CANSR10_ISR(void)                                         **
**                                                                           **
** Service ID: NA                                                            **
**                                                                           **
** Sync/Async: Synchronous                                                   **
**                                                                           **
** Reentrancy: Reentrant                                                     **
**                                                                           **
** Parameters (in): None                                                     **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value: None                                                        **
**                                                                           **
** Description : Service for CAN Controller 2 Busoff event             **
**                                                                           **
******************************************************************************/
#if (IRQ_CAN10_EXIST == STD_ON)
#if((IRQ_CAN_SR10_PRIO > 0) || (IRQ_CAN_SR10_CAT == IRQ_CAT23))
#if((IRQ_CAN_SR10_PRIO > 0) && (IRQ_CAN_SR10_CAT == IRQ_CAT1))
IFX_INTERRUPT(CANSR10_ISR, 0, IRQ_CAN_SR10_PRIO)
#elif IRQ_CAN_SR10_CAT == IRQ_CAT23
ISR(CANSR10_ISR)
#endif
{
#if (IRQ_CAN_SR10_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  #ifdef CAN_BO_PROCESSING_HWCONTROLLER2
  #if (CAN_BO_PROCESSING_HWCONTROLLER2 == CAN_INTERRUPT)
  Can_17_MCanP_IsrBusOffHandler(CAN_HWCONTROLLER2);
  #endif
  #endif
}
#endif
#endif

/******************************************************************************
** Syntax : void CANSR11_ISR(void)                                         **
**                                                                           **
** Service ID: NA                                                            **
**                                                                           **
** Sync/Async: Synchronous                                                   **
**                                                                           **
** Reentrancy: Reentrant                                                     **
**                                                                           **
** Parameters (in): None                                                     **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value: None                                                        **
**                                                                           **
** Description : Service for CAN Controller 3 Busoff event             **
**                                                                           **
******************************************************************************/
#if (IRQ_CAN11_EXIST == STD_ON)
#if((IRQ_CAN_SR11_PRIO > 0) || (IRQ_CAN_SR11_CAT == IRQ_CAT23))
#if((IRQ_CAN_SR11_PRIO > 0) && (IRQ_CAN_SR11_CAT == IRQ_CAT1))
IFX_INTERRUPT(CANSR11_ISR, 0, IRQ_CAN_SR11_PRIO)
#elif IRQ_CAN_SR11_CAT == IRQ_CAT23
ISR(CANSR11_ISR)
#endif
{
#if (IRQ_CAN_SR11_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  #ifdef CAN_BO_PROCESSING_HWCONTROLLER3
  #if (CAN_BO_PROCESSING_HWCONTROLLER3 == CAN_INTERRUPT)
  Can_17_MCanP_IsrBusOffHandler(CAN_HWCONTROLLER3);
  #endif
  #endif
}
#endif
#endif

/******************************************************************************
** Syntax : void CANSR16_ISR(void)                                          **
**                                                                           **
** Service ID: NA                                                            **
**                                                                           **
** Sync/Async: Synchronous                                                   **
**                                                                           **
** Reentrancy: Reentrant                                                     **
**                                                                           **
** Parameters (in): None                                                     **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value: None                                                        **
**                                                                           **
** Description : Service for CAN Controller 4 Transmission event                   **
**                                                                           **
******************************************************************************/
#if (IRQ_CAN16_EXIST == STD_ON)
#if((IRQ_CAN_SR16_PRIO > 0) || (IRQ_CAN_SR16_CAT == IRQ_CAT23))
#if((IRQ_CAN_SR16_PRIO > 0) && (IRQ_CAN_SR16_CAT == IRQ_CAT1))
IFX_INTERRUPT(CANSR16_ISR, 0, IRQ_CAN_SR16_PRIO)
#elif IRQ_CAN_SR16_CAT == IRQ_CAT23
ISR(CANSR16_ISR)
#endif
{
#if (IRQ_CAN_SR16_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  #ifdef CAN_TX_PROCESSING_HWCONTROLLER4
  #if (CAN_TX_PROCESSING_HWCONTROLLER4 == CAN_INTERRUPT)
  Can_17_MCanP_IsrTransmitHandler(CAN_HWCONTROLLER4);
  #endif
  #endif
}
#endif
#endif

/******************************************************************************
** Syntax : void CANSR17_ISR(void)                                          **
**                                                                           **
** Service ID: NA                                                            **
**                                                                           **
** Sync/Async: Synchronous                                                   **
**                                                                           **
** Reentrancy: Reentrant                                                     **
**                                                                           **
** Parameters (in): None                                                     **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value: None                                                        **
**                                                                           **
** Description : Service for CAN Controller 5 Transmission event                   **
**                                                                           **
******************************************************************************/
#if (IRQ_CAN17_EXIST == STD_ON)
#if((IRQ_CAN_SR17_PRIO > 0) || (IRQ_CAN_SR17_CAT == IRQ_CAT23))
#if((IRQ_CAN_SR17_PRIO > 0) && (IRQ_CAN_SR17_CAT == IRQ_CAT1))
IFX_INTERRUPT(CANSR17_ISR, 0, IRQ_CAN_SR17_PRIO)
#elif IRQ_CAN_SR17_CAT == IRQ_CAT23
ISR(CANSR17_ISR)
#endif
{
#if (IRQ_CAN_SR17_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  #ifdef CAN_TX_PROCESSING_HWCONTROLLER5
  #if (CAN_TX_PROCESSING_HWCONTROLLER5 == CAN_INTERRUPT)
  Can_17_MCanP_IsrTransmitHandler(CAN_HWCONTROLLER5);
  #endif
  #endif
}
#endif
#endif

/******************************************************************************
** Syntax : void CANSR18_ISR(void)                                          **
**                                                                           **
** Service ID: NA                                                            **
**                                                                           **
** Sync/Async: Synchronous                                                   **
**                                                                           **
** Reentrancy: Reentrant                                                     **
**                                                                           **
** Parameters (in): None                                                     **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value: None                                                        **
**                                                                           **
** Description : Service for CAN Controller 4 Reception/Wakeup event         **
**                                                                           **
******************************************************************************/
#if (IRQ_CAN18_EXIST == STD_ON)
#if((IRQ_CAN_SR18_PRIO > 0) || (IRQ_CAN_SR18_CAT == IRQ_CAT23))
#if((IRQ_CAN_SR18_PRIO > 0) && (IRQ_CAN_SR18_CAT == IRQ_CAT1))
IFX_INTERRUPT(CANSR18_ISR, 0, IRQ_CAN_SR18_PRIO)
#elif IRQ_CAN_SR18_CAT == IRQ_CAT23
ISR(CANSR18_ISR)
#endif
{
#if (IRQ_CAN_SR18_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  #ifdef CAN_RX_PROCESSING_HWCONTROLLER4
  #if (CAN_RX_PROCESSING_HWCONTROLLER4 == CAN_INTERRUPT)
  Can_17_MCanP_IsrReceiveHandler(CAN_HWCONTROLLER4);
  #endif
  #endif
}
#endif
#endif

/******************************************************************************
** Syntax : void CANSR19_ISR(void)                                          **
**                                                                           **
** Service ID: NA                                                            **
**                                                                           **
** Sync/Async: Synchronous                                                   **
**                                                                           **
** Reentrancy: Reentrant                                                     **
**                                                                           **
** Parameters (in): None                                                     **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value: None                                                        **
**                                                                           **
** Description : Service for CAN Controller 5 Reception/Wakeup event         **
**                                                                           **
******************************************************************************/
#if (IRQ_CAN19_EXIST == STD_ON)
#if((IRQ_CAN_SR19_PRIO > 0) || (IRQ_CAN_SR19_CAT == IRQ_CAT23))
#if((IRQ_CAN_SR19_PRIO > 0) && (IRQ_CAN_SR19_CAT == IRQ_CAT1))
IFX_INTERRUPT(CANSR19_ISR, 0, IRQ_CAN_SR19_PRIO)
#elif IRQ_CAN_SR19_CAT == IRQ_CAT23
ISR(CANSR19_ISR)
#endif
{
#if (IRQ_CAN_SR19_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  #ifdef CAN_RX_PROCESSING_HWCONTROLLER5
  #if (CAN_RX_PROCESSING_HWCONTROLLER5 == CAN_INTERRUPT)
  Can_17_MCanP_IsrReceiveHandler(CAN_HWCONTROLLER5);
  #endif
  #endif
}
#endif
#endif

/******************************************************************************
** Syntax : void CANSR20_ISR(void)                                          **
**                                                                           **
** Service ID: NA                                                            **
**                                                                           **
** Sync/Async: Synchronous                                                   **
**                                                                           **
** Reentrancy: Reentrant                                                     **
**                                                                           **
** Parameters (in): None                                                     **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value: None                                                        **
**                                                                           **
** Description : Service for CAN Controller 4 Busoff event             **
**                                                                           **
******************************************************************************/
#if (IRQ_CAN20_EXIST == STD_ON)
#if((IRQ_CAN_SR20_PRIO > 0) || (IRQ_CAN_SR20_CAT == IRQ_CAT23))
#if((IRQ_CAN_SR20_PRIO > 0) && (IRQ_CAN_SR20_CAT == IRQ_CAT1))
IFX_INTERRUPT(CANSR20_ISR, 0, IRQ_CAN_SR20_PRIO)
#elif IRQ_CAN_SR20_CAT == IRQ_CAT23
ISR(CANSR20_ISR)
#endif
{
#if (IRQ_CAN_SR20_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  #ifdef CAN_BO_PROCESSING_HWCONTROLLER4
  #if (CAN_BO_PROCESSING_HWCONTROLLER4 == CAN_INTERRUPT)
  Can_17_MCanP_IsrBusOffHandler(CAN_HWCONTROLLER4);
  #endif
  #endif
}
#endif
#endif

/******************************************************************************
** Syntax : void CANSR21_ISR(void)                                          **
**                                                                           **
** Service ID: NA                                                            **
**                                                                           **
** Sync/Async: Synchronous                                                   **
**                                                                           **
** Reentrancy: Reentrant                                                     **
**                                                                           **
** Parameters (in): None                                                     **
**                                                                           **
** Parameters (out): None                                                    **
**                                                                           **
** Return value: None                                                        **
**                                                                           **
** Description : Service for CAN Controller 5 Busoff event             **
**                                                                           **
******************************************************************************/
#if (IRQ_CAN21_EXIST == STD_ON)
#if((IRQ_CAN_SR21_PRIO > 0) || (IRQ_CAN_SR21_CAT == IRQ_CAT23))
#if((IRQ_CAN_SR21_PRIO > 0) && (IRQ_CAN_SR21_CAT == IRQ_CAT1))
IFX_INTERRUPT(CANSR21_ISR, 0, IRQ_CAN_SR21_PRIO)
#elif IRQ_CAN_SR21_CAT == IRQ_CAT23
ISR(CANSR21_ISR)
#endif
{
#if (IRQ_CAN_SR21_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  #ifdef CAN_BO_PROCESSING_HWCONTROLLER5
  #if (CAN_BO_PROCESSING_HWCONTROLLER5 == CAN_INTERRUPT)
  Can_17_MCanP_IsrBusOffHandler(CAN_HWCONTROLLER5);
  #endif
  #endif
}
#endif
#endif

#define IRQ_STOP_SEC_CODE
#include "MemMap.h"


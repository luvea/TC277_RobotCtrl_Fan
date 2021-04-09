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
**  $FILENAME   : AscLin_Irq.c $                                             **
**                                                                           **
**  $CC VERSION : \main\14 $                                                 **
**                                                                           **
**  $DATE       : 2016-06-27 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains the ISRs for ASCLIN MCAL drivers        **
**                This file is given for evaluation purpose only             **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"
/* Inclusion of Tasking sfr file */
/* MCAL driver utility functions for setting interrupt priority initialization 
    and interrupt category */
#include "Irq.h"
/* Global functions like Set/Reset END INIT protection bit, 
  Enable/Disable interrupts, Automic write function */
#include "Mcal.h"

#if (IFX_SAFETLIB_USED == STD_ON)
#include "SafeWdgIf_Cfg.h"
#ifdef SWDG_EXT_CIC_WDG_ONLY
/* Call IsrRx when CIC receive interrupt occurs  */
extern void   SafeWdgAscLin_IsrRx         (void);
#endif
#endif

#if ((defined(IRQ_ASCLIN3_EXIST)) &&(IRQ_ASCLIN3_EXIST == STD_ON))
#if ((IRQ_ASCLIN_CHANNEL0_USED == IRQ_ASCLIN_USED_MCALSTDLIN) || \
     (IRQ_ASCLIN_CHANNEL1_USED == IRQ_ASCLIN_USED_MCALSTDLIN) || \
     (IRQ_ASCLIN_CHANNEL2_USED == IRQ_ASCLIN_USED_MCALSTDLIN) || \
     (IRQ_ASCLIN_CHANNEL3_USED == IRQ_ASCLIN_USED_MCALSTDLIN))
#include "StdLin.h"
#include "StdLin_Hal.h"
#endif
#if ((IRQ_ASCLIN_CHANNEL0_USED == IRQ_ASCLIN_USED_MCALLIN) || \
     (IRQ_ASCLIN_CHANNEL1_USED == IRQ_ASCLIN_USED_MCALLIN) || \
     (IRQ_ASCLIN_CHANNEL2_USED == IRQ_ASCLIN_USED_MCALLIN) || \
     (IRQ_ASCLIN_CHANNEL3_USED == IRQ_ASCLIN_USED_MCALLIN))
#include "Lin_17_AscLin.h"
#endif
#if ((IRQ_ASCLIN_CHANNEL0_USED == IRQ_ASCLIN_USED_MCALUART) || \
     (IRQ_ASCLIN_CHANNEL1_USED == IRQ_ASCLIN_USED_MCALUART) || \
     (IRQ_ASCLIN_CHANNEL2_USED == IRQ_ASCLIN_USED_MCALUART) || \
     (IRQ_ASCLIN_CHANNEL3_USED == IRQ_ASCLIN_USED_MCALUART))
#include "Uart.h"
#endif

#elif ((defined(IRQ_ASCLIN2_EXIST)) &&(IRQ_ASCLIN2_EXIST == STD_ON))
#if ((IRQ_ASCLIN_CHANNEL0_USED == IRQ_ASCLIN_USED_MCALSTDLIN) || \
     (IRQ_ASCLIN_CHANNEL1_USED == IRQ_ASCLIN_USED_MCALSTDLIN) || \
     (IRQ_ASCLIN_CHANNEL2_USED == IRQ_ASCLIN_USED_MCALSTDLIN))
#include "StdLin.h"
#include "StdLin_Hal.h"
#endif
#if ((IRQ_ASCLIN_CHANNEL0_USED == IRQ_ASCLIN_USED_MCALLIN) || \
     (IRQ_ASCLIN_CHANNEL1_USED == IRQ_ASCLIN_USED_MCALLIN) || \
     (IRQ_ASCLIN_CHANNEL2_USED == IRQ_ASCLIN_USED_MCALLIN))
#include "Lin_17_AscLin.h"
#endif
#if ((IRQ_ASCLIN_CHANNEL0_USED == IRQ_ASCLIN_USED_MCALUART) || \
     (IRQ_ASCLIN_CHANNEL1_USED == IRQ_ASCLIN_USED_MCALUART) || \
     (IRQ_ASCLIN_CHANNEL2_USED == IRQ_ASCLIN_USED_MCALUART))
#include "Uart.h"
#endif

#else
#if ((IRQ_ASCLIN_CHANNEL0_USED == IRQ_ASCLIN_USED_MCALSTDLIN) || \
     (IRQ_ASCLIN_CHANNEL1_USED == IRQ_ASCLIN_USED_MCALSTDLIN))
#include "StdLin.h"
#include "StdLin_Hal.h"
#endif
#if ((IRQ_ASCLIN_CHANNEL0_USED == IRQ_ASCLIN_USED_MCALLIN) || \
     (IRQ_ASCLIN_CHANNEL1_USED == IRQ_ASCLIN_USED_MCALLIN))
#include "Lin_17_AscLin.h"
#endif
#if ((IRQ_ASCLIN_CHANNEL0_USED == IRQ_ASCLIN_USED_MCALUART) || \
     (IRQ_ASCLIN_CHANNEL1_USED == IRQ_ASCLIN_USED_MCALUART))
#include "Uart.h"
#endif
#endif

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
#if (IFX_MCAL_USED == STD_ON)
#define IRQ_START_SEC_CODE
#include "MemMap.h"
#else
#define IFX_IRQ_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
#endif
/******************************************************************************
** Syntax : void ASCLINxTX_ISR(void)                                        **
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
** Description : Service for Transmit interrupt of ASCLINx                   **
**                                                                           **
*****************************************************************************/
/* This node is for ASCLINx_TX */
#if((IRQ_ASCLIN0_TX_PRIO > 0) || (IRQ_ASCLIN0_TX_CAT == IRQ_CAT23))
#if((IRQ_ASCLIN0_TX_PRIO > 0) && (IRQ_ASCLIN0_TX_CAT == IRQ_CAT1))
IFX_INTERRUPT(ASCLIN0TX_ISR, 0, IRQ_ASCLIN0_TX_PRIO)
#elif IRQ_ASCLIN0_TX_CAT == IRQ_CAT23
ISR(ASCLIN0TX_ISR)
#endif
{

  /* Enable Global Interrupts */
#if (IRQ_ASCLIN0_TX_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

#if (IRQ_ASCLIN_CHANNEL0_USED == IRQ_ASCLIN_USED_MCALLIN)
#if ((defined(LIN_ASCLIN0_USED)) && (LIN_ASCLIN0_USED == STD_ON))
  /* Call TX Interrupt funtion*/                                              
  Lin_17_AscLin_IsrTransmit(LIN_ASCLIN0);
#endif/*(LIN_ASCLINx_USED == STD_ON)*/
#endif/*#if (IRQ_ASCLIN_CHANNEL0_USED == IRQ_ASCLIN_USED_MCALLIN)*/

#if (IRQ_ASCLIN_CHANNEL0_USED == IRQ_ASCLIN_USED_MCALUART)
#if ((defined(UART_ASCLIN0_USED)) && (UART_ASCLIN0_USED == STD_ON))
  /* Call TX Interrupt funtion*/                                              
  Uart_IsrTransmit( UART_ASCLIN0);
#endif/*( UART_ASCLINx_USED == STD_ON)*/
#endif
#if (IRQ_ASCLIN_CHANNEL0_USED == IRQ_ASCLIN_USED_MCALSTDLIN)
  /* Complex STDLIN driver usage */
  StdLin_IsrTransmit(0U);
#endif/*#if (IRQ_ASCLIN_CHANNEL0_USED == IRQ_ASCLIN_USED_MCALLIN)*/
}
#endif
//edit by Guan
uint8 TestUartISRCnt;
uint8 TestUartRXISRCnt;
uint8 TestUartEXISRCnt;

#if((IRQ_ASCLIN1_TX_PRIO > 0) || (IRQ_ASCLIN1_TX_CAT == IRQ_CAT23))
#if((IRQ_ASCLIN1_TX_PRIO > 0) && (IRQ_ASCLIN1_TX_CAT == IRQ_CAT1))
IFX_INTERRUPT(ASCLIN1TX_ISR, 0, IRQ_ASCLIN1_TX_PRIO)
#elif IRQ_ASCLIN1_TX_CAT == IRQ_CAT23
ISR(ASCLIN1TX_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_ASCLIN1_TX_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  TestUartISRCnt++;
#if (IRQ_ASCLIN_CHANNEL1_USED == IRQ_ASCLIN_USED_MCALLIN)
#if ((defined(LIN_ASCLIN1_USED)) && (LIN_ASCLIN1_USED == STD_ON))
  /* Call TX Interrupt funtion*/                                              
  Lin_17_AscLin_IsrTransmit(LIN_ASCLIN1);
#endif/*(LIN_ASCLINx_USED == STD_ON)*/
#endif/*#if (IRQ_ASCLIN_CHANNEL1_USED == IRQ_ASCLIN_USED_MCALLIN)*/

#if (IRQ_ASCLIN_CHANNEL1_USED == IRQ_ASCLIN_USED_MCALUART)
#if ((defined(UART_ASCLIN1_USED)) && (UART_ASCLIN1_USED == STD_ON))
  /* Call TX Interrupt funtion*/                                              
  Uart_IsrTransmit( UART_ASCLIN1);
#endif/*( UART_ASCLINx_USED == STD_ON)*/
#endif
#if (IRQ_ASCLIN_CHANNEL1_USED == IRQ_ASCLIN_USED_MCALSTDLIN)
  /* Complex STDLIN driver usage */
  StdLin_IsrTransmit(1U);
#endif/*#if (IRQ_ASCLIN_CHANNEL1_USED == IRQ_ASCLIN_USED_MCALLIN)*/

}
#endif

#if ((defined(IRQ_ASCLIN2_EXIST)) &&(IRQ_ASCLIN2_EXIST == STD_ON))
#if((IRQ_ASCLIN2_TX_PRIO > 0) || (IRQ_ASCLIN2_TX_CAT == IRQ_CAT23))
#if((IRQ_ASCLIN2_TX_PRIO > 0) && (IRQ_ASCLIN2_TX_CAT == IRQ_CAT1))
IFX_INTERRUPT(ASCLIN2TX_ISR, 0, IRQ_ASCLIN2_TX_PRIO)
#elif IRQ_ASCLIN2_TX_CAT == IRQ_CAT23
ISR(ASCLIN2TX_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_ASCLIN2_TX_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

#if (IRQ_ASCLIN_CHANNEL2_USED == IRQ_ASCLIN_USED_MCALLIN)
#if ((defined(LIN_ASCLIN2_USED)) && (LIN_ASCLIN2_USED == STD_ON))
  /* Call TX Interrupt funtion*/                                              
  Lin_17_AscLin_IsrTransmit(LIN_ASCLIN2);
#endif/*#if ((defined(LIN_ASCLIN2_USED)) && (LIN_ASCLIN2_USED == STD_ON))*/
#endif/*#if (IRQ_ASCLIN_CHANNEL2_USED == IRQ_ASCLIN_USED_MCALLIN)*/

#if (IRQ_ASCLIN_CHANNEL2_USED == IRQ_ASCLIN_USED_MCALUART)
#if ((defined(UART_ASCLIN2_USED)) && (UART_ASCLIN2_USED == STD_ON))
  /* Call TX Interrupt funtion*/                                              
  Uart_IsrTransmit( UART_ASCLIN2);
#endif/*( UART_ASCLINx_USED == STD_ON)*/
#endif
#if (IRQ_ASCLIN_CHANNEL2_USED == IRQ_ASCLIN_USED_MCALSTDLIN)
  /* Complex STDLIN driver usage */
  StdLin_IsrTransmit(2U);
#endif/*#if (IRQ_ASCLIN_CHANNEL2_USED == IRQ_ASCLIN_USED_MCALLIN)*/

}
#endif
#endif

#if ((defined(IRQ_ASCLIN3_EXIST)) &&(IRQ_ASCLIN3_EXIST == STD_ON))
#if((IRQ_ASCLIN3_TX_PRIO > 0) || (IRQ_ASCLIN3_TX_CAT == IRQ_CAT23))
#if((IRQ_ASCLIN3_TX_PRIO > 0) && (IRQ_ASCLIN3_TX_CAT == IRQ_CAT1))
IFX_INTERRUPT(ASCLIN3TX_ISR, 0, IRQ_ASCLIN3_TX_PRIO)
#elif IRQ_ASCLIN3_TX_CAT == IRQ_CAT23
ISR(ASCLIN3TX_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_ASCLIN3_TX_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

#if (IRQ_ASCLIN_CHANNEL3_USED == IRQ_ASCLIN_USED_MCALLIN)
#if ((defined(LIN_ASCLIN3_USED)) && (LIN_ASCLIN3_USED == STD_ON))
  /* Call TX Interrupt funtion*/                                              
  Lin_17_AscLin_IsrTransmit(LIN_ASCLIN3);
#endif/*#if ((defined(LIN_ASCLIN3_USED)) && (LIN_ASCLIN3_USED == STD_ON))*/
#endif/*#if (IRQ_ASCLIN_CHANNEL3_USED == IRQ_ASCLIN_USED_MCALLIN)*/

#if (IRQ_ASCLIN_CHANNEL3_USED == IRQ_ASCLIN_USED_MCALUART)
#if ((defined(UART_ASCLIN3_USED)) && (UART_ASCLIN3_USED == STD_ON))
  /* Call TX Interrupt funtion*/                                              
  Uart_IsrTransmit( UART_ASCLIN3);
#endif/*( UART_ASCLIN3_USED == STD_ON)*/
#endif
#if (IRQ_ASCLIN_CHANNEL3_USED == IRQ_ASCLIN_USED_MCALSTDLIN)
  /* Complex STDLIN driver usage */
  StdLin_IsrTransmit(3U);
#endif/*#if (IRQ_ASCLIN_CHANNEL3_USED == IRQ_ASCLIN_USED_MCALLIN)*/

}
#endif
#endif


/******************************************************************************
** Syntax : void ASCLINxRX_ISR(void)                                        **
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
** Description : Service for Receive interrupt of ASCLINx                    **
**                                                                           **
*****************************************************************************/
#if((IRQ_ASCLIN0_RX_PRIO > 0) || (IRQ_ASCLIN0_RX_CAT == IRQ_CAT23))
#if((IRQ_ASCLIN0_RX_PRIO > 0) && (IRQ_ASCLIN0_RX_CAT == IRQ_CAT1))
IFX_INTERRUPT(ASCLIN0RX_ISR, 0, IRQ_ASCLIN0_RX_PRIO)
#elif IRQ_ASCLIN0_RX_CAT == IRQ_CAT23
ISR(ASCLIN0RX_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_ASCLIN0_RX_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  
#if (IFX_SAFETLIB_USED == STD_ON)
#ifdef SWDG_EXT_CIC_WDG_ONLY
#if (IRQ_ASCLIN_CHANNEL0_USED == IRQ_ASCLIN_AVAILABLE)
  /*call isr to read the received data from CIC */
  SafeWdgAscLin_IsrRx();
#endif
#endif
#endif  

#if (IRQ_ASCLIN_CHANNEL0_USED == IRQ_ASCLIN_USED_MCALLIN)
#if ((defined(LIN_ASCLIN0_USED)) && (LIN_ASCLIN0_USED == STD_ON))
  /* Call RX Interrupt funtion*/                                              
  Lin_17_AscLin_IsrReceive(LIN_ASCLIN0);
#endif/*(LIN_ASCLINx_USED == STD_ON)*/
#endif/*#if (IRQ_ASCLIN_CHANNEL0_USED == IRQ_ASCLIN_USED_MCALLIN)*/

#if (IRQ_ASCLIN_CHANNEL0_USED == IRQ_ASCLIN_USED_MCALUART)
#if ((defined(UART_ASCLIN0_USED)) && (UART_ASCLIN0_USED == STD_ON))
  /* Call RX Interrupt funtion*/                                              
  Uart_IsrReceive(UART_ASCLIN0);
#endif/*( UART_ASCLINx_USED == STD_ON)*/
#endif
#if (IRQ_ASCLIN_CHANNEL0_USED == IRQ_ASCLIN_USED_MCALSTDLIN)
  /* Complex STDLIN driver usage */
  StdLin_IsrReceive(0U);
#endif/*#if (IRQ_ASCLIN_CHANNEL0_USED == IRQ_ASCLIN_USED_MCALLIN)*/
}
#endif

#if((IRQ_ASCLIN1_RX_PRIO > 0) || (IRQ_ASCLIN1_RX_CAT == IRQ_CAT23))
#if((IRQ_ASCLIN1_RX_PRIO > 0) && (IRQ_ASCLIN1_RX_CAT == IRQ_CAT1))
IFX_INTERRUPT(ASCLIN1RX_ISR, 0, IRQ_ASCLIN1_RX_PRIO)
#elif IRQ_ASCLIN1_RX_CAT == IRQ_CAT23
ISR(ASCLIN1RX_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_ASCLIN1_RX_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

#if (IFX_SAFETLIB_USED == STD_ON)
#ifdef SWDG_EXT_CIC_WDG_ONLY
#if (IRQ_ASCLIN_CHANNEL1_USED == IRQ_ASCLIN_AVAILABLE)  
  /*call isr to read the received data from CIC */
  SafeWdgAscLin_IsrRx();
#endif
#endif  
#endif
  
#if (IRQ_ASCLIN_CHANNEL1_USED == IRQ_ASCLIN_USED_MCALLIN)
#if ((defined(LIN_ASCLIN1_USED)) && (LIN_ASCLIN1_USED == STD_ON))
  /* Call RX Interrupt funtion*/                                              
  Lin_17_AscLin_IsrReceive(LIN_ASCLIN1);
#endif/*(LIN_ASCLIN1_USED == STD_ON)*/
#endif/*#if (IRQ_ASCLIN_CHANNEL1_USED == IRQ_ASCLIN_USED_MCALLIN)*/

#if (IRQ_ASCLIN_CHANNEL1_USED == IRQ_ASCLIN_USED_MCALUART)
#if ((defined(UART_ASCLIN1_USED)) && (UART_ASCLIN1_USED == STD_ON))
  /* Call RX Interrupt funtion*/                                              
  Uart_IsrReceive(UART_ASCLIN1);
  TestUartRXISRCnt++;
#endif/*( UART_ASCLINx_USED == STD_ON)*/
#endif
#if (IRQ_ASCLIN_CHANNEL1_USED == IRQ_ASCLIN_USED_MCALSTDLIN)
  /* Complex STDLIN driver usage */
  StdLin_IsrReceive(1U);
#endif/*#if (IRQ_ASCLIN_CHANNEL1_USED == IRQ_ASCLIN_USED_MCALLIN)*/
}
#endif

#if ((defined(IRQ_ASCLIN2_EXIST)) &&(IRQ_ASCLIN2_EXIST == STD_ON))
#if((IRQ_ASCLIN2_RX_PRIO > 0) || (IRQ_ASCLIN2_RX_CAT == IRQ_CAT23))
#if((IRQ_ASCLIN2_RX_PRIO > 0) && (IRQ_ASCLIN2_RX_CAT == IRQ_CAT1))
IFX_INTERRUPT(ASCLIN2RX_ISR, 0, IRQ_ASCLIN2_RX_PRIO)
#elif IRQ_ASCLIN2_RX_CAT == IRQ_CAT23
ISR(ASCLIN2RX_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_ASCLIN2_RX_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif
  
#if (IFX_SAFETLIB_USED == STD_ON)
#ifdef SWDG_EXT_CIC_WDG_ONLY
#if (IRQ_ASCLIN_CHANNEL2_USED == IRQ_ASCLIN_AVAILABLE)
  /*call isr to read the received data from CIC */
  SafeWdgAscLin_IsrRx();
#endif
#endif
#endif 

#if (IRQ_ASCLIN_CHANNEL2_USED == IRQ_ASCLIN_USED_MCALLIN)
#if ((defined(LIN_ASCLIN2_USED)) && (LIN_ASCLIN2_USED == STD_ON))
  /* Call RX Interrupt funtion*/                                              
  Lin_17_AscLin_IsrReceive(LIN_ASCLIN2);
#endif/*#if ((defined(LIN_ASCLIN2_USED)) && (LIN_ASCLIN2_USED == STD_ON))*/
#endif/*#if (IRQ_ASCLIN_CHANNEL2_USED == IRQ_ASCLIN_USED_MCALLIN)*/

#if (IRQ_ASCLIN_CHANNEL2_USED == IRQ_ASCLIN_USED_MCALUART)
#if ((defined(UART_ASCLIN2_USED)) && (UART_ASCLIN2_USED == STD_ON))
  /* Call RX Interrupt funtion*/                                              
  Uart_IsrReceive(UART_ASCLIN2);
#endif/*( UART_ASCLIN2_USED == STD_ON)*/
#endif
#if (IRQ_ASCLIN_CHANNEL2_USED == IRQ_ASCLIN_USED_MCALSTDLIN)
  /* Complex STDLIN driver usage */
  StdLin_IsrReceive(2U);
#endif/*#if (IRQ_ASCLIN_CHANNEL2_USED == IRQ_ASCLIN_USED_MCALLIN)*/
}
#endif
#endif

#if ((defined(IRQ_ASCLIN3_EXIST)) &&(IRQ_ASCLIN3_EXIST == STD_ON))
#if((IRQ_ASCLIN3_RX_PRIO > 0) || (IRQ_ASCLIN3_RX_CAT == IRQ_CAT23))
#if((IRQ_ASCLIN3_RX_PRIO > 0) && (IRQ_ASCLIN3_RX_CAT == IRQ_CAT1))
IFX_INTERRUPT(ASCLIN3RX_ISR, 0, IRQ_ASCLIN3_RX_PRIO)
#elif IRQ_ASCLIN3_RX_CAT == IRQ_CAT23
ISR(ASCLIN3RX_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_ASCLIN3_RX_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif


#if (IFX_SAFETLIB_USED == STD_ON)
#ifdef SWDG_EXT_CIC_WDG_ONLY
#if (IRQ_ASCLIN_CHANNEL3_USED == IRQ_ASCLIN_AVAILABLE)
  /*call isr to read the received data from CIC */
  SafeWdgAscLin_IsrRx();
#endif
#endif
#endif



#if (IRQ_ASCLIN_CHANNEL3_USED == IRQ_ASCLIN_USED_MCALLIN)
#if ((defined(LIN_ASCLIN3_USED)) && (LIN_ASCLIN3_USED == STD_ON))
  /* Call RX Interrupt funtion*/                                              
  Lin_17_AscLin_IsrReceive(LIN_ASCLIN3);
#endif/*#if ((defined(LIN_ASCLIN3_USED)) && (LIN_ASCLIN3_USED == STD_ON))*/
#endif/*#if (IRQ_ASCLIN_CHANNEL3_USED == IRQ_ASCLIN_USED_MCALLIN)*/

#if (IRQ_ASCLIN_CHANNEL3_USED == IRQ_ASCLIN_USED_MCALUART)
#if ((defined(UART_ASCLIN3_USED)) && (UART_ASCLIN3_USED == STD_ON))
  /* Call RX Interrupt funtion*/                                              
  Uart_IsrReceive(UART_ASCLIN3);
#endif/*( UART_ASCLIN3_USED == STD_ON)*/
#endif
#if (IRQ_ASCLIN_CHANNEL3_USED == IRQ_ASCLIN_USED_MCALSTDLIN)
  /* Complex STDLIN driver usage */
  StdLin_IsrReceive(3U);
#endif/*#if (IRQ_ASCLIN_CHANNEL3_USED == IRQ_ASCLIN_USED_MCALLIN)*/
}
#endif
#endif

/******************************************************************************
** Syntax : void ASCLINxEX_ISR(void)                                         **
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
** Description : Service for Error interrupt of ASCLINx                      **
**                                                                           **
*****************************************************************************/
#if((IRQ_ASCLIN0_ERR_PRIO > 0) || (IRQ_ASCLIN0_ERR_CAT == IRQ_CAT23))
#if((IRQ_ASCLIN0_ERR_PRIO > 0) && (IRQ_ASCLIN0_ERR_CAT == IRQ_CAT1))
IFX_INTERRUPT(ASCLIN0EX_ISR, 0, IRQ_ASCLIN0_ERR_PRIO)
#elif IRQ_ASCLIN0_ERR_CAT == IRQ_CAT23
ISR(ASCLIN0EX_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_ASCLIN0_ERR_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

#if (IRQ_ASCLIN_CHANNEL0_USED == IRQ_ASCLIN_USED_MCALLIN)
#if ((defined(LIN_ASCLIN0_USED)) && (LIN_ASCLIN0_USED == STD_ON))
  /* Call the Error ISR */
  Lin_17_AscLin_IsrError(LIN_ASCLIN0);
#endif/*(LIN_ASCLINx_USED == STD_ON)*/
#endif/*#if (IRQ_ASCLIN_CHANNEL0_USED == IRQ_ASCLIN_USED_MCALLIN)*/

#if (IRQ_ASCLIN_CHANNEL0_USED == IRQ_ASCLIN_USED_MCALUART)
#if ((defined(UART_ASCLIN0_USED)) && (UART_ASCLIN0_USED == STD_ON))
  /* Call the Error ISR */
  Uart_IsrError(UART_ASCLIN0);
#endif/*( UART_ASCLINx_USED == STD_ON)*/
#endif
#if (IRQ_ASCLIN_CHANNEL0_USED == IRQ_ASCLIN_USED_MCALSTDLIN)
  /* Complex STDLIN driver usage */
  StdLin_IsrError(0U);
#endif/*#if (IRQ_ASCLIN_CHANNEL0_USED == IRQ_ASCLIN_USED_MCALLIN)*/
  
}
#endif

#if((IRQ_ASCLIN1_ERR_PRIO > 0) || (IRQ_ASCLIN1_ERR_CAT == IRQ_CAT23))
#if((IRQ_ASCLIN1_ERR_PRIO > 0) && (IRQ_ASCLIN1_ERR_CAT == IRQ_CAT1))
IFX_INTERRUPT(ASCLIN1EX_ISR, 0, IRQ_ASCLIN1_ERR_PRIO)
#elif IRQ_ASCLIN1_ERR_CAT == IRQ_CAT23
ISR(ASCLIN1EX_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_ASCLIN1_ERR_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

#if (IRQ_ASCLIN_CHANNEL1_USED == IRQ_ASCLIN_USED_MCALLIN)
#if ((defined(LIN_ASCLIN1_USED)) && (LIN_ASCLIN1_USED == STD_ON))
  /* Call the Error ISR */
  Lin_17_AscLin_IsrError(LIN_ASCLIN1);
#endif/*(LIN_ASCLINx_USED == STD_ON)*/
#endif/*#if (IRQ_ASCLIN_CHANNEL1_USED == IRQ_ASCLIN_USED_MCALLIN)*/

#if (IRQ_ASCLIN_CHANNEL1_USED == IRQ_ASCLIN_USED_MCALUART)
#if ((defined(UART_ASCLIN1_USED)) && (UART_ASCLIN1_USED == STD_ON))
  /* Call the Error ISR */
  Uart_IsrError(UART_ASCLIN1);
  TestUartEXISRCnt++;
#endif/*( UART_ASCLINx_USED == STD_ON)*/
#endif
#if (IRQ_ASCLIN_CHANNEL1_USED == IRQ_ASCLIN_USED_MCALSTDLIN)
  /* Complex STDLIN driver usage */
  StdLin_IsrError(1U);
#endif/*#if (IRQ_ASCLIN_CHANNEL1_USED == IRQ_ASCLIN_USED_MCALLIN)*/
  
}
#endif

#if ((defined(IRQ_ASCLIN2_EXIST)) &&(IRQ_ASCLIN2_EXIST == STD_ON))
#if((IRQ_ASCLIN2_ERR_PRIO > 0) || (IRQ_ASCLIN2_ERR_CAT == IRQ_CAT23))
#if((IRQ_ASCLIN2_ERR_PRIO > 0) && (IRQ_ASCLIN2_ERR_CAT == IRQ_CAT1))
IFX_INTERRUPT(ASCLIN2EX_ISR, 0, IRQ_ASCLIN2_ERR_PRIO)
#elif IRQ_ASCLIN2_ERR_CAT == IRQ_CAT23
ISR(ASCLIN2EX_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_ASCLIN2_ERR_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

#if (IRQ_ASCLIN_CHANNEL2_USED == IRQ_ASCLIN_USED_MCALLIN)
#if ((defined(LIN_ASCLIN2_USED)) && (LIN_ASCLIN2_USED == STD_ON))
  /* Call the Error ISR */
  Lin_17_AscLin_IsrError(LIN_ASCLIN2);
#endif/*#if ((defined(LIN_ASCLIN2_USED)) && (LIN_ASCLIN2_USED == STD_ON))*/
#endif/*#if (IRQ_ASCLIN_CHANNEL2_USED == IRQ_ASCLIN_USED_MCALLIN)*/

#if (IRQ_ASCLIN_CHANNEL2_USED == IRQ_ASCLIN_USED_MCALUART)
#if ((defined(UART_ASCLIN2_USED)) && (UART_ASCLIN2_USED == STD_ON))
  /* Call the Error ISR */
  Uart_IsrError(UART_ASCLIN2);
#endif/*( UART_ASCLIN2_USED == STD_ON)*/
#endif
#if (IRQ_ASCLIN_CHANNEL2_USED == IRQ_ASCLIN_USED_MCALSTDLIN)
  /* Complex STDLIN driver usage */
  StdLin_IsrError(2U);
#endif/*#if (IRQ_ASCLIN_CHANNEL2_USED == IRQ_ASCLIN_USED_MCALLIN)*/
  
}
#endif
#endif

#if ((defined(IRQ_ASCLIN3_EXIST)) &&(IRQ_ASCLIN3_EXIST == STD_ON))
#if((IRQ_ASCLIN3_ERR_PRIO > 0) || (IRQ_ASCLIN3_ERR_CAT == IRQ_CAT23))
#if((IRQ_ASCLIN3_ERR_PRIO > 0) && (IRQ_ASCLIN3_ERR_CAT == IRQ_CAT1))
IFX_INTERRUPT(ASCLIN3EX_ISR, 0, IRQ_ASCLIN3_ERR_PRIO)
#elif IRQ_ASCLIN3_ERR_CAT == IRQ_CAT23
ISR(ASCLIN3EX_ISR)
#endif
{
  
  /* Enable Global Interrupts */
#if (IRQ_ASCLIN3_ERR_CAT == IRQ_CAT1)
  Mcal_EnableAllInterrupts();
#endif

#if (IRQ_ASCLIN_CHANNEL3_USED == IRQ_ASCLIN_USED_MCALLIN)
#if ((defined(LIN_ASCLIN3_USED)) && (LIN_ASCLIN3_USED == STD_ON))
  /* Call the Error ISR */
  Lin_17_AscLin_IsrError(LIN_ASCLIN3);
#endif/*#if ((defined(LIN_ASCLIN3_USED)) && (LIN_ASCLIN3_USED == STD_ON))*/
#endif/*#if (IRQ_ASCLIN_CHANNEL3_USED == IRQ_ASCLIN_USED_MCALLIN)*/

#if (IRQ_ASCLIN_CHANNEL3_USED == IRQ_ASCLIN_USED_MCALUART)
#if ((defined(UART_ASCLIN3_USED)) && (UART_ASCLIN3_USED == STD_ON))
  /* Call the Error ISR */
  Uart_IsrError(UART_ASCLIN3);
#endif/*( UART_ASCLIN3_USED == STD_ON)*/
#endif
#if (IRQ_ASCLIN_CHANNEL3_USED == IRQ_ASCLIN_USED_MCALSTDLIN)
  /* Complex STDLIN driver usage */
  StdLin_IsrError(3U);
#endif/*#if (IRQ_ASCLIN_CHANNEL3_USED == IRQ_ASCLIN_USED_MCALLIN)*/
  
}
#endif
#endif

#if (IFX_MCAL_USED == STD_ON)
#define IRQ_STOP_SEC_CODE
#include "MemMap.h"
#else
#define IFX_IRQ_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
#endif

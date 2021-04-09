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
**  $FILENAME   : Test_Time.c $                                              **
**                                                                           **
**  $CC VERSION : \main\23 $                                                 **
**                                                                           **
**  $DATE       : 2016-04-06 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains functionality of                        **
**                System Timer Module.                                       **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of Platform_Types.h and Compiler.h */
#include "IfxScu_reg.h"
#include <Std_Types.h>
#include <IfxScu_reg.h>
#include <IfxSrc_reg.h>
#include <IfxStm_reg.h>
#include <Test_Print.h>
#include <Test_Time.h>
#include <Irq.h>
#include <Mcal.h>

/*******************************************************************************
**                      Imported Compiler Switch Checks                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define OSC_FREQ (20)

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/



/******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

#ifdef STM_SETALARM_API
/* API for the Alarm */
void Test_Time_SetAlarm(uint8 AlarmId, uint8 AlarmMode, uint32 ReqTimeMs, \
                        void (*Test_Time_CallFnpp)(void));

/* API to DeInit the Alarm */
void Test_DeInitAlarm(void);


/* Arry of 2 Function Pointer for alarm ID 0, Alarm ID 1 */
void (*TestTime_ArrayFnp[2])(void);

#endif

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
#ifdef STM_SETALARM_API
/* Load Value for the Counter Compare register */
uint32 Count_Timer[2];

/*Variable to hold the Mode of alarm ID 0 and 1 at 0  and 1st bit respectively*/
uint8 TestTime_AlarmMode;
#endif

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/* STM Frequency Params */
uint32 uwStmFreq;

/*******************************************************************************
** Syntax           : uint32 Get_Fstm()                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : uint32 - Fstm                                           **
**                                                                            **
** Description      : This function calculates Fstm runtime                   **
**                                                                            **
*******************************************************************************/

uint32 Get_Fstm(void)
{
	uint8 PDIV = SCU_PLLCON0.B.PDIV;
	uint8 NDIV = SCU_PLLCON0.B.NDIV;
	uint8 K2DIV = SCU_PLLCON1.B.K2DIV;
	
	uint32 Fsrc = 0;
	uint32 Fstm = 0;
	
	if(SCU_PLLCON0.B.VCOBYP == 0)
	{
		Fsrc = ((OSC_FREQ * 1000000) * (NDIV+1)) / ((PDIV + 1) * (K2DIV + 1));
	}
	else
	{
		Fsrc = (OSC_FREQ * 1000000) / (K2DIV + 1);
	}
	
	Fstm = Fsrc / (SCU_CCUCON1.B.STMDIV);

	return Fstm;
}

/*******************************************************************************
** Syntax           : void Test_InitTime(void)                                **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function Initializes System Timer Module           **

*******************************************************************************/

void Test_InitTime(void)
{
	/* Enable CLC*/
   Mcal_ResetENDINIT(); 
   
   STM0_CLC.U = ((STM0_CLC.U& 0x0U) | (0x00000100U));
   
   Mcal_SetENDINIT(); 
    
   /* Use Get_Fstm to get proper STM frequency */ 
   uwStmFreq = Get_Fstm(); 
  
   STM0_CMP0.U     =  0x00000000U; /* load compare register 0 */
   
   STM0_CMP1.U     =  0x00000000U; /* load compare register 1 */
  
   STM0_CMCON.U    =  0x001F001FU; /* load compare match control register */
               
   STM0_ICR.U      =  0x00000051U; /* load interrupt control register */

}

/*******************************************************************************
** Syntax        : void Test_Time_SetAlarm(uint8 AlarmId, uint8 AlarmMode,    ** 
**                 uint32 ReqTimeStmCycles, void (*Test_Time_CallFnpp)(void)) **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters(in)   : AlarmId (0,1) only 2 alarms are possible                ** 
**                    AlarmMode(0 for Continuous, 1 for Oneshot)              **
**                    ReqTimeStmCycles(time in counts)                        **
**                    void (*Test_Time_CallFnpp)(void)) Function pointer      **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function schedules a function based on the input   **
**                    parameters                                              **
*******************************************************************************/

#ifdef STM_SETALARM_API

/* API for Scheduling a Task */
void Test_Time_SetAlarm(uint8 AlarmId, uint8 AlarmMode, uint32 ReqTimeStmCycles, \
         void (*Test_Time_CallFnpp)(void))
{

   /* Update the Load Valule required in the Array based on the delay */
   Count_Timer[AlarmId] = ReqTimeStmCycles ;
   
   /* Set alarm mode as one shot (0) or contnuous (1) */
   TestTime_AlarmMode = AlarmMode << AlarmId ;  
  
  /*Check for the alarm ID and load corresponding compare register and enble SRN*/   
  if( AlarmId == 0 ) 
  {

    /* store the local function pointer in the global array of function pointer */
    TestTime_ArrayFnp[0] = Test_Time_CallFnpp; 

    /* Load the compare register */
    STM0_CMP0.U  =  (Count_Timer[AlarmId] + STM0_TIM0.U) & (0xffffffff);
   /*  Enable intr */
	SRC_STM0SR0.U = ((SRC_STM0SR0.U & 0x7FFFFFFFU) | (0x2000400U));

  }
  else
  {

   /* store the local function pointer in the global array of function pointer   */
   TestTime_ArrayFnp[1] = Test_Time_CallFnpp; 

   /* Load the compare register */
   STM0_CMP1.U  =  ( (Count_Timer[AlarmId]) + STM0_TIM0.U) & (0xffffffff);

   /*  Enable intr */
	SRC_STM0SR1.U = ((SRC_STM0SR1.U & 0x7FFFFFFFU ) | (0x2000400U));

  } 
}   

 



/*******************************************************************************
** Syntax           : void Test_DeInitAlarm(void)                             **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function De-Initializes System Timer Module        **

*******************************************************************************/

void Test_Time_DeInitAlarm( uint8 AlarmId )
{
  
  /* if Timer is for AlarmID 0 clear corresponding SRC i.e SRC0 */ 
  if( AlarmId == 0 )
  {
	
	SRC_STM0SR0.U = ((SRC_STM0SR0.U & 0X7FFFFBFFU) | 0x0U);

  }

  /* if Timer is for AlarmID 1 clear corresponding SRC i.e SRC1 */ 
  if( AlarmId == 1 )
  {
    SRC_STM0SR1.U = ((SRC_STM0SR1.U & 0X7FFFFBFFU) | 0x0U);
  }
}
#endif

/*******************************************************************************
** Syntax           : void Timer_DelayMs(uint32 ReqTime)                      **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function introduces a delay of ReqTimeMs in        **
**                      milli seconds                                         **
*******************************************************************************/

void Timer_DelayMs(uint32 ReqTimeMs )
{
  volatile uint32 ReadStm;
  uint32 Delay_Count, Delay_Compare_Count;
    
  Delay_Count = COUNT_TIMER(ReqTimeMs);
    
  Delay_Compare_Count = Delay_Count + STM0_TIM0.U;

  ReadStm = STM0_TIM0.U;

  while( Delay_Compare_Count >= ReadStm)
  {
    ReadStm = STM0_TIM0.U;
  }
}

/*******************************************************************************
** Syntax           : void Timer_DelayTicks(uint32 ReqTimeTicks)              **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function introduces a delay of ReqTimeTicks in     **
**                    STM Timer Ticks                                         **
*******************************************************************************/

void Timer_DelayTicks(uint32 ReqTimeTicks )
{
  volatile uint32 ReadStm;
  uint32 Delay_Compare_Count ;
    
  Delay_Compare_Count = ReqTimeTicks + STM0_TIM0.U;

  ReadStm = STM0_TIM0.U;

  while( Delay_Compare_Count >= ReadStm)
  {
    ReadStm = STM0_TIM0.U;
  }
}

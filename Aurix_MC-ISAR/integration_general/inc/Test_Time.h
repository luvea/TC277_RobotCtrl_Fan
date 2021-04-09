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
**  $FILENAME   : Test_Time.h $                                              **
**                                                                           **
**  $CC VERSION : \main\7 $                                                  **
**                                                                           **
**  $DATE       : 2014-03-07 $                                               **
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


#ifndef TEST_TIME_H
#define TEST_TIME_H

extern uint32 uwStmFreq;



#define STM_SETALARM_API 

#ifdef STM_SETALARM_API
/* Load Value for the Counter Compare register */
extern uint32 Count_Timer[2];

extern void (*TestTime_ArrayFnp[2])(void);

/*Variable to hold the Mode of alarm ID 0 and 1 at 0  and 1st bit respectively*/
extern uint8 TestTime_AlarmMode;
#endif

#define StmFreq         (uwStmFreq) /* Hz */
#define StmFreqKhz   ( (StmFreq + 500) / 1000 )

#define ReqTimeMs       (uwReqTimeMs)

/* Macro to get time in milli seconds from the timer count */
#define TIME_100NS(cycles) (uint32)(((long )cycles * 10000 + StmFreqKhz/2) \
                                      /StmFreqKhz)

/* Macro to get Load Value from the time in milli seconds */
#define COUNT_TIMER(ReqTimeMs)   (uint32)((StmFreqKhz) * (ReqTimeMs))

/* STM Init Function */
extern void Test_InitTime(void);

/*extern void STM_ISR_SR0(void);*/
extern void STM0SRN1_ISR(void);


#ifdef STM_SETALARM_API

/* STM Test Function */
extern void Test_Time_SetAlarm(uint8 AlarmId,uint8 AlarmMode,uint32 ReqTimeStmCycles,\
                                void (*Test_Time_CallFnpp)(void));

/* STM DeInit Function */
extern void Test_Time_DeInitAlarm(uint8 AlarmId);

/* STM Delay Function */
extern void Timer_DelayMs(uint32 ReqTimeMs );
extern void Timer_DelayTicks(uint32 ReqTimeTicks );

#endif

extern uint32 Get_Fstm(void);

#endif /* End of File Test_Time.h */

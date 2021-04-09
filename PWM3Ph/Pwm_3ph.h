/*
 * Pwm_3ph.h
 *
 *  Created on: 2020-9-19
 *      Author: light
 */

#ifndef PWM_3PH_H_
#define PWM_3PH_H_

#include "Gtm.h"
#include "Port.h"
#include "Dio.h"
#include "IfxStm_reg.h"
#include "IfxGtm_reg.h"
#include "Can.h"

//1tick=10ns
#define PWM_PHASE_TICKS 10000U    //10k  10000us
//#define PWM_PHASE_TICKS 5000U    //20k  5000us


//#define PWM_DEADTIME_H 100U   /*  2us   */
//#define PWM_DEADTIME_L 100U

#define PWM_DEADTIME_H 50U   /*  1us   */
#define PWM_DEADTIME_L 50U


#define MOTOR_NUM_Atom 3U
#define MOTOR_NUM_Tom 1U

#define PHASEU 0u
#define PHASEV 1u
#define PHASEW 2u
#define ADCTRIGGER_ATOM_SEL     1u
#define ADCTRIGGER_ATOMCH_SEL   7u
#define ADCTRIGGER_TICK         0u

typedef struct AtomCh_Cfg
{
	uint8 Atom_Sel;
	uint8 Channel_Sel;
}AtomCh_DataType;
typedef struct TomCh_Cfg
{
	uint8 Tom_Sel;
	uint8 Channel_Sel;
}TomCh_DataType;

typedef struct Pwm3ph_AtomCh_Cfg
{
	AtomCh_DataType PhaseH_AtomCh[3];
	AtomCh_DataType PhaseL_AtomCh[3];
}Pwm3ph_AtomCh_Cfg_DataType;
typedef struct Pwm3ph_TomCh_Cfg
{
	TomCh_DataType PhaseH_TomCh[3];
	TomCh_DataType PhaseL_TomCh[3];
}Pwm3ph_TomCh_Cfg_DataType;


extern float32 Ton_M1_Duty_U_f32;
extern float32 Ton_M1_Duty_V_f32;
extern float32 Ton_M1_Duty_W_f32;
extern float32 Ton_M2_Duty_U_f32;
extern float32 Ton_M2_Duty_V_f32;
extern float32 Ton_M2_Duty_W_f32;
extern float32 Ton_M3_Duty_U_f32;
extern float32 Ton_M3_Duty_V_f32;
extern float32 Ton_M3_Duty_W_f32;
extern float32 Ton_M4_Duty_U_f32;
extern float32 Ton_M4_Duty_V_f32;
extern float32 Ton_M4_Duty_W_f32;



extern void Pwm_3ph_Init(void);
extern void Pwm_3ph_DeInit(void);
extern void Pwm_3ph_SetDuty_M1(void);
extern void Pwm_3ph_SetDuty_M2(void);
extern void Pwm_3ph_SetDuty_M3(void);
extern void Pwm_3ph_SetDuty_M4(void);
extern Pwm3ph_AtomCh_Cfg_DataType Pwm3ph_AtomCh_Cfg[MOTOR_NUM_Atom];

#endif /* PWM_3PH_H_ */

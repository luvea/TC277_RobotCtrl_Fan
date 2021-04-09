/*
 * Pwm_3ph_Core2.c
 *
 *  Created on: 2021年4月1日
 *      Author: luvea
 */


/*
 * Pwm_3ph.c
 *
 *  Created on: 2020-9-19
 *      Author: light
 */

#include "Pwm_3ph.h"





//static void Pwm_3ph_SetHLSr0Sr1_Atom(uint8 MotorNo_u8, uint8 Phase_Sel, float32 Ton_Duty_f32)
//{
//	uint32 ui32_phaseSr1;
//	uint32 ui32_phaseSr0;
//
//	uint8 PwmPhaseH_Atom_Sel = Pwm3ph_AtomCh_Cfg[MotorNo_u8].PhaseH_AtomCh[Phase_Sel].Atom_Sel;
//	uint8 PwmPhaseH_AtomCh_Sel = Pwm3ph_AtomCh_Cfg[MotorNo_u8].PhaseH_AtomCh[Phase_Sel].Channel_Sel;
//	uint8 PwmPhaseL_Atom_Sel = Pwm3ph_AtomCh_Cfg[MotorNo_u8].PhaseL_AtomCh[Phase_Sel].Atom_Sel;
//	uint8 PwmPhaseL_AtomCh_Sel = Pwm3ph_AtomCh_Cfg[MotorNo_u8].PhaseL_AtomCh[Phase_Sel].Channel_Sel;
//
//	ui32_phaseSr1 = (uint32)(PWM_PHASE_TICKS/2 - (uint32)(PWM_PHASE_TICKS * Ton_Duty_f32/2));
//	ui32_phaseSr0 = (uint32)(PWM_PHASE_TICKS - ui32_phaseSr1);
//
//	Gtm_SetAtomShadowValSr0(PwmPhaseH_Atom_Sel, PwmPhaseH_AtomCh_Sel, ui32_phaseSr0);
//	Gtm_SetAtomShadowValSr1(PwmPhaseH_Atom_Sel, PwmPhaseH_AtomCh_Sel, ui32_phaseSr1 + PWM_DEADTIME_H);
//
//	Gtm_SetAtomShadowValSr0(PwmPhaseL_Atom_Sel, PwmPhaseL_AtomCh_Sel, ui32_phaseSr0 + PWM_DEADTIME_L);
//	Gtm_SetAtomShadowValSr1(PwmPhaseL_Atom_Sel, PwmPhaseL_AtomCh_Sel, ui32_phaseSr1);
//
//	Gtm_SetAtomShadowValSr0(ADCTRIGGER_ATOM_SEL, ADCTRIGGER_ATOMCH_SEL, ui32_phaseSr0);
//	Gtm_SetAtomShadowValSr1(ADCTRIGGER_ATOM_SEL, ADCTRIGGER_ATOMCH_SEL, ADCTRIGGER_TICK);             //更新adc采样点
//}




//void Pwm_3ph_SetDuty_M3(void)                                                 //Atom4_(1-6)
//{
//	Pwm_3ph_SetHLSr0Sr1_Atom(1, PHASEU, Ton_M3_Duty_U_f32);
//	Pwm_3ph_SetHLSr0Sr1_Atom(1, PHASEV, Ton_M3_Duty_V_f32);
//	Pwm_3ph_SetHLSr0Sr1_Atom(1, PHASEW, Ton_M3_Duty_W_f32);
//}
//void Pwm_3ph_SetDuty_M4(void)                                                 //Atom0_(1-6)
//{
//	Pwm_3ph_SetHLSr0Sr1_Atom(2, PHASEU, Ton_M4_Duty_U_f32);
//	Pwm_3ph_SetHLSr0Sr1_Atom(2, PHASEV, Ton_M4_Duty_V_f32);
//	Pwm_3ph_SetHLSr0Sr1_Atom(2, PHASEW, Ton_M4_Duty_W_f32);
//}


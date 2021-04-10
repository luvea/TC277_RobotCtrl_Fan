/*
 * Pwm_3ph.c
 *
 *  Created on: 2020-9-19
 *      Author: light
 */

#include "Pwm_3ph.h"
uint32 TimeStamptest[2];
uint32 TimetestRes[2];


Pwm3ph_AtomCh_Cfg_DataType Pwm3ph_AtomCh_Cfg[MOTOR_NUM_Atom] = \
{
	{
    /* U_AtomCh  V_AtomCh W_AtomCh */
		{{1, 1}, {1, 3}, {1, 5}},
		{{1, 2}, {1, 4}, {1, 6}},
	},
	{
    /* U_AtomCh  V_AtomCh W_AtomCh */
		{{4, 1}, {4, 3}, {4, 5}},
		{{4, 2}, {4, 4}, {4, 6}},
	},
	{
    /* U_AtomCh  V_AtomCh W_AtomCh */
		{{0, 1}, {0, 3}, {0, 5}},
		{{0, 2}, {0, 4}, {0, 6}},
	},
};

Pwm3ph_TomCh_Cfg_DataType Pwm3ph_TomCh_Cfg[MOTOR_NUM_Tom] = \
{
	{
    /* U_TomCh  V_TomCh W_TomCh */
		{{0, 1}, {0, 3}, {0, 5}},
		{{0, 2}, {0, 4}, {0, 6}},
	},
};



static void Pwm_3ph_SetHLSr0Sr1_Atom(uint8 MotorNo_u8, uint8 Phase_Sel, float32 Ton_Duty_f32)
{
	uint32 ui32_phaseSr1;
	uint32 ui32_phaseSr0;

	uint8 PwmPhaseH_Atom_Sel = Pwm3ph_AtomCh_Cfg[MotorNo_u8].PhaseH_AtomCh[Phase_Sel].Atom_Sel;
	uint8 PwmPhaseH_AtomCh_Sel = Pwm3ph_AtomCh_Cfg[MotorNo_u8].PhaseH_AtomCh[Phase_Sel].Channel_Sel;
	uint8 PwmPhaseL_Atom_Sel = Pwm3ph_AtomCh_Cfg[MotorNo_u8].PhaseL_AtomCh[Phase_Sel].Atom_Sel;
	uint8 PwmPhaseL_AtomCh_Sel = Pwm3ph_AtomCh_Cfg[MotorNo_u8].PhaseL_AtomCh[Phase_Sel].Channel_Sel;

	ui32_phaseSr1 = (uint32)(PWM_PHASE_TICKS/2 - (uint32)(PWM_PHASE_TICKS * Ton_Duty_f32/2));
	ui32_phaseSr0 = (uint32)(PWM_PHASE_TICKS - ui32_phaseSr1);

	Gtm_SetAtomShadowValSr0(PwmPhaseH_Atom_Sel, PwmPhaseH_AtomCh_Sel, ui32_phaseSr0);
	Gtm_SetAtomShadowValSr1(PwmPhaseH_Atom_Sel, PwmPhaseH_AtomCh_Sel, ui32_phaseSr1 + PWM_DEADTIME_H);

	Gtm_SetAtomShadowValSr0(PwmPhaseL_Atom_Sel, PwmPhaseL_AtomCh_Sel, ui32_phaseSr0 + PWM_DEADTIME_L);
	Gtm_SetAtomShadowValSr1(PwmPhaseL_Atom_Sel, PwmPhaseL_AtomCh_Sel, ui32_phaseSr1);

	Gtm_SetAtomShadowValSr0(ADCTRIGGER_ATOM_SEL, ADCTRIGGER_ATOMCH_SEL, ui32_phaseSr0);
	Gtm_SetAtomShadowValSr1(ADCTRIGGER_ATOM_SEL, ADCTRIGGER_ATOMCH_SEL, ADCTRIGGER_TICK);             //更新adc采样点
}

static void Pwm_3ph_SetHLSr0Sr1_Tom(uint8 MotorNo_u8, uint8 Phase_Sel, float32 Ton_Duty_f32)
{
	uint32 ui32_phaseSr1;
	uint32 ui32_phaseSr0;

	uint8 PwmPhaseH_Tom_Sel = Pwm3ph_TomCh_Cfg[MotorNo_u8].PhaseH_TomCh[Phase_Sel].Tom_Sel;
	uint8 PwmPhaseH_TomCh_Sel = Pwm3ph_TomCh_Cfg[MotorNo_u8].PhaseH_TomCh[Phase_Sel].Channel_Sel;
	uint8 PwmPhaseL_Tom_Sel = Pwm3ph_TomCh_Cfg[MotorNo_u8].PhaseL_TomCh[Phase_Sel].Tom_Sel;
	uint8 PwmPhaseL_TomCh_Sel = Pwm3ph_TomCh_Cfg[MotorNo_u8].PhaseL_TomCh[Phase_Sel].Channel_Sel;

	ui32_phaseSr1 = (uint32)(PWM_PHASE_TICKS/2 - (uint32)(PWM_PHASE_TICKS * Ton_Duty_f32/2));
	ui32_phaseSr0 = (uint32)(PWM_PHASE_TICKS - ui32_phaseSr1);

	Gtm_SetTomShadowValSr0(PwmPhaseH_Tom_Sel, PwmPhaseH_TomCh_Sel, ui32_phaseSr0);
	Gtm_SetTomShadowValSr1(PwmPhaseH_Tom_Sel, PwmPhaseH_TomCh_Sel, ui32_phaseSr1 + PWM_DEADTIME_H);

	Gtm_SetTomShadowValSr0(PwmPhaseL_Tom_Sel, PwmPhaseL_TomCh_Sel, ui32_phaseSr0 + PWM_DEADTIME_L);
	Gtm_SetTomShadowValSr1(PwmPhaseL_Tom_Sel, PwmPhaseL_TomCh_Sel, ui32_phaseSr1);

	Gtm_SetAtomShadowValSr0(ADCTRIGGER_ATOM_SEL, ADCTRIGGER_ATOMCH_SEL, ui32_phaseSr0);
	Gtm_SetAtomShadowValSr1(ADCTRIGGER_ATOM_SEL, ADCTRIGGER_ATOMCH_SEL, ADCTRIGGER_TICK);
}


void Pwm_3ph_Init(void)
{

//	  MODULE_P02.IOCR0.B.PC1 = 0x11;
//	  MODULE_P02.IOCR0.B.PC2 = 0x11;
//	  MODULE_P02.IOCR0.B.PC3 = 0x11;
//	  MODULE_P02.IOCR4.B.PC4 = 0x11;
//	  MODULE_P02.IOCR4.B.PC5 = 0x11;
//	  MODULE_P02.IOCR4.B.PC6 = 0x11;
//    GTM_ATOM1_CH0_CTRL.B.RST_CCU0=1;
//    GTM_ATOM1_CH1_CTRL.B.RST_CCU0=1;
//    GTM_ATOM1_CH2_CTRL.B.RST_CCU0=1;
//    GTM_ATOM1_CH3_CTRL.B.RST_CCU0=1;
//    GTM_ATOM1_CH4_CTRL.B.RST_CCU0=1;
//    GTM_ATOM1_CH5_CTRL.B.RST_CCU0=1;
//    GTM_ATOM1_CH6_CTRL.B.RST_CCU0=1;
//    GTM_ATOM1_CH7_CTRL.B.RST_CCU0=1;
    MODULE_GTM.ATOM[1].CH0.CN0.B.CN0 = 0;
    MODULE_GTM.TOM[0].CH0.CN0.B.CN0 = 0;
    MODULE_GTM.ATOM[0].CH0.CN0.B.CN0 = 0;
    MODULE_GTM.ATOM[4].CH0.CN0.B.CN0 = 0;                     //reference通道cn0重置，使四路pwm对齐

	Gtm_SetAtomShadowValSr0(1, 0, PWM_PHASE_TICKS);           //DPO_M1_PWM_REF_RES        //设置pwm参考通道的周期，也就是设置输出pwm的周期
	Gtm_SetTomShadowValSr0(0, 0, PWM_PHASE_TICKS);            //DPO_M2_PWM_REF_RES
	Gtm_SetAtomShadowValSr0(4, 0, PWM_PHASE_TICKS);           //DPO_M3_PWM_REF_RES
	Gtm_SetAtomShadowValSr0(0, 0, PWM_PHASE_TICKS);           //DPO_M4_PWM_REF_RES

}
void Pwm_3ph_DeInit(void)
{
	Port_SetPinMode(PORT_2_PIN_1, PORT_PIN_MODE_GPIO);
	Port_SetPinMode(PORT_2_PIN_2, PORT_PIN_MODE_GPIO);
	Port_SetPinMode(PORT_2_PIN_3, PORT_PIN_MODE_GPIO);
	Port_SetPinMode(PORT_2_PIN_4, PORT_PIN_MODE_GPIO);
	Port_SetPinMode(PORT_2_PIN_5, PORT_PIN_MODE_GPIO);
	Port_SetPinMode(PORT_2_PIN_6, PORT_PIN_MODE_GPIO);
	Dio_WriteChannel(DIO_CHANNEL_2_1, STD_LOW);
	Dio_WriteChannel(DIO_CHANNEL_2_2, STD_LOW);
	Dio_WriteChannel(DIO_CHANNEL_2_3, STD_LOW);
	Dio_WriteChannel(DIO_CHANNEL_2_4, STD_LOW);
	Dio_WriteChannel(DIO_CHANNEL_2_5, STD_LOW);
	Dio_WriteChannel(DIO_CHANNEL_2_6, STD_LOW);
}







void Pwm_3ph_SetDuty_M1(void)                                                 //Atom1_(1-6)
{
	Pwm_3ph_SetHLSr0Sr1_Atom(0, PHASEU, Ton_M1_Duty_U_f32);
	Pwm_3ph_SetHLSr0Sr1_Atom(0, PHASEV, Ton_M1_Duty_V_f32);
	Pwm_3ph_SetHLSr0Sr1_Atom(0, PHASEW, Ton_M1_Duty_W_f32);
}

void Pwm_3ph_SetDuty_M2(void)                                                 //Tom0_(1-6)
{
	Pwm_3ph_SetHLSr0Sr1_Tom(0, PHASEU, Ton_M2_Duty_U_f32);
	Pwm_3ph_SetHLSr0Sr1_Tom(0, PHASEV, Ton_M2_Duty_V_f32);
	Pwm_3ph_SetHLSr0Sr1_Tom(0, PHASEW, Ton_M2_Duty_W_f32);
}

void Pwm_3ph_SetDuty_M3(void)                                                 //Atom4_(1-6)
{
	Pwm_3ph_SetHLSr0Sr1_Atom(1, PHASEU, Ton_M3_Duty_U_f32);
	Pwm_3ph_SetHLSr0Sr1_Atom(1, PHASEV, Ton_M3_Duty_V_f32);
	Pwm_3ph_SetHLSr0Sr1_Atom(1, PHASEW, Ton_M3_Duty_W_f32);
}
void Pwm_3ph_SetDuty_M4(void)                                                 //Atom0_(1-6)
{
	Pwm_3ph_SetHLSr0Sr1_Atom(2, PHASEU, Ton_M4_Duty_U_f32);
	Pwm_3ph_SetHLSr0Sr1_Atom(2, PHASEV, Ton_M4_Duty_V_f32);
	Pwm_3ph_SetHLSr0Sr1_Atom(2, PHASEW, Ton_M4_Duty_W_f32);
}


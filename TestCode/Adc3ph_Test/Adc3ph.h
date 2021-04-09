/*
 * Adc3ph.h
 *
 *  Created on: 2021Äê2ÔÂ5ÈÕ
 *      Author: zhaojing
 */

#ifndef TESTCODE_ADC3PH_TEST_ADC3PH_H_
#define TESTCODE_ADC3PH_TEST_ADC3PH_H_

#include "Std_Types.h"
#include "Hal_Sensor.h"
#include "Std_Types.h"
#include "Adc.h"
#include "Test_Print.h"
#include "IfxVadc_reg.h"
#include "IfxGtm_reg.h"
#include "Pwm_3ph.h"
#include "Port.h"
#include "TLE_9180.h"
//#include "Testmodel_Core1.h"
//#include "Testmodel_Core2.h"
#include "Testmodel.h"
extern uint16 Adc3ph_Reg_M1_U;
extern uint16 Adc3ph_Reg_M1_V;
extern uint16 Adc3ph_Reg_M1_W;
extern uint16 Adc3ph_Reg_M2_U;
extern uint16 Adc3ph_Reg_M2_V;
extern uint16 Adc3ph_Reg_M2_W;
extern uint16 Adc3ph_Reg_M3_U;
extern uint16 Adc3ph_Reg_M3_V;
extern uint16 Adc3ph_Reg_M3_W;
extern uint16 Adc3ph_Reg_M4_U;
extern uint16 Adc3ph_Reg_M4_V;
extern uint16 Adc3ph_Reg_M4_W;

extern uint16 DC1_Reg;
extern uint16 DC2_Reg;

extern uint16 VRO_M1_Reg;
extern uint16 VRO_M2_Reg;
extern uint16 VRO_M3_Reg;
extern uint16 VRO_M4_Reg;
extern void Adc3ph_M1_Init(void);
extern void Adc3ph_M2_Init(void);
extern void Adc3ph_M3_Init(void);
extern void Adc3ph_M4_Init(void);


extern void Adc3ph_M1_GetResult(void);
extern void Adc3ph_M2_GetResult(void);
extern void Adc3ph_M3_GetResult(void);
extern void Adc3ph_M4_GetResult(void);

extern void Adc3ph_Current_M1_PhyCal(void);
extern void Adc3ph_Current_M2_PhyCal(void);
extern void Adc3ph_Current_M3_PhyCal(void);
extern void Adc3ph_Current_M4_PhyCal(void);

#endif /* TESTCODE_ADC3PH_TEST_ADC3PH_H_ */

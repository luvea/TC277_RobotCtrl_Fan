/*
 * Notification_Adc3ph_Result.h
 *
 *  Created on: 2021Äê3ÔÂ9ÈÕ
 *      Author: zhaojing
 */

#ifndef TESTCODE_ADC3PH_TEST_NOTIFICATION_ADC3PH_RESULT_H_
#define TESTCODE_ADC3PH_TEST_NOTIFICATION_ADC3PH_RESULT_H_
#include <Hal_Sensor.h>
#include "IfxDma_reg.h"
#include "Adc.h"
#include "Adc_Sw.h"
#include "Adc3ph.h"
#include "Pwm_3ph.h"
#include "Can.h"
#include <math.h>
#include "IfxStm_reg.h"
//#include "Testmodel_Core1.h"
//#include "Testmodel_Core2.h"
#include "Testmodel.h"
extern uint32 Hal_M1_Timestamp_tick;
extern uint32 Hal_M2_Timestamp_tick;
extern uint32 Hal_M3_Timestamp_tick;
extern uint32 Hal_M4_Timestamp_tick;


extern uint8_T VePC_S_SubDebugMode_NULL;

extern void UVW_Complete_M1_AdcNotification(void);
extern void UVW_Complete_M2_AdcNotification(void);
extern void UVW_Complete_M3_AdcNotification(void);
extern void UVW_Complete_M4_AdcNotification(void);

#endif /* TESTCODE_ADC3PH_TEST_NOTIFICATION_ADC3PH_RESULT_H_ */

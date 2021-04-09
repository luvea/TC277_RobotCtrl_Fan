/*
 * HAL_SENSOR.h
 *
 *  Created on: 2021-02-05
 *      Author: jw
 */

#ifndef HAL_SENSOR_H_
#define HAL_SENSOR_H_

#include "Dio.h"
#include "IfxStm_reg.h"

#define HAL_A 0u
#define HAL_B 1u
#define HAL_C 2u


#define MOTOT_M1 1u
#define MOTOT_M2 2u
#define MOTOT_M3 3u
#define MOTOT_M4 4u


//extern uint32 Hal_M1_Timestamp;
extern uint32 Hal_M1_Timestamp_tick;
extern uint32 Hal_M2_Timestamp_tick;
extern uint32 Hal_M3_Timestamp_tick;
extern uint32 Hal_M4_Timestamp_tick;

extern void Hal_M1_GetStatus(uint8 MotorNo, uint8 Phase_Sel);
extern void Hal_M2_GetStatus(uint8 MotorNo, uint8 Phase_Sel);
extern void Hal_M3_GetStatus(uint8 MotorNo, uint8 Phase_Sel);
extern void Hal_M4_GetStatus(uint8 MotorNo, uint8 Phase_Sel);

#endif /* HAL_SENSOR_H_ */

/*
 * HAL_SENSOR.h
 *
 *  Created on: 2021-02-05
 *      Author: jw
 */

#include <Hal_Sensor.h>

volatile uint8 Hal_M1_Pos_bit;
/*bit0: Hal_A   bit1: Hal_B   bit2: Hal_C*/
//ABC   Hal_M1_Pos_bit
//100    4
//101    5
//110    6
//111    7
//010    2
//011    3
//001    1
//000    0



//volatile uint32 Hal_M1_Timestamp_pre;

volatile uint8 Hal_M1_Error;
uint8 flgM1HalABC[3];    /*  Ë­µÄÉÏÉýÑØ   */

Dio_LevelType Hal_M1_A_DioLevel;
Dio_LevelType Hal_M1_B_DioLevel;
Dio_LevelType Hal_M1_C_DioLevel;
//uint32 Hal_M1_Timestamp;
uint32 Hal_M1_Timestamp_tick;

void Hal_M1_GetStatus(uint8 MotorNo, uint8 M1Hal_ABCSel)
{


	if(MotorNo == MOTOT_M1)
	{
		flgM1HalABC[0] = 0;
		flgM1HalABC[1] = 0;
		flgM1HalABC[2] = 0;

		Hal_M1_A_DioLevel = Dio_ReadChannel(DioConf_DioChannel_DI_HALL_M1_A);
		Hal_M1_B_DioLevel = Dio_ReadChannel(DioConf_DioChannel_DI_HALL_M1_B);
		Hal_M1_C_DioLevel = Dio_ReadChannel(DioConf_DioChannel_DI_HALL_M1_C);

//		Hal_M1_Timestamp_tick = MODULE_STM0.TIM2.B.STM39_8;  /*  1 tick = 10 * 256ns*/
//		Hal_M1_Timespan_tick = Hal_M1_Timestamp - Hal_M1_Timestamp_pre;
//		Hal_M1_Timestamp_pre = Hal_M1_Timestamp;

//		flgM1HalABC[M1Hal_ABCSel] = 1;

		if(Hal_M1_A_DioLevel == STD_HIGH)
		{
			Hal_M1_Pos_bit|=(1<<2);
			Hal_M1_Timestamp_tick|=(1<<2);
		}
		else
		{
			Hal_M1_Pos_bit&=~(1<<2);
			Hal_M1_Timestamp_tick&=~(1<<2);
		}

		if(Hal_M1_B_DioLevel == STD_HIGH)
		{
			Hal_M1_Pos_bit|=(1<<1);
			Hal_M1_Timestamp_tick|=(1<<1);
		}
		else
		{
			Hal_M1_Pos_bit&=~(1<<1);
			Hal_M1_Timestamp_tick&=~(1<<1);
		}

		if(Hal_M1_C_DioLevel == STD_HIGH)
		{
			Hal_M1_Pos_bit|=(1<<0);
			Hal_M1_Timestamp_tick|=(1<<0);
		}
		else
		{
			Hal_M1_Pos_bit&=~(1<<0);
			Hal_M1_Timestamp_tick&=~(1<<0);
		}

	}
	else
	{
		Hal_M1_Error =1;
	}
}

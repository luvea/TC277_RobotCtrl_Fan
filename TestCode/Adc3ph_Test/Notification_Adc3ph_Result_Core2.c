/*
 * Notification_Adc3ph_Result_Core2.c
 *
 *  Created on: 2021年4月1日
 *      Author: luvea
 */

/*
 * Notification_Adc3ph_Result.c
 *
 *  Created on: 2021年2月4日
 *      Author: zhaojing
 */

#include "Notification_Adc3ph_Result.h"

#define PI (3.1415926535897f)




uint32 Appl_Adc_M3_TimeStamp_tick_u32;
uint32 Appl_Hal_M3_TimeStamp_tick_u32;

uint32 Appl_Adc_M4_TimeStamp_tick_u32;
uint32 Appl_Hal_M4_TimeStamp_tick_u32;






uint32 u32_M3_IrqCn0;
uint32 u32_M4_IrqCn0;


#define HALSTATUS_MASK 0x00000007


uint32 Time_M3_Irq[3];
uint32 Time_M4_Irq[3];                                         //代码运行时间测试




//void UVW_Complete_M3_AdcNotification(void)
//{
//	Time_M3_Irq[0] = MODULE_STM0.TIM0.B.STM31_0;
//
//	static uint8 TxCnt;
//	static float32 SinAngle;
////	u32_IrqCn0 = MODULE_GTM.ATOM[1].CH1.CN0.B.CN0;
//	Appl_Adc_M3_TimeStamp_tick_u32 = MODULE_STM0.TIM2.B.STM39_8;
////	Appl_Adc_M1_TimeStamp_second_f32 = (float32)Appl_Adc_M1_TimeStamp_tick_u32 * 256 / 100000000;
//	// max: 10995.11627775‬s   resolution: 0.00000256s
////	Appl_Hal_M1_TimeStamp_tick_u32 = Hal_M1_Timestamp_tick;
////	Appl_Hal_M1_TimeStamp_second_f32 = (float32)Appl_Hal_M1_TimeStamp_tick_u32 * 256 / 100000000;
//	// max: 10995.11627775‬s   resolution: 0.00002048s
//
//	TxCnt++;
//	if(TxCnt==100)
//	{
////		Can_17_MCanP_Send();
//		TxCnt=0;
//	}
//
////	DMA_DADR052.U=Adc3ph_Buffer_M1_CUR_U[0];
////	DMA_DADR051.U=Adc3ph_Buffer_M1_CUR_V[0];
////	DMA_DADR050.U=Adc3ph_Buffer_M1_CUR_W[0];
//	Adc3ph_Current_M3_PhyCal();
//	Appl_HalStatus_M3_u8 = ((uint8)( Hal_M3_Timestamp_tick & HALSTATUS_MASK ));
//	Testmodel_Core2_step();
////	Pwm_3ph_SetDuty();
//
//	if (VePC_S_SubDebugMode_NULL == 1)
//	{
//		Ton_M3_Duty_U_f32 = 0.5;
//		Ton_M3_Duty_V_f32 = 0.5;
//		Ton_M3_Duty_W_f32 = 0.5;
//
//		Pwm_3ph_SetDuty_M3();
//	}
//	else if ((VePC_S_SubDebugMode_NULL == 0) || (VePC_S_SubDebugMode_NULL == 2) || (VePC_S_SubDebugMode_NULL == 3)|| (VePC_S_SubDebugMode_NULL == 5))
//	{
//		Ton_M3_Duty_U_f32 = f32_M3_Ton_fault_A;
//		Ton_M3_Duty_V_f32 = f32_M3_Ton_fault_B;
//		Ton_M3_Duty_W_f32 = f32_M3_Ton_fault_C;
//		Pwm_3ph_SetDuty_M3();
//
//	}
//
//
//	Time_M3_Irq[1] = MODULE_STM0.TIM0.B.STM31_0;
//	Time_M3_Irq[2] = Time_M3_Irq[1] - Time_M3_Irq[0];
//}

//void UVW_Complete_M4_AdcNotification(void)
//{
//	Time_M4_Irq[0] = MODULE_STM0.TIM0.B.STM31_0;
//
//	static uint8 TxCnt;
//	static float32 SinAngle;
////	u32_IrqCn0 = MODULE_GTM.ATOM[1].CH1.CN0.B.CN0;
//	Appl_Adc_M4_TimeStamp_tick_u32 = MODULE_STM0.TIM2.B.STM39_8;
////	Appl_Adc_M1_TimeStamp_second_f32 = (float32)Appl_Adc_M1_TimeStamp_tick_u32 * 256 / 100000000;
//	// max: 10995.11627775‬s   resolution: 0.00000256s
////	Appl_Hal_M1_TimeStamp_tick_u32 = Hal_M1_Timestamp_tick;
////	Appl_Hal_M1_TimeStamp_second_f32 = (float32)Appl_Hal_M1_TimeStamp_tick_u32 * 256 / 100000000;
//	// max: 10995.11627775‬s   resolution: 0.00002048s
//
//	TxCnt++;
//	if(TxCnt==100)
//	{
////		Can_17_MCanP_Send();
//		TxCnt=0;
//	}
//
////	DMA_DADR052.U=Adc3ph_Buffer_M1_CUR_U[0];
////	DMA_DADR051.U=Adc3ph_Buffer_M1_CUR_V[0];
////	DMA_DADR050.U=Adc3ph_Buffer_M1_CUR_W[0];
//	Adc3ph_Current_M4_PhyCal();
//	Appl_HalStatus_M4_u8 = ((uint8)( Hal_M4_Timestamp_tick & HALSTATUS_MASK ));
//	Testmodel_Core2_step();
////	Pwm_3ph_SetDuty();
//
//	if (VePC_S_SubDebugMode_NULL == 1)
//	{
//		Ton_M4_Duty_U_f32 = 0.5;
//		Ton_M4_Duty_V_f32 = 0.5;
//		Ton_M4_Duty_W_f32 = 0.5;
//
//		Pwm_3ph_SetDuty_M4();
//	}
//	else if ((VePC_S_SubDebugMode_NULL == 0) || (VePC_S_SubDebugMode_NULL == 2) || (VePC_S_SubDebugMode_NULL == 3)|| (VePC_S_SubDebugMode_NULL == 5))
//	{
//		Ton_M4_Duty_U_f32 = f32_M4_Ton_fault_A;
//		Ton_M4_Duty_V_f32 = f32_M4_Ton_fault_B;
//		Ton_M4_Duty_W_f32 = f32_M4_Ton_fault_C;
//		Pwm_3ph_SetDuty_M4();
//
//	}
//
//
//	Time_M4_Irq[1] = MODULE_STM0.TIM0.B.STM31_0;
//	Time_M4_Irq[2] = Time_M4_Irq[1] - Time_M4_Irq[0];
//}


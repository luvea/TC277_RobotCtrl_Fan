/*
 * DemoApp.c
 *
 *  Created on: 2020/6/17
 *      Author: Lenovo
 */
#include "Adc3ph.h"
#include "Adc_Sw.h"
#include "Can.h"
#include "Std_Types.h"
#include "Platform_Types.h"
#include "IfxStm_reg.h"
#include "IfxPort_reg.h"
#include "Adc.h"
#include "Irq.h"
#include "Test_Time.h"
#include "AuirxQspi.h"
#include "TLE_9180.h"
#include "IfxSrc_reg.h"
#include "Can_17_MCanP.h"
#include "CanIf_Cbk.h"
#include "Mcal.h"
#include "Uart.h"
//#include "Testmodel_Core1.h"
//#include "Testmodel_Core2.h"
#include "Testmodel.h"


#include "Dio.h"

#include "Pwm_3ph.h"
#include "Adc3ph.h"
#include "Uart_Test.h"
#include "Icu_17_GtmCcu6.h"


volatile uint32 testCnt;

//struct Qspi_ResBuff_
//{
//	uint32 Qspireceive:8;
//}Qspi_ResBuff;

uint8 Flag_Uart_Validate;         /* 0: OK   1: Not OK  */

uint8 Uart_TxDataBuff[12]= \
{
  0xff,0x00,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19
};

uint8 Uart_RxDataBuff[12];
Uart_ReturnType RetWriteApi;
Uart_ReturnType RetReadApi;
Uart_StatusType ChStatus;
volatile uint8 ReceiveCntr;
volatile uint8 TransmitCntr;
Uart_SizeType UartWriteRetSize;
Uart_SizeType UartReadRetSize;

Uart_ErrorIdType UartTransmitNotifError;
Uart_ErrorIdType UartReceiveNotifError;


void TestUartReceiveNotif (Uart_ErrorIdType Error);
void TestUartTransmitNotif (Uart_ErrorIdType Error);
void DemoApp(void);

boolean TestDio = 1;
boolean TestDio1 = 0;

float32 Ton_M1_Duty_U_f32;
float32 Ton_M1_Duty_V_f32;
float32 Ton_M1_Duty_W_f32;

float32 Ton_M2_Duty_U_f32;
float32 Ton_M2_Duty_V_f32;
float32 Ton_M2_Duty_W_f32;

float32 Ton_M3_Duty_U_f32;
float32 Ton_M3_Duty_V_f32;
float32 Ton_M3_Duty_W_f32;

float32 Ton_M4_Duty_U_f32;
float32 Ton_M4_Duty_V_f32;
float32 Ton_M4_Duty_W_f32;

real_T VfPC_S_DebugIdCmd_A;     /* '<Root>/VfPC_S_DebugIdCmd_A' */
real_T VfPC_S_DebugIqCmd_A;     /* '<Root>/VfPC_S_DebugIqCmd_A' */
real_T VfPC_S_DebugUdCmd_V;     /* '<Root>/VfPC_S_DebugUdCmd_V' */
real_T VfPC_S_DebugUqCmd_V;     /* '<Root>/VfPC_S_DebugUqCmd_V' */
//uint8_T VePC_S_SubDebugMode_NULL_M12;/* '<Root>/In1' */
//uint8_T VePC_S_SubDebugMode_NULL_M34;/* '<Root>/In1' */
//uint8_T VePC_S_SubDebugMode_NULL;/* '<Root>/In1' */
real32_T VfPC_S_DebugUalphaCmd_V;/* '<Root>/VfPC_S_DebugUalphaCmd_V' */
real32_T VfPC_S_DebugUbetaCmd_V;/* '<Root>/VfPC_S_DebugUbetaCmd_V' */
uint8_T VfPC_S_DebugFreqCmd_M12;  /* '<Root>/VfPC_S_DebugFreqCmd_Hz' */

real_T VfPC_S_DebugUuCmd_V;     /* '<Root>/VfPC_S_DebugUuCmd_V' */




uint32 Time_Appl[3];
float32 Time_perTick_ns;


void DemoApp(void)
{
	    VePC_S_SubDebugMode_NULL = 1;

	    Timer_DelayMs(10);

	    Test_InitTime();
		Time_perTick_ns = ((float32)1000000000 / (float32)uwStmFreq);

	   Dio_WriteChannel(DioConf_DioChannel_GPIO_5V_SHUT_OFF, STD_LOW);

	   Dio_WriteChannel(DioConf_DioChannel_DO_SEN_POW_EN, STD_HIGH);

       IrqAdc_Init();

       Adc_InitS();
       Adc3ph_M1_Init();





       Pwm_3ph_Init();


       Ton_M1_Duty_U_f32 = 0.5;
       Ton_M1_Duty_V_f32 = 0.5;
       Ton_M1_Duty_W_f32 = 0.5;

       Ton_M2_Duty_U_f32 = 0.5;
       Ton_M2_Duty_V_f32 = 0.5;
       Ton_M2_Duty_W_f32 = 0.5;

       Ton_M3_Duty_U_f32 = 0.5;
       Ton_M3_Duty_V_f32 = 0.5;
       Ton_M3_Duty_W_f32 = 0.5;

       Ton_M4_Duty_U_f32 = 0.5;
       Ton_M4_Duty_V_f32 = 0.5;
       Ton_M4_Duty_W_f32 = 0.5;


       TLE9180_WriteINH_N(STD_LOW);
       Timer_DelayMs(1);
       TLE9180_WriteINH_N(STD_HIGH);

       AurixQspi_Init(&AurixQspi_HWCfg_cst);       /*   9180   */
       TLE9180_Init();

//	   Can_MCanP_Init();
//	   Testmodel_Core1_initialize();
//	   Testmodel_Core2_initialize();
	   Testmodel_initialize();
       ENABLE();

	             MODULE_P23.OUT.B.P6 = TestDio;         //GPIO_12V_PEN                     /*  9180  */
	   		     MODULE_P02.OUT.B.P8 = TestDio1;        //GPIO_5V_SHUT_OFF
	             MODULE_P00.OUT.B.P12 = TestDio1;       //GPIO_5V_JESTON_NEN   /*  9180  */
	             MODULE_P11.OUT.B.P7 = TestDio;         //GPIO_1V8_EN     /*  9180  */
//	             MODULE_P01.OUT.B.P8 = TestDio;    /*  9180  */
	   		     MODULE_P13.OUT.B.P1 = TestDio1;

	              MODULE_P11.OUT.B.P9 = TestDio;         //JESTON_EN     /*  9180  */
//	              MODULE_P11.OUT.B.P0 = TestDio;         //DO_SPI_DRIVER_CS1    /*  9180  */
	              MODULE_P02.OUT.B.P0 = TestDio;         //JESTON_SLEEP_WAKE    /*  9180  */

	   		   	Icu_17_GtmCcu6_EnableEdgeDetection(IcuConf_IcuChannel_DI_HALL_M1_A);
	   		   	Icu_17_GtmCcu6_EnableNotification(IcuConf_IcuChannel_DI_HALL_M1_A);
	   			Icu_17_GtmCcu6_EnableEdgeDetection(IcuConf_IcuChannel_DI_HALL_M1_B);
	   			Icu_17_GtmCcu6_EnableNotification(IcuConf_IcuChannel_DI_HALL_M1_B);
	   			Icu_17_GtmCcu6_EnableEdgeDetection(IcuConf_IcuChannel_DI_HALL_M1_C);
	   			Icu_17_GtmCcu6_EnableNotification(IcuConf_IcuChannel_DI_HALL_M1_C);

	   		   	Icu_17_GtmCcu6_EnableEdgeDetection(IcuConf_IcuChannel_DI_HALL_M2_A);
	   		   	Icu_17_GtmCcu6_EnableNotification(IcuConf_IcuChannel_DI_HALL_M2_A);
	   			Icu_17_GtmCcu6_EnableEdgeDetection(IcuConf_IcuChannel_DI_HALL_M2_B);
	   			Icu_17_GtmCcu6_EnableNotification(IcuConf_IcuChannel_DI_HALL_M2_B);
	   			Icu_17_GtmCcu6_EnableEdgeDetection(IcuConf_IcuChannel_DI_HALL_M2_C);
	   			Icu_17_GtmCcu6_EnableNotification(IcuConf_IcuChannel_DI_HALL_M2_C);

	   		   	Icu_17_GtmCcu6_EnableEdgeDetection(IcuConf_IcuChannel_DI_HALL_M3_A);
	   		   	Icu_17_GtmCcu6_EnableNotification(IcuConf_IcuChannel_DI_HALL_M3_A);
	   			Icu_17_GtmCcu6_EnableEdgeDetection(IcuConf_IcuChannel_DI_HALL_M3_B);
	   			Icu_17_GtmCcu6_EnableNotification(IcuConf_IcuChannel_DI_HALL_M3_B);
	   			Icu_17_GtmCcu6_EnableEdgeDetection(IcuConf_IcuChannel_DI_HALL_M3_C);
	   			Icu_17_GtmCcu6_EnableNotification(IcuConf_IcuChannel_DI_HALL_M3_C);

	   		   	Icu_17_GtmCcu6_EnableEdgeDetection(IcuConf_IcuChannel_DI_HALL_M4_A);
	   		   	Icu_17_GtmCcu6_EnableNotification(IcuConf_IcuChannel_DI_HALL_M4_A);
	   			Icu_17_GtmCcu6_EnableEdgeDetection(IcuConf_IcuChannel_DI_HALL_M4_B);
	   			Icu_17_GtmCcu6_EnableNotification(IcuConf_IcuChannel_DI_HALL_M4_B);
	   			Icu_17_GtmCcu6_EnableEdgeDetection(IcuConf_IcuChannel_DI_HALL_M4_C);
	   			Icu_17_GtmCcu6_EnableNotification(IcuConf_IcuChannel_DI_HALL_M4_C);

	   			VfPC_S_DebugIdCmd_A = 0;     /* '<Root>/VfPC_S_DebugIdCmd_A' */
	   			VfPC_S_DebugIqCmd_A = 0;     /* '<Root>/VfPC_S_DebugIqCmd_A' */
	   			VfPC_S_DebugUdCmd_V = 0;     /* '<Root>/VfPC_S_DebugUdCmd_V' */
	   			VfPC_S_DebugUqCmd_V = 0;     /* '<Root>/VfPC_S_DebugUqCmd_V' */
	   			VfPC_S_DebugUalphaCmd_V = 0;/* '<Root>/VfPC_S_DebugUalphaCmd_V' */
	   			VfPC_S_DebugUbetaCmd_V = 0;/* '<Root>/VfPC_S_DebugUbetaCmd_V' */
	   			VfPC_S_DebugFreqCmd_M12 = 0;  /* '<Root>/VfPC_S_DebugFreqCmd_Hz' */
	   			VfPC_S_DebugUuCmd_V = 0;     /* '<Root>/VfPC_S_DebugUuCmd_V' */
	   			Timer_DelayMs(50);

	while(1)
	{
		    Time_Appl[0] = MODULE_STM0.TIM0.B.STM31_0;


            TLE9180_PowerupSequence();          //∆¿π¿∞Â…œ∆¡±Œ
//            Adc3ph_M1_GetResult();
//            Adc3ph_M2_GetResult();
//            Adc3ph_M3_GetResult();
//            Adc3ph_M4_GetResult();

             TransmitCntr = 0;
             RetWriteApi = Uart_Write(0U, (Uart_MemPtrType)Uart_TxDataBuff, UART_TX_DATA_COUNT);

//           do
//            {
//               ChStatus = Uart_GetStatus(2U);
//            }
//            while(ChStatus != UART_IDLE);
//             UartWriteRetSize = Uart_AbortWrite(2);
             ReceiveCntr = 0;
             RetReadApi = Uart_Read(0U, (Uart_MemPtrType)Uart_RxDataBuff, UART_TX_DATA_COUNT);

//     		TLE9180_WriteINH_N(STD_HIGH);
//     		TLE9180_WriteSOFF_N(STD_HIGH);
//     		TLE9180_WriteENA(STD_HIGH);
//		     Timer_DelayMs(10);

//	           Pwm_3ph_SetDuty();

//		Testmodel_step();

//		for (int i =0; i<10000; i++)
//		{
//			__nop();
//		}

//		Timer_DelayMs(1);

//		Pwm_3ph_SetDuty();

//		Ton_M1_Duty_U_f32 = f32_Ton_fault_A;
//		Ton_M1_Duty_V_f32 = f32_Ton_fault_B;
//		Ton_M1_Duty_W_f32 = f32_Ton_fault_C;
//


//        f32_EAngle_Motor = f32_EAngle_Motor + 15;
//		if(f32_EAngle_Motor > 4096)
//		{
//			f32_EAngle_Motor = 0;              //Appl
//		}
            // Can_17_MCanP_Send();
           testCnt++;

           Time_Appl[1] = MODULE_STM0.TIM0.B.STM31_0;
           Time_Appl[2] = Time_Appl[1] - Time_Appl[0];    /*  1tick = 10ns  */

	}

}

void TestUartReceiveNotif (Uart_ErrorIdType Error)
{
//	UartReceiveNotifError = Error;
//	if(Error == UART_NO_ERR)
//		{
//			ReceiveCntr = 1;
//		}
}

void TestUartTransmitNotif (Uart_ErrorIdType Error)
{
//	UartTransmitNotifError = Error;
//	if(Error == UART_NO_ERR)
//		{
//			TransmitCntr = 1;
//		}
}

void TestUartReceiveNotif_0 (Uart_ErrorIdType Error)
{
	UartReceiveNotifError = Error;
	if(Error == UART_NO_ERR)
		{
			ReceiveCntr = 1;
		}
}

void TestUartTransmitNotif_0 (Uart_ErrorIdType Error)
{
	UartTransmitNotifError = Error;
	if(Error == UART_NO_ERR)
		{
			TransmitCntr = 1;
		}
}

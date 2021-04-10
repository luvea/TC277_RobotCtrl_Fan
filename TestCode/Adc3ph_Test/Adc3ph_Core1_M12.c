/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : Adc_Demo.c $                                               **
**                                                                            **
**   $CC VERSION : \main\17 $                                                 **
**                                                                            **
**   $DATE       : 2014-08-06 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : This file contains                                         **
**                - sample Demo Test for  ADC module                          **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                            **
*******************************************************************************/
//*******************************************************************************
//**                      Includes                                              **
//*******************************************************************************/
#include "Adc3ph.h"
//*******************************************************************************
//**                      Imported Compiler Switch Check                        **
//*******************************************************************************/

//*******************************************************************************
//**                      Private Macro Definitions                             **
//*******************************************************************************/
#define ADC3PH_REFVOLTAGE           5.000f
#define ADC3PH_RESOLUTION           4095.000f
#define CUR_ADC_GAIN                3.183f
#define DC_FACTOR                   7.0f
//*******************************************************************************
//**                      Private Type Definitions                              **
//*******************************************************************************/

//*******************************************************************************
//**                      Private Function Declarations                         **
//*******************************************************************************/

//*******************************************************************************
//**                      Global Constant Definitions                           **
//*******************************************************************************/
//
//*******************************************************************************
//**                      Global Variable Definitions                           **
//*******************************************************************************/
//* Memory Mapping the global variables */

float32 AI_DC_CH_1;
float32 AI_DC_CH_2;



float32 AI_DRV1_VRO;
float32 AI_DRV2_VRO;


uint16 Adc3ph_Reg_M1_U;
uint16 Adc3ph_Reg_M1_V;
uint16 Adc3ph_Reg_M1_W;
uint16 Adc3ph_Reg_M2_U;
uint16 Adc3ph_Reg_M2_V;
uint16 Adc3ph_Reg_M2_W;


uint16 VRO_M1_Reg;
uint16 VRO_M2_Reg;





uint16 DC1_Reg;
uint16 DC2_Reg;





boolean flg_OverCur_b;


Adc_ValueGroupType Adc3ph_Buffer_M1_CUR_U[8];
Adc_ValueGroupType Adc3ph_Buffer_M1_CUR_V[8];
Adc_ValueGroupType Adc3ph_Buffer_M1_CUR_W[8];
Adc_ValueGroupType Adc3ph_Buffer_M2_CUR_U[8];
Adc_ValueGroupType Adc3ph_Buffer_M2_CUR_V[8];
Adc_ValueGroupType Adc3ph_Buffer_M2_CUR_W[8];




Adc_ValueGroupType DC1_Buffer_M1[8];
Adc_ValueGroupType DC1_Buffer_M2[8];


//Adc_ValueGroupType DC2_Buffer_M1[8];
//Adc_ValueGroupType VRO_Buffer_M1[8];

uint32 Test_IrqTim1_3_Cnt;
uint32 Test_IrqTim1_4_Cnt;
uint32 Test_IrqTim1_6_Cnt;

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

void Adc3ph_M1_Init(void)
{
      Adc_SetupResultBuffer(AdcConf_AdcGroup_G0_FOC_CUR_M1_U,&Adc3ph_Buffer_M1_CUR_U[0]);
      Adc_SetupResultBuffer(AdcConf_AdcGroup_G1_FOC_CUR_M1_V,&Adc3ph_Buffer_M1_CUR_V[0]);
      Adc_SetupResultBuffer(AdcConf_AdcGroup_G2_FOC_CUR_M1_W,&Adc3ph_Buffer_M1_CUR_W[0]);
      Adc_SetupResultBuffer(AdcConf_AdcGroup_G3_AI_DC,&DC1_Buffer_M1[0]);

      Adc_EnableHardwareTrigger(AdcConf_AdcGroup_G0_FOC_CUR_M1_U);
      Adc_EnableHardwareTrigger(AdcConf_AdcGroup_G1_FOC_CUR_M1_V);
      Adc_EnableHardwareTrigger(AdcConf_AdcGroup_G2_FOC_CUR_M1_W);
      Adc_EnableHardwareTrigger(AdcConf_AdcGroup_G3_AI_DC);
//      Adc_EnableGroupNotification(AdcConf_AdcGroup_G0_FOC_CUR_M1_U);
}



void Adc3ph_M1_GetResult(void)
{

	Adc3ph_Reg_M1_U=MODULE_VADC.G[0].RES[0].B.RESULT;
	Adc3ph_Reg_M1_V=MODULE_VADC.G[1].RES[0].B.RESULT;                //UVW电压采样
	Adc3ph_Reg_M1_W=MODULE_VADC.G[2].RES[0].B.RESULT;
	VRO_M1_Reg=MODULE_VADC.G[0].RES[6].B.RESULT;                     //9180_1相电流采样参考电压
	DC1_Reg=MODULE_VADC.G[3].RES[3].B.RESULT;                     //母线电压采样1
	DC2_Reg=MODULE_VADC.G[3].RES[2].B.RESULT;                     //母线电压采样2

}
void Adc3ph_M2_GetResult(void)
{
	Adc3ph_Reg_M2_U=MODULE_VADC.G[0].RES[1].B.RESULT;
	Adc3ph_Reg_M2_V=MODULE_VADC.G[1].RES[1].B.RESULT;                //UVW电压采样
	Adc3ph_Reg_M2_W=MODULE_VADC.G[2].RES[1].B.RESULT;
	VRO_M2_Reg=MODULE_VADC.G[0].RES[7].B.RESULT;                     //9180_2相电流采样参考电压
	DC1_Reg=MODULE_VADC.G[3].RES[3].B.RESULT;                        //母线电压采样1
	DC2_Reg=MODULE_VADC.G[3].RES[2].B.RESULT;                        //母线电压采样2
}



void Adc3ph_Current_M1_PhyCal(void)
{
    float32 temp_M1_U;
    float32 temp_M1_V;
    float32 temp_M1_W;

    Adc3ph_M1_GetResult();

    temp_M1_U=((float32)Adc3ph_Reg_M1_U * ADC3PH_REFVOLTAGE) / ADC3PH_RESOLUTION;
    temp_M1_V=((float32)Adc3ph_Reg_M1_V * ADC3PH_REFVOLTAGE) / ADC3PH_RESOLUTION;   //UVW电压实际值
    temp_M1_W=((float32)Adc3ph_Reg_M1_W * ADC3PH_REFVOLTAGE) / ADC3PH_RESOLUTION;

    AI_DC_CH_1=((float32)DC1_Reg * ADC3PH_REFVOLTAGE) / ADC3PH_RESOLUTION;
    AI_DC_CH_2=((float32)DC2_Reg * ADC3PH_REFVOLTAGE) / ADC3PH_RESOLUTION;
    AI_DRV1_VRO=((float32)VRO_M1_Reg * ADC3PH_REFVOLTAGE) / ADC3PH_RESOLUTION;   //9180相电流采样参考电压实际值

    if(((AI_DC_CH_1 >= 4.5) || (AI_DC_CH_1 <= -4.5)) || ((AI_DC_CH_2 >= 4.5) || (AI_DC_CH_2 <= -4.5)) || ((AI_DRV1_VRO >= 4.5) || (AI_DRV1_VRO <= -4.5)))
    {
    	flg_OverCur_b = 1;
    	TLE9180_WriteENA(STD_LOW);
    	Port_SetPinMode(PORT_0_PIN_2, PORT_PIN_MODE_GPIO);
    	Port_SetPinMode(PORT_0_PIN_3, PORT_PIN_MODE_GPIO);
    	Port_SetPinMode(PORT_0_PIN_4, PORT_PIN_MODE_GPIO);
    	Port_SetPinMode(PORT_0_PIN_5, PORT_PIN_MODE_GPIO);
    	Port_SetPinMode(PORT_0_PIN_6, PORT_PIN_MODE_GPIO);
    	Port_SetPinMode(PORT_0_PIN_7, PORT_PIN_MODE_GPIO);
    	Dio_WriteChannel(DIO_CHANNEL_0_2, STD_LOW);
    	Dio_WriteChannel(DIO_CHANNEL_0_3, STD_LOW);
    	Dio_WriteChannel(DIO_CHANNEL_0_4, STD_LOW);
    	Dio_WriteChannel(DIO_CHANNEL_0_5, STD_LOW);
    	Dio_WriteChannel(DIO_CHANNEL_0_6, STD_LOW);
    	Dio_WriteChannel(DIO_CHANNEL_0_7, STD_LOW);
    }//采样电流大于3关闭pwm输出



//	  Test_IrqTim1_3_Cnt++;
	  Hal_M1_GetStatus(MOTOT_M1, HAL_A);
//      Test_IrqTim1_4_Cnt++;
//      Hal_GetStatus(MOTOT_M1, HAL_B);
//  	  Test_IrqTim1_6_Cnt++;
//      Hal_GetStatus(MOTOT_M1, HAL_C);



    DC_link_Vol=((float32)(AI_DC_CH_1+AI_DC_CH_2))*DC_FACTOR;           //母线电压实际值
//    DC_link_Vol=((float32)(AI_DC_CH_1+AI_DC_CH_2))*DC_FACTOR;           //母线电压实际值



    Phase_Cur_A_M1_Value= -(temp_M1_U-AI_DRV1_VRO) * CUR_ADC_GAIN;
    Phase_Cur_B_M1_Value= -(temp_M1_V-AI_DRV1_VRO) * CUR_ADC_GAIN;
    Phase_Cur_C_M1_Value= -(temp_M1_W-AI_DRV1_VRO) * CUR_ADC_GAIN;

//    Phase_Cur_A_Value= -(temp_M1_U-AI_DRV1_VRO) * CUR_ADC_GAIN;
//    Phase_Cur_B_Value= -(temp_M1_V-AI_DRV1_VRO) * CUR_ADC_GAIN;
//    Phase_Cur_C_Value= -(temp_M1_W-AI_DRV1_VRO) * CUR_ADC_GAIN;


}
void Adc3ph_Current_M2_PhyCal(void)
{
    float32 temp_M2_U;
    float32 temp_M2_V;
    float32 temp_M2_W;

    Adc3ph_M2_GetResult();

    temp_M2_U=((float32)Adc3ph_Reg_M2_U * ADC3PH_REFVOLTAGE) / ADC3PH_RESOLUTION;
    temp_M2_V=((float32)Adc3ph_Reg_M2_V * ADC3PH_REFVOLTAGE) / ADC3PH_RESOLUTION;   //UVW电压实际值
    temp_M2_W=((float32)Adc3ph_Reg_M2_W * ADC3PH_REFVOLTAGE) / ADC3PH_RESOLUTION;

    AI_DC_CH_1=((float32)DC1_Reg * ADC3PH_REFVOLTAGE) / ADC3PH_RESOLUTION;
    AI_DC_CH_2=((float32)DC2_Reg * ADC3PH_REFVOLTAGE) / ADC3PH_RESOLUTION;
    AI_DRV2_VRO=((float32)VRO_M2_Reg * ADC3PH_REFVOLTAGE) / ADC3PH_RESOLUTION;   //相电流采样参考电压实际值




//	  Test_IrqTim1_3_Cnt++;
	  Hal_M2_GetStatus(MOTOT_M2, HAL_A);
//      Test_IrqTim1_4_Cnt++;
//      Hal_GetStatus(MOTOT_M1, HAL_B);
//  	  Test_IrqTim1_6_Cnt++;
//      Hal_GetStatus(MOTOT_M1, HAL_C);



    DC_link_Vol=((float32)(AI_DC_CH_1+AI_DC_CH_2))*DC_FACTOR;           //母线电压实际值

    Phase_Cur_A_M2_Value= -(temp_M2_U-AI_DRV2_VRO) * CUR_ADC_GAIN;
    Phase_Cur_B_M2_Value= -(temp_M2_V-AI_DRV2_VRO) * CUR_ADC_GAIN;
    Phase_Cur_C_M2_Value= -(temp_M2_W-AI_DRV2_VRO) * CUR_ADC_GAIN;
}




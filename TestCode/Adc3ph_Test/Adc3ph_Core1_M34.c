/*
 * Adc3ph_Core2.c
 *
 *  Created on: 2021年4月1日
 *      Author: luvea
 */

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
#define ADC3PH_RESOLUTION           4096.000f
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

//float32 AI_DC_CH_1;
//float32 AI_DC_CH_2;
float32 AI_DC_CH_3;
float32 AI_DC_CH_4;


//float32 AI_DRV1_VRO;
//float32 AI_DRV2_VRO;
float32 AI_DRV3_VRO;
float32 AI_DRV4_VRO;

//uint16 Adc3ph_Reg_M1_U;
//uint16 Adc3ph_Reg_M1_V;
//uint16 Adc3ph_Reg_M1_W;
//uint16 Adc3ph_Reg_M2_U;
//uint16 Adc3ph_Reg_M2_V;
//uint16 Adc3ph_Reg_M2_W;
uint16 Adc3ph_Reg_M3_U;
uint16 Adc3ph_Reg_M3_V;
uint16 Adc3ph_Reg_M3_W;
uint16 Adc3ph_Reg_M4_U;
uint16 Adc3ph_Reg_M4_V;
uint16 Adc3ph_Reg_M4_W;

//uint16 VRO_M1_Reg;
//uint16 VRO_M2_Reg;
uint16 VRO_M3_Reg;
uint16 VRO_M4_Reg;












Adc_ValueGroupType Adc3ph_Buffer_M3_CUR_U[8];
Adc_ValueGroupType Adc3ph_Buffer_M3_CUR_V[8];
Adc_ValueGroupType Adc3ph_Buffer_M3_CUR_W[8];
Adc_ValueGroupType Adc3ph_Buffer_M4_CUR_U[8];
Adc_ValueGroupType Adc3ph_Buffer_M4_CUR_V[8];
Adc_ValueGroupType Adc3ph_Buffer_M4_CUR_W[8];





Adc_ValueGroupType DC1_Buffer_M3[8];
Adc_ValueGroupType DC1_Buffer_M4[8];






/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/


//void Adc3ph_M3_Init(void)
//{
//      Adc_SetupResultBuffer(AdcConf_AdcGroup_G0_FOC_CUR_M3_U,&Adc3ph_Buffer_M3_CUR_U[0]);
//      Adc_SetupResultBuffer(AdcConf_AdcGroup_G1_FOC_CUR_M3_V,&Adc3ph_Buffer_M3_CUR_V[0]);
//      Adc_SetupResultBuffer(AdcConf_AdcGroup_G2_FOC_CUR_M3_W,&Adc3ph_Buffer_M3_CUR_W[0]);
//      Adc_SetupResultBuffer(AdcConf_AdcGroup_G3_AI_DC,&DC1_Buffer_M3[0]);
//
//      Adc_EnableHardwareTrigger(AdcConf_AdcGroup_G0_FOC_CUR_M3_U);
//      Adc_EnableHardwareTrigger(AdcConf_AdcGroup_G1_FOC_CUR_M3_V);
//      Adc_EnableHardwareTrigger(AdcConf_AdcGroup_G2_FOC_CUR_M3_W);
//      Adc_EnableHardwareTrigger(AdcConf_AdcGroup_G3_AI_DC);
////    Adc_EnableGroupNotification(AdcConf_AdcGroup_G0_FOC_CUR_M1_U);
//}
//void Adc3ph_M4_Init(void)
//
//{
//      Adc_SetupResultBuffer(AdcConf_AdcGroup_G0_FOC_CUR_M4_U,&Adc3ph_Buffer_M4_CUR_U[0]);
//      Adc_SetupResultBuffer(AdcConf_AdcGroup_G1_FOC_CUR_M4_V,&Adc3ph_Buffer_M4_CUR_V[0]);
//      Adc_SetupResultBuffer(AdcConf_AdcGroup_G2_FOC_CUR_M4_W,&Adc3ph_Buffer_M4_CUR_W[0]);
//      Adc_SetupResultBuffer(AdcConf_AdcGroup_G3_AI_DC,&DC1_Buffer_M4[0]);
//
//      Adc_EnableHardwareTrigger(AdcConf_AdcGroup_G0_FOC_CUR_M4_U);
//      Adc_EnableHardwareTrigger(AdcConf_AdcGroup_G1_FOC_CUR_M4_V);
//      Adc_EnableHardwareTrigger(AdcConf_AdcGroup_G2_FOC_CUR_M4_W);
//      Adc_EnableHardwareTrigger(AdcConf_AdcGroup_G3_AI_DC);
////    Adc_EnableGroupNotification(AdcConf_AdcGroup_G0_FOC_CUR_M1_U);
//}




void Adc3ph_M3_GetResult(void)
{
	Adc3ph_Reg_M3_U=MODULE_VADC.G[0].RES[2].B.RESULT;
	Adc3ph_Reg_M3_V=MODULE_VADC.G[1].RES[2].B.RESULT;                //UVW电压采样
	Adc3ph_Reg_M3_W=MODULE_VADC.G[2].RES[2].B.RESULT;
	VRO_M3_Reg=MODULE_VADC.G[1].RES[6].B.RESULT;                     //9180_3相电流采样参考电压
	DC1_Reg=MODULE_VADC.G[3].RES[3].B.RESULT;                        //母线电压采样1
	DC2_Reg=MODULE_VADC.G[3].RES[2].B.RESULT;                        //母线电压采样2
}
void Adc3ph_M4_GetResult(void)
{
	Adc3ph_Reg_M4_U=MODULE_VADC.G[0].RES[3].B.RESULT;
	Adc3ph_Reg_M4_V=MODULE_VADC.G[1].RES[3].B.RESULT;                //UVW电压采样
	Adc3ph_Reg_M4_W=MODULE_VADC.G[2].RES[3].B.RESULT;
	VRO_M4_Reg=MODULE_VADC.G[1].RES[7].B.RESULT;                     //9180_4相电流采样参考电压
	DC1_Reg=MODULE_VADC.G[3].RES[3].B.RESULT;                        //母线电压采样1
	DC2_Reg=MODULE_VADC.G[3].RES[2].B.RESULT;                        //母线电压采样2
}



void Adc3ph_Current_M3_PhyCal(void)
{
    float32 temp_M3_U;
    float32 temp_M3_V;
    float32 temp_M3_W;

    Adc3ph_M3_GetResult();

    temp_M3_U=((float32)Adc3ph_Reg_M3_U * ADC3PH_REFVOLTAGE) / ADC3PH_RESOLUTION;
    temp_M3_V=((float32)Adc3ph_Reg_M3_V * ADC3PH_REFVOLTAGE) / ADC3PH_RESOLUTION;   //UVW电压实际值
    temp_M3_W=((float32)Adc3ph_Reg_M3_W * ADC3PH_REFVOLTAGE) / ADC3PH_RESOLUTION;

    AI_DC_CH_3=((float32)DC1_Reg * ADC3PH_REFVOLTAGE) / ADC3PH_RESOLUTION;
    AI_DC_CH_4=((float32)DC2_Reg * ADC3PH_REFVOLTAGE) / ADC3PH_RESOLUTION;
    AI_DRV3_VRO=((float32)VRO_M3_Reg * ADC3PH_REFVOLTAGE) / ADC3PH_RESOLUTION;   //相电流采样参考电压实际值




//	  Test_IrqTim1_3_Cnt++;
	  Hal_M3_GetStatus(MOTOT_M3, HAL_A);
//      Test_IrqTim1_4_Cnt++;
//      Hal_GetStatus(MOTOT_M1, HAL_B);
//  	  Test_IrqTim1_6_Cnt++;
//      Hal_GetStatus(MOTOT_M1, HAL_C);



    DC_link_Vol=((float32)(AI_DC_CH_3+AI_DC_CH_4))*DC_FACTOR;           //母线电压实际值

    Phase_Cur_A_M3_Value= -(temp_M3_U-AI_DRV3_VRO) * CUR_ADC_GAIN;
    Phase_Cur_B_M3_Value= -(temp_M3_V-AI_DRV3_VRO) * CUR_ADC_GAIN;
    Phase_Cur_C_M3_Value= -(temp_M3_W-AI_DRV3_VRO) * CUR_ADC_GAIN;
}

void Adc3ph_Current_M4_PhyCal(void)
{
    float32 temp_M4_U;
    float32 temp_M4_V;
    float32 temp_M4_W;

    Adc3ph_M4_GetResult();

    temp_M4_U=((float32)Adc3ph_Reg_M4_U * ADC3PH_REFVOLTAGE) / ADC3PH_RESOLUTION;
    temp_M4_V=((float32)Adc3ph_Reg_M4_V * ADC3PH_REFVOLTAGE) / ADC3PH_RESOLUTION;   //UVW电压实际值
    temp_M4_W=((float32)Adc3ph_Reg_M4_W * ADC3PH_REFVOLTAGE) / ADC3PH_RESOLUTION;

    AI_DC_CH_3=((float32)DC1_Reg * ADC3PH_REFVOLTAGE) / ADC3PH_RESOLUTION;
    AI_DC_CH_4=((float32)DC2_Reg * ADC3PH_REFVOLTAGE) / ADC3PH_RESOLUTION;
    AI_DRV4_VRO=((float32)VRO_M4_Reg * ADC3PH_REFVOLTAGE) / ADC3PH_RESOLUTION;   //相电流采样参考电压实际值




//	  Test_IrqTim1_3_Cnt++;
	  Hal_M4_GetStatus(MOTOT_M4, HAL_A);
//      Test_IrqTim1_4_Cnt++;
//      Hal_GetStatus(MOTOT_M1, HAL_B);
//  	  Test_IrqTim1_6_Cnt++;
//      Hal_GetStatus(MOTOT_M1, HAL_C);



    DC_link_Vol =((float32)(AI_DC_CH_3+AI_DC_CH_4))*DC_FACTOR;           //母线电压实际值

    Phase_Cur_A_M4_Value= -(temp_M4_U-AI_DRV4_VRO) * CUR_ADC_GAIN;
    Phase_Cur_B_M4_Value= -(temp_M4_V-AI_DRV4_VRO) * CUR_ADC_GAIN;
    Phase_Cur_C_M4_Value= -(temp_M4_W-AI_DRV4_VRO) * CUR_ADC_GAIN;
}


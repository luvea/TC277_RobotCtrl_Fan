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

#include "Adc_Sw.h"
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define ADC_REFVOLTAGE           5.000f
#define ADC_RESOLUTION           4096.000f
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
float32 Adc_V_3V3V;
float32 Adc_V_5V0V;
float32 Adc_V_1V8V;
float32 Adc_VOL_UPOWIN;
float32 Adc_V_12V;

Adc_ValueGroupType Adc_G2_VOL_UPOWIN[8];
Adc_ValueGroupType Adc_G3_V_3V3V[8];
Adc_ValueGroupType Adc_G5_5V0_1V8[8];

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

void Adc_InitS(void)
{

	Adc_SetupResultBuffer(AdcConf_AdcGroup_G2_VOL_UPOWIN,&Adc_G2_VOL_UPOWIN[0]);
	Adc_StartGroupConversion(AdcConf_AdcGroup_G2_VOL_UPOWIN);

    Adc_SetupResultBuffer(AdcConf_AdcGroup_G3_AI_3V3V,&Adc_G3_V_3V3V[0]);
    Adc_StartGroupConversion(AdcConf_AdcGroup_G3_AI_3V3V);

    Adc_SetupResultBuffer(AdcConf_AdcGroup_G5_5V0_1V8,&Adc_G5_5V0_1V8[0]);
    Adc_StartGroupConversion(AdcConf_AdcGroup_G5_5V0_1V8);
}

void Adc_GetResult(void)
{

	Adc_ReadGroup(AdcConf_AdcGroup_G2_VOL_UPOWIN,&Adc_G2_VOL_UPOWIN[0]);
    Adc_StartGroupConversion(AdcConf_AdcGroup_G2_VOL_UPOWIN);

	Adc_ReadGroup(AdcConf_AdcGroup_G3_AI_3V3V,&Adc_G3_V_3V3V[0]);
	Adc_StartGroupConversion(AdcConf_AdcGroup_G3_AI_3V3V);

	Adc_ReadGroup(AdcConf_AdcGroup_G5_5V0_1V8,&Adc_G5_5V0_1V8[0]);
	Adc_StartGroupConversion(AdcConf_AdcGroup_G5_5V0_1V8);

}

void Adc_Current_PhyCal(void)
{
	Adc_GetResult();

	Adc_VOL_UPOWIN=((float32)Adc_G2_VOL_UPOWIN[1]*ADC_REFVOLTAGE) / ADC_RESOLUTION;
	Adc_V_12V=((float32)Adc_G2_VOL_UPOWIN[0]*ADC_REFVOLTAGE) / ADC_RESOLUTION;
	Adc_V_3V3V=((float32)Adc_G3_V_3V3V[0]*ADC_REFVOLTAGE) / ADC_RESOLUTION;
	Adc_V_5V0V=((float32)Adc_G5_5V0_1V8[0]*ADC_REFVOLTAGE) / ADC_RESOLUTION;
	Adc_V_1V8V=((float32)Adc_G5_5V0_1V8[1]*ADC_REFVOLTAGE) / ADC_RESOLUTION;

}


/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Can_17_MCanP_Demo.c $                                      **
**                                                                           **
**  $CC VERSION : \main\11 $                                                 **
**                                                                           **
**  $DATE       : 2014-07-10 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                - Demo application for CAN driver                          **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Can.h"


/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define CAN_SRC_SET_SRE                 (0x00000400U)
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
#define CAN_17_MCANP_START_SEC_VAR_8BIT
#include "MemMap.h"

/* Global variables used for pass/fail criteria */
uint8 Test_RxConfirmCount;
uint8 Test_TxConfirmCount;

#define CAN_17_MCANP_STOP_SEC_VAR_8BIT
#include "MemMap.h"

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

#define CAN_17_MCANP_START_SEC_VAR_8BIT
#include "MemMap.h"

/* Data Bytes For CAN Frame */
uint16 Hall_DCLink_RawData[8]={0};
uint16 PhaseCur_VRO_RawData[8]={0};
//uint8 Appl_HalStatus_M1_u8_Buff[8]={0};
uint16 f32_EAngle_KalmanValue_Buff[8]={0};
//uint32 tx_data_1[][8]={
//    {0x01, 0x00, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08 },
//    {0x11, 0x00, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18 },
//    {0x21, 0x00, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28 },
//    {0x31, 0x00, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38 },
//    {0x41, 0x00, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48 },
//    {0x51, 0x00, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58 },
//    {0x61, 0x00, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68 },
//} ;

#define CAN_17_MCANP_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define CAN_17_MCANP_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

/* CAN Frame PDU Info With Standard Identifier */
//Can_PduType PduInfo_1[] =
//{
//  {10,  8,  0x111,  tx_data_1[0] },
//  {11,  8,  0x222,  tx_data_1[1] },
//  {12,  8,  0x333,  tx_data_1[2] },
//  {14,  8,  0x444,  tx_data_1[3] },
//  {15,  8,  0x555,  tx_data_1[4] },
//  {16,  8,  0x666,  tx_data_1[5] },
//  {17,  8,  0x777,  tx_data_1[6] }
//};

Can_PduType PduInfo[] =
{
  {10,  8,  0x111,  &Hall_DCLink_RawData[0] },
  {11,  8,  0x222,  &PhaseCur_VRO_RawData[0] },
  {12,  8,  0x333,  &f32_EAngle_KalmanValue_Buff[0] },
};


#define CAN_17_MCANP_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

#define CAN_17_MCANP_START_SEC_CODE
#include "MemMap.h"


#define CAN_17_MCANP_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

#define CAN_17_MCANP_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Syntax : void Can_MCanP_Init (void)                                     **
**                                                                            **
** Service ID:   : NA                                                         **
**                                                                            **
** Sync/Async:   : Synchronous                                                **
**                                                                            **
** Reentrancy:   : Non Reentrant                                              **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : DemoApp_Init for CAN driver                                       **
**                                                                            **
*******************************************************************************/
void Can_MCanP_Init(void)
{
//	IrqCan_Init();
//	Can_EnableServiceRequest(1);

//	Can_17_MCanP_Init(&Can_17_MCanP_ConfigRoot[0]);
//	Can_17_MCanP_EnableControllerInterrupts(Can_17_MCanPConf_CanController_CanController_0);
//	Can_17_MCanP_EnableControllerInterrupts(Can_17_MCanPConf_CanController_CanController_1);
//	Can_17_MCanP_EnableControllerInterrupts(Can_17_MCanPConf_CanController_CanController_2);
//	Can_17_MCanP_EnableControllerInterrupts(Can_17_MCanPConf_CanController_CanController_3);
	Can_17_MCanP_SetControllerMode(Can_17_MCanPConf_CanController_CanController_0, CAN_T_START);
//	Can_17_MCanP_SetControllerMode(Can_17_MCanPConf_CanController_CanController_1, CAN_T_START);
//	Can_17_MCanP_SetControllerMode(Can_17_MCanPConf_CanController_CanController_2, CAN_T_START);
//	Can_17_MCanP_SetControllerMode(Can_17_MCanPConf_CanController_CanController_3, CAN_T_START);
}/* Can_17_MCanP_Demo_Init() */

/*******************************************************************************
** Syntax : void Can_17_MCanP_Send (void)                                     **
**                                                                            **
** Service ID:   : NA                                                         **
**                                                                            **
** Sync/Async:   : Synchronous                                                **
**                                                                            **
** Reentrancy:   : Non Reentrant                                              **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : DemoApp for CAN driver                                       **
**                                                                            **
*******************************************************************************/
void Can_17_MCanP_Send(void)
{
//	Hall_DCLink_RawData[0]=(uint16)(Hal_M1_Timestamp>>16);
//	Hall_DCLink_RawData[1]=(uint16)(Hal_M1_Timestamp);
//	Hall_DCLink_RawData[2]=DC1_Reg;
//	Hall_DCLink_RawData[3]=DC2_Reg;

//	PhaseCur_VRO_RawData[0]=Adc3ph_Reg_U;
//	PhaseCur_VRO_RawData[1]=Adc3ph_Reg_V;
//	PhaseCur_VRO_RawData[2]=Adc3ph_Reg_W;
//	PhaseCur_VRO_RawData[3]=VRO_Reg;
	f32_EAngle_KalmanValue_Buff[0]=f32_EAngle_M2_KalmanValue;
	f32_EAngle_KalmanValue_Buff[1]=f32_ESpeed_M2_KalmanValue;
//	f32_EAngle_KalmanValue_Buff[0]=f32_EAngle_KalmanValue;
//	f32_EAngle_KalmanValue_Buff[1]=f32_eSpeed_KalmanValue;
	f32_EAngle_KalmanValue_Buff[2]=Appl_HalStatus_M2_u8;
//	DC_VRO_RawData[0]=DC1_Reg;
//	DC_VRO_RawData[1]=DC2_Reg;
//	DC_VRO_RawData[2]=VRO_Reg;
//	HallTime_RawData[0]=Hal_M1_Timestamp;

//	Can_17_MCanP_Write(Can_17_MCanPConf_CanHardwareObject_Hall_Timestamp, &PduInfo[0]);
	Can_17_MCanP_Write(Can_17_MCanPConf_CanHardwareObject_Adc3ph_U, &PduInfo[2]);
//	Can_17_MCanP_Write(Can_17_MCanPConf_CanHardwareObject_Adc3ph_V, &PduInfo_1[2]);
//	Can_17_MCanP_Write(Can_17_MCanPConf_CanHardwareObject_Adc3ph_W, &PduInfo_1[3]);
//	Can_17_MCanP_Write(Can_17_MCanPConf_CanHardwareObject_DC_Link_1, &PduInfo_1[4]);
//	Can_17_MCanP_Write(Can_17_MCanPConf_CanHardwareObject_DC_Link_2, &PduInfo_1[5]);
//	Can_17_MCanP_Write(Can_17_MCanPConf_CanHardwareObject_VRO_9180, &PduInfo_1[6]);

}/* Can_17_MCanP_Demo() */

void Can_EnableServiceRequest(uint8 node)
{
//  if(0U == node)
//  {
//    SRC_CAN_CAN0_INT0.U |= CAN_SRC_SET_SRE ;
//    SRC_CAN_CAN0_INT1.U |= CAN_SRC_SET_SRE ;
//    SRC_CAN_CAN0_INT2.U |= CAN_SRC_SET_SRE ;
//    SRC_CAN_CAN0_INT3.U |= CAN_SRC_SET_SRE ;
//  }

//  if(1U == node)
//  {
//    SRC_CAN_CAN1_INT0.U |= CAN_SRC_SET_SRE ;
//    SRC_CAN_CAN1_INT1.U |= CAN_SRC_SET_SRE ;
//    SRC_CAN_CAN1_INT2.U |= CAN_SRC_SET_SRE ;
//    SRC_CAN_CAN1_INT3.U |= CAN_SRC_SET_SRE ;
//  }
//
//  if(2U == node)
//    {
//      SRC_CAN_CAN2_INT0.U |= CAN_SRC_SET_SRE ;
//      SRC_CAN_CAN2_INT1.U |= CAN_SRC_SET_SRE ;
//      SRC_CAN_CAN2_INT2.U |= CAN_SRC_SET_SRE ;
//      SRC_CAN_CAN2_INT3.U |= CAN_SRC_SET_SRE ;
//    }
//
//  if(3U == node)
//    {
//      SRC_CAN_CAN3_INT0.U |= CAN_SRC_SET_SRE ;
//      SRC_CAN_CAN3_INT1.U |= CAN_SRC_SET_SRE ;
//      SRC_CAN_CAN3_INT2.U |= CAN_SRC_SET_SRE ;
//      SRC_CAN_CAN3_INT3.U |= CAN_SRC_SET_SRE ;
//    }

}

#define CAN_17_MCANP_STOP_SEC_CODE
#include "MemMap.h"

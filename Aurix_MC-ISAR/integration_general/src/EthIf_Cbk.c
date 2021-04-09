///******************************************************************************
//**                                                                           **
//** Copyright (C) Infineon Technologies (2013)                                **
//**                                                                           **
//** All rights reserved.                                                      **
//**                                                                           **
//** This document contains proprietary information belonging to Infineon      **
//** Technologies. Passing on and copying of this document, and communication  **
//** of its contents is not permitted without prior written authorization.     **
//**                                                                           **
//*******************************************************************************
//**                                                                           **
//**  $FILENAME   : EthIf_Cbk.c $                                              **
//**                                                                           **
//**  $CC VERSION : \main\7 $                                                  **
//**                                                                           **
//**  $DATE       : 2014-03-04 $                                               **
//**                                                                           **
//**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
//**                                                                           **
//**  VENDOR      : Infineon Technologies                                      **
//**                                                                           **
//**  DESCRIPTION : This file contains                                         **
//**                Implementation of ETH interface callback functions         **
//**                                                                           **
//**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
//**                                                                           **
//******************************************************************************/
//
//#include <EthIf_Cbk.h>
//#include <Test_Print.h>
//
//extern uint32 Src_IPaddress;
//extern uint8 ArpReply;
//volatile uint32 TotalRxCount,TotalTxCount;
//volatile uint8 TxFrameCount;
//
//void EthIf_Cbk_RxIndication( uint8 CtrlIdx, uint8* DataPtr, uint16 LenByte )
//{
//  uint16 i;
//  uint16 Protocol;
//  uint32 lSrcipadd=0;
//
//  TotalRxCount++;
//  UNUSED_PARAMETER(CtrlIdx)
//  Protocol = ((*(DataPtr +12))<<8) + (*(DataPtr +13));
//
//
//  print_f("\n\n Received Protocol is: 0x%x ",(Protocol));
//  print_f("\n Received Frame Size: %d \n ",(LenByte));
//
//  if ( Protocol == 0xABCD)
//  {
//    print_f("\n Received Raw Frame from PC");
//  }
//
//  if( Protocol == 0x0806)
//  {
//    for (i=0;i <4;i++)
//    {
//      lSrcipadd <<= 8;
//      lSrcipadd |= (*(DataPtr+28+i));
//    }
//    if(lSrcipadd ==Src_IPaddress )
//    {
//      ArpReply = 1;
//      print_f("\n Given IP address is at Mac Address - %x :%x :%x :%x :%x :%x ",(*(DataPtr+22)),(*(DataPtr+23)),(*(DataPtr+24)),(*(DataPtr+25)),(*(DataPtr+26)),(*(DataPtr+27)));
//    }
//  }
//return;
//}
//
//void EthIf_Cbk_TxConfirmation( uint8 CtrlIdx, uint8 BufIdx)
//{
//  UNUSED_PARAMETER(CtrlIdx)
//  print_f("\n Transmitted Ethernet Frame of BufIdx: %d: ",BufIdx);
//  TxFrameCount++;
//  TotalTxCount++;
//  return;
//}

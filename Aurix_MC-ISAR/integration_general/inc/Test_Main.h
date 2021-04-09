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
**  $FILENAME   : Test_Main.h $                                              **
**                                                                           **
**  $CC VERSION : \main\2 $                                                  **
**                                                                           **
**  $DATE       : 2013-06-20 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This header file exports                                   **
**                - functionality of Test_main.                              **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/
#ifndef TEST_MAIN_H
#define TEST_MAIN_H


typedef void (*Test_FunctionType)(void);

/*******************************************************************************
** Syntax : void Test_StaticFunction(void)                                    **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in):                                                           **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : This function will be defined in the module test application **
**                                                                            **
*******************************************************************************/
extern Test_FunctionType Test_StaticFunction;

/*******************************************************************************
** Syntax : void Test_AutomatedFunction(void)                                 **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in):                                                           **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : This function will be defined in the module test application **
**                                                                            **
*******************************************************************************/
extern Test_FunctionType Test_AutomatedFunction;


/*******************************************************************************
** Syntax : void Test_Application()                                           **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : This function does the target initialization and calls the   **
**               application.                                                 **
*******************************************************************************/
extern void Test_Application(void);


#endif /* TEST_MAIN_H */

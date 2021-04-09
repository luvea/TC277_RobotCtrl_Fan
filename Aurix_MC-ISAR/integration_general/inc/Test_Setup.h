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
**  $FILENAME   : Test_Setup.h $                                             **
**                                                                           **
**  $CC VERSION : \main\2 $                                                  **
**                                                                           **
**  $DATE       : 2013-06-20 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION :   This file exports the functionality of Test_Setup.c      **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/

#ifndef TEST_SETUP
#define TEST_SETUP  

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "../../general/inc/Std_Types.h"
#include "../../general/tricore/inc/Platform_Types.h"
#include "../../tricore_general/ssc/inc/Mcal.h"
#include "TEST_PRINT.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define PARAM_COUNT 20
#define MAX_STRING_LEN 100

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/
extern char inputString[100];                                     
extern uint32 paramArray[PARAM_COUNT];

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
** Syntax : void Test_InitPrint(void)                                         **                                   
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in):   none                                                    **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : This function Initializes the Test Setup.                    **
*******************************************************************************/
extern void Test_Setup_Init(void);

/*******************************************************************************
** Syntax : uint32 atoi(char s[])                                             **
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
** Description : This function convert character String to integer            **
*******************************************************************************/
extern uint32 atoi(char s[]);
        
/*******************************************************************************
** Syntax : int StringParser()                                                **
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
** Description : This function parses the Input Parameter String Passed       **
**               to the Test Application.Preamble: "@@@"                      **
**               TestApplication ID & Delimiter :[Numeric value]> , ex: 1>    **
**               Param String:Parameters Separated by Commas.                 **
**               PostAmble: "@@@"                                             **
**               Example of ParamString:  "@@@1>0,32768,50@@@"                **
*******************************************************************************/
extern int StringParser(void);

/*******************************************************************************
** Syntax : int StringParser_manual()                                         **
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
** Description : This function does the parsing of the given string           **
*******************************************************************************/
extern int StringParser_manual(void); 


#endif

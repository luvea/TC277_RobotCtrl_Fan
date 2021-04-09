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
**  $FILENAME   : Test_Setup.c $                                             **
**                                                                           **
**  $CC VERSION : \main\3 $                                                  **
**                                                                           **
**  $DATE       : 2013-06-20 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION :   This file is used to initialize the Test environment     **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/*Inclusion of Std_Types.h */
#include <Std_Types.h>
#include <Test_Print.h>
#include <Test_Setup.h>
#include <Mcal.h>

/*******************************************************************************
**                      Imported Compiler Switch Checks                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

typedef void (*Test_Setup_Init_Demo)(void);
typedef int (*StringParser_Demo)(void);

/******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
char inputString[100];
uint32 paramArray[PARAM_COUNT];  
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Local Function Declarations                           **
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

void Test_Setup_Init()
{
  char c;
  Test_InitPrint();        /* Call to Test_InitPrint() function */
  get_char();              /*Call to get_char() function */ 
  do
  {
    print_f("START_APP"); /* Send the Token "START_APP" till a Character is recieved 
                             from the Communication Port.*/
   }while( (c=get_ch()) == -1);
   ENABLE();              /* Enable Global Interrupt Flag */                
}


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

int StringParser()
{
    char *tempString, param[20];
    tempString = inputString;
    int preAmble=0, postAmble=0, paramCount=0, charCount=0;
    
    /* Check for PreAmble */
    for(; *tempString == '@' && preAmble < 3; tempString++, preAmble++);
    if (preAmble < 3) 
        return -1;

    /* Find the TestCase ID ending with '>' delimiter */
    for(; *tempString != '>'; tempString++)
    {
        param[charCount++] = (char) *tempString;
    }
    /* Transfer it the the Parameter Array as first Element.*/
    paramArray[paramCount] = (uint32) atoi(param);
    charCount = 0;
    tempString++;

    /* Find the Test Case Parameters */
    while (*tempString != '@')
    {
        /* Looks for the ',' delimiter */
        if (*tempString != ',')
        {
            param[charCount++]= (char) *tempString;
        }   
        else
        {
            param[charCount] = 0;
            paramCount++;
            paramArray[paramCount] = (uint32) atoi(param);
            charCount = 0;
        }
        tempString++;
    }
    if (charCount)
    {
        param[charCount] = 0;
        paramCount++;
        paramArray[paramCount] = (uint32) atoi(param);
    }
    /* Check for PostAmble */
    for(; *tempString == '@' && postAmble < 3; tempString++, postAmble++);
    if (postAmble < 3) 
        return -1;
    /* Return the Number of Parameters obtained in the ParamString */
    return paramCount;
}


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
uint32 atoi(char s[])
{
    uint32 i, n;
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;      /* return of n value */
}


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
int StringParser_manual()
{
    char *tempString, param[20];
    tempString = inputString;
    int preAmble=0, postAmble=0, paramCount=0, charCount=0;
    
    /* Check for PreAmble */
    for(; *tempString == '[' && preAmble < 1; tempString++, preAmble++);
    if (preAmble < 1) 
        return -1;

    /* Find the TestCase ID ending with ']' delimiter */
    for(; *tempString != ']'; tempString++)
    {
        param[charCount++] = (char) *tempString;
    }
    
    /* Check for parameter PreAmble */
    if (*++tempString != '[') 
        return -1;

    /* Transfer it the the Parameter Array as first Element. */
    tempString++;
    paramArray[paramCount] = (uint32) atoi(param);
    charCount = 0;
    tempString++;

    /* Find the Test Case Parameters */
    while (*tempString != ']')
    {
        /* Looks for the ',' delimiter */
        if (*tempString != ',')
        {
            param[charCount++]= (char) *tempString;
        }   
        else
        {
            param[charCount] = 0;
            paramCount++;
            paramArray[paramCount] = (uint32) atoi(param);
            charCount = 0;
        }
        tempString++;
    }
    if (charCount)
    {
        param[charCount] = 0;
        paramCount++;
        paramArray[paramCount] = (uint32) atoi(param);
    }
    /* Return the Number of Parameters obtained in the ParamString */
    return paramCount;
}


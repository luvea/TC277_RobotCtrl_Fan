/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2014)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Test_Print.c $                                             **
**                                                                           **
**  $CC VERSION : \main\28 $                                                 **
**                                                                           **
**  $DATE       : 2016-04-04 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file provides display and print support.              **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"

#include "IfxAsclin_reg.h"

/* Include Mcal.h to import the library functions */
#include "Mcal.h"

/* Include Test_Time header file - Test_Time.h */
#include "Test_Time.h"

/* Include Test_Print header file - Test_Print.h */
#include "Test_Print.h"
#include "IfxPort_reg.h"
/*******************************************************************************
**                      Imported Compiler Switch Checks                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

#define USE_ASCLIN1 (STD_OFF)

#define ASCLIN0_BASE          (0xF0000600U)
#define ASCLIN1_BASE          (0xF0000700U)

#if(USE_ASCLIN1 == STD_ON)
#define ASCLIN_BASE ASCLIN1_BASE
#else
#define ASCLIN_BASE ASCLIN0_BASE
#endif

#define ASCLIN_FRAMECON_MODE_INIT (0U)
#define ASCLIN_FRAMECON_MODE_ASC  (1U)
#define ASCLIN_FRAMECON_MODE_SPI  (2U)
#define ASCLIN_FRAMECON_MODE_LIN  (3U)
#define ASCLIN_FRAMECON_MODE_SHIFT (16U)
#define ASCLIN_FRAMECON_STOP_SHIFT (9U)
#define ASCLIN_FRAMECON_STOP       (1U)

#define ASCLIN_DATCON_DATLEN       (7U) /* 8 bit */
#define ASCLIN_DATCON_DATLEN_SHIFT (0U)
#define ASCLIN_DATCON_DATLEN_MASK  (0xFFFFFFF0U)

#define ASCLIN_BITCON_PRESCALAR_SHIFT (0U)
#define ASCLIN_BITCON_OVERSAMPLING_SHIFT (16U)
#define ASCLIN_BITCON_SAMPLEPOINT_SHIFT (24U)
#define ASCLIN_BITCON_SM_SHIFT (31U)
#define ASCLIN_BITCON_PRESCALAR (19U) /* 1 - 4096 */
#define ASCLIN_BITCON_OVERSAMPLING (15U) /* min of 3 */
#define ASCLIN_BITCON_SAMPLEPOINT (8U) /* min of 1 */
#define ASCLIN_BITCON_SM (0U)

#define ASCLIN_BRG_NUMERATOR_SHIFT (16U)
#define ASCLIN_BRG_DENOMINATOR_SHIFT (0U)
#define ASCLIN_BRG_NUMERATOR       (2304U)  /* 38,400Khz */
#define ASCLIN_BRG_DENOMINATOR      (3750U)

#define ASCLIN_CSR_CLKSEL_NOCLK       (0U)
#define ASCLIN_CSR_CLKSEL_CLC       (1U)
#define ASCLIN_CSR_CLKSEL_EVROSC    (2U)
#define ASCLIN_CSR_CLKSEL_FMAX      (8U)
#define ASCLIN_CSR_CLKSEL_SHIFT (0U)
#define ASCLIN_CSR_CLKSEL       (ASCLIN_CSR_CLKSEL_EVROSC)

#define ASCLIN_TXFIFOCON_FILL_SHIFT (16U)
#define ASCLIN_TXFIFOCON_FILL_MASK  (0x1FU)
#define ASCLIN_TXFIFOCON_ENO_SHIFT (1U)
#define ASCLIN_TXFIFOCON_ENO_EN    (1U) /* tx fifo outlet enable */
#define ASCLIN_TXFIFOCON_INW_SHIFT (6U)
#define ASCLIN_TXFIFOCON_INW_VAL   (1U) /* tx fifo outlet width */

#define ASCLIN_RXFIFOCON_FILL_SHIFT (16U)
#define ASCLIN_RXFIFOCON_FILL_MASK  (0x1FU)
#define ASCLIN_RXFIFOCON_ENO_SHIFT (1U)
#define ASCLIN_RXFIFOCON_ENO_EN    (1U) /* rx fifo outlet enable */
#define ASCLIN_RXFIFOCON_INW_SHIFT (6U)
#define ASCLIN_RXFIFOCON_INW_VAL   (1U) /* rx fifo outlet width */

#define ASCLIN_IOCR_FILTER_DEPTH   (4U) /* digital filter glitch depth */

#define ASCLIN_FLAGSCLEAR_MASK (0xFFFFFffFU)

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
static volatile Ifx_ASCLIN *psASCLIN0;

#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)
#pragma section farbss="Shared.DEFAULT_RAM_8BIT"
#endif /* #if (_TASKING_C_TRICORE_ == 1U) */
#elif defined _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)
#pragma section ".data.Shared.DEFAULT_RAM_8BIT" aw 1
#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#elif defined _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
#pragma section DATA ".data.Shared.DEFAULT_RAM_8BIT" ".bss.Shared.DEFAULT_RAM_8BIT" far-absolute RW
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif

static char ubOutputBuf[140];

#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)
#pragma section farbss restore
#endif /* #if (_TASKING_C_TRICORE_ == 1U) */
#elif defined _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)
#pragma section
#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#elif defined _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
#pragma section DATA RW
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Local Function Declarations                           **
*******************************************************************************/
void put_char(char);
int get_char(void);
void InitSCI(void);
void print_f(const char *p_frm, ...);
void getline(char *p_line, uint32 n_max);

IFX_INLINE void delay(void)
{
    volatile int i;
    for (i=0;i<100;i++);
}

/*******************************************************************************
** Syntax : void Test_InitPrint(void)                                         **
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
** Description : This function Initializes the Printing on Serial             **
**               Communication Port. Baud rate : 38,400 Hz                    **
*******************************************************************************/
void Test_InitPrint(void)
{
  volatile int i;
  psASCLIN0 = (volatile Ifx_ASCLIN *)ASCLIN_BASE ;

  Mcal_ResetENDINIT();
  psASCLIN0->CLC.U =  0x00000000;
  while(psASCLIN0->CLC.U) ;
  Mcal_SetENDINIT();

  psASCLIN0->CSR.B.CLKSEL = ASCLIN_CSR_CLKSEL_NOCLK ;
  for (i=0;i<1000;i++)
  {;}
  /* select the operation mode (INIT)*/
  psASCLIN0->FRAMECON.B.MODE  =  ASCLIN_FRAMECON_MODE_INIT  ;
  for (i=0;i<1000;i++)
  {;}
  /* activate the clock source */
  psASCLIN0->CSR.B.CLKSEL       =  ASCLIN_CSR_CLKSEL ;

  /* provide delay of 2-fA clock cycles */
  for (i=0; i< 1000; i++)
  {;}

  /* deactivate the clock source */
  psASCLIN0->CSR.B.CLKSEL       = ASCLIN_CSR_CLKSEL_NOCLK ;
  for (i=0;i<1000;i++)
  {;}
   psASCLIN0->FRAMECON.B.MODE =  ASCLIN_FRAMECON_MODE_ASC ;
  for (i=0;i<1000;i++)
  {;}
    /* activate the clock source */
  psASCLIN0->CSR.B.CLKSEL       =  ASCLIN_CSR_CLKSEL ;

  /* provide delay of 2-fA clock cycles */
  for (i=0; i< 1000; i++)
  {;}

  /* deactivate the clock source */
  psASCLIN0->CSR.B.CLKSEL =  ASCLIN_CSR_CLKSEL_NOCLK ;
  /* select 1 stop bit */
  psASCLIN0->FRAMECON.B.MSB = 0U;
  psASCLIN0->FRAMECON.B.LEAD = 0U;
  psASCLIN0->FRAMECON.B.IDLE = 0;
  psASCLIN0->FRAMECON.B.PEN  = 0U;

  psASCLIN0->FRAMECON.U |= (1U << 9);

  psASCLIN0->DATCON.B.DATLEN = ASCLIN_DATCON_DATLEN;

    /* rx fifo inlet enable, rx fifo outlet width */
  psASCLIN0->RXFIFOCON.B.OUTW = ASCLIN_RXFIFOCON_INW_VAL ;
  psASCLIN0->RXFIFOCON.B.ENI = ASCLIN_RXFIFOCON_ENO_EN ;
  psASCLIN0->RXFIFOCON.B.FLUSH = 1 ;
  psASCLIN0->RXFIFOCON.B.INTLEVEL = 0;
  psASCLIN0->RXFIFOCON.B.BUF    = 0U;

  /* tx fifo inlet enable, tx fifo outlet width */
  psASCLIN0->TXFIFOCON.B.INW = ASCLIN_TXFIFOCON_INW_VAL ;
  psASCLIN0->TXFIFOCON.B.ENO = ASCLIN_TXFIFOCON_ENO_EN ;
  psASCLIN0->TXFIFOCON.B.FLUSH = 1 ;
  psASCLIN0->TXFIFOCON.B.INTLEVEL = 0;

  psASCLIN0->BITCON.U =
            (ASCLIN_BITCON_OVERSAMPLING << ASCLIN_BITCON_OVERSAMPLING_SHIFT)
          | (ASCLIN_BITCON_PRESCALAR << ASCLIN_BITCON_PRESCALAR_SHIFT)
          |(ASCLIN_BITCON_SAMPLEPOINT << ASCLIN_BITCON_SAMPLEPOINT_SHIFT)
          |(ASCLIN_BITCON_SM << ASCLIN_BITCON_SM_SHIFT);

  psASCLIN0->BRG.U = (ASCLIN_BRG_NUMERATOR << ASCLIN_BRG_NUMERATOR_SHIFT)
             | (ASCLIN_BRG_DENOMINATOR << ASCLIN_BRG_DENOMINATOR_SHIFT);

  /* Enable the digital glitch filter - number of microticks to sample
   * Microticks is CLKSEL/PRESCALAR i.e. 20MHz/20 = 1us
   */
  psASCLIN0->IOCR.B.DEPTH =  ASCLIN_IOCR_FILTER_DEPTH;

  #if(USE_ASCLIN1 == STD_ON)
  psASCLIN0->IOCR.B.ALTI =  0x2; /* ALT2 used. */
  #else
  psASCLIN0->IOCR.B.ALTI =  0x1; /* ALT1 used. */
  #endif

  /* activate the clock source - 20MHz Crystal */
  psASCLIN0->CSR.B.CLKSEL =  ASCLIN_CSR_CLKSEL;

    /* clear the interrupt event flags*/
  psASCLIN0->FLAGSCLEAR.U =  ASCLIN_FLAGSCLEAR_MASK;

}
/*******************************************************************************
** Syntax : void erase_line(char *p_line,uint32 pos)                          **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in): p_line , pos                                              **
**                                                                            **
** Parameters (out): void                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : This function used to erase the present received line        **
*******************************************************************************/
void erase_line(char *p_line, uint32 *pos)
{
  uint32 cnt;

  for(cnt=0;cnt<*pos;cnt++)
  {
    *p_line = 0;
    p_line++;
    put_char(BACKSPACE);
    put_char(' ');
    put_char(BACKSPACE);
  }
  *pos = 0;
}
/*******************************************************************************
** Syntax : void put_buffer(char *p_line, uint32 n_max,const
                             char *p_str,uint32 *pos)                         **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in): p_line, n_max , p_str , pos                               **
**                                                                            **
** Parameters (out): void                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : This function fill buffer and send to terminal the string    **
*******************************************************************************/
void put_buffer(char *p_line, uint32 n_max,const char *p_str,uint32 *pos)
{
/*  uint32 cnt;

  cnt = *pos; */
  while(*pos < n_max && *p_str !=0)
  {
    *p_line = *p_str;
    put_char(*p_str);
    p_line++;
    p_str++;
    (*pos)++;
  }
  /* *pos = cnt; */
}

/*******************************************************************************
** Syntax : uint32 getlineWithPos(char *p_line, uint32 n_max, uint32 pos)     **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in): p_line , n_max , pos                                      **
**                                                                            **
** Parameters (out): uint32: new char arrived is TAB or CR                    **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : This function used to Read input from communication Port     **
*******************************************************************************/
int getlineWithPos(char *p_line, uint32 n_max, uint32 *pos)
{
   uint32 w_cnt;
   uint32 ret_val;
   int w_key;

   w_cnt = *pos;
   p_line += *pos;
   ret_val = 0;


   do
   {
     w_key = get_ch();
     if (w_key == -1)
     {
        ret_val = 0;
     }
     else
     {
        if (w_key == CR || w_key == LF)
        {
           *p_line = 0;
           ret_val = CR;
        }
        else
        {

           if (w_key == TAB)
           {
              *p_line = 0; /* set the value to 0 so that the first part of the string can be analyzed */
              ret_val = TAB;
           }
           else
           {
              if (w_key == BACKSPACE || w_key == DEL)
              {
                 /* backspace or delete */

                 if (w_cnt != 0)

                 {
                    /* delete character */
                    w_cnt--;
                    p_line--;
                    put_char(BACKSPACE);
                    put_char(' ');
                    put_char(BACKSPACE);
                 }
              }
              else
              {
                 if ((w_key != CNTLQ) && (w_key != CNTLS))
                 {
                    /* normal character*/
                    {
                       /* store/reflect character */
                       *p_line = (char)w_key;
                       put_char ((char)w_key);
                       p_line++;
                       w_cnt++;
                       if (w_cnt == n_max)
                       {
                          /* limit reached */
                          (void)beep();
                          /* delete all characters */
                          while (w_cnt != 0)
                          {
                             w_cnt--;
                             p_line--;
                             put_char(BACKSPACE);
                             put_char(' ');
                             put_char(BACKSPACE);

                          }
                       }
                    }
                 }
              }
           }
        }
     }
   }
   while ((w_key != CR) && (w_key != LF) && (w_key != BACKSPACE) && \
   (w_key != DEL) && (w_key != TAB));
   *pos = w_cnt;
   return(ret_val);
}
/*******************************************************************************
** Syntax : int get_char(void)                                                **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in):                                                           **
**                                                                            **
** Parameters (out): int                                                      **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : This function used to put the character to terminal          **
**               and waits till a char is entered.                            **
*******************************************************************************/
int get_char(void)
/*~-*/
{
   volatile uint32 rxdata;

   {

      /*~L*/
      /* Wait till RX fifo is NOT empty */

     while ((psASCLIN0->RXFIFOCON.B.FILL)  == 0)
     /*~-*/
     {
        /*~T*/
         delay();
     /*~-*/
     }
     /*~E*/
     /*~T*/
     /* get byte */
     rxdata = psASCLIN0->RXDATA.U;

     psASCLIN0->FLAGSCLEAR.U = ASCLIN_FLAGSCLEAR_MASK;

   }

   return rxdata;
/*~-*/
}

/*******************************************************************************
** Syntax : void put_char(char z)                                             **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in):                                                           **
**                                                                            **
** Parameters (out): void                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : This function sends a character to Communication Port.       **
*******************************************************************************/
void put_char(char z)
/*~-*/
{


  {

     /*~T*/
     /* send character */
     psASCLIN0->FLAGSCLEAR.U = ASCLIN_FLAGSCLEAR_MASK;
     psASCLIN0->TXDATA.U = (uint32)z;

     /*~I*/
     if (z == LF)
     /*~-*/
     {
        /*~L*/
        while ( (psASCLIN0->TXFIFOCON.B.FILL) != 0)
        /*~-*/
        {
           /*~T*/
           delay();

        /*~-*/
        }
        /*~E*/
        /*~T*/
        /* send CR */
        psASCLIN0->FLAGSCLEAR.U = ASCLIN_FLAGSCLEAR_MASK;
        psASCLIN0->TXDATA.U = CR;
     /*~-*/
     }
     /*~E*/
     /*~L*/
     while ( (psASCLIN0->TXFIFOCON.B.FILL ) != 0)
     /*~-*/
     {
        /*~T*/
        delay();
     /*~-*/
     }
     /*~E*/
     psASCLIN0->FLAGSCLEAR.U = ASCLIN_FLAGSCLEAR_MASK;


  }


/*~-*/
}

/*******************************************************************************
** Syntax : void buf_to_screen(char *text_buf)                                **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in):                                                           **
**                                                                            **
** Parameters (out): void                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : This function holds the Sting to be buffered to the          **
**               Communication Port.                                          **
*******************************************************************************/
void buf_to_screen(char *text_buf)
/*~-*/
{
   /*~L*/
   while (*text_buf != 0)
   /*~-*/
   {
      /*~T*/
      /* send character */
      put_char(*text_buf);
      text_buf++;

   /*~-*/
   }
   /*~E*/
/*~-*/
}

/*******************************************************************************
** Syntax : void print_f(const char *p_frm, ...)                              **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in):                                                           **
**                                                                            **
** Parameters (out): void                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : This function Prints a formatted string to the               **
**               Communication Port.                                          **
*******************************************************************************/
void print_f(const char *p_frm, ...)
/*~-*/
{
   /*~T*/
   va_list p_arg;

   /*~T*/
   va_start(p_arg, p_frm);
   vsprintf(ubOutputBuf,p_frm,p_arg);
   va_end(p_arg);
   buf_to_screen(ubOutputBuf);

/*~-*/
}

/*******************************************************************************
** Syntax : void getline(char *p_line, uint32 n_max)                          **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in): p_line and n_max                                          **
**                                                                            **
** Parameters (out): void                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : This function used to Read input from communication Port     **
*******************************************************************************/
void getline(char *p_line, uint32 n_max)

/*~-*/
{
   /*~T*/
   uint32 w_cnt;
   int w_key;

   /*~T*/
   w_cnt = 0;

   /*~U*/
   /*~-2*/
   do
   {
      /*~T*/
      w_key = get_char();
      /*~I*/
      if (w_key == CR || w_key == LF)

      /*~-*/
      {
         /*~T*/
         *p_line = 0;

      /*~-*/
      }
      /*~O*/
      /*~-2*/
      else
      {
         /*~I*/
         if (w_key == BACKSPACE || w_key == DEL)

         /*~-*/
         {
            /*~T*/
            /* backspace or delete */

            /*~I*/
            if (w_cnt != 0)

            /*~-*/
            {
               /*~T*/
               /* delete character */
               w_cnt--;
               p_line--;
               put_char(BACKSPACE);
               put_char(' ');
               put_char(BACKSPACE);

            /*~-*/
            }
            /*~E*/
         /*~-*/
         }
         /*~O*/
         /*~-2*/
         else
         {
            /*~I*/
            if ((w_key != CNTLQ) && (w_key != CNTLS))

            /*~-*/
            {
               /*~F*/
               /* normal character*/

               /*~-*/
               {
                  /*~T*/
                  /* store/reflect character */
                  *p_line = (char)w_key;
                  put_char ((char)w_key);
                  p_line++;
                  w_cnt++;

                  /*~I*/
                  if (w_cnt == n_max)
                  /*~-*/
                  {
                     /*~T*/
                     /* limit reached */
                     (void)beep();

                     /*~T*/
                     /* delete all characters */

                     /*~L*/
                     while (w_cnt != 0)
                     /*~-*/
                     {
                        /*~T*/
                        w_cnt--;
                        p_line--;
                        put_char(BACKSPACE);
                        put_char(' ');
                        put_char(BACKSPACE);

                     /*~-*/
                     }
                     /*~E*/
                  /*~-*/
                  }
                  /*~E*/
               /*~-*/
               }
               /*~E*/
            /*~-*/
            }
            /*~E*/
         /*~-*/
         }
         /*~E*/
      /*~-*/
      }
      /*~E*/
   /*~-*/
   }
   /*~O*/
   while ((w_key != CR) && (w_key != LF));
   /*~E*/
/*~-*/
}

/*******************************************************************************
** Syntax : int get_ch(void)                                                  **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value: int(ASCII value for the input character)                     **
**                                                                            **
** Description :This function reads a character from the Commucation port     **
**              and does not wait.                        **
*******************************************************************************/
int get_ch(void)
{
  uint32 c;

  if (psASCLIN0->RXFIFOCON.B.FILL  != 0)
  {
    c = (char)psASCLIN0->RXDATA.U ;
    psASCLIN0->FLAGSCLEAR.U = ASCLIN_FLAGSCLEAR_MASK;
    return c;
  }
  else
  {
    return (-1);
  }
}

/*******************************************************************************
** Syntax : void Continue(void)                                               **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in):                                                           **
**                                                                            **
** Parameters (out): void                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : This function waits to get input from communication Port     **
*******************************************************************************/
void Continue(void)
{
  char szString[4];
  do
    {
       print_f("\n<ENTER>to continue: ");
       getline(szString, sizeof szString - 1);
       if (*szString != 0)
       {
         (void)beep();
        }
     }
  while (*szString != 0);
}


/*******************************************************************************
** Syntax : char ParMenu(char *pszText, PAR_t *pstPar, uint32 uwParNum)       **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in):                                                           **
**                                                                            **
** Parameters (out): void                                                     **
**                                                                            **
** Return value: char                                                         **
**                                                                            **
** Description : This function used to check Parameter size and type.         **
*******************************************************************************/
char ParMenu(char *pszText, PAR_t *pstPar, uint32 uwParNum)
{
  char szString[81];
  PAR_t *pst;
  uint32 uwData;
  uint32 uwId;

  do
   {
      print_f("\nParameters for %s:\n", pszText);
      pst = pstPar;
      for (uwId = 0; uwId < uwParNum; uwId++)
      {
         print_f("<%d>%s: ", uwId, pst->szText);
         pst = pstPar + uwId;
         switch (pst->uwSize)
         {
            case 1:
            {
               print_f(pst->szOutputFormat, (uint32)*(uint8 *)pst->pvData);
               break;
            }
            case 2:
            {
               print_f(pst->szOutputFormat, (uint32)*(uint16 *)pst->pvData);
               break;
            }
            case 4:
            {
               print_f(pst->szOutputFormat, *(uint32 *)pst->pvData);
               break;
            }
            default:
            {
               print_f("\nINTERNAL ERROR - INVALID PARAMETER SIZE\n");
               return 'q';
            }
         }
         print_f("\n");
         pst++;
      }
      print_f("\n<Id Data> or <q>uit or <ENTER>continue: ");
      getline(szString, sizeof szString - 1);
      if ((*szString !='q') && (*szString != 0))
       {
         if (sscanf(szString, "%ld", &uwId) && (uwId < uwParNum))
         {
            pst = pstPar + uwId;
            switch (pst->uwType)
            {
               case PAR_TYP_DEC:
               {
                  if (sscanf(szString, "%ld %ld", &uwId, &uwData) == 2)
                  {
                      if (((sint32)uwData >= (sint32)pst->uwMin) &&
                                ((sint32)uwData <= (sint32)pst->uwMax))
                     {
                        switch (pst->uwSize)
                        {
                           case 1:
                             {
                                 *(sint8 *)pst->pvData = (sint8)uwData;
                              break;
                           }
                           case 2:
                           {
                              *(sint16 *)pst->pvData = (sint16)uwData;
                              break;
                           }
                           case 4:
                           {
                              *(sint32 *)pst->pvData = (sint32)uwData;
                              break;
                           }
                           default:
                           {
                              print_f("\nINTERNAL ERROR - INVALID PARAMETER \
                                                  SIZE\n");
                              return 'q';
                           }
                        }
                     }
                     else
                     {
                        (void)beep();
                     }
                  }
                  else
                  {
                     (void)beep();

                  }
                  break;
               }
               case PAR_TYP_HEX:
               {
                  if (sscanf(szString, "%ld %lx", &uwId, &uwData) == 2)
                  {
                     if ((uwData >= pst->uwMin) && (uwData <= pst->uwMax))
                     {
                        switch (pst->uwSize)
                        {
                           case 1:
                           {
                              *(uint8 *)pst->pvData = (uint8)uwData;
                              break;
                           }
                           case 2:
                           {
                              *(uint16 *)pst->pvData = (uint16)uwData;
                              break;
                           }
                           case 4:
                           {
                              *(uint32 *)pst->pvData = (uint32)uwData;
                              break;
                           }

                           default:
                           {
                               print_f("\nINTERNAL ERROR - INVALID PARAMETER \
                                                  SIZE\n");
                              return 'q';
                           }
                        }
                     }
                     else
                     {
                        (void)beep();
                     }
                  }
                  else
                  {
                     (void)beep();
                  }
                  break;
               }

               default:
               {
                  (void)beep();
                  print_f("\nINTERNAL ERROR - INVALID PARAMETER TYPE\n");
                  return 'q';
               }

            }
         }
         else
         {
            (void)beep();
         }
      }
   }
   while ((*szString !='q') && (*szString != 0));

   print_f("\n\n");

   return *szString;
}

/*******************************************************************************
** Syntax : void Print_Configuration(uint32 config)                           **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in):   config                                                  **
**                                                                            **
** Parameters (out): void                                                     **
**                                                                            **
** Return value: void                                                         **
**                                                                            **
** Description : This function used  to print system clock frequency          **
*******************************************************************************/
void Print_Configuration(uint32 config)
{
/*  print_f("Osc_Clock: %d, Sys_Clock:%d, Per_Clock:%d\n", Clk_Freq, uwSysFreq,
                                uwPerFreq);
*/
  /* this line is provided to remove unused param warning in GNU */
  UNUSED_PARAMETER(config)
}


/*******************************************************************************
** Syntax : void ClearBuffer(uint32* buf, uint32 size)                        **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in):   buf and size                                            **
**                                                                            **
** Parameters (out): void                                                     **
**                                                                            **
** Return value: void                                                         **
**                                                                            **
** Description : This function used to clear the given buffer               **
*******************************************************************************/
void ClearBuffer(uint32* buf, uint32 size)
{
  uint32 m;
  for(m=0;m<size;m++)
  {
    buf[m] = 0U;
  }
}

/*******************************************************************************
** Syntax : void SetBuffer(uint32* buf, uint32 size, uint32 seed)             **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in):   buf,size and seed                                       **
**                                                                            **
** Parameters (out): void                                                     **
**                                                                            **
** Return value: void                                                         **
**                                                                            **
** Description : This function used to write the given value in to the buffer **
*******************************************************************************/
void SetBuffer(uint32* buf, uint32 size, uint32 seed)
{
  uint32 m;
  for(m=0;m<size;m++)
  {
    buf[m] =  (uint32)( (size/10 * (m+3)) + (seed*(m+1))) ;
  }
}

/*******************************************************************************
** Syntax : void print_flushfifo()                                            **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in):   none                                                    **
**                                                                            **
** Parameters (out): void                                                     **
**                                                                            **
** Return value: void                                                         **
**                                                                            **
** Description : This function flushes TX and RX FIFO of ASCLIN               **
*******************************************************************************/
void print_flushfifo(void)
{
  psASCLIN0->RXFIFOCON.B.FLUSH = 1 ;
  psASCLIN0->TXFIFOCON.B.FLUSH = 1 ;
}


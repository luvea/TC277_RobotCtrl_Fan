
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2015)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : Mcal.c $                                                   **
**                                                                            **
**   $CC VERSION : \main\77 $                                                 **
**                                                                            **
**   $DATE       : 2016-10-06 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : This file contains the startup code, endinit protection    **
**                 functions                                                  **
**                                                                            **
**   SPECIFICATION(S) :  NA                                                   **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of Std_Types.h */
#include "Std_Types.h"
#include "IfxCpu_reg.h"
#include "IfxScu_reg.h"
#include "IfxFlash_reg.h"
/* Inclusion of Mcal.h */
#include "Mcal.h"
#include "Mcal_Options.h"
#if (IFX_MCAL_USED == STD_ON)
/* Inclusion of EcuM.h */
#include "EcuM.h"
#endif
/* Inclusion of Test_Print.h */
#include "Test_Print.h"
/* Inclusion of Irq.h */
#include "Irq.h"

#if (IFX_MCAL_USED == STD_ON)
#include "DemoApp_Cfg.h"
#endif
#if 0
#if (GPT_DELIVERY == STD_ON)
#include "Gpt.h"
#include "Gpt_Demo.h"
#endif
#if (DIO_DELIVERY == STD_ON)
#include "Dio_Demo.h"
#endif

#if (WDG_DELIVERY == STD_ON)
#include "Wdg_17_Scu_Demo.h"
#include "Wdg_17_Scu.h"
#endif
#endif
/* #if (GPT_DELIVERY == STD_ON) */

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define TRICORE_VERSION    (16U)


#define CPU_PSW_USER_MODE_MASK (0xFFFFF3FFU)
#define SET_USER_MODE_MASK ((1U  <<  10U))

#if (TRICORE_VERSION == 16U)
#define PCON0_PCBYP        (0x02U)
#define PCON0_NOPCBYP      (0x00U)
#define PCON1_PCINV        (0x01U)
#define PCON2_PCACHE_SIZE   (0x0008U)     /* Size = 8KB */
#define PCON2_PSCRATCH_SIZE (0x080000U)   /* Size = 8KB */
#define DCON2_DCACHE_SIZE   (0x0000U)     /* Size = 0KB */
#define DCON2_DSCRATCH_SIZE (0x700000U)   /* Size = 112KB */
#endif /* #if (TRICORE_VERSION == 16U) */

#define STACK_ALIGN (0xfffffff8U)
#define MCAL_CORE_ID_MASK   (0x7U)


#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)
#define DEBUG()  __debug()
#endif /* #if (_TASKING_C_TRICORE_ == 1U) */
#endif

#ifdef _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)
#define DEBUG() __asm__ volatile ("debug")
#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#endif

#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
#define DEBUG() __debug()
#define __debug _debug
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif


/*******************************************************************************
Preprocessor definations for the Start Up Routine.
  - if defined the Option is Enabled
  - if not defined the Option is Disabled
*******************************************************************************/
#define MCAL_CALL_DEMOAPP

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Functon Definitions                            **
*******************************************************************************/
#if (IFX_SAFETLIB_USED == STD_ON)
extern void SafeTlib_main(uint8 CoreId);
extern void SAFET_core1_RunTimeTest(void);
extern void SAFET_core2_RunTimeTest(void);
#endif

#if (OS_DELIVERY == STD_ON)
extern void Ifx_OSTask_ApplicationInit(void);
#endif

#ifdef MCAL_CALL_DEMOAPP
extern __indirect void DemoApp(void);
#endif



/*
 With the following preprocessor definations, the code gets Enabled
*/
/* For CrossView utilty function */
/*#define _SYNC_ON_HALT*/

/*
With the following preprocessor definations, the code gets disabled
*/

/*
 Re-enable and reset the call depth counter and  make A0,A1,A8,A9
 write-able. It is required for CrossView that these RESET values are
 restored for each time the startup code is executed.
*/
/*#define _NO_PSW_RESET*/

/*
 user stack initialisation
*/
/*#define _NO_USP_INIT*/

/*
 Clear Previous Context Pointer Segment Address and Offset Field.
 It is required for CrossView stack trace that these RESET values
 are restored for each time the startup code is executed.
*/
/*#define _NO_PCX_RESET*/

/*
 Context Switch Area initialisation
*/
/*#define _NO_CSA_INIT*/

/*
 disable watchdog
*/
/*#define NO_WATCHDOG_DISABLE*/

/*
 Load Base Address of Trap Vector Table
 Disable this if not started from RESET vector. (E.g.
 ROM monitors require to keep in control of vectors)
*/
/*#define _NO_BTV_INIT*/

/*
 Load Base Address of Interrupt Vector Table
 Disable this if not started from RESET vector. (E.g.
 ROM monitors require to keep in control of vectors)
*/
/*#define _NO_BIV_INIT*/

/*
 Load interupt stack pointer
 Disable this if not started from RESET vector. (E.g.
 ROM monitors require to keep in control of vectors)
*/
/*#define _NO_ISP_INIT*/

/*
 Wait States for read access to PFlash is 6
 Wait states for Pflash access with wordline hit should be same as WSPFlash
 Wait States for read access to DFlash is 6
*/
/*#define _NO_FLASH_CONF*/

/*
 Inititialize global address registers a0/a1 to support
 __a0/__a1 storage qualifiers of the C compiler.
*/
/*#define _NO_A0A1_ADDRESSING*/

/*
 Inititialize global address registers a8/a9 to support
 __a8/__a9 storage qualifiers of the C compiler. A8 and A9
 are reserved for OS use, or for application use in cases
 where the application ans OS are tightly coupled.
*/
#define _NO_A8A9_ADDRESSING

/*
 Initialize Bus configuration registers
*/
/*#define _NO_BUS_CONF*/

/*
 Initialize and clear C variables
*/
/*#define _NO_C_INIT*/

/*
 Enable ICACHE
*/
#define _ENABLE_ICACHE

/*
 Enable DCACHE
*/
/* #define _ENABLE_DCACHE */

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

typedef struct {
  uint32 StackEndAddress;
  uint32 CsaStartAddress;
  uint32 CsaEndAddress;
  uint32 *TrapFn;
  uint32 IStackAddress;
  uint32 SmallData0;
  uint32 SmallData2;
  uint32 CopyTable;  /* Start Address in case of Diab */
  uint32 ClearTable; /* End Address in case of Diab */
  void (*CoreFn)(void);
}Mcal_CoreInit_t;


/* BMI Header to be placed at location 0xA0000000 */
typedef struct 
{
  uint32 stadabm;       /*User Code Start Address                             */
  uint16 bmi;           /*Boot Mode Index (BMI)                               */
  uint16 bmhdid;        /*Boot Mode Header ID B359H                           */
  uint32 chkstart;      /*Memory Range to be checked - Start Address          */
  uint32 chkend;        /*Memory Range to be checked - End Address            */
  uint32 crcrange;      /*Check Result for the Memory Range                   */
  uint32 crcrangeinv;   /*Inverted Check Result for the Memory Range          */
  uint32 crchead;       /*Check Result for the ABM Header (offset 00H..17H)   */
  uint32 crcheadinv;    /*Inverted Check Result for the ABM Header            */
}BMD_HDR;

/*******************************************************************************
**                      Imported Function Declarations                        **
*******************************************************************************/
#ifdef _SYNC_ON_HALT
void _sync_on_halt(void);    /* CrossView utilty function */
#endif

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/* Mcal specific startup code */
#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
__attribute__((use_frame_pointer)) void _Mcal_Start(void) ;
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#else
void _Mcal_Start(void) ;
#endif
#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)
void _START(void) ;          /* app init start address */
void _Exit(void) ;           /* exit return address */
/* C initialization function */
void _c_init(uint32 CoreNumber, uint32 Copytable) ;         
#ifdef _DEFINE_CALL_ENDINIT
void  _CALL_ENDINIT(void) ;  /* User definition function */
#endif

#ifdef _DEFINE_CALL_INIT
void   _CALL_INIT(void) ;    /* User definition function */
#endif
#endif /*(_TASKING_C_TRICORE_ == 1U)*/
#endif /* _TASKING_C_TRICORE_ */

#ifdef _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)
void _Gnu_CopyTable(uint32 Cleartable, uint32 CopyTable);
#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#endif

void Mcal_Core0Container(void);
#if ( MCAL_NO_OF_CORES > 1U )
void Mcal_Core1Container(void);
#if ( MCAL_NO_OF_CORES == 3U )
void Mcal_Core2Container(void);
#endif /* ( MCAL_NO_OF_CORES == 3U ) */
#endif /* ( MCAL_NO_OF_CORES > 1U ) */

extern __indirect void Test_InitTime(void);
extern void DemoApp_CallMenuFctCpu1 (void);
extern void DemoApp_CallMenuFctCpu2 (void);

/* interface to set/reset endinit of CPU/Safety watchdog */
static void safety_endinit_reset(void); 
static void safety_endinit_set  (void);
static void endinit_reset  (void);
static void endinit_set  (void);

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
#if (IFX_MCAL_USED == STD_ON)
#define BMD_HDR_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#else
#define IFX_BMD_HDR_START_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"
#endif


const BMD_HDR Bmiheader = 
{
  0x80000020,
  0x0370,
  0xB359,
  0x00000000,
  0x00000000,
  0x00000000,
  0x00000000,
  0x49E9B5B4,
  0xB6164A4B 
};

#if (IFX_MCAL_USED == STD_ON)
#define BMD_HDR_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#else
#define IFX_BMD_HDR_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"
#endif

#if (IFX_MCAL_USED == STD_ON)
#define MCAL_START_SEC_VAR_FAST_32BIT
#include "MemMap.h"
#else
#define IFX_MCAL_START_SEC_VAR_FAST_32BIT_ASIL_B
#include "Ifx_MemMap.h"
#endif

#if defined (_GNU_C_TRICORE_) || defined (_DIABDATA_C_TRICORE_)
#if (_GNU_C_TRICORE_ == 1U) || (_DIABDATA_C_TRICORE_ == 1U)
static uint32 Mcal_SmallDataAddress;
static uint32 Mcal_LiteralDataAddress;
static uint32* Mcal_StackEndAddress;
#endif /* #if (_GNU_C_TRICORE_ == 1U) || (_DIABDATA_C_TRICORE_ == 1U) */
#endif

#if ( MCAL_NO_OF_CORES > 1U )
/* Semaphore to signal the completed of Init sequence of different Cores */
/* Element 0 signifies CPU0 -> This signifies if EcuM Init is completed by CPU0
   Element 1 signifies CPU1 -> This signifies if CPU1 startup code is executed
   Element 1 signifies CPU1 -> This signifies if CPU1 startup code is executed
   This is implemented as an array to prevent parallel updation by seperate
   cores
*/

volatile uint32  Mcal_CpuInitCompletedSem[MCAL_NO_OF_CORES] __at(0x60000000);
#endif

#if (IFX_MCAL_USED == STD_ON)
#define MCAL_STOP_SEC_VAR_FAST_32BIT
#include "MemMap.h"
#else
#define IFX_MCAL_STOP_SEC_VAR_FAST_32BIT_ASIL_B
#include "Ifx_MemMap.h"
#endif


#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)
extern void cpu0_trap_0 (void); /* trap table */
extern void inttab (void);      /* interrupt table */

extern uint8 * _SMALL_DATA_ ;       /* centre of A0 addressable area */
extern uint8 * _SMALL_DATA_TC1;
extern uint8 * _SMALL_DATA_TC2;
extern uint8 * _LITERAL_DATA_ ;     /* centre of A1 addressable area */
extern uint8 * _LITERAL_DATA_TC1;
extern uint8 * _LITERAL_DATA_TC2;
extern uint8 * _A8_DATA_ ;          /* centre of A8 addressable area */
extern uint8 * _A9_DATA_ ;          /* centre of A9 addressable area */
extern uint8 * _lc_ub_table ;
extern uint8 * _lc_ub_table_tc1 ;
extern uint8 * _lc_ub_table_tc2 ;

extern uint8 __far * _lc_ue_ustack_tc0 ; /* user stack end */
extern uint8 __far * _lc_ue_ustack_tc1 ; /* user stack end */
extern uint8 __far * _lc_ue_ustack_tc2 ; /* user stack end */
extern uint8 __far * _lc_ub_csa_01 ;       /* context save area begin */
extern uint8 __far * _lc_ue_csa_01 ;       /* context save area end */
extern uint8 __far * _lc_ue_csa_tc0 ;       /* context save area end */
extern uint8 __far * _lc_ue_csa_tc1 ;       /* context save area end */
extern uint8 __far * _lc_ue_csa_tc2 ;       /* context save area end */
extern uint8 __far * _lc_ub_csa_tc0 ;       /* context save area end */
extern uint8 __far * _lc_ub_csa_tc1 ;       /* context save area end */
extern uint8 __far * _lc_ub_csa_tc2 ;       /* context save area end */


extern uint8 __far * _lc_u_trap_tab_tc0; /* trap table */
extern uint8 __far * _lc_u_trap_tab_tc1; /* trap table */
extern uint8 __far * _lc_u_trap_tab_tc2; /* trap table */

extern uint8 __far * _lc_u_int_tab ; /* interrupt table */
extern uint8 __far * _lc_ue_istack_tc0 ; /* interrupt stack end */
extern uint8 __far * _lc_ue_istack_tc1 ; /* interrupt stack end */
extern uint8 __far * _lc_ue_istack_tc2 ; /* interrupt stack end */

extern uint32 __far  *_lc_cp ;       /* copy table (cinit) */
#if (ECUM_POSTBUILD_CONFIG_TYPE == ECUM_LOADABLE)
extern uint32 __far *_lc_gb_FLS_STATE_VAR ; /* FLS state variable */
#endif
#define __INTTAB _lc_u_int_tab
#define __TRAPTAB cpu0_trap_0
#define __CPU0_ISTACK (&_lc_ue_istack_tc0)
#define __CPU1_ISTACK (&_lc_ue_istack_tc1)
#define __CPU2_ISTACK (&_lc_ue_istack_tc2)

#define __CPU0_TRAPTAB (&_lc_u_trap_tab_tc0)
#define __CPU1_TRAPTAB (&_lc_u_trap_tab_tc1)
#define __CPU2_TRAPTAB (&_lc_u_trap_tab_tc2)

#define __CPU0_USTACK (&_lc_ue_ustack_tc0)
#define __CPU1_USTACK (&_lc_ue_ustack_tc1)
#define __CPU2_USTACK (&_lc_ue_ustack_tc2)

#define CPU0_BASE_MEM_ADRRESS     (0x70000000U)
#define CPU1_BASE_MEM_ADRRESS     (0x60000000U)
#define CPU2_BASE_MEM_ADRRESS     (0x50000000U)
#define CPUX_BASE_MEM_ADDR_MASK   (0xF0000000U)
#endif /* #if (_TASKING_C_TRICORE_ == 1U) */

#elif defined(_GNU_C_TRICORE_)
#if (_GNU_C_TRICORE_ == 1U)

extern void cpu0_trap_0 (void); /* trap table */
extern void cpu1_trap_0 (void); /* trap table */
extern void cpu2_trap_0 (void); /* trap table */
extern void inttab (void);      /* interrupt table */

extern void *__CPU0_USTACK;          /* user stack end */
extern void *__CPU1_USTACK;          /* user stack end */
extern void *__CPU2_USTACK;          /* user stack end */

extern void *__INTTAB_CPU0;          /* interrupt vector table */

extern uint32 __CPU0_ISTACK[];       /* interrupt stack end */
extern uint32 __CPU1_ISTACK[];       /* interrupt stack end */
extern uint32 __CPU2_ISTACK[];       /* interrupt stack end */

extern void *__CPU0_SMALL_DATA;      /* centre of A0 addressable area */
extern void *__CPU1_SMALL_DATA;      /* centre of A0 addressable area */
extern void *__CPU2_SMALL_DATA;      /* centre of A0 addressable area */

extern void *__CPU0_SMALL_DATA2;     /* centre of A1 addressable area */
extern void *__CPU1_SMALL_DATA2;     /* centre of A1 addressable area */
extern void *__CPU2_SMALL_DATA2;     /* centre of A1 addressable area */

extern void *_SMALL_DATA3_;     /* centre of A8 addressable area */
extern void *_SMALL_DATA4_;     /* centre of A9 addressable area */

extern uint32 __shared_clear_table[];  /* clear table entry */
extern uint32 __cpu0_clear_table[];  /* clear table entry */
extern uint32 __cpu1_clear_table[];  /* clear table entry */
extern uint32 __cpu2_clear_table[];  /* clear table entry */


extern uint32 __shared_copy_table[];   /* copy table entry */
extern uint32 __cpu0_copy_table[];   /* copy table entry */
extern uint32 __cpu1_copy_table[];   /* copy table entry */
extern uint32 __cpu2_copy_table[];   /* copy table entry */


extern uint32 __CPU0_CSA_BEGIN[];    /* context save area 1 begin */
extern uint32 __CPU0_CSA_END[];      /* context save area 1 begin */
extern uint32 __CPU1_CSA_BEGIN[];    /* context save area 1 begin */
extern uint32 __CPU1_CSA_END[];      /* context save area 1 begin */
extern uint32 __CPU2_CSA_BEGIN[];    /* context save area 1 begin */
extern uint32 __CPU2_CSA_END[];      /* context save area 1 begin */



#define __INTTAB __INTTAB_CPU0
#define __CPU0_TRAPTAB (uint32*)cpu0_trap_0
#define __CPU1_TRAPTAB (uint32*)cpu1_trap_0
#define __CPU2_TRAPTAB (uint32*)cpu2_trap_0

#define __setareg(areg,val) \
{ \
  __asm volatile (" movh.a\t %%"#areg",hi:"#val"\n\tlea\t %%"#areg",\
                                        [%%"#areg"]lo:"#val"" : : : "memory"); \
}

#define __setreg(areg,val) \
{ \
  __asm volatile ("mov.aa %%"#areg", %0" :: "a" (val)); \
}


__asm ("\t .weak _SMALL_DATA3_,_SMALL_DATA4_");

#endif /* #if (_GNU_C_TRICORE_ == 1U) */

#elif defined(_DIABDATA_C_TRICORE_)
#if (_DIABDATA_C_TRICORE_ == 1U)
/* first trap table */
extern void cpu0_trap_0 (void) __attribute__ ((section (".cpu0_trap_0")));
extern void cpu1_trap_0 (void) __attribute__ ((section (".cpu1_trap_0")));
extern void cpu2_trap_0 (void) __attribute__ ((section (".cpu2_trap_0")));
/* interrupt table */
extern void inttab (void) __attribute__ ((section (".inttab")));
void _init_main(uint32 CoreNumber, uint32 Copytable);
void copy_to_ram(void);
extern uint32 __INTTAB_CPU0;          /* interrupt vector table */

extern char __COPY_TABLE_BEGIN__[], __COPY_TABLE_END__[];
extern char _cpu0_copytable[], _cpu0_copytable__END__[];
extern char _cpu1_copytable[], _cpu1_copytable__END__[];
extern char _cpu2_copytable[], _cpu2_copytable__END__[];


__asm ("\t .weak __COPY_TABLE_BEGIN__, __COPY_TABLE_END__");
__asm ("\t .weak _cpu0_copytable, _cpu0_copytable__END__");
__asm ("\t .weak _cpu1_copytable, _cpu1_copytable__END__");
__asm ("\t .weak _cpu2_copytable, _cpu2_copytable__END__");

extern void __init(void);
char **environ;    /* used by getenv(), putenv()    */
extern char     *__argv[];
extern char     *__env[];

#define __INTTAB __INTTAB_CPU0
#define __CPU0_TRAPTAB (uint32*)cpu0_trap_0
#define __CPU1_TRAPTAB (uint32*)cpu1_trap_0
#define __CPU2_TRAPTAB (uint32*)cpu2_trap_0
#define _SMALL_DATA3_ __SDA8_BASE
#define _SMALL_DATA4_ __SDA9_BASE

extern uint32 __CPU0_CSA_BEGIN[];    /* context save area 1 begin */
extern uint32 __CPU0_CSA_END[];      /* context save area 1 begin */
extern uint32 __CPU1_CSA_BEGIN[];    /* context save area 1 begin */
extern uint32 __CPU1_CSA_END[];      /* context save area 1 begin */
extern uint32 __CPU2_CSA_BEGIN[];    /* context save area 1 begin */
extern uint32 __CPU2_CSA_END[];      /* context save area 1 begin */

extern uint32 const __CPU0_USTACK;          /* user stack end */
extern uint32 const __CPU1_USTACK;          /* user stack end */
extern uint32 const __CPU2_USTACK;          /* user stack end */


extern uint32 __CPU0_ISTACK[];       /* interrupt stack end */
extern uint32 __CPU1_ISTACK[];       /* interrupt stack end */
extern uint32 __CPU2_ISTACK[];       /* interrupt stack end */

extern uint32 __CPU0_SMALL_DATA;      /* centre of A0 addressable area */
extern uint32 __CPU1_SMALL_DATA;      /* centre of A0 addressable area */
extern uint32 __CPU2_SMALL_DATA;      /* centre of A0 addressable area */

extern uint32 __CPU0_SMALL_DATA2;     /* centre of A1 addressable area */
extern uint32 __CPU1_SMALL_DATA2;     /* centre of A1 addressable area */
extern uint32 __CPU2_SMALL_DATA2;     /* centre of A1 addressable area */

extern uint32 __SOURCE[];
extern uint32 __END_SOURCE[];
extern uint32 __DESTINATION[];



__asm ("\t .weak __SDA8_BASE, __SDA9_BASE");

#define __setareg(areg,val) ___setareg(areg,val)
/* we need to use a15 for the address register and not direct that the compiler
    this will not remove */
#define ___setareg(areg,val) \
  { __asm("#$$bp");                \
          __asm ("  movh.a\t %a15,"#val"@ha\n"); \
    __asm ("  lea\t %a15,[%a15]"#val"@l\n"); \
    __asm ("  mov.aa %"#areg", %a15\n"); \
    __asm ("#$$ep"); }


#define __setreg(areg,val) \
{ __asm("#$$bp"); \
  __asm ("ld.w %d0, "#val"@abs"); \
  __asm ("mov.a %"#areg", %d0"); \
  __asm ("#$$ep"); }
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */

#else
#pragma error "No Compiler specified."
#endif

/* Semaphore Operations */
#define MCAL_SET_SEMAPHORE(Sem)   (Sem = 1U)
#define MCAL_CLEAR_SEMAPHORE(Sem) (Sem = 0U)

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
#if (IFX_MCAL_USED == STD_ON)
#define MCAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#else
#define IFX_MCAL_START_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"
#endif

#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)
const Mcal_CoreInit_t Mcal_CoreInit[MCAL_NO_OF_CORES] = {
  {
    (uint32)__CPU0_USTACK,
    (uint32)&_lc_ub_csa_tc0,
    (uint32)&_lc_ue_csa_tc0,
    (uint32*)__CPU0_TRAPTAB,
    (uint32)__CPU0_ISTACK,
    (uint32)&_SMALL_DATA_,
    (uint32)&_LITERAL_DATA_,
    (uint32)&_lc_ub_table,
    0,
    &Mcal_Core0Container
#if ( MCAL_NO_OF_CORES > 1U )      
  },
  {
    (uint32)__CPU1_USTACK,
    (uint32)&_lc_ub_csa_tc1,
    (uint32)&_lc_ue_csa_tc1,
    (uint32*)__CPU1_TRAPTAB,
    (uint32)__CPU1_ISTACK,
    (uint32)&_SMALL_DATA_TC1,
    (uint32)&_LITERAL_DATA_TC1,
    (uint32)&_lc_ub_table,
    0,
    &Mcal_Core1Container
#if ( MCAL_NO_OF_CORES == 3U )   
  },
  {
    (uint32)__CPU2_USTACK,
    (uint32)&_lc_ub_csa_tc2,
    (uint32)&_lc_ue_csa_tc2,
    (uint32*)__CPU2_TRAPTAB,
    (uint32)__CPU2_ISTACK,
    (uint32)&_SMALL_DATA_TC2,
    (uint32)&_LITERAL_DATA_TC2,
    (uint32)&_lc_ub_table,
    0,
    &Mcal_Core2Container
#endif /* ( MCAL_NO_OF_CORES == 3U )  */ 
#endif /* ( MCAL_NO_OF_CORES > 1U )  */
  }
};
#endif /* #if (_TASKING_C_TRICORE_ == 1U) */
#elif defined(_GNU_C_TRICORE_)
#if (_GNU_C_TRICORE_ == 1U)
Mcal_CoreInit_t const Mcal_CoreInit[MCAL_NO_OF_CORES] = {
  {
    (uint32)&__CPU0_USTACK,
    (uint32)__CPU0_CSA_BEGIN,
    (uint32)__CPU0_CSA_END,
    __CPU0_TRAPTAB,
    (uint32)__CPU0_ISTACK,
    (uint32)&__CPU0_SMALL_DATA,
    (uint32)&__CPU0_SMALL_DATA2,
    (uint32)__cpu0_copy_table,
    (uint32)__cpu0_clear_table,
    &Mcal_Core0Container
#if ( MCAL_NO_OF_CORES > 1U )    
  },
  {
    (uint32)&__CPU1_USTACK,
    (uint32)__CPU1_CSA_BEGIN,
    (uint32)__CPU1_CSA_END,
    __CPU1_TRAPTAB,
    (uint32)__CPU1_ISTACK,
    (uint32)&__CPU1_SMALL_DATA,
    (uint32)&__CPU1_SMALL_DATA2,
    (uint32)__cpu1_copy_table,
    (uint32)__cpu1_clear_table,
    &Mcal_Core1Container
#if ( MCAL_NO_OF_CORES == 3U )   
  },
  {
    (uint32)&__CPU2_USTACK,
    (uint32)__CPU2_CSA_BEGIN,
    (uint32)__CPU2_CSA_END,
    __CPU2_TRAPTAB,
    (uint32)__CPU2_ISTACK,
    (uint32)&__CPU2_SMALL_DATA,
    (uint32)&__CPU2_SMALL_DATA2,
    (uint32)__cpu2_copy_table,
    (uint32)__cpu2_clear_table,
    &Mcal_Core2Container
#endif /* ( MCAL_NO_OF_CORES == 3U )   */
#endif /* ( MCAL_NO_OF_CORES > 1U )  */
  }
};
#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#elif defined(_DIABDATA_C_TRICORE_)
#if (_DIABDATA_C_TRICORE_ == 1U)
const Mcal_CoreInit_t Mcal_CoreInit[MCAL_NO_OF_CORES] = {
  {
    (uint32)&__CPU0_USTACK,
    (uint32)__CPU0_CSA_BEGIN,
    (uint32)__CPU0_CSA_END,
    __CPU0_TRAPTAB,
    (uint32)__CPU0_ISTACK,
    (uint32)&__CPU0_SMALL_DATA,
    (uint32)&__CPU0_SMALL_DATA2,
    (uint32)_cpu0_copytable,
    (uint32)_cpu0_copytable__END__,
    &Mcal_Core0Container
#if ( MCAL_NO_OF_CORES > 1U )      
  },
  {
    (uint32)&__CPU1_USTACK,
    (uint32)__CPU1_CSA_BEGIN,
    (uint32)__CPU1_CSA_END,
    __CPU1_TRAPTAB,
    (uint32)__CPU1_ISTACK,
    (uint32)&__CPU1_SMALL_DATA,
    (uint32)&__CPU1_SMALL_DATA2,
    (uint32)_cpu1_copytable,
    (uint32)_cpu1_copytable__END__,
    &Mcal_Core1Container
#if ( MCAL_NO_OF_CORES == 3U )   
  },
  {
    (uint32)&__CPU2_USTACK,
    (uint32)__CPU2_CSA_BEGIN,
    (uint32)__CPU2_CSA_END,
    __CPU2_TRAPTAB,
    (uint32)__CPU2_ISTACK,
    (uint32)&__CPU2_SMALL_DATA,
    (uint32)&__CPU2_SMALL_DATA2,
    (uint32)_cpu2_copytable,
    (uint32)_cpu2_copytable__END__,
    &Mcal_Core2Container
#endif /* ( MCAL_NO_OF_CORES == 3U )   */
#endif /* ( MCAL_NO_OF_CORES > 1U )  */
  }
};
#endif
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#if (IFX_MCAL_USED == STD_ON)
#define MCAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#else
#define IFX_MCAL_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"
#endif

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#if (ECUM_POSTBUILD_CONFIG_TYPE == ECUM_SELECTABLE)
uint8 Mcal_lGetEcumCfgSelector(void);
#endif
/* Semaphore to halt the processing of other cores until CORE0 completes
   initialization */



void Mcal_Core1Functionality(void);
void Mcal_Core2Functionality(void);
void Mcal_EcuMInit(void);



#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)
/*******************************************************************************
** Syntax : void _START(void)                                                 **
**                                                                            **
** Service ID:  0                                                             **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Reset vector address                                         **
**                                                                            **
*******************************************************************************/

#pragma section code "libc.reset"
#pragma align 4

void _START(void)
{
  __asm("j _Mcal_Start");      /* jump to reset start address */
}


#pragma section code "libc"
#pragma align 4
#endif /* #if (_TASKING_C_TRICORE_ == 1U) */

#else

#ifdef _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)
#pragma section ".startup_code" awx
#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#elif defined(_DIABDATA_C_TRICORE_)
#if (_DIABDATA_C_TRICORE_ == 1U)
#pragma section CODE ".startup_code" X
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif
/*******************************************************************************
** Syntax : int _RESET(void)                                                  **
**                                                                            **
** Service ID:  0                                                             **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Reset vector address                                         **
**                                                                            **
*******************************************************************************/
void _RESET (void)
{
  __asm (".global _START");
  /* we must make a jump to cached segment, why trap_tab follow */
#ifdef _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)
  __asm ("_START: ja _Mcal_Start");
#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#elif defined(_DIABDATA_C_TRICORE_)
#if (_DIABDATA_C_TRICORE_ == 1U)
  __asm ("_START: movh.a %a15,_Mcal_Start@ha");
  __asm ("  lea  %a15,[%a15]_Mcal_Start@l");
  __asm ("  ji %a15");
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif
}
#ifdef _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)
#pragma section
#endif
#endif /* #if (_GNU_C_TRICORE_ == 1U) */




#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
/*******************************************************************************
** Syntax : int main(void)                                                    **
**                                                                            **
** Service ID:  0                                                             **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Reset vector address                                         **
**                                                                            **
*******************************************************************************/

/* we switch to normal region to habe cpu0 traptab on 0x80000100 */
#pragma section CODE X
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif

#endif
/*******************************************************************************
** Syntax : void _Mcal_Start(void)                                            **
**                                                                            **
** Service ID:  0                                                             **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description :  MCAL Specific Start up code (Sample Test Code)              **
**                CrossView Requirement: Re-enable and reset the call depth   **
**                counter and  make A0,A1,A8,A9 accessible. User Stack        **
**                Pointer Initialization. PCX Reset: Clear Previous Context   **
**                Pointer Segment Address and Offset Field. CSA               **
**                initialization followed by clearing endinit bit.            **
**                Disable Watchdog.                                           **
**                Trap vector base address initialization.                    **
**                ISP - initlaization                                         **
**                Base Interrupt vector table initalization.                  **
**                Flash waitstates configuration followed by endinit set      **
**                A0,A1 addressing.                                           **
**                A8,A9 addressing.                                           **
**                Bus and LMB configuration                                   **
**                Initialization of RAM variables.                            **
**                Call to Mcal_Main                                           **
**                                                                            **
*******************************************************************************/
#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
__attribute__((use_frame_pointer)) void _Mcal_Start(void)
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#else
void _Mcal_Start(void)
#endif
{


  const Mcal_CoreInit_t * CoreTable;
  #ifdef _TASKING_C_TRICORE_
  #if (_TASKING_C_TRICORE_ == 1U)
  uint32 sp;
  #ifndef _NO_A0A1_ADDRESSING
    void *a0 ;
    void *a1;
  #endif
  #endif
  #endif /* #if (_TASKING_C_TRICORE_ == 1U) */
  uint8 CoreNumber;


  CoreNumber = MFCR(CPU_CORE_ID);

  CoreTable = &(Mcal_CoreInit[CoreNumber]);

#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)
  /*
   Re-enable and reset the call depth counter and  make A0,A1,A8,A9
   write-able. It is required for CrossView that these RESET values are
   restored for each time the startup code is executed.
  */
  #ifndef _NO_PSW_RESET
     MTCR(CPU_PSW, 0x00000980);        /* clear PSW.IS and set to User Stack*/
  #endif

  /*
   user stack init
  */
  #ifndef _NO_USP_INIT
    sp = (uint32)(CoreTable->StackEndAddress) & STACK_ALIGN;
    __asm("mov.a\tsp,%0"::"d"(sp));
  #endif


  /*
   Clear Previous Context Pointer Segment Address and Offset Field.
   It is required for CrossView stack trace that these RESET values
   are restored for each time the startup code is executed.
  */

  #ifndef _NO_PCX_RESET
  {
      sint32 PCXValue ;
      PCXValue = __mfcr(CPU_PCXI) ;
      MTCR(CPU_PCXI, (sint32)((uint32)PCXValue & 0xfff00000UL)) ;
      __isync() ;
  }
  #endif

  #ifndef _NO_CSA_INIT
  {
      uint32 loopCount ;
      uint32 x ;
      uint32 _csa_index;
      uint32 _lcx_index;
      uint32 * _prev_csa;

  /*
   The total no of CSA's is computed between the difference of CSA boundary
   address.
   The logic goes like this , assume the CSA starts as 0xd0004000 and ends at
   0xd0005000. 64 CSA's and each CSA occupying 64 bytes ( total 0x1000 bytes)
   At the address 0xd0004000 ZERO is written, to indicate last CSA.
   At 0xd0004040 - link to the 0th CSA is written as 0x000D0100. ( D stands for 
   segment number)
   At 0xd0004080 - link to the 1st CSA is written as 0x000D0101. 
   The list continues finally 
   At 0xd0004fc0 , link to the 62nd CSA is written as 0x000D013E
  */
      _prev_csa = (uint32 *)(CoreTable->CsaStartAddress) ;
      /*
       Load the count with the value of total CSA
      */
      loopCount = (((uint32)(\
          CoreTable->CsaEndAddress - CoreTable->CsaStartAddress) >> 6) - 1UL) ;
      x = (((uint32)(CoreTable->CsaStartAddress) >> 28) << 16) ;

      /*   Load the null pointer for initial CSA (0th)      */
      *(_prev_csa) = 0 ;
      /* Fill the complete list */
      while(loopCount != 0)
      {
        _csa_index = ((((uint32)(_prev_csa) << 10) >> 16) | x ) ;
        _prev_csa += 0x10 ;
        *(_prev_csa) = _csa_index ;
        loopCount-- ;
      }
      _csa_index = ((((uint32)(_prev_csa) << 10) >> 16) | x ) ;
      
      /* Load the last but 2 CSA link into LCX register */
      _lcx_index = (uint32)( (uint32 *)(CoreTable->CsaStartAddress) + 0x20);
      _lcx_index = (uint32)(((_lcx_index << 10) >> 16) | x );
      MTCR(CPU_LCX,(sint32)_lcx_index) ;
      __isync() ;

      /*
       Load FCX with the free context pointer
       Write the last segment number into FCX register
      */
      MTCR(CPU_FCX,(sint32)_csa_index) ;
      __isync() ;

  }
#endif /* #if (_TASKING_C_TRICORE_ == 1U) */
#endif
/* #elif _DIABDATA_C_TRICORE_ or _GNU_C_TRICORE_*/
#else

  uint32 pcxi;
  sint32 k;
  sint32 no_of_csas;
  sint32 *pCsa;
  uint32 seg_nr, seg_idx, pcxi_val = 0;
  sint32 *csa_area_begin = (sint32 *)(CoreTable->CsaStartAddress);
  sint32 *csa_area_end = (sint32 *)(CoreTable->CsaEndAddress);

  #ifndef _NO_USP_INIT
  Mcal_StackEndAddress = (uint32*)CoreTable->StackEndAddress;
  __setreg (sp, Mcal_StackEndAddress);

  DSYNC();
  #endif

  #ifndef _NO_PSW_RESET
  /* Set the PSW to its reset value in case of a warm start */
  MTCR (CPU_PSW, 0x00000980);     /* clear PSW.IS */
  ISYNC();
  #endif

  /* Set the PCXS and PCXO to its reset value in case of a warm start */
  pcxi = __mfcr (CPU_PCXI);
  pcxi &= 0xfff00000;
  MTCR (CPU_PCXI, pcxi);


  /* Setup the context save area linked list. */
  /* first calculate nr of CSAs in this area */
  no_of_csas = (csa_area_end - csa_area_begin) >> 4;
  pCsa = csa_area_begin;

  for (k = 0; k < no_of_csas; k++)
  {
    /* Store null pointer in last CSA (= very first time!) */
    *pCsa = pcxi_val;
    /* get segment number */
    seg_nr = EXTRACT((sint32)pCsa, 28, 4) << 16;
    /* get idx number */
    seg_idx = EXTRACT((sint32)pCsa, 6, 16);
    /* calculate va榘卍 pcxi value */
    pcxi_val = seg_nr | seg_idx;
    /* if this is the last but 2 csa, then we store the new pcxi value to LCX */
    if (k == 2)
    {
      MTCR (CPU_LCX, pcxi_val);
    }
    /* next CSA */
    pCsa += 16;
  }
  /* store actual pcxi value to the FCX (this is our first free context) */
  MTCR (CPU_FCX, pcxi_val);
  ISYNC();

#endif /* _TASKING_C_TRICORE_ */

  endinit_reset();

  /* Icache enabling steps */
  /* Step 1: Set PCBYP to 1 */
  MTCR(CPU_PCON0,PCON0_PCBYP);
  /* Step 2: Call Isync */
  ISYNC();

  endinit_set();

  /* Step 3: Invalidate current settings */
  MTCR(CPU_PCON1,PCON1_PCINV);

  /* Step 5: wait till PCINV becomes zero */
  while((__mfcr(CPU_PCON1) & PCON1_PCINV) == PCON1_PCINV);

  /*
   Clear the ENDINIT bit in the WDT_CON0 register in order
   to disable the write-protection for registers protected
   via the EndInit feature (for example: WDT_CON1).
  */
  endinit_reset();


#ifndef NO_WATCHDOG_DISABLE
    /*
     disable Safety watchdog & Cpu0 watchdog
    */
    if(CoreNumber==0)
    {
      safety_endinit_reset();
      SCU_WDTSCON1.U = 0x00000008 ;
      safety_endinit_set();
    }


    MODULE_SCU.WDTCPU[CoreNumber].CON1.U = 0x00000008;
#endif

/*
 Load Base Address of Trap Vector Table
 Disable this if not started from RESET vector. (E.g.
 ROM monitors require to keep in control of vectors)
*/
#ifndef _NO_BTV_INIT
  MTCR(CPU_BTV,(uint32)(CoreTable->TrapFn)) ; /* initialize BTV    */
#endif

/*
 Load Base Address of Interrupt Vector Table
 Disable this if not started from RESET vector. (E.g.
 ROM monitors require to keep in control of vectors)
*/
#ifndef _NO_BIV_INIT
  MTCR (CPU_BIV, (uint32)&__INTTAB);
#endif

/*
 Load interupt stack pointer
 Disable this if not started from RESET vector. (E.g.
 ROM monitors require to keep in control of vectors)
*/
#ifndef _NO_ISP_INIT
  MTCR(CPU_ISP,(uint32)((uint32)(CoreTable->IStackAddress))) ;
#endif



#ifdef _ENABLE_ICACHE
   /* After setting the size, enable end init protection */

   /* Step 6: Enable ICACHE memory, followed by ISYNC instruction */
   MTCR(CPU_PCON0,0);

   ISYNC(); 
#endif

#ifdef _ENABLE_DCACHE
   /* After setting the size, enable end init protection */

   /* Step 6: Enable DCACHE memory, followed by ISYNC instruction */
   MTCR(CPU_DCON0,0);

  ISYNC(); 
  DSYNC();
#endif

/*
 Set the ENDINIT bit in the WDT_CON0 register again
 to enable the write-protection and to prevent a time-out.
*/
    endinit_set();
    
#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)
/*
 Inititialize global address registers a0/a1 to support
 __a0/__a1 storage qualifiers of the C compiler.
*/
#ifndef _NO_A0A1_ADDRESSING
      a0 = (uint32*)CoreTable->SmallData0;
    __asm( "mov.aa\ta0,%0"::"a"(a0) );

      a1 = (uint32*)CoreTable->SmallData2;
    __asm( "mov.aa\ta1,%0"::"a"(a1) );

#endif

/*
 Inititialize global address registers a8/a9 to support
 __a8/__a9 storage qualifiers of the C compiler. A8 and A9
 are reserved for OS use, or for application use in cases
 where the application ans OS are tightly coupled.
*/
#ifndef _NO_A8A9_ADDRESSING
    void * a8 = _A8_DATA_;
    __asm( "mov.aa\ta8,%0"::"a"(a8) );

    void * a9 = _A9_DATA_;
    __asm( "mov.aa\ta9,%0"::"a"(a9) );
#endif

#endif /* #if (_TASKING_C_TRICORE_ == 1U) */
#else
 /*
   * initialize SDA base pointers
   */
  Mcal_SmallDataAddress = CoreTable->SmallData0;
  Mcal_LiteralDataAddress = CoreTable->SmallData2;

  __setareg (a8, _SMALL_DATA3_);

  __setareg (a9, _SMALL_DATA4_);

  __setreg(a0, Mcal_SmallDataAddress);
  __setreg(a1, Mcal_LiteralDataAddress);

#endif /* _TASKING_C_TRICORE_ */

/* 
   Example configuration for tPF = 30 ns, tPFECC = 10 ns, tDF = 200 ns, 
   tDFECC = 20 ns with fFSI2 = 200 MHz and fFSI = 100 MHz: 

   FCON.WSPFLASH = 5
   FCON.WSECPF = 1

   FCON.WSPFLASH =  Ceil (tPF * fFSI2) - 1
   FCON.WSECPF = Ceil (tPFECC * fFSI2) - 1

   The Ceil(r) function rounds a real number up, i.e. the result is the 
   smallest integer not less than the real argument. 
   The mathematical function name is 鎻卐iling(r)锟�


   Demo configuration: 
   tPF = 30 ns, tPFECC = 10 ns,fFSI2 = 200 MHz
   FCON.WSPFLASH = 5
   FCON.WSECPF = 1
   Wait States for DFLASH is updated in FLS driver.
   Application shall reconfigure FCON based on clock configuration.
*/

  if(CoreNumber==0U)
  {
    uint32 FconVal;
    FconVal = FLASH0_FCON.U;
    FconVal &= (uint32)0xFFFFFFC0U;
    FconVal |= (uint32)0x00000015U;
    endinit_reset();
    FLASH0_FCON.U = FconVal;
    endinit_set();
  }

/*
 Enabling LMB split mode means all LMB reads accepted by LFI where the LMB
 Master is not asserting lmb_no_split_n are taken as split transactions.
 Default state is All LMB reads accepted by LFI are taken as no split
 transactions.
 Modification of LFI_CON register is done only when the LMB mode is enabled.
 Its left to default state if the split is not  enabled hence code will not
 be generated
 In LFI_CON.U register the bit 0 is modified for the same, if LMB split
 is enabled.
*/

#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)
/*
 Initialize and clear C variables
*/
#ifndef _NO_C_INIT
    /* initialize data for all cores */
   {
     _c_init(CoreNumber, CoreTable->CopyTable) ;
   }
#endif
#endif /* #if (_TASKING_C_TRICORE_ == 1U) */

#elif defined(_GNU_C_TRICORE_)
#if (_GNU_C_TRICORE_ == 1U)
    /* initialize data */
#if ( MCAL_NO_OF_CORES == 3U )   
   if(CoreNumber == 0)
   {
     _Gnu_CopyTable((uint32)__shared_clear_table, (uint32)__shared_copy_table);
   }
#endif /* ( MCAL_NO_OF_CORES == 3U ) */
  _Gnu_CopyTable(CoreTable->ClearTable, CoreTable->CopyTable);

#endif /* #if (_GNU_C_TRICORE_ == 1U) */

#elif defined(_DIABDATA_C_TRICORE_)
#if (_DIABDATA_C_TRICORE_ == 1U)
    __isync ();  /* mtcr will don't do this for us */
    /* initialize data */
    copy_to_ram();
    
    _init_main(CoreNumber, CoreTable->CopyTable);
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif /* _TASKING_C_TRICORE_ */
  /* IFX_SAFETLIB_USED enable in case of SafeTlib standalone and Integration */
  #if (IFX_SAFETLIB_USED == STD_ON)
    #if ( MCAL_NO_OF_CORES > 1U )
    if(CoreNumber == 0)
    {
      /* Set program counter of core 1 */
      CPU1_PC.U = (unsigned int)_Mcal_Start;
        
      #if ( MCAL_NO_OF_CORES == 3U )   
      /* Set program counter of core 2 */
      CPU2_PC.U = (unsigned int)_Mcal_Start;
      #endif
    }
    #endif /* #if ( MCAL_NO_OF_CORES > 1U ) */
    SafeTlib_main(CoreNumber);
  #endif/* #if (IFX_SAFETLIB_USED == STD_ON) */

  #if (IFX_MCAL_USED == STD_ON)
   #if ( MCAL_NO_OF_CORES > 1U )
   if(CoreNumber == 0)
   {
     #if (IFX_SAFETLIB_USED == STD_OFF)
       Mcal_StartCore(1, (uint32)&_Mcal_Start);
       #if ( MCAL_NO_OF_CORES == 3U )   
       Mcal_StartCore(2, (uint32)&_Mcal_Start);
       #endif /* ( MCAL_NO_OF_CORES == 3U )  */
     #endif


   }
   else
   {
     Mcal_CpuInitCompletedSem[CoreNumber] = 1;
   }
   #endif /* #if ( MCAL_NO_OF_CORES > 1U ) */
  /* Call the Core specifc functionalities */
  CoreTable->CoreFn();
  #endif /* #if (IFX_MCAL_USED == STD_ON) */
}

/*
 End of Function Start
*/
#if defined(_DIABDATA_C_TRICORE_)
#if (_DIABDATA_C_TRICORE_ == 1U)

void copy_to_ram(void)
{
  uint32 i;
  uint32 n;
  /* Calculate length of the region in ints */
  n = (__END_SOURCE) - (__DESTINATION);
  for (i = 0; i < n; i++)
  {
    __DESTINATION[i] = __SOURCE[i];
  }
}
#endif
#endif

#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)
/*******************************************************************************
** Syntax : void _Exit(void)                                                  **
**                                                                            **
** Service ID:  0                                                             **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Exits and calls debug16 instruction                          **
**                                                                            **
*******************************************************************************/
void _Exit(void)
{
  while(1)
  {
    __asm("debug16") ;
  }
}



#pragma section code "libc"
#pragma align 4

/*******************************************************************************
** Syntax : void _c_init(uint32 CoreNumber, uint32 Copytable)                 **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  CoreNumber - CoreId of the core executing               **
**                    Copytable - Copytable to be initialized/copied          **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Initialize or clear data segments as specified by the copy   **
**               table, It is an array of 4 word entries generated by the     **
**               locator. offset  0: type- 0=end, 1=copy, 2=clear             **
**               offset  4: destination address                               **
**               offset  8: source address (copy only)                        **
**               offset 12: length             - length in bytes.             **
**                                                                            **
*******************************************************************************/
void _c_init(uint32 CoreNumber, uint32 Copytable)
{
  uint32 *table ;

  uint32 type ;
  uint32 *src ;
  uint32 *dest ;
  uint32 lenb ; /* length in bytes */
  uint8 *tempsrc;
  uint8 *tempdest ;

  table = (uint32 *)Copytable ;
  type  = *table++ ; /* extract the first table entry; */

  while( (1==type) || (2==type))
  {
    dest = (uint32 *)*table++  ;
    src = (uint32 *)*table++  ;
    lenb = *table++  ;

    /* Do copytable only if shared address and CPU0 address */
    if ( (CoreNumber == 0U) && 
         ((((uint32)dest & CPUX_BASE_MEM_ADDR_MASK) == CPU1_BASE_MEM_ADRRESS)|| 
         (((uint32)dest & CPUX_BASE_MEM_ADDR_MASK) == CPU2_BASE_MEM_ADRRESS)) 
        )
    {
      type = *table++ ; /* extract the next table entry */
      continue;    
    }

    #if ( MCAL_NO_OF_CORES > 1U )   
    /* Core 1 - Do copytable only if CPU1 address */
    if ((CoreNumber == 1U) && 
        ((uint32)dest & CPUX_BASE_MEM_ADDR_MASK) != CPU1_BASE_MEM_ADRRESS)
    {
      type = *table++ ; /* extract the next table entry */
      continue;
    }

    #if ( MCAL_NO_OF_CORES == 3U )   
    /* Core 2 - Do copytable only if CPU2 address */
    if ((CoreNumber == 2U) && 
        ((uint32)dest & CPUX_BASE_MEM_ADDR_MASK) != CPU2_BASE_MEM_ADRRESS)
    {
      type = *table++ ; /* extract the next table entry */
      continue;
    }
    #endif /* #if ( MCAL_NO_OF_CORES == 3U ) */
    #endif /* #if ( MCAL_NO_OF_CORES > 1U ) */

    if(1 == type )
    {
      tempsrc = (uint8 *)src ;
      tempdest = (uint8 *)dest ;

      while(lenb)
      {
        *tempdest++ = *tempsrc++ ;
        lenb-- ;
      }
    }
    if(2 == type) /* clear */
    {
      tempdest = (uint8 *)dest ;

      while(lenb)
      {
        *tempdest++ = 0 ;
        lenb-- ;
      }
    }
    type = *table++ ; /* extract the next table entry */
  } /* while (type == 1 || type == 2) */
}
#endif /* #if (_TASKING_C_TRICORE_ == 1U) */

#elif defined(_GNU_C_TRICORE_)
#if (_GNU_C_TRICORE_ == 1U)
/*******************************************************************************
** Syntax : void _Gnu_CopyTable(uint32 ClearTable, uint32 CopyTable)          **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Initialize or clear data segments as specified by the copy   **
**               table, It is an array of 4 word entries generated by the     **
**               locator. offset  0: type- 0=end, 1=copy, 2=clear             **
**               offset  4: destination address                               **
**               offset  8: source address (copy only)                        **
**               offset 12: length             - length in bytes.             **
**                                                                            **
*******************************************************************************/
void _Gnu_CopyTable(uint32 ClearTable, uint32 CopyTable)
{
  typedef volatile union
  {
    uint8 *ucPtr;
    uint16 *usPtr;
    uint32 *uiPtr;
    unsigned long long *ullPtr;
  } TABLE_PTR;

  uint32 uiLength, uiCnt;
  uint32 *pTable;
  TABLE_PTR pBlockDest;
  TABLE_PTR pBlockSrc;
  /* clear table */
  pTable = (uint32*)ClearTable;
  while (pTable)
  {
    pBlockDest.uiPtr = (uint32 *)*pTable++;
    uiLength = *pTable++;
    /* we are finished when length == -1 */
    if (uiLength == 0xFFFFFFFF)
    {
      break;
    }

    uiCnt = uiLength / 8;

    while (uiCnt--)
    {
      *pBlockDest.ullPtr++ = 0;
    }

    if ((uiLength) & 0x4)
    {
      *pBlockDest.uiPtr++ = 0;
    }

    if ((uiLength) & 0x2)
    {
      *pBlockDest.usPtr++ = 0;
    }

    if ((uiLength) & 0x1)
    {
      *pBlockDest.ucPtr = 0;
    }
  }
  /* copy table */
  pTable = (uint32*)CopyTable;
  while (pTable)
  {
    pBlockSrc.uiPtr = (uint32 *)*pTable++;
    pBlockDest.uiPtr = (uint32 *)*pTable++;
    uiLength = *pTable++;
    /* we are finished when length == -1 */
    if (uiLength == 0xFFFFFFFF)
    {
      break;
    }

    uiCnt = uiLength / 8;

    while (uiCnt--)
    {
      *pBlockDest.ullPtr++ = *pBlockSrc.ullPtr++;
    }

    if ((uiLength) & 0x4)
    {
      *pBlockDest.uiPtr++ = *pBlockSrc.uiPtr++;
    }

    if ((uiLength) & 0x2)
    {
      *pBlockDest.usPtr++ = *pBlockSrc.usPtr++;
    }

    if ((uiLength) & 0x1)
    {
      *pBlockDest.ucPtr = *pBlockSrc.ucPtr;
    }
  }
}
#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#elif defined(_DIABDATA_C_TRICORE_)
#if (_DIABDATA_C_TRICORE_ == 1U)
/*******************************************************************************
** Syntax : void _init_main(uint32 CoreNumber, uint32 Copytable)              **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  CoreNumber - CoreId of the core executing               **
**                    Copytable - Copytable to be initialized/copied          **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Initialize or clear data segments as specified by the copy   **
**               table, It is an array of 4 word entries generated by the     **
**               locator. offset  0: type- 0=end, 1=copy, 2=clear             **
**               offset  4: destination address                               **
**               offset  8: source address (copy only)                        **
**               offset 12: length             - length in bytes.             **
**                                                                            **
*******************************************************************************/
void _init_main(uint32 CoreNumber, uint32 Copytable)
{
    int argc;
    /* we use only the copytables to copy and clear for us */
    if (CoreNumber == 0U)
    {
        __copy_multiple(__COPY_TABLE_BEGIN__, __COPY_TABLE_END__);
        __copy_multiple(_cpu0_copytable, _cpu0_copytable__END__);
        
    }
    if (CoreNumber == 1U)
    {
        __copy_multiple(_cpu1_copytable, _cpu1_copytable__END__);
        
    }
    if (CoreNumber == 2U)
    {
        __copy_multiple(_cpu2_copytable, _cpu2_copytable__END__);
        
    }

    argc = 0;
    /* check how many arguments we have            */
    for(argc = 0; __argv[argc] != NULL; argc++) ;

    environ = __env;

    /* initialize constructors                */
    __init();

    /* prepare to call the main function            */
    /* we don't need a call to main, because not used */
    /* main(argc,__argv,__env) ; */
}
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif
/*******************************************************************************
** Syntax           : uint8 EcuM_lGetCfgSelector(void)                        **
**                                                                            **
** Service ID       : None/<Specified>                                        **
**                                                                            **
** Sync/Async       : Synchronous / Asynchronous                              **
**                                                                            **
** Reentrancy       : Non-reentrant / Reentrant                               **
**                                                                            **
** Parameters(in)   : None/<Specified>                                        **
**                                                                            **
** Parameters (out) : None/<Specified>                                        **
**                                                                            **
** Return value     : None/<Specified>                                        **
**                                                                            **
** Description      : <Suitable Description>                                  **
**                                                                            **
*******************************************************************************/
#if (ECUM_POSTBUILD_CONFIG_TYPE == ECUM_SELECTABLE)
uint8 Mcal_lGetEcumCfgSelector(void)
{
 /* Get Selector based on ......*/

 return(0);
}
#endif


#if (IFX_MCAL_USED == STD_ON)
void Mcal_EcuMInit()
{
  #if (ECUM_POSTBUILD_CONFIG_TYPE == ECUM_SELECTABLE)
  uint8 CfgSelector;
  #endif

  const struct EcuM_ConfigType_Tag*   EcuMConfigPtr;


  /*Determine ECU Configuration Set */
  #if (ECUM_POSTBUILD_CONFIG_TYPE == ECUM_LOADABLE)
  /*Get Memory Location of the EcuM Configuration Set*/
  EcuMConfigPtr = EcuM_ConfigAddressPtr;
  /* In case of loadable the FlsStateVar memory area 48 bytes should be cleared.
   */
  #endif

  #if (ECUM_POSTBUILD_CONFIG_TYPE == ECUM_SELECTABLE)
  /*Get Configuration Set from available alternatives*/
  CfgSelector = Mcal_lGetEcumCfgSelector();
  EcuMConfigPtr =  &EcuM_ConfigAlternative[CfgSelector];
  #endif

  #if (OS_DELIVERY == STD_OFF)
//   Test_InitTime(); /* Initialize Time Measurement For Run Time Calc */
//   Test_InitPrint();/* Initialize ASC0 for Hyperterminal Communication*/
  #endif
   /*Initialize ECUM Module*/
  EcuM_Init(EcuMConfigPtr);
}

#endif



void Mcal_Core0Container()
{
  /* EcuM Init will be done only after all the other cores startup is completed
     This is because, if any of Core0's code accesses information belonging to
     other cores, then this information will not hold correct value until
     copy table is initialized. Also, if Core 0 updates a variable that resides
     in the memory allocated to other cores, then this data will  vanish during
     the copy table/clear table routine of the other cores. Hence it is safe
     to wait for the completion of the startup of the other cores before
     starting the application */
  #if ( MCAL_NO_OF_CORES > 1U )
  #if ( MCAL_NO_OF_CORES == 3U )
//	Mcal_CpuInitCompletedSem[1] = 1;
//	Mcal_CpuInitCompletedSem[2] = 1;
  while((Mcal_CpuInitCompletedSem[1] & Mcal_CpuInitCompletedSem[2] ) != 1);
  
  #else
  
  while(Mcal_CpuInitCompletedSem[1] != 1);
  
  #endif /* ( MCAL_NO_OF_CORES == 3U ) */
  #endif /* ( MCAL_NO_OF_CORES > 1U ) */
  
  #if (OS_DELIVERY == STD_OFF)
    
    #if (IFX_MCAL_USED == STD_ON)
    Mcal_EcuMInit();
    #endif

    #if ( MCAL_NO_OF_CORES > 1U )
    /* This line will signify basic initializations are completed by CPU0. Other
    initializations can be started by other cores from now on */
    Mcal_CpuInitCompletedSem[0] = 1;
    #endif /* ( MCAL_NO_OF_CORES > 1U ) */
    
    #if (IFX_MCAL_USED == STD_ON)
    #ifdef MCAL_CALL_DEMOAPP
    DemoApp();
    #endif
    #endif
  #else
  /*
   * OS Init - in OS Background Task, EcuM_Init shall happen
   */
  Ifx_OSTask_ApplicationInit();
  #endif
  
}

#if ( MCAL_NO_OF_CORES > 1U )

volatile uint32 TempCounterCPU1=0, TempCounterCPU2=0;

void Mcal_Core1Container()
{
   /* This is to wait until basic initializations are completed by CPU0. Other
  initializations can be started by other cores from now on */
  while(Mcal_CpuInitCompletedSem[0] != 1);
  Mcal_EnableAllInterrupts();       /* Enable Global Interrupt Flag. */

  while(1)
  {
    TempCounterCPU1++;
    
    /************* Function Calls Start **************/
    #if (IFX_SAFETLIB_USED == STD_ON)
    SAFET_core1_RunTimeTest();
    #endif
    #if (WDG_DELIVERY == STD_ON)
      Wdg_17_Scu_Core1Demo();
    #endif

    #if (GPT_DELIVERY == STD_ON)
//    Gpt_StartMCDemo();
    #endif
    /************* Function Calls End   **************/

  }
}


#if ( MCAL_NO_OF_CORES == 3U )   

void Mcal_Core2Container()
{
  #ifdef IFX_MCAL_RUN_MODE_DEFINE
  #if (IFX_MCAL_RUN_MODE_DEFINE!=0U)
  uint32 lCpu_PSW;
  #endif
  #endif
  #if ((IFX_MCAL_USED == STD_ON) && (WDG_DELIVERY == STD_ON))
    const struct EcuM_ConfigType_Tag*   EcuMConfigPtr;
    #if (ECUM_POSTBUILD_CONFIG_TYPE == ECUM_SELECTABLE)
    uint8 CfgSelector;
    #endif
  #endif

  /* This is to wait until basic initializations are completed by CPU0. Other
  initializations can be started by other cores from now on */
  while(Mcal_CpuInitCompletedSem[0] != 1);

  #if ((IFX_MCAL_USED == STD_ON) && (WDG_DELIVERY == STD_ON))
  /*Determine ECU Configuration Set */
  #if (ECUM_POSTBUILD_CONFIG_TYPE == ECUM_LOADABLE)
  /*Get Memory Location of the EcuM Configuration Set*/
  EcuMConfigPtr = EcuM_ConfigAddressPtr;
  #else
  /*Get Configuration Set from available alternatives*/
  CfgSelector = Mcal_lGetEcumCfgSelector();
  EcuMConfigPtr =  &EcuM_ConfigAlternative[CfgSelector];
  #endif
  #endif
  Mcal_EnableAllInterrupts();       /* Enable Global Interrupt Flag. */

  /*************** Init Section Start ************************/
  #if (WDG_DELIVERY == STD_ON)
  #if(WDG_PB_FIXEDADDR == STD_OFF)
     Wdg_17_Scu_Init(EcuMConfigPtr->Wdg_ConfigData);
  #else
   Wdg_17_Scu_Init(&Wdg_ConfigRoot[0]);
  #endif
  #endif
  /*************** Init Section End   ************************/

  #ifdef IFX_MCAL_RUN_MODE_DEFINE
  #if (IFX_MCAL_RUN_MODE_DEFINE!=0U)
    /* Set the user-1 mode on*/
  lCpu_PSW = (uint32)MFCR(CPU_PSW);
  lCpu_PSW = (lCpu_PSW & CPU_PSW_USER_MODE_MASK);
  lCpu_PSW = (lCpu_PSW | SET_USER_MODE_MASK);
  MTCR (CPU_PSW, lCpu_PSW); /* Set mode to user-1 mode. */
  #endif
  #endif
  
  while(1)
  {
    TempCounterCPU2++;
    #if (WDG_DELIVERY == STD_ON)
      Wdg_17_Scu_Core2Demo();
    #endif
    #if (DIO_DELIVERY == STD_ON)
//      DemoApp_McDioDemo();
    #endif
    /************* Function Calls Start **************/
    #if (IFX_SAFETLIB_USED == STD_ON)
    SAFET_core2_RunTimeTest();
    #endif
    /************* Function Calls End ****************/

  }
}
#endif /* ( MCAL_NO_OF_CORES == 3U )  */
#endif /* ( MCAL_NO_OF_CORES > 1U ) */

/* Function to reset the endinit bit of Safety watchdog */
static void safety_endinit_reset(void) 
{ 
  Mcal_ResetCpuENDINIT( -1 ); 
}

/* Function to set the endinit bit of Safety watchdog */
static void safety_endinit_set  (void) 
{ 
  Mcal_SetCpuENDINIT( -1 );
}

/* Function to reset the endinit bit of executing CPU watchdog */
static void endinit_reset(void) 
{ 
  uint32 CoreID = ((uint32)MFCR(CPU_CORE_ID) & MCAL_CORE_ID_MASK);
  Mcal_ResetCpuENDINIT( (sint8)CoreID );
}

/* Function to set the endinit bit of executing CPU watchdog */
static void endinit_set  (void) 
{ 
  uint32 CoreID = ((uint32)MFCR(CPU_CORE_ID) & MCAL_CORE_ID_MASK);
  Mcal_SetCpuENDINIT( (sint8)CoreID );
}
/*******************************************************************************
** Syntax           : void Mcal_SafeErrorHandler(uint32 ErrorType)            **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : ErrorType                                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This is an Error handler function which can be called   **
                      in two conditions                                       **
** 1. Any detection of inconsistency in copies of relevant global variables   **
**    is reported to the user via the function Mcal_SafeErrorHandler.         **
**    Mcal_SafeErrorHandler shall never return, else it may lead to           **
**    unpredictable behavior.The user is expected to perform the error        **
**    handling in this function.                                              **
**                                                                            **
**    The error reported is MCAL_DIV_INCONSISTENCY:Typical error reactions    **
**    could be to reset the microcontroller (software reset)                  **
**                                                                            **
** 2. Support functions are called to access the protected registers,         **
**    these functions can be called from multiple cores concurrently, a       **
**    spinlock mechanism with timeout is provided. In case, the timeout       **
**    expires, it is reported to the user via Mcal_SafeErrorHandler.          **
**    The user is expected to perform the error handling in this function.    **
**                                                                            **
**    The error reported is MCAL_SPINLOCK_TIMEOUT:Typical error reactions     **
**    could be to the terminate the operating system task or restart the      **
**    partition or reset the microcontroller.                                 **
**                                                                            **
**    This funtion is written here only to avoid build error.                 **
**    The user needs to implement this functionality (Mcal_SafeErrorHandler)  **
**    in a separate file and needs to add this file as part of the build.     **
**                                                                            **
*******************************************************************************/
void Mcal_SafeErrorHandler(uint32 ErrorType)
{
  volatile uint32 TimeOut;
  
  TimeOut = 0U;
  /* User can add the code here */
  UNUSED_PARAMETER(ErrorType)
  /* While loop added for UTP AI00252128 */
  while(TimeOut < 0xFFFFFFFFU)
  {
    TimeOut++;
  }
  /* Control should not reach here. WDG timeout happens before this. */
  DEBUG();

}

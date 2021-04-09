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
**  FILENAME  : Gtm_PBCfg.c                                                   **
**                                                                            **
**  $CC VERSION : \main\76 $                                                 **
**                                                                            **
**  DATE, TIME: 2021-04-08, 20:15:41                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : Mcu.bmd                                           **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking/GNU/Diab                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : GTM configuration generated out of ECU configuration      **
**                 file                                                       **
**                                                                            **
**  SPECIFICATION(S) : complex driver implementation                          **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
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
**  FILENAME  : Gtm.m                                                        **
**                                                                           **
**  $CC VERSION : \main\54 $                                                 **
**                                                                           **
**  DATE, TIME: 2021-04-08, 20:15:41                                         **
**                                                                           **
**  GENERATOR : Build b141014-0350                                           **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : GTM configuration generated out of ECU configuration      **
**                 file (Mcu.bmd/.xdm)                                       **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                                                                            **
*******************************************************************************/




/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Own header file, this includes own configuration file also */
#include "Gtm.h"



/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* Note:
The user can configure the parameters with the tag Configuration:
The user should not change anything under the tag Configuration Options:
*/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define GTM_INTERRUPT_LEVEL_MODE          (0U)
#define GTM_INTERRUPT_PULSE_MODE          (1U)
#define GTM_INTERRUPT_PULSE_NOTIFY_MODE   (2U) 
#define GTM_INTERRUPT_SINGLE_PULSE_MODE   (3U)

#define TSPP1_SUBUNIT_OUTPUT 5

/* For Tbu */
#define BITS_0_TO_23   (0U)
#define BITS_3_TO_26   (1U)
#define FREE_RUNNING_COUNTER_MODE      (0)
#define FORWARD_BACKWARD_COUNTER_MODE  (1)

/*IFX_MISRA_RULE_19_07_STATUS= Function like macros used for simplifacation of
        configuration generation and increase the readability of config file */
#define Gtm_lTbuBuildControl(Bit0, Bit123, Bit5)                              \
 (0x00U | (uint8)(Bit0) | (uint8)((uint8)(Bit123) << 1) |                     \
                                                 (uint8)((uint8)(Bit5) << 5))
                                                 
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used for simplifacation of
        configuration generation and increase the readability of config file*/
#define Gtm_lTimerCtrlValue(Word, ClockValue)                                 \
                        ((uint32)(Word) | (uint32)((uint32)(ClockValue) << 12))
                        
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used for simplifacation of
        configuration generation and increase the readability of config file*/
#define Gtm_TimbuildReg(Word, ClockValue)                                     \
                         ((uint32)(Word)| (uint32)((uint32)(ClockValue) << 24))
                         
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used for simplifacation of
        configuration generation and increase the readability of config file*/
#define Gtm_TimTduBuildReg(Word, ClockValue)                                  \
                        ((uint32)(Word) | (uint32)((uint32)(ClockValue) << 28))
                        
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used for simplifacation of
        configuration generation and increase the readability of config file*/
#define Gtm_MapBuildReg(Word, ClockValue)                                     \
                         ((uint32)(Word) | (uint32)((uint32)(ClockValue) << 1))

/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used for simplifacation of
        configuration generation and increase the readability of config file*/
#define Gtm_lMoveCcuTo8Bit(Ccu1,Ccu0)                                        \
                             (((uint16)(Ccu0))| (uint16)((uint16)(Ccu1) << 8))

/* For Interrupt Mode Appending */
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used for simplifacation of
        configuration generation and increase the readability of config file*/
#define Gtm_lIncludeIntMode8Bit(Bytevalue, IrqMode)                           \
                          ((uint8)(Bytevalue) | (uint8)((uint8)(IrqMode) << 6))
                          
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used for simplifacation of
        configuration generation and increase the readability of config file*/
#define Gtm_lIncludeIntMode16Bit(Intvalue, IrqMode)                           \
                       ((uint16)(Intvalue) | (uint16)((uint16)(IrqMode) << 14))
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used for simplifacation of
        configuration generation and increase the readability of config file*/
        
#define Gtm_lIncludeIntMode32Bit(Wordvalue, IrqMode)                          \
                      ((uint32)(Wordvalue) | (uint32)((uint32)(IrqMode) << 30))

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Funtion Declarations                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#define MCU_START_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
 allowed only for MemMap.h*/
#include "MemMap.h"

static const Gtm_ClockSettingType Gtm_kClockSetting0 = 
{
  0x00955556U,
  {
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
  },

    0x0U,

  {
    {  0x00000001U,  0x00000001U  },
    {  0x00000001U,  0x00000001U  },
    {  0x00000001U,  0x00000001U  }
  }
};

static const Gtm_GeneralConfigType Gtm_kGeneralConfig0 =
{
  0x0001U,
  Gtm_lIncludeIntMode8Bit(0U,GTM_INTERRUPT_LEVEL_MODE)
  };





static const Gtm_TomTgcConfigType Gtm_kTomTgcConfig0[] =
{
  {
    0x0U,
    0x0U,
    NULL_PTR	
  },

};

static const Gtm_TomConfigType Gtm_kTomConfig0[] = 
{
  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_0),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_0),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_0),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_0),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_0),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_0),
    NULL_PTR

  },


  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x0U,GTM_FIXED_CLOCK_0),
    NULL_PTR

  },


};

static const Gtm_AtomAgcConfigGroupType Gtm_kAtomAgcConfigGroup0[] =
{
  {
      0x8000U,
      0x0000U,
      0x8000U,
      0x0000U,
      0x8000U,
      0x00000000U,

  },

};

static const Gtm_AtomChannelConfigType Gtm_kAtomChannelConfig0[]=
{
  {
    0x0U,
    0x1fe01feU,
    0x0U,
    0x1388U, 
    0x9c4U,
    0x1388U,
    0x9c4U

  },     

};

static const Gtm_AtomAgcConfigType Gtm_kAtomAgcConfig0[] =
{
  {
    0x8000U,
    0x0U,
    &Gtm_kAtomAgcConfigGroup0[0]
  },
  {
    0x8000U,
    0x0U,
    NULL_PTR	
  },
  {
    0x0U,
    0x0U,
    NULL_PTR	
  },

};

static const Gtm_AtomConfigType Gtm_kAtomConfig0[] = 
{
  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x2U,GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,

  },
  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x2U,GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,

  },
  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x2U,GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,

  },
  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x2U,GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,

  },
  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x2U,GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,

  },
  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x2U,GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,

  },
  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x2U,GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,

  },
  {
    GTM_DRIVER_COMPLEX,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x100002U,GTM_CONFIGURABLE_CLOCK_0),
    &Gtm_kAtomChannelConfig0[0],

  },
  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x2U,GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,

  },
  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x2U,GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,

  },
  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x2U,GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,

  },
  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x2U,GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,

  },
  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x2U,GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,

  },
  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x2U,GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,

  },
  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x2U,GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,

  },
  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x2U,GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,

  },
  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x2U,GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,

  },
  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x2U,GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,

  },
  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x2U,GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,

  },
  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x2U,GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,

  },
  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x2U,GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,

  },
  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x2U,GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,

  },
  {
    GTM_DRIVER_PWM,
    GTM_INTERRUPT_LEVEL_MODE,
    Gtm_lTimerCtrlValue(0x2U,GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,

  },

};



static const Gtm_TimConfigType Gtm_kTimConfig0[] =
{
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x00000000U
    
},
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x00000000U
    
},
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x00000000U
    
},
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x00000000U
    
},
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x00000000U
    
},
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x00000000U
    
},
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x00000000U
    
},
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x00000000U
    
},
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x00000000U
    
},
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x00000000U
    
},
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x00000000U
    
},
  {
    GTM_DRIVER_ICU,
    Gtm_lIncludeIntMode8Bit(0x0U,GTM_INTERRUPT_LEVEL_MODE),
    0x00U,
    0x00U,
    0x0U,
    Gtm_TimbuildReg(0x0U, GTM_CONFIGURABLE_CLOCK_0),
    NULL_PTR,
    0x00000000U,
    Gtm_TimTduBuildReg(0x0U,GTM_CONFIGURABLE_CLOCK_0),  
    0x00000000U
    
},

};

static const Gtm_ModUsageConfigType Gtm_kModUsage0 =
{  
  { /*TIM Module Usage */
    
     /*TIM0 Module Usage*/   {
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
   },
     /*TIM1 Module Usage*/
   {
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      0x0U, /*ICU channel no*/
      0x1U, /*ICU channel no*/
      GTM_TIM_CH_NOT_USEDBY_ICU,
      0x2U, /*ICU channel no*/
      0x9U, /*ICU channel no*/
   },
     /*TIM2 Module Usage*/
   {
      0x8U, /*ICU channel no*/
      0x3U, /*ICU channel no*/
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      0x4U, /*ICU channel no*/
      0x5U, /*ICU channel no*/
      0x6U, /*ICU channel no*/
      0x7U, /*ICU channel no*/
   },
     /*TIM3 Module Usage*/
   {
      0xaU, /*ICU channel no*/
      0xbU, /*ICU channel no*/
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
      GTM_TIM_CH_NOT_USEDBY_ICU,
   },
  },
  {   /*TOM module Usage */
     /*TOM Module 0 Usage*/    {
      0x7U,/*PWM channel no*/
      0x8U,/*PWM channel no*/
      0x9U,/*PWM channel no*/
      0xaU,/*PWM channel no*/
      0xbU,/*PWM channel no*/
      0xcU,/*PWM channel no*/
      0xdU,/*PWM channel no*/
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
    },
     /*TOM Module 1 Usage*/
    {
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
    },
     /*TOM Module 2 Usage*/
    {
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_TOM_CH_NOT_USEDBY_GPT_PWM,
    },
  },  {     /*ATOM module Usage */


     /*ATOM Module 0 Usage*/
   {
      0x15U, /*PWM channel no*/
      0x16U, /*PWM channel no*/
      0x17U, /*PWM channel no*/
      0x18U, /*PWM channel no*/
      0x19U, /*PWM channel no*/
      0x1aU, /*PWM channel no*/
      0x1bU, /*PWM channel no*/
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
    },
     /*ATOM Module 1 Usage*/
   {
      0x0U, /*PWM channel no*/
      0x1U, /*PWM channel no*/
      0x2U, /*PWM channel no*/
      0x3U, /*PWM channel no*/
      0x4U, /*PWM channel no*/
      0x5U, /*PWM channel no*/
      0x6U, /*PWM channel no*/
      0x1cU, /*PWM channel no*/
    },
     /*ATOM Module 2 Usage*/
   {
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
    },
     /*ATOM Module 3 Usage*/
   {
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
    },

   /*ATOM Module 4 Usage*/
   {
      0xeU, /*PWM channel no*/
      0xfU, /*PWM channel no*/
      0x10U, /*PWM channel no*/
      0x11U, /*PWM channel no*/
      0x12U, /*PWM channel no*/
      0x13U, /*PWM channel no*/
      0x14U, /*PWM channel no*/
      GTM_ATOM_CH_NOT_USEDBY_GPT_PWM,
    },
  }

};


static const Gtm_TbuConfigType Gtm_kTbuConfig0[GTM_NO_OF_TBU_CHANNELS] = 
{
  {  Gtm_lTbuBuildControl(BITS_0_TO_23, GTM_CONFIGURABLE_CLOCK_0, 1U),  0U  },
  {  GTM_SETUNUSED8 ,0x00000000U   },
  {  GTM_SETUNUSED8 ,0x00000000U   },
};

static const uint8 Gtm_kAdcConnections0[GTM_NO_OF_ADC_MODULES] = 
{
 0x0cU, 0x0cU, 0x0cU, 0x88U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U,
};


static const Gtm_PortConfigType Gtm_kPortConfig0 =
{
  {
    0x00000000U,
    0x44047000U,
    0x44440014U,
    0x00000078U,
  },
  {
    0xffcc2aa8U,
    0x000c000bU,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x0000c800U,
    0x000ff000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,

  }
};

static const Gtm_ModuleConfigType Gtm_kModuleConfig0 =
{
  0x00U | (uint8)((uint8)1U << 5),  /* ARU Configuration */
  (uint8)GTM_ZERO_U,  /* Mcfg Configuration*/
  GTM_SLEEP_ENABLE,  /* Module Sleep Mode */
  1U,  /* Global Clock Configuration - Numerator */
  1U,/* Global Clock Configuration - Denominator */
  0xFFFFFFFFU,  /* Access Enable 0 */
  0UL,  /* Access Enable 1 */
  {  0x51400000U, 
     0x00055505U,
  },    /* TIM Module Usage by GTM and ICU driver*/
  {  0x03f3d800U,
  },  /* TIM Usage */
  &Gtm_kTimConfig0[0],  /* TIM Configuration Pointer */
  {0x00000001U},  /* TOM TGC Usage */
  &Gtm_kTomTgcConfig0[0],  /* TOM TGC Configuration Pointer */
  {0x00001555U,
   0x00000000U,0x00000000U,  
   },
  {0x0000007fU,
   0x00000000U,

  },  /* TOM Usage */
  &Gtm_kTomConfig0[0],  /* TOM Configuration Pointer */
  {0x00000013U},  /* ATOM AGC Usage */
  &Gtm_kAtomAgcConfig0[0],  /* ATOM AGC Configuration Pointer */  
  { 0x5555d555U, 
    0x00000000U, 
    0x00001555U,
  },
  {0x0000ffffU,
    
    0x0000007fU,
    
    
    },  /* ATOM Usage */
  &Gtm_kAtomConfig0[0],  /* ATOM Configuration Pointer */   
    

  &Gtm_kModUsage0, /* Configuration for GTM Usage by other modules */
  &Gtm_kGeneralConfig0,  /* GTM General Configuration */
  &Gtm_kTbuConfig0[0],  /* TBU Configuration Pointer */
  NULL_PTR,  /* BRC Configuration Pointer*/
  NULL_PTR,  /* Fifo Configuration Pointer*/
  NULL_PTR,  /* F2a Configuration Pointer*/
  NULL_PTR,  /* Mcs Configuration Pointer*/
  GTM_SETUNUSED32,  /* Map Configuration*/
  NULL_PTR,  /* Dpll Configuration Pointer*/
  { /* Spe Configurations*/
    NULL_PTR,  /* Spe Configuration Pointer*/
    NULL_PTR,  /* Spe Configuration Pointer*/
  },
  NULL_PTR,  /* Cmp Configuration Pointer*/
  NULL_PTR,  /* Msc Connections Configuration Pointer*/
  NULL_PTR,  /* Dsadc Connections Configuration Pointer*/
  &Gtm_kAdcConnections0[0],  /* Adc Connections Configuration Pointer*/
  {
    0x00000000U,  /* Ttcan Connections Configuration*/
  },
  0x00000000U,  /* Psi5 Connections Configuration Pointer*/
  0x00000000U  /* Psi5S Connections Configuration Pointer*/
};

const Gtm_ConfigType Gtm_ConfigRoot[]  =
{
  {
    /*  GTM Module Clock Settings  */
    &Gtm_kClockSetting0,
    /*  Pointer to Gtm Configuration structure  */
    &Gtm_kPortConfig0,
    &Gtm_kModuleConfig0,
  },
};
#define MCU_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
 allowed only for MemMap.h*/
#include "MemMap.h"




/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/


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
**  FILENAME  : Icu_17_GtmCcu6_PBCfg.c                                        **
**                                                                            **
**  $CC VERSION : \main\50 $                                                 **
**                                                                            **
**  DATE, TIME: 2021-04-08, 20:15:41                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Icu configuration generated out of ECU configuration       **
**                 file  (Icu_17_GtmCcu6.bmd)                                 **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Include module header File */
/* [cover parentID=SAS_AS_ICU219_ICU245_ICU247_ICU251_ICU254_ICU256_ICU115,
        DS_NAS_ICU_PR699,DS_NAS_ICU_PR709] */
#include "Icu_17_GtmCcu6.h"
/* [/cover] */
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define GTM_INTERRUPT_LEVEL_MODE          (0U)
#define GTM_INTERRUPT_PULSE_MODE          (1U)
#define GTM_INTERRUPT_PULSE_NOTIFY_MODE   (2U) 
#define GTM_INTERRUPT_SINGLE_PULSE_MODE   (3U)
/*
Configuration Options:
IcuAssignedHwunit
*/
#define ICU_ASSIGN_ERU0_PINLINE0 (0U)
#define ICU_ASSIGN_ERU0_PINLINE1 (1U)
#define ICU_ASSIGN_ERU0_PINLINE2 (2U)
#define ICU_ASSIGN_ERU0_PINLINE3 (3U)
#define ICU_ASSIGN_ERU1_PINLINE0 (4U)
#define ICU_ASSIGN_ERU1_PINLINE1 (5U)
#define ICU_ASSIGN_ERU1_PINLINE2 (6U)
#define ICU_ASSIGN_ERU1_PINLINE3 (7U)
#define ICU_ASSIGN_ERU2_PINLINE0 (8U)
#define ICU_ASSIGN_ERU2_PINLINE1 (9U)
#define ICU_ASSIGN_ERU2_PINLINE2 (10U)
#define ICU_ASSIGN_ERU2_PINLINE3 (11U)
#define ICU_ASSIGN_ERU3_PINLINE0 (12U)
#define ICU_ASSIGN_ERU3_PINLINE1 (13U)
#define ICU_ASSIGN_ERU3_PINLINE2 (14U)
#define ICU_ASSIGN_ERU3_PINLINE3 (15U)
#define ICU_ASSIGN_ERU4_PINLINE0 (16U)   
#define ICU_ASSIGN_ERU4_PINLINE1 (17U)  
#define ICU_ASSIGN_ERU4_PINLINE2 (18U)  
#define ICU_ASSIGN_ERU4_PINLINE3 (19U)  
#define ICU_ASSIGN_ERU5_PINLINE0 (20U)  
#define ICU_ASSIGN_ERU5_PINLINE1 (21U)  
#define ICU_ASSIGN_ERU5_PINLINE2 (22U)  
#define ICU_ASSIGN_ERU5_PINLINE3 (23U)  
#define ICU_ASSIGN_ERU6_PINLINE0 (24U)  
#define ICU_ASSIGN_ERU6_PINLINE1 (25U)  
#define ICU_ASSIGN_ERU6_PINLINE2 (26U) 
#define ICU_ASSIGN_ERU6_PINLINE3 (27U) 
#define ICU_ASSIGN_ERU7_PINLINE0 (28U) 
#define ICU_ASSIGN_ERU7_PINLINE1 (29U) 
#define ICU_ASSIGN_ERU7_PINLINE2 (30U) 
#define ICU_ASSIGN_ERU7_PINLINE3 (31U) 


/*
Define for unused ERU Line 
*/
#define ERU_REQLINE_UNUSED   (255U)

/* CCU defines */
#define ICU_CCU60_CC60 0x00U
#define ICU_CCU60_CC61 0x10U
#define ICU_CCU60_CC62 0x20U
#define ICU_CCU61_CC60 0x01U
#define ICU_CCU61_CC61 0x11U
#define ICU_CCU61_CC62 0x21U

/*******************************************************************************
**                      Private Function like Macros                          **
*******************************************************************************/


/*******************************************************************************
**                       Function Declarations                                **
*******************************************************************************/

#define ICU_17_GTMCCU6_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"


#define ICU_17_GTMCCU6_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#define ICU_17_GTMCCU6_START_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"


/* 
   Channel Configuration Instance IcuConfigSet_0
*/
static const Icu_17_GtmCcu6_ChannelConfigType Icu_kChannelConfig0[ ] =
{
  
  {
      /* ICU Channel 0 */
    (Icu_17_GtmCcu6_NotifiPtrType)0,/*Notification-function name*/
    {
      ICU_MODE_SIGNAL_EDGE_DETECT,/*Measurement Mode*/
      ICU_BOTH_EDGES,/*Default Start Edge */
      0U,/*Measurement Property*/
      ICU_NOT_WAKEUPCAPABLE,/*Wakeup capability*/
      GTM_TIM1_CHANNEL3,/* Assigned Hardware Resource Number */
      (uint8)ICU_GTM_OPTION, /* Assigned Hw Unit */
      0U, /* CCU connection */
      ICU_QM_SIGNAL, /* Safety ON or OFF*/        
      0U,/* Reserved */
    #if (ICU_SAFETY_ENABLE == STD_ON)   
     0U,/*Buffer Marker value */
    #endif   
     0U,/* Filtering time for rising edge */
     0U,/* Filtering time for falling edge */   
     GTM_INTERRUPT_LEVEL_MODE,/* Filtering time for TIM interrupt mode */
     GTM_CONFIGURABLE_CLOCK_0, /*Channel Clock Select */
     TIMEBASE_TBU_TS0,  /* Gpr0 input select for the Tim channel */   
     0U, /* Enables Filter for the Channel */
   /*Decides the filter Counter frequency for the TIM Channel */
     GTM_CONFIGURABLE_CLOCK_0,
   /*Decides the filter mode for rising Edge of the TIM Channel Input */
     IMMEDIATE_EDGE_PROPAGATION_MODE,
   /*Decides the filter mode for falling Edge of the TIM Channel Input */ 
     IMMEDIATE_EDGE_PROPAGATION_MODE, 
     /*Input channel select : current chl or previous chl */
   INPUT_OF_CURRENT_TIM_CHANNEL, 
    }
  },  
  {
      /* ICU Channel 1 */
    (Icu_17_GtmCcu6_NotifiPtrType)0,/*Notification-function name*/
    {
      ICU_MODE_SIGNAL_EDGE_DETECT,/*Measurement Mode*/
      ICU_BOTH_EDGES,/*Default Start Edge */
      0U,/*Measurement Property*/
      ICU_NOT_WAKEUPCAPABLE,/*Wakeup capability*/
      GTM_TIM1_CHANNEL4,/* Assigned Hardware Resource Number */
      (uint8)ICU_GTM_OPTION, /* Assigned Hw Unit */
      0U, /* CCU connection */
      ICU_QM_SIGNAL, /* Safety ON or OFF*/        
      0U,/* Reserved */
    #if (ICU_SAFETY_ENABLE == STD_ON)   
     0U,/*Buffer Marker value */
    #endif   
     0U,/* Filtering time for rising edge */
     0U,/* Filtering time for falling edge */   
     GTM_INTERRUPT_LEVEL_MODE,/* Filtering time for TIM interrupt mode */
     GTM_CONFIGURABLE_CLOCK_0, /*Channel Clock Select */
     TIMEBASE_TBU_TS0,  /* Gpr0 input select for the Tim channel */   
     0U, /* Enables Filter for the Channel */
   /*Decides the filter Counter frequency for the TIM Channel */
     GTM_CONFIGURABLE_CLOCK_0,
   /*Decides the filter mode for rising Edge of the TIM Channel Input */
     IMMEDIATE_EDGE_PROPAGATION_MODE,
   /*Decides the filter mode for falling Edge of the TIM Channel Input */ 
     IMMEDIATE_EDGE_PROPAGATION_MODE, 
     /*Input channel select : current chl or previous chl */
   INPUT_OF_CURRENT_TIM_CHANNEL, 
    }
  },  
  {
      /* ICU Channel 2 */
    (Icu_17_GtmCcu6_NotifiPtrType)0,/*Notification-function name*/
    {
      ICU_MODE_SIGNAL_EDGE_DETECT,/*Measurement Mode*/
      ICU_BOTH_EDGES,/*Default Start Edge */
      0U,/*Measurement Property*/
      ICU_NOT_WAKEUPCAPABLE,/*Wakeup capability*/
      GTM_TIM1_CHANNEL6,/* Assigned Hardware Resource Number */
      (uint8)ICU_GTM_OPTION, /* Assigned Hw Unit */
      0U, /* CCU connection */
      ICU_QM_SIGNAL, /* Safety ON or OFF*/        
      0U,/* Reserved */
    #if (ICU_SAFETY_ENABLE == STD_ON)   
     0U,/*Buffer Marker value */
    #endif   
     0U,/* Filtering time for rising edge */
     0U,/* Filtering time for falling edge */   
     GTM_INTERRUPT_LEVEL_MODE,/* Filtering time for TIM interrupt mode */
     GTM_CONFIGURABLE_CLOCK_0, /*Channel Clock Select */
     TIMEBASE_TBU_TS0,  /* Gpr0 input select for the Tim channel */   
     0U, /* Enables Filter for the Channel */
   /*Decides the filter Counter frequency for the TIM Channel */
     GTM_CONFIGURABLE_CLOCK_0,
   /*Decides the filter mode for rising Edge of the TIM Channel Input */
     IMMEDIATE_EDGE_PROPAGATION_MODE,
   /*Decides the filter mode for falling Edge of the TIM Channel Input */ 
     IMMEDIATE_EDGE_PROPAGATION_MODE, 
     /*Input channel select : current chl or previous chl */
   INPUT_OF_CURRENT_TIM_CHANNEL, 
    }
  },  
  {
      /* ICU Channel 3 */
    (Icu_17_GtmCcu6_NotifiPtrType)0,/*Notification-function name*/
    {
      ICU_MODE_SIGNAL_EDGE_DETECT,/*Measurement Mode*/
      ICU_BOTH_EDGES,/*Default Start Edge */
      0U,/*Measurement Property*/
      ICU_NOT_WAKEUPCAPABLE,/*Wakeup capability*/
      GTM_TIM2_CHANNEL1,/* Assigned Hardware Resource Number */
      (uint8)ICU_GTM_OPTION, /* Assigned Hw Unit */
      0U, /* CCU connection */
      ICU_QM_SIGNAL, /* Safety ON or OFF*/        
      0U,/* Reserved */
    #if (ICU_SAFETY_ENABLE == STD_ON)   
     0U,/*Buffer Marker value */
    #endif   
     0U,/* Filtering time for rising edge */
     0U,/* Filtering time for falling edge */   
     GTM_INTERRUPT_LEVEL_MODE,/* Filtering time for TIM interrupt mode */
     GTM_CONFIGURABLE_CLOCK_0, /*Channel Clock Select */
     TIMEBASE_TBU_TS0,  /* Gpr0 input select for the Tim channel */   
     0U, /* Enables Filter for the Channel */
   /*Decides the filter Counter frequency for the TIM Channel */
     GTM_CONFIGURABLE_CLOCK_0,
   /*Decides the filter mode for rising Edge of the TIM Channel Input */
     IMMEDIATE_EDGE_PROPAGATION_MODE,
   /*Decides the filter mode for falling Edge of the TIM Channel Input */ 
     IMMEDIATE_EDGE_PROPAGATION_MODE, 
     /*Input channel select : current chl or previous chl */
   INPUT_OF_CURRENT_TIM_CHANNEL, 
    }
  },  
  {
      /* ICU Channel 4 */
    (Icu_17_GtmCcu6_NotifiPtrType)0,/*Notification-function name*/
    {
      ICU_MODE_SIGNAL_EDGE_DETECT,/*Measurement Mode*/
      ICU_BOTH_EDGES,/*Default Start Edge */
      0U,/*Measurement Property*/
      ICU_NOT_WAKEUPCAPABLE,/*Wakeup capability*/
      GTM_TIM2_CHANNEL4,/* Assigned Hardware Resource Number */
      (uint8)ICU_GTM_OPTION, /* Assigned Hw Unit */
      0U, /* CCU connection */
      ICU_QM_SIGNAL, /* Safety ON or OFF*/        
      0U,/* Reserved */
    #if (ICU_SAFETY_ENABLE == STD_ON)   
     0U,/*Buffer Marker value */
    #endif   
     0U,/* Filtering time for rising edge */
     0U,/* Filtering time for falling edge */   
     GTM_INTERRUPT_LEVEL_MODE,/* Filtering time for TIM interrupt mode */
     GTM_CONFIGURABLE_CLOCK_0, /*Channel Clock Select */
     TIMEBASE_TBU_TS0,  /* Gpr0 input select for the Tim channel */   
     0U, /* Enables Filter for the Channel */
   /*Decides the filter Counter frequency for the TIM Channel */
     GTM_CONFIGURABLE_CLOCK_0,
   /*Decides the filter mode for rising Edge of the TIM Channel Input */
     IMMEDIATE_EDGE_PROPAGATION_MODE,
   /*Decides the filter mode for falling Edge of the TIM Channel Input */ 
     IMMEDIATE_EDGE_PROPAGATION_MODE, 
     /*Input channel select : current chl or previous chl */
   INPUT_OF_CURRENT_TIM_CHANNEL, 
    }
  },  
  {
      /* ICU Channel 5 */
    (Icu_17_GtmCcu6_NotifiPtrType)0,/*Notification-function name*/
    {
      ICU_MODE_SIGNAL_EDGE_DETECT,/*Measurement Mode*/
      ICU_BOTH_EDGES,/*Default Start Edge */
      0U,/*Measurement Property*/
      ICU_NOT_WAKEUPCAPABLE,/*Wakeup capability*/
      GTM_TIM2_CHANNEL5,/* Assigned Hardware Resource Number */
      (uint8)ICU_GTM_OPTION, /* Assigned Hw Unit */
      0U, /* CCU connection */
      ICU_QM_SIGNAL, /* Safety ON or OFF*/        
      0U,/* Reserved */
    #if (ICU_SAFETY_ENABLE == STD_ON)   
     0U,/*Buffer Marker value */
    #endif   
     0U,/* Filtering time for rising edge */
     0U,/* Filtering time for falling edge */   
     GTM_INTERRUPT_LEVEL_MODE,/* Filtering time for TIM interrupt mode */
     GTM_CONFIGURABLE_CLOCK_0, /*Channel Clock Select */
     TIMEBASE_TBU_TS0,  /* Gpr0 input select for the Tim channel */   
     0U, /* Enables Filter for the Channel */
   /*Decides the filter Counter frequency for the TIM Channel */
     GTM_CONFIGURABLE_CLOCK_0,
   /*Decides the filter mode for rising Edge of the TIM Channel Input */
     IMMEDIATE_EDGE_PROPAGATION_MODE,
   /*Decides the filter mode for falling Edge of the TIM Channel Input */ 
     IMMEDIATE_EDGE_PROPAGATION_MODE, 
     /*Input channel select : current chl or previous chl */
   INPUT_OF_CURRENT_TIM_CHANNEL, 
    }
  },  
  {
      /* ICU Channel 6 */
    (Icu_17_GtmCcu6_NotifiPtrType)0,/*Notification-function name*/
    {
      ICU_MODE_SIGNAL_EDGE_DETECT,/*Measurement Mode*/
      ICU_BOTH_EDGES,/*Default Start Edge */
      0U,/*Measurement Property*/
      ICU_NOT_WAKEUPCAPABLE,/*Wakeup capability*/
      GTM_TIM2_CHANNEL6,/* Assigned Hardware Resource Number */
      (uint8)ICU_GTM_OPTION, /* Assigned Hw Unit */
      0U, /* CCU connection */
      ICU_QM_SIGNAL, /* Safety ON or OFF*/        
      0U,/* Reserved */
    #if (ICU_SAFETY_ENABLE == STD_ON)   
     0U,/*Buffer Marker value */
    #endif   
     0U,/* Filtering time for rising edge */
     0U,/* Filtering time for falling edge */   
     GTM_INTERRUPT_LEVEL_MODE,/* Filtering time for TIM interrupt mode */
     GTM_CONFIGURABLE_CLOCK_0, /*Channel Clock Select */
     TIMEBASE_TBU_TS0,  /* Gpr0 input select for the Tim channel */   
     0U, /* Enables Filter for the Channel */
   /*Decides the filter Counter frequency for the TIM Channel */
     GTM_CONFIGURABLE_CLOCK_0,
   /*Decides the filter mode for rising Edge of the TIM Channel Input */
     IMMEDIATE_EDGE_PROPAGATION_MODE,
   /*Decides the filter mode for falling Edge of the TIM Channel Input */ 
     IMMEDIATE_EDGE_PROPAGATION_MODE, 
     /*Input channel select : current chl or previous chl */
   INPUT_OF_CURRENT_TIM_CHANNEL, 
    }
  },  
  {
      /* ICU Channel 7 */
    (Icu_17_GtmCcu6_NotifiPtrType)0,/*Notification-function name*/
    {
      ICU_MODE_SIGNAL_EDGE_DETECT,/*Measurement Mode*/
      ICU_BOTH_EDGES,/*Default Start Edge */
      0U,/*Measurement Property*/
      ICU_NOT_WAKEUPCAPABLE,/*Wakeup capability*/
      GTM_TIM2_CHANNEL7,/* Assigned Hardware Resource Number */
      (uint8)ICU_GTM_OPTION, /* Assigned Hw Unit */
      0U, /* CCU connection */
      ICU_QM_SIGNAL, /* Safety ON or OFF*/        
      0U,/* Reserved */
    #if (ICU_SAFETY_ENABLE == STD_ON)   
     0U,/*Buffer Marker value */
    #endif   
     0U,/* Filtering time for rising edge */
     0U,/* Filtering time for falling edge */   
     GTM_INTERRUPT_LEVEL_MODE,/* Filtering time for TIM interrupt mode */
     GTM_CONFIGURABLE_CLOCK_0, /*Channel Clock Select */
     TIMEBASE_TBU_TS0,  /* Gpr0 input select for the Tim channel */   
     0U, /* Enables Filter for the Channel */
   /*Decides the filter Counter frequency for the TIM Channel */
     GTM_CONFIGURABLE_CLOCK_0,
   /*Decides the filter mode for rising Edge of the TIM Channel Input */
     IMMEDIATE_EDGE_PROPAGATION_MODE,
   /*Decides the filter mode for falling Edge of the TIM Channel Input */ 
     IMMEDIATE_EDGE_PROPAGATION_MODE, 
     /*Input channel select : current chl or previous chl */
   INPUT_OF_CURRENT_TIM_CHANNEL, 
    }
  },  
  {
      /* ICU Channel 8 */
    (Icu_17_GtmCcu6_NotifiPtrType)0,/*Notification-function name*/
    {
      ICU_MODE_SIGNAL_EDGE_DETECT,/*Measurement Mode*/
      ICU_BOTH_EDGES,/*Default Start Edge */
      0U,/*Measurement Property*/
      ICU_NOT_WAKEUPCAPABLE,/*Wakeup capability*/
      GTM_TIM2_CHANNEL0,/* Assigned Hardware Resource Number */
      (uint8)ICU_GTM_OPTION, /* Assigned Hw Unit */
      0U, /* CCU connection */
      ICU_QM_SIGNAL, /* Safety ON or OFF*/        
      0U,/* Reserved */
    #if (ICU_SAFETY_ENABLE == STD_ON)   
     0U,/*Buffer Marker value */
    #endif   
     0U,/* Filtering time for rising edge */
     0U,/* Filtering time for falling edge */   
     GTM_INTERRUPT_LEVEL_MODE,/* Filtering time for TIM interrupt mode */
     GTM_CONFIGURABLE_CLOCK_0, /*Channel Clock Select */
     TIMEBASE_TBU_TS0,  /* Gpr0 input select for the Tim channel */   
     0U, /* Enables Filter for the Channel */
   /*Decides the filter Counter frequency for the TIM Channel */
     GTM_CONFIGURABLE_CLOCK_0,
   /*Decides the filter mode for rising Edge of the TIM Channel Input */
     IMMEDIATE_EDGE_PROPAGATION_MODE,
   /*Decides the filter mode for falling Edge of the TIM Channel Input */ 
     IMMEDIATE_EDGE_PROPAGATION_MODE, 
     /*Input channel select : current chl or previous chl */
   INPUT_OF_CURRENT_TIM_CHANNEL, 
    }
  },  
  {
      /* ICU Channel 9 */
    (Icu_17_GtmCcu6_NotifiPtrType)0,/*Notification-function name*/
    {
      ICU_MODE_SIGNAL_EDGE_DETECT,/*Measurement Mode*/
      ICU_BOTH_EDGES,/*Default Start Edge */
      0U,/*Measurement Property*/
      ICU_NOT_WAKEUPCAPABLE,/*Wakeup capability*/
      GTM_TIM1_CHANNEL7,/* Assigned Hardware Resource Number */
      (uint8)ICU_GTM_OPTION, /* Assigned Hw Unit */
      0U, /* CCU connection */
      ICU_QM_SIGNAL, /* Safety ON or OFF*/        
      0U,/* Reserved */
    #if (ICU_SAFETY_ENABLE == STD_ON)   
     0U,/*Buffer Marker value */
    #endif   
     0U,/* Filtering time for rising edge */
     0U,/* Filtering time for falling edge */   
     GTM_INTERRUPT_LEVEL_MODE,/* Filtering time for TIM interrupt mode */
     GTM_CONFIGURABLE_CLOCK_0, /*Channel Clock Select */
     TIMEBASE_TBU_TS0,  /* Gpr0 input select for the Tim channel */   
     0U, /* Enables Filter for the Channel */
   /*Decides the filter Counter frequency for the TIM Channel */
     GTM_CONFIGURABLE_CLOCK_0,
   /*Decides the filter mode for rising Edge of the TIM Channel Input */
     IMMEDIATE_EDGE_PROPAGATION_MODE,
   /*Decides the filter mode for falling Edge of the TIM Channel Input */ 
     IMMEDIATE_EDGE_PROPAGATION_MODE, 
     /*Input channel select : current chl or previous chl */
   INPUT_OF_CURRENT_TIM_CHANNEL, 
    }
  },  
  {
      /* ICU Channel 10 */
    (Icu_17_GtmCcu6_NotifiPtrType)0,/*Notification-function name*/
    {
      ICU_MODE_SIGNAL_EDGE_DETECT,/*Measurement Mode*/
      ICU_BOTH_EDGES,/*Default Start Edge */
      0U,/*Measurement Property*/
      ICU_NOT_WAKEUPCAPABLE,/*Wakeup capability*/
      GTM_TIM3_CHANNEL0,/* Assigned Hardware Resource Number */
      (uint8)ICU_GTM_OPTION, /* Assigned Hw Unit */
      0U, /* CCU connection */
      ICU_QM_SIGNAL, /* Safety ON or OFF*/        
      0U,/* Reserved */
    #if (ICU_SAFETY_ENABLE == STD_ON)   
     0U,/*Buffer Marker value */
    #endif   
     0U,/* Filtering time for rising edge */
     0U,/* Filtering time for falling edge */   
     GTM_INTERRUPT_LEVEL_MODE,/* Filtering time for TIM interrupt mode */
     GTM_CONFIGURABLE_CLOCK_0, /*Channel Clock Select */
     TIMEBASE_TBU_TS0,  /* Gpr0 input select for the Tim channel */   
     0U, /* Enables Filter for the Channel */
   /*Decides the filter Counter frequency for the TIM Channel */
     GTM_CONFIGURABLE_CLOCK_0,
   /*Decides the filter mode for rising Edge of the TIM Channel Input */
     IMMEDIATE_EDGE_PROPAGATION_MODE,
   /*Decides the filter mode for falling Edge of the TIM Channel Input */ 
     IMMEDIATE_EDGE_PROPAGATION_MODE, 
     /*Input channel select : current chl or previous chl */
   INPUT_OF_CURRENT_TIM_CHANNEL, 
    }
  },  
  {
      /* ICU Channel 11 */
    (Icu_17_GtmCcu6_NotifiPtrType)0,/*Notification-function name*/
    {
      ICU_MODE_SIGNAL_EDGE_DETECT,/*Measurement Mode*/
      ICU_BOTH_EDGES,/*Default Start Edge */
      0U,/*Measurement Property*/
      ICU_NOT_WAKEUPCAPABLE,/*Wakeup capability*/
      GTM_TIM3_CHANNEL1,/* Assigned Hardware Resource Number */
      (uint8)ICU_GTM_OPTION, /* Assigned Hw Unit */
      0U, /* CCU connection */
      ICU_QM_SIGNAL, /* Safety ON or OFF*/        
      0U,/* Reserved */
    #if (ICU_SAFETY_ENABLE == STD_ON)   
     0U,/*Buffer Marker value */
    #endif   
     0U,/* Filtering time for rising edge */
     0U,/* Filtering time for falling edge */   
     GTM_INTERRUPT_LEVEL_MODE,/* Filtering time for TIM interrupt mode */
     GTM_CONFIGURABLE_CLOCK_0, /*Channel Clock Select */
     TIMEBASE_TBU_TS0,  /* Gpr0 input select for the Tim channel */   
     0U, /* Enables Filter for the Channel */
   /*Decides the filter Counter frequency for the TIM Channel */
     GTM_CONFIGURABLE_CLOCK_0,
   /*Decides the filter mode for rising Edge of the TIM Channel Input */
     IMMEDIATE_EDGE_PROPAGATION_MODE,
   /*Decides the filter mode for falling Edge of the TIM Channel Input */ 
     IMMEDIATE_EDGE_PROPAGATION_MODE, 
     /*Input channel select : current chl or previous chl */
   INPUT_OF_CURRENT_TIM_CHANNEL, 
    }
  }
};








/*
typedef struct {
uint8 PhysicalChannelMap;
uint8 ChannelIndexMap;
}Icu_17_GtmCcu6_MapType; */


static const Icu_17_GtmCcu6_MapType Icu_17_GtmCcu6_MappingIndex0[ICU_MAX_CHANNELS] =
{



  /*DI_HALL_M1_A*/
  {   
    0U,
    /* Edge Detection, Indexing not required */
    0U
  },


  /*DI_HALL_M1_B*/
  {   
    1U,
    /* Edge Detection, Indexing not required */
    0U
  },


  /*DI_HALL_M1_C*/
  {   
    2U,
    /* Edge Detection, Indexing not required */
    0U
  },


  /*DI_HALL_M2_A*/
  {   
    3U,
    /* Edge Detection, Indexing not required */
    0U
  },


  /*DI_HALL_M2_B*/
  {   
    4U,
    /* Edge Detection, Indexing not required */
    0U
  },


  /*DI_HALL_M2_C*/
  {   
    5U,
    /* Edge Detection, Indexing not required */
    0U
  },


  /*DI_HALL_M3_A*/
  {   
    6U,
    /* Edge Detection, Indexing not required */
    0U
  },


  /*DI_HALL_M3_B*/
  {   
    7U,
    /* Edge Detection, Indexing not required */
    0U
  },


  /*DI_HALL_M3_C*/
  {   
    8U,
    /* Edge Detection, Indexing not required */
    0U
  },


  /*DI_HALL_M4_A*/
  {   
    9U,
    /* Edge Detection, Indexing not required */
    0U
  },


  /*DI_HALL_M4_B*/
  {   
    10U,
    /* Edge Detection, Indexing not required */
    0U
  },


  /*DI_HALL_M4_C*/
  {   
    11U,
    /* Edge Detection, Indexing not required */
    0U
  }
};



const Icu_17_GtmCcu6_ConfigType Icu_ConfigRoot[] =
{
  
  {
    /*Pointer to channel configuration set */
    &Icu_kChannelConfig0[0],
  
  /* Pointer to Phsycial channel mapping set */
  &Icu_17_GtmCcu6_MappingIndex0[0],
  
    #if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
    &Icu_kChannelWakeup0[0],
    #endif
    #if (ICU_ERU_SIGEDGE_USED == STD_ON)
    {
           ERU_REQLINE_UNUSED,
           ERU_REQLINE_UNUSED,
           ERU_REQLINE_UNUSED,
           ERU_REQLINE_UNUSED,
           ERU_REQLINE_UNUSED,
           ERU_REQLINE_UNUSED,
           ERU_REQLINE_UNUSED,
           ERU_REQLINE_UNUSED
    },
    #endif
    #if (ICU_CCU6_USED == STD_ON)
    /* T12ClkSelection -> Lower 3 bits (Bits 0 to 2)
       T12PrescalerEnabled -> Bit 3
       Ccu6SleepEnable -> Bit 4
       Initialized by ICU or not -> Bit 7. ICU Initialization -> 0, 
                                           Other Driver Initialization -> 1
    */
    
  {

      ICU_CCU6X_UNUSED,
      ICU_CCU6X_UNUSED,
    },
    #endif
    /*
     Enter the no of channels configured in the following order
     1. Number of Signal Edge Detection Channels.
     2. Number of Timestamp channels
     3. Number of EdgeCount Channels
     4. Number of Signal Measurement Channels.
    */
    {12U,0U,0U,0U}
 }
};

#define ICU_17_GTMCCU6_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"


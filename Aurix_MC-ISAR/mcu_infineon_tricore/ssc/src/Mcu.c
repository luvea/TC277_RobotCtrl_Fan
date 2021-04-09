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
**  $FILENAME   : Mcu.c $                                                    **
**                                                                           **
**  $CC VERSION : \main\158 $                                                **
**                                                                           **
**  $DATE       : 2016-09-22 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains functionality of MCU driver.            **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*  TRACEABILITY : [cover parentID=DS_NAS_MCU_PR912_1,DS_MCAL_SWSC_MCU0401,
  DS_NAS_MCU_PR123,DS_MCAL_MCU_050,DS_NAS_MCU_PR131,SAS_NAS_ALL_PR748,
  SAS_AS_MCU108_MCU211_MCU215_MCU109_MCU111_MCU213, SAS_NAS_ALL_PR102,
  SAS_NAS_ALL_PR470,SAS_NAS_ALL_PR471,SAS_NAS_ALL_PR70,SAS_NAS_ALL_PR749,
  SAS_NAS_ALL_PR630_PR631,SAS_NAS_ALL_PR1652][/cover]
                                                                  */
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of controller sfr file */
#include "IfxSmu_reg.h"
#include "IfxScu_bf.h"
  /* Inclusion of  Mcal header file */
#include "Mcal.h"

  /* Module header file, this includes module configuration file also */
  /* MCU108 :Inclusion of Mcu.h file*/
#include "Mcu.h"

#include "Mcu_Local.h"

#if (MCU_SAFETY_ENABLE == STD_ON)
#include "SafetyReport.h"
#endif


/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

#define MCU_PMSWCR1_IRADIS_CLEARMASK          0xFFFFEFFFU
#define MCU_PMSWCR1_IRADIS_SETMASK            0x00001000U
#define MCU_PMSWCR1_IRADIS_CLEARMASK1         0xFFFFEFFFU
#define MCU_PMSWCR1_IRADIS_SETMASK1           0x00000000U
#define MCU_CCUCON3_UP_CLEARMASK              0xBFFFFFFFU
#define MCU_CCUCON3_UP_SETMASK                0x40000000U
#define MCU_OSCCON_OSCVAL_CLEARMASK           0xFFE0FFFFU
#define MCU_OSCCON_OSCRES_CLEARMASK           0xFFFFFFFBU
#define MCU_OSCCON_OSCRES_SETMASK             0x00000004U
#define MCU_PLLSTAT_VCOBYST_CLEARMASK         0x00000001U
#define MCU_PLLCON1_K1DIV_CLEARMASK           0xFF80FFFFU
#define MCU_PLLCON1_K1DIV_SETMASK             0x00000000U
#define MCU_PLLCON0_OSCDISCDIS_CLEARMASK      0xFFFFFFBFU
#define MCU_PLLCON0_OSCDISCDIS_SETMASK        0x00000000U
#define MCU_PLLCON0_VCOBYP_CLEARMASK          0xFFFFFFFEU
#define MCU_PLLCON0_VCOBYP_SETMASK            0x00000001U
#define MCU_PLLCON0_SETFINDIS_CLEARMASK       0xFFFFFFEFU
#define MCU_PLLCON0_SETFINDIS_SETMASK         0x00000010U
#define MCU_PLLCON1_K1DIV_CLEARMASK1          0xFF80FFFFU
#define MCU_PLLCON0_OSCDISCDIS_CLEARMASK1     0xFFFFFFBFU
#define MCU_PLLCON0_OSCDISCDIS_SETMASK1       0x00000040U
#define MCU_PLLCON0_PLLPWD_CLEARMASK          0xFFFEFFFFU
#define MCU_PLLCON0_PLLPWD_SETMASK            0x00000000U
#define MCU_PLLCON0_CLRFINDIS_CLEARMASK       0xFFFFFFDFU
#define MCU_PLLCON0_CLRFINDIS_SETMASK         0x00000020U
#define MCU_CCUCON0_UP_CLEARMASK              0xBFFFFFFFU
#define MCU_CCUCON0_CLKSEL_CLEARMASK          0xCFFFFFFFU

#define MCU_CCUCON0_UP_CLEARMASK1             0xBFFFFFFFU

#define MCU_PLLCON1_K1DIV_CLEARMASK2          0xFF80FFFFU
#define MCU_PLLCON1_K1DIV_SETMASK2            0x00000000U
#define MCU_PLLCON0_OSCDISCDIS_CLEARMASK2     0xFFFFFFBFU
#define MCU_PLLCON0_OSCDISCDIS_SETMASK2       0x00000000U
#define MCU_PLLCON0_VCOBYP_CLEARMASK1         0xFFFFFFFEU
#define MCU_PLLCON0_VCOBYP_SETMASK1           0x00000001U
#define MCU_PLLCON0_SETFINDIS_CLEARMASK1      0xFFFFFFEFU
#define MCU_PLLCON0_SETFINDIS_SETMASK1        0x00000010U
#define MCU_PLLCON0_PDIV_CLEARMASK            0xF0FFFFFFU
#define MCU_PLLCON0_NDIV_CLEARMASK            0xFFFF01FFU
#define MCU_PLLCON1_K3DIV_CLEARMASK           0xFFFF80FFU
#define MCU_PLLCON0_OSCDISCDIS_CLEARMASK3     0xFFFFFFBFU
#define MCU_PLLCON0_OSCDISCDIS_SETMASK3       0x00000040U
#define MCU_PLLCON0_PLLPWD_CLEARMASK1         0xFFFEFFFFU
#define MCU_PLLCON0_PLLPWD_SETMASK1           0x00000000U
#define MCU_PLLCON0_CLRFINDIS_CLEARMASK1      0xFFFFFFDFU
#define MCU_PLLCON0_CLRFINDIS_SETMASK1        0x00000020U
#define MCU_PLLCON0_CLEARMASK                 0xFFFFFFFFU
#define MCU_PLLCON0_RESLD_CLEARMASK           0xFFFBFFFFU
#define MCU_PLLCON0_RESLD_SETMASK             0x00040000U
#define MCU_TRAPCLR_SMUT_CLEARMASK            0xFFFFFFF7U
#define MCU_TRAPCLR_SMUT_SETMASK              0x00000008U
#define MCU_PLLCON0_VCOBYP_CLEARMASK2         0xFFFFFFFEU
#define MCU_PLLCON0_VCOBYP_SETMASK2           0x00000000U
#define MCU_CCUCON0_UP_CLEARMASK2             0xBFFFFFFFU

#define MCU_CCUCON0_CLKSEL_CLEARMASK1         0xCFFFFFFFU

#define MCU_CCUCON0_UP_CLEARMASK3             0xBFFFFFFFU

#define MCU_PLLCON1_K2DIV_CLEARMASK1          0xFFFFFF80U
#define MCU_PLLCON0_OSCDISCDIS_CLEARMASK4     0xFFFFFFBFU
#define MCU_PLLCON0_OSCDISCDIS_SETMASK4       0x00000000U
#define MCU_PLLSTAT_VCOLOCK_CLEARMASK         0x00000004U
#define MCU_PMCSR_PMST_CLEARMASK              0x00000700U
#define MCU_CCUCON0_CLKSEL_CLEARMASK3         0x30000000U
#define MCU_PLLCON0_NDIV_CLEARMASK1           0x0000FE00U
#define MCU_PLLCON0_PDIV_CLEARMASK1           0x0F000000U
#define MCU_PLLCON0_K2DIV_CLEARMASK           0x0000007FU
#define MCU_PLLCON0_SRIDIV_CLEARMASK          0x00000F00U
#define MCU_PLLCON1_K2DIV_CLEARMASK           0xFFFFFF80U
#define MCU_CCUCON0_CLKSEL_CLEARMASK2         0xCFFFFFFFU

#define MCU_CCUCON1_INSEL_CLEARMASK           0xCFFFFFFFU
#define MCU_CCUCON1_INSEL_SETMASK             0x10000000U
#define MCU_CCUCON1_UP_CLEARMASK              0xBFFFFFFFU
#define MCU_CCUCON1_UP_SETMASK                0x40000000U
#define MCU_PLLCON1_CLEARMASK                 0xFFFFFF80U
#define MCU_SWRSTCON_CLEARMASK                0xFFFFFFFFU
#define MCU_SWRSTCON_SETMASK                  0x00000002U
#define MCU_CCUCON3_CLEARMASK                 0xFFFFFFFFU
#define MCU_CCUCON3_SETMASK                   0x40000000U
#define MCU_PLLCON0_CLEARMASK2                0xFFFFFFBFU
#define MCU_SMU_KEYS_MASK                     0x000000BCU
#define MCU_SMU_CMD_MASK                      0x00000005U
#define MCU_RSTCON2_CLEARMASK                 0xFFFFFFFFU
#define MCU_OSCCON_OSCVAL_BITPOS              16U
#define MCU_PLLCON1_K1DIV_BITPOS              16U
#define MCU_CCUCON0_UP_BITPOS                 30U
#define MCU_CCUCON0_CLKSEL_BITPOS             28U
#define MCU_PLLCON0_PDIV_BITPOS               24U
#define MCU_PLLCON0_NDIV_BITPOS               9U
#define MCU_PLLCON1_K3DIV_BITPOS              8U
#define MCU_PLLSTAT_VCOLOCK_BITPOS            2U
#define MCU_PMCSR_PMST_BITPOS                 8U
#define MCU_RSTCON2_BITPOS                    1U
#define MCU_PLLCON0_SRIDIV_BITPOS             8U


#define MCU_CCUCONREG_ID                  ((uint8)0x06U)
#define MCU_CCUCON_CPUDIV_MAX             ((uint8)0x3FU)

/* Register Mapping for WDG */
#define MCU_REGMAP       ((Ifx_SCU_CCUCON6*)(void*)&(SCU_CCUCON6))


/* Used to check the oscillator for PLL Valid Low Status Bit in OSCCON SFR*/
#define MCU_PLLLV_PLLHV_STATUS_CHECK   (0x00000102U)

#define MCU_RSTSTAT_MASK_VALUE         (0x13FD00FBU)
#define MCU_RSTSTAT_CLRC_BITS          (0x13810000U)

  /*This value masks the reset status register*/
#define MCU_RESET_REASON_MASK          (0x13BD00FBU)

  /*Delay in Microseconds for Mcu_InitClock and Mcu_DistributePllClock*/
#define MCU_DELAY                      (20UL)

/* When setting a bit to '1', this can be used */
#define MCU_BITVAL_1 (1U)

/* When setting a bit to '0', this can be used */
#define MCU_BITVAL_0 (0U)

/*Used for the delay after performing reset */
#define MCU_PERFORM_RESET_DELAY              (450000U)

/* Dealy for validating the frequency of PLL */
#define MCU_VALIDATE_OSC_FREQ_DELAY          (1000U)

/* Selection bit for normal mode in PLL status register */
#define MCU_PLLSTAT_NORMAL_MODE              (0x00U)

/* Delay for normal mode selection */
#define MCU_DELAY_NORMAL_MODE_SELECTION      (500U)

/* Macro to verify PLLCON0 - VCOBP = 1, OSCDISCDIS = 1 & PLLPWD = 1 */
#define MCU_PLLCON0_REGVAL_CHECK             (0x10001U)

/* Mask Values to be verified in Mcu_InitCheck */
#define MCU_PMSWCR1_MASK                     ((uint32)0x07001700U)
#define MCU_OSCCON_MASK                      ((uint32)0x001F0102U)
#define MCU_PLLCON0_NORMAL_MASK              ((uint32)0x0F01FE47U)
#define MCU_PLLCON0_PRESCALAR_MASK           ((uint32)0x00010003U)
#define MCU_PLLCON1_PRESCALAR_MASK           ((uint32)0x007F0000U)
/* Mask for SMU alarms configuration related to PLL and OSC */
#define MCU_PLL_OSC_SMU_MASK                 ((uint32)0x00000007U)
#define MCU_PLL_CLKM_SMU_MASK                ((uint32)0x000003F8U)

/* Mask for STM timer reset settings*/
#define MCU_STM_RESET_ENABLE_MASK            ((uint32)0x00000007U)
#define MCU_BACKUP_FREQ_TOLERANCE (20U)
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*Memory Map of the MCU Code*/
#define MCU_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives
 is allowed only for MemMap.h*/
#include "MemMap.h"
IFX_LOCAL_INLINE void Mcu_lSwitchToBackupClock(void);

#define MCU_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives
 is allowed only for MemMap.h*/
#include "MemMap.h"
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/


#if (MCU_PB_FIXEDADDR == STD_ON)
#define MCU_START_SEC_CONST_32BIT
/*
 * To be used for global or static variables (32 bits) that are initialized
 * after every reset (the normal case)
   Inclusion of MemMap.h
*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives
 is allowed only for MemMap.h*/
#include "MemMap.h"

/* To store the Mcu driver configuration pointer */
const Mcu_ConfigType * const Mcu_kConfigPtr = &Mcu_ConfigRoot[0];

 /*
 * To be used for global or static variables (32 bits) that are initialized
 * after every reset (the normal case)
   Inclusion of MemMap.h
*/
#define MCU_STOP_SEC_CONST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives
 is allowed only for MemMap.h*/
#include "MemMap.h"
#endif /*End Of MCU_PB_FIXEDADDR*/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

#define MCU_START_SEC_VAR_INIT_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives
 is allowed only for MemMap.h*/
#include "MemMap.h"

#if (MCU_PB_FIXEDADDR == STD_OFF)
const Mcu_ConfigType *Mcu_kConfigPtr = NULL_PTR;
#endif /* (MCU_PB_FIXEDADDR == STD_OFF)*/

/* No static qualifier -
 * To avoid different AUTOSAR versions and also for debug support
 * DS_AS40X_MCU200
 */

uint32 Mcu_ResetStatusVal = MCU_RAW_RESET_UNDEFINED;

#define MCU_STOP_SEC_VAR_INIT_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives
 is allowed only for MemMap.h*/
#include "MemMap.h"

#define MCU_START_SEC_VAR_8BIT
/*
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives
 is allowed only for MemMap.h*/
#include "MemMap.h"

/* No static qualifier -
 * To avoid different AUTOSAR versions and also for debug support
 * [cover parentID=DS_AS40X_MCU200] [/cover]
 */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
/*IFX_MISRA_RULE_08_07_STATUS=Objects shall be defined as block scope */
uint8 Mcu_DriverState;
#endif /* End MCU_DEV_ERROR_DETECT == STD_ON */

/* Simulating CCUCON register write failure */
#ifdef IFX_MCU_CCUCONREG_DEBUG
    extern volatile uint8 TestMcu_CcuconRegReadValue;
#endif

/* To store the Mcu clock setting used in Mcu_InitClock */
uint8 Mcu_ClockSetting;

  /*
  used for global or static variables (8 bits) that are initialized
  after every reset
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
#define MCU_STOP_SEC_VAR_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives
 is allowed only for MemMap.h*/
#include "MemMap.h"


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*Memory Map of the MCU Code*/
#define MCU_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives
 is allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
** Traceability    : [cover parentID=DS_AS_MCU101, DS_AS_MCU018,
   DS_AS_MCU026, DS_AS_MCU116, DS_AS_MCU245, DS_AS_MCU153, DS_MCAL_MCU_0403,
   DS_AS_MCU_PR459,DS_MCAL_MCU_0404][/cover]                                  **
**                                                                            **
** Syntax          : void Mcu_Init(const Mcu_ConfigType* ConfigPtr)           **
**                                                                 **
**                                                                            **
** Service ID      :    0                                                     **
**                                                                            **
** Sync/Async      :    Synchronous                                           **
**                                                                            **
** Reentrancy      :    Non Reentrant                                         **
**                                                                            **
** Parameters (in) :    ConfigPtr - Pointer to MCU Driver configuration set   **
**                                                                            **
** Parameters (out):    None                                                  **
**                                                                            **
** Return value    :    None                                                  **
**                                                                            **
** Description     : This routine initializes the MCU driver. The intention of**
**                 this function is to make the configuration settings for    **
**                 power down, clock and RAM sections visible within the MCU  **
**                 driver.
**                 MCU026, MCU116,MCU126: Initialization of Mcu driver        **
**                                                                            **
*******************************************************************************/
void Mcu_Init( const Mcu_ConfigType *ConfigPtr )
{
  uint32 ResetConfig;
  #if ((MCU_CRC_HW_USED == STD_ON)||(MCU_DMA_USED == STD_ON)||\
       (MCU_GTM_USED == STD_ON))
  Std_ReturnType ClcError = E_OK;
  #endif

  #if (( MCU_DEV_ERROR_DETECT == STD_ON ) || ( MCU_SAFETY_ENABLE == STD_ON ))
  uint32 ErrorFlag;

  /*Initialize Error Flag with No Error*/
  ErrorFlag = MCU_ERR_NOT_FOUND;

  #if (MCU_PB_FIXEDADDR == STD_OFF)
  /* MCU126 Parameter check for Init */
  /*For PB Fixed Address STD_OFF : Check if passed parameter is NULL*/
  /* MCU012, MCU016, MCU013
   MCU018 - ConfigPtr shall not be NULL pointer.  */
  if (ConfigPtr == NULL_PTR)
  #else
  /*For PB Fixed Address STD_ON :ConfigPtr and Mcu_kConfigPtr should match*/
  if (Mcu_kConfigPtr != ConfigPtr)
  #endif  /*End Of MCU_PB_FIXEDADDR*/
  {
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    Det_ReportError((uint16)MCU_MODULE_ID,MCU_MODULE_INSTANCE,
                     MCU_SID_INIT,MCU_E_PARAM_CONFIG);
    #endif

    #if (MCU_SAFETY_ENABLE == STD_ON)
    /* Report an error */
    SafeMcal_ReportError ((uint16)MCU_MODULE_ID,MCU_MODULE_INSTANCE,
                     MCU_SID_INIT,MCU_E_PARAM_CONFIG);
    #endif
    /*Error flag is set*/
    ErrorFlag = MCU_ERR_FOUND;
  }

  #elif ( MCU_DEV_ERROR_DETECT == STD_OFF )
  /* To remove compiler warning of unused variable ConfigPtr*/
  UNUSED_PARAMETER(ConfigPtr)
  #endif  /*End Of MCU_DEV_ERROR_DETECT == STD_OFF */

  #if (MCU_SAFETY_ENABLE == STD_ON)
  if ((ErrorFlag != MCU_ERR_FOUND) &&
      (ConfigPtr->Marker != ((uint32)MCU_MODULE_ID << 16U)))
  {
    /* report to upper layer */
    ErrorFlag = MCU_ERR_FOUND;
    SafeMcal_ReportError ((uint16)MCU_MODULE_ID,MCU_MODULE_INSTANCE,
                     MCU_SID_INIT,MCU_E_PARAM_CONFIG);

  }
  #endif /*End Of MCU_SAFETY_ENABLE*/
  #if ( MCU_DEV_ERROR_DETECT == STD_ON ) || ( MCU_SAFETY_ENABLE == STD_ON )
  /*If no error present*/
  if(ErrorFlag != MCU_ERR_FOUND)
  #endif
  {

     /*MCU120, MCU123, MCU124 Configuration  for PostBuild */
     /* Store the passed Mcu configuration parameter  ( Mcu_ConfigType* )*/

     #if (MCU_PB_FIXEDADDR == STD_OFF)
     /*MCU_PB_FIXEDADDR is STD_OFF : Assign ConfigPtr to the global variable*/
     Mcu_kConfigPtr = ConfigPtr;
     #endif /*End of MCU_PB_FIXEDADDR is STD_OFF*/


     /*Clear the SafetyENDINIT bit in the WDT_CON0 register in order
     to disable the write-protection for registers protected
     via the EndInit feature */
     MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);

     /*Capture the RSTSTAT register value in a variable*/

     Mcu_ResetStatusVal = (uint32)MCU_SFR_INIT_USER_MODE_READ32(SCU_RSTSTAT.U);

     /*Assign the master core to control system mode or cpu idle mode changes*/
     MCU_SFR_INIT_WRITE32(SCU_PMSWCR1.U,(((uint32)MCU_SYSTEM_MODE_CORE<<24U)|\
                                          ((uint32)MCU_IDLE_MODE_CORE<<8U)));
         /* CPUSEL bit */       /* CPUIDLSEL bit */
     #if (MCU_DISABLE_IRADIS == STD_ON)
     /* Set IRADIS (bit 12) to 1*/
     MCU_SFR_INIT_MODIFY32(SCU_PMSWCR1.U,MCU_PMSWCR1_IRADIS_CLEARMASK,\
                                                   MCU_PMSWCR1_IRADIS_SETMASK)
     #else
     /* Set IRADIS (bit 12) to 0*/
     MCU_SFR_INIT_MODIFY32(SCU_PMSWCR1.U,MCU_PMSWCR1_IRADIS_CLEARMASK1,
                                                MCU_PMSWCR1_IRADIS_SETMASK1)
     #endif

     /* Configure reset related registers */
     /* Configure RSTCON ; lower 16-bits */
     ResetConfig =(Mcu_kConfigPtr->ResetCfg) &0x0000FFFFU;

     MCU_SFR_INIT_WRITE32(SCU_RSTCON.U,(unsigned_int)ResetConfig);

     /* Configure ARSTDIS ; upper 16-bits */
     ResetConfig = Mcu_kConfigPtr->ResetCfg >> 16U;
     MCU_SFR_INIT_WRITE32(SCU_ARSTDIS.U,(unsigned_int)ResetConfig);

     /* End of setting reset related configuration */

     /* Configure Standby registers if enabled*/
     if (Mcu_kConfigPtr->StandbyCfgPtr != NULL_PTR)
     {
      /* Update PMSWCR0 register */
      MCU_SFR_INIT_WRITE32(MODULE_SCU.PMSWCR0.U,\
                                      (Mcu_kConfigPtr->StandbyCfgPtr->PMSWCR0));
     }

     /* Set the SafetyENDINIT bit in the WDT_CON0 register again
     to enable the write-protection and to prevent a time-out */
     MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();

     /*Call Gtm_Init()*/
     #if (MCU_GTM_USED == STD_ON)
     ClcError |= Gtm_Init(ConfigPtr->GtmConfigRootPtr);
     #endif /*End of MCU_GTM_USED STD_ON */

     #if (MCU_CRC_HW_USED == STD_ON)
     ClcError |= Mcu_lCrcPlatformInit();
     #endif

     #if (MCU_DMA_USED == STD_ON)
     ClcError |= Mcu_lDmaInit();
     #endif

     #if (MCU_DEV_ERROR_DETECT == STD_ON)
     /*To confirm initialization*/
     #if ((MCU_CRC_HW_USED == STD_ON)||(MCU_DMA_USED == STD_ON)||\
          (MCU_GTM_USED == STD_ON))
     if(ClcError == E_OK)
     #endif/*End for MCU_CRC_HW_USED OR MCU_DMA_USED OR MCU_GTM_USED*/
     {
       Mcu_DriverState = MCU_DRIVER_INITIALIZED;
     }
     #else
     #if ((MCU_CRC_HW_USED == STD_ON)||(MCU_DMA_USED == STD_ON)||\
          (MCU_GTM_USED == STD_ON))
     UNUSED_PARAMETER(ClcError)
     #endif/*End for MCU_CRC_HW_USED OR MCU_DMA_USED OR MCU_GTM_USED*/
     #endif /*End for MCU_DEV_ERROR_DETECT*/

     #if (MCU_SAFETY_ENABLE == STD_ON)
     #if ((MCU_CRC_HW_USED == STD_ON)||(MCU_DMA_USED == STD_ON)||\
          (MCU_GTM_USED == STD_ON))
     if(ClcError != E_OK)
     {
       /* Report an safety error */
       SafeMcal_ReportError((uint16)MCU_MODULE_ID,MCU_MODULE_INSTANCE,\
                                       MCU_SID_INIT,MCU_E_CLC_ERROR);
     }
     #endif/*End for MCU_CRC_HW_USED OR MCU_DMA_USED OR MCU_GTM_USED*/
     #endif/*End for MCU_SAFETY_ENABLE*/
  }

  return;

}/* End of Mcu_Init() */

#if (MCU_DEINIT_API == STD_ON)
/*******************************************************************************
** Traceability    : [cover parentID=DS_NAS_HE2_MCU_PR3019,
                                     DS_NAS_EP_MCU_PR3019][/cover]            **
**                                                                            **
** Syntax          : void Mcu_DeInit(void)                                    **
**                                                                            **
**                                                                            **
** Service ID      :    81                                                    **
**                                                                            **
** Sync/Async      :    Synchronous                                           **
**                                                                            **
** Reentrancy      :    Non Reentrant                                         **
**                                                                            **
** Parameters (in) :    None                                                  **
**                                                                            **
** Parameters (out):    None                                                  **
**                                                                            **
** Return value    :    None                                                  **
**                                                                            **
** Description     : This routine de-initializes the MCU driver. This
                     function puts all the resources used by MCU
                     for reset configuration and power management in
                     uninitialized state. PLL will not be de-initialized by
                     this function.
**                                                                            **
*******************************************************************************/
void Mcu_DeInit(void)
{
  #if ( MCU_DEV_ERROR_DETECT == STD_ON )
  uint32 ErrorFlag;

  /* Check whether Mcu_init is  called before this API.*/
  ErrorFlag = Mcu_lInitCallVerify(MCU_SID_DEINIT);

  /*If no error present*/
  if(ErrorFlag != MCU_ERR_FOUND)
  #endif
  {

     /*Clear the SafetyENDINIT bit in the WDT_CON0 register in order
     to disable the write-protection for registers protected
     via the EndInit feature */
     MCU_SFR_DEINIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);

     MCU_SFR_DEINIT_WRITE32(SCU_PMSWCR1.U,MCU_PMSWCR1_DEINIT_VALUE);

     MCU_SFR_DEINIT_WRITE32(SCU_RSTCON.U,\
                                         (unsigned_int)MCU_RSTCON_DEINIT_VALUE);

     MCU_SFR_DEINIT_WRITE32(SCU_ARSTDIS.U,\
                                        (unsigned_int)MCU_ARSTDIS_DEINIT_VALUE);

     MCU_SFR_DEINIT_WRITE32(MODULE_SCU.PMSWCR0.U,MCU_PMSWCR0_DEINIT_VALUE);

     /* Set the SafetyENDINIT bit in the WDT_CON0 register again
     to enable the write-protection and to prevent a time-out */
     MCU_SFR_DEINIT_SETSAFETYENDINIT_TIMED();


     #if (MCU_GTM_USED == STD_ON)
     /* GTM de-initialization */
     Gtm_DeInit();
     #endif  /*End of MCU_GTM_USED STD_ON */

     #if (MCU_CRC_HW_USED == STD_ON)
     /* CRC de-initialization */
     Mcu_lCrcDeInit();
     #endif

     #if (MCU_DMA_USED == STD_ON)
     /* DMA de-initialization */
     Mcu_lDmaDeInit();
     #endif

     #if (MCU_DEV_ERROR_DETECT == STD_ON)
     /*To confirm de-initialization*/
     Mcu_DriverState = MCU_DRIVER_UNINITIALIZED;
     #endif
     Mcu_ResetStatusVal = MCU_RAW_RESET_UNDEFINED;

     #if (MCU_PB_FIXEDADDR == STD_OFF)

     Mcu_kConfigPtr = NULL_PTR;

     #endif
  }

  return;

}/* End of Mcu_DeInit() */
#endif
/*******************************************************************************
** Traceability : [cover parentID=DS_AS_MCU101,SAS_MCAL_MCU_0427,
  SAS_MCAL_MCU_0426,DS_AS_MCU125, DS_AS_MCU011, DS_AS_MCU021, DS_AS_MCU154]   **
**                                                                            **
** Syntax : Std_ReturnType Mcu_InitRamSection                                 **
**           (                                                                **
**             Mcu_RamSectionType    RamSection                               **
**           )                                                                **
** [/cover]                                                                   **
**                                                                            **
** Service ID:    1                                                           **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non Reentrant                                               **
**                                                                            **
** Parameters (in):    RamSection: Selects RAM memory section provided in     **
**                     configuration set                                      **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:    E_OK: command has been accepted                           **
**                  E_NOT_OK: command has not been accepted                   **
**                   e.g. due to parameter error                              **
**                                                                            **
** Description : This function initializes the RAM section wise. The          **
**                 definition of the section and the initialization value is  **
**                 provided from the configuration structure                  **
**               MCU011: RAM is initialized section wise                      **
**                                                                            **
*******************************************************************************/
Std_ReturnType    Mcu_InitRamSection (Mcu_RamSectionType    RamSection )
{
  #if (MCU_RAM_SECTORS != 0U)
  /* Local variables used in this block */
  uint8                 *RamBasePtr;
  uint8                  RamData;
  Mcu_RamSizeType        RamLength;
  #endif /*(MCU_RAM_SECTORS != 0U)*/

  Std_ReturnType RetValue ;
  #if ( MCU_DEV_ERROR_DETECT == STD_ON ) || ( MCU_SAFETY_ENABLE == STD_ON )
  uint32 ErrorFlag;
  #endif

  #if ( MCU_DEV_ERROR_DETECT == STD_OFF ) && ( MCU_SAFETY_ENABLE == STD_ON )
  ErrorFlag = MCU_ERR_NOT_FOUND;
  #endif

  /*MCU101 : Parameter check for the API if DET is STD_ON*/
  #if ( MCU_DEV_ERROR_DETECT == STD_ON )
  /*MCU101 : Parameter check for the API if DET is STD_ON*/
  /* MCU012, MCU016, MCU013, MCU015  : DET Parameter checking*/
  /* MCU125 :Check whether Mcu_init is  called before this API.*/
  ErrorFlag = Mcu_lInitCallVerify(MCU_SID_INITRAMSECTION);

  /*If Error Flag is not set*/
  if (MCU_ERR_FOUND != ErrorFlag)
  #endif
  #if ( MCU_DEV_ERROR_DETECT == STD_ON ) || ( MCU_SAFETY_ENABLE == STD_ON )
  {
    /*MCU021 : Check whether RamSection shall be within the sections
    defined in Configuration structure*/
    if ( RamSection >= (Mcu_kConfigPtr->NoOfRamCfg))
    {
      #if (MCU_DEV_ERROR_DETECT == STD_ON)
      Det_ReportError((uint16)MCU_MODULE_ID,MCU_MODULE_INSTANCE,
                      MCU_SID_INITRAMSECTION,MCU_E_PARAM_RAMSECTION);
      #endif
      #if ( MCU_SAFETY_ENABLE == STD_ON )
      /* Report an error */
      SafeMcal_ReportError((uint16)MCU_MODULE_ID,MCU_MODULE_INSTANCE,
                     MCU_SID_INITRAMSECTION,MCU_E_PARAM_RAMSECTION);

      #endif
      ErrorFlag = MCU_ERR_FOUND;
    } /* end of if ( RamSection >= (Mcu_kConfigPtr->NoOfRamCfg)) */
  } /* end of if(MCU_ERR_FOUND != ErrorFlag) */

  if(ErrorFlag == MCU_ERR_FOUND)
  {
     /*Return E_NOT_OK if Error is present*/
     RetValue = E_NOT_OK;
  }
  else
  #elif ( MCU_DEV_ERROR_DETECT == STD_OFF ) && (MCU_RAM_SECTORS == 0U)
  /* To remove compiler warning of unused variable RamSection*/
  UNUSED_PARAMETER(RamSection)
  #endif /*End for MCU_DEV_ERROR_DETECT == STD_OFF && MCU_RAM_SECTORS == 0U */
  {  /* Return E_OK if no Error*/

     RetValue = E_OK;
     /* End of MCU_DEV_ERROR_DETECT */

     #if (MCU_RAM_SECTORS != 0U)

    /* It may so happen that, in multiple config sets, some config sets will
    have no ram sectors defined.  In that case, if there is a access to those
    pointers, we get a memory exception.  To avoid that, ensure we are not
    dealing with NULL_PTR */
    if(Mcu_kConfigPtr->RamCfgPtr != NULL_PTR)
    {
      /* Ram Section Base Address is copied to the local variable*/
       /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range*/
       RamBasePtr =
            (uint8*)(Mcu_kConfigPtr->RamCfgPtr[RamSection].RamBaseAdrPtr);

      /* Ram Section data pointer is copied to the local variable*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
       PBConfigStructure and is within allowed range*/
      RamData =
            (uint8)(Mcu_kConfigPtr->RamCfgPtr[RamSection].RamPrstData);
      /* RAM length of 8 bit words is copied to local variable */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
       PBConfigStructure and is within allowed range*/
      RamLength =
           (Mcu_kConfigPtr->RamCfgPtr[RamSection].RamSize);

      /* Initialize all the 8 bit locations with user configured value */
      while (RamLength > (Mcu_RamSizeType)0)
      {
        *RamBasePtr = RamData;
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used to
          traverse efficiently through the memory locations*/
        RamBasePtr++;
        RamLength--;
      }
    }
    #endif
  }
  /* Normal operation */
  return (RetValue);

}/*End Of Mcu_InitRamSection()*/

#if (MCU_INIT_CLOCK == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_AS_MCU101, DS_AS_MCU017, DS_AS_MCU125,
   DS_AS_MCU137, DS_AS_MCU138, DS_AS40X_MCU210, DS_AS40X_MCU248,
   DS_AS_MCU155, DS_AS_MCU019, DS_MCAL_MCU_0405, DS_NAS_HE2_MCU_PR2936,
   DS_NAS_EP_MCU_PR2936,DS_NAS_HE2_MCU_PR2983,DS_NAS_EP_MCU_PR2983,
                        DS_NAS_HE2_MCU_PR2984,DS_NAS_EP_MCU_PR2984,
                       DS_NAS_EP_MCU_PR3030,DS_NAS_HE2_MCU_PR3030]            **
**                                                                            **
** Syntax : Std_ReturnType Mcu_InitClock                                      **
**           (                                                                **
**              Mcu_ClockType    ClockSetting                                 **
**           )                                                                **
** [/cover]                                                                   **
**                                                                            **
** Service ID:    2                                                           **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non Reentrant                                               **
**                                                                            **
** Parameters (in):    ClockSetting:   Clock setting                          **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value:    E_OK: command has been accepted                           **
**                  E_NOT_OK: command has not been accepted                   **
**                   e.g. due to parameter error                              **
**                                                                            **
** Description : This function initializes the PLL and other MCU specific     **
**                 clock options. The clock configuration parameters are      **
**                 provided via the configuration structure. In this function **
**                 the PLL lock procedure is started (if PLL shall be         **
**                 initialized) but the function does not wait until the PLL  **
**                 is locked                                                  **
**               Note: Mcu_InitClock only initializes the PLL parameters.     **
**                 PLL clock will be activated to the MCU distribution only   **
**                 after the PLL is locked and then Mcu_DistributePllClock is **
**                 called. i.e The sequence to activate PLL clock to the MCU  **
**                 clock distribution is                                      **
**                  1)Call Mcu_InitClock                                      **
**                  2)Call Mcu_GetPllStatus                                   **
**                  3)Mcu_DistributePllClock                                  **
**               MCU009: PLL and other MCU specific clock initialization      **
**                                                                            **
*******************************************************************************/
Std_ReturnType Mcu_InitClock( Mcu_ClockType ClockSetting )
{
  /* Local variables used in this API */
  volatile uint32 TimeoutCtr;
  uint32 DelayCtr;
  uint32 OscconStatus;
  uint32 AG3CF0_Status;
  uint32 AG3CF1_Status;
  uint32 AG3CF2_Status;
  uint32 SmuStatus_Temp;
  Std_ReturnType RetValue;
  uint32 PllStableTimeoutCtr;
  #if ( MCU_DEV_ERROR_DETECT == STD_ON ) || ( MCU_SAFETY_ENABLE == STD_ON )
  uint32 ErrorFlag;
  #endif

  #if ( MCU_DEV_ERROR_DETECT == STD_OFF ) && ( MCU_SAFETY_ENABLE == STD_ON )
  ErrorFlag = MCU_ERR_NOT_FOUND;
  #endif

  /* Parameter check for the API if DET is STD_ON*/
  #if ( MCU_DEV_ERROR_DETECT == STD_ON )
  /* MCU012, MCU016, MCU013, MCU015  : DET Parameter checking*/
  /* MCU125 :Check whether Mcu_init is  called before this API.*/
  ErrorFlag = Mcu_lInitCallVerify(MCU_SID_INITCLOCK);

  /*If no Error is present*/
  if (MCU_ERR_FOUND != ErrorFlag)
  #endif
  #if ( MCU_DEV_ERROR_DETECT == STD_ON ) || ( MCU_SAFETY_ENABLE == STD_ON )
  {
    /* MCU019 :Check if the ID passed is valid */
    if ( ClockSetting >= Mcu_kConfigPtr->NoOfClockCfg )
    {
      #if (MCU_DEV_ERROR_DETECT == STD_ON)
      Det_ReportError((uint16)MCU_MODULE_ID,MCU_MODULE_INSTANCE,
                       MCU_SID_INITCLOCK,MCU_E_PARAM_CLOCK);
      #endif
      #if (MCU_SAFETY_ENABLE == STD_ON)
      /* Report an error */
      SafeMcal_ReportError((uint16)MCU_MODULE_ID,MCU_MODULE_INSTANCE,
                       MCU_SID_INITCLOCK,MCU_E_PARAM_CLOCK);

      #endif
      ErrorFlag = MCU_ERR_FOUND;
    } /* end of check for clock setting ID */

  } /* end of if (MCU_ERR_FOUND != ErrorFlag) */

  if (MCU_ERR_FOUND == ErrorFlag)
  {
     /*Return E_NOT_OK if error is present*/
     RetValue = E_NOT_OK;
  }
  else
  #endif /* (MCU_DEV_ERROR_DETECT == STD_ON) || (MCU_SAFETY_ENABLE == STD_ON)*/
  {
    /*Store the current status of PLL, OSC and Clock Monitoring Alarms*/
    AG3CF0_Status = ((uint32)MCU_SFR_INIT_USER_MODE_READ32(SMU_AGCF3_0.U)) \
                              & (MCU_PLL_OSC_SMU_MASK | MCU_PLL_CLKM_SMU_MASK);
    AG3CF1_Status = ((uint32)MCU_SFR_INIT_USER_MODE_READ32(SMU_AGCF3_1.U)) \
                              & (MCU_PLL_OSC_SMU_MASK | MCU_PLL_CLKM_SMU_MASK);
    AG3CF2_Status = ((uint32)MCU_SFR_INIT_USER_MODE_READ32(SMU_AGCF3_2.U)) \
                              & (MCU_PLL_OSC_SMU_MASK | MCU_PLL_CLKM_SMU_MASK);
    MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
    /* Enable access to SMU registers */
    MCU_SFR_INIT_WRITE32(SMU_KEYS.U,(unsigned_int)0x000000BCU);
    /*Clear all SMU alarms for PLL and OSC*/
    SmuStatus_Temp = (((uint32)MCU_SFR_INIT_USER_MODE_READ32\
          (SMU_AGCF3_0.U)) & (~(MCU_PLL_OSC_SMU_MASK | MCU_PLL_CLKM_SMU_MASK)));
    MCU_SFR_INIT_WRITE32(SMU_AGCF3_0.U,(unsigned_int)SmuStatus_Temp);
    MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();
    MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
    SmuStatus_Temp = (((uint32)MCU_SFR_INIT_USER_MODE_READ32(SMU_AGCF3_1.U)) &
                          (~(MCU_PLL_OSC_SMU_MASK | MCU_PLL_CLKM_SMU_MASK)));
    MCU_SFR_INIT_WRITE32(SMU_AGCF3_1.U,(unsigned_int)SmuStatus_Temp);
    SmuStatus_Temp =  (((uint32)MCU_SFR_INIT_USER_MODE_READ32(SMU_AGCF3_2.U)) &
                          (~(MCU_PLL_OSC_SMU_MASK | MCU_PLL_CLKM_SMU_MASK)));
    MCU_SFR_INIT_WRITE32(SMU_AGCF3_2.U,(unsigned_int)SmuStatus_Temp);
    /* Clear the keys to avoid any further update to SMU registers */
    MCU_SFR_INIT_WRITE32(SMU_KEYS.U,(unsigned_int)0U);
    MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();
    MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
    #if (MCU_ENABLE_CLOCK_MONITORING == STD_ON)
    /* Disable the clock monitoring unit */
    /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
    if((Mcu_lInitCcuconLckBitCheck((volatile uint32 *)(void *)&SCU_CCUCON3.U))\
                                          != (uint32)MCU_BITVAL_0)
    {                      
       MCU_SFR_INIT_WRITE32(SCU_CCUCON3.U,0U);
    }
  
    /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
    if((Mcu_lInitCcuconLckBitCheck((volatile uint32 *)(void *)&SCU_CCUCON4.U))\
                                          != (uint32)MCU_BITVAL_0)
    {                      
       MCU_SFR_INIT_WRITE32(SCU_CCUCON4.U,0U);
    }
  
    /* Single Update for all CCUCON3 & 4 registers*/
     /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
     if((Mcu_lInitCcuconLckBitCheck((volatile uint32 *)(void *)&SCU_CCUCON4.U))\
                                          != (uint32)MCU_BITVAL_0)
    {
     MCU_SFR_INIT_MODIFY32(SCU_CCUCON4.U,MCU_CCUCON3_UP_CLEARMASK,\
                                                       MCU_CCUCON3_UP_SETMASK)
    } 
    #endif
    MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();

     /* Switch to backup clock*/
    Mcu_lSwitchToBackupClock();

    MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
    /* OSCVAL  defines the divider value that generates  the reference clock
     that is supervised by the oscillator watchdog.
    fOSC / (OSCVAL + 1) ~ 2.5Mhz*/

    /* Setmask value corresponds to OSCVAL, bits 16 to 20 of SCU_OSCCON
    register*/
    MCU_SFR_INIT_MODIFY32(SCU_OSCCON.U,MCU_OSCCON_OSCVAL_CLEARMASK,\
                         (uint32)MCU_OSCVAL_REG_VALUE<<MCU_OSCCON_OSCVAL_BITPOS)

    /* The Oscillator Watchdog of the PLL(OSCRES: bit 2)
    is cleared and restarted */
    MCU_SFR_INIT_MODIFY32(SCU_OSCCON.U,MCU_OSCCON_OSCRES_CLEARMASK,\
                                                    MCU_OSCCON_OSCRES_SETMASK)

    /* Set the SafetyENDINIT bit in the WDT_CON0 register again
    to enable the write-protection and to prevent a time-out */
    MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();

    /* Timeout counter to come out of while loop in case the
      OSC frequency is not usable */
    TimeoutCtr = MCU_VALIDATE_OSC_FREQ_DELAY;

      /* wait until PLLLV and PLLHV flags are set */
    OscconStatus = (uint32)MCU_SFR_INIT_USER_MODE_READ32(SCU_OSCCON.U);
    while((TimeoutCtr > 0UL) && ((((OscconStatus) &
         (unsigned_int)MCU_PLLLV_PLLHV_STATUS_CHECK) !=
         ((unsigned_int)MCU_PLLLV_PLLHV_STATUS_CHECK))))
    {
      OscconStatus = (uint32)MCU_SFR_INIT_USER_MODE_READ32(SCU_OSCCON.U);
      --TimeoutCtr;
    }

    if(0U==TimeoutCtr)
    {
      #if(MCU_E_OSC_FAILURE_DEM_REPORT == MCU_ENABLE_DEM_REPORT)
      /*Report DEM for oscillator error*/
      Dem_ReportErrorStatus(MCU_E_OSC_FAILURE, DEM_EVENT_STATUS_FAILED);
      #endif /*End for(MCU_E_OSC_FAILURE_DEM_REPORT == MCU_ENABLE_DEM_REPORT)*/
      RetValue = E_NOT_OK;
    }
    else
    {
       /* Save the clock setting to be referred in Mcu Local functions
        * Mcu_lPlatformInit, Mcu_lInitClockMonitoring and also for
        * Mcu_DistributePllClock while configuring K2steps
        */
       Mcu_ClockSetting = (uint8)ClockSetting;

      /* PLL bypass mode : PLL is configured in Prescaler Mode*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
       PBConfigStructure and is within allowed range*/
      if (Mcu_kConfigPtr->ClockCfgPtr[ClockSetting].Mcu_ClockDivValues.PllMode\
                                                         == 0U)
      {
         /* Prescaler Mode for PLL */
         /* checking PLLBYPST flag(VCOBYST-bit 0)*/
         if(((uint32)(MCU_SFR_INIT_USER_MODE_READ32(SCU_PLLSTAT.U) & \
           MCU_PLLSTAT_VCOBYST_CLEARMASK)) == ((uint32)MCU_PLLSTAT_NORMAL_MODE))
         {
           /* Clear the SafetyENDINIT bit in the WDT_CON0 register in order
           to disable the write-protection for registers protected
           via the EndInit feature */
           MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
           /* Set K1DIV field(bits 16 to 22) to 0 */
           MCU_SFR_INIT_MODIFY32(SCU_PLLCON1.U,MCU_PLLCON1_K1DIV_CLEARMASK,\
                                                   MCU_PLLCON1_K1DIV_SETMASK)
           /* Set OSCDISCDIS field(bit 6) to 0 */
           MCU_SFR_INIT_MODIFY32(SCU_PLLCON0.U,\
              MCU_PLLCON0_OSCDISCDIS_CLEARMASK,MCU_PLLCON0_OSCDISCDIS_SETMASK)
           MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();
           MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);

           /*Enter Prescalar mode*/
           /* PLL is configured into Prescaler Mode; VCO is bypassed*/
           /* Set VCOBYP(bit 0) to 1*/
           MCU_SFR_INIT_MODIFY32(SCU_PLLCON0.U,MCU_PLLCON0_VCOBYP_CLEARMASK,\
                                                  MCU_PLLCON0_VCOBYP_SETMASK)
           /* Set SETFINDIS(bit 4) to 1*/
           MCU_SFR_INIT_MODIFY32(SCU_PLLCON0.U,MCU_PLLCON0_SETFINDIS_CLEARMASK,\
                                               MCU_PLLCON0_SETFINDIS_SETMASK)
           MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();
         }
          MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
          /* Set K1DIV(bits 16 to 22) as per configuration value*/
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
           PBConfigStructure and is within allowed range*/
          MCU_SFR_INIT_MODIFY32(SCU_PLLCON1.U,MCU_PLLCON1_K1DIV_CLEARMASK1,\
                                                    ((uint32)(Mcu_kConfigPtr->\
           ClockCfgPtr[ClockSetting].Mcu_ClockDivValues.K1div) <<\
                    MCU_PLLCON1_K1DIV_BITPOS))
         /* In case of a PLL loss-of-lock bit PLLSTAT.FINDIS is not set*/
         /* Set OSCDISCDIS(bit 6) to 1*/
         MCU_SFR_INIT_MODIFY32(SCU_PLLCON0.U,MCU_PLLCON0_OSCDISCDIS_CLEARMASK1,\
                                            MCU_PLLCON0_OSCDISCDIS_SETMASK1)

         /*Set PLL to power saving mode - errata*/
         /* Set PLLPWD(bit 16) to 0*/
         MCU_SFR_INIT_MODIFY32(SCU_PLLCON0.U,MCU_PLLCON0_PLLPWD_CLEARMASK,\
                                                   MCU_PLLCON0_PLLPWD_SETMASK)

         /* PLL delay to reach at intended target frequency after cold power on
         reset. EPN PLL_TC.005 */
          MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();

         DelayCtr = MCU_CONF_DELAY_PLL;
         for(;DelayCtr > 0U;DelayCtr--)
         {
           NOP();
         }
         MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
         /* The input clock from the oscillator is connected to the VCO part */
         /* Set CLRFINDIS(bit 5) to 1*/
         MCU_SFR_INIT_MODIFY32(SCU_PLLCON0.U,MCU_PLLCON0_CLRFINDIS_CLEARMASK,\
                                                MCU_PLLCON0_CLRFINDIS_SETMASK)
         /*Set PLL to Normal mode*/
         MCU_SFR_INIT_MODIFY32(SCU_PLLCON0.U,MCU_VCOPWD_IS_SET_TO_NORMAL,\
                                                   MCU_PLLPWD_IS_SET_TO_NORMAL)

         MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();
         /*Delay for PLL to be stable*/
         for(PllStableTimeoutCtr=0U;\
              PllStableTimeoutCtr < MCU_PLL_STABLE_DELAY; PllStableTimeoutCtr++)
         {
           NOP();
         }

         /* Call platform specific initialization */
         RetValue = Mcu_lPlatformInit();
   
         /* Reset safety end init protection for modification of SCU_CCUCON0*/
         MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
    /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, 
    since it gives compile time warning in windriver compiler*/
    if((Mcu_lInitCcuconLckBitCheck((volatile uint32 *)(void *)&SCU_CCUCON0.U))\
                                          != (uint32)MCU_BITVAL_0)
    {
          /*Set UP(bit 30) to 0   */
          /*Reserve bit access is ensured for CCUCON0 register*/
          MCU_SFR_INIT_MODIFY32(SCU_CCUCON0.U,MCU_CCUCON0_UP_CLEARMASK,\
                                  ((uint32)MCU_BITVAL_0<<MCU_CCUCON0_UP_BITPOS))

          /* Set PLL as clock source by setting CLKSEL bit field(bits 28,29) */
          /*Reserve bit access is ensured for CCUCON0 register*/
    }
     /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
       gives compile time warning in windriver compiler*/
     if((Mcu_lInitCcuconLckBitCheck((volatile uint32 *)(void *)&SCU_CCUCON0.U))\
                                            != (uint32)MCU_BITVAL_0)
        {
         MCU_SFR_INIT_MODIFY32(SCU_CCUCON0.U,MCU_CCUCON0_CLKSEL_CLEARMASK,\
                              ((uint32)MCU_BITVAL_1<<MCU_CCUCON0_CLKSEL_BITPOS))
        } 
         /* update for SCU_CCUCON0 by setting UP(bit 30) to 1 */
         /*Reserve bit access is ensured for CCUCON0 register*/
        /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
          gives compile time warning in windriver compiler*/
    if((Mcu_lInitCcuconLckBitCheck((volatile uint32 *)(void *)&SCU_CCUCON0.U))\
                                          != (uint32)MCU_BITVAL_0)
        {
          MCU_SFR_INIT_MODIFY32(SCU_CCUCON0.U,MCU_CCUCON0_UP_CLEARMASK1,\
                                                   MCU_CCUCON0_UP_SETMASK)
        } 
        
        /* Set safety end init protection back*/
         MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();
    
         /* Enable Clock monitoring unit */
         #if (MCU_ENABLE_CLOCK_MONITORING == STD_ON)
         Mcu_lInitClockMonitoring();
         #endif


      }
      else
      {
         /* Normal Mode. VCO is used */
         /* Clear the ENDINIT bit in the WDT_CON0 register in order
         to disable the write-protection for registers protected
         via the EndInit feature */
         MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);

         /*Enter Prescalar mode*/
         /* Set VCOBYP = 1* and configure K1DIV with 1*/
         MCU_SFR_INIT_MODIFY32(SCU_PLLCON1.U,MCU_PLLCON1_K1DIV_CLEARMASK2,\
                                                   MCU_PLLCON1_K1DIV_SETMASK2)

         /* In case of a PLL loss-of-lock bit PLLSTAT.FINDIS is set*/
         /* Set OSCDISCDIS(bit 6) to 0*/
         MCU_SFR_INIT_MODIFY32(SCU_PLLCON0.U,MCU_PLLCON0_OSCDISCDIS_CLEARMASK2,\
                                            MCU_PLLCON0_OSCDISCDIS_SETMASK2)
         /* PLL is configured into Prescaler Mode; VCO is bypassed*/
         /* Set VCOBYP(bit 0) to 1*/
         MCU_SFR_INIT_MODIFY32(SCU_PLLCON0.U,MCU_PLLCON0_VCOBYP_CLEARMASK1,\
                                                MCU_PLLCON0_VCOBYP_SETMASK1)
          MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();
          MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
         /* Bit PLLSTAT.FINDIS is set. The input clock from the oscillator is
            disconnected from the VCO part.*/
         /* Set SETFINDIS(bit 4) to 1*/
         MCU_SFR_INIT_MODIFY32(SCU_PLLCON0.U,MCU_PLLCON0_SETFINDIS_CLEARMASK1,\
                                                MCU_PLLCON0_SETFINDIS_SETMASK1)

        /* Set PDIV(Bits 24 to 27)with configured value*/
         /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
          PBConfigStructure and is within allowed range*/
        MCU_SFR_INIT_MODIFY32(SCU_PLLCON0.U,(uint32)MCU_PLLCON0_PDIV_CLEARMASK,\
                                                     ((uint32)(Mcu_kConfigPtr->\
                        ClockCfgPtr[ClockSetting].Mcu_ClockDivValues.Pdiv) << \
                                    MCU_PLLCON0_PDIV_BITPOS))
        /* Set NDIV(Bits 9 to 15) with configured value*/
         /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
          PBConfigStructure and is within allowed range*/
        MCU_SFR_INIT_MODIFY32(SCU_PLLCON0.U,(uint32)MCU_PLLCON0_NDIV_CLEARMASK,\
                                                     ((uint32)(Mcu_kConfigPtr->\
                     ClockCfgPtr[ClockSetting].Mcu_ClockDivValues.Ndiv) <<\
                                MCU_PLLCON0_NDIV_BITPOS))
        MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();
        MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
        /* Set K3DIV(bits 8 to 14) with configured value*/
         /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
          PBConfigStructure and is within allowed range*/
         MCU_SFR_INIT_MODIFY32(SCU_PLLCON1.U,MCU_PLLCON1_K3DIV_CLEARMASK,\
                                                      (uint32)(Mcu_kConfigPtr->\
                      ClockCfgPtr[ClockSetting].Mcu_ClockDivValues.K3div) <<\
                            MCU_PLLCON1_K3DIV_BITPOS)
        /* Set K2DIV(bits 0 to 6) with configured value*/
         /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
          PBConfigStructure and is within allowed range*/
         MCU_SFR_INIT_MODIFY32(SCU_PLLCON1.U,MCU_PLLCON1_K2DIV_CLEARMASK,\
                    (uint32)Mcu_kConfigPtr->ClockCfgPtr[ClockSetting].K2div[0])

         /* In case of a PLL loss-of-lock bit PLLSTAT.FINDIS is not set*/
         /* Set OSCDISCDIS(bit 6) to 1*/
         MCU_SFR_INIT_MODIFY32(SCU_PLLCON0.U,MCU_PLLCON0_OSCDISCDIS_CLEARMASK3,\
                                            MCU_PLLCON0_OSCDISCDIS_SETMASK3)

         /*Set PLL to power saving mode - errata*/
         /* Set PLLPWD(bit 16) to 0*/
         MCU_SFR_INIT_MODIFY32(SCU_PLLCON0.U,MCU_PLLCON0_PLLPWD_CLEARMASK1,\
                                                MCU_PLLCON0_PLLPWD_SETMASK1)
         MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();
         /* PLL delay to reach at intended target frequency after cold power on
         reset. EPN PLL_TC.005 */
         DelayCtr = MCU_CONF_DELAY_PLL;
         for(;DelayCtr > 0U;DelayCtr--)
         {
           NOP();
         }
         MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
         /* The input clock from the oscillator is connected to the VCO part */
         /* Set CLRFINDIS(bit 5) to 1*/
         MCU_SFR_INIT_MODIFY32(SCU_PLLCON0.U,MCU_PLLCON0_CLRFINDIS_CLEARMASK1,\
                                                MCU_PLLCON0_CLRFINDIS_SETMASK1)

         /*Set PLL to Normal mode - Exit Power Saving Mode*/
         MCU_SFR_INIT_MODIFY32(SCU_PLLCON0.U, MCU_VCOPWD_IS_SET_TO_NORMAL,\
                                                   MCU_PLLPWD_IS_SET_TO_NORMAL)

         MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();

         #if (MCU_FMPLL_ENABLE == STD_ON)

         MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
         MCU_SFR_INIT_MODIFY32(SCU_PLLCON0.U,MCU_PLLCON0_CLEARMASK,\
                               ((unsigned_int)1U << IFX_SCU_PLLCON0_MODEN_OFF))
         /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
          PBConfigStructure and is within allowed range*/
         MCU_SFR_INIT_WRITE32(SCU_PLLCON2.U,\
               (unsigned_int)Mcu_kConfigPtr->ClockCfgPtr[ClockSetting].Pllcon2);
         MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();
         #endif

         /* Delay for PLL to be stable - errata */
         for(PllStableTimeoutCtr=0U; PllStableTimeoutCtr < MCU_PLL_STABLE_DELAY;
             PllStableTimeoutCtr++)
         {
           NOP();
         }
         MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
         /* restart the VCO lock detection */
         /* Set RESLD(bit 18) to 1*/
         MCU_SFR_INIT_MODIFY32(SCU_PLLCON0.U,MCU_PLLCON0_RESLD_CLEARMASK,\
                                                    MCU_PLLCON0_RESLD_SETMASK)

         /* Set the ENDINIT bit in the WDT_CON0 register again
         to enable the write-protection and to prevent a time-out */
         MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();

         /* Initialize all clock dividers */
         /* Call platform specific initialization */
         RetValue = Mcu_lPlatformInit();
      }
    }

    /*Restore the SMU Status*/
    MCU_SFR_INIT_RESETENDINIT();
    /*Clear any SMU TRAP request*/
    /*Set SMUT (bit 3) to 1*/
    MCU_SFR_INIT_MODIFY32(SCU_TRAPCLR.U,MCU_TRAPCLR_SMUT_CLEARMASK,\
                                                    MCU_TRAPCLR_SMUT_SETMASK)
    MCU_SFR_INIT_SETENDINIT();

    MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
    /* Enable access to SMU registers */
    MCU_SFR_INIT_WRITE32(SMU_KEYS.U,((unsigned_int)MCU_SMU_KEYS_MASK));
    MCU_SFR_INIT_WRITE32(SMU_CMD.U,((unsigned_int)MCU_SMU_CMD_MASK));
    /*Clear SMU alarms. To clear alarms SET the corresponding bit to 1.*/
    MCU_SFR_INIT_WRITE32(SMU_AG3.U,((unsigned_int)(MCU_PLL_OSC_SMU_MASK | \
                                                       MCU_PLL_CLKM_SMU_MASK)));
    MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();
    MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
    /*Restore SMU alarm configuration for PLL, OSC & Clock Monitoring Alarms*/
    SmuStatus_Temp = (((uint32)MCU_SFR_INIT_USER_MODE_READ32(SMU_AGCF3_0.U)) | \
                                                                 AG3CF0_Status);
    MCU_SFR_INIT_WRITE32(SMU_AGCF3_0.U,((unsigned_int)SmuStatus_Temp));
    SmuStatus_Temp = (((uint32)MCU_SFR_INIT_USER_MODE_READ32(SMU_AGCF3_1.U)) | \
                                                                 AG3CF1_Status);
    MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();
    MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
    MCU_SFR_INIT_WRITE32(SMU_AGCF3_1.U,((unsigned_int)SmuStatus_Temp));
    SmuStatus_Temp = (((uint32)MCU_SFR_INIT_USER_MODE_READ32(SMU_AGCF3_2.U)) | \
                                                                 AG3CF2_Status);
    MCU_SFR_INIT_WRITE32(SMU_AGCF3_2.U,((unsigned_int)SmuStatus_Temp));
    /* Clear the keys to avoid any further update to SMU registers */
    MCU_SFR_INIT_WRITE32(SMU_KEYS.U,((unsigned_int)0U));
    MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();
  }
  return (RetValue);
}/* End of Mcu_InitClock() */

#endif/* End of (MCU_INIT_CLOCK == STD_ON)*/

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_MCU101, DS_AS_MCU125,DS_AS_MCU122,
                   DS_AS_MCU140, DS_AS40X_MCU205, DS_AS_MCU156,
          DS_MCAL_MCU_0406, DS_NAS_EP_MCU_PR2985_1, DS_NAS_HE2_MCU_PR2985_1]  **
**                                                                            **
** Syntax : void Mcu_DistributePllClock( void )                               **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID:    3                                                           **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non Reentrant                                               **
**                                                                            **
** Parameters (in):   None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value:      none                                                    **
**                                                                            **
** Description : This function activates the PLL clock to the MCU clock       **
**                 distribution. This function shall be executed, if the MCU  **
**                 needs a separate request to activate the PLL clock after   **
**                 the PLL is locked. In this case the current clock source   **
**                 (for example internal oscillator clock) is removed         **
**                 from MCU clock distribution.                               **
**               Note: Mcu_InitClock only initializes the PLL parameters.     **
**                 PLL clock will be activated to the MCU distribution only   **
**                 after the PLL is locked and then Mcu_DistributePllClock is **
**                 called. i.e The sequence to activate PLL clock to the MCU  **
**                 clock distribution is                                      **
**                  1)Call Mcu_InitClock                                      **
**                  2)Call Mcu_GetPllStatus                                   **
**                  3)Mcu_DistributePllClock                                  **
**               MCU028,MCU056: Activates PLL for clock distribution  .       **
**                                                                            **
*******************************************************************************/
void Mcu_DistributePllClock ( void )
{
  uint32 Index;
  uint32 K2Divsteps;
  uint32 Delay;
  uint32 K2RampUpDelay;
  #if ( MCU_DEV_ERROR_DETECT == STD_ON ) || (MCU_SAFETY_ENABLE == STD_ON)
  uint32 ErrorFlag;
  #endif

  #if ( MCU_DEV_ERROR_DETECT == STD_OFF ) && ( MCU_SAFETY_ENABLE == STD_ON )
  ErrorFlag = MCU_ERR_NOT_FOUND;
  #endif

  /*  Parameter check for the API if DET is STD_ON*/
  #if ( MCU_DEV_ERROR_DETECT == STD_ON )

  /*MCU101 : Parameter check for the API if DET is STD_ON*/
  /* MCU012, MCU016, MCU013, MCU015  : DET Parameter checking*/
  /* MCU125 :Check whether Mcu_init is  called before this API.*/
  ErrorFlag = Mcu_lInitCallVerify(MCU_SID_DISTRIBUTEPLLCLOCK);
  if (MCU_ERR_FOUND != ErrorFlag)
  #endif
  #if ( MCU_DEV_ERROR_DETECT == STD_ON ) || (MCU_SAFETY_ENABLE == STD_ON)
  {
    /* MCU122 :Check if PLL is locked by checking VCOLOCK(bit 2) */
    if((Mcu_PllStatusType)((MCU_SFR_INIT_USER_MODE_READ32(SCU_PLLSTAT.U) & \
             MCU_PLLSTAT_VCOLOCK_CLEARMASK) >> MCU_PLLSTAT_VCOLOCK_BITPOS) != \
                                                                MCU_PLL_LOCKED)
    {
      #if ( MCU_DEV_ERROR_DETECT == STD_ON )
      Det_ReportError((uint16)MCU_MODULE_ID,MCU_MODULE_INSTANCE,
                       MCU_SID_DISTRIBUTEPLLCLOCK,MCU_E_PLL_NOT_LOCKED);
      #endif
      #if (MCU_SAFETY_ENABLE == STD_ON)
      /* Report an error */
      SafeMcal_ReportError((uint16)MCU_MODULE_ID,MCU_MODULE_INSTANCE,
                       MCU_SID_DISTRIBUTEPLLCLOCK,MCU_E_PLL_NOT_LOCKED);

      #endif
      ErrorFlag = MCU_ERR_FOUND;
    }
  }
  /*Execute only if Error is not set */
  if (MCU_ERR_FOUND != ErrorFlag)
  #endif /* (MCU_DEV_ERROR_DETECT == STD_ON) || (MCU_SAFETY_ENABLE == STD_ON)*/
  {
    uint32 AG3CF0_Status;
    uint32 AG3CF1_Status;
    uint32 AG3CF2_Status;
    uint32 SmuStatus_Temp;

    /*Get the K2 Intermediate step values */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
     PBConfigStructure and is within allowed range*/
    K2Divsteps = ((uint32)(Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].\
                                  Mcu_ClockDivValues.K2steps) + 1U);
    Index = 1U;

    /* Clear the ENDINIT bit in the WDT_CON0 register in order
    to disable the write-protection for registers protected
    via the EndInit feature */
    MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);

    /* Normal operation, VCO is not bypassed */
    /* Set VCOBYP(bit 0) to 0*/
    MCU_SFR_INIT_MODIFY32(SCU_PLLCON0.U,MCU_PLLCON0_VCOBYP_CLEARMASK2,\
                                                 MCU_PLLCON0_VCOBYP_SETMASK2)

     /* Give a delay for normal mode selection */
    for (Delay = 0U; Delay < MCU_DELAY_NORMAL_MODE_SELECTION; Delay++)
    {
       NOP();
    }

    /* Set UP(bit 30) to 0*/
    /*Reserve bit access is ensured for CCUCON0 register*/
    /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
    if((Mcu_lInitCcuconLckBitCheck((volatile uint32 *)(void *)&SCU_CCUCON0.U))\
                                            != (uint32)MCU_BITVAL_0)
    {
      MCU_SFR_INIT_MODIFY32(SCU_CCUCON0.U,MCU_CCUCON0_UP_CLEARMASK2,\
                                                   MCU_CCUCON0_UP_SETMASK2)
    }
    /* Set PLL as clock source */
    /*Set CLKSEL(bits 28:29) as 1U*/
    /*Reserve bit access is ensured for CCUCON0 register*/
    /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
    if((Mcu_lInitCcuconLckBitCheck((volatile uint32 *)(void *)&SCU_CCUCON0.U))\
                                            != (uint32)MCU_BITVAL_0)
    {
      MCU_SFR_INIT_MODIFY32(SCU_CCUCON0.U,MCU_CCUCON0_CLKSEL_CLEARMASK1,\
                                                MCU_CCUCON0_CLKSEL_SETMASK)
    }
    /* update for SCU_CCUCON0  */
    /* Set UP(bit 30) to 0*/
    /*Reserve bit access is ensured for CCUCON0 register*/
    /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
    if((Mcu_lInitCcuconLckBitCheck((volatile uint32 *)(void *)&SCU_CCUCON0.U))\
                                            != (uint32)MCU_BITVAL_0)
    {
      MCU_SFR_INIT_MODIFY32(SCU_CCUCON0.U,MCU_CCUCON0_UP_CLEARMASK3,\
                                                  MCU_CCUCON0_UP_SETMASK)
    }
    /* Set the SafetyENDINIT bit in the WDT_CON0 register again
    to enable the wr   ite-protection and to prevent a time-out */
    MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();

    /*Run a loop for desired number of K2 intermediate step values*/
    do
    {
       /* Clear the ENDINIT bit in the WDT_CON0 register in order
       to disable the write-protection for registers protected
       via the EndInit feature */
       MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);

      /* Configure the next K2 step value */
      /* Set K2DIV(Bits 0 to 6) to configured value*/
      /* IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
       PBConfigStructure and is within allowed range */
       MCU_SFR_INIT_MODIFY32(SCU_PLLCON1.U,MCU_PLLCON1_CLEARMASK,\
                    Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].K2div[Index])

       /* Set the SafetyENDINIT bit in the WDT_CON0 register again
       to enable the wr   ite-protection and to prevent a time-out */
       MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();

       /* Wait for the configured delay before ramping up K2 divider further */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
       PBConfigStructure and is within allowed range*/
      K2RampUpDelay = Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].\
                                            K2RampToPllDelayTicks[Index];
      for(;K2RampUpDelay>0U;K2RampUpDelay--)
      {
        NOP();
      }
      Index++;
    } while (Index <= K2Divsteps);

    /* Clear the ENDINIT bit in the WDT_CON0 register in order
    to disable the write-protection for registers protected
    via the EndInit feature */
    MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);

    /* In case of a PLL loss-of-lock bit PLLSTAT.FINDIS is cleared */
    /* Set OSCDISCDIS(bit 6) to 0*/
    MCU_SFR_INIT_MODIFY32(SCU_PLLCON0.U,MCU_PLLCON0_OSCDISCDIS_CLEARMASK4,\
                                               MCU_PLLCON0_OSCDISCDIS_SETMASK4)

    /*Store the current status of PLL and OSC Alrams*/
    AG3CF0_Status = (((uint32)MCU_SFR_INIT_USER_MODE_READ32(SMU_AGCF3_0.U)) \
                                                       & MCU_PLL_CLKM_SMU_MASK);
    AG3CF1_Status = (((uint32)MCU_SFR_INIT_USER_MODE_READ32(SMU_AGCF3_1.U)) \
                                                       & MCU_PLL_CLKM_SMU_MASK);
    AG3CF2_Status = (((uint32)MCU_SFR_INIT_USER_MODE_READ32(SMU_AGCF3_2.U)) \
                                                       & MCU_PLL_CLKM_SMU_MASK);
    /* Enable access to SMU registers */
    MCU_SFR_INIT_WRITE32(SMU_KEYS.U,(unsigned_int)MCU_SMU_KEYS_MASK);
    /*Clear all SMU alarms for PLL and OSC*/
    SmuStatus_Temp = (((uint32)MCU_SFR_INIT_USER_MODE_READ32\
                                   (SMU_AGCF3_0.U)) & (~MCU_PLL_CLKM_SMU_MASK));
    MCU_SFR_INIT_WRITE32(SMU_AGCF3_0.U,(unsigned_int)SmuStatus_Temp);
    SmuStatus_Temp = (((uint32)MCU_SFR_INIT_USER_MODE_READ32\
                                   (SMU_AGCF3_1.U)) & (~MCU_PLL_CLKM_SMU_MASK));
    MCU_SFR_INIT_WRITE32(SMU_AGCF3_1.U,(unsigned_int)SmuStatus_Temp);
    SmuStatus_Temp = (((uint32)MCU_SFR_INIT_USER_MODE_READ32\
                                   (SMU_AGCF3_2.U)) & (~MCU_PLL_CLKM_SMU_MASK));
    MCU_SFR_INIT_WRITE32(SMU_AGCF3_2.U,(unsigned_int)SmuStatus_Temp);
    /* Clear the keys to avoid any further update to SMU registers */
    MCU_SFR_INIT_WRITE32(SMU_KEYS.U,(unsigned_int)0U);

    MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();

    /* Enable Clock monitoring unit */
    #if (MCU_ENABLE_CLOCK_MONITORING == STD_ON)
    Mcu_lInitClockMonitoring();
    #endif

    MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
    /* Enable access to SMU registers */
    MCU_SFR_INIT_WRITE32(SMU_KEYS.U,(unsigned_int)MCU_SMU_KEYS_MASK);
    MCU_SFR_INIT_WRITE32(SMU_CMD.U,(unsigned_int)MCU_SMU_CMD_MASK);
    /*Clear SMU alarms. To clear alarms SET the corresponding bit to 1.*/
    MCU_SFR_INIT_WRITE32(SMU_AG3.U,(unsigned_int)MCU_PLL_CLKM_SMU_MASK);
    /*Restore SMU alarm configuration for PLL & OSC*/
    SmuStatus_Temp = (((uint32)MCU_SFR_INIT_USER_MODE_READ32\
                                              (SMU_AGCF3_0.U)) | AG3CF0_Status);
    MCU_SFR_INIT_WRITE32(SMU_AGCF3_0.U,(unsigned_int)SmuStatus_Temp);
    SmuStatus_Temp = (((uint32)MCU_SFR_INIT_USER_MODE_READ32\
                                              (SMU_AGCF3_1.U)) | AG3CF1_Status);
    MCU_SFR_INIT_WRITE32(SMU_AGCF3_1.U,(unsigned_int)SmuStatus_Temp);
    SmuStatus_Temp = (((uint32)MCU_SFR_INIT_USER_MODE_READ32\
                                              (SMU_AGCF3_2.U)) | AG3CF2_Status);
    MCU_SFR_INIT_WRITE32(SMU_AGCF3_2.U,(unsigned_int)SmuStatus_Temp);
    /* Clear the keys to avoid any further update to SMU registers */
    MCU_SFR_INIT_WRITE32(SMU_KEYS.U,(unsigned_int)0U);

    /* Set the SafetyENDINIT bit in the WDT_CON0 register again
    to enable the wr   ite-protection and to prevent a time-out */
    MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();
  }
  return;
}/* End of Mcu_DistributePllClock() */

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_MCU101, DS_AS_MCU125,DS_AS40X_MCU230
                   DS_AS_MCU008, DS_AS_MCU132, DS_AS_MCU157]                  **
**                                                                            **
** Syntax : Mcu_PllStatusType Mcu_GetPllStatus( void )                        **
** [/cover]                                                                   **
**                                                                            **
** Service ID:    4                                                           **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Reentrant                                                   **
**                                                                            **
** Parameters (in):    None                                                   **
**                                                                            **
** Parameters (out):   None                                                   **
**                                                                            **
** Return value:   Mcu_PllStatusType                                          **
**                 Returns whether PLL is Locked,Unlocked or Undefined status **
**                                                                            **
** Description : This function provides the lock status of the PLL            **
**               MCU008: Lock status of the PLL is provided                   **
**                                                                            **
*******************************************************************************/
Mcu_PllStatusType    Mcu_GetPllStatus ( void )
{

  Mcu_PllStatusType RetValue;
  /*MCU101 : Parameter check for the API if DET is STD_ON*/
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  uint32 ErrorFlag;
  ErrorFlag = Mcu_lInitCallVerify(MCU_SID_GETPLLSTATUS);
  /* MCU012, MCU016, MCU013, MCU015  : DET Parameter checking*/
  /* MCU125 :Check whether Mcu_init is  called before this API.*/
  if (MCU_ERR_FOUND == ErrorFlag)
  {
     /*Return Undefined in case of Error */
     RetValue = MCU_PLL_STATUS_UNDEFINED;
  }
  else
  #endif
  {
     /*Return the pll lock staus(VCOLOCK-bit 2)*/
     RetValue =  (Mcu_PllStatusType)((MCU_SFR_INIT_USER_MODE_READ32\
                           (SCU_PLLSTAT.U) & MCU_PLLSTAT_VCOLOCK_CLEARMASK) >> \
                                                    MCU_PLLSTAT_VCOLOCK_BITPOS);
  }
  return(RetValue);
}/* End of Mcu_GetPllStatus() */
/*******************************************************************************
** Traceability : [cover parentID=DS_AS_MCU101, DS_AS_MCU125,DS_AS_MCU158,
                    DS_AS_MCU052, DS_AS_MCU005, DS_AS_MCU133]                 **
**                                                                            **
** Syntax : Mcu_ResetType Mcu_GetResetReason( void )                          **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID:    5                                                           **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Reentrant                                                   **
**                                                                            **
** Parameters (in):    None                                                   **
**                                                                            **
** Parameters (out):   None                                                   **
**                                                                            **
** Return value:  Mcu_ResetType                                               **
**                Returns the reset reason                                    **
**                                                                            **
** Description : The function reads the reset type from the hardware, if      **
**                 supported. If the hardware doesn't support the hardware    **
**                 detection of the reset reason, the return value for those  **
**                 resets is always MCU_POWER_ON_RESET.                       **
**               MCU005, MCU052, MCU012  : Function to read the reset type    **
**                from the hardware                                           **
**                                                                            **
*******************************************************************************/
Mcu_ResetType Mcu_GetResetReason (void )
{
  /* Placeholder for Raw reset value */
  Mcu_RawResetType ResetReasonRaw;
  /* Placeholder for mapped reset value */
  Mcu_ResetType ResetValueToUser;

  /*MCU101 : Parameter check for the API if DET is STD_ON*/
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  uint32 ErrorFlag;
  ErrorFlag = Mcu_lInitCallVerify(MCU_SID_GETRESETREASON);
  /* MCU012, MCU016, MCU013, MCU015  : DET Parameter checking*/
  /* MCU125 :Check whether Mcu_init is  called before this API.*/
  if ( MCU_ERR_FOUND == ErrorFlag)
  {
    /*Return Undefined in case of Error */
    ResetValueToUser = MCU_RESET_UNDEFINED;
  }
  else
  #endif /* End of MCU_DEV_ERROR_DETECT*/
  {
    /* Extract raw reset reason from the status register */
    ResetReasonRaw = ((Mcu_RawResetType)(Mcu_ResetStatusVal &
                      MCU_RESET_REASON_MASK));

    ResetValueToUser = Mcu_lGetPlatformRstReason(ResetReasonRaw);

  }/* Return the computed value which is user friendly */
  return(ResetValueToUser);
} /*End of Mcu_GetResetReason*/

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_MCU101, DS_AS_MCU125,DS_AS_MCU006,
                DS_AS_MCU_PR464,DS_AS_MCU135, DS_AS_MCU159, DS_MCAL_MCU_0407] **
** Syntax : Mcu_ResetType Mcu_GetResetRawValue( void )                        **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID:    6                                                           **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Reentrant                                                   **
**                                                                            **
** Parameters (in):    None                                                   **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value:      Mcu_RawResetType                                        **
**                    Returns the reset reason                                **
**                                                                            **
** Description : The function reads the reset type from the hardware, if      **
**                 supported. If the hardware doesn't have reset status       **
**                 register return value shall be 0x0.                        **
**               MCU006:  Reset reason in a Raw register format               **
**                                                                            **
*******************************************************************************/
Mcu_RawResetType Mcu_GetResetRawValue (void )
{
  Mcu_RawResetType RetValue ;
  /* Det specific local variables go here */
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  uint32 ErrorFlag;

  /* End of Det specific local variables */

  /* Other function specific local variables go here */
  /* End of Other function specific local variables */

  /*MCU101 : Parameter check for the API if DET is STD_ON*/
  /* MCU012, MCU016, MCU013, MCU015  : DET Parameter checking*/
  /* MCU125 :Check whether Mcu_init is  called before this API.*/
  ErrorFlag  = Mcu_lInitCallVerify(MCU_SID_GETRESETRAWVALUE);
  if(MCU_ERR_FOUND == ErrorFlag)
  {
    /*Return Undefined in case of Error */
    RetValue = MCU_RAW_RESET_UNDEFINED;
  }
  else
  #endif
  {
     RetValue =(Mcu_RawResetType)Mcu_ResetStatusVal;
  }
  return (RetValue);

}/*End of Mcu_GetResetRawValue*/

/* MCU007  : This function is available if the runtime parameter
   MCU_PERFORM_RESET_API is set to TRUE. */
#if (MCU_PERFORM_RESET_API == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_AS_MCU101, DS_AS_MCU125,DS_AS_MCU146,
                  SAS_MCAL_MCU_0413,DS_AS_MCU125, DS_AS_MCU055, DS_AS_MCU143,
                  DS_AS_MCU144,DS_AS_MCU160,SAS_MCAL_MCU_0432,DS_MCAL_MCU_0409,
                  SAS_MCAL_MCU_0411,DS_MCAL_MCU_0408,  DS_MCAL_MCU_0410]      **
**                                                                            **
** Syntax :void Mcu_PerformReset( void )                                      **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID:    7                                                           **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non reentrant                                               **
**                                                                            **
** Parameters (in):    None                                                   **
**                                                                            **
** Parameters (out):   None                                                   **
**                                                                            **
** Return value:       None                                                   **
**                                                                            **
** Description : The function performs a microcontroller reset. This is done  **
**                 by using the hardware feature of the microcontroller.      **
**                 The MCU specific reset type to be performed by this        **
**                 service shall be configured in the configuration set.      **
**              MCU007 , MCU055: The function performs a microcontroller      **
**             reset                                                          **
**                                                                            **
*******************************************************************************/
void Mcu_PerformReset( void )
{
  /* Local variables used in this API */
  uint32 LoopCount;

  /*MCU101 : Parameter check for the API if DET is STD_ON*/
  #if ( MCU_DEV_ERROR_DETECT == STD_ON )
  uint32 ErrorFlag;
  ErrorFlag = Mcu_lInitCallVerify(MCU_SID_PERFORMRESET);

  /* MCU012, MCU016, MCU013, MCU015  : DET Parameter checking*/
  /* MCU125 :Check whether Mcu_init is  called before this API.*/
  if ( MCU_ERR_FOUND != ErrorFlag)
  #endif
  {
    /* End of MCU_DEV_ERROR_DETECT*/
    /* Set SWRSTREQ bit of SCU_SWRSTCON register */
    /* software Reset can be performed by writing to Reset Request register
    SWRSTCON */
    #if (MCU_SAFETY_ENABLE == STD_ON)
     MCU_SAFETY_RESETSAFETYENDINIT_TIMED(MCU_SID_PERFORMRESET,\
                                           MCU_SAFETY_ENDINT_TIMEOUT);
    #else
     MCU_SFR_RUNTIME_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
    #endif
    /*Reserve bit access is ensured for SMU_SWRSTCON register*/
    MCU_SFR_RUNTIME_MODIFY32(SCU_SWRSTCON.U,MCU_SWRSTCON_CLEARMASK,\
                                                           MCU_SWRSTCON_SETMASK)
    
    /* Add some delay for HW to reset */
    for(LoopCount = 0U;LoopCount<(uint32)MCU_PERFORM_RESET_DELAY;LoopCount++)
    {
      NOP();
    }
  }

  /* Mcal_SetENDINIT() is not required, as the MCU would RESET  */

}/* End of Mcu_PerformReset()*/
#endif
/* End of MCU_PERFORM_RESET_API*/

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_MCU125,DS_NAS_MCU_PR2866_PR2867,
                   SAS_MCAL_MCU_0418,DS_AS_MCU020, DS_AS_MCU147, DS_AS_MCU164,
                   DS_AS_MCU161,DS_AS40X_MCU_PR8348,DS_MCAL_MCU_0411,
                   DS_MCAL_MCU_0412, DS_MCAL_MCU_0413]                        **
**                                                                            **
** Syntax : void Mcu_SetMode                                                  **
**          (                                                                 **
**             Mcu_ModeType   McuMode                                         **
**          )                                                                 **
** [/cover]                                                                   **
**                                                                            **
** Service ID:    8                                                           **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non reentrant                                               **
**                                                                            **
** Parameters (in):   McuMode : Set different MCU power modes configured in   **
**                    the configuration set                                   **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value:      None                                                    **
**                                                                            **
** Description : This function activates the MCU power modes. In case the     **
**                CPU is switched off, the function is returned after a       **
**                wake-up was performed                                       **
**              MCU001: The MCU service to activate MCU reduced power modes   **
**                                                                            **
*******************************************************************************/
void Mcu_SetMode(Mcu_ModeType   McuMode)
{
  uint8 CoreId;

  #if ( MCU_DEV_ERROR_DETECT == STD_ON ) || ( MCU_SAFETY_ENABLE == STD_ON )
  uint32 ErrorFlag ;
  #endif

  #if ( MCU_DEV_ERROR_DETECT == STD_OFF ) && ( MCU_SAFETY_ENABLE == STD_ON )
  ErrorFlag = MCU_ERR_NOT_FOUND;
  #endif

  /* To remove the MISRA error this is used*/
  #if ( MCU_DEV_ERROR_DETECT == STD_ON )
  /*MCU101 : Parameter check for the API if DET is STD_ON*/
  /* MCU012, MCU016, MCU013, MCU015  : DET Parameter checking*/
  /* MCU125 :Check whether Mcu_init is  called before this API.*/
  ErrorFlag = Mcu_lInitCallVerify(MCU_SID_SETMODE);

  if (MCU_ERR_FOUND != ErrorFlag)
  #endif
  #if ( MCU_DEV_ERROR_DETECT == STD_ON ) || ( MCU_SAFETY_ENABLE == STD_ON )
  {
    /* MCU020: Check if invalid ModeSetting Id is passed */
    if((McuMode >= MCU_MAX_NO_MODES) ||
      ((((uint32)1U << McuMode) & (Mcu_kConfigPtr->MaxMode)) == 0x00U) )
    {
      #if ( MCU_DEV_ERROR_DETECT == STD_ON )
      Det_ReportError((uint16)MCU_MODULE_ID,MCU_MODULE_INSTANCE,
                       MCU_SID_SETMODE,MCU_E_PARAM_MODE);
      #endif
      #if ( MCU_SAFETY_ENABLE == STD_ON )
      /* report an error */
      SafeMcal_ReportError((uint16)MCU_MODULE_ID,MCU_MODULE_INSTANCE,
                       MCU_SID_SETMODE,MCU_E_PARAM_MODE);
      #endif
      ErrorFlag = MCU_ERR_FOUND ;
    } /* end of  if (McuMode >= MCU_NUMBER_OF_MODES) */
  } /* end of if(MCU_ERR_FOUND != ErrorFlag) */
  /* If DET is present return here */
  if (MCU_ERR_FOUND != ErrorFlag)
  #endif /* (MCU_DEV_ERROR_DETECT == STD_ON) || (MCU_SAFETY_ENABLE == STD_ON)*/
  {

    CoreId = Mcal_GetCoreId();

    if (MCU_IDLE == McuMode)
    {
      Mcu_lSetIdleMode(CoreId);
    }
    else if (MCU_SLEEP == McuMode)
    {
      Mcu_lSetSleepMode(CoreId);
    }
    else
    {
      Mcu_lSetStandbyMode(CoreId);
    }
  }
return;
}/*End of Mcu_SetMode()*/

#if (MCU_E_CLOCK_FAILURE_DEM_REPORT == MCU_ENABLE_DEM_REPORT)
/******************************************************************************
** Traceability : [cover parentID=DS_AS_MCU049_MCU051, DS_AS_MCU166,
                  DS_AS_MCU226]                                              **
**                                                                           **
** Syntax :           void Mcu_ClockFailureNotification(void)                **
** [/cover]                                                                  **
** Service ID:        none                                                   **
**                                                                           **
** Sync/Async:        Synchronous                                            **
**                                                                           **
** Reentrancy:        reentrant                                              **
**                                                                           **
** Parameters (in):   None                                                   **
**                                                                           **
** Parameters (out):  None                                                   **
**                                                                           **
** Return value:      void                                                   **
**                                                                           **
** Description :      Function reports clock fail error to DEM               **
**                                                                           **
*****************************************************************************/
void Mcu_ClockFailureNotification(void)
{
  /* Report the error to DEM only if
  McuClockSrcFailureNotification is enabled and DEM is configured */
  Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE, DEM_EVENT_STATUS_FAILED);
}
#endif

#if (MCU_RAMP_TO_BACKUP_FREQ_API == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_MCU_PR2873, DS_NAS_HE2_MCU_PR2985_2,
                                                     DS_NAS_EP_MCU_PR2985_2]  **
**                                                                            **
** Syntax : Std_ReturnType Mcu_RampToBackUpClockFreq( void )                  **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID:    NA                                                          **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non Reentrant                                               **
**                                                                            **
** Parameters (in):   None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value:      E_OK: command has been accepted                         **
**                  E_NOT_OK: command has not been accepted                   **
**                                                                            **
** Description : This function ramps up/down from the current PLL frequency   **
**               close to the back-up clock frequency. This function can be   **
**               called only after Mcu_InitClock and Mcu_DistributePllClock.  **
**                                                                            **
*******************************************************************************/
Std_ReturnType Mcu_RampToBackUpClockFreq ( void )
{
  Std_ReturnType RetVal;
  uint32 lValue;

  RetVal = E_NOT_OK;

  #if (MCU_ENABLE_CLOCK_MONITORING == STD_ON)
  /* Disable the clock monitoring unit */
  MCU_SFR_RUNTIME_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);

  /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
  if((Mcu_lRuntimeCcuconLckBitCheck((volatile uint32 *)(void *)&SCU_CCUCON3.U))\
                                            != (uint32)MCU_BITVAL_0)
  {
    MCU_SFR_RUNTIME_WRITE32(SCU_CCUCON3.U,0U);
  }
  /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
  if((Mcu_lRuntimeCcuconLckBitCheck((volatile uint32 *)(void *)&SCU_CCUCON4.U))\
                                            != (uint32)MCU_BITVAL_0)
  {  
    MCU_SFR_RUNTIME_WRITE32(SCU_CCUCON4.U,0U);
  } 
  /* Single Update for all CCUCON3 & 4 registers via CCUCON3.UP*/
  /* setting up bit in CCUCON3 register*/
  /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
  if((Mcu_lRuntimeCcuconLckBitCheck((volatile uint32 *)(void *)&SCU_CCUCON3.U))\
                                            != (uint32)MCU_BITVAL_0)
  {
    MCU_SFR_RUNTIME_MODIFY32(SCU_CCUCON3.U,MCU_CCUCON3_CLEARMASK,\
                                                            MCU_CCUCON3_SETMASK)
  }  
  
  MCU_SFR_RUNTIME_SETSAFETYENDINIT_TIMED();

  #endif

  /* Check if Normal mode, VCO is not bypassed */
  /* Check the value of VCOBYP(bit 0)*/
  if((MCU_SFR_RUNTIME_USER_MODE_READ32(SCU_PLLCON0.U) &1U) == 0U)
  {
    uint32 K2RampDownDelay;
    uint32 K2Divsteps;
    uint8 K2StepsCounter;

    /* Get number of K2Div steps configured from configuration*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
     PBConfigStructure and is within allowed range*/
    K2Divsteps = Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].\
                                                    Mcu_ClockDivValues.K2steps;

    /*
     * Run a loop for desired number of K2 intermediate step values till it
     * reaches close to the back up frequency
     */
    for(K2StepsCounter = 0U; K2StepsCounter <= K2Divsteps ; \
                                                               K2StepsCounter++)
    {
      /* Clear the ENDINIT bit in the WDT_CON0 register in order
      to disable the write-protection for registers protected
      via the EndInit feature */


      /*Configure the next K2 step value*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
       PBConfigStructure and is within allowed range*/
      lValue=(uint32)Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting]\
                                     .K2div[(K2Divsteps - K2StepsCounter)];

      MCU_SFR_RUNTIME_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);

      MCU_SFR_RUNTIME_MODIFY32(SCU_PLLCON1.U,(uint32)(~(~(lValue) & \
               IFX_SCU_PLLCON1_K2DIV_MSK)),(lValue & IFX_SCU_PLLCON1_K2DIV_MSK))
      MCU_SFR_RUNTIME_SETSAFETYENDINIT_TIMED();

      /* Set the SafetyENDINIT bit in the WDT_CON0 register again
      to enable the write-protection and to prevent a time-out */

        /* Wait for the configured delay before ramping down K2
                                             divider further */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
       PBConfigStructure and is within allowed range*/
      K2RampDownDelay = Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].\
                        K2RampToBackUpDelayTicks[(K2Divsteps - K2StepsCounter)];
      for(; K2RampDownDelay > 0U; K2RampDownDelay--)
      {
         NOP();
      }
    }
     /*Clear PLLCON0.OSCDISCDIS*/

    /* Disable disconnecting the oscillator in case of PLL loss of lock */

    MCU_SFR_RUNTIME_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
    MCU_SFR_RUNTIME_MODIFY32(SCU_PLLCON0.U,MCU_PLLCON0_CLEARMASK2,0U)
    MCU_SFR_RUNTIME_SETSAFETYENDINIT_TIMED();

    /* Set the SafetyENDINIT bit in the WDT_CON0 register again
    to enable the write-protection and to prevent a time-out */

    RetVal = E_OK;
  }/* end of if (normal mode) */

  return RetVal;
}/* End of Mcu_RampToBackUpClockFreq() */
#endif /* End of MCU_RAMP_TO_BACKUP_FREQ_API */

#if (MCU_SAFETY_ENABLE == STD_ON)

#if (MCU_INITCHECK_API == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_MCAL_MCU_0414, DS_MCAL_MCU_0415,
            SAS_MCAL_MCU_0407,SAS_MCAL_MCU_0406,DS_MCAL_MCU_0416,
            DS_MCAL_MCU_0417,DS_MCAL_MCU_0418]                                **
**                                                                            **
** Syntax          : Std_ReturnType Mcu_InitCheck                             **
**                   (                                                        **
**                      const Mcu_ConfigType* ConfigPtr                       **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :    None                                                  **
**                                                                            **
** Sync/Async      :    Synchronous                                           **
**                                                                            **
** Reentrancy      :    Non Reentrant                                         **
**                                                                            **
** Parameters (in) :    ConfigPtr - Pointer to MCU Driver configuration set   **
**                                                                            **
** Parameters (out):    None                                                  **
**                                                                            **
** Return value    :    E_OK - if initialization comparison is success        **
**                      E_NOT_OK - if initialization comparison fails         **
**                                                                            **
** Description     : This routine verifies the initialization the MCU driver. **
**                   Note: The sequence should be                             **
**                    1)Call Mcu_InitClock                                    **
**                    2)Call Mcu_GetPllStatus                                 **
**                    3)Call Mcu_DistributePllClock                           **
**                    4)Call Mcu_InitCheck                                    **
**                                                                            **
*******************************************************************************/
Std_ReturnType Mcu_InitCheck (const Mcu_ConfigType* ConfigPtr)
{
  Std_ReturnType ErrorFlag;
  Std_ReturnType TempErrFlag;
  uint32         TempFlag;

  ErrorFlag = E_NOT_OK;

  if (Mcu_kConfigPtr == ConfigPtr)
  {
    volatile uint32 CompareFlag = 0xFFFFFFFFU;
    uint32 TempFlag1;

    /* To avoid multiple if conditions, storing in CompareFlag */
    /* Comparison to be done for initialization done by Mcu_Init() */
    TempFlag = (uint32)MCU_SFR_INIT_USER_MODE_READ32(SCU_PMSWCR1.U) & \
                                                               MCU_PMSWCR1_MASK;
    /* CPUSEL bit */
    TempFlag1 = ((uint32)MCU_SYSTEM_MODE_CORE << 24U);
    /* CPUIDLSEL bit */
    TempFlag1 |= ((uint32)MCU_IDLE_MODE_CORE << 8U);
    #if (MCU_DISABLE_IRADIS == STD_ON)
    /* IRADIS bit */
    TempFlag1 |= (uint32)1U << 12;
    #endif
    CompareFlag &= (TempFlag ^ ~TempFlag1);

    TempFlag = ~(uint32)MCU_SFR_INIT_USER_MODE_READ32(SCU_RSTCON.U);
    TempFlag1 = (Mcu_kConfigPtr->ResetCfg) & 0x0000FFFFU;
    CompareFlag &= (TempFlag1 ^ TempFlag);

    TempFlag = ~(uint32)MCU_SFR_INIT_USER_MODE_READ32(SCU_ARSTDIS.U);
    TempFlag1 = Mcu_kConfigPtr->ResetCfg >> 16U;
    CompareFlag &= (TempFlag1 ^ TempFlag);

    /* Comparison to be done for initialization done by Mcu_InitClock() */
    TempFlag = (((uint32)MCU_OSCVAL_REG_VALUE << 16)) |
               MCU_PLLLV_PLLHV_STATUS_CHECK;
    TempFlag1 = (uint32)MCU_SFR_INIT_USER_MODE_READ32(SCU_OSCCON.U) & \
                                                                MCU_OSCCON_MASK;
    CompareFlag &= (TempFlag1 ^ ~TempFlag);

    /* Verify Prescaler Mode*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
     PBConfigStructure and is within allowed range*/
    if (Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].\
        Mcu_ClockDivValues.PllMode  == 0U)
    {
      TempFlag = MCU_PLLCON0_REGVAL_CHECK;
      TempFlag1 = MCU_SFR_INIT_USER_MODE_READ32(SCU_PLLCON0.U) & \
                                                     MCU_PLLCON0_PRESCALAR_MASK;
      CompareFlag &= (TempFlag1 ^ ~TempFlag);

      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
       PBConfigStructure and is within allowed range*/
      TempFlag = ((uint32)Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].\
                         Mcu_ClockDivValues.K1div) << 16U;
      TempFlag1 = MCU_SFR_INIT_USER_MODE_READ32(SCU_PLLCON1.U) & \
                                                     MCU_PLLCON1_PRESCALAR_MASK;
      CompareFlag &= (TempFlag1 ^ ~TempFlag);
    }
    else /* Verify Normal Mode*/
    {
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
       PBConfigStructure and is within allowed range*/
      uint32 K2Divsteps =
       ((uint32)(Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].\
                                   Mcu_ClockDivValues.K2steps) + 1U);
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
       PBConfigStructure and is within allowed range*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
       PBConfigStructure and is within allowed range*/
      TempFlag = ((uint32)Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].\
                       Mcu_ClockDivValues.Pdiv << 24U) |\
                 ((uint32)Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].\
                       Mcu_ClockDivValues.Ndiv << 9U) |\
                   MCU_PLLPWD_IS_SET_TO_NORMAL;
      TempFlag1 = MCU_SFR_INIT_USER_MODE_READ32(SCU_PLLCON0.U) & \
                                                        MCU_PLLCON0_NORMAL_MASK;
      #if (MCU_FMPLL_ENABLE == STD_ON)
      TempFlag |= ((uint32)1U << IFX_SCU_PLLCON0_MODEN_OFF);
      #endif
      CompareFlag &= (TempFlag1 ^ ~TempFlag);

      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
       PBConfigStructure and is within allowed range*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
       PBConfigStructure and is within allowed range*/
      TempFlag =((uint32)Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].\
                 Mcu_ClockDivValues.K3div << 8U) | Mcu_kConfigPtr->\
                 ClockCfgPtr[Mcu_ClockSetting].K2div[K2Divsteps];
      TempFlag1 = MCU_SFR_INIT_USER_MODE_READ32(SCU_PLLCON1.U);
      CompareFlag &= (TempFlag1 ^ ~TempFlag);

      #if (MCU_FMPLL_ENABLE == STD_ON)
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
       PBConfigStructure and is within allowed range*/
      TempFlag = (uint32)Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Pllcon2;
      TempFlag1 = MCU_SFR_INIT_USER_MODE_READ32(SCU_PLLCON2.U);
      CompareFlag &= (TempFlag1 ^ ~TempFlag);
      #endif
    } /* end of Normal mode */

    TempErrFlag = Mcu_lPlatformInitCheck();

    #if (MCU_GTM_USED == STD_ON)
    TempErrFlag |= Gtm_InitCheck(ConfigPtr->GtmConfigRootPtr);
    #endif

    #if (MCU_CRC_HW_USED == STD_ON)
    TempErrFlag |= Mcu_lCrcPlatformInitCheck();
    #endif

    #if (MCU_DMA_USED == STD_ON)
    TempErrFlag |= Mcu_lDmaInitCheck();
    #endif

    /* Verify GTM initialization */
    if ( (CompareFlag == 0xFFFFFFFFU) && (TempErrFlag == E_OK) )
    {
      ErrorFlag = E_OK;
    }
  } /* end of if ConfigPtr!=NULL_PTR && Marker==MCU_MODULE_ID << 16U */

  return (ErrorFlag);
}/* End of Mcu_InitCheck() */
#endif /* end of MCU_INITCHECK_API == STD_ON */

#if (MCU_GETMODE_API == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=SAS_MCAL_MCU_0420,DS_MCAL_MCU_0419,
                  DS_MCAL_MCU_0420]                                           **
**                                                                            **
** Syntax           : Mcu_ModeStateType  Mcu_GetMode                          **
**                    (                                                       **
**                      uint8 CoreId                                          **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in):   CoreId : The Core for which the mode needs to be        **
**                    dertermined                                             **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Mcu_ModeStateType  - Power mode status                  **
**                                                                            **
** Description      :                                                         **
**   - provides the mode the CPU is currently in                              **
**                                                                            **
*******************************************************************************/
Mcu_ModeStateType Mcu_GetMode(uint8 CoreId)
{
  Mcu_ModeStateType ModeState;

  if (CoreId >= MCAL_NO_OF_CORES)
  {
    /* Report an error */
    ModeState = MCU_UNDEFINED_MODE;
  }
  else
  {
    /* Return PMST(bits 8 to 10)*/
    ModeState = (Mcu_ModeStateType)((MCU_SFR_RUNTIME_USER_MODE_READ32\
   (MODULE_SCU.PMCSR[CoreId].U) & (MCU_PMCSR_PMST_CLEARMASK)) >> \
                                                    MCU_PMCSR_PMST_BITPOS);
  }
  return (ModeState);
} /* End of Mcu_GetMode() */
#endif /* end of MCU_GETMODE_API == STD_ON */

#endif /*End Of MCU_SAFETY_ENABLE*/

#if (MCU_CLR_COLD_RESET_STAT_API == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_EP_MCU_PR2982,DS_NAS_HE2_MCU_PR2982] **
** Syntax :  void   Mcu_ClearColdResetStatus(void)                            **
** [/cover]                                                                   **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Service ID       : 80                                                      **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:    none                                                      **
**                                                                            **
** Description : clear the SCU_RSTSTAT register value                         **
**                                                                            **
*******************************************************************************/
void Mcu_ClearColdResetStatus(void)
{

  #if ( MCU_DEV_ERROR_DETECT == STD_ON )
  uint32 ErrorFlag;

  /* Parameter check for the API if DET is STD_ON*/
  ErrorFlag = Mcu_lInitCallVerify(MCU_SID_CLRCOLDRESETSTAT);
  /*If no Error is present*/
  if (MCU_ERR_FOUND != ErrorFlag)
  #endif
  {
    /*Clear cold reset status by setting RSTCON2.CLRC*/
    MCU_SFR_RUNTIME_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
    MCU_SFR_RUNTIME_MODIFY32(SCU_RSTCON2.U,MCU_RSTCON2_CLEARMASK,\
                                                       (1U<<MCU_RSTCON2_BITPOS))
    MCU_SFR_RUNTIME_SETSAFETYENDINIT_TIMED();
  }
}
#endif /* (MCU_CLR_COLD_RESET_STAT_API == STD_ON) */

/*******************************************************************************
** Syntax : void Mcu_lSwitchToBackupClock(void)                               **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to switch close to backup frequency in          **
**                   Mcu_InitClock                                            **
*******************************************************************************/
IFX_LOCAL_INLINE void Mcu_lSwitchToBackupClock(void)
{
  uint32 NDiv;
  uint32 PDiv;
  uint32 K2Div;
  uint32 CurrentPllFreq;
  uint32 CurrentCpuFreq;
  uint32 SriDiv;
  uint32 CpuDiv;
  uint8 ClockSel;
  uint8 VcoByPassStatus;
  uint32 K2RampUpDelayCount;
  uint32 K2RampUpDelay;
  /* Check if currently normal mode is configured and Fback is not used
     as clock source*/
  /* Read CLKSEL(Bits 28 and 29)*/
  ClockSel = (uint8)((((uint32)MCU_SFR_INIT_USER_MODE_READ32\
          (SCU_CCUCON0.U)) & ((uint32)MCU_CCUCON0_CLKSEL_CLEARMASK3)) \
                                                >> MCU_CCUCON0_CLKSEL_BITPOS);
  /* Read VCOBYST(Bit 0)*/
  VcoByPassStatus = (uint8)((((uint32)MCU_SFR_INIT_USER_MODE_READ32\
                             (SCU_PLLSTAT.U)) & MCU_PLLSTAT_VCOBYST_CLEARMASK));
  /* Normal Mode and PLL is slock source*/
  if((ClockSel == 1U) && (VcoByPassStatus == MCU_PLLSTAT_NORMAL_MODE))
  {
    /* Read NDIV(Bits 9 to 15)*/
    NDiv = (uint32)((MCU_SFR_INIT_USER_MODE_READ32\
                      (SCU_PLLCON0.U) & MCU_PLLCON0_NDIV_CLEARMASK1) >> \
                                                 MCU_PLLCON0_NDIV_BITPOS) + 1U;
    /* Read PDIV(Bits 24 to 27)*/
    PDiv = (uint32)((MCU_SFR_INIT_USER_MODE_READ32\
                     (SCU_PLLCON0.U) & MCU_PLLCON0_PDIV_CLEARMASK1) >> \
                                                 MCU_PLLCON0_PDIV_BITPOS) + 1U;
    /* Read K2DIV(Bits 0 to 6)*/
    K2Div = (uint32)(MCU_SFR_INIT_USER_MODE_READ32\
                            (SCU_PLLCON1.U) & MCU_PLLCON0_K2DIV_CLEARMASK) + 1U;
    /* Read SRIDIV(Bits 8 to 11)*/
    SriDiv = (uint32)((MCU_SFR_INIT_USER_MODE_READ32\
                          (SCU_CCUCON0.U) & MCU_PLLCON0_SRIDIV_CLEARMASK) >> \
                                                    MCU_PLLCON0_SRIDIV_BITPOS);
    CpuDiv = (uint32)MCU_SFR_INIT_USER_MODE_READ32(SCU_CCUCON6.U);
    /* Calculate current frequency */
    CurrentPllFreq = (MCU_MAIN_OSC_FREQ * NDiv) / (PDiv * K2Div);
     /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range*/
    K2RampUpDelay = Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].\
                        K2RampToPllDelayConf;

    /* Compare current frequency with Fback*/

    if( CurrentPllFreq > (MCU_BACKUP_FREQ + MCU_BACKUP_FREQ_TOLERANCE))
    {
      /* Loop until current frequency does not reach close to Fback */
      do
      {
        K2Div++;

        MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);

        /* Set K2DIV(Bits 0 to 6) */
        MCU_SFR_INIT_MODIFY32(SCU_PLLCON1.U,MCU_PLLCON1_K2DIV_CLEARMASK,\
                                                         (uint32)(K2Div - 1U))

        MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();

        /* Calculate the current CPU frequency */
        CurrentPllFreq = (MCU_MAIN_OSC_FREQ * NDiv) / (PDiv * K2Div);
        CurrentCpuFreq = CurrentPllFreq / SriDiv;
        CurrentCpuFreq = (CurrentCpuFreq * (64U-CpuDiv))/64U;
        /* Count the required delay ticks*/
        K2RampUpDelayCount = CurrentCpuFreq * K2RampUpDelay;

        /* Divide the count by 2 or 1*/
        K2RampUpDelayCount = K2RampUpDelayCount / MCU_DELAY_COUNT_DIVIDER;
        /* wait for the calculated time */
        for(; K2RampUpDelayCount > 0U; K2RampUpDelayCount--)
        {
          NOP();
        }
      }while( CurrentPllFreq > MCU_BACKUP_FREQ );
    }
    else if ( CurrentPllFreq < (MCU_BACKUP_FREQ - MCU_BACKUP_FREQ_TOLERANCE))
    {
      /* Loop until current frequency does not reach close to Fback*/
      do
      {
        K2Div--;

        MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);

        /* Set K2DIV(Bits 0 to 6) */
        MCU_SFR_INIT_MODIFY32(SCU_PLLCON1.U,MCU_PLLCON1_K2DIV_CLEARMASK,\
                                                            (uint32)(K2Div-1U))

        MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();

        /* Calculate the current CPU frequency */
        CurrentPllFreq = (MCU_MAIN_OSC_FREQ * NDiv) / (PDiv * K2Div);
        CurrentCpuFreq = CurrentPllFreq / SriDiv;
        CurrentCpuFreq = (CurrentCpuFreq * (64U-CpuDiv))/64U;
        /* Count the required delay ticks*/
        K2RampUpDelayCount = CurrentCpuFreq * K2RampUpDelay;

        /* Divide the count by 2  or 1*/
        K2RampUpDelayCount = K2RampUpDelayCount / MCU_DELAY_COUNT_DIVIDER;
        /* wait for the calculated time */
        for(; K2RampUpDelayCount > 0U; K2RampUpDelayCount--)
        {
          NOP();
        }
      }while( CurrentPllFreq < MCU_BACKUP_FREQ );
    }
    else
    {
         /* Do Nothing */
    }

  }
    MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
 /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/   
 if((Mcu_lInitCcuconLckBitCheck((volatile uint32 *)(void *)&SCU_CCUCON0.U))\
                                            != (uint32)MCU_BITVAL_0)
  {
    /*Select Fback as the source for all clocks during PLL initialization*/
   /* Set CLKSEL(Bits 28 and 29) to 0*/
   /*Reserve bit access is ensured for CCUCON0 register*/
   MCU_SFR_INIT_MODIFY32(SCU_CCUCON0.U,MCU_CCUCON0_CLKSEL_CLEARMASK2,\
                                              MCU_CCUCON0_CLKSEL_SETMASK2)

   }/* Fosc0(Ext Osc) is used as clock source and a new complete parameter
   set is transferred to the CCU.*/
   /* Set INSEL(bits 28, 29) to 1U*/
  /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
  if((Mcu_lInitCcuconLckBitCheck((volatile uint32 *)(void *)&SCU_CCUCON1.U))\
                                            != (uint32)MCU_BITVAL_0)
  {
    MCU_SFR_INIT_MODIFY32(SCU_CCUCON1.U,MCU_CCUCON1_INSEL_CLEARMASK,\
                                                  MCU_CCUCON1_INSEL_SETMASK)
  }

   /* Update for CCUCON0 and CCUCON1*/
   /* Set UP(bit 30) to 1*/
  /*IFX_MISRA_RULE_11_05_STATUS=volatile typecasting is removed, since it
    gives compile time warning in windriver compiler*/
  if((Mcu_lInitCcuconLckBitCheck((volatile uint32 *)(void *)&SCU_CCUCON1.U))\
                                            != (uint32)MCU_BITVAL_0)
  {
    MCU_SFR_INIT_MODIFY32(SCU_CCUCON1.U,MCU_CCUCON1_UP_CLEARMASK,\
                                                      MCU_CCUCON1_UP_SETMASK)
  }
  MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();
 
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_MCU_PR3155,DS_MCAL_MCU_0555]         **
**                                                                            **
** Syntax : void Mcu_17_CcuconRegUpdate(uint8 *RegIndex, uint8 Value,         **
**                                      uint32 DelayCtr)                      **
** [/cover]                                                                   **
**                                                                            **
** Service ID:    82                                                          **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non Reentrant                                               **
**                                                                            **
** Parameters (in):   RegIndex : CCUCONx (x = 6 to 8) Register Index          **
**                    Value   : CPUx(x = 0 to 2) DIVIDER Value                **
**                    DelayCtr: Delay Counter(CPU Ticks) Value                **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value:      None                                                    **
**                                                                            **
** Description : TThis service sets the CPUx (x = 0 to 2) Divider value to    **
**               corresponding CCUCONx (x = 6 to 8) register address which is **
**               passed as an argument. Configured delay(CPU Ticks) is        **
**               introduced followed by Register Write operation to reach     **
**               CPUx (x = 0 to 2) desired frequency. Readback mechanism      **
**               ensure that Value which is written into CCUCONx(x=6 to 8) is **
**               upated correctly.                                            **
**               DET MCU_E_UNINIT: If Mcu_Init is not initialised             **
**               DET MCU_E_PARAM_CONFIG: If Value is greater then 63U         **
**               Safety Error MCU_E_PARAM_CONFIG: If RegIndex is not within   **
**               range (6 to 8).                                              **
**               Safety Error MCU_E_PARAM_CONFIG: If CPU divider value which  **
**               is written and readback is not same                          **
**                                                                            **
*******************************************************************************/
void Mcu_17_CcuconRegUpdate(uint8 RegIndex, uint8 Value, uint32 DelayCtr)
{

#if (MCU_SAFETY_ENABLE == STD_ON)
 uint8 RegValue;
#endif

#if ( ( MCU_DEV_ERROR_DETECT == STD_ON ) || ( MCU_SAFETY_ENABLE == STD_ON ) )

  Std_ReturnType ErrorFlag;
  
  /*Initialize Error Flag with No Error*/
  ErrorFlag = E_OK;

#if ( MCU_DEV_ERROR_DETECT == STD_ON )

  if( MCU_DRIVER_UNINITIALIZED == Mcu_DriverState )
  {
    Det_ReportError((uint16)MCU_MODULE_ID,MCU_MODULE_INSTANCE,
                     MCU_SID_CCUCONREGUPDATE,MCU_E_UNINIT);
    ErrorFlag = E_NOT_OK;
  }
  
  if( Value > MCU_CCUCON_CPUDIV_MAX )
  {
     Det_ReportError((uint16)MCU_MODULE_ID,MCU_MODULE_INSTANCE,
                     MCU_SID_CCUCONREGUPDATE,MCU_E_PARAM_CONFIG);
    ErrorFlag = E_NOT_OK;
  }
#endif  

#if (MCU_SAFETY_ENABLE == STD_ON)
if((RegIndex < MCU_CCUCONREG_ID)||(RegIndex > MCU_CCUCONREG_AVAILABILITY_RANGE))
{
/* Report an safety error when RegIndex is out of range */
    SafeMcal_ReportError ((uint16)MCU_MODULE_ID,MCU_MODULE_INSTANCE,
                     MCU_SID_CCUCONREGUPDATE,MCU_E_PARAM_CONFIG);
    ErrorFlag = E_NOT_OK;
}
#endif
 
   if( E_NOT_OK != ErrorFlag )
#endif
   { 
   
    /*Clear the SafetyENDINIT bit in the WDT_CON0 register in order
     to disable the write-protection for registers protected
     via the EndInit feature */
     MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
    
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
    access into CCUCON SFR register */   
    MCU_SFR_INIT_WRITE32(MCU_REGMAP[RegIndex-MCU_CCUCONREG_ID].U,(uint32)Value);

    /* Set the SafetyENDINIT bit in the WDT_CON0 register again
     to enable the write-protection and to prevent a time-out */
     MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();
      
   /* delay is provided to reach fCPUx(x=0 to 2) to desired value */
   
   do
   {
     NOP();
     DelayCtr--;
   }while(DelayCtr > 0U);
   
  /* when IFX_MCU_CCUCONREG_DEBUG MACRO is defined, use can simulate
     failure case of value which is read from CCUCON Register */
#if (MCU_SAFETY_ENABLE == STD_ON)
  
#ifdef IFX_MCU_CCUCONREG_DEBUG
    RegValue = (uint8)TestMcu_CcuconRegReadValue;
#else
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to efficiently
    access into CCUCON SFR register */  
   RegValue=(uint8)((uint32)MCU_SFR_INIT_USER_MODE_READ32(        \
   MCU_REGMAP[RegIndex-MCU_CCUCONREG_ID].U)&                       \
   (uint32)(MCU_CCUCON_CPUDIV_MAX));
#endif   

   if( RegValue != Value)
   {
    /* Report an safety error when Value which is written is not
       equall to read value */
    SafeMcal_ReportError ((uint16)MCU_MODULE_ID,MCU_MODULE_INSTANCE,
                     MCU_SID_CCUCONREGUPDATE,MCU_E_PARAM_CONFIG);
   }
#endif
      
   }
  
 return;   
} /* End of Mcu_17_CcuconRegUpdate */

#define MCU_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives
 is allowed only for MemMap.h*/
#include "MemMap.h"

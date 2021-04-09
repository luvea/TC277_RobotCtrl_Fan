/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2015)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Uart.c $                                                   **
**                                                                           **
**  $CC VERSION : \main\74 $                                                 **
**                                                                           **
**  $DATE       : 2016-08-01 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                functionality of UART driver                               **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
   Traceability   : [cover parentID=
   SAS_NAS_ALL_PR748,SAS_NAS_ALL_PR749,
   SAS_NAS_ALL_PR102,SAS_NAS_ALL_PR470,SAS_NAS_ALL_PR471,
   SAS_NAS_ALL_PR70,SAS_NAS_ALL_PR1652]
   [/cover]
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of sfr file */
#include "IfxAsclin_reg.h"
#include "IfxSrc_reg.h"

/* Own header file, this includes own configuration file also */
/* Inclusion structure */
#include "Uart.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*************** SW Version Checks ***************/
#ifndef UART_SW_MAJOR_VERSION
  #error "UART_SW_MAJOR_VERSION is not defined."
#endif

#ifndef UART_SW_MINOR_VERSION
  #error "UART_SW_MINOR_VERSION is not defined."
#endif

#ifndef UART_SW_PATCH_VERSION
  #error "UART_SW_PATCH_VERSION is not defined."
#endif

/* Check for Correct inclusion of headers */
#if ( UART_SW_MAJOR_VERSION != 1U )
  #error "UART_SW_MAJOR_VERSION does not match."
#endif
#if ( UART_SW_MINOR_VERSION != 3U )
  #error "UART_SW_MINOR_VERSION does not match."
#endif

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/* ASCLIN Register Start Address Mapping */
#define UART_HW_MODULE                    (&MODULE_ASCLIN0)

#define UART_CSRREG_CLKSEL_NOCLK          (0U)  /* No Clock  */
#define UART_FRAMECONREG_INIT_MODE        (0U)  /* ASCLIN INIT mode */
#define UART_FRAMECONREG_ASC_MODE         (0x00010000U)  /* ASCLIN UART mode */
#define UART_CSRREG_CLKSEL_CLC            (8U)  /* Clk source = fASCLINF */

/* Digital Glitch Filter Disabled */
#define UART_IOCRREG_DEPTH_VAL            (0U)

#define UART_BITCONREG_SM_VAL             (1U)

#define UART_ENABLE_BIT                   (1U)
#define UART_DISABLE_BIT                  (0U)

#define UART_INVALID_CHANNEL              (0xFFU)

/* Configure Inlet width and outlet width for FIFO
depending on the Datalength configured for the Channels */

#if (UART_NINEBITS_USED == STD_ON)
#define UART_TXFIFOCONREG_INW_VAL         (2U)
#define UART_RXFIFOCONREG_OUTW_VAL        (2U)
#define UART_STEPSIZE                     (2U)
#else
#define UART_TXFIFOCONREG_INW_VAL         (1U)
#define UART_RXFIFOCONREG_OUTW_VAL        (1U)
#define UART_STEPSIZE                     (1U)
#endif

#define UART_ZERO_U                       (0U)
#define UART_ONE_U                        (1U)

#define UART_BIT_RESET                    (0U)
#define UART_BIT_SET                      (1U)

#define UART_TX_LOCK_IDX                  (0U)
#define UART_RX_LOCK_IDX                  (1U)

#define UART_NINEBIT_DATLEN               (9U)

/*Rx FIFO Buffer Int level is set to Store 16 bytes*/
#define UART_RX_FIFO_INT_LEVEL_VAL        (15U)

/* SRC register for ASCLIN are offset by a below value  0x0C div 4 */
#define UART_SRC_ADDROFFSET               (0x03U)

/* Disable ASCLIN Module clock */
#define UART_DISABLE_ASCLIN_MODULE        (0x00000001U)

#define UART_TIMEOUT_DURATION             (0xFFU)

#define UART_KRST_TIMEOUT                 (0x100U)

/* Set and Clear Mask to Disable Interrupts */
#define UART_SET_MASK_DISABLE_INTR        (0x02000000U)
#define UART_CLR_MASK_DISABLE_INTR        (0x80000400U)

/* Set and Clear Mask to Clear Interrupts */
#define UART_SET_MASK_CLR_INTR            (0x52000000U)
#define UART_CLR_MASK_CLR_INTR            (0x80000000U)

/* Set and Clear Mask to Enable Interrupts */
#define UART_SET_MASK_ENABLE_INTR         (0x00000400U)
#define UART_CLR_MASK_ENABLE_INTR         (0x80000000U)

/* SRC register addresses */
#define UART_SRC_ASCLIN0TXADDR  ((volatile Ifx_SRC_SRCR_Bits  *) \
(void *)&(SRC_ASCLIN0TX))
#define UART_SRC_ASCLIN0RXADDR  ((volatile Ifx_SRC_SRCR_Bits  *) \
(void *)&(SRC_ASCLIN0RX))
#define UART_SRC_ASCLIN0ERRADDR ((volatile Ifx_SRC_SRCR_Bits  *) \
(void *)&(SRC_ASCLIN0ERR))

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
*                     Private Function Declarations                            *
*******************************************************************************/
/*Memory Map of the UART Code*/
#define UART_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

IFX_LOCAL_INLINE uint8 Uart_lHwInitClcReg(uint8 HwUnit, uint32 Value);

#if ((UART_RESET_SFR_INIT == STD_ON) || (UART_DEINIT_API == STD_ON))
IFX_LOCAL_INLINE void Uart_lHwInitKernelRegInit(uint8 HwUnit);
IFX_LOCAL_INLINE void Uart_lHwInitKernelRegDeInit(uint8 HwUnit);
#endif

static void Uart_lHwInit(uint8 HwUnit,\
                                     const Uart_ChannelType* ChannelConfigPtr);
#if ((UART_ABORT_READ_API == STD_ON) || (UART_ABORT_WRITE_API == STD_ON))
static void Uart_lHwInitRuntime(uint8 HwUnit,\
                                      const Uart_ChannelType* ChannelConfigPtr);
#endif
static void Uart_lRead(Ifx_ASCLIN* HwModulePtr,Uart_ChannelIdType Channel);
static void Uart_lWrite(Ifx_ASCLIN* HwModulePtr,Uart_ChannelIdType Channel);

static void Uart_lEnableReadInterrupts(Ifx_ASCLIN* HwModulePtr);
static void Uart_lEnableWriteInterrupts(Ifx_ASCLIN* HwModulePtr,\
                                                             uint8 ApiAccessId);

/* Functions to clear flags for read and write functions */
static void Uart_lClearWriteInterrupts(Ifx_ASCLIN* HwModulePtr,\
                                                             uint8 ApiAccessId);
static void Uart_lClearReadInterrupts(Ifx_ASCLIN* HwModulePtr,\
                                                             uint8 ApiAccessId);

#if (UART_DEV_ERROR_DETECT == STD_ON)
static Uart_ReturnType Uart_lChannelCheck(\
                             Uart_ChannelIdType Channel,uint8 ApiId);
#endif

/* Functions to enable SRE bit of corresponding hardware*/
static void  Uart_lHwEnableAscLinTxIntr(volatile uint8 HwUnit);
static void  Uart_lHwEnableAscLinRxIntr(volatile uint8 HwUnit);
static void  Uart_lHwEnableAscLinErrIntr(volatile uint8 HwUnit);

/* Functions to disable SRE bit of curresponding hardware*/
static void  Uart_lHwDisableAscLinTxIntr(volatile uint8 HwUnit, \
                                                             uint8 ApiAccessId);
static void  Uart_lHwDisableAscLinRxIntr(volatile uint8 HwUnit, \
                                                             uint8 ApiAccessId);
static void  Uart_lHwDisableAscLinErrIntr(volatile uint8 HwUnit, \
                                                             uint8 ApiAccessId);

#define UART_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#if (UART_PB_FIXEDADDR == STD_ON)

#define UART_START_SEC_CONST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/* UART Config Set Pointer */
static const Uart_ConfigType* const Uart_kConfigPtr = &Uart_ConfigRoot[0];

#define UART_STOP_SEC_CONST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

#endif /*(UART_PB_FIXEDADDR == STD_ON)*/


#if (UART_PB_FIXEDADDR == STD_OFF)

#define UART_START_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

static const Uart_ConfigType* Uart_kConfigPtr;

#define UART_STOP_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

#endif /*(UART_PB_FIXEDADDR == OFF)*/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*[cover parentID=DS_NAS_UART_PR115]Global and Static variable[/cover]*/

#define UART_START_SEC_VAR_INIT_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/* Mapping of ASCLIN HW Units Used to the respective logical UART Channel Ids*/
static Uart_ChannelIdType Uart_BusChannelMap[UART_MAX_HW_UNIT]=\
{UART_INVALID_CHANNEL};

/* Variable used to check Uart Initialization Status */
#if (UART_DEV_ERROR_DETECT == STD_ON)
static Uart_StateType Uart_InitStatus = UART_UNINITIALISED;
#endif

#define UART_STOP_SEC_VAR_INIT_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"


#define UART_START_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

#if (UART_DEBUG_SUPPORT == STD_ON)
/*IFX_MISRA_RULE_08_10_STATUS=Variable Uart_ChannelInfo is declared as
 extern in Uart_Dbg.h, which will be included application for
 debugging*/
Uart_ChannelInfoType  Uart_ChannelInfo[UART_MAXIMUM_CHANNEL];
#else
static Uart_ChannelInfoType Uart_ChannelInfo[UART_MAXIMUM_CHANNEL];
#endif

#define UART_STOP_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

#define UART_START_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/*Resource Protection Flags for UART Channel Resource(using binary semaphore)*/
static uint32 Uart_ChLock[2][UART_MAXIMUM_CHANNEL];

#ifdef IFX_UART_DEBUG
extern volatile uint32 TestUart_DebugMask01;
extern volatile uint32 TestUart_DebugMask02;
#endif

#define UART_STOP_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
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

/*Memory Map of the UART Code*/
#define UART_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_UART_PR1569,DS_NAS_HE2_UART_PR3018,  **
**                DS_NAS_EP_UART_PR3018,DS_NAS_UART_PR63_6][/cover]           **
**                                                                            **
** Syntax : void Uart_Init( const Uart_ConfigType* ConfigPtr )                **
**    [/cover]                                                                **
** Service ID:  0x00                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  ConfigPtr - Pointer to Uart driver configuration set    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Driver Module Initialization function.                       **
** Service for UART initialization. The Initialization function shall         **
** initialize all common relevant registers of UART channels with the values  **
** of the structure referenced by the parameter ConfigPtr.                    **
*******************************************************************************/
void Uart_Init(const Uart_ConfigType* ConfigPtr)
{
  const Uart_ChannelType *ChannelConfigPtr;
  uint8 ModuleNo,Chan;
  uint8 MaxChannel,ClkDisableChk,ClkFailureChk ;

  #if (UART_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType ReturnStatus;
  ReturnStatus = E_OK;
  #endif

  #if (UART_DEV_ERROR_DETECT == STD_ON) /* if DET detection is switched On */
   #if (UART_PB_FIXEDADDR == STD_OFF)
   if (ConfigPtr == NULL_PTR)
   {
     /* If the config pointer is equal to null pointer report to DET */
     Det_ReportError(
                     UART_MODULE_ID,
                     UART_MODULE_INSTANCE,
                     UART_SID_INIT,
                     UART_E_PARAM_POINTER
                    );
     ReturnStatus = E_NOT_OK;
   }
   #else
   if (Uart_kConfigPtr != ConfigPtr)
   {
     /* In case of PB Fixed address if the Uart_kConfigPtr not equal to
     ConfigPtr then report to DET */
     Det_ReportError(
                     UART_MODULE_ID,
                     UART_MODULE_INSTANCE,
                     UART_SID_INIT,
                     UART_E_INVALID_POINTER
                    );
     ReturnStatus = E_NOT_OK;
   }
   #endif/*(UART_PB_FIXEDADDR == STD_ON)*/

   else if (Uart_InitStatus == UART_INITIALISED)
   {
     /* If Uart is already initialsed then report to DET */
     Det_ReportError(
                     UART_MODULE_ID,
                     UART_MODULE_INSTANCE,
                     UART_SID_INIT,
                     UART_E_STATE_TRANSITION
                    );
     ReturnStatus = E_NOT_OK;
   }
   else
   {
     /* Do Nothing */
   }
  #endif  /* (UART_DEV_ERROR_DETECT == STD_ON) */

  #if (UART_DEV_ERROR_DETECT == STD_ON)
  if (ReturnStatus == E_OK)
  #endif
  {
    MaxChannel = ConfigPtr->NoOfChannels;

    ClkFailureChk = UART_ZERO_U;

    /* Enable the ASCLIN hardware unit/s for all configured Channels */
    for (Chan = UART_ZERO_U; Chan < MaxChannel; Chan++)
    {
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
       ChannelConfigPtr to access the Configuration of a particular Channel*/
      ChannelConfigPtr = &(ConfigPtr->ChannelConfigPtr[Chan]);
      /* Extract the HW Module */
      ModuleNo = ChannelConfigPtr->HwModule;

      /* Enable the ASCLIN module and also set the EDIS bit (Sleep setting) */
      ClkDisableChk = Uart_lHwInitClcReg(ModuleNo, UART_ASCLIN_CLC);

      if (UART_ZERO_U == ClkDisableChk)
      {
        #if (UART_RESET_SFR_INIT == STD_ON)
        /* Reset ASCLIN Kernel  */
        Uart_lHwInitKernelRegInit(ModuleNo);
        #endif

        /* Initialise the Uart Hardware. */
        Uart_lHwInit(ModuleNo, ChannelConfigPtr);

      /* Initialize the ChannelInfo containig UART Channel to HW Unit Mapping*/
        Uart_ChannelInfo[Chan].Uart_AssignedHW = ModuleNo;

        /* Init Uart_BusChannelMap Array */
        Uart_BusChannelMap[ModuleNo] = Chan;

        /* Init UART Channel Tx and Rx State variables */
        Uart_ChannelInfo[Chan].Uart_TxState = UART_INITIALISED;
        Uart_ChannelInfo[Chan].Uart_RxState = UART_INITIALISED;

        /* Init Uart Channel Tx/Rx Resource Lock */
        Uart_ChLock[UART_TX_LOCK_IDX][Chan] = UART_ZERO_U;
        Uart_ChLock[UART_RX_LOCK_IDX][Chan] = UART_ZERO_U;
      }
      else
      {
        ClkFailureChk++;

      /* Set Uart_AssignedHW to Invalid Channel Id */
        Uart_ChannelInfo[Chan].Uart_AssignedHW = UART_INVALID_CHANNEL;

        /* Set Uart_BusChannelMap as Invalid Channel Id */
        Uart_BusChannelMap[ModuleNo] = UART_INVALID_CHANNEL;

       /* Set UART Channel Tx and Rx State as Uninitialised*/
        Uart_ChannelInfo[Chan].Uart_TxState = UART_UNINITIALISED;
        Uart_ChannelInfo[Chan].Uart_RxState = UART_UNINITIALISED;
      }
    }

    if(UART_ZERO_U == ClkFailureChk)
    {
      /* Store ConfigPtr for use by APIs*/
      #if (UART_PB_FIXEDADDR == STD_OFF)
      Uart_kConfigPtr = ConfigPtr;
      #endif    /*(UART_PB_FIXEDADDR == OFF)*/

      #if (UART_DEV_ERROR_DETECT == STD_ON)
       /* Store UART driver initailization status */
      Uart_InitStatus = UART_INITIALISED;
      #endif/*(UART_DEV_ERROR_DETECT == STD_ON)*/
    }
    else
    {
      #if (UART_DEV_ERROR_DETECT == STD_ON)
       /* Store UART driver Status */
      Uart_InitStatus = UART_UNINITIALISED;
      #endif/*(UART_DEV_ERROR_DETECT == STD_ON)*/
    }
  }
  return ;
}

#if ((UART_RESET_SFR_INIT == STD_ON) || (UART_DEINIT_API == STD_ON))
/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Uart_lHwInitKernelRegInit         **
**                      (uint8 HwUnit)                                        **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function resets the Kernel                         **
*******************************************************************************/
IFX_LOCAL_INLINE void Uart_lHwInitKernelRegInit(uint8 HwUnit)
{
  volatile uint32 Readback;
  uint32 WaitCount,RstStatus;
  WaitCount = UART_KRST_TIMEOUT;
  /* Reset End Init Protection to access regsiters */
  UART_SFR_INIT_RESETENDINIT();
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
   efficiently access the SFRs of multiple ASCLINKernels.*/
  UART_SFR_INIT_MODIFY32(UART_HW_MODULE[HwUnit].KRST0.U,\
                                     UART_KRST0_RST_CLEARMASK,UART_ENABLE_BIT)
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
   efficiently access the SFRs of multiple ASCLIN kernels.*/
  Readback = UART_SFR_INIT_USER_MODE_READ32(UART_HW_MODULE[HwUnit].KRST0.U);
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
   efficiently access the SFRs of multiple ASCLIN kernels.*/
  UART_SFR_INIT_MODIFY32(UART_HW_MODULE[HwUnit].KRST1.U,\
               UART_KRST1_RST_CLEARMASK,UART_ENABLE_BIT)
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
   efficiently access the SFRs of multiple ASCLIN kernels.*/
  Readback = UART_SFR_INIT_USER_MODE_READ32(UART_HW_MODULE[HwUnit].KRST1.U);
  /* Set End Init Protection */
  UART_SFR_INIT_SETENDINIT();
  do
  {
    WaitCount--;
    #ifdef IFX_UART_DEBUG
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple ASCLIN kernels.*/
    RstStatus =(uint32)(((UART_SFR_INIT_USER_MODE_READ32\
          (UART_HW_MODULE[HwUnit].KRST0.U) & UART_KRST0_RSTSTAT_MASK) >>\
             UART_KRST0_RSTSTAT_BITPOS) & TestUart_DebugMask01);
    #else
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple ASCLIN kernels.*/
    RstStatus =(uint32)((UART_SFR_INIT_USER_MODE_READ32\
           (UART_HW_MODULE[HwUnit].KRST0.U) & UART_KRST0_RSTSTAT_MASK) >>\
                                                   UART_KRST0_RSTSTAT_BITPOS);
    #endif
  }
  while ((RstStatus == UART_ZERO_U) && (WaitCount > UART_ZERO_U));
  /* Reset End Init Protection to access regsiters */
  UART_SFR_INIT_RESETENDINIT();
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
   efficiently access the SFRs of multiple ASCLIN kernels.*/
  UART_SFR_INIT_MODIFY32(UART_HW_MODULE[HwUnit].KRSTCLR.U,\
                                  UART_KRSTCLR_CLR_CLEARMASK,UART_ENABLE_BIT)
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
   efficiently access the SFRs of multiple ASCLIN kernels.*/
  Readback = UART_SFR_INIT_USER_MODE_READ32(UART_HW_MODULE[HwUnit].KRSTCLR.U);
  /* Set End Init Protection */
  UART_SFR_INIT_SETENDINIT();
  UNUSED_PARAMETER(Readback)
}
/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Uart_lHwInitKernelRegDeInit       **
**                      (uint8 HwUnit)                                        **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function resets the Kernel                         **
*******************************************************************************/
IFX_LOCAL_INLINE void Uart_lHwInitKernelRegDeInit(uint8 HwUnit)
{
  volatile uint32 Readback;
  uint32 WaitCount,RstStatus;
  WaitCount = UART_KRST_TIMEOUT;
  /* Reset End Init Protection to access regsiters */
  UART_SFR_DEINIT_RESETENDINIT();
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
   efficiently access the SFRs of multiple ASCLINKernels.*/
  UART_SFR_DEINIT_MODIFY32(UART_HW_MODULE[HwUnit].KRST0.U,\
                                     UART_KRST0_RST_CLEARMASK,UART_ENABLE_BIT)
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
   efficiently access the SFRs of multiple ASCLIN kernels.*/
  Readback = UART_SFR_DEINIT_USER_MODE_READ32(UART_HW_MODULE[HwUnit].KRST0.U);
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
   efficiently access the SFRs of multiple ASCLIN kernels.*/
  UART_SFR_DEINIT_MODIFY32(UART_HW_MODULE[HwUnit].KRST1.U,\
               UART_KRST1_RST_CLEARMASK,UART_ENABLE_BIT)
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
   efficiently access the SFRs of multiple ASCLIN kernels.*/
  Readback = UART_SFR_DEINIT_USER_MODE_READ32(UART_HW_MODULE[HwUnit].KRST1.U);
  /* Set End Init Protection */
  UART_SFR_DEINIT_SETENDINIT();
  do
  {
    WaitCount--;
    #ifdef IFX_UART_DEBUG
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple ASCLIN kernels.*/
    RstStatus =(uint32)(((UART_SFR_DEINIT_USER_MODE_READ32\
          (UART_HW_MODULE[HwUnit].KRST0.U) & UART_KRST0_RSTSTAT_MASK) >>\
             UART_KRST0_RSTSTAT_BITPOS) & TestUart_DebugMask01);
    #else
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
    efficiently access the SFRs of multiple ASCLIN kernels.*/
    RstStatus =(uint32)((UART_SFR_DEINIT_USER_MODE_READ32\
           (UART_HW_MODULE[HwUnit].KRST0.U) & UART_KRST0_RSTSTAT_MASK) >>\
                                                   UART_KRST0_RSTSTAT_BITPOS);
    #endif
  }
  while ((RstStatus == UART_ZERO_U) && (WaitCount > UART_ZERO_U));
  /* Reset End Init Protection to access regsiters */
  UART_SFR_DEINIT_RESETENDINIT();
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
   efficiently access the SFRs of multiple ASCLIN kernels.*/
  UART_SFR_DEINIT_MODIFY32(UART_HW_MODULE[HwUnit].KRSTCLR.U,\
                                  UART_KRSTCLR_CLR_CLEARMASK,UART_ENABLE_BIT)
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
   efficiently access the SFRs of multiple ASCLIN kernels.*/
  Readback = UART_SFR_DEINIT_USER_MODE_READ32\
                                           (UART_HW_MODULE[HwUnit].KRSTCLR.U);
  /* Set End Init Protection */
  UART_SFR_DEINIT_SETENDINIT();
  UNUSED_PARAMETER(Readback)
}
#endif

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE uint8 Uart_lHwInitClcReg               **
**                      (uint8 HwUnit, uint32 Value)                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                  : Value    : Value to configure CLC Reg                   **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : 0 (Module Clk Enabled)/ 1 (Module Clk Disabled)         **
**                                                                            **
** Description      : This function sets the clc register with given value    **
*******************************************************************************/
IFX_LOCAL_INLINE uint8 Uart_lHwInitClcReg(uint8 HwUnit, uint32 Value)
{
  uint8 ModClkStatus;

  /* Reset End Init Protection */
  UART_SFR_INIT_RESETENDINIT();

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
   UART_HW_MODULE to access the SFRs of a particular HW Unit*/
  UART_SFR_INIT_WRITE32(UART_HW_MODULE[HwUnit].CLC.U,Value);

  /* Set End Init Protection */
  UART_SFR_INIT_SETENDINIT();

/* Check the status bit DISS for Checking Mod Clk Disable Status*/
#ifdef IFX_UART_DEBUG
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
   UART_HW_MODULE to access the SFRs of a particular HW Unit*/
  ModClkStatus = (uint8)(((UART_SFR_INIT_USER_MODE_READ32\
                 (UART_HW_MODULE[HwUnit].CLC.U) & UART_CLC_DISS_MASK) >>\
                 UART_CLC_DISS_BITPOS) | TestUart_DebugMask02);
#else
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
   UART_HW_MODULE to access the SFRs of a particular HW Unit*/
  ModClkStatus = (uint8)((UART_SFR_INIT_USER_MODE_READ32\
  (UART_HW_MODULE[HwUnit].CLC.U) & UART_CLC_DISS_MASK) >> UART_CLC_DISS_BITPOS);
#endif

  return ModClkStatus;
}
/*******************************************************************************
** Traceability :                                                             **
** Syntax           : static void Uart_lHwInit                                **
**                     (uint8 HwUnit,Uart_ChannelConfigType* ChannelConfigPtr)**
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                ChannelConfigPtr : Channel configuration pointer            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function initialises the ASCLIN Hw module          **
*******************************************************************************/
static void Uart_lHwInit(uint8 HwUnit,const Uart_ChannelType* ChannelConfigPtr)
{
  Ifx_ASCLIN*  HwModulePtr;
  uint32 TimeOutCount = UART_TIMEOUT_DURATION;

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
   UART_HW_MODULE to access the SFRs of a particular HW Unit*/
  HwModulePtr = &(UART_HW_MODULE[HwUnit]);
  /* Disable the Input Clock source */
  UART_SFR_INIT_USER_MODE_MODIFY32(HwModulePtr->CSR.U,\
                           UART_CSR_CLKSEL_CLEARMASK,UART_CSRREG_CLKSEL_NOCLK)
  /* provide delay of  TW >= 4 * (1/fA) + 2 * (1/fCLC) clock cycles */
  /* Wait TW or poll for CSR.CON = 0 */
  while ((((UART_SFR_INIT_USER_MODE_READ32(HwModulePtr->CSR.U) &\
          UART_CSR_CON_MASK) >> UART_CSR_CON_BITPOS) != UART_BIT_RESET) &&\
                                                            (TimeOutCount > 0U))
  {
    TimeOutCount-- ;
  }

  TimeOutCount = UART_TIMEOUT_DURATION;
  /* Change to INIT mode */
  UART_SFR_INIT_USER_MODE_MODIFY32(HwModulePtr->FRAMECON.U,\
                       UART_FRAMECON_MODE_CLEARMASK,UART_FRAMECONREG_INIT_MODE)
  /* Connect the Clock source */
  UART_SFR_INIT_USER_MODE_MODIFY32(HwModulePtr->CSR.U,\
                             UART_CSR_CLKSEL_CLEARMASK,UART_CSRREG_CLKSEL_CLC)
  /* provide delay of TW >= 4 * (1/fA) + 2 * (1/fCLC) clock cycles */
  /*Wait TW or poll for CSR.CON = 1*/
  while ((((UART_SFR_INIT_USER_MODE_READ32(HwModulePtr->CSR.U) &\
            UART_CSR_CON_MASK) >> UART_CSR_CON_BITPOS) !=\
                            UART_BIT_SET) && (TimeOutCount > 0U))
  {
     TimeOutCount-- ;
  }

  TimeOutCount = UART_TIMEOUT_DURATION;
  /* Disable the Clock source. */
  UART_SFR_INIT_USER_MODE_MODIFY32(HwModulePtr->CSR.U,\
                          UART_CSR_CLKSEL_CLEARMASK,UART_CSRREG_CLKSEL_NOCLK)
  /* provide delay of  TW >= 4 * (1/fA) + 2 * (1/fCLC) clock cycles */
  /*Wait TW or poll for CSR.CON = 0*/
  while ((((UART_SFR_INIT_USER_MODE_READ32(HwModulePtr->CSR.U) &\
         UART_CSR_CON_MASK) >> UART_CSR_CON_BITPOS) != UART_BIT_RESET) &&\
                                                            (TimeOutCount > 0U))
  {
     TimeOutCount-- ;
  }
  /* Change to ASC mode */
   UART_SFR_INIT_USER_MODE_MODIFY32(HwModulePtr->FRAMECON.U,\
                       UART_FRAMECON_MODE_CLEARMASK,UART_FRAMECONREG_ASC_MODE)

  /* Configure the Baudrate parameters */
  UART_SFR_INIT_USER_MODE_MODIFY32(HwModulePtr->BRG.U,\
                                    UART_BRG_NUMERATOR_CLEARMASK,\
        ((uint32)ChannelConfigPtr->HwBrgNumerator << UART_BRG_NUMERATOR_BITPOS))
  UART_SFR_INIT_USER_MODE_MODIFY32(HwModulePtr->BRG.U,\
                                       UART_BRG_DENOMINATOR_CLEARMASK,\
                                           ChannelConfigPtr->HwBrgDenominator)
  UART_SFR_INIT_USER_MODE_MODIFY32(HwModulePtr->BITCON.U,\
                                          UART_BITCON_PRESCALER_CLEARMASK,\
                                          ChannelConfigPtr->HwBitconPrescalar)
  UART_SFR_INIT_USER_MODE_MODIFY32(HwModulePtr->BITCON.U,\
                UART_BITCON_OVERSAMPLING_CLEARMASK,((uint32)\
     ChannelConfigPtr->HwBitconOversampling << UART_BITCON_OVERSAMPLING_BITPOS))

  /* Digital Glitch Filter = OFF */
  UART_SFR_INIT_USER_MODE_MODIFY32(HwModulePtr->IOCR.U,\
                             UART_IOCR_DEPTH_CLEARMASK,UART_IOCRREG_DEPTH_VAL)

  /* Configure CTS */
  UART_SFR_INIT_USER_MODE_MODIFY32(HwModulePtr->IOCR.U,\
        UART_IOCR_CTSEN_CLEARMASK, ((uint32)ChannelConfigPtr->CtsEnable <<\
                                                        UART_IOCR_CTSEN_BITPOS))
  UART_SFR_INIT_USER_MODE_MODIFY32(HwModulePtr->IOCR.U,\
      UART_IOCR_RCPOL_CLEARMASK, ((uint32)ChannelConfigPtr->CtsPolarity <<\
                                                        UART_IOCR_RCPOL_BITPOS))

  /* Configure Sample mode(3 Bit), Sample point, Parity, Collision detection */
  UART_SFR_INIT_USER_MODE_MODIFY32(HwModulePtr->BITCON.U,\
               UART_BITCON_SM_CLEARMASK, ((uint32)UART_BITCONREG_SM_VAL <<\
                                                         UART_BITCON_SM_BITPOS))
  UART_SFR_INIT_USER_MODE_MODIFY32(HwModulePtr->BITCON.U,\
                                  UART_BITCON_SAMPLEPOINT_CLEARMASK,\
    (uint32)((((uint32)(ChannelConfigPtr->HwBitconOversampling)>>UART_ONE_U)+\
                                 UART_ONE_U) << UART_BITCON_SAMPLEPOINT_BITPOS))

  UART_SFR_INIT_USER_MODE_MODIFY32(HwModulePtr->FRAMECON.U,\
        UART_FRAMECON_PEN_CLEARMASK, ((uint32)ChannelConfigPtr->ParityEnable <<\
                                                      UART_FRAMECON_PEN_BITPOS))
  UART_SFR_INIT_USER_MODE_MODIFY32(HwModulePtr->FRAMECON.U,\
            UART_FRAMECON_ODD_CLEARMASK, ((uint32)ChannelConfigPtr->Parity <<\
                                                      UART_FRAMECON_ODD_BITPOS))
  UART_SFR_INIT_USER_MODE_MODIFY32(HwModulePtr->FRAMECON.U,\
        UART_FRAMECON_IDLE_CLEARMASK, UART_BIT_SET << UART_FRAMECON_IDLE_BITPOS)

  UART_SFR_INIT_USER_MODE_MODIFY32(HwModulePtr->FRAMECON.U,\
       UART_FRAMECON_STOP_CLEARMASK, ((uint32)ChannelConfigPtr->StopBits <<\
                                                     UART_FRAMECON_STOP_BITPOS))

  /* Configure RX inlet, TX outlet width/s(8/16 bit) based on UartDataLength*/
  UART_SFR_INIT_USER_MODE_MODIFY32(HwModulePtr->TXFIFOCON.U,\
                 UART_TXFIFOCON_INW_CLEARMASK, UART_TXFIFOCONREG_INW_VAL <<\
                                                      UART_TXFIFOCON_INW_BITPOS)
  UART_SFR_INIT_USER_MODE_MODIFY32(HwModulePtr->RXFIFOCON.U,\
              UART_RXFIFOCON_OUTW_CLEARMASK, UART_RXFIFOCONREG_OUTW_VAL <<\
                                                     UART_RXFIFOCON_OUTW_BITPOS)

  /*Data length Defines the number of bits in a character*/
  UART_SFR_INIT_USER_MODE_MODIFY32(HwModulePtr->DATCON.U,\
                                   UART_DATCON_DATLEN_CLEARMASK,\
                           ((uint32)ChannelConfigPtr->DataLength - UART_ONE_U))

  UART_SFR_INIT_USER_MODE_MODIFY32(HwModulePtr->IOCR.U,\
                                   UART_IOCR_LB_CLEARMASK, UART_DISABLE_BIT)
  UART_SFR_INIT_USER_MODE_MODIFY32(HwModulePtr->IOCR.U,\
                   UART_IOCR_ALTI_CLEARMASK, ChannelConfigPtr->RxPinSelection)

  /* Select the Clock source */
  UART_SFR_INIT_USER_MODE_MODIFY32(HwModulePtr->CSR.U,\
                             UART_CSR_CLKSEL_CLEARMASK, UART_CSRREG_CLKSEL_CLC)

  TimeOutCount = UART_TIMEOUT_DURATION;
  /* provide delay of TW >= 4 * (1/fA) + 2 * (1/fCLC) clock cycles */
  /*Wait TW or poll for CSR.CON = 1*/
  while ((((UART_SFR_INIT_USER_MODE_READ32(HwModulePtr->CSR.U) &\
             UART_CSR_CON_MASK) >> UART_CSR_CON_BITPOS) !=UART_BIT_SET) &&\
                                                            (TimeOutCount > 0U))
  {
     TimeOutCount-- ;
  }
}
#if ((UART_ABORT_READ_API == STD_ON) || (UART_ABORT_WRITE_API == STD_ON))
/*******************************************************************************
** Traceability :                                                             **
** Syntax           : static void Uart_lHwInitRuntime                         **
**                     (uint8 HwUnit,Uart_ChannelConfigType* ChannelConfigPtr)**
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                ChannelConfigPtr : Channel configuration pointer            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function initialises the ASCLIN Hw module          **
*******************************************************************************/
static void Uart_lHwInitRuntime(uint8 HwUnit,\
                                       const Uart_ChannelType* ChannelConfigPtr)
{
  Ifx_ASCLIN*  HwModulePtr;
  uint32 TimeOutCount = UART_TIMEOUT_DURATION;

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
   UART_HW_MODULE to access the SFRs of a particular HW Unit*/
  HwModulePtr = &(UART_HW_MODULE[HwUnit]);
   /* Disable the Input Clock source */
    UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->CSR.U,\
                           UART_CSR_CLKSEL_CLEARMASK,UART_CSRREG_CLKSEL_NOCLK)
    /* provide delay of  TW >= 4 * (1/fA) + 2 * (1/fCLC) clock cycles */
    /* Wait TW or poll for CSR.CON = 0 */
    while ((((UART_SFR_RUNTIME_USER_MODE_READ32(HwModulePtr->CSR.U) &\
          UART_CSR_CON_MASK) >> UART_CSR_CON_BITPOS) != UART_BIT_RESET) &&\
                                                            (TimeOutCount > 0U))
    {
      TimeOutCount-- ;
    }

    TimeOutCount = UART_TIMEOUT_DURATION;
  /* Change to INIT mode */
  UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->FRAMECON.U,\
                       UART_FRAMECON_MODE_CLEARMASK,UART_FRAMECONREG_INIT_MODE)
  /* Connect the Clock source */
  UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->CSR.U,\
                             UART_CSR_CLKSEL_CLEARMASK,UART_CSRREG_CLKSEL_CLC)
  /* provide delay of TW >= 4 * (1/fA) + 2 * (1/fCLC) clock cycles */
  /*Wait TW or poll for CSR.CON = 1*/
  while ((((UART_SFR_RUNTIME_USER_MODE_READ32(HwModulePtr->CSR.U) &\
            UART_CSR_CON_MASK) >> UART_CSR_CON_BITPOS) !=\
                            UART_BIT_SET) && (TimeOutCount > 0U))
  {
     TimeOutCount-- ;
  }

  TimeOutCount = UART_TIMEOUT_DURATION;
  /* Disable the Clock source. */
  UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->CSR.U,\
                          UART_CSR_CLKSEL_CLEARMASK,UART_CSRREG_CLKSEL_NOCLK)
  /* provide delay of  TW >= 4 * (1/fA) + 2 * (1/fCLC) clock cycles */
  /*Wait TW or poll for CSR.CON = 0*/
  while ((((UART_SFR_RUNTIME_USER_MODE_READ32(HwModulePtr->CSR.U) &\
         UART_CSR_CON_MASK) >> UART_CSR_CON_BITPOS) != UART_BIT_RESET) &&\
                                                            (TimeOutCount > 0U))
  {
     TimeOutCount-- ;
  }
  /* Change to ASC mode */
  UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->FRAMECON.U,\
                       UART_FRAMECON_MODE_CLEARMASK,UART_FRAMECONREG_ASC_MODE)

  /* Configure the Baudrate parameters */
  UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->BRG.U,\
                                    UART_BRG_NUMERATOR_CLEARMASK,\
        ((uint32)ChannelConfigPtr->HwBrgNumerator << UART_BRG_NUMERATOR_BITPOS))
  UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->BRG.U,\
                                       UART_BRG_DENOMINATOR_CLEARMASK,\
                                           ChannelConfigPtr->HwBrgDenominator)
  UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->BITCON.U,\
                                          UART_BITCON_PRESCALER_CLEARMASK,\
                                          ChannelConfigPtr->HwBitconPrescalar)
  UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->BITCON.U,\
                UART_BITCON_OVERSAMPLING_CLEARMASK,((uint32)\
     ChannelConfigPtr->HwBitconOversampling << UART_BITCON_OVERSAMPLING_BITPOS))

  /* Digital Glitch Filter = OFF */
  UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->IOCR.U,\
                             UART_IOCR_DEPTH_CLEARMASK,UART_IOCRREG_DEPTH_VAL)

  /* Configure CTS */
  UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->IOCR.U,\
        UART_IOCR_CTSEN_CLEARMASK, ((uint32)ChannelConfigPtr->CtsEnable <<\
                                                        UART_IOCR_CTSEN_BITPOS))
  UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->IOCR.U,\
      UART_IOCR_RCPOL_CLEARMASK, ((uint32)ChannelConfigPtr->CtsPolarity <<\
                                                        UART_IOCR_RCPOL_BITPOS))

  /* Configure Sample mode(3 Bit), Sample point, Parity, Collision detection */
  UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->BITCON.U,\
               UART_BITCON_SM_CLEARMASK, ((uint32)UART_BITCONREG_SM_VAL <<\
                                                         UART_BITCON_SM_BITPOS))
  UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->BITCON.U,\
                                  UART_BITCON_SAMPLEPOINT_CLEARMASK,\
    (uint32)((((uint32)(ChannelConfigPtr->HwBitconOversampling)>>UART_ONE_U)+\
                                 UART_ONE_U) << UART_BITCON_SAMPLEPOINT_BITPOS))

  UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->FRAMECON.U,\
        UART_FRAMECON_PEN_CLEARMASK, ((uint32)ChannelConfigPtr->ParityEnable <<\
                                                      UART_FRAMECON_PEN_BITPOS))
  UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->FRAMECON.U,\
            UART_FRAMECON_ODD_CLEARMASK, ((uint32)ChannelConfigPtr->Parity <<\
                                                      UART_FRAMECON_ODD_BITPOS))
  UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->FRAMECON.U,\
        UART_FRAMECON_IDLE_CLEARMASK, UART_BIT_SET << UART_FRAMECON_IDLE_BITPOS)

  UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->FRAMECON.U,\
       UART_FRAMECON_STOP_CLEARMASK, ((uint32)ChannelConfigPtr->StopBits <<\
                                                     UART_FRAMECON_STOP_BITPOS))

  /* Configure RX inlet, TX outlet width/s(8/16 bit) based on UartDataLength*/
  UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->TXFIFOCON.U,\
                 UART_TXFIFOCON_INW_CLEARMASK, UART_TXFIFOCONREG_INW_VAL <<\
                                                      UART_TXFIFOCON_INW_BITPOS)
  UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->RXFIFOCON.U,\
              UART_RXFIFOCON_OUTW_CLEARMASK, UART_RXFIFOCONREG_OUTW_VAL <<\
                                                     UART_RXFIFOCON_OUTW_BITPOS)

  /*Data length Defines the number of bits in a character*/
  UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->DATCON.U,\
                                   UART_DATCON_DATLEN_CLEARMASK,\
                           ((uint32)ChannelConfigPtr->DataLength - UART_ONE_U))

  UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->IOCR.U,\
                                   UART_IOCR_LB_CLEARMASK, UART_DISABLE_BIT)
  UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->IOCR.U,\
                   UART_IOCR_ALTI_CLEARMASK, ChannelConfigPtr->RxPinSelection)

  /* Select the Clock source */
  UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->CSR.U,\
                             UART_CSR_CLKSEL_CLEARMASK, UART_CSRREG_CLKSEL_CLC)

  TimeOutCount = UART_TIMEOUT_DURATION;
  /* provide delay of TW >= 4 * (1/fA) + 2 * (1/fCLC) clock cycles */
  /*Wait TW or poll for CSR.CON = 1*/
  while ((((UART_SFR_RUNTIME_USER_MODE_READ32(HwModulePtr->CSR.U) &\
             UART_CSR_CON_MASK) >> UART_CSR_CON_BITPOS) !=UART_BIT_SET) &&\
                                                            (TimeOutCount > 0U))
  {
     TimeOutCount-- ;
  }
}
#endif
#if (UART_DEINIT_API == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_UART_PR1570,DS_NAS_UART_PR63_7]      **
**
** Syntax : void Uart_DeInit( void )                                          **
**          [/cover]                                                          **
** Service ID:  0x01                                                          **
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
** Description : Driver Module DeInitialization function.                     **
** Service for UART de initialization.                                        **
*******************************************************************************/
void Uart_DeInit(void)
{
  Ifx_ASCLIN*  HwModulePtr;
  const Uart_ChannelType   *ChannelConfigPtr;
  uint32 TimeOutCount = UART_TIMEOUT_DURATION;
  uint8 ModuleNo,Chan;
  uint8 MaxChannel;

  #if (UART_DEV_ERROR_DETECT == STD_ON)
   Std_ReturnType ReturnStatus;
   ReturnStatus = E_OK;
  #endif

  #if (UART_DEV_ERROR_DETECT == STD_ON) /* if DET detection is switched On */
  if (Uart_InitStatus == UART_UNINITIALISED)
   {
     /* If Uart is already unintialised Report to  DET */
     Det_ReportError(
                      UART_MODULE_ID,
                      UART_MODULE_INSTANCE,
                      UART_SID_DEINIT,
                      UART_E_UNINIT
                     );
     ReturnStatus = E_NOT_OK;
   }
  #endif  /* (_DEV_ERROR_DETECT == STD_ON) */

  #if (UART_DEV_ERROR_DETECT == STD_ON)
  if (ReturnStatus == E_OK)
  #endif
  {
    MaxChannel = Uart_kConfigPtr->NoOfChannels;

    for (Chan = UART_ZERO_U; Chan < MaxChannel; Chan++)
    {
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
       ChannelConfigPtr to access the Configuration of a particular Channel*/
      ChannelConfigPtr = &(Uart_kConfigPtr->ChannelConfigPtr[Chan]);
      /* Extract the Hw module */
      ModuleNo = ChannelConfigPtr->HwModule;
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
       UART_HW_MODULE to access the SFRs of a particular HW Unit*/
      HwModulePtr = &(UART_HW_MODULE[ModuleNo]);

      /* Disable the Clock source */
      UART_SFR_DEINIT_USER_MODE_MODIFY32(HwModulePtr->CSR.U,\
                           UART_CSR_CLKSEL_CLEARMASK, UART_CSRREG_CLKSEL_NOCLK)

      TimeOutCount = UART_TIMEOUT_DURATION;
      /* provide delay of  TW >= 4 * (1/fA) + 2 * (1/fCLC) clock cycles */
      /*Wait TW or poll for CSR.CON = 0*/
      while ((((UART_SFR_DEINIT_USER_MODE_READ32(HwModulePtr->CSR.U) &\
           UART_CSR_CON_MASK) >> UART_CSR_CON_BITPOS) !=UART_BIT_RESET) &&\
                                                            (TimeOutCount > 0U))
      {
        TimeOutCount-- ;
      }

      /* Change to  INIT mode */
      UART_SFR_DEINIT_USER_MODE_MODIFY32(HwModulePtr->FRAMECON.U,\
                    UART_FRAMECON_MODE_CLEARMASK, UART_FRAMECONREG_INIT_MODE)
      /* Connect the Clock source */
      UART_SFR_DEINIT_USER_MODE_MODIFY32(HwModulePtr->FRAMECON.U,\
                           UART_CSR_CLKSEL_CLEARMASK, UART_CSRREG_CLKSEL_CLC)

      TimeOutCount = UART_TIMEOUT_DURATION;
      /* provide delay of TW >= 4 * (1/fA) + 2 * (1/fCLC) clock cycles */
      /* Wait TW or poll for CSR.CON = 1 */
      while ((((UART_SFR_DEINIT_USER_MODE_READ32(HwModulePtr->CSR.U) &\
             UART_CSR_CON_MASK) >> UART_CSR_CON_BITPOS) !=UART_BIT_SET) && \
                                                            (TimeOutCount > 0U))
      {
        TimeOutCount-- ;
      }

      /* Init the Uart_BusChannelMap Array */
      Uart_BusChannelMap[ModuleNo] = UART_INVALID_CHANNEL;

      /* Reset the channel Info*/
      Uart_ChannelInfo[Chan].Uart_TxState = UART_UNINITIALISED;
      Uart_ChannelInfo[Chan].Uart_RxState = UART_UNINITIALISED;
      Uart_ChannelInfo[Chan].Uart_TxDataLeft = UART_ZERO_U;
      Uart_ChannelInfo[Chan].Uart_RxDataLeft = UART_ZERO_U;
      Uart_ChannelInfo[Chan].Uart_TotalDataTxd= UART_ZERO_U;
      Uart_ChannelInfo[Chan].Uart_TotalDataRxd= UART_ZERO_U;
      Uart_ChannelInfo[Chan].Uart_TxBuffPtr = NULL_PTR;
      Uart_ChannelInfo[Chan].Uart_RxBuffPtr = NULL_PTR;
      Uart_ChannelInfo[Chan].Uart_TxDataCopyCntr = UART_ZERO_U;
      Uart_ChannelInfo[Chan].Uart_AssignedHW = UART_INVALID_CHANNEL;

      /* Reset the Uart Channel Tx/Rx Resource Lock */
      Uart_ChLock[UART_TX_LOCK_IDX][Chan] = UART_ZERO_U;
      Uart_ChLock[UART_RX_LOCK_IDX][Chan] = UART_ZERO_U;

      /* Clear the read and write Interrupts*/
      Uart_lClearReadInterrupts(HwModulePtr, UART_DEINIT_ACCESS);
      Uart_lClearWriteInterrupts(HwModulePtr, UART_DEINIT_ACCESS);

      /* Disable Tx,Rx and Err Interrupts*/
      Uart_lHwDisableAscLinTxIntr(ModuleNo, UART_DEINIT_ACCESS);
      Uart_lHwDisableAscLinRxIntr(ModuleNo, UART_DEINIT_ACCESS);
      Uart_lHwDisableAscLinErrIntr(ModuleNo, UART_DEINIT_ACCESS);

      /* Reset ASCLIN Kernel  */
      Uart_lHwInitKernelRegDeInit(ModuleNo);

      /* Reset End Init Protection */
      UART_SFR_DEINIT_RESETENDINIT();

      /* Disable the ASCLIN module */
      UART_SFR_DEINIT_WRITE32(HwModulePtr->CLC.U, UART_DISABLE_ASCLIN_MODULE);

      /* Set End Init Protection */
      UART_SFR_DEINIT_SETENDINIT();
    }

    #if (UART_DEV_ERROR_DETECT == STD_ON)
     /* Store UART driver initailization status */
    Uart_InitStatus = UART_UNINITIALISED;
    #endif/*(UART_DEV_ERROR_DETECT == STD_ON)*/
  }
  return ;
}
#endif
/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_UART_PR1571,DS_NAS_UART_PR63_8]
**
** Syntax : Uart_ReturnType Uart_Read                                         **
**  (                                                                         **
**    Uart_ChannelIdType channel,Uart_MemPtrType MemPtr,Uart_SizeType Size    **
**  )                                                                         **
**                    [/cover]                                                **
** Service ID:  0x02                                                          **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  Reentrant(Not for same channel)                               **
**                                                                            **
** Parameters (in): Channel - Uart channel to be addressed .                  **
**                  MemPtr - Pointer to location where data needs to be stored**
**                  Size - No of data that needs to be recieved               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : UART_OK - Read operation was initiaited successfully     **
**                   UART_NOT_OK - Read operation couldn't be initiated       **
**                   due to developement errors                               **
**                   UART_IS_BUSY - Uart channel is busy with other           **
**                   read operation                                           **
**                                                                            **
** Description : Api to configure the given UART Channel for reception of the **
**       specified number of data bytes and the memory location (App Rx Buff) **
**        to be used to store the received data                               **
*******************************************************************************/

Uart_ReturnType Uart_Read\
         (Uart_ChannelIdType Channel,Uart_MemPtrType MemPtr,Uart_SizeType Size)
{
  Ifx_ASCLIN*  HwModulePtr;
  Uart_ReturnType Retvalue = UART_OK;
  uint8 HwUnit;
  uint8 TempIntLevel;

 #if (UART_DEV_ERROR_DETECT != STD_ON)
  uint32 ChRxLock;
 #endif

  #if (UART_DEV_ERROR_DETECT == STD_ON)
  if (Uart_InitStatus == UART_UNINITIALISED)
  {
    /*If Uart is not initialised then  Report to  DET */
    Det_ReportError(
                    UART_MODULE_ID,
                    UART_MODULE_INSTANCE,
                    UART_SID_READ,
                    UART_E_UNINIT
                   );
    Retvalue = UART_NOT_OK;
  }
  else if (MemPtr == NULL_PTR)
  {
    /*If memory pointer is equal to null pointer Report to  DET */
    Det_ReportError(
                    UART_MODULE_ID,
                    UART_MODULE_INSTANCE,
                    UART_SID_READ,
                    UART_E_PARAM_POINTER
                   );
    Retvalue = UART_NOT_OK;
  }
  else if (Size == UART_ZERO_U )
  {
    /* If the size is equal to zero Report to  DET */
    Det_ReportError(
                    UART_MODULE_ID,
                    UART_MODULE_INSTANCE,
                    UART_SID_READ,
                    UART_E_INVALID_SIZE
                   );
    Retvalue = UART_NOT_OK;
  }
  else
  {
    /* If the channelId is Invalid Report to DET */
    Retvalue = Uart_lChannelCheck(Channel,UART_SID_READ);

    if (Retvalue == UART_OK)
    {
      /* If the channel is busy then Report to DET */
      if (Uart_ChannelInfo[Channel].Uart_RxState != UART_INITIALISED)
      {
        /*If channel is busy then Report to  DET */
        Det_ReportError(
                        UART_MODULE_ID,
                        UART_MODULE_INSTANCE,
                        UART_SID_READ,
                        UART_E_STATE_TRANSITION
                        );
        Retvalue = UART_IS_BUSY;
      }
    }
  }
  #endif
  #if (UART_DEV_ERROR_DETECT == STD_ON)
  if (Retvalue == UART_OK)
  #else
   /* The Uart Read operation is already started for the channel. No other
      operation can be started on this Channel. This is implemented using a
      binary semaphore mechanism */
   ChRxLock = Mcal_LockResource(&Uart_ChLock[UART_RX_LOCK_IDX][Channel]);

   /* No other Uart Read operation is in progress on the same Channel */
   if (ChRxLock == MCAL_RESOURCE_BUSY)
   {
        Retvalue = UART_IS_BUSY;
   }
   else
  #endif
  {
    /* Update Uart_ChannelInfo for Read Operation */
    Uart_ChannelInfo[Channel].Uart_RxState= UART_OPERATION_IN_PROGRESS;
    Uart_ChannelInfo[Channel].Uart_RxBuffPtr= MemPtr;
    Uart_ChannelInfo[Channel].Uart_RxDataLeft = Size;
    Uart_ChannelInfo[Channel].Uart_TotalDataRxd =UART_ZERO_U;

    HwUnit = Uart_ChannelInfo[Channel].Uart_AssignedHW;
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
    UART_HW_MODULE to access the SFRs of a particular HW Unit*/
    HwModulePtr= &(UART_HW_MODULE[HwUnit]);

    /* Configure RX Outlet Width */
    UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->RXFIFOCON.U,\
              UART_RXFIFOCON_OUTW_CLEARMASK, UART_RXFIFOCONREG_OUTW_VAL <<\
                                                    UART_RXFIFOCON_OUTW_BITPOS)

    if(Uart_ChannelInfo[Channel].Uart_RxDataLeft < UART_BUFFER_SIZE)
    {
      /*Set RX FIFO Interrupt level according to Uart Size*/
      TempIntLevel = (uint8)Uart_ChannelInfo[Channel].Uart_RxDataLeft\
                                  - (uint8)(UART_ONE_U);
      UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->RXFIFOCON.U,\
                UART_RXFIFOCON_INTLEVEL_CLEARMASK,(uint32)(TempIntLevel) << \
                                                 UART_RXFIFOCON_INTLEVEL_BITPOS)
    }
    else
    {
      /*Set RX FIFO Interrupt level to RX FIFO level*/
      UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->RXFIFOCON.U,\
                                 UART_RXFIFOCON_INTLEVEL_CLEARMASK,\
         ((uint32)UART_RX_FIFO_INT_LEVEL_VAL << UART_RXFIFOCON_INTLEVEL_BITPOS))
    }

     /*Flush the Rx FIFO*/
    UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->RXFIFOCON.U,\
                             UART_RXFIFOCON_FLUSH_CLEARMASK, UART_ENABLE_BIT)

    /*Enable Rx(RxFIFO level) and Err(Parity,framing,rx underflow) Interrupts*/
    Uart_lEnableReadInterrupts(HwModulePtr);

     /*Enable Error and Rx Interrupts*/
    Uart_lHwEnableAscLinRxIntr(HwUnit);
    Uart_lHwEnableAscLinErrIntr(HwUnit);

     /*Enable Receiver and filling of RxFIFO*/
    UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->RXFIFOCON.U,\
          UART_RXFIFOCON_ENI_CLEARMASK, UART_ONE_U << UART_RXFIFOCON_ENI_BITPOS)
  }
  return Retvalue;
}


/*******************************************************************************
** Syntax : static void Uart_lRead                                            **
**  (                                                                         **
**    Ifx_ASCLIN* HwModulePtr,Uart_ChannelIdType Channel                      **
**  )                                                                         **
**                                                                            **
** Service ID: NA                                                             **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:   Reentrant(Not for same channel)                              **
**                                                                            **
** Parameters (in): Channel - Uart channel to be addressed                    **
**                  HwModulePtr - Asclin Hardware Pointer                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : local function to copy the data from the RX FIFO buffer to   **
**               the user specified memory location(App Buffer)               **
*******************************************************************************/
static void Uart_lRead(Ifx_ASCLIN* HwModulePtr,Uart_ChannelIdType Channel)
{
  Uart_MemPtrType BuffPtr;
  uint16 Read_Count;
  uint8 TempIntLevel;
  uint8 UartDatalen;

  BuffPtr =  Uart_ChannelInfo[Channel].Uart_RxBuffPtr;

  if (Uart_ChannelInfo[Channel].Uart_RxDataLeft <= UART_BUFFER_SIZE)
  {
    /*Set Read byte Count equal to the amount of data Remaining */
    Read_Count = Uart_ChannelInfo[Channel].Uart_RxDataLeft;
  }
  else
  {
    /*Set Read byte Count equal to RX FIFO Buffer Size*/
    Read_Count = UART_BUFFER_SIZE;
  }

  while (Read_Count > UART_ZERO_U)
  {
    UartDatalen =(uint8)((UART_SFR_RUNTIME_USER_MODE_READ32\
    (HwModulePtr->DATCON.U) & UART_DATCON_DATLEN_MASK) + UART_ONE_U);

    /*Check if the data to be read is the last one and datalen is 7/8*/
    if ((Uart_ChannelInfo[Channel].Uart_RxDataLeft == UART_ONE_U) &&\
                            (UartDatalen != UART_NINEBIT_DATLEN))
    {
      UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->RXFIFOCON.U,\
        UART_RXFIFOCON_OUTW_CLEARMASK, UART_ONE_U << UART_RXFIFOCON_OUTW_BITPOS)

      *BuffPtr = (Uart_MemType)UART_SFR_RUNTIME_USER_MODE_READ32\
                                         (HwModulePtr->RXDATA.U);
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
        BuffPtr to access next element of Application Data Buffer*/
      BuffPtr++;

      /*Complete data is copied so set the Rx FIFO Interrupt level to Zero*/
      UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->RXFIFOCON.U,\
                              UART_RXFIFOCON_INTLEVEL_CLEARMASK, UART_ZERO_U)

      /*Complete data is copied so set Read count to Zero*/
      Read_Count = UART_ZERO_U;

      Uart_ChannelInfo[Channel].Uart_RxDataLeft = UART_ZERO_U;
      Uart_ChannelInfo[Channel].Uart_TotalDataRxd += UART_ONE_U;
    }
    else
    {
      *BuffPtr = (Uart_MemType)UART_SFR_RUNTIME_USER_MODE_READ32\
                                                (HwModulePtr->RXDATA.U);
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
        BuffPtr to access next element of Application Data Buffer*/
      BuffPtr++;

      /*Reduce the Read count by step size(i.e. One Data Count)*/
      Read_Count = Read_Count - UART_STEPSIZE;
      /*Update Uart_ChannelInfo for total data received and data
       bytes remaining to be received*/
      Uart_ChannelInfo[Channel].Uart_RxDataLeft -= UART_STEPSIZE;
      Uart_ChannelInfo[Channel].Uart_TotalDataRxd += UART_STEPSIZE;
    }
  }

  if(Uart_ChannelInfo[Channel].Uart_RxDataLeft < UART_BUFFER_SIZE)
  {
    if (Uart_ChannelInfo[Channel].Uart_RxDataLeft > UART_ZERO_U)
    {
      /*Set RX FIFO Interrupt level according to the amount of data remainig*/
      TempIntLevel = (uint8)Uart_ChannelInfo[Channel].Uart_RxDataLeft\
                                                  - ((uint8)UART_ONE_U);
      UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->RXFIFOCON.U,\
                 UART_RXFIFOCON_INTLEVEL_CLEARMASK, (uint32)TempIntLevel << \
                                                 UART_RXFIFOCON_INTLEVEL_BITPOS)
    }
    else
    {
     /* Do Nothing */
    }
  }
  else
  {
    /*Set the RX FIFO Interrupt level to RX FIFO Buffer Size*/
     UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->RXFIFOCON.U,\
                                      UART_RXFIFOCON_INTLEVEL_CLEARMASK,\
         ((uint32)UART_RX_FIFO_INT_LEVEL_VAL << UART_RXFIFOCON_INTLEVEL_BITPOS))
  }
    /*Update Uart_ChannelInfo for Memptr*/
  Uart_ChannelInfo[Channel].Uart_RxBuffPtr = BuffPtr;

}

/*******************************************************************************
** Syntax : static void Uart_lEnableReadInterrupts (Ifx_ASCLIN* HwModulePtr)  **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:      reentrant                                                 **
**                                                                            **
** Parameters (in): HwModulePtr - Asclin Hardware Pointer                     **
**                                                                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Local function to Enable Rx and Err Interrupts in read fnt   **
**                                                                            **
*******************************************************************************/
static void Uart_lEnableReadInterrupts(Ifx_ASCLIN* HwModulePtr)
{
  /*Enable Parity, Framing, RxFIFO Underflow and RxFIFO Level Interrupts*/
  UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->FLAGSENABLE.U,\
               UART_FLAGSENABLE_PEE_CLEARMASK,((uint32)UART_ENABLE_BIT << \
                                                   UART_FLAGSENABLE_PEE_BITPOS))

  UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->FLAGSENABLE.U,\
              UART_FLAGSENABLE_FEE_CLEARMASK, ((uint32)UART_ENABLE_BIT << \
                                                   UART_FLAGSENABLE_FEE_BITPOS))

  UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->FLAGSENABLE.U,\
              UART_FLAGSENABLE_RFLE_CLEARMASK, ((uint32)UART_ENABLE_BIT << \
                                                  UART_FLAGSENABLE_RFLE_BITPOS))

  UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->FLAGSENABLE.U,\
              UART_FLAGSENABLE_RFUE_CLEARMASK, ((uint32)UART_ENABLE_BIT << \
                                                  UART_FLAGSENABLE_RFUE_BITPOS))
}

/*******************************************************************************
** Syntax : static void Uart_lClearReadInterrupts (Ifx_ASCLIN* HwModulePtr,   **
                                                         uint8 ApiAccessId)   **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:      reentrant                                                 **
**                                                                            **
** Parameters (in): HwModulePtr - Asclin Hardware Pointer                     **
**                  ApiAccessId - API Access type                             **
**                                                                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Local function to Disable  Rx and Err Interrupts in read fnt **
**                                                                            **
*******************************************************************************/
static void Uart_lClearReadInterrupts(Ifx_ASCLIN* HwModulePtr,\
                                                              uint8 ApiAccessId)
{
  #if (UART_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  #if (UART_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
  if (ApiAccessId == UART_RUNTIME_ACCESS)
  {
    /*Clear Parity,Framing, RxFIFO Underflow and RxFIFO Level Interrupts*/
    UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->FLAGSCLEAR.U,\
               UART_FLAGSCLEAR_PEC_CLEARMASK, ((uint32)UART_ENABLE_BIT << \
                                                    UART_FLAGSCLEAR_PEC_BITPOS))

    UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->FLAGSCLEAR.U,\
                UART_FLAGSCLEAR_FEC_CLEARMASK, ((uint32)UART_ENABLE_BIT << \
                                                    UART_FLAGSCLEAR_FEC_BITPOS))

    UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->FLAGSCLEAR.U,\
               UART_FLAGSCLEAR_RFLC_CLEARMASK, ((uint32)UART_ENABLE_BIT << \
                                                   UART_FLAGSCLEAR_RFLC_BITPOS))

    UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->FLAGSCLEAR.U,\
               UART_FLAGSCLEAR_RFUC_CLEARMASK, ((uint32)UART_ENABLE_BIT << \
                                                   UART_FLAGSCLEAR_RFUC_BITPOS))
  }
  else
  #endif /*(UART_USER_MODE_RUNTIME_API_ENABLE == STD_ON)*/
  #if (UART_USER_MODE_DEINIT_API_ENABLE == STD_ON)
  if (ApiAccessId == UART_DEINIT_ACCESS)
  {
    /*Clear Parity,Framing, RxFIFO Underflow and RxFIFO Level Interrupts*/
    UART_SFR_DEINIT_USER_MODE_MODIFY32(HwModulePtr->FLAGSCLEAR.U,\
               UART_FLAGSCLEAR_PEC_CLEARMASK, ((uint32)UART_ENABLE_BIT << \
                                                    UART_FLAGSCLEAR_PEC_BITPOS))

    UART_SFR_DEINIT_USER_MODE_MODIFY32(HwModulePtr->FLAGSCLEAR.U,\
                UART_FLAGSCLEAR_FEC_CLEARMASK, ((uint32)UART_ENABLE_BIT << \
                                                    UART_FLAGSCLEAR_FEC_BITPOS))

    UART_SFR_DEINIT_USER_MODE_MODIFY32(HwModulePtr->FLAGSCLEAR.U,\
               UART_FLAGSCLEAR_RFLC_CLEARMASK, ((uint32)UART_ENABLE_BIT << \
                                                   UART_FLAGSCLEAR_RFLC_BITPOS))

    UART_SFR_DEINIT_USER_MODE_MODIFY32(HwModulePtr->FLAGSCLEAR.U,\
               UART_FLAGSCLEAR_RFUC_CLEARMASK, ((uint32)UART_ENABLE_BIT << \
                                                   UART_FLAGSCLEAR_RFUC_BITPOS))
  }
  else
  #endif /*(UART_USER_MODE_DEINIT_API_ENABLE == STD_ON)*/
  #endif /*(UART_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)*/
  {
    /*Clear Parity,Framing, RxFIFO Underflow and RxFIFO Level Interrupts*/
    HwModulePtr->FLAGSCLEAR.U = (unsigned_int)((HwModulePtr->FLAGSCLEAR.U &\
            UART_FLAGSCLEAR_PEC_CLEARMASK) | ((unsigned_int)UART_ENABLE_BIT << \
                                                   UART_FLAGSCLEAR_PEC_BITPOS));

    HwModulePtr->FLAGSCLEAR.U = (unsigned_int)((HwModulePtr->FLAGSCLEAR.U &\
            UART_FLAGSCLEAR_FEC_CLEARMASK) | ((unsigned_int)UART_ENABLE_BIT << \
                                                   UART_FLAGSCLEAR_FEC_BITPOS));

    HwModulePtr->FLAGSCLEAR.U = (unsigned_int)((HwModulePtr->FLAGSCLEAR.U &\
           UART_FLAGSCLEAR_RFLC_CLEARMASK) | ((unsigned_int)UART_ENABLE_BIT << \
                                                  UART_FLAGSCLEAR_RFLC_BITPOS));

    HwModulePtr->FLAGSCLEAR.U = (unsigned_int)((HwModulePtr->FLAGSCLEAR.U &\
           UART_FLAGSCLEAR_RFUC_CLEARMASK) | ((unsigned_int)UART_ENABLE_BIT << \
                                                  UART_FLAGSCLEAR_RFUC_BITPOS));
  }
  #if ((UART_RUNNING_IN_USER_0_MODE_ENABLE == STD_OFF) || \
      ((UART_USER_MODE_RUNTIME_API_ENABLE == STD_OFF) && \
      (UART_USER_MODE_DEINIT_API_ENABLE == STD_OFF)))
      UNUSED_PARAMETER(ApiAccessId)
      #endif
}


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_UART_PR1572,DS_NAS_UART_PR63_9]      **
** Syntax : Uart_ReturnType Uart_Write                                        **
**  (                                                                         **
**    Uart_ChannelIdType channel,Uart_MemPtrType MemPtr,Uart_SizeType Size    **
**  )                                                                         **
**                    [/cover]                                                **
** Service ID:  0x03                                                          **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  Reentrant  (Not for the same channel)                         **
**                                                                            **
** Parameters (in): Channel - Uart channel to be addressed                    **
**                  MemPtr - Pointer to location where transmit data is stored**
**                  Size - No. of data bytes that needs to be transmitted     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : UART_OK - Write operation was initiaited successfully    **
**                   UART_NOT_OK - Write operation couldn't performed         **
**                                 due to developement error                  **
**                   UART_IS_BUSY - Uart channel is busy with other           **
**                                  write operation                           **
**                                                                            **
** Description : Api to transmit data from user memory location(App Buffer)   **
**               on to the given channel                                      **
**                                                                            **
*******************************************************************************/
Uart_ReturnType Uart_Write\
          (Uart_ChannelIdType Channel,Uart_MemPtrType MemPtr,Uart_SizeType Size)
{
  const Uart_ChannelType *ChannelConfigPtr;
  Ifx_ASCLIN* HwModulePtr;
  Uart_ReturnType Retvalue = UART_OK;
  uint8 HwUnit;

 #if (UART_DEV_ERROR_DETECT != STD_ON)
  uint32 ChTxLock;
 #endif

   #if (UART_DEV_ERROR_DETECT == STD_ON)

   if (Uart_InitStatus == UART_UNINITIALISED)
   {
     /* If Uart is not initialised then report the DET */
     Det_ReportError(
                     UART_MODULE_ID,
                     UART_MODULE_INSTANCE,
                     UART_SID_WRITE,
                     UART_E_UNINIT
                    );
     Retvalue = UART_NOT_OK;
   }
   else if (MemPtr == NULL_PTR)
   {
     /* If the memory pointer passed is a Null Pointer report the DET */
     Det_ReportError(
                     UART_MODULE_ID,
                     UART_MODULE_INSTANCE,
                     UART_SID_WRITE,
                     UART_E_PARAM_POINTER
                    );
     Retvalue = UART_NOT_OK;
   }
   else if (Size == UART_ZERO_U )
   {
     /* If the parameter Size is equal to zero Report to  DET */
     Det_ReportError(
                     UART_MODULE_ID,
                     UART_MODULE_INSTANCE,
                     UART_SID_WRITE,
                     UART_E_INVALID_SIZE
                    );
     Retvalue = UART_NOT_OK;
   }
   else
   {
     /* If the channelId is Invalid Report to DET */
     Retvalue = Uart_lChannelCheck(Channel,UART_SID_WRITE);

     if (Retvalue == UART_OK)
     {
       if (Uart_ChannelInfo[Channel].Uart_TxState != UART_INITIALISED)
       {
        /* If the channel is Busy(Read/Write on-going) Report to  DET */
        Det_ReportError(
                        UART_MODULE_ID,
                        UART_MODULE_INSTANCE,
                        UART_SID_WRITE,
                        UART_E_STATE_TRANSITION
                       );
        Retvalue = UART_IS_BUSY;
       }
     }
   }
  #endif

  #if (UART_DEV_ERROR_DETECT == STD_ON)
   if (Retvalue == UART_OK)
  #else
   /* The Uart Write operation is already started for the channel. No other
      operation can be started on this Channel. This is implemented using a
      binary semaphore mechanism*/
   ChTxLock = Mcal_LockResource(&Uart_ChLock[UART_TX_LOCK_IDX][Channel]);

   /* No other Uart Write operation is in progress */
   if (ChTxLock == MCAL_RESOURCE_BUSY)
   {
        Retvalue = UART_IS_BUSY;
   }
   else
  #endif
   {
   /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
     ChannelConfigPtr to access the Configuration of Channel passed*/
   ChannelConfigPtr = &(Uart_kConfigPtr->ChannelConfigPtr[Channel]);
    /*Update driver state in Uart_ChannelInfo as Write Operation*/
   Uart_ChannelInfo[Channel].Uart_TxState= UART_OPERATION_IN_PROGRESS;

   /* Extract asssigned HWUnit module ptr */
   HwUnit = Uart_ChannelInfo[Channel].Uart_AssignedHW;
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
   UART_HW_MODULE to access the SFRs of a particular HW Unit*/
   HwModulePtr= &(UART_HW_MODULE[HwUnit]);

   /* Set TX FIFO Inlet width */
   UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->TXFIFOCON.U,\
              UART_TXFIFOCON_INW_CLEARMASK, UART_TXFIFOCONREG_INW_VAL << \
                                                      UART_TXFIFOCON_INW_BITPOS)
   /* Set TX Datalength */
   UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->DATCON.U,\
                                       UART_DATCON_DATLEN_CLEARMASK,\
                         ((uint32)ChannelConfigPtr->DataLength - UART_ONE_U))

   /*Update Tx BuffPtr,size in Uart_ChannelInfo for Write Operation*/
   Uart_ChannelInfo[Channel].Uart_TxBuffPtr= MemPtr;
   Uart_ChannelInfo[Channel].Uart_TxDataLeft = Size;
   Uart_ChannelInfo[Channel].Uart_TotalDataTxd = UART_ZERO_U;

   /* Flush TX FIFO */
    UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->TXFIFOCON.U,\
                              UART_TXFIFOCON_FLUSH_CLEARMASK, UART_ENABLE_BIT)

   /*local function to copy the Tx data to FIFO*/
   Uart_lWrite(HwModulePtr,Channel);

   /*Check if only one data needs to be txd*/
   if (Size == UART_ONE_U )
   {
     /*Clear the Tx Complete flag*/
     UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->FLAGSCLEAR.U,\
                                          UART_FLAGSCLEAR_TCC_CLEARMASK,\
                        ((uint32)UART_ENABLE_BIT << UART_FLAGSCLEAR_TCC_BITPOS))
     /*Enable the Tx Complete flag*/
     UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->FLAGSENABLE.U,\
                                         UART_FLAGSENABLE_TCE_CLEARMASK,\
                       ((uint32)UART_ENABLE_BIT << UART_FLAGSENABLE_TCE_BITPOS))
     Uart_ChannelInfo[Channel].Uart_TotalDataTxd = UART_ONE_U;
   }
   else
   {
     /*Enable Tx and Err Interrupts*/
     Uart_lEnableWriteInterrupts(HwModulePtr, UART_RUNTIME_ACCESS);
     Uart_lHwEnableAscLinTxIntr(HwUnit);
   }

   Uart_lHwEnableAscLinErrIntr(HwUnit);

   /*Enable the Tx FIFO*/
   UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->TXFIFOCON.U,\
     UART_TXFIFOCON_ENO_CLEARMASK, UART_ENABLE_BIT << UART_TXFIFOCON_ENO_BITPOS)
  }
  return Retvalue;
}
/*******************************************************************************
** Syntax : static void Uart_lWrite                                           **
**  (                                                                         **
**    Ifx_ASCLIN* HwModulePtr,Uart_ChannelIdType Channel                      **
**  )                                                                         **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:      reentrant                                                 **
**                                                                            **
** Parameters (in): Channel - Uart channel to be addressed                    **
**                  HwModulePtr - Asclin Hardware Pointer                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : local function to copy the transmit data from specified      **
**               memory location(App buffer) to TX FIFO Buffer                **
*******************************************************************************/
static void Uart_lWrite(Ifx_ASCLIN* HwModulePtr,Uart_ChannelIdType Channel)
{
  Uart_MemPtrType BuffPtr;
  uint16 Write_Count =UART_ZERO_U;
  uint8 Uartdata = UART_ZERO_U;
  uint8 UartDatalen ;

  BuffPtr = Uart_ChannelInfo[Channel].Uart_TxBuffPtr;
  Uart_ChannelInfo[Channel].Uart_TxDataCopyCntr = UART_ZERO_U;

  if (Uart_ChannelInfo[Channel].Uart_TxDataLeft == UART_STEPSIZE)
  {
     /*Set the Write byte Count to copy the last data*/
    Write_Count = UART_STEPSIZE;
  }
  else if (Uart_ChannelInfo[Channel].Uart_TxDataLeft <= UART_BUFFER_SIZE)
  {
    /*Set the Write byte Count to copy the Data left minus last data*/
    Write_Count = (Uart_ChannelInfo[Channel].Uart_TxDataLeft - UART_STEPSIZE);
  }
  else
  {
   /*Set the data copy  byte Count to Tx Fifo Buff Size */
    Write_Count = UART_BUFFER_SIZE;
  }

  while (Write_Count > UART_ZERO_U)
  {
     UartDatalen = ((uint8)(UART_SFR_RUNTIME_USER_MODE_READ32\
               (HwModulePtr->DATCON.U) & UART_DATCON_DATLEN_MASK) + UART_ONE_U);

   /*Check if the data to Write is the last one and datalen is 7/8*/
     if ((Uart_ChannelInfo[Channel].Uart_TxDataLeft == UART_ONE_U) &&\
                        (UartDatalen !=UART_NINEBIT_DATLEN))
     {
       /* Set TX FIFO Inlet width to One as one byte TX data is there*/
       UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->TXFIFOCON.U,\
         UART_TXFIFOCON_INW_CLEARMASK, UART_ONE_U << UART_TXFIFOCON_INW_BITPOS)

       /*Copy the data from the mem to Tx FIFO buffer*/
       Uartdata = *((uint8*)(void*)BuffPtr) ;
       UART_SFR_RUNTIME_USER_MODE_WRITE32(HwModulePtr->TXDATA.U, Uartdata);
       /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
        BuffPtr to access next element of Application Data Buffer*/
       BuffPtr++;

     /*Reset Data Copy counter and Tx Data left cntr to one as Tx is complete*/
       Uart_ChannelInfo[Channel].Uart_TxDataLeft = UART_ZERO_U;
       Uart_ChannelInfo[Channel].Uart_TxDataCopyCntr += UART_ONE_U;

       /* Reset Write count as Tx is complete*/
       Write_Count = UART_ZERO_U;
     }
     else
     {
       /*Copy the data from the mem to Tx FIFO buffer*/
       UART_SFR_RUNTIME_USER_MODE_WRITE32(HwModulePtr->TXDATA.U, *( BuffPtr));
       /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
        BuffPtr to access next element of Application Data Buffer*/
       BuffPtr++;

   /*Decrement TxData Left Cntr and increment TxData Copy cntr by step size*/
       Uart_ChannelInfo[Channel].Uart_TxDataLeft -= UART_STEPSIZE;
       Uart_ChannelInfo[Channel].Uart_TxDataCopyCntr += UART_STEPSIZE;

       /*Decrement the Data copy counter by step size(i.e. one Data Count)*/
       Write_Count = Write_Count - UART_STEPSIZE;
     }
  }

  Uart_ChannelInfo[Channel].Uart_TxBuffPtr = BuffPtr;
  return ;
}

/*******************************************************************************
** Syntax : static void Uart_lEnableWriteInterrupts                           **
**                   ( Ifx_ASCLIN* HwModulePtr,uint8 ApiAccessId)             **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:      reentrant                                                 **
**                                                                            **
** Parameters (in):   HwModulePtr - Asclin Hardware Pointer                   **
**                :   ApiAccessId - API Access type                           **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Local function to Enable Interrupts for Write Operation      **
**                                                                            **
*******************************************************************************/
static void Uart_lEnableWriteInterrupts(Ifx_ASCLIN* HwModulePtr,\
                                                             uint8 ApiAccessId)
{
#if ((UART_USER_MODE_RUNTIME_API_ENABLE == STD_ON) && \
                                 (UART_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON))
  if (ApiAccessId == UART_RUNTIME_ACCESS)
  {
    /*Set Tx FIFO Int level and Enable Tx FIFO overflow and Level flags*/
    UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->TXFIFOCON.U,\
                               UART_TXFIFOCON_INTLEVEL_CLEARMASK, UART_ZERO_U)

    UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->FLAGSENABLE.U,\
                                       UART_FLAGSENABLE_TFLE_CLEARMASK,\
                      ((uint32)UART_ENABLE_BIT << UART_FLAGSENABLE_TFLE_BITPOS))

    UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->FLAGSENABLE.U,\
                                        UART_FLAGSENABLE_TFOE_CLEARMASK,\
                      ((uint32)UART_ENABLE_BIT << UART_FLAGSENABLE_TFOE_BITPOS))
  }
  else
#endif
  {
    /*Set Tx FIFO Int level and Enable Tx FIFO overflow and Level flags*/
    HwModulePtr->TXFIFOCON.U = (unsigned_int)((HwModulePtr->TXFIFOCON.U &\
                              UART_TXFIFOCON_INTLEVEL_CLEARMASK) | UART_ZERO_U);

    HwModulePtr->FLAGSENABLE.U = (unsigned_int)((HwModulePtr->FLAGSENABLE.U &\
                                       UART_FLAGSENABLE_TFLE_CLEARMASK) |\
               ((unsigned_int)UART_ENABLE_BIT << UART_FLAGSENABLE_TFLE_BITPOS));

    HwModulePtr->FLAGSENABLE.U = (unsigned_int)((HwModulePtr->FLAGSENABLE.U &\
                                        UART_FLAGSENABLE_TFOE_CLEARMASK) |\
               ((unsigned_int)UART_ENABLE_BIT << UART_FLAGSENABLE_TFOE_BITPOS));
  }
#if ((UART_USER_MODE_RUNTIME_API_ENABLE == STD_OFF) || \
                               (UART_RUNNING_IN_USER_0_MODE_ENABLE == STD_OFF))
    UNUSED_PARAMETER(ApiAccessId)
#endif
}
/*******************************************************************************
** Syntax : static void Uart_lClearWriteInterrupts                            **
**                   ( Ifx_ASCLIN* HwModulePtr,uint8 ApiAccessId)             **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:      reentrant                                                 **
**                                                                            **
** Parameters (in):   HwModulePtr - Asclin Hardware Pointer                   **
**                    ApiAccessId - Describes the API access type             **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Local function to Disable Interrupts for Write operation     **
**                                                                            **
*******************************************************************************/
static void Uart_lClearWriteInterrupts(Ifx_ASCLIN* HwModulePtr,\
                                                              uint8 ApiAccessId)
{
  #if (UART_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  #if (UART_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
  if (ApiAccessId == UART_RUNTIME_ACCESS)
  {
    /*Clear Tx FIFO overflow and Level flags*/
    UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->FLAGSCLEAR.U,\
                   UART_FLAGSCLEAR_TFLC_CLEARMASK,(uint32)UART_ENABLE_BIT <<\
                                                    UART_FLAGSCLEAR_TFLC_BITPOS)
    
    UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->FLAGSCLEAR.U,\
                 UART_FLAGSCLEAR_TFOC_CLEARMASK,((uint32)UART_ENABLE_BIT <<\
                                                   UART_FLAGSCLEAR_TFOC_BITPOS))
  }
  else
  #endif /*(UART_USER_MODE_RUNTIME_API_ENABLE == STD_ON)*/
  #if (UART_USER_MODE_DEINIT_API_ENABLE == STD_ON)
  if (ApiAccessId == UART_DEINIT_ACCESS)  
  {  
    /*Clear Tx FIFO overflow and Level flags*/
    UART_SFR_DEINIT_USER_MODE_MODIFY32(HwModulePtr->FLAGSCLEAR.U,\
                   UART_FLAGSCLEAR_TFLC_CLEARMASK,(uint32)UART_ENABLE_BIT <<\
                                                   UART_FLAGSCLEAR_TFLC_BITPOS)
  
    UART_SFR_DEINIT_USER_MODE_MODIFY32(HwModulePtr->FLAGSCLEAR.U,\
                 UART_FLAGSCLEAR_TFOC_CLEARMASK,((uint32)UART_ENABLE_BIT <<\
                                                  UART_FLAGSCLEAR_TFOC_BITPOS))
  }
  else
  #endif /*(UART_USER_MODE_DEINIT_API_ENABLE == STD_ON)*/
  #endif /*(UART_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)*/
  {
    HwModulePtr->FLAGSCLEAR.U = (unsigned_int)((HwModulePtr->FLAGSCLEAR.U &\
          UART_FLAGSCLEAR_TFLC_CLEARMASK) | ((unsigned_int)UART_ENABLE_BIT <<\
                                                 UART_FLAGSCLEAR_TFLC_BITPOS));
    HwModulePtr->FLAGSCLEAR.U = (unsigned_int)((HwModulePtr->FLAGSCLEAR.U &\
         UART_FLAGSCLEAR_TFOC_CLEARMASK) | ((unsigned_int)UART_ENABLE_BIT <<\
                                                  UART_FLAGSCLEAR_TFOC_BITPOS));
  }
  #if((UART_RUNNING_IN_USER_0_MODE_ENABLE == STD_OFF) || \
   ((UART_USER_MODE_RUNTIME_API_ENABLE == STD_OFF) && \
   (UART_USER_MODE_DEINIT_API_ENABLE == STD_OFF)))
   UNUSED_PARAMETER(ApiAccessId)
   #endif
}

 #if (UART_ABORT_READ_API == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_UART_PR1573,DS_NAS_UART_PR63_10]     **
** Syntax : Uart_SizeType Uart_AbortRead( Uart_ChannelIdType Channel )        **
**              [/cover]                                                      **
** Service ID:  0x04                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant  (Not for the same channel)                         **
**                                                                            **
** Parameters (in): Channel - Uart channel to be addressed                    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value  : UartRetSize - Number of bytes that have been successfully  **
**                               recieved and stored to the memory location   **
**                               before the read operation was aborted        **
** Description : Api to Abort the read operation on the specified channel     **
**                                                                            **
*******************************************************************************/
Uart_SizeType Uart_AbortRead(Uart_ChannelIdType  Channel)
{
  Ifx_ASCLIN* HwModulePtr;
  const Uart_ChannelType *ChannelConfigPtr;
  Uart_SizeType UartRetSize = UART_ZERO_U ;
  uint8 HwUnit;

  #if (UART_DEV_ERROR_DETECT == STD_ON)
  Uart_ReturnType Retvalue = UART_OK;

  if (Uart_InitStatus == UART_UNINITIALISED)
  {
    /* If uart is not uninitialised Report to  DET */
    Det_ReportError(
                    UART_MODULE_ID,
                    UART_MODULE_INSTANCE,
                    UART_SID_ABORT_READ,
                    UART_E_UNINIT
                   );
    Retvalue = UART_NOT_OK;
    UartRetSize = UART_ZERO_U ;
  }
  else
  {
    /* If the channelId is Invalid Report to DET */
    Retvalue = Uart_lChannelCheck(Channel,UART_SID_ABORT_READ);
    UartRetSize = UART_ZERO_U ;
  }
  #endif

  #if (UART_DEV_ERROR_DETECT == STD_ON)
  if (Retvalue == UART_OK)
  #else
   /* Release the lock so that New Uart Read Operation can be started*/
  Mcal_UnlockResource(&Uart_ChLock[UART_RX_LOCK_IDX][Channel]);
  #endif
  {
    HwUnit = Uart_ChannelInfo[Channel].Uart_AssignedHW;
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
   UART_HW_MODULE to access the SFRs of a particular HW Unit*/
    HwModulePtr= &(UART_HW_MODULE[HwUnit]);

    /*Disable RxFIFO and flush It*/
    UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->RXFIFOCON.U,\
                             UART_RXFIFOCON_ENI_CLEARMASK, UART_DISABLE_BIT)
    UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->RXFIFOCON.U,\
                          UART_RXFIFOCON_FLUSH_CLEARMASK, UART_ENABLE_BIT)

    /*Clear Rx overflow and level Interrupts*/
    Uart_lClearReadInterrupts(HwModulePtr, UART_RUNTIME_ACCESS);

    /*Disable Rx and Err Interrupts*/
    Uart_lHwDisableAscLinRxIntr(HwUnit, UART_RUNTIME_ACCESS);
    Uart_lHwDisableAscLinErrIntr(HwUnit, UART_RUNTIME_ACCESS);

    /*Return Total Data Rxd before Read operation was Aborted */
    UartRetSize = Uart_ChannelInfo[Channel].Uart_TotalDataRxd;

   /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
     ChannelConfigPtr to access the Configuration of Channel passed*/
    ChannelConfigPtr = &(Uart_kConfigPtr->ChannelConfigPtr[Channel]);
   /*Reinitialise the HW Unit*/
    Uart_lHwInitRuntime(HwUnit, ChannelConfigPtr);

    /*Reset Uart_ChannelInfo*/
    Uart_ChannelInfo[Channel].Uart_RxState = UART_INITIALISED;
    Uart_ChannelInfo[Channel].Uart_RxBuffPtr = NULL_PTR;

    /*Reset Data Rxd Counter*/
    Uart_ChannelInfo[Channel].Uart_TotalDataRxd = UART_ZERO_U;

    if(ChannelConfigPtr->UartNotif.UartAbortReceiveNotifPtr != NULL_PTR)
    {
      /*Call Abort Receive Notification Function*/
      ChannelConfigPtr->UartNotif.UartAbortReceiveNotifPtr(UART_NO_ERR);
    }
  }
  return UartRetSize ;
}
#endif

#if (UART_ABORT_WRITE_API == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_UART_PR1574,DS_NAS_UART_PR63_11]     **
** Syntax : Uart_SizeType Uart_AbortWrite( Uart_ChannelIdType Channel )       **
**            [/cover]                                                        **
** Service ID:  0x05                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant  (Not for the same channel)                         **
**                                                                            **
** Parameters (in): Channel - Uart channel to be addressed                    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value  : UartRetSize - Number of bytes that have been successfully  **
**                       transmitted before the write operation was aborted   **
**                                                                            **
** Description : Api to Abort Transmission of data on the specified channel   **
**                                                                            **
*******************************************************************************/
Uart_SizeType Uart_AbortWrite(Uart_ChannelIdType Channel)
{
  Ifx_ASCLIN* HwModulePtr;
  const Uart_ChannelType *ChannelConfigPtr;
  Uart_SizeType UartRetSize = UART_ZERO_U;
  uint16 tempsum;
  uint8 HwUnit;

   #if (UART_DEV_ERROR_DETECT == STD_ON)
   Uart_ReturnType Retvalue;
   #endif

  #if (UART_DEV_ERROR_DETECT == STD_ON)
  if (Uart_InitStatus == UART_UNINITIALISED)
  {
    /* Report to  DET */
    Det_ReportError(
                    UART_MODULE_ID,
                    UART_MODULE_INSTANCE,
                    UART_SID_ABORT_WRITE,
                    UART_E_UNINIT
                   );
    Retvalue = UART_NOT_OK;
    UartRetSize = UART_ZERO_U;
  }
  else
  {
    /* If the channelId is Invalid Report to DET */
    Retvalue = Uart_lChannelCheck(Channel,UART_SID_ABORT_WRITE);
    UartRetSize = UART_ZERO_U;
  }

  if (Retvalue == UART_OK)
  #else
   /* Release the lock so that New Uart Write Operation can be started*/
  Mcal_UnlockResource(&Uart_ChLock[UART_TX_LOCK_IDX][Channel]);
  #endif
  {

   /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
     ChannelConfigPtr to access the Configuration of Channel passed*/
    ChannelConfigPtr = &(Uart_kConfigPtr->ChannelConfigPtr[Channel]);
    HwUnit = Uart_ChannelInfo[Channel].Uart_AssignedHW;
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
   UART_HW_MODULE to access the SFRs of a particular HW Unit*/
    HwModulePtr= &(UART_HW_MODULE[HwUnit]);

    /*Disable TxFIFO*/
    UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->TXFIFOCON.U,\
                              UART_TXFIFOCON_ENO_CLEARMASK, UART_DISABLE_BIT)

   if((Uart_ChannelInfo[Channel].Uart_TxState == UART_INITIALISED) &&\
         (Uart_ChannelInfo[Channel].Uart_TxDataLeft == UART_ZERO_U))
    {
       /*Reset Txd Data Fill to zero*/
       Uart_ChannelInfo[Channel].Uart_TxDataCopyCntr = UART_ZERO_U;
    }

    /*Return the Count of Data Txd before the write operation was aborted*/
    tempsum =(uint16)Uart_ChannelInfo[Channel].Uart_TxDataCopyCntr -\
        ((uint16)((UART_SFR_RUNTIME_USER_MODE_READ32(HwModulePtr->TXFIFOCON.U)\
                   & UART_TXFIFOCON_FILL_MASK) >> UART_TXFIFOCON_FILL_BITPOS));
    Uart_ChannelInfo[Channel].Uart_TotalDataTxd += tempsum;

    UartRetSize = Uart_ChannelInfo[Channel].Uart_TotalDataTxd;

   /*Flush TxFIFO*/
    UART_SFR_RUNTIME_USER_MODE_MODIFY32(HwModulePtr->TXFIFOCON.U,\
                             UART_TXFIFOCON_FLUSH_CLEARMASK, UART_ENABLE_BIT )

   /*Clear Tx overflow and level Interrupts*/
    Uart_lClearWriteInterrupts(HwModulePtr, UART_RUNTIME_ACCESS);

   /*Disable Tx and Err Interrupts*/
    Uart_lHwDisableAscLinTxIntr(HwUnit, UART_RUNTIME_ACCESS);
    Uart_lHwDisableAscLinErrIntr(HwUnit, UART_RUNTIME_ACCESS);

   /*Reinitialise the HW Unit*/
    Uart_lHwInitRuntime(HwUnit, ChannelConfigPtr);

   /*Reset Uart_ChannelInfo*/
    Uart_ChannelInfo[Channel].Uart_TxBuffPtr = NULL_PTR;
    Uart_ChannelInfo[Channel].Uart_TxState = UART_INITIALISED;
    Uart_ChannelInfo[Channel].Uart_TotalDataTxd = UART_ZERO_U;
    Uart_ChannelInfo[Channel].Uart_TxDataCopyCntr = UART_ZERO_U;

    if(ChannelConfigPtr->UartNotif.UartAbortTransmitNotifPtr != NULL_PTR)
    {
      /*Call Abort Transmit Notification Function*/
      ChannelConfigPtr->UartNotif.UartAbortTransmitNotifPtr(UART_NO_ERR);
    }
   }
  return UartRetSize;
}
#endif

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_UART_PR1575,DS_NAS_UART_PR63_12]     **
** Syntax : Uart_StatusType Uart_GetStatus(Uart_ChannelIdType Channel)        **
**            [/cover]                                                        **
** Service ID:      0x06                                                      **
**                                                                            **
** Sync/Async:      Synchronous                                               **
**                                                                            **
** Reentrancy:      Re-entrant                                                **
**                                                                            **
** Parameters (in): Channel    : Uart channel to be addressed                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:                                                              **
**                  UART_BUSY : Uart channel is busy with transmission        **
**                                    or Reception operation                  **
**                  UART_IDLE : Uart channel is currently free to use         **
**                                                                            **
**                  UART_UNINIT: Uart channel is not uninitialised            **
**                                                                            **
** Description :    Indicates the current driver status for the UART channel  **
**                                                                            **
*******************************************************************************/
Uart_StatusType Uart_GetStatus(Uart_ChannelIdType Channel)
{
  Uart_StatusType UartDriverState = UART_UNINIT;

  #if (UART_DEV_ERROR_DETECT == STD_ON)
  Uart_ReturnType Retvalue = UART_OK;

  /*Check for driver initialisation */
  if (Uart_InitStatus == UART_UNINITIALISED)
  {
    Det_ReportError(
                    UART_MODULE_ID,
                    UART_MODULE_INSTANCE,
                    UART_SID_GETSTATUS,
                    UART_E_UNINIT
                   );

    Retvalue = UART_NOT_OK;

    UartDriverState = UART_UNINIT;
  }
  else
  {
     /* If the channelId is Invalid Report to DET */
    Retvalue = Uart_lChannelCheck(Channel,UART_SID_GETSTATUS);

    UartDriverState = UART_BUSY;
  }

  if (Retvalue == UART_OK)
  #endif
  {
   /*Return state as BUSY if channel is busy with Read or Write Operation*/

    if((Uart_ChannelInfo[Channel].Uart_TxState == UART_OPERATION_IN_PROGRESS) \
     ||( Uart_ChannelInfo[Channel].Uart_RxState == UART_OPERATION_IN_PROGRESS))
    {
      UartDriverState = UART_BUSY;
    }
    else if (( Uart_ChannelInfo[Channel].Uart_TxState == UART_INITIALISED)\
     &&( Uart_ChannelInfo[Channel].Uart_RxState == UART_INITIALISED))
    {
      UartDriverState = UART_IDLE;
    }
    else
    {
      UartDriverState = UART_UNINIT;
    }
  }

  return UartDriverState;
}


/*******************************************************************************
** Syntax :          void Uart_IsrReceive( uint8  HwUnit)                     **
**                                                                            **
** Service ID:       NA                                                       **
**                                                                            **
** Sync/Async:       Asynchronous                                             **
**                                                                            **
** Reentrancy:  Reentrant  (Not for the same HW Unit)                         **
**                                                                            **
** Parameters (in):  HwUnit : Represents ASCLIN hw module number              **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     This ISR will be called whenever  data                   **
**                   is completely received by the ASCLIN w/o any errors      **
*******************************************************************************/
void Uart_IsrReceive(uint8  HwUnit)
{
  const Uart_ChannelType *ChannelConfigPtr;
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
   UART_HW_MODULE to access the SFRs of a particular HW Unit*/
  Ifx_ASCLIN* HwModulePtr= &(UART_HW_MODULE[HwUnit]);
  Uart_ChannelIdType Channel;

  /* Extract the Channel */
  Channel = Uart_BusChannelMap[HwUnit];
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
    ChannelConfigPtr to access the Configuration of Channel passed*/
  ChannelConfigPtr = &(Uart_kConfigPtr->ChannelConfigPtr[Channel]);

  /* Local fnt to read the Data from Rx FIFO */
  Uart_lRead(HwModulePtr,Channel);

  if (Uart_ChannelInfo[Channel].Uart_RxDataLeft == UART_ZERO_U)
  {
    /*Flush RxFIFO*/
    HwModulePtr->RXFIFOCON.U = ((HwModulePtr->RXFIFOCON.U &\
                            UART_RXFIFOCON_FLUSH_CLEARMASK) | UART_ENABLE_BIT);

    /*Clear Rx Overflow and Level Interrupts*/
    Uart_lClearReadInterrupts(HwModulePtr, UART_ISR_ACCESS);

    /*Disable Rx FIFO*/
    HwModulePtr->RXFIFOCON.U = ((HwModulePtr->RXFIFOCON.U &\
                            UART_RXFIFOCON_ENI_CLEARMASK) | UART_DISABLE_BIT);

    /*Disable Rx Interrupt*/
    Uart_lHwDisableAscLinRxIntr(HwUnit, UART_ISR_ACCESS);

    /* Release the lock so that other Uart Read Operation can be started*/
    Mcal_UnlockResource(&Uart_ChLock[UART_RX_LOCK_IDX][Channel]);

    Uart_ChannelInfo[Channel].Uart_RxBuffPtr = NULL_PTR;
    Uart_ChannelInfo[Channel].Uart_RxState = UART_INITIALISED;

    if(ChannelConfigPtr->UartNotif.UartReceiveNotifPtr != NULL_PTR)
    {
      /*Call the Receive Notification Function*/
      ChannelConfigPtr->UartNotif.UartReceiveNotifPtr(UART_NO_ERR);
    }
    else
    {
     /* Do Nothing */
    }
  }
  return ;
}

/*******************************************************************************
** Syntax :          void Uart_IsrTransmit( uint8  HwUnit)                    **
**                                                                            **
** Service ID:       NA                                                       **
**                                                                            **
** Sync/Async:       Asynchronous                                             **
**                                                                            **
** Reentrancy:  Reentrant  (Not for the same HW Unit)                         **
**                                                                            **
** Parameters (in):  HwUnit : Represents Hw Module number                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     This ISR will be called whenever the data                **
**                   is successfully transmitted by the ASCLIN w/o any errors **
**                                                                            **
*******************************************************************************/
void Uart_IsrTransmit(uint8  HwUnit)
{
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
   UART_HW_MODULE to access the SFRs of a particular HW Unit*/
  Ifx_ASCLIN* HwModulePtr = &(UART_HW_MODULE[HwUnit]);
  uint16 Tempsum;
  Uart_ChannelIdType Channel;

  /* Extract the Channel */
  Channel = Uart_BusChannelMap[HwUnit];
  Tempsum = (uint16)(Uart_ChannelInfo[Channel].Uart_TxDataCopyCntr -\
     ((uint16) ((HwModulePtr->TXFIFOCON.U & UART_TXFIFOCON_FILL_MASK) >>\
                                                  UART_TXFIFOCON_FILL_BITPOS)));

  Uart_ChannelInfo[Channel].Uart_TotalDataTxd += Tempsum;

  if ( Uart_ChannelInfo[Channel].Uart_TxDataLeft == UART_ZERO_U)
   {
     /*Clear the transmission complete flag*/
     HwModulePtr->FLAGSCLEAR.U = (unsigned_int)((HwModulePtr->FLAGSCLEAR.U &
            UART_FLAGSCLEAR_TCC_MASK) | ((unsigned_int)UART_ENABLE_BIT <<\
                                                   UART_FLAGSCLEAR_TCC_BITPOS));

     /*Clear all write interrupts */
     Uart_lClearWriteInterrupts(HwModulePtr, UART_ISR_ACCESS);

     /*Disable the Tx Overflow and Level Interrupt*/
     HwModulePtr->FLAGSENABLE.U = ((HwModulePtr->FLAGSENABLE.U &\
                            UART_FLAGSENABLE_TFLE_MASK) | UART_DISABLE_BIT);

     HwModulePtr->FLAGSENABLE.U = ((HwModulePtr->FLAGSENABLE.U\
                            & UART_FLAGSENABLE_TFOE_MASK) | UART_DISABLE_BIT);

     /*Disable Tx Interrupts*/
     Uart_lHwDisableAscLinTxIntr(HwUnit, UART_ISR_ACCESS);

     Uart_ChannelInfo[Channel].Uart_TxBuffPtr = NULL_PTR;
     Uart_ChannelInfo[Channel].Uart_TxDataCopyCntr = UART_ZERO_U;
   }
   else
   {
     /*Clear the transmission complete flag*/
     HwModulePtr->FLAGSCLEAR.U = (unsigned_int)((HwModulePtr->FLAGSCLEAR.U &
            UART_FLAGSCLEAR_TCC_MASK) | ((unsigned_int)UART_ENABLE_BIT <<\
                                                   UART_FLAGSCLEAR_TCC_BITPOS));

     if(Uart_ChannelInfo[Channel].Uart_TxDataLeft == UART_STEPSIZE)
     {
       /* Enable the transmission complete interrupt
       for the last data transmission*/
       HwModulePtr->FLAGSENABLE.U = (unsigned_int)((HwModulePtr->FLAGSENABLE.U &
           UART_FLAGSENABLE_TCE_MASK) | ((unsigned_int)UART_ENABLE_BIT <<\
                                                   UART_FLAGSCLEAR_TCC_BITPOS));
     }

     /*Disable TxFIFO*/
     HwModulePtr->TXFIFOCON.U = ((HwModulePtr->TXFIFOCON.U &\
                                 UART_TXFIFOCON_ENO_MASK) | UART_DISABLE_BIT);

     /*Clear Tx Overflow and Level Interrupt*/
     Uart_lClearWriteInterrupts(HwModulePtr, UART_ISR_ACCESS);

     /* Write the Data to Tx FIFO */
     Uart_lWrite(HwModulePtr,Channel);

     /*Enable the Tx Overflow and Level Interrupt*/
     Uart_lEnableWriteInterrupts(HwModulePtr, UART_ISR_ACCESS);

     /*Enable TxFIFO*/
     HwModulePtr->TXFIFOCON.U = (unsigned_int)((HwModulePtr->TXFIFOCON.U &\
              UART_TXFIFOCON_ENO_MASK) | ((unsigned_int)UART_ENABLE_BIT <<\
                                                    UART_TXFIFOCON_ENO_BITPOS));
   }
  return ;
}

/*******************************************************************************
** Syntax :          void Uart_IsrError( uint8  HwUnit)                       **
**                                                                            **
** Service ID:       NA                                                       **
**                                                                            **
** Sync/Async:       Asynchronous                                             **
**                                                                            **
** Reentrancy:  Reentrant  (Not for the same HW Unit)                         **
**                                                                            **
** Parameters (in):  HwUnit : Represents Hw Module number                     **
**                                                                            **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     This ISR will be called whenever there is data           **
**                   transmission or reception error on ASCLINx HW Unit       **
*******************************************************************************/
void Uart_IsrError(uint8 HwUnit)
{
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
   UART_HW_MODULE to access the SFRs of a particular HW Unit*/
  Ifx_ASCLIN* HwModulePtr= &(UART_HW_MODULE[HwUnit]);
  const Uart_ChannelType *ChannelConfigPtr;
  Uart_ErrorIdType ErrId = UART_NO_ERR;
  uint8 Channel = Uart_BusChannelMap[HwUnit];

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
    ChannelConfigPtr to access the Configuration of Channel passed*/
  ChannelConfigPtr = &(Uart_kConfigPtr->ChannelConfigPtr[Channel]);

  /* Check parity error*/
  if (((HwModulePtr->FLAGS.U & UART_FLAGS_PE_MASK) >> UART_FLAGS_PE_BITPOS) ==\
                                                                    UART_ONE_U)
  {
    HwModulePtr->FLAGSCLEAR.U = (unsigned_int)((HwModulePtr->FLAGSCLEAR.U &\
                 UART_FLAGSCLEAR_PEC_MASK) | ((unsigned_int)UART_ONE_U <<\
                                                   UART_FLAGSCLEAR_PEC_BITPOS));
    ErrId = UART_PARITY_ERR;
  }
  /* Check framing error*/
  else if(((HwModulePtr->FLAGS.U & UART_FLAGS_FE_MASK) >> UART_FLAGS_FE_BITPOS)\
                                                                  == UART_ONE_U)
  {
    HwModulePtr->FLAGSCLEAR.U = (unsigned_int)((HwModulePtr->FLAGSCLEAR.U &\
                 UART_FLAGSCLEAR_FEC_MASK) | ((unsigned_int)UART_ONE_U <<\
                                                   UART_FLAGSCLEAR_FEC_BITPOS));
    ErrId = UART_FRAME_ERR;
  }
   /* Check TxFIFO Overflow error*/
  else if(((HwModulePtr->FLAGS.U & UART_FLAGS_TFO_MASK) >>\
                                           UART_FLAGS_TFO_BITPOS) == UART_ONE_U)
  {
    HwModulePtr->FLAGSCLEAR.U = (unsigned_int)((HwModulePtr->FLAGSCLEAR.U &\
                UART_FLAGSCLEAR_TFOC_MASK) | ((unsigned_int)UART_ONE_U <<\
                                                UART_FLAGSCLEAR_TFOC_BITPOS));
    ErrId = UART_TXOVERFLOW_ERR;
  }
    /* Check RxFIFO Overflow error*/
  else if(((HwModulePtr->FLAGS.U & UART_FLAGS_RFO_MASK) >>\
                                           UART_FLAGS_RFO_BITPOS) == UART_ONE_U)
  {
    HwModulePtr->FLAGSCLEAR.U = (unsigned_int)((HwModulePtr->FLAGSCLEAR.U &\
                UART_FLAGSCLEAR_RFOC_MASK) | ((unsigned_int)UART_ONE_U <<\
                                                  UART_FLAGSCLEAR_RFOC_BITPOS));
    ErrId = UART_RXOVERFLOW_ERR;
  }
   /* Check RxFIFO Underflow error*/
  else if(((HwModulePtr->FLAGS.U & UART_FLAGS_RFU_MASK) >> \
                                           UART_FLAGS_RFU_BITPOS) == UART_ONE_U)
  {
    HwModulePtr->FLAGSCLEAR.U = (unsigned_int)((HwModulePtr->FLAGSCLEAR.U &\
                UART_FLAGSCLEAR_RFUC_MASK) | ((unsigned_int)UART_ONE_U <<\
                                                  UART_FLAGSCLEAR_RFUC_BITPOS));
    ErrId = UART_RXUNDERFLOW_ERR;
  }
    /* Check Tx Complete */
  else if(((HwModulePtr->FLAGS.U & UART_FLAGS_TC_MASK) >> UART_FLAGS_TC_BITPOS)\
                                                                == UART_ONE_U)
  {
    /* Disable TxFIFO */
    HwModulePtr->TXFIFOCON.U = ((HwModulePtr->TXFIFOCON.U &\
                                UART_TXFIFOCON_ENO_MASK) | UART_DISABLE_BIT);

    /* Clear Transmit complete */
    HwModulePtr->FLAGSCLEAR.U = (unsigned_int)((HwModulePtr->FLAGSCLEAR.U &\
            UART_FLAGSCLEAR_TCC_MASK) | ((unsigned_int)UART_ENABLE_BIT <<\
                                                   UART_FLAGSCLEAR_TCC_BITPOS));

    ErrId = UART_NO_ERR;

    /* Disable Tx complete interrupt */
    HwModulePtr->FLAGSENABLE.U = ((HwModulePtr->FLAGSENABLE.U &\
                               UART_FLAGSENABLE_TCE_MASK) | UART_DISABLE_BIT);

    /* Flush TxFIFO */
    HwModulePtr->TXFIFOCON.U = ((HwModulePtr->TXFIFOCON.U &\
                               UART_TXFIFOCON_FLUSH_MASK) | UART_ENABLE_BIT);

    /* Disable Err interrupts */
    Uart_lHwDisableAscLinErrIntr(HwUnit, UART_ISR_ACCESS);
  }
  else
  {
     /* Do Nothing */
  }

  /*Call Notification fnt*/
  if ((ErrId == UART_PARITY_ERR)||(ErrId == UART_FRAME_ERR)\
   ||(ErrId == UART_RXOVERFLOW_ERR)||(ErrId == UART_RXUNDERFLOW_ERR))
  {
    /* Release the lock so that other Uart Read Operation can be started*/
    Mcal_UnlockResource(&Uart_ChLock[UART_RX_LOCK_IDX][Channel]);

    Uart_ChannelInfo[Channel].Uart_RxState = UART_INITIALISED;

    if(ChannelConfigPtr->UartNotif.UartReceiveNotifPtr != NULL_PTR)
    {
      /*Call Receive Notification Function*/
      ChannelConfigPtr->UartNotif.UartReceiveNotifPtr(ErrId);
    }
  }
  else
  {
     /* Do Nothing */
  }

  if ((ErrId == UART_TXOVERFLOW_ERR)||(ErrId == UART_NO_ERR))
  {
    /* Release the lock so that other Uart Write Operation can be started*/
    Mcal_UnlockResource(&Uart_ChLock[UART_TX_LOCK_IDX][Channel]);

    Uart_ChannelInfo[Channel].Uart_TxState = UART_INITIALISED;

    if(ChannelConfigPtr->UartNotif.UartTransmitNotifPtr != NULL_PTR)
    {
       /*Call Transmit Notification Function*/
      ChannelConfigPtr->UartNotif.UartTransmitNotifPtr(ErrId);
    }
  }
  else
  {
     /* Do Nothing */
  }

}
/*******************************************************************************
** Syntax : static Uart_ReturnType Uart_lChannelCheck                         **
**  (                                                                         **
**    Uart_ChannelIdType Channel,uint8 ApiId                                  **
**  )                                                                         **
**                                                                            **
** Service ID:    NA                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:      reentrant                                                 **
**                                                                            **
** Parameters (in): Channel - Uart channel to be addressed                    **
**                  ApiId - Service id of the Api which calls this function   **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : UART_OK / UART_NOT_OK                                    **
**                                                                            **
** Description : Local function to check whether channel is valid or not      **
**                                                                            **
*******************************************************************************/
#if (UART_DEV_ERROR_DETECT == STD_ON)
static Uart_ReturnType Uart_lChannelCheck(\
                                       Uart_ChannelIdType Channel,uint8 ApiId)
{
  uint8 MaxChannel;
  Uart_ReturnType Retvalue;

  MaxChannel = Uart_kConfigPtr->NoOfChannels;

  if(Channel < MaxChannel)
  {
    Retvalue = UART_OK;
  }
  else
  {
    /* If the channelid is invalid Report to  DET */

    Det_ReportError(
                    UART_MODULE_ID,
                    UART_MODULE_INSTANCE,
                    ApiId,
                    UART_E_INVALID_CHANNEL
                   );

    Retvalue = UART_NOT_OK;
  }

  return Retvalue;
}
#endif


/*******************************************************************************
** Syntax           :  static void Uart_lHwDisableAscLinErrIntr               **
**                      (uint8 HwUnit, uint8 ApiAccessId)                     **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit        : ASCLIN Hardware module no               **
                    : ApiAccessId   : API access type                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function clears and disables the  Err              **
**                    interrupts in SRC registers.                            **
*******************************************************************************/
static void Uart_lHwDisableAscLinErrIntr(volatile uint8 HwUnit,\
                                                              uint8 ApiAccessId)
{
  /* Ifx_SRC_SRCR_Bits IntrSrc; */
  uint32 Offset,IntrSrc;

  Offset = (uint32)HwUnit * UART_SRC_ADDROFFSET ;
  #if (UART_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  #if (UART_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
  if (ApiAccessId == UART_RUNTIME_ACCESS)
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
    UART_SRC_ASCLIN0ERRADDR to access the SRC register for HW Unit passed*/
    IntrSrc = UART_SFR_RUNTIME_USER_MODE_READ32\
                                          (*(UART_SRC_ASCLIN0ERRADDR + Offset));
  }
  else
  #endif /*(UART_USER_MODE_RUNTIME_API_ENABLE == STD_ON)*/
  #if (UART_USER_MODE_DEINIT_API_ENABLE == STD_ON)
  if (ApiAccessId == UART_DEINIT_ACCESS)
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
    UART_SRC_ASCLIN0ERRADDR to access the SRC register for HW Unit passed*/
    IntrSrc = UART_SFR_DEINIT_USER_MODE_READ32\
                                          (*(UART_SRC_ASCLIN0ERRADDR + Offset));
  }
  else
  #endif /*(UART_USER_MODE_DEINIT_API_ENABLE == STD_ON)*/
  #endif /*(UART_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)*/
  {
    /*IFX_MISRA_RULE_11_05_STATUS=Attempts to cast away volatile from
      UART_SRC_ASCLINxERRADDR to cast it for SFR access*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
    UART_SRC_ASCLIN0ERRADDR to access the SRC register for HW Unit passed*/
    IntrSrc = (*((volatile uint32 *)(void *)\
                                         (UART_SRC_ASCLIN0ERRADDR  + Offset)));
  }

  if (((IntrSrc & UART_SET_MASK_ENABLE_INTR)>>10U) == UART_BIT_SET)
  {
    #if (UART_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
    if (ApiAccessId == UART_RUNTIME_ACCESS)
    {
      /*Reserve bit access is ensured for SRC_ASCLIN0ERR register*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
      UART_SRC_ASCLIN0ERRADDR to access the SRC register for HW Unit passed*/
      /*IFX_MISRA_RULE_11_05_STATUS=Attempts to cast away volatile from
      UART_SRC_ASCLINxERRADDR to cast it for SFR access*/
      UART_SFR_RUNTIME_MODIFY32(*((volatile uint32 *)\
      (void *)(UART_SRC_ASCLIN0ERRADDR + Offset)), ~UART_CLR_MASK_DISABLE_INTR,\
                                               UART_SET_MASK_DISABLE_INTR)
    }
    else
    #endif /*(UART_USER_MODE_RUNTIME_API_ENABLE == STD_ON)*/
    #if (UART_USER_MODE_DEINIT_API_ENABLE == STD_ON)
    if (ApiAccessId == UART_DEINIT_ACCESS)
    {
      /*Reserve bit access is ensured for SRC_ASCLIN0ERR register*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
      UART_SRC_ASCLIN0ERRADDR to access the SRC register for HW Unit passed*/
      /*IFX_MISRA_RULE_11_05_STATUS=Attempts to cast away volatile from
      UART_SRC_ASCLINxERRADDR to cast it for SFR access*/
      UART_SFR_DEINIT_MODIFY32(*((volatile uint32 *)\
      (void *)(UART_SRC_ASCLIN0ERRADDR + Offset)), ~UART_CLR_MASK_DISABLE_INTR,\
                                               UART_SET_MASK_DISABLE_INTR)
    }
    else
    #endif /*(UART_USER_MODE_DEINIT_API_ENABLE == STD_ON)*/
    {
      /*Reserve bit access is ensured for SRC_ASCLIN0ERR register*/
      /*IFX_MISRA_RULE_11_05_STATUS=Attempts to cast away volatile from
      UART_SRC_ASCLINxERRADDR to cast it for SFR access*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
      UART_SRC_ASCLIN0ERRADDR to access the SRC register for HW Unit passed*/
      /*IFX_MISRA_RULE_11_05_STATUS=Attempts to cast away volatile from
      UART_SRC_ASCLINxERRADDR to cast it for SFR access*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
      UART_SRC_ASCLIN0ERRADDR to access the SRC register for HW Unit passed*/
      *((volatile uint32 *)(void *)(UART_SRC_ASCLIN0ERRADDR + Offset)) = \
        (*((volatile uint32 *)(void *)(UART_SRC_ASCLIN0ERRADDR + Offset)) & \
                   (~UART_CLR_MASK_DISABLE_INTR)) | UART_SET_MASK_DISABLE_INTR;

      UNUSED_PARAMETER(ApiAccessId)
    }
  }
}

/*******************************************************************************
** Syntax           :    static void Uart_lHwDisableAscLinRxIntr              **
**                      (uint8 HwUnit, uint8 ApiAccessId)                     **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit        : ASCLIN Hardware module no               **
**                  : ApiAccessId   : API access type                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function clears and disables the   RX              **
**                    interrupts in SRC registers.                            **
*******************************************************************************/
static void Uart_lHwDisableAscLinRxIntr(volatile uint8 HwUnit,\
                                                              uint8 ApiAccessId)
{
  /*Ifx_SRC_SRCR_Bits IntrSrc;*/
  uint32 Offset,IntrSrc;

  Offset = (uint32)HwUnit * UART_SRC_ADDROFFSET ;
  #if (UART_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  #if (UART_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
  if (ApiAccessId == UART_RUNTIME_ACCESS)
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
    UART_SRC_ASCLIN0RXADDR to access the SRC register for HW Unit passed*/
    IntrSrc = UART_SFR_RUNTIME_USER_MODE_READ32\
                                          (*(UART_SRC_ASCLIN0RXADDR + Offset));
  }
  else
  #endif /*(UART_USER_MODE_RUNTIME_API_ENABLE == STD_ON)*/
  #if (UART_USER_MODE_DEINIT_API_ENABLE == STD_ON)
  if (ApiAccessId == UART_DEINIT_ACCESS)
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
    UART_SRC_ASCLIN0RXADDR to access the SRC register for HW Unit passed*/
    IntrSrc = UART_SFR_DEINIT_USER_MODE_READ32\
                                    (*(UART_SRC_ASCLIN0RXADDR + Offset));
  }
  else
  #endif /*(UART_USER_MODE_DEINIT_API_ENABLE == STD_ON)*/
  #endif /*(UART_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)*/
  {
    /*IFX_MISRA_RULE_11_05_STATUS=Attempts to cast away volatile from
      UART_SRC_ASCLINxERRADDR to cast it for SFR access*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
    UART_SRC_ASCLIN0RXADDR to access the SRC register for HW Unit passed*/
    IntrSrc =(*((volatile uint32 *)(void *)(UART_SRC_ASCLIN0RXADDR  + Offset)));
  }

  if (((IntrSrc & UART_SET_MASK_ENABLE_INTR)>>10U) == UART_BIT_SET)
  {
    #if (UART_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
    if (ApiAccessId == UART_RUNTIME_ACCESS)
    {
      /*Reserve bit access is ensured for SRC_ASCLIN0ERR register*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
      UART_SRC_ASCLIN0RXADDR to access the SRC register for HW Unit passed*/
      /*IFX_MISRA_RULE_11_05_STATUS=Attempts to cast away volatile from
      UART_SRC_ASCLINxRXADDR to cast it for SFR access*/
      UART_SFR_RUNTIME_MODIFY32(*((volatile uint32 *)\
      (void *)(UART_SRC_ASCLIN0RXADDR + Offset)), ~UART_CLR_MASK_DISABLE_INTR,\
                                               UART_SET_MASK_DISABLE_INTR)
    }
    else
    #endif /*(UART_USER_MODE_RUNTIME_API_ENABLE == STD_ON)*/
    #if (UART_USER_MODE_DEINIT_API_ENABLE == STD_ON)
    if (ApiAccessId == UART_DEINIT_ACCESS)
    {
      /*Reserve bit access is ensured for SRC_ASCLIN0ERR register*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
      UART_SRC_ASCLIN0RXADDR to access the SRC register for HW Unit passed*/
      /*IFX_MISRA_RULE_11_05_STATUS=Attempts to cast away volatile from
      UART_SRC_ASCLINxRXADDR to cast it for SFR access*/
      UART_SFR_DEINIT_MODIFY32(*((volatile uint32 *)\
      (void *)(UART_SRC_ASCLIN0RXADDR + Offset)), ~UART_CLR_MASK_DISABLE_INTR,\
                                               UART_SET_MASK_DISABLE_INTR)
    }
    else
    #endif /*(UART_USER_MODE_DEINIT_API_ENABLE == STD_ON)*/
    {
      /*Reserve bit access is ensured for SRC_ASCLIN0ERR register*/
      /*IFX_MISRA_RULE_11_05_STATUS=Attempts to cast away volatile from
      UART_SRC_ASCLINxRXADDR to cast it for SFR access*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
      UART_SRC_ASCLIN0RXADDR to access the SRC register for HW Unit passed*/
      /*IFX_MISRA_RULE_11_05_STATUS=Attempts to cast away volatile from
      UART_SRC_ASCLINxRXADDR to cast it for SFR access*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
      UART_SRC_ASCLIN0RXADDR to access the SRC register for HW Unit passed*/
      *((volatile uint32 *)\
       (void *)(UART_SRC_ASCLIN0RXADDR + Offset)) = (*((volatile uint32 *)\
       (void *)(UART_SRC_ASCLIN0RXADDR + Offset)) &\
                    (~UART_CLR_MASK_DISABLE_INTR)) | UART_SET_MASK_DISABLE_INTR;

      UNUSED_PARAMETER(ApiAccessId)
    }
  }
}
/*******************************************************************************
** Syntax           :  static void Uart_lHwDisableAscLinTxIntr                **
**                      (uint8 HwUnit, uint8 ApiAccessId)                     **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit        : ASCLIN Hardware module no               **
**                  : ApiAccessId   : API access type                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function clears and disables the TX                **
**                    interrupts in SRC registers.                            **
*******************************************************************************/
static void Uart_lHwDisableAscLinTxIntr(volatile uint8 HwUnit,uint8 ApiAccessId)
{
  /*Ifx_SRC_SRCR_Bits IntrSrc;*/
  uint32 Offset,IntrSrc;

  Offset = (uint32)HwUnit * UART_SRC_ADDROFFSET ;
  #if (UART_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  #if (UART_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
  if (ApiAccessId == UART_RUNTIME_ACCESS)
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
     UART_SRC_ASCLIN0TXADDR to access the SRC register for HW Unit passed*/
    IntrSrc = UART_SFR_RUNTIME_USER_MODE_READ32\
                                    (*(UART_SRC_ASCLIN0TXADDR + Offset));
  }
  else
  #endif /*(UART_USER_MODE_RUNTIME_API_ENABLE == STD_ON)*/
  #if (UART_USER_MODE_DEINIT_API_ENABLE == STD_ON)
  if (ApiAccessId == UART_DEINIT_ACCESS)
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
    UART_SRC_ASCLIN0TXADDR to access the SRC register for HW Unit passed*/
    IntrSrc = UART_SFR_DEINIT_USER_MODE_READ32\
                                          (*(UART_SRC_ASCLIN0TXADDR + Offset));
  }
  else
  #endif /*(UART_USER_MODE_DEINIT_API_ENABLE == STD_ON)*/
  #endif /*(UART_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)*/
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
    UART_SRC_ASCLIN0ERRADDR to access the SRC register for HW Unit passed*/
    /*IFX_MISRA_RULE_11_05_STATUS=Attempts to cast away volatile from
    UART_SRC_ASCLINxRXADDR to cast it for SFR access*/
    IntrSrc = (*((volatile uint32 *)(void *)(UART_SRC_ASCLIN0TXADDR + Offset)));
  }


  if (((IntrSrc & UART_SET_MASK_ENABLE_INTR)>>10U) == UART_BIT_SET)
  {
    #if (UART_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
    if (ApiAccessId == UART_RUNTIME_ACCESS)
    {
      /*Reserve bit access is ensured for SRC_ASCLIN0TX register*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
      UART_SRC_ASCLIN0TXADDR to access the SRC register for HW Unit passed*/
      /*IFX_MISRA_RULE_11_05_STATUS=Attempts to cast away volatile from
      UART_SRC_ASCLINxTXADDR to cast it for SFR access*/
      UART_SFR_RUNTIME_MODIFY32(*((volatile uint32 *)(void *)\
                (UART_SRC_ASCLIN0TXADDR + Offset)),~UART_CLR_MASK_DISABLE_INTR,\
                                                     UART_SET_MASK_DISABLE_INTR)
    }
    else
    #endif /*(UART_USER_MODE_RUNTIME_API_ENABLE == STD_ON)*/
    #if (UART_USER_MODE_DEINIT_API_ENABLE == STD_ON)
    if (ApiAccessId == UART_DEINIT_ACCESS)
    {
      /*Reserve bit access is ensured for SRC_ASCLIN0TX register*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
      UART_SRC_ASCLIN0TXADDR to access the SRC register for HW Unit passed*/
      /*IFX_MISRA_RULE_11_05_STATUS=Attempts to cast away volatile from
      UART_SRC_ASCLINxTXADDR to cast it for SFR access*/
      UART_SFR_DEINIT_MODIFY32(*((volatile uint32 *)(void *)\
                (UART_SRC_ASCLIN0TXADDR + Offset)),~UART_CLR_MASK_DISABLE_INTR,\
                                                     UART_SET_MASK_DISABLE_INTR)
    }
    else
    #endif /*(UART_USER_MODE_DEINIT_API_ENABLE == STD_ON)*/
    {
      /*Reserve bit access is ensured for SRC_ASCLIN0TX register*/
      /*IFX_MISRA_RULE_11_05_STATUS=Attempts to cast away volatile from
      UART_SRC_ASCLINxTXADDR to cast it for SFR access*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
      UART_SRC_ASCLIN0TXADDR to access the SRC register for HW Unit passed*/
      /*IFX_MISRA_RULE_11_05_STATUS=Attempts to cast away volatile from
      UART_SRC_ASCLINxTXADDR to cast it for SFR access*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
      UART_SRC_ASCLIN0TXADDR to access the SRC register for HW Unit passed*/
      *((volatile uint32 *)\
       (void *)(UART_SRC_ASCLIN0TXADDR + Offset)) = (*((volatile uint32 *)\
       (void *)(UART_SRC_ASCLIN0TXADDR + Offset)) &\
                    (~UART_CLR_MASK_DISABLE_INTR)) | UART_SET_MASK_DISABLE_INTR;

      UNUSED_PARAMETER(ApiAccessId)
    }
  }
}

/*******************************************************************************
** Syntax           : static void Uart_lHwEnableAscLinErrIntr                 **
**                      (uint8 HwUnit)                                        **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function clears and enables the  Err               **
**                    interrupts in SRC registers.                            **
*******************************************************************************/
static void Uart_lHwEnableAscLinErrIntr(volatile uint8 HwUnit)
{
  uint32 Offset;

  Offset = (uint32)HwUnit * UART_SRC_ADDROFFSET ;

  /*Reserve bit access is ensured for SRC_ASCLIN0ERR register*/
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
  UART_SRC_ASCLIN0ERRADDR to access the SRC register for HW Unit passed*/
  /*IFX_MISRA_RULE_11_05_STATUS=Attempts to cast away volatile from
  UART_SRC_ASCLINxERRADDR to cast it for SFR access*/
  UART_SFR_RUNTIME_MODIFY32(*((volatile uint32 *)(void *)\
                 (UART_SRC_ASCLIN0ERRADDR + Offset)), ~UART_CLR_MASK_CLR_INTR,\
                                                    UART_SET_MASK_CLR_INTR)

  /*Reserve bit access is ensured for SRC_ASCLIN0ERR register*/
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
  UART_SRC_ASCLIN0ERRADDR to access the SRC register for HW Unit passed*/
  /*IFX_MISRA_RULE_11_05_STATUS=Attempts to cast away volatile from
  UART_SRC_ASCLINxERRADDR to cast it for SFR access*/
  UART_SFR_RUNTIME_MODIFY32(*((volatile uint32 *)(void *)\
               (UART_SRC_ASCLIN0ERRADDR + Offset)), ~UART_CLR_MASK_ENABLE_INTR,\
                                                    UART_SET_MASK_ENABLE_INTR)

}


/*******************************************************************************
** Syntax           : static void Uart_lHwEnableAscLinRxIntr                  **
**                      (uint8 HwUnit)                                        **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function clears and enables the  RX                **
**                    interrupts in SRC registers.                            **
*******************************************************************************/
static void Uart_lHwEnableAscLinRxIntr(volatile uint8 HwUnit)
{
  uint32 Offset;

  Offset = (uint32)HwUnit * UART_SRC_ADDROFFSET ;

  /*Reserve bit access is ensured for SRC_ASCLIN0RX register*/
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
  UART_SRC_ASCLIN0RXADDR to access the SRC register for HW Unit passed*/
  /*IFX_MISRA_RULE_11_05_STATUS=Attempts to cast away volatile from
  UART_SRC_ASCLINxRXADDR to cast it for SFR access*/
  UART_SFR_RUNTIME_MODIFY32(*((volatile uint32 *)(void *)\
                 (UART_SRC_ASCLIN0RXADDR + Offset)), ~UART_CLR_MASK_CLR_INTR,\
                                                     UART_SET_MASK_CLR_INTR)


  /*Reserve bit access is ensured for SRC_ASCLIN0RX register*/
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
  UART_SRC_ASCLIN0RXADDR to access the SRC register for HW Unit passed*/
  /*IFX_MISRA_RULE_11_05_STATUS=Attempts to cast away volatile from
  UART_SRC_ASCLINxRXADDR to cast it for SFR access*/
  UART_SFR_RUNTIME_MODIFY32(*((volatile uint32 *)(void *)\
              (UART_SRC_ASCLIN0RXADDR + Offset)), ~UART_CLR_MASK_ENABLE_INTR,\
                                                     UART_SET_MASK_ENABLE_INTR)

}
/*******************************************************************************
** Syntax           : static void Uart_lHwEnableAscLinTxIntr                  **
**                      (uint8 HwUnit)                                        **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : NA                                                      **
**                                                                            **
** Parameters (in)  : HwUnit   : ASCLIN Hardware module no                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function clears and enables the  TX                **
**                    interrupts in SRC registers.                            **
*******************************************************************************/
static void Uart_lHwEnableAscLinTxIntr(volatile uint8 HwUnit)
{
  uint32 Offset;

  Offset = (uint32)HwUnit * UART_SRC_ADDROFFSET ;

  /*Reserve bit access is ensured for SRC_ASCLIN0TX register*/
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
   UART_SRC_ASCLIN0TXADDR to access the SRC register for HW Unit passed*/
  /*IFX_MISRA_RULE_11_05_STATUS=Attempts to cast away volatile from
    UART_SRC_ASCLINxTXADDR to cast it for SFR access*/
  UART_SFR_RUNTIME_MODIFY32(*((volatile uint32 *)(void *)\
               (UART_SRC_ASCLIN0TXADDR + Offset)), ~UART_CLR_MASK_CLR_INTR,\
                                                        UART_SET_MASK_CLR_INTR)

  /*Reserve bit access is ensured for SRC_ASCLIN0TX register*/
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is done on
   UART_SRC_ASCLIN0TXADDR to access the SRC register for HW Unit passed*/
  /*IFX_MISRA_RULE_11_05_STATUS=Attempts to cast away volatile from
   UART_SRC_ASCLINxTXADDR to cast it for SFR access*/
  UART_SFR_RUNTIME_MODIFY32(*((volatile uint32 *)(void *)\
              (UART_SRC_ASCLIN0TXADDR + Offset)), ~UART_CLR_MASK_ENABLE_INTR,\
                                                    UART_SET_MASK_ENABLE_INTR)
}
/*----------------------------------------------------------------------------*/
/* Memory Map of the UART Code */
#define UART_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
/*******************************************************************************
**                               End of File                                  **
*******************************************************************************/

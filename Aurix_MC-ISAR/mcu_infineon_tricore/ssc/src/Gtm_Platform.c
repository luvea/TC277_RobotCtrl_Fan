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
**  $FILENAME   : Gtm_Platform.c $                                           **
**                                                                           **
**  $CC VERSION : \main\32 $                                                 **
**                                                                           **
**  $DATE       : 2016-07-13 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                functionality of <> driver.                                **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Own header file, this includes own configuration file also */
#include "Gtm.h"
#include "Gtm_Local.h"
/* Include Irq definitions for IRQ */
#include "IfxSrc_reg.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

#define GTM_ADCCONNECT_GET_LOWER_NIBBLE (0x0FUL)
#define GTM_ADCCONNECT_GET_UPPER_NIBBLE (0xF0UL)
#define GTM_BITS_PER_ADC_CONNECTION (4U)
#define GTM_BITS_IN_U32 (32U)
#define GTM_CLEAR_INTERRUPT (3UL)
#define GTM_TOM_ATOM_CLK_POS (12U)
#define GTM_TOM_ATOM_TPWM_MODE_MASK (0x3U)
#define GTM_TOM_CLK_MASK (0x7000U)
#define GTM_ATOM_CLK_TPWM_MASK (0x7003U)
#define GTM_CLEAR_STICKY_BITS (0x52000000U)
#define GTM_TOM_NO_OF_SRC_REG (8U)
#define GTM_ATOM_NO_OF_SRC_REG (4U)


/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*Memory Map of the GTM Code*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#define GTM_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
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

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*******************************************************************************
** Syntax : void Gtm_lAdcConnectionsConfig(void)                              **
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
** Description :     Function to initialize ADC Connections                   **
*******************************************************************************/
 void Gtm_lAdcConnectionsConfig(void)
{
  uint32 RegTemp1;          /* Temporary variable to store the register value */
  uint32 RegTemp2;          /* Temporary variable to store the register value */
  uint8 Count;
  volatile uint8 TrigOutLoopLimit = \
                             GTM_NO_OF_ADC_MODULES - GTM_ADC_CONN_PER_REGISTER;

  /* Check if Adc Connections is configured */
  if(Gtm_kConfigPtr->GtmModuleConfigPtr->GtmAdcConnectionsPtr != NULL_PTR)
  {
    RegTemp1 = GTM_ZERO_UL;
    RegTemp2 = GTM_ZERO_UL;


    for(Count=GTM_ZERO_U; Count < GTM_ADC_CONN_PER_REGISTER; Count++)
    {
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
     PBConfigStructure and is within allowed range.*/
      RegTemp1 |=                                                              \
       ((uint32)Gtm_kConfigPtr->GtmModuleConfigPtr->GtmAdcConnectionsPtr[Count]\
                                   & GTM_ADCCONNECT_GET_LOWER_NIBBLE) <<      \
                                    (GTM_BITS_PER_ADC_CONNECTION * Count);
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
     PBConfigStructure and is within allowed range.*/
      RegTemp2 |=                                                              \
      (((uint32)Gtm_kConfigPtr->GtmModuleConfigPtr->GtmAdcConnectionsPtr[Count]\
            & GTM_ADCCONNECT_GET_UPPER_NIBBLE) >> GTM_BITS_PER_ADC_CONNECTION)\
            << (GTM_BITS_PER_ADC_CONNECTION * Count);

    }
    GTM_SFR_INIT_USER_MODE_WRITE32((GTM_ADCTRIG0OUT0.U),(uint32)RegTemp1);
    GTM_SFR_INIT_USER_MODE_WRITE32((GTM_ADCTRIG1OUT0.U),(uint32)RegTemp2);


    RegTemp1 = GTM_ZERO_UL;
    RegTemp2 = GTM_ZERO_UL;
    for(Count=GTM_ZERO_U ; Count < TrigOutLoopLimit ; Count++)
    {
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
     PBConfigStructure and is within allowed range.*/
      RegTemp1 |=                                                              \
      ((uint32)Gtm_kConfigPtr->GtmModuleConfigPtr->GtmAdcConnectionsPtr \
      [Count+GTM_ADC_CONN_PER_REGISTER] & GTM_ADCCONNECT_GET_LOWER_NIBBLE) <<
                 (GTM_BITS_PER_ADC_CONNECTION * Count);
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
     PBConfigStructure and is within allowed range.*/
      RegTemp2 |=                                                              \
     (((uint32)Gtm_kConfigPtr->GtmModuleConfigPtr->GtmAdcConnectionsPtr \
     [Count+GTM_ADC_CONN_PER_REGISTER] & GTM_ADCCONNECT_GET_UPPER_NIBBLE) >>  \
          GTM_BITS_PER_ADC_CONNECTION) << (GTM_BITS_PER_ADC_CONNECTION * Count);

    }
    GTM_SFR_INIT_USER_MODE_WRITE32((GTM_ADCTRIG0OUT1.U),((uint32)RegTemp1));
    GTM_SFR_INIT_USER_MODE_WRITE32((GTM_ADCTRIG1OUT1.U),((uint32)RegTemp2));

  }
}

#if (GTM_DEINIT_API_ENABLE == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=                    ]                       **
** Syntax :  void Gtm_lResetGtmSRCReg (void)                                  **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       None                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       Non Reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :  This service shall de-initialize GTM registers that are not **
** de-initaliazed by GTM kernel reset                                         **
**                                                                            **
*******************************************************************************/
void Gtm_lResetGtmSRCReg(void)
{
  uint8 ModuleNo;
  uint8 ChannelNo;
  /* De-init AEI SRC register*/
  /* Clear Sticky bits of SRC register */
  GTM_SFR_DEINIT_MODIFY32((SRC_GTMAEIIRQ.U),GTM_SRC_CLEAR_MASK,\
    GTM_CLEAR_STICKY_BITS)

  /* Disable SRE  */
  GTM_SFR_DEINIT_MODIFY32((SRC_GTMAEIIRQ.U),GTM_SRC_SRE_CLEAR_MASK,\
         GTM_ZERO_U)

  /* De-init ARU SRC registers*/
  /* Clear Sticky bits of SRC register */
  GTM_SFR_DEINIT_MODIFY32((SRC_GTMARUIRQ0.U),GTM_SRC_CLEAR_MASK,\
    GTM_CLEAR_STICKY_BITS)
  /* Disable SRE  */
   GTM_SFR_DEINIT_MODIFY32((SRC_GTMARUIRQ0.U),GTM_SRC_SRE_CLEAR_MASK,\
         GTM_ZERO_U)

  /* Clear Sticky bits of SRC register */
  GTM_SFR_DEINIT_MODIFY32((SRC_GTMARUIRQ1.U),GTM_SRC_CLEAR_MASK,\
    GTM_CLEAR_STICKY_BITS)
  /* Disable SRE  */
  GTM_SFR_DEINIT_MODIFY32((SRC_GTMARUIRQ1.U),GTM_SRC_SRE_CLEAR_MASK,\
         GTM_ZERO_U)

  /* Clear Sticky bits of SRC register */
  GTM_SFR_DEINIT_MODIFY32((SRC_GTMARUIRQ2.U),GTM_SRC_CLEAR_MASK,\
    GTM_CLEAR_STICKY_BITS)
  /* Disable SRE  */
  GTM_SFR_DEINIT_MODIFY32((SRC_GTMARUIRQ2.U),GTM_SRC_SRE_CLEAR_MASK,\
         GTM_ZERO_U)

  /* De-init FIFO SRC registers*/
  for(ChannelNo=GTM_ZERO_U; ChannelNo < GTM_NO_OF_FIFO_CHANNELS; ChannelNo++)
  {
    /* Clear Sticky bits of SRC register */
      GTM_SFR_DEINIT_MODIFY32((\
          MODULE_SRC.GTM.GTM[0].PSM[0][ChannelNo].U),\
          GTM_SRC_CLEAR_MASK,GTM_CLEAR_STICKY_BITS)
    /* Disable SRE */
      GTM_SFR_DEINIT_MODIFY32((\
          MODULE_SRC.GTM.GTM[0].PSM[0][ChannelNo].U),\
          GTM_SRC_SRE_CLEAR_MASK,GTM_ZERO_U)
  }

  /* De-init TIM SRC registers */
  for(ModuleNo=GTM_ZERO_U; ModuleNo < GTM_NO_OF_TIM_MODULES; ModuleNo++)
  {
    for(ChannelNo=GTM_ZERO_U; ChannelNo < GTM_CHANNELS_PER_TIM_MODULE;\
                                                                 ChannelNo++)
    {
      /* Clear Sticky bits of SRC register */
        GTM_SFR_DEINIT_MODIFY32((\
          MODULE_SRC.GTM.GTM[0].TIM[ModuleNo][ChannelNo].U),\
          GTM_SRC_CLEAR_MASK,GTM_CLEAR_STICKY_BITS)
       /* Disable SRE  */
      GTM_SFR_DEINIT_MODIFY32((\
        MODULE_SRC.GTM.GTM[0].TIM[ModuleNo][ChannelNo].U),\
        GTM_SRC_SRE_CLEAR_MASK,GTM_ZERO_U)
    }
  }

  /* De-init TOM SRC registers */
  for(ModuleNo=GTM_ZERO_U; ModuleNo < GTM_NO_OF_TOM_MODULES; ModuleNo++)
  {
    for(ChannelNo=GTM_ZERO_U; ChannelNo < GTM_TOM_NO_OF_SRC_REG;\
                                                                 ChannelNo++)
    {
      /* Clear Sticky bits of SRC register */
        GTM_SFR_DEINIT_MODIFY32((\
            MODULE_SRC.GTM.GTM[0].TOM[ModuleNo][ChannelNo].U),\
            GTM_SRC_CLEAR_MASK,GTM_CLEAR_STICKY_BITS)
      /* Disable SRE  */
        GTM_SFR_DEINIT_MODIFY32((\
            MODULE_SRC.GTM.GTM[0].TOM[ModuleNo][ChannelNo].U),\
            GTM_SRC_SRE_CLEAR_MASK,GTM_ZERO_U)
    }
  }

  /* De-init ATOM SRC registers */
  for(ModuleNo=GTM_ZERO_U; ModuleNo < GTM_NO_OF_ATOM_MODULES; ModuleNo++)
  {
    for(ChannelNo=GTM_ZERO_U; ChannelNo < GTM_ATOM_NO_OF_SRC_REG;\
                                                                 ChannelNo++)
    {
      /* Clear Sticky bits of SRC register */
        GTM_SFR_DEINIT_MODIFY32((\
            MODULE_SRC.GTM.GTM[0].ATOM[ModuleNo][ChannelNo].U),\
            GTM_SRC_CLEAR_MASK,GTM_CLEAR_STICKY_BITS)
      /* Disable SRE  */
        GTM_SFR_DEINIT_MODIFY32((\
            MODULE_SRC.GTM.GTM[0].ATOM[ModuleNo][ChannelNo].U),\
            GTM_SRC_SRE_CLEAR_MASK,GTM_ZERO_U)
    }
  }

  /* De-init BRC SRC registers */

  /* Clear Sticky bits of SRC register */
    GTM_SFR_DEINIT_MODIFY32((\
        MODULE_SRC.GTM.GTM[0].BRCIRQ.U),GTM_SRC_CLEAR_MASK,\
        GTM_CLEAR_STICKY_BITS)
  /* Disable SRE  */
    GTM_SFR_DEINIT_MODIFY32((MODULE_SRC.GTM.GTM[0].BRCIRQ.U),\
        GTM_SRC_SRE_CLEAR_MASK,\
        GTM_ZERO_U)

  /* De-init MCS SRC registers */
  for(ModuleNo=GTM_ZERO_U; ModuleNo < GTM_NO_OF_MCS_MODULES; ModuleNo++)
  {
    for(ChannelNo=GTM_ZERO_U; ChannelNo < GTM_NO_OF_MCS_CHANNELS;\
                                                                 ChannelNo++)
    {
      /* Clear Sticky bits of SRC register */
        GTM_SFR_DEINIT_MODIFY32((\
            MODULE_SRC.GTM.GTM[0].MCS[ModuleNo][ChannelNo].U),\
            GTM_SRC_CLEAR_MASK,GTM_CLEAR_STICKY_BITS)
      /* Disable SRE  */
        GTM_SFR_DEINIT_MODIFY32((\
            MODULE_SRC.GTM.GTM[0].MCS[ModuleNo][ChannelNo].U),\
            GTM_SRC_SRE_CLEAR_MASK,GTM_ZERO_U)
    }
  }

  /* De-init DPLL SRC registers */
  for(ModuleNo = GTM_ZERO_U; ModuleNo < GTM_NUMBER_OF_DPLL_INT; ModuleNo++)
  {
    /* Clear Sticky bits of SRC register */
      GTM_SFR_DEINIT_MODIFY32((MODULE_SRC.GTM.GTM[0].DPLL[ModuleNo].U),\
          GTM_SRC_CLEAR_MASK,GTM_CLEAR_STICKY_BITS)
    /* Disable SRE  */
      GTM_SFR_DEINIT_MODIFY32((MODULE_SRC.GTM.GTM[0].DPLL[ModuleNo].U),\
          GTM_SRC_SRE_CLEAR_MASK,GTM_ZERO_U)
  }

  /* De-init SPE SRC registers */
  for(ModuleNo = GTM_ZERO_U; ModuleNo < GTM_NO_SPE_MODULES; ModuleNo++)
  {
    /* Clear Sticky bits of SRC register */
      GTM_SFR_DEINIT_MODIFY32((MODULE_SRC.GTM.GTM[0].SPEIRQ[ModuleNo].U),\
        GTM_SRC_CLEAR_MASK,GTM_CLEAR_STICKY_BITS)
    /* Disable SRE  */
      GTM_SFR_DEINIT_MODIFY32((MODULE_SRC.GTM.GTM[0].SPEIRQ[ModuleNo].U),\
        GTM_SRC_SRE_CLEAR_MASK,GTM_ZERO_U)
  }

  /* De-init CMP SRC registers */
  /* Clear Sticky bits of SRC register */
    GTM_SFR_DEINIT_MODIFY32((SRC_GTM_GTM0_CMPIRQ.U),GTM_SRC_CLEAR_MASK,\
      GTM_CLEAR_STICKY_BITS)
    /* Disable SRE  */
    GTM_SFR_DEINIT_MODIFY32((SRC_GTM_GTM0_CMPIRQ.U),GTM_SRC_SRE_CLEAR_MASK,\
         GTM_ZERO_U)

}
/* End of Gtm_lResetGtmSRCReg() */
#endif
/*******************************************************************************
** Syntax : void Gtm_lTomComplexConfig(void)                                  **
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
** Description :     Function to initialize Complex Configuration of TOM      **
*******************************************************************************/
void Gtm_lTomComplexConfig(void)
{
  const Gtm_TomConfigType *TomChannelConfigPtr;  /* Pointer to TOM Channel    */
  Ifx_GTM_TOM_CH_TYPE *TomChannelRegPtr;       /* Ptr to TOM Channel Reg    */
  uint8 TomCnt;             /* Variable to TOM Channel Initialization Count   */
  uint8 MajorCnt;           /* Variable to maintain Loop Count                */
  uint8 MinorCnt;           /* Variable to maintain Loop Count                */
  uint8 ModuleNo;           /* Variable to hold Module Number                 */
  uint8 ChannelNo;          /* Variable to hold Channel Number                */

  /* Count to maintain track of the index in TOM Channel Config  */
  TomCnt = GTM_ZERO_U;

  /* MajorCnt -Count to maintain an index to the GtmTomUsage Array            */
  /* MinorCnt -Count to maintain an index to the channels in GtmTomUsage Array*/
  for(MajorCnt = GTM_ZERO_U;
      MajorCnt < (((GTM_MAX_TOM_CHANNELS - GTM_ONE_U)/GTM_BITS_IN_U32) +
                    GTM_ONE_U);
      MajorCnt++)
  {
    for(MinorCnt = GTM_ZERO_U;
       (MinorCnt < GTM_BITS_IN_U32)
       &&(((MajorCnt * GTM_BITS_IN_U32)+ MinorCnt) < GTM_MAX_TOM_CHANNELS);
       MinorCnt++)
    {
      /* Check if the channel is configured */
      if((Gtm_kConfigPtr->GtmModuleConfigPtr->GtmTomUsage[MajorCnt] &      \
        (GTM_BIT_SET << MinorCnt)) > GTM_ZERO_UL)
      {
        /* Get the Pointer to the Channel Configuration Register */
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
     PBConfigStructure and is within allowed range.*/
        TomChannelConfigPtr =
            &(Gtm_kConfigPtr->GtmModuleConfigPtr->GtmTomConfigPtr[TomCnt]);

        TomCnt++;
        /* Initialize the channels if the channel is configured as Complex*/
        if(TomChannelConfigPtr->TomUsage == GTM_DRIVER_COMPLEX)
        {
          /* Extract Module Number and Channel Number from the Loop Count     */
          ModuleNo = ((MajorCnt * GTM_BITS_IN_U32) + MinorCnt)/
                       GTM_CHANNELS_PER_TOM_MODULE;
          ChannelNo = MinorCnt % GTM_CHANNELS_PER_TOM_MODULE;

          /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
         Permitted for special function registers.*/
          TomChannelRegPtr = &((((*(Ifx_GTM_TOMx*)(void *)(MODULE_GTM.TOM)).   \
                                            TOM_CH[ModuleNo])).CH[ChannelNo]);

          /* Initialize the Channel parameters */
          GTM_SFR_INIT_WRITE32((TomChannelRegPtr->CN0.U),\
                     TomChannelConfigPtr->GtmTomChannelCfgPtr->GtmTomCn0Value);
          GTM_SFR_INIT_WRITE32((TomChannelRegPtr->CM0.U),\
                     TomChannelConfigPtr->GtmTomChannelCfgPtr->GtmTomCm0Value);
          GTM_SFR_INIT_WRITE32((TomChannelRegPtr->CM1.U),\
                     TomChannelConfigPtr->GtmTomChannelCfgPtr->GtmTomCm1Value);
          GTM_SFR_INIT_WRITE32((TomChannelRegPtr->SR0.U),\
                     TomChannelConfigPtr->GtmTomChannelCfgPtr->GtmTomSr0Value);
          GTM_SFR_INIT_WRITE32((TomChannelRegPtr->SR1.U),\
                     TomChannelConfigPtr->GtmTomChannelCfgPtr->GtmTomSr1Value);

          GTM_SFR_INIT_WRITE32((TomChannelRegPtr->IRQ_MODE.U),\
                  (uint32)TomChannelConfigPtr->GtmTomIrqMode);
          GTM_SFR_INIT_WRITE32((TomChannelRegPtr->CTRL.U), \
                       TomChannelConfigPtr->GtmTomControlWord);

          /* Clear the Pending Interrupts */
          GTM_SFR_INIT_WRITE32((TomChannelRegPtr->IRQ_NOTIFY.U),\
                        GTM_CLEAR_INTERRUPT);
          GTM_SFR_INIT_WRITE32((TomChannelRegPtr->IRQ_EN.U),\
               (uint32)TomChannelConfigPtr->GtmTomChannelCfgPtr->GtmTomIrqEn);

          /* Enable SRN */
          GTM_SFR_INIT_MODIFY32(\
             (MODULE_SRC.GTM.GTM[0].TOM[ModuleNo][ChannelNo/2U].U),\
             GTM_SRC_CLEAR_MASK,\
             (unsigned_int)(GTM_BIT_SET << GTM_BIT_SRE))

        }
      }
    }
  }
}

/*******************************************************************************
** Syntax : void Gtm_lAtomComplexConfig(void)                                 **
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
** Description :     Function to initialize ATOM Complex Channels             **
*******************************************************************************/
void Gtm_lAtomComplexConfig(void)
{
  const Gtm_AtomConfigType *AtomChannelConfigPtr;/* Pointer to ATOM Channel   */
  Ifx_GTM_ATOM_CH_TYPE* AtomChannelRegPtr;      /* Ptr to ATOM Channel Reg   */
  uint8 AtomCnt;            /* Variable to ATOM Channel Initialization Count  */
  uint8 MajorCnt;           /* Variable to maintain Loop Count                */
  uint8 MinorCnt;           /* Variable to maintain Loop Count                */
  uint8 ModuleNo;           /* Variable to hold Module Number                 */
  uint8 ChannelNo;          /* Variable to hold Channel Number                */

  /* Count to maintain track of the index in ATOM Channel Config */
  AtomCnt = GTM_ZERO_U;

  /* MajorCnt -Count to maintain an index to the GtmAtomUsage Array           */
  /* MinorCnt -Count to maintain an index to the channels in GtmAtomUsage
     Array */
  for(MajorCnt = GTM_ZERO_U;
      MajorCnt < (((GTM_MAX_ATOM_CHANNELS - GTM_ONE_U)/GTM_BITS_IN_U32) +
                   GTM_ONE_U);
      MajorCnt++)
  {

    for(MinorCnt = GTM_ZERO_U;
       (MinorCnt < GTM_BITS_IN_U32) &&
       (((MajorCnt * GTM_BITS_IN_U32) + MinorCnt) < GTM_MAX_ATOM_CHANNELS);
       MinorCnt++)
    {
      /* Check if the channel is configured */
      if((Gtm_kConfigPtr->GtmModuleConfigPtr->GtmAtomUsage[MajorCnt] &
         (GTM_BIT_SET << MinorCnt)) > GTM_ZERO_UL)
      {

        /* Get the Pointer to the Channel Configuration Register */
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
     PBConfigStructure and is within allowed range.*/
        AtomChannelConfigPtr =           \
               &(Gtm_kConfigPtr->GtmModuleConfigPtr->GtmAtomConfigPtr[AtomCnt]);


        AtomCnt++;
        /* Initialize the channels if the channel is configured as Complex*/
        if(AtomChannelConfigPtr->GtmAtomUsage == GTM_DRIVER_COMPLEX)
        {
          /* Extract Module Number and Channel Number from the Loop Count     */
          ModuleNo = ((MajorCnt * 32U) + MinorCnt)/GTM_CHANNELS_PER_ATOM_MODULE;
          ChannelNo = MinorCnt%GTM_CHANNELS_PER_ATOM_MODULE;

          /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
         Permitted for special function registers.*/
          AtomChannelRegPtr =  &((*(Ifx_GTM_ATOMx*)(void *)
                       (MODULE_GTM.ATOM)).ATOM_CH[ModuleNo].CH[ChannelNo]);


          /* Initialize the Channel parameters */
          GTM_SFR_INIT_WRITE32((AtomChannelRegPtr->CN0.U),\
            AtomChannelConfigPtr->GtmAtomChannelCfgPtr->GtmAtomCn0Value);
          GTM_SFR_INIT_WRITE32((AtomChannelRegPtr->CM0.U),\
            AtomChannelConfigPtr->GtmAtomChannelCfgPtr->GtmAtomCm0Value);
          GTM_SFR_INIT_WRITE32((AtomChannelRegPtr->CM1.U),\
            AtomChannelConfigPtr->GtmAtomChannelCfgPtr->GtmAtomCm1Value);
          GTM_SFR_INIT_WRITE32((AtomChannelRegPtr->SR0.U),\
            AtomChannelConfigPtr->GtmAtomChannelCfgPtr->GtmAtomSr0Value);
          GTM_SFR_INIT_WRITE32((AtomChannelRegPtr->SR1.U),\
            AtomChannelConfigPtr->GtmAtomChannelCfgPtr->GtmAtomSr1Value);

          GTM_SFR_INIT_WRITE32((AtomChannelRegPtr->RDADDR.U),\
            AtomChannelConfigPtr->GtmAtomChannelCfgPtr->GtmAtomRdAddrValue);
          GTM_SFR_INIT_WRITE32((AtomChannelRegPtr->IRQ_MODE.U),\
            (uint32)AtomChannelConfigPtr->GtmAtomIrqMode);
          GTM_SFR_INIT_WRITE32((AtomChannelRegPtr->CTRL.U),\
            AtomChannelConfigPtr->GtmAtomControlWord);

          /* Clear the Pending Interrupts */
          GTM_SFR_INIT_WRITE32((AtomChannelRegPtr->IRQ_NOTIFY.U),\
            GTM_CLEAR_INTERRUPT);
          GTM_SFR_INIT_WRITE32((AtomChannelRegPtr->IRQ_EN.U),\
            (uint32)AtomChannelConfigPtr->GtmAtomChannelCfgPtr->GtmAtomIrqEn);

          /* Enable SRN */
          GTM_SFR_INIT_MODIFY32(\
            (MODULE_SRC.GTM.GTM[0].ATOM[ModuleNo][ChannelNo/2U].U),\
            GTM_SRC_CLEAR_MASK,\
            (unsigned_int)(GTM_BIT_SET << GTM_BIT_SRE))
        }
      }
    }
  }
}

/*******************************************************************************
** Syntax : void Gtm_lTomClockSetting(void)                                   **
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
** Description :     Function to initialize TOM Clock information             **
*******************************************************************************/
void Gtm_lTomClockSetting(void)
{
  const Gtm_TomConfigType *TomChannelConfigPtr;  /* Pointer to TOM Channel    */
  Ifx_GTM_TOM_CH_TYPE *TomChannelRegPtr;         /* Ptr to TOM Channel Reg    */
  Ifx_GTM_TOM_TGC_TYPE *TomTgcRegPtr;            /* Pointer to TOM TGC Reg    */
  uint8 TomCnt;             /* Variable to TOM Channel Initialization Count   */
  uint8 MajorCnt;           /* Variable to maintain Loop Count                */
  uint8 MinorCnt;           /* Variable to maintain Loop Count                */
  uint8 ModuleNo;           /* Variable to hold Module Number                 */
  uint8 ChannelNo;          /* Variable to hold Channel Number                */
  uint8 TgcNumber;          /* Variable to hold TGC Number                    */
  uint32 RegVal;


  /* Clock Setting for GPT and PWM Modules */
  /* Count to maintain track of the index in TOM Channel Config   */
  TomCnt = GTM_ZERO_U;
  /* MajorCnt -Count to maintain an index to the GtmTomUsage Array            */
  /* MinorCnt -Count to maintain an index to the channels in GtmTomUsage Array*/
  for(MajorCnt = GTM_ZERO_U;
      MajorCnt < (((GTM_MAX_TOM_CHANNELS - GTM_ONE_U)/GTM_BITS_IN_U32) +
                                                                     GTM_ONE_U);
      MajorCnt++)
  {
    for(MinorCnt = GTM_ZERO_U;
       (MinorCnt < GTM_BITS_IN_U32)
       &&(((MajorCnt * GTM_BITS_IN_U32)+ MinorCnt) < GTM_MAX_TOM_CHANNELS);
       MinorCnt++)
    {
      /* Check if the TOM channel is configured */
      if((Gtm_kConfigPtr->GtmModuleConfigPtr->GtmTomUsage[MajorCnt] &          \
                                       (GTM_BIT_SET << MinorCnt)) > GTM_ZERO_UL)
      {

        /* Get reference to the Channel configuration */
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
     PBConfigStructure and is within allowed range.*/
        TomChannelConfigPtr =                                                  \
                 &(Gtm_kConfigPtr->GtmModuleConfigPtr->GtmTomConfigPtr[TomCnt]);

        TomCnt++;
        /* Check if the channel is configured for GPT or PWM */
        if(TomChannelConfigPtr->TomUsage != GTM_DRIVER_COMPLEX)
        {
          /* Extract module number and channel number from the Loop
             Count information */
          ModuleNo = ((MajorCnt * GTM_BITS_IN_U32) + MinorCnt)/
                                                    GTM_CHANNELS_PER_TOM_MODULE;
          ChannelNo = MinorCnt % GTM_CHANNELS_PER_TOM_MODULE;
          TgcNumber =                                                          \
                 (MinorCnt/GTM_TOM_CHANNELS_PER_TGC) % GTM_NO_OF_TGC_PER_MODULE;

          /* Get reference to the Channel Register */
          /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access,
           permitted for special function registers.*/
          TomChannelRegPtr = &((((*(Ifx_GTM_TOMx*)(void *)(MODULE_GTM.TOM)).   \
                                             TOM_CH[ModuleNo])).CH[ChannelNo]);


          /*Set the CTRL value*/
          GTM_SFR_INIT_USER_MODE_MODIFY32((TomChannelRegPtr->CTRL.U),\
            GTM_TOM_CH_CTRL_CLK_CLR_MASK,\
          ((uint32)(TomChannelConfigPtr->GtmTomControlWord) & \
             GTM_TOM_CH_CTRL_CLK_MASK))


          /* Set the IRQ_MODE value*/
          GTM_SFR_INIT_USER_MODE_WRITE32((TomChannelRegPtr->IRQ_MODE.U),\
                              TomChannelConfigPtr->GtmTomIrqMode);
          /*Get the TGC reg pointer reference*/
          /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
         Permitted for special function registers.*/
          TomTgcRegPtr = &(((*(Ifx_GTM_TOMx*)(void *)(MODULE_GTM.TOM)).
                                TOM_TGC[ModuleNo].TGC[TgcNumber]));
          /*Set the FUPD_CTRL value*/
          RegVal = (uint32)(GTM_TOM_ENABLE << (GTM_TOM_BITS_PER_CHAN * \
                         (ChannelNo % GTM_TOM_CHANNELS_PER_TGC)));
          GTM_SFR_INIT_USER_MODE_MODIFY32((TomTgcRegPtr->FUPD_CTRL.U),\
                       GTM_WHOLE_REG,RegVal)
          /* Enable SRN */
          GTM_SFR_INIT_MODIFY32((\
               MODULE_SRC.GTM.GTM[0].TOM[ModuleNo][ChannelNo/2U].U),\
               GTM_SRC_CLEAR_MASK,\
               (unsigned_int)(GTM_BIT_SET << GTM_BIT_SRE))
        }
      }
    }
  }
}

/*******************************************************************************
** Syntax : void Gtm_lAtomClockSetting(void)                                  **
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
** Description :     Function to configure ATOM clock                         **
*******************************************************************************/
void Gtm_lAtomClockSetting(void)
{
  const Gtm_AtomConfigType *AtomChannelConfigPtr;/* Pointer to ATOM Channel   */
  Ifx_GTM_ATOM_CH_TYPE *AtomChannelRegPtr;      /* Ptr to ATOM Channel Reg   */
  Ifx_GTM_ATOM *AtomAgcRegPtr;             /* Pointer to ATOM Reg   */
  uint8 AtomCnt;            /* Variable to ATOM Channel Initialization Count  */
  uint8 MajorCnt;           /* Variable to maintain Loop Count                */
  uint8 MinorCnt;           /* Variable to maintain Loop Count                */
  uint8 ModuleNo;           /* Variable to hold Module Number                 */
  uint8 ChannelNo;          /* Variable to hold Channel Number                */



  /* Clock Setting for GPT and PWM Modules */
  /* Count to maintain track of the index in ATOM Channel Config */
  AtomCnt = GTM_ZERO_U;
  /* MajorCnt -Count to maintain an index to the GtmTomUsage Array            */
  /* MinorCnt -Count to maintain an index to the channels in GtmTomUsage Array*/
  for(MajorCnt = GTM_ZERO_U;
      MajorCnt < (((GTM_MAX_ATOM_CHANNELS - GTM_ONE_U)/GTM_BITS_IN_U32) +
                    GTM_ONE_U);
      MajorCnt++)
  {
    for(MinorCnt = GTM_ZERO_U;
       (MinorCnt < GTM_BITS_IN_U32) &&
       (((MajorCnt * GTM_BITS_IN_U32) + MinorCnt) < GTM_MAX_ATOM_CHANNELS);
       MinorCnt++)
    {
      /* Check if the ATOM channel is configured */
      if((Gtm_kConfigPtr->GtmModuleConfigPtr->GtmAtomUsage[MajorCnt] &
                                       (GTM_BIT_SET << MinorCnt)) > GTM_ZERO_UL)
      {
        /* Get reference to the Channel configuration */
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
     PBConfigStructure and is within allowed range.*/
        AtomChannelConfigPtr =
               &(Gtm_kConfigPtr->GtmModuleConfigPtr->GtmAtomConfigPtr[AtomCnt]);


        AtomCnt++;
        /* Check if the channel is configured for GPT or PWM */
        if(AtomChannelConfigPtr->GtmAtomUsage != GTM_DRIVER_COMPLEX)
        {
          /* Extract module number and channel number from the Loop
             Count information */
          ModuleNo = ((MajorCnt * GTM_BITS_IN_U32) + MinorCnt)/
                       GTM_CHANNELS_PER_ATOM_MODULE;
          ChannelNo = MinorCnt % GTM_CHANNELS_PER_ATOM_MODULE;

          /* Get reference to the Channel Register */
          /*IFX_MISRA_RULE_11_05_STATUS=volatile in terms of pointer access.
         Permitted for special function registers.*/
          AtomChannelRegPtr = &((*(Ifx_GTM_ATOMx*)(void *)
                       (MODULE_GTM.ATOM)).ATOM_CH[ModuleNo].CH[ChannelNo]);
          /*Set the CTRL value*/
          GTM_SFR_INIT_USER_MODE_MODIFY32((AtomChannelRegPtr->CTRL.U),\
            GTM_TOM_CH_CTRL_CLK_CLR_MASK,\
          (AtomChannelConfigPtr->GtmAtomControlWord)&                  \
             GTM_ATOM_CLK_TPWM_MASK)

          GTM_SFR_INIT_USER_MODE_WRITE32(AtomChannelRegPtr->IRQ_MODE.U,\
            AtomChannelConfigPtr->GtmAtomIrqMode);

          AtomAgcRegPtr = &(MODULE_GTM.ATOM[ModuleNo]);
          GTM_SFR_INIT_USER_MODE_MODIFY32(AtomAgcRegPtr->AGC.FUPD_CTRL.U ,\
            GTM_WHOLE_REG,\
            (GTM_ATOM_ENABLE << (GTM_ATOM_BITS_PER_CHAN * (ChannelNo))))

          /* Enable SRN */
          GTM_SFR_INIT_MODIFY32((\
          MODULE_SRC.GTM.GTM[0].ATOM[ModuleNo][ChannelNo/2U].U),\
               GTM_SRC_CLEAR_MASK,\
               (unsigned_int)(GTM_BIT_SET << GTM_BIT_SRE))
        }
      }
    }
  }
}

#define GTM_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"



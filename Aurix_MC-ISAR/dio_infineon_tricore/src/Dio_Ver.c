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
**  $FILENAME   : Dio_Ver.c $                                                **
**                                                                           **
**  $CC VERSION : \main\21 $                                                 **
**                                                                           **
**  $DATE       : 2016-07-01 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This contains the functionality for DIO driver             **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
*******************************************************************************
** TRACEABILITY : [cover parentID= DS_NAS_DIO_PR699,DS_NAS_DIO_PR730,
                                   DS_MCAL_DIO_0517,
                                   DS_MCAL_DIO_0503_0504_0508,
                                   DS_MCAL_DIO_0509_1_0513_0_0500]      **
**                [/cover]                                                   **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Own header file, this includes own configuration file also */
/* DIO117: Inclusion structure */
#include "Dio.h"

/* AS Version Specific header file */
#include "Dio_Ver.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/* Version checks */

#ifndef DIO_AR_RELEASE_MAJOR_VERSION
  #error "DIO_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif

#ifndef DIO_AR_RELEASE_MINOR_VERSION
  #error "DIO_AR_RELEASE_MINOR_VERSION is not defined. "
#endif

#ifndef DIO_AR_RELEASE_REVISION_VERSION
  #error "DIO_AR_RELEASE_REVISION_VERSION is not defined. "
#endif

#if ( DIO_AR_RELEASE_MAJOR_VERSION != 4U)
  #error "DIO_AR_RELEASE_MAJOR_VERSION does not match. "
#endif

#if ( DIO_AR_RELEASE_MINOR_VERSION != 0U )
  #error "DIO_AR_RELEASE_MINOR_VERSION does not match. "
#endif


#if (DIO_DEV_ERROR_DETECT == STD_ON)

#ifndef DET_AR_RELEASE_MAJOR_VERSION
  #error "DET_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif

#ifndef DET_AR_RELEASE_MINOR_VERSION
  #error "DET_AR_RELEASE_MINOR_VERSION is not defined. "
#endif

/* UTP AI00251674 fix */
#if (IFX_DET_VERSION_CHECK == STD_ON)

#if ( DET_AR_RELEASE_MAJOR_VERSION != 4U )
  #error "DET_AR_RELEASE_MAJOR_VERSION does not match. "
#endif

#if ( DET_AR_RELEASE_MINOR_VERSION != 0U )
  #error "DET_AR_RELEASE_MINOR_VERSION does not match. "
#endif

#endif /* (IFX_DET_VERSION_CHECK == STD_ON) */

#endif /*#if (DIO_DEV_ERROR_DETECT == STD_ON)*/

/*******************************************************************************
**                      Private Variable macro                                **
*******************************************************************************/

/* IOCR0 register offset in Port_RegType */
#define DIO_PORT_IOCR0_REG_OFFSET  (4U)

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

#if((DIO_LOADABLE_USED == STD_ON) || (DIO_CONFIG_COUNT > 1U))
  #define DIO_START_SEC_VAR_32BIT
  #include "MemMap.h"

  const Dio_ConfigType  *Dio_kConfigPtr;

  #define DIO_STOP_SEC_VAR_32BIT
  /*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives
  is allowed only for MemMap.h*/
  #include "MemMap.h"
#else
  #if((DIO_DEV_ERROR_DETECT == STD_ON) || (DIO_SAFETY_ENABLE == STD_ON))
    #if(DIO_PB_FIXED_ADDRESS == STD_ON)
      #define DIO_START_SEC_CONST_32BIT
      #include "MemMap.h"

      const Dio_ConfigType * const Dio_kConfigPtr = &Dio_ConfigRoot[0];

      #define DIO_STOP_SEC_CONST_32BIT
      /*IFX_MISRA_RULE_19_01_STATUS=File inclusion after
        pre-processor directives is allowed only for MemMap.h*/
      #include "MemMap.h"
    #else
      #define DIO_START_SEC_VAR_32BIT
      #include "MemMap.h"

      const Dio_ConfigType  *Dio_kConfigPtr;

      #define DIO_STOP_SEC_VAR_32BIT
      /*IFX_MISRA_RULE_19_01_STATUS=File inclusion after
        pre-processor directives is allowed only for MemMap.h*/
      #include "MemMap.h"
    #endif /* DIO_PB_FIXED_ADDRESS == STD_ON */
  #endif /* DIO_DEV_ERROR_DETECT == STD_ON || DIO_SAFETY_ENABLE == STD_ON */
#endif /* DIO_LOADABLE_USED == STD_ON */

#if (DIO_DEV_ERROR_DETECT == STD_ON)
  #define DIO_START_SEC_VAR_8BIT
  /*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives
    is allowed only for MemMap.h*/
  #include "MemMap.h"
  /* Init Status Variable.
     It has to be initialized to "0U" after every reset,
     as "0" represents the deinitialized state */
  static  uint8 Dio_InitStatus;
  #define DIO_STOP_SEC_VAR_8BIT
  /*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives
    is allowed only for MemMap.h*/
  #include "MemMap.h"
#endif /* DIO_DEV_ERROR_DETECT == STD_ON */

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

#if(DIO_DEV_ERROR_DETECT == STD_ON)

/*Memory Map of the DIO Code*/
#define DIO_START_SEC_CODE
/*mapping of code and data to specific memory sections via memory mapping file*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives
  is allowed only for MemMap.h*/
#include "MemMap.h"

/* This function returns the init status of DIO module */
static uint8 Dio_lcheckDetStatus(uint8 ApiId);

/*Memory Map of the DIO Code*/
#define DIO_STOP_SEC_CODE
/*mapping of code and data to specific memory sections via memory mapping file*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives
  is allowed only for MemMap.h*/
#include "MemMap.h"

#endif /* DIO_DEV_ERROR_DETECT */


/*******************************************************************************
**                      Private Function Definition                           **
*******************************************************************************/

/*Memory Map of the DIO Code*/
#define DIO_START_SEC_CODE
/*mapping of code and data to specific memory sections via memory mapping file*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives
  is allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
** Traceability     : [cover parentID=DS_AS40X_DIO165,DS_AS40X_DIO166,
                       DS_AS40X_DIO167_DIO176,DS_AS40X_DIO129,
                       SAS_MCAL_AS4XX_DIO_0500]                               **
**                                                                            **
** Syntax           : void Dio_Init                                           **
**                    (                                                       **
**                      const Dio_ConfigType * ConfigPtr                      **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x10                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : ConfigPtr - Pointer to DIO configuration                **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - DIO166: Initializes all global variables of the Dio module             **
**                                                                            **
*******************************************************************************/
void Dio_Init(const Dio_ConfigType *ConfigPtr)
{
   #if((DIO_DEV_ERROR_DETECT == STD_ON) || (DIO_SAFETY_ENABLE == STD_ON))
   uint8 DetError;
   #if(DIO_PB_FIXED_ADDRESS == STD_OFF)
     if (ConfigPtr == NULL_PTR)
     {
        DetError = 1U;
     }
   #else
     if(ConfigPtr != Dio_kConfigPtr)
     {
        DetError = 1U;
     }
   #endif /*DIO_PB_FIXED_ADDRESS*/

   #if(DIO_SAFETY_ENABLE == STD_ON)
     else if((ConfigPtr->Dio_MarkerCheckValue) !=
      (((uint32)DIO_MODULE_ID << DIO_MODULEID_SHIFT_VAL) | DIO_INSTANCE_ID))
     {
        DetError = 1U;
     }
   #endif /* DIO_SAFETY_ENABLE == STD_ON */
   else
   {
      DetError = 0U;
   }
   if(DetError != 1U)
   #endif /* (DIO_DEV_ERROR_DETECT) || (DIO_SAFETY_ENABLE == STD_ON)*/
   {
   /* Store ConfigPtr to use in other APIs */
   #if((DIO_LOADABLE_USED == STD_ON) || (DIO_CONFIG_COUNT > 1U))
    Dio_kConfigPtr = ConfigPtr;
   #else
    #if((DIO_PB_FIXED_ADDRESS == STD_OFF) &&           \
        ((DIO_DEV_ERROR_DETECT == STD_ON) || (DIO_SAFETY_ENABLE == STD_ON)))
      Dio_kConfigPtr = ConfigPtr;
    #else
      UNUSED_PARAMETER(ConfigPtr)
    #endif /* PBfixed && (DET || Safety) */
   #endif /* DIO_LOADABLE_USED */

   #if(DIO_DEV_ERROR_DETECT == STD_ON)
   Dio_InitStatus = DIO_INITIALIZED;
   #endif /* DIO_DEV_ERROR_DETECT == STD_ON */
   }
   #if((DIO_DEV_ERROR_DETECT == STD_ON) || (DIO_SAFETY_ENABLE == STD_ON))
   else
   {
    #if(DIO_DEV_ERROR_DETECT == STD_ON)
       /* Report DIO_E_PARAM_CONFIG DET */
       Det_ReportError(
         (uint16)DIO_MODULE_ID,
         DIO_INSTANCE_ID,
         DIO_SID_INIT,
         DIO_E_PARAM_CONFIG);
    #endif /* DIO_DEV_ERROR_DETECT == STD_ON */

    #if(DIO_SAFETY_ENABLE == STD_ON)
       /* Report DIO_E_PARAM_CONFIG DET */
       SafeMcal_ReportError(
         (uint16)DIO_MODULE_ID,
         DIO_INSTANCE_ID,
         DIO_SID_INIT,
         DIO_E_PARAM_CONFIG);
    #endif /* DIO_SAFETY_ENABLE == STD_ON */
   }
   #endif
   /* DIO_DEV_ERROR_DETECT == STD_ON) || (DIO_SAFETY_ENABLE == STD_ON */
}/* Dio_Init */

#if (DIO_INITCHECK_API == STD_ON)
/*******************************************************************************
** Traceability     : [cover parentID= DS_MCAL_AS4XX_DIO_0528,
                                       DS_AS4XX_DIO_PR912_4,
**                                     DS_MCAL_AS4XX_DIO_0520,
**                                     DS_MCAL_AS4XX_DIO_0523,
**                                     DS_MCAL_AS4XX_DIO_0521,
**                                     DS_MCAL_AS4XX_DIO_0522]           **
**                                                                            **
** Syntax           : Std_ReturnType Dio_InitCheck                            **
**                    (                                                       **
**                      const Dio_ConfigType * ConfigPtr                      **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x10                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : ConfigPtr - Pointer to DIO configuration                **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      : This function verifies the initialization               **
**                    done by Dio_Init                                        **
*******************************************************************************/
Std_ReturnType Dio_InitCheck(const Dio_ConfigType *ConfigPtr)
{
  Std_ReturnType RetVal;

  RetVal = E_NOT_OK;

  if(Dio_kConfigPtr == ConfigPtr)
  {
    RetVal = E_OK;
  }
  return(RetVal);
}/* Dio_InitCheck */
#endif /* (DIO_INITCHECK_API == STD_ON) */

/* Enable / Disable the use of the function */
#if (DIO_FLIP_CHANNEL_API == STD_ON)
/*******************************************************************************
**                                                                            **
** Traceability     : [cover parentID=DS_AS40X_DIO190,DS_AS40X_DIO191,
                       DS_AS40X_DIO192,DS_AS40X_DIO193,DS_AS40X_DIO060_3,
                       DS_AS_DIO089,DS_AS40X_DIO118_4,DS_AS4XX_DIO_PR912_1]   **
**                                                                            **
** Syntax           : Dio_LevelType Dio_FlipChannel                           **
**                    (                                                       **
**                      Dio_ChannelType ChannelId                             **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x11                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : ChannelId - ChannelId whose level to be inverted        **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Dio_LevelType - The function returns value or the level **
**                  of the specified channel which is of type Dio_LevelType   **
**                                                                            **
** Description      : This function: Flip the channel level                   **
**      - DIO191: returns the inverted level of specified output channel      **
**      - DIO192: The specified channel is input, API shall have no influence **
**                      on the physical output of the channel                 **
**      - DIO193: The specified channel is input, API shall have no influence **
**                      on the result of next Read service                    **
**                                                                            **
**                                                                            **
*******************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
  Ifx_P           *GetPortAddressPtr;
  uint32           OmrVal;
  uint32           PinNumber;
  uint32           PinPosition;
  Dio_LevelType    RetVal;
  volatile uint32  *IocrRegPtr;

  RetVal = (Dio_LevelType)STD_LOW;
  OmrVal = DIO_OMR_RESET_BIT;

  #if(DIO_DEV_ERROR_DETECT == STD_ON)
  if(Dio_lcheckDetStatus(DIO_SID_FLIPCHANNEL) == DIO_NO_ERROR)
  #endif /* DIO_DEV_ERROR_DETECT == STD_ON */
  {
    /* Check for the validity of symbolic channel ID
       Reported DET if error detected */
  #if((DIO_SAFETY_ENABLE == STD_ON) || (DIO_DEV_ERROR_DETECT == STD_ON))
    if(Dio_lCheckChannelId(DIO_SID_FLIPCHANNEL,ChannelId) ==
              (uint8)DIO_NO_ERROR)
  #endif /*DIO_DEV_ERROR_DETECT == STD_ON || DIO_SAFETY_ENABLE == STD_ON*/
    {
      /* GetPortAddressPtr will hold the port address */
      GetPortAddressPtr = Dio_lGetPortAdr(Dio_lGetPortNumber(ChannelId));

      /* Get the IOCR0 register address of particular port */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used
        due to GetPortAddressPtr pointing to a structure and
        is within allowed range.*/
      IocrRegPtr = ((volatile uint32*)(volatile void*)GetPortAddressPtr +
                                                 DIO_PORT_IOCR0_REG_OFFSET);
      PinNumber = Dio_lGetPinNumber(ChannelId);

      /* Get the Pin position */
      PinPosition = ((uint32)0x01U << Dio_lGetPinNumber(ChannelId));

      /* Read the Channel level and decide the return value */
      if((PinPosition & (DIO_SFR_RUNTIME_USER_MODE_READ32\
                           (GetPortAddressPtr->IN.U)))!= (Dio_LevelType)STD_LOW)
      {
        /* current level of the channel*/
         RetVal = (Dio_LevelType)STD_HIGH;
      }
      /*Check the channel is configured as output channel*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used
        due to IocrRegPtr pointing to a structure and
        is within allowed range.*/
      if(((DIO_SFR_RUNTIME_USER_MODE_READ32(*(IocrRegPtr + \
           (PinNumber/DIO_NUM_FOUR))) >> DIO_IOCR0_BIT_SHIFT_COUNT(PinNumber))\
                   & (uint32)DIO_PORT_DIR_MSK) != (uint32)DIO_PORT_PIN_IN)
      {
         /* Invert the Level of dio channel */
         if(RetVal == STD_LOW)
         {
            RetVal = (Dio_LevelType)STD_HIGH;
            OmrVal = 0x01U;
         }
         else
         {
            RetVal = (Dio_LevelType)STD_LOW;
         }
         /* Write to the PORT OMR register to reflect at the channel*/
         DIO_SFR_RUNTIME_USER_MODE_WRITE32(GetPortAddressPtr->OMR.U, \
                                        (unsigned_int)(OmrVal << PinNumber));
      }
    }
  }
  return RetVal;
}/* Dio_FlipChannel */
#endif /*(DIO_FLIP_CHANNEL_API == STD_ON) */

#if(DIO_DEV_ERROR_DETECT == STD_ON)
/*******************************************************************************
** Syntax           : static uint8 Dio_lcheckDetStatus                        **
**                    (                                                       **
**                      uint8 ApiId                                           **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                           **
**                                                                            **
** Parameters (in)  : ApiId - Service ID                                      **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - This function returns the init status of DIO module                      **
*******************************************************************************/
static uint8 Dio_lcheckDetStatus(uint8 ApiId)
{
  if(Dio_InitStatus != DIO_INITIALIZED)
  {
    Det_ReportError(
      (uint16)DIO_MODULE_ID,
      DIO_INSTANCE_ID,
      ApiId,
      DIO_E_UNINIT);
  }
  return Dio_InitStatus;
}
#endif /* DIO_DEV_ERROR_DETECT */


#if((DIO_DEV_ERROR_DETECT == STD_ON) || (DIO_SAFETY_ENABLE == STD_ON))
/*******************************************************************************
** Syntax           : uint8 Dio_lErrorCheckChannelGroupDet                    **
**                    (                                                       **
**                      const Dio_ChannelGroupType *ChannelGroupIdPtr,        **
**                      uint8 ApiId                                           **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                           **
**                                                                            **
** Parameters (in)  : ApiId - Service ID                                      **
**                    *ChannelGroupIdPtr - Pointer to the Group ofchannels    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - This function returns the validity of the ChannelGroup                   **
*******************************************************************************/
uint8 Dio_lErrorCheckChannelGroupDet(
             const Dio_ChannelGroupType *ChannelGroupIdPtr,
             uint8 ApiId)
{
  uint8 RetVal;
  RetVal = DIO_ERROR;

  #if(DIO_DEV_ERROR_DETECT == STD_ON)
  if(Dio_lcheckDetStatus(ApiId) == (uint8)DIO_NO_ERROR)
  #endif /* DIO_DEV_ERROR_DETECT == STD_ON */
  {
     /* Check for the validity of group configuration
        Reports DET error if detected */
     if(Dio_lCheckGroupId(ApiId,ChannelGroupIdPtr) == (uint8)DIO_NO_ERROR)
     {
        RetVal = DIO_NO_ERROR;
     }
  }
  return RetVal;
}

/*******************************************************************************
** Syntax           : uint8 Dio_lErrorCheckChannelDet                         **
**                    (                                                       **
**                      Dio_ChannelType ChannelId,                            **
**                      uint8 ApiId                                           **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                           **
**                                                                            **
** Parameters (in)  : ApiId - Service ID                                      **
**                    ChannelId - Identifier for the PortPin                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - This function returns the validity of the ChannelId                      **
*******************************************************************************/
uint8 Dio_lErrorCheckChannelDet(
             Dio_ChannelType ChannelId,
             uint8 ApiId)
{
  uint8 RetVal;

  RetVal = DIO_ERROR;

  #if(DIO_DEV_ERROR_DETECT == STD_ON)
  if(Dio_lcheckDetStatus(ApiId) == (uint8)DIO_NO_ERROR)
  #endif /* DIO_DEV_ERROR_DETECT == STD_ON */
  {
     /* Check for the validity of group configuration
        Reports DET error if detected */
     if(Dio_lCheckChannelId(ApiId,ChannelId) == (uint8)DIO_NO_ERROR)
     {
        RetVal = DIO_NO_ERROR;
     }
  }
  return RetVal;
}

/*******************************************************************************
** Syntax           : uint8 Dio_lErrorCheckPortDet                            **
**                    (                                                       **
**                      Dio_ChannelType PortId,                               **
**                      uint8 ApiId                                           **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                           **
**                                                                            **
** Parameters (in)  : ApiId - Service ID                                      **
**                    PortId - Identifier for the Port                        **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - This function returns the validity of the PortId                         **
*******************************************************************************/
uint8 Dio_lErrorCheckPortDet(Dio_PortType PortId, uint8 ApiId)
{
  uint8 RetVal;
  RetVal = DIO_ERROR;

  #if(DIO_DEV_ERROR_DETECT == STD_ON)
  if(Dio_lcheckDetStatus(ApiId) == (uint8)DIO_NO_ERROR)
  #endif /* DIO_DEV_ERROR_DETECT == STD_ON */
  {
     /* Check for the validity of group configuration
        Reports DET error if detected */
     if(Dio_lCheckPortId(ApiId,PortId) == (uint8)DIO_NO_ERROR)
     {
        RetVal = DIO_NO_ERROR;
     }
  }
  return RetVal;
}

/*******************************************************************************
** Syntax           : uint8 Dio_lCheckChGrpValue                              **
**                    (                                                       **
**                      const Dio_ChannelGroupType *GroupIdPtr                **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                           **
**                                                                            **
** Parameters (in)  : ApiId - Service ID                                      **
**                    ChGroupId - Identifier for the Channel Group            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - This function returns the validity of the ChGrpId                        **
*******************************************************************************/
uint8 Dio_lCheckChGrpValue(const Dio_ChannelGroupType *GroupIdPtr)
{
#if((DIO_CONFIG_COUNT == 1U) || (DIO_CH_GRP_SET_U > 1U))
   uint32 Index;
#endif
   uint8  ErrStatus = DIO_ERROR;

#if(DIO_CONFIG_COUNT == 1U)
   for(Index = 0U;Index < (Dio_kConfigPtr->Dio_ChannelGroupConfigSize);Index++)
   {
     /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used
       due to PBConfigStructure and is within allowed range.*/
     if (GroupIdPtr == &(Dio_kConfigPtr->Dio_ChannelGroupConfigPtr[Index]))
     {
     /*DIO114: channel group is valid within the current configuration*/
       ErrStatus = (uint8)DIO_NO_ERROR;
       break;
     }
   }
#else
  #if(DIO_CH_GRP_SET_U == 1U)
   if (GroupIdPtr == &(Dio_kConfigPtr->Dio_ChGrpIdMap[0U]))
   {
   /*DIO114: channel group is valid within the current configuration*/
     ErrStatus = (uint8)DIO_NO_ERROR;
   }
  #elif(DIO_CH_GRP_SET_U > 1U)
   for(Index = 0U; Index < (DIO_CH_GRP_SET_U); Index++)
   {
     if (GroupIdPtr == &(Dio_kConfigPtr->Dio_ChGrpIdMap[Index]))
     {
     /*DIO114: channel group is valid within the current configuration*/
       ErrStatus = (uint8)DIO_NO_ERROR;
       break;
     }
   }
  #else
   UNUSED_PARAMETER(GroupIdPtr)
  #endif /* DIO_CH_GRP_SET_U > 1U */
#endif

   return ErrStatus;
}

/*******************************************************************************
** Syntax           : uint8 Dio_lCheckAnalogChannel                           **
**                    (                                                       **
**                      uint8 ApiId, uint32 PortReadOnly                      **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                           **
**                                                                            **
** Parameters (in)  : ApiId - Service ID                                      **
**                    PortReadOnly - Flag to represent Analog PortPins        **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - This function returns status for Read/Write Called on Analog Ports       **
*******************************************************************************/
uint8 Dio_lCheckAnalogChannel(uint8 ApiId, uint32 PortReadOnly)
{
   uint8 ErrStatus;
   ErrStatus = (uint8)DIO_NO_ERROR;

   #if( DIO_FLIP_CHANNEL_API == STD_ON )
   if( ( (ApiId == DIO_SID_WRITECHANNEL) ||
         (ApiId == DIO_SID_FLIPCHANNEL)
       ) &&  (PortReadOnly != 0U)
     )
     {
       /* Error status = Error has occurred */
       ErrStatus = (uint8)DIO_ERROR;
     }
   #else
   if( (ApiId == DIO_SID_WRITECHANNEL) &&  (PortReadOnly != 0U) )
   {
     /* Error status = Error has occurred */
     ErrStatus = (uint8)DIO_ERROR;
   }
   #endif
   return ErrStatus;
}

/*******************************************************************************
** Syntax           : uint8 Dio_lCheckAnalogPort                              **
**                    (                                                       **
**                      uint8 ApiId, uint32 PortReadOnly                      **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                           **
**                                                                            **
** Parameters (in)  : ApiId - Service ID                                      **
**                    PortReadOnly - Flag to represent Analog PortPins        **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - This function returns status for Read/Write Called on Analog Ports       **
*******************************************************************************/
uint8 Dio_lCheckAnalogPort(uint8 ApiId, uint32 PortReadOnly)
{
   uint8 ErrStatus;
   ErrStatus = (uint8)DIO_NO_ERROR;

   if( (ApiId == DIO_SID_WRITEPORT) &&  (PortReadOnly != 0U) )
   {
     /* Error status = Error has occurred */
     ErrStatus = (uint8)DIO_ERROR;
   }
   return ErrStatus;
}

#endif /* DIO_DEV_ERROR_DETECT == STD_ON || DIO_SAFETY_ENABLE == STD_ON*/

/*Memory Map of the DIO Code*/
#define DIO_STOP_SEC_CODE
/*mapping of code and data to specific memory sections via memory mapping file*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives
  is allowed only for MemMap.h*/
#include "MemMap.h"

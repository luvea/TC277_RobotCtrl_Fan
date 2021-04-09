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
**   $FILENAME   : Adc.c $                                                    **
**                                                                            **
**   $CC VERSION : \main\81 $                                                 **
**                                                                            **
**   $DATE       : 2016-09-06 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : This file contains                                         **
**                 - functionality of Adc driver.                             **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**  TRACEABILITY: [cover parentID=SAS_AS_ADC267,DS_NAS_ADC_PR915,
DS_NAS_ADC_PR69_PR469,DS_NAS_ADC_PR912,DS_NAS_ADC_PR759_PR760_PR761,
DS_AS321_ADC354,SAS_NAS_ALL_PR749,SAS_NAS_ALL_PR128,SAS_MCAL_ADC_0437,
SAS_NAS_ALL_PR630_PR631,SAS_NAS_ALL_PR102,SAS_NAS_ALL_PR70,SAS_NAS_ALL_PR471,
SAS_NAS_ALL_PR470,SAS_NAS_ALL_PR1652]**
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - functionality of Adc driver.                             **
**                                                                            **
**  [/cover]                                                                  **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* ADC267: The file include structure */
/* Own header file, this includes own configuration file also */
/* Inclusion structure */
#include "Adc.h"
#include "Adc_Utility.h"
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/* Version check is done in Adc_Ver.c */
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define ADC_START_SEC_CODE
#include "MemMap.h"
    
#if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
/* DET check for API input parameters */
static uint32 Adc_lValidateParamGroup 
                     (uint8 ServiceId, Adc_GroupType Group, uint8 AdcKernel);

#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */

#if (ADC_DEV_ERROR_DETECT == STD_ON)
  
/* DET check function: ADC_E_UNINIT*/
IFX_LOCAL_INLINE uint32 Adc_lCheckInit(uint8 ServiceId);

#if (ADC_DEINIT_API == STD_ON)
IFX_LOCAL_INLINE Adc_StatusType Adc_lCheckGroupStatusAll(void);
#endif /* (ADC_DEINIT_API == STD_ON) */

#if((ADC_ENABLE_START_STOP_GROUP_API == STD_ON)||(ADC_HW_TRIGGER_API == STD_ON))
/* DET check for Driver status when API service is called */
static uint32 Adc_lCheckDriverState
                     (uint8 ServiceId, Adc_GroupType Group, uint8 AdcKernel);
#endif /* ADC_ENABLE_START_STOP_GROUP_API or ADC_HW_TRIGGER_API is STD_ON */

#if( (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) &&\
                               (ADC_RESULT_POLLING_MODE == STD_OFF) )
/* DET check for Driver status when Start Group API service is called */
static uint32 Adc_lCheckStateForStartGroup
(
  Adc_GroupType Group, 
  uint8 AdcKernel
);
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

#if( (ADC_HW_TRIGGER_API == STD_ON) && (ADC_RESULT_POLLING_MODE == STD_OFF) )
/* DET check for Driver status when Enable Group API service is called */
static uint32 Adc_lCheckStateForEnableGroup
(
  Adc_GroupType Group,
  uint8 AdcKernel
);
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
  
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
/* DET check for resource conflict when Start / Enable Group API 
   service is called 
*/
static uint32 Adc_lCheckResourceConflict
( 
  Adc_GlobalDataType *DataPtr,
  const Adc_GroupCfgType *GrpPtr,
  uint8 ServiceId
);
#endif /* (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) */
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

#define ADC_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#if (ADC_PB_FIXED_ADDRESS == STD_OFF)
#define ADC_START_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
allowed only for MemMap.h*/
#include "MemMap.h"

/* To store the Adc driver configuration pointer */
const Adc_ConfigType  *Adc_kConfigPtr;

#define ADC_STOP_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
allowed only for MemMap.h*/
#include "MemMap.h"
#endif /*(ADC_PB_FIXED_ADDRESS == STD_OFF)*/
  
#if(ADC_PB_FIXED_ADDRESS == STD_ON)
#define ADC_START_SEC_CONST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
allowed only for MemMap.h*/
#include "MemMap.h"

/* To store the Adc driver configuration pointer */
const Adc_ConfigType * const Adc_kConfigPtr = &Adc_ConfigRoot[0];

#define ADC_STOP_SEC_CONST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
allowed only for MemMap.h*/
#include "MemMap.h"
#endif /*(ADC_PB_FIXED_ADDRESS == STD_ON) */
  
/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

#define ADC_START_SEC_VAR_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
allowed only for MemMap.h*/
#include "MemMap.h"
#if (ADC_REQSRC2 == ADC_REQSRC_USED)
/* variables used for Background request source */
uint8 Adc_BgndScanData;
uint8 Adc_BgndGrpCnt;
#endif /* (ADC_REQSRC2 == ADC_REQSRC_USED) */

#if (ADC_DEV_ERROR_DETECT == STD_ON)
/* Init Status Variable. It has to be initialized to "0U" after every reset as 0
   represents the deinitialized state */
uint8 Adc_InitStatus;
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

#define ADC_STOP_SEC_VAR_8BIT
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
#define ADC_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
allowed only for MemMap.h*/
#include "MemMap.h"

#if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
/*******************************************************************************
** Traceabilty      :[cover parentID=DS_AS_ADC419,DS_AS_ADC413_1,
                     DS_AS_ADC067_ADC234_2,DS_AS_ADC423,DS_AS_ADC433,
                     DS_AS_ADC434,DS_AS_ADC457,DS_AS_ADC420,DS_AS_ADC415,
                     DS_AS_ADC318,DS_AS_ADC319,DS_AS_ADC320,DS_MCAL_ADC_0413_2]
** Syntax           : Std_ReturnType Adc_SetupResultBuffer                    **
**                    (                                                       **
**                      Adc_GroupType Group,                                  **
**                      Adc_ValueGroupType* DataBufferPtr                     **
**                    )                                                       **
**[/cover]                                                                    **
**                                                                            **
** Service ID       : 0x0C                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters(in)   : Group ID and Data buffer pointer                        **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK/E_NOT_OK                                           **
**                                                                            **
** Description      : This function:                                          **
**   - ADC420:  The function shall initialize the result buffer pointer       **
**              of the selected group with the address value                  **
**              passed as parameter.                                          **
**   - ADC421, ADC422 :  The ADC module's environment shall ensure that       **
**              result buffer are initialised before group conversions and    **
**              has size to hold streaming result if configured               **
**   - ADC423 : Checks for DET: ADC_E_PARAM_GROUP                             **
**   - Checks for DET: ADC_E_BUSY                                             **
**                                                                            **
*******************************************************************************/
Std_ReturnType Adc_SetupResultBuffer
(
  Adc_GroupType Group,
  Adc_ValueGroupType* DataBufferPtr 
)
{
  Adc_GlobalDataType        *DataPtr;
  #if (ADC_SAFETY_ENABLE == STD_ON)
  const Adc_GroupCfgType    *GrpPtr;
  #endif /* (ADC_SAFETY_ENABLE == STD_ON) */
  #if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
  uint32                    Err;
  #endif
  /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */
  Adc_GroupType             GroupId;
  Std_ReturnType            RetStatus;
  uint8                     Kernel;

  #if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
  /* Initializing the return value */
  RetStatus = (Std_ReturnType)E_NOT_OK;
  #endif
  /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */
  
  /* Get Kernel number from Group ID */
  Kernel = (uint8)Adc_lGetAdcKernel(Group);
  /* Get the Group Id for perticular kernel */
  GroupId = (Adc_GroupType)Adc_lGetKernelGroupId(Group);

  #if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )

  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* ADC434: Check for DET error ADC_E_UNINIT */
  Err = Adc_lCheckInit(ADC_SID_SETUP_RESULT_BUFFER);

  if (Err == ADC_E_DET_NO_ERR)
  #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ADC423 : Check for ADC_E_PARAM_GROUP */
    Err = Adc_lValidateParamGroup(ADC_SID_SETUP_RESULT_BUFFER, GroupId, Kernel);
  }

  if (Err == ADC_E_DET_NO_ERR)
  {
    #if (ADC_SAFETY_ENABLE == STD_ON)
    /* Get the Adc Group Configuration Pointer */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    PBConfigStructure and is within allowed range*/
    GrpPtr = Adc_kConfigPtr->CfgPtr[Kernel]->GrpCfgPtr + GroupId;
    #endif /* (ADC_SAFETY_ENABLE == STD_ON) */
  
    /* ADC457 : Check for ADC_E_PARAM_POINTER */
    if(DataBufferPtr == NULL_PTR)
    {
      #if (ADC_DEV_ERROR_DETECT == STD_ON)
      Det_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE,
                       ADC_SID_SETUP_RESULT_BUFFER, ADC_E_PARAM_POINTER
                     );
      #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

      Err = (uint32)ADC_E_PARAM_POINTER;
    }
    #if (ADC_SAFETY_ENABLE == STD_ON)
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    Group Configuration Structure and is within allowed range*/
    else if(DataBufferPtr[0] != GrpPtr->BufferMarker)
    {
      SafeMcal_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE,
                            ADC_SID_SETUP_RESULT_BUFFER, ADC_E_PARAM_POINTER
                          );

      Err = (uint32)ADC_E_PARAM_POINTER;
    }
    #endif /* (ADC_SAFETY_ENABLE == STD_ON) */
    else
    {
      /* do nothing */
    }
  }
  
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  
  if (Err == ADC_E_DET_NO_ERR)
  {
    /* ADC433: Check for ADC_E_BUSY
       Service is called while requested group is already 
       started / Enabled. Which Implies Group result buffer pointer is 
       already initialised and stated/Enabled for conversion
    */
    Err = Adc_lCheckDriverState(ADC_SID_SETUP_RESULT_BUFFER, GroupId, Kernel);
  }
  #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
  
  if (Err == ADC_E_DET_NO_ERR)
  #endif
  /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */
  {
    /* Get ADC Kernel index for variables */
    /* Assign the address of ASIL or QM signal variable to global data pointer*/
    DataPtr = Adc_lGetDataAddress(Kernel);
    
    /* Set up the Group result buffer pointer to be used by the driver */
    DataPtr->GroupResultBuffer[GroupId] = DataBufferPtr;
    /* Initialize the number of conversion result set available to 0 */
    DataPtr->NumValidConRes[GroupId] = (Adc_StreamNumSampleType)0;

    /* ADC419 return value column: */
    /* Returning Result buffer pointer initialised correctly */
    RetStatus = (Std_ReturnType)E_OK;
  }
  return (RetStatus);

}/* Adc_SetupResultBuffer */
#endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */

/* Enable/Disable the use of the function */
#if (ADC_DEINIT_API == STD_ON)
/*******************************************************************************
** Traceabilty      :[cover parentID=DS_AS_ADC366,DS_AS_ADC111,DS_AS_ADC228,
                     DS_AS_ADC067_ADC234_3,DS_AS_ADC154,DS_AS_ADC112,
                     DS_AS_ADC110]
** Syntax           : void Adc_DeInit                                         **
**                    (                                                       **
**                      void                                                  **
**                    )                                                       **
**[/cover]                                                                    **
**                                                                            **
** Service ID       : 0x01                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - ADC110: This service shall return all ADC HW Units to a state          **
**             comparable to their power on reset state.                      **
**   - ADC111: The service shall disable all used interrupts and notifications**
**   - ADC112:This service shall not be called while a conversion is ongoing. **
**   - ADC228: This function shall available only if configuration parameter: **
**             ADC_DEINIT_API is switched On                                  **
**                                                                            **
*******************************************************************************/
void Adc_DeInit( void )
{
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  uint32                      Err;
  #endif
  #if (ADC_GROUP_EMUX_SCAN == STD_ON)
  const Adc_HwUnitCfgType     *HwCfgPtr;
  uint32                       LoopCtr;
  uint32                       EmuxKernel;
  Dma_ChannelType              AdcDmaChannel;
  uint8                        AdcKernel;
  #endif
  uint8                        ClcStatus;
  
  ClcStatus = 1U;
/*-----------------------------------**
** Check for Development Time Errors **
**-----------------------------------*/
/* ADC234, ADC067: Detected development errors shall be reported to the 
   Det_ReportError service 
*/
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* ADC154: Check for DET error ADC_E_UNINIT */
  Err = Adc_lCheckInit(ADC_SID_DEINIT);

  if (Err == ADC_E_DET_NO_ERR)
  {
    /* ADC112 : Check for ADC_E_BUSY */

    /* Check by verifying the Group status being busy. 
       If a group is in the Queue still, its status will be busy.
       For any group whose conversion is ongoing, its state will be 
       ADC_BUSY/ADC_COMPLETE/ADC_STREAM_COMPLETED.
       In this senario, Adc_DeInit will not be serviced.
       The Groups which have implicitly stopped conversion, 
       its state will be ADC_STREAM_COMPLETED.
       In this senario, Adc_DeInit will be serviced.
    */
    Err = (uint32)Adc_lCheckGroupStatusAll();
    
    if (Err == ADC_E_BUSY)
    {
      /* Group is enabled in the Queue */
      /* ADC112: Service is called while queue is still not empty */    
      Det_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE, 
                       ADC_SID_DEINIT, ADC_E_BUSY
                     );
    }
  }

  if (Err == ADC_E_DET_NO_ERR)
  #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /*------------------------------------------------------**
    ** De-Initialisation of module registers to reset value **
    **------------------------------------------------------*/
    Adc_lDeInitWriteKernelRstSfr( ADC_KERNEL_RESET );

    #if (ADC_GROUP_EMUX_SCAN == STD_ON)
    
    EmuxKernel = Adc_kConfigPtr->GlobCfgPtr->EmuxSelectGrp;
    LoopCtr = 0U;
    do
    {
      AdcKernel = Adc_lGetEmuxKernel(EmuxKernel,(uint8)LoopCtr);
    
      if ( Adc_kConfigPtr->CfgPtr[AdcKernel] != NULL_PTR )
      {
        /* Get ADC kernel HW Unit Config pointer */
        HwCfgPtr = Adc_kConfigPtr->CfgPtr[AdcKernel]->HwCfgPtr;
        /* read the configured DMA channel */
        AdcDmaChannel = (Dma_ChannelType)HwCfgPtr->DmaChannel;
      
        if(AdcDmaChannel != DMA_CHANNEL_INVALID)
        {
          /* ReSet DMA Channel registers */
          ADC_SFR_DEINIT_MCAL_DMARESETDMACHANNEL(AdcDmaChannel);
        }
      }
      LoopCtr++;
      
    } while (LoopCtr < ADC_MAX_EMUX_KERNELS);

    #endif /* (ADC_GROUP_EMUX_SCAN == STD_ON) */

    #if (ADC_CCU6_SYNCHRONIZATION == STD_ON)
    /* Deinitialization of CCU6 module */
    ClcStatus &= Adc_lCcu6DeInit();
    #endif /* (ADC_CCU6_SYNCHRONIZATION == STD_ON) */

    #if (ADC_RESULT_POLLING_MODE == STD_OFF)
    /* ADC HW Unit Service Request Control Register.
       One set of SRN Available for all ADC Kernel 
       Disable Service request
    */
    Adc_lDeInitSetResetSre(ADC_DISABLE_INTERRUPT);
    #endif /* (ADC_RESULT_POLLING_MODE == STD_OFF) */
    
    /*----------------**
    ** Disable module **
    **----------------*/
    ClcStatus &= Adc_lDeInitWriteClcSfr((uint32)ADC_MODULE_DISABLE, \
                                                       ADC_SID_DEINIT);

    /*---------------------------------------------------------------**
    ** De-initialise the configuration structure pointer to NULL_PTR **
    **---------------------------------------------------------------*/

    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    if(ClcStatus != 0U)
    {
      Adc_InitStatus = (uint8)0;
    }
    #else
    /* to remove the unused param warning in GNU */
    UNUSED_PARAMETER(ClcStatus)
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

  }
  return;
  
}/* Adc_DeInit */
#endif /* (ADC_DEINIT_API == STD_ON) */

/* Enable/Disable the use of the function */
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/*******************************************************************************
** Traceabilty      :[cover parentID=DS_AS_ADC367,DS_AS_ADC061,DS_AS_ADC431,
                     DS_AS_ADC156,DS_AS_ADC413_2,DS_AS_ADC067_ADC234_4,
                     DS_AS_ADC259,DS_AS_ADC294,DS_AS_ADC125,DS_AS_ADC133,
                     DS_AS_ADC424,DS_AS_ADC346,DS_AS_ADC426,DS_AS_ADC348,
                     DS_AS_ADC427,DS_AS_ADC351,DS_AS_ADC428,DS_AS_ADC280,
                     DS_AS_ADC415,DS_AS_ADC338,DS_AS_ADC417,DS_MCAL_ADC_0413_3]
** Syntax           : void Adc_StartGroupConversion                           **
**                    (                                                       **
**                      Adc_GroupType Group                                   **
**                    )                                                       **
**[/cover]                                                                    **
**                                                                            **
** Service ID       : 0x02                                                    **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : re-entrant                                              **
**                                                                            **
** Parameters(in)   : Group - Numeric ID of requested ADC Channel group.      **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - ADC061: This service shall start the conversion of all channels of the **
**             requested ADC Channel group.                                   **
**   - ADC146: This service can only be used for groups configured in software**
**             trigger mode ADC_GROUP_CONV_MODE                               **
**   - ADC259: This function shall available only if configuration parameter: **
**             ADC_ENABLE_START_STOP_GROUP_API is switched On                 **
**                                                                            **
*******************************************************************************/
void Adc_StartGroupConversion
(
  Adc_GroupType Group
)
{
  #if ( (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_HW_SW) && \
                                               (ADC_ENABLE_QUEUING == STD_OFF) )
  Adc_GlobalDataType *DataPtr;
  #endif /* (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_HW_SW) */
  #if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
  uint32 Err;
  #endif
  /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */

  #if ( (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_HW_SW) &&\
        (ADC_ENABLE_QUEUING != STD_ON)\
      )
  const Adc_GroupCfgType    *GrpPtr;
  uint32 GrpRequestSource;
  #if (ADC_REQSRC2 == ADC_REQSRC_USED)
  uint8 LoopCnt;
  #endif /* (ADC_REQSRC2 == ADC_REQSRC_USED) */
  #endif /* (Priority is not ADC_PRIORITY_HW_SW) and (Queue is STD_OFF) */
  Adc_GroupType GroupId;
  uint8 Kernel;


  /* Get Kernel number from Group ID */
  Kernel = (uint8)Adc_lGetAdcKernel(Group);
  /* Get the Group Id for perticular kernel */
  GroupId = (Adc_GroupType)Adc_lGetKernelGroupId(Group);

/*-------------------------------------**
** Check for Developement Time Errors  **
**-------------------------------------*/
/* ADC234, ADC067: Detected development errors shall be reported to the 
   Det_ReportError service 
*/
  #if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )

  #if (ADC_DEV_ERROR_DETECT == STD_ON)

  /* ADC294: Check for DET error ADC_E_UNINIT */
  Err = Adc_lCheckInit(ADC_SID_START_GROUP_CONVERSION);

  if (Err == ADC_E_DET_NO_ERR)
  #endif  /* (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ADC125 : Check for ADC_E_PARAM_GROUP
       ADC133 : Check for ADC_E_WRONG_TRIGG_SRC
       ADC424 : Check for ADC_E_BUFFER_UNINIT
    */
    Err = 
      Adc_lValidateParamGroup(ADC_SID_START_GROUP_CONVERSION, GroupId, Kernel);
  }

/* Check for Group Busy Status. This status is checked only when DET is STD_ON.
In the production mode the user should not make any calls
that leads to ADC_E_BUSY. Failing to do so may lead to arbitrary behavior of the
driver.*/
    
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* Enter Critical Section */
  Adc_lSchmEnterStartGroup();

  #if (ADC_RESULT_POLLING_MODE == STD_OFF)
  if (Err == ADC_E_DET_NO_ERR)
  {
    /*  Check for ADC_E_BUSY */
    Err = Adc_lCheckStateForStartGroup(GroupId, Kernel);

  }
  #endif  /* (ADC_RESULT_POLLING_MODE == STD_OFF) */
  #endif  /* (ADC_DEV_ERROR_DETECT == STD_ON) */
  
  if (Err != ADC_E_DET_NO_ERR)
  {
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    Adc_lSchmExitStartGroup(); 
    /* Exit Critical Section */
  
    /*Note: The Status variables have to be checked and updated in a critical 
    section only in the case of DET == STD_ON. This is because the status check
    is done only in the Developement code */
    #endif  /* (ADC_DEV_ERROR_DETECT == STD_ON) */

    /* do nothing incase SAFETY == STD_ON and DET == STD_OFF */
  }
  else
  #endif
  /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */
  {

    #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)

    /* Call the Priority Scheduler */
    Adc_lSchedulerOnStart(Kernel,GroupId);

    /* HW Priority or No Priority */
    /* Queue Enable is STD_ON only during No priority */
    #elif (ADC_ENABLE_QUEUING == STD_ON)
    /* Call the Push on Queue function which handles the start of the Group 
       througn Queue
    */
    Adc_lPushOnQueue(Kernel,GroupId);

    #else /* If Queue mechanism not enabled in No priority / HW priority */

    /* Get ADC Kernel index for variables */
    /* Assign the address of ASIL or QM signal variable to global data pointer*/
    DataPtr = Adc_lGetDataAddress(Kernel);
    /* Get the Adc Group Configuration Pointer */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    PBConfigStructure and is within allowed range*/
    GrpPtr = Adc_kConfigPtr->CfgPtr[Kernel]->GrpCfgPtr + GroupId;
    /* Get the configured Group request source */
    GrpRequestSource = (uint32)(GrpPtr->GrpRequestSrc);

  /*-------------------------------**
  **  Update all Status Variables  **
  **-------------------------------*/

    #if(ADC_RESULT_POLLING_MODE == STD_OFF)
    /* Group status of given group is made ADC_BUSY */
    Adc_lSetGroupStatusBusyAtomic(DataPtr,GroupId);
    #endif /* (ADC_RESULT_POLLING_MODE == STD_OFF) */
   
    /* GrpId is updated with the requested Group */
    DataPtr->TriggSrcData[GrpRequestSource].GrpId = GroupId;

    #if (ADC_REQSRC2 == ADC_REQSRC_USED)
    /* Background request source is triggered */
    if(GrpRequestSource == ADC_REQSRC2_BGND_SCAN)
    {
      Adc_BgndScanData = ADC_TRIGG_SRC_SW;
      /*IsrDoNothing is set to 1. One-Shot Single access group UTP AI00132372*/
      LoopCnt = 0U;
      #if (ADC_QM_KERNEL_USED_COUNT > 1U)
      do
      #endif
      {
        Adc_QmSignal[LoopCnt].TriggSrcData[GrpRequestSource].IsrDoNothing = 
                                                                ADC_NO_SERVICE;

        #if (ADC_QM_KERNEL_USED_COUNT > 1U)
        LoopCnt++;
        #endif
      
      }
      #if (ADC_QM_KERNEL_USED_COUNT > 1U)
      while (LoopCnt < ADC_QM_KERNEL_USED_COUNT);
      #endif
    }
    #endif /* (ADC_REQSRC2 == ADC_REQSRC_USED) */

    #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
    /* Clear ADC Group Result Status */
    Adc_lClrGroupResultAtomic(DataPtr,GroupId);

    /* Initialize the number of conversion result set available to 0 */
    DataPtr->NumValidConRes[GroupId] = (Adc_StreamNumSampleType)0;
    #endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */
    /*Note: The Result Status is cleared at every start even if it is also 
      cleared at every Stop. This is because we assume that the user may call 
      Adc_StartGroup twice without explicitly calling Adc_StopGroup essentially 
      in the case of implicitly stopping functions (Oneshot, streaming - linear)
    */
    #if(ADC_RESULT_POLLING_MODE == STD_OFF)
    /* Reset the End result status to 0 */
    Adc_lClrResBuffEndStatusAtomic(DataPtr,GroupId);
    #endif /* (ADC_RESULT_POLLING_MODE == STD_OFF) */
    
    #if (ADC_DEV_ERROR_DETECT == STD_ON)  
    Adc_lSchmExitStartGroup(); 
    /* Exit Critical Section */

    /*Note: The Status variables have to be checked and updated in a critical 
    section only in the case of DET == STD_ON. This is because the status check
    is done only in the Developement code */
    #endif  /* (ADC_DEV_ERROR_DETECT == STD_ON) */
    
  /*----------------------------------------------------------------------**
  ** Set Up ADC Channels :Prepare Group channels by configuring in CHCtr  **
  ** register and update TriggSrcData                                     **
  **----------------------------------------------------------------------*/
                                               
    Adc_lPrepareGrpForStart(Kernel,GroupId);

    #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
    /* Update the RS Group data */
    Adc_lUpdateRsGroupData(Kernel,GrpPtr);
    #endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */
    
    /*
      Clear the No ISR service flag for the trigger source. Which might have set
      if Stop API is called.
    */
    DataPtr->TriggSrcData[GrpRequestSource].IsrDoNothing = (uint8)0;
    /* Note: In case of short conversion time, ISR no service flag has to be 
       cleared before the first conversion complete interrupt
    */

  /*-----------------------------------------------------**
  ** Trigger Conversion Source :Trigger the appropriate  **
  ** Conversion Request Source                           **
  **-----------------------------------------------------*/
                            
    Adc_lStartSwConversionRS(GrpPtr,Kernel);

    #endif /* No Priority No Queue / HW Priority */
  }
  
}/* Adc_StartGroupConversion */
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */


/* Enable/Disable the use of the function */
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/*******************************************************************************
** Traceabilty      :[cover parentID=DS_AS_ADC368,DS_AS_ADC260,DS_AS_ADC413_3,
                     DS_AS_ADC067_ADC234_5,DS_AS_ADC385_ADC386,
                     DS_AS_ADC437_ADC438,DS_AS_ADC360,DS_AS_ADC155,DS_AS_ADC295,
                     DS_AS_ADC126,DS_AS_ADC164,DS_AS_ADC241,DS_AS_ADC415,
                     DS_MCAL_ADC_0413_4]
** Syntax           : void Adc_StopGroupConversion                            **
**                    (                                                       **
**                      Adc_GroupType Group                                   **
**                    )                                                       **
**[/cover]                                                                    **
**                                                                            **
** Service ID       : 0x03                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : re-entrant                                              **
**                                                                            **
** Parameters(in)   : Group - Numeric ID of requested ADC Channel group.      **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - ADC072: This service shall stop the conversion of the requested ADC    **
**             Channel group.                                                 **
**   - ADC155: Stopping a group conversion shall automatically disable group  **
**             notification for the requested group.                          **
**   - ADC283: This service can only be used for groups configured in software**
**             trigger mode ADC_GROUP_CONV_MODE                               **
**   - ADC260: This function shall available only if configuration parameter: **
**             ADC_ENABLE_START_STOP_GROUP_API is switched On                 **
**                                                                            **
*******************************************************************************/
void Adc_StopGroupConversion
(
  Adc_GroupType Group
)
{
  #if ( (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_HW_SW) && \
                                               (ADC_ENABLE_QUEUING == STD_OFF) )
  Adc_GlobalDataType     *DataPtr;
  #endif /* (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_HW_SW) */
  #if ( (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_HW_SW) &&\
      (ADC_ENABLE_QUEUING != STD_ON)\
    )
  const Adc_GroupCfgType *GrpPtr;
  #endif
  #if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
  uint32                  Err;
  #endif
  /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */
  Adc_GroupType           GroupId;
  uint8                   Kernel;

  /*-------------------------------------**
  ** Check for Developement Time Errors  **
  **-------------------------------------*/
  /* ADC234, ADC067: Detected development errors shall be reported to the 
     Det_ReportError service 
  */
  Kernel = (uint8)Adc_lGetAdcKernel(Group);
  /* Get the Group Id for perticular kernel */
  GroupId = (Adc_GroupType)Adc_lGetKernelGroupId(Group);

  #if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
  
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  /* ADC295: Check for DET error ADC_E_UNINIT */
  Err = Adc_lCheckInit(ADC_SID_STOP_GROUP_CONVERSION);

  if (Err == ADC_E_DET_NO_ERR)
  #endif  /* (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ADC126 : Check for ADC_E_PARAM_GROUP
       ADC164 : Check for ADC_E_WRONG_TRIGG_SRC
    */
    Err = Adc_lValidateParamGroup
            (ADC_SID_STOP_GROUP_CONVERSION, GroupId, Kernel);
  }
  
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  
  if (Err == ADC_E_DET_NO_ERR)
  {
    /* ADC241 : Check for ADC_E_IDLE */
    Err = Adc_lCheckDriverState
          (ADC_SID_STOP_GROUP_CONVERSION, GroupId, Kernel);
  }
  #endif  /* (ADC_DEV_ERROR_DETECT == STD_ON) */
  
  if (Err == ADC_E_DET_NO_ERR)
  #endif
  /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */
  {
    /* Full priority considered */
    #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)
    /* Call scheduler */
    Adc_lSchedulerOnStop(Kernel,GroupId);

    /* Queue Enable is STD_ON only during No priority */
    #elif (ADC_ENABLE_QUEUING == STD_ON)
    /* Call the Pop From Queue function which handles the stop request 
       of the Group 
    */
    Adc_lPopFromQueue(Kernel,GroupId);
    #else /* If Queue mechanism not enabled in No priority / HW priority */

    /* Get ADC Kernel index for variables */
    /* Assign the address of ASIL or QM signal variable to global data pointer*/
    DataPtr = Adc_lGetDataAddress(Kernel);
    /* Get the Adc Group Configuration Pointer */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    PBConfigStructure and is within allowed range*/
    GrpPtr = Adc_kConfigPtr->CfgPtr[Kernel]->GrpCfgPtr + GroupId;

    /*Note:
      Set a no ISR service flag for the trigger source. 
      By this disabing the service request for the node is not required.
      Note: There is a chance that the Group has already stopped in ISR and 
      new Group of same trigger source might have started. While going ahead in 
      stop may reset the trigger source data. To avoid this cause, service the 
      Stop depending upon the Group status
    */
    /* Note: 
       There is a chance that, an ISR of this Group - Oneshot, 
       continuous - Linear 
       will change the status of the Group to IDLE and 
       sets the trigger source data free and allow to start 
       an another Group with same trigger source as which 
       has called for stop. 
       1. After new start the control in Stop/Disable API may clear the 
          service request if its been set
       2. Also for the new start we will be going to reset the trigger source 
          data in this function
       3. A continuous conversion of a group (SW) can restart the Group in ISR
          after the stop-while loop which will cause the interrupt again after
          stop
    */

    /* Enter Critical section */
    Adc_lSchmEnterStopGroup();
    /* During the Group status check, interrupt should not be serviced */

    /*With DET STD_ON/STD_OFF:
      Check if Group status status is IDLE, if not IDLE, allow to stop
      If Idle, return back by just resetting the result. 
      If Idle but not stopped, there will not be DET reoported and will allow
      to service the API 
    */
    if ((Adc_StatusType)Adc_lGetGroupStatus(DataPtr,GroupId) != ADC_IDLE)
    {
       DataPtr->TriggSrcData[GrpPtr->GrpRequestSrc].IsrDoNothing 
                                                              = ADC_NO_SERVICE;

       Adc_lSchmExitStopGroup(); 
       /* Exit Critical section */

      /*Note: Not required to reset the lowest internal channel as its been 
        handled differently by waiting for Busy status during stop 
      */
      /*------------------------------------**
      ** Stop the Conversion Request Source **
      **------------------------------------*/
      Adc_lStopConvRequestSource(GrpPtr,Kernel);

      /* Note:
         Reset of Group RS Group data (RsGroupData) is not required
         as its been initialised with start of group conversion before reading
      */

      #if (ADC_USE_EMUX == STD_ON)
      if (DataPtr->EmuxGroup == GroupId)
      {
        /* Reset ADC EMUXCTR register */
        Adc_lWriteEmuxCtrSfr(Kernel, 0U);

        /* Reset Emux variable */
        DataPtr->EmuxGroup = ADC_INVALID_GROUP_ID;
       
      }
      #endif /* (ADC_USE_EMUX == STD_ON) */
    
      /*-------------------------------**
      **  Update all Status Variables  **
      **-------------------------------*/
      
        /* Update request source data and Adc_AllRunningCh */
      Adc_lResetTrigSrcData(GrpPtr,DataPtr);

      /* Group status of given group is made ADC_IDLE */
      Adc_lSetGroupStatusIdleAtomic(DataPtr,GroupId);
    }
    else
    {
       Adc_lSchmExitStopGroup(); 
       /* Exit Critical section */
    }
    /* Set the Group status to ADC_IDLE, but the converted result data
       are avilable for the user */

    #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
    /* Clear ADC Group Result Status */
    Adc_lClrGroupResultAtomic(DataPtr,GroupId);
    #endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */

    /* Reset the End result status to 0 */
    Adc_lClrResBuffEndStatusAtomic(DataPtr,GroupId);
    
  /*----------------------------------------------------------------**
  ** ADC155: Disable the group notification for the requested group **
  **----------------------------------------------------------------*/
    #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    Mcal_SetAtomic(
      ((sint32 *)(void*)&DataPtr->GrpNotifStatus), 
      (uint32)0, 
      (sint32)GroupId,
      1);
    #endif /* ADC_GRP_NOTIF_CAPABILITY */ 

    #endif /* No Priority No Queue / HW Priority */
  }

}/* Adc_StopGroupConversion */
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

#if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
#if (ADC_READ_GROUP_API == STD_ON)
/*******************************************************************************
** Traceabilty      :[cover parentID=DS_AS_ADC369_ADC383,DS_AS_ADC413_4,
                     DS_AS_ADC067_ADC234_6,DS_AS_ADC296,DS_AS_ADC152,
                     DS_AS_ADC388,DS_AS_ADC075,DS_AS_ADC113,DS_AS_ADC330,
                     DS_AS_ADC329_ADC331,DS_AS_ADC359,DS_AS_ADC415,
                     DS_MCAL_ADC_0413_5]
** Syntax           : Std_ReturnType Adc_ReadGroup                            **
**                    (                                                       **
**                      Adc_GroupType Group                                   **
**                      Adc_ValueGroupType *DataBufferPtr                     **
**                    )                                                       **
**[/cover]                                                                    **
**                                                                            **
** Service ID       : 0x04                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : re-entrant                                              **
**                                                                            **
** Parameters(in)   : Group - Numeric ID of requested ADC Channel group.      **
**                                                                            **
** Parameters (out) : DataBufferPtr - Location to store the requested Group's **
**                    channels conversion result                              **
**                                                                            **
** Return value     : E_OK - Read command is accepted                         **
**                    E_NOT_OK - Read command is not accepted, or DET occurred**
**                                                                            **
** Description      : This function:                                          **
**   - ADC075: Adc_ReadGroup is a service for reading the latest available    **
**             conversion results of the requested group.                     **
**   - ADC113: The Adc_ReadGroup service shall return the raw converted values**
**             without further scaling.                                       **
**             The returned values shall be right-aligned.                    **
**   - ADC329, ADC330, ADC331: Reading the Group result will change the       **
**             Group status                                                   **
**                                                                            **
*******************************************************************************/
Std_ReturnType Adc_ReadGroup
(
  Adc_GroupType Group,
  Adc_ValueGroupType *DataBufferPtr 
)
{
  Adc_GlobalDataType        *DataPtr;
  const Adc_GroupCfgType    *GrpPtr;
  uint32                    NoOfChannels;
  #if (ADC_GROUP_EMUX_SCAN == STD_ON)
  uint32                    GrpEmuxScanFlag;
  uint32                    EmuxSelect;
  #endif /* (ADC_GROUP_EMUX_SCAN == STD_ON) */

  #if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
  uint32 Err;
  #endif
  /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */

  Adc_ValueGroupType        *CurrentResBufPtr;
  Adc_GroupType             GroupId;
  Std_ReturnType            RetStatus;
  Adc_StreamNumSampleType   NoOfValidConv;
  Adc_StreamNumSampleType   StreamNumOfSamples;
  Adc_StatusType            GrpStat;
  Adc_StatusType            GrpRes;
  uint8                     Kernel;

  /* Get Kernel number from Group ID */
  Kernel = (uint8)Adc_lGetAdcKernel(Group);
  /* Get the Group Id for perticular kernel */
  GroupId = (Adc_GroupType)Adc_lGetKernelGroupId(Group);

  #if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
  
  #if (ADC_DEV_ERROR_DETECT == STD_ON)

  /* ADC296: Check for DET error ADC_E_UNINIT */
  Err = Adc_lCheckInit(ADC_SID_READ_GROUP);

  if (Err == ADC_E_DET_NO_ERR)
  #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ADC152 : Check for ADC_E_PARAM_GROUP
    */
    Err = Adc_lValidateParamGroup(ADC_SID_READ_GROUP, GroupId, Kernel);
  }
  
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
/* Check for Group IDLE Status. This status is checked only when DET is STD_ON.
In the production mode the user should not make any calls
that leads to ADC_E_IDLE. Failing to do so may lead to arbitrary behavior of the
driver.*/
  Adc_lSchmEnterReadGroup();
  /* Enter Critical Section */
  if (Err == ADC_E_DET_NO_ERR)
  {
    /* ADC388 : Check for ADC_E_IDLE */
    Err = Adc_lCheckDriverState(ADC_SID_READ_GROUP, GroupId, Kernel);
  }
  #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
  
  #if (ADC_SAFETY_ENABLE == STD_ON)
  if (Err == ADC_E_DET_NO_ERR)
  {
    /* Get the Adc Group Configuration Pointer */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    PBConfigStructure and is within allowed range*/
    GrpPtr = Adc_kConfigPtr->CfgPtr[Kernel]->GrpCfgPtr + GroupId;

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    Group Configuration Structure and is within allowed range*/
    if(DataBufferPtr[0] != GrpPtr->BufferMarker)
    {
      SafeMcal_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE,
                            ADC_SID_READ_GROUP, ADC_E_PARAM_POINTER
                          );
    
      Err = (uint32)ADC_E_PARAM_POINTER;
    }
  }
  #endif /* (ADC_SAFETY_ENABLE == STD_ON) */

  if (Err != ADC_E_DET_NO_ERR)
  {
    
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    Adc_lSchmExitReadGroup();
    /* Exit Critical Section */
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
  
    /* ADC296, ADC152: 
       If error detected, the service will return with E_NOT_OK 
    */
    RetStatus = (Std_ReturnType)E_NOT_OK;
  }
  else
  #endif
  /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */
  {
    /* Get ADC Kernel index for variables */
    /* Assign the address of ASIL or QM signal variable to global data pointer*/
    DataPtr = Adc_lGetDataAddress(Kernel);

    #if (ADC_DEV_ERROR_DETECT != STD_ON)  
    /* ADC141: The Adc_ReadGroup function shall provide atomic access by 
       the use of OS interrupt masking functions
    */
    /* Enter Critical section */
    Adc_lSchmEnterReadGroup();
    #endif  /* (ADC_DEV_ERROR_DETECT != STD_ON) */
    /* Note: Read of Number of valid conversion result, buffer end status, 
       Group status update are protected from ISR 
    */

    GrpStat = (Adc_StatusType)Adc_lGetGroupStatus(DataPtr,GroupId);
    GrpRes = (Adc_StatusType)Adc_lGetGroupResult(DataPtr,GroupId);


    /* Exit Critical section */
    Adc_lSchmExitReadGroup();

    /* If Group is in ADC_BUSY state (no matter of result availability), then
       return E_NOT_OK without any action
    */
    /* Check for Group status to be ADC_BUSY
       If Group Result status is 0, then Group Result End status will definitely
       be 0
    */
    if ((GrpStat != ADC_IDLE) && (GrpRes == (Adc_StatusType)0))
    {
      /* Group status is ADC_BUSY, return E_NOT_OK without any action */
      RetStatus = (Std_ReturnType)E_NOT_OK;
    
    }
    else
    {

      /* Note:If Group status is ADC_IDLE and number of valid conversion 
         result available is not 0, then Group results are read.
      */
      /* Note: Check for zero no. of valid converstion results in ADC_IDLE 
         state is done at DET
      */
      /* ADC330: Calling function Adc_ReadGroup while group status is 
         ADC_STREAM_COMPLETED shall trigger a state transition to ADC_IDLE 
         for conversion modes which automatically stop the conversion
         Possible combinations are:
         Linear Groups in ADC_STREAM_COMPLETED state
         1. Sw Trigger, Oneshot (Default : Single - Linear)
         2. Sw Trigger, Continuous, Streaming - Linear
         3. Hw Trigger, Oneshot, Streaming - Linear
         Request source has already stopped or Disabled the request source
         for further conversion and GroupStatus variableis already in 
         IDLE state.
         Hence, clearing of Result Buffer status and Result Buffer End status 
         is required for state transition to ADC_IDLE 
      */
      /* Note: Set the Group status to ADC_IDLE, but the converted result data
         are avilable for the user 
      */
      /* ADC329: Calling function Adc_ReadGroup while group status is 
         ADC_STREAM_COMPLETED shall trigger a state transition to ADC_BUSY 
         for continuous conversion modes
         ADC331: Calling function Adc_ReadGroup while group status is 
         ADC_COMPLETED shall trigger a state transition to ADC_BUSY 
         Possible combinations are:
         Continuous Groups either in ADC_STREAM_COMPLETED or ADC_COMPLETED
         1. Sw Trigger, Continuous, Streaming - Continuous 
         2. Hw Trigger, Oneshot, Streaming - Continuous
         Linear Groups in ADC_COMPLETED state
         1. Sw Trigger, Oneshot (Default : Single - Linear)
         2. Sw Trigger, Continuous, Streaming - Linear
         3. Hw Trigger, Oneshot, Streaming - Linear
      */
    
      /* Enter Critical section */
      Adc_lSchmEnterReadGroup();

      /* Clear ADC Group Result Status on read */
      Adc_lClrGroupResultAtomic(DataPtr,GroupId);

      /* Clear the Buffer end status */
      Adc_lClrResBuffEndStatusAtomic(DataPtr,GroupId);

      /* Exit Critical section */
      Adc_lSchmExitReadGroup();

      /* Get the Adc Group Configuration Pointer */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
      PBConfigStructure and is within allowed range*/
      GrpPtr = Adc_kConfigPtr->CfgPtr[Kernel]->GrpCfgPtr + GroupId;

      /* Get the configured no. of samples for the Group */
      StreamNumOfSamples = GrpPtr->NumSamples;


      #if (ADC_GROUP_EMUX_SCAN == STD_ON)
      
      /* Get Group EMUX Scan flag */
      GrpEmuxScanFlag = (uint32)Adc_lGetEmuxScan((uint32)GrpPtr->GroupEmuxData);

      if (GrpEmuxScanFlag == (uint32)ADC_GROUP_EMUX_SCAN_ENABLE)
      {
        /* Get Group EMUX select value */
        EmuxSelect = (uint32)Adc_lGetEmuxSelect((uint32)GrpPtr->GroupEmuxData);
        /* Implicit num of channels = (EmuxSelect + 1U) */
        NoOfChannels = (uint32)(EmuxSelect + 1U);
      
      }
      else
      {
        /* Get the configured no. of channels in a group */
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
        Group Configuration Structure and is within allowed range*/
        NoOfChannels = (uint32)(GrpPtr->GroupDefinition)[0];
      }
      #else /* (ADC_GROUP_EMUX_SCAN == STD_ON) */

      /* Get the configured no. of channels in a group */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
      Group Configuration Structure and is within allowed range*/
      NoOfChannels = (uint32)(GrpPtr->GroupDefinition)[0];
      
      #endif /* (ADC_GROUP_EMUX_SCAN == STD_OFF) */


      /* Read the no. of valid converstion results available */
      NoOfValidConv = DataPtr->NumValidConRes[GroupId];
      /* latest valid data location in result buffer */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
      result buffer and is within allowed range*/
      CurrentResBufPtr = DataPtr->GroupResultBuffer[GroupId] + \
                          (NoOfValidConv - (Adc_StreamNumSampleType)1);

      
      /* Total number of channels in a Group will be atleast one */
      do
      {
        /* Store the channel conversion result into the requested buffer */
        /* Increment the DataBufferPtr to point to the next location */
        *DataBufferPtr = *CurrentResBufPtr;
        
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
        result buffer and is within allowed range*/
        DataBufferPtr++;

        /* Get the latest result location of the next channel in the group */
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
        result buffer and is within allowed range*/
        CurrentResBufPtr = (CurrentResBufPtr + (uint32)StreamNumOfSamples);

        /* Decrement the loop count */
        NoOfChannels--;

      } while (NoOfChannels > 0U);

      /* Set the return status to E_OK */
      RetStatus = (Std_ReturnType)E_OK;

    }/* When Group is not in ADC_BUSY state */
  }
  
/*--------------------------------------------**
** Return the API Status has E_OK or E_NOT_OK **
**--------------------------------------------*/
  return (RetStatus);

}/* Adc_ReadGroup */
#endif /* (ADC_READ_GROUP_API == STD_ON) */
#endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */

/* Enable/Disable the use of the function */
#if (ADC_HW_TRIGGER_API == STD_ON)
/*******************************************************************************
** Traceabilty      :[cover parentID=DS_AS_ADC370,DS_AS_ADC413_5,
                     DS_AS_ADC067_ADC234_7,DS_AS_ADC297,DS_AS_ADC128,
                     DS_AS_ADC136,DS_AS_ADC281,DS_AS_ADC425,DS_AS_ADC321,
                     DS_AS_ADC349,DS_AS_ADC353,DS_AS_ADC114,DS_AS_ADC144,
                     DS_AS_ADC432,DS_AS_ADC336,DS_AS_ADC280,DS_AS_ADC415,
                     DS_AS_ADC332,DS_AS_ADC337,DS_AS_ADC417,DS_AS_ADC265,
                     DS_MCAL_ADC_0413_6]
** Syntax           : void Adc_EnableHardwareTrigger                          **
**                    (                                                       **
**                      Adc_GroupType Group                                   **
**                    )                                                       **
**[/cover]                                                                    **
**                                                                            **
** Service ID       : 0x05                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : re-entrant                                              **
**                                                                            **
** Parameters(in)   : Group - Numeric ID of requested ADC Channel group.      **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - ADC114: This service shall enable the hardware trigger for the         **
**             requested ADC Channel group.                                   **
**   - ADC120: This service can only be used for groups configured in hardware**
**             trigger mode ADC_GROUP_TRIGG_SRC                               **
**   - ADC265: This function shall available only if configuration parameter: **
**             ADC_HW_TRIGGER_API is switched On                              **
*******************************************************************************/
void Adc_EnableHardwareTrigger
(                             
  Adc_GroupType Group         
)
{
  Adc_GlobalDataType        *DataPtr;
  const Adc_GroupCfgType    *GrpPtr;
  #if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
  uint32                    Err;
  #endif
  /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */
  Adc_GroupType             GroupId;
  uint8                     GrpRequestSource;
  uint8                     Kernel;

  /* Get Kernel number from Group ID */
  Kernel = (uint8)Adc_lGetAdcKernel(Group);
  /* Get the Group Id for perticular kernel */
  GroupId = (Adc_GroupType)Adc_lGetKernelGroupId(Group);

/*-------------------------------------**
** Check for Developement Time Errors  **
**-------------------------------------*/
/* ADC234, ADC067: Detected development errors shall be reported to the 
   Det_ReportError service 
*/

  #if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
  
  #if (ADC_DEV_ERROR_DETECT == STD_ON)

  /* ADC297: Check for DET error ADC_E_UNINIT */
  Err = Adc_lCheckInit(ADC_SID_ENABLE_HARDWARE_TRIGGER);

  if (Err == ADC_E_DET_NO_ERR)
  #endif  /* (ADC_DEV_ERROR_DETECT == STD_ON)*/
  {
    /* ADC128 : Check for ADC_E_PARAM_GROUP
       ADC136 : Check for ADC_E_WRONG_TRIGG_SRC
       ADC281 : Check for ADC_E_WRONG_CONV_MODE
       ADC425 : Check for ADC_E_BUFFER_UNINIT
    */
    Err = Adc_lValidateParamGroup
            (ADC_SID_ENABLE_HARDWARE_TRIGGER, GroupId, Kernel);
  }

  #if (ADC_DEV_ERROR_DETECT == STD_ON)
/* Check for Group Busy Status. This status is checked only when DET is STD_ON.
In the production mode the user should not make any calls
that leads to ADC_E_BUSY. Failing to do so may lead to arbitrary behavior of the
driver.*/
  /* Enter Critical Section */
  Adc_lSchmEnterEnableHwTrig(); 

  #if (ADC_RESULT_POLLING_MODE == STD_OFF)
  if (Err == ADC_E_DET_NO_ERR)
  {
    /* ADC276 : Check for ADC_E_BUSY */
    Err = Adc_lCheckStateForEnableGroup(GroupId, Kernel);
  }
  #endif /* (ADC_RESULT_POLLING_MODE == STD_OFF) */
  #endif  /* (ADC_DEV_ERROR_DETECT == STD_ON) */
  
  if (Err != ADC_E_DET_NO_ERR)
  {
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    Adc_lSchmExitEnableHwTrig(); 
    /* Exit Critical Section */
    #endif  /* (ADC_DEV_ERROR_DETECT == STD_ON)*/

    /* do nothing incase SAFETY == STD_ON and DET == STD_OFF */
  }
  else
  #endif
  /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */
  {
  /* ADC336: 'Enable hardware trigger requests' 
     shall not wait in queue. It is serviced immedietly if resource is free.
     Hence scheduler function is not called
  */

    /* Get ADC Kernel index for variables */
    /* Assign the address of ASIL or QM signal variable to global data pointer*/
    DataPtr = Adc_lGetDataAddress(Kernel);
    /* Queue Enable is STD_ON only during No priority */
    #if (ADC_ENABLE_QUEUING == STD_ON)

    /* Note: When the Queue is empty, the HW Group can be serviced.*/
    /* Initialise the Pop Index and Push Index to the Requested Group */
    DataPtr->PushGroupId = GroupId;
    DataPtr->PopGroupId = GroupId;

    #endif /* (ADC_ENABLE_QUEUING == STD_ON) */

    /* Get the Adc Group Configuration Pointer */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    PBConfigStructure and is within allowed range*/
    GrpPtr = Adc_kConfigPtr->CfgPtr[Kernel]->GrpCfgPtr + GroupId;
    /* Get the configured Group request source */
    GrpRequestSource = GrpPtr->GrpRequestSrc;

  /*-------------------------------**
  **  Update all Status Variables  **
  **-------------------------------*/

    #if (ADC_RESULT_POLLING_MODE == STD_OFF)
    /* Group status of given group is made ADC_BUSY */
    Adc_lSetGroupStatusBusyAtomic(DataPtr,GroupId);
    #endif /* (ADC_RESULT_POLLING_MODE == STD_OFF) */

    /* GrpId is updated with the requested Group */
    DataPtr->TriggSrcData[GrpRequestSource].GrpId = GroupId;

    /* Note:
       DataPtr->TriggSrcData[GrpRequestSource].GrpPriority when RS
       is free is ADC_INVALID_PRIORITY which is greater than any of the priority
       levels. 
       Here HW trigger group of higher priority compared to SW trigger groups 
       under same RS
    */

    #if (ADC_REQSRC2 == ADC_REQSRC_USED)
    /* Background request source is triggered */
    if(GrpRequestSource == ADC_REQSRC2_BGND_SCAN)
    {
      Adc_BgndScanData = ADC_TRIGG_SRC_HW;
      Adc_BgndGrpCnt++;
    }
    #endif /* (ADC_REQSRC2 == ADC_REQSRC_USED) */
   
    #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
    /* Clear ADC Group Result Status */
    Adc_lClrGroupResultAtomic(DataPtr,GroupId);

    /* Initialize the number of conversion result set available to 0 */
    DataPtr->NumValidConRes[GroupId] = (Adc_StreamNumSampleType)0;
    #endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */
    /*Note: The Result Status is cleared at every start even if it is also 
    cleared at every Stop. This is because we assume that the user may call 
    Adc_StartGroup twice without explicitly calling Adc_StopGroup essentially 
    in the case of One Shot Mode*/
    /* Reset the End result status to 0 */
    Adc_lClrResBuffEndStatusAtomic(DataPtr,GroupId);

    #if (ADC_DEV_ERROR_DETECT == STD_ON)  
    Adc_lSchmExitEnableHwTrig(); 
    /* Exit Critical Section */

    /*Note: The Status variables have to be checked and updated in a critical 
    section only in the case of DET == STD_ON. This is because the status check
    is done only in the Developement code */
    #endif  /* (ADC_DEV_ERROR_DETECT == STD_ON) */

  /*----------------------------------------------------------------------**
  ** Set Up ADC Channels :Prepare Group channels by configuring in CHCON  **
  ** register and update TriggSrcData                                     **
  **----------------------------------------------------------------------*/

    Adc_lPrepareGrpForStart(Kernel,GroupId);

    #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
    /* Update the RS Group data */
    Adc_lUpdateRsGroupData(Kernel,GrpPtr);
    #endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */

    /*
      Clear the No ISR service flag for the trigger source. Which might have set
      if Stop API is called.
    */
    DataPtr->TriggSrcData[GrpRequestSource].IsrDoNothing = (uint8)0;
    /* Note: In case of short conversion time, ISR no service flag has to be 
       cleared before the first conversion complete interrupt
    */

  /*-----------------------------------------------------**
  ** Trigger Conversion Source :Trigger the appropriate  **
  ** Conversion Request Source                           **
  **-----------------------------------------------------*/

    Adc_lStartHwConversionRS(GrpPtr,Kernel);
  }

}/* Adc_EnableHardwareTrigger */                             
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

/* Enable/Disable the use of the function */
#if (ADC_HW_TRIGGER_API == STD_ON)
/*******************************************************************************
** Traceabilty      :[cover parentID=DS_AS_ADC371,DS_AS_ADC413_6,
                     DS_AS_ADC067_ADC234_8,DS_AS_ADC298,DS_AS_ADC129,
                     DS_AS_ADC137,DS_AS_ADC282,DS_AS_ADC304,DS_AS_ADC116,
                     DS_AS_ADC145,DS_AS_ADC361,DS_AS_ADC429,DS_AS_ADC157,
                     DS_AS_ADC266,DS_AS_ADC415,DS_MCAL_ADC_0413_7]
** Syntax           : void Adc_DisableHardwareTrigger                         **
**                    (                                                       **
**                      Adc_GroupType Group                                   **
**                    )                                                       **
**[/cover]                                                                    **
**                                                                            **
** Service ID       : 0x06                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : re-entrant                                              **
**                                                                            **
** Parameters(in)   : Group - Numeric ID of requested ADC Channel group.      **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - ADC116: This service shall disable the hardware trigger for the        **
**             requested ADC Channel group.                                   **
**   - ADC145: If applicable, an ongoing conversion shall be aborted.         **
**   - ADC157: If enabled, this function shall also disable the notification  **
**             mechanism for the requested group.                             **
**   - ADC121: This service can only be used for groups configured in hardware**
**             trigger mode ADC_GROUP_TRIGG_SRC                               **
**   - ADC266: This function shall available only if configuration parameter: **
**             ADC_HW_TRIGGER_API is switched On                              **
*******************************************************************************/
void Adc_DisableHardwareTrigger
(                             
  Adc_GroupType Group         
)
{
  Adc_GlobalDataType      *DataPtr;
  const Adc_GroupCfgType  *GrpPtr;
  #if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
  uint32                  Err;
  #endif
  /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */
  #if (ADC_ENABLE_QUEUING == STD_ON)
  uint32                  NextStartStatus;
  Adc_GroupType           PopGrpId;
  #endif /* (ADC_ENABLE_QUEUING == STD_ON) */
  Adc_GroupType           GroupId;
  uint8                   Kernel;

  Kernel = (uint8)Adc_lGetAdcKernel(Group);
  /* Get the Group Id for perticular kernel */
  GroupId = (Adc_GroupType)Adc_lGetKernelGroupId(Group);

/*-------------------------------------**
** Check for Developement Time Errors  **
**-------------------------------------*/
/* ADC234, ADC067: Detected development errors shall be reported to the 
   Det_ReportError service 
*/

  #if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
  
  #if (ADC_DEV_ERROR_DETECT == STD_ON)

  /* ADC298: Check for DET error ADC_E_UNINIT */
  Err = Adc_lCheckInit(ADC_SID_DISABLE_HARDWARE_TRIGGER);

  if (Err == ADC_E_DET_NO_ERR)
  #endif  /* (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ADC128, ADC304 : Check for ADC_E_PARAM_GROUP
       ADC136 : Check for ADC_E_WRONG_TRIGG_SRC
       ADC281 : Check for ADC_E_WRONG_CONV_MODE
    */
    Err = Adc_lValidateParamGroup
            (ADC_SID_DISABLE_HARDWARE_TRIGGER, GroupId, Kernel);
  }
  
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  
  if (Err == ADC_E_DET_NO_ERR)
  {
    /* Check for ADC_E_IDLE */
    Err = Adc_lCheckDriverState
            (ADC_SID_DISABLE_HARDWARE_TRIGGER, GroupId, Kernel);
  }
  #endif  /* (ADC_DEV_ERROR_DETECT == STD_ON) */

  if (Err == ADC_E_DET_NO_ERR)
  #endif
  /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */
  {
  /* ADC336: 'Enable hardware trigger requests' 
     shall not wait in queue. It is serviced immedietly if resource is free.
     Hence scheduler function is not called
  */

    /* Get ADC Kernel index for variables */
    /* Assign the address of ASIL or QM signal variable to global data pointer*/
    DataPtr = Adc_lGetDataAddress(Kernel);
    /* Get the Adc Group Configuration Pointer */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    PBConfigStructure and is within allowed range*/
    GrpPtr = Adc_kConfigPtr->CfgPtr[Kernel]->GrpCfgPtr + GroupId;

    /*Note:
      Set a no ISR service flag for the trigger source. 
      By this disabing the service request for the node is not required.
      Note: There is a chance that the Group has already stopped in ISR and 
      new Group of same trigger source might have started. While going ahead in 
      stop may reset the trigger source data. To avoid this cause, service the 
      Stop depending upon the Group status
    */
    /* Note: 
       There is a chance that, an ISR of this Group - Oneshot, 
       continuous - Linear 
       will change the status of the Group to IDLE and 
       sets the trigger source data free and allow to start 
       an another Group with same trigger source as which 
       has called for stop. 
       1. After new start the control in Stop/Disable API may clear the 
          service request if its been set
       2. Also for the new start we will be going to reset the trigger source 
          data in this function
       3. A continuous conversion of a group (SW) can restart the Group in ISR
          after the stop-while loop which will cause the interrupt again after
          stop
    */

    Adc_lSchmEnterDisableHwTrig(); 
    /* Enter Critical section */

    /* During the Group status check, interrupt should not be serviced */

    /*With DET STD_ON/STD_OFF:
      Check if Group status status is IDLE, if not IDLE, allow to stop
      If Idle, return back by just resetting the result. 
      If Idle but not stopped, there will not be DET reoported and will allow
      to service the API 
    */
    if ((Adc_StatusType)Adc_lGetGroupStatus(DataPtr,GroupId) != ADC_IDLE)
    {
       
       DataPtr->TriggSrcData[GrpPtr->GrpRequestSrc].IsrDoNothing 
                                                              = ADC_NO_SERVICE;

       Adc_lSchmExitDisableHwTrig(); 
       /* Exit Critical section */

      /* Note: Not required to reset the lowest internal channel as its been 
         handled differently by waiting for Busy status during stop 
      */
      
      /*------------------------------------**
      ** Stop the Conversion Request Source **
      **------------------------------------*/
      #if (ADC_REQSRC2 == ADC_REQSRC_USED)
      if(GrpPtr->GrpRequestSrc == ADC_REQSRC2_BGND_SCAN)
      {
     
        Adc_BgndGrpCnt--;
       
        if(Adc_BgndGrpCnt == 0U)
        {
          Adc_BgndScanData = ADC_BGND_REQ_SRC_FREE;
        }
      }
      #endif /* (ADC_REQSRC2 == ADC_REQSRC_USED) */
    
      Adc_lStopConvRequestSource(GrpPtr,Kernel);

      /* Note:
         Reset of Group RS Group data (RsGroupData) is not required
         as its been initialised with start of group conversion before reading
      */

      #if (ADC_USE_EMUX == STD_ON)
      if (DataPtr->EmuxGroup == GroupId)
      {
        /* Reset ADC EMCTR register */
        Adc_lWriteEmuxCtrSfr(Kernel, 0U);
        
        /* Reset Emux variable */
        DataPtr->EmuxGroup = ADC_INVALID_GROUP_ID;
      }
      #endif /* (ADC_USE_EMUX == STD_ON) */
      
      /*-------------------------------**
      **  Update all Status Variables  **
      **-------------------------------*/
        /* Update request source data and Adc_AllRunningCh */
      Adc_lResetTrigSrcData(GrpPtr,DataPtr);

      /* Group status of given group is made ADC_IDLE */
      Adc_lSetGroupStatusIdleAtomic(DataPtr,GroupId);

      /* Queue Enable is STD_ON only during No priority */
      #if (ADC_ENABLE_QUEUING == STD_ON)
      /* Initialise the next start to be none */
      NextStartStatus = (uint32)0;

      /* Pop index will be the next Group in Queue */
      DataPtr->PopGroupId = DataPtr->QueueOfSwGroup[GroupId].NextGroup;

      /* If Pop index has valid Group Id, request for start conversion */
      if (DataPtr->PopGroupId != ADC_INVALID_GROUP_ID)
      {
        /* Reset, next Group to invalid */
        DataPtr->QueueOfSwGroup[GroupId].NextGroup = ADC_INVALID_GROUP_ID;
      
        PopGrpId = DataPtr->PopGroupId;

        DataPtr->QueueOfSwGroup[PopGrpId].PreviousGroup = ADC_INVALID_GROUP_ID;
        
        NextStartStatus = ADC_START_CONVERSION;
      }
      else /* If Pop Group ID is invalid, then there is no Group in the Queue,
              Reset Push Group Id to invalid */
      {
        DataPtr->PushGroupId = ADC_INVALID_GROUP_ID;
      }

      /* Scheduler function needs to be called only when Group is not Idle.
         If Group has implicitly become Idle, it would have scheduled 
         the next group for conversion. 
      */
      if (NextStartStatus == ADC_START_CONVERSION)
      {
        /* Schedule the next Group conversion pointed by Pop index */
        Adc_lScheduleFromQueue(Kernel);
      }

      #endif /* (ADC_ENABLE_QUEUING == STD_ON) */

      /* Full priority considered */
      #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)

      /* Schedule the next conversion in the stopped trigger source */
      Adc_lScheduleNext(Kernel,GrpPtr->GrpRequestSrc);

      #endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) */
    }
    else
    {
       Adc_lSchmExitDisableHwTrig(); 
       /* Exit Critical section */
    }
    /* Set the Group status to ADC_IDLE, but the converted result data
       are avilable for the user */

    #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
    /* Clear ADC Group Result Status */
    Adc_lClrGroupResultAtomic(DataPtr,GroupId);
    #endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */

    /* Reset the End result status to 0 */
    Adc_lClrResBuffEndStatusAtomic(DataPtr,GroupId);
    
  /*----------------------------------------------------------------**
  ** ADC157: Disable the group notification for the requested group **
  **----------------------------------------------------------------*/

    #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    Mcal_SetAtomic(
    ((sint32 *)(void *)&DataPtr->GrpNotifStatus), 
    (uint32)0, 
    (sint32)GroupId,
    1);
    #endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
  }

}/* Adc_DisableHardwareTrigger */                             
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

/* Enable/Disable the use of the function */
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
/*******************************************************************************
** Traceabilty      :[cover parentID=DS_AS_ADC372,DS_AS_ADC413_7,
                     DS_AS_ADC067_adc234_9,DS_AS_ADC057,DS_AS_ADC100,
                     DS_AS_ADC299,DS_AS_ADC130,DS_AS_ADC165,DS_AS_ADC415,
                     DS_MCAL_ADC_0413_8]
** Syntax           : void Adc_EnableGroupNotification                        **
**                    (                                                       **
**                      Adc_GroupType Group                                   **
**                    )                                                       **
**[/cover]                                                                    **
**                                                                            **
** Service ID       : 0x07                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : re-entrant                                              **
**                                                                            **
** Parameters(in)   : Group - Numeric ID of requested ADC Channel group.      **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - ADC057: This service shall enable the notification mechanism for the   **
**             requested ADC Channel group.                                   **
**   - ADC100: This function shall available only if configuration parameter: **
**             ADC_GRP_NOTIF_CAPABILITY is switched On                        **
*******************************************************************************/
void Adc_EnableGroupNotification
(                             
  Adc_GroupType Group         
)
{
  Adc_GlobalDataType   *DataPtr;
  #if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
  uint32               Err;
  #endif
  /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */
  Adc_GroupType        GroupId;
  uint8                Kernel;

  /* Get the ADC HW Unit Id */
  Kernel = (uint8)Adc_lGetAdcKernel(Group);
  /* Get the Group Id for perticular kernel */
  GroupId = (Adc_GroupType)Adc_lGetKernelGroupId(Group);

/*-------------------------------------**
** Check for Developement Time Errors  **
**-------------------------------------*/
/* ADC234, ADC067: Detected development errors shall be reported to the 
   Det_ReportError service 
*/
  #if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
  
  #if (ADC_DEV_ERROR_DETECT == STD_ON)

  /* ADC299: Check for DET error ADC_E_UNINIT */
  Err = Adc_lCheckInit(ADC_SID_ENABLE_GROUP_NOTIFICATION);

  if (Err == ADC_E_DET_NO_ERR)
  #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ADC130 : Check for ADC_E_PARAM_GROUP
       ADC165 : Check for ADC_E_NOTIF_CAPABILITY
    */
    Err = Adc_lValidateParamGroup
            (ADC_SID_ENABLE_GROUP_NOTIFICATION, GroupId, Kernel);
  }
  
  if (Err == ADC_E_DET_NO_ERR)
  #endif
  /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */
  {
    /* Get ADC Kernel index for variables */
    /* Assign the address of ASIL or QM signal variable to global data pointer*/
    DataPtr = Adc_lGetDataAddress(Kernel);

  /*---------------------------------------------------------------------**
  ** Enable Group Notification: Set the bit for the corresponding group  **
  **                            in GrpNotifStatus                        **
  **---------------------------------------------------------------------*/
    Mcal_SetAtomic(
      ((sint32 *)(void *)&(DataPtr->GrpNotifStatus)), 
      (uint32)1, 
      (sint32)GroupId,
      1);
  }
  return;
}/* Adc_EnableGroupNotification */                             
#endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

/* Enable/Disable the use of the function */
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
/*******************************************************************************
** Traceabilty      :[cover parentID=DS_AS_ADC373,DS_AS_ADC413_8,
                     DS_AS_ADC067_ADC234_10,DS_AS_ADC058,DS_AS_ADC101,
                     DS_AS_ADC300,DS_AS_ADC131,DS_AS_ADC166,DS_AS_ADC415,
                     DS_MCAL_ADC_0413_9]
** Syntax           : void Adc_DisableGroupNotification                       **
**                    (                                                       **
**                      Adc_GroupType Group                                   **
**                    )                                                       **
**[/cover]                                                                    **
**                                                                            **
** Service ID       : 0x08                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : re-entrant                                              **
**                                                                            **
** Parameters(in)   : Group - Numeric ID of requested ADC Channel group.      **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - ADC058: This service shall disable the notification mechanism for the  **
**             requested ADC Channel group.                                   **
**   - ADC101: This function shall available only if configuration parameter: **
**             ADC_GRP_NOTIF_CAPABILITY is switched On                        **
*******************************************************************************/
void Adc_DisableGroupNotification
(                             
  Adc_GroupType Group         
)
{
  Adc_GlobalDataType *DataPtr;
  #if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
  uint32            Err;
  #endif
  /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */
  Adc_GroupType     GroupId;
  uint8             Kernel;

  /* Get the ADC HW Unit Id */
  Kernel = (uint8)Adc_lGetAdcKernel(Group);
  /* Get the Group Id for perticular kernel */
  GroupId = (Adc_GroupType)Adc_lGetKernelGroupId(Group);

/*-------------------------------------**
** Check for Developement Time Errors  **
**-------------------------------------*/
/* ADC234, ADC067: Detected development errors shall be reported to the 
   Det_ReportError service 
*/
  #if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
  
  #if (ADC_DEV_ERROR_DETECT == STD_ON)

  /* ADC300: Check for DET error ADC_E_UNINIT */
  Err = Adc_lCheckInit(ADC_SID_DISABLE_GROUP_NOTIFICATION);

  if (Err == ADC_E_DET_NO_ERR)
  #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ADC131 : Check for ADC_E_PARAM_GROUP
       ADC166 : Check for ADC_E_NOTIF_CAPABILITY
    */
    Err = Adc_lValidateParamGroup
            (ADC_SID_DISABLE_GROUP_NOTIFICATION, GroupId, Kernel);
  }
  if (Err == ADC_E_DET_NO_ERR)
  #endif
  /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */
  {
    /* Get ADC Kernel index for variables */
    /* Assign the address of ASIL or QM signal variable to global data pointer*/
    DataPtr = Adc_lGetDataAddress(Kernel);

  /*------------------------------------------------------------------------**
  ** Disable Group Notification: Clear the bit for the corresponding group  **
  **                            in GrpNotifStatus                           **
  **------------------------------------------------------------------------*/
    Mcal_SetAtomic(
      ((sint32 *)(void *)&(DataPtr->GrpNotifStatus)), 
      (uint32)0, 
      (sint32)GroupId,
      1);
  }
  return;

}/* Adc_DisableGroupNotification */                             
#endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

/*******************************************************************************
** Traceabilty      :[cover parentID=DS_AS_ADC374,DS_AS_ADC413_9,
                     DS_AS_ADC067_ADC234_11,DS_AS_ADC301,DS_AS_ADC225,
                     DS_AS_ADC220,DS_AS_ADC436,DS_AS_ADC325,DS_AS_ADC224,
                     DS_AS_ADC221,DS_AS_ADC222,DS_AS_ADC226,DS_AS_ADC415,
                     DS_MCAL_ADC_0413_10]
** Syntax           : Adc_StatusType Adc_GetGroupStatus                       **
**                    (                                                       **
**                      Adc_GroupType Group                                   **
**                    )                                                       **
**[/cover]                                                                    **
**                                                                            **
** Service ID       : 0x09                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : re-entrant                                              **
**                                                                            **
** Parameters(in)   : Group - Numeric ID of requested ADC Channel group.      **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Adc_StatusType                                          **
**                    Conversion status for the requested group               **
**                                                                            **
** Description      : This function:                                          **
**   - AADC220: This service shall return the conversion status: ADC_IDLE /   **
**              ADC_BUSY / ADC_COMPLETED of the requested ADC Channel group   **
**   - ADC307: After Adc_Init all groups are in ADC_IDLE state.               **
**   - ADC308: Adc_StopGroupConversion or Adc_DisableHardwareTrigger is       **
**             called successfully, the group status shall be set to ADC_IDLE.**
*******************************************************************************/
Adc_StatusType Adc_GetGroupStatus
(                             
  Adc_GroupType Group         
)
{
  Adc_GlobalDataType *DataPtr;
  #if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
  uint32            Err;
  #endif
  /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */
  Adc_GroupType     GroupId;
  Adc_StatusType    RetStatus; 
  uint8             Kernel;

  /* Get Kernel number from Group ID */
  Kernel = (uint8)Adc_lGetAdcKernel(Group);
  /* Get the Group Id for perticular kernel */
  GroupId = (Adc_GroupType)Adc_lGetKernelGroupId(Group);

/*-------------------------------------**
** Check for Developement Time Errors  **
**-------------------------------------*/
/* ADC234, ADC067: Detected development errors shall be reported to the 
   Det_ReportError service 
*/
  #if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
  
  #if (ADC_DEV_ERROR_DETECT == STD_ON)

  /* ADC301: Check for DET error ADC_E_UNINIT */
  Err = Adc_lCheckInit(ADC_SID_GET_GROUP_STATUS);

  if (Err == ADC_E_DET_NO_ERR)
  #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ADC225 : Check for ADC_E_PARAM_GROUP */
    Err = Adc_lValidateParamGroup(ADC_SID_GET_GROUP_STATUS, GroupId, Kernel);
  }
  if (Err == ADC_E_DET_NO_ERR)
  #endif
  /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */
  {
    /* Get ADC Kernel index for variables */
    /* Assign the address of ASIL or QM signal variable to global data pointer*/
    DataPtr = Adc_lGetDataAddress(Kernel);

    /* ADC226: Automic access to the status data by using 
       OS interrupt masking functions 
    */
    /* Enter Critical section */
    Adc_lSchmEnterGetGrpStatus();  
    /* Note: Status of the Group gets changed on 
       Adc_ReadGroup/Adc_GetStreamLastPointer API call and on 
       Conversion complete service routine */
    
    /*------------------------------------**
    ** ADC220: Return status of the group **
    **------------------------------------*/
    /* Check if the result buffer is full */
    if ((uint32)Adc_lGetResBuffEndStatus(DataPtr,GroupId) == (uint32)1)
    {
      RetStatus = ADC_STREAM_COMPLETED;
    }
    #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
    /* Else, check if atleast one set of results of Group available */
    else if ((uint32)Adc_lGetGroupResult(DataPtr,GroupId) == (uint32)1)
    {
      RetStatus = ADC_COMPLETED;
    }
    #endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */
    /* ADC221, Else, Group is either in ADC_BUSY state or ADC_IDLE state */
    else
    {
      RetStatus = Adc_lGetGroupStatus(DataPtr,GroupId); 
    }

    Adc_lSchmExitGetGrpStatus();
    /* Exit Critical section */
  }
  #if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
  else
  {
    /*ADC255, ADC301: If error detected, the service will return with 0 */
    RetStatus = ADC_IDLE;
  }
  #endif
  /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */
  
  return (RetStatus);
}/* Adc_GetGroupStatus */                             

#if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
/*******************************************************************************
** Traceabilty      :[cover parentID=DS_AS_ADC375_ADC382,DS_AS_ADC413_10,
                     DS_AS_ADC067_ADC234_12,DS_AS_ADC214,DS_AS_ADC418,
                     DS_AS_ADC387,DS_AS_ADC216,DS_AS_ADC327,DS_AS_ADC326_ADC328,
                     DS_AS_ADC302,DS_AS_ADC218,DS_AS_ADC215,DS_AS_ADC415,
                     DS_MCAL_ADC_0413_11]
** Syntax           : Adc_StreamNumSampleType Adc_GetStreamLastPointer        **
**                    (                                                       **
**                      Adc_GroupType Group                                   **
**                      Adc_ValueGroupType** SamplePtr                        **
**                    )                                                       **
**[/cover]                                                                    **
**                                                                            **
** Service ID       : 0x0b                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : re-entrant                                              **
**                                                                            **
** Parameters(in)   : Group - Numeric ID of requested ADC Channel group.      **
**                                                                            **
** Parameters (out) : SamplePtr - Pointer to the last acquired value.         **
**                                                                            **
** Return value     : Adc_StreamNumSampleType                                 **
**                    Number of valid samples per channel.                    **
**                                                                            **
** Description      : This function:                                          **
**   - ADC214: This service shall return the pointer to the last converted    **
**             value. All values stored in the buffer are left without further**
**             scaling.                                                       **
**   - ADC215: Asking for a group buffer pointer prior to starting the        **
**             conversion of the group, will return a default value null.     **
**   - ADC216: Asking for a group buffer pointer while a conversion of the    **
**             group is in progress will return null                          **
*******************************************************************************/
Adc_StreamNumSampleType Adc_GetStreamLastPointer
(                                               
  Adc_GroupType Group,                           
  Adc_ValueGroupType** PtrToSamplePtr              
)
{
  Adc_GlobalDataType        *DataPtr;
  const Adc_GroupCfgType    *GrpPtr;
  uint32                    BufferEndStatus;
  #if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
  uint32                    Err;
  #endif
  /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */
  Adc_ValueGroupType        *CurrentResBufPtr;
  Adc_GroupType             GroupId;
  Adc_StreamNumSampleType   NoOfValidConv;
  Adc_StreamNumSampleType   RetVal;
  Adc_StatusType            GrpStat;
  Adc_StatusType            GrpRes;
  uint8                     Kernel;

  /* Get Kernel number from Group ID */
  Kernel = (uint8)Adc_lGetAdcKernel(Group);
  /* Get the Group Id for perticular kernel */
  GroupId = (Adc_GroupType)Adc_lGetKernelGroupId(Group);

/*-------------------------------------**
** Check for Developement Time Errors  **
**-------------------------------------*/
/* ADC234, ADC067: Detected development errors shall be reported to the 
   Det_ReportError service 
*/
  #if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
  
  #if (ADC_DEV_ERROR_DETECT == STD_ON)

  /* ADC302: Check for DET error ADC_E_UNINIT */
  Err = Adc_lCheckInit(ADC_SID_GET_STREAM_LAST_POINTER);

  if (Err == ADC_E_DET_NO_ERR)
  #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ADC218 : Check for ADC_E_PARAM_GROUP */
    Err = Adc_lValidateParamGroup
            (ADC_SID_GET_STREAM_LAST_POINTER, GroupId, Kernel);
  }
  
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
/* Check for Group IDLE Status. This status is checked only when DET is STD_ON.
In the production mode the user should not make any calls
that leads to ADC_E_IDLE. Failing to do so may lead to arbitrary behavior of the
driver.*/
  /* Enter Critical Section */
  Adc_lSchmEnterGetStreamLastPtr(); 
  if (Err == ADC_E_DET_NO_ERR)
  {
    /* ADC388 : Check for ADC_E_IDLE */
    Err = Adc_lCheckDriverState
            (ADC_SID_GET_STREAM_LAST_POINTER, GroupId, Kernel);
  }
  #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
  
  if (Err != ADC_E_DET_NO_ERR)
  {
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    Adc_lSchmExitGetStreamLastPtr();
    /* Exit Critical Section */
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
  
    /* ADC218, ADC302: 
       If error detected, the streaming buffer sample pointer is NULL 
    */
    *PtrToSamplePtr = (Adc_ValueGroupType*)NULL_PTR;
  
    /* ADC218, ADC302: If error detected, the service will return 0 */
    RetVal = (Adc_StreamNumSampleType)0;
  }
  else
  #endif
  /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */
  {
  /*---------------------------------------------------**
  ** Assign the out parameter with the Pointer of the  **
  ** latest/last conversion result                     **
  **---------------------------------------------------*/
    /* Initialize the outparameter to NULL_PTR */
    /* This will satisfy 
       ADC216: Asking for a group buffer pointer while Group status is ADC_BUSY,
       will return a default value NULL.
    */
    *PtrToSamplePtr = (Adc_ValueGroupType*)NULL_PTR;

    /* Get ADC Kernel index for variables */
    /* Assign the address of ASIL or QM signal variable to global data pointer*/
    DataPtr = Adc_lGetDataAddress(Kernel);
    
    #if (ADC_DEV_ERROR_DETECT != STD_ON)  
    /* ADC141: The Adc_ReadGroup function shall provide atomic access by 
       the use of OS interrupt masking functions
    */
    /* Enter Critical section */
    Adc_lSchmEnterGetStreamLastPtr();
    #endif  /* (ADC_DEV_ERROR_DETECT != STD_ON) */
    /* Note: Read of Number of valid conversion result and buffer end status in
       local variable and Status change after result access 
       are protected from ISR */

    GrpStat = Adc_lGetGroupStatus(DataPtr,GroupId);
    GrpRes = Adc_lGetGroupResult(DataPtr,GroupId);

    /* Exit Critical section */
    Adc_lSchmExitGetStreamLastPtr();

    /* If Group is in ADC_BUSY state (no matter of result availability), then
       return no. of valid conversion result as 0 without any action
    */
    /* Check for Group status to be ADC_BUSY
       If Group Result status is 0, then Group Result End status will definitely
       be 0
    */
    if ((GrpStat != ADC_IDLE) && (GrpRes == (Adc_StatusType)0))
    {
      /* Group status is ADC_BUSY, return E_NOT_OK without any action */
      NoOfValidConv = (Adc_StreamNumSampleType)0;
    }
    else
    {
      /* Get the Adc Group Configuration Pointer */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
      PBConfigStructure and is within allowed range*/
      GrpPtr = Adc_kConfigPtr->CfgPtr[Kernel]->GrpCfgPtr + GroupId;

      /* Note:If Group status is ADC_IDLE and number of valid conversion 
         result available is not 0, then Group results are read.
      */
      /* Note: Check for zero no. of valid converstion results in ADC_IDLE 
         state is done at DET
      */
         
      /* Enter Critical section */
      Adc_lSchmEnterGetStreamLastPtr();
      

      /* Read the no. of valid converstion results available */
      NoOfValidConv = DataPtr->NumValidConRes[GroupId];
      /* latest valid data location in result buffer */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
      result buffer and is within allowed range*/
      CurrentResBufPtr = DataPtr->GroupResultBuffer[GroupId] + \
                          (NoOfValidConv - (Adc_StreamNumSampleType)1);

      BufferEndStatus = (uint32)Adc_lGetResBuffEndStatus(DataPtr,GroupId);

      /* Exit Critical section */
      Adc_lSchmExitGetStreamLastPtr();

      if (BufferEndStatus)
      {
        /* All the location in result buffer is filled with valid data */
        NoOfValidConv = GrpPtr->NumSamples;
      }

      *PtrToSamplePtr = CurrentResBufPtr;
      
      /* ADC327: Calling function Adc_GetStreamLastPointer while group status 
         is ADC_STREAM_COMPLETED shall trigger a state transition to ADC_IDLE 
         for conversion modes which automatically stop the conversion 
         Possible combinations are:
         Linear Groups in ADC_STREAM_COMPLETED state
         1. Sw Trigger, Oneshot (Default : Single - Linear)
         2. Sw Trigger, Continuous, Streaming - Linear
         3. Hw Trigger, Oneshot, Streaming - Linear
         Request source has already stopped or Disabled the request source 
         for further conversion and GroupStatus variableis already in 
         IDLE state
         Hence, clearing of Result Buffer status and Result Buffer End status 
         is required for state transition to ADC_IDLE 
      */
      /* Note: Set the Group status to ADC_IDLE, but the converted result data
         are avilable for the user 
      */
      /* ADC326: Calling function Adc_GetStreamLastPointer while group status 
         is ADC_STREAM_COMPLETED shall trigger a state transition to ADC_BUSY 
         for continuous conversion modes
         ADC328: Calling function Adc_GetStreamLastPointer while group status is
         ADC_COMPLETED shall trigger a state transition to ADC_BUSY 
         Possible combinations are:
         Continuous Groups either in ADC_STREAM_COMPLETED or ADC_COMPLETED
         1. Sw Trigger, Continuous, Streaming - Continuous 
         2. Hw Trigger, Oneshot, Streaming - Continuous
         Linear Groups in ADC_COMPLETED state
         1. Sw Trigger, Oneshot (Default : Single - Linear)
         2. Sw Trigger, Continuous, Streaming - Linear
         3. Hw Trigger, Oneshot, Streaming - Linear
      */

      /* Enter Critical section */
      Adc_lSchmEnterGetStreamLastPtr();

      /* Clear ADC Group Result Status on read */
      Adc_lClrGroupResultAtomic(DataPtr,GroupId);

      /* Clear the Buffer end status */
      Adc_lClrResBuffEndStatusAtomic(DataPtr,GroupId);

      /* Exit Critical section */
      Adc_lSchmExitGetStreamLastPtr();
    } /* When Group is not in ADC_BUSY state */

    RetVal = NoOfValidConv;
  }

/*------------------------------------------**
** Return the no. of valid result available **
**------------------------------------------*/
  return (RetVal);

}/* Adc_GetStreamLastPointer */                                       
#endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */

#if (ADC_GROUP_EMUX_SCAN == STD_ON)
/*******************************************************************************
** Traceabilty      :[cover parentID=DS_MCAL_ADC_0402_4]
** Syntax           : void Adc_IsrDmaSrn(uint8 AdcKernel)                     **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function                                           **
**  - Handles the interrupts from DMA on transfer complete                    **
**  - Must be called in ISR of DMA_SRC3                                       **
*******************************************************************************/
void Adc_IsrDmaSrn(uint8 AdcKernel)
{
  Adc_GlobalDataType         *DataPtr;
  const Adc_KernelConfigType *KernelPtr;
  const Adc_GroupCfgType     *GrpPtr;
  Dma_ChannelType            DmaChannel;
  uint32                     DmaIntrStatus;
  #if (ADC_ENABLE_QUEUING == STD_ON)
  Adc_GroupType              PopGrpId;
  #endif /* (ADC_ENABLE_QUEUING == STD_ON) */
  Adc_GroupType              GrpNr;
  uint8                      GrpRequestSrc;
  
  /* Get ADC Kernel index for variables */
  /* Assign the address of ASIL or QM signal variable to global data pointer*/
  DataPtr = Adc_lGetDataAddress(AdcKernel);

  KernelPtr = Adc_kConfigPtr->CfgPtr[AdcKernel];
  
  DmaChannel = (Dma_ChannelType)KernelPtr->HwCfgPtr->DmaChannel;
  
  /* Check ICH bit being Set for DMA channel */
  DmaIntrStatus = ADC_SFR_RUNTIME_MCAL_DMAGETTRANSFERINTSTATUS(DmaChannel);

  /* AoU : Interrupt Source Check */
  if(DmaIntrStatus == 1U)
  {
    /*-----------------------------------------------**
    ** Interrupt is because of ADC0 Group EMUX SCAN  **
    **-----------------------------------------------*/
    /* Clear interrupt on DMA Channel */
    ADC_SFR_RUNTIME_MCAL_DMACHCLRINTRFLAGS(DmaChannel);

    /* Disable DMA Channel on Hardware request */
    ADC_SFR_RUNTIME_MCAL_DMADISABLEHWTRANSFER(DmaChannel);

    /* Get the ADC kernel Group Id from DmaData */
    GrpNr = DataPtr->DmaData.Group;
  
    /* Get the address of Group configuration structure */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    PBConfigStructure and is within allowed range*/
    GrpPtr = (KernelPtr->GrpCfgPtr) + GrpNr;

    /* Get the Group request source */
    GrpRequestSrc = GrpPtr->GrpRequestSrc;

    /* Update Group Result value from DMA buffer into Group result buffer */
    Adc_lDmaTransResUpdate(AdcKernel);

    /* Update the status of group to ADC_COMPLETED */
    Adc_lSetGroupResultAtomic(DataPtr,GrpNr);

    /* Stop the Request source as to avoid losing any converted results */
    Adc_lStopConvRequestSource(GrpPtr,AdcKernel);

    /*Note: No need to reset the RS Group Data as it is decided 
      depending on Group buffer type i.e. linear / Circular
    */

    /* Reset ADC EMUXCTR register */
    Adc_lWriteEmuxCtrSfr(AdcKernel, 0U);
  

    /* Group with EMUX SCAN is always Continuous conversion mode */
    /* Continuous Mode - Single result access will be default Circular buffer */
    /* So, check for only circular to restart the conversion */
    if (GrpPtr->StreamBufferMode == ADC_STREAM_BUFFER_CIRCULAR)
    {
      /* Streaming and circular buffer mode considered */
      /* Restart the ADC Conversion with EMUX enabled */
      Adc_lPrepareGrpForStart(AdcKernel,GrpNr);

      /* Note: No need to update the RS Group data as reset is not done 
         on stop in the ISR
      */

      /*-----------------------------------------------------**
      ** Trigger Conversion Source :Trigger the appropriate  **
      ** Conversion Request Source                           **
      **-----------------------------------------------------*/
      #if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
      if (GrpPtr->TriggSrc == ADC_TRIGG_SRC_SW)
      {
        Adc_lStartSwConversionRS(GrpPtr,AdcKernel);
      }
      #endif /*(ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */
      #if ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) && \
                                       (ADC_HW_TRIGGER_API == STD_ON))
      else
      #endif /*SW trigg STD_ON and HW trigg STD_ON*/
      #if (ADC_HW_TRIGGER_API == STD_ON)
      {
        Adc_lStartHwConversionRS(GrpPtr,AdcKernel);
      }
      #endif /* (ADC_HW_TRIGGER_API == STD_ON) */
    }/* Restarted ADC Conversion with DMA - EMUX re initialized */
    else /* Linear buffer mode */
    {
      /* ADC316: The ADC Driver stops the conversion as soon as the
         stream buffer is full (number of samples reached).
         - for Liner buffer
      */
      /* Clear the EMUX data */
      DataPtr->EmuxGroup = ADC_INVALID_GROUP_ID;

      /* Note: Need to set the Trigger source stop flag
      */
      DataPtr->TriggSrcData[GrpRequestSrc].IsrDoNothing = ADC_NO_SERVICE;

      /* Note:
         Reset of Group RS Group data (RsGroupData) is not required
         as its been initialised with start of group conversion before reading
      */

      Adc_lSetGroupStatusIdleAtomic(DataPtr,GrpNr);

      /* Reset HW Trigger source data and Adc_AllRunningCh */
      Adc_lResetTrigSrcData(GrpPtr,DataPtr);

      /* Full priority considered */
      #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)
      /* Call to schedule next group */
      Adc_lScheduleNext(AdcKernel,GrpRequestSrc);
      #endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) */
    
      /* Queue Enable is STD_ON only during No priority */
      #if (ADC_ENABLE_QUEUING == STD_ON)
    
      Adc_lRemoveFromQueue(DataPtr,GrpNr);
    
      PopGrpId = DataPtr->PopGroupId;
      
      if (PopGrpId != ADC_INVALID_GROUP_ID)
      {
        /* The Previous Group pointer of Group which is for 
           scheduling has to be reset to invalid 
        */
        DataPtr->QueueOfSwGroup[PopGrpId].PreviousGroup = ADC_INVALID_GROUP_ID;
    
        /* Schedule the next Group conversion pointed by Pop index */
        Adc_lScheduleFromQueue(AdcKernel);
      }
      else/* If Pop Group ID is invalid, then there is no Group 
             in the Queue, Reset Push Group Id to invalid */
      {
        DataPtr->PushGroupId = ADC_INVALID_GROUP_ID;
      }
      #endif /* (ADC_ENABLE_QUEUING == STD_ON) */
    }/* Group with linear buffer */

    #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    /*-------------------------------------------------------**
    ** If notification is enabled call notification function ** 
    **-------------------------------------------------------*/
    if (( DataPtr->GrpNotifStatus & ((uint32)1 << GrpNr) ) > 0U)
    {
      /* ADC060: Call to notification function */
      GrpPtr->NotifFctPtr();
    }
    #endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
  }
} /* Adc_IsrDmaSrn */
#endif /* (ADC_GROUP_EMUX_SCAN == STD_ON) */

#if (ADC_REQSRC2 == ADC_REQSRC_USED)
#if ( ADC_TIMER_TRIGG == STD_ON )
/*******************************************************************************
** Syntax           : void Adc_17_StartGtmTimer                               **
**                    (                                                       **
**                       Adc_GroupType Group                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x29                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Adc Channel Group Id                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called when Timer trigger Group has requested for    **
**                    Enable Hardware - Background Request Source             **
**                                                                            **
** Traceability:                                                              **
** [cover parentID=DS_NAS_ADC_PR123_1] [/cover]                               **
**                                                                            **
*******************************************************************************/
void Adc_17_StartGtmTimer(Adc_GroupType Group)
{
  const Adc_GroupCfgType    *GrpPtr;
  uint32                     HwCfgData;
  uint32                     TimEnableFlag;
  Adc_GroupType              GroupId;
  uint8                      Kernel;

  /* Get Kernel number from Group ID */
  Kernel = (uint8)Adc_lGetAdcKernel(Group);
  /* Get the Group Id for perticular kernel */
  GroupId = (Adc_GroupType)Adc_lGetKernelGroupId(Group);

  /* Get the Adc Group Configuration Pointer */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
  PBConfigStructure and is within allowed range*/
  GrpPtr = Adc_kConfigPtr->CfgPtr[Kernel]->GrpCfgPtr + GroupId;

  /* Get the user config data for HW trigger */
  HwCfgData = (uint32)GrpPtr->HwTrigConfig;

  /* Get the Timer Enable bit */
  TimEnableFlag = (uint32)Adc_lGetTimEnData(HwCfgData);
  
  /* Only when timer trigger selected */
  if (TimEnableFlag == (uint32)ADC_GROUP_TIMER_ENABLE)
  {
    Adc_lGtmTimerCfg(GrpPtr);
  }

} /* Adc_17_StartGtmTimer */

/*******************************************************************************
** Syntax           : void Adc_17_StopGtmTimer                                **
**                    (                                                       **
**                       Adc_GroupType Group                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x2A                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Adc Channel Group Id                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called when Timer trigger Group has requested for    **
**                    Disable Hardware - Background Request Source            **
**                                                                            **
** Traceability:                                                              **
** [cover parentID=DS_NAS_ADC_PR123_3] [/cover]                               **
**                                                                            **
*******************************************************************************/
void Adc_17_StopGtmTimer(Adc_GroupType Group)
{
  const Adc_GroupCfgType    *GrpPtr;
  uint32                     HwCfgData;
  uint32                     TimEnableFlag;
  Adc_GroupType              GroupId;
  uint8                      Kernel;

  /* Get Kernel number from Group ID */
  Kernel = (uint8)Adc_lGetAdcKernel(Group);
  /* Get the Group Id for perticular kernel */
  GroupId = (Adc_GroupType)Adc_lGetKernelGroupId(Group);

  /* Get the Adc Group Configuration Pointer */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
  PBConfigStructure and is within allowed range*/
  GrpPtr = Adc_kConfigPtr->CfgPtr[Kernel]->GrpCfgPtr + GroupId;

  /* Get the user config data for HW trigger */
  HwCfgData = (uint32)GrpPtr->HwTrigConfig;

  /* Get the Timer Enable bit */
  TimEnableFlag = (uint32)Adc_lGetTimEnData(HwCfgData);
  
  /* Only when timer trigger selected */
  if (TimEnableFlag == (uint32)ADC_GROUP_TIMER_ENABLE)
  {
    Adc_lStopGtmTimer(GrpPtr);
  }
} /* Adc_17_StopGtmTimer */
#endif /*  ADC_TIMER_TRIGG == STD_ON */

#if ( (ADC_ERU_TRIGG == STD_ON) || (ADC_ERU_GATING == STD_ON) )
/*******************************************************************************
** Syntax           : void Adc_17_SetEruTrigger                               **
**                    (                                                       **
**                       Adc_GroupType Group                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x2B                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Adc Channel Group Id                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called when ERU trigger Group has requested for      **
**                    Enable Hardware - Background Request Source             **
**                                                                            **
** Traceability:                                                              **
** [cover parentID=DS_NAS_ADC_PR123_2] [/cover]                               **
**                                                                            **
*******************************************************************************/
void Adc_17_SetEruTrigger(Adc_GroupType Group)
{
  const Adc_GroupCfgType    *GrpPtr;
  #if (ADC_ERU_TRIGG == STD_ON)
  uint32                    HwCfgData;
  uint32                    EruTrigFlag;
  #endif /* (ADC_ERU_TRIGG == STD_ON) */
  Adc_GroupType             GroupId;
  uint8                     Kernel;

  /* Get Kernel number from Group ID */
  Kernel = (uint8)Adc_lGetAdcKernel(Group);
  /* Get the Group Id for perticular kernel */
  GroupId = (Adc_GroupType)Adc_lGetKernelGroupId(Group);

  /* Get the Adc Group Configuration Pointer */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
  PBConfigStructure and is within allowed range*/
  GrpPtr = Adc_kConfigPtr->CfgPtr[Kernel]->GrpCfgPtr + GroupId;

  #if (ADC_ERU_TRIGG == STD_ON)
  /* Get the user config data for HW trigger */
  HwCfgData = (uint32)GrpPtr->HwTrigConfig;

  /* Get the Group ERU trigger flag */
  EruTrigFlag = Adc_lGetEruData(HwCfgData);

  if (EruTrigFlag == (uint32)ADC_TRIG_ERU_SELECTED)
  {
    /* Trigger is by ERU IOUT Signal */
    Adc_lEruTrigCfg(HwCfgData);
  }
  #endif /* (ADC_ERU_TRIGG == STD_ON) */

} /* Adc_17_SetEruTrigger */

/*******************************************************************************
** Syntax           : void Adc_17_ResetEruTrigger                             **
**                    (                                                       **
**                       Adc_GroupType Group                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x2C                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : Adc Channel Group Id                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Is called when ERU trigger Group has requested for      **
**                    Diable Hardware - Background Request Source             **
**                                                                            **
** Traceability:                                                              **
** [cover parentID=DS_NAS_ADC_PR123_4] [/cover]                               **
**                                                                            **
*******************************************************************************/
void Adc_17_ResetEruTrigger(Adc_GroupType Group)
{
  const Adc_GroupCfgType    *GrpPtr;
  #if (ADC_ERU_TRIGG == STD_ON)
  uint32                    HwCfgData;
  uint32                    EruTrigFlag;
  #endif /* (ADC_ERU_TRIGG == STD_ON) */
  Adc_GroupType             GroupId;
  uint8                     Kernel;

  /* Get Kernel number from Group ID */
  Kernel = (uint8)Adc_lGetAdcKernel(Group);
  /* Get the Group Id for perticular kernel */
  GroupId = (Adc_GroupType)Adc_lGetKernelGroupId(Group);

  /* Get the Adc Group Configuration Pointer */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
  PBConfigStructure and is within allowed range*/
  GrpPtr = Adc_kConfigPtr->CfgPtr[Kernel]->GrpCfgPtr + GroupId;

  #if (ADC_ERU_TRIGG == STD_ON)
  /* Get the user config data for HW trigger */
  HwCfgData = (uint32)GrpPtr->HwTrigConfig;

  /* Get the Group ERU trigger flag */
  EruTrigFlag = Adc_lGetEruData(HwCfgData);

  if (EruTrigFlag == (uint32)ADC_TRIG_ERU_SELECTED)
  {
    /* Resetting ERU IOUT Signal */
    Adc_lResetEruCfg(HwCfgData,ADC_RUNTIME_ACCESS);
  }
  #endif /* (ADC_ERU_TRIGG == STD_ON) */

} /* Adc_17_ResetEruTrigger */
#endif /*  ADC_ERU_TRIGG == STD_ON */

#endif /* (ADC_REQSRC2 == ADC_REQSRC_USED) */

#if (ADC_RESULT_POLLING_MODE == STD_ON)
/*******************************************************************************
** Traceabilty      :[cover parentID=DS_NAS_HE2_ADC_PR3031,DS_NAS_EP_ADC_PR3031,
                     DS_NAS_HE2_ADC_PR3035,DS_NAS_EP_ADC_PR3035]              **
** Syntax           : Std_ReturnType Adc_17_GetGroupResult                    **
**                    (                                                       **
**                      Adc_GroupType Group                                   **
**                      Adc_ValueGroupType *DataBufferPtr                     **
**                    )                                                       **
**[/cover]                                                                    **
**                                                                            **
** Service ID       : 0x2E                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : re-entrant                                              **
**                                                                            **
** Parameters(in)   : Group - Numeric ID of requested ADC Channel group.      **
**                                                                            **
** Parameters (out) : DataBufferPtr - Location to store the requested Group's **
**                    channels conversion result                              **
**                                                                            **
** Return value     : E_OK - DET or Safety errors not occured                 **
**                    E_NOT_OK - DET or Safety errors occured                 **
**                                                                            **
** Description      : This function: reads the latest available conversion    **
**                    results of the requested group in a polling mode        **
**                                                                            **
*******************************************************************************/
Std_ReturnType Adc_17_GetGroupResult
(
  Adc_GroupType Group,
  Adc_ValueGroupType *DataBufferPtr 
)
{
  const Adc_GroupCfgType    *GrpPtr;
  const Adc_ChannelCfgType  *ChPtr;
  uint32                    NoOfChannels;
  uint32                    ChCfgData;
  uint32                    ResVal;

  #if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
  uint32 Err;
  #endif
  /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */

  Adc_GroupType             GroupId;
  Std_ReturnType            RetStatus;
  Adc_ChannelType           ChIdx;
  uint8                     Kernel;
  uint8                     LoopCnt;
  uint8                     ChannelNum;

  /* Get Kernel number from Group ID */
  Kernel = (uint8)Adc_lGetAdcKernel(Group);
  /* Get the Group Id for perticular kernel */
  GroupId = (Adc_GroupType)Adc_lGetKernelGroupId(Group);

  #if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
  
  /* Check for ADC_E_PARAM_GROUP */
  Err = Adc_lValidateParamGroup(ADC_SID_GET_GROUP_RESULT, GroupId, Kernel);
  
  #if (ADC_SAFETY_ENABLE == STD_ON)
  if (Err == ADC_E_DET_NO_ERR)
  {
    /* Get the Adc Group Configuration Pointer */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    PBConfigStructure and is within allowed range*/
    GrpPtr = Adc_kConfigPtr->CfgPtr[Kernel]->GrpCfgPtr + GroupId;

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    Group Configuration Structure and is within allowed range*/
    if(DataBufferPtr[0] != GrpPtr->BufferMarker)
    {
      SafeMcal_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE,
                            ADC_SID_GET_GROUP_RESULT, ADC_E_PARAM_POINTER
                          );
    
      Err = (uint32)ADC_E_PARAM_POINTER;
    }
  }
  #endif /* (ADC_SAFETY_ENABLE == STD_ON) */

  if (Err != ADC_E_DET_NO_ERR)
  {
   
    /* If error detected, the service will return with E_NOT_OK */
    RetStatus = (Std_ReturnType)E_NOT_OK;
  }
  else
  #endif
  /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */
  {
    /* Get the Adc Group Configuration Pointer */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    PBConfigStructure and is within allowed range*/
    GrpPtr = Adc_kConfigPtr->CfgPtr[Kernel]->GrpCfgPtr + GroupId;

    /* Get the configured no. of channels in a group */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    Group Configuration Structure and is within allowed range*/
    NoOfChannels = (uint32)(GrpPtr->GroupDefinition)[0];
    
    /* Get the starting address of the Channel Config data array */
    ChPtr = (Adc_kConfigPtr->CfgPtr[Kernel]->ChCfgPtr);
    
    /* Total number of channels in a Group will be atleast one */
    LoopCnt = 0U;
    do
    {
      /* Get the Channel Index from group definition */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
      Group Configuration Structure and is within allowed range*/
      ChIdx = (GrpPtr->GroupDefinition)[(LoopCnt + 1U)];
  
      /* Get the Channel configuration data value for ChIdx */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
      Channel Configuration Structure and is within allowed range*/
      ChCfgData = ChPtr[ChIdx].AdcChConfigValue;
  
      /* Get the Internal channel number from Channel config data */
      ChannelNum = (Adc_ChannelType)Adc_lGetKernelChNum(ChCfgData);

      /* Get the conversion Result of the channel from RESy Reg */
      ResVal = Adc_lReadResult(Kernel, ChannelNum);

      #if ( (ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT) && \
                       (ADC_RESULT_ACCUMULATION == ADC_RES_ACCUMULATION_NONE) )
      /* Store the channel conversion result with alignement into the
       requested buffer */
      Adc_lAlignResultBuffer(Kernel, Group, DataBufferPtr, ResVal);
      #else

      *DataBufferPtr = (Adc_ValueGroupType)(ResVal);

      #endif /* (ADC_RESULT_ALIGNMENT == ADC_ALIGN_RIGHT) */
      
      /* Increment the DataBufferPtr to point to the next location */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
      result buffer and is within allowed range*/
      DataBufferPtr++;
      
      LoopCnt++;

      /* Decrement the loop count */
      NoOfChannels--;

    } while (NoOfChannels > 0U);

    /* Set the return status to E_OK */
    RetStatus = (Std_ReturnType)E_OK;

  }

  return (RetStatus);

}/* Adc_17_GetGroupResult */

/*******************************************************************************
** Traceabilty      :[cover parentID=DS_NAS_HE2_ADC_PR3032,
                     DS_NAS_EP_ADC_PR3032]                                    **
** Syntax           : Std_ReturnType Adc_17_GetChannelStatus                  **
**                    (                                                       **
**                      uint8 ChannelNumber                                   **
**                    )                                                       **
**[/cover]                                                                    **
**                                                                            **
** Service ID       : 0x2F                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : re-entrant                                              **
**                                                                            **
** Parameters(in)   : Group - Numeric ID of requested ADC Channel.            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : E_OK - Channel conversion is completed                  **
**                    E_NOT_OK - Channel conversion is ongoing                **
**                                                                            **
** Description      : This function: checks the end of requested analog       **
**                    channel conversion in a polling mode                    **
**                                                                            **
*******************************************************************************/
Std_ReturnType Adc_17_GetChannelStatus
(
  uint8 ChannelNumber
)
{
  #if (ADC_SAFETY_ENABLE == STD_ON)
  uint32 Err;
  #endif /* (ADC_SAFETY_ENABLE == STD_ON) */

  Std_ReturnType            RetStatus;
  uint8                     Kernel;
  uint8                     ChNum;

  /* Set the return status to E_NOT_OK */
  RetStatus = (Std_ReturnType)E_NOT_OK;

  /* Get Kernel number from Group ID */
  Kernel = (uint8)((ChannelNumber & ADC_KERNEL_MASK) >>\
                                         (ADC_KERNEL_NUM_SHIFT_POS));

  #if (ADC_SAFETY_ENABLE == STD_ON)
  
  Err = ADC_E_DET_NO_ERR;

  if (Kernel < ADC_MAX_KERNELS)
  {
    if (Adc_kConfigPtr->CfgPtr[Kernel] == NULL_PTR)
    {
      Err = (uint32)ADC_E_PARAM_CHANNEL;
    }
  }
  else
  {
    Err = (uint32)ADC_E_PARAM_CHANNEL;
  }

  if (Err == (uint32)ADC_E_PARAM_CHANNEL)
  {
    SafeMcal_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE, 
                          ADC_SID_GET_CHANNEL_STATUS, ADC_E_PARAM_CHANNEL
                        );    
  }
  else
  #endif /* (ADC_SAFETY_ENABLE == STD_ON) */
  {
    /* Get channel number from analog channel number */
    ChNum = (uint8)(ChannelNumber & ADC_AN_CH_MASK);
    /* Read the valid flag of the result register */
    if(Adc_lReadValidFlag(Kernel,ChNum) != 0U)
    {
      /* Set the return status to E_OK */
      RetStatus = (Std_ReturnType)E_OK;
    }
  }

  return (RetStatus);

}/* Adc_17_GetChannelStatus */

#endif /* (ADC_RESULT_POLLING_MODE == STD_ON) */


/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

#if ( (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) )
/*******************************************************************************
** Syntax           : static uint32 Adc_lValidateParamGroup                   **
**                    (                                                       **
**                      uint8 ServiceId,                                      **
**                      Adc_GroupType Group,                                  **
**                      uint8 AdcKernel                                       **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters(in)   : ServiceId - Service ID of the calling API               **
**                    Group - Numeric ID of requested ADC Channel group       **
**                    AdcKernel - Group HW Unit ID                            **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Error code if error detected else ADC_E_DET_NO_ERR      **
**                                                                            **
** Description      : Local funtion :                                         **
**                    Service for validating the group parameters and         **
**                    reporting DET                                           **
**                                                                            **
** Traceability:                                                              **
** [cover parentID=DS_NAS_ADC_PR127_2] [/cover]                               **
**                                                                            **
*******************************************************************************/
static uint32 Adc_lValidateParamGroup
                    (uint8 ServiceId, Adc_GroupType Group, uint8 AdcKernel)
{
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  const Adc_GroupCfgType     *GrpPtr;
  #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
  const Adc_KernelConfigType *CfgPtr;
  uint32                     RetErr;

  RetErr = ADC_E_DET_NO_ERR;
  
  if (AdcKernel < ADC_MAX_KERNELS)
  {
    CfgPtr = Adc_kConfigPtr->CfgPtr[AdcKernel];
  
    if (CfgPtr == NULL_PTR)
    {
      RetErr = (uint32)ADC_E_PARAM_GROUP;
    }
    /*Group id is out of range*/
    else if (Group >= CfgPtr->TotCfgGrps)
    {
      RetErr = (uint32)ADC_E_PARAM_GROUP;
    }
    else
    {
      /* Do-Nothing*/
    }
  }
  else
  {
    RetErr = (uint32)ADC_E_PARAM_GROUP;
  }

  if (RetErr == (uint32)ADC_E_PARAM_GROUP)
  {
    /* ADC269, ADC065: Invalid group ID passed, report DET error */
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
    Det_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE, 
                     ServiceId, ADC_E_PARAM_GROUP
                   );    
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
    
    #if (ADC_SAFETY_ENABLE == STD_ON)
    SafeMcal_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE, 
                          ServiceId, ADC_E_PARAM_GROUP
                        );    
    #endif /* (ADC_SAFETY_ENABLE == STD_ON) */
  }
  #if (ADC_DEV_ERROR_DETECT == STD_ON)
  else
  {
    CfgPtr = Adc_kConfigPtr->CfgPtr[AdcKernel];
  
    /* Parameter Group ID is valid check for other errors */
    
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
    Group Configuration Structure and is within allowed range*/
    GrpPtr = (CfgPtr->GrpCfgPtr + Group);
    

    switch (ServiceId)
    {
      #if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)      
      case ADC_SID_START_GROUP_CONVERSION:
      {

        RetErr = Adc_lSwConvDetCheck(ServiceId, AdcKernel, Group);
        
      }/* ADC_SID_START_GROUP_CONVERSION */
      break;
      case ADC_SID_STOP_GROUP_CONVERSION:
      {

        if (GrpPtr->TriggSrc != ADC_TRIGG_SRC_SW)
        {
          /* ADC164: Group with trigger source not configured as Software */
          Det_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE, 
                           ServiceId, ADC_E_WRONG_TRIGG_SRC
                         );    
          RetErr = (uint32)ADC_E_WRONG_TRIGG_SRC;
        }
      }/* ADC_SID_STOP_GROUP_CONVERSION */
      break;
      #endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */
        
      #if (ADC_HW_TRIGGER_API == STD_ON)
      case ADC_SID_ENABLE_HARDWARE_TRIGGER:
      {
        /* Error check function for Enable Hardware trigger */
        RetErr = Adc_lValParamGrpEnableHwTrigg(ServiceId, Group, AdcKernel);
        
      } /* ADC_SID_ENABLE_HARDWARE_TRIGGER */
      break;
      
      case ADC_SID_DISABLE_HARDWARE_TRIGGER:
      {
        if (GrpPtr->TriggSrc != ADC_TRIGG_SRC_HW)
        {
          /* ADC136: Group with trigger source not configured as Hardware */
          Det_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE, 
                           ServiceId, ADC_E_WRONG_TRIGG_SRC
                         );    
          RetErr = (uint32)ADC_E_WRONG_TRIGG_SRC;
        }

        else if (GrpPtr->ConvMode == ADC_CONV_MODE_CONTINUOUS)
        {
          /* ADC281: Service is called for group with continuous mode, 
             report the DET error */
          Det_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE, 
                           ServiceId, ADC_E_WRONG_CONV_MODE
                         );    
          RetErr = ADC_E_WRONG_CONV_MODE;
        }
        else
        {
          /* Do Nothing */
        }
      } /* ADC_SID_DISABLE_HARDWARE_TRIGGER */        
      break;
      #endif /* (ADC_HW_TRIGGER_API == STD_ON) */

      #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
      case ADC_SID_ENABLE_GROUP_NOTIFICATION:
      case ADC_SID_DISABLE_GROUP_NOTIFICATION:
      {
        /* ADC165,166: If function pointer is NULL, DET is reported */
        if (GrpPtr->NotifFctPtr == NULL_PTR)
        {
          Det_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE, 
                           ServiceId, ADC_E_NOTIF_CAPABILITY
                         );    
          RetErr = ADC_E_NOTIF_CAPABILITY;
        }
      }
      break;
      #endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
      
      /* UTP AI00135619 */
      default:
      break;
    }  /* Switch for ServiceId */
  } /* Check for Group parameter */
  #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
    
  return RetErr;

} /* Adc_lValidateParamGroup */

#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) || (ADC_SAFETY_ENABLE == STD_ON) */

#if (ADC_DEV_ERROR_DETECT == STD_ON)
/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE uint32 Adc_lCheckInit(uint8 ServiceId) **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters(in)   : ServiceId - Service ID of the calling API               **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Error code if error detected else ADC_E_DET_NO_ERR      **
**                                                                            **
** Description      : Local inline funtion :                                  **
**                    Service for ADC_E_UNINIT DET check and reporting        **
**                                                                            **
** Traceability:                                                              **
** [cover parentID=DS_NAS_ADC_PR127_1] [/cover]                               **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE uint32 Adc_lCheckInit(uint8 ServiceId)
{
  uint32 RetErr;
  
  RetErr = ADC_E_DET_NO_ERR;

  if (Adc_InitStatus != ADC_INITIALIZED)
  {
    /* ADC107: Reporting of error ADC_E_UNINIT */
    Det_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE, 
                     ServiceId, ADC_E_UNINIT
                   );    
    RetErr = (uint32)ADC_E_UNINIT;
  }

  return RetErr;

} /* Adc_lCheckInit */

/* Enable/Disable the use of the function */
#if((ADC_ENABLE_START_STOP_GROUP_API == STD_ON)||(ADC_HW_TRIGGER_API == STD_ON))
/*******************************************************************************
** Syntax           : static uint32 Adc_lCheckDriverState                     **
**                    (                                                       **
**                      uint8 ServiceId,                                      **
**                      Adc_GroupType Group,                                  **
**                      uint8 AdcKernel                                       **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters(in)   : ServiceId - Service ID of the calling API               **
**                    Group - Numeric ID of requested ADC Channel group       **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Error code if error detected else ADC_E_DET_NO_ERR      **
**                                                                            **
** Description      : Local funtion :                                         **
**                    Service for checking the applicable driver state for    **
**                    API call and reporting DET                              **
**                                                                            **
** Traceability:                                                              **
** [cover parentID=DS_NAS_ADC_PR127_4] [/cover]                               **
**                                                                            **
*******************************************************************************/
static uint32 Adc_lCheckDriverState
                       (uint8 ServiceId, Adc_GroupType Group, uint8 AdcKernel)
{
  Adc_GlobalDataType          *DataPtr;
  uint32                      RetErr;
  Adc_StatusType              GrpStat;
  Adc_StatusType              GrpRes;
  #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
  Adc_StreamNumSampleType     NoOfValidConv;
  #endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */

  RetErr = ADC_E_DET_NO_ERR;

  /* Get ADC Kernel index for variables */
  /* Assign the address of ASIL or QM signal variable to global data pointer*/
  DataPtr = Adc_lGetDataAddress(AdcKernel);

  GrpStat = (Adc_StatusType)Adc_lGetGroupStatus(DataPtr,Group);

  switch (ServiceId)
  {

    #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
    
    #if (ADC_READ_GROUP_API == STD_ON)
    case ADC_SID_READ_GROUP:
    #endif /* (ADC_READ_GROUP_API == STD_ON) */
    case ADC_SID_GET_STREAM_LAST_POINTER:
    {
      /* ADC388, ADC215: If Group Status is ADC_IDLE and no results are 
         available from previous conversion, then Report error */
      
      /* If Group status and Group result status are Idle, the group 
         status is ADC_IDLE. */

      GrpRes = (Adc_StatusType)Adc_lGetGroupResult(DataPtr,Group);

      /* Read the no. of valid converstion results available */
      NoOfValidConv = DataPtr->NumValidConRes[Group];

      
      /* Check for Group status to be ADC_IDLE and 
         availability of Group valid conversion result
      */
      if (((GrpStat == ADC_IDLE) && (GrpRes == ADC_IDLE)) &&
           (NoOfValidConv == (Adc_StreamNumSampleType)0)
         )
      {
      
        /* Service is while the group is in Idle state */
        Det_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE, 
                         ServiceId, ADC_E_IDLE
                       );    
        RetErr = ADC_E_IDLE;
      }
    }/* ADC_SID_READ_GROUP/ADC_SID_GET_STREAM_LAST_POINTER */
    break;
    #endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */

    #if( (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) ||              \
                                        (ADC_HW_TRIGGER_API == STD_ON) )    
    case ADC_SID_STOP_GROUP_CONVERSION:
    case ADC_SID_DISABLE_HARDWARE_TRIGGER:
    {
      
      #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
      GrpRes = (Adc_StatusType)Adc_lGetGroupResult(DataPtr,Group);
      #else /* (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR) */
      GrpRes = (Adc_StatusType)Adc_lGetResBuffEndStatus(DataPtr,Group);
      #endif /* Check on result handling mode */

      /* If Group status and Group result status are Idle then return DET */
      if ((GrpStat == ADC_IDLE) && (GrpRes == (Adc_StatusType)0))
      {
      
        /* ADC241: Service is while the group is in Idle state */
        /* Group will go to ADC_IDLE state by explicit stop API call
           or by reading the Group result data
        */
        Det_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE, 
                         ServiceId, ADC_E_IDLE
                       );
        RetErr = ADC_E_IDLE;
      }

    }/* ADC_SID_STOP_GROUP_CONVERSION */
    
    break;
    
    #endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */    


    /* ADC_SID_SETUP_RESULT_BUFFER is used as default case */
    default:

    #if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
    {
      /* Check if the Group is already in queue or busy still under conversion
         i.e. Group not Idle, then Report ADC_E_BUSY error
      */
      /* The Groups which are implicitly stopped, 
         can be started again and the result buffer pointer can be 
         set again
      */
      if (GrpStat != ADC_IDLE)
      {
        /* Service is called while requested group is already 
           started / Enabled. Which Implies Group result buffer pointer is 
           already initialised and stated/Enabled for conversion
        */
        Det_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE, 
                         ServiceId, ADC_E_BUSY
                       );    
        RetErr = ADC_E_BUSY;
      }
    }/* ADC_SID_SETUP_RESULT_BUFFER */
    #endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */

    break;
    
  }/* Switch for ServiceId */
    
  return RetErr;

} /* Adc_lCheckDriverState */
#endif /* ADC_ENABLE_START_STOP_GROUP_API or ADC_HW_TRIGGER_API is STD_ON */

/* Enable/Disable the use of the function */
#if( (ADC_HW_TRIGGER_API == STD_ON) && (ADC_RESULT_POLLING_MODE == STD_OFF) )
/*******************************************************************************
** Syntax           : static uint32 Adc_lCheckStateForEnableGroup             **
**                    (                                                       **
**                      Adc_GroupType Group,                                  **
**                      uint8 AdcKernel                                       **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters(in)   : Group - Numeric ID of requested ADC Channel group       **
**                    AdcKernel - ADC Kernel for the Group                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Error code if error detected else ADC_E_DET_NO_ERR      **
**                                                                            **
** Description      : Local funtion :                                         **
**                    Service for checking the applicable driver state for    **
**                    Adc_EnableHardwareTrigger API call and reporting DET    **
*******************************************************************************/
static uint32 Adc_lCheckStateForEnableGroup
(
  Adc_GroupType Group,
  uint8 AdcKernel
)
{
  Adc_GlobalDataType         *DataPtr;
  #if ( (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) ||  \
                                           (ADC_REQSRC2 == ADC_REQSRC_USED) )
  const Adc_KernelConfigType *CfgPtr;
  const Adc_GroupCfgType     *GrpPtr;
  #endif
  uint32                     RetErr;
  #if ( (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) ||  \
                                           (ADC_REQSRC2 == ADC_REQSRC_USED) )
  uint8                      GroupReqSrc;
  #endif 

  /* Get ADC Kernel index for variables */
  /* Assign the address of ASIL or QM signal variable to global data pointer*/
  DataPtr = Adc_lGetDataAddress(AdcKernel);

  #if ( (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) ||  \
                                           (ADC_REQSRC2 == ADC_REQSRC_USED) )
  CfgPtr = Adc_kConfigPtr->CfgPtr[AdcKernel];
  
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
  Group Configuration Structure and is within allowed range*/
  GrpPtr = (CfgPtr->GrpCfgPtr + Group);
  GroupReqSrc = GrpPtr->GrpRequestSrc;
  
  #else
  
  /* to remove the unused param warning in GNU */
  UNUSED_PARAMETER(Group)
  
  #endif 
  
  #if (ADC_REQSRC2 == ADC_REQSRC_USED)
  
  if( (GroupReqSrc == ADC_REQSRC2_BGND_SCAN) && 
      (Adc_BgndScanData == ADC_TRIGG_SRC_SW)
    )
  {
    /* Service is called while conversion request for the 
       particular HW trigger source is not free. 
       Report DET error 
    */
    Det_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE, 
                     ADC_SID_ENABLE_HARDWARE_TRIGGER, ADC_E_BUSY
                   );    
    RetErr = ADC_E_BUSY;
  }
  else
  #endif /* (ADC_REQSRC2 == ADC_REQSRC_USED) */
  {
  /* Priority implementation switched off */    
    #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)    
    RetErr = ADC_E_DET_NO_ERR;
    /* Check if any group is in the busy status */
    if (Adc_lGetGroupStatusAll(DataPtr) != (uint32)0)
    {
      /* ADC306: Service is called while ADC is busy in conversion. 
         Priority mechanism switched off. Report DET error */
      Det_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE, 
                      ADC_SID_ENABLE_HARDWARE_TRIGGER, ADC_E_BUSY
                     );    
      RetErr = ADC_E_BUSY;
    }
  /* (ADC_PRIORITY_IMPLEMENTATION == 0) */
    #else      
  /* Hardware Priority mechanism considered  or 
     Full priority considered 
  */
    /* Check for HW trigger source free */
    if (DataPtr->TriggSrcData[GroupReqSrc].GrpId != 
         ADC_GRP_REQ_SRC_FREE
       )
    {
      /* Service is called while conversion request for the requested HW 
         trigger source is already enabled 
         Priority mechanism switched STD_ON. Report DET error */
      Det_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE, 
                       ADC_SID_ENABLE_HARDWARE_TRIGGER, ADC_E_BUSY
                     );    
      RetErr = ADC_E_BUSY;
    }
    /* HW Trigger Source is free,
       so check for if the CHCTRy register get shared */
    else
    {
        /* Get the group channel overlapping / EMUX Group in use from the 
           Driver status variables */
        RetErr = Adc_lCheckResourceConflict(DataPtr,
                                            GrpPtr, 
                                            ADC_SID_ENABLE_HARDWARE_TRIGGER
                                           );
    }
    #endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) */
         /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) */
  }
  return RetErr;
}/* Adc_lCheckStateForEnableGroup */
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

/* Enable/Disable the use of the function */
#if( (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) &&\
                               (ADC_RESULT_POLLING_MODE == STD_OFF) )
/*******************************************************************************
** Traceabilty      :[cover parentID=DS_AS_ADC333,DS_NAS_ADC_PR127_5]         **
** Syntax           : static uint32 Adc_lCheckStateForStartGroup              **
**                    (                                                       **
**                      Adc_GroupType Group,                                  **
**                      uint8 AdcKernel                                       **
**                    )                                                       **
**[/cover]                                                                    **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters(in)   : Group - Numeric ID of requested ADC Channel group       **
**                    AdcKernel - ADC Kernel for the Group                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Error code if error detected else ADC_E_DET_NO_ERR      **
**                                                                            **
** Description      : Local funtion :                                         **
**                    Service for checking the applicable driver state for    **
**                    Adc_StartGroupConversion API call and reporting DET     **
**                                                                            **
**                                                                            **
*******************************************************************************/
static uint32 Adc_lCheckStateForStartGroup
(
  Adc_GroupType Group, 
  uint8 AdcKernel
)
{
  Adc_GlobalDataType          *DataPtr;
  #if ( (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) ||  \
                                           (ADC_REQSRC2 == ADC_REQSRC_USED) )
  const Adc_KernelConfigType  *CfgPtr;
  const Adc_GroupCfgType      *GrpPtr;
  #endif
  uint32                      RetErr;
  #if ( (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) ||  \
                                           (ADC_REQSRC2 == ADC_REQSRC_USED) )
  uint8                       GroupReqSrc;
  #endif

  /* Get ADC Kernel index for variables */
  /* Assign the address of ASIL or QM signal variable to global data pointer*/
  DataPtr = Adc_lGetDataAddress(AdcKernel);

  #if ( (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) ||  \
                                           (ADC_REQSRC2 == ADC_REQSRC_USED) )
  CfgPtr = Adc_kConfigPtr->CfgPtr[AdcKernel];
    
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to 
  Group Configuration Structure and is within allowed range*/
  GrpPtr = (CfgPtr->GrpCfgPtr + Group);

  #else

  /* to remove the unused param warning in GNU */
  UNUSED_PARAMETER(Group)

  #endif

  #if ( (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) ||  \
                                           (ADC_REQSRC2 == ADC_REQSRC_USED) )
  GroupReqSrc = GrpPtr->GrpRequestSrc;
  #endif
  
  #if (ADC_REQSRC2 == ADC_REQSRC_USED)
  
  if( (GroupReqSrc == ADC_REQSRC2_BGND_SCAN) && 
      (Adc_BgndScanData != ADC_BGND_REQ_SRC_FREE)
    )
  {
    /* Service is called while conversion request for the 
       particular HW trigger source is not free. 
       Report DET error 
    */
    Det_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE, 
                     ADC_SID_START_GROUP_CONVERSION, ADC_E_BUSY
                   );    
    RetErr = ADC_E_BUSY;
  }
  else
  #endif /* (ADC_REQSRC2 == ADC_REQSRC_USED) */
  {  /* RS0 & RS1 */
  /* Priority implementation switched off */    
    #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)

    RetErr = ADC_E_DET_NO_ERR;

    #if (ADC_ENABLE_QUEUING == STD_OFF)
    /* Check if any group is in the busy status */
    if (Adc_lGetGroupStatusAll(DataPtr) != (uint32)0)
    {
      /* ADC346,ADC426: Service is called while ADC is busy in conversion. 
         Priority mechanism switched off. Report DET error */
      Det_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE, 
                       ADC_SID_START_GROUP_CONVERSION, ADC_E_BUSY
                     );    
      RetErr = ADC_E_BUSY;
    }
    #else
  /* Queue Enable is STD_ON only during No priority */
    /* Check if the Group is already in queue or busy still under conversion
       i.e. Group not Idle, then Report ADC_E_BUSY error
    */
    if ((Adc_StatusType)Adc_lGetGroupStatus(DataPtr,Group) != ADC_IDLE)
    {
      /* ADC351,ADC428: Service is called while requested group is already in 
         SW queue or under conversion in the ADC unit 
      */
      Det_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE, 
                       ADC_SID_START_GROUP_CONVERSION, ADC_E_BUSY
                     );    
      RetErr = ADC_E_BUSY;
    }

    #endif /* (ADC_ENABLE_QUEUING == STD_ON) */

    #endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) */

  /* Partial Priority mechanism considered */      
    #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW)

    /* Check for HW trigger source free */
    if (DataPtr->TriggSrcData[GroupReqSrc].GrpId  != 
         ADC_GRP_REQ_SRC_FREE
       )
    {
      /* Service is called while conversion request for the 
         particular HW trigger source is not free. 
         Report DET error 
      */
      Det_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE, 
                       ADC_SID_START_GROUP_CONVERSION, ADC_E_BUSY
                     );    
      RetErr = ADC_E_BUSY;
    }
    /* HW TR Source is free, so check for if the CHCON register get 
      shared */
    else
    {
      /* Get the group channel overlapping / EMUX Group in use from the 
         Driver status variables */
      RetErr = Adc_lCheckResourceConflict(DataPtr,
                                          GrpPtr, 
                                          ADC_SID_START_GROUP_CONVERSION
                                         );
    }
    #endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW) */
  /* Full priority mechanism considered */
    #if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)
    /* Check if the Group is already in queue or busy still under conversion
       i.e. Group not Idle, then Report ADC_E_BUSY error
    */
    if ((Adc_StatusType)Adc_lGetGroupStatus(DataPtr,Group) != ADC_IDLE)
    {
      /* ADC348,ADC427: Service is called while requested group is already in 
         SW queue or under conversion in the ADC unit 
      */
      Det_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE, 
                       ADC_SID_START_GROUP_CONVERSION, ADC_E_BUSY
                     );    
      RetErr = ADC_E_BUSY;
    }
    else
    {
     
      /* Get the group channel overlapping / EMUX Group in use from the 
         Driver status variables */
      RetErr = Adc_lCheckResourceConflict(DataPtr,
                                          GrpPtr, 
                                          ADC_SID_START_GROUP_CONVERSION
                                         );

    }
    #endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) */      
  }
  return RetErr;

}/* Adc_lCheckStateForStartGroup */
#endif /* ADC_ENABLE_START_STOP_GROUP_API */

/* Enable/Disable the use of the function */
#if((ADC_ENABLE_START_STOP_GROUP_API == STD_ON)||(ADC_HW_TRIGGER_API == STD_ON))
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
/*******************************************************************************
** Syntax           : static uint32 Adc_lCheckResourceConflict                **
**                    (                                                       **
**                      Adc_GlobalDataType *DataPtr,                          **
**                      const Adc_GroupCfgType *GrpPtr,                       **
**                      uint8 ServiceId                                       **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : reentrant                                               **
**                                                                            **
** Parameters(in)   : DataPtr - pointer to the data variable                  **
**                    GrpPtr - Group Config pointer                           **
**                    ServiceId - Service ID of the check API                 **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Error code if error detected else ADC_E_DET_NO_ERR      **
**                                                                            **
** Description      : Local funtion :                                         **
**                    Service for checking Group resource conflict in ADC HW  **
**                    i.e. Analog channels overlap with the group already     **
**                    enabled in hardware and EMUX in Use                     **
**                                                                            **
** Traceability:                                                              **
** [cover parentID=DS_NAS_ADC_PR127_6] [/cover]                               **
**                                                                            **
*******************************************************************************/
static uint32 Adc_lCheckResourceConflict
( 
  Adc_GlobalDataType *DataPtr,
  const Adc_GroupCfgType *GrpPtr,
  uint8 ServiceId
)
{
  uint32     RetErr;
  #if (ADC_USE_EMUX == STD_ON)
  uint32     EmuxEnable;
  Adc_GroupType EmuxGroup;
  #endif /* (ADC_USE_EMUX == STD_ON) */

  #if (ADC_USE_EMUX == STD_ON)
  EmuxEnable = (uint32)Adc_lGetEmuxEnable((uint32)GrpPtr->GroupEmuxData);
  EmuxGroup = DataPtr->EmuxGroup;
  #endif /* (ADC_USE_EMUX == STD_ON) */

  if ((GrpPtr->IntChMask & DataPtr->AllRunningCh) != 0U)
  {
    /*ADC276: Service is called while requested group channel 
       CHCTR register is already in use by the HW Queue.
       Here we are overruling the priority mechanism */
    Det_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE, 
                     ServiceId, ADC_E_BUSY
                   );    
    RetErr = ADC_E_BUSY;
  }
  #if (ADC_USE_EMUX == STD_ON)
  /* Check if Kernel Emux is already in use */
  else if ((EmuxEnable == (uint32)1) && 
            (EmuxGroup != ADC_INVALID_GROUP_ID)
          )
  {
    /*ADC276: Service is called while requested group Kernel 
       EMUX register is already in use and group is configured for EMUX.
       Here we are overruling the priority mechanism
    */
    Det_ReportError( ADC_MODULE_ID, ADC_MODULE_INSTANCE, 
                     ServiceId, ADC_E_BUSY
                   );    
    RetErr = ADC_E_BUSY;
  }
  #endif /* (ADC_USE_EMUX == STD_ON) */
  else
  {
    /* Set the channels of the Group to be started as 
       currently running channels */
    DataPtr->AllRunningCh = ((DataPtr->AllRunningCh) | (GrpPtr->IntChMask));
        
    RetErr = ADC_E_DET_NO_ERR;
  }
  
  return RetErr;
}/* Adc_lCheckResourceConflict */
#endif/*(ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)*/
#endif
/*(ADC_ENABLE_START_STOP_GROUP_API == STD_ON)||(ADC_HW_TRIGGER_API == STD_ON)*/

#if (ADC_DEINIT_API == STD_ON)
/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE Adc_StatusType Adc_lCheckGroupStatusAll**
**                    (                                                       **
**                       void                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : DataPtr - Pointer to an data variable                   **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Adc_StatusType                                          **
**                                                                            **
** Description      : Is called to Get Group Status of all the groups         **
**                    Adc_lGetGroupStatusAll() == 0 => ADC_IDLE               **
**                    Adc_lGetGroupStatusAll() != 0 => ADC_BUSY               **
**                                          (Atleast one group is busy)       **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE Adc_StatusType Adc_lCheckGroupStatusAll(void)
{
  Adc_GlobalDataType *DataPtr;
  Adc_StatusType Err;
  uint8          LoopCtr;

  Err = (Adc_StatusType)ADC_E_DET_NO_ERR;

  LoopCtr = 0U;
  do
  {
    if(Adc_lKernelConfigured((uint8)LoopCtr) != 0U)
    {
      /* Get ADC Kernel index for variables */
      /* Assign the address of ASIL or QM signal variable to 
                                                     global data pointer */
      DataPtr = Adc_lGetDataAddress(LoopCtr);

      if (Adc_lGetGroupStatusAll(DataPtr) > 0U)
      {
        Err = ADC_E_BUSY;
      }
    }
    LoopCtr++;
  }
  while (LoopCtr < ADC_MAX_KERNELS);

  return(Err);
  
} /* Adc_lCheckGroupStatusAll */
#endif /* (ADC_DEINIT_API == STD_ON) */

#endif/*(ADC_DEV_ERROR_DETECT == STD_ON)*/

#define ADC_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
/*******************************************************************************
**                            General Notes                                   **
*******************************************************************************/
/*
Notification prototype for the notification callback function. It has to
be implemented by the user.

When the notification mechanism is disabled, no notification
shall be sent. When the notifications are re-enabled again, 
the user will not be notified of events that occurred while 
notifications have been disabled.

The ADC Driver shall allow the assignment of identical channels to
more than one group. However parallel operation of groups with same 
channel are not allowed. 

All channels of a group share the same configuration related to group.

There are no registers related to ADC that can be written only one time.

The callback functions are running in the interrupt context. It's the 
responsibility of the user to keep the code short inside this function.
This is note for the user of ADC driver.
*/

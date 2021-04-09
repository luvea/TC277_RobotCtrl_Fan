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
**  $FILENAME   : SchM_Eth_17_EthMac.h $                                     **
**                                                                           **
**  $CC VERSION : \main\8 $                                                  **
**                                                                           **
**  $DATE       : 2014-03-04 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                This header file exports the exclusive area functions      **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/

#ifndef SCHM_ETH_H
#define SCHM_ETH_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "../../general/inc/Std_Types.h"
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
** Syntax           : void SchM_Enter_Eth_17_EthMac_Transmit                  **
**                    (uint8 Instance, uint8 ExclusiveArea)                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   :                                                         **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Enters Module exclusive area                            **
**                                                                            **
*******************************************************************************/
extern void SchM_Enter_Eth_17_EthMac_Transmit(void);


/*******************************************************************************
** Syntax           : void SchM_Exit_Eth_17_EthMac_Transmit                   **
**                    (uint8 Instance, uint8 ExclusiveArea)                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Exits Module exclusive area                             **
**                                                                            **
*******************************************************************************/
extern void SchM_Exit_Eth_17_EthMac_Transmit(void);

/*******************************************************************************
** Syntax           : void SchM_Enter_Eth_17_EthMac_ProvideTxBuffer           **
**                    (uint8 Instance, uint8 ExclusiveArea)                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   :                                                         **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Enters Module exclusive area                            **
**                                                                            **
*******************************************************************************/
extern void SchM_Enter_Eth_17_EthMac_ProvideTxBuffer(void);

/*******************************************************************************
** Syntax           : void SchM_Exit_Eth_17_EthMac_ProvideTxBuffer            **
**                    (uint8 Instance, uint8 ExclusiveArea)                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Exits Module exclusive area                             **
**                                                                            **
*******************************************************************************/
extern void SchM_Exit_Eth_17_EthMac_ProvideTxBuffer(void);

/*******************************************************************************
** Syntax           : void SchM_Enter_Eth_17_EthMac_SetControllerMode         **
**                    (uint8 Instance, uint8 ExclusiveArea)                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   :                                                         **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Enters Module exclusive area                            **
**                                                                            **
*******************************************************************************/
extern void SchM_Enter_Eth_17_EthMac_SetControllerMode(void);
/*******************************************************************************
** Syntax           : void SchM_Exit_Eth_17_EthMac_SetControllerMode          **
**                    (uint8 Instance, uint8 ExclusiveArea)                   **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non - Reentrant                                         **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : Exits Module exclusive area                             **
**                                                                            **
*******************************************************************************/
extern void SchM_Exit_Eth_17_EthMac_SetControllerMode(void);

#endif /* SCHM_ETH_H */

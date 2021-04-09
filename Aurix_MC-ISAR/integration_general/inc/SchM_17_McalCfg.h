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
**  $FILENAME   : SchM_17_McalCfg.h $                                        **
**                                                                           **
**  $CC VERSION : \main\2 $                                                  **
**                                                                           **
**  $DATE       : 2013-07-24 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This header file defines IFX MCAL module specific SchM    **
**                  header file names                                        **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/

#ifndef SCHM_17_MCALCFG_H
#define SCHM_17_MCALCFG_H

#ifdef SCHM_FLS_17_PMU_HEADER
#error "SCHM_FLS_17_PMU_HEADER already defined"
#endif
#define SCHM_FLS_17_PMU_HEADER         "SchM_Fls_17_Pmu.h"

#ifdef SCHM_CAN_17_MCANP_HEADER
#error "SCHM_CAN_17_MCANP_HEADER already defined"
#endif
#define SCHM_CAN_17_MCANP_HEADER         "SchM_Can_17_MCanP.h"

#ifdef SCHM_ETH_17_ETHMAC_HEADER
#error "SCHM_ETH_17_ETHMAC_HEADER already defined"
#endif
#define SCHM_ETH_17_ETHMAC_HEADER        "SchM_Eth_17_EthMac.h"

#ifdef SCHM_FR_17_ERAY_HEADER
#error "SCHM_FR_17_ERAY_HEADER already defined"
#endif
#define SCHM_FR_17_ERAY_HEADER        "SchM_Fr_17_Eray.h"

#ifdef SCHM_ICU_17_GTMCCU6_HEADER
#error "SCHM_ICU_17_GTMCCU6_HEADER already defined"
#endif
#define SCHM_ICU_17_GTMCCU6_HEADER        "SchM_Icu_17_GtmCcu6.h"

#ifdef SCHM_LIN_17_ASCLIN_HEADER
#error "SCHM_LIN_17_ASCLIN_HEADER already defined"
#endif
#define SCHM_LIN_17_ASCLIN_HEADER        "SchM_Lin_17_AscLin.h"

#ifdef SCHM_WDG_17_SCU_HEADER
#error "SCHM_WDG_17_SCU_HEADER already defined"
#endif
#define SCHM_WDG_17_SCU_HEADER        "SchM_Wdg_17_Scu.h"


#endif /* #ifndef SCHM_17_MCALCFG_H */



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
**  $FILENAME   : Fr_GeneralTypes.h $                                        **
**                                                                           **
**  $CC VERSION : \main\5 $                                                  **
**                                                                           **
**  $DATE       : 2013-06-19 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  :                                                           **
**      - FR117: FrGeneralTypes.h shall contain all types and constants that **
**        are shared among the AUTOSAR FlexRay modules Fr, FrIf and FrTrcv.  **
**        The integrator of the FlexRay modules shall provide this file.     **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/
#if !defined FR_GENERAL_TYPES
#define FR_GENERAL_TYPES

/*****************************************************************************
 Include Section
******************************************************************************/

#include "../../general/inc/Std_Types.h"      /* basic AUTOSAR type definitions */

/*****************************************************************************
 Global Macros
******************************************************************************/

/*****************************************************************************
 Global Data Types
******************************************************************************/

/*
 * This enumerator type represents the FlexRay controller POC states.
 */
typedef enum
{
    FR_POCSTATE_CONFIG = 0,     /* config state */
    FR_POCSTATE_DEFAULT_CONFIG, /* default config state */
    FR_POCSTATE_HALT,           /* halt state */
    FR_POCSTATE_NORMAL_ACTIVE,  /* normal active state */
    FR_POCSTATE_NORMAL_PASSIVE, /* normal passive state */
    FR_POCSTATE_READY,          /* ready state */
    FR_POCSTATE_STARTUP,        /* startup state */
    FR_POCSTATE_WAKEUP          /* wakeup state */
}Fr_POCStateType;

/*
 * This enumerator type represents the FlexRay controller slotmodes.
 */
typedef enum
{
    FR_SLOTMODE_KEYSLOT = 0,     /* single slot mode */
    FR_SLOTMODE_ALL_PENDING,    /* all peding slot mode */
    FR_SLOTMODE_ALL             /* all slot mode */
}Fr_SlotModeType;

/*
 * This enumerator type represents the FlexRay controller errormode.
 */
typedef enum
{
    FR_ERRORMODE_ACTIVE = 0,    /* acvtive errormode */
    FR_ERRORMODE_PASSIVE,       /* passive errormode */
    FR_ERRORMODE_COMM_HALT      /* communication halted errormode */
}Fr_ErrorModeType;


/*
 * This enumerator type represents the wakeup status type.
 */
typedef enum
{
    FR_WAKEUP_UNDEFINED = 0,    /* wakeup state "undefined" */
    FR_WAKEUP_RECEIVED_HEADER,  /* wakeup state "received header" */
    FR_WAKEUP_RECEIVED_WUP,     /* wakeup state "received wakeup pattern" */
    FR_WAKEUP_COLLISION_HEADER, /* wakeup state "collsision header" */
    FR_WAKEUP_COLLISION_WUP,    /* wakeup state "collision wakeup pattern" */
    FR_WAKEUP_COLLISION_UNKNOWN,/* wakeup state "collision unknown" */
    FR_WAKEUP_TRANSMITTED       /* wakeup state "transmitted" */
}Fr_WakeupStatusType;

/*
 * This enumerator type represents the startup status type.
 */
typedef enum
{
    FR_STARTUP_UNDEFINED = 0,                   /* startup state "undefined" */
    FR_STARTUP_COLDSTART_LISTEN,                /* startup state "coldstart listen" */
    FR_STARTUP_INTEGRATION_COLDSTART_CHECK,     /* startup state "integration coldstart check" */
    FR_STARTUP_COLDSTART_JOIN,                  /* startup state "coldstart join" */
    FR_STARTUP_COLDSTART_COLLISION_RESOLUTION,  /* startup state "collision resolution" */
    FR_STARTUP_COLDSTART_CONSISTENCY_CHECK,     /* startup state "consistency check" */
    FR_STARTUP_INTEGRATION_LISTEN,              /* startup state "integration listen" */
    FR_STARTUP_INITIALIZE_SCHEDULE,             /* startup state "initialize schedule" */
    FR_STARTUP_INTEGRATION_CONSISTENCY_CHECK,   /* startup state "integration consistency check" */
    FR_STARTUP_COLDSTART_GAP,                   /* startup state "coldstart gap" */
    FR_STARTUP_EXTERNAL_STARTUP
}Fr_StartupStateType;

/*
 * This structure contains the POC-Status information.
 */
typedef struct
{
    Fr_POCStateType State;            /*  CC - POC state */
    boolean Freeze;                   /*  CC - Freeze bit */
    boolean CHIHaltRequest;           /*  CC - CHI Halt request bit */
    boolean ColdstartNoise;           /*  CC - Coldstart noise bit */
    Fr_SlotModeType SlotMode;         /*  CC - slot mode */
    Fr_ErrorModeType ErrorMode;       /*  CC - error mode */
    Fr_WakeupStatusType WakeupStatus; /*  CC - wakeup state */
    Fr_StartupStateType StartupState; /*  CC - startup state */
}Fr_POCStatusType;


/*
 * This enumerator type represents the LSdu tx status.
 */
typedef enum
{
    FR_TRANSMITTED = 0,    /* LSdu was transmitted */
    FR_NOT_TRANSMITTED     /* LSdu was not transmitted */
}Fr_TxLPduStatusType;      

/*
 * This enumerator type represents the LSdu rx status.
 */
typedef enum
{
    FR_RECEIVED = 0,                 /* LSdu was received */
    FR_NOT_RECEIVED,                 /* LSdu was not received */
    FR_RECEIVED_MORE_DATA_AVAILABLE  /* FIFO is not empty */
}Fr_RxLPduStatusType;

/*
 * This enumerator type represents the FlexRay channels.
 */
typedef enum
{
    FR_CHANNEL_A = 0,     /* FlexRay channel A */
    FR_CHANNEL_B,         /* FlexRay channel B */
    FR_CHANNEL_AB         /* FlexRay channel A and B */
} Fr_ChannelType;

/*
 * This enumerator type represents the FlexRay transceiver driver modes.
 */
typedef enum
{
    FRTRCV_TRCVMODE_NORMAL = 0,  /* FrTrcv mode "Normal" */
    FRTRCV_TRCVMODE_STANDBY,     /* FrTrcv mode "Standby" */
    FRTRCV_TRCVMODE_SLEEP,       /* FrTrcv mode "Sleep" */
    FRTRCV_TRCVMODE_RECEIVEONLY  /* FrTrcv mode "Receive Only" */
} FrTrcv_TrcvModeType;

/*
 * This enumerator type represents the FlexRay transceiver wakeup-reasons.
 */
typedef enum
{
    FRTRCV_WU_NOT_SUPPORTED = 0,  /* FrTrcv wakeup not supported */
    FRTRCV_WU_BY_BUS,             /* FrTrcv wakeup by bus */
    FRTRCV_WU_INTERNALLY,         /* FrTrcv internally wakeup */
    FRTRCV_WU_RESET,              /* FrTrcv reset wakeup */
    FRTRCV_WU_POWER_ON            /* FrTrcv power on wakeup */
} FrTrcv_TrcvWUReasonType;

/* Macros for Configuration Parameter indices */
/* Symbolic names that can be passed into API function Fr_ReadCCConfig as 
   parameter Fr_ConfigParamIdx*/
   
#define   FR_CIDX_GDCYCLE       	                ((uint8)0U)
#define   FR_CIDX_PMICROPERCYCLE	                ((uint8)1U)
#define   FR_CIDX_PDLISTENTIMEOUT	                ((uint8)2U)
#define   FR_CIDX_GMACROPERCYCLE	                ((uint8)3U)
#define   FR_CIDX_GDMACROTICK	                    ((uint8)4U)
#define   FR_CIDX_GNUMBEROFMINISLOTS	            ((uint8)5U)
#define   FR_CIDX_GNUMBEROFSTATICSLOTS	          ((uint8)6U)
#define   FR_CIDX_GDNIT	                          ((uint8)7U)
#define   FR_CIDX_GDSTATICSLOT	                  ((uint8)8U)
#define   FR_CIDX_GDWAKEUPRXWINDOW	              ((uint8)9U)
#define   FR_CIDX_PKEYSLOTID	                    ((uint8)10U)
#define   FR_CIDX_PLATESTTX 	                    ((uint8)11U)
#define   FR_CIDX_POFFSETCORRECTIONOUT	          ((uint8)12U)
#define   FR_CIDX_POFFSETCORRECTIONSTART	        ((uint8)13U)
#define   FR_CIDX_PRATECORRECTIONOUT	            ((uint8)14U)
#define   FR_CIDX_PSECONDKEYSLOTID	              ((uint8)15U)
#define   FR_CIDX_PDACCEPTEDSTARTUPRANGE	        ((uint8)16U)
#define   FR_CIDX_GCOLDSTARTATTEMPTS	            ((uint8)17U)
#define   FR_CIDX_GCYCLECOUNTMAX	                ((uint8)18U)
#define   FR_CIDX_GLISTENNOISE	                  ((uint8)19U)
#define   FR_CIDX_GMAXWITHOUTCLOCKCORRECTFATAL 	  ((uint8)20U)
#define   FR_CIDX_GMAXWITHOUTCLOCKCORRECTPASSIVE	((uint8)21U)
#define   FR_CIDX_GNETWORKMANAGEMENTVECTORLENGTH	((uint8)22U)
#define   FR_CIDX_GPAYLOADLENGTHSTATIC	          ((uint8)23U)
#define   FR_CIDX_GSYNCFRAMEIDCOUNTMAX	          ((uint8)24U)
#define   FR_CIDX_GDACTIONPOINTOFFSET	            ((uint8)25U)
#define   FR_CIDX_GDBIT	                          ((uint8)26U)
#define   FR_CIDX_GDCASRXLOWMAX	                  ((uint8)27U)
#define   FR_CIDX_GDDYNAMICSLOTIDLEPHASE	        ((uint8)28U)
#define   FR_CIDX_GDMINISLOTACTIONPOINTOFFSET	    ((uint8)29U)
#define   FR_CIDX_GDMINISLOT	                    ((uint8)30U)
#define   FR_CIDX_GDSAMPLECLOCKPERIOD	            ((uint8)31U)
#define   FR_CIDX_GDSYMBOLWINDOW	                ((uint8)32U)
#define   FR_CIDX_GDSYMBOLWINDOWACTIONPOINTOFFSET	((uint8)33U)
#define   FR_CIDX_GDTSSTRANSMITTER	              ((uint8)34U)
#define   FR_CIDX_GDWAKEUPRXIDLE	                ((uint8)35U)
#define   FR_CIDX_GDWAKEUPRXLOW	                  ((uint8)36U)
#define   FR_CIDX_GDWAKEUPTXACTIVE	              ((uint8)37U)
#define   FR_CIDX_GDWAKEUPTXIDLE	                ((uint8)38U)
#define   FR_CIDX_PALLOWPASSIVETOACTIVE	          ((uint8)39U)
#define   FR_CIDX_PCHANNELS 	                    ((uint8)40U)
#define   FR_CIDX_PCLUSTERDRIFTDAMPING	          ((uint8)41U)
#define   FR_CIDX_PDECODINGCORRECTION	            ((uint8)42U)
#define   FR_CIDX_PDELAYCOMPENSATIONA	            ((uint8)43U)
#define   FR_CIDX_PDELAYCOMPENSATIONB	            ((uint8)44U)
#define   FR_CIDX_PMACROINITIALOFFSETA	          ((uint8)45U)
#define   FR_CIDX_PMACROINITIALOFFSETB	          ((uint8)46U)
#define   FR_CIDX_PMICROINITIALOFFSETA	          ((uint8)47U)
#define   FR_CIDX_PMICROINITIALOFFSETB	          ((uint8)48U)
#define   FR_CIDX_PPAYLOADLENGTHDYNMAX	          ((uint8)49U)
#define   FR_CIDX_PSAMPLESPERMICROTICK 	          ((uint8)50U)
#define   FR_CIDX_PWAKEUPCHANNEL	                ((uint8)51U)
#define   FR_CIDX_PWAKEUPPATTERN	                ((uint8)52U)
#define   FR_CIDX_PDMICROTICK	                    ((uint8)53U)
#define   FR_CIDX_GDIGNOREAFTERTX	                ((uint8)54U)
#define   FR_CIDX_PALLOWHALTDUETOCLOCK 	          ((uint8)55U)
#define   FR_CIDX_PEXTERNALSYNC	                  ((uint8)56U)
#define   FR_CIDX_PFALLBACKINTERNAL	              ((uint8)57U)
#define   FR_CIDX_PKEYSLOTONLYENABLED	            ((uint8)58U)
#define   FR_CIDX_PKEYSLOTUSEDFORSTARTUP	        ((uint8)59U)
#define   FR_CIDX_PKEYSLOTUSEDFORSYNC	            ((uint8)60U)
#define   FR_CIDX_PNMVECTOREARLYUPDATE	          ((uint8)61U)
#define   FR_CIDX_PTWOKEYSLOTMODE       	        ((uint8)62U)

#endif /* FR_GENERAL_TYPES */


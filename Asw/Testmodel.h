/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Testmodel.h
 *
 * Code generated for Simulink model 'Testmodel'.
 *
 * Model version                  : 1.660
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Tue Apr  6 12:28:01 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Testmodel_h_
#define RTW_HEADER_Testmodel_h_
#include <math.h>
#ifndef Testmodel_COMMON_INCLUDES_
# define Testmodel_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Testmodel_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Merge;                        /* '<S300>/Merge' */
  real_T Merge3;                       /* '<S300>/Merge3' */
  real_T Merge_j;                      /* '<S225>/Merge' */
  real_T Merge3_j;                     /* '<S225>/Merge3' */
  real_T Merge_e;                      /* '<S150>/Merge' */
  real_T Merge3_m;                     /* '<S150>/Merge3' */
  real_T Merge_d;                      /* '<S75>/Merge' */
  real_T Merge3_j4;                    /* '<S75>/Merge3' */
  real_T Add2;                         /* '<S253>/Add2' */
  real_T Add2_l;                       /* '<S178>/Add2' */
  real_T Add2_k;                       /* '<S103>/Add2' */
  real_T Add2_h;                       /* '<S28>/Add2' */
  real_T MinMax1;                      /* '<S319>/MinMax1' */
  real_T MinMax1_b;                    /* '<S244>/MinMax1' */
  real_T MinMax1_c;                    /* '<S169>/MinMax1' */
  real_T MinMax1_g;                    /* '<S94>/MinMax1' */
  real_T UnitDelay_DSTATE;             /* '<S253>/Unit Delay' */
  real_T Delay_DSTATE;                 /* '<S320>/Delay' */
  real_T Delay1_DSTATE;                /* '<S320>/Delay1' */
  real_T UnitDelay_DSTATE_l;           /* '<S178>/Unit Delay' */
  real_T Delay_DSTATE_m;               /* '<S245>/Delay' */
  real_T Delay1_DSTATE_b;              /* '<S245>/Delay1' */
  real_T UnitDelay_DSTATE_b;           /* '<S103>/Unit Delay' */
  real_T Delay_DSTATE_f;               /* '<S170>/Delay' */
  real_T Delay1_DSTATE_m;              /* '<S170>/Delay1' */
  real_T UnitDelay_DSTATE_o;           /* '<S28>/Unit Delay' */
  real_T Delay_DSTATE_b;               /* '<S95>/Delay' */
  real_T Delay1_DSTATE_p;              /* '<S95>/Delay1' */
  real32_T Delay[3];                   /* '<S270>/Delay' */
  real32_T Delay1[9];                  /* '<S270>/Delay1' */
  real32_T Merge1_n[3];                /* '<S270>/Merge1' */
  real32_T Merge_l[9];                 /* '<S270>/Merge' */
  real32_T VectorConcatenate[3];       /* '<S275>/Vector Concatenate' */
  real32_T VectorConcatenate_l[3];     /* '<S274>/Vector Concatenate' */
  real32_T Product[3];                 /* '<S278>/Product' */
  real32_T VectorConcatenate_le[3];    /* '<S280>/Vector Concatenate' */
  real32_T Delay_n[3];                 /* '<S195>/Delay' */
  real32_T Delay1_e[9];                /* '<S195>/Delay1' */
  real32_T Merge1_i[3];                /* '<S195>/Merge1' */
  real32_T Merge_b[9];                 /* '<S195>/Merge' */
  real32_T VectorConcatenate_o[3];     /* '<S200>/Vector Concatenate' */
  real32_T VectorConcatenate_m[3];     /* '<S199>/Vector Concatenate' */
  real32_T Product_m[3];               /* '<S203>/Product' */
  real32_T VectorConcatenate_p[3];     /* '<S205>/Vector Concatenate' */
  real32_T Delay_o[3];                 /* '<S120>/Delay' */
  real32_T Delay1_i[9];                /* '<S120>/Delay1' */
  real32_T Merge1_b[3];                /* '<S120>/Merge1' */
  real32_T Merge_i[9];                 /* '<S120>/Merge' */
  real32_T VectorConcatenate_a[3];     /* '<S125>/Vector Concatenate' */
  real32_T VectorConcatenate_b[3];     /* '<S124>/Vector Concatenate' */
  real32_T Product_l[3];               /* '<S128>/Product' */
  real32_T VectorConcatenate_mm[3];    /* '<S130>/Vector Concatenate' */
  real32_T Delay_g[3];                 /* '<S45>/Delay' */
  real32_T Delay1_b[9];                /* '<S45>/Delay1' */
  real32_T Merge1_m[3];                /* '<S45>/Merge1' */
  real32_T Merge_hf[9];                /* '<S45>/Merge' */
  real32_T VectorConcatenate_d[3];     /* '<S50>/Vector Concatenate' */
  real32_T VectorConcatenate_om[3];    /* '<S49>/Vector Concatenate' */
  real32_T Product_c[3];               /* '<S53>/Product' */
  real32_T VectorConcatenate_g[3];     /* '<S55>/Vector Concatenate' */
  real32_T Delay_DSTATE_l[3];          /* '<S270>/Delay' */
  real32_T Delay1_DSTATE_e[9];         /* '<S270>/Delay1' */
  real32_T Delay_DSTATE_oc[3];         /* '<S195>/Delay' */
  real32_T Delay1_DSTATE_j[9];         /* '<S195>/Delay1' */
  real32_T Delay_DSTATE_oq[3];         /* '<S120>/Delay' */
  real32_T Delay1_DSTATE_i[9];         /* '<S120>/Delay1' */
  real32_T Delay_DSTATE_dc[3];         /* '<S45>/Delay' */
  real32_T Delay1_DSTATE_bm[9];        /* '<S45>/Delay1' */
  real32_T Merge_h;                    /* '<S252>/Merge' */
  real32_T ui16_Channels_TonU;         /* '<S251>/TonUVWCalc_UdUq' */
  real32_T ui16_Channels_TonV;         /* '<S251>/TonUVWCalc_UdUq' */
  real32_T ui16_Channels_TonW;         /* '<S251>/TonUVWCalc_UdUq' */
  real32_T DataTypeConversion;         /* '<S300>/Data Type Conversion' */
  real32_T DataTypeConversion1;        /* '<S300>/Data Type Conversion1' */
  real32_T Merge1;                     /* '<S305>/Merge1' */
  real32_T Merge2;                     /* '<S305>/Merge2' */
  real32_T Merge2_m;                   /* '<S270>/Merge2' */
  real32_T Merge_c;                    /* '<S295>/Merge' */
  real32_T Add1;                       /* '<S278>/Add1' */
  real32_T Merge_k;                    /* '<S279>/Merge' */
  real32_T Merge_n;                    /* '<S177>/Merge' */
  real32_T ui16_Channels_TonU_g;       /* '<S176>/TonUVWCalc_UdUq' */
  real32_T ui16_Channels_TonV_p;       /* '<S176>/TonUVWCalc_UdUq' */
  real32_T ui16_Channels_TonW_f;       /* '<S176>/TonUVWCalc_UdUq' */
  real32_T DataTypeConversion_l;       /* '<S225>/Data Type Conversion' */
  real32_T DataTypeConversion1_c;      /* '<S225>/Data Type Conversion1' */
  real32_T Merge1_d;                   /* '<S230>/Merge1' */
  real32_T Merge2_o;                   /* '<S230>/Merge2' */
  real32_T Merge2_mr;                  /* '<S195>/Merge2' */
  real32_T Merge_cy;                   /* '<S220>/Merge' */
  real32_T Add1_n;                     /* '<S203>/Add1' */
  real32_T Merge_eo;                   /* '<S204>/Merge' */
  real32_T Merge_o;                    /* '<S102>/Merge' */
  real32_T ui16_Channels_TonU_j;       /* '<S101>/TonUVWCalc_UdUq' */
  real32_T ui16_Channels_TonV_m;       /* '<S101>/TonUVWCalc_UdUq' */
  real32_T ui16_Channels_TonW_j;       /* '<S101>/TonUVWCalc_UdUq' */
  real32_T DataTypeConversion_o;       /* '<S150>/Data Type Conversion' */
  real32_T DataTypeConversion1_m;      /* '<S150>/Data Type Conversion1' */
  real32_T Merge1_nd;                  /* '<S155>/Merge1' */
  real32_T Merge2_i;                   /* '<S155>/Merge2' */
  real32_T Merge2_a;                   /* '<S120>/Merge2' */
  real32_T Merge_cm;                   /* '<S145>/Merge' */
  real32_T Add1_k;                     /* '<S128>/Add1' */
  real32_T Merge_om;                   /* '<S129>/Merge' */
  real32_T Merge_nw;                   /* '<S27>/Merge' */
  real32_T ui16_Channels_TonU_f;       /* '<S26>/TonUVWCalc_UdUq' */
  real32_T ui16_Channels_TonV_ma;      /* '<S26>/TonUVWCalc_UdUq' */
  real32_T ui16_Channels_TonW_l;       /* '<S26>/TonUVWCalc_UdUq' */
  real32_T DataTypeConversion_c;       /* '<S75>/Data Type Conversion' */
  real32_T DataTypeConversion1_j;      /* '<S75>/Data Type Conversion1' */
  real32_T Merge1_c;                   /* '<S80>/Merge1' */
  real32_T Merge2_c;                   /* '<S80>/Merge2' */
  real32_T Merge2_n;                   /* '<S45>/Merge2' */
  real32_T Merge_kf;                   /* '<S70>/Merge' */
  real32_T Add1_c;                     /* '<S53>/Add1' */
  real32_T Merge_m;                    /* '<S54>/Merge' */
  real32_T Divide;                     /* '<S301>/Divide' */
  real32_T Divide1;                    /* '<S301>/Divide1' */
  real32_T Add;                        /* '<S29>/Add' */
  real32_T Add_j;                      /* '<S254>/Add' */
  real32_T Divide2;                    /* '<S301>/Divide2' */
  real32_T Add_f;                      /* '<S104>/Add' */
  real32_T Add_p;                      /* '<S260>/Add' */
  real32_T Add_d;                      /* '<S259>/Add' */
  real32_T Add_n;                      /* '<S179>/Add' */
  real32_T Gain16;                     /* '<S255>/Gain16' */
  real32_T UnitDelay1_DSTATE;          /* '<Root>/Unit Delay1' */
  real32_T UnitDelay7_DSTATE;          /* '<Root>/Unit Delay7' */
  real32_T UnitDelay3_DSTATE;          /* '<Root>/Unit Delay3' */
  real32_T UnitDelay5_DSTATE;          /* '<Root>/Unit Delay5' */
  real32_T Delay_DSTATE_j;             /* '<S9>/Delay' */
  real32_T Delay_DSTATE_o;             /* '<S8>/Delay' */
  real32_T Delay_DSTATE_e;             /* '<S7>/Delay' */
  real32_T Delay_DSTATE_mc;            /* '<S6>/Delay' */
  real32_T Delay2_DSTATE;              /* '<S270>/Delay2' */
  real32_T UnitDelay_DSTATE_i;         /* '<S264>/Unit Delay' */
  real32_T Delay_DSTATE_fy;            /* '<S266>/Delay' */
  real32_T Delay1_DSTATE_p4;           /* '<S266>/Delay1' */
  real32_T UnitDelay_DSTATE_p;         /* '<S261>/Unit Delay' */
  real32_T Delay_DSTATE_li;            /* '<S263>/Delay' */
  real32_T Delay1_DSTATE_n;            /* '<S263>/Delay1' */
  real32_T Delay2_DSTATE_n;            /* '<S195>/Delay2' */
  real32_T UnitDelay_DSTATE_g;         /* '<S189>/Unit Delay' */
  real32_T Delay_DSTATE_bg;            /* '<S191>/Delay' */
  real32_T Delay1_DSTATE_jt;           /* '<S191>/Delay1' */
  real32_T UnitDelay_DSTATE_e;         /* '<S186>/Unit Delay' */
  real32_T Delay_DSTATE_lq;            /* '<S188>/Delay' */
  real32_T Delay1_DSTATE_o;            /* '<S188>/Delay1' */
  real32_T Delay2_DSTATE_p;            /* '<S120>/Delay2' */
  real32_T UnitDelay_DSTATE_on;        /* '<S114>/Unit Delay' */
  real32_T Delay_DSTATE_lh;            /* '<S116>/Delay' */
  real32_T Delay1_DSTATE_g;            /* '<S116>/Delay1' */
  real32_T UnitDelay_DSTATE_d;         /* '<S111>/Unit Delay' */
  real32_T Delay_DSTATE_k;             /* '<S113>/Delay' */
  real32_T Delay1_DSTATE_f;            /* '<S113>/Delay1' */
  real32_T Delay2_DSTATE_k;            /* '<S45>/Delay2' */
  real32_T UnitDelay_DSTATE_j;         /* '<S39>/Unit Delay' */
  real32_T Delay_DSTATE_bz;            /* '<S41>/Delay' */
  real32_T Delay1_DSTATE_k;            /* '<S41>/Delay1' */
  real32_T UnitDelay_DSTATE_e1;        /* '<S36>/Unit Delay' */
  real32_T Delay_DSTATE_bf;            /* '<S38>/Delay' */
  real32_T Delay1_DSTATE_h;            /* '<S38>/Delay1' */
  real32_T Product4_DWORK4;            /* '<S278>/Product4' */
  real32_T Product4_DWORK4_l;          /* '<S203>/Product4' */
  real32_T Product4_DWORK4_i;          /* '<S128>/Product4' */
  real32_T Product4_DWORK4_d;          /* '<S53>/Product4' */
  int16_T f32_Motor_Angle_M4_Value;    /* '<S5>/f32_Motor_Angle_M4_Value' */
  int16_T Merge3_mi;                   /* '<S270>/Merge3' */
  int16_T f32_Motor_Angle_M3_Value;    /* '<S4>/f32_Motor_Angle_M3_Value' */
  int16_T Merge3_f;                    /* '<S195>/Merge3' */
  int16_T f32_Motor_Angle_M2_Value;    /* '<S3>/f32_Motor_Angle_M2_Value' */
  int16_T Merge3_a;                    /* '<S120>/Merge3' */
  int16_T f32_Motor_Angle_M1_Value;    /* '<S2>/f32_Motor_Angle_M1_Value' */
  int16_T Merge3_i;                    /* '<S45>/Merge3' */
  int16_T f32_Hall_EAngle_Value;       /* '<S269>/f32_Hall_EAngle_Value' */
  int16_T Add_l;                       /* '<S269>/Add' */
  int16_T Delay3_DSTATE;               /* '<S270>/Delay3' */
  int16_T Delay_DSTATE_jp;             /* '<S269>/Delay' */
  int16_T Delay3_DSTATE_b;             /* '<S195>/Delay3' */
  int16_T Delay_DSTATE_o0;             /* '<S194>/Delay' */
  int16_T Delay3_DSTATE_e;             /* '<S120>/Delay3' */
  int16_T Delay_DSTATE_dw;             /* '<S119>/Delay' */
  int16_T Delay3_DSTATE_f;             /* '<S45>/Delay3' */
  int16_T Delay_DSTATE_c;              /* '<S44>/Delay' */
  uint16_T UnitDelay4;                 /* '<Root>/Unit Delay4' */
  uint16_T Rem;                        /* '<S247>/Rem' */
  uint16_T UnitDelay_DSTATE_n;         /* '<Root>/Unit Delay' */
  uint16_T UnitDelay6_DSTATE;          /* '<Root>/Unit Delay6' */
  uint16_T UnitDelay2_DSTATE;          /* '<Root>/Unit Delay2' */
  uint16_T UnitDelay4_DSTATE;          /* '<Root>/Unit Delay4' */
  uint16_T Delay2_DSTATE_c;            /* '<S247>/Delay2' */
  uint16_T Delay2_DSTATE_d;            /* '<S172>/Delay2' */
  uint16_T Delay2_DSTATE_i;            /* '<S97>/Delay2' */
  uint16_T Delay2_DSTATE_e;            /* '<S22>/Delay2' */
  uint8_T Merge_oo;                    /* '<S299>/Merge' */
  uint8_T Merge_lx;                    /* '<S224>/Merge' */
  uint8_T Merge_p;                     /* '<S149>/Merge' */
  uint8_T Merge_kd;                    /* '<S74>/Merge' */
  uint8_T icLoad;                      /* '<S270>/Delay' */
  uint8_T icLoad_j;                    /* '<S270>/Delay1' */
  uint8_T icLoad_o;                    /* '<S269>/Delay' */
  uint8_T icLoad_l;                    /* '<S195>/Delay' */
  uint8_T icLoad_e;                    /* '<S195>/Delay1' */
  uint8_T icLoad_ew;                   /* '<S194>/Delay' */
  uint8_T icLoad_h;                    /* '<S120>/Delay' */
  uint8_T icLoad_f;                    /* '<S120>/Delay1' */
  uint8_T icLoad_l5;                   /* '<S119>/Delay' */
  uint8_T icLoad_m;                    /* '<S45>/Delay' */
  uint8_T icLoad_i;                    /* '<S45>/Delay1' */
  uint8_T icLoad_ju;                   /* '<S44>/Delay' */
  boolean_T SpdModeReq;                /* '<Root>/Chart' */
} DW;

/* Invariant block signals for system '<S45>/KFP' */
typedef struct {
  const real32_T Transpose5[9];        /* '<S47>/Transpose5' */
} ConstB_KFP;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Transpose[9];         /* '<S278>/Transpose' */
  const real32_T Transpose5[3];        /* '<S278>/Transpose5' */
  const real32_T Transpose_m[9];       /* '<S203>/Transpose' */
  const real32_T Transpose5_b[3];      /* '<S203>/Transpose5' */
  const real32_T Transpose_g[9];       /* '<S128>/Transpose' */
  const real32_T Transpose5_o[3];      /* '<S128>/Transpose5' */
  const real32_T Transpose_f[9];       /* '<S53>/Transpose' */
  const real32_T Transpose5_d[3];      /* '<S53>/Transpose5' */
  ConstB_KFP KFP_k;                    /* '<S270>/KFP' */
  ConstB_KFP KFP_el;                   /* '<S195>/KFP' */
  ConstB_KFP KFP_e;                    /* '<S120>/KFP' */
  ConstB_KFP KFP_c;                    /* '<S45>/KFP' */
} ConstB;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: [1 0 0;0 1 0;0 0 1])
   * Referenced by:
   *   '<S53>/I'
   *   '<S128>/I'
   *   '<S203>/I'
   *   '<S278>/I'
   */
  real32_T pooled12[9];

  /* Pooled Parameter (Expression: [1 0 0])
   * Referenced by:
   *   '<S53>/H'
   *   '<S128>/H'
   *   '<S203>/H'
   *   '<S278>/H'
   */
  real32_T pooled13[3];

  /* Pooled Parameter (Expression: [1e3 0 0;0 1e6 0;
     0 0 1e8])
   * Referenced by:
   *   '<S51>/P0'
   *   '<S126>/P0'
   *   '<S201>/P0'
   *   '<S276>/P0'
   */
  real32_T pooled15[9];

  /* Pooled Parameter (Expression: [1 1e-4 1e-4*1e-4/2;0 1 1e-4;0 0 1])
   * Referenced by:
   *   '<S45>/Constant1'
   *   '<S120>/Constant1'
   *   '<S195>/Constant1'
   *   '<S270>/Constant1'
   */
  real32_T pooled16[9];

  /* Pooled Parameter (Expression: [1e3 0 0;0 1e6 0;0 0 1e6])
   * Referenced by:
   *   '<S45>/P0'
   *   '<S120>/P0'
   *   '<S195>/P0'
   *   '<S270>/P0'
   */
  real32_T pooled17[9];

  /* Pooled Parameter (Expression: [0 0 0;
     0 1e4 0;
     0 0 1e4])
   * Referenced by:
   *   '<S45>/Q0'
   *   '<S120>/Q0'
   *   '<S195>/Q0'
   *   '<S270>/Q0'
   */
  real32_T pooled18[9];

  /* Pooled Parameter (Expression: [270 150 210 30 330 90])
   * Referenced by:
   *   '<S2>/f32_Motor_Angle_M1_Value'
   *   '<S3>/f32_Motor_Angle_M2_Value'
   *   '<S4>/f32_Motor_Angle_M3_Value'
   *   '<S5>/f32_Motor_Angle_M4_Value'
   */
  int16_T pooled31[6];

  /* Pooled Parameter (Expression: [1 2 3 4 5 6])
   * Referenced by:
   *   '<S2>/f32_Motor_Angle_M1_Value'
   *   '<S3>/f32_Motor_Angle_M2_Value'
   *   '<S4>/f32_Motor_Angle_M3_Value'
   *   '<S5>/f32_Motor_Angle_M4_Value'
   */
  uint8_T pooled42[6];
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T f32_speed_filtered_value;   /* '<Root>/f32_speed_filtered_value' */
  real32_T f32_EAngle_Motor;           /* '<Root>/f32_EAngle_Motor' */
  real_T VfPC_S_DebugUdCmd_V;          /* '<Root>/VfPC_S_DebugUdCmd_V' */
} ExtU;

/* Type definition for custom storage class: Struct */
typedef struct Struct_Motor_tag {
  real_T f32_Kc_speed;
  real_T f32_Ki_speed;
  real_T f32_Kp_Speed;
  real32_T TPre;
  real32_T f32_Cutoff_Frequency;
  real32_T f32_Flux;
  real32_T f32_Inductance_value_d;
  real32_T f32_Inductance_value_q;
  real32_T f32_Kc_d;
  real32_T f32_Kc_q;
  real32_T f32_Ki_d;
  real32_T f32_Ki_q;
  real32_T f32_Kp_d;
  real32_T f32_Kp_q;
  real32_T f32_PWM_frequency;
  real32_T f32_Pole_Pair;
  real32_T outmax_Ton;
  real32_T outmax_Tor;
  real32_T outmax_d;
  real32_T outmax_q;
  real32_T outmin_Ton;
  real32_T outmin_Tor;
  real32_T outmin_d;
  real32_T outmin_q;
} Struct_Motor_type;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;
extern const ConstB rtConstB;          /* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern uint8_T VePC_S_SubDebugMode_NULL;/* '<Root>/In1' */
extern real32_T Phase_Cur_A_M1_Value;  /* '<Root>/Phase_Cur_A_M1_Value' */
extern real32_T Phase_Cur_B_M1_Value;  /* '<Root>/Phase_Cur_B_M1_Value' */
extern real32_T Phase_Cur_C_M1_Value;  /* '<Root>/Phase_Cur_C_M1_Value' */
extern real32_T VfPC_S_DebugFreqCmd_M1;/* '<Root>/VfPC_S_DebugFreqCmd_M1' */
extern real32_T DC_link_Vol;           /* '<Root>/DC_link_Vol' */
extern uint8_T Appl_HalStatus_M1_u8;   /* '<Root>/Appl_HalStatus_M1_u8' */
extern real32_T Phase_Cur_A_M2_Value;  /* '<Root>/Phase_Cur_A_M2_Value' */
extern real32_T Phase_Cur_B_M2_Value;  /* '<Root>/Phase_Cur_B_M2_Value' */
extern real32_T Phase_Cur_C_M2_Value;  /* '<Root>/Phase_Cur_C_M2_Value' */
extern real32_T VfPC_S_DebugFreqCmd_M2;/* '<Root>/VfPC_S_DebugFreqCmd_M2' */
extern uint8_T Appl_HalStatus_M2_u8;   /* '<Root>/Appl_HalStatus_M2_u8' */
extern real32_T Phase_Cur_A_M3_Value;  /* '<Root>/Phase_Cur_A_M3_Value' */
extern real32_T Phase_Cur_B_M3_Value;  /* '<Root>/Phase_Cur_B_M3_Value' */
extern real32_T Phase_Cur_C_M3_Value;  /* '<Root>/Phase_Cur_C_M3_Value' */
extern real32_T VfPC_S_DebugFreqCmd_M3;/* '<Root>/VfPC_S_DebugFreqCmd_M3' */
extern uint8_T Appl_HalStatus_M3_u8;   /* '<Root>/Appl_HalStatus_M3_u8' */
extern real32_T Phase_Cur_A_M4_Value;  /* '<Root>/Phase_Cur_A_M4_Value' */
extern real32_T Phase_Cur_B_M4_Value;  /* '<Root>/Phase_Cur_B_M4_Value' */
extern real32_T Phase_Cur_C_M4_Value;  /* '<Root>/Phase_Cur_C_M4_Value' */
extern real32_T VfPC_S_DebugFreqCmd_M4;/* '<Root>/VfPC_S_DebugFreqCmd_M4' */
extern uint8_T Appl_HalStatus_M4_u8;   /* '<Root>/Appl_HalStatus_M4_u8' */
extern real32_T f32_M4_Ton_fault_C;    /* '<S21>/MinMax1' */
extern real32_T f32_M3_Ton_fault_C;    /* '<S20>/MinMax1' */
extern real32_T f32_M2_Ton_fault_C;    /* '<S19>/MinMax1' */
extern real32_T f32_M1_Ton_fault_C;    /* '<S18>/MinMax1' */
extern real32_T f32_M4_Ton_fault_B;    /* '<S17>/MinMax1' */
extern real32_T f32_M3_Ton_fault_B;    /* '<S16>/MinMax1' */
extern real32_T f32_M2_Ton_fault_B;    /* '<S15>/MinMax1' */
extern real32_T f32_M1_Ton_fault_B;    /* '<S14>/MinMax1' */
extern real32_T f32_M4_Ton_fault_A;    /* '<S13>/MinMax1' */
extern real32_T f32_M3_Ton_fault_A;    /* '<S12>/MinMax1' */
extern real32_T f32_M2_Ton_fault_A;    /* '<S11>/MinMax1' */
extern real32_T f32_M1_Ton_fault_A;    /* '<S10>/MinMax1' */
extern real32_T f32_ESpeed_M4_KalmanValue;/* '<S250>/Product' */
extern real32_T f32_ESpeed_M3_KalmanValue;/* '<S175>/Product' */
extern real32_T f32_ESpeed_M2_KalmanValue;/* '<S100>/Product' */
extern real32_T f32_ESpeed_M1_KalmanValue;/* '<S25>/Product' */
extern uint16_T f32_EAngle_M4_KalmanValue;/* '<S250>/Data Type Conversion' */
extern uint16_T f32_EAngle_M3_KalmanValue;/* '<S175>/Data Type Conversion' */
extern uint16_T f32_EAngle_M2_KalmanValue;/* '<S100>/Data Type Conversion' */
extern uint16_T f32_EAngle_M1_KalmanValue;/* '<S25>/Data Type Conversion' */

/* Model entry point functions */
extern void Testmodel_initialize(void);
extern void Testmodel_step(void);

/* Exported data declaration */

/* Declaration for custom storage class: Struct */
extern Struct_Motor_type Struct_Motor;

/* Const memory section */
/* Declaration for custom storage class: Const */
extern const real32_T f32_CosineTable[4096];
extern const real32_T f32_SineTable[4096];

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S34>/Constant' : Unused code path elimination
 * Block '<S34>/Constant1' : Unused code path elimination
 * Block '<S34>/Product1' : Unused code path elimination
 * Block '<S34>/Product2' : Unused code path elimination
 * Block '<S35>/Add1' : Unused code path elimination
 * Block '<S35>/Constant' : Unused code path elimination
 * Block '<S35>/Constant1' : Unused code path elimination
 * Block '<S35>/Flux' : Unused code path elimination
 * Block '<S35>/Product' : Unused code path elimination
 * Block '<S35>/Product1' : Unused code path elimination
 * Block '<S35>/Product2' : Unused code path elimination
 * Block '<S35>/Product3' : Unused code path elimination
 * Block '<S109>/Constant' : Unused code path elimination
 * Block '<S109>/Constant1' : Unused code path elimination
 * Block '<S109>/Product1' : Unused code path elimination
 * Block '<S109>/Product2' : Unused code path elimination
 * Block '<S110>/Add1' : Unused code path elimination
 * Block '<S110>/Constant' : Unused code path elimination
 * Block '<S110>/Constant1' : Unused code path elimination
 * Block '<S110>/Flux' : Unused code path elimination
 * Block '<S110>/Product' : Unused code path elimination
 * Block '<S110>/Product1' : Unused code path elimination
 * Block '<S110>/Product2' : Unused code path elimination
 * Block '<S110>/Product3' : Unused code path elimination
 * Block '<S184>/Constant' : Unused code path elimination
 * Block '<S184>/Constant1' : Unused code path elimination
 * Block '<S184>/Product1' : Unused code path elimination
 * Block '<S184>/Product2' : Unused code path elimination
 * Block '<S185>/Add1' : Unused code path elimination
 * Block '<S185>/Constant' : Unused code path elimination
 * Block '<S185>/Constant1' : Unused code path elimination
 * Block '<S185>/Flux' : Unused code path elimination
 * Block '<S185>/Product' : Unused code path elimination
 * Block '<S185>/Product1' : Unused code path elimination
 * Block '<S185>/Product2' : Unused code path elimination
 * Block '<S185>/Product3' : Unused code path elimination
 * Block '<S259>/Constant' : Unused code path elimination
 * Block '<S259>/Constant1' : Unused code path elimination
 * Block '<S259>/Product1' : Unused code path elimination
 * Block '<S259>/Product2' : Unused code path elimination
 * Block '<S260>/Add1' : Unused code path elimination
 * Block '<S260>/Constant' : Unused code path elimination
 * Block '<S260>/Constant1' : Unused code path elimination
 * Block '<S260>/Flux' : Unused code path elimination
 * Block '<S260>/Product' : Unused code path elimination
 * Block '<S260>/Product1' : Unused code path elimination
 * Block '<S260>/Product2' : Unused code path elimination
 * Block '<S260>/Product3' : Unused code path elimination
 * Block '<S30>/Gain' : Eliminated nontunable gain of 1
 * Block '<S105>/Gain' : Eliminated nontunable gain of 1
 * Block '<S180>/Gain' : Eliminated nontunable gain of 1
 * Block '<S255>/Gain' : Eliminated nontunable gain of 1
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Testmodel'
 * '<S1>'   : 'Testmodel/Chart'
 * '<S2>'   : 'Testmodel/FocControl_M1'
 * '<S3>'   : 'Testmodel/FocControl_M2'
 * '<S4>'   : 'Testmodel/FocControl_M3'
 * '<S5>'   : 'Testmodel/FocControl_M4'
 * '<S6>'   : 'Testmodel/LowPassF_M1'
 * '<S7>'   : 'Testmodel/LowPassF_M2'
 * '<S8>'   : 'Testmodel/LowPassF_M3'
 * '<S9>'   : 'Testmodel/LowPassF_M4'
 * '<S10>'  : 'Testmodel/Ton_Saturation_A_M1'
 * '<S11>'  : 'Testmodel/Ton_Saturation_A_M2'
 * '<S12>'  : 'Testmodel/Ton_Saturation_A_M3'
 * '<S13>'  : 'Testmodel/Ton_Saturation_A_M4'
 * '<S14>'  : 'Testmodel/Ton_Saturation_B_M1'
 * '<S15>'  : 'Testmodel/Ton_Saturation_B_M2'
 * '<S16>'  : 'Testmodel/Ton_Saturation_B_M3'
 * '<S17>'  : 'Testmodel/Ton_Saturation_B_M4'
 * '<S18>'  : 'Testmodel/Ton_Saturation_C_M1'
 * '<S19>'  : 'Testmodel/Ton_Saturation_C_M2'
 * '<S20>'  : 'Testmodel/Ton_Saturation_C_M3'
 * '<S21>'  : 'Testmodel/Ton_Saturation_C_M4'
 * '<S22>'  : 'Testmodel/FocControl_M1/Counter_M1'
 * '<S23>'  : 'Testmodel/FocControl_M1/Cur_alphabetaxy_loop_IdIq_M1'
 * '<S24>'  : 'Testmodel/FocControl_M1/IqRefCalc_M1'
 * '<S25>'  : 'Testmodel/FocControl_M1/Kalman_M1'
 * '<S26>'  : 'Testmodel/FocControl_M1/PWM_Generate_UdUq_M1'
 * '<S27>'  : 'Testmodel/FocControl_M1/SpeedToIq_M1'
 * '<S28>'  : 'Testmodel/FocControl_M1/Speed_PI_M1'
 * '<S29>'  : 'Testmodel/FocControl_M1/UdUq_Mode_Cal_M1'
 * '<S30>'  : 'Testmodel/FocControl_M1/Cur_alphabetaxy_loop_IdIq_M1/Clarke_Transformation_Fault_IdIq'
 * '<S31>'  : 'Testmodel/FocControl_M1/Cur_alphabetaxy_loop_IdIq_M1/Cur_Controller_alphabeta_Fault_IdIq'
 * '<S32>'  : 'Testmodel/FocControl_M1/Cur_alphabetaxy_loop_IdIq_M1/EAngle_cos_sin_cal_IdIq'
 * '<S33>'  : 'Testmodel/FocControl_M1/Cur_alphabetaxy_loop_IdIq_M1/Park_Transformation_alphabeta_Fault_IdIq '
 * '<S34>'  : 'Testmodel/FocControl_M1/Cur_alphabetaxy_loop_IdIq_M1/Cur_Controller_alphabeta_Fault_IdIq/Pi_d'
 * '<S35>'  : 'Testmodel/FocControl_M1/Cur_alphabetaxy_loop_IdIq_M1/Cur_Controller_alphabeta_Fault_IdIq/Pi_q'
 * '<S36>'  : 'Testmodel/FocControl_M1/Cur_alphabetaxy_loop_IdIq_M1/Cur_Controller_alphabeta_Fault_IdIq/Pi_d/PI_Controller_d'
 * '<S37>'  : 'Testmodel/FocControl_M1/Cur_alphabetaxy_loop_IdIq_M1/Cur_Controller_alphabeta_Fault_IdIq/Pi_d/PI_Controller_d/Saturation'
 * '<S38>'  : 'Testmodel/FocControl_M1/Cur_alphabetaxy_loop_IdIq_M1/Cur_Controller_alphabeta_Fault_IdIq/Pi_d/PI_Controller_d/integrator'
 * '<S39>'  : 'Testmodel/FocControl_M1/Cur_alphabetaxy_loop_IdIq_M1/Cur_Controller_alphabeta_Fault_IdIq/Pi_q/PI_Controller_q'
 * '<S40>'  : 'Testmodel/FocControl_M1/Cur_alphabetaxy_loop_IdIq_M1/Cur_Controller_alphabeta_Fault_IdIq/Pi_q/PI_Controller_q/Saturation'
 * '<S41>'  : 'Testmodel/FocControl_M1/Cur_alphabetaxy_loop_IdIq_M1/Cur_Controller_alphabeta_Fault_IdIq/Pi_q/PI_Controller_q/integrator'
 * '<S42>'  : 'Testmodel/FocControl_M1/IqRefCalc_M1/IqRefCalc'
 * '<S43>'  : 'Testmodel/FocControl_M1/IqRefCalc_M1/IqSatur'
 * '<S44>'  : 'Testmodel/FocControl_M1/Kalman_M1/JudgeofHallTurn'
 * '<S45>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF'
 * '<S46>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF/If Action Subsystem'
 * '<S47>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF/KFP'
 * '<S48>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF/KFPandU'
 * '<S49>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF/Trim_2'
 * '<S50>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF/X0'
 * '<S51>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF/If Action Subsystem/If Action Subsystem'
 * '<S52>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF/If Action Subsystem/If Action Subsystem1'
 * '<S53>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF/KFPandU/KFU'
 * '<S54>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF/KFPandU/KFU/Judgement'
 * '<S55>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF/KFPandU/KFU/Trim_2'
 * '<S56>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF/KFPandU/KFU/Judgement/If Action Subsystem'
 * '<S57>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF/KFPandU/KFU/Judgement/If Action Subsystem1'
 * '<S58>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF/KFPandU/KFU/Judgement/If Action Subsystem/Trim'
 * '<S59>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF/KFPandU/KFU/Judgement/If Action Subsystem/Trim/If Action Subsystem'
 * '<S60>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF/KFPandU/KFU/Judgement/If Action Subsystem/Trim/If Action Subsystem1'
 * '<S61>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF/KFPandU/KFU/Judgement/If Action Subsystem/Trim/If Action Subsystem2'
 * '<S62>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF/KFPandU/KFU/Judgement/If Action Subsystem1/Trim'
 * '<S63>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF/KFPandU/KFU/Judgement/If Action Subsystem1/Trim/If Action Subsystem'
 * '<S64>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF/KFPandU/KFU/Judgement/If Action Subsystem1/Trim/If Action Subsystem1'
 * '<S65>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF/KFPandU/KFU/Judgement/If Action Subsystem1/Trim/If Action Subsystem2'
 * '<S66>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF/KFPandU/KFU/Trim_2/Trim_1'
 * '<S67>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF/KFPandU/KFU/Trim_2/Trim_1/If Action Subsystem'
 * '<S68>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF/KFPandU/KFU/Trim_2/Trim_1/If Action Subsystem1'
 * '<S69>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF/KFPandU/KFU/Trim_2/Trim_1/If Action Subsystem2'
 * '<S70>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF/Trim_2/Trim_1'
 * '<S71>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF/Trim_2/Trim_1/If Action Subsystem'
 * '<S72>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF/Trim_2/Trim_1/If Action Subsystem1'
 * '<S73>'  : 'Testmodel/FocControl_M1/Kalman_M1/KF/Trim_2/Trim_1/If Action Subsystem2'
 * '<S74>'  : 'Testmodel/FocControl_M1/PWM_Generate_UdUq_M1/PWMFOC_SectorCalc_UdUq'
 * '<S75>'  : 'Testmodel/FocControl_M1/PWM_Generate_UdUq_M1/PWMFOC_T12CoefCalc_UdUq'
 * '<S76>'  : 'Testmodel/FocControl_M1/PWM_Generate_UdUq_M1/PWMFOC_TabcCalc_UdUq'
 * '<S77>'  : 'Testmodel/FocControl_M1/PWM_Generate_UdUq_M1/TonUVWCalc_UdUq'
 * '<S78>'  : 'Testmodel/FocControl_M1/PWM_Generate_UdUq_M1/PWMFOC_SectorCalc_UdUq/If Action Subsystem'
 * '<S79>'  : 'Testmodel/FocControl_M1/PWM_Generate_UdUq_M1/PWMFOC_SectorCalc_UdUq/If Action Subsystem1'
 * '<S80>'  : 'Testmodel/FocControl_M1/PWM_Generate_UdUq_M1/PWMFOC_T12CoefCalc_UdUq/Subsystem'
 * '<S81>'  : 'Testmodel/FocControl_M1/PWM_Generate_UdUq_M1/PWMFOC_T12CoefCalc_UdUq/Switch Case Action Subsystem'
 * '<S82>'  : 'Testmodel/FocControl_M1/PWM_Generate_UdUq_M1/PWMFOC_T12CoefCalc_UdUq/Switch Case Action Subsystem1'
 * '<S83>'  : 'Testmodel/FocControl_M1/PWM_Generate_UdUq_M1/PWMFOC_T12CoefCalc_UdUq/Switch Case Action Subsystem2'
 * '<S84>'  : 'Testmodel/FocControl_M1/PWM_Generate_UdUq_M1/PWMFOC_T12CoefCalc_UdUq/Switch Case Action Subsystem3'
 * '<S85>'  : 'Testmodel/FocControl_M1/PWM_Generate_UdUq_M1/PWMFOC_T12CoefCalc_UdUq/Switch Case Action Subsystem4'
 * '<S86>'  : 'Testmodel/FocControl_M1/PWM_Generate_UdUq_M1/PWMFOC_T12CoefCalc_UdUq/Switch Case Action Subsystem5'
 * '<S87>'  : 'Testmodel/FocControl_M1/PWM_Generate_UdUq_M1/PWMFOC_T12CoefCalc_UdUq/Subsystem/If Action Subsystem'
 * '<S88>'  : 'Testmodel/FocControl_M1/PWM_Generate_UdUq_M1/PWMFOC_T12CoefCalc_UdUq/Subsystem/If Action Subsystem1'
 * '<S89>'  : 'Testmodel/FocControl_M1/PWM_Generate_UdUq_M1/PWMFOC_T12CoefCalc_UdUq/Subsystem/If Action Subsystem/Switch Case Action Subsystem'
 * '<S90>'  : 'Testmodel/FocControl_M1/PWM_Generate_UdUq_M1/PWMFOC_T12CoefCalc_UdUq/Subsystem/If Action Subsystem/Switch Case Action Subsystem1'
 * '<S91>'  : 'Testmodel/FocControl_M1/SpeedToIq_M1/If Action Subsystem'
 * '<S92>'  : 'Testmodel/FocControl_M1/SpeedToIq_M1/If Action Subsystem1'
 * '<S93>'  : 'Testmodel/FocControl_M1/SpeedToIq_M1/If Action Subsystem2'
 * '<S94>'  : 'Testmodel/FocControl_M1/Speed_PI_M1/Saturation'
 * '<S95>'  : 'Testmodel/FocControl_M1/Speed_PI_M1/integrator'
 * '<S96>'  : 'Testmodel/FocControl_M1/UdUq_Mode_Cal_M1/f32_Angle_CosSin_Value'
 * '<S97>'  : 'Testmodel/FocControl_M2/Counter_M2'
 * '<S98>'  : 'Testmodel/FocControl_M2/Cur_alphabetaxy_loop_IdIq_M2'
 * '<S99>'  : 'Testmodel/FocControl_M2/IqRefCalc_M2'
 * '<S100>' : 'Testmodel/FocControl_M2/Kalman_M2'
 * '<S101>' : 'Testmodel/FocControl_M2/PWM_Generate_UdUq_M2'
 * '<S102>' : 'Testmodel/FocControl_M2/SpeedToIq_M2'
 * '<S103>' : 'Testmodel/FocControl_M2/Speed_PI_M2'
 * '<S104>' : 'Testmodel/FocControl_M2/UdUq_Mode_Cal_M2'
 * '<S105>' : 'Testmodel/FocControl_M2/Cur_alphabetaxy_loop_IdIq_M2/Clarke_Transformation_Fault_IdIq'
 * '<S106>' : 'Testmodel/FocControl_M2/Cur_alphabetaxy_loop_IdIq_M2/Cur_Controller_alphabeta_Fault_IdIq'
 * '<S107>' : 'Testmodel/FocControl_M2/Cur_alphabetaxy_loop_IdIq_M2/EAngle_cos_sin_cal_IdIq'
 * '<S108>' : 'Testmodel/FocControl_M2/Cur_alphabetaxy_loop_IdIq_M2/Park_Transformation_alphabeta_Fault_IdIq '
 * '<S109>' : 'Testmodel/FocControl_M2/Cur_alphabetaxy_loop_IdIq_M2/Cur_Controller_alphabeta_Fault_IdIq/Pi_d'
 * '<S110>' : 'Testmodel/FocControl_M2/Cur_alphabetaxy_loop_IdIq_M2/Cur_Controller_alphabeta_Fault_IdIq/Pi_q'
 * '<S111>' : 'Testmodel/FocControl_M2/Cur_alphabetaxy_loop_IdIq_M2/Cur_Controller_alphabeta_Fault_IdIq/Pi_d/PI_Controller_d'
 * '<S112>' : 'Testmodel/FocControl_M2/Cur_alphabetaxy_loop_IdIq_M2/Cur_Controller_alphabeta_Fault_IdIq/Pi_d/PI_Controller_d/Saturation'
 * '<S113>' : 'Testmodel/FocControl_M2/Cur_alphabetaxy_loop_IdIq_M2/Cur_Controller_alphabeta_Fault_IdIq/Pi_d/PI_Controller_d/integrator'
 * '<S114>' : 'Testmodel/FocControl_M2/Cur_alphabetaxy_loop_IdIq_M2/Cur_Controller_alphabeta_Fault_IdIq/Pi_q/PI_Controller_q'
 * '<S115>' : 'Testmodel/FocControl_M2/Cur_alphabetaxy_loop_IdIq_M2/Cur_Controller_alphabeta_Fault_IdIq/Pi_q/PI_Controller_q/Saturation'
 * '<S116>' : 'Testmodel/FocControl_M2/Cur_alphabetaxy_loop_IdIq_M2/Cur_Controller_alphabeta_Fault_IdIq/Pi_q/PI_Controller_q/integrator'
 * '<S117>' : 'Testmodel/FocControl_M2/IqRefCalc_M2/IqRefCalc'
 * '<S118>' : 'Testmodel/FocControl_M2/IqRefCalc_M2/IqSatur'
 * '<S119>' : 'Testmodel/FocControl_M2/Kalman_M2/JudgeofHallTurn'
 * '<S120>' : 'Testmodel/FocControl_M2/Kalman_M2/KF'
 * '<S121>' : 'Testmodel/FocControl_M2/Kalman_M2/KF/If Action Subsystem'
 * '<S122>' : 'Testmodel/FocControl_M2/Kalman_M2/KF/KFP'
 * '<S123>' : 'Testmodel/FocControl_M2/Kalman_M2/KF/KFPandU'
 * '<S124>' : 'Testmodel/FocControl_M2/Kalman_M2/KF/Trim_2'
 * '<S125>' : 'Testmodel/FocControl_M2/Kalman_M2/KF/X0'
 * '<S126>' : 'Testmodel/FocControl_M2/Kalman_M2/KF/If Action Subsystem/If Action Subsystem'
 * '<S127>' : 'Testmodel/FocControl_M2/Kalman_M2/KF/If Action Subsystem/If Action Subsystem1'
 * '<S128>' : 'Testmodel/FocControl_M2/Kalman_M2/KF/KFPandU/KFU'
 * '<S129>' : 'Testmodel/FocControl_M2/Kalman_M2/KF/KFPandU/KFU/Judgement'
 * '<S130>' : 'Testmodel/FocControl_M2/Kalman_M2/KF/KFPandU/KFU/Trim_2'
 * '<S131>' : 'Testmodel/FocControl_M2/Kalman_M2/KF/KFPandU/KFU/Judgement/If Action Subsystem'
 * '<S132>' : 'Testmodel/FocControl_M2/Kalman_M2/KF/KFPandU/KFU/Judgement/If Action Subsystem1'
 * '<S133>' : 'Testmodel/FocControl_M2/Kalman_M2/KF/KFPandU/KFU/Judgement/If Action Subsystem/Trim'
 * '<S134>' : 'Testmodel/FocControl_M2/Kalman_M2/KF/KFPandU/KFU/Judgement/If Action Subsystem/Trim/If Action Subsystem'
 * '<S135>' : 'Testmodel/FocControl_M2/Kalman_M2/KF/KFPandU/KFU/Judgement/If Action Subsystem/Trim/If Action Subsystem1'
 * '<S136>' : 'Testmodel/FocControl_M2/Kalman_M2/KF/KFPandU/KFU/Judgement/If Action Subsystem/Trim/If Action Subsystem2'
 * '<S137>' : 'Testmodel/FocControl_M2/Kalman_M2/KF/KFPandU/KFU/Judgement/If Action Subsystem1/Trim'
 * '<S138>' : 'Testmodel/FocControl_M2/Kalman_M2/KF/KFPandU/KFU/Judgement/If Action Subsystem1/Trim/If Action Subsystem'
 * '<S139>' : 'Testmodel/FocControl_M2/Kalman_M2/KF/KFPandU/KFU/Judgement/If Action Subsystem1/Trim/If Action Subsystem1'
 * '<S140>' : 'Testmodel/FocControl_M2/Kalman_M2/KF/KFPandU/KFU/Judgement/If Action Subsystem1/Trim/If Action Subsystem2'
 * '<S141>' : 'Testmodel/FocControl_M2/Kalman_M2/KF/KFPandU/KFU/Trim_2/Trim_1'
 * '<S142>' : 'Testmodel/FocControl_M2/Kalman_M2/KF/KFPandU/KFU/Trim_2/Trim_1/If Action Subsystem'
 * '<S143>' : 'Testmodel/FocControl_M2/Kalman_M2/KF/KFPandU/KFU/Trim_2/Trim_1/If Action Subsystem1'
 * '<S144>' : 'Testmodel/FocControl_M2/Kalman_M2/KF/KFPandU/KFU/Trim_2/Trim_1/If Action Subsystem2'
 * '<S145>' : 'Testmodel/FocControl_M2/Kalman_M2/KF/Trim_2/Trim_1'
 * '<S146>' : 'Testmodel/FocControl_M2/Kalman_M2/KF/Trim_2/Trim_1/If Action Subsystem'
 * '<S147>' : 'Testmodel/FocControl_M2/Kalman_M2/KF/Trim_2/Trim_1/If Action Subsystem1'
 * '<S148>' : 'Testmodel/FocControl_M2/Kalman_M2/KF/Trim_2/Trim_1/If Action Subsystem2'
 * '<S149>' : 'Testmodel/FocControl_M2/PWM_Generate_UdUq_M2/PWMFOC_SectorCalc_UdUq'
 * '<S150>' : 'Testmodel/FocControl_M2/PWM_Generate_UdUq_M2/PWMFOC_T12CoefCalc_UdUq'
 * '<S151>' : 'Testmodel/FocControl_M2/PWM_Generate_UdUq_M2/PWMFOC_TabcCalc_UdUq'
 * '<S152>' : 'Testmodel/FocControl_M2/PWM_Generate_UdUq_M2/TonUVWCalc_UdUq'
 * '<S153>' : 'Testmodel/FocControl_M2/PWM_Generate_UdUq_M2/PWMFOC_SectorCalc_UdUq/If Action Subsystem'
 * '<S154>' : 'Testmodel/FocControl_M2/PWM_Generate_UdUq_M2/PWMFOC_SectorCalc_UdUq/If Action Subsystem1'
 * '<S155>' : 'Testmodel/FocControl_M2/PWM_Generate_UdUq_M2/PWMFOC_T12CoefCalc_UdUq/Subsystem'
 * '<S156>' : 'Testmodel/FocControl_M2/PWM_Generate_UdUq_M2/PWMFOC_T12CoefCalc_UdUq/Switch Case Action Subsystem'
 * '<S157>' : 'Testmodel/FocControl_M2/PWM_Generate_UdUq_M2/PWMFOC_T12CoefCalc_UdUq/Switch Case Action Subsystem1'
 * '<S158>' : 'Testmodel/FocControl_M2/PWM_Generate_UdUq_M2/PWMFOC_T12CoefCalc_UdUq/Switch Case Action Subsystem2'
 * '<S159>' : 'Testmodel/FocControl_M2/PWM_Generate_UdUq_M2/PWMFOC_T12CoefCalc_UdUq/Switch Case Action Subsystem3'
 * '<S160>' : 'Testmodel/FocControl_M2/PWM_Generate_UdUq_M2/PWMFOC_T12CoefCalc_UdUq/Switch Case Action Subsystem4'
 * '<S161>' : 'Testmodel/FocControl_M2/PWM_Generate_UdUq_M2/PWMFOC_T12CoefCalc_UdUq/Switch Case Action Subsystem5'
 * '<S162>' : 'Testmodel/FocControl_M2/PWM_Generate_UdUq_M2/PWMFOC_T12CoefCalc_UdUq/Subsystem/If Action Subsystem'
 * '<S163>' : 'Testmodel/FocControl_M2/PWM_Generate_UdUq_M2/PWMFOC_T12CoefCalc_UdUq/Subsystem/If Action Subsystem1'
 * '<S164>' : 'Testmodel/FocControl_M2/PWM_Generate_UdUq_M2/PWMFOC_T12CoefCalc_UdUq/Subsystem/If Action Subsystem/Switch Case Action Subsystem'
 * '<S165>' : 'Testmodel/FocControl_M2/PWM_Generate_UdUq_M2/PWMFOC_T12CoefCalc_UdUq/Subsystem/If Action Subsystem/Switch Case Action Subsystem1'
 * '<S166>' : 'Testmodel/FocControl_M2/SpeedToIq_M2/If Action Subsystem'
 * '<S167>' : 'Testmodel/FocControl_M2/SpeedToIq_M2/If Action Subsystem1'
 * '<S168>' : 'Testmodel/FocControl_M2/SpeedToIq_M2/If Action Subsystem2'
 * '<S169>' : 'Testmodel/FocControl_M2/Speed_PI_M2/Saturation'
 * '<S170>' : 'Testmodel/FocControl_M2/Speed_PI_M2/integrator'
 * '<S171>' : 'Testmodel/FocControl_M2/UdUq_Mode_Cal_M2/f32_Angle_SinCos_Value'
 * '<S172>' : 'Testmodel/FocControl_M3/Counter_M3'
 * '<S173>' : 'Testmodel/FocControl_M3/Cur_alphabetaxy_loop_IdIq_M3'
 * '<S174>' : 'Testmodel/FocControl_M3/IqRefCalc_M3'
 * '<S175>' : 'Testmodel/FocControl_M3/Kalman_M3'
 * '<S176>' : 'Testmodel/FocControl_M3/PWM_Generate_UdUq_M3'
 * '<S177>' : 'Testmodel/FocControl_M3/SpeedToIq_M3'
 * '<S178>' : 'Testmodel/FocControl_M3/Speed_PI_M3'
 * '<S179>' : 'Testmodel/FocControl_M3/UdUq_Mode_Cal_M3'
 * '<S180>' : 'Testmodel/FocControl_M3/Cur_alphabetaxy_loop_IdIq_M3/Clarke_Transformation_Fault_IdIq'
 * '<S181>' : 'Testmodel/FocControl_M3/Cur_alphabetaxy_loop_IdIq_M3/Cur_Controller_alphabeta_Fault_IdIq'
 * '<S182>' : 'Testmodel/FocControl_M3/Cur_alphabetaxy_loop_IdIq_M3/EAngle_cos_sin_cal_IdIq'
 * '<S183>' : 'Testmodel/FocControl_M3/Cur_alphabetaxy_loop_IdIq_M3/Park_Transformation_alphabeta_Fault_IdIq '
 * '<S184>' : 'Testmodel/FocControl_M3/Cur_alphabetaxy_loop_IdIq_M3/Cur_Controller_alphabeta_Fault_IdIq/Pi_d'
 * '<S185>' : 'Testmodel/FocControl_M3/Cur_alphabetaxy_loop_IdIq_M3/Cur_Controller_alphabeta_Fault_IdIq/Pi_q'
 * '<S186>' : 'Testmodel/FocControl_M3/Cur_alphabetaxy_loop_IdIq_M3/Cur_Controller_alphabeta_Fault_IdIq/Pi_d/PI_Controller_d'
 * '<S187>' : 'Testmodel/FocControl_M3/Cur_alphabetaxy_loop_IdIq_M3/Cur_Controller_alphabeta_Fault_IdIq/Pi_d/PI_Controller_d/Saturation'
 * '<S188>' : 'Testmodel/FocControl_M3/Cur_alphabetaxy_loop_IdIq_M3/Cur_Controller_alphabeta_Fault_IdIq/Pi_d/PI_Controller_d/integrator'
 * '<S189>' : 'Testmodel/FocControl_M3/Cur_alphabetaxy_loop_IdIq_M3/Cur_Controller_alphabeta_Fault_IdIq/Pi_q/PI_Controller_q'
 * '<S190>' : 'Testmodel/FocControl_M3/Cur_alphabetaxy_loop_IdIq_M3/Cur_Controller_alphabeta_Fault_IdIq/Pi_q/PI_Controller_q/Saturation'
 * '<S191>' : 'Testmodel/FocControl_M3/Cur_alphabetaxy_loop_IdIq_M3/Cur_Controller_alphabeta_Fault_IdIq/Pi_q/PI_Controller_q/integrator'
 * '<S192>' : 'Testmodel/FocControl_M3/IqRefCalc_M3/IqRefCalc'
 * '<S193>' : 'Testmodel/FocControl_M3/IqRefCalc_M3/IqSatur'
 * '<S194>' : 'Testmodel/FocControl_M3/Kalman_M3/JudgeofHallTurn'
 * '<S195>' : 'Testmodel/FocControl_M3/Kalman_M3/KF'
 * '<S196>' : 'Testmodel/FocControl_M3/Kalman_M3/KF/If Action Subsystem'
 * '<S197>' : 'Testmodel/FocControl_M3/Kalman_M3/KF/KFP'
 * '<S198>' : 'Testmodel/FocControl_M3/Kalman_M3/KF/KFPandU'
 * '<S199>' : 'Testmodel/FocControl_M3/Kalman_M3/KF/Trim_2'
 * '<S200>' : 'Testmodel/FocControl_M3/Kalman_M3/KF/X0'
 * '<S201>' : 'Testmodel/FocControl_M3/Kalman_M3/KF/If Action Subsystem/If Action Subsystem'
 * '<S202>' : 'Testmodel/FocControl_M3/Kalman_M3/KF/If Action Subsystem/If Action Subsystem1'
 * '<S203>' : 'Testmodel/FocControl_M3/Kalman_M3/KF/KFPandU/KFU'
 * '<S204>' : 'Testmodel/FocControl_M3/Kalman_M3/KF/KFPandU/KFU/Judgement'
 * '<S205>' : 'Testmodel/FocControl_M3/Kalman_M3/KF/KFPandU/KFU/Trim_2'
 * '<S206>' : 'Testmodel/FocControl_M3/Kalman_M3/KF/KFPandU/KFU/Judgement/If Action Subsystem'
 * '<S207>' : 'Testmodel/FocControl_M3/Kalman_M3/KF/KFPandU/KFU/Judgement/If Action Subsystem1'
 * '<S208>' : 'Testmodel/FocControl_M3/Kalman_M3/KF/KFPandU/KFU/Judgement/If Action Subsystem/Trim'
 * '<S209>' : 'Testmodel/FocControl_M3/Kalman_M3/KF/KFPandU/KFU/Judgement/If Action Subsystem/Trim/If Action Subsystem'
 * '<S210>' : 'Testmodel/FocControl_M3/Kalman_M3/KF/KFPandU/KFU/Judgement/If Action Subsystem/Trim/If Action Subsystem1'
 * '<S211>' : 'Testmodel/FocControl_M3/Kalman_M3/KF/KFPandU/KFU/Judgement/If Action Subsystem/Trim/If Action Subsystem2'
 * '<S212>' : 'Testmodel/FocControl_M3/Kalman_M3/KF/KFPandU/KFU/Judgement/If Action Subsystem1/Trim'
 * '<S213>' : 'Testmodel/FocControl_M3/Kalman_M3/KF/KFPandU/KFU/Judgement/If Action Subsystem1/Trim/If Action Subsystem'
 * '<S214>' : 'Testmodel/FocControl_M3/Kalman_M3/KF/KFPandU/KFU/Judgement/If Action Subsystem1/Trim/If Action Subsystem1'
 * '<S215>' : 'Testmodel/FocControl_M3/Kalman_M3/KF/KFPandU/KFU/Judgement/If Action Subsystem1/Trim/If Action Subsystem2'
 * '<S216>' : 'Testmodel/FocControl_M3/Kalman_M3/KF/KFPandU/KFU/Trim_2/Trim_1'
 * '<S217>' : 'Testmodel/FocControl_M3/Kalman_M3/KF/KFPandU/KFU/Trim_2/Trim_1/If Action Subsystem'
 * '<S218>' : 'Testmodel/FocControl_M3/Kalman_M3/KF/KFPandU/KFU/Trim_2/Trim_1/If Action Subsystem1'
 * '<S219>' : 'Testmodel/FocControl_M3/Kalman_M3/KF/KFPandU/KFU/Trim_2/Trim_1/If Action Subsystem2'
 * '<S220>' : 'Testmodel/FocControl_M3/Kalman_M3/KF/Trim_2/Trim_1'
 * '<S221>' : 'Testmodel/FocControl_M3/Kalman_M3/KF/Trim_2/Trim_1/If Action Subsystem'
 * '<S222>' : 'Testmodel/FocControl_M3/Kalman_M3/KF/Trim_2/Trim_1/If Action Subsystem1'
 * '<S223>' : 'Testmodel/FocControl_M3/Kalman_M3/KF/Trim_2/Trim_1/If Action Subsystem2'
 * '<S224>' : 'Testmodel/FocControl_M3/PWM_Generate_UdUq_M3/PWMFOC_SectorCalc_UdUq'
 * '<S225>' : 'Testmodel/FocControl_M3/PWM_Generate_UdUq_M3/PWMFOC_T12CoefCalc_UdUq'
 * '<S226>' : 'Testmodel/FocControl_M3/PWM_Generate_UdUq_M3/PWMFOC_TabcCalc_UdUq'
 * '<S227>' : 'Testmodel/FocControl_M3/PWM_Generate_UdUq_M3/TonUVWCalc_UdUq'
 * '<S228>' : 'Testmodel/FocControl_M3/PWM_Generate_UdUq_M3/PWMFOC_SectorCalc_UdUq/If Action Subsystem'
 * '<S229>' : 'Testmodel/FocControl_M3/PWM_Generate_UdUq_M3/PWMFOC_SectorCalc_UdUq/If Action Subsystem1'
 * '<S230>' : 'Testmodel/FocControl_M3/PWM_Generate_UdUq_M3/PWMFOC_T12CoefCalc_UdUq/Subsystem'
 * '<S231>' : 'Testmodel/FocControl_M3/PWM_Generate_UdUq_M3/PWMFOC_T12CoefCalc_UdUq/Switch Case Action Subsystem'
 * '<S232>' : 'Testmodel/FocControl_M3/PWM_Generate_UdUq_M3/PWMFOC_T12CoefCalc_UdUq/Switch Case Action Subsystem1'
 * '<S233>' : 'Testmodel/FocControl_M3/PWM_Generate_UdUq_M3/PWMFOC_T12CoefCalc_UdUq/Switch Case Action Subsystem2'
 * '<S234>' : 'Testmodel/FocControl_M3/PWM_Generate_UdUq_M3/PWMFOC_T12CoefCalc_UdUq/Switch Case Action Subsystem3'
 * '<S235>' : 'Testmodel/FocControl_M3/PWM_Generate_UdUq_M3/PWMFOC_T12CoefCalc_UdUq/Switch Case Action Subsystem4'
 * '<S236>' : 'Testmodel/FocControl_M3/PWM_Generate_UdUq_M3/PWMFOC_T12CoefCalc_UdUq/Switch Case Action Subsystem5'
 * '<S237>' : 'Testmodel/FocControl_M3/PWM_Generate_UdUq_M3/PWMFOC_T12CoefCalc_UdUq/Subsystem/If Action Subsystem'
 * '<S238>' : 'Testmodel/FocControl_M3/PWM_Generate_UdUq_M3/PWMFOC_T12CoefCalc_UdUq/Subsystem/If Action Subsystem1'
 * '<S239>' : 'Testmodel/FocControl_M3/PWM_Generate_UdUq_M3/PWMFOC_T12CoefCalc_UdUq/Subsystem/If Action Subsystem/Switch Case Action Subsystem'
 * '<S240>' : 'Testmodel/FocControl_M3/PWM_Generate_UdUq_M3/PWMFOC_T12CoefCalc_UdUq/Subsystem/If Action Subsystem/Switch Case Action Subsystem1'
 * '<S241>' : 'Testmodel/FocControl_M3/SpeedToIq_M3/If Action Subsystem'
 * '<S242>' : 'Testmodel/FocControl_M3/SpeedToIq_M3/If Action Subsystem1'
 * '<S243>' : 'Testmodel/FocControl_M3/SpeedToIq_M3/If Action Subsystem2'
 * '<S244>' : 'Testmodel/FocControl_M3/Speed_PI_M3/Saturation'
 * '<S245>' : 'Testmodel/FocControl_M3/Speed_PI_M3/integrator'
 * '<S246>' : 'Testmodel/FocControl_M3/UdUq_Mode_Cal_M3/f32_Angle_CosSin_Value'
 * '<S247>' : 'Testmodel/FocControl_M4/Counter_M4'
 * '<S248>' : 'Testmodel/FocControl_M4/Cur_alphabetaxy_loop_IdIq_M4'
 * '<S249>' : 'Testmodel/FocControl_M4/IqRefCalc_M4'
 * '<S250>' : 'Testmodel/FocControl_M4/Kalman_M4'
 * '<S251>' : 'Testmodel/FocControl_M4/PWM_Generate_UdUq_M4'
 * '<S252>' : 'Testmodel/FocControl_M4/SpeedToIq_M4'
 * '<S253>' : 'Testmodel/FocControl_M4/Speed_PI_M4'
 * '<S254>' : 'Testmodel/FocControl_M4/UdUq_Mode_Cal_M4'
 * '<S255>' : 'Testmodel/FocControl_M4/Cur_alphabetaxy_loop_IdIq_M4/Clarke_Transformation_Fault_IdIq'
 * '<S256>' : 'Testmodel/FocControl_M4/Cur_alphabetaxy_loop_IdIq_M4/Cur_Controller_alphabeta_Fault_IdIq'
 * '<S257>' : 'Testmodel/FocControl_M4/Cur_alphabetaxy_loop_IdIq_M4/EAngle_cos_sin_cal_IdIq'
 * '<S258>' : 'Testmodel/FocControl_M4/Cur_alphabetaxy_loop_IdIq_M4/Park_Transformation_alphabeta_Fault_IdIq '
 * '<S259>' : 'Testmodel/FocControl_M4/Cur_alphabetaxy_loop_IdIq_M4/Cur_Controller_alphabeta_Fault_IdIq/Pi_d'
 * '<S260>' : 'Testmodel/FocControl_M4/Cur_alphabetaxy_loop_IdIq_M4/Cur_Controller_alphabeta_Fault_IdIq/Pi_q'
 * '<S261>' : 'Testmodel/FocControl_M4/Cur_alphabetaxy_loop_IdIq_M4/Cur_Controller_alphabeta_Fault_IdIq/Pi_d/PI_Controller_d'
 * '<S262>' : 'Testmodel/FocControl_M4/Cur_alphabetaxy_loop_IdIq_M4/Cur_Controller_alphabeta_Fault_IdIq/Pi_d/PI_Controller_d/Saturation'
 * '<S263>' : 'Testmodel/FocControl_M4/Cur_alphabetaxy_loop_IdIq_M4/Cur_Controller_alphabeta_Fault_IdIq/Pi_d/PI_Controller_d/integrator'
 * '<S264>' : 'Testmodel/FocControl_M4/Cur_alphabetaxy_loop_IdIq_M4/Cur_Controller_alphabeta_Fault_IdIq/Pi_q/PI_Controller_q'
 * '<S265>' : 'Testmodel/FocControl_M4/Cur_alphabetaxy_loop_IdIq_M4/Cur_Controller_alphabeta_Fault_IdIq/Pi_q/PI_Controller_q/Saturation'
 * '<S266>' : 'Testmodel/FocControl_M4/Cur_alphabetaxy_loop_IdIq_M4/Cur_Controller_alphabeta_Fault_IdIq/Pi_q/PI_Controller_q/integrator'
 * '<S267>' : 'Testmodel/FocControl_M4/IqRefCalc_M4/IqRefCalc'
 * '<S268>' : 'Testmodel/FocControl_M4/IqRefCalc_M4/IqSatur'
 * '<S269>' : 'Testmodel/FocControl_M4/Kalman_M4/JudgeofHallTurn'
 * '<S270>' : 'Testmodel/FocControl_M4/Kalman_M4/KF'
 * '<S271>' : 'Testmodel/FocControl_M4/Kalman_M4/KF/If Action Subsystem'
 * '<S272>' : 'Testmodel/FocControl_M4/Kalman_M4/KF/KFP'
 * '<S273>' : 'Testmodel/FocControl_M4/Kalman_M4/KF/KFPandU'
 * '<S274>' : 'Testmodel/FocControl_M4/Kalman_M4/KF/Trim_2'
 * '<S275>' : 'Testmodel/FocControl_M4/Kalman_M4/KF/X0'
 * '<S276>' : 'Testmodel/FocControl_M4/Kalman_M4/KF/If Action Subsystem/If Action Subsystem'
 * '<S277>' : 'Testmodel/FocControl_M4/Kalman_M4/KF/If Action Subsystem/If Action Subsystem1'
 * '<S278>' : 'Testmodel/FocControl_M4/Kalman_M4/KF/KFPandU/KFU'
 * '<S279>' : 'Testmodel/FocControl_M4/Kalman_M4/KF/KFPandU/KFU/Judgement'
 * '<S280>' : 'Testmodel/FocControl_M4/Kalman_M4/KF/KFPandU/KFU/Trim_2'
 * '<S281>' : 'Testmodel/FocControl_M4/Kalman_M4/KF/KFPandU/KFU/Judgement/If Action Subsystem'
 * '<S282>' : 'Testmodel/FocControl_M4/Kalman_M4/KF/KFPandU/KFU/Judgement/If Action Subsystem1'
 * '<S283>' : 'Testmodel/FocControl_M4/Kalman_M4/KF/KFPandU/KFU/Judgement/If Action Subsystem/Trim'
 * '<S284>' : 'Testmodel/FocControl_M4/Kalman_M4/KF/KFPandU/KFU/Judgement/If Action Subsystem/Trim/If Action Subsystem'
 * '<S285>' : 'Testmodel/FocControl_M4/Kalman_M4/KF/KFPandU/KFU/Judgement/If Action Subsystem/Trim/If Action Subsystem1'
 * '<S286>' : 'Testmodel/FocControl_M4/Kalman_M4/KF/KFPandU/KFU/Judgement/If Action Subsystem/Trim/If Action Subsystem2'
 * '<S287>' : 'Testmodel/FocControl_M4/Kalman_M4/KF/KFPandU/KFU/Judgement/If Action Subsystem1/Trim'
 * '<S288>' : 'Testmodel/FocControl_M4/Kalman_M4/KF/KFPandU/KFU/Judgement/If Action Subsystem1/Trim/If Action Subsystem'
 * '<S289>' : 'Testmodel/FocControl_M4/Kalman_M4/KF/KFPandU/KFU/Judgement/If Action Subsystem1/Trim/If Action Subsystem1'
 * '<S290>' : 'Testmodel/FocControl_M4/Kalman_M4/KF/KFPandU/KFU/Judgement/If Action Subsystem1/Trim/If Action Subsystem2'
 * '<S291>' : 'Testmodel/FocControl_M4/Kalman_M4/KF/KFPandU/KFU/Trim_2/Trim_1'
 * '<S292>' : 'Testmodel/FocControl_M4/Kalman_M4/KF/KFPandU/KFU/Trim_2/Trim_1/If Action Subsystem'
 * '<S293>' : 'Testmodel/FocControl_M4/Kalman_M4/KF/KFPandU/KFU/Trim_2/Trim_1/If Action Subsystem1'
 * '<S294>' : 'Testmodel/FocControl_M4/Kalman_M4/KF/KFPandU/KFU/Trim_2/Trim_1/If Action Subsystem2'
 * '<S295>' : 'Testmodel/FocControl_M4/Kalman_M4/KF/Trim_2/Trim_1'
 * '<S296>' : 'Testmodel/FocControl_M4/Kalman_M4/KF/Trim_2/Trim_1/If Action Subsystem'
 * '<S297>' : 'Testmodel/FocControl_M4/Kalman_M4/KF/Trim_2/Trim_1/If Action Subsystem1'
 * '<S298>' : 'Testmodel/FocControl_M4/Kalman_M4/KF/Trim_2/Trim_1/If Action Subsystem2'
 * '<S299>' : 'Testmodel/FocControl_M4/PWM_Generate_UdUq_M4/PWMFOC_SectorCalc_UdUq'
 * '<S300>' : 'Testmodel/FocControl_M4/PWM_Generate_UdUq_M4/PWMFOC_T12CoefCalc_UdUq'
 * '<S301>' : 'Testmodel/FocControl_M4/PWM_Generate_UdUq_M4/PWMFOC_TabcCalc_UdUq'
 * '<S302>' : 'Testmodel/FocControl_M4/PWM_Generate_UdUq_M4/TonUVWCalc_UdUq'
 * '<S303>' : 'Testmodel/FocControl_M4/PWM_Generate_UdUq_M4/PWMFOC_SectorCalc_UdUq/If Action Subsystem'
 * '<S304>' : 'Testmodel/FocControl_M4/PWM_Generate_UdUq_M4/PWMFOC_SectorCalc_UdUq/If Action Subsystem1'
 * '<S305>' : 'Testmodel/FocControl_M4/PWM_Generate_UdUq_M4/PWMFOC_T12CoefCalc_UdUq/Subsystem'
 * '<S306>' : 'Testmodel/FocControl_M4/PWM_Generate_UdUq_M4/PWMFOC_T12CoefCalc_UdUq/Switch Case Action Subsystem'
 * '<S307>' : 'Testmodel/FocControl_M4/PWM_Generate_UdUq_M4/PWMFOC_T12CoefCalc_UdUq/Switch Case Action Subsystem1'
 * '<S308>' : 'Testmodel/FocControl_M4/PWM_Generate_UdUq_M4/PWMFOC_T12CoefCalc_UdUq/Switch Case Action Subsystem2'
 * '<S309>' : 'Testmodel/FocControl_M4/PWM_Generate_UdUq_M4/PWMFOC_T12CoefCalc_UdUq/Switch Case Action Subsystem3'
 * '<S310>' : 'Testmodel/FocControl_M4/PWM_Generate_UdUq_M4/PWMFOC_T12CoefCalc_UdUq/Switch Case Action Subsystem4'
 * '<S311>' : 'Testmodel/FocControl_M4/PWM_Generate_UdUq_M4/PWMFOC_T12CoefCalc_UdUq/Switch Case Action Subsystem5'
 * '<S312>' : 'Testmodel/FocControl_M4/PWM_Generate_UdUq_M4/PWMFOC_T12CoefCalc_UdUq/Subsystem/If Action Subsystem'
 * '<S313>' : 'Testmodel/FocControl_M4/PWM_Generate_UdUq_M4/PWMFOC_T12CoefCalc_UdUq/Subsystem/If Action Subsystem1'
 * '<S314>' : 'Testmodel/FocControl_M4/PWM_Generate_UdUq_M4/PWMFOC_T12CoefCalc_UdUq/Subsystem/If Action Subsystem/Switch Case Action Subsystem'
 * '<S315>' : 'Testmodel/FocControl_M4/PWM_Generate_UdUq_M4/PWMFOC_T12CoefCalc_UdUq/Subsystem/If Action Subsystem/Switch Case Action Subsystem1'
 * '<S316>' : 'Testmodel/FocControl_M4/SpeedToIq_M4/If Action Subsystem'
 * '<S317>' : 'Testmodel/FocControl_M4/SpeedToIq_M4/If Action Subsystem1'
 * '<S318>' : 'Testmodel/FocControl_M4/SpeedToIq_M4/If Action Subsystem2'
 * '<S319>' : 'Testmodel/FocControl_M4/Speed_PI_M4/Saturation'
 * '<S320>' : 'Testmodel/FocControl_M4/Speed_PI_M4/integrator'
 * '<S321>' : 'Testmodel/FocControl_M4/UdUq_Mode_Cal_M4/f32_Angle_SinCos_Value'
 */
#endif                                 /* RTW_HEADER_Testmodel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

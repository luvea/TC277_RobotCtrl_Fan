/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Testmodel_data.c
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

#include "Testmodel.h"

/* Invariant block signals (default storage) */
const ConstB rtConstB = {
  { 1.0F, 0.0001F, 5.0E-9F, 0.0F, 1.0F, 0.0001F, 0.0F, 0.0F, 1.0F },/* '<S278>/Transpose' */

  { 1.0F, 0.0F, 0.0F },                /* '<S278>/Transpose5' */

  { 1.0F, 0.0001F, 5.0E-9F, 0.0F, 1.0F, 0.0001F, 0.0F, 0.0F, 1.0F },/* '<S203>/Transpose' */

  { 1.0F, 0.0F, 0.0F },                /* '<S203>/Transpose5' */

  { 1.0F, 0.0001F, 5.0E-9F, 0.0F, 1.0F, 0.0001F, 0.0F, 0.0F, 1.0F },/* '<S128>/Transpose' */

  { 1.0F, 0.0F, 0.0F },                /* '<S128>/Transpose5' */

  { 1.0F, 0.0001F, 5.0E-9F, 0.0F, 1.0F, 0.0001F, 0.0F, 0.0F, 1.0F },/* '<S53>/Transpose' */

  { 1.0F, 0.0F, 0.0F },                /* '<S53>/Transpose5' */

  /* Start of '<S270>/KFP' */
  {
    { 1.0F, 0.0001F, 5.0E-9F, 0.0F, 1.0F, 0.0001F, 0.0F, 0.0F, 1.0F }/* '<S272>/Transpose5' */
  }
  ,

  /* End of '<S270>/KFP' */

  /* Start of '<S195>/KFP' */
  {
    { 1.0F, 0.0001F, 5.0E-9F, 0.0F, 1.0F, 0.0001F, 0.0F, 0.0F, 1.0F }/* '<S197>/Transpose5' */
  }
  ,

  /* End of '<S195>/KFP' */

  /* Start of '<S120>/KFP' */
  {
    { 1.0F, 0.0001F, 5.0E-9F, 0.0F, 1.0F, 0.0001F, 0.0F, 0.0F, 1.0F }/* '<S122>/Transpose5' */
  }
  ,

  /* End of '<S120>/KFP' */

  /* Start of '<S45>/KFP' */
  {
    { 1.0F, 0.0001F, 5.0E-9F, 0.0F, 1.0F, 0.0001F, 0.0F, 0.0F, 1.0F }/* '<S47>/Transpose5' */
  }
  /* End of '<S45>/KFP' */
};

/* Constant parameters (default storage) */
const ConstP rtConstP = {
  /* Pooled Parameter (Expression: [1 0 0;0 1 0;0 0 1])
   * Referenced by:
   *   '<S53>/I'
   *   '<S128>/I'
   *   '<S203>/I'
   *   '<S278>/I'
   */
  { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },

  /* Pooled Parameter (Expression: [1 0 0])
   * Referenced by:
   *   '<S53>/H'
   *   '<S128>/H'
   *   '<S203>/H'
   *   '<S278>/H'
   */
  { 1.0F, 0.0F, 0.0F },

  /* Pooled Parameter (Expression: [1e3 0 0;0 1e6 0;
     0 0 1e8])
   * Referenced by:
   *   '<S51>/P0'
   *   '<S126>/P0'
   *   '<S201>/P0'
   *   '<S276>/P0'
   */
  { 1000.0F, 0.0F, 0.0F, 0.0F, 1.0E+6F, 0.0F, 0.0F, 0.0F, 1.0E+8F },

  /* Pooled Parameter (Expression: [1 1e-4 1e-4*1e-4/2;0 1 1e-4;0 0 1])
   * Referenced by:
   *   '<S45>/Constant1'
   *   '<S120>/Constant1'
   *   '<S195>/Constant1'
   *   '<S270>/Constant1'
   */
  { 1.0F, 0.0F, 0.0F, 0.0001F, 1.0F, 0.0F, 5.0E-9F, 0.0001F, 1.0F },

  /* Pooled Parameter (Expression: [1e3 0 0;0 1e6 0;0 0 1e6])
   * Referenced by:
   *   '<S45>/P0'
   *   '<S120>/P0'
   *   '<S195>/P0'
   *   '<S270>/P0'
   */
  { 1000.0F, 0.0F, 0.0F, 0.0F, 1.0E+6F, 0.0F, 0.0F, 0.0F, 1.0E+6F },

  /* Pooled Parameter (Expression: [0 0 0;
     0 1e4 0;
     0 0 1e4])
   * Referenced by:
   *   '<S45>/Q0'
   *   '<S120>/Q0'
   *   '<S195>/Q0'
   *   '<S270>/Q0'
   */
  { 0.0F, 0.0F, 0.0F, 0.0F, 10000.0F, 0.0F, 0.0F, 0.0F, 10000.0F },

  /* Pooled Parameter (Expression: [270 150 210 30 330 90])
   * Referenced by:
   *   '<S2>/f32_Motor_Angle_M1_Value'
   *   '<S3>/f32_Motor_Angle_M2_Value'
   *   '<S4>/f32_Motor_Angle_M3_Value'
   *   '<S5>/f32_Motor_Angle_M4_Value'
   */
  { 270, 150, 210, 30, 330, 90 },

  /* Pooled Parameter (Expression: [1 2 3 4 5 6])
   * Referenced by:
   *   '<S2>/f32_Motor_Angle_M1_Value'
   *   '<S3>/f32_Motor_Angle_M2_Value'
   *   '<S4>/f32_Motor_Angle_M3_Value'
   *   '<S5>/f32_Motor_Angle_M4_Value'
   */
  { 1U, 2U, 3U, 4U, 5U, 6U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * LQR_forRTMaps10ms.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "LQR_forRTMaps10ms".
 *
 * Model version              : 1.5
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Fri Oct 31 12:11:31 2025
 *
 * Target selection: rtmaps.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LQR_forRTMaps10ms.h"

/* Model step function */
void LQR_forRTMaps10ms::step()
{
  /* Outport: '<Root>/Outport' incorporates:
   *  Inport: '<Root>/Inport'
   *  Inport: '<Root>/Inport1'
   *  Inport: '<Root>/Inport2'
   *  Inport: '<Root>/Inport3'
   *  MATLAB Function: '<Root>/LQR Block'
   */
  LQR_forRTMaps10ms_Y.Outport = -LQR_forRTMaps10ms_U.K_derr *
    LQR_forRTMaps10ms_U.foll_dist_err - LQR_forRTMaps10ms_U.K_vh *
    LQR_forRTMaps10ms_U.relative_spd;
}

/* Model initialize function */
void LQR_forRTMaps10ms::initialize()
{
  /* (no initialization code required) */
}

/* Model terminate function */
void LQR_forRTMaps10ms::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
LQR_forRTMaps10ms::LQR_forRTMaps10ms() :
  LQR_forRTMaps10ms_U(),
  LQR_forRTMaps10ms_Y(),
  LQR_forRTMaps10ms_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
/* Currently there is no destructor body generated.*/
LQR_forRTMaps10ms::~LQR_forRTMaps10ms() = default;

/* Real-Time Model get method */
RT_MODEL_LQR_forRTMaps10ms_T * LQR_forRTMaps10ms::getRTM()
{
  return (&LQR_forRTMaps10ms_M);
}

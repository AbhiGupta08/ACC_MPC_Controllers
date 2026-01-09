/*
 * LQR_Desired_Command_Accel.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "LQR_Desired_Command_Accel".
 *
 * Model version              : 1.1
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Fri Jan  9 06:47:03 2026
 *
 * Target selection: rtmaps.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LQR_Desired_Command_Accel.h"

/* Model step function */
void LQR_Desired_Command_Accel::step()
{
  /* Outport: '<Root>/LQR Acceleration (m//s2)' incorporates:
   *  Inport: '<Root>/Following Distance Error (m)'
   *  Inport: '<Root>/K_dist_err'
   *  Inport: '<Root>/K_rel_velocity'
   *  Inport: '<Root>/Relative Velocity (m//s)'
   *  MATLAB Function: '<Root>/LQR Block'
   */
  LQR_Desired_Command_Accel_Y.LQRAccelerationms2 =
    -LQR_Desired_Command_Accel_U.K_dist_err *
    LQR_Desired_Command_Accel_U.FollowingDistanceErrorm -
    LQR_Desired_Command_Accel_U.K_rel_velocity *
    LQR_Desired_Command_Accel_U.RelativeVelocityms;
}

/* Model initialize function */
void LQR_Desired_Command_Accel::initialize()
{
  /* (no initialization code required) */
}

/* Model terminate function */
void LQR_Desired_Command_Accel::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
LQR_Desired_Command_Accel::LQR_Desired_Command_Accel() :
  LQR_Desired_Command_Accel_U(),
  LQR_Desired_Command_Accel_Y(),
  LQR_Desired_Command_Accel_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
/* Currently there is no destructor body generated.*/
LQR_Desired_Command_Accel::~LQR_Desired_Command_Accel() = default;

/* Real-Time Model get method */
RT_MODEL_LQR_Desired_Command__T * LQR_Desired_Command_Accel::getRTM()
{
  return (&LQR_Desired_Command_Accel_M);
}

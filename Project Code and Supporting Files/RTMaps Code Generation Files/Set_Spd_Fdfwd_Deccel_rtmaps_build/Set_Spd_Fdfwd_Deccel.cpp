/*
 * Set_Spd_Fdfwd_Deccel.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Set_Spd_Fdfwd_Deccel".
 *
 * Model version              : 1.1
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Thu Jan  8 12:46:33 2026
 *
 * Target selection: rtmaps.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Set_Spd_Fdfwd_Deccel.h"
#include "rtwtypes.h"

/* Model step function */
void Set_Spd_Fdfwd_Deccel::step()
{
  real_T set_spd_err;

  /* MATLAB Function: '<Root>/Set Speed Match Feedforward' incorporates:
   *  Inport: '<Root>/Host Velocity (m//s)'
   *  Inport: '<Root>/Set Speed Target (m//s)'
   */
  set_spd_err = Set_Spd_Fdfwd_Deccel_U.SetSpeedTargetms -
    Set_Spd_Fdfwd_Deccel_U.HostVelocityms;
  if (set_spd_err < 0.0) {
    /* Outport: '<Root>/Set Speed FeedForward Deccel (m//s2)' incorporates:
     *  Inport: '<Root>/Preview Time for Deccel (s)'
     */
    Set_Spd_Fdfwd_Deccel_Y.SetSpeedFeedForwardDeccelms2 = set_spd_err /
      Set_Spd_Fdfwd_Deccel_U.PreviewTimeforDeccels;
  } else {
    /* Outport: '<Root>/Set Speed FeedForward Deccel (m//s2)' */
    Set_Spd_Fdfwd_Deccel_Y.SetSpeedFeedForwardDeccelms2 = 0.0;
  }

  /* Outport: '<Root>/Set Speed error (m//s)' incorporates:
   *  MATLAB Function: '<Root>/Set Speed Match Feedforward'
   */
  Set_Spd_Fdfwd_Deccel_Y.SetSpeederrorms = set_spd_err;
}

/* Model initialize function */
void Set_Spd_Fdfwd_Deccel::initialize()
{
  /* (no initialization code required) */
}

/* Model terminate function */
void Set_Spd_Fdfwd_Deccel::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
Set_Spd_Fdfwd_Deccel::Set_Spd_Fdfwd_Deccel() :
  Set_Spd_Fdfwd_Deccel_U(),
  Set_Spd_Fdfwd_Deccel_Y(),
  Set_Spd_Fdfwd_Deccel_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
/* Currently there is no destructor body generated.*/
Set_Spd_Fdfwd_Deccel::~Set_Spd_Fdfwd_Deccel() = default;

/* Real-Time Model get method */
RT_MODEL_Set_Spd_Fdfwd_Deccel_T * Set_Spd_Fdfwd_Deccel::getRTM()
{
  return (&Set_Spd_Fdfwd_Deccel_M);
}

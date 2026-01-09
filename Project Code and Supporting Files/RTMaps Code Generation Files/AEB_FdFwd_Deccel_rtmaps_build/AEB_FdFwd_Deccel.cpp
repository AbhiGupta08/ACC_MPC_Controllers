/*
 * AEB_FdFwd_Deccel.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "AEB_FdFwd_Deccel".
 *
 * Model version              : 1.1
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Fri Jan  9 06:26:39 2026
 *
 * Target selection: rtmaps.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AEB_FdFwd_Deccel.h"

/* Model step function */
void AEB_FdFwd_Deccel::step()
{
  /* MATLAB Function: '<Root>/AEB Feedforward Compensator' incorporates:
   *  Inport: '<Root>/Relative Velocity (m//s)'
   *  Inport: '<Root>/Relative Velocity Threshold (m//s)'
   */
  if (AEB_FdFwd_Deccel_U.RelativeVelocityms >
      -AEB_FdFwd_Deccel_U.RelativeVelocityThresholdms) {
    /* Outport: '<Root>/AEB FeedForward Deccel (m//s2)' */
    AEB_FdFwd_Deccel_Y.AEBFeedForwardDeccelms2 = 0.0;
  } else {
    /* Outport: '<Root>/AEB FeedForward Deccel (m//s2)' incorporates:
     *  Inport: '<Root>/Preview Time for Deccel (s)'
     */
    AEB_FdFwd_Deccel_Y.AEBFeedForwardDeccelms2 =
      AEB_FdFwd_Deccel_U.RelativeVelocityms /
      AEB_FdFwd_Deccel_U.PreviewTimeforDeccels;
  }

  /* End of MATLAB Function: '<Root>/AEB Feedforward Compensator' */
}

/* Model initialize function */
void AEB_FdFwd_Deccel::initialize()
{
  /* (no initialization code required) */
}

/* Model terminate function */
void AEB_FdFwd_Deccel::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
AEB_FdFwd_Deccel::AEB_FdFwd_Deccel() :
  AEB_FdFwd_Deccel_U(),
  AEB_FdFwd_Deccel_Y(),
  AEB_FdFwd_Deccel_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
/* Currently there is no destructor body generated.*/
AEB_FdFwd_Deccel::~AEB_FdFwd_Deccel() = default;

/* Real-Time Model get method */
RT_MODEL_AEB_FdFwd_Deccel_T * AEB_FdFwd_Deccel::getRTM()
{
  return (&AEB_FdFwd_Deccel_M);
}

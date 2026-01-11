/*
 * Saturator_with_bounds_inputs.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Saturator_with_bounds_inputs".
 *
 * Model version              : 1.2
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Sat Jan 10 16:08:14 2026
 *
 * Target selection: rtmaps.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Saturator_with_bounds_inputs.h"

/* Model step function */
void Saturator_with_bounds_inputs::step()
{
  /* Switch: '<S1>/Switch2' incorporates:
   *  Inport: '<Root>/Lower Bound'
   *  Inport: '<Root>/Signal Input'
   *  Inport: '<Root>/Upper Bound'
   *  RelationalOperator: '<S1>/LowerRelop1'
   *  RelationalOperator: '<S1>/UpperRelop'
   *  Switch: '<S1>/Switch'
   */
  if (Saturator_with_bounds_inputs_U.SignalInput >
      Saturator_with_bounds_inputs_U.UpperBound) {
    /* Outport: '<Root>/Signal Output' */
    Saturator_with_bounds_inputs_Y.SignalOutput =
      Saturator_with_bounds_inputs_U.UpperBound;
  } else if (Saturator_with_bounds_inputs_U.SignalInput <
             Saturator_with_bounds_inputs_U.LowerBound) {
    /* Switch: '<S1>/Switch' incorporates:
     *  Inport: '<Root>/Lower Bound'
     *  Outport: '<Root>/Signal Output'
     */
    Saturator_with_bounds_inputs_Y.SignalOutput =
      Saturator_with_bounds_inputs_U.LowerBound;
  } else {
    /* Outport: '<Root>/Signal Output' */
    Saturator_with_bounds_inputs_Y.SignalOutput =
      Saturator_with_bounds_inputs_U.SignalInput;
  }

  /* End of Switch: '<S1>/Switch2' */
}

/* Model initialize function */
void Saturator_with_bounds_inputs::initialize()
{
  /* (no initialization code required) */
}

/* Model terminate function */
void Saturator_with_bounds_inputs::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
Saturator_with_bounds_inputs::Saturator_with_bounds_inputs() :
  Saturator_with_bounds_inputs_U(),
  Saturator_with_bounds_inputs_Y(),
  Saturator_with_bounds_inputs_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
/* Currently there is no destructor body generated.*/
Saturator_with_bounds_inputs::~Saturator_with_bounds_inputs() = default;

/* Real-Time Model get method */
RT_MODEL_Saturator_with_bound_T * Saturator_with_bounds_inputs::getRTM()
{
  return (&Saturator_with_bounds_inputs_M);
}

/*
 * DiscreteTimeDerivative.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "DiscreteTimeDerivative".
 *
 * Model version              : 1.1
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Sun Jan 11 14:27:45 2026
 *
 * Target selection: rtmaps.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DiscreteTimeDerivative.h"
#include "rtwtypes.h"

/* Model step function */
void DiscreteTimeDerivative::step()
{
  real_T rtb_TSamp;

  /* SampleTimeMath: '<S1>/TSamp' incorporates:
   *  Inport: '<Root>/Derivative Input'
   *
   * About '<S1>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TSamp = DiscreteTimeDerivative_U.DerivativeInput *
    DiscreteTimeDerivative_P.TSamp_WtEt;

  /* Outport: '<Root>/Derivative Output' incorporates:
   *  Sum: '<S1>/Diff'
   *  UnitDelay: '<S1>/UD'
   */
  DiscreteTimeDerivative_Y.DerivativeOutput = rtb_TSamp -
    DiscreteTimeDerivative_DW.UD_DSTATE;

  /* Update for UnitDelay: '<S1>/UD' */
  DiscreteTimeDerivative_DW.UD_DSTATE = rtb_TSamp;
}

/* Model initialize function */
void DiscreteTimeDerivative::initialize()
{
  /* InitializeConditions for UnitDelay: '<S1>/UD' */
  DiscreteTimeDerivative_DW.UD_DSTATE =
    DiscreteTimeDerivative_P.DiscreteDerivative_ICPrevScaled;
}

/* Model terminate function */
void DiscreteTimeDerivative::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
DiscreteTimeDerivative::DiscreteTimeDerivative() :
  DiscreteTimeDerivative_U(),
  DiscreteTimeDerivative_Y(),
  DiscreteTimeDerivative_DW(),
  DiscreteTimeDerivative_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
/* Currently there is no destructor body generated.*/
DiscreteTimeDerivative::~DiscreteTimeDerivative() = default;

/* Real-Time Model get method */
RT_MODEL_DiscreteTimeDerivati_T * DiscreteTimeDerivative::getRTM()
{
  return (&DiscreteTimeDerivative_M);
}

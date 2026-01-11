/*
 * DiscreteTimeIntegrator.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "DiscreteTimeIntegrator".
 *
 * Model version              : 1.3
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Sat Jan 10 17:20:06 2026
 *
 * Target selection: rtmaps.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DiscreteTimeIntegrator.h"

/* Model step function */
void DiscreteTimeIntegrator::step()
{
  /* Outport: '<Root>/Integrator Out' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete Integrator'
   */
  DiscreteTimeIntegrator_Y.IntegratorOut =
    DiscreteTimeIntegrator_DW.DiscreteIntegrator_DSTATE;

  /* Update for DiscreteIntegrator: '<Root>/Discrete Integrator' incorporates:
   *  Inport: '<Root>/Integrator In'
   */
  DiscreteTimeIntegrator_DW.DiscreteIntegrator_DSTATE +=
    DiscreteTimeIntegrator_P.DiscreteIntegrator_gainval *
    DiscreteTimeIntegrator_U.IntegratorIn;
}

/* Model initialize function */
void DiscreteTimeIntegrator::initialize()
{
  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete Integrator' */
  DiscreteTimeIntegrator_DW.DiscreteIntegrator_DSTATE =
    DiscreteTimeIntegrator_P.DiscreteIntegrator_IC;
}

/* Model terminate function */
void DiscreteTimeIntegrator::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
DiscreteTimeIntegrator::DiscreteTimeIntegrator() :
  DiscreteTimeIntegrator_U(),
  DiscreteTimeIntegrator_Y(),
  DiscreteTimeIntegrator_DW(),
  DiscreteTimeIntegrator_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
/* Currently there is no destructor body generated.*/
DiscreteTimeIntegrator::~DiscreteTimeIntegrator() = default;

/* Real-Time Model get method */
RT_MODEL_DiscreteTimeIntegrat_T * DiscreteTimeIntegrator::getRTM()
{
  return (&DiscreteTimeIntegrator_M);
}

/*
 * Add3Elements.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Add3Elements".
 *
 * Model version              : 1.1
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Fri Jan  9 11:07:02 2026
 *
 * Target selection: rtmaps.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Add3Elements.h"

/* Model step function */
void Add3Elements::step()
{
  /* Outport: '<Root>/Total Desired Acceleration (m//s2)' incorporates:
   *  Inport: '<Root>/Inport'
   *  Inport: '<Root>/Inport1'
   *  Inport: '<Root>/Inport2'
   *  Sum: '<Root>/Add'
   */
  Add3Elements_Y.TotalDesiredAccelerationms2 = (Add3Elements_U.Inport +
    Add3Elements_U.Inport2) + Add3Elements_U.Inport1;
}

/* Model initialize function */
void Add3Elements::initialize()
{
  /* (no initialization code required) */
}

/* Model terminate function */
void Add3Elements::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
Add3Elements::Add3Elements() :
  Add3Elements_U(),
  Add3Elements_Y(),
  Add3Elements_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
/* Currently there is no destructor body generated.*/
Add3Elements::~Add3Elements() = default;

/* Real-Time Model get method */
RT_MODEL_Add3Elements_T * Add3Elements::getRTM()
{
  return (&Add3Elements_M);
}

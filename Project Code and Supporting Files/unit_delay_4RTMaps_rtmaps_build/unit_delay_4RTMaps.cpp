/*
 * unit_delay_4RTMaps.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "unit_delay_4RTMaps".
 *
 * Model version              : 1.1
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Mon Nov  3 11:37:33 2025
 *
 * Target selection: rtmaps.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "unit_delay_4RTMaps.h"

/* Model step function */
void unit_delay_4RTMaps::step()
{
  /* Outport: '<Root>/unit_delay_out' incorporates:
   *  UnitDelay: '<Root>/Unit Delay'
   */
  unit_delay_4RTMaps_Y.unit_delay_out = unit_delay_4RTMaps_DW.UnitDelay_DSTATE;

  /* Update for UnitDelay: '<Root>/Unit Delay' incorporates:
   *  Inport: '<Root>/unit_delay_in'
   */
  unit_delay_4RTMaps_DW.UnitDelay_DSTATE = unit_delay_4RTMaps_U.unit_delay_in;
}

/* Model initialize function */
void unit_delay_4RTMaps::initialize()
{
  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  unit_delay_4RTMaps_DW.UnitDelay_DSTATE =
    unit_delay_4RTMaps_P.UnitDelay_InitialCondition;
}

/* Model terminate function */
void unit_delay_4RTMaps::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
unit_delay_4RTMaps::unit_delay_4RTMaps() :
  unit_delay_4RTMaps_U(),
  unit_delay_4RTMaps_Y(),
  unit_delay_4RTMaps_DW(),
  unit_delay_4RTMaps_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
/* Currently there is no destructor body generated.*/
unit_delay_4RTMaps::~unit_delay_4RTMaps() = default;

/* Real-Time Model get method */
RT_MODEL_unit_delay_4RTMaps_T * unit_delay_4RTMaps::getRTM()
{
  return (&unit_delay_4RTMaps_M);
}

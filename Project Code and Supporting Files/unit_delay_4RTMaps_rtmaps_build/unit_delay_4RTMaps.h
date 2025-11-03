/*
 * unit_delay_4RTMaps.h
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

#ifndef unit_delay_4RTMaps_h_
#define unit_delay_4RTMaps_h_
#include <cmath>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "unit_delay_4RTMaps_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
struct DW_unit_delay_4RTMaps_T {
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
};

/* External inputs (root inport signals with default storage) */
struct ExtU_unit_delay_4RTMaps_T {
  real_T unit_delay_in;                /* '<Root>/unit_delay_in' */
};

/* External outputs (root outports fed by signals with default storage) */
struct ExtY_unit_delay_4RTMaps_T {
  real_T unit_delay_out;               /* '<Root>/unit_delay_out' */
};

/* Parameters (default storage) */
struct P_unit_delay_4RTMaps_T_ {
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_unit_delay_4RTMaps_T {
  const char_T *errorStatus;
};

/* Class declaration for model unit_delay_4RTMaps */
class unit_delay_4RTMaps final
{
  /* public data and function members */
 public:
  /* Copy Constructor */
  unit_delay_4RTMaps(unit_delay_4RTMaps const&) = delete;

  /* Assignment Operator */
  unit_delay_4RTMaps& operator= (unit_delay_4RTMaps const&) & = delete;

  /* Move Constructor */
  unit_delay_4RTMaps(unit_delay_4RTMaps &&) = delete;

  /* Move Assignment Operator */
  unit_delay_4RTMaps& operator= (unit_delay_4RTMaps &&) = delete;

  /* Real-Time Model get method */
  RT_MODEL_unit_delay_4RTMaps_T * getRTM();

  /* Tunable parameters */
  static P_unit_delay_4RTMaps_T unit_delay_4RTMaps_P;

  /* Root inports set method */
  void setExternalInputs(const ExtU_unit_delay_4RTMaps_T
    *pExtU_unit_delay_4RTMaps_T)
  {
    unit_delay_4RTMaps_U = *pExtU_unit_delay_4RTMaps_T;
  }

  /* Root outports get method */
  const ExtY_unit_delay_4RTMaps_T &getExternalOutputs() const
  {
    return unit_delay_4RTMaps_Y;
  }

  /* Initial conditions function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  static void terminate();

  /* Constructor */
  unit_delay_4RTMaps();

  /* Destructor */
  ~unit_delay_4RTMaps();

  /* private data and function members */
 private:
  /* External inputs */
  ExtU_unit_delay_4RTMaps_T unit_delay_4RTMaps_U;

  /* External outputs */
  ExtY_unit_delay_4RTMaps_T unit_delay_4RTMaps_Y;

  /* Block states */
  DW_unit_delay_4RTMaps_T unit_delay_4RTMaps_DW;

  /* Real-Time Model */
  RT_MODEL_unit_delay_4RTMaps_T unit_delay_4RTMaps_M;
};

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'unit_delay_4RTMaps'
 */
#endif                                 /* unit_delay_4RTMaps_h_ */

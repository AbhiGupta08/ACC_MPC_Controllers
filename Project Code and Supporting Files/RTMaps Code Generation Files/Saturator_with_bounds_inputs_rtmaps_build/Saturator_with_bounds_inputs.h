/*
 * Saturator_with_bounds_inputs.h
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

#ifndef Saturator_with_bounds_inputs_h_
#define Saturator_with_bounds_inputs_h_
#include <cmath>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "Saturator_with_bounds_inputs_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with default storage) */
struct ExtU_Saturator_with_bounds_in_T {
  real_T UpperBound;                   /* '<Root>/Upper Bound' */
  real_T SignalInput;                  /* '<Root>/Signal Input' */
  real_T LowerBound;                   /* '<Root>/Lower Bound' */
};

/* External outputs (root outports fed by signals with default storage) */
struct ExtY_Saturator_with_bounds_in_T {
  real_T SignalOutput;                 /* '<Root>/Signal Output' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Saturator_with_bounds_T {
  const char_T *errorStatus;
};

/* Class declaration for model Saturator_with_bounds_inputs */
class Saturator_with_bounds_inputs final
{
  /* public data and function members */
 public:
  /* Copy Constructor */
  Saturator_with_bounds_inputs(Saturator_with_bounds_inputs const&) = delete;

  /* Assignment Operator */
  Saturator_with_bounds_inputs& operator= (Saturator_with_bounds_inputs const&)
    & = delete;

  /* Move Constructor */
  Saturator_with_bounds_inputs(Saturator_with_bounds_inputs &&) = delete;

  /* Move Assignment Operator */
  Saturator_with_bounds_inputs& operator= (Saturator_with_bounds_inputs &&) =
    delete;

  /* Real-Time Model get method */
  RT_MODEL_Saturator_with_bound_T * getRTM();

  /* Root inports set method */
  void setExternalInputs(const ExtU_Saturator_with_bounds_in_T
    *pExtU_Saturator_with_bounds_in_T)
  {
    Saturator_with_bounds_inputs_U = *pExtU_Saturator_with_bounds_in_T;
  }

  /* Root outports get method */
  const ExtY_Saturator_with_bounds_in_T &getExternalOutputs() const
  {
    return Saturator_with_bounds_inputs_Y;
  }

  /* Initial conditions function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  static void terminate();

  /* Constructor */
  Saturator_with_bounds_inputs();

  /* Destructor */
  ~Saturator_with_bounds_inputs();

  /* private data and function members */
 private:
  /* External inputs */
  ExtU_Saturator_with_bounds_in_T Saturator_with_bounds_inputs_U;

  /* External outputs */
  ExtY_Saturator_with_bounds_in_T Saturator_with_bounds_inputs_Y;

  /* Real-Time Model */
  RT_MODEL_Saturator_with_bound_T Saturator_with_bounds_inputs_M;
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
 * '<Root>' : 'Saturator_with_bounds_inputs'
 * '<S1>'   : 'Saturator_with_bounds_inputs/Saturator With Bounds Inputs'
 */
#endif                                 /* Saturator_with_bounds_inputs_h_ */

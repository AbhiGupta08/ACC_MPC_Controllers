/*
 * AEB_FdFwd_Deccel.h
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

#ifndef AEB_FdFwd_Deccel_h_
#define AEB_FdFwd_Deccel_h_
#include <cmath>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "AEB_FdFwd_Deccel_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with default storage) */
struct ExtU_AEB_FdFwd_Deccel_T {
  real_T RelativeVelocityms;           /* '<Root>/Relative Velocity (m//s)' */
  real_T PreviewTimeforDeccels;       /* '<Root>/Preview Time for Deccel (s)' */
  real_T RelativeVelocityThresholdms;
                               /* '<Root>/Relative Velocity Threshold (m//s)' */
};

/* External outputs (root outports fed by signals with default storage) */
struct ExtY_AEB_FdFwd_Deccel_T {
  real_T AEBFeedForwardDeccelms2;  /* '<Root>/AEB FeedForward Deccel (m//s2)' */
};

/* Real-time Model Data Structure */
struct tag_RTM_AEB_FdFwd_Deccel_T {
  const char_T *errorStatus;
};

/* Class declaration for model AEB_FdFwd_Deccel */
class AEB_FdFwd_Deccel final
{
  /* public data and function members */
 public:
  /* Copy Constructor */
  AEB_FdFwd_Deccel(AEB_FdFwd_Deccel const&) = delete;

  /* Assignment Operator */
  AEB_FdFwd_Deccel& operator= (AEB_FdFwd_Deccel const&) & = delete;

  /* Move Constructor */
  AEB_FdFwd_Deccel(AEB_FdFwd_Deccel &&) = delete;

  /* Move Assignment Operator */
  AEB_FdFwd_Deccel& operator= (AEB_FdFwd_Deccel &&) = delete;

  /* Real-Time Model get method */
  RT_MODEL_AEB_FdFwd_Deccel_T * getRTM();

  /* Root inports set method */
  void setExternalInputs(const ExtU_AEB_FdFwd_Deccel_T *pExtU_AEB_FdFwd_Deccel_T)
  {
    AEB_FdFwd_Deccel_U = *pExtU_AEB_FdFwd_Deccel_T;
  }

  /* Root outports get method */
  const ExtY_AEB_FdFwd_Deccel_T &getExternalOutputs() const
  {
    return AEB_FdFwd_Deccel_Y;
  }

  /* Initial conditions function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  static void terminate();

  /* Constructor */
  AEB_FdFwd_Deccel();

  /* Destructor */
  ~AEB_FdFwd_Deccel();

  /* private data and function members */
 private:
  /* External inputs */
  ExtU_AEB_FdFwd_Deccel_T AEB_FdFwd_Deccel_U;

  /* External outputs */
  ExtY_AEB_FdFwd_Deccel_T AEB_FdFwd_Deccel_Y;

  /* Real-Time Model */
  RT_MODEL_AEB_FdFwd_Deccel_T AEB_FdFwd_Deccel_M;
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
 * '<Root>' : 'AEB_FdFwd_Deccel'
 * '<S1>'   : 'AEB_FdFwd_Deccel/AEB Feedforward Compensator'
 */
#endif                                 /* AEB_FdFwd_Deccel_h_ */

/*
 * Set_Spd_Fdfwd_Deccel.h
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

#ifndef Set_Spd_Fdfwd_Deccel_h_
#define Set_Spd_Fdfwd_Deccel_h_
#include <cmath>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "Set_Spd_Fdfwd_Deccel_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with default storage) */
struct ExtU_Set_Spd_Fdfwd_Deccel_T {
  real_T SetSpeedTargetms;             /* '<Root>/Set Speed Target (m//s)' */
  real_T HostVelocityms;               /* '<Root>/Host Velocity (m//s)' */
  real_T PreviewTimeforDeccels;       /* '<Root>/Preview Time for Deccel (s)' */
};

/* External outputs (root outports fed by signals with default storage) */
struct ExtY_Set_Spd_Fdfwd_Deccel_T {
  real_T SetSpeedFeedForwardDeccelms2;
                             /* '<Root>/Set Speed FeedForward Deccel (m//s2)' */
  real_T SetSpeederrorms;              /* '<Root>/Set Speed error (m//s)' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Set_Spd_Fdfwd_Deccel_T {
  const char_T *errorStatus;
};

/* Class declaration for model Set_Spd_Fdfwd_Deccel */
class Set_Spd_Fdfwd_Deccel final
{
  /* public data and function members */
 public:
  /* Copy Constructor */
  Set_Spd_Fdfwd_Deccel(Set_Spd_Fdfwd_Deccel const&) = delete;

  /* Assignment Operator */
  Set_Spd_Fdfwd_Deccel& operator= (Set_Spd_Fdfwd_Deccel const&) & = delete;

  /* Move Constructor */
  Set_Spd_Fdfwd_Deccel(Set_Spd_Fdfwd_Deccel &&) = delete;

  /* Move Assignment Operator */
  Set_Spd_Fdfwd_Deccel& operator= (Set_Spd_Fdfwd_Deccel &&) = delete;

  /* Real-Time Model get method */
  RT_MODEL_Set_Spd_Fdfwd_Deccel_T * getRTM();

  /* Root inports set method */
  void setExternalInputs(const ExtU_Set_Spd_Fdfwd_Deccel_T
    *pExtU_Set_Spd_Fdfwd_Deccel_T)
  {
    Set_Spd_Fdfwd_Deccel_U = *pExtU_Set_Spd_Fdfwd_Deccel_T;
  }

  /* Root outports get method */
  const ExtY_Set_Spd_Fdfwd_Deccel_T &getExternalOutputs() const
  {
    return Set_Spd_Fdfwd_Deccel_Y;
  }

  /* Initial conditions function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  static void terminate();

  /* Constructor */
  Set_Spd_Fdfwd_Deccel();

  /* Destructor */
  ~Set_Spd_Fdfwd_Deccel();

  /* private data and function members */
 private:
  /* External inputs */
  ExtU_Set_Spd_Fdfwd_Deccel_T Set_Spd_Fdfwd_Deccel_U;

  /* External outputs */
  ExtY_Set_Spd_Fdfwd_Deccel_T Set_Spd_Fdfwd_Deccel_Y;

  /* Real-Time Model */
  RT_MODEL_Set_Spd_Fdfwd_Deccel_T Set_Spd_Fdfwd_Deccel_M;
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
 * '<Root>' : 'Set_Spd_Fdfwd_Deccel'
 * '<S1>'   : 'Set_Spd_Fdfwd_Deccel/Set Speed Match Feedforward'
 */
#endif                                 /* Set_Spd_Fdfwd_Deccel_h_ */

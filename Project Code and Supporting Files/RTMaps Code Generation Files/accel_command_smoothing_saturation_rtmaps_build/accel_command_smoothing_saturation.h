/*
 * accel_command_smoothing_saturation.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "accel_command_smoothing_saturation".
 *
 * Model version              : 1.4
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Fri Jan  9 11:02:52 2026
 *
 * Target selection: rtmaps.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef accel_command_smoothing_saturation_h_
#define accel_command_smoothing_saturation_h_
#include <cmath>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "accel_command_smoothing_saturation_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#define accel_command_smoothing_saturation_M (accel_command_smoothing_satu_M)

/* Block states (default storage) for system '<Root>' */
struct DW_accel_command_smoothing_sa_T {
  real_T u_k_minus_1;       /* '<Root>/acceleration smoothing and saturation' */
};

/* External inputs (root inport signals with default storage) */
struct ExtU_accel_command_smoothing__T {
  real_T rho_weight;                   /* '<Root>/rho_weight' */
  real_T JerkMaxLimms3;                /* '<Root>/Jerk Max Lim (m//s3)' */
  real_T SampleTimesteps;              /* '<Root>/Sample Timestep (s)' */
  real_T AccelerationMaxms2;           /* '<Root>/Acceleration Max (m//s2)' */
  real_T AccelerationMinms2;           /* '<Root>/Acceleration Min (m//s2)' */
  real_T SetSpeedTargetms;             /* '<Root>/Set Speed Target (m//s)' */
  real_T DesiredTotalAccelms2;        /* '<Root>/Desired Total Accel (m//s2)' */
  real_T HostVelocityms;               /* '<Root>/Host Velocity (m//s)' */
};

/* External outputs (root outports fed by signals with default storage) */
struct ExtY_accel_command_smoothing__T {
  real_T FinalAccelerationCommandms2;
                               /* '<Root>/Final Acceleration Command (m//s2)' */
};

/* Real-time Model Data Structure */
struct tag_RTM_accel_command_smoothi_T {
  const char_T *errorStatus;
};

/* Class declaration for model accel_command_smoothing_saturation */
class accel_command_smoothing_saturation final
{
  /* public data and function members */
 public:
  /* Copy Constructor */
  accel_command_smoothing_saturation(accel_command_smoothing_saturation const&) =
    delete;

  /* Assignment Operator */
  accel_command_smoothing_saturation& operator=
    (accel_command_smoothing_saturation const&) & = delete;

  /* Move Constructor */
  accel_command_smoothing_saturation(accel_command_smoothing_saturation &&) =
    delete;

  /* Move Assignment Operator */
  accel_command_smoothing_saturation& operator=
    (accel_command_smoothing_saturation &&) = delete;

  /* Real-Time Model get method */
  RT_MODEL_accel_command_smooth_T * getRTM();

  /* Root inports set method */
  void setExternalInputs(const ExtU_accel_command_smoothing__T
    *pExtU_accel_command_smoothing__T)
  {
    accel_command_smoothing_satur_U = *pExtU_accel_command_smoothing__T;
  }

  /* Root outports get method */
  const ExtY_accel_command_smoothing__T &getExternalOutputs() const
  {
    return accel_command_smoothing_satur_Y;
  }

  /* Initial conditions function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  static void terminate();

  /* Constructor */
  accel_command_smoothing_saturation();

  /* Destructor */
  ~accel_command_smoothing_saturation();

  /* private data and function members */
 private:
  /* External inputs */
  ExtU_accel_command_smoothing__T accel_command_smoothing_satur_U;

  /* External outputs */
  ExtY_accel_command_smoothing__T accel_command_smoothing_satur_Y;

  /* Block states */
  DW_accel_command_smoothing_sa_T accel_command_smoothing_satu_DW;

  /* Real-Time Model */
  RT_MODEL_accel_command_smooth_T accel_command_smoothing_satu_M;
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
 * '<Root>' : 'accel_command_smoothing_saturation'
 * '<S1>'   : 'accel_command_smoothing_saturation/acceleration smoothing and saturation'
 */
#endif                               /* accel_command_smoothing_saturation_h_ */

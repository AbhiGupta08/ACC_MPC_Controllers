/*
 * LQR_Desired_Command_Accel.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "LQR_Desired_Command_Accel".
 *
 * Model version              : 1.1
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Fri Jan  9 06:47:03 2026
 *
 * Target selection: rtmaps.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef LQR_Desired_Command_Accel_h_
#define LQR_Desired_Command_Accel_h_
#include <cmath>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "LQR_Desired_Command_Accel_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with default storage) */
struct ExtU_LQR_Desired_Command_Acce_T {
  real_T FollowingDistanceErrorm;    /* '<Root>/Following Distance Error (m)' */
  real_T RelativeVelocityms;           /* '<Root>/Relative Velocity (m//s)' */
  real_T K_dist_err;                   /* '<Root>/K_dist_err' */
  real_T K_rel_velocity;               /* '<Root>/K_rel_velocity' */
};

/* External outputs (root outports fed by signals with default storage) */
struct ExtY_LQR_Desired_Command_Acce_T {
  real_T LQRAccelerationms2;           /* '<Root>/LQR Acceleration (m//s2)' */
};

/* Real-time Model Data Structure */
struct tag_RTM_LQR_Desired_Command_A_T {
  const char_T *errorStatus;
};

/* Class declaration for model LQR_Desired_Command_Accel */
class LQR_Desired_Command_Accel final
{
  /* public data and function members */
 public:
  /* Copy Constructor */
  LQR_Desired_Command_Accel(LQR_Desired_Command_Accel const&) = delete;

  /* Assignment Operator */
  LQR_Desired_Command_Accel& operator= (LQR_Desired_Command_Accel const&) & =
    delete;

  /* Move Constructor */
  LQR_Desired_Command_Accel(LQR_Desired_Command_Accel &&) = delete;

  /* Move Assignment Operator */
  LQR_Desired_Command_Accel& operator= (LQR_Desired_Command_Accel &&) = delete;

  /* Real-Time Model get method */
  RT_MODEL_LQR_Desired_Command__T * getRTM();

  /* Root inports set method */
  void setExternalInputs(const ExtU_LQR_Desired_Command_Acce_T
    *pExtU_LQR_Desired_Command_Acce_T)
  {
    LQR_Desired_Command_Accel_U = *pExtU_LQR_Desired_Command_Acce_T;
  }

  /* Root outports get method */
  const ExtY_LQR_Desired_Command_Acce_T &getExternalOutputs() const
  {
    return LQR_Desired_Command_Accel_Y;
  }

  /* Initial conditions function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  static void terminate();

  /* Constructor */
  LQR_Desired_Command_Accel();

  /* Destructor */
  ~LQR_Desired_Command_Accel();

  /* private data and function members */
 private:
  /* External inputs */
  ExtU_LQR_Desired_Command_Acce_T LQR_Desired_Command_Accel_U;

  /* External outputs */
  ExtY_LQR_Desired_Command_Acce_T LQR_Desired_Command_Accel_Y;

  /* Real-Time Model */
  RT_MODEL_LQR_Desired_Command__T LQR_Desired_Command_Accel_M;
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
 * '<Root>' : 'LQR_Desired_Command_Accel'
 * '<S1>'   : 'LQR_Desired_Command_Accel/LQR Block'
 */
#endif                                 /* LQR_Desired_Command_Accel_h_ */

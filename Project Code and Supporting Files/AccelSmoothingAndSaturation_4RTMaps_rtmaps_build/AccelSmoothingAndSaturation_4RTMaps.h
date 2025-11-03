/*
 * AccelSmoothingAndSaturation_4RTMaps.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "AccelSmoothingAndSaturation_4RTMaps".
 *
 * Model version              : 1.1
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Mon Nov  3 11:55:26 2025
 *
 * Target selection: rtmaps.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef AccelSmoothingAndSaturation_4RTMaps_h_
#define AccelSmoothingAndSaturation_4RTMaps_h_
#include <cmath>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "AccelSmoothingAndSaturation_4RTMaps_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#define AccelSmoothingAndSaturation_4RTMaps_M (AccelSmoothingAndSaturation__M)

/* External inputs (root inport signals with default storage) */
struct ExtU_AccelSmoothingAndSaturat_T {
  real_T rho;                          /* '<Root>/rho' */
  real_T JerkMax;                      /* '<Root>/JerkMax' */
  real_T TimeStep;                     /* '<Root>/TimeStep' */
  real_T AccelMax;                     /* '<Root>/AccelMax' */
  real_T AccelMin;                     /* '<Root>/AccelMin' */
  real_T DriverSetSpeed;               /* '<Root>/DriverSetSpeed' */
  real_T u_LQR;                        /* '<Root>/u_LQR' */
  real_T HostVelocity;                 /* '<Root>/HostVelocity' */
  real_T u_k_minus_1;                  /* '<Root>/u_k_minus_1' */
};

/* External outputs (root outports fed by signals with default storage) */
struct ExtY_AccelSmoothingAndSaturat_T {
  real_T u_cmd;                        /* '<Root>/u_cmd' */
};

/* Real-time Model Data Structure */
struct tag_RTM_AccelSmoothingAndSatu_T {
  const char_T *errorStatus;
};

/* Class declaration for model AccelSmoothingAndSaturation_4RTMaps */
class AccelSmoothingAndSaturation_4RTMaps final
{
  /* public data and function members */
 public:
  /* Copy Constructor */
  AccelSmoothingAndSaturation_4RTMaps(AccelSmoothingAndSaturation_4RTMaps const&)
    = delete;

  /* Assignment Operator */
  AccelSmoothingAndSaturation_4RTMaps& operator=
    (AccelSmoothingAndSaturation_4RTMaps const&) & = delete;

  /* Move Constructor */
  AccelSmoothingAndSaturation_4RTMaps(AccelSmoothingAndSaturation_4RTMaps &&) =
    delete;

  /* Move Assignment Operator */
  AccelSmoothingAndSaturation_4RTMaps& operator=
    (AccelSmoothingAndSaturation_4RTMaps &&) = delete;

  /* Real-Time Model get method */
  RT_MODEL_AccelSmoothingAndSat_T * getRTM();

  /* Root inports set method */
  void setExternalInputs(const ExtU_AccelSmoothingAndSaturat_T
    *pExtU_AccelSmoothingAndSaturat_T)
  {
    AccelSmoothingAndSaturation_4_U = *pExtU_AccelSmoothingAndSaturat_T;
  }

  /* Root outports get method */
  const ExtY_AccelSmoothingAndSaturat_T &getExternalOutputs() const
  {
    return AccelSmoothingAndSaturation_4_Y;
  }

  /* Initial conditions function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  static void terminate();

  /* Constructor */
  AccelSmoothingAndSaturation_4RTMaps();

  /* Destructor */
  ~AccelSmoothingAndSaturation_4RTMaps();

  /* private data and function members */
 private:
  /* External inputs */
  ExtU_AccelSmoothingAndSaturat_T AccelSmoothingAndSaturation_4_U;

  /* External outputs */
  ExtY_AccelSmoothingAndSaturat_T AccelSmoothingAndSaturation_4_Y;

  /* Real-Time Model */
  RT_MODEL_AccelSmoothingAndSat_T AccelSmoothingAndSaturation__M;
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
 * '<Root>' : 'AccelSmoothingAndSaturation_4RTMaps'
 * '<S1>'   : 'AccelSmoothingAndSaturation_4RTMaps/acceleration smoothing and saturation'
 */
#endif                              /* AccelSmoothingAndSaturation_4RTMaps_h_ */

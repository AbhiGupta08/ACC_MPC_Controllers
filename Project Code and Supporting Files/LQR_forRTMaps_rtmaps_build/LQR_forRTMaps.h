/*
 * LQR_forRTMaps.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "LQR_forRTMaps".
 *
 * Model version              : 1.4
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Fri Oct 31 11:58:19 2025
 *
 * Target selection: rtmaps.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef LQR_forRTMaps_h_
#define LQR_forRTMaps_h_
#include <cmath>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "LQR_forRTMaps_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with default storage) */
struct ExtU_LQR_forRTMaps_T {
  real_T relative_spd;                 /* '<Root>/Inport' */
  real_T foll_dist_err;                /* '<Root>/Inport1' */
  real_T K_derr;                       /* '<Root>/Inport2' */
  real_T K_vh;                         /* '<Root>/Inport3' */
};

/* External outputs (root outports fed by signals with default storage) */
struct ExtY_LQR_forRTMaps_T {
  real_T Outport;                      /* '<Root>/Outport' */
};

/* Real-time Model Data Structure */
struct tag_RTM_LQR_forRTMaps_T {
  const char_T *errorStatus;
};

/* Class declaration for model LQR_forRTMaps */
class LQR_forRTMaps final
{
  /* public data and function members */
 public:
  /* Copy Constructor */
  LQR_forRTMaps(LQR_forRTMaps const&) = delete;

  /* Assignment Operator */
  LQR_forRTMaps& operator= (LQR_forRTMaps const&) & = delete;

  /* Move Constructor */
  LQR_forRTMaps(LQR_forRTMaps &&) = delete;

  /* Move Assignment Operator */
  LQR_forRTMaps& operator= (LQR_forRTMaps &&) = delete;

  /* Real-Time Model get method */
  RT_MODEL_LQR_forRTMaps_T * getRTM();

  /* Root inports set method */
  void setExternalInputs(const ExtU_LQR_forRTMaps_T *pExtU_LQR_forRTMaps_T)
  {
    LQR_forRTMaps_U = *pExtU_LQR_forRTMaps_T;
  }

  /* Root outports get method */
  const ExtY_LQR_forRTMaps_T &getExternalOutputs() const
  {
    return LQR_forRTMaps_Y;
  }

  /* Initial conditions function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  static void terminate();

  /* Constructor */
  LQR_forRTMaps();

  /* Destructor */
  ~LQR_forRTMaps();

  /* private data and function members */
 private:
  /* External inputs */
  ExtU_LQR_forRTMaps_T LQR_forRTMaps_U;

  /* External outputs */
  ExtY_LQR_forRTMaps_T LQR_forRTMaps_Y;

  /* Real-Time Model */
  RT_MODEL_LQR_forRTMaps_T LQR_forRTMaps_M;
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
 * '<Root>' : 'LQR_forRTMaps'
 * '<S1>'   : 'LQR_forRTMaps/LQR Block'
 */
#endif                                 /* LQR_forRTMaps_h_ */

/*
 * LQR_forRTMaps10ms.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "LQR_forRTMaps10ms".
 *
 * Model version              : 1.5
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Fri Oct 31 12:11:31 2025
 *
 * Target selection: rtmaps.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef LQR_forRTMaps10ms_h_
#define LQR_forRTMaps10ms_h_
#include <cmath>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "LQR_forRTMaps10ms_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with default storage) */
struct ExtU_LQR_forRTMaps10ms_T {
  real_T relative_spd;                 /* '<Root>/Inport' */
  real_T foll_dist_err;                /* '<Root>/Inport1' */
  real_T K_derr;                       /* '<Root>/Inport2' */
  real_T K_vh;                         /* '<Root>/Inport3' */
};

/* External outputs (root outports fed by signals with default storage) */
struct ExtY_LQR_forRTMaps10ms_T {
  real_T Outport;                      /* '<Root>/Outport' */
};

/* Real-time Model Data Structure */
struct tag_RTM_LQR_forRTMaps10ms_T {
  const char_T *errorStatus;
};

/* Class declaration for model LQR_forRTMaps10ms */
class LQR_forRTMaps10ms final
{
  /* public data and function members */
 public:
  /* Copy Constructor */
  LQR_forRTMaps10ms(LQR_forRTMaps10ms const&) = delete;

  /* Assignment Operator */
  LQR_forRTMaps10ms& operator= (LQR_forRTMaps10ms const&) & = delete;

  /* Move Constructor */
  LQR_forRTMaps10ms(LQR_forRTMaps10ms &&) = delete;

  /* Move Assignment Operator */
  LQR_forRTMaps10ms& operator= (LQR_forRTMaps10ms &&) = delete;

  /* Real-Time Model get method */
  RT_MODEL_LQR_forRTMaps10ms_T * getRTM();

  /* Root inports set method */
  void setExternalInputs(const ExtU_LQR_forRTMaps10ms_T
    *pExtU_LQR_forRTMaps10ms_T)
  {
    LQR_forRTMaps10ms_U = *pExtU_LQR_forRTMaps10ms_T;
  }

  /* Root outports get method */
  const ExtY_LQR_forRTMaps10ms_T &getExternalOutputs() const
  {
    return LQR_forRTMaps10ms_Y;
  }

  /* Initial conditions function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  static void terminate();

  /* Constructor */
  LQR_forRTMaps10ms();

  /* Destructor */
  ~LQR_forRTMaps10ms();

  /* private data and function members */
 private:
  /* External inputs */
  ExtU_LQR_forRTMaps10ms_T LQR_forRTMaps10ms_U;

  /* External outputs */
  ExtY_LQR_forRTMaps10ms_T LQR_forRTMaps10ms_Y;

  /* Real-Time Model */
  RT_MODEL_LQR_forRTMaps10ms_T LQR_forRTMaps10ms_M;
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
 * '<Root>' : 'LQR_forRTMaps10ms'
 * '<S1>'   : 'LQR_forRTMaps10ms/LQR Block'
 */
#endif                                 /* LQR_forRTMaps10ms_h_ */

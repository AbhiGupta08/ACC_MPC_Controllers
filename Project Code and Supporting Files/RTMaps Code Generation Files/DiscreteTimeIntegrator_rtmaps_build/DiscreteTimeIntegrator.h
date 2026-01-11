/*
 * DiscreteTimeIntegrator.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "DiscreteTimeIntegrator".
 *
 * Model version              : 1.3
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Sat Jan 10 17:20:06 2026
 *
 * Target selection: rtmaps.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef DiscreteTimeIntegrator_h_
#define DiscreteTimeIntegrator_h_
#include <cmath>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "DiscreteTimeIntegrator_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
struct DW_DiscreteTimeIntegrator_T {
  real_T DiscreteIntegrator_DSTATE;    /* '<Root>/Discrete Integrator' */
};

/* External inputs (root inport signals with default storage) */
struct ExtU_DiscreteTimeIntegrator_T {
  real_T IntegratorIn;                 /* '<Root>/Integrator In' */
};

/* External outputs (root outports fed by signals with default storage) */
struct ExtY_DiscreteTimeIntegrator_T {
  real_T IntegratorOut;                /* '<Root>/Integrator Out' */
};

/* Parameters (default storage) */
struct P_DiscreteTimeIntegrator_T_ {
  real_T DiscreteIntegrator_gainval;
                               /* Computed Parameter: DiscreteIntegrator_gainval
                                * Referenced by: '<Root>/Discrete Integrator'
                                */
  real_T DiscreteIntegrator_IC;        /* Expression: 0
                                        * Referenced by: '<Root>/Discrete Integrator'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_DiscreteTimeIntegrato_T {
  const char_T *errorStatus;
};

/* Class declaration for model DiscreteTimeIntegrator */
class DiscreteTimeIntegrator final
{
  /* public data and function members */
 public:
  /* Copy Constructor */
  DiscreteTimeIntegrator(DiscreteTimeIntegrator const&) = delete;

  /* Assignment Operator */
  DiscreteTimeIntegrator& operator= (DiscreteTimeIntegrator const&) & = delete;

  /* Move Constructor */
  DiscreteTimeIntegrator(DiscreteTimeIntegrator &&) = delete;

  /* Move Assignment Operator */
  DiscreteTimeIntegrator& operator= (DiscreteTimeIntegrator &&) = delete;

  /* Real-Time Model get method */
  RT_MODEL_DiscreteTimeIntegrat_T * getRTM();

  /* Tunable parameters */
  static P_DiscreteTimeIntegrator_T DiscreteTimeIntegrator_P;

  /* Root inports set method */
  void setExternalInputs(const ExtU_DiscreteTimeIntegrator_T
    *pExtU_DiscreteTimeIntegrator_T)
  {
    DiscreteTimeIntegrator_U = *pExtU_DiscreteTimeIntegrator_T;
  }

  /* Root outports get method */
  const ExtY_DiscreteTimeIntegrator_T &getExternalOutputs() const
  {
    return DiscreteTimeIntegrator_Y;
  }

  /* Initial conditions function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  static void terminate();

  /* Constructor */
  DiscreteTimeIntegrator();

  /* Destructor */
  ~DiscreteTimeIntegrator();

  /* private data and function members */
 private:
  /* External inputs */
  ExtU_DiscreteTimeIntegrator_T DiscreteTimeIntegrator_U;

  /* External outputs */
  ExtY_DiscreteTimeIntegrator_T DiscreteTimeIntegrator_Y;

  /* Block states */
  DW_DiscreteTimeIntegrator_T DiscreteTimeIntegrator_DW;

  /* Real-Time Model */
  RT_MODEL_DiscreteTimeIntegrat_T DiscreteTimeIntegrator_M;
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
 * '<Root>' : 'DiscreteTimeIntegrator'
 */
#endif                                 /* DiscreteTimeIntegrator_h_ */

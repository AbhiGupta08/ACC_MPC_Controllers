/*
 * DiscreteTimeDerivative.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "DiscreteTimeDerivative".
 *
 * Model version              : 1.1
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Sun Jan 11 14:27:45 2026
 *
 * Target selection: rtmaps.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef DiscreteTimeDerivative_h_
#define DiscreteTimeDerivative_h_
#include <cmath>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "DiscreteTimeDerivative_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
struct DW_DiscreteTimeDerivative_T {
  real_T UD_DSTATE;                    /* '<S1>/UD' */
};

/* External inputs (root inport signals with default storage) */
struct ExtU_DiscreteTimeDerivative_T {
  real_T DerivativeInput;              /* '<Root>/Derivative Input' */
};

/* External outputs (root outports fed by signals with default storage) */
struct ExtY_DiscreteTimeDerivative_T {
  real_T DerivativeOutput;             /* '<Root>/Derivative Output' */
};

/* Parameters (default storage) */
struct P_DiscreteTimeDerivative_T_ {
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S1>/UD'
                               */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S1>/TSamp'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_DiscreteTimeDerivativ_T {
  const char_T *errorStatus;
};

/* Class declaration for model DiscreteTimeDerivative */
class DiscreteTimeDerivative final
{
  /* public data and function members */
 public:
  /* Copy Constructor */
  DiscreteTimeDerivative(DiscreteTimeDerivative const&) = delete;

  /* Assignment Operator */
  DiscreteTimeDerivative& operator= (DiscreteTimeDerivative const&) & = delete;

  /* Move Constructor */
  DiscreteTimeDerivative(DiscreteTimeDerivative &&) = delete;

  /* Move Assignment Operator */
  DiscreteTimeDerivative& operator= (DiscreteTimeDerivative &&) = delete;

  /* Real-Time Model get method */
  RT_MODEL_DiscreteTimeDerivati_T * getRTM();

  /* Tunable parameters */
  static P_DiscreteTimeDerivative_T DiscreteTimeDerivative_P;

  /* Root inports set method */
  void setExternalInputs(const ExtU_DiscreteTimeDerivative_T
    *pExtU_DiscreteTimeDerivative_T)
  {
    DiscreteTimeDerivative_U = *pExtU_DiscreteTimeDerivative_T;
  }

  /* Root outports get method */
  const ExtY_DiscreteTimeDerivative_T &getExternalOutputs() const
  {
    return DiscreteTimeDerivative_Y;
  }

  /* Initial conditions function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  static void terminate();

  /* Constructor */
  DiscreteTimeDerivative();

  /* Destructor */
  ~DiscreteTimeDerivative();

  /* private data and function members */
 private:
  /* External inputs */
  ExtU_DiscreteTimeDerivative_T DiscreteTimeDerivative_U;

  /* External outputs */
  ExtY_DiscreteTimeDerivative_T DiscreteTimeDerivative_Y;

  /* Block states */
  DW_DiscreteTimeDerivative_T DiscreteTimeDerivative_DW;

  /* Real-Time Model */
  RT_MODEL_DiscreteTimeDerivati_T DiscreteTimeDerivative_M;
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
 * '<Root>' : 'DiscreteTimeDerivative'
 * '<S1>'   : 'DiscreteTimeDerivative/ Discrete Derivative'
 */
#endif                                 /* DiscreteTimeDerivative_h_ */

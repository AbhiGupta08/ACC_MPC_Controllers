/*
 * Add3Elements.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Add3Elements".
 *
 * Model version              : 1.1
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Fri Jan  9 11:07:02 2026
 *
 * Target selection: rtmaps.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Add3Elements_h_
#define Add3Elements_h_
#include <cmath>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "Add3Elements_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with default storage) */
struct ExtU_Add3Elements_T {
  real_T Inport;                       /* '<Root>/Inport' */
  real_T Inport1;                      /* '<Root>/Inport1' */
  real_T Inport2;                      /* '<Root>/Inport2' */
};

/* External outputs (root outports fed by signals with default storage) */
struct ExtY_Add3Elements_T {
  real_T TotalDesiredAccelerationms2;
                               /* '<Root>/Total Desired Acceleration (m//s2)' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Add3Elements_T {
  const char_T *errorStatus;
};

/* Class declaration for model Add3Elements */
class Add3Elements final
{
  /* public data and function members */
 public:
  /* Copy Constructor */
  Add3Elements(Add3Elements const&) = delete;

  /* Assignment Operator */
  Add3Elements& operator= (Add3Elements const&) & = delete;

  /* Move Constructor */
  Add3Elements(Add3Elements &&) = delete;

  /* Move Assignment Operator */
  Add3Elements& operator= (Add3Elements &&) = delete;

  /* Real-Time Model get method */
  RT_MODEL_Add3Elements_T * getRTM();

  /* Root inports set method */
  void setExternalInputs(const ExtU_Add3Elements_T *pExtU_Add3Elements_T)
  {
    Add3Elements_U = *pExtU_Add3Elements_T;
  }

  /* Root outports get method */
  const ExtY_Add3Elements_T &getExternalOutputs() const
  {
    return Add3Elements_Y;
  }

  /* Initial conditions function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  static void terminate();

  /* Constructor */
  Add3Elements();

  /* Destructor */
  ~Add3Elements();

  /* private data and function members */
 private:
  /* External inputs */
  ExtU_Add3Elements_T Add3Elements_U;

  /* External outputs */
  ExtY_Add3Elements_T Add3Elements_Y;

  /* Real-Time Model */
  RT_MODEL_Add3Elements_T Add3Elements_M;
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
 * '<Root>' : 'Add3Elements'
 */
#endif                                 /* Add3Elements_h_ */

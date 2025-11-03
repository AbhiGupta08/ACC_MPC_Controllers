/*
 * AccelSmoothingAndSaturation_4RTMaps.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "AccelSmoothingAndSaturation_4RTMaps".
 *
 * Model version              : 1.4
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Mon Nov  3 17:53:28 2025
 *
 * Target selection: rtmaps.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AccelSmoothingAndSaturation_4RTMaps.h"
#include <cmath>
#include "rtwtypes.h"

/* Model step function */
void AccelSmoothingAndSaturation_4RTMaps::step()
{
  real_T rtb_u_cmd;

  /* MATLAB Function: '<Root>/acceleration smoothing and saturation' incorporates:
   *  Inport: '<Root>/AccelMax'
   *  Inport: '<Root>/AccelMin'
   *  Inport: '<Root>/DriverSetSpeed'
   *  Inport: '<Root>/HostVelocity'
   *  Inport: '<Root>/JerkMax'
   *  Inport: '<Root>/TimeStep'
   *  Inport: '<Root>/rho'
   *  Inport: '<Root>/u_LQR'
   *  Inport: '<Root>/u_k_minus_1'
   */
  rtb_u_cmd = AccelSmoothingAndSaturation_4_U.JerkMax *
    AccelSmoothingAndSaturation_4_U.TimeStep;
  rtb_u_cmd = std::fmin(std::fmax(std::fmin(std::fmax
    ((AccelSmoothingAndSaturation_4_U.rho *
      AccelSmoothingAndSaturation_4_U.u_k_minus_1 +
      AccelSmoothingAndSaturation_4_U.u_LQR) /
     (AccelSmoothingAndSaturation_4_U.rho + 1.0),
     AccelSmoothingAndSaturation_4_U.u_k_minus_1 - rtb_u_cmd), rtb_u_cmd +
    AccelSmoothingAndSaturation_4_U.u_k_minus_1),
    AccelSmoothingAndSaturation_4_U.AccelMin),
                        AccelSmoothingAndSaturation_4_U.AccelMax);
  if ((AccelSmoothingAndSaturation_4_U.HostVelocity <= 0.001) && (rtb_u_cmd <
       0.0)) {
    rtb_u_cmd = 0.0;
  } else if ((AccelSmoothingAndSaturation_4_U.HostVelocity >=
              AccelSmoothingAndSaturation_4_U.DriverSetSpeed) && (rtb_u_cmd >
              0.0)) {
    rtb_u_cmd = std::exp(-AccelSmoothingAndSaturation_4_U.TimeStep / 0.5);
    rtb_u_cmd = (1.0 - rtb_u_cmd) * 0.0 + rtb_u_cmd *
      AccelSmoothingAndSaturation_4_U.u_k_minus_1;
  }

  /* End of MATLAB Function: '<Root>/acceleration smoothing and saturation' */

  /* Outport: '<Root>/u_cmd' */
  AccelSmoothingAndSaturation_4_Y.u_cmd = rtb_u_cmd;
}

/* Model initialize function */
void AccelSmoothingAndSaturation_4RTMaps::initialize()
{
  /* (no initialization code required) */
}

/* Model terminate function */
void AccelSmoothingAndSaturation_4RTMaps::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
AccelSmoothingAndSaturation_4RTMaps::AccelSmoothingAndSaturation_4RTMaps() :
  AccelSmoothingAndSaturation_4_U(),
  AccelSmoothingAndSaturation_4_Y(),
  AccelSmoothingAndSaturation__M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
/* Currently there is no destructor body generated.*/
AccelSmoothingAndSaturation_4RTMaps::~AccelSmoothingAndSaturation_4RTMaps() =
  default;

/* Real-Time Model get method */
RT_MODEL_AccelSmoothingAndSat_T * AccelSmoothingAndSaturation_4RTMaps::getRTM()
{
  return (&AccelSmoothingAndSaturation__M);
}

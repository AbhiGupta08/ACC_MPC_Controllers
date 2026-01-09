/*
 * accel_command_smoothing_saturation.cpp
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

#include "accel_command_smoothing_saturation.h"
#include <cmath>
#include "rtwtypes.h"

/* Model step function */
void accel_command_smoothing_saturation::step()
{
  real_T rtb_u_cmd;
  real_T rtb_u_cmd_tmp;
  real_T rtb_u_cmd_tmp_0;

  /* MATLAB Function: '<Root>/acceleration smoothing and saturation' incorporates:
   *  Inport: '<Root>/Acceleration Max (m//s2)'
   *  Inport: '<Root>/Acceleration Min (m//s2)'
   *  Inport: '<Root>/Desired Total Accel (m//s2)'
   *  Inport: '<Root>/Host Velocity (m//s)'
   *  Inport: '<Root>/Jerk Max Lim (m//s3)'
   *  Inport: '<Root>/Sample Timestep (s)'
   *  Inport: '<Root>/Set Speed Target (m//s)'
   *  Inport: '<Root>/rho_weight'
   */
  rtb_u_cmd_tmp = accel_command_smoothing_satur_U.JerkMaxLimms3 *
    accel_command_smoothing_satur_U.SampleTimesteps;
  rtb_u_cmd_tmp_0 = accel_command_smoothing_satu_DW.u_k_minus_1 - rtb_u_cmd_tmp;
  rtb_u_cmd_tmp += accel_command_smoothing_satu_DW.u_k_minus_1;
  rtb_u_cmd = std::fmin(std::fmax(std::fmin(std::fmax
    ((accel_command_smoothing_satur_U.rho_weight *
      accel_command_smoothing_satu_DW.u_k_minus_1 +
      accel_command_smoothing_satur_U.DesiredTotalAccelms2) /
     (accel_command_smoothing_satur_U.rho_weight + 1.0), rtb_u_cmd_tmp_0),
    rtb_u_cmd_tmp), accel_command_smoothing_satur_U.AccelerationMinms2),
                        accel_command_smoothing_satur_U.AccelerationMaxms2);
  if ((accel_command_smoothing_satur_U.HostVelocityms <= 0.001) && (rtb_u_cmd <
       0.0)) {
    rtb_u_cmd = 0.0;
    accel_command_smoothing_satu_DW.u_k_minus_1 = 0.0;
  } else if ((accel_command_smoothing_satur_U.HostVelocityms >=
              accel_command_smoothing_satur_U.SetSpeedTargetms - 0.5) &&
             (rtb_u_cmd >= 0.0)) {
    rtb_u_cmd = std::fmin(std::fmax(0.0, rtb_u_cmd_tmp_0), rtb_u_cmd_tmp);
    accel_command_smoothing_satu_DW.u_k_minus_1 = rtb_u_cmd;
  } else {
    accel_command_smoothing_satu_DW.u_k_minus_1 = rtb_u_cmd;
  }

  /* End of MATLAB Function: '<Root>/acceleration smoothing and saturation' */

  /* Outport: '<Root>/Final Acceleration Command (m//s2)' */
  accel_command_smoothing_satur_Y.FinalAccelerationCommandms2 = rtb_u_cmd;
}

/* Model initialize function */
void accel_command_smoothing_saturation::initialize()
{
  /* (no initialization code required) */
}

/* Model terminate function */
void accel_command_smoothing_saturation::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
accel_command_smoothing_saturation::accel_command_smoothing_saturation() :
  accel_command_smoothing_satur_U(),
  accel_command_smoothing_satur_Y(),
  accel_command_smoothing_satu_DW(),
  accel_command_smoothing_satu_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
/* Currently there is no destructor body generated.*/
accel_command_smoothing_saturation::~accel_command_smoothing_saturation() =
  default;

/* Real-Time Model get method */
RT_MODEL_accel_command_smooth_T * accel_command_smoothing_saturation::getRTM()
{
  return (&accel_command_smoothing_satu_M);
}

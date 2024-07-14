#include "PID.h"

PID Motor1_PID;
PID Motor2_PID;
PID Sensor_PID;

/**
 * @brief  PID初始化
 *	@note 	无
 * @retval 无
 */
void PID_Param_Init(void) {

  // ---------------------- SENSOR_PID ----------------------------------
  Sensor_PID.target_val = 0;
  Sensor_PID.output_val = 0.0;
  Sensor_PID.Error = 0.0;
  Sensor_PID.LastError = 0.0;
  Sensor_PID.integral = 0.0;

  Sensor_PID.Kp = 12;
  Sensor_PID.Ki = 0;
  Sensor_PID.Kd = 0;
  //   Sensor_PID.Kp = 0.6;
  //   Sensor_PID.Ki = 0;
  //   Sensor_PID.Kd = 0;

  // ---------------------- MOTOR1_PID ----------------------------------
  Motor1_PID.target_val = 60;
  Motor1_PID.output_val = 0.0;
  Motor1_PID.Error = 0.0;
  Motor1_PID.LastError = 0.0;
  Motor1_PID.integral = 0.0;

  Motor1_PID.Kp = 0.0001;
  // addPID.Ki = 0.0065;
  Motor1_PID.Ki = 0.083;
  Motor1_PID.Kd = 0.0;

  // ---------------------- MOTOR2_PID ----------------------------------
  Motor2_PID.target_val = 60;
  Motor2_PID.output_val = 0.0;
  Motor2_PID.Error = 0.0;
  Motor2_PID.LastError = 0.0;
  Motor2_PID.integral = 0.0;

  Motor2_PID.Kp = 0.0001;
  // 2ddPID.Ki = 0.0065;
  Motor2_PID.Ki = 0.083;
  Motor2_PID.Kd = 0;
}

void Clear_Params(PID *pid) {
  pid -> target_val = 0;
  pid -> output_val = 0.0;
  pid -> Error = 0.0;
  pid -> LastError = 0.0;
  pid -> integral = 0.0;

  pid -> Kp = 0;
  pid -> Ki = 0;
  pid -> Kd = 0;
}

/**
 * @brief  设置目标值
 * @param  val 目标值
 *	@note 	无
 * @retval 无
 */
void set_PID_target(PID *pid, float temp_val) { pid->target_val = temp_val; }

/**
 * @brief  获取目标值
 * @param  无
 *	@note 	无
 * @retval 目标值
 */
float get_pid_target(PID *pid) { return pid->target_val; }

/**
 * @brief  设置比例、积分、微分系数
 * @param  p 比例系数 p
 * @param  i 积分系数 i
 * @param  d 微分 d
 *	@note 	ÎÞ
 * @retval ÎÞ
 */
void set_PID(PID *pid, float p, float i, float d) {
  pid->Kp = p;
  pid->Ki = i;
  pid->Kd = d;
}
/**
 * @brief  速度(增量)PID
 * @param  actual_val:实际值
 *	@note 	无
 * @retval 算出后的值
 */
float addPID_realize(PID *pid, float actual_val) {

  //   actual_val = myabs(actual_val);

  pid->Error = pid->target_val - actual_val;

  pid->output_val +=
      pid->Kp * (pid->Error - pid->LastError) + pid->Ki * pid->Error +
      pid->Kd * (pid->Error - 2 * pid->LastError + pid->PrevError);

  pid->PrevError = pid->LastError;
  pid->LastError = pid->Error;

  if (pid->output_val > 5000)
    pid->output_val = 5000;
  if (pid->output_val < 0)
    pid->output_val = 0;

  return pid->output_val;
}

/**
 * @brief  位置PID
 * @param  actual_val:实际值
 *	@note 	无
 * @retval 算出后的值
 */
float PosionPID_realize(PID *pid, float actual_val) {
  pid->Error = pid->target_val - actual_val;
//   pid->Error = actual_val;

  pid->integral += pid->Error;

  if (pid->integral > 600)
    pid->integral = 1200 - 1;
  if (pid->integral < -600)
    pid->integral = -1200 - 1;

  pid->output_val = pid->Kp * pid->Error + pid->Ki * pid->integral +
                    pid->Kd * (pid->Error - pid->LastError);
  pid->LastError = pid->Error;

  return pid->output_val;
}

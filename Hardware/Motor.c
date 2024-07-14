#include "Motor.h"

/**
 * =============== 定义区域 ============
 */
uint8_t Speed_Range_Handle(int32_t Speed);
uint32_t myabs(int32_t a);

/**
 * =============== END =============
 */

/**
 * @brief  电机初始化
 * @return void
 */
void Motor_Init(void) {
//   DL_TimerG_startCounter(PWM_34_INST);
  DL_TimerG_startCounter(PWM_12_INST);
  DL_TimerG_startCounter(PWM_34_INST);

  DL_GPIO_setPins(Motor_PORT, Motor_Motor_1_PIN);
  DL_GPIO_setPins(Motor_PORT, Motor_Motor_2_PIN);
  DL_GPIO_setPins(Motor_PORT, Motor_Motor_3_PIN);
  DL_GPIO_setPins(Motor_PORT, Motor_Motor_4_PIN);

  // NVIC_EnableIRQ(PWM_0_INST_INT_IRQN);
}

/**
 * @brief  电机1设置速度
 * @param  Speed 速度
 * @return void
 */
void Motor1_SetSpeed(int32_t Speed) {
  if (Speed > 0) {
    DL_GPIO_setPins(Motor_PORT, Motor_Motor_1_PIN);
  } else if (Speed < 0) {
    DL_GPIO_clearPins(Motor_PORT, Motor_Motor_1_PIN);
  }

  DL_TimerG_setCaptureCompareValue(PWM_12_INST, Speed_Range_Handle(Speed),
                                   GPIO_PWM_34_C1_IDX);
}

/**
 * @brief  电机2设置速度
 * @param  Speed 速度
 * @return void
 */
void Motor2_SetSpeed(int32_t Speed) {
  if (Speed > 0) {
    DL_GPIO_setPins(Motor_PORT, Motor_Motor_2_PIN);
  } else if (Speed < 0) {
    DL_GPIO_clearPins(Motor_PORT, Motor_Motor_2_PIN);
  }

  DL_TimerG_setCaptureCompareValue(PWM_12_INST, Speed_Range_Handle(Speed),
                                   GPIO_PWM_34_C0_IDX);
}

/**
 * @brief  电机3设置速度
 * @param  Speed 速度
 * @return void
 */
void Motor3_SetSpeed(int32_t Speed) {
  if (Speed > 0) {
    DL_GPIO_setPins(Motor_PORT, Motor_Motor_3_PIN);
  } else if (Speed < 0) {
    DL_GPIO_clearPins(Motor_PORT, Motor_Motor_3_PIN);
  }

  DL_TimerG_setCaptureCompareValue(PWM_34_INST, Speed_Range_Handle(Speed),
                                   GPIO_PWM_12_C1_IDX);
}

/**
 * @brief  电机4设置速度
 * @param  Speed 速度
 * @return void
 */
void Motor4_SetSpeed(int32_t Speed) {
  if (Speed > 0) {
    DL_GPIO_setPins(Motor_PORT, Motor_Motor_4_PIN);
  } else if (Speed < 0) {
    DL_GPIO_clearPins(Motor_PORT, Motor_Motor_4_PIN);
  }

  DL_TimerG_setCaptureCompareValue(PWM_34_INST, Speed_Range_Handle(Speed),
                                   GPIO_PWM_12_C0_IDX);
}

/**
 * @brief  电机速度范围
 * @param  Speed 速度
 * @return 速度
 */
uint8_t Speed_Range_Handle(int32_t val) {
  uint32_t Speed = myabs(val);
  if (Speed >= MAX_SPEED) {
    return 1;
  } else if (Speed <= 0) {
    return 90;
  }

  return 100 - Speed;
}

uint32_t myabs(int32_t a) {
  uint32_t temp;
  if (a < 0)
    temp = -a;
  else
    temp = a;
  return temp;
}

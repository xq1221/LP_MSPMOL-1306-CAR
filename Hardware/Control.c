#include "Control.h"
#include "Hardware/PID.h"
#include "Hardware/Sensor.h"
#include "System/Delay.h"

volatile int32_t freq = 0;
volatile int32_t freq2 = 0;
volatile float APWM = 0;
volatile float BPWM = 0;
volatile float SPWM = 0;
volatile float speed = 0;
volatile int DefaultPWML = 0;
volatile int DefaultPWMR = 0;
volatile int32_t Total_ERROR = 0;
volatile char Turn_Flag = 0;
volatile int32_t Distance = 0;

extern int32_t gCaptureCnt1;
extern int32_t gCaptureCnt2;

// ---------------- 函数定义区域 -------------------------
float Get_Velocity_Form_Encoder(int32_t encoder);
void Conditional_Judgment(void);
void Straight(int Speed);
void PID_Straight(int Speed, int PWM);
void Turn_Left_90(void);
void Turn_Right_90(void);
void Stop(void);
// ------------------- END ------------------------------

/**
 * @brief   PID 速度控制
 * @param   None
 * @return  None
 */
void PID_Control(void) {
  //   int total = 0;
  //   int i;
  //   for (i = 0; i < 8; i++) {
  //     if (sensor[i] == 1) {
  //       total++;
  //     }
  //   }
  // ---------------------------  -------------------------
  freq = Encoder_Get_Freq();
  freq2 = Encoder_Get_Freq2();
  gCaptureCnt1 = 0;
  gCaptureCnt2 = 0;
  // speed = Get_Velocity_Form_Encoder(freq);
  // Total_ERROR += freq;

  //   if (SPWM > 25) {
  //     SPWM = 25;
  //   } else if (SPWM < -25) {
  //     SPWM = -25;
  //   }

  APWM = addPID_realize(&Motor1_PID, freq);
  BPWM = addPID_realize(&Motor2_PID, freq2);

  //   Motor1_SetSpeed(DefaultPWML - SPWM);
  //   Motor2_SetSpeed(DefaultPWMR + SPWM);
  //   Motor3_SetSpeed(DefaultPWML - SPWM);
  //   Motor4_SetSpeed(DefaultPWMR + SPWM);
  //   Conditional_Judgment();
}

void Conditional_Judgment(void) {
  read_sensor_values();

//   Total_ERROR += error;

  SPWM = PosionPID_realize(&Sensor_PID, error);
  // 在中间
  if (decide == 1) {
    if (Turn_Flag == 0) {
      PID_Straight(75, SPWM);
    }
  }
  // 直角转弯
//   else if (decide == 2 || decide == 3 || decide == 4 || decide == 5) {
//     Turn_Flag = 1;
//     Clear_Params(&Sensor_PID);
//     Total_ERROR = 0;
//     delay_ms(220);
//     Turn_Left_90();
//     delay_ms(1500);
//     PID_Param_Init();
//     PID_Straight(75, SPWM);
//     decide = 1;
//     Turn_Flag = 0;
//   } 
//   else if (decide == 20 && Turn_Flag == 0) {
//     Clear_Params(&Sensor_PID);
//     Total_ERROR = 0;
//     Stop();
//   }
}

/**
 * @brief  PID直行
 * @param Speed 直行速度
 * @param PWM 灰度传感器偏差
 * @retval : 无
 */
void Stop(void) {
  Motor1_SetSpeed(0);
  Motor2_SetSpeed(0);
  Motor3_SetSpeed(0);
  Motor4_SetSpeed(0);
}

/**
 * @brief  PID直行
 * @param Speed 直行速度
 * @param PWM 灰度传感器偏差
 * @retval : 无
 */
void PID_Straight(int Speed, int PWM) {
  Motor1_SetSpeed(Speed - PWM);
  Motor2_SetSpeed(Speed + PWM);
  Motor3_SetSpeed(Speed - PWM);
  Motor4_SetSpeed(Speed + PWM);
}

/**
 * @brief  直行
 * @param Speed 直行速度
 * @retval : 无
 */
void Straight(int Speed) {
  Motor1_SetSpeed(Speed);
  Motor2_SetSpeed(Speed);
  Motor3_SetSpeed(Speed);
  Motor4_SetSpeed(Speed);
}

/**
 * @brief  左转
 * @param 无
 * @retval : 无
 */
void Turn_Left_90(void) {
  Motor1_SetSpeed(-50);
  Motor2_SetSpeed(50);
  Motor3_SetSpeed(-50);
  Motor4_SetSpeed(50);
}

/**
 * @brief  右转
 * @param 无
 * @retval : 无
 */
void Turn_Right_90(void) {
  Motor1_SetSpeed(50);
  Motor2_SetSpeed(-50);
  Motor3_SetSpeed(50);
  Motor4_SetSpeed(-50);
}

/**
 * @brief  编码器读数转换为轮子速度（mm/s）
 * @param encoder：编码器计数
 * @retval : Velocity 轮子速度
 */
float Get_Velocity_Form_Encoder(int32_t encoder) {
  float Distance, Velocity;
  Distance = 2 * 3.14159 * 32.5 / (2 * 30 * 30); // 单位是mm
  Velocity =
      encoder * Distance / 0.1; // 单位是mm/s。0.1就是编码器计数周期100ms，0.1s

  return Velocity;
}

/**
 * @brief  编码器读数转换为路程
 * @param encoder：编码器总计数
 * @retval : 总距离 mm
 */
float Get_Distance_Form_Encoder(int32_t encoder) {
  float Distance, Velocity;
  Distance = 2 * 3.14159 * 32.5 / (2 * 30 * 30);
  return encoder * Distance;
}

void TIMER_0_INST_IRQHandler(void) {
  switch (DL_TimerG_getPendingInterrupt(TIMER_0_INST)) {
  case DL_TIMER_IIDX_ZERO:
    PID_Control();
    break;
  default:
    break;
  }
}

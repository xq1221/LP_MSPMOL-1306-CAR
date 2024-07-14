#ifndef __MOTOR_H
#define __MOTOR_H

#include "ti_msp_dl_config.h"
#include "./Hardware/OLED.h"

#define MAX_SPEED  100

void Motor_Init(void);
void Motor1_SetSpeed(int32_t Speed);
void Motor2_SetSpeed(int32_t Speed);
void Motor3_SetSpeed(int32_t Speed);
void Motor4_SetSpeed(int32_t Speed);
uint32_t myabs(int32_t a);

#endif

#ifndef __CONTROL_H
#define __CONTROL_H

#include "ti_msp_dl_config.h"
#include "./Motor.h"
#include "./PID.h"
#include "./Encoder.h"
#include "./Sensor.h"
#include "../System/Delay.h"
#include "../System/UART.h"


extern volatile char direction;

void PID_Control(void);
void Conditional_Judgment();

#endif

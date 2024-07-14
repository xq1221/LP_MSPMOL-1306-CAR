/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "./Hardware/Control.h"
#include "./Hardware/Encoder.h"
#include "./Hardware/HCSR04.h"
#include "./Hardware/Motor.h"
#include "./Hardware/OLED.h"
#include "./Hardware/PID.h"
#include "./Hardware/Sensor.h"
#include "./System/Delay.h"
#include "./System/UART.h"
#include "ti_msp_dl_config.h"
#include <string.h>

 extern volatile int32_t freq;
 extern volatile int32_t freq2;
 extern volatile float APWM;
 extern volatile float BPWM;
 extern volatile float SPWM;
 extern volatile float speed;
 extern volatile int32_t Total_ERROR;

int main(void) {
  SYSCFG_DL_init();

  UART_Init();
  OLED_Init();
  Encoder_Init();
  Motor_Init();
  PID_Param_Init();

  DL_TimerG_startCounter(TIMER_0_INST);
  NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);
  //   HCSR04_Init();

    // Motor1_SetSpeed(-40);

  OLED_ShowString(1, 1, "freq:");
  OLED_ShowString(2, 1, "error:");
  OLED_ShowString(3, 1, "SPWM:");

  while (1) {
    // ------------------------------- CAPTURE -------------------------------
    
    Conditional_Judgment();
    // Control();
    // PID_Control();
    UART_SendNumber(Total_ERROR, 3, UART_0_INST);
    UART_SendString("\r\n", UART_0_INST);
    OLED_ShowSignedNum(1, 7, freq, 3);
    OLED_ShowSignedNum(1, 12, freq2, 3);
    OLED_ShowSignedNum(2, 7, Total_ERROR, 5);
    // OLED_ShowSignedNum(3, 7, APWM , 6);
    OLED_ShowSignedNum(2, 13, SPWM, 3);
    OLED_ShowSignedNum(3, 1, Sensor_PID.Kp * 100, 3);
    OLED_ShowSignedNum(3, 6, error, 3);
    // OLED_ShowBinNum(4, 1, UART1_RxPacket, 8);
    OLED_ShowSignedNum(4, 2, Sensor_Deviation, 5);
    // OLED_ShowNum(1, 7, Encoder_Get_Freq(), 6);
    // OLED_ShowNum(2, 7, Encoder_Get_Freq2(), 6);

    // ------------------------------- UART -----------------------------------
    switch (UART_PID) {
        case 0x01: 
            Sensor_PID.Kp += 0.01;
            break;
        case 0x02: 
        Sensor_PID.Kp += 0.1;
            break;
        case 0x03: 
        Sensor_PID.Kp += 1;
            break;
        case 0x04: 
        Sensor_PID.Kp += 10;
            break;
        case 0x05: 
        Sensor_PID.Kd += 0.01;
            break;
        case 0x06: 
        Sensor_PID.Kd += 0.1;
            break;
        case 0x07: 
        Sensor_PID.Kd += 1;
            break;
        case 0x08: 
        Sensor_PID.Kd += 10;
            break;
    }
    // OLED_ShowString(2, 1, UART_RxPacket);
    // if (UART_RxFlag == 1) {

    //   /*将收到的数据包与预设的指令对比，以此决定将要执行的操作*/
    //   if (strcmp(UART_RxPacket, "ADD") == 0) // 如果收到LED_ON指令
    //   {
    //     UART_SendString("ADD_OK");
    //     Speed += 10;
    //     Motor1_SetSpeed(Speed);
    //     OLED_ShowString(2, 1, "                ");
    //     OLED_ShowString(2, 1, "ADD_OK"); // OLED清除指定位置，并显示LED_ON_OK
    //   }
    //   if (strcmp(UART_RxPacket, "DOWN") == 0) // 如果收到LED_ON指令
    //   {
    //     UART_SendString("DOWN_OK");
    //     Speed -= 10;
    //     Motor1_SetSpeed(Speed);
    //     OLED_ShowString(2, 1, "                ");
    //     OLED_ShowString(2, 1, "DOWN_OK"); //
    //     OLED清除指定位置，并显示LED_ON_OK
    //   }

    //   UART_RxFlag = 0;
    // }

    // --------------------------- HCSR04
    // ----------------------------------------- OLED_ShowNum(3, 1, Speed, 2);
    // OLED_ShowNum(4, 1, DL_Timer_getCaptureCompareValue(PWM12_INST,
    //                                GPIO_PWM12_C0_IDX), 2);

    // HCSR04_getValue();
    // OLED_ShowNum(3, 1, Time, 6);
    // OLED_ShowNum(4, 1,  ((Time * 0.0001) * 34000) / 2, 8);

    // OLED_ShowNum(4, 1,  HCSR04_getValue(), 8);

    // delay_ms(60);
  }
}





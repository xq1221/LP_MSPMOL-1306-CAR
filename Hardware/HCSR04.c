#include "../System/Delay.h"
#include "HCSR04.h"
#include "../Hardware/OLED.h"

uint16_t TimeCount = 0;

void HCSR04_Init(void) {
//   NVIC_EnableIRQ(HCSR04_Timer_INST_INT_IRQN);
//   DL_TimerG_startCounter(HCSR04_Timer_INST); // 开启计数
  DL_GPIO_clearPins(HCSR04_PORT, HCSR04_RX_PIN);
}

// void HCSR04_Start() {
//   DL_GPIO_setPins(HCSR04_PORT, HCSR04_TX_PIN);
// //   delay_ms(1);
//   DL_GPIO_clearPins(HCSR04_PORT, HCSR04_TX_PIN);
//   Time = 0;
// }

// uint16_t HCSR04_getValue(void) {
//   HCSR04_Start();
//   delay_ms(60);
// //   return Time;
//   return ((Time * 0.0001) * 34000) / 2;
// }

float HCSR04_getValue()
{
	float Distance, Distance_mm;
	uint32_t Time_end;
	
    DL_GPIO_setPins(HCSR04_PORT, HCSR04_TX_PIN);
	delay_ms(1);
    DL_GPIO_clearPins(HCSR04_PORT, HCSR04_TX_PIN);
	
    uint32_t val = DL_GPIO_readPins(HCSR04_PORT, HCSR04_RX_PIN);
    OLED_ShowHexNum(3, 1, val & 0x20000 ,    16);
    OLED_ShowNum(1, 1, val,    16);
    
    
	// while((DL_GPIO_readPins(HCSR04_PORT, HCSR04_RX_PIN) & 0x20000) == 0x00);
	TimeCount = 0;
	// while((DL_GPIO_readPins(HCSR04_PORT, HCSR04_RX_PIN) & 0x20000));
	Time_end = TimeCount * 10;
	
	if (Time_end < 24000)
	{
		Distance = Time_end * 0.000001f * 340 / 2;
		Distance_mm = Distance * 1000;
	}
	
	return Distance_mm;
}

// void HCSR04_Timer_INST_IRQHandler(void) {
//   switch (DL_TimerG_getPendingInterrupt(HCSR04_Timer_INST)) {
//   case DL_TIMER_IIDX_ZERO:
//     TimeCount++;
//     // DL_TimerG_startCounter(HCSR04_Timer_INST);
//     break;
//   default:
//     break;
//   }
// }



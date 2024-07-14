#include "Delay.h"

/**
 * @name 延时函数
 * @param uint32_t ms
 **/
void delay_ms(uint32_t ms) {
  while (ms) {
    ms--;
    delay_cycles(CPUCLK_FREQ / 1000);
  }

//   delay_cycles(16 000 000);
}

/**
 * @name 延时函数
 * @param uint32_t us
 **/
void delay_ns(uint32_t us) {
  while (us) {
    us--;
    delay_cycles(CPUCLK_FREQ / 1000000);
  }

//   delay_cycles(16000000);
}

// unsigned int utick = 0; // 滴答定时器中断计数

// void SysTick_Handler(void)
// {

//   SysTick->CTRL &= ~(1 << 16); /*清除滴答定时器中断标志位*/
//   utick++; // 滴答定时器中断计数
// }

// void delay_ms(unsigned int ms)
// {
//   unsigned int tick = utick;

//   while (utick < (tick + ms));
// }

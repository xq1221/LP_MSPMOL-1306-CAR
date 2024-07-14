#include "Encoder.h"

volatile uint32_t Encoder_Capture1;
volatile uint32_t Encoder_Capture2;

int32_t gLoadValue1;
volatile int32_t gCaptureCnt1;
volatile bool gSynced = true;

int32_t gLoadValue2;
volatile int32_t gCaptureCnt2;
volatile bool gSynced2 = true;

void Encoder_Init(void) {
// IO 口模拟
 NVIC_EnableIRQ(Encoder_Capture_INT_IRQN);

/** 
* 输入捕获通道
**/
//   gLoadValue = DL_TimerG_getLoadValue(Encoder_INST);
//   gLoadValue2 = DL_TimerG_getLoadValue(Encoder2_INST);
//   NVIC_EnableIRQ(Encoder_INST_INT_IRQN);
//   NVIC_EnableIRQ(Encoder2_INST_INT_IRQN);
//   DL_TimerG_startCounter(Encoder_INST);
//   DL_TimerG_startCounter(Encoder2_INST);
}

float Encoder_Get_Freq(void) {
//   if (gCaptureCnt == 0) {
//     return 0;
//   }
//   return 1000000 / (gLoadValue - gCaptureCnt + 1);
return gCaptureCnt1;
}
float Encoder_Get_Freq2(void) {
//     if (gCaptureCnt2 == 0) {
//     return 0;
//   }
//   return 500000 / (gLoadValue - gCaptureCnt2 + 1);
return gCaptureCnt2;
}


/**
*   捕获通道
**/
void GROUP1_IRQHandler(void)
{
    //获取中断信号
    Encoder_Capture1 = DL_GPIO_getEnabledInterruptStatus(Encoder_Capture_PORT,
    Encoder_Capture_Capture1_A_PIN | Encoder_Capture_Capture1_B_PIN );
    Encoder_Capture2 = DL_GPIO_getEnabledInterruptStatus(Encoder_Capture_PORT,
    Encoder_Capture_Capture2_A_PIN | Encoder_Capture_Capture2_B_PIN);
 
     //-------------------------- ENCODER_CAPTURE1 ---------------------------
    //如果是GPIO_EncoderA_PIN_0_PIN产生的中断
    if((Encoder_Capture1 & Encoder_Capture_Capture1_A_PIN) == Encoder_Capture_Capture1_A_PIN)
    {
        //Pin0上升沿，看Pin1的电平，为低电平则判断为反转，高电平判断为正转
        if(!DL_GPIO_readPins(Encoder_Capture_PORT,Encoder_Capture_Capture1_B_PIN))//P1为低电平
        {
            gCaptureCnt1--;
        }
        else//P1为高电平
        {
            gCaptureCnt1++;
        }
    }
    
    else if((Encoder_Capture1 & Encoder_Capture_Capture1_B_PIN) == Encoder_Capture_Capture1_B_PIN)
    {
        //Pin1上升沿
        if(!DL_GPIO_readPins(Encoder_Capture_PORT,Encoder_Capture_Capture1_A_PIN))//P0为低电平
        {
            gCaptureCnt1++;
        }
        else//P1为高电平
        {
            gCaptureCnt1--;
        }
    }

    //-------------------------- ENCODER_CAPTURE2 ---------------------------
    if((Encoder_Capture2 & Encoder_Capture_Capture2_A_PIN) == Encoder_Capture_Capture2_A_PIN)
    {
        if(!DL_GPIO_readPins(Encoder_Capture_PORT,Encoder_Capture_Capture2_B_PIN))//P1为低电平
        {
            gCaptureCnt2--;
        }
        else//P1为高电平
        {
            gCaptureCnt2++;
        }
    }
    
    else if((Encoder_Capture2 & Encoder_Capture_Capture2_B_PIN) == Encoder_Capture_Capture2_B_PIN)
    {

        if(!DL_GPIO_readPins(Encoder_Capture_PORT,Encoder_Capture_Capture2_A_PIN))//P0为低电平
        {
            gCaptureCnt2++;
        }
        else
        {
            gCaptureCnt2--;
        }
    }
    
    //最后清除中断标志位
    DL_GPIO_clearInterruptStatus(Encoder_Capture_PORT, Encoder_Capture_Capture1_A_PIN|Encoder_Capture_Capture1_B_PIN | Encoder_Capture_Capture2_A_PIN|Encoder_Capture_Capture2_B_PIN);
}

/**
*   捕获通道获取频率
**/

// void Encoder_INST_IRQHandler(void) {
//   switch (DL_TimerG_getPendingInterrupt(Encoder_INST)) {
//   case DL_TIMERG_IIDX_CC0_DN:
//     if (gSynced == true) {
//       gCaptureCnt =
//           DL_TimerG_getCaptureCompareValue(Encoder_INST, DL_TIMER_CC_0_INDEX);
//     } else {
//       gSynced = true;
//     }
//     DL_TimerG_setTimerCount(Encoder_INST, gLoadValue);
//     break;
//   case DL_TIMERG_IIDX_ZERO:
//     gSynced = false;

//     break;
//   default:
//     break;
//   }
// }

// void Encoder2_INST_IRQHandler(void) {
//   switch (DL_TimerG_getPendingInterrupt(Encoder2_INST)) {
//   case DL_TIMERG_IIDX_CC0_DN:
//     if (gSynced2 == true) {
//       gCaptureCnt2 =
//           DL_TimerG_getCaptureCompareValue(Encoder2_INST, DL_TIMER_CC_0_INDEX);
//     } else {
//       gSynced2 = true;
//     }
//     DL_TimerG_setTimerCount(Encoder2_INST, gLoadValue2);
//     break;
//   case DL_TIMERG_IIDX_ZERO:

//     gSynced2 = false;
//     break;
//   default:
//     break;
//   }
// }

// ------------------------------------- TWO ----------------------------------

// void Encoder_INST_IRQHandler(void) {
//   switch (DL_TimerG_getPendingInterrupt(Encoder_INST)) {
//   case DL_TIMERG_IIDX_CC0_DN:
//     if (gSynced == true) {

//       // DL_TimerG_setCaptureCompareValue(Encoder_INST, 0,
//       //                               DL_TIMER_CC_0_INDEX);
//       gCaptureCnt =
//           DL_TimerG_getCaptureCompareValue(Encoder_INST,
//           DL_TIMER_CC_0_INDEX);

//           DL_TimerG_setTimerCount(Encoder_INST, gLoadValue);

//       //   gSynced = false;
//       // gSynced2 = true;
//       //   b++;
//     }
//     /* Manual reload is needed to workaround timer capture limitation */
//     break;
//   case DL_TIMERG_IIDX_CC1_DN:
//     if (gSynced2 == true) {
//       gCaptureCnt2 =
//           DL_TimerG_getCaptureCompareValue(Encoder_INST,
//           DL_TIMER_CC_1_INDEX);

//           DL_TimerG_setTimerCount(Encoder_INST, gLoadValue);
//       //    a++;
//       //   DL_TimerG_setCaptureCompareValue(Encoder_INST, gLoadValue,
//       //                                   DL_TIMER_CC_1_INDEX);
//       // DL_TimerG_setTimerCount(Encoder_INST, gLoadValue);
//       // DL_TimerG_setTimerCount(Encoder_INST, gLoadValue);
//       // gSynced2 = false;
//       // gSynced = true;
//     }
//     /* Manual reload is needed to workaround timer capture limitation */
//     break;
//   case DL_TIMERG_IIDX_ZERO:
//     /* If Timer reaches zero then no PWM signal is detected and it
//      * requires re-synchronization
//      */
//     gSynced = false;
//     break;
//   default:
//     break;
//   }
// }

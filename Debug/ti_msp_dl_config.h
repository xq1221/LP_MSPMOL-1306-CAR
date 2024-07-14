/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
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

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0L130X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0L130X

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     32000000



/* Defines for PWM_12 */
#define PWM_12_INST                                                        TIMG0
#define PWM_12_INST_IRQHandler                                  TIMG0_IRQHandler
#define PWM_12_INST_INT_IRQN                                    (TIMG0_INT_IRQn)
#define PWM_12_INST_CLK_FREQ                                             1000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_12_C0_PORT                                                GPIOA
#define GPIO_PWM_12_C0_PIN                                        DL_GPIO_PIN_12
#define GPIO_PWM_12_C0_IOMUX                                     (IOMUX_PINCM13)
#define GPIO_PWM_12_C0_IOMUX_FUNC                    IOMUX_PINCM13_PF_TIMG0_CCP0
#define GPIO_PWM_12_C0_IDX                                   DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_12_C1_PORT                                                GPIOA
#define GPIO_PWM_12_C1_PIN                                        DL_GPIO_PIN_13
#define GPIO_PWM_12_C1_IOMUX                                     (IOMUX_PINCM14)
#define GPIO_PWM_12_C1_IOMUX_FUNC                    IOMUX_PINCM14_PF_TIMG0_CCP1
#define GPIO_PWM_12_C1_IDX                                   DL_TIMER_CC_1_INDEX

/* Defines for PWM_34 */
#define PWM_34_INST                                                        TIMG1
#define PWM_34_INST_IRQHandler                                  TIMG1_IRQHandler
#define PWM_34_INST_INT_IRQN                                    (TIMG1_INT_IRQn)
#define PWM_34_INST_CLK_FREQ                                             1000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_34_C0_PORT                                                GPIOA
#define GPIO_PWM_34_C0_PIN                                        DL_GPIO_PIN_26
#define GPIO_PWM_34_C0_IOMUX                                     (IOMUX_PINCM27)
#define GPIO_PWM_34_C0_IOMUX_FUNC                    IOMUX_PINCM27_PF_TIMG1_CCP0
#define GPIO_PWM_34_C0_IDX                                   DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_34_C1_PORT                                                GPIOA
#define GPIO_PWM_34_C1_PIN                                        DL_GPIO_PIN_27
#define GPIO_PWM_34_C1_IOMUX                                     (IOMUX_PINCM28)
#define GPIO_PWM_34_C1_IOMUX_FUNC                    IOMUX_PINCM28_PF_TIMG1_CCP1
#define GPIO_PWM_34_C1_IDX                                   DL_TIMER_CC_1_INDEX



/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMG2)
#define TIMER_0_INST_IRQHandler                                 TIMG2_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMG2_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                          (1874U)




/* Defines for I2C_0 */
#define I2C_0_INST                                                          I2C0
#define I2C_0_INST_IRQHandler                                    I2C0_IRQHandler
#define I2C_0_INST_INT_IRQN                                        I2C0_INT_IRQn
#define I2C_0_BUS_SPEED_HZ                                                400000
#define GPIO_I2C_0_SDA_PORT                                                GPIOA
#define GPIO_I2C_0_SDA_PIN                                         DL_GPIO_PIN_0
#define GPIO_I2C_0_IOMUX_SDA                                      (IOMUX_PINCM1)
#define GPIO_I2C_0_IOMUX_SDA_FUNC                       IOMUX_PINCM1_PF_I2C0_SDA
#define GPIO_I2C_0_SCL_PORT                                                GPIOA
#define GPIO_I2C_0_SCL_PIN                                         DL_GPIO_PIN_1
#define GPIO_I2C_0_IOMUX_SCL                                      (IOMUX_PINCM2)
#define GPIO_I2C_0_IOMUX_SCL_FUNC                       IOMUX_PINCM2_PF_I2C0_SCL


/* Defines for UART_0 */
#define UART_0_INST                                                        UART0
#define UART_0_INST_IRQHandler                                  UART0_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART0_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOA
#define GPIO_UART_0_TX_PORT                                                GPIOA
#define GPIO_UART_0_RX_PIN                                         DL_GPIO_PIN_9
#define GPIO_UART_0_TX_PIN                                         DL_GPIO_PIN_8
#define GPIO_UART_0_IOMUX_RX                                     (IOMUX_PINCM10)
#define GPIO_UART_0_IOMUX_TX                                      (IOMUX_PINCM9)
#define GPIO_UART_0_IOMUX_RX_FUNC                      IOMUX_PINCM10_PF_UART0_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                       IOMUX_PINCM9_PF_UART0_TX
#define UART_0_BAUD_RATE                                                  (9600)
#define UART_0_IBRD_32_MHZ_9600_BAUD                                       (208)
#define UART_0_FBRD_32_MHZ_9600_BAUD                                        (21)
/* Defines for UART_1 */
#define UART_1_INST                                                        UART1
#define UART_1_INST_IRQHandler                                  UART1_IRQHandler
#define UART_1_INST_INT_IRQN                                      UART1_INT_IRQn
#define GPIO_UART_1_RX_PORT                                                GPIOA
#define GPIO_UART_1_TX_PORT                                                GPIOA
#define GPIO_UART_1_RX_PIN                                        DL_GPIO_PIN_22
#define GPIO_UART_1_TX_PIN                                        DL_GPIO_PIN_23
#define GPIO_UART_1_IOMUX_RX                                     (IOMUX_PINCM23)
#define GPIO_UART_1_IOMUX_TX                                     (IOMUX_PINCM24)
#define GPIO_UART_1_IOMUX_RX_FUNC                      IOMUX_PINCM23_PF_UART1_RX
#define GPIO_UART_1_IOMUX_TX_FUNC                      IOMUX_PINCM24_PF_UART1_TX
#define UART_1_BAUD_RATE                                                  (9600)
#define UART_1_IBRD_32_MHZ_9600_BAUD                                       (208)
#define UART_1_FBRD_32_MHZ_9600_BAUD                                        (21)





/* Port definition for Pin Group Tracking */
#define Tracking_PORT                                                    (GPIOA)

/* Defines for PIN_0: GPIOA.14 with pinCMx 15 on package pin 18 */
#define Tracking_PIN_0_PIN                                      (DL_GPIO_PIN_14)
#define Tracking_PIN_0_IOMUX                                     (IOMUX_PINCM15)
/* Port definition for Pin Group HCSR04 */
#define HCSR04_PORT                                                      (GPIOA)

/* Defines for TX: GPIOA.6 with pinCMx 7 on package pin 10 */
#define HCSR04_TX_PIN                                            (DL_GPIO_PIN_6)
#define HCSR04_TX_IOMUX                                           (IOMUX_PINCM7)
/* Defines for RX: GPIOA.2 with pinCMx 3 on package pin 6 */
#define HCSR04_RX_PIN                                            (DL_GPIO_PIN_2)
#define HCSR04_RX_IOMUX                                           (IOMUX_PINCM3)
/* Port definition for Pin Group Motor */
#define Motor_PORT                                                       (GPIOA)

/* Defines for Motor_1: GPIOA.5 with pinCMx 6 on package pin 9 */
#define Motor_Motor_1_PIN                                        (DL_GPIO_PIN_5)
#define Motor_Motor_1_IOMUX                                       (IOMUX_PINCM6)
/* Defines for Motor_2: GPIOA.4 with pinCMx 5 on package pin 8 */
#define Motor_Motor_2_PIN                                        (DL_GPIO_PIN_4)
#define Motor_Motor_2_IOMUX                                       (IOMUX_PINCM5)
/* Defines for Motor_3: GPIOA.7 with pinCMx 8 on package pin 11 */
#define Motor_Motor_3_PIN                                        (DL_GPIO_PIN_7)
#define Motor_Motor_3_IOMUX                                       (IOMUX_PINCM8)
/* Defines for Motor_4: GPIOA.3 with pinCMx 4 on package pin 7 */
#define Motor_Motor_4_PIN                                        (DL_GPIO_PIN_3)
#define Motor_Motor_4_IOMUX                                       (IOMUX_PINCM4)
/* Port definition for Pin Group Encoder_Capture */
#define Encoder_Capture_PORT                                             (GPIOA)

/* Defines for Capture1_A: GPIOA.21 with pinCMx 22 on package pin 25 */
// pins affected by this interrupt request:["Capture1_A","Capture1_B","Capture2_A","Capture2_B"]
#define Encoder_Capture_INT_IRQN                                (GPIOA_INT_IRQn)
#define Encoder_Capture_INT_IIDX                (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define Encoder_Capture_Capture1_A_IIDX                     (DL_GPIO_IIDX_DIO21)
#define Encoder_Capture_Capture1_A_PIN                          (DL_GPIO_PIN_21)
#define Encoder_Capture_Capture1_A_IOMUX                         (IOMUX_PINCM22)
/* Defines for Capture1_B: GPIOA.11 with pinCMx 12 on package pin 15 */
#define Encoder_Capture_Capture1_B_IIDX                     (DL_GPIO_IIDX_DIO11)
#define Encoder_Capture_Capture1_B_PIN                          (DL_GPIO_PIN_11)
#define Encoder_Capture_Capture1_B_IOMUX                         (IOMUX_PINCM12)
/* Defines for Capture2_A: GPIOA.10 with pinCMx 11 on package pin 14 */
#define Encoder_Capture_Capture2_A_IIDX                     (DL_GPIO_IIDX_DIO10)
#define Encoder_Capture_Capture2_A_PIN                          (DL_GPIO_PIN_10)
#define Encoder_Capture_Capture2_A_IOMUX                         (IOMUX_PINCM11)
/* Defines for Capture2_B: GPIOA.15 with pinCMx 16 on package pin 19 */
#define Encoder_Capture_Capture2_B_IIDX                     (DL_GPIO_IIDX_DIO15)
#define Encoder_Capture_Capture2_B_PIN                          (DL_GPIO_PIN_15)
#define Encoder_Capture_Capture2_B_IOMUX                         (IOMUX_PINCM16)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_12_init(void);
void SYSCFG_DL_PWM_34_init(void);
void SYSCFG_DL_TIMER_0_init(void);
void SYSCFG_DL_I2C_0_init(void);
void SYSCFG_DL_UART_0_init(void);
void SYSCFG_DL_UART_1_init(void);



#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */

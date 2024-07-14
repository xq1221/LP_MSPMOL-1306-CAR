#ifndef __UART_H
#define __UART_H

#include <stdio.h>
#include <stdarg.h>
#include "ti_msp_dl_config.h"

// ---- UART1 -----
extern volatile char UART_RxPacket[];
extern volatile char UART_PID;
extern volatile uint8_t UART_RxFlag;
// ---- UART2 -----
extern volatile char UART1_RxPacket;
extern volatile int Data_Index;

void UART_Init(void);
void UART_SendByte(uint8_t Byte, UART_Regs *uart);
void UART_SendArray(uint8_t *Array, uint16_t Length, UART_Regs *uart);
void UART_SendString(char *String, UART_Regs *uart);
void UART_SendNumber(uint32_t Number, uint8_t Length, UART_Regs *uart);

#endif
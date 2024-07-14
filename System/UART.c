#include "UART.h"
#include "ti_msp_dl_config.h"
#include <stdarg.h>
#include <stdio.h>

#define UART_PACKET_SIZE (100)

// ---- UART1 -----
volatile char UART_RxPacket[UART_PACKET_SIZE];
volatile char UART_PID;
volatile uint8_t UART_RxFlag = 0;
// ---- UART2 -----
volatile char UART1_RxPacket;
volatile int Data_Index;

/**
 * @brief  串口初始化
 * @return void
 */
void UART_Init() {
  NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);
  NVIC_EnableIRQ(UART_0_INST_INT_IRQN);
  NVIC_ClearPendingIRQ(UART_1_INST_INT_IRQN);
  NVIC_EnableIRQ(UART_1_INST_INT_IRQN);
}

/**
 * @brief：串口发送一个字节
 * @param：Byte 要发送的一个字节
 * @return：无
 */
void UART_SendByte(uint8_t Byte, UART_Regs *uart) {
  DL_UART_Main_transmitDataBlocking(uart, Byte);
}

/**
 * @brief：串口发送一个数组
 * @param：Array 要发送数组的首地址
 * @param：Length 要发送数组的长度
 * @return：无
 */
void UART_SendArray(uint8_t *Array, uint16_t Length, UART_Regs *uart) {
  uint16_t i;
  for (i = 0; i < Length; i++) // 遍历数组
  {
    UART_SendByte(Array[i], uart); // 依次调用UART_SendByte发送每个字节数据
  }
}

/**
 * @brief：串口发送一个字符串
 * @param：String 要发送字符串的首地址
 * @return：无
 */
void UART_SendString(char *String, UART_Regs *uart) {
  uint8_t i;
  for (i = 0; String[i] != '\0';
       i++) // 遍历字符数组（字符串），遇到字符串结束标志位后停止
  {
    UART_SendByte(String[i], uart); // 依次调用UART_SendByte发送每个字节数据
  }
}

/**
 * @brief：次方函数（内部使用）
 * @return：返回值等于X的Y次方
 */
uint32_t UART_Pow(uint32_t X, uint32_t Y) {
  uint32_t Result = 1; // 设置结果初值为1
  while (Y--)          // 执行Y次
  {
    Result *= X; // 将X累乘到结果
  }
  return Result;
}

/**
 * @brief：串口发送数字
 * @param：Number 要发送的数字，范围：0~4294967295
 * @param：Length 要发送数字的长度，范围：0~10
 * @return：无
 */
void UART_SendNumber(uint32_t Number, uint8_t Length, UART_Regs *uart) {
  uint8_t i;
  for (i = 0; i < Length; i++) // 根据数字长度遍历数字的每一位
  {
    UART_SendByte(Number / UART_Pow(10, Length - i - 1) % 10 + '0',
                  uart); // 依次调用UART_SendByte发送每位数字
  }
}

/**
 * 函    数：使用printf需要重定向的底层函数
 * 参    数：保持原始格式即可，无需变动
 * 返 回 值：保持原始格式即可，无需变动
 */
int fputc1(uint8_t ch, FILE *f, UART_Regs *uart) {
  UART_SendByte(ch, uart); // 将printf的底层重定向到自己的发送字节函数
  return ch;
}

/**
 * 函    数：自己封装的prinf函数
 * 参    数：format 格式化字符串
 * 参    数：... 可变的参数列表
 * 返 回 值：无
 */
void UART_Printf(char *format, ...) {
  char String[100];      // 定义字符数组
  va_list arg;           // 定义可变参数列表数据类型的变量arg
  va_start(arg, format); // 从format开始，接收参数列表到arg变量
  vsprintf(String, format,
           arg); // 使用vsprintf打印格式化字符串和参数列表到字符数组中
  va_end(arg); // 结束变量arg
  //   UART_SendString(String, uart); // 串口发送字符数组（字符串）
}

/**
 * @brief：USART1中断函数
 * @param：无
 * @return：无
 * 注意事项：此函数为中断函数，无需调用，中断触发后自动执行
 *           函数名为预留的指定名称，可以从启动文件复制
 *           请确保函数名正确，不能有任何差异，否则中断函数将不能进入
 */
void DL_UART_MAIN_IIDX_RX_Handel() {
  static uint8_t RxState = 0; // 定义表示当前状态机状态的静态变量
  static uint8_t pRxPacket = 0; // 定义表示当前接收数据位置的静态变量

  //   uint8_t RxData = DL_UART_Main_receiveData(UART_0_INST);
  UART_PID = DL_UART_Main_receiveData(UART_0_INST);

  /*使用状态机的思路，依次处理数据包的不同部分*/

  /*当前状态为0，接收数据包包头*/
  //   if (RxState == 0) {
  //     if (RxData == '@' &&
  //         UART_RxFlag == 0) // 如果数据确实是包头，并且上一个数据包已处理完毕
  //     {
  //       RxState = 1;   // 置下一个状态
  //       pRxPacket = 0; // 数据包的位置归零
  //     }
  //   }
  //   /*当前状态为1，接收数据包数据，同时判断是否接收到了第一个包尾*/
  //   else if (RxState == 1) {
  //     if (RxData == '\r') // 如果收到第一个包尾
  //     {
  //       RxState = 2; // 置下一个状态
  //     } else         // 接收到了正常的数据
  //     {
  //       UART_RxPacket[pRxPacket] = RxData; // 将数据存入数据包数组的指定位置
  //       pRxPacket++;                       // 数据包的位置自增
  //     }
  //   }
  //   /*当前状态为2，接收数据包第二个包尾*/
  //   else if (RxState == 2) {
  //     if (RxData == '\n') // 如果收到第二个包尾
  //     {
  //       RxState = 0; // 状态归0
  //       UART_RxPacket[pRxPacket] =
  //           '\0'; // 将收到的字符数据包添加一个字符串结束标志
  //       UART_RxFlag = 1; // 接收数据包标志位置1，成功接收一个数据包
  //     }
  //   }
}

void DL_UART1_MAIN_IIDX_RX_Handel() {
  UART1_RxPacket = DL_UART_Main_receiveData(UART_1_INST);
}

void UART_0_INST_IRQHandler(void) {
  switch (DL_UART_Main_getPendingInterrupt(UART_0_INST)) {
  case DL_UART_MAIN_IIDX_RX:
    DL_UART_MAIN_IIDX_RX_Handel();
    break;
  default:
    break;
  }
}

void UART_1_INST_IRQHandler(void) {
  switch (DL_UART_Main_getPendingInterrupt(UART_1_INST)) {
  case DL_UART_MAIN_IIDX_RX:
    DL_UART1_MAIN_IIDX_RX_Handel();
    break;
  default:
    break;
  }
}
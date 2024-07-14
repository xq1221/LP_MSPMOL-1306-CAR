#include "Sensor.h"

int decide;
int error;
char sensor[8];
int16_t Sensor_Deviation = 0;

// void read_sensor_values(void) {
//   UART_SendByte(0x57, UART_1_INST);

//   Sensor_Deviation = UART1_RxPacket[1];
//   Sensor_Deviation <<= 8;
//   Sensor_Deviation = UART1_RxPacket[2];

//   if (UART1_RxPacket[0] == 0) {
//     Sensor_Deviation = -Sensor_Deviation;
//   }

//   Data_Index = 0;
// }

void read_sensor_values(void) {
    UART_SendByte(0x57, UART_1_INST);
    sensor[0] = (UART1_RxPacket & 0x01);
    sensor[1] = (UART1_RxPacket & 0x02) >> 1;
    sensor[2] = (UART1_RxPacket & 0x04) >> 2;
    sensor[3] = (UART1_RxPacket & 0x08) >> 3;
    sensor[4] = (UART1_RxPacket & 0x10) >> 4;
    sensor[5] = (UART1_RxPacket & 0x20) >> 5;
    sensor[6] = (UART1_RxPacket & 0x40) >> 6;
    sensor[7] = (UART1_RxPacket & 0x80) >> 7;

    if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) &&
        (sensor[3] == 1) && (sensor[4] == 1) && (sensor[5] == 1) &&
        (sensor[6] == 1) && (sensor[7] == 1)) {
        decide = 4; // 十字路口 1 1 1 1 1 1 1 1   直行
        error = 0;
    }
    else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 1) &&
        (sensor[3] == 1) && (sensor[4] == 1) && (sensor[5] == 1) &&
        (sensor[6] == 1) && (sensor[7] == 0)) {
        decide = 5; // 十字路口 0 1 1 1 1 1 1 0   直行
        error = 0;
    }
    else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) &&
             (sensor[3] == 1) && (sensor[4] == 1) && (sensor[5] == 1) &&
             (sensor[6] == 0) && (sensor[7] == 0)) {
        decide = 6; // 十字路口 0 0 1 1 1 1 0 0   直行
        error = 0;
    }
    else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) &&
             (sensor[3] == 1) && (sensor[4] == 1) && (sensor[5] == 0) &&
             (sensor[6] == 0) && (sensor[7] == 0)) {
        decide = 1; // 十字路口 0 0 0 1 1 0 0 0   直行
        error = 0;
    }
    else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) &&
             (sensor[3] == 0) && (sensor[4] == 1) && (sensor[5] == 1) &&
             (sensor[6] == 1) && (sensor[7] == 1)) {
        decide = 2; // 90度路口 0 0 0 0 1 1 1 1    右转90度
    }
    else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) &&
             (sensor[3] == 1) && (sensor[4] == 1) && (sensor[5] == 1) &&
             (sensor[6] == 1) && (sensor[7] == 1)) {
        decide = 2; // 90度路口 0 0 0 1 1 1 1 1    右转90度
    }
    else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) &&
             (sensor[3] == 1) && (sensor[4] == 0) && (sensor[5] == 0) &&
             (sensor[6] == 0) && (sensor[7] == 0)) {
        decide = 3; // 90度路口 1 1 1 1 0 0 0 0    左转90度
    }
    else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) &&
             (sensor[3] == 1) && (sensor[4] == 1) && (sensor[5] == 0) &&
             (sensor[6] == 0) && (sensor[7] == 0)) {
        decide = 3; // 向上锐角 1 1 1 1 1 0 0 0    向上锐角
    }
    else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) &&
             (sensor[3] == 0) && (sensor[4] == 0) && (sensor[5] == 0) &&
             (sensor[6] == 0) && (sensor[7] == 1)) {
        error = 4; //          0 0 0 0 0 0 0 1
    }
    else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) &&
             (sensor[3] == 0) && (sensor[4] == 0) && (sensor[5] == 0) &&
             (sensor[6] == 1) && (sensor[7] == 0)) {
        error = 3; //          0 0 0 0 0 0 1 0
    }
    else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) &&
             (sensor[3] == 0) && (sensor[4] == 0) && (sensor[5] == 1) &&
             (sensor[6] == 0) && (sensor[7] == 0)) {
        error = 2; //          0 0 0 0 0 1 0 0
    }
    else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) &&
             (sensor[3] == 0) && (sensor[4] == 1) && (sensor[5] == 0) &&
             (sensor[6] == 0) && (sensor[7] == 0)) {
        error = 1; //          0 0 0 0 1 0 0 0
    }
    else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) &&
             (sensor[3] == 1) && (sensor[4] == 1) && (sensor[5] == 0) &&
             (sensor[6] == 0) && (sensor[7] == 0)) {
        error = 0; //          0 0 0 1 1 0 0 0
    }
    else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) &&
             (sensor[3] == 1) && (sensor[4] == 0) && (sensor[5] == 0) &&
             (sensor[6] == 0) && (sensor[7] == 0)) {
        error = -1; //          0 0 0 1 0 0 0 0
    }
    else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) &&
             (sensor[3] == 0) && (sensor[4] == 0) && (sensor[5] == 0) &&
             (sensor[6] == 0) && (sensor[7] == 0)) {
        error = -2; //         0 0 1 0 0 0 0 0
    }
    else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 0) &&
             (sensor[3] == 0) && (sensor[4] == 0) && (sensor[5] == 0) &&
             (sensor[6] == 0) && (sensor[7] == 0)) {
        error = -3; //         0 1 0 0 0 0 0 0
    }
    else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) &&
             (sensor[3] == 0) && (sensor[4] == 0) && (sensor[5] == 0) &&
             (sensor[6] == 0) && (sensor[7] == 0)) {
        error = -4; //         1 0 0 0 0 0 0 0
    }
    else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) &&
             (sensor[3] == 0) && (sensor[4] == 0) && (sensor[5] == 0) &&
             (sensor[6] == 0) && (sensor[7] == 0)) {
        if (error < 0) {
            error = -5; //     0 0 0 0 0 0 0 0 (previously moving left)
        } else {
            error = 5;  //     0 0 0 0 0 0 0 0 (previously moving right or
        }
        decide = 20;
    }
}

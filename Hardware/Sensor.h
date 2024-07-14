#ifndef __SENSOR_H
#define	__SENSOR_H

#include "../System/UART.h"
#include "../Hardware/OLED.h"

extern int decide;
extern int error;
extern char sensor[];
extern int16_t Sensor_Deviation;

void read_sensor_values(void);


#endif

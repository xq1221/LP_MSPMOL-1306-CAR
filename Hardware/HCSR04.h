#ifndef __HCSR04_H
#define __HCSR04_H

#include "ti_msp_dl_config.h"

extern uint16_t TimeCount;

void HCSR04_Init(void) ;
float HCSR04_getValue(void);

#endif

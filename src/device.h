#ifndef  DEVICE_H
#define  DEVICE_H

#include "global.h"

void DEV_UartInit(void);
void DEV_DelayMs(U32 uiMs);

void DEV_SoftwareInit(void);
void DEV_HardwareInit(void);

#endif
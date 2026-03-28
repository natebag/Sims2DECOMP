#ifndef TIMER_H
#define TIMER_H

#include "types.h"

// Timer functions - from timer.obj
// These access SDA (r13-relative) globals for time/tick tracking

extern "C" {

// Returns frame delta time as float (SDA global at r13-0x6150)
float Timer_GetTime(void);

// Returns total elapsed time as float (SDA global at r13-0x614C)
float Timer_GetTotalTime(void);

// Returns frame tick count as int (SDA global at r13-0x6144)
int Timer_GetTicks(void);

// Returns total tick count as int (SDA global at r13-0x6140)
int Timer_GetTotalTicks(void);

}

#endif // TIMER_H

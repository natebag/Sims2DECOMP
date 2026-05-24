// FLAGS: -fno-schedule-insns
// 0x800770DC Timer_GetTotalTicks (8B)
// lwz r3,gTimerTotalTicks(r13)
extern int gTimerTotalTicks;
int Timer_GetTotalTicks() { return gTimerTotalTicks; }

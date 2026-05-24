// FLAGS: -fno-schedule-insns
// 0x800770D4 Timer_GetTicks (8B)
// lwz r3,gTimerTicks(r13)
extern int gTimerTicks;
int Timer_GetTicks() { return gTimerTicks; }

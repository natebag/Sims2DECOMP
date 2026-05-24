// FLAGS: -fno-schedule-insns
// 0x800770C4 Timer_GetTime (8B)
// lfs f1,gTimerTime(r13)
extern float gTimerTime;
float Timer_GetTime() { return gTimerTime; }

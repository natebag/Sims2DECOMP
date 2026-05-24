// FLAGS: -fno-schedule-insns
// 0x800770CC Timer_GetTotalTime (8B)
// lfs f1,gTimerTotalTime(r13)
extern float gTimerTotalTime;
float Timer_GetTotalTime() { return gTimerTotalTime; }

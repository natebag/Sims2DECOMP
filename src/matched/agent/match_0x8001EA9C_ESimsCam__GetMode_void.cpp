// 0x8001EA9C ESimsCam::GetMode(void) (8 B)
// FLAGS: -fno-schedule-insns
struct ESimsCam { char _pad[0x3cc]; int m_mode; int GetMode(); };
int ESimsCam::GetMode() { return m_mode; }

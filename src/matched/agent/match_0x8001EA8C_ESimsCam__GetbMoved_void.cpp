// 0x8001EA8C ESimsCam::GetbMoved(void) (8 B)
// FLAGS: -fno-schedule-insns
struct ESimsCam { char _pad[0x8]; int m_bMoved; int GetbMoved(); };
int ESimsCam::GetbMoved() { return m_bMoved; }

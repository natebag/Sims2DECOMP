// 0x8001EA94 ESimsCam::GetRotAng(void) (8 B)
// FLAGS: -fno-schedule-insns
struct ESimsCam { char _pad[0x44c]; float m_rotAng; float GetRotAng(); };
float ESimsCam::GetRotAng() { return m_rotAng; }

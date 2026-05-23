// 0x8001EA7C ESimsCam::GetTilt(void) (8 B)
// FLAGS: -fno-schedule-insns
struct ESimsCam { char _pad[0x450]; float m_tilt; float GetTilt(); };
float ESimsCam::GetTilt() { return m_tilt; }

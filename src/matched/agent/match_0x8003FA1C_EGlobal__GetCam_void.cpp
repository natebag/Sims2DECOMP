// 0x8003FA1C EGlobal::GetCam(void) (8 B)
struct EGlobal { char _pad[0xd0]; unsigned m_cam; unsigned GetCam(); };
unsigned EGlobal::GetCam() { return m_cam; }

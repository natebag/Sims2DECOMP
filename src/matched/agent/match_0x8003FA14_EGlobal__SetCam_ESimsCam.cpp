// 0x8003FA14 EGlobal::SetCam(ESimsCam (8 B)
struct EGlobal { char _pad[0xd0]; unsigned m_cam; void SetCam(unsigned); };
void EGlobal::SetCam(unsigned cam) { m_cam = cam; }

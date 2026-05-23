// 0x80030654 EIWallPart::SetForceFadeOff(bool) (8 B)
// FLAGS: -fno-schedule-insns
struct EIWallPart { char _pad[0x3b0]; unsigned m_forceFadeOff; void SetForceFadeOff(bool); };
void EIWallPart::SetForceFadeOff(bool flag) { m_forceFadeOff = flag; }

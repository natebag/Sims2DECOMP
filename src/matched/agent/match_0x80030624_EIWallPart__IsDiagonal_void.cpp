// 0x80030624 EIWallPart::IsDiagonal(void) (24 B)
// FLAGS: -fno-schedule-insns
struct EIWallPart { char _pad[0x320]; unsigned m_wallFlags; int IsDiagonal(); };
int EIWallPart::IsDiagonal() { return (m_wallFlags & 0x30) != 0; }

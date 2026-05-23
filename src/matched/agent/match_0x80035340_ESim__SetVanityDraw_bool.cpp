// 0x80035340 ESim::SetVanityDraw(bool, (12 B)
// FLAGS: -fno-schedule-insns
struct ESim { char _pad[0x3d4]; unsigned m_vanityObj; unsigned m_pad3d8; unsigned m_vanityMode; void SetVanityDraw(unsigned, unsigned); };
void ESim::SetVanityDraw(unsigned p1, unsigned p2) { m_vanityObj = p2; m_vanityMode = p1; }

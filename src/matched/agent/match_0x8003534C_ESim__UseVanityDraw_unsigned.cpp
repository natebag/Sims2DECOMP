// 0x8003534C ESim::UseVanityDraw(unsigned (16 B)
// FLAGS: -fno-schedule-insns
struct ESim { char _pad[0x3d4]; unsigned m_vanityObj; unsigned m_pad3d8; unsigned m_vanityMode; unsigned UseVanityDraw(unsigned*); };
unsigned ESim::UseVanityDraw(unsigned* out) { *out = m_vanityObj; return m_vanityMode; }

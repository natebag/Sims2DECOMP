// 0x800BC96C HouseStats::GetNumLevels(void) (8 B)
struct HouseStats { char _pad[0x10]; unsigned m_field; unsigned GetNumLevels(); };
unsigned HouseStats::GetNumLevels() { return m_field; }

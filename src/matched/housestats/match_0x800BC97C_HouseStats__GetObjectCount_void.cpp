// 0x800BC97C HouseStats::GetObjectCount(void) (8 B)
struct HouseStats { char _pad[0x24]; unsigned m_field; unsigned GetObjectCount(); };
unsigned HouseStats::GetObjectCount() { return m_field; }

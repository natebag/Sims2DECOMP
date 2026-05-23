// 0x800BC974 HouseStats::GetLotSize(void) (8 B)
struct HouseStats { char _pad[0x14]; unsigned m_field; unsigned GetLotSize(); };
unsigned HouseStats::GetLotSize() { return m_field; }

// 0x800D1294 NeighborhoodImpl::GetHouseNumber(void) (8 B)
struct NeighborhoodImpl { char _pad[0x70]; unsigned m_field; unsigned GetHouseNumber(); };
unsigned NeighborhoodImpl::GetHouseNumber() { return m_field; }

// 0x800D1950 NeighborhoodImpl::SetHouseNum(int) (8 B)
struct NeighborhoodImpl { char _pad[0x70]; unsigned m_field; void SetHouseNum(unsigned); };
void NeighborhoodImpl::SetHouseNum(unsigned val) { m_field = val; }

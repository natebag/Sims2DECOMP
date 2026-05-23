// 0x800D18A8 NeighborhoodImpl::GetHighestLevelCompleted(void) (8 B)
struct NeighborhoodImpl { char _pad[0x84]; short m_field; int GetHighestLevelCompleted(); };
int NeighborhoodImpl::GetHighestLevelCompleted() { return m_field; }

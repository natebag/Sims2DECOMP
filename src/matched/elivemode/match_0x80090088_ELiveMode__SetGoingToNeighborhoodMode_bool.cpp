// 0x80090088 ELiveMode::SetGoingToNeighborhoodMode(bool) (8 B)
struct ELiveMode { char _pad[0x24]; unsigned m_goingToNeighborhood; void SetGoingToNeighborhoodMode(bool); };
void ELiveMode::SetGoingToNeighborhoodMode(bool val) { m_goingToNeighborhood = val; }

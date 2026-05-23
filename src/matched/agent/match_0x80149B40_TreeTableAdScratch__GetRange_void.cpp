// 0x80149B40 TreeTableAdScratch::GetRange(void) (8 B)
struct TreeTableAdScratch { char _pad[0x8]; short m_range; int GetRange(); };
int TreeTableAdScratch::GetRange() { return m_range; }

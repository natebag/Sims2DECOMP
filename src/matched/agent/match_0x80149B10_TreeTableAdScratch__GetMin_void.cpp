// 0x80149B10 TreeTableAdScratch::GetMin(void) (8 B)
struct TreeTableAdScratch { char _pad[0x6]; short m_min; int GetMin(); };
int TreeTableAdScratch::GetMin() { return m_min; }

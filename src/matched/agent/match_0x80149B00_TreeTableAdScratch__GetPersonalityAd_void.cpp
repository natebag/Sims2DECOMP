// 0x80149B00 TreeTableAdScratch::GetPersonalityAd(void) (8 B)
struct TreeTableAdScratch { char _pad[0x4]; short m_personalityAd; int GetPersonalityAd(); };
int TreeTableAdScratch::GetPersonalityAd() { return m_personalityAd; }

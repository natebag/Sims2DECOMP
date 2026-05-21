// 0x80118E28 cTrack::GetMinRange(void) (12B)
struct SndEvtGMR { char _pad[0x1f]; unsigned char m_minRange; };
struct cTrackGMR { SndEvtGMR* m_inner; unsigned char GetMinRange() const; };
unsigned char cTrackGMR::GetMinRange() const { return m_inner->m_minRange; }

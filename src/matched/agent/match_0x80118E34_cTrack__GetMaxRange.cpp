// 0x80118E34 cTrack::GetMaxRange(void) (12B)
struct SndEvtGMXR { char _pad[0x20]; unsigned char m_maxRange; };
struct cTrackGMXR { SndEvtGMXR* m_inner; unsigned char GetMaxRange() const; };
unsigned char cTrackGMXR::GetMaxRange() const { return m_inner->m_maxRange; }

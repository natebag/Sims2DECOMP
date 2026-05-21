// 0x801178A0 cTrack::StartPos(void) (12B)
struct SndEvtSP { char _pad[0x30]; int m_startPos; };
struct cTrackSP { SndEvtSP* m_inner; int StartPos() const; };
int cTrackSP::StartPos() const { return m_inner->m_startPos; }

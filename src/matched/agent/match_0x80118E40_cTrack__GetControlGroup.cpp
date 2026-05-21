// 0x80118E40 cTrack::GetControlGroup(void) (12B)
struct SndEvtGCG { char _pad[0x17]; unsigned char m_controlGroup; };
struct cTrackGCG { SndEvtGCG* m_inner; unsigned char GetControlGroup() const; };
unsigned char cTrackGCG::GetControlGroup() const { return m_inner->m_controlGroup; }

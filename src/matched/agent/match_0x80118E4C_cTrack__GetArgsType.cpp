// 0x80118E4C cTrack::GetArgsType(void) (12B)
struct SndEvtGAT { char _pad[0x15]; unsigned char m_argsType; };
struct cTrackGAT { SndEvtGAT* m_inner; unsigned char GetArgsType() const; };
unsigned char cTrackGAT::GetArgsType() const { return m_inner->m_argsType; }

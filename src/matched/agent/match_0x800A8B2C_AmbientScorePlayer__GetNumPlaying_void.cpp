// 0x800A8B2C AmbientScorePlayer::GetNumPlaying(void) (8 B)
struct AmbientScorePlayer { char _pad[0x10]; unsigned m_numPlaying; unsigned GetNumPlaying(); };
unsigned AmbientScorePlayer::GetNumPlaying() { return m_numPlaying; }

// 0x800A8B24 AmbientScorePlayer::GetAmbientScore(void) (8 B)
struct AmbientScorePlayer { char _pad[0x8]; unsigned m_ambientScore; unsigned GetAmbientScore(); };
unsigned AmbientScorePlayer::GetAmbientScore() { return m_ambientScore; }

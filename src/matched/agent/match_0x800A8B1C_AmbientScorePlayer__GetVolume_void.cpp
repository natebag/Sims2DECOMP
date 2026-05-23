// 0x800A8B1C AmbientScorePlayer::GetVolume(void) (8 B)
struct AmbientScorePlayer { char _pad[0x14]; unsigned m_volume; unsigned GetVolume(); };
unsigned AmbientScorePlayer::GetVolume() { return m_volume; }

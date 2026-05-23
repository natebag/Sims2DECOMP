// 0x800A876C AmbientScorePlayer::GetTime(void) (8 B)
struct AmbientScorePlayer { char _pad[0x34]; float m_time; float GetTime(); };
float AmbientScorePlayer::GetTime() { return m_time; }

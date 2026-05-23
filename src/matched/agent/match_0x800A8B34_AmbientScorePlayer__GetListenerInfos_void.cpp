// 0x800A8B34 AmbientScorePlayer::GetListenerInfos(void) (8 B)
struct AmbientScorePlayer { char _pad[0x20]; unsigned m_listenerInfos[1]; unsigned* GetListenerInfos(); };
unsigned* AmbientScorePlayer::GetListenerInfos() { return m_listenerInfos; }

// 0x800BADA4 cGZMusic::IsPlaying(void) (8 B)
struct cGZMusic { char _pad[0x8]; unsigned m_isPlaying; unsigned IsPlaying(); };
unsigned cGZMusic::IsPlaying() { return m_isPlaying; }

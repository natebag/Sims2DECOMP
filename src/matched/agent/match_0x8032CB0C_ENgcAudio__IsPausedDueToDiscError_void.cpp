// 0x8032CB0C ENgcAudio::IsPausedDueToDiscError(void) (8 B)
struct ENgcAudio { char _pad[0x38]; unsigned m_field; unsigned IsPausedDueToDiscError(); };
unsigned ENgcAudio::IsPausedDueToDiscError() { return m_field; }

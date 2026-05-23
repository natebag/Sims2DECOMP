// 0x8018AAE8 LoadGameTarget::GetResult(void) (8 B)
struct LoadGameTarget { char _pad[0x10c]; unsigned m_field; unsigned GetResult(); };
unsigned LoadGameTarget::GetResult() { return m_field; }

// 0x801E7078 MMUTarget::GetCurrentMainScreenChoice(void) (8 B)
struct MMUTarget { char _pad[0xa4]; unsigned m_field; unsigned GetCurrentMainScreenChoice(); };
unsigned MMUTarget::GetCurrentMainScreenChoice() { return m_field; }

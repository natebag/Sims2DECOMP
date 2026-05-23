// 0x801E7080 MMUTarget::GetCurrentGameplayChoice(void) (8 B)
struct MMUTarget { char _pad[0xb8]; unsigned m_field; unsigned GetCurrentGameplayChoice(); };
unsigned MMUTarget::GetCurrentGameplayChoice() { return m_field; }

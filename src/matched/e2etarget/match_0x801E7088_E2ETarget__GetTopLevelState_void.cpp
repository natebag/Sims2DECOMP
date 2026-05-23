// 0x801E7088 E2ETarget::GetTopLevelState(void) (8 B)
struct E2ETarget { char _pad[0xd8]; unsigned m_field; unsigned GetTopLevelState(); };
unsigned E2ETarget::GetTopLevelState() { return m_field; }

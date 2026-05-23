// 0x8018DE08 SaveGameTarget::GetResult(void) (8 B)
struct SaveGameTarget { char _pad[0x110]; unsigned m_field; unsigned GetResult(); };
unsigned SaveGameTarget::GetResult() { return m_field; }

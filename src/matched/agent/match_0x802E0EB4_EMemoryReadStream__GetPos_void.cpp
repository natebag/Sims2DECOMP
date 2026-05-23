// 0x802E0EB4 EMemoryReadStream::GetPos(void) (8 B)
struct EMemoryReadStream { char _pad[0x20]; unsigned m_field; unsigned GetPos(); };
unsigned EMemoryReadStream::GetPos() { return m_field; }

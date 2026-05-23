// 0x802E0EF8 EMemoryWriteStream::GetPos(void) (8 B)
struct EMemoryWriteStream { char _pad[0x1c]; unsigned m_field; unsigned GetPos(); };
unsigned EMemoryWriteStream::GetPos() { return m_field; }

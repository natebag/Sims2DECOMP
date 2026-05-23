// 0x802E0EE8 EMemoryBufferWriteStream::GetPos(void) (8 B)
struct EMemoryBufferWriteStream { char _pad[0x20]; unsigned m_field; unsigned GetPos(); };
unsigned EMemoryBufferWriteStream::GetPos() { return m_field; }

// 0x802C6944 EFile::GetLength(void) (8 B)
struct EFile { char _pad[0x14]; unsigned m_field; unsigned GetLength(); };
unsigned EFile::GetLength() { return m_field; }

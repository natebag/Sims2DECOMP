// 0x802C6934 EFile::GetName(void) (8 B)
struct EFile { char _pad[0x20]; unsigned m_field; unsigned GetName(); };
unsigned EFile::GetName() { return m_field; }

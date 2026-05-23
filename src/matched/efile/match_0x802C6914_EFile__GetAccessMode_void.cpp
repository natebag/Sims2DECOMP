// 0x802C6914 EFile::GetAccessMode(void) (8 B)
struct EFile { char _pad[0xc]; unsigned m_field; unsigned GetAccessMode(); };
unsigned EFile::GetAccessMode() { return m_field; }

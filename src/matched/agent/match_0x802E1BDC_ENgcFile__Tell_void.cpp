// 0x802E1BDC ENgcFile::Tell(void) (8 B)
struct ENgcFile { char _pad[0x68]; unsigned m_field; unsigned Tell(); };
unsigned ENgcFile::Tell() { return m_field; }

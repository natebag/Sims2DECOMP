// 0x802D8080 ENgcSNFile::Tell(void) (8 B)
struct ENgcSNFile { char _pad[0x30]; unsigned m_field; unsigned Tell(); };
unsigned ENgcSNFile::Tell() { return m_field; }

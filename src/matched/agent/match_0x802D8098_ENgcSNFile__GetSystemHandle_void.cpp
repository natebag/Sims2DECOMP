// 0x802D8098 ENgcSNFile::GetSystemHandle(void) (8 B)
struct ENgcSNFile { char _pad[0x2c]; unsigned m_field; unsigned GetSystemHandle(); };
unsigned ENgcSNFile::GetSystemHandle() { return m_field; }

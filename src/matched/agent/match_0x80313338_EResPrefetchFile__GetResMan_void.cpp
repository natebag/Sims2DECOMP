// 0x80313338 EResPrefetchFile::GetResMan(void) (8 B)
struct EResPrefetchFile { char _pad[0x2c]; unsigned m_field; unsigned GetResMan(); };
unsigned EResPrefetchFile::GetResMan() { return m_field; }

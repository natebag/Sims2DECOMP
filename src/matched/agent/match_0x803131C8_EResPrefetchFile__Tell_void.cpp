// 0x803131C8 EResPrefetchFile::Tell(void) (8 B)
struct EResPrefetchFile { char _pad[0x40]; unsigned m_field; unsigned Tell(); };
unsigned EResPrefetchFile::Tell() { return m_field; }

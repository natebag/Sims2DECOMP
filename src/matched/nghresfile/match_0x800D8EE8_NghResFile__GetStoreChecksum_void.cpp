// 0x800D8EE8 NghResFile::GetStoreChecksum(void) (8 B)
struct NghResFile { char _pad[0x18c]; unsigned m_field; unsigned GetStoreChecksum(); };
unsigned NghResFile::GetStoreChecksum() { return m_field; }

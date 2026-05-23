// 0x800D8EE0 NghResFile::SetStoreChecksum(bool) (8 B)
struct NghResFile { char _pad[0x18c]; unsigned m_field; void SetStoreChecksum(unsigned); };
void NghResFile::SetStoreChecksum(unsigned val) { m_field = val; }

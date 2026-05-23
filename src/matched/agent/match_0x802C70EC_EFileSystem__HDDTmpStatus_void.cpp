// 0x802C70EC EFileSystem::HDDTmpStatus(void) (8 B)
struct EFileSystem { char _pad[0x1c]; unsigned m_field; unsigned HDDTmpStatus(); };
unsigned EFileSystem::HDDTmpStatus() { return m_field; }

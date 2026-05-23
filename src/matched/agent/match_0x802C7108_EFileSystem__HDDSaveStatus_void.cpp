// 0x802C7108 EFileSystem::HDDSaveStatus(void) (8 B)
struct EFileSystem { char _pad[0x20]; unsigned m_field; unsigned HDDSaveStatus(); };
unsigned EFileSystem::HDDSaveStatus() { return m_field; }

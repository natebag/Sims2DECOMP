// 0x802C70D0 EFileSystem::HDDStatus(void) (8 B)
struct EFileSystem { char _pad[0x18]; unsigned m_field; unsigned HDDStatus(); };
unsigned EFileSystem::HDDStatus() { return m_field; }

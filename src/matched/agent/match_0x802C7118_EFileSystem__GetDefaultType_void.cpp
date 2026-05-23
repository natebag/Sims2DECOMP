// 0x802C7118 EFileSystem::GetDefaultType(void) (8 B)
struct EFileSystem { char _pad[0x10]; unsigned m_field; unsigned GetDefaultType(); };
unsigned EFileSystem::GetDefaultType() { return m_field; }

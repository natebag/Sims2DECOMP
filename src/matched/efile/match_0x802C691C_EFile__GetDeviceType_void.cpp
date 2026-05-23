// 0x802C691C EFile::GetDeviceType(void) (8 B)
struct EFile { char _pad[0x10]; unsigned m_field; unsigned GetDeviceType(); };
unsigned EFile::GetDeviceType() { return m_field; }

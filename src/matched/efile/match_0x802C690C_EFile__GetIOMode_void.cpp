// 0x802C690C EFile::GetIOMode(void) (8 B)
struct EFile { char _pad[0x8]; unsigned m_field; unsigned GetIOMode(); };
unsigned EFile::GetIOMode() { return m_field; }

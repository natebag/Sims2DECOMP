// 0x802C692C EFile::GetPath(void) (8 B)
struct EFile { char _pad[0x1c]; unsigned m_field; unsigned GetPath(); };
unsigned EFile::GetPath() { return m_field; }

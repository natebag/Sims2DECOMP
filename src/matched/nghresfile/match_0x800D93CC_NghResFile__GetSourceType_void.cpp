// 0x800D93CC NghResFile::GetSourceType(void) (8 B)
struct NghResFile { char _pad[0x20]; unsigned m_field; unsigned GetSourceType(); };
unsigned NghResFile::GetSourceType() { return m_field; }

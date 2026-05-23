// 0x80135624 iResFile::GetError(void) (8 B)
struct iResFile { char _pad[0x4]; unsigned m_error; unsigned GetError(); };
unsigned iResFile::GetError() { return m_error; }

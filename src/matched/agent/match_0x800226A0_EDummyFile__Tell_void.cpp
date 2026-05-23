// 0x800226A0 EDummyFile::Tell(void) (8 B)
struct EDummyFile { char _pad[0x2c]; unsigned m_pos; unsigned Tell(); };
unsigned EDummyFile::Tell() { return m_pos; }

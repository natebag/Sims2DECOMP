// 0x800A64E0 MemFile::Writable(void) (8 B)
struct MemFile { char _pad[0x10c]; unsigned m_writable; unsigned Writable(); };
unsigned MemFile::Writable() { return m_writable; }

// 0x800BEA00 IFFResFile2::Writable(void) (8 B)
struct IFFResFile2 { char _pad[0x11c]; unsigned m_field; unsigned Writable(); };
unsigned IFFResFile2::Writable() { return m_field; }

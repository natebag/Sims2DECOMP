// 0x800A6D1C StringBuffer2::capacity(void) (8 B)
struct StringBuffer2 { char _pad[0x4]; unsigned m_capacity; unsigned capacity(); };
unsigned StringBuffer2::capacity() { return m_capacity; }

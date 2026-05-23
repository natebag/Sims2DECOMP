// 0x800A65E4 StringBuffer::capacity(void) (8 B)
struct StringBuffer { char _pad[0x4]; unsigned m_capacity; unsigned capacity(); };
unsigned StringBuffer::capacity() { return m_capacity; }

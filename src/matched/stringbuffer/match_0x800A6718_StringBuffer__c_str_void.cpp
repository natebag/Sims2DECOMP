// 0x800A6718 StringBuffer::c_str(void) (8 B)
struct StringBuffer { unsigned m_data; unsigned c_str(); };
unsigned StringBuffer::c_str() { return m_data; }

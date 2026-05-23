// 0x800A6E70 StringBuffer2::buffer(void) (8 B)
struct StringBuffer2 { unsigned m_data; unsigned buffer(); };
unsigned StringBuffer2::buffer() { return m_data; }

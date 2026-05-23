// 0x800A6720 StringBuffer::buffer(void) (8 B)
struct StringBuffer { unsigned m_data; unsigned buffer(); };
unsigned StringBuffer::buffer() { return m_data; }

// 0x800A6E68 StringBuffer2::c_str(void) (8 B)
struct StringBuffer2 { unsigned m_data; unsigned c_str(); };
unsigned StringBuffer2::c_str() { return m_data; }

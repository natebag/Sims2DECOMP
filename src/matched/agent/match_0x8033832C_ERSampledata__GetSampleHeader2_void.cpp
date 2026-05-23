// 0x8033832C ERSampledata::GetSampleHeader2(void) (8 B)
struct ERSampledata { char _pad[0x18]; unsigned m_field; unsigned GetSampleHeader2(); };
unsigned ERSampledata::GetSampleHeader2() { return m_field; }

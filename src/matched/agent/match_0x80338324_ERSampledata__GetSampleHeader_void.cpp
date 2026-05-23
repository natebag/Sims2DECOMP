// 0x80338324 ERSampledata::GetSampleHeader(void) (8 B)
struct ERSampledata { char _pad[0x14]; unsigned m_field; unsigned GetSampleHeader(); };
unsigned ERSampledata::GetSampleHeader() { return m_field; }

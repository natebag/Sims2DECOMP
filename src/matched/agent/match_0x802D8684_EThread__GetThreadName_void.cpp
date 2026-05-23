// 0x802D8684 EThread::GetThreadName(void) (8 B)
struct EThread { char _pad[0x32c]; unsigned m_field; unsigned GetThreadName(); };
unsigned EThread::GetThreadName() { return m_field; }

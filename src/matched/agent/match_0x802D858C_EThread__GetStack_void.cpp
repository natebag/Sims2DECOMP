// 0x802D858C EThread::GetStack(void) (8 B)
struct EThread { char _pad[0x31c]; unsigned m_field; unsigned GetStack(); };
unsigned EThread::GetStack() { return m_field; }

// 0x802D8594 EThread::GetStackSize(void) (8 B)
struct EThread { char _pad[0x320]; unsigned m_field; unsigned GetStackSize(); };
unsigned EThread::GetStackSize() { return m_field; }

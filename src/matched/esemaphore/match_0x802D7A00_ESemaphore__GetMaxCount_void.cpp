// 0x802D7A00 ESemaphore::GetMaxCount(void) (8 B)
struct ESemaphore { char _pad[0x8]; unsigned m_field; unsigned GetMaxCount(); };
unsigned ESemaphore::GetMaxCount() { return m_field; }

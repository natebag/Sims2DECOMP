// 0x802D79F8 ESemaphore::GetCurrentCount(void) (8 B)
struct ESemaphore { char _pad[0xc]; unsigned m_field; unsigned GetCurrentCount(); };
unsigned ESemaphore::GetCurrentCount() { return m_field; }

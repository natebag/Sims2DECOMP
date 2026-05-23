// 0x800B43E4 Commander::GetNext(void) (8 B)
struct Commander { unsigned m_next; unsigned GetNext(); };
unsigned Commander::GetNext() { return m_next; }

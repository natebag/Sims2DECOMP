// 0x802D7220 FastAllocPool::GetAlignment(void) (8 B)
struct FastAllocPool { char _pad[0x10]; unsigned m_field; unsigned GetAlignment(); };
unsigned FastAllocPool::GetAlignment() { return m_field; }

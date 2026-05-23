// 0x802D7228 FastAllocPool::GetPoolStart(void) (8 B)
struct FastAllocPool { unsigned m_field; unsigned GetPoolStart(); };
unsigned FastAllocPool::GetPoolStart() { return m_field; }

// 0x802D7240 FastAllocPool::GetBlockSize(void) (8 B)
struct FastAllocPool { char _pad[0xc]; unsigned m_field; unsigned GetBlockSize(); };
unsigned FastAllocPool::GetBlockSize() { return m_field; }

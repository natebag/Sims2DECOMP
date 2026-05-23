// 0x802D7248 FastAllocPool::GetPoolBlocks(void) (8 B)
struct FastAllocPool { char _pad[0x8]; unsigned m_field; unsigned GetPoolBlocks(); };
unsigned FastAllocPool::GetPoolBlocks() { return m_field; }

// 0x8012C980 cXPersonImpl::GetMotives(void) (8 B)
struct cXPersonImpl { char _pad[168]; unsigned m_motives[1]; unsigned* GetMotives(); };
unsigned* cXPersonImpl::GetMotives() { return m_motives; }

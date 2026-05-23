// 0x800EB844 cXObjectImpl::GetNextImpl(void) (8 B)
struct cXObjectImpl { char _pad[0x5c]; unsigned m_nextImpl; unsigned GetNextImpl(); };
unsigned cXObjectImpl::GetNextImpl() { return m_nextImpl; }

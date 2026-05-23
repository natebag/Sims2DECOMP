// 0x800EB330 cXObjectImpl::GetSelector(void) (8 B)
struct cXObjectImpl { char _pad[0x8c]; unsigned m_selector; unsigned GetSelector(); };
unsigned cXObjectImpl::GetSelector() { return m_selector; }

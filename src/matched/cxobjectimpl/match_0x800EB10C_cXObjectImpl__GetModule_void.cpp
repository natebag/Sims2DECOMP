// 0x800EB10C cXObjectImpl::GetModule(void) (8 B)
struct cXObjectImpl { char _pad[0x58]; unsigned m_field; unsigned GetModule(); };
unsigned cXObjectImpl::GetModule() { return m_field; }

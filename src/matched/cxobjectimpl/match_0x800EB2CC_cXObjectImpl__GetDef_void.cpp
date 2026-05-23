// 0x800EB2CC cXObjectImpl::GetDef(void) (8 B)
struct cXObjectImpl { char _pad[0x88]; unsigned m_field; unsigned GetDef(); };
unsigned cXObjectImpl::GetDef() { return m_field; }

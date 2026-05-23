// 0x800EAA3C cXObjectImpl::GetNumAttr(void) (8 B)
struct cXObjectImpl { char _pad[0xc]; unsigned m_field; unsigned GetNumAttr(); };
unsigned cXObjectImpl::GetNumAttr() { return m_field; }

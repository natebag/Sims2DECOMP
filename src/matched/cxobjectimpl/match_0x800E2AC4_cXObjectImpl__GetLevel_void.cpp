// 0x800E2AC4 cXObjectImpl::GetLevel(void) (8 B)
struct cXObjectImpl { char _pad[0x80]; unsigned m_field; unsigned GetLevel(); };
unsigned cXObjectImpl::GetLevel() { return m_field; }

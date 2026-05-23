// 0x800E2ACC cXObjectImpl::SetLevel(int) (8 B)
struct cXObjectImpl { char _pad[0x80]; unsigned m_field; void SetLevel(unsigned); };
void cXObjectImpl::SetLevel(unsigned val) { m_field = val; }

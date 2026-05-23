// 0x800EB2FC cXObjectImpl::GetLocation(void) (8 B)
struct cXObjectImpl { char _pad[104]; unsigned m_location[1]; unsigned* GetLocation(); };
unsigned* cXObjectImpl::GetLocation() { return m_location; }

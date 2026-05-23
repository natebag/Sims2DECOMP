// 0x800EB2E0 cXObjectImpl::GetID(void) (8 B)
struct cXObjectImpl { char _pad[0x64]; short m_field; int GetID(); };
int cXObjectImpl::GetID() { return m_field; }

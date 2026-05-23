// 0x800EAB38 cXObjectImpl::GetSyncObject(void) (8 B)
struct cXObjectImpl { char _pad[0xdc]; unsigned m_field; unsigned GetSyncObject(); };
unsigned cXObjectImpl::GetSyncObject() { return m_field; }

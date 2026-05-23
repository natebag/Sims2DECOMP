// 0x800EAB4C cXObjectImpl::WaitingForSync(void) (8 B)
struct cXObjectImpl { char _pad[0xe4]; unsigned m_field; unsigned WaitingForSync(); };
unsigned cXObjectImpl::WaitingForSync() { return m_field; }

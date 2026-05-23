// 0x800B6B28 FamilyImpl::GetCreationOrder(void) (8 B)
struct FamilyImpl { char _pad[0x10]; unsigned m_creationOrder; unsigned GetCreationOrder(); };
unsigned FamilyImpl::GetCreationOrder() { return m_creationOrder; }

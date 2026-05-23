// 0x800B6B38 FamilyImpl::GetFunds(void) (8 B)
struct FamilyImpl { char _pad[0x14]; unsigned m_funds; unsigned GetFunds(); };
unsigned FamilyImpl::GetFunds() { return m_funds; }

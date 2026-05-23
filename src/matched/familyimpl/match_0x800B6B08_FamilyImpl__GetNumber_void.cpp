// 0x800B6B08 FamilyImpl::GetNumber(void) (8 B)
struct FamilyImpl { char _pad[0x8]; unsigned m_number; unsigned GetNumber(); };
unsigned FamilyImpl::GetNumber() { return m_number; }

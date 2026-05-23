// 0x800B6B18 FamilyImpl::GetHouseNumber(void) (8 B)
struct FamilyImpl { char _pad[0xc]; unsigned m_houseNumber; unsigned GetHouseNumber(); };
unsigned FamilyImpl::GetHouseNumber() { return m_houseNumber; }

// 0x800B6B60 FamilyImpl::GetHouseValue(void) (8 B)
struct FamilyImpl { char _pad[0x18]; unsigned m_houseValue; unsigned GetHouseValue(); };
unsigned FamilyImpl::GetHouseValue() { return m_houseValue; }

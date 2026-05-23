// 0x800BC984 HouseImpl::GetFamily(void) (8 B)
struct HouseImpl { char _pad[0x14]; unsigned m_field; unsigned GetFamily(); };
unsigned HouseImpl::GetFamily() { return m_field; }

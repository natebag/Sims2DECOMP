// 0x801A3E94 BBHTarget::IsBuildBuyHUDActive(void) (8 B)
struct BBHTarget { char _pad[0x88]; unsigned m_field; unsigned IsBuildBuyHUDActive(); };
unsigned BBHTarget::IsBuildBuyHUDActive() { return m_field; }

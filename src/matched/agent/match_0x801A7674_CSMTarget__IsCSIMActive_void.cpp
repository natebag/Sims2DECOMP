// 0x801A7674 CSMTarget::IsCSIMActive(void) (8 B)
struct CSMTarget { char _pad[0x88]; unsigned m_field; unsigned IsCSIMActive(); };
unsigned CSMTarget::IsCSIMActive() { return m_field; }

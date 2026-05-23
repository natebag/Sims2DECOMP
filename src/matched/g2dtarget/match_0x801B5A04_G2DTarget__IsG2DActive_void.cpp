// 0x801B5A04 G2DTarget::IsG2DActive(void) (8 B)
struct G2DTarget { char _pad[0x88]; unsigned m_field; unsigned IsG2DActive(); };
unsigned G2DTarget::IsG2DActive() { return m_field; }

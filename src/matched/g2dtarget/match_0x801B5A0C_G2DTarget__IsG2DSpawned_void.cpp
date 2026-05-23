// 0x801B5A0C G2DTarget::IsG2DSpawned(void) (8 B)
struct G2DTarget { char _pad[0x84]; unsigned m_field; unsigned IsG2DSpawned(); };
unsigned G2DTarget::IsG2DSpawned() { return m_field; }

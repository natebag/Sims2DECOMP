// 0x801E38F8 WAFTarget::IsWantsAndFearsActive(void) (8 B)
struct WAFTarget { char _pad[0x88]; unsigned m_field; unsigned IsWantsAndFearsActive(); };
unsigned WAFTarget::IsWantsAndFearsActive() { return m_field; }

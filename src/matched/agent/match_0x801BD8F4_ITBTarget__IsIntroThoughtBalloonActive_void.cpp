// 0x801BD8F4 ITBTarget::IsIntroThoughtBalloonActive(void) (8 B)
struct ITBTarget { char _pad[0x88]; unsigned m_field; unsigned IsIntroThoughtBalloonActive(); };
unsigned ITBTarget::IsIntroThoughtBalloonActive() { return m_field; }

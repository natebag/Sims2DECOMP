// 0x801F8E8C INTTarget::IsInterestMeterActive(void) (8 B)
struct INTTarget { char _pad[0x88]; unsigned m_field; unsigned IsInterestMeterActive(); };
unsigned INTTarget::IsInterestMeterActive() { return m_field; }

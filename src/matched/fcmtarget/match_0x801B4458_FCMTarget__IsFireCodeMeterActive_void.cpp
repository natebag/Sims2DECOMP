// 0x801B4458 FCMTarget::IsFireCodeMeterActive(void) (8 B)
struct FCMTarget { char _pad[0x88]; unsigned m_field; unsigned IsFireCodeMeterActive(); };
unsigned FCMTarget::IsFireCodeMeterActive() { return m_field; }

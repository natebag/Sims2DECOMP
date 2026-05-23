// 0x801A23BC ACTTarget::IsActionQueueActive(void) (8 B)
struct ACTTarget { char _pad[0xd0]; unsigned m_field; unsigned IsActionQueueActive(); };
unsigned ACTTarget::IsActionQueueActive() { return m_field; }

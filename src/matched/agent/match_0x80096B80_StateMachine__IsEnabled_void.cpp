// 0x80096B80 StateMachine::IsEnabled(void) (8 B)
struct StateMachine { char _pad[0x94]; unsigned m_isEnabled; unsigned IsEnabled(); };
unsigned StateMachine::IsEnabled() { return m_isEnabled; }

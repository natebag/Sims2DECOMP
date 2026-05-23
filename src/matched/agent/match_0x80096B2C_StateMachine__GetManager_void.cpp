// 0x80096B2C StateMachine::GetManager(void) (8 B)
struct StateMachine { char _pad[0x20]; unsigned m_manager; unsigned GetManager(); };
unsigned StateMachine::GetManager() { return m_manager; }

// 0x80096B88 StateMachine::IsPausedUpdate(void) (8 B)
struct StateMachine { char _pad[0x24]; unsigned m_isPausedUpdate; unsigned IsPausedUpdate(); };
unsigned StateMachine::IsPausedUpdate() { return m_isPausedUpdate; }

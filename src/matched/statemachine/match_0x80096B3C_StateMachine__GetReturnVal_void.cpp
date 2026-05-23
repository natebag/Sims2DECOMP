// 0x80096B3C StateMachine::GetReturnVal(void) (8 B)
struct StateMachine { char _pad[0x90]; unsigned m_returnVal; unsigned GetReturnVal(); };
unsigned StateMachine::GetReturnVal() { return m_returnVal; }

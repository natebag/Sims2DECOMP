// 0x80093BD4 MUStateMachine::GetMUWrapper(void) (8 B)
struct MUStateMachine { char _pad[0x98]; unsigned m_muWrapper; unsigned GetMUWrapper(); };
unsigned MUStateMachine::GetMUWrapper() { return m_muWrapper; }

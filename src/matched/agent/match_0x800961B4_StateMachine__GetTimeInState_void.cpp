// 0x800961B4 StateMachine::GetTimeInState(void) (8 B)
struct StateMachine { char _pad[0x50]; float m_timeInState; float GetTimeInState(); };
float StateMachine::GetTimeInState() { return m_timeInState; }

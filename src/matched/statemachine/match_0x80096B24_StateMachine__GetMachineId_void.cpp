// 0x80096B24 StateMachine::GetMachineId(void) (8 B)
struct StateMachine { char _pad[0x1c]; unsigned m_machineId; unsigned GetMachineId(); };
unsigned StateMachine::GetMachineId() { return m_machineId; }

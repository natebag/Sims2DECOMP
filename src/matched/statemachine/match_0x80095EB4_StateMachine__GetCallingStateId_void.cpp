// FLAGS: -fno-schedule-insns
// 0x80095EB4 StateMachine::GetCallingStateId(void) (12B)
// lwz r9,0x48(3); lwz r3,0x0(9); blr  -- this->m_callingState->m_id
struct SMState {
    int m_id;           // 0x0
};

struct StateMachine {
    char pad[0x48];
    SMState* m_callingState;    // 0x48
    int GetCallingStateId();
};

int StateMachine::GetCallingStateId() { return m_callingState->m_id; }

// FLAGS: -fno-schedule-insns
// 0x80095EA8 StateMachine::GetLastStateId(void) (12B)
// lwz r9,0x44(3); lwz r3,0x0(9); blr  -- this->m_lastState->m_id
struct SMState {
    int m_id;           // 0x0
};

struct StateMachine {
    char pad[0x44];
    SMState* m_lastState;   // 0x44
    int GetLastStateId();
};

int StateMachine::GetLastStateId() { return m_lastState->m_id; }

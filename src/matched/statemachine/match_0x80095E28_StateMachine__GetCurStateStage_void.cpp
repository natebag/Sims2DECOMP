// FLAGS: -fno-schedule-insns
// 0x80095E28 StateMachine::GetCurStateStage(void) (12B)
// lwz r9,0x3c(3); lwz r3,0xc(9); blr  -- this->m_curState->m_stage
struct SMState {
    char pad[0xC];
    int m_stage;        // 0xC
};

struct StateMachine {
    char pad[0x3C];
    SMState* m_curState;    // 0x3C
    int GetCurStateStage();
};

int StateMachine::GetCurStateStage() { return m_curState->m_stage; }

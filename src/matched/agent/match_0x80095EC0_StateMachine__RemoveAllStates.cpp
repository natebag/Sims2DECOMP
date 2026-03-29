// 0x80095EC0 (80 bytes)
struct StateMachineState;

struct StateMachineStatus {
    StateMachineState* m_curState;   // 0x00
    StateMachineState* m_nextState;  // 0x04
    int m_field_08;                  // 0x08
    int m_field_0C;                  // 0x0C
    float m_secBeforeNext;           // 0x10
    float m_secInCur;                // 0x14

    void ShutdownCurState(void);
};

struct StateMachine {
    char pad[0x2C];                  // 0x00-0x2B
    StateMachineState** m_begin;     // 0x2C (44)
    StateMachineState** m_end;       // 0x30 (48)
    char pad2[0x08];                 // 0x34-0x3B
    StateMachineStatus m_status;     // 0x3C

    void RemoveAllStates(void);
};

void StateMachine::RemoveAllStates(void) {
    StateMachineStatus* status = &m_status;
    status->ShutdownCurState();
    status->m_nextState = 0;
    status->m_secBeforeNext = 0.0f;
    m_end = m_begin;
}

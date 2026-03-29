// 0x80095D78 (76 bytes)
struct StateMachineState;

struct StateMachineStatus {
    StateMachineState* m_curState;   // 0x00
    StateMachineState* m_nextState;  // 0x04
    int m_field_08;                  // 0x08
    int m_field_0C;                  // 0x0C
    float m_secBeforeNext;           // 0x10
    float m_secInCur;                // 0x14
};

struct StateMachine {
    char pad[0x2C];                  // 0x00-0x2B (44 bytes)
    StateMachineState** m_begin;     // 0x2C (44)
    StateMachineState** m_end;       // 0x30 (48)
    char pad2[0x08];                 // 0x34-0x3B (8 bytes)
    StateMachineStatus m_status;     // 0x3C

    StateMachineState* FindStateById(int id);
    void SetNextState(int id, float delay);
};

void StateMachine::SetNextState(int id, float delay) {
    StateMachineState* state = FindStateById(id);
    if (state != 0) {
        StateMachineStatus* status = &m_status;
        status->m_nextState = state;
        status->m_secBeforeNext = delay;
    }
}

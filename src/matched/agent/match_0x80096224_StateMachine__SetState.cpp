// 0x80096224 (56 bytes)
struct StateMachineState;

struct StateMachineStatus {
    int m_curState;         // 0x00
    int m_field_04;         // 0x04
    int m_field_08;         // 0x08
    int m_field_0C;         // 0x0C
    float m_secBeforeNext;  // 0x10
    float m_secInCur;       // 0x14

    void SetState(StateMachineState* state);
};

struct StateMachine {
    char pad[0x3C];               // 0x00-0x3B
    StateMachineStatus m_status;  // 0x3C (24 bytes, ends at 0x54)
    char pad2[0x3C];              // 0x54-0x8F (60 bytes)
    int m_field_090;              // 0x90 (144)

    void SetState(StateMachineState* state);
};

void StateMachine::SetState(StateMachineState* state) {
    m_status.SetState(state);
    m_field_090 = 0;
}

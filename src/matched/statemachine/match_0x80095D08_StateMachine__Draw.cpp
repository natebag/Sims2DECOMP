// 0x80095D08 (48 bytes)
struct ERC;

struct StateMachineStatus {
    int m_curState;         // 0x00
    int m_field_04;         // 0x04
    int m_field_08;         // 0x08
    int m_field_0C;         // 0x0C
    float m_secBeforeNext;  // 0x10
    float m_secInCur;       // 0x14

    void DrawCurState(ERC* rc);
};

struct StateMachine {
    char pad[0x3C];               // 0x00-0x3B
    StateMachineStatus m_status;  // 0x3C (24 bytes, ends at 0x54)
    char pad2[0x40];              // 0x54-0x93 (64 bytes)
    int m_enabled;                // 0x94 (148)

    void Draw(ERC* rc);
};

void StateMachine::Draw(ERC* rc) {
    if (m_enabled != 0) {
        m_status.DrawCurState(rc);
    }
}

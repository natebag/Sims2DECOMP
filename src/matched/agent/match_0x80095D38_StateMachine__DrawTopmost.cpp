// 0x80095D38 (64 bytes)
struct ERC;

struct StateMachineStatus {
    int m_curState;         // 0x00
    int m_field_04;         // 0x04
    int m_field_08;         // 0x08
    int m_field_0C;         // 0x0C
    float m_secBeforeNext;  // 0x10
    float m_secInCur;       // 0x14

    void DrawTopmostCurState(ERC* rc);
};

// Direct global at 0x80475C0C (field 0x88 inside _gd struct)
extern int g_topmostDrawEnabled;

struct StateMachine {
    char pad[0x3C];               // 0x00-0x3B
    StateMachineStatus m_status;  // 0x3C (24 bytes, ends at 0x54)
    char pad2[0x40];              // 0x54-0x93 (64 bytes)
    int m_enabled;                // 0x94 (148)

    void DrawTopmost(ERC* rc);
};

void StateMachine::DrawTopmost(ERC* rc) {
    if (g_topmostDrawEnabled != 0) {
        if (m_enabled != 0) {
            m_status.DrawTopmostCurState(rc);
        }
    }
}

// 0x800964D8 (44 bytes)
struct StateMachineStatus {
    char* m_curState;       // 0x00
    int m_field_04;         // 0x04
    int m_field_08;         // 0x08
    int m_field_0C;         // 0x0C
    float m_secBeforeNext;  // 0x10
    float m_secInCur;       // 0x14

    void AddToSecondsBeforeNextState(float dt);
};

void StateMachineStatus::AddToSecondsBeforeNextState(float dt) {
    float val = m_secBeforeNext;
    if (!(val > 0.0f)) return;
    val += dt;
    m_secBeforeNext = val;
    if (!(val < 0.0f)) return;
    m_secBeforeNext = 0.0f;
}

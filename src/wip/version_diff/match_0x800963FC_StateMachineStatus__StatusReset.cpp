// 0x800963FC (40 bytes)
struct StateMachineStatus {
    char* m_curState;       // 0x00
    int m_field_04;         // 0x04
    int m_field_08;         // 0x08
    int m_field_0C;         // 0x0C
    float m_secBeforeNext;  // 0x10
    float m_secInCur;       // 0x14

    void StatusReset(void);
};

void StateMachineStatus::StatusReset(void) {
    m_curState = 0;
    m_field_04 = 0;
    m_field_08 = 0;
    m_field_0C = 0;
    m_secBeforeNext = 0.0f;
    m_secInCur = 0.0f;
}

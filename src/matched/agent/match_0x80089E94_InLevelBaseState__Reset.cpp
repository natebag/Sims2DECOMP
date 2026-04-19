/* InLevelBaseState::Reset(void) at 0x80089E94 (28B) */

extern char g_stateFlag[];

struct InLevelBaseState_R {
    char _pad[28];
    int m_field28;  // 28
    int m_field32;  // 32
    void Reset();
};

void InLevelBaseState_R::Reset() {
    m_field32 = 0;
    m_field28 = 0;
    *(int*)(g_stateFlag) = 1;
}

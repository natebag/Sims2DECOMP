// 0x80090F7C (40 bytes)

struct LoadingScreenStateMachine {
    char pad_A0[0xA0];
    void* m_curState;     // offset 0xA0
    char pad_B4[0x14];
    int m_state;          // offset 0xB4

    int IsFadingIn();
};

extern LoadingScreenStateMachine* g_loadingScreenStateMachine;

int LoadingScreenStateMachine::IsFadingIn() {
    if (g_loadingScreenStateMachine->m_state & 1) return 1;
    if (g_loadingScreenStateMachine->m_curState == 0) return 0;
    return 1;
}

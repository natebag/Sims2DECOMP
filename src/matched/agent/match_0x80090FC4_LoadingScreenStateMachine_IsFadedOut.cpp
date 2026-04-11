/* LoadingScreenStateMachine::IsFadedOut(void) at 0x80090FC4 (16B) */

extern struct LoadingScreenStateMachine* g_loadingScreenStateMachine;

struct LoadingScreenStateMachine {
    char pad[0xB4];
    int m_state;

    static int IsFadedOut(void);
};

int LoadingScreenStateMachine::IsFadedOut(void) {
    return (g_loadingScreenStateMachine->m_state >> 3) & 1;
}

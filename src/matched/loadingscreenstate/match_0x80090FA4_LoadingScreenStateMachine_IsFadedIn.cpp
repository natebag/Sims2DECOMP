/* LoadingScreenStateMachine::IsFadedIn(void) at 0x80090FA4 (16B) */

extern struct LoadingScreenStateMachine* g_loadingScreenStateMachine;

struct LoadingScreenStateMachine {
    char pad[0xB4];
    int m_state;

    static int IsFadedIn(void);
};

int LoadingScreenStateMachine::IsFadedIn(void) {
    return (g_loadingScreenStateMachine->m_state >> 2) & 1;
}

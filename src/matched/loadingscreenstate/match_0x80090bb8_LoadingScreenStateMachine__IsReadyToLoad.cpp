// 0x80090bb8 LoadingScreenStateMachine::IsReadyToLoad(void) (24B)

struct LoadingScreenStateMachine {
    char pad[0xA0];
    int m_ready;
    int IsReadyToLoad(void);
};

int LoadingScreenStateMachine::IsReadyToLoad(void) {
    if (m_ready != 0) return 1;
    return 0;
}

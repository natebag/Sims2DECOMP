struct LoadingScreenStateMachine {
    char pad[0xA4];
    int m_loadComplete;

    int IsLoadComplete(void);
};

int LoadingScreenStateMachine::IsLoadComplete(void) {
    return m_loadComplete;
}

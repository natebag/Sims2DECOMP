struct LoadingScreenStateMachine {
    char pad[0xA0];
    int m_loadStartedFlag;

    void LoadStarted(void);
};

void LoadingScreenStateMachine::LoadStarted(void) {
    m_loadStartedFlag = 0;
}

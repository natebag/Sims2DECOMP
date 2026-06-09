struct LoadingScreenStateMachine {
    char pad[0xA4];
    int m_loadComplete;

    void LoadFinished(void);
};

void LoadingScreenStateMachine::LoadFinished(void) {
    m_loadComplete = 1;
}

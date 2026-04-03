struct LoadingScreenStateMachine {
    char pad[0xB4];
    int m_fading;

    void FaderStop(void);
};

void LoadingScreenStateMachine::FaderStop(void) {
    m_fading = 0;
}

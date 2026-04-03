struct ELiveMode {
    char pad[0x0C];
    int m_introCameraState;

    void ResetIntroCamera(void);
};

void ELiveMode::ResetIntroCamera(void) {
    m_introCameraState = 0;
}

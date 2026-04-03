struct ELiveMode {
    char pad[0x0C];
    int m_introCameraState;

    void SetIntroCameraState(int state);
};

void ELiveMode::SetIntroCameraState(int state) {
    m_introCameraState = state;
}

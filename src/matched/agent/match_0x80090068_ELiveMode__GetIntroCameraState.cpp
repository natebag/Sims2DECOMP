struct ELiveMode {
    char pad[0x0C];
    int m_introCameraState;

    int GetIntroCameraState(void);
};

int ELiveMode::GetIntroCameraState(void) {
    return m_introCameraState;
}

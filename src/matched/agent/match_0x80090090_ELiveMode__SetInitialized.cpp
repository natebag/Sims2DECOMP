struct ELiveMode {
    char pad[0x30];
    int m_initialized;

    void SetInitialized(int flag);
};

void ELiveMode::SetInitialized(int flag) {
    m_initialized = flag;
}

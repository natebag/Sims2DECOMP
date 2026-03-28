struct ELiveMode {
    char pad[0x30];
    int m_initialized;

    int IsInitialized(void);
};

int ELiveMode::IsInitialized(void) {
    return m_initialized;
}

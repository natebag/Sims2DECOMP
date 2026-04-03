struct MUStatesLoadConfig {
    char pad[0x1C];
    int m_state;

    void Reset(void);
};

void MUStatesLoadConfig::Reset(void) {
    m_state = 0;
}

struct ELiveMode {
    char pad[0x28];
    int m_inTransportMode;

    int InTransportMode(void);
};

int ELiveMode::InTransportMode(void) {
    return m_inTransportMode;
}

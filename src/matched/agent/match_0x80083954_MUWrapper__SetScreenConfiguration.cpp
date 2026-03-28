struct MUWrapper {
    char pad[0xAC];
    int m_screenConfig;

    void SetScreenConfiguration(int config);
};

void MUWrapper::SetScreenConfiguration(int config) {
    m_screenConfig = config;
}

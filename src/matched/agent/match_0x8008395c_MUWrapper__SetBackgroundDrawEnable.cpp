struct MUWrapper {
    char pad[0xC8];
    int m_bgDrawEnable;

    void SetBackgroundDrawEnable(int enable);
};

void MUWrapper::SetBackgroundDrawEnable(int enable) {
    m_bgDrawEnable = enable;
}

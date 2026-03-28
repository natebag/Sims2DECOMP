struct EFile_SD {
    char pad[0x10];
    int m_deviceType;
    void SetDevice(int type);
};

void EFile_SD::SetDevice(int type) {
    m_deviceType = type;
}

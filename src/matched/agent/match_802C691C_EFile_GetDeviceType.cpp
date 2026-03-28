struct EFile_GDT {
    char pad[0x10];
    int m_deviceType;
    int GetDeviceType() const;
};

int EFile_GDT::GetDeviceType() const {
    return m_deviceType;
}

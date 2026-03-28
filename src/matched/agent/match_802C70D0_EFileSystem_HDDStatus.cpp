struct EFileSystem_HS {
    char pad[0x18];
    int m_hddStatus;
    int HDDStatus();
};

int EFileSystem_HS::HDDStatus() {
    return m_hddStatus;
}

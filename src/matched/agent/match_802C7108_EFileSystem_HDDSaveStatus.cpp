struct EFileSystem_HSS {
    char pad[0x20];
    int m_hddSaveStatus;
    int HDDSaveStatus();
};

int EFileSystem_HSS::HDDSaveStatus() {
    return m_hddSaveStatus;
}

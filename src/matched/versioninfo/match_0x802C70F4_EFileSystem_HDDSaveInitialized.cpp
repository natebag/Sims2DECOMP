// 0x802C70F4 EFileSystem::HDDSaveInitialized (20b)

struct EFileSystem_HSI {
    char pad[0x20];
    int m_hddSaveStatus;
    bool HDDSaveInitialized();
};

bool EFileSystem_HSI::HDDSaveInitialized() {
    return m_hddSaveStatus == 11;
}

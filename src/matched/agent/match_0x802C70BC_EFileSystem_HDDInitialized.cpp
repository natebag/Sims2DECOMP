// 0x802C70BC EFileSystem::HDDInitialized (20b)

struct EFileSystem_HI {
    char pad[0x18];
    int m_hddStatus;
    bool HDDInitialized();
};

bool EFileSystem_HI::HDDInitialized() {
    return m_hddStatus == 11;
}

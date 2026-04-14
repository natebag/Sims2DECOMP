// 0x802C70D8 EFileSystem::HDDTmpInitialized (20b)

struct EFileSystem_HTI {
    char pad[0x1C];
    int m_hddTmpStatus;
    bool HDDTmpInitialized();
};

bool EFileSystem_HTI::HDDTmpInitialized() {
    return m_hddTmpStatus == 11;
}

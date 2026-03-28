struct EFileSystem_HTS {
    char pad[0x1C];
    int m_hddTmpStatus;
    int HDDTmpStatus();
};

int EFileSystem_HTS::HDDTmpStatus() {
    return m_hddTmpStatus;
}

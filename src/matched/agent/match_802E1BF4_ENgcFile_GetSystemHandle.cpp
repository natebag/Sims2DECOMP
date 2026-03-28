struct ENgcFile_GSH {
    char pad[0x2C];
    int m_sysHandle;
    int* GetSystemHandle() const;
};
int* ENgcFile_GSH::GetSystemHandle() const {
    return (int*)&m_sysHandle;
}

struct ENgcSNFile_GSH {
    char pad[0x2C];
    void* m_sysHandle;
    void* GetSystemHandle() const;
};
void* ENgcSNFile_GSH::GetSystemHandle() const {
    return m_sysHandle;
}

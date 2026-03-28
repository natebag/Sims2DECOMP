struct EFile_GAM {
    char pad[0x0C];
    int m_accessMode;
    int GetAccessMode() const;
};

int EFile_GAM::GetAccessMode() const {
    return m_accessMode;
}

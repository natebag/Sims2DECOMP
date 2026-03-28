struct EFileSystem_GDT {
    char pad[0x10];
    int m_defaultType;
    int GetDefaultType() const;
};

int EFileSystem_GDT::GetDefaultType() const {
    return m_defaultType;
}

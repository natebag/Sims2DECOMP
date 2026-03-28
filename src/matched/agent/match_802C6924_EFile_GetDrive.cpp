struct EFile_GD {
    char pad[0x18];
    char m_drive;
    char* GetDrive() const;
};

char* EFile_GD::GetDrive() const {
    return (char*)&m_drive;
}

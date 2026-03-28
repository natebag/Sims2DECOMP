struct EFile_GN {
    char pad[0x20];
    char* m_name;
    char* GetName() const;
};

char* EFile_GN::GetName() const {
    return m_name;
}

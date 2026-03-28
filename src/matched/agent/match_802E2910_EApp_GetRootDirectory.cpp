struct RootDir {
    char* m_dir;
};
struct EApp_GRD {
    char pad[0x470];
    RootDir* m_rootDir;
    char* GetRootDirectory();
};
char* EApp_GRD::GetRootDirectory() {
    return m_rootDir->m_dir;
}

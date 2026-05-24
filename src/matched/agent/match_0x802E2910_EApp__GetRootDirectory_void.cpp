// 0x802E2910 EApp::GetRootDirectory(void) (12 B)
// FLAGS: -fno-schedule-insns
// Pattern: lwz r9,0x470(r3); lwz r3,0x0(r9); blr

struct EDirectory {
    void* m_path; // 0x0
};

struct EApp {
    char _pad[0x470];
    EDirectory* m_rootDirectory; // 0x470

    void* GetRootDirectory();
};

void* EApp::GetRootDirectory() {
    return m_rootDirectory->m_path;
}

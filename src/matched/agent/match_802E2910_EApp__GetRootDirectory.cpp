struct DirEntry { char *path; };
class EApp {
public:
    char m_pad[1136];
    DirEntry *m_pRootDir;
    char *GetRootDirectory();
};
char *EApp::GetRootDirectory() { return m_pRootDir->path; }

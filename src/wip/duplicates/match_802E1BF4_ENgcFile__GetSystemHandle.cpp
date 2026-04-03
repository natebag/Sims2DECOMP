class ENgcFile {
public:
    char m_pad[44];
    int m_handle;
    void *GetSystemHandle() const;
};
void *ENgcFile::GetSystemHandle() const { return (void *)&m_handle; }

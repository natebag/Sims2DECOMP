/* NghResFile::SetFileName(char *) - 72 bytes */

struct StringBuffer {
    void erase(void);
    void append(char *str, int len);
};

struct NghResFile {
    char m_pad[0x28];
    StringBuffer m_fileName;

    int SetFileName(char *name);
};

int NghResFile::SetFileName(char *name) {
    m_fileName.erase();
    m_fileName.append(name, -1);
    return 1;
}

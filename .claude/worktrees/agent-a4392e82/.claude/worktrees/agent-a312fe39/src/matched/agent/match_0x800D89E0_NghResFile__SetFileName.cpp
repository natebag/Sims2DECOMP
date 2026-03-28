/* NghResFile::SetFileName(char *) - 0x800D89E0 (72 bytes) */

struct StringBuffer {
    void erase(void);
    void append(char *, int);
};

struct NghResFile {
    char _pad[0x28];
    StringBuffer m_fileName;

    int SetFileName(char *name);
};

int NghResFile::SetFileName(char *name)
{
    m_fileName.erase();
    m_fileName.append(name, -1);
    return 1;
}

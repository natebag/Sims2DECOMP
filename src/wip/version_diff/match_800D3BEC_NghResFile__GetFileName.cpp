/* NghResFile::GetFileName(StringBuffer &) - 44 bytes */

struct StringBuffer {
    void copy(StringBuffer &src);
};

struct NghResFile {
    char m_pad[0x28];
    StringBuffer m_fileName;

    void GetFileName(StringBuffer &result);
};

void NghResFile::GetFileName(StringBuffer &result) {
    result.copy(m_fileName);
}

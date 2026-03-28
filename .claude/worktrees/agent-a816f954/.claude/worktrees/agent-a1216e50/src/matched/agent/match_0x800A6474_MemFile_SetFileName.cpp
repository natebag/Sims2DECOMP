struct StringBuffer;

struct MemFile {
    void clearName(void);
    void appendName(StringBuffer* buf, int len);
    void SetFileName(StringBuffer* buf);
};

void MemFile::SetFileName(StringBuffer* buf) {
    clearName();
    appendName(buf, -1);
}

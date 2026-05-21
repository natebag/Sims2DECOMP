// 0x800A641C (88B) MemFile::GetFileName(StringBuffer&)

class StringBuffer {
public:
    void erase();
    void append(StringBuffer& sb, int len);
};

class MemFile : public StringBuffer {
public:
    int ValidFile();
    int GetFileName(StringBuffer& buf);
};

int MemFile::GetFileName(StringBuffer& buf) {
    if (!ValidFile()) return -49;
    buf.erase();
    buf.append(*this, -1);
    return 0;
}

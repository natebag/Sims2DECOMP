// 0x800a5e18 (116B) MemFile::SetFileSize(int)

class MemFile {
public:
    char pad1[0x10c];
    int m_writable;   // offset 0x10c
    int m_field110;   // offset 0x110
    void* m_data;     // offset 0x114
    int m_field118;   // offset 0x118
    int m_pos;        // offset 0x11c
    int m_size;       // offset 0x120

    int ValidFile();
    int SetFileSize(int new_size);
};

int MemFile::SetFileSize(int new_size) {
    int result = 0;
    if (!ValidFile()) {
        result = -49;
    } else if (!m_writable) {
        result = -45;
    } else if (new_size < 0) {
        result = -50;
    } else {
        m_pos = new_size;
        m_size = new_size;
    }
    return result;
}

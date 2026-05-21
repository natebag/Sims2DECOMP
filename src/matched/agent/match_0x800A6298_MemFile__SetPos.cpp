// 0x800A6298 (88B) MemFile::SetPos(int)

class MemFile {
public:
    char pad[0x114];
    void* m_data;
    char pad2[4];
    int m_pos;

    int ValidFile();
    int SetPos(int pos);
};

int MemFile::SetPos(int pos) {
    if (!ValidFile()) return -49;
    if (pos < 0) return -50;
    m_pos = pos;
    return 0;
}

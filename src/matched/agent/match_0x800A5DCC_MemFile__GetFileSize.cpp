// 0x800A5DCC MemFile::GetFileSize(int*) (76B)

class MemFile {
public:
    char pad[0x120];
    int m_120;
    bool ValidFile();
    int GetFileSize(int* pSize);
};

int MemFile::GetFileSize(int* pSize) {
    if (!ValidFile()) return -49;
    *pSize = m_120;
    return 0;
}

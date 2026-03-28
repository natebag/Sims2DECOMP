/* MemFile::ValidFile(void) at 0x800A62F0 (24B) */

struct MemFile {
    char pad[0x114];
    void* m_data;

    int ValidFile(void);
};

int MemFile::ValidFile(void) {
    if (m_data != 0) {
        return 1;
    }
    return 0;
}

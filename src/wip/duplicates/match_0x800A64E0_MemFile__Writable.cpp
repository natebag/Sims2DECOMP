/* MemFile::Writable(void) at 0x800A64E0 (8B) */

struct MemFile {
    char pad[0x10C];
    int m_writable;

    int Writable(void);
};

int MemFile::Writable(void) {
    return m_writable;
}

// 0x800A64E0 (8 bytes)
class MemFile {
public:
    char pad[268];
    int m_writable;

    int Writable(void);
};

int MemFile::Writable(void) {
    return m_writable;
}

/* IFFResFile2::Writable(void) at 0x800BEA00 (8B) */

struct IFFResFile2 {
    char pad[0x11C];
    int m_writable;

    int Writable(void);
};

int IFFResFile2::Writable(void) {
    return m_writable;
}

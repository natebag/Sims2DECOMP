// 0x800BEA00 IFFResFile2::Writable (8B)
struct IFFResFile2 {
    char pad[284];
    int m_writable;
    int Writable();
};

int IFFResFile2::Writable() { return m_writable; }

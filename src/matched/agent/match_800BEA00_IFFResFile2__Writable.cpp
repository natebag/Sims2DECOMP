class IFFResFile2 {
public:
    char pad[0x11C];
    int m_writable;

    int Writable(void);
};

int IFFResFile2::Writable(void) {
    return m_writable;
}

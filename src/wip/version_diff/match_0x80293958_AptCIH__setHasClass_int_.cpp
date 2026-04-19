/* 0x80293958 (64B) AptCIH::setHasClass(int) */

struct AptCIH_HC2 {
    char pad[0x5C];
    unsigned int m_flags;

    void setHasClass(int v);
};

void AptCIH_HC2::setHasClass(int v) {
    int b = v ? 1 : 0;
    unsigned int f = m_flags;
    f = (f & ~0x00004000) | (b << 14);
    m_flags = f;
}

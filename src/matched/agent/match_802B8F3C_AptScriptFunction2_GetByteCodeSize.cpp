struct Inner_SF2BCS {
    char pad[0x10];
    int m_size;
};
struct AptSF2_GBCS {
    char pad[0x34];
    Inner_SF2BCS* m_inner;
    int GetByteCodeSize();
};
int AptSF2_GBCS::GetByteCodeSize() {
    return m_inner->m_size;
}

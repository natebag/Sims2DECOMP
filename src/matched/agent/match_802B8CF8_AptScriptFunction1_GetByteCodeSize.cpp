struct Inner_SF1BCS {
    char pad[0x0C];
    int m_size;
};
struct AptSF1_GBCS {
    char pad[0x34];
    Inner_SF1BCS* m_inner;
    int GetByteCodeSize();
};
int AptSF1_GBCS::GetByteCodeSize() {
    return m_inner->m_size;
}

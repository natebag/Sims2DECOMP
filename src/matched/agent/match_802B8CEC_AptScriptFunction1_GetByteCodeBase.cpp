struct Inner_SF1BCB {
    char pad[0x18];
    int m_code;
};
struct AptSF1_GBCB {
    char pad[0x34];
    Inner_SF1BCB* m_inner;
    void* GetByteCodeBase();
};
void* AptSF1_GBCB::GetByteCodeBase() {
    return &m_inner->m_code;
}

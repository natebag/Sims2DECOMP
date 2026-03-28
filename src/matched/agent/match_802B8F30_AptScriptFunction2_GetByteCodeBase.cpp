struct Inner_SF2BCB {
    char pad[0x1C];
    int m_code;
};
struct AptSF2_GBCB {
    char pad[0x34];
    Inner_SF2BCB* m_inner;
    void* GetByteCodeBase();
};
void* AptSF2_GBCB::GetByteCodeBase() {
    return &m_inner->m_code;
}

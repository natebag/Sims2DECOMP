struct AptSFBCB_GBCB {
    char pad[0x34];
    void* m_byteCodeBase;
    void* GetByteCodeBase();
};

void* AptSFBCB_GBCB::GetByteCodeBase() {
    return m_byteCodeBase;
}

struct AptSFBCB_GBCS {
    char pad[0x38];
    int m_byteCodeSize;
    int GetByteCodeSize();
};

int AptSFBCB_GBCS::GetByteCodeSize() {
    return m_byteCodeSize;
}

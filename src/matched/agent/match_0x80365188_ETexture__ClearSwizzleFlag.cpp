struct ETexture {
    char _p[0x08];
    unsigned int m_flags;
    void ClearSwizzleFlag();
};
void ETexture::ClearSwizzleFlag() { m_flags &= ~0x80u; }

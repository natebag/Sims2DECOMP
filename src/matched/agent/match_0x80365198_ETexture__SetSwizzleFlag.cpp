struct ETexture {
    char _p[0x08];
    unsigned int m_flags;
    void SetSwizzleFlag();
};
void ETexture::SetSwizzleFlag() { m_flags |= 0x80; }

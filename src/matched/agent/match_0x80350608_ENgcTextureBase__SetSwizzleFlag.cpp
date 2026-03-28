struct ENgcTextureBase {
    char _p[0x08];
    unsigned int m_flags;
    void SetSwizzleFlag();
};
void ENgcTextureBase::SetSwizzleFlag() { m_flags |= 0x80; }

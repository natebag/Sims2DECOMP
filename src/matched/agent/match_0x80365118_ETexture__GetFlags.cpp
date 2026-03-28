struct ETexture {
    char _p[0x08];
    unsigned int m_flags;
    unsigned int GetFlags();
};
unsigned int ETexture::GetFlags() { return m_flags; }

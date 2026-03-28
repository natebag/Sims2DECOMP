/* 0x80365198 (16 bytes) - ETexture::SetSwizzleFlag(void) */
class ETexture {
    int m_f0;
    unsigned int m_flags;
public:
    void SetSwizzleFlag();
};
void ETexture::SetSwizzleFlag() { m_flags |= 0x80; }

// 0x80365178 ETexture::ClearTileFlags (16b)
struct ETexture {
    char _p[0x08];
    unsigned int m_flags;
    void ClearTileFlags();
};
void ETexture::ClearTileFlags() { m_flags &= 0xFFFFFFFC; }

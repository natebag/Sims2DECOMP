// 0x803505B8 (28B) ENgcTextureBase::ClearTileFlags(void)

struct ENgcTB_CTF {
    char pad_00[8];
    unsigned int m_08;
    char pad_0C[0x5C];
    unsigned int m_68;
    unsigned int m_6C;
    void ClearTileFlags();
};

void ENgcTB_CTF::ClearTileFlags() {
    m_08 &= ~3u;
    m_68 = 0;
    m_6C = 0;
}

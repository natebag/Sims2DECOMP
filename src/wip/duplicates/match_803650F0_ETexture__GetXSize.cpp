// 0x803650F0 (8 bytes) - ETexture::GetXSize(void)
// lhz r3, 16(r3); blr

class ETexture {
public:
    int pad0; int pad1; int pad2; int pad3;
    unsigned short m_xSize; // 0x10

    unsigned short GetXSize();
};

unsigned short ETexture::GetXSize() { return m_xSize; }

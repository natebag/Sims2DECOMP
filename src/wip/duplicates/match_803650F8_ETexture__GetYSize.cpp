// 0x803650F8 (8 bytes) - ETexture::GetYSize(void)
// lhz r3, 18(r3); blr

class ETexture {
public:
    int pad0; int pad1; int pad2; int pad3;
    unsigned short m_xSize; // 0x10
    unsigned short m_ySize; // 0x12

    unsigned short GetYSize();
};

unsigned short ETexture::GetYSize() { return m_ySize; }

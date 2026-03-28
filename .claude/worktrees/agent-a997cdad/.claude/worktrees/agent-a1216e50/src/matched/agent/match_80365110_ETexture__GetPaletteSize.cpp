// 0x80365110 (8 bytes) - ETexture::GetPaletteSize(void)
// lhz r3, 20(r3); blr

class ETexture {
public:
    int pad0; int pad1; int pad2; int pad3;
    unsigned short m_xSize; // 0x10
    unsigned short m_ySize; // 0x12
    unsigned short m_paletteSize; // 0x14

    unsigned short GetPaletteSize();
};

unsigned short ETexture::GetPaletteSize() { return m_paletteSize; }

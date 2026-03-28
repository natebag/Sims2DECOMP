struct ETexture {
    char _pad[0x14];
    unsigned short m_paletteSize;
    unsigned short GetPaletteSize();
};
unsigned short ETexture::GetPaletteSize() { return m_paletteSize; }

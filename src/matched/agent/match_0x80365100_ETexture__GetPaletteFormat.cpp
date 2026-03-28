struct ETexture {
    char _pad[0x19];
    unsigned char m_paletteFormat;
    unsigned char GetPaletteFormat();
};
unsigned char ETexture::GetPaletteFormat() { return m_paletteFormat; }

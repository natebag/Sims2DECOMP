struct ETexture {
    char _pad[0x1b];
    unsigned char m_bitsPerPaletteEntry;
    unsigned char GetBitsPerPaletteEntry();
};
unsigned char ETexture::GetBitsPerPaletteEntry() { return m_bitsPerPaletteEntry; }

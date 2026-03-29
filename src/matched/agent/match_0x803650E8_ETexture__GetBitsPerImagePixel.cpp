struct ETexture {
    char _p[0x1a];
    unsigned char m_bitsPerImagePixel;
    unsigned char GetBitsPerImagePixel();
};
unsigned char ETexture::GetBitsPerImagePixel() { return m_bitsPerImagePixel; }

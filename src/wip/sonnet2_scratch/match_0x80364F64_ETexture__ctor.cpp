// FLAGS: -fno-schedule-insns
// ETexture::ETexture(void) at 0x80364F64 (96 bytes)

extern int __vt__8ETexture[];

struct ETexture {
    unsigned int m_word00;
    unsigned int m_word04;
    unsigned int m_word08;
    unsigned int m_word0C;
    unsigned short m_xSize;
    unsigned short m_ySize;
    unsigned short m_paletteSize;
    unsigned short m_word16;
    unsigned char m_imageFormat;
    unsigned char m_paletteFormat;
    unsigned char m_bitsPerImagePixel;
    unsigned char m_bitsPerPaletteEntry;
    unsigned int m_word1C;
    unsigned int m_sentinel;
    int *m_vtable;
    ETexture();
};

ETexture::ETexture() {
    m_vtable = __vt__8ETexture;
    m_ySize = 64;
    m_xSize = 64;
    m_imageFormat = 1;
    m_bitsPerImagePixel = 32;
    m_word1C = 0;
    m_sentinel = 0x900DBEEF;
    m_word00 = 0;
    m_word04 = 0;
    m_word08 = 0;
    m_paletteFormat = 0;
    m_bitsPerPaletteEntry = 0;
    m_paletteSize = 0;
    m_word16 = 0;
}

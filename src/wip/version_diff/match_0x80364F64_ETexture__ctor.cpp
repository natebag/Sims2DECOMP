/* ETexture::ETexture(void) at 0x80364F64 (96 bytes)
 * NON_MATCHING: store scheduling mismatch — FIFO vs LIFO ready-list tiebreaker.
 * DOL's SN BUILD v1.76 emits stores in source order (FIFO); our SN BUILD v3.93
 * prefers last-computed register r10 (sentinel) before r0 (word1C) after bpp store.
 * Best achieved: first 3 stores after vtable match (xSize, imageFormat, bpp);
 * store 4 diverges (DOL: word1C@0x1c, compiled: sentinel@0x20).
 * Key trick: m_ySize=64 must appear BEFORE m_xSize=64 in source to force
 * xSize(0x10) before imageFormat(0x18) in the schedule (r6 treated as single-use
 * at xSize point when ySize gets the earlier source uid).
 */

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

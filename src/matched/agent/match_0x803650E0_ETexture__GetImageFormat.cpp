struct ETexture {
    char _p[0x18];
    unsigned char m_imageFormat;
    unsigned char GetImageFormat();
};
unsigned char ETexture::GetImageFormat() { return m_imageFormat; }

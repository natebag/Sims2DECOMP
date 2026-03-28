struct ETexture {
    char _pad[0x18];
    unsigned char m_imageFormat;
    unsigned char GetImageFormat();
};
unsigned char ETexture::GetImageFormat() { return m_imageFormat; }

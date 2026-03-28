struct ETexture {
    char _pad[0x10];
    unsigned short m_xSize;
    unsigned short GetXSize();
};
unsigned short ETexture::GetXSize() { return m_xSize; }

struct ETexture {
    char _p[0x12];
    unsigned short m_ySize;
    unsigned short GetYSize();
};
unsigned short ETexture::GetYSize() { return m_ySize; }

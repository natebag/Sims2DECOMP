struct ETexture {
    char _p[0x20];
    unsigned int m_sentinel;
    int IsValid();
};
int ETexture::IsValid() {
    return m_sentinel == 0x900dbeef;
}

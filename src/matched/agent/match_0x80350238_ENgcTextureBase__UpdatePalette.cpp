struct ENgcTextureBase {
    char _pad[0x90];
    int m_pal;
    int UpdatePalette();
};
int ENgcTextureBase::UpdatePalette() { return m_pal; }

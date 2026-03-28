struct ENgcRenderSurface {
    char _pad[0x28];
    int m_tex;
    int GetTexture();
};
int ENgcRenderSurface::GetTexture() { return m_tex; }

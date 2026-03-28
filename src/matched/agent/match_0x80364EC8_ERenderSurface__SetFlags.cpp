struct ERenderSurface {
    char _p[0x08];
    unsigned int m_flags;
    void SetFlags(unsigned int v);
};
void ERenderSurface::SetFlags(unsigned int v) { m_flags = v; }

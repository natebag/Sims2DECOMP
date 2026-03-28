struct ERenderSurface {
    char _p[0x08];
    unsigned int m_flags;
    unsigned int GetFlags();
};
unsigned int ERenderSurface::GetFlags() { return m_flags; }

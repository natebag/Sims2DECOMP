struct ERenderSurface {
    char _p[0x04];
    int m_ySize;
    int GetYSize();
};
int ERenderSurface::GetYSize() { return m_ySize; }

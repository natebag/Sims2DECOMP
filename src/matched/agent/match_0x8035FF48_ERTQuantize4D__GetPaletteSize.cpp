struct ERTQuantize4D {
    char _p[0x1024];
    int m_val;
    int GetPaletteSize();
};
int ERTQuantize4D::GetPaletteSize() { return m_val; }

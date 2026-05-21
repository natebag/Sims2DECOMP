// 0x80364E58 ERenderSurface::Create(ERenderSurfaceDef const&) (96B)

struct ERenderSurfaceDef {
    unsigned int a, b, c, d, e, f, g, h;
};

struct ERenderSurface {
    ERenderSurfaceDef m_def;
    int Create(const ERenderSurfaceDef& def);
};

int ERenderSurface::Create(const ERenderSurfaceDef& def) {
    m_def = def;
    return 1;
}

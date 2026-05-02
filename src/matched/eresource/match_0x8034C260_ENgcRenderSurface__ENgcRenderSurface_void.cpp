// 0x8034C260 (72B) ENgcRenderSurface::ENgcRenderSurface(void)
// SI ctor — ERenderSurface base + vtable @ +0x20 + 2 zero stores.

extern char vt_ENgcRenderSurface[];

class ERenderSurface {
public:
    void* m_base_vt;
    ERenderSurface();
};

class ENgcRenderSurface : public ERenderSurface {
public:
    char pad04_1F[0x20 - 4];
    void* m_vt_at_20;
    int m_field24;
    int m_field28;
    ENgcRenderSurface();
};

ENgcRenderSurface::ENgcRenderSurface() {
    m_field24 = 0;
    m_vt_at_20 = (void*)vt_ENgcRenderSurface;
    m_field28 = 0;
}

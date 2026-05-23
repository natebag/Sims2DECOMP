// 0x8033B6EC (52B) ENgcRenderer::~ENgcRenderer(void)
// Vtable-at-+0x338 MI recipe (extern char vt[]) — descoped vtable_at_offset.
// Reset vtable, clear SDA flag, chain to ERenderer base dtor.

extern char vt_ENgcRenderer[];

class ERenderer {
public:
    void* m_base_vtable;
    ~ERenderer();
};

extern int s_renderActive;

class ENgcRenderer : public ERenderer {
public:
    char  pad[0x338 - 4];
    void* m_vt_at_338;

    ~ENgcRenderer();
};

ENgcRenderer::~ENgcRenderer() {
    m_vt_at_338 = vt_ENgcRenderer;
    s_renderActive = 0;
}

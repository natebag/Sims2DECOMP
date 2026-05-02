// 0x80364D38 (60B) ERenderer::ERenderer(void)
// SI ctor — EThread base + vtable assignment at +0x338.

extern char vt_ERenderer[];

class EThread {
public:
    void* m_base_vt;
    EThread();
};

class ERenderer : public EThread {
public:
    char pad[0x338 - 4];
    void* m_vt_at_338;
    ERenderer();
};

ERenderer::ERenderer() {
    m_vt_at_338 = (void*)vt_ERenderer;
}

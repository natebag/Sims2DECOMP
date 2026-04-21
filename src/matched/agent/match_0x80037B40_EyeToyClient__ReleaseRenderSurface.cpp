// 0x80037B40 EyeToyClient::ReleaseRenderSurface(ERenderSurface*) (64B)
struct ERenderSurface;

struct VTable {
    char pad[216];
    short m_adj;
    short m_pad;
    void (*m_fn)(void*, ERenderSurface*);
};

struct Engine {
    VTable* m_vt;
};

extern Engine* g_engine;  // SDA

void EyeToyClient__ReleaseRenderSurface(ERenderSurface* surf) {
    if (surf == 0) return;
    Engine* e = g_engine;
    VTable* vt = e->m_vt;
    vt->m_fn((char*)e + vt->m_adj, surf);
}

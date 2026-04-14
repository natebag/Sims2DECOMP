// 0x80037A5C EyeToyClient::ReleaseTexture(ETexture*) (60B)
struct ETexture;

struct VTable {
    char pad[192];
    short m_adj;
    short m_pad;
    void (*m_fn)(void*, ETexture*);
};

struct Engine {
    VTable* m_vt;
};

extern Engine* g_engine;  // SDA (at r13-26392)

void EyeToyClient__ReleaseTexture(ETexture* tex) {
    if (tex == 0) return;
    Engine* e = g_engine;
    VTable* vt = e->m_vt;
    vt->m_fn((char*)e + vt->m_adj, tex);
}

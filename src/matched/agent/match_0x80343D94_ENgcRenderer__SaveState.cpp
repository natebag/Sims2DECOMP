struct EDLEntry;
struct ENgcRenderStateCache;

void ENgcRenderStateCache_SaveState(ENgcRenderStateCache*);

struct ENgcRenderer {
    char _pad[0x4D8];
    ENgcRenderStateCache* m_pStateCache;
    void SaveState(EDLEntry*);
};

void ENgcRenderer::SaveState(EDLEntry*) {
    ENgcRenderStateCache_SaveState(m_pStateCache);
}

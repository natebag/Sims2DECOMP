struct EDLEntry;
struct ENgcRenderStateCache;

void ENgcRenderStateCache_RestoreState(ENgcRenderStateCache*);

struct ENgcRenderer {
    char _pad[0x4D8];
    ENgcRenderStateCache* m_pStateCache;
    void RestoreState(EDLEntry*);
};

void ENgcRenderer::RestoreState(EDLEntry*) {
    ENgcRenderStateCache_RestoreState(m_pStateCache);
}

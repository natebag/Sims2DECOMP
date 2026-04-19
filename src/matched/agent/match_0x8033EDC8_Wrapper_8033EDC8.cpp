/* ENgcRenderer::RestoreViewport(void) at 0x8033EDC8 (36B) */
// 0x8033EDC8 (36 bytes)
class ENgcRenderStateCache {
public:
    void RestoreViewportState();
};
struct ENgcRendererProxy {
    int _pad[310];  // 0x4D8 bytes
    ENgcRenderStateCache* m_stateCache;
};
class ENgcRenderer {
public:
    void RestoreViewport();
};
void ENgcRenderer::RestoreViewport() {
    ((ENgcRendererProxy*)this)->m_stateCache->RestoreViewportState();
}

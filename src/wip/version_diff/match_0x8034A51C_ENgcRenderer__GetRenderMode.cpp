/* ENgcRenderer::GetRenderMode(void) at 0x8034A51C (28B) */

struct ENgcRenderMode_GRM {
    char m_data[1];
};

struct ENgcRenderer_GRM {
    char _pad34c[0x34c];
    int m_active;
    char _pad350[0x14];
    ENgcRenderMode_GRM m_renderMode;
    ENgcRenderMode_GRM* GetRenderMode();
};

ENgcRenderMode_GRM* ENgcRenderer_GRM::GetRenderMode() {
    if (!m_active) return 0;
    return &m_renderMode;
}

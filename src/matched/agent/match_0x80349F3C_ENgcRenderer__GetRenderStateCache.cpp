struct ENgcRenderer {
    char _pad[0x4d8];
    int m_val;
    int GetRenderStateCache();
};
int ENgcRenderer::GetRenderStateCache() { return m_val; }

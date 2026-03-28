struct ENgcRenderer {
    char _p[0x4638];
    int m_currentTexture[4];
    int GetCurrentTexture(int i);
};
int ENgcRenderer::GetCurrentTexture(int i) { return m_currentTexture[i]; }

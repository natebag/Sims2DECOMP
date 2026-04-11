struct ENgcRenderer {
    char _p1[0x3a4];
    float m_alpha;
    char _p2[0x168];
    int m_dirty;
    void SetAlpha(float a);
};
void ENgcRenderer::SetAlpha(float a) { m_alpha = a; m_dirty = 1; }

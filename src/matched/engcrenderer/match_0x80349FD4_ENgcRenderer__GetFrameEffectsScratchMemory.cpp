struct ENgcRenderer {
    char _pad[0x464c];
    int m_val;
    int GetFrameEffectsScratchMemory();
};
int ENgcRenderer::GetFrameEffectsScratchMemory() { return m_val; }

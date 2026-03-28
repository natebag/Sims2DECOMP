class ERTexture;
class ENgcRenderer { char pad[17976]; ERTexture *m_currentTexture[8]; public: ERTexture *GetCurrentTexture(int); };
ERTexture *ENgcRenderer::GetCurrentTexture(int idx) { return m_currentTexture[idx]; }

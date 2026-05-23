struct REffectsEmitter {
    char _p[0x1c];
    int m_tex;
    int GetTexture();
};
int REffectsEmitter::GetTexture() { return m_tex; }

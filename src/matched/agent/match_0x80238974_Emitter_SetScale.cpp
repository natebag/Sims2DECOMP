struct EmitterInner {
    char _pad[0xBC];
    float m_scale;
};
struct Emitter {
    char _pad[0x7C];
    EmitterInner *m_inner;
    void SetScale(float scale);
};
void Emitter::SetScale(float scale) { m_inner->m_scale = scale; }

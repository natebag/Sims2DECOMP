// 0x8023867C (32B) Emitter::GetNumActiveParticles(void)
struct EmitterInner2 { char pad[0x84]; int m_84; };
struct EmitterInner1 { char pad[0x54]; EmitterInner2* m_54; };
struct Emitter_GNAP {
    char pad[0x7C];
    EmitterInner1* m_7C;
    int GetNumActiveParticles();
};
int Emitter_GNAP::GetNumActiveParticles() {
    EmitterInner1* p = m_7C;
    if (!p) return 0;
    return p->m_54->m_84;
}

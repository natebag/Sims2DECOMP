// 0x80303ABC (12B) PSystemGetNumActiveParticles
// Return SDA-global pSystem->field_8 (active particle count).

class PSystem {
public:
    char pad[8];
    int m_activeParticles;
};

extern PSystem* g_pSystem;

int PSystemGetNumActiveParticles() {
    return g_pSystem->m_activeParticles;
}

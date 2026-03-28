struct EOrderTableData;

struct ELevelDrawData {
    char pad[0x24];
    void *m_userData;
};

struct EmitterInner {
    char pad[0x7C];
    void *m_pemitter;
};

extern void PEmitterSubmitParticlesFunc(void *pemitter, float dt);
extern float g_emitterDt;

struct Emitter {
    char pad[0xA8];
    int m_fieldA8;
    int m_fieldAC;
    int m_fieldB0;
    int m_fieldB4;
    int m_fieldB8;

    void PEmitterSubmitParticlesCB(ELevelDrawData &data, EOrderTableData *otd);
};

void Emitter::PEmitterSubmitParticlesCB(ELevelDrawData &data, EOrderTableData *otd) {
    EmitterInner *inner = (EmitterInner *)data.m_userData;
    void *pem = inner->m_pemitter;
    if (pem != 0) {
        PEmitterSubmitParticlesFunc(pem, g_emitterDt);
        m_fieldAC = 0;
        m_fieldB4 = 0;
        m_fieldA8 = 0;
        m_fieldB8 = 0;
    }
}

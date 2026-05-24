// 0x80303730 PEmitterGetNumActiveParticles (12 B)
// FLAGS: -fno-schedule-insns
// Pattern: lwz r9,0x54(r3); lwz r3,0x84(r9); blr

struct PEmitterData {
    char _pad[0x84];
    int m_numActiveParticles; // 0x84
};

struct PEmitter {
    char _pad[0x54];
    PEmitterData* m_data; // 0x54
};

int PEmitterGetNumActiveParticles(PEmitter* emitter) {
    return emitter->m_data->m_numActiveParticles;
}

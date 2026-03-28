// 0x80303730 (12 bytes) - PEmitterGetNumActiveParticles
// lwz r9, 84(r3); lwz r3, 132(r9); blr

struct PEmitterInner {
    char pad[132]; // 0x00-0x83
    int numActiveParticles; // 0x84
};

struct PEmitter {
    char pad[84]; // 0x00-0x53
    PEmitterInner* inner; // 0x54
};

int PEmitterGetNumActiveParticles(PEmitter* e) {
    return e->inner->numActiveParticles;
}

typedef unsigned char u8;

void cleanupParticlesDelayed(u8*, u8*);

void SAnimator2_checkParticleCleanup(u8* self) {
    if (*(int*)(self + 0x61C) & 0x10000) {
        cleanupParticlesDelayed(self, self + 0x5D0);
        *(int*)(self + 0x61C) &= ~0x10000;
    }
    if (*(int*)(self + 0x61C) & 0x20000) {
        cleanupParticlesDelayed(self, self + 0x5DC);
        *(int*)(self + 0x61C) &= ~0x20000;
    }
}

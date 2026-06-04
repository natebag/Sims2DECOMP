// 0x802B512C (84B) AptValueGC_PoolManager::AllocateAptValueGC(unsigned int)
//
// Allocates a GC-tracked value object from the underlying pool, then, depending
// on the current GC phase byte, marks the new object so the in-progress sweep
// won't reclaim it: phase 4 sets the high bit of word @0x04, phase 0 sets the
// high bit of word @0x00. (Other phases leave it unmarked.)
//
// The mark is a 1-bit MSB bitfield assigned from a value (not a literal), which
// is what makes SN ProDG emit the `rlwimi r0,r9,31,0,0` insert with a hoisted
// `li r9,1` rather than folding to `oris`. Clean structural C++, no surgery.

struct DOGMA_PoolManager {
    static void* Allocate(unsigned int size);
};

struct AptGCObj {
    unsigned int mark0 : 1;   // 0x00 MSB (0x80000000)
    unsigned int rest0 : 31;
    unsigned int mark4 : 1;   // 0x04 MSB
    unsigned int rest4 : 31;
};

extern unsigned char g_aptGCPhase;   // SDA: gc-phase discriminant

struct AptValueGC_PoolManager {
    static void* AllocateAptValueGC(unsigned int size);
};

void* AptValueGC_PoolManager::AllocateAptValueGC(unsigned int size) {
    AptGCObj* v = (AptGCObj*)DOGMA_PoolManager::Allocate(size);
    unsigned char phase = g_aptGCPhase;
    unsigned int mark = 1;
    if (phase == 4) {
        v->mark4 = mark;
    } else if (phase == 0) {
        v->mark0 = mark;
    }
    return v;
}

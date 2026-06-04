// 0x802B5180 (104B) AptValueGC_PoolManager::DeallocateAptValueGC(unsigned int, AptValueGC*)
//
// Inverse of AllocateAptValueGC: returns the value object to the pool, and if the
// pool actually freed it, clears the sweep-protect mark bit (word @0x04 in phase 4,
// word @0x00 in phase 0). The clear is a 1-bit MSB bitfield set from a value var
// (0) -> SN's `li r9,0` + `rlwimi r0,r9,31,0,0` insert. Clean structural C++.

struct AptGCObj {
    unsigned int mark0 : 1;   // 0x00 MSB
    unsigned int rest0 : 31;
    unsigned int mark4 : 1;   // 0x04 MSB
    unsigned int rest4 : 31;
};

struct DOGMA_PoolManager {
    static int Deallocate(unsigned int size, void* ptr);
};

extern unsigned char g_aptGCPhase;

struct AptValueGC_PoolManager {
    static void DeallocateAptValueGC(unsigned int size, AptGCObj* obj);
};

void AptValueGC_PoolManager::DeallocateAptValueGC(unsigned int size, AptGCObj* obj) {
    if (DOGMA_PoolManager::Deallocate(size, obj)) {
        unsigned char phase = g_aptGCPhase;
        unsigned int clr = 0;
        if (phase == 4) {
            obj->mark4 = clr;
        } else if (phase == 0) {
            obj->mark0 = clr;
        }
    }
}

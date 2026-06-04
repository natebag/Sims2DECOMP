// 0x802B5534 (120B) AptValueGC_PoolManager::StaticInitialize(void)
//
// One-time GC value-pool init: seeds three config bytes, scans a 46-entry size
// table for its min (and max — tracked but only the min is consumed), zeroes a
// word counter, clamps the min to at least 12, and stores it as the pool's
// minimum block size. Leaf, default scheduling (the scheduler interleaves the
// three head stores with the loop-constant setup, matching the DOL). Clean C++.

extern unsigned char g_aptGCByte0;   // -21328
extern unsigned char g_aptGCPhase;   // -21327
extern unsigned char g_aptGCByte8;   // -21336
extern unsigned int  g_aptGCWord4;   // -21332
extern unsigned char g_aptGCMinByte; // -21335
extern unsigned char g_aptGCTable[]; // size table @ 0x80400E94

struct AptValueGC_PoolManager {
    static void StaticInitialize();
};

void AptValueGC_PoolManager::StaticInitialize() {
    g_aptGCByte0 = 4;
    g_aptGCPhase = 0;
    g_aptGCByte8 = 8;

    unsigned int hi = 0;
    unsigned int lo = 1000000;
    for (int i = 1; i <= 46; i++) {
        unsigned int v = g_aptGCTable[i];
        if (v > hi) hi = v;
        if (v < lo) lo = v;
    }

    g_aptGCWord4 = 0;
    if (lo <= 11) lo = 12;
    g_aptGCMinByte = (unsigned char)lo;
}

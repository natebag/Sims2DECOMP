// 0x802B5534 AptValueGC_PoolManager::StaticInitialize(void) (120 B)
//
// One-time GC value-pool init: seeds three SDA config bytes (4, 0, 8), scans a
// 46-entry size table (indices 1..46) tracking the running min (and a max the
// DOL computes but never stores), clears an SDA word, clamps the min up to 12,
// and stores it. mtctr/bdnz loop. Plain static init (no guard/atexit), so
// verified at section offset 0.
extern "C" unsigned char g_b5350;
extern "C" unsigned char g_b534f;
extern "C" unsigned char g_b5358;
extern "C" unsigned int  g_w5354;
extern "C" unsigned char g_b5357;
extern "C" unsigned char g_sizeTable[];

extern "C" void f_802B5534()
{
    g_b5350 = 4;
    g_b534f = 0;
    g_b5358 = 8;
    unsigned int max = 0;
    unsigned int min = 1000000;
    for (int i = 1; i <= 46; i++) {
        unsigned int v = g_sizeTable[i];
        if (v > max) max = v;
        if (v < min) min = v;
    }
    g_w5354 = 0;
    if (min <= 11)
        min = 12;
    g_b5357 = (unsigned char)min;
}

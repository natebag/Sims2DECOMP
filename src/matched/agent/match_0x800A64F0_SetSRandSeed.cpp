/* SetSRandSeed(unsigned int) at 0x800A64F0 (8B) */

extern unsigned int g_srandSeed;

void SetSRandSeed(unsigned int seed) {
    g_srandSeed = seed;
}

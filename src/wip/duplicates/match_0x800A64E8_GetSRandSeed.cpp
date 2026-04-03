/* GetSRandSeed(void) at 0x800A64E8 (8B) */

extern unsigned int g_srandSeed;

unsigned int GetSRandSeed(void) {
    return g_srandSeed;
}

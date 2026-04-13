/* CARDSrand at 0x80385494 (8B) */

extern int CARDSrandSeed;

void CARDSrand(int seed) {
    CARDSrandSeed = seed;
}

// 0x80352190 (80B) Effects::SetSeed2(int)
// Sets s_seed + s_seedIdx, then fills gRandTable2[0..19] via PMRand() loop.

namespace Effects {

extern int s_seed;
extern int s_seedIdx;
extern int gRandTable2[20];

int PMRand();
void SetSeed2(int seed);

void SetSeed2(int seed) {
    s_seed = seed;
    s_seedIdx = 20;
    int* p = gRandTable2;
    int* end = &gRandTable2[19];
    do {
        *p = PMRand();
        p++;
    } while ((int)p <= (int)end);
}

}  // namespace Effects

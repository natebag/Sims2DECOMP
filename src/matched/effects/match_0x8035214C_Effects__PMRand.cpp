// 0x8035214C Effects::PMRand(void) (68B)
// Park-Miller LCG with multiplier 16807 and modulus 2^31-1.
//
// Cracked S13 Lane E E-9 (2026-05-01) via source-level recipe — NO mutator
// needed. Key: use UNSIGNED right shift on the seed to get `srwi` (logical)
// instead of `srawi` (arithmetic) which `int >> 16` produces. Once the
// shift kinds match DOL, the rest of the Park-Miller body falls into place
// with the standard split-multiply-recombine pattern.

extern int g_pmrand_seed;  // SDA r13-22460

namespace Effects {
int PMRand();
}

int Effects::PMRand() {
    unsigned int s = (unsigned int)g_pmrand_seed;
    unsigned int hi = s >> 16;
    int hi_mul = (int)hi * 16807;
    unsigned int lo = s & 0xFFFF;
    int lo_mul = (int)lo * 16807;
    int combined = (lo_mul + (int)(((unsigned int)hi_mul << 16) & 0x7FFFFFFF))
                 + (int)((unsigned int)hi_mul >> 15);
    g_pmrand_seed = combined;
    if (combined < 0) {
        combined += 0x80000001;
        g_pmrand_seed = combined;
    }
    return g_pmrand_seed;
}

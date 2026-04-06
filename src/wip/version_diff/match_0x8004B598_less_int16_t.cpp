// less_int16_t(void *, void *)
// Address: 0x8004B598 | Size: 36 bytes
// Pattern: comparison function returning -1, 0, or 1
// Uses beqlr/bgelr branch-to-link-register optimization

extern "C" int less_int16_t(const short* a, const short* b) {
    short av = *a;
    short bv = *b;
    // Compiler generates beqlr/bgelr when returning immediately after compare
    if (av == bv) return 0;
    if (av > bv) return 1;
    return -1;
}

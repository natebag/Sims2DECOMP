// COMPILER: mwcc
// 0x8025ACB0 C_VECDotProduct (48B)
//
// Returns the dot product a.b. Dolphin SDK vec/vec.c. MWCC GC-1.2.5n.

struct Vec { float x, y, z; };

extern "C" float C_VECDotProduct(const Vec* a, const Vec* b) {
    return a->x * b->x + a->y * b->y + a->z * b->z;
}

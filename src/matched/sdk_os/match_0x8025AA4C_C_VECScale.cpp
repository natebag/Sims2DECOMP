// COMPILER: mwcc
// 0x8025AA4C C_VECScale (40B)
//
// Scales a vector by a scalar dst = src * scale. Dolphin SDK vec/vec.c. MWCC GC-1.2.5n.

struct Vec { float x, y, z; };

extern "C" void C_VECScale(const Vec* src, Vec* dst, float scale) {
    dst->x = src->x * scale;
    dst->y = src->y * scale;
    dst->z = src->z * scale;
}

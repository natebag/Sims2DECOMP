// COMPILER: mwcc
// 0x8025AB9C C_VECSquareMag (36B)
//
// Returns the squared magnitude x*x + y*y + z*z. Dolphin SDK vec/vec.c. MWCC GC-1.2.5n.

struct Vec { float x, y, z; };

extern "C" float C_VECSquareMag(const Vec* v) {
    return v->x * v->x + v->y * v->y + v->z * v->z;
}

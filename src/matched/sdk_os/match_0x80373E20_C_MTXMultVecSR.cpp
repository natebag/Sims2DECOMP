// COMPILER: mwcc
// 0x80373E20 C_MTXMultVecSR (124B) — Dolphin SDK mtx/mtx.c
//
// Transforms a vector by the scale/rotation (upper 3x3) of a 3x4 matrix,
// ignoring the translation column. Results via temporaries for aliasing.
// MWCC GC-1.2.5n.

typedef float Mtx[3][4];
struct Vec { float x, y, z; };

extern "C" void C_MTXMultVecSR(const Mtx m, const Vec* src, Vec* dst) {
    float x = m[0][0]*src->x + m[0][1]*src->y + m[0][2]*src->z;
    float y = m[1][0]*src->x + m[1][1]*src->y + m[1][2]*src->z;
    float z = m[2][0]*src->x + m[2][1]*src->y + m[2][2]*src->z;
    dst->x = x;
    dst->y = y;
    dst->z = z;
}

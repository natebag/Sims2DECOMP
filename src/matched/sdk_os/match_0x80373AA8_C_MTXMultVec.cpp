// COMPILER: mwcc
// 0x80373AA8 C_MTXMultVec (148B) — Dolphin SDK mtx/mtx.c
//
// Transforms a point by a 3x4 matrix (includes translation). Results go through
// temporaries so dst may alias src. MWCC GC-1.2.5n reproduces the interleaved
// schedule from the natural row expressions.

typedef float Mtx[3][4];
struct Vec { float x, y, z; };

extern "C" void C_MTXMultVec(const Mtx m, const Vec* src, Vec* dst) {
    float x = m[0][0]*src->x + m[0][1]*src->y + m[0][2]*src->z + m[0][3];
    float y = m[1][0]*src->x + m[1][1]*src->y + m[1][2]*src->z + m[1][3];
    float z = m[2][0]*src->x + m[2][1]*src->y + m[2][2]*src->z + m[2][3];
    dst->x = x;
    dst->y = y;
    dst->z = z;
}

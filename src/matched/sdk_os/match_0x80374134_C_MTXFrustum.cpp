// COMPILER: mwcc
// 0x80374134 C_MTXFrustum (156B) — Dolphin SDK mtx/mtx44.c
//
// Builds a 4x4 perspective frustum projection matrix. MWCC GC-1.2.5n.

typedef float Mtx44[4][4];

extern "C" void C_MTXFrustum(Mtx44 m, float t, float b, float l, float r, float n, float f) {
    float tmp;
    tmp = 1.0f / (r - l);
    m[0][0] = (2.0f * n) * tmp;
    m[0][1] = 0.0f;
    m[0][2] = (r + l) * tmp;
    m[0][3] = 0.0f;

    tmp = 1.0f / (t - b);
    m[1][0] = 0.0f;
    m[1][1] = (2.0f * n) * tmp;
    m[1][2] = (t + b) * tmp;
    m[1][3] = 0.0f;

    tmp = 1.0f / (f - n);
    m[2][0] = 0.0f;
    m[2][1] = 0.0f;
    m[2][2] = -n * tmp;
    m[2][3] = -(f * n) * tmp;

    m[3][0] = 0.0f;
    m[3][1] = 0.0f;
    m[3][2] = -1.0f;
    m[3][3] = 0.0f;
}

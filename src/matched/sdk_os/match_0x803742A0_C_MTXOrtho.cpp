// COMPILER: mwcc
// 0x803742A0 C_MTXOrtho (152B) — Dolphin SDK mtx/mtx44.c
//
// Builds a 4x4 orthographic projection matrix. MWCC GC-1.2.5n.

typedef float Mtx44[4][4];

extern "C" void C_MTXOrtho(Mtx44 m, float t, float b, float l, float r, float n, float f) {
    float tmp;
    tmp = 1.0f / (r - l);
    m[0][0] =  2.0f * tmp;
    m[0][1] =  0.0f;
    m[0][2] =  0.0f;
    m[0][3] = -(r + l) * tmp;

    tmp = 1.0f / (t - b);
    m[1][0] =  0.0f;
    m[1][1] =  2.0f * tmp;
    m[1][2] =  0.0f;
    m[1][3] = -(t + b) * tmp;

    tmp = 1.0f / (f - n);
    m[2][0] =  0.0f;
    m[2][1] =  0.0f;
    m[2][2] = -1.0f * tmp;
    m[2][3] = -f * tmp;

    m[3][0] =  0.0f;
    m[3][1] =  0.0f;
    m[3][2] =  0.0f;
    m[3][3] =  1.0f;
}

// COMPILER: mwcc
// 0x80373A20 C_MTXLightOrtho (136B) — Dolphin SDK mtx/mtxvec.c (light)
//
// Builds a 3x4 texture-projection orthographic matrix with S/T scale and
// translation baked into the third column. MWCC GC-1.2.5n.

typedef float Mtx[3][4];

extern "C" void C_MTXLightOrtho(Mtx m, float t, float b, float l, float r,
                                float scaleS, float scaleT, float transS, float transT) {
    float tmp;
    tmp = 1.0f / (r - l);
    m[0][0] = 2.0f * tmp * scaleS;
    m[0][1] = 0.0f;
    m[0][2] = 0.0f;
    m[0][3] = -(r + l) * tmp * scaleS + transS;

    tmp = 1.0f / (t - b);
    m[1][0] = 0.0f;
    m[1][1] = 2.0f * tmp * scaleT;
    m[1][2] = 0.0f;
    m[1][3] = -(t + b) * tmp * scaleT + transT;

    m[2][0] = 0.0f;
    m[2][1] = 0.0f;
    m[2][2] = 0.0f;
    m[2][3] = 1.0f;
}

// COMPILER: mwcc
// 0x80371F34 C_MTXIdentity (60B) — Dolphin SDK mtx/mtx.c
//
// Fills a 3x4 matrix with the identity. The 1.0f / 0.0f constants are loaded
// once each from the SDA float pool. MWCC GC-1.2.5n.

typedef float Mtx[3][4];

extern "C" void C_MTXIdentity(Mtx m) {
    m[0][0]=1.0f; m[0][1]=0.0f; m[0][2]=0.0f; m[0][3]=0.0f;
    m[1][0]=0.0f; m[1][1]=1.0f; m[1][2]=0.0f; m[1][3]=0.0f;
    m[2][0]=0.0f; m[2][1]=0.0f; m[2][2]=1.0f; m[2][3]=0.0f;
}

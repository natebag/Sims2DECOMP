// COMPILER: mwcc
// 0x803732E4 C_MTXScale (56B) — Dolphin SDK mtx/mtx.c
//
// Builds a 3x4 scale matrix. MWCC GC-1.2.5n.

typedef float Mtx[3][4];

extern "C" void C_MTXScale(Mtx m, float xS, float yS, float zS) {
    m[0][0]=xS;   m[0][1]=0.0f; m[0][2]=0.0f; m[0][3]=0.0f;
    m[1][0]=0.0f; m[1][1]=yS;   m[1][2]=0.0f; m[1][3]=0.0f;
    m[2][0]=0.0f; m[2][1]=0.0f; m[2][2]=zS;   m[2][3]=0.0f;
}

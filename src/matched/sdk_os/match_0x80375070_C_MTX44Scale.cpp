// COMPILER: mwcc
// 0x80375070 C_MTX44Scale (76B) — Dolphin SDK mtx/mtx44.c
//
// Builds a 4x4 scale matrix. MWCC GC-1.2.5n.

typedef float Mtx44[4][4];

extern "C" void C_MTX44Scale(Mtx44 m, float xS, float yS, float zS) {
    m[0][0]=xS;   m[0][1]=0.0f; m[0][2]=0.0f; m[0][3]=0.0f;
    m[1][0]=0.0f; m[1][1]=yS;   m[1][2]=0.0f; m[1][3]=0.0f;
    m[2][0]=0.0f; m[2][1]=0.0f; m[2][2]=zS;   m[2][3]=0.0f;
    m[3][0]=0.0f; m[3][1]=0.0f; m[3][2]=0.0f; m[3][3]=1.0f;
}

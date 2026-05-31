// COMPILER: mwcc
// 0x803731B0 C_MTXTrans (60B) — Dolphin SDK mtx/mtx.c
//
// Builds a 3x4 translation matrix. MWCC GC-1.2.5n.

typedef float Mtx[3][4];

extern "C" void C_MTXTrans(Mtx m, float xT, float yT, float zT) {
    m[0][0]=1.0f; m[0][1]=0.0f; m[0][2]=0.0f; m[0][3]=xT;
    m[1][0]=0.0f; m[1][1]=1.0f; m[1][2]=0.0f; m[1][3]=yT;
    m[2][0]=0.0f; m[2][1]=0.0f; m[2][2]=1.0f; m[2][3]=zT;
}

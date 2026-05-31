// COMPILER: mwcc
// 0x80374EF4 C_MTX44Trans (76B) — Dolphin SDK mtx/mtx44.c
//
// Builds a 4x4 translation matrix. MWCC GC-1.2.5n.

typedef float Mtx44[4][4];

extern "C" void C_MTX44Trans(Mtx44 m, float xT, float yT, float zT) {
    m[0][0]=1.0f; m[0][1]=0.0f; m[0][2]=0.0f; m[0][3]=xT;
    m[1][0]=0.0f; m[1][1]=1.0f; m[1][2]=0.0f; m[1][3]=yT;
    m[2][0]=0.0f; m[2][1]=0.0f; m[2][2]=1.0f; m[2][3]=zT;
    m[3][0]=0.0f; m[3][1]=0.0f; m[3][2]=0.0f; m[3][3]=1.0f;
}

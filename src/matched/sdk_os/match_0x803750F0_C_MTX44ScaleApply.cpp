// COMPILER: mwcc
// 0x803750F0 C_MTX44ScaleApply (180B) — Dolphin SDK mtx/mtx44.c
//
// Scales the first three rows of a 4x4 matrix by the corresponding axis factor
// and copies the fourth row unchanged. MWCC GC-1.2.5n.

typedef float Mtx44[4][4];

extern "C" void C_MTX44ScaleApply(const Mtx44 src, Mtx44 dst, float xS, float yS, float zS) {
    dst[0][0]=src[0][0]*xS; dst[0][1]=src[0][1]*xS; dst[0][2]=src[0][2]*xS; dst[0][3]=src[0][3]*xS;
    dst[1][0]=src[1][0]*yS; dst[1][1]=src[1][1]*yS; dst[1][2]=src[1][2]*yS; dst[1][3]=src[1][3]*yS;
    dst[2][0]=src[2][0]*zS; dst[2][1]=src[2][1]*zS; dst[2][2]=src[2][2]*zS; dst[2][3]=src[2][3]*zS;
    dst[3][0]=src[3][0]; dst[3][1]=src[3][1]; dst[3][2]=src[3][2]; dst[3][3]=src[3][3];
}

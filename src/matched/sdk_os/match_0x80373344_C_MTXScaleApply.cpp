// COMPILER: mwcc
// 0x80373344 C_MTXScaleApply (148B) — Dolphin SDK mtx/mtx.c
//
// Scales each row of a 3x4 matrix by the corresponding axis factor.
// MWCC GC-1.2.5n.

typedef float Mtx[3][4];

extern "C" void C_MTXScaleApply(const Mtx src, Mtx dst, float xS, float yS, float zS) {
    dst[0][0]=src[0][0]*xS; dst[0][1]=src[0][1]*xS; dst[0][2]=src[0][2]*xS; dst[0][3]=src[0][3]*xS;
    dst[1][0]=src[1][0]*yS; dst[1][1]=src[1][1]*yS; dst[1][2]=src[1][2]*yS; dst[1][3]=src[1][3]*yS;
    dst[2][0]=src[2][0]*zS; dst[2][1]=src[2][1]*zS; dst[2][2]=src[2][2]*zS; dst[2][3]=src[2][3]*zS;
}

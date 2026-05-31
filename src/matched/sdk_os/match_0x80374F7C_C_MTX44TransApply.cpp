// COMPILER: mwcc
// 0x80374F7C C_MTX44TransApply (152B) — Dolphin SDK mtx/mtx44.c
//
// Copies the matrix (when src and dst differ) then adds a translation to the
// fourth column of the first three rows. MWCC GC-1.2.5n.

typedef float Mtx44[4][4];

extern "C" void C_MTX44TransApply(const Mtx44 src, Mtx44 dst, float xT, float yT, float zT) {
    if (src != dst) {
        dst[0][0]=src[0][0]; dst[0][1]=src[0][1]; dst[0][2]=src[0][2];
        dst[1][0]=src[1][0]; dst[1][1]=src[1][1]; dst[1][2]=src[1][2];
        dst[2][0]=src[2][0]; dst[2][1]=src[2][1]; dst[2][2]=src[2][2];
        dst[3][0]=src[3][0]; dst[3][1]=src[3][1]; dst[3][2]=src[3][2]; dst[3][3]=src[3][3];
    }
    dst[0][3]=src[0][3]+xT;
    dst[1][3]=src[1][3]+yT;
    dst[2][3]=src[2][3]+zT;
}

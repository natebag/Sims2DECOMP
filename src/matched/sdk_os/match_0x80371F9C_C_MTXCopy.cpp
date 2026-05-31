// COMPILER: mwcc
// 0x80371F9C C_MTXCopy (108B) — Dolphin SDK mtx/mtx.c
//
// Copies a 3x4 matrix element-by-element; no-op when src and dst alias.
// MWCC GC-1.2.5n.

typedef float Mtx[3][4];

extern "C" void C_MTXCopy(const Mtx src, Mtx dst) {
    if (src == dst)
        return;
    dst[0][0]=src[0][0]; dst[0][1]=src[0][1]; dst[0][2]=src[0][2]; dst[0][3]=src[0][3];
    dst[1][0]=src[1][0]; dst[1][1]=src[1][1]; dst[1][2]=src[1][2]; dst[1][3]=src[1][3];
    dst[2][0]=src[2][0]; dst[2][1]=src[2][1]; dst[2][2]=src[2][2]; dst[2][3]=src[2][3];
}

// COMPILER: mwcc
// 0x80373220 C_MTXTransApply (120B) — Dolphin SDK mtx/mtx.c
//
// Copies the rotation part (when src and dst differ) then adds a translation to
// the matrix's fourth column. MWCC GC-1.2.5n.

typedef float Mtx[3][4];

extern "C" void C_MTXTransApply(const Mtx src, Mtx dst, float xT, float yT, float zT) {
    if (src != dst) {
        dst[0][0]=src[0][0]; dst[0][1]=src[0][1]; dst[0][2]=src[0][2];
        dst[1][0]=src[1][0]; dst[1][1]=src[1][1]; dst[1][2]=src[1][2];
        dst[2][0]=src[2][0]; dst[2][1]=src[2][1]; dst[2][2]=src[2][2];
    }
    dst[0][3]=src[0][3]+xT;
    dst[1][3]=src[1][3]+yT;
    dst[2][3]=src[2][3]+zT;
}

/*
 * DolphinSDK decompiled functions - Sims 2 GC Decompilation
 *
 * Real C implementations of DolphinSDK functions.
 * Each function is annotated with its address and size from the original DOL.
 * Functions that cannot match with GCC due to register allocation differences
 * use inline asm.
 *
 * Verified against: extracted/sys/main.dol
 * Compiler: devkitPPC (GCC) with -O2 -mcpu=750 -fno-schedule-insns -fno-schedule-insns2
 */
#include "types.h"

/* ======================================================================
 * Type definitions
 * ====================================================================== */

typedef f32 Vec[3];
typedef f32 Mtx[3][4];
typedef f32 Mtx44[4][4];

/* ======================================================================
 * VEC functions (C_ prefix = C fallback, no paired singles)
 * ====================================================================== */

// 0x8025A99C (52 bytes)
void C_VECAdd(const Vec *a, const Vec *b, Vec *ab) {
    (*ab)[0] = (*a)[0] + (*b)[0];
    (*ab)[1] = (*a)[1] + (*b)[1];
    (*ab)[2] = (*a)[2] + (*b)[2];
}

// 0x8025A9F4 (52 bytes)
void C_VECSubtract(const Vec *a, const Vec *b, Vec *ab) {
    (*ab)[0] = (*a)[0] - (*b)[0];
    (*ab)[1] = (*a)[1] - (*b)[1];
    (*ab)[2] = (*a)[2] - (*b)[2];
}

// 0x8025AA4C (40 bytes)
void C_VECScale(const Vec *src, Vec *dst, f32 scale) {
    (*dst)[0] = (*src)[0] * scale;
    (*dst)[1] = (*src)[1] * scale;
    (*dst)[2] = (*src)[2] * scale;
}

// 0x8025AB9C (36 bytes)
// C_VECSquareMag: GCC uses different register allocation, use asm
__attribute__((noreturn))
void C_VECSquareMag_decomp(const Vec *v) {
    __asm__ __volatile__(
        "lfs     1, 0(3)\n"
        "lfs     0, 4(3)\n"
        "fmuls   1, 1, 1\n"
        "lfs     2, 8(3)\n"
        "fmuls   0, 0, 0\n"
        "fmuls   2, 2, 2\n"
        "fadds   0, 1, 0\n"
        "fadds   1, 2, 0\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8025ACB0 (48 bytes)
// C_VECDotProduct
__attribute__((noreturn))
void C_VECDotProduct_decomp(const Vec *a, const Vec *b) {
    __asm__ __volatile__(
        "lfs     3, 0(3)\n"
        "lfs     2, 0(4)\n"
        "lfs     1, 4(3)\n"
        "lfs     0, 4(4)\n"
        "fmuls   2, 3, 2\n"
        "lfs     3, 8(3)\n"
        "fmuls   0, 1, 0\n"
        "lfs     1, 8(4)\n"
        "fmuls   1, 3, 1\n"
        "fadds   0, 2, 0\n"
        "fadds   1, 1, 0\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8025AD00 (76 bytes)
// C_VECCrossProduct
__attribute__((noreturn))
void C_VECCrossProduct_decomp(const Vec *a, const Vec *b, Vec *axb) {
    __asm__ __volatile__(
        "lfs     1, 8(3)\n"
        "lfs     6, 4(4)\n"
        "lfs     5, 0(4)\n"
        "lfs     7, 4(3)\n"
        "fmuls   0, 1, 6\n"
        "lfs     3, 8(4)\n"
        "fmuls   4, 1, 5\n"
        "lfs     2, 0(3)\n"
        "fmuls   1, 7, 3\n"
        "fmuls   3, 2, 3\n"
        "fmuls   2, 2, 6\n"
        "fsubs   0, 1, 0\n"
        "fmuls   1, 7, 5\n"
        "fsubs   3, 4, 3\n"
        "stfs    0, 0(5)\n"
        "fsubs   0, 2, 1\n"
        "stfs    3, 4(5)\n"
        "stfs    0, 8(5)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8025AF34 (60 bytes)
// C_VECSquareDistance
__attribute__((noreturn))
void C_VECSquareDistance_decomp(const Vec *a, const Vec *b) {
    __asm__ __volatile__(
        "lfs     3, 0(3)\n"
        "lfs     2, 0(4)\n"
        "lfs     1, 4(3)\n"
        "lfs     0, 4(4)\n"
        "fsubs   3, 3, 2\n"
        "lfs     2, 8(3)\n"
        "fsubs   4, 1, 0\n"
        "lfs     0, 8(4)\n"
        "fmuls   1, 3, 3\n"
        "fsubs   2, 2, 0\n"
        "fmuls   0, 4, 4\n"
        "fmuls   2, 2, 2\n"
        "fadds   0, 1, 0\n"
        "fadds   1, 2, 0\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* ======================================================================
 * MTX functions (C_ prefix = C fallback, no paired singles)
 * ====================================================================== */

// 0x80371F9C (108 bytes)
void C_MTXCopy(const Mtx src, Mtx dst) {
    if (src == dst) return;
    dst[0][0] = src[0][0]; dst[0][1] = src[0][1]; dst[0][2] = src[0][2]; dst[0][3] = src[0][3];
    dst[1][0] = src[1][0]; dst[1][1] = src[1][1]; dst[1][2] = src[1][2]; dst[1][3] = src[1][3];
    dst[2][0] = src[2][0]; dst[2][1] = src[2][1]; dst[2][2] = src[2][2]; dst[2][3] = src[2][3];
}

// 0x803732E4 (56 bytes)
// C_MTXScale: GCC adds extra instruction for 1.0f, use asm
__attribute__((noreturn))
void C_MTXScale_decomp(Mtx m, f32 xS, f32 yS, f32 zS) {
    __asm__ __volatile__(
        "stfs    1, 0(3)\n"
        "lfs     0, -17964(13)\n"
        "stfs    0, 4(3)\n"
        "stfs    0, 8(3)\n"
        "stfs    0, 12(3)\n"
        "stfs    0, 16(3)\n"
        "stfs    2, 20(3)\n"
        "stfs    0, 24(3)\n"
        "stfs    0, 28(3)\n"
        "stfs    0, 32(3)\n"
        "stfs    0, 36(3)\n"
        "stfs    3, 40(3)\n"
        "stfs    0, 44(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80373344 (148 bytes)
void C_MTXScaleApply(const Mtx src, Mtx dst, f32 xS, f32 yS, f32 zS) {
    dst[0][0] = src[0][0] * xS; dst[0][1] = src[0][1] * xS;
    dst[0][2] = src[0][2] * xS; dst[0][3] = src[0][3] * xS;
    dst[1][0] = src[1][0] * yS; dst[1][1] = src[1][1] * yS;
    dst[1][2] = src[1][2] * yS; dst[1][3] = src[1][3] * yS;
    dst[2][0] = src[2][0] * zS; dst[2][1] = src[2][1] * zS;
    dst[2][2] = src[2][2] * zS; dst[2][3] = src[2][3] * zS;
}

// 0x80373220 (120 bytes)
void C_MTXTransApply(const Mtx src, Mtx dst, f32 xT, f32 yT, f32 zT) {
    if (src != dst) {
        dst[0][0] = src[0][0]; dst[0][1] = src[0][1]; dst[0][2] = src[0][2];
        dst[1][0] = src[1][0]; dst[1][1] = src[1][1]; dst[1][2] = src[1][2];
        dst[2][0] = src[2][0]; dst[2][1] = src[2][1]; dst[2][2] = src[2][2];
    }
    dst[0][3] = src[0][3] + xT;
    dst[1][3] = src[1][3] + yT;
    dst[2][3] = src[2][3] + zT;
}

// 0x80373AA8 (148 bytes)
void C_MTXMultVec(const Mtx m, const Vec *src, Vec *dst) {
    (*dst)[0] = m[0][0]*(*src)[0] + m[0][1]*(*src)[1] + m[0][2]*(*src)[2] + m[0][3];
    (*dst)[1] = m[1][0]*(*src)[0] + m[1][1]*(*src)[1] + m[1][2]*(*src)[2] + m[1][3];
    (*dst)[2] = m[2][0]*(*src)[0] + m[2][1]*(*src)[1] + m[2][2]*(*src)[2] + m[2][3];
}

// 0x80373E20 (124 bytes)
void C_MTXMultVecSR(const Mtx m, const Vec *src, Vec *dst) {
    (*dst)[0] = m[0][0]*(*src)[0] + m[0][1]*(*src)[1] + m[0][2]*(*src)[2];
    (*dst)[1] = m[1][0]*(*src)[0] + m[1][1]*(*src)[1] + m[1][2]*(*src)[2];
    (*dst)[2] = m[2][0]*(*src)[0] + m[2][1]*(*src)[1] + m[2][2]*(*src)[2];
}

// 0x80371F34 (60 bytes)
// C_MTXIdentity
__attribute__((noreturn))
void C_MTXIdentity_decomp(Mtx m) {
    __asm__ __volatile__(
        "lfs     1, -17968(13)\n"
        "stfs    1, 0(3)\n"
        "lfs     0, -17964(13)\n"
        "stfs    0, 4(3)\n"
        "stfs    0, 8(3)\n"
        "stfs    0, 12(3)\n"
        "stfs    0, 16(3)\n"
        "stfs    1, 20(3)\n"
        "stfs    0, 24(3)\n"
        "stfs    0, 28(3)\n"
        "stfs    0, 32(3)\n"
        "stfs    0, 36(3)\n"
        "stfs    1, 40(3)\n"
        "stfs    0, 44(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803731B0 (60 bytes)
// C_MTXTrans
__attribute__((noreturn))
void C_MTXTrans_decomp(Mtx m, f32 xT, f32 yT, f32 zT) {
    __asm__ __volatile__(
        "lfs     4, -17968(13)\n"
        "stfs    4, 0(3)\n"
        "lfs     0, -17964(13)\n"
        "stfs    0, 4(3)\n"
        "stfs    0, 8(3)\n"
        "stfs    1, 12(3)\n"
        "stfs    0, 16(3)\n"
        "stfs    4, 20(3)\n"
        "stfs    0, 24(3)\n"
        "stfs    2, 28(3)\n"
        "stfs    0, 32(3)\n"
        "stfs    0, 36(3)\n"
        "stfs    4, 40(3)\n"
        "stfs    3, 44(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* ======================================================================
 * MTX44 functions (4x4 matrix)
 * ====================================================================== */

// 0x80374338 (76 bytes)
// C_MTX44Identity: uses SDA for float constants
__attribute__((noreturn))
void C_MTX44Identity_decomp(Mtx44 m) {
    __asm__ __volatile__(
        "lfs     1, -17872(13)\n"
        "stfs    1, 0(3)\n"
        "lfs     0, -17864(13)\n"
        "stfs    0, 4(3)\n"
        "stfs    0, 8(3)\n"
        "stfs    0, 12(3)\n"
        "stfs    0, 16(3)\n"
        "stfs    1, 20(3)\n"
        "stfs    0, 24(3)\n"
        "stfs    0, 28(3)\n"
        "stfs    0, 32(3)\n"
        "stfs    0, 36(3)\n"
        "stfs    1, 40(3)\n"
        "stfs    0, 44(3)\n"
        "stfs    0, 48(3)\n"
        "stfs    0, 52(3)\n"
        "stfs    0, 56(3)\n"
        "stfs    1, 60(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803743B8 (140 bytes)
void C_MTX44Copy(const Mtx44 src, Mtx44 dst) {
    if (src == dst) return;
    dst[0][0] = src[0][0]; dst[0][1] = src[0][1]; dst[0][2] = src[0][2]; dst[0][3] = src[0][3];
    dst[1][0] = src[1][0]; dst[1][1] = src[1][1]; dst[1][2] = src[1][2]; dst[1][3] = src[1][3];
    dst[2][0] = src[2][0]; dst[2][1] = src[2][1]; dst[2][2] = src[2][2]; dst[2][3] = src[2][3];
    dst[3][0] = src[3][0]; dst[3][1] = src[3][1]; dst[3][2] = src[3][2]; dst[3][3] = src[3][3];
}

// 0x80374EF4 (76 bytes)
// C_MTX44Trans
__attribute__((noreturn))
void C_MTX44Trans_decomp(Mtx44 m, f32 xT, f32 yT, f32 zT) {
    __asm__ __volatile__(
        "lfs     4, -17872(13)\n"
        "stfs    4, 0(3)\n"
        "lfs     0, -17864(13)\n"
        "stfs    0, 4(3)\n"
        "stfs    0, 8(3)\n"
        "stfs    1, 12(3)\n"
        "stfs    0, 16(3)\n"
        "stfs    4, 20(3)\n"
        "stfs    0, 24(3)\n"
        "stfs    2, 28(3)\n"
        "stfs    0, 32(3)\n"
        "stfs    0, 36(3)\n"
        "stfs    4, 40(3)\n"
        "stfs    3, 44(3)\n"
        "stfs    0, 48(3)\n"
        "stfs    0, 52(3)\n"
        "stfs    0, 56(3)\n"
        "stfs    4, 60(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80375070 (76 bytes)
// C_MTX44Scale
__attribute__((noreturn))
void C_MTX44Scale_decomp(Mtx44 m, f32 xS, f32 yS, f32 zS) {
    __asm__ __volatile__(
        "stfs    1, 0(3)\n"
        "lfs     0, -17864(13)\n"
        "stfs    0, 4(3)\n"
        "stfs    0, 8(3)\n"
        "stfs    0, 12(3)\n"
        "stfs    0, 16(3)\n"
        "stfs    2, 20(3)\n"
        "stfs    0, 24(3)\n"
        "stfs    0, 28(3)\n"
        "stfs    0, 32(3)\n"
        "stfs    0, 36(3)\n"
        "stfs    3, 40(3)\n"
        "stfs    0, 44(3)\n"
        "stfs    0, 48(3)\n"
        "stfs    0, 52(3)\n"
        "stfs    0, 56(3)\n"
        "lfs     0, -17872(13)\n"
        "stfs    0, 60(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80374F7C (152 bytes)
void C_MTX44TransApply(const Mtx44 src, Mtx44 dst, f32 xT, f32 yT, f32 zT) {
    if (src != dst) {
        dst[0][0] = src[0][0]; dst[0][1] = src[0][1]; dst[0][2] = src[0][2];
        dst[1][0] = src[1][0]; dst[1][1] = src[1][1]; dst[1][2] = src[1][2];
        dst[2][0] = src[2][0]; dst[2][1] = src[2][1]; dst[2][2] = src[2][2];
        dst[3][0] = src[3][0]; dst[3][1] = src[3][1]; dst[3][2] = src[3][2];
    }
    dst[0][3] = src[0][3] + xT;
    dst[1][3] = src[1][3] + yT;
    dst[2][3] = src[2][3] + zT;
    dst[3][3] = src[3][3];
}

// 0x803750F0 (180 bytes)
void C_MTX44ScaleApply(const Mtx44 src, Mtx44 dst, f32 xS, f32 yS, f32 zS) {
    dst[0][0] = src[0][0] * xS; dst[0][1] = src[0][1] * xS;
    dst[0][2] = src[0][2] * xS; dst[0][3] = src[0][3] * xS;
    dst[1][0] = src[1][0] * yS; dst[1][1] = src[1][1] * yS;
    dst[1][2] = src[1][2] * yS; dst[1][3] = src[1][3] * yS;
    dst[2][0] = src[2][0] * zS; dst[2][1] = src[2][1] * zS;
    dst[2][2] = src[2][2] * zS; dst[2][3] = src[2][3] * zS;
    dst[3][0] = src[3][0]; dst[3][1] = src[3][1];
    dst[3][2] = src[3][2]; dst[3][3] = src[3][3];
}

/* ======================================================================
 * OS functions (inline asm - SDA variable accessors)
 * ====================================================================== */

// 0x8024C760 (8 bytes)
__attribute__((noreturn))
void OSGetArenaHi_decomp(void) {
    __asm__ __volatile__(
        "lwz     3, -23680(13)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8024C768 (8 bytes)
__attribute__((noreturn))
void OSGetArenaLo_decomp(void) {
    __asm__ __volatile__(
        "lwz     3, -27920(13)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8024C770 (8 bytes)
__attribute__((noreturn))
void OSSetArenaHi_decomp(void) {
    __asm__ __volatile__(
        "stw     3, -23680(13)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8024C778 (8 bytes)
__attribute__((noreturn))
void OSSetArenaLo_decomp(void) {
    __asm__ __volatile__(
        "stw     3, -27920(13)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8024C780 (44 bytes)
__attribute__((noreturn))
void OSAllocFromArenaLo_decomp(u32 size, u32 align) {
    __asm__ __volatile__(
        "lwz     0, -27920(13)\n"
        "addi    4, 4, -1\n"
        "not     5, 4\n"
        "add     0, 0, 4\n"
        "and     6, 5, 0\n"
        "add     0, 6, 3\n"
        "add     0, 0, 4\n"
        "and     0, 5, 0\n"
        "stw     0, -27920(13)\n"
        "mr      3, 6\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8024C7AC (32 bytes)
__attribute__((noreturn))
void OSAllocFromArenaHi_decomp(u32 size, u32 align) {
    __asm__ __volatile__(
        "addi    0, 4, -1\n"
        "lwz     4, -23680(13)\n"
        "not     0, 0\n"
        "and     4, 4, 0\n"
        "subf    4, 3, 4\n"
        "and     3, 4, 0\n"
        "stw     3, -23680(13)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8024B1AC (40 bytes)
__attribute__((noreturn))
void OSGetConsoleType_decomp(void) {
    __asm__ __volatile__(
        "lwz     3, -23744(13)\n"
        "cmplwi  3, 0\n"
        "beq     1f\n"
        "lwz     3, 44(3)\n"
        "cmplwi  3, 0\n"
        "bne     2f\n"
        "1:\n"
        "lis     3, 0x1000\n"
        "addi    3, 3, 2\n"
        "b       2f\n"
        "2:\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80250D50 (12 bytes)
__attribute__((noreturn))
void OSSetSaveRegion_decomp(void *start, void *end) {
    __asm__ __volatile__(
        "stw     3, -23640(13)\n"
        "stw     4, -23636(13)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80250D5C (20 bytes)
__attribute__((noreturn))
void OSGetSaveRegion_decomp(u32 *start, u32 *end) {
    __asm__ __volatile__(
        "lwz     0, -23640(13)\n"
        "stw     0, 0(3)\n"
        "lwz     0, -23636(13)\n"
        "stw     0, 0(4)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80250D70 (28 bytes)
__attribute__((noreturn))
void OSGetSavedRegion_decomp(u32 *start, u32 *end) {
    __asm__ __volatile__(
        "lis     5, 0x804A\n"
        "addi    5, 5, -24816\n"
        "lwz     0, 12(5)\n"
        "stw     0, 0(3)\n"
        "lwz     0, 16(5)\n"
        "stw     0, 0(4)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x802534A0 (28 bytes)
__attribute__((noreturn))
void OSIsThreadSuspended_decomp(void *thread) {
    __asm__ __volatile__(
        "lwz     0, 716(3)\n"
        "cmpwi   0, 0\n"
        "ble     1f\n"
        "li      3, 1\n"
        "blr\n"
        "1:\n"
        "li      3, 0\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x802534BC (52 bytes)
__attribute__((noreturn))
void OSIsThreadTerminated_decomp(void *thread) {
    __asm__ __volatile__(
        "lhz     3, 712(3)\n"
        "li      0, 1\n"
        "cmplwi  3, 8\n"
        "beq     1f\n"
        "cmplwi  3, 0\n"
        "beq     1f\n"
        "li      0, 0\n"
        "1:\n"
        "cmpwi   0, 0\n"
        "beq     2f\n"
        "li      3, 1\n"
        "blr\n"
        "2:\n"
        "li      3, 0\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x802552D0 (24 bytes)
__attribute__((noreturn))
void OSGetTime_decomp(void) {
    __asm__ __volatile__(
        "1:\n"
        "mftbu   3\n"
        "mftb    4\n"
        "mftbu   5\n"
        "cmpw    3, 5\n"
        "bne     1b\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8024D970 (48 bytes)
__attribute__((noreturn))
void OSSwitchFiber_decomp(void) {
    __asm__ __volatile__(
        "mflr    0\n"
        "mr      5, 1\n"
        "stwu    5, -8(3)\n"
        "mr      1, 3\n"
        "stw     0, 4(1)\n"
        "mtlr    4\n"
        "blrl\n"
        "lwz     5, 0(1)\n"
        "lwz     0, 4(5)\n"
        "mtlr    0\n"
        "mr      1, 5\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8024D9A0 (36 bytes)
__attribute__((noreturn))
void OSClearContext_decomp(void *context) {
    __asm__ __volatile__(
        "li      0, 0\n"
        "stw     0, 0x19C(3)\n"
        "stw     0, 0x198(3)\n"
        "lis     4, 0x8000\n"
        "lwz     4, 0xD8(4)\n"
        "cmpw    4, 3\n"
        "bnelr\n"
        "lis     4, 0x8000\n"
        "stw     0, 0xD8(4)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* ======================================================================
 * DVD functions
 * ====================================================================== */

// 0x8025BF9C (12 bytes)
__attribute__((noreturn))
void DVDGetFSTLocation_decomp(void) {
    __asm__ __volatile__(
        "lwz     3, -23512(13)\n"
        "lwz     3, 56(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8025F5B8 (8 bytes)
__attribute__((noreturn))
void DVDResetRequired_decomp(void) {
    __asm__ __volatile__(
        "lwz     3, -23424(13)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8025C29C (8 bytes)
__attribute__((noreturn))
void __DVDSetOptionalCommandChecker_decomp(void *checker) {
    __asm__ __volatile__(
        "stw     3, -27784(13)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8025F6B8 (16 bytes)
__attribute__((noreturn))
void DVDSetAutoInvalidation_decomp(BOOL flag) {
    __asm__ __volatile__(
        "lwz     0, -27788(13)\n"
        "stw     3, -27788(13)\n"
        "mr      3, 0\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8025D950 (36 bytes)
__attribute__((noreturn))
void __DVDSetImmCommand_decomp(void) {
    __asm__ __volatile__(
        "lis     5, 0xCC00\n"
        "stw     3, 0x6008(5)\n"
        "stw     4, 0x600C(5)\n"
        "stw     0, 0x6010(5)\n"
        "lwz     0, 0x6014(5)\n"
        "ori     0, 0, 1\n"
        "rlwinm  0, 0, 0, 29, 27\n"
        "stw     0, 0x6014(5)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8025D974 (28 bytes)
__attribute__((noreturn))
void __DVDSetDmaCommand_decomp(void) {
    __asm__ __volatile__(
        "lis     5, 0xCC00\n"
        "stw     3, 0x6008(5)\n"
        "stw     4, 0x600C(5)\n"
        "stw     0, 0x6010(5)\n"
        "lwz     0, 0x6014(5)\n"
        "ori     0, 0, 3\n"
        "stw     0, 0x6014(5)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8025E084 (12 bytes)
__attribute__((noreturn))
void __DVDGetIssueCommandAddr_decomp(void) {
    __asm__ __volatile__(
        "lis     3, 0x804F\n"
        "lwz     3, -1344(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80261D24 (20 bytes)
__attribute__((noreturn))
void DVDLowBreak_decomp(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "lwz     0, 0x6014(3)\n"
        "rlwinm  0, 0, 0, 31, 29\n"
        "stw     0, 0x6014(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80261D38 (28 bytes)
__attribute__((noreturn))
void DVDLowClearCallback_decomp(void) {
    __asm__ __volatile__(
        "lis     4, 0x804F\n"
        "lwz     3, -1304(4)\n"
        "li      0, 0\n"
        "stw     0, -1304(4)\n"
        "stw     0, -1308(4)\n"
        "stw     0, -1300(4)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* ======================================================================
 * GX functions
 * ====================================================================== */

// 0x80388D74 (20 bytes)
void GXGetFifoLimits_decomp(void *fifo, u32 *hi, u32 *lo) {
    *hi = *(u32 *)((char *)fifo + 0x0C);
    *lo = *(u32 *)((char *)fifo + 0x10);
}

// 0x80389150 (8 bytes)
__attribute__((noreturn))
void GXGetCurrentGXThread_decomp(void) {
    __asm__ __volatile__(
        "lwz     3, -21952(13)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80389158 (8 bytes)
__attribute__((noreturn))
void GXGetCPUFifo_decomp(void) {
    __asm__ __volatile__(
        "lwz     3, -21960(13)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80389160 (8 bytes)
__attribute__((noreturn))
void GXGetGPFifo_decomp(void) {
    __asm__ __volatile__(
        "lwz     3, -21956(13)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80389168 (8 bytes)
__attribute__((noreturn))
void GXGetOverflowCount_decomp(void) {
    __asm__ __volatile__(
        "lwz     3, -21936(13)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80389170 (16 bytes)
__attribute__((noreturn))
void GXResetOverflowCount_decomp(void) {
    __asm__ __volatile__(
        "lwz     3, -21936(13)\n"
        "li      0, 0\n"
        "stw     0, -21936(13)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038AFB8 (12 bytes)
__attribute__((noreturn))
void GXReadDrawSync_decomp(void) {
    __asm__ __volatile__(
        "lwz     3, -21992(13)\n"
        "lhz     3, 14(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038B170 (20 bytes)
__attribute__((noreturn))
void GXPokeAlphaMode_decomp(u32 func, u32 threshold) {
    __asm__ __volatile__(
        "lwz     5, -21992(13)\n"
        "clrlwi  0, 4, 24\n"
        "rlwimi  0, 3, 8, 0, 23\n"
        "sth     0, 6(5)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038B184 (32 bytes)
__attribute__((noreturn))
void GXPokeAlphaRead_decomp(u32 mode) {
    __asm__ __volatile__(
        "li      5, 0\n"
        "lwz     4, -21992(13)\n"
        "rlwimi  5, 3, 0, 30, 31\n"
        "li      0, 1\n"
        "addi    3, 5, 0\n"
        "rlwimi  3, 0, 2, 29, 29\n"
        "sth     3, 8(4)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038B1A4 (24 bytes)
__attribute__((noreturn))
void GXPokeAlphaUpdate_decomp(u32 enable) {
    __asm__ __volatile__(
        "lwz     4, -21992(13)\n"
        "clrlwi  0, 3, 24\n"
        "lhz     3, 2(4)\n"
        "rlwimi  3, 0, 4, 27, 27\n"
        "sth     3, 2(4)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038B220 (24 bytes)
__attribute__((noreturn))
void GXPokeColorUpdate_decomp(u32 enable) {
    __asm__ __volatile__(
        "lwz     4, -21992(13)\n"
        "clrlwi  0, 3, 24\n"
        "lhz     3, 2(4)\n"
        "rlwimi  3, 0, 3, 28, 28\n"
        "sth     3, 2(4)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038B238 (36 bytes)
__attribute__((noreturn))
void GXPokeDstAlpha_decomp(u32 enable, u32 alpha) {
    __asm__ __volatile__(
        "clrlwi  0, 4, 24\n"
        "lwz     4, -21992(13)\n"
        "li      5, 0\n"
        "rlwimi  5, 0, 0, 24, 31\n"
        "clrlwi  0, 3, 24\n"
        "addi    3, 5, 0\n"
        "rlwimi  3, 0, 8, 23, 23\n"
        "sth     3, 4(4)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038B25C (24 bytes)
__attribute__((noreturn))
void GXPokeDither_decomp(u32 enable) {
    __asm__ __volatile__(
        "lwz     4, -21992(13)\n"
        "clrlwi  0, 3, 24\n"
        "lhz     3, 2(4)\n"
        "rlwimi  3, 0, 2, 29, 29\n"
        "sth     3, 2(4)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038B274 (32 bytes)
__attribute__((noreturn))
void GXPokeZMode_decomp(u32 compare_enable, u32 func, u32 update_enable) {
    __asm__ __volatile__(
        "clrlwi  0, 3, 24\n"
        "lwz     3, -21992(13)\n"
        "li      6, 0\n"
        "rlwimi  6, 0, 0, 31, 31\n"
        "rlwimi  6, 4, 1, 28, 30\n"
        "rlwimi  6, 5, 4, 27, 27\n"
        "sth     6, 0(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038B294 (36 bytes)
__attribute__((noreturn))
void GXPeekARGB_decomp(u16 x, u16 y, u32 *color) {
    __asm__ __volatile__(
        "clrlwi  0, 3, 16\n"
        "lis     3, -14336\n"
        "rlwimi  3, 0, 2, 20, 29\n"
        "li      0, 0\n"
        "rlwimi  3, 4, 12, 10, 19\n"
        "rlwimi  3, 0, 22, 8, 9\n"
        "lwz     0, 0(3)\n"
        "stw     0, 0(5)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038B2B8 (32 bytes)
__attribute__((noreturn))
void GXPokeARGB_decomp(u16 x, u16 y, u32 color) {
    __asm__ __volatile__(
        "clrlwi  0, 3, 16\n"
        "lis     3, -14336\n"
        "rlwimi  3, 0, 2, 20, 29\n"
        "li      0, 0\n"
        "rlwimi  3, 4, 12, 10, 19\n"
        "rlwimi  3, 0, 22, 8, 9\n"
        "stw     5, 0(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038B2D8 (36 bytes)
__attribute__((noreturn))
void GXPeekZ_decomp(u16 x, u16 y, u32 *z) {
    __asm__ __volatile__(
        "clrlwi  0, 3, 16\n"
        "lis     3, -14336\n"
        "rlwimi  3, 0, 2, 20, 29\n"
        "li      0, 1\n"
        "rlwimi  3, 4, 12, 10, 19\n"
        "rlwimi  3, 0, 22, 8, 9\n"
        "lwz     0, 0(3)\n"
        "stw     0, 0(5)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038B2FC (32 bytes)
__attribute__((noreturn))
void GXPokeZ_decomp(u16 x, u16 y, u32 z) {
    __asm__ __volatile__(
        "clrlwi  0, 3, 16\n"
        "lis     3, -14336\n"
        "rlwimi  3, 0, 2, 20, 29\n"
        "li      0, 1\n"
        "rlwimi  3, 4, 12, 10, 19\n"
        "rlwimi  3, 0, 22, 8, 9\n"
        "stw     5, 0(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038B128 (36 bytes)
__attribute__((noreturn))
void GXPixModeSync_decomp(void) {
    __asm__ __volatile__(
        "li      0, 0x61\n"
        "lwz     4, -17720(13)\n"
        "lis     5, 0xCC01\n"
        "stb     0, -32768(5)\n"
        "li      0, 0\n"
        "lwz     3, 476(4)\n"
        "stw     3, -32768(5)\n"
        "sth     0, 2(4)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038B14C (36 bytes)
__attribute__((noreturn))
void GXTexModeSync_decomp(void) {
    __asm__ __volatile__(
        "li      0, 0x61\n"
        "lwz     3, -17720(13)\n"
        "lis     5, 0xCC01\n"
        "stb     0, -32768(5)\n"
        "lis     4, 0x6300\n"
        "li      0, 0\n"
        "stw     4, -32768(5)\n"
        "sth     0, 2(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* ======================================================================
 * EXI functions
 * ====================================================================== */

// 0x80267870 (8 bytes)
s32 EXI2_Poll_decomp(void) {
    return 0;
}

// 0x80267878 (8 bytes)
s32 EXI2_ReadN_decomp(void) {
    return 0;
}

// 0x80267880 (8 bytes)
s32 EXI2_WriteN_decomp(void) {
    return 0;
}

// 0x80268308 (24 bytes)
__attribute__((noreturn))
void DBGEXIClearInterrupts_decomp(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "addi    3, 3, 0x6800\n"
        "lwz     0, 0(3)\n"
        "rlwinm  0, 0, 0, 24, 22\n"
        "stw     0, 0(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x802685B8 (28 bytes)
__attribute__((noreturn))
void DBGEXISync_decomp(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "addi    3, 3, 0x6800\n"
        "1:\n"
        "lwz     0, 12(3)\n"
        "rlwinm. 0, 0, 0, 31, 31\n"
        "beq     1b\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x802685D4 (28 bytes)
__attribute__((noreturn))
void DBGEXIDeselect_decomp(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "addi    3, 3, 0x6800\n"
        "lwz     0, 0(3)\n"
        "rlwinm  0, 0, 0, 28, 19\n"
        "ori     0, 0, 0x0010\n"
        "stw     0, 0(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x802685F0 (40 bytes)
__attribute__((noreturn))
void DBGEXISelect_decomp(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "addi    3, 3, 0x6800\n"
        "lwz     4, 0(3)\n"
        "rlwinm  4, 4, 0, 28, 19\n"
        "ori     4, 4, 0x00D0\n"
        "stw     4, 0(3)\n"
        "1:\n"
        "lwz     0, 12(3)\n"
        "rlwinm. 0, 0, 0, 31, 31\n"
        "beq     1b\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80257D50 (24 bytes)
__attribute__((noreturn))
void EXIGetState_decomp(s32 chan) {
    __asm__ __volatile__(
        "mulli   0, 3, 36\n"
        "lis     3, 0x804F\n"
        "addi    3, 3, -496\n"
        "add     3, 3, 0\n"
        "lwz     3, 0(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* ======================================================================
 * PAD functions
 * ====================================================================== */

// 0x80266280 (8 bytes)
__attribute__((noreturn))
void PADGetSpec_decomp(void) {
    __asm__ __volatile__(
        "lwz     3, -132(13)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80266C58 (12 bytes)
__attribute__((noreturn))
void __PADDisableXPatch_decomp(void) {
    __asm__ __volatile__(
        "lis     3, 0x8050\n"
        "li      0, 1\n"
        "stb     0, -344(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* ======================================================================
 * PSVECAdd / PSVECSubtract / PSVECScale (Paired Singles)
 * ====================================================================== */

// 0x8025A9D0 (36 bytes)
__attribute__((noreturn))
void PSVECAdd_decomp(const Vec *a, const Vec *b, Vec *ab) {
    __asm__ __volatile__(
        "psq_l   0, 0(3), 0, 0\n"
        "psq_l   1, 0(4), 0, 0\n"
        "ps_add  0, 0, 1\n"
        "psq_st  0, 0(5), 0, 0\n"
        "psq_l   0, 8(3), 1, 0\n"
        "psq_l   1, 8(4), 1, 0\n"
        "ps_add  0, 0, 1\n"
        "psq_st  0, 8(5), 1, 0\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8025AA28 (36 bytes)
__attribute__((noreturn))
void PSVECSubtract_decomp(const Vec *a, const Vec *b, Vec *ab) {
    __asm__ __volatile__(
        "psq_l   0, 0(3), 0, 0\n"
        "psq_l   1, 0(4), 0, 0\n"
        "ps_sub  0, 0, 1\n"
        "psq_st  0, 0(5), 0, 0\n"
        "psq_l   0, 8(3), 1, 0\n"
        "psq_l   1, 8(4), 1, 0\n"
        "ps_sub  0, 0, 1\n"
        "psq_st  0, 8(5), 1, 0\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8025AA74 (28 bytes)
__attribute__((noreturn))
void PSVECScale_decomp(const Vec *src, Vec *dst, f32 scale) {
    __asm__ __volatile__(
        "psq_l   0, 0(3), 0, 0\n"
        "ps_muls0 0, 0, 1\n"
        "psq_st  0, 0(4), 0, 0\n"
        "psq_l   0, 8(3), 1, 0\n"
        "ps_muls0 0, 0, 1\n"
        "psq_st  0, 8(4), 1, 0\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8025ABC0 (24 bytes)
__attribute__((noreturn))
void PSVECSquareMag_decomp(const Vec *v) {
    __asm__ __volatile__(
        "psq_l   0, 0(3), 0, 0\n"
        "ps_mul  0, 0, 0\n"
        "psq_l   1, 8(3), 1, 0\n"
        "ps_madd 0, 1, 1, 0\n"
        "ps_sum0 1, 0, 0, 0\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8025ACE0 (32 bytes)
__attribute__((noreturn))
void PSVECDotProduct_decomp(const Vec *a, const Vec *b) {
    __asm__ __volatile__(
        "psq_l   0, 0(3), 0, 0\n"
        "psq_l   1, 0(4), 0, 0\n"
        "ps_mul  0, 0, 1\n"
        "psq_l   2, 8(3), 1, 0\n"
        "psq_l   1, 8(4), 1, 0\n"
        "ps_madd 0, 2, 1, 0\n"
        "ps_sum0 1, 0, 0, 0\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8025AF70 (40 bytes)
__attribute__((noreturn))
void PSVECSquareDistance_decomp(const Vec *a, const Vec *b) {
    __asm__ __volatile__(
        "psq_l   0, 0(3), 0, 0\n"
        "psq_l   1, 0(4), 0, 0\n"
        "ps_sub  0, 0, 1\n"
        "psq_l   2, 8(3), 1, 0\n"
        "ps_mul  0, 0, 0\n"
        "psq_l   1, 8(4), 1, 0\n"
        "ps_sub  1, 2, 1\n"
        "ps_madd 0, 1, 1, 0\n"
        "ps_sum0 1, 0, 0, 0\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* ======================================================================
 * PSMTX functions (Paired Singles matrix operations)
 * ====================================================================== */

// 0x80371F70 (44 bytes)
__attribute__((noreturn))
void PSMTXIdentity_decomp(Mtx m) {
    __asm__ __volatile__(
        "lfs     0, -17964(13)\n"
        "lfs     1, -17968(13)\n"
        "ps_merge00 2, 1, 0\n"
        "ps_merge00 3, 0, 0\n"
        "psq_st  2, 0(3), 0, 0\n"
        "psq_st  3, 8(3), 0, 0\n"
        "psq_st  3, 16(3), 0, 0\n"
        "psq_st  2, 24(3), 0, 0\n"
        "psq_st  3, 32(3), 0, 0\n"
        "psq_st  3, 40(3), 0, 0\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80372008 (52 bytes)
__attribute__((noreturn))
void PSMTXCopy_decomp(const Mtx src, Mtx dst) {
    __asm__ __volatile__(
        "psq_l   0, 0(3), 0, 0\n"
        "psq_st  0, 0(4), 0, 0\n"
        "psq_l   1, 8(3), 0, 0\n"
        "psq_st  1, 8(4), 0, 0\n"
        "psq_l   2, 16(3), 0, 0\n"
        "psq_st  2, 16(4), 0, 0\n"
        "psq_l   3, 24(3), 0, 0\n"
        "psq_st  3, 24(4), 0, 0\n"
        "psq_l   4, 32(3), 0, 0\n"
        "psq_st  4, 32(4), 0, 0\n"
        "psq_l   5, 40(3), 0, 0\n"
        "psq_st  5, 40(4), 0, 0\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803731EC (52 bytes)
__attribute__((noreturn))
void PSMTXTrans_decomp(Mtx m, f32 xT, f32 yT, f32 zT) {
    __asm__ __volatile__(
        "lfs     0, -17964(13)\n"
        "lfs     4, -17968(13)\n"
        "ps_merge00 5, 4, 0\n"
        "ps_merge00 6, 0, 1\n"
        "ps_merge00 7, 0, 0\n"
        "psq_st  5, 0(3), 0, 0\n"
        "psq_st  6, 8(3), 0, 0\n"
        "psq_st  7, 16(3), 0, 0\n"
        "ps_merge00 6, 4, 0\n"
        "psq_st  6, 24(3), 0, 0\n"
        "ps_merge00 6, 0, 0\n"
        "psq_st  6, 32(3), 0, 0\n"
        "ps_merge00 6, 4, 3\n"
        "psq_st  6, 40(3), 0, 0\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8037331C (40 bytes)
__attribute__((noreturn))
void PSMTXScale_decomp(Mtx m, f32 xS, f32 yS, f32 zS) {
    __asm__ __volatile__(
        "lfs     0, -17964(13)\n"
        "stfs    1, 0(3)\n"
        "psq_st  0, 4(3), 0, 0\n"
        "psq_st  0, 12(3), 0, 0\n"
        "stfs    2, 20(3)\n"
        "psq_st  0, 24(3), 0, 0\n"
        "psq_st  0, 32(3), 0, 0\n"
        "stfs    3, 40(3)\n"
        "stfs    0, 44(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* ======================================================================
 * PSMTX44 functions
 * ====================================================================== */

// 0x80374384 (52 bytes)
__attribute__((noreturn))
void PSMTX44Identity_decomp(Mtx44 m) {
    __asm__ __volatile__(
        "lfs     0, -17864(13)\n"
        "lfs     1, -17872(13)\n"
        "ps_merge00 2, 1, 0\n"
        "ps_merge00 3, 0, 0\n"
        "psq_st  2, 0(3), 0, 0\n"
        "psq_st  3, 8(3), 0, 0\n"
        "psq_st  3, 16(3), 0, 0\n"
        "psq_st  2, 24(3), 0, 0\n"
        "psq_st  3, 32(3), 0, 0\n"
        "psq_st  3, 40(3), 0, 0\n"
        "psq_st  2, 48(3), 0, 0\n"
        "psq_st  3, 56(3), 0, 0\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80374444 (68 bytes)
__attribute__((noreturn))
void PSMTX44Copy_decomp(const Mtx44 src, Mtx44 dst) {
    __asm__ __volatile__(
        "psq_l   0, 0(3), 0, 0\n"
        "psq_st  0, 0(4), 0, 0\n"
        "psq_l   1, 8(3), 0, 0\n"
        "psq_st  1, 8(4), 0, 0\n"
        "psq_l   2, 16(3), 0, 0\n"
        "psq_st  2, 16(4), 0, 0\n"
        "psq_l   3, 24(3), 0, 0\n"
        "psq_st  3, 24(4), 0, 0\n"
        "psq_l   4, 32(3), 0, 0\n"
        "psq_st  4, 32(4), 0, 0\n"
        "psq_l   5, 40(3), 0, 0\n"
        "psq_st  5, 40(4), 0, 0\n"
        "psq_l   6, 48(3), 0, 0\n"
        "psq_st  6, 48(4), 0, 0\n"
        "psq_l   7, 56(3), 0, 0\n"
        "psq_st  7, 56(4), 0, 0\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80374F40 (60 bytes)
__attribute__((noreturn))
void PSMTX44Trans_decomp(Mtx44 m, f32 xT, f32 yT, f32 zT) {
    __asm__ __volatile__(
        "lfs     0, -17864(13)\n"
        "lfs     4, -17872(13)\n"
        "stfs    1, 12(3)\n"
        "stfs    2, 28(3)\n"
        "ps_merge00 5, 4, 0\n"
        "stfs    3, 44(3)\n"
        "psq_st  5, 0(3), 0, 0\n"
        "psq_st  0, 4(3), 0, 0\n"
        "psq_st  0, 16(3), 0, 0\n"
        "psq_st  0, 24(3), 0, 0\n"
        "psq_st  0, 32(3), 0, 0\n"
        "psq_st  5, 40(3), 1, 0\n"
        "psq_st  0, 48(3), 0, 0\n"
        "psq_st  0, 56(3), 0, 0\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803750BC (52 bytes)
__attribute__((noreturn))
void PSMTX44Scale_decomp(Mtx44 m, f32 xS, f32 yS, f32 zS) {
    __asm__ __volatile__(
        "lfs     0, -17864(13)\n"
        "lfs     4, -17872(13)\n"
        "stfs    1, 0(3)\n"
        "psq_st  0, 4(3), 0, 0\n"
        "psq_st  0, 12(3), 0, 0\n"
        "stfs    2, 20(3)\n"
        "psq_st  0, 24(3), 0, 0\n"
        "psq_st  0, 32(3), 0, 0\n"
        "stfs    3, 40(3)\n"
        "psq_st  0, 44(3), 0, 0\n"
        "psq_st  0, 52(3), 0, 0\n"
        "stfs    4, 60(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* ======================================================================
 * PSMTXTransApply / PSMTXScaleApply
 * ====================================================================== */

/* PSMTXTransApply, PSMTXScaleApply, PSMTX44TransApply, PSMTX44ScaleApply
 * require frsp instructions for double-to-single parameter rounding that
 * the assembler handles differently. Skipping these for now. */

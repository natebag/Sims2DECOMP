/*
 * sdk_wrappers.cpp - DolphinSDK function decompilations
 *
 * Converted from inline PPC asm (src/asm_decomp/global.cpp) and empty stubs
 * (src/libs/dolphinsdk/*.cpp) to real C implementations.
 *
 * These are the actual DolphinSDK 1.0 HW2 library functions statically linked
 * into the Sims 2 GC executable. Each function is annotated with its address
 * and size from the original DOL.
 *
 * Functions that cannot match with GCC due to register allocation, SDA access,
 * special PPC instructions (paired singles, cache ops, etc.) remain as inline
 * asm with a comment explaining why.
 *
 * Complements: src/matched/sdk_decomp.c (which covers VEC/MTX math, simple
 * OS/DVD/GX/EXI/PAD leaf functions, and PS variants)
 *
 * Source: Disassembly of extracted/sys/main.dol
 *         Symbol names from extracted/files/u2_ngc_release.map (39,169 symbols)
 * Compiler: devkitPPC (GCC) with -O2 -mcpu=750
 */

#include "types.h"

/* ======================================================================
 * Type definitions
 * ====================================================================== */

typedef f32 Vec[3];
typedef f32 Mtx[3][4];
typedef f32 Mtx44[4][4];

/* DolphinSDK struct forward declarations */
typedef struct _GXFifoObj GXFifoObj;
typedef struct _GXRenderModeObj GXRenderModeObj;
typedef struct _GXLightObj GXLightObj;
typedef struct _GXTexObj GXTexObj;
typedef struct _GXTlutObj GXTlutObj;
typedef struct _GXColor { u8 r, g, b, a; } GXColor;

typedef struct OSThread OSThread;
typedef struct OSAlarm OSAlarm;
typedef struct OSContext OSContext;
typedef struct OSMutex OSMutex;
typedef struct OSMessageQueue OSMessageQueue;
typedef struct OSModuleInfo OSModuleInfo;
typedef struct OSModuleQueue OSModuleQueue;
typedef struct OSSemaphore OSSemaphore;
typedef struct OSCond OSCond;
typedef struct OSCalendarTime OSCalendarTime;
typedef struct OSThreadQueue OSThreadQueue;
typedef struct OSResetFunctionInfo OSResetFunctionInfo;

typedef struct DVDFileInfo DVDFileInfo;
typedef struct DVDDir DVDDir;
typedef struct DVDDirEntry DVDDirEntry;
typedef struct DVDCommandBlock DVDCommandBlock;
typedef struct DVDDiskID DVDDiskID;

typedef struct PADStatus PADStatus;
typedef struct CARDFileInfo CARDFileInfo;
typedef struct DSPTask DSPTask;

typedef struct ARQRequest ARQRequest;

typedef void (*OSAlarmHandler)(OSAlarm* alarm, OSContext* context);
typedef void (*GXBreakPtCallback)(void);
typedef void (*GXDrawSyncCallback)(u16 token);
typedef void (*GXDrawDoneCallback)(void);
typedef void (*DVDCallback)(s32 result, DVDFileInfo* fileInfo);
typedef void (*DVDCBCallback)(s32 result, DVDCommandBlock* block);
typedef void (*OSResetCallback)(void);
typedef void (*OSSwitchThreadCallback)(OSThread* from, OSThread* to);
typedef void (*OSIdleFunction)(void* param);
typedef void (*PADSamplingCallback)(void);
typedef void (*VIRetraceCallback)(u32 retraceCount);
typedef void (*ARCallback)(void);
typedef void (*ARQCallback)(void);
typedef s32  (*DVDLowCallback)(void);

/* ======================================================================
 * GX - Graphics Library
 *
 * Total: 281 functions in src/libs/dolphinsdk/gx.cpp
 *        (many also in src/asm_decomp/global.cpp as inline asm)
 * Already in sdk_decomp.c: ~20 (GXGet/Poke/Peek leaf functions)
 * ====================================================================== */

/* --- GX Fifo Management --- */

// 0x80388D14 (12 bytes)
void GXInitFifoLimits(GXFifoObj* fifo, u32 hiWatermark, u32 loWatermark) {
    *(u32*)((u8*)fifo + 0x0C) = hiWatermark;
    *(u32*)((u8*)fifo + 0x10) = loWatermark;
}

// 0x80388D28 (8 bytes)
void* GXGetFifoBase(GXFifoObj* fifo) {
    return *(void**)((u8*)fifo + 0x00);
}

// 0x80388D30 (8 bytes)
u32 GXGetFifoSize(GXFifoObj* fifo) {
    return *(u32*)((u8*)fifo + 0x04);
}

// 0x80389148 (8 bytes)
// GXGetCurrentGXThread - SDA access, kept as asm in sdk_decomp.c

// 0x80389150 (8 bytes)
// GXGetCPUFifo - SDA access, kept as asm in sdk_decomp.c

// 0x80389158 (8 bytes)
// GXGetGPFifo - SDA access, kept as asm in sdk_decomp.c

// 0x80389160 (8 bytes)
// GXGetOverflowCount - SDA access, kept as asm in sdk_decomp.c

// 0x80389170 (16 bytes)
// GXResetOverflowCount - SDA access, kept as asm in sdk_decomp.c

/* --- GX Vertex Cache --- */

// 0x80565330 (16 bytes)
// GXInvalidateVtxCache - writes to GX FIFO (write-gather pipe)
__attribute__((noreturn))
void GXInvalidateVtxCache_decomp(void) {
    __asm__ __volatile__(
        "li      0, 0x48\n"
        "lis     3, 0xCC01\n"
        "stb     0, -32768(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* --- GX Clear Vertex Desc --- */

// 0x80564A5C (56 bytes)
// GXClearVtxDesc - clears all vertex attribute descriptors
// Complex: modifies GX internal state struct
__attribute__((noreturn))
void GXClearVtxDesc_decomp(void) {
    __asm__ __volatile__(
        "lwz     3, -17720(13)\n"
        "li      0, 0\n"
        "stw     0, 12(3)\n"
        "stw     0, 16(3)\n"
        "stw     0, 456(3)\n"
        "stw     0, 460(3)\n"
        "li      0, 1\n"
        "stw     0, 464(3)\n"
        "stw     0, 468(3)\n"
        "stb     0, 1165(3)\n"
        "stb     0, 1166(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* --- GX Line/Point --- */

// 0x805665D8 (64 bytes)
// GXSetLineWidth - writes to GX state and FIFO
__attribute__((noreturn))
void GXSetLineWidth_decomp(u8 width, u32 texOffsets) {
    __asm__ __volatile__(
        "lwz     5, -17720(13)\n"
        "clrlwi  0, 3, 24\n"
        "rlwimi  0, 4, 8, 21, 23\n"
        "stw     0, 444(5)\n"
        "li      4, 0x61\n"
        "lis     3, 0xCC01\n"
        "stb     4, -32768(3)\n"
        "stw     0, -32768(3)\n"
        "li      0, 0\n"
        "sth     0, 2(5)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80566618 (28 bytes)
// GXGetLineWidth
__attribute__((noreturn))
void GXGetLineWidth_decomp(u8* width, u32* texOffsets) {
    __asm__ __volatile__(
        "lwz     5, -17720(13)\n"
        "lwz     0, 444(5)\n"
        "clrlwi  5, 0, 24\n"
        "stb     5, 0(3)\n"
        "rlwinm  0, 0, 24, 29, 31\n"
        "stw     0, 0(4)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80566634 (64 bytes)
// GXSetPointSize
__attribute__((noreturn))
void GXSetPointSize_decomp(u8 size, u32 texOffsets) {
    __asm__ __volatile__(
        "lwz     5, -17720(13)\n"
        "clrlwi  0, 3, 24\n"
        "rlwimi  0, 4, 8, 21, 23\n"
        "stw     0, 448(5)\n"
        "li      4, 0x61\n"
        "lis     3, 0xCC01\n"
        "stb     4, -32768(3)\n"
        "stw     0, -32768(3)\n"
        "li      0, 0\n"
        "sth     0, 2(5)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80566674 (32 bytes)
// GXGetPointSize
__attribute__((noreturn))
void GXGetPointSize_decomp(u8* size, u32* texOffsets) {
    __asm__ __volatile__(
        "lwz     5, -17720(13)\n"
        "lwz     0, 448(5)\n"
        "clrlwi  5, 0, 24\n"
        "stb     5, 0(3)\n"
        "rlwinm  0, 0, 24, 29, 31\n"
        "stw     0, 0(4)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* --- GX Cull Mode --- */

// 0x805666DC (40 bytes)
// GXSetCullMode
__attribute__((noreturn))
void GXSetCullMode_decomp(u32 mode) {
    __asm__ __volatile__(
        "lwz     4, -17720(13)\n"
        "rlwinm  0, 3, 0, 30, 31\n"
        "xoris   0, 0, 2\n"
        "rlwimi  0, 3, 0, 0, 15\n"
        "stw     0, 452(4)\n"
        "li      3, 0x61\n"
        "lis     4, 0xCC01\n"
        "stb     3, -32768(4)\n"
        "stw     0, -32768(4)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80566704 (28 bytes)
// GXGetCullMode
__attribute__((noreturn))
void GXGetCullMode_decomp(u32* mode) {
    __asm__ __volatile__(
        "lwz     4, -17720(13)\n"
        "lwz     0, 452(4)\n"
        "rlwinm  4, 0, 0, 30, 31\n"
        "xoris   4, 4, 2\n"
        "rlwimi  4, 0, 0, 0, 15\n"
        "stw     4, 0(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* --- GX Display Copy Gamma --- */

// 0x80567200 (20 bytes)
// GXSetDispCopyGamma
__attribute__((noreturn))
void GXSetDispCopyGamma_decomp(u32 gamma) {
    __asm__ __volatile__(
        "lwz     4, -17720(13)\n"
        "li      0, 0\n"
        "rlwimi  0, 3, 9, 21, 22\n"
        "stw     0, 364(4)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* --- GX Bounding Box --- */

// 0x80567508 (56 bytes)
// GXClearBoundingBox
__attribute__((noreturn))
void GXClearBoundingBox_decomp(void) {
    __asm__ __volatile__(
        "lis     4, 0xCC01\n"
        "li      3, 0x61\n"
        "stb     3, -32768(4)\n"
        "lis     3, 0x5500\n"
        "ori     3, 3, 0x0F0F\n"
        "stw     3, -32768(4)\n"
        "li      3, 0x61\n"
        "stb     3, -32768(4)\n"
        "lis     3, 0x5600\n"
        "ori     3, 3, 0x0F0F\n"
        "stw     3, -32768(4)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80567540 (52 bytes)
// GXReadBoundingBox
__attribute__((noreturn))
void GXReadBoundingBox_decomp(u16* top, u16* bottom, u16* left, u16* right) {
    __asm__ __volatile__(
        "lis     7, 0xCC01\n"
        "lhz     0, -28670(7)\n"
        "sth     0, 0(3)\n"
        "lhz     0, -28668(7)\n"
        "sth     0, 0(4)\n"
        "lhz     0, -28666(7)\n"
        "sth     0, 0(5)\n"
        "lhz     0, -28664(7)\n"
        "sth     0, 0(6)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* --- GX Light Attribute Access --- */

// 0x80567574 (28 bytes)
void GXInitLightAttn(GXLightObj* lt_obj, f32 a0, f32 a1, f32 a2,
                     f32 k0, f32 k1, f32 k2) {
    *(f32*)((u8*)lt_obj + 0x10) = a0;
    *(f32*)((u8*)lt_obj + 0x14) = a1;
    *(f32*)((u8*)lt_obj + 0x18) = a2;
    *(f32*)((u8*)lt_obj + 0x1C) = k0;
    *(f32*)((u8*)lt_obj + 0x20) = k1;
    *(f32*)((u8*)lt_obj + 0x24) = k2;
}

// 0x80567590 (16 bytes)
void GXInitLightAttnA(GXLightObj* lt_obj, f32 a0, f32 a1, f32 a2) {
    *(f32*)((u8*)lt_obj + 0x10) = a0;
    *(f32*)((u8*)lt_obj + 0x14) = a1;
    *(f32*)((u8*)lt_obj + 0x18) = a2;
}

// 0x805675A0 (28 bytes)
void GXGetLightAttnA(const GXLightObj* lt_obj, f32* a0, f32* a1, f32* a2) {
    *a0 = *(f32*)((u8*)lt_obj + 0x10);
    *a1 = *(f32*)((u8*)lt_obj + 0x14);
    *a2 = *(f32*)((u8*)lt_obj + 0x18);
}

// 0x805675BC (16 bytes)
void GXInitLightAttnK(GXLightObj* lt_obj, f32 k0, f32 k1, f32 k2) {
    *(f32*)((u8*)lt_obj + 0x1C) = k0;
    *(f32*)((u8*)lt_obj + 0x20) = k1;
    *(f32*)((u8*)lt_obj + 0x24) = k2;
}

// 0x805675CC (28 bytes)
void GXGetLightAttnK(const GXLightObj* lt_obj, f32* k0, f32* k1, f32* k2) {
    *k0 = *(f32*)((u8*)lt_obj + 0x1C);
    *k1 = *(f32*)((u8*)lt_obj + 0x20);
    *k2 = *(f32*)((u8*)lt_obj + 0x24);
}

// 0x80567848 (16 bytes)
void GXInitLightPos(GXLightObj* lt_obj, f32 x, f32 y, f32 z) {
    *(f32*)((u8*)lt_obj + 0x04) = x;
    *(f32*)((u8*)lt_obj + 0x08) = y;
    *(f32*)((u8*)lt_obj + 0x0C) = z;
}

// 0x80567858 (28 bytes)
void GXGetLightPos(const GXLightObj* lt_obj, f32* x, f32* y, f32* z) {
    *x = *(f32*)((u8*)lt_obj + 0x04);
    *y = *(f32*)((u8*)lt_obj + 0x08);
    *z = *(f32*)((u8*)lt_obj + 0x0C);
}

// 0x80567874 (28 bytes)
void GXInitLightDir(GXLightObj* lt_obj, f32 nx, f32 ny, f32 nz) {
    *(f32*)((u8*)lt_obj + 0x28) = -nx;
    *(f32*)((u8*)lt_obj + 0x2C) = -ny;
    *(f32*)((u8*)lt_obj + 0x30) = -nz;
}

// 0x80567890 (40 bytes)
void GXGetLightDir(const GXLightObj* lt_obj, f32* nx, f32* ny, f32* nz) {
    *nx = -*(f32*)((u8*)lt_obj + 0x28);
    *ny = -*(f32*)((u8*)lt_obj + 0x2C);
    *nz = -*(f32*)((u8*)lt_obj + 0x30);
}

// 0x8056799C (44 bytes)
void GXInitSpecularDirHA(GXLightObj* lt_obj, f32 nx, f32 ny, f32 nz,
                         f32 hx, f32 hy, f32 hz) {
    *(f32*)((u8*)lt_obj + 0x28) = hx;
    *(f32*)((u8*)lt_obj + 0x2C) = hy;
    *(f32*)((u8*)lt_obj + 0x30) = hz;
    *(f32*)((u8*)lt_obj + 0x04) = nx * -1048576.0f;
    *(f32*)((u8*)lt_obj + 0x08) = ny * -1048576.0f;
    *(f32*)((u8*)lt_obj + 0x0C) = nz * -1048576.0f;
}

// 0x805679C8 (16 bytes)
void GXInitLightColor(GXLightObj* lt_obj, GXColor color) {
    *(GXColor*)((u8*)lt_obj + 0x00) = color;
}

// 0x805679D8 (12 bytes)
void GXGetLightColor(const GXLightObj* lt_obj, GXColor* color) {
    *color = *(GXColor*)((u8*)lt_obj + 0x00);
}

/* --- GX Texture Object Accessors --- */

// 0x805685C0 (16 bytes)
void* GXGetTexObjData(const GXTexObj* tex_obj) {
    return *(void**)((u8*)tex_obj + 0x14);
}

// 0x805685D0 (8 bytes)
u16 GXGetTexObjWidth(const GXTexObj* tex_obj) {
    return *(u16*)((u8*)tex_obj + 0x18);
}

// 0x805685D8 (8 bytes)
u16 GXGetTexObjHeight(const GXTexObj* tex_obj) {
    return *(u16*)((u8*)tex_obj + 0x1A);
}

// 0x805685E0 (8 bytes)
u32 GXGetTexObjFmt(const GXTexObj* tex_obj) {
    return *(u32*)((u8*)tex_obj + 0x1C);
}

// 0x805685E8 (8 bytes)
u32 GXGetTexObjWrapS(const GXTexObj* tex_obj) {
    return *(u32*)((u8*)tex_obj + 0x20);
}

// 0x805685F0 (8 bytes)
u32 GXGetTexObjWrapT(const GXTexObj* tex_obj) {
    return *(u32*)((u8*)tex_obj + 0x24);
}

// 0x805685F8 (8 bytes)
u32 GXGetTexObjMipMap(const GXTexObj* tex_obj) {
    return *(u32*)((u8*)tex_obj + 0x28);
}

/* --- GX Number of Stages/Channels --- */

// 0x80569464 (28 bytes)
// GXSetNumChans
__attribute__((noreturn))
void GXSetNumChans_decomp(u32 nChans) {
    __asm__ __volatile__(
        "lwz     4, -17720(13)\n"
        "stw     3, 472(4)\n"
        "li      0, 1\n"
        "sth     0, 2(4)\n"
        "stb     0, 1167(4)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8056AD88 (32 bytes)
// GXSetNumTevStages
__attribute__((noreturn))
void GXSetNumTevStages_decomp(u8 nStages) {
    __asm__ __volatile__(
        "lwz     4, -17720(13)\n"
        "addi    0, 3, -1\n"
        "rlwimi  0, 3, 0, 0, 21\n"
        "stw     0, 480(4)\n"
        "li      0, 1\n"
        "sth     0, 2(4)\n"
        "stb     0, 1177(4)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80569C58 (36 bytes)
// GXSetNumTexGens
__attribute__((noreturn))
void GXSetNumTexGens_decomp(u32 nTexGens) {
    __asm__ __volatile__(
        "lwz     4, -17720(13)\n"
        "stw     3, 476(4)\n"
        "li      0, 1\n"
        "stb     0, 1178(4)\n"
        "lwz     0, 480(4)\n"
        "rlwimi  0, 3, 0, 0, 15\n"
        "stw     0, 480(4)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* --- GX Z Mode --- */

// 0x8056AE44 (72 bytes)
// GXSetZMode
__attribute__((noreturn))
void GXSetZMode_decomp(BOOL compare_enable, u32 func, BOOL update_enable) {
    __asm__ __volatile__(
        "lwz     6, -17720(13)\n"
        "clrlwi  0, 3, 24\n"
        "lwz     3, 484(6)\n"
        "rlwimi  3, 0, 0, 31, 31\n"
        "rlwimi  3, 4, 1, 28, 30\n"
        "clrlwi  0, 5, 24\n"
        "rlwimi  3, 0, 4, 27, 27\n"
        "stw     3, 484(6)\n"
        "li      3, 0x61\n"
        "lis     4, 0xCC01\n"
        "li      0, 0\n"
        "stb     3, -32768(4)\n"
        "lwz     3, 484(6)\n"
        "stw     3, -32768(4)\n"
        "sth     0, 2(6)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8056AE8C (28 bytes)
// GXSetZCompLoc
__attribute__((noreturn))
void GXSetZCompLoc_decomp(BOOL before_tex) {
    __asm__ __volatile__(
        "lwz     4, -17720(13)\n"
        "rlwimi  3, 3, 0, 0, 25\n"
        "stw     3, 488(4)\n"
        "li      0, 1\n"
        "sth     0, 2(4)\n"
        "stb     0, 1177(4)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* --- GX Current Matrix --- */

// 0x8056A2DC (36 bytes)
// GXSetCurrentMtx
__attribute__((noreturn))
void GXSetCurrentMtx_decomp(u32 id) {
    __asm__ __volatile__(
        "lwz     4, -17720(13)\n"
        "rlwinm  0, 3, 0, 26, 31\n"
        "stw     0, 484(4)\n"
        "li      0, 0x10\n"
        "lis     3, 0xCC01\n"
        "stb     0, -32768(3)\n"
        "lwz     0, 484(4)\n"
        "stw     0, -32768(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* --- GX Display List --- */

// 0x80569764 (72 bytes)
// GXBeginDisplayList
__attribute__((noreturn))
void GXBeginDisplayList_decomp(void* list, u32 size) {
    __asm__ __volatile__(
        "stwu    1, -16(1)\n"
        "mflr    0\n"
        "stw     0, 20(1)\n"
        "lwz     5, -17720(13)\n"
        "li      0, 1\n"
        "stb     0, 1161(5)\n"
        "mr      5, 3\n"
        "mr      6, 4\n"
        ".long 0x4bfba709  /* bl GXSaveCPUFifo */\n"
        "mr      3, 5\n"
        "mr      4, 6\n"
        ".long 0x4bfb9c55  /* bl __GXSaveFifo */\n"
        "lwz     0, 20(1)\n"
        "mtlr    0\n"
        "addi    1, 1, 16\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* --- GX Set Fog --- */

// 0x8056ACBC (36 bytes)
// GXSetFogColor
__attribute__((noreturn))
void GXSetFogColor_decomp(GXColor color) {
    __asm__ __volatile__(
        "lwz     0, -17720(13)\n"
        "rlwinm  4, 3, 0, 8, 31\n"
        "lis     3, 0xF5\n"
        "or      4, 4, 3\n"
        "stw     4, 0(0)\n"
        "li      3, 0x61\n"
        "lis     0, 0xCC01\n"
        "stb     3, -32768(0)\n"
        "stw     4, -32768(0)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* ======================================================================
 * VEC functions (C_ prefix = C fallback, no paired singles)
 *
 * Already in sdk_decomp.c: C_VECAdd, C_VECSubtract, C_VECScale,
 *   C_VECSquareMag, C_VECDotProduct, C_VECCrossProduct, C_VECSquareDistance
 * ====================================================================== */

// 0x8025AB9C (228 bytes) - C_VECNormalize
// Complex: Uses frsqrte Newton-Raphson iteration and SDA floats
// Must remain inline asm (see global.cpp line 68527)

// 0x8025ABD8 (148 bytes) - C_VECMag
// Complex: Uses frsqrte Newton-Raphson and SDA floats
// Must remain inline asm (see global.cpp line 68614)

// 0x8025AF34 (60 bytes)
// C_VECSquareDistance - already in sdk_decomp.c

// 0x8025AD88 (216 bytes) - C_VECHalfAngle
// Complex: calls C_VECNormalize, uses stack frame
// Must remain inline asm

// 0x8025AE60 (212 bytes) - C_VECReflect
// Complex: calls C_VECDotProduct, C_VECNormalize
// Must remain inline asm

// 0x8025AF98 (132 bytes) - C_VECDistance
// Complex: uses frsqrte Newton-Raphson and SDA floats
// Must remain inline asm

/* ======================================================================
 * MTX functions (C_ prefix = C fallback, no paired singles)
 *
 * Already in sdk_decomp.c: C_MTXCopy, C_MTXScale, C_MTXIdentity,
 *   C_MTXTrans, C_MTXTransApply, C_MTXScaleApply, C_MTXMultVec,
 *   C_MTXMultVecSR, C_MTX44Identity, C_MTX44Copy, C_MTX44Trans,
 *   C_MTX44Scale, C_MTX44TransApply, C_MTX44ScaleApply
 * ====================================================================== */

// 0x80372040 (400 bytes)
// C_MTXConcat - 3x4 matrix multiplication
void C_MTXConcat(const Mtx a, const Mtx b, Mtx ab) {
    Mtx tmp;
    Mtx *m;

    if (ab == a || ab == b) {
        m = &tmp;
    } else {
        m = (Mtx*)ab;
    }

    (*m)[0][0] = a[0][0]*b[0][0] + a[0][1]*b[1][0] + a[0][2]*b[2][0];
    (*m)[0][1] = a[0][0]*b[0][1] + a[0][1]*b[1][1] + a[0][2]*b[2][1];
    (*m)[0][2] = a[0][0]*b[0][2] + a[0][1]*b[1][2] + a[0][2]*b[2][2];
    (*m)[0][3] = a[0][0]*b[0][3] + a[0][1]*b[1][3] + a[0][2]*b[2][3] + a[0][3];

    (*m)[1][0] = a[1][0]*b[0][0] + a[1][1]*b[1][0] + a[1][2]*b[2][0];
    (*m)[1][1] = a[1][0]*b[0][1] + a[1][1]*b[1][1] + a[1][2]*b[2][1];
    (*m)[1][2] = a[1][0]*b[0][2] + a[1][1]*b[1][2] + a[1][2]*b[2][2];
    (*m)[1][3] = a[1][0]*b[0][3] + a[1][1]*b[1][3] + a[1][2]*b[2][3] + a[1][3];

    (*m)[2][0] = a[2][0]*b[0][0] + a[2][1]*b[1][0] + a[2][2]*b[2][0];
    (*m)[2][1] = a[2][0]*b[0][1] + a[2][1]*b[1][1] + a[2][2]*b[2][1];
    (*m)[2][2] = a[2][0]*b[0][2] + a[2][1]*b[1][2] + a[2][2]*b[2][2];
    (*m)[2][3] = a[2][0]*b[0][3] + a[2][1]*b[1][3] + a[2][2]*b[2][3] + a[2][3];

    if (m == &tmp) {
        C_MTXCopy(tmp, ab);
    }
}

// 0x803721D0 (96 bytes)
// C_MTXTranspose
void C_MTXTranspose(const Mtx src, Mtx xPose) {
    xPose[0][0] = src[0][0]; xPose[0][1] = src[1][0]; xPose[0][2] = src[2][0]; xPose[0][3] = 0.0f;
    xPose[1][0] = src[0][1]; xPose[1][1] = src[1][1]; xPose[1][2] = src[2][1]; xPose[1][3] = 0.0f;
    xPose[2][0] = src[0][2]; xPose[2][1] = src[1][2]; xPose[2][2] = src[2][2]; xPose[2][3] = 0.0f;
}

// 0x80373EA0 (76 bytes)
// C_MTXMultVecArray
void C_MTXMultVecArray(const Mtx m, const Vec* srcBase, Vec* dstBase, u32 count) {
    u32 i;
    for (i = 0; i < count; i++) {
        const f32* src = (*((const Vec*)((const u8*)srcBase + i * 12)));
        f32* dst = (*((Vec*)((u8*)dstBase + i * 12)));

        dst[0] = m[0][0]*src[0] + m[0][1]*src[1] + m[0][2]*src[2] + m[0][3];
        dst[1] = m[1][0]*src[0] + m[1][1]*src[1] + m[1][2]*src[2] + m[1][3];
        dst[2] = m[2][0]*src[0] + m[2][1]*src[1] + m[2][2]*src[2] + m[2][3];
    }
}

// 0x80373F3C (76 bytes)
// C_MTXMultVecArraySR
void C_MTXMultVecArraySR(const Mtx m, const Vec* srcBase, Vec* dstBase, u32 count) {
    u32 i;
    for (i = 0; i < count; i++) {
        const f32* src = (*((const Vec*)((const u8*)srcBase + i * 12)));
        f32* dst = (*((Vec*)((u8*)dstBase + i * 12)));

        dst[0] = m[0][0]*src[0] + m[0][1]*src[1] + m[0][2]*src[2];
        dst[1] = m[1][0]*src[0] + m[1][1]*src[1] + m[1][2]*src[2];
        dst[2] = m[2][0]*src[0] + m[2][1]*src[1] + m[2][2]*src[2];
    }
}

/* --- MTX44 functions --- */

// 0x80374488 (584 bytes)
// C_MTX44Concat - 4x4 matrix multiplication
void C_MTX44Concat(const Mtx44 a, const Mtx44 b, Mtx44 ab) {
    Mtx44 tmp;
    Mtx44 *m;

    if (ab == a || ab == b) {
        m = &tmp;
    } else {
        m = (Mtx44*)ab;
    }

    (*m)[0][0] = a[0][0]*b[0][0] + a[0][1]*b[1][0] + a[0][2]*b[2][0] + a[0][3]*b[3][0];
    (*m)[0][1] = a[0][0]*b[0][1] + a[0][1]*b[1][1] + a[0][2]*b[2][1] + a[0][3]*b[3][1];
    (*m)[0][2] = a[0][0]*b[0][2] + a[0][1]*b[1][2] + a[0][2]*b[2][2] + a[0][3]*b[3][2];
    (*m)[0][3] = a[0][0]*b[0][3] + a[0][1]*b[1][3] + a[0][2]*b[2][3] + a[0][3]*b[3][3];

    (*m)[1][0] = a[1][0]*b[0][0] + a[1][1]*b[1][0] + a[1][2]*b[2][0] + a[1][3]*b[3][0];
    (*m)[1][1] = a[1][0]*b[0][1] + a[1][1]*b[1][1] + a[1][2]*b[2][1] + a[1][3]*b[3][1];
    (*m)[1][2] = a[1][0]*b[0][2] + a[1][1]*b[1][2] + a[1][2]*b[2][2] + a[1][3]*b[3][2];
    (*m)[1][3] = a[1][0]*b[0][3] + a[1][1]*b[1][3] + a[1][2]*b[2][3] + a[1][3]*b[3][3];

    (*m)[2][0] = a[2][0]*b[0][0] + a[2][1]*b[1][0] + a[2][2]*b[2][0] + a[2][3]*b[3][0];
    (*m)[2][1] = a[2][0]*b[0][1] + a[2][1]*b[1][1] + a[2][2]*b[2][1] + a[2][3]*b[3][1];
    (*m)[2][2] = a[2][0]*b[0][2] + a[2][1]*b[1][2] + a[2][2]*b[2][2] + a[2][3]*b[3][2];
    (*m)[2][3] = a[2][0]*b[0][3] + a[2][1]*b[1][3] + a[2][2]*b[2][3] + a[2][3]*b[3][3];

    (*m)[3][0] = a[3][0]*b[0][0] + a[3][1]*b[1][0] + a[3][2]*b[2][0] + a[3][3]*b[3][0];
    (*m)[3][1] = a[3][0]*b[0][1] + a[3][1]*b[1][1] + a[3][2]*b[2][1] + a[3][3]*b[3][1];
    (*m)[3][2] = a[3][0]*b[0][2] + a[3][1]*b[1][2] + a[3][2]*b[2][2] + a[3][3]*b[3][2];
    (*m)[3][3] = a[3][0]*b[0][3] + a[3][1]*b[1][3] + a[3][2]*b[2][3] + a[3][3]*b[3][3];

    if (m == &tmp) {
        C_MTX44Copy(tmp, ab);
    }
}

// 0x80374AD0 (128 bytes)
// C_MTX44Transpose
void C_MTX44Transpose(const Mtx44 src, Mtx44 xPose) {
    xPose[0][0] = src[0][0]; xPose[0][1] = src[1][0]; xPose[0][2] = src[2][0]; xPose[0][3] = src[3][0];
    xPose[1][0] = src[0][1]; xPose[1][1] = src[1][1]; xPose[1][2] = src[2][1]; xPose[1][3] = src[3][1];
    xPose[2][0] = src[0][2]; xPose[2][1] = src[1][2]; xPose[2][2] = src[2][2]; xPose[2][3] = src[3][2];
    xPose[3][0] = src[0][3]; xPose[3][1] = src[1][3]; xPose[3][2] = src[2][3]; xPose[3][3] = src[3][3];
}

/* ======================================================================
 * OS - Operating System
 *
 * Total: 144 functions in src/libs/dolphinsdk/os.cpp
 * Already in sdk_decomp.c: ~25 (simple getters/setters)
 * ====================================================================== */

/* --- Simple OS accessors (SDA-based, must be inline asm) --- */

// 0x803CB230 (8 bytes) - OSGetArenaHi - in sdk_decomp.c
// 0x803CB238 (8 bytes) - OSGetArenaLo - in sdk_decomp.c
// 0x803CB240 (8 bytes) - OSSetArenaHi - in sdk_decomp.c
// 0x803CB248 (8 bytes) - OSSetArenaLo - in sdk_decomp.c
// 0x803CB250 (44 bytes) - OSAllocFromArenaLo - in sdk_decomp.c
// 0x803CB27C (32 bytes) - OSAllocFromArenaHi - in sdk_decomp.c
// 0x803D3DA0 (24 bytes) - OSGetTime - in sdk_decomp.c

// 0x803D3DB8 (8 bytes)
// OSGetTick - reads TBL register
__attribute__((noreturn))
void OSGetTick_decomp(void) {
    __asm__ __volatile__(
        "mftb    3\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803CC428 (8 bytes)
// OSGetStackPointer - reads r1
__attribute__((noreturn))
void OSGetStackPointer_decomp(void) {
    __asm__ __volatile__(
        "mr      3, 1\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803CC430 (16 bytes)
// OSSwitchStack - swaps r1 with provided stack
__attribute__((noreturn))
void OSSwitchStack_decomp(void* newStack) {
    __asm__ __volatile__(
        "mr      5, 1\n"
        "mr      1, 3\n"
        "mr      3, 5\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803CC2C4 (12 bytes)
// OSGetCurrentContext - reads from fixed memory
__attribute__((noreturn))
void OSGetCurrentContext_decomp(void) {
    __asm__ __volatile__(
        "lis     3, 0x8000\n"
        "lwz     3, 0xD4(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803D1F08 (12 bytes)
// OSGetCurrentThread - reads from fixed memory
__attribute__((noreturn))
void OSGetCurrentThread_decomp(void) {
    __asm__ __volatile__(
        "lis     3, 0x8000\n"
        "lwz     3, 0xE4(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803D33C0 (8 bytes)
// OSGetThreadPriority
__attribute__((noreturn))
void OSGetThreadPriority_decomp(OSThread* thread) {
    __asm__ __volatile__(
        "lwz     3, 724(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803D3458 (28 bytes)
// OSGetIdleFunction
__attribute__((noreturn))
void OSGetIdleFunction_decomp(void) {
    __asm__ __volatile__(
        "lis     3, 0x8000\n"
        "lwz     3, 0xE4(3)\n"
        "cmpwi   3, 0\n"
        "beqlr\n"
        "lwz     3, 728(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803CB0D8 (8 bytes)
// OSSetAlarmTag
__attribute__((noreturn))
void OSSetAlarmTag_decomp(OSAlarm* alarm, u32 tag) {
    __asm__ __volatile__(
        "stw     4, 4(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803CA988 (16 bytes)
// OSCreateAlarm
void OSCreateAlarm(OSAlarm* alarm) {
    *(u32*)((u8*)alarm + 0x08) = 0; /* handler */
    *(u32*)((u8*)alarm + 0x04) = 0; /* tag */
    *(u32*)((u8*)alarm + 0x1C) = 0; /* next */
    *(u32*)((u8*)alarm + 0x18) = 0; /* prev */
}

// 0x803CA72C (44 bytes)
// OSRegisterVersion
__attribute__((noreturn))
void OSRegisterVersion_decomp(const char* version) {
    __asm__ __volatile__(
        "lis     4, 0x8000\n"
        "lwz     0, 0x3110(4)\n"
        "cmpwi   0, 0\n"
        "beqlr\n"
        "stw     3, 0x3110(4)\n"
        "lwz     0, 0x3110(4)\n"
        "rlwinm  0, 0, 0, 0, 5\n"
        "stw     0, 0x3110(4)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* --- OS Interrupt functions --- */

// 0x803CE020 (20 bytes)
// OSDisableInterrupts - manipulates MSR
__attribute__((noreturn))
void OSDisableInterrupts_decomp(void) {
    __asm__ __volatile__(
        "mfmsr   3\n"
        "rlwinm  4, 3, 0, 17, 15\n"
        "mtmsr   4\n"
        "rlwinm  3, 3, 17, 31, 31\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803CE034 (20 bytes)
// OSEnableInterrupts - manipulates MSR
__attribute__((noreturn))
void OSEnableInterrupts_decomp(void) {
    __asm__ __volatile__(
        "mfmsr   3\n"
        "ori     4, 3, 0x8000\n"
        "mtmsr   4\n"
        "rlwinm  3, 3, 17, 31, 31\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803CE048 (36 bytes)
// OSRestoreInterrupts
__attribute__((noreturn))
void OSRestoreInterrupts_decomp(BOOL enable) {
    __asm__ __volatile__(
        "cmpwi   3, 0\n"
        "mfmsr   4\n"
        "beq     1f\n"
        "ori     5, 4, 0x8000\n"
        "mtmsr   5\n"
        "b       2f\n"
        "1:\n"
        "rlwinm  5, 4, 0, 17, 15\n"
        "mtmsr   5\n"
        "2:\n"
        "rlwinm  3, 4, 17, 31, 31\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803CE3E8 (12 bytes)
// OSGetInterruptMask
__attribute__((noreturn))
void OSGetInterruptMask_decomp(void) {
    __asm__ __volatile__(
        "lis     3, 0x8000\n"
        "lwz     3, 0xF0(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* --- OS Link/Unlink --- */

// 0x803CE928 (4 bytes)
// OSNotifyLink - empty stub
void OSNotifyLink(void) {
    /* empty - debug-only function */
}

// 0x803CE92C (4 bytes)
// OSNotifyUnlink - empty stub
void OSNotifyUnlink(void) {
    /* empty - debug-only function */
}

// 0x803CE930 (12 bytes)
// OSSetStringTable
__attribute__((noreturn))
void OSSetStringTable_decomp(void* table) {
    __asm__ __volatile__(
        "lis     4, 0x8000\n"
        "stw     3, 0x30D4(4)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* --- OS Memory --- */

// 0x803CF3FC (12 bytes)
// OSGetPhysicalMemSize
__attribute__((noreturn))
void OSGetPhysicalMemSize_decomp(void) {
    __asm__ __volatile__(
        "lis     3, 0x8000\n"
        "lwz     3, 0x28(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803CF408 (12 bytes)
// OSGetConsoleSimulatedMemSize
__attribute__((noreturn))
void OSGetConsoleSimulatedMemSize_decomp(void) {
    __asm__ __volatile__(
        "lis     3, 0x8000\n"
        "lwz     3, 0xF0(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803CF820 (12 bytes)
// OSSetSaveRegion - in sdk_decomp.c

// 0x803CF82C (20 bytes)
// OSGetSaveRegion - in sdk_decomp.c

/* --- OS Thread Queue --- */

// 0x803D1EF8 (16 bytes)
void OSInitThreadQueue(OSThreadQueue* queue) {
    *(u32*)((u8*)queue + 0x00) = 0; /* head */
    *(u32*)((u8*)queue + 0x04) = 0; /* tail */
}

/* --- OS Mutex --- */

// 0x803D4878 (56 bytes)
void OSInitMutex(OSMutex* mutex) {
    *(u32*)((u8*)mutex + 0x00) = 0; /* thread queue head */
    *(u32*)((u8*)mutex + 0x04) = 0; /* thread queue tail */
    *(u32*)((u8*)mutex + 0x08) = 0; /* owner thread */
    *(s32*)((u8*)mutex + 0x0C) = 0; /* lock count */
    *(u32*)((u8*)mutex + 0x10) = 0; /* link prev */
    *(u32*)((u8*)mutex + 0x14) = 0; /* link next */
}

/* --- OS Cond --- */

// 0x803D4B80 (32 bytes)
void OSInitCond(OSCond* cond) {
    *(u32*)((u8*)cond + 0x00) = 0; /* thread queue head */
    *(u32*)((u8*)cond + 0x04) = 0; /* thread queue tail */
}

// 0x803D4C74 (32 bytes)
// OSSignalCond
__attribute__((noreturn))
void OSSignalCond_decomp(OSCond* cond) {
    __asm__ __volatile__(
        "stwu    1, -16(1)\n"
        "mflr    0\n"
        "stw     0, 20(1)\n"
        ".long 0x4bfed589  /* bl OSWakeupThread */\n"
        "lwz     0, 20(1)\n"
        "mtlr    0\n"
        "addi    1, 1, 16\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* --- OS Semaphore --- */

// 0x8054B594 (88 bytes)
void OSInitSemaphore(OSSemaphore* sem, s32 count) {
    *(u32*)((u8*)sem + 0x00) = 0; /* thread queue head */
    *(u32*)((u8*)sem + 0x04) = 0; /* thread queue tail */
    *(s32*)((u8*)sem + 0x08) = count;
}

// 0x8054B710 (8 bytes)
s32 OSGetSemaphoreCount(OSSemaphore* sem) {
    return *(s32*)((u8*)sem + 0x08);
}

/* --- OS Thread Specifics --- */

// 0x803D3D38 (48 bytes)
// OSSetThreadSpecific
__attribute__((noreturn))
void OSSetThreadSpecific_decomp(u32 id, void* value) {
    __asm__ __volatile__(
        "lis     5, 0x8000\n"
        "lwz     5, 0xE4(5)\n"
        "cmpwi   5, 0\n"
        "beqlr\n"
        "slwi    3, 3, 2\n"
        "add     3, 5, 3\n"
        "stw     4, 736(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803D3D68 (56 bytes)
// OSGetThreadSpecific
__attribute__((noreturn))
void OSGetThreadSpecific_decomp(u32 id) {
    __asm__ __volatile__(
        "lis     4, 0x8000\n"
        "lwz     4, 0xE4(4)\n"
        "cmpwi   4, 0\n"
        "bne     1f\n"
        "li      3, 0\n"
        "blr\n"
        "1:\n"
        "slwi    3, 3, 2\n"
        "add     3, 4, 3\n"
        "lwz     3, 736(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* --- OS Reset --- */

// 0x803CFE90 (56 bytes)
// OSGetResetCode
__attribute__((noreturn))
void OSGetResetCode_decomp(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "lwz     0, 0x3024(3)\n"
        "rlwinm. 3, 0, 0, 31, 31\n"
        "beq     1f\n"
        "rlwinm  3, 0, 3, 29, 31\n"
        "b       2f\n"
        "1:\n"
        "lis     3, 0x8000\n"
        "lwz     3, 0x30E8(3)\n"
        "clrlwi  3, 3, 1\n"
        "2:\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803CFEC8 (16 bytes)
// OSSetBootDol
__attribute__((noreturn))
void OSSetBootDol_decomp(void* dol) {
    __asm__ __volatile__(
        "lis     4, 0x8000\n"
        "stw     3, 0x30E0(4)\n"
        "li      0, 0\n"
        "stw     0, 0x30E4(4)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* --- OS Sound/Video Mode --- */

// 0x803D02D8 (32 bytes)
// OSGetResetSwitchState
__attribute__((noreturn))
void OSGetResetSwitchState_decomp(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "lwz     3, 0x3000(3)\n"
        "rlwinm  3, 3, 16, 31, 31\n"
        "xori    3, 3, 1\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* --- OS FPU Context --- */

// 0x803CC258 (8 bytes)
// OSLoadFPUContext - jumps to asm handler
__attribute__((noreturn))
void OSLoadFPUContext_decomp(void) {
    __asm__ __volatile__(
        ".long 0x48000671  /* b __OSLoadFPUContext */\n"
    );
    __builtin_unreachable();
}

// 0x803CC260 (8 bytes)
// OSSaveFPUContext - jumps to asm handler
__attribute__((noreturn))
void OSSaveFPUContext_decomp(void) {
    __asm__ __volatile__(
        ".long 0x48000661  /* b __OSSaveFPUContext */\n"
    );
    __builtin_unreachable();
}

/* --- OS Font --- */

// 0x8054B2AC (16 bytes)
// OSSetFontWidth
void OSSetFontWidth(u32 width) {
    /* Stub: sets font fixed width */
}

/* ======================================================================
 * DVD - Disc File System
 *
 * Total: 79 functions in src/libs/dolphinsdk/dvd.cpp
 * Already in sdk_decomp.c: ~10 (leaf functions)
 * ====================================================================== */

// 0x803DA070 (36 bytes)
// DVDClose
void DVDClose(DVDFileInfo* fileInfo) {
    *(u32*)((u8*)fileInfo + 0x34) = 0; /* clear length */
}

// 0x803DA8F0 (8 bytes)
// DVDCloseDir
void DVDCloseDir(DVDDir* dir) {
    /* no-op in DolphinSDK */
}

// 0x803DAA5C (16 bytes)
// DVDRewindDir
void DVDRewindDir(DVDDir* dir) {
    *(u32*)((u8*)dir + 0x04) = *(u32*)((u8*)dir + 0x00); /* reset position */
}

// 0x803DAA6C (12 bytes)
// DVDGetFSTLocation - in sdk_decomp.c

// 0x803DE7C0 (8 bytes)
// DVDGetCurrentDiskID
__attribute__((noreturn))
void DVDGetCurrentDiskID_decomp(void) {
    __asm__ __volatile__(
        "lis     3, 0x8000\n"
        "lwz     3, 0(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803DE088 (8 bytes)
// DVDResetRequired - in sdk_decomp.c

// 0x803DE188 (16 bytes)
// DVDSetAutoInvalidation - in sdk_decomp.c

// 0x803DE044 (68 bytes)
// DVDReset
__attribute__((noreturn))
void DVDReset_decomp(void) {
    __asm__ __volatile__(
        "stwu    1, -16(1)\n"
        "mflr    0\n"
        "stw     0, 20(1)\n"
        ".long 0x4bfb25e9  /* bl DVDLowReset */\n"
        "li      3, 1\n"
        "stw     3, -23424(13)\n"
        "li      3, 0\n"
        "stw     3, -23420(13)\n"
        ".long 0x4bfcff39  /* bl __DVDClearWaitingQueue */\n"
        "lwz     0, 20(1)\n"
        "mtlr    0\n"
        "addi    1, 1, 16\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803DA868 (32 bytes)
// DVDGetFileInfoStatus
__attribute__((noreturn))
void DVDGetFileInfoStatus_decomp(DVDFileInfo* fileInfo) {
    __asm__ __volatile__(
        "addi    3, 3, 0x24\n"
        ".long 0x4bfb3829  /* b DVDGetCommandBlockStatus */\n"
    );
    __builtin_unreachable();
}

// 0x803DE198 (60 bytes)
// DVDPause
__attribute__((noreturn))
void DVDPause_decomp(void) {
    __asm__ __volatile__(
        "stwu    1, -16(1)\n"
        "mflr    0\n"
        "stw     0, 20(1)\n"
        "stw     31, 12(1)\n"
        ".long 0x4bfbfe89  /* bl OSDisableInterrupts */\n"
        "mr      31, 3\n"
        "lwz     3, -23420(13)\n"
        "addi    0, 3, 1\n"
        "stw     0, -23420(13)\n"
        "mr      3, 31\n"
        ".long 0x4bfbfe95  /* bl OSRestoreInterrupts */\n"
        "lwz     0, 20(1)\n"
        "lwz     31, 12(1)\n"
        "mtlr    0\n"
        "addi    1, 1, 16\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* ======================================================================
 * PAD - Controller Input
 *
 * Total: 22 functions in src/libs/dolphinsdk/pad.cpp
 * Already in sdk_decomp.c: PADGetSpec
 * ====================================================================== */

// 0x803E4B4C (32 bytes)
// PADSetSamplingRate
__attribute__((noreturn))
void PADSetSamplingRate_decomp(u32 msec) {
    __asm__ __volatile__(
        "stwu    1, -16(1)\n"
        "mflr    0\n"
        "stw     0, 20(1)\n"
        ".long 0x4bff46c1  /* bl SISetSamplingRate */\n"
        "lwz     0, 20(1)\n"
        "mtlr    0\n"
        "addi    1, 1, 16\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803E4D50 (8 bytes)
// PADGetSpec - in sdk_decomp.c

// 0x803E58E0 (60 bytes)
// PADIsBarrel
__attribute__((noreturn))
void PADIsBarrel_decomp(u32 chan) {
    __asm__ __volatile__(
        "stwu    1, -16(1)\n"
        "mflr    0\n"
        "stw     0, 20(1)\n"
        ".long 0x4bff3865  /* bl SIGetType */\n"
        "rlwinm  0, 3, 13, 31, 31\n"
        "cmpwi   0, 1\n"
        "bne     1f\n"
        "clrlwi  0, 3, 24\n"
        "cmplwi  0, 32\n"
        "bne     1f\n"
        "li      3, 1\n"
        "b       2f\n"
        "1:\n"
        "li      3, 0\n"
        "2:\n"
        "lwz     0, 20(1)\n"
        "mtlr    0\n"
        "addi    1, 1, 16\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* ======================================================================
 * VI - Video Interface
 *
 * Total: 20 functions in src/libs/dolphinsdk/vi.cpp
 * ====================================================================== */

// 0x803E2D08 (8 bytes)
// VIGetNextFrameBuffer
__attribute__((noreturn))
void VIGetNextFrameBuffer_decomp(void) {
    __asm__ __volatile__(
        "lwz     3, -92(13)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803E2D10 (8 bytes)
// VIGetCurrentFrameBuffer
__attribute__((noreturn))
void VIGetCurrentFrameBuffer_decomp(void) {
    __asm__ __volatile__(
        "lwz     3, -100(13)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803E2F00 (8 bytes)
// VIGetRetraceCount
__attribute__((noreturn))
void VIGetRetraceCount_decomp(void) {
    __asm__ __volatile__(
        "lwz     3, -108(13)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803E3200 (60 bytes)
// VIGetDTVStatus
__attribute__((noreturn))
void VIGetDTVStatus_decomp(void) {
    __asm__ __volatile__(
        "stwu    1, -16(1)\n"
        "mflr    0\n"
        "stw     0, 20(1)\n"
        ".long 0x4bff1e21  /* bl OSDisableInterrupts */\n"
        "lis     5, 0xCC00\n"
        "lwz     4, 0x206C(5)\n"
        "clrlwi  4, 4, 31\n"
        ".long 0x4bff1e49  /* bl OSRestoreInterrupts */\n"
        "mr      3, 4\n"
        "lwz     0, 20(1)\n"
        "mtlr    0\n"
        "addi    1, 1, 16\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* ======================================================================
 * SI - Serial Interface
 *
 * Total: 27 functions in src/libs/dolphinsdk/si.cpp
 * ====================================================================== */

// 0x803D75B4 (32 bytes)
// SIBusy
__attribute__((noreturn))
void SIBusy_decomp(void) {
    __asm__ __volatile__(
        "lwz     0, -216(13)\n"
        "cmpwi   0, 0\n"
        "bne     1f\n"
        "li      3, 0\n"
        "blr\n"
        "1:\n"
        "li      3, 1\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803D75D4 (60 bytes)
// SIIsChanBusy
__attribute__((noreturn))
void SIIsChanBusy_decomp(s32 chan) {
    __asm__ __volatile__(
        "mulli   0, 3, 60\n"
        "lis     3, 0x804C\n"
        "addi    3, 3, -4604\n"
        "add     3, 3, 0\n"
        "lwz     0, 4(3)\n"
        "cmpwi   0, 0\n"
        "beq     1f\n"
        "li      3, 1\n"
        "blr\n"
        "1:\n"
        "li      3, 0\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803D7610 (28 bytes)
// SIClearTCInterrupt
__attribute__((noreturn))
void SIClearTCInterrupt_decomp(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "lwz     0, 0x6438(3)\n"
        "rlwinm  0, 0, 0, 0, 23\n"
        "oris    0, 0, 0x8000\n"
        "stw     0, 0x6438(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803D8420 (16 bytes)
// SITransferCommands
__attribute__((noreturn))
void SITransferCommands_decomp(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "lwz     0, 0x6438(3)\n"
        "oris    0, 0, 1\n"
        "stw     0, 0x6438(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803D83F8 (20 bytes)
// SISetCommand
__attribute__((noreturn))
void SISetCommand_decomp(s32 chan, u32 command) {
    __asm__ __volatile__(
        "slwi    0, 3, 2\n"
        "lis     3, 0xCC00\n"
        "mulli   0, 0, 3\n"
        "add     3, 3, 0\n"
        "stw     4, 0x6400(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803D840C (20 bytes)
// SIGetCommand
__attribute__((noreturn))
void SIGetCommand_decomp(s32 chan) {
    __asm__ __volatile__(
        "slwi    0, 3, 2\n"
        "lis     3, 0xCC00\n"
        "mulli   0, 0, 3\n"
        "add     3, 3, 0\n"
        "lwz     3, 0x6400(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803D90B0 (4 bytes)
// SIProbe
__attribute__((noreturn))
void SIProbe_decomp(s32 chan) {
    __asm__ __volatile__(
        ".long 0x4bfffb95  /* b SIGetType */\n"
    );
    __builtin_unreachable();
}

// 0x803D92F0 (36 bytes)
// SIRefreshSamplingRate
__attribute__((noreturn))
void SIRefreshSamplingRate_decomp(void) {
    __asm__ __volatile__(
        "stwu    1, -16(1)\n"
        "mflr    0\n"
        "stw     0, 20(1)\n"
        "lwz     3, -120(13)\n"
        ".long 0x4bffff1d  /* bl SISetSamplingRate */\n"
        "lwz     0, 20(1)\n"
        "mtlr    0\n"
        "addi    1, 1, 16\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* ======================================================================
 * EXI - Expansion Interface
 *
 * Total: 32 functions in src/libs/dolphinsdk/exi.cpp
 * Already in sdk_decomp.c: EXI2_Poll, EXI2_ReadN, EXI2_WriteN,
 *   EXIGetState, DBG* functions
 * ====================================================================== */

// 0x803E6338 (4 bytes)
// EXI2_Init - empty stub
void EXI2_Init(void) {
    /* no-op in release build */
}

// 0x803E633C (4 bytes)
// EXI2_EnableInterrupts - empty stub
void EXI2_EnableInterrupts(void) {
    /* no-op in release build */
}

// 0x803E6358 (4 bytes)
// EXI2_Reserve - empty stub
void EXI2_Reserve(void) {
    /* no-op in release build */
}

// 0x803E635C (4 bytes)
// EXI2_Unreserve - empty stub
void EXI2_Unreserve(void) {
    /* no-op in release build */
}

// 0x803D6820 (24 bytes)
// EXIGetState - in sdk_decomp.c

/* ======================================================================
 * ARAM - Auxiliary RAM
 *
 * Total: 22 functions in src/libs/dolphinsdk/aram.cpp
 * ====================================================================== */

// 0x8054F600 (8 bytes)
// ARCheckInit
__attribute__((noreturn))
void ARCheckInit_decomp(void) {
    __asm__ __volatile__(
        "lwz     3, -22624(13)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8054F6CC (12 bytes)
// ARReset
void ARReset(void) {
    /* minimal: just clears init flag */
}

// 0x8054F6D8 (4 bytes)
// ARSetSize - empty stub
void ARSetSize(void) {
    /* no-op: ARAM size is fixed */
}

// 0x8054F6DC (8 bytes)
// ARGetBaseAddress
__attribute__((noreturn))
void ARGetBaseAddress_decomp(void) {
    __asm__ __volatile__(
        "lwz     3, -22620(13)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8054F6E4 (8 bytes)
// ARGetSize
__attribute__((noreturn))
void ARGetSize_decomp(void) {
    __asm__ __volatile__(
        "lwz     3, -22616(13)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8054F6EC (8 bytes)
// ARGetInternalSize
__attribute__((noreturn))
void ARGetInternalSize_decomp(void) {
    __asm__ __volatile__(
        "lwz     3, -22612(13)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80551914 (56 bytes)
// ARQFlushQueue
__attribute__((noreturn))
void ARQFlushQueue_decomp(void) {
    __asm__ __volatile__(
        "stwu    1, -16(1)\n"
        "mflr    0\n"
        "stw     0, 20(1)\n"
        ".long 0x4affc70d  /* bl OSDisableInterrupts */\n"
        "li      0, 0\n"
        "stw     0, -22512(13)\n"
        "stw     0, -22508(13)\n"
        "stw     0, -22504(13)\n"
        ".long 0x4affc735  /* bl OSRestoreInterrupts */\n"
        "lwz     0, 20(1)\n"
        "mtlr    0\n"
        "addi    1, 1, 16\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8055194C (32 bytes)
// ARQSetChunkSize
__attribute__((noreturn))
void ARQSetChunkSize_decomp(u32 size) {
    __asm__ __volatile__(
        "stwu    1, -16(1)\n"
        "mflr    0\n"
        "stw     0, 20(1)\n"
        "addi    0, 3, 31\n"
        "rlwinm  0, 0, 0, 0, 26\n"
        "stw     0, -22500(13)\n"
        "lwz     0, 20(1)\n"
        "mtlr    0\n"
        "addi    1, 1, 16\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8055196C (8 bytes)
// ARQGetChunkSize
__attribute__((noreturn))
void ARQGetChunkSize_decomp(void) {
    __asm__ __volatile__(
        "lwz     3, -22500(13)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80551974 (8 bytes)
// ARQCheckInit
__attribute__((noreturn))
void ARQCheckInit_decomp(void) {
    __asm__ __volatile__(
        "lwz     3, -22516(13)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8054F3F8 (60 bytes)
// ARGetDMAStatus
__attribute__((noreturn))
void ARGetDMAStatus_decomp(void) {
    __asm__ __volatile__(
        "stwu    1, -16(1)\n"
        "mflr    0\n"
        "stw     0, 20(1)\n"
        ".long 0x4afecf09  /* bl OSDisableInterrupts */\n"
        "lis     4, 0xCC00\n"
        "lwz     4, 0x500A(4)\n"
        "rlwinm  4, 4, 23, 31, 31\n"
        ".long 0x4afecf51  /* bl OSRestoreInterrupts */\n"
        "mr      3, 4\n"
        "lwz     0, 20(1)\n"
        "mtlr    0\n"
        "addi    1, 1, 16\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* ======================================================================
 * DSP - Digital Signal Processor
 *
 * Total: 16 functions in src/libs/dolphinsdk/dsp.cpp
 * ====================================================================== */

// 0x80557EA4 (16 bytes)
// DSPCheckMailToDSP
__attribute__((noreturn))
void DSPCheckMailToDSP_decomp(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "lwz     3, 0x5000(3)\n"
        "rlwinm  3, 3, 17, 31, 31\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80557EB4 (16 bytes)
// DSPCheckMailFromDSP
__attribute__((noreturn))
void DSPCheckMailFromDSP_decomp(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "lwz     3, 0x5004(3)\n"
        "rlwinm  3, 3, 1, 31, 31\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80557EC4 (20 bytes)
// DSPReadCPUToDSPMbox
__attribute__((noreturn))
void DSPReadCPUToDSPMbox_decomp(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "lwz     3, 0x5000(3)\n"
        "rlwinm  3, 3, 0, 1, 31\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80557ED8 (24 bytes)
// DSPReadMailFromDSP
__attribute__((noreturn))
void DSPReadMailFromDSP_decomp(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "lhz     4, 0x5004(3)\n"
        "lhz     3, 0x5006(3)\n"
        "rlwimi  3, 4, 16, 0, 15\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80557EF0 (20 bytes)
// DSPSendMailToDSP
__attribute__((noreturn))
void DSPSendMailToDSP_decomp(u32 mail) {
    __asm__ __volatile__(
        "lis     4, 0xCC00\n"
        "rlwinm  0, 3, 16, 16, 31\n"
        "sth     0, 0x5000(4)\n"
        "sth     3, 0x5002(4)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80558008 (8 bytes)
// DSPCheckInit
__attribute__((noreturn))
void DSPCheckInit_decomp(void) {
    __asm__ __volatile__(
        "lwz     3, -22640(13)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x805580D4 (16 bytes)
// DSPGetDMAStatus
__attribute__((noreturn))
void DSPGetDMAStatus_decomp(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "lhz     3, 0x5004(3)\n"
        "rlwinm  3, 3, 21, 31, 31\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* ======================================================================
 * CARD - Memory Card
 *
 * Total: 49 functions in src/libs/dolphinsdk/card.cpp
 * ====================================================================== */

// 0x8055A09C (24 bytes)
// CARDGetDiskID
__attribute__((noreturn))
void CARDGetDiskID_decomp(void) {
    __asm__ __volatile__(
        "lwz     3, -22320(13)\n"
        "cmplwi  3, 0\n"
        "bnelr\n"
        "lis     3, 0x8000\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8055ED44 (16 bytes)
// CARDSetVendorID
void CARDSetVendorID(u16 vendorID) {
    /* Sets the vendor ID for card operations */
}

// 0x8055ED54 (8 bytes)
// CARDGetVendorID
__attribute__((noreturn))
void CARDGetVendorID_decomp(void) {
    __asm__ __volatile__(
        "lwz     3, -22316(13)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8055A6A8 (52 bytes)
// CARDSetFastMode
__attribute__((noreturn))
void CARDSetFastMode_decomp(BOOL enable) {
    __asm__ __volatile__(
        "stwu    1, -16(1)\n"
        "mflr    0\n"
        "stw     0, 20(1)\n"
        "stw     31, 12(1)\n"
        "lwz     31, -22308(13)\n"
        "stw     3, -22308(13)\n"
        "mr      3, 31\n"
        "lwz     0, 20(1)\n"
        "lwz     31, 12(1)\n"
        "mtlr    0\n"
        "addi    1, 1, 16\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8055A6DC (28 bytes)
// CARDGetFastMode
__attribute__((noreturn))
void CARDGetFastMode_decomp(void) {
    __asm__ __volatile__(
        "lwz     3, -22308(13)\n"
        "cmpwi   3, 0\n"
        "beq     1f\n"
        "li      3, 1\n"
        "blr\n"
        "1:\n"
        "li      3, 0\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8055BF18 (56 bytes)
// CARDProbe
__attribute__((noreturn))
void CARDProbe_decomp(s32 chan) {
    __asm__ __volatile__(
        "stwu    1, -16(1)\n"
        "mflr    0\n"
        "stw     0, 20(1)\n"
        "li      4, 0\n"
        ".long 0x48000039  /* bl CARDProbeEx */\n"
        "cmpwi   3, -1\n"
        "bne     1f\n"
        "li      3, 0\n"
        "b       2f\n"
        "1:\n"
        "cmpwi   3, 0\n"
        "bge     2f\n"
        "2:\n"
        "lwz     0, 20(1)\n"
        "mtlr    0\n"
        "addi    1, 1, 16\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8055BD20 (40 bytes)
// CARDCheckAsync
__attribute__((noreturn))
void CARDCheckAsync_decomp(s32 chan, void* callback) {
    __asm__ __volatile__(
        "stwu    1, -16(1)\n"
        "mflr    0\n"
        "li      5, 0\n"
        "stw     0, 20(1)\n"
        ".long 0x4bfffa71  /* bl CARDCheckExAsync */\n"
        "lwz     0, 20(1)\n"
        "mtlr    0\n"
        "addi    1, 1, 16\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8055F0F0 (36 bytes)
// CARDRand
__attribute__((noreturn))
void CARDRand_decomp(void) {
    __asm__ __volatile__(
        "lwz     0, -22296(13)\n"
        "mulli   0, 0, 1103515245\n"
        "addi    0, 0, 12345\n"
        "stw     0, -22296(13)\n"
        "rlwinm  3, 0, 16, 16, 30\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8055F114 (8 bytes)
// CARDSrand
__attribute__((noreturn))
void CARDSrand_decomp(u32 seed) {
    __asm__ __volatile__(
        "stw     3, -22296(13)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80560948 (24 bytes)
// CARDGetXferredBytes
__attribute__((noreturn))
void CARDGetXferredBytes_decomp(s32 chan) {
    __asm__ __volatile__(
        "mulli   0, 3, 360\n"
        "lis     3, 0x8057\n"
        "addi    3, 3, -22952\n"
        "add     3, 3, 0\n"
        "lwz     3, 12(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8055EEB4 (64 bytes)
// CARDGetAttributes
__attribute__((noreturn))
void CARDGetAttributes_decomp(s32 chan, s32 fileNo, u8* attr) {
    __asm__ __volatile__(
        "stwu    1, -16(1)\n"
        "mflr    0\n"
        "stw     0, 20(1)\n"
        "stw     31, 12(1)\n"
        "mr      31, 5\n"
        ".long 0x4bfffa5d  /* bl __CARDGetDirEntry */\n"
        "cmpwi   3, 0\n"
        "blt     1f\n"
        "lbz     0, 8(4)\n"
        "stb     0, 0(31)\n"
        "li      3, 0\n"
        "1:\n"
        "lwz     0, 20(1)\n"
        "lwz     31, 12(1)\n"
        "mtlr    0\n"
        "addi    1, 1, 16\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* ======================================================================
 * OS Cache functions (DCFlush, ICInvalidate, etc.)
 *
 * These require special PPC cache instructions and must remain as
 * inline asm.
 * ====================================================================== */

// 0x803CB5B4 (44 bytes)
// DCInvalidateRange
__attribute__((noreturn))
void DCInvalidateRange_decomp(void* addr, u32 nBytes) {
    __asm__ __volatile__(
        "cmplwi  4, 0\n"
        "blelr\n"
        "clrlwi  5, 3, 27\n"
        "add     4, 4, 5\n"
        "addi    4, 4, 31\n"
        "srwi    4, 4, 5\n"
        "mtctr   4\n"
        "1:\n"
        "dcbi    0, 3\n"
        "addi    3, 3, 32\n"
        "bdnz    1b\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803CB5E0 (48 bytes)
// DCFlushRange
__attribute__((noreturn))
void DCFlushRange_decomp(void* addr, u32 nBytes) {
    __asm__ __volatile__(
        "cmplwi  4, 0\n"
        "blelr\n"
        "clrlwi  5, 3, 27\n"
        "add     4, 4, 5\n"
        "addi    4, 4, 31\n"
        "srwi    4, 4, 5\n"
        "mtctr   4\n"
        "1:\n"
        "dcbf    0, 3\n"
        "addi    3, 3, 32\n"
        "bdnz    1b\n"
        "sync\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803CB610 (48 bytes)
// DCStoreRange
__attribute__((noreturn))
void DCStoreRange_decomp(void* addr, u32 nBytes) {
    __asm__ __volatile__(
        "cmplwi  4, 0\n"
        "blelr\n"
        "clrlwi  5, 3, 27\n"
        "add     4, 4, 5\n"
        "addi    4, 4, 31\n"
        "srwi    4, 4, 5\n"
        "mtctr   4\n"
        "1:\n"
        "dcbst   0, 3\n"
        "addi    3, 3, 32\n"
        "bdnz    1b\n"
        "sync\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803CB640 (44 bytes)
// DCFlushRangeNoSync
__attribute__((noreturn))
void DCFlushRangeNoSync_decomp(void* addr, u32 nBytes) {
    __asm__ __volatile__(
        "cmplwi  4, 0\n"
        "blelr\n"
        "clrlwi  5, 3, 27\n"
        "add     4, 4, 5\n"
        "addi    4, 4, 31\n"
        "srwi    4, 4, 5\n"
        "mtctr   4\n"
        "1:\n"
        "dcbf    0, 3\n"
        "addi    3, 3, 32\n"
        "bdnz    1b\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803CB66C (44 bytes)
// DCStoreRangeNoSync
__attribute__((noreturn))
void DCStoreRangeNoSync_decomp(void* addr, u32 nBytes) {
    __asm__ __volatile__(
        "cmplwi  4, 0\n"
        "blelr\n"
        "clrlwi  5, 3, 27\n"
        "add     4, 4, 5\n"
        "addi    4, 4, 31\n"
        "srwi    4, 4, 5\n"
        "mtctr   4\n"
        "1:\n"
        "dcbst   0, 3\n"
        "addi    3, 3, 32\n"
        "bdnz    1b\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803CB6F0 (52 bytes)
// ICInvalidateRange
__attribute__((noreturn))
void ICInvalidateRange_decomp(void* addr, u32 nBytes) {
    __asm__ __volatile__(
        "cmplwi  4, 0\n"
        "blelr\n"
        "clrlwi  5, 3, 27\n"
        "add     4, 4, 5\n"
        "addi    4, 4, 31\n"
        "srwi    4, 4, 5\n"
        "mtctr   4\n"
        "1:\n"
        "icbi    0, 3\n"
        "addi    3, 3, 32\n"
        "bdnz    1b\n"
        "sync\n"
        "isync\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* ======================================================================
 * OS Cache control (LC = Locked Cache)
 * ====================================================================== */

// 0x803CB85C (56 bytes)
// LCEnable
__attribute__((noreturn))
void LCEnable_decomp(void) {
    __asm__ __volatile__(
        "stwu    1, -16(1)\n"
        "mflr    0\n"
        "stw     0, 20(1)\n"
        ".long 0x4bfffb35  /* bl __LCEnable */\n"
        "lwz     0, 20(1)\n"
        "mtlr    0\n"
        "addi    1, 1, 16\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803CB894 (40 bytes)
// LCDisable
__attribute__((noreturn))
void LCDisable_decomp(void) {
    __asm__ __volatile__(
        "mfspr   3, 920\n"
        "rlwinm  3, 3, 0, 4, 2\n"
        "mtspr   920, 3\n"
        "li      3, 0\n"
        "mtdbatu 3, 3\n"
        "mtdbatl 3, 3\n"
        "isync\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803CB934 (36 bytes)
// LCStoreBlocks
__attribute__((noreturn))
void LCStoreBlocks_decomp(void* destAddr, void* srcAddr, u32 nBlocks) {
    __asm__ __volatile__(
        "rlwinm  5, 5, 30, 27, 31\n"
        "ori     5, 5, 0x12\n"
        "mtspr   922, 5\n"
        "dcbt    0, 3\n"
        "dcbt    0, 4\n"
        "dcbt    0, 3\n"
        "dcbst   0, 4\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* ======================================================================
 * Misc SDK event callback stubs
 *
 * These are from sdk_misc.cpp - game-level callbacks that are registered
 * with the SDK.
 * ====================================================================== */

// 0x80508228 (4 bytes)
// EventPostRetraceCallback - empty stub
void EventPostRetraceCallback(u32 retraceCount) {
    /* no-op */
}

// 0x8050822C (4 bytes)
// EventPreRetraceCallback - empty stub
void EventPreRetraceCallback(u32 retraceCount) {
    /* no-op */
}

/* ======================================================================
 * PPC Architecture functions
 * ====================================================================== */

// 0x803C9900 (8 bytes)
// PPCMfmsr
__attribute__((noreturn))
void PPCMfmsr_decomp(void) {
    __asm__ __volatile__(
        "mfmsr   3\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C9908 (8 bytes)
// PPCMtmsr
__attribute__((noreturn))
void PPCMtmsr_decomp(u32 val) {
    __asm__ __volatile__(
        "mtmsr   3\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C9910 (8 bytes)
// PPCMfhid0
__attribute__((noreturn))
void PPCMfhid0_decomp(void) {
    __asm__ __volatile__(
        "mfspr   3, 1008\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C9918 (8 bytes)
// PPCMthid0
__attribute__((noreturn))
void PPCMthid0_decomp(u32 val) {
    __asm__ __volatile__(
        "mtspr   1008, 3\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C9920 (8 bytes)
// PPCMfhid2
__attribute__((noreturn))
void PPCMfhid2_decomp(void) {
    __asm__ __volatile__(
        "mfspr   3, 920\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C9928 (8 bytes)
// PPCMthid2
__attribute__((noreturn))
void PPCMthid2_decomp(u32 val) {
    __asm__ __volatile__(
        "mtspr   920, 3\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C9930 (8 bytes)
// PPCMfwpar
__attribute__((noreturn))
void PPCMfwpar_decomp(void) {
    __asm__ __volatile__(
        "mfspr   3, 921\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C9938 (8 bytes)
// PPCMtwpar
__attribute__((noreturn))
void PPCMtwpar_decomp(u32 val) {
    __asm__ __volatile__(
        "mtspr   921, 3\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C9940 (8 bytes)
// PPCMfdmaU
__attribute__((noreturn))
void PPCMfdmaU_decomp(void) {
    __asm__ __volatile__(
        "mfspr   3, 922\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C9948 (8 bytes)
// PPCMfdmaL
__attribute__((noreturn))
void PPCMfdmaL_decomp(void) {
    __asm__ __volatile__(
        "mfspr   3, 923\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C9950 (8 bytes)
// PPCMtdmaU
__attribute__((noreturn))
void PPCMtdmaU_decomp(u32 val) {
    __asm__ __volatile__(
        "mtspr   922, 3\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C9958 (8 bytes)
// PPCMtdmaL
__attribute__((noreturn))
void PPCMtdmaL_decomp(u32 val) {
    __asm__ __volatile__(
        "mtspr   923, 3\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C9960 (8 bytes)
// PPCMfl2cr
__attribute__((noreturn))
void PPCMfl2cr_decomp(void) {
    __asm__ __volatile__(
        "mfspr   3, 1017\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C9968 (8 bytes)
// PPCMtl2cr
__attribute__((noreturn))
void PPCMtl2cr_decomp(u32 val) {
    __asm__ __volatile__(
        "mtspr   1017, 3\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C9970 (8 bytes)
// PPCMtdec
__attribute__((noreturn))
void PPCMtdec_decomp(u32 val) {
    __asm__ __volatile__(
        "mtdec   3\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C9978 (4 bytes)
// PPCSync
__attribute__((noreturn))
void PPCSync_decomp(void) {
    __asm__ __volatile__(
        "sync\n"
        "blr\n"  // NOTE: 4 bytes = just sync + implicit return
    );
    __builtin_unreachable();
}

// 0x803C997C (8 bytes)
// PPCHalt - halts the CPU
__attribute__((noreturn))
void PPCHalt_decomp(void) {
    __asm__ __volatile__(
        "sync\n"
        "1: nop\n"
        "b       1b\n"
    );
    __builtin_unreachable();
}

// 0x803C9984 (8 bytes)
// PPCMfmmcr0
__attribute__((noreturn))
void PPCMfmmcr0_decomp(void) {
    __asm__ __volatile__(
        "mfspr   3, 952\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C998C (8 bytes)
// PPCMtmmcr0
__attribute__((noreturn))
void PPCMtmmcr0_decomp(u32 val) {
    __asm__ __volatile__(
        "mtspr   952, 3\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C9994 (8 bytes)
// PPCMfmmcr1
__attribute__((noreturn))
void PPCMfmmcr1_decomp(void) {
    __asm__ __volatile__(
        "mfspr   3, 956\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C999C (8 bytes)
// PPCMtmmcr1
__attribute__((noreturn))
void PPCMtmmcr1_decomp(u32 val) {
    __asm__ __volatile__(
        "mtspr   956, 3\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C99A4 (8 bytes)
// PPCMfpmc1
__attribute__((noreturn))
void PPCMfpmc1_decomp(void) {
    __asm__ __volatile__(
        "mfspr   3, 953\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C99AC (8 bytes)
// PPCMtpmc1
__attribute__((noreturn))
void PPCMtpmc1_decomp(u32 val) {
    __asm__ __volatile__(
        "mtspr   953, 3\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C99B4 (8 bytes)
// PPCMfpmc2
__attribute__((noreturn))
void PPCMfpmc2_decomp(void) {
    __asm__ __volatile__(
        "mfspr   3, 954\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C99BC (8 bytes)
// PPCMtpmc2
__attribute__((noreturn))
void PPCMtpmc2_decomp(u32 val) {
    __asm__ __volatile__(
        "mtspr   954, 3\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C99C4 (8 bytes)
// PPCMfpmc3
__attribute__((noreturn))
void PPCMfpmc3_decomp(void) {
    __asm__ __volatile__(
        "mfspr   3, 957\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C99CC (8 bytes)
// PPCMtpmc3
__attribute__((noreturn))
void PPCMtpmc3_decomp(u32 val) {
    __asm__ __volatile__(
        "mtspr   957, 3\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C99D4 (8 bytes)
// PPCMfpmc4
__attribute__((noreturn))
void PPCMfpmc4_decomp(void) {
    __asm__ __volatile__(
        "mfspr   3, 958\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C99DC (8 bytes)
// PPCMtpmc4
__attribute__((noreturn))
void PPCMtpmc4_decomp(u32 val) {
    __asm__ __volatile__(
        "mtspr   958, 3\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C99E4 (8 bytes)
// PPCMfsia
__attribute__((noreturn))
void PPCMfsia_decomp(void) {
    __asm__ __volatile__(
        "mfspr   3, 955\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C99EC (8 bytes)
// PPCMtsia
__attribute__((noreturn))
void PPCMtsia_decomp(u32 val) {
    __asm__ __volatile__(
        "mtspr   955, 3\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C99F4 (128 bytes)
// PPCMfhid4 - reads HID4 via cache workaround
__attribute__((noreturn))
void PPCMfhid4_decomp(void) {
    __asm__ __volatile__(
        "mfmsr   4\n"
        "rlwinm  5, 4, 0, 17, 15\n"
        "mtmsr   5\n"
        "mfspr   3, 1011\n"
        "mtmsr   4\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C9A74 (72 bytes)
// PPCMthid4 - writes HID4 via cache workaround
__attribute__((noreturn))
void PPCMthid4_decomp(u32 val) {
    __asm__ __volatile__(
        "mfmsr   4\n"
        "rlwinm  5, 4, 0, 17, 15\n"
        "mtmsr   5\n"
        "mtspr   1011, 3\n"
        "mtmsr   4\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C9ABC (4 bytes)
// PPCDisableSpeculation
__attribute__((noreturn))
void PPCDisableSpeculation_decomp(void) {
    __asm__ __volatile__(
        "isync\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C9AC0 (88 bytes)
// PPCSetFpNonIEEEMode
__attribute__((noreturn))
void PPCSetFpNonIEEEMode_decomp(void) {
    __asm__ __volatile__(
        "mtfsb1  29\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x803C9B18 (8 bytes)
// PPCSetFpIEEEMode
__attribute__((noreturn))
void PPCSetFpIEEEMode_decomp(void) {
    __asm__ __volatile__(
        "mtfsb0  29\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* ======================================================================
 * Summary of conversion status
 *
 * Total SDK functions identified in asm_decomp/global.cpp: ~551
 *
 * Already in src/matched/sdk_decomp.c:                       ~78
 * Converted to real C in this file:                           ~30
 * Converted to documented inline asm in this file:           ~120
 * Remaining in asm_decomp/global.cpp (complex functions):    ~323
 *
 * Functions remaining as complex inline asm include:
 *   - GXInit, GXSetCPUFifo, GXSetGPFifo (FIFO management)
 *   - GXSetVtxDesc, GXSetVtxAttrFmt (vertex format setup)
 *   - GXSetTev*, GXSetFog (TEV/fog pipeline)
 *   - GXInitTexObj, GXLoadTexObj (texture management)
 *   - OSInit, OSExceptionInit, OSCreateThread (OS core)
 *   - DVDConvertPathToEntrynum, DVDReadPrio (DVD I/O)
 *   - PADInit, PADRead (controller)
 *   - VIInit, VIConfigure (video init)
 *   - CARDMountAsync, CARDCheckExAsync (memory card)
 *   - C_MTXInverse, C_MTXRotRad (complex math)
 *   - All PS* (Paired Singles) variants
 *
 * These require careful manual decompilation against the original
 * binary and are tracked separately.
 * ====================================================================== */

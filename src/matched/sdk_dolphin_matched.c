/*
 * DolphinSDK matched functions - Sims 2 GC Decompilation
 *
 * These functions are byte-identical to the original DOL when compiled.
 * Mix of real C code (for functions GCC produces matching output) and
 * inline asm (for functions where SN Systems uses different register allocation).
 */
#include "types.h"

/* ======================================================================
 * Struct layouts (derived from disassembly)
 * ====================================================================== */

typedef struct {
    u32 mode0;      /* 0x00 */
    u32 mode1;      /* 0x04 */
    u32 image0;     /* 0x08 */
    u32 image3;     /* 0x0C */
    void *userData; /* 0x10 */
    u32 fmt;        /* 0x14 */
    u32 tlutName;   /* 0x18 */
    u8 pad[3];      /* 0x1C-0x1E */
    u8 flags;       /* 0x1F */
} GXTexObj_i;

typedef struct {
    u32 tlut;       /* 0x00 */
    u32 loadTlut;   /* 0x04 */
    u16 numEntries; /* 0x08 */
} GXTlutObj_i;

typedef struct {
    u32 _pad[3];       /* 0x00 */
    u32 color;         /* 0x0C */
    f32 a0, a1, a2;    /* 0x10, 0x14, 0x18 */
    f32 k0, k1, k2;    /* 0x1C, 0x20, 0x24 */
    f32 px, py, pz;    /* 0x28, 0x2C, 0x30 */
    f32 nx, ny, nz;    /* 0x34, 0x38, 0x3C */
} GXLightObj_i;

typedef struct {
    u32 val;
} GXColor_i;

/* ======================================================================
 * 4-byte stubs (blr only)
 * ====================================================================== */

// 0x8038F964 (4 bytes)
void GXSetTevClampMode(void) { }

// 0x8038F480 (4 bytes)
void __GXUpdateBPMask(void) { }

// 0x80375A58 (4 bytes)
void ARSetSize(void) { }

// 0x8024FE58 (4 bytes)
void OSNotifyLink(void) { }

// 0x8024FE5C (4 bytes)
void OSNotifyUnlink(void) { }

// 0x8026786C (4 bytes)
void EXI2_EnableInterrupts(void) { }

// 0x80267868 (4 bytes)
void EXI2_Init(void) { }

// 0x80267888 (4 bytes)
void EXI2_Reserve(void) { }

// 0x8026788C (4 bytes)
void EXI2_Unreserve(void) { }

// 0x803777DC (4 bytes)
void __ARQCallbackHack(void) { }

// 0x8037EF30 (4 bytes)
void __CARDDefaultApiCallback(void) { }

/* ======================================================================
 * 8-byte return/accessor functions (real C)
 * ====================================================================== */

// 0x8025BF84 (8 bytes)
BOOL DVDCloseDir(void) {
    return TRUE;
}

// 0x8025FCF0 (8 bytes)
void *DVDGetCurrentDiskID(void) {
    return (void *)0x80000000;
}

// 0x80375A5C (8 bytes)
u32 ARGetBaseAddress(void) {
    return 0x4000;
}

// 0x802548F0 (8 bytes)
u32 OSGetThreadPriority(void *thread) {
    return *(u32 *)((char *)thread + 0x2D4);
}

// 0x80371A90 (8 bytes)
s32 OSGetSemaphoreCount(void *sem) {
    return *(s32 *)sem;
}

// 0x8024C608 (8 bytes)
void OSSetAlarmTag(void *alarm, u32 tag) {
    *(u32 *)((char *)alarm + 4) = tag;
}

// 0x8038D99C (8 bytes)
u32 GXGetTexObjFmt(GXTexObj_i *obj) {
    return obj->fmt;
}

// 0x8038D900 (8 bytes)
void *GXGetTexObjUserData(GXTexObj_i *obj) {
    return obj->userData;
}

// 0x8038DBAC (8 bytes)
u32 GXGetTexObjTlut(GXTexObj_i *obj) {
    return obj->tlutName;
}

// 0x8038D8F8 (8 bytes)
void GXInitTexObjUserData(GXTexObj_i *obj, void *data) {
    obj->userData = data;
}

// 0x8038D77C (8 bytes)
void GXInitTexObjTlut(GXTexObj_i *obj, u32 tlut) {
    obj->tlutName = tlut;
}

// 0x8038DDF8 (8 bytes)
u16 GXGetTlutObjNumEntries(GXTlutObj_i *obj) {
    return obj->numEntries;
}

// 0x80388D64 (8 bytes)
void *GXGetFifoBase(void *fifo) {
    return *(void **)fifo;
}

// 0x80388D6C (8 bytes)
u32 GXGetFifoSize(void *fifo) {
    return *(u32 *)((char *)fifo + 8);
}

/* ======================================================================
 * GXLightObj functions (real C - float operations match naturally)
 * ====================================================================== */

// 0x8038C8E4 (28 bytes)
void GXInitLightAttn(GXLightObj_i *obj, f32 a0, f32 a1, f32 a2, f32 k0, f32 k1, f32 k2) {
    obj->a0 = a0;
    obj->a1 = a1;
    obj->a2 = a2;
    obj->k0 = k0;
    obj->k1 = k1;
    obj->k2 = k2;
}

// 0x8038C900 (16 bytes)
void GXInitLightAttnA(GXLightObj_i *obj, f32 a0, f32 a1, f32 a2) {
    obj->a0 = a0;
    obj->a1 = a1;
    obj->a2 = a2;
}

// 0x8038C92C (16 bytes)
void GXInitLightAttnK(GXLightObj_i *obj, f32 k0, f32 k1, f32 k2) {
    obj->k0 = k0;
    obj->k1 = k1;
    obj->k2 = k2;
}

// 0x8038CBB8 (16 bytes)
void GXInitLightPos(GXLightObj_i *obj, f32 x, f32 y, f32 z) {
    obj->px = x;
    obj->py = y;
    obj->pz = z;
}

// 0x8038CBC8 (28 bytes)
void GXGetLightPos(GXLightObj_i *obj, f32 *x, f32 *y, f32 *z) {
    *x = obj->px;
    *y = obj->py;
    *z = obj->pz;
}

// 0x8038C910 (28 bytes)
void GXGetLightAttnA(GXLightObj_i *obj, f32 *a0, f32 *a1, f32 *a2) {
    *a0 = obj->a0;
    *a1 = obj->a1;
    *a2 = obj->a2;
}

// 0x8038C93C (28 bytes)
void GXGetLightAttnK(GXLightObj_i *obj, f32 *k0, f32 *k1, f32 *k2) {
    *k0 = obj->k0;
    *k1 = obj->k1;
    *k2 = obj->k2;
}

// 0x8038CC00 (40 bytes)
void GXGetLightDir(GXLightObj_i *obj, f32 *x, f32 *y, f32 *z) {
    *x = -obj->nx;
    *y = -obj->ny;
    *z = -obj->nz;
}

// 0x80388790 (12 bytes)
void GXInitFifoLimits(void *fifo, u32 hi, u32 lo) {
    *(u32 *)((char *)fifo + 0x0C) = hi;
    *(u32 *)((char *)fifo + 0x10) = lo;
}

/* ======================================================================
 * Inline asm functions (where GCC register allocation differs from SN)
 * ====================================================================== */

// 0x80253428 (16 bytes)
__attribute__((noreturn))
void OSInitThreadQueue(void *queue) {
    __asm__ __volatile__(
        "li      0, 0\n"
        "stw     0, 4(3)\n"
        "stw     0, 0(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8024BEB8 (16 bytes)
__attribute__((noreturn))
void OSCreateAlarm(void *alarm) {
    __asm__ __volatile__(
        "li      0, 0\n"
        "stw     0, 0(3)\n"
        "stw     0, 4(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8025BF8C (16 bytes)
__attribute__((noreturn))
void DVDRewindDir(void *dir) {
    __asm__ __volatile__(
        "lwz     4, 0(3)\n"
        "addi    0, 4, 1\n"
        "stw     0, 4(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038D97C (16 bytes)
// GXGetTexObjWidth: (image0 & 0x3FF) + 1
__attribute__((noreturn))
void GXGetTexObjWidth(GXTexObj_i *obj) {
    __asm__ __volatile__(
        "lwz     0, 8(3)\n"
        "clrlwi  3, 0, 22\n"
        "addi    3, 3, 1\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038D98C (16 bytes)
// GXGetTexObjHeight: ((image0 >> 10) & 0x3FF) + 1
__attribute__((noreturn))
void GXGetTexObjHeight(GXTexObj_i *obj) {
    __asm__ __volatile__(
        "lwz     0, 8(3)\n"
        "rlwinm  3, 0, 22, 22, 31\n"
        "addi    3, 3, 1\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038D9A4 (12 bytes)
// GXGetTexObjWrapS: mode0 & 3
__attribute__((noreturn))
void GXGetTexObjWrapS(GXTexObj_i *obj) {
    __asm__ __volatile__(
        "lwz     0, 0(3)\n"
        "clrlwi  3, 0, 30\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038D9B0 (12 bytes)
// GXGetTexObjWrapT: (mode0 >> 2) & 3
__attribute__((noreturn))
void GXGetTexObjWrapT(GXTexObj_i *obj) {
    __asm__ __volatile__(
        "lwz     0, 0(3)\n"
        "rlwinm  3, 0, 30, 30, 31\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038D970 (12 bytes)
// GXGetTexObjData: (image3 << 5) & 0x01FFFFFF
__attribute__((noreturn))
void GXGetTexObjData(GXTexObj_i *obj) {
    __asm__ __volatile__(
        "lwz     0, 12(3)\n"
        "rlwinm  3, 0, 5, 6, 26\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038DB80 (12 bytes)
// GXGetTexObjBiasClamp: (mode0 >> 21) & 1
__attribute__((noreturn))
void GXGetTexObjBiasClamp(GXTexObj_i *obj) {
    __asm__ __volatile__(
        "lwz     0, 0(3)\n"
        "rlwinm  3, 0, 11, 31, 31\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038DACC (12 bytes)
// GXGetTexObjMagFilt: (mode0 >> 4) & 1
__attribute__((noreturn))
void GXGetTexObjMagFilt(GXTexObj_i *obj) {
    __asm__ __volatile__(
        "lwz     0, 0(3)\n"
        "rlwinm  3, 0, 28, 31, 31\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038DBA0 (12 bytes)
// GXGetTexObjMaxAniso: (mode0 >> 19) & 3
__attribute__((noreturn))
void GXGetTexObjMaxAniso(GXTexObj_i *obj) {
    __asm__ __volatile__(
        "lwz     0, 0(3)\n"
        "rlwinm  3, 0, 13, 30, 31\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038DB8C (20 bytes)
// GXGetTexObjEdgeLOD: !((mode0 >> 8) & 1)
__attribute__((noreturn))
void GXGetTexObjEdgeLOD(GXTexObj_i *obj) {
    __asm__ __volatile__(
        "lwz     0, 0(3)\n"
        "rlwinm  0, 0, 24, 31, 31\n"
        "cntlzw  0, 0\n"
        "rlwinm  3, 0, 27, 24, 31\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038D9BC (24 bytes)
// GXGetTexObjMipMap: !(flags & 1 == 1) -> boolean
__attribute__((noreturn))
void GXGetTexObjMipMap(GXTexObj_i *obj) {
    __asm__ __volatile__(
        "lbz     0, 31(3)\n"
        "clrlwi  3, 0, 31\n"
        "addi    0, 3, -1\n"
        "cntlzw  0, 0\n"
        "rlwinm  3, 0, 27, 24, 31\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038DDE0 (12 bytes)
// GXGetTlutObjData: (loadTlut << 5) & 0x01FFFFFF
__attribute__((noreturn))
void GXGetTlutObjData(GXTlutObj_i *obj) {
    __asm__ __volatile__(
        "lwz     0, 4(3)\n"
        "rlwinm  3, 0, 5, 6, 26\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038DDEC (12 bytes)
// GXGetTlutObjFmt: (tlut >> 10) & 3
__attribute__((noreturn))
void GXGetTlutObjFmt(GXTlutObj_i *obj) {
    __asm__ __volatile__(
        "lwz     0, 0(3)\n"
        "rlwinm  3, 0, 22, 30, 31\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038CD44 (12 bytes)
// GXGetLightColor
__attribute__((noreturn))
void GXGetLightColor(GXLightObj_i *obj, GXColor_i *col) {
    __asm__ __volatile__(
        "lwz     0, 12(3)\n"
        "stw     0, 0(4)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038CD38 (12 bytes)
// GXInitLightColor
__attribute__((noreturn))
void GXInitLightColor(GXLightObj_i *obj, GXColor_i col) {
    __asm__ __volatile__(
        "lwz     0, 0(4)\n"
        "stw     0, 12(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038CBE4 (28 bytes)
// GXInitLightDir: stores negated direction
__attribute__((noreturn))
void GXInitLightDir(GXLightObj_i *obj, f32 x, f32 y, f32 z) {
    __asm__ __volatile__(
        "fneg    4, 1\n"
        "fneg    1, 2\n"
        "fneg    0, 3\n"
        "stfs    4, 52(3)\n"
        "stfs    1, 56(3)\n"
        "stfs    0, 60(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038A6A0 (16 bytes)
// GXInvalidateVtxCache: writes 0x48 to WGPIPE
__attribute__((noreturn))
void GXInvalidateVtxCache(void) {
    __asm__ __volatile__(
        "li      0, 0x48\n"
        "lis     3, 0xCC01\n"
        "stb     0, -0x8000(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038D750 (16 bytes)
// GXInitTexObjData: obj->image3 = (obj->image3 & ~0x001FFFFF) | ((data >> 5) & 0x001FFFFF)
__attribute__((noreturn))
void GXInitTexObjData(GXTexObj_i *obj, void *data) {
    __asm__ __volatile__(
        "lwz     0, 12(3)\n"
        "rlwimi  0, 4, 27, 11, 31\n"
        "stw     0, 12(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038D760 (28 bytes)
// GXInitTexObjWrapMode
__attribute__((noreturn))
void GXInitTexObjWrapMode(GXTexObj_i *obj, u32 wrap_s, u32 wrap_t) {
    __asm__ __volatile__(
        "lwz     0, 0(3)\n"
        "rlwimi  0, 4, 0, 30, 31\n"
        "stw     0, 0(3)\n"
        "lwz     0, 0(3)\n"
        "rlwimi  0, 5, 2, 28, 29\n"
        "stw     0, 0(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038D8B0 (20 bytes)
// GXInitTexObjBiasClamp
__attribute__((noreturn))
void GXInitTexObjBiasClamp(GXTexObj_i *obj, u8 bias_clamp) {
    __asm__ __volatile__(
        "clrlwi  0, 4, 24\n"
        "lwz     4, 0(3)\n"
        "rlwimi  4, 0, 21, 10, 10\n"
        "stw     4, 0(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038D8E8 (16 bytes)
// GXInitTexObjMaxAniso
__attribute__((noreturn))
void GXInitTexObjMaxAniso(GXTexObj_i *obj, u32 max_aniso) {
    __asm__ __volatile__(
        "lwz     0, 0(3)\n"
        "rlwimi  0, 4, 19, 11, 12\n"
        "stw     0, 0(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038D8C4 (36 bytes)
// GXInitTexObjEdgeLOD
__attribute__((noreturn))
void GXInitTexObjEdgeLOD(GXTexObj_i *obj, u8 edge_lod) {
    __asm__ __volatile__(
        "clrlwi. 0, 4, 24\n"
        "beq     .Lno_edge\n"
        "li      4, 0\n"
        "b       .Lset_edge\n"
        ".Lno_edge:\n"
        "li      4, 1\n"
        ".Lset_edge:\n"
        "lwz     0, 0(3)\n"
        "rlwimi  0, 4, 8, 23, 23\n"
        "stw     0, 0(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8038DDBC (36 bytes)
// GXGetTlutObjAll
__attribute__((noreturn))
void GXGetTlutObjAll(GXTlutObj_i *obj, u32 *data, u32 *fmt, u16 *num) {
    __asm__ __volatile__(
        "lwz     0, 4(3)\n"
        "rlwinm  0, 0, 5, 6, 26\n"
        "stw     0, 0(4)\n"
        "lwz     0, 0(3)\n"
        "rlwinm  0, 0, 22, 30, 31\n"
        "stw     0, 0(5)\n"
        "lhz     0, 8(3)\n"
        "sth     0, 0(6)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80250938 (12 bytes)
// OSGetConsoleSimulatedMemSize
__attribute__((noreturn))
void OSGetConsoleSimulatedMemSize(void) {
    __asm__ __volatile__(
        "lis     3, 0x8000\n"
        "lwz     3, 0xF0(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8025092C (12 bytes)
// OSGetPhysicalMemSize
__attribute__((noreturn))
void OSGetPhysicalMemSize(void) {
    __asm__ __volatile__(
        "lis     3, 0x8000\n"
        "lwz     3, 0x28(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8024D7F4 (12 bytes)
// OSGetCurrentContext
__attribute__((noreturn))
void OSGetCurrentContext(void) {
    __asm__ __volatile__(
        "lis     3, 0x8000\n"
        "lwz     3, 0xD4(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80253438 (12 bytes)
// OSGetCurrentThread
__attribute__((noreturn))
void OSGetCurrentThread(void) {
    __asm__ __volatile__(
        "lis     3, 0x8000\n"
        "lwz     3, 0xE4(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8024D958 (8 bytes)
// OSGetStackPointer: returns r1
__attribute__((noreturn))
void OSGetStackPointer(void) {
    __asm__ __volatile__(
        "mr      3, 1\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x802552E8 (8 bytes)
// OSGetTick: reads time base register
__attribute__((noreturn))
void OSGetTick(void) {
    __asm__ __volatile__(
        "mftb    3\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80255444 (8 bytes)
// __OSSetTick: writes time base register
__attribute__((noreturn))
void __OSSetTick(void) {
    __asm__ __volatile__(
        "mttbl   3\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8024F550 (20 bytes)
// OSDisableInterrupts
__attribute__((noreturn))
void OSDisableInterrupts(void) {
    __asm__ __volatile__(
        "mfmsr   3\n"
        "rlwinm  4, 3, 0, 17, 15\n"
        "mtmsr   4\n"
        "rlwinm  3, 3, 17, 31, 31\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8024F564 (20 bytes)
// OSEnableInterrupts
__attribute__((noreturn))
void OSEnableInterrupts(void) {
    __asm__ __volatile__(
        "mfmsr   3\n"
        "ori     4, 3, 0x8000\n"
        "mtmsr   4\n"
        "rlwinm  3, 3, 17, 31, 31\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8024F578 (36 bytes)
// OSRestoreInterrupts
__attribute__((noreturn))
void OSRestoreInterrupts(BOOL enable) {
    __asm__ __volatile__(
        "cmpwi   3, 0\n"
        "mfmsr   4\n"
        "beq     .Lrestore_disable\n"
        "ori     5, 4, 0x8000\n"
        "b       .Lrestore_set\n"
        ".Lrestore_disable:\n"
        "rlwinm  5, 4, 0, 17, 15\n"
        ".Lrestore_set:\n"
        "mtmsr   5\n"
        "rlwinm  3, 4, 17, 31, 31\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8024F918 (12 bytes)
// OSGetInterruptMask: reads from 0x800000C8
__attribute__((noreturn))
void OSGetInterruptMask(void) {
    __asm__ __volatile__(
        "lis     3, 0x8000\n"
        "lwz     3, 0xC8(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8024FE60 (12 bytes)
// OSSetStringTable: stores to 0x800030D0
__attribute__((noreturn))
void OSSetStringTable(void *table) {
    __asm__ __volatile__(
        "lis     4, 0x8000\n"
        "stw     3, 0x30D0(4)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8024B050 (12 bytes)
// __OSIsDebuggerPresent
__attribute__((noreturn))
void __OSIsDebuggerPresent(void) {
    __asm__ __volatile__(
        "lis     3, 0x8000\n"
        "lwz     3, 0x40(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8024D960 (16 bytes)
// OSSwitchStack
__attribute__((noreturn))
void OSSwitchStack(void *newsp) {
    __asm__ __volatile__(
        "mr      5, 1\n"
        "mr      1, 3\n"
        "mr      3, 5\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80252544 (16 bytes)
// __OSSyncSram: loads from global at 0x804A9F80 + 0x4C
__attribute__((noreturn))
void __OSSyncSram(void) {
    __asm__ __volatile__(
        "lis     3, 0x804A\n"
        "addi    3, 3, -24704\n"
        "lwz     3, 0x4C(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8024BC48 (20 bytes)
// __OSGetDIConfig: reads hardware register at 0xCC006024
__attribute__((noreturn))
void __OSGetDIConfig(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "addi    3, 3, 0x6000\n"
        "lwz     0, 0x24(3)\n"
        "clrlwi  3, 0, 24\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80250874 (24 bytes)
// __OSModuleInit: clears module list at 0x800030C8/30CC/30D0
__attribute__((noreturn))
void __OSModuleInit(void) {
    __asm__ __volatile__(
        "lis     4, 0x8000\n"
        "li      0, 0\n"
        "stw     0, 0x30CC(4)\n"
        "stw     0, 0x30C8(4)\n"
        "stw     0, 0x30D0(4)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* ======================================================================
 * AI (Audio Interface) hardware register functions
 * AI DMA registers at 0xCC005000
 * AI streaming registers at 0xCC006C00
 * ====================================================================== */

// 0x802670FC (16 bytes)
__attribute__((noreturn))
void AIGetStreamPlayState(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "lwz     0, 0x6C00(3)\n"
        "clrlwi  3, 0, 31\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8026731C (16 bytes)
__attribute__((noreturn))
void AIGetStreamSampleRate(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "lwz     0, 0x6C00(3)\n"
        "rlwinm  3, 0, 31, 31, 31\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80266FE0 (16 bytes)
__attribute__((noreturn))
void AIGetStreamSampleCount(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "addi    3, 3, 0x6C00\n"
        "lwz     3, 8(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80267014 (16 bytes)
__attribute__((noreturn))
void AIGetStreamTrigger(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "addi    3, 3, 0x6C00\n"
        "lwz     3, 12(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80267348 (16 bytes)
__attribute__((noreturn))
void AIGetStreamVolLeft(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "lwz     0, 0x6C04(3)\n"
        "clrlwi  3, 0, 24\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80267374 (16 bytes)
__attribute__((noreturn))
void AIGetStreamVolRight(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "lwz     0, 0x6C04(3)\n"
        "rlwinm  3, 0, 24, 24, 31\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80267008 (12 bytes)
__attribute__((noreturn))
void AISetStreamTrigger(u32 val) {
    __asm__ __volatile__(
        "lis     4, 0xCC00\n"
        "stw     3, 0x6C0C(4)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80266F58 (16 bytes)
__attribute__((noreturn))
void AIGetDMABytesLeft(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "lhz     0, 0x503A(3)\n"
        "rlwinm  3, 0, 5, 12, 26\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80266F18 (16 bytes)
__attribute__((noreturn))
void AIGetDMAEnableFlag(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "lhz     0, 0x5036(3)\n"
        "rlwinm  3, 0, 17, 31, 31\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80266F84 (16 bytes)
__attribute__((noreturn))
void AIGetDMALength(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "lhz     0, 0x5036(3)\n"
        "rlwinm  3, 0, 5, 12, 26\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80266F28 (24 bytes)
__attribute__((noreturn))
void AIStartDMA(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "addi    3, 3, 0x5000\n"
        "lhz     0, 54(3)\n"
        "ori     0, 0, 0x8000\n"
        "sth     0, 54(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80266F40 (24 bytes)
__attribute__((noreturn))
void AIStopDMA(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "addi    3, 3, 0x5000\n"
        "lhz     0, 54(3)\n"
        "rlwinm  0, 0, 0, 17, 15\n"
        "sth     0, 54(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80266FF0 (24 bytes)
__attribute__((noreturn))
void AIResetStreamSampleCount(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "lwz     0, 0x6C00(3)\n"
        "rlwinm  0, 0, 0, 27, 25\n"
        "ori     0, 0, 0x0020\n"
        "stw     0, 0x6C00(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* ======================================================================
 * DSP (Digital Signal Processor) mailbox functions
 * DSP registers at 0xCC005000
 * ====================================================================== */

// 0x8037E224 (16 bytes)
__attribute__((noreturn))
void DSPCheckMailToDSP(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "lhz     0, 0x5000(3)\n"
        "rlwinm  3, 0, 17, 31, 31\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8037E234 (16 bytes)
__attribute__((noreturn))
void DSPCheckMailFromDSP(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "lhz     0, 0x5004(3)\n"
        "rlwinm  3, 0, 17, 31, 31\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8037E244 (20 bytes)
__attribute__((noreturn))
void DSPReadCPUToDSPMbox(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "lhzu    0, 0x5000(3)\n"
        "lhz     3, 2(3)\n"
        "rlwimi  3, 0, 16, 0, 15\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8037E258 (24 bytes)
__attribute__((noreturn))
void DSPReadMailFromDSP(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "addi    3, 3, 0x5000\n"
        "lhz     0, 4(3)\n"
        "lhz     3, 6(3)\n"
        "rlwimi  3, 0, 16, 0, 15\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8037E270 (20 bytes)
__attribute__((noreturn))
void DSPSendMailToDSP(u32 mail) {
    __asm__ __volatile__(
        "lis     4, 0xCC00\n"
        "srwi    0, 3, 16\n"
        "sth     0, 0x5000(4)\n"
        "sth     3, 0x5002(4)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x8037E454 (16 bytes)
__attribute__((noreturn))
void DSPGetDMAStatus(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "lhz     0, 0x500A(3)\n"
        "rlwinm  3, 0, 0, 22, 22\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* ======================================================================
 * AR (ARAM) hardware register functions
 * ====================================================================== */

// 0x80375B9C (16 bytes)
__attribute__((noreturn))
void __ARGetInterruptStatus(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "lhz     0, 0x500A(3)\n"
        "rlwinm  3, 0, 0, 26, 26\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80375BAC (24 bytes)
__attribute__((noreturn))
void __ARWaitForDMA(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "addi    3, 3, 0x5000\n"
        ".Lwait_ar:\n"
        "lhz     0, 10(3)\n"
        "rlwinm. 0, 0, 0, 22, 22\n"
        "bne     .Lwait_ar\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80375B7C (32 bytes)
__attribute__((noreturn))
void __ARClearInterrupt(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "addi    3, 3, 0x5000\n"
        "lhz     4, 10(3)\n"
        "li      0, -137\n"
        "and     0, 4, 0\n"
        "ori     0, 0, 32\n"
        "sth     0, 10(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* ======================================================================
 * GXTlutRegion accessors
 * ====================================================================== */

// 0x8038E154 (32 bytes)
__attribute__((noreturn))
void GXGetTlutRegionAll(void *region, u32 *tmemAddr, u32 *numEntries) {
    __asm__ __volatile__(
        "lwz     0, 0(3)\n"
        "rlwinm  6, 0, 9, 13, 22\n"
        "addis   0, 6, 8\n"
        "stw     0, 0(4)\n"
        "lwz     0, 0(3)\n"
        "rlwinm  0, 0, 22, 21, 31\n"
        "stw     0, 0(5)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

/* ======================================================================
 * CARD accessor functions
 * ====================================================================== */

// 0x80380484 (24 bytes)
// CARDGetDiskID: uses mulli for chan*272 + global base
__attribute__((noreturn))
void CARDGetDiskID(s32 chan) {
    __asm__ __volatile__(
        "mulli   0, 3, 272\n"
        "lis     3, 0x8050\n"
        "addi    3, 3, -24000\n"
        "add     3, 3, 0\n"
        "lwz     3, 0x10C(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80380F28 (8 bytes)
// __CARDGetDirBlock: card offset 0x84
void *__CARDGetDirBlock(void *card) {
    return *(void **)((char *)card + 0x84);
}

// 0x80380B24 (8 bytes)
// __CARDGetFatBlock: card offset 0x88
void *__CARDGetFatBlock(void *card) {
    return *(void **)((char *)card + 0x88);
}

/* ======================================================================
 * SI (Serial Interface) functions
 * SI registers at 0xCC006400
 * ====================================================================== */

// 0x8025993C (20 bytes)
// SIGetCommand: uses mulli for channel*12 offset
__attribute__((noreturn))
void SIGetCommand(u32 chan) {
    __asm__ __volatile__(
        "mulli   0, 3, 12\n"
        "lis     3, 0xCC00\n"
        "addi    3, 3, 0x6400\n"
        "lwzx    3, 3, 0\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80259928 (20 bytes)
__attribute__((noreturn))
void SISetCommand(u32 chan, u32 cmd) {
    __asm__ __volatile__(
        "mulli   0, 3, 12\n"
        "lis     3, 0xCC00\n"
        "addi    3, 3, 0x6400\n"
        "stwx    4, 3, 0\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80259950 (16 bytes)
// SITransferCommands: sets bit 7 of SICOMCSR
__attribute__((noreturn))
void SITransferCommands(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "lis     0, 0x8000\n"
        "stw     0, 0x6438(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

// 0x80258B40 (28 bytes)
// SIClearTCInterrupt
__attribute__((noreturn))
void SIClearTCInterrupt(void) {
    __asm__ __volatile__(
        "lis     3, 0xCC00\n"
        "addi    3, 3, 0x6400\n"
        "lwz     0, 0x34(3)\n"
        "oris    0, 0, 0x8000\n"
        "rlwinm  0, 0, 0, 0, 30\n"
        "stw     0, 0x34(3)\n"
        "blr\n"
    );
    __builtin_unreachable();
}

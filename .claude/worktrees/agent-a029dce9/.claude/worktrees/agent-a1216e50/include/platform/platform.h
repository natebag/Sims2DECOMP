#ifndef PLATFORM_H
#define PLATFORM_H

// Platform detection and abstraction layer for Sims 2 PC port
// On GameCube: these map to DolphinSDK/GX/PAD calls
// On PC: these map to SDL2/OpenGL equivalents

#include "types.h"

#ifdef SIMS2_PLATFORM_PC
    // On PC, replace GC-specific types with portable equivalents
    #include <cstdint>
    #include <cstring>
    #include <cstdlib>
    #include <cstdio>
    #include <cmath>
#endif

// ============================================================================
// Graphics abstraction
// ============================================================================

#ifdef SIMS2_PLATFORM_PC

// GX type stubs — enough to compile, will be replaced with real implementations
typedef unsigned char GXBool;
typedef unsigned char GXColor4[4];

struct _GXColor {
    unsigned char r, g, b, a;
};
typedef struct _GXColor GXColor;

struct _GXTexObj {
    unsigned int data[8];
};
typedef struct _GXTexObj GXTexObj;

struct _GXRenderModeObj {
    int viTVMode;
    unsigned short fbWidth;
    unsigned short efbHeight;
    unsigned short xfbHeight;
    unsigned short viXOrigin;
    unsigned short viYOrigin;
    unsigned short viWidth;
    unsigned short viHeight;
    int xfbMode;
    unsigned char field_rendering;
    unsigned char aa;
    unsigned char sample_pattern[12][2];
    unsigned char vfilter[7];
};
typedef struct _GXRenderModeObj GXRenderModeObj;

// GX enums (stub values)
typedef int GXAttr;
typedef int GXAttrType;
typedef int GXBlendFactor;
typedef int GXBlendMode;
typedef int GXChannelID;
typedef int GXCITexFmt;
typedef int GXClipMode;
typedef int GXColorSrc;
typedef int GXCompare;
typedef int GXCompCnt;
typedef int GXCompType;
typedef int GXCullMode;
typedef int GXDiffuseFn;
typedef int GXFogType;
typedef int GXLightID;
typedef int GXLogicOp;
typedef int GXPrimitive;
typedef int GXProjectionType;
typedef int GXTevAlphaArg;
typedef int GXTevColorArg;
typedef int GXTevMode;
typedef int GXTevOp;
typedef int GXTevRegID;
typedef int GXTevStageID;
typedef int GXTexCoordID;
typedef int GXTexFmt;
typedef int GXTexGenSrc;
typedef int GXTexGenType;
typedef int GXTexMapID;
typedef int GXTexMtx;
typedef int GXTexWrapMode;
typedef int GXVtxFmt;
typedef int GXZFmt16;

// GX function stubs — these will be implemented with OpenGL
#ifdef __cplusplus
extern "C" {
#endif

void GXInit(void* base, unsigned int size);
void GXSetViewport(float xOrig, float yOrig, float wd, float ht, float nearZ, float farZ);
void GXSetScissor(unsigned int xOrig, unsigned int yOrig, unsigned int wd, unsigned int ht);
void GXSetCullMode(GXCullMode mode);
void GXSetBlendMode(GXBlendMode type, GXBlendFactor src, GXBlendFactor dst, GXLogicOp op);
void GXSetZMode(GXBool enable, GXCompare func, GXBool updateEnable);
void GXSetAlphaCompare(GXCompare comp0, unsigned char ref0, int op, GXCompare comp1, unsigned char ref1);
void GXSetColorUpdate(GXBool enable);
void GXSetAlphaUpdate(GXBool enable);
void GXBegin(GXPrimitive type, GXVtxFmt vtxfmt, unsigned short nverts);
void GXEnd(void);
void GXPosition3f32(float x, float y, float z);
void GXNormal3f32(float nx, float ny, float nz);
void GXColor4u8(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
void GXTexCoord2f32(float s, float t);
void GXLoadPosMtxImm(float mtx[3][4], unsigned int id);
void GXSetCurrentMtx(unsigned int id);
void GXSetNumChans(unsigned char nChans);
void GXSetNumTexGens(unsigned char nTexGens);
void GXSetNumTevStages(unsigned char nStages);
void GXSetTevOrder(GXTevStageID stage, GXTexCoordID coord, GXTexMapID map, GXChannelID color);
void GXSetTevOp(GXTevStageID stage, GXTevMode mode);
void GXSetTevColorIn(GXTevStageID stage, GXTevColorArg a, GXTevColorArg b, GXTevColorArg c, GXTevColorArg d);
void GXSetTevAlphaIn(GXTevStageID stage, GXTevAlphaArg a, GXTevAlphaArg b, GXTevAlphaArg c, GXTevAlphaArg d);
void GXCopyDisp(void* dest, GXBool clear);
void GXDrawDone(void);
void GXInitTexObj(GXTexObj* obj, void* imgPtr, unsigned short wd, unsigned short ht, GXTexFmt fmt, GXTexWrapMode wrapS, GXTexWrapMode wrapT, GXBool mipmap);
void GXLoadTexObj(GXTexObj* obj, GXTexMapID id);
void GXInvalidateTexAll(void);
void GXSetFog(GXFogType type, float startz, float endz, float nearz, float farz, GXColor color);
void GXSetFogRangeAdj(GXBool enable, unsigned short center, void* table);

#ifdef __cplusplus
}
#endif

#endif // SIMS2_PLATFORM_PC

// ============================================================================
// Input abstraction
// ============================================================================

#ifdef SIMS2_PLATFORM_PC

#define PAD_CHAN0        0
#define PAD_CHAN1        1
#define PAD_BUTTON_A    0x0100
#define PAD_BUTTON_B    0x0200
#define PAD_BUTTON_X    0x0400
#define PAD_BUTTON_Y    0x0800
#define PAD_BUTTON_START 0x1000
#define PAD_TRIGGER_L   0x0040
#define PAD_TRIGGER_R   0x0020
#define PAD_BUTTON_UP   0x0008
#define PAD_BUTTON_DOWN 0x0004
#define PAD_BUTTON_LEFT 0x0001
#define PAD_BUTTON_RIGHT 0x0002
#define PAD_TRIGGER_Z   0x0010

typedef struct {
    unsigned short button;
    signed char stickX;
    signed char stickY;
    signed char substickX;
    signed char substickY;
    unsigned char triggerL;
    unsigned char triggerR;
    unsigned char analogA;
    unsigned char analogB;
    signed char err;
} PADStatus;

#ifdef __cplusplus
extern "C" {
#endif

int PADInit(void);
int PADRead(PADStatus* status);
void PADReset(unsigned int mask);
void PADSetAnalogMode(int mode);

#ifdef __cplusplus
}
#endif

#endif // SIMS2_PLATFORM_PC

// ============================================================================
// OS abstraction
// ============================================================================

#ifdef SIMS2_PLATFORM_PC

#ifdef __cplusplus
extern "C" {
#endif

// Timing
unsigned long long OSGetTime(void);
unsigned int OSGetTick(void);
void OSReport(const char* fmt, ...);

// Threading (maps to std::thread on PC)
typedef void* OSThread;
typedef void* OSMutex;
typedef void* OSCond;

int OSCreateThread(OSThread* thread, void* (*func)(void*), void* param,
                   void* stack, unsigned int stackSize, int priority, int detached);
void OSResumeThread(OSThread* thread);
void OSSuspendThread(OSThread* thread);
int OSIsThreadTerminated(OSThread* thread);

void OSInitMutex(OSMutex* mutex);
void OSLockMutex(OSMutex* mutex);
void OSUnlockMutex(OSMutex* mutex);

void OSInitCond(OSCond* cond);
void OSWaitCond(OSCond* cond, OSMutex* mutex);
void OSSignalCond(OSCond* cond);

// Memory
void* OSAllocFromHeap(int heap, unsigned int size);
void OSFreeToHeap(int heap, void* ptr);

// Interrupts (no-ops on PC)
int OSDisableInterrupts(void);
void OSRestoreInterrupts(int level);

#ifdef __cplusplus
}
#endif

#endif // SIMS2_PLATFORM_PC

// ============================================================================
// File I/O abstraction
// ============================================================================

#ifdef SIMS2_PLATFORM_PC

#ifdef __cplusplus
extern "C" {
#endif

// DVD (maps to standard file I/O on PC)
typedef struct {
    void* internal;
} DVDFileInfo;

int DVDOpen(const char* fileName, DVDFileInfo* fileInfo);
void DVDClose(DVDFileInfo* fileInfo);
int DVDReadPrio(DVDFileInfo* fileInfo, void* addr, int length, int offset, int prio);
int DVDGetLength(DVDFileInfo* fileInfo);

// CARD (maps to save files on PC)
int CARDInit(void);
int CARDOpen(int chan, const char* fileName, void* fileInfo);
int CARDClose(void* fileInfo);
int CARDRead(void* fileInfo, void* addr, int length, int offset);
int CARDWrite(void* fileInfo, const void* addr, int length, int offset);

#ifdef __cplusplus
}
#endif

#endif // SIMS2_PLATFORM_PC

// ============================================================================
// Audio abstraction
// ============================================================================

#ifdef SIMS2_PLATFORM_PC

#ifdef __cplusplus
extern "C" {
#endif

void AXInit(void);
void AXQuit(void);
void AXSetMode(int mode);

#ifdef __cplusplus
}
#endif

#endif // SIMS2_PLATFORM_PC

#endif // PLATFORM_H

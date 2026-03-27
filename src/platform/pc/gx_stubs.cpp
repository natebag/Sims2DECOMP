// gx_stubs.cpp — Stub implementations of GX (GameCube graphics) functions for PC
// These will be replaced with OpenGL implementations as the port progresses.

#include "platform/platform.h"

#ifdef SIMS2_PLATFORM_PC

#include <cstdio>

// Stub counter for tracking which GX calls are hit
static int gx_call_count = 0;
#define GX_STUB() do { if (gx_call_count++ < 10) printf("[GX STUB] %s\n", __func__); } while(0)

extern "C" {

void GXInit(void* base, unsigned int size) { GX_STUB(); }
void GXSetViewport(float xOrig, float yOrig, float wd, float ht, float nearZ, float farZ) { GX_STUB(); }
void GXSetScissor(unsigned int xOrig, unsigned int yOrig, unsigned int wd, unsigned int ht) { GX_STUB(); }
void GXSetCullMode(GXCullMode mode) { GX_STUB(); }
void GXSetBlendMode(GXBlendMode type, GXBlendFactor src, GXBlendFactor dst, GXLogicOp op) { GX_STUB(); }
void GXSetZMode(GXBool enable, GXCompare func, GXBool updateEnable) { GX_STUB(); }
void GXSetAlphaCompare(GXCompare comp0, unsigned char ref0, int op, GXCompare comp1, unsigned char ref1) { GX_STUB(); }
void GXSetColorUpdate(GXBool enable) { GX_STUB(); }
void GXSetAlphaUpdate(GXBool enable) { GX_STUB(); }
void GXBegin(GXPrimitive type, GXVtxFmt vtxfmt, unsigned short nverts) { GX_STUB(); }
void GXEnd(void) { }
void GXPosition3f32(float x, float y, float z) { }
void GXNormal3f32(float nx, float ny, float nz) { }
void GXColor4u8(unsigned char r, unsigned char g, unsigned char b, unsigned char a) { }
void GXTexCoord2f32(float s, float t) { }
void GXLoadPosMtxImm(float mtx[3][4], unsigned int id) { GX_STUB(); }
void GXSetCurrentMtx(unsigned int id) { GX_STUB(); }
void GXSetNumChans(unsigned char nChans) { GX_STUB(); }
void GXSetNumTexGens(unsigned char nTexGens) { GX_STUB(); }
void GXSetNumTevStages(unsigned char nStages) { GX_STUB(); }
void GXSetTevOrder(GXTevStageID stage, GXTexCoordID coord, GXTexMapID map, GXChannelID color) { GX_STUB(); }
void GXSetTevOp(GXTevStageID stage, GXTevMode mode) { GX_STUB(); }
void GXSetTevColorIn(GXTevStageID stage, GXTevColorArg a, GXTevColorArg b, GXTevColorArg c, GXTevColorArg d) { GX_STUB(); }
void GXSetTevAlphaIn(GXTevStageID stage, GXTevAlphaArg a, GXTevAlphaArg b, GXTevAlphaArg c, GXTevAlphaArg d) { GX_STUB(); }
void GXCopyDisp(void* dest, GXBool clear) { GX_STUB(); }
void GXDrawDone(void) { GX_STUB(); }
void GXInitTexObj(GXTexObj* obj, void* imgPtr, unsigned short wd, unsigned short ht, GXTexFmt fmt, GXTexWrapMode wrapS, GXTexWrapMode wrapT, GXBool mipmap) { GX_STUB(); }
void GXLoadTexObj(GXTexObj* obj, GXTexMapID id) { GX_STUB(); }
void GXInvalidateTexAll(void) { GX_STUB(); }
void GXSetFog(GXFogType type, float startz, float endz, float nearz, float farz, GXColor color) { GX_STUB(); }
void GXSetFogRangeAdj(GXBool enable, unsigned short center, void* table) { GX_STUB(); }

} // extern "C"

#endif // SIMS2_PLATFORM_PC

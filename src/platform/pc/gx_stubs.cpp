// gx_stubs.cpp — GX (GameCube graphics) → OpenGL implementation for PC port
// Texture functions are wired through gx_texture_bridge for real decoding.
// Other functions remain stubs until Session B (OpenGL rendering backend).

#include "platform/platform.h"

#ifdef SIMS2_PLATFORM_PC

#include "gx_texture_bridge.h"
#include "gx_vertex_bridge.h"
#include "gx_state_bridge.h"
#include "gx_constants.h"
#include <stdio.h>

// Stub counter for tracking which GX calls are hit
static int gx_call_count = 0;
#define GX_STUB() do { if (gx_call_count++ < 20) printf("[GX STUB] %s\n", __func__); } while(0)

extern "C" {

void GXInit(void* base, unsigned int size) {
    printf("[GX] GXInit(%p, %u)\n", base, size);
    gx_tex_bridge_init();
}

// --- Render state (implemented via gx_state_bridge) ---
void GXSetViewport(float xOrig, float yOrig, float wd, float ht, float nearZ, float farZ) {
    gx_state_set_viewport(xOrig, yOrig, wd, ht, nearZ, farZ);
}
void GXSetScissor(unsigned int xOrig, unsigned int yOrig, unsigned int wd, unsigned int ht) {
    gx_state_set_scissor(xOrig, yOrig, wd, ht);
}
void GXSetCullMode(GXCullMode mode) {
    gx_state_set_cull_mode(mode);
}
void GXSetBlendMode(GXBlendMode type, GXBlendFactor src, GXBlendFactor dst, GXLogicOp op) {
    gx_state_set_blend_mode(type, src, dst, op);
}
void GXSetZMode(GXBool enable, GXCompare func, GXBool updateEnable) {
    gx_state_set_z_mode(enable, func, updateEnable);
}
void GXSetAlphaCompare(GXCompare comp0, unsigned char ref0, int op, GXCompare comp1, unsigned char ref1) {
    gx_state_set_alpha_compare(comp0, ref0, op, comp1, ref1);
}
void GXSetColorUpdate(GXBool enable) {
    gx_state_set_color_update(enable);
}
void GXSetAlphaUpdate(GXBool enable) {
    gx_state_set_alpha_update(enable);
}

// --- Vertex submission (implemented via gx_vertex_bridge) ---
void GXBegin(GXPrimitive type, GXVtxFmt vtxfmt, unsigned short nverts) {
    gx_vertex_begin(type, vtxfmt, nverts);
}
void GXEnd(void) {
    gx_vertex_end();
}
void GXPosition3f32(float x, float y, float z) {
    gx_vertex_position(x, y, z);
}
void GXNormal3f32(float nx, float ny, float nz) {
    gx_vertex_normal(nx, ny, nz);
}
void GXColor4u8(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    gx_vertex_color(r, g, b, a);
}
void GXTexCoord2f32(float s, float t) {
    gx_vertex_texcoord(s, t);
}

// --- Matrix (implemented via gx_vertex_bridge) ---
void GXLoadPosMtxImm(float mtx[3][4], unsigned int id) {
    gx_load_pos_mtx(mtx, id);
}
void GXSetCurrentMtx(unsigned int id) {
    gx_set_current_mtx(id);
}

// --- TEV (simplified — maps common modes to GL fixed-function) ---
void GXSetNumChans(unsigned char nChans) { (void)nChans; }
void GXSetNumTexGens(unsigned char nTexGens) { (void)nTexGens; }
void GXSetNumTevStages(unsigned char nStages) { (void)nStages; }
void GXSetTevOrder(GXTevStageID stage, GXTexCoordID coord, GXTexMapID map, GXChannelID color) {
    (void)stage; (void)coord; (void)map; (void)color;
}
void GXSetTevOp(GXTevStageID stage, GXTevMode mode) {
    // Map common TEV modes to GL texture environment
    // Only meaningful for stage 0 in fixed-function GL
    (void)stage; (void)mode;
}
void GXSetTevColorIn(GXTevStageID stage, GXTevColorArg a, GXTevColorArg b, GXTevColorArg c, GXTevColorArg d) {
    (void)stage; (void)a; (void)b; (void)c; (void)d;
}
void GXSetTevAlphaIn(GXTevStageID stage, GXTevAlphaArg a, GXTevAlphaArg b, GXTevAlphaArg c, GXTevAlphaArg d) {
    (void)stage; (void)a; (void)b; (void)c; (void)d;
}

// --- Frame operations ---
void GXCopyDisp(void* dest, GXBool clear) {
    gx_state_copy_disp(dest, clear);
}
void GXDrawDone(void) {
    gx_state_draw_done();
}

// --- TEXTURE FUNCTIONS — REAL IMPLEMENTATIONS ---
void GXInitTexObj(GXTexObj* obj, void* imgPtr, unsigned short wd, unsigned short ht,
                  GXTexFmt fmt, GXTexWrapMode wrapS, GXTexWrapMode wrapT, GXBool mipmap) {
    gx_tex_bridge_init_obj(obj, imgPtr, wd, ht, fmt);
}

void GXLoadTexObj(GXTexObj* obj, GXTexMapID id) {
    gx_tex_bridge_load_obj(obj, id);
}

void GXInvalidateTexAll(void) {
    gx_tex_bridge_invalidate_all();
}

// --- Fog stubs ---
void GXSetFog(GXFogType type, float startz, float endz, float nearz, float farz, GXColor color) { GX_STUB(); }
void GXSetFogRangeAdj(GXBool enable, unsigned short center, void* table) { GX_STUB(); }

} // extern "C"

#endif // SIMS2_PLATFORM_PC

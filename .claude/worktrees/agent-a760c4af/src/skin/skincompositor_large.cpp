// skincompositor_large.cpp - SkinCompositor large functions (257-1024 bytes)
// Object file: skincompositor.obj
// All NON_MATCHING due to: GCC vs SN Systems codegen differences

#include "skin/skincompositor.h"

// Forward declarations
extern "C" void* EAHeap_Alloc(int size);
extern "C" void EAHeap_Free2(void* ptr);
extern "C" void* ERTexture_Create(int width, int height, int format, int flags);
extern "C" void ERTexture_Lock(void* tex, void** data, int* pitch);
extern "C" void ERTexture_Unlock(void* tex);
extern "C" void GXInvalidateTexAll();
extern "C" void DCFlushRange(void* addr, u32 len);

// ============================================================================
// SkinCompositor::CreateSkinQuadrantPrecomposited(ERTexture*, unsigned int, bool)
// Address: 0x80075CC8
// Size: 292 bytes
// NON_MATCHING - creates a precomposited skin quadrant texture
// ============================================================================
void SkinCompositor::CreateSkinQuadrantPrecomposited(ERTexture* tex, unsigned int quadrant, bool flag)
{
    u8* self = (u8*)this;

    if (!tex) return;

    // Get texture data pointer
    void* texData = *(void**)((u8*)tex + 0x10);
    if (!texData) return;

    u16 size = m_size;
    u32 quadSize = size / 2;

    // Calculate quadrant offset
    u32 xOff = (quadrant & 1) * quadSize;
    u32 yOff = (quadrant >> 1) * quadSize;

    // Get scratchpad texture
    void* scratch = m_ptr04;
    if (!scratch) return;

    // Copy quadrant from scratch to output texture
    void* scratchData = *(void**)((u8*)scratch + 0x10);
    if (!scratchData) return;

    u32 srcPitch = size * 4;
    u32 dstPitch = quadSize * 4;

    for (u32 y = 0; y < quadSize; y++) {
        u8* srcRow = (u8*)scratchData + (yOff + y) * srcPitch + xOff * 4;
        u8* dstRow = (u8*)texData + y * dstPitch;
        for (u32 x = 0; x < dstPitch; x++) {
            dstRow[x] = srcRow[x];
        }
    }

    // Flush data cache for GX
    DCFlushRange(texData, quadSize * quadSize * 4);
    GXInvalidateTexAll();
}

// ============================================================================
// SkinCompositor::InitScratchpadTextures(unsigned short)
// Address: 0x80075E8C
// Size: 372 bytes
// NON_MATCHING - initializes scratchpad textures for compositing
// ============================================================================
void SkinCompositor::InitScratchpadTextures(unsigned short size)
{
    u8* self = (u8*)this;

    m_size = size;

    // Create main scratchpad texture (RGBA8)
    void* scratch0 = ERTexture_Create(size, size, 6, 0); // GX_TF_RGBA8
    m_ptr04 = scratch0;

    // Create secondary scratchpad for blending
    void* scratch1 = ERTexture_Create(size, size, 6, 0);
    m_ptr08 = scratch1;

    // Create mask texture (I4 or I8)
    void* mask = ERTexture_Create(size, size, 0, 0); // GX_TF_I4
    m_ptr0C = mask;

    // Create reflection mask texture
    void* reflMask = ERTexture_Create(size, size, 0, 0);
    m_ptr10 = reflMask;

    // Allocate temporary buffers for compositing operations
    u32 bufSize = size * size * 4;
    void* tmpBuf0 = EAHeap_Alloc(bufSize);
    m_ptr14 = tmpBuf0;

    void* tmpBuf1 = EAHeap_Alloc(bufSize);
    m_ptr18 = tmpBuf1;

    m_byte1C = 0;
    m_ptr20 = 0;
    m_ptr24 = 0;
}

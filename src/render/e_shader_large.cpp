// e_shader_large.cpp - EShader large functions (257-1024 bytes)
// Part of the Sims 2 GC decompilation
// Original: engine_ngc_release_dvd.lib(e_shader.obj)

#include "types.h"

// Forward declarations
class EShader;
class ERC;
class ETexture;
struct EVec2 { float x, y; };
struct EVec4 { float x, y, z, w; };
struct EShaderDef;

extern void* PoolAlloc(void* pool, u32 size);
extern void PoolFree(void* pool, void* ptr);

// ============================================================================
// EShader::EShader(void)
// Address: 0x802F9BA8
// Size: 448 bytes
// NON_MATCHING - complex constructor initializing many fields
// ============================================================================
EShader::EShader(void)
{
    // Set vtable
    *(u32*)((u8*)this + 0xF0) = 0x8046AD20; // NON_MATCHING: link-time address

    // Initialize base transform (identity-like)
    float zero = 0.0f;
    float one = 1.0f;

    // Copy default position/rotation from float constants
    *(float*)((u8*)this + 0x30) = zero;
    *(float*)((u8*)this + 0x34) = zero;
    *(float*)((u8*)this + 0x38) = zero;

    // Copy to position fields
    *(float*)((u8*)this + 0x10) = *(float*)((u8*)this + 0x30);
    *(float*)((u8*)this + 0x14) = *(float*)((u8*)this + 0x34);
    *(float*)((u8*)this + 0x18) = *(float*)((u8*)this + 0x38);
    *(float*)((u8*)this + 0x1C) = *(float*)((u8*)this + 0x30);
    *(float*)((u8*)this + 0x20) = *(float*)((u8*)this + 0x34);
    *(float*)((u8*)this + 0x24) = *(float*)((u8*)this + 0x38);
    *(float*)((u8*)this + 0x28) = *(float*)((u8*)this + 0x30);
    *(float*)((u8*)this + 0x2C) = *(float*)((u8*)this + 0x34);

    // Initialize texture state
    *(u32*)((u8*)this + 0x64) = 0;  // m_pTexture[0]
    *(u32*)((u8*)this + 0x68) = 0;  // m_pTexture[1]
    *(u32*)((u8*)this + 0x6C) = 0;  // m_pTexture[2]
    *(u32*)((u8*)this + 0x70) = 8;  // blend mode
    *(u32*)((u8*)this + 0x74) = 24; // other mode

    // Initialize blend/color state
    *(u8*)((u8*)this + 0x80) = 0;
    *(u8*)((u8*)this + 0x81) = 1;
    *(u8*)((u8*)this + 0x82) = 0;
    *(u8*)((u8*)this + 0x83) = 1;
    *(u8*)((u8*)this + 0x84) = 255;
    *(u8*)((u8*)this + 0x85) = 0;
    *(u8*)((u8*)this + 0x86) = 0;
    *(u8*)((u8*)this + 0x87) = 0;

    // More texture/state initialization
    *(u32*)((u8*)this + 0x88) = 0;
    *(u32*)((u8*)this + 0x8C) = 0;
    *(u32*)((u8*)this + 0x90) = 0;
    *(float*)((u8*)this + 0x94) = one;
    *(float*)((u8*)this + 0x98) = zero;
    *(u32*)((u8*)this + 0x04) = 0;
    *(u32*)((u8*)this + 0x08) = 0;
    *(u32*)((u8*)this + 0x0C) = 0;

    // Default scroll speeds
    *(float*)((u8*)this + 0x9C) = zero;
    *(float*)((u8*)this + 0xA0) = zero;

    // Initialize color
    *(u32*)((u8*)this + 0x8C) = 0x000000FF;

    *(u32*)((u8*)this + 0x00) = 0;
    *(u32*)((u8*)this + 0xCC) = 0;
    *(u32*)((u8*)this + 0x98) = 0;
    *(u32*)((u8*)this + 0x90) = 0;
    *(u32*)((u8*)this + 0x324) = 0;

    // Sentinel values
    *(s32*)((u8*)this + 0x2C) = -1;
    *(s32*)((u8*)this + 0x1C) = -1;
    *(s32*)((u8*)this + 0x18) = -1;
    *(s32*)((u8*)this + 0x28) = -1;
    *(s32*)((u8*)this + 0x14) = 0;

    // Call SetDisplayRect and other init methods
    // NON_MATCHING: branch targets
}

// ============================================================================
// EShader::AddToUpdateList(void)
// Address: 0x802F9E88
// Size: 288 bytes
// NON_MATCHING
// ============================================================================
void EShader::AddToUpdateList(void)
{
    // Check if already in list
    u32 flags = *(u32*)((u8*)this + 0x04);
    if (flags & 0x00100000) return;

    // Set in-list flag
    *(u32*)((u8*)this + 0x04) = flags | 0x00100000;

    // Add to global linked list
    // NON_MATCHING: global list head address
}

// ============================================================================
// EShader::Update(float)
// Address: 0x802FA130
// Size: 608 bytes
// NON_MATCHING - complex update with scroll, UV animation
// ============================================================================
void EShader::Update(float dt)
{
    u32 flags = *(u32*)((u8*)this + 0x04);

    // Update scroll offsets
    if (flags & 0x00010000) {
        float scrollU = *(float*)((u8*)this + 0x9C);
        float scrollV = *(float*)((u8*)this + 0xA0);

        *(float*)((u8*)this + 0xA4) += scrollU * dt;
        *(float*)((u8*)this + 0xA8) += scrollV * dt;
    }

    // Update UV animation frames
    if (flags & 0x00020000) {
        float frameTime = *(float*)((u8*)this + 0xB0);
        float elapsed = *(float*)((u8*)this + 0xB4);
        elapsed += dt;

        if (elapsed >= frameTime) {
            elapsed -= frameTime;
            u32 frame = *(u32*)((u8*)this + 0xB8);
            u32 maxFrame = *(u32*)((u8*)this + 0xBC);
            frame++;
            if (frame >= maxFrame) frame = 0;
            *(u32*)((u8*)this + 0xB8) = frame;
        }

        *(float*)((u8*)this + 0xB4) = elapsed;
    }

    // Update texture blend
    if (flags & 0x00040000) {
        float blendRate = *(float*)((u8*)this + 0xC0);
        float blend = *(float*)((u8*)this + 0xC4);
        blend += blendRate * dt;
        if (blend > 1.0f) blend = 1.0f;
        if (blend < 0.0f) blend = 0.0f;
        *(float*)((u8*)this + 0xC4) = blend;
    }
}

// ============================================================================
// EShader::SetTransform(ERC*)
// Address: 0x802FA648
// Size: 596 bytes
// NON_MATCHING - sets up texture coordinate transform matrix
// ============================================================================
void EShader::SetTransform(ERC* rc)
{
    u32 flags = *(u32*)((u8*)this + 0x04);

    // Build texture transform matrix from scroll/scale/rotation
    float scrollU = *(float*)((u8*)this + 0xA4);
    float scrollV = *(float*)((u8*)this + 0xA8);
    float scaleU = *(float*)((u8*)this + 0xAC);
    float scaleV = *(float*)((u8*)this + 0xB0);

    // Construct 4x4 texture matrix
    float mat[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            mat[i][j] = (i == j) ? 1.0f : 0.0f;

    mat[0][0] = scaleU;
    mat[1][1] = scaleV;
    mat[3][0] = scrollU;
    mat[3][1] = scrollV;

    // Apply rotation if needed
    if (flags & 0x00080000) {
        float angle = *(float*)((u8*)this + 0xC8);
        // NON_MATCHING: sin/cos rotation applied
    }

    // Set on RC through vtable dispatch
    // NON_MATCHING: vtable call to rc->TextureMatrix
}

// ============================================================================
// EShader::SetScrollSpeed(EVec2&, int, bool)
// Address: 0x802FA89C
// Size: 272 bytes
// NON_MATCHING
// ============================================================================
void EShader::SetScrollSpeed(EVec2& speed, int layer, bool addToUpdateList)
{
    u32 flags = *(u32*)((u8*)this + 0x04);
    flags |= 0x00010000;  // Enable scroll
    *(u32*)((u8*)this + 0x04) = flags;

    *(float*)((u8*)this + 0x9C) = speed.x;
    *(float*)((u8*)this + 0xA0) = speed.y;

    if (addToUpdateList) {
        // Call AddToUpdateList
        // NON_MATCHING: branch target
    }
}

// ============================================================================
// EShaderDef::operator=(EShaderDef&)
// Address: 0x803C360C
// Size: 368 bytes
// NON_MATCHING - member-by-member copy of shader definition
// ============================================================================
void EShaderDef_CopyAssign(void* dst, void* src)
{
    // Copy all shader definition fields
    // Texture paths, blend modes, color values, flags
    // NON_MATCHING: field layout
    for (int i = 0; i < 92; i++) {
        ((u32*)dst)[i] = ((u32*)src)[i];
    }
}

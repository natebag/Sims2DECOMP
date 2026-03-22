// e_graphics_large.cpp - EGraphics large functions (257-1024 bytes)
// Part of the Sims 2 GC decompilation
// Original: engine_ngc_release_dvd.lib(e_graphics.obj)

#include "types.h"

// Forward declarations
class EGraphics;
class ERC;
struct EVec2 { float x, y; };
struct EVec4 { float x, y, z, w; };

// ============================================================================
// EGraphics::EGraphics(void)
// Address: 0x802F0D9C
// Size: 408 bytes
// NON_MATCHING - constructor with many field initializations from constants
// ============================================================================
void EGraphics_Ctor(void* self)
{
    u8* p = (u8*)self;

    // Set vtable
    *(u32*)(p + 0xF0) = 0x8046A808; // NON_MATCHING: link-time vtable address

    float zero = 0.0f;
    float one = 1.0f;

    // Initialize position/bounds
    *(float*)(p + 0x30) = zero;
    *(float*)(p + 0x34) = zero;
    *(float*)(p + 0x38) = zero;

    // Copy position to secondary fields
    *(float*)(p + 0x10) = *(float*)(p + 0x30);
    *(float*)(p + 0x14) = *(float*)(p + 0x34);
    *(float*)(p + 0x18) = *(float*)(p + 0x38);

    *(u32*)(p + 0x04) = 0;
    *(u32*)(p + 0x08) = 0;
    *(u32*)(p + 0x80) = 0;

    // Initialize timing/FPS fields
    *(float*)(p + 0x08) = one;
    *(u32*)(p + 0x10) = 1;
    *(u32*)(p + 0x0C) = 1;
    *(u32*)(p + 0x8C) = 0x000000FF;

    *(u32*)(p + 0x31C) = 0;
    *(u32*)(p + 0x24) = 0;
    *(u32*)(p + 0x20) = 0;
    *(u32*)(p + 0x38) = 0;
    *(u32*)(p + 0x34) = 0;
    *(u32*)(p + 0x3C) = 0;
    *(u32*)(p + 0x30) = 0;
    *(u32*)(p + 0x2CC) = 0;
    *(u32*)(p + 0x98) = 0;
    *(u32*)(p + 0x90) = 0;
    *(u32*)(p + 0x324) = 0;
    *(u32*)(p + 0x14) = 0;

    *(s32*)(p + 0x2C) = -1;
    *(s32*)(p + 0x1C) = -1;
    *(s32*)(p + 0x18) = -1;
    *(s32*)(p + 0x28) = -1;

    // Call init methods
    // NON_MATCHING: branch targets for SetDisplayRect, SetViewport, SetViewWindow

    *(u32*)(p + 0x320) = 1;
}

// ============================================================================
// EGraphics::DrawTiming(void)
// Address: 0x802F1C34
// Size: 612 bytes
// NON_MATCHING - draws FPS/timing overlay text
// ============================================================================
void EGraphics_DrawTiming(void* self)
{
    u8* p = (u8*)self;

    // Check if timing display enabled
    u32 flags = *(u32*)(p + 0x04);
    if (!(flags & 0x01)) return;

    // Get RC
    void* rc = *(void**)(p + 0x00);
    if (!rc) return;

    // Calculate FPS
    float frameTime = *(float*)(p + 0x08);
    float fps = 0.0f;
    if (frameTime > 0.0f) {
        fps = 1.0f / frameTime;
    }

    // Draw timing bars and text
    // NON_MATCHING: complex drawing with rect calls, text formatting
    // Uses multiple ERC::Rect calls to draw colored bars
    // Text drawn via font system

    // Draw frame time bar (green/red based on target)
    float barWidth = frameTime * 60.0f * 100.0f;
    if (barWidth > 200.0f) barWidth = 200.0f;

    // NON_MATCHING: ERC vtable calls for drawing
}

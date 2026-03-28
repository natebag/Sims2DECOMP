#if 0 // SKIP
// e_rc_large.cpp - ERC class large functions (257-1024 bytes)
// Part of the Sims 2 GC decompilation
// Original: engine_ngc_release_dvd.lib(e_rc.obj)

#include "types.h"
#include "stub_classes.h"

// Forward declarations
class ERC;
class EDLEntry;
class ETexture;
struct EVec2 { float x, y; };
struct EVec3 { float x, y, z; };
struct EVec4 { float x, y, z, w; };
struct EMat4 { float m[4][4]; };
struct EGEVert;
enum ETCTransformSource {};

// External functions
extern void* DLAlloc(void* dl, u32 size);
extern void* DLCopy(void* dl, void* data, u32 size);

// ============================================================================
// ERC::TriStrip(int, float*, float*, unsigned char*, signed char*, unsigned char*, bool)
// Address: 0x802F68EC
// Size: 320 bytes
// NON_MATCHING - DL allocation and vtable dispatches
// ============================================================================
void ERC::TriStrip(int count, float* verts, float* texCoords,
    unsigned char* colors, signed char* normals, unsigned char* flags, bool strip)
{
    if (count == 0) return;

    // Copy vertex data into display list
    void* dl = *(void**)((u8*)this + 0x00);
    float* dlVerts = (float*)DLCopy(this, verts, count * 16);

    int stride = (strip == false) ? 2 : 4;
    u32 copySize = stride * (count * 4);

    float* dlTexCoords = (float*)DLCopy(this, texCoords, copySize);
    unsigned char* dlColors = (unsigned char*)DLCopy(this, normals, count * 4);
    signed char* dlNormals = (signed char*)DLCopy(this, colors, count * 4);
    unsigned char* dlFlags = (unsigned char*)DLCopy(this, flags, count * 4);

    // Dispatch through vtable - begin primitive
    void** vtable = *(void***)((u8*)this + 0x70);
    {
        s16 thunkOff = *(s16*)((u8*)vtable + 0x2B0);
        void* fn = *(void**)((u8*)vtable + 0x2B4);
        void* thisPtr = (void*)((u8*)this + thunkOff);
        typedef void (*Fn)(void*, int, int);
        ((Fn)fn)(thisPtr, 2, 1);
    }

    // Update primitive count
    void* dlPtr = *(void**)((u8*)this + 0x00);
    u32 primCount = *(u32*)((u8*)dlPtr + 0x54);
    *(u32*)((u8*)dlPtr + 0x54) = primCount + count;

    // Dispatch through vtable - alloc DL entry
    {
        s16 thunkOff = *(s16*)((u8*)vtable + 0x2A8);
        void* fn = *(void**)((u8*)vtable + 0x2AC);
        void* thisPtr = (void*)((u8*)this + thunkOff);
        typedef void* (*Fn)(void*, int);
        EDLEntry* entry = (EDLEntry*)((Fn)fn)(thisPtr, 4);

        // Fill DL entry
        *(u8*)entry = 0x2A;  // TriStrip command
        *(u32*)((u8*)entry + 0x04) = count;
        *(u32*)((u8*)entry + 0x08) = (u32)dlVerts;
        *(u32*)((u8*)entry + 0x0C) = (u32)dlTexCoords;
        *(u32*)((u8*)entry + 0x10) = (u32)dlNormals;
        *(u32*)((u8*)entry + 0x14) = (u32)dlColors;
        *(u32*)((u8*)entry + 0x18) = (u32)dlFlags;
    }

    // End primitive dispatch
    {
        s16 thunkOff = *(s16*)((u8*)vtable + 0x2B8);
        void* fn = *(void**)((u8*)vtable + 0x2BC);
        void* thisPtr = (void*)((u8*)this + thunkOff);
        typedef void (*Fn)(void*);
        ((Fn)fn)(thisPtr);
    }
}

// ============================================================================
// ERC::TriStrip(int, short*, short*, unsigned char*, signed char*, unsigned char*, bool)
// Address: 0x802F6A60
// Size: 332 bytes
// NON_MATCHING - same pattern as float version but with short data
// ============================================================================
void ERC::TriStrip(int count, short* verts, short* texCoords,
    unsigned char* colors, signed char* normals, unsigned char* flags, bool strip)
{
    if (count == 0) return;

    void* dlVerts = DLCopy(this, verts, count * 8);

    int stride = (strip == false) ? 2 : 4;
    u32 copySize = stride * (count * 2);

    short* dlTexCoords = (short*)DLCopy(this, texCoords, copySize);
    unsigned char* dlColors = (unsigned char*)DLCopy(this, normals, count * 4);
    signed char* dlNormals = (signed char*)DLCopy(this, colors, count * 4);
    unsigned char* dlFlags = (unsigned char*)DLCopy(this, flags, count * 4);

    void** vtable = *(void***)((u8*)this + 0x70);
    {
        s16 thunkOff = *(s16*)((u8*)vtable + 0x2B0);
        void* fn = *(void**)((u8*)vtable + 0x2B4);
        void* thisPtr = (void*)((u8*)this + thunkOff);
        typedef void (*Fn)(void*, int, int);
        ((Fn)fn)(thisPtr, 2, 1);
    }

    void* dlPtr = *(void**)((u8*)this + 0x00);
    u32 primCount = *(u32*)((u8*)dlPtr + 0x54);
    *(u32*)((u8*)dlPtr + 0x54) = primCount + count;

    {
        s16 thunkOff = *(s16*)((u8*)vtable + 0x2A8);
        void* fn = *(void**)((u8*)vtable + 0x2AC);
        void* thisPtr = (void*)((u8*)this + thunkOff);
        typedef void* (*Fn)(void*, int);
        EDLEntry* entry = (EDLEntry*)((Fn)fn)(thisPtr, 4);

        *(u8*)entry = 0x2B;
        *(u32*)((u8*)entry + 0x04) = count;
        *(u32*)((u8*)entry + 0x08) = (u32)dlVerts;
        *(u32*)((u8*)entry + 0x0C) = (u32)dlTexCoords;
        *(u32*)((u8*)entry + 0x10) = (u32)dlNormals;
        *(u32*)((u8*)entry + 0x14) = (u32)dlColors;
        *(u32*)((u8*)entry + 0x18) = (u32)dlFlags;
    }

    {
        s16 thunkOff = *(s16*)((u8*)vtable + 0x2B8);
        void* fn = *(void**)((u8*)vtable + 0x2BC);
        void* thisPtr = (void*)((u8*)this + thunkOff);
        typedef void (*Fn)(void*);
        ((Fn)fn)(thisPtr);
    }
}

// ============================================================================
// ERC::PointList(int, float*, float*, unsigned char*, signed char*, unsigned char*)
// Address: 0x802F6D5C
// Size: 300 bytes
// NON_MATCHING - DL allocation pattern
// ============================================================================
void ERC::PointList(int count, float* verts, float* texCoords,
    unsigned char* colors, signed char* normals, unsigned char* flags)
{
    if (count == 0) return;

    float* dlVerts = (float*)DLCopy(this, verts, count * 16);
    float* dlTexCoords = (float*)DLCopy(this, texCoords, count * 8);
    unsigned char* dlColors = (unsigned char*)DLCopy(this, colors, count * 4);
    signed char* dlNormals = (signed char*)DLCopy(this, normals, count * 4);
    unsigned char* dlFlags = (unsigned char*)DLCopy(this, flags, count * 4);

    void** vtable = *(void***)((u8*)this + 0x70);
    {
        s16 thunkOff = *(s16*)((u8*)vtable + 0x2B0);
        void* fn = *(void**)((u8*)vtable + 0x2B4);
        void* thisPtr = (void*)((u8*)this + thunkOff);
        typedef void (*Fn)(void*, int, int);
        ((Fn)fn)(thisPtr, 2, 1);
    }

    void* dlPtr = *(void**)((u8*)this + 0x00);
    u32 primCount = *(u32*)((u8*)dlPtr + 0x54);
    *(u32*)((u8*)dlPtr + 0x54) = primCount + count;

    {
        s16 thunkOff = *(s16*)((u8*)vtable + 0x2A8);
        void* fn = *(void**)((u8*)vtable + 0x2AC);
        void* thisPtr = (void*)((u8*)this + thunkOff);
        typedef void* (*Fn)(void*, int);
        EDLEntry* entry = (EDLEntry*)((Fn)fn)(thisPtr, 4);

        *(u8*)entry = 0x2E;
        *(u32*)((u8*)entry + 0x04) = count;
        *(u32*)((u8*)entry + 0x08) = (u32)dlVerts;
        *(u32*)((u8*)entry + 0x0C) = (u32)dlTexCoords;
        *(u32*)((u8*)entry + 0x10) = (u32)dlNormals;
        *(u32*)((u8*)entry + 0x14) = (u32)dlColors;
        *(u32*)((u8*)entry + 0x18) = (u32)dlFlags;
    }

    {
        s16 thunkOff = *(s16*)((u8*)vtable + 0x2B8);
        void* fn = *(void**)((u8*)vtable + 0x2BC);
        void* thisPtr = (void*)((u8*)this + thunkOff);
        typedef void (*Fn)(void*);
        ((Fn)fn)(thisPtr);
    }
}

// ============================================================================
// ERC::SpriteList(int, float*, float*, unsigned char*, signed char*, unsigned char*)
// Address: 0x802F6F3C
// Size: 300 bytes
// NON_MATCHING
// ============================================================================
void ERC::SpriteList(int count, float* verts, float* texCoords,
    unsigned char* colors, signed char* normals, unsigned char* flags)
{
    if (count == 0) return;

    float* dlVerts = (float*)DLCopy(this, verts, count * 16);
    float* dlTexCoords = (float*)DLCopy(this, texCoords, count * 8);
    unsigned char* dlColors = (unsigned char*)DLCopy(this, colors, count * 4);
    signed char* dlNormals = (signed char*)DLCopy(this, normals, count * 4);
    unsigned char* dlFlags = (unsigned char*)DLCopy(this, flags, count * 4);

    void** vtable = *(void***)((u8*)this + 0x70);
    {
        s16 thunkOff = *(s16*)((u8*)vtable + 0x2B0);
        void* fn = *(void**)((u8*)vtable + 0x2B4);
        void* thisPtr = (void*)((u8*)this + thunkOff);
        typedef void (*Fn)(void*, int, int);
        ((Fn)fn)(thisPtr, 2, 1);
    }

    void* dlPtr = *(void**)((u8*)this + 0x00);
    u32 primCount = *(u32*)((u8*)dlPtr + 0x54);
    *(u32*)((u8*)dlPtr + 0x54) = primCount + count;

    {
        s16 thunkOff = *(s16*)((u8*)vtable + 0x2A8);
        void* fn = *(void**)((u8*)vtable + 0x2AC);
        void* thisPtr = (void*)((u8*)this + thunkOff);
        typedef void* (*Fn)(void*, int);
        EDLEntry* entry = (EDLEntry*)((Fn)fn)(thisPtr, 4);

        *(u8*)entry = 0x30;
        *(u32*)((u8*)entry + 0x04) = count;
        *(u32*)((u8*)entry + 0x08) = (u32)dlVerts;
        *(u32*)((u8*)entry + 0x0C) = (u32)dlTexCoords;
        *(u32*)((u8*)entry + 0x10) = (u32)dlNormals;
        *(u32*)((u8*)entry + 0x14) = (u32)dlColors;
        *(u32*)((u8*)entry + 0x18) = (u32)dlFlags;
    }

    {
        s16 thunkOff = *(s16*)((u8*)vtable + 0x2B8);
        void* fn = *(void**)((u8*)vtable + 0x2BC);
        void* thisPtr = (void*)((u8*)this + thunkOff);
        typedef void (*Fn)(void*);
        ((Fn)fn)(thisPtr);
    }
}

// ============================================================================
// ERC::FlushQueuedMatrices
// Address: 0x802F793C
// Size: 264 bytes
// NON_MATCHING
// ============================================================================
void ERC::FlushQueuedMatrices(void)
{
    void* dlPtr = *(void**)((u8*)this + 0x00);
    u32 matCount = *(u32*)((u8*)dlPtr + 0x58);
    if (matCount == 0) return;

    void** vtable = *(void***)((u8*)this + 0x70);
    s16 thunkOff = *(s16*)((u8*)vtable + 0x2A8);
    void* fn = *(void**)((u8*)vtable + 0x2AC);
    void* thisPtr = (void*)((u8*)this + thunkOff);
    typedef void* (*Fn)(void*, int);
    EDLEntry* entry = (EDLEntry*)((Fn)fn)(thisPtr, 4);

    *(u8*)entry = 0x06;
    *(u32*)((u8*)entry + 0x04) = matCount;

    // Copy queued matrix indices
    void* matData = (void*)((u8*)dlPtr + 0x60);
    void* dlMatData = DLCopy(this, matData, matCount * 8);
    *(u32*)((u8*)entry + 0x08) = (u32)dlMatData;

    *(u32*)((u8*)dlPtr + 0x58) = 0;
}

// ============================================================================
// ERC::Rect(EVec2&, EVec2&, EVec2&, EVec2&, EVec4&, float)
// Address: 0x802F8594
// Size: 264 bytes
// NON_MATCHING - DL entry construction
// ============================================================================
void ERC::Rect(EVec2& pos, EVec2& size, EVec2& uv0, EVec2& uv1, EVec4& color, float depth)
{
    void** vtable = *(void***)((u8*)this + 0x70);
    s16 thunkOff = *(s16*)((u8*)vtable + 0x2A8);
    void* fn = *(void**)((u8*)vtable + 0x2AC);
    void* thisPtr = (void*)((u8*)this + thunkOff);
    typedef void* (*Fn)(void*, int);
    EDLEntry* entry = (EDLEntry*)((Fn)fn)(thisPtr, 4);

    *(u8*)entry = 0x08;
    *(float*)((u8*)entry + 0x04) = pos.x;
    *(float*)((u8*)entry + 0x08) = pos.y;
    *(float*)((u8*)entry + 0x0C) = size.x;
    *(float*)((u8*)entry + 0x10) = size.y;
    *(float*)((u8*)entry + 0x14) = uv0.x;
    *(float*)((u8*)entry + 0x18) = uv0.y;
    *(float*)((u8*)entry + 0x1C) = uv1.x;
    *(float*)((u8*)entry + 0x20) = uv1.y;
    *(float*)((u8*)entry + 0x24) = color.x;
    *(float*)((u8*)entry + 0x28) = color.y;
    *(float*)((u8*)entry + 0x2C) = color.z;
    *(float*)((u8*)entry + 0x30) = color.w;
    *(float*)((u8*)entry + 0x34) = depth;
}

// ============================================================================
// ERC::Rect(EVec2&, EVec2&, EVec4*, EVec2&, EVec2&, float)
// Address: 0x802F869C
// Size: 264 bytes
// NON_MATCHING
// ============================================================================
void ERC::Rect(EVec2& pos, EVec2& size, EVec4* colors, EVec2& uv0, EVec2& uv1, float depth)
{
    void** vtable = *(void***)((u8*)this + 0x70);
    s16 thunkOff = *(s16*)((u8*)vtable + 0x2A8);
    void* fn = *(void**)((u8*)vtable + 0x2AC);
    void* thisPtr = (void*)((u8*)this + thunkOff);
    typedef void* (*Fn)(void*, int);
    EDLEntry* entry = (EDLEntry*)((Fn)fn)(thisPtr, 4);

    *(u8*)entry = 0x09;
    *(float*)((u8*)entry + 0x04) = pos.x;
    *(float*)((u8*)entry + 0x08) = pos.y;
    *(float*)((u8*)entry + 0x0C) = size.x;
    *(float*)((u8*)entry + 0x10) = size.y;

    // Copy 4 vertex colors
    for (int i = 0; i < 4; i++) {
        *(float*)((u8*)entry + 0x14 + i * 16 + 0) = colors[i].x;
        *(float*)((u8*)entry + 0x14 + i * 16 + 4) = colors[i].y;
        *(float*)((u8*)entry + 0x14 + i * 16 + 8) = colors[i].z;
        *(float*)((u8*)entry + 0x14 + i * 16 + 12) = colors[i].w;
    }

    *(float*)((u8*)entry + 0x54) = uv0.x;
    *(float*)((u8*)entry + 0x58) = uv0.y;
    *(float*)((u8*)entry + 0x5C) = uv1.x;
    *(float*)((u8*)entry + 0x60) = uv1.y;
    *(float*)((u8*)entry + 0x64) = depth;
}

// ============================================================================
// ERC::TextureMatrix(EMat4*, ETCTransformSource, bool, bool, int)
// Address: 0x802F8918
// Size: 280 bytes
// NON_MATCHING
// ============================================================================
void ERC::TextureMatrix(EMat4* mat, ETCTransformSource src, bool enable, bool identity, int stage)
{
    void** vtable = *(void***)((u8*)this + 0x70);
    s16 thunkOff = *(s16*)((u8*)vtable + 0x2A8);
    void* fn = *(void**)((u8*)vtable + 0x2AC);
    void* thisPtr = (void*)((u8*)this + thunkOff);
    typedef void* (*Fn)(void*, int);
    EDLEntry* entry = (EDLEntry*)((Fn)fn)(thisPtr, 4);

    *(u8*)entry = 0x18;
    *(u32*)((u8*)entry + 0x04) = (u32)src;
    *(u8*)((u8*)entry + 0x08) = enable ? 1 : 0;
    *(u8*)((u8*)entry + 0x09) = identity ? 1 : 0;
    *(u32*)((u8*)entry + 0x0C) = stage;

    if (mat) {
        // Copy matrix into DL
        void* dlMat = DLCopy(this, mat, 64);
        *(u32*)((u8*)entry + 0x10) = (u32)dlMat;
    } else {
        *(u32*)((u8*)entry + 0x10) = 0;
    }
}

// ============================================================================
// ERC::ZClear(float, float, float, float, float)
// Address: 0x802F9268
// Size: 556 bytes
// NON_MATCHING - complex clear with viewport setup
// ============================================================================
void ERC::ZClear(float x, float y, float w, float h, float depth)
{
    void** vtable = *(void***)((u8*)this + 0x70);

    // Begin primitive
    {
        s16 thunkOff = *(s16*)((u8*)vtable + 0x2B0);
        void* fn = *(void**)((u8*)vtable + 0x2B4);
        void* thisPtr = (void*)((u8*)this + thunkOff);
        typedef void (*Fn)(void*, int, int);
        ((Fn)fn)(thisPtr, 2, 1);
    }

    // Alloc DL entry
    {
        s16 thunkOff = *(s16*)((u8*)vtable + 0x2A8);
        void* fn = *(void**)((u8*)vtable + 0x2AC);
        void* thisPtr = (void*)((u8*)this + thunkOff);
        typedef void* (*Fn)(void*, int);
        EDLEntry* entry = (EDLEntry*)((Fn)fn)(thisPtr, 4);

        *(u8*)entry = 0x0A;
        *(float*)((u8*)entry + 0x04) = x;
        *(float*)((u8*)entry + 0x08) = y;
        *(float*)((u8*)entry + 0x0C) = w;
        *(float*)((u8*)entry + 0x10) = h;
        *(float*)((u8*)entry + 0x14) = depth;
    }

    // End primitive
    {
        s16 thunkOff = *(s16*)((u8*)vtable + 0x2B8);
        void* fn = *(void**)((u8*)vtable + 0x2BC);
        void* thisPtr = (void*)((u8*)this + thunkOff);
        typedef void (*Fn)(void*);
        ((Fn)fn)(thisPtr);
    }
}

// ============================================================================
// ERC::StencilClear(float, float, float, float, int)
// Address: 0x802F9494
// Size: 480 bytes
// NON_MATCHING
// ============================================================================
void ERC::StencilClear(float x, float y, float w, float h, int value)
{
    void** vtable = *(void***)((u8*)this + 0x70);

    {
        s16 thunkOff = *(s16*)((u8*)vtable + 0x2B0);
        void* fn = *(void**)((u8*)vtable + 0x2B4);
        void* thisPtr = (void*)((u8*)this + thunkOff);
        typedef void (*Fn)(void*, int, int);
        ((Fn)fn)(thisPtr, 2, 1);
    }

    {
        s16 thunkOff = *(s16*)((u8*)vtable + 0x2A8);
        void* fn = *(void**)((u8*)vtable + 0x2AC);
        void* thisPtr = (void*)((u8*)this + thunkOff);
        typedef void* (*Fn)(void*, int);
        EDLEntry* entry = (EDLEntry*)((Fn)fn)(thisPtr, 4);

        *(u8*)entry = 0x0B;
        *(float*)((u8*)entry + 0x04) = x;
        *(float*)((u8*)entry + 0x08) = y;
        *(float*)((u8*)entry + 0x0C) = w;
        *(float*)((u8*)entry + 0x10) = h;
        *(u32*)((u8*)entry + 0x14) = value;
    }

    {
        s16 thunkOff = *(s16*)((u8*)vtable + 0x2B8);
        void* fn = *(void**)((u8*)vtable + 0x2BC);
        void* thisPtr = (void*)((u8*)this + thunkOff);
        typedef void (*Fn)(void*);
        ((Fn)fn)(thisPtr);
    }
}

// ============================================================================
// ERC::CopyScreenToTexture(ETexture*, EVec4&, EVec2&)
// Address: 0x802F97A0
// Size: 288 bytes
// NON_MATCHING
// ============================================================================
void ERC::CopyScreenToTexture(ETexture* tex, EVec4& srcRect, EVec2& dstSize)
{
    void** vtable = *(void***)((u8*)this + 0x70);

    {
        s16 thunkOff = *(s16*)((u8*)vtable + 0x2B0);
        void* fn = *(void**)((u8*)vtable + 0x2B4);
        void* thisPtr = (void*)((u8*)this + thunkOff);
        typedef void (*Fn)(void*, int, int);
        ((Fn)fn)(thisPtr, 2, 1);
    }

    {
        s16 thunkOff = *(s16*)((u8*)vtable + 0x2A8);
        void* fn = *(void**)((u8*)vtable + 0x2AC);
        void* thisPtr = (void*)((u8*)this + thunkOff);
        typedef void* (*Fn)(void*, int);
        EDLEntry* entry = (EDLEntry*)((Fn)fn)(thisPtr, 4);

        *(u8*)entry = 0x34;
        *(u32*)((u8*)entry + 0x04) = (u32)tex;
        *(float*)((u8*)entry + 0x08) = srcRect.x;
        *(float*)((u8*)entry + 0x0C) = srcRect.y;
        *(float*)((u8*)entry + 0x10) = srcRect.z;
        *(float*)((u8*)entry + 0x14) = srcRect.w;
        *(float*)((u8*)entry + 0x18) = dstSize.x;
        *(float*)((u8*)entry + 0x1C) = dstSize.y;
    }

    {
        s16 thunkOff = *(s16*)((u8*)vtable + 0x2B8);
        void* fn = *(void**)((u8*)vtable + 0x2BC);
        void* thisPtr = (void*)((u8*)this + thunkOff);
        typedef void (*Fn)(void*);
        ((Fn)fn)(thisPtr);
    }
}
#endif

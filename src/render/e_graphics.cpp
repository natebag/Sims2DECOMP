// e_graphics.cpp - EGraphics class (main graphics system)
// Part of the Sims 2 GC decompilation
// Original: engine_ngc_release_dvd.lib(e_graphics.obj)
//
// Small functions (<=64 bytes) decompiled from the e_graphics object file.

#include "render/e_graphics.h"

// External function declarations
extern "C" {
    void* __builtin_new(u32 size);
    void __builtin_delete(void* ptr);
}

// External functions
void* FastAllocPool_Alloc(void* pool, u32 size);
void FastAllocPool_Free(void* pool, void* ptr);
void ERC_Construct(void* ptr);
void* EDL_Alloc(u32 size);
void EDL_Init(void* dl, u32 mode);
void EStr_Assign(void* str, const char* src);

// Constants stored in .sdata2 (read via lis/lfs pattern)
// These addresses reference float constants in the data sections.
// The actual values are loaded from fixed addresses like 0x8041F094, etc.

//=============================================================================
// EGraphics::ManagedShutdown
// Address: 0x802F0F80, Size: 4
//=============================================================================
void EGraphics::ManagedShutdown() {
    // Empty stub - just blr
}

//=============================================================================
// EGraphics::DoSwapBuffer
// Address: 0x802F11A8, Size: 4
//=============================================================================
void EGraphics::DoSwapBuffer(int) {
    // Empty stub - just blr
}

//=============================================================================
// EGraphics::DoSetupFrameBuffer
// Address: 0x802F11AC, Size: 4
//=============================================================================
void EGraphics::DoSetupFrameBuffer(int) {
    // Empty stub - just blr
}

//=============================================================================
// EGraphics::GetScissorRect
// Address: 0x802F12B0, Size: 36
// Copies 16 bytes (TRect<float>) from src to dest
// NON_MATCHING: Original uses lfs/stfs (float copy), GCC uses lwz/stw (int copy)
//=============================================================================
void EGraphics::GetScissorRect(TRect<float>* out, TRect<float>& a, TRect<float>& b) {
    *out = a;
}

//=============================================================================
// EGraphics::SetBackgroundColor
// Address: 0x802F12D4, Size: 40
// Copies EVec3 (12 bytes) to this+0x80, stores int at 0x10, stores ptr at 0x8C
// NON_MATCHING: Register allocation differs, store ordering differs
//=============================================================================
void EGraphics::SetBackgroundColor(EVec3& color, int idx, bool flag) {
    // Store color at offset 0x80
    *(EVec3*)((u8*)this + 0x80) = color;
    // Store idx at offset 0x10
    *(int*)((u8*)this + 0x10) = idx;
    // Store flag pointer at offset 0x8C
    *(EVec3**)((u8*)this + 0x8C) = &color;
}

//=============================================================================
// EGraphics::GetBackgroundColor
// Address: 0x802F12FC, Size: 40
// Copies EVec3 from this+0x80 to color, copies this+0x8C to outIdx
// NON_MATCHING: Register allocation differs
//=============================================================================
void EGraphics::GetBackgroundColor(EVec3& color, int& outIdx) {
    color = *(EVec3*)((u8*)this + 0x80);
    outIdx = *(int*)((u8*)this + 0x8C);
}

//=============================================================================
// EGraphics::AllocDL
// Address: 0x802F1324, Size: 44
// Allocates 0x68 bytes and calls EDL_Init
// NON_MATCHING: bl targets may differ
//=============================================================================
EDL* EGraphics::AllocDL(RCMode mode) {
    void* mem = FastAllocPool_Alloc((void*)0, 0x68);  // size = 104
    EDL_Init(mem, 0x1000);
    return (EDL*)mem;
}

//=============================================================================
// EGraphics::FreeDL
// Address: 0x802F1350, Size: 64
// Frees an EDL by calling its vtable destructor
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void EGraphics::FreeDL(EDL* dl, RCMode mode) {
    if (dl != 0) {
        // Get vtable entry at offset 100 -> get thunk offset at +8, fn at +12
        void** vtable = *(void***)((u8*)dl + 100);
        s16 thunkOff = *(s16*)((u8*)vtable + 8);
        void* fn = *(void**)((u8*)vtable + 12);
        void* thisPtr = (void*)((u8*)dl + thunkOff);
        // Call destructor with mode=3
        typedef void (*DestroyFn)(void*, int);
        ((DestroyFn)fn)(thisPtr, 3);
    }
}

//=============================================================================
// EGraphics::AllocRC
// Address: 0x802F1390, Size: 40
// Allocates 0x74 bytes and constructs ERC
// NON_MATCHING: bl targets
//=============================================================================
ERC* EGraphics::AllocRC(RCMode mode) {
    void* mem = __builtin_new(0x74);
    ERC_Construct(mem);
    return (ERC*)mem;
}

//=============================================================================
// EGraphics::FreeRC
// Address: 0x802F13B8, Size: 64
// Frees an ERC by calling its vtable destructor
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void EGraphics::FreeRC(ERC* rc, RCMode mode) {
    if (rc != 0) {
        void** vtable = *(void***)((u8*)rc + 112);
        s16 thunkOff = *(s16*)((u8*)vtable + 8);
        void* fn = *(void**)((u8*)vtable + 12);
        void* thisPtr = (void*)((u8*)rc + thunkOff);
        typedef void (*DestroyFn)(void*, int);
        ((DestroyFn)fn)(thisPtr, 3);
    }
}

//=============================================================================
// EGraphics::Execute
// Address: 0x802F1520, Size: 56
// NON_MATCHING: vtable dispatch via gpEGraphics singleton
//=============================================================================
void EGraphics::Execute(EDL* dl, bool flush) {
    // Dispatches through gpEGraphics vtable at offset 0x338
    // vtable[0x28/4] -> actual execute
    // Complex vtable dispatch - stubbing
    (void)dl;
    (void)flush;
}

//=============================================================================
// EGraphics::AllocDisplayList
// Address: 0x802F1558, Size: 52
// Dispatches through vtable offset 0x1C8/0x1CC
// NON_MATCHING: vtable dispatch
//=============================================================================
EDL* EGraphics::AllocDisplayList(RCMode mode) {
    // vtable dispatch
    return 0;
}

//=============================================================================
// EGraphics::Destroy(EDL*)
// Address: 0x802F158C, Size: 44
// If dl is not null, calls DeallocateDL with flag=1
//=============================================================================
void EGraphics::Destroy(EDL* dl) {
    if (dl) {
        DeallocateDL(dl, (RCMode)1);
    }
}

//=============================================================================
// EGraphics::DeallocateDL
// Address: 0x802F15B8, Size: 52
// Dispatches through vtable offset 0x1D0/0x1D4
// NON_MATCHING: vtable dispatch
//=============================================================================
void EGraphics::DeallocateDL(EDL* dl, RCMode mode) {
    // vtable dispatch through this->vtable[0x1D0]
    (void)dl;
    (void)mode;
}

//=============================================================================
// EGraphics::CreateMovie
// Address: 0x802F1954, Size: 52
// Dispatches through vtable offset 0x218/0x21C
// NON_MATCHING: vtable dispatch
//=============================================================================
EMovie* EGraphics::CreateMovie() {
    // vtable dispatch
    return 0;
}

//=============================================================================
// EGraphics::Destroy(EMovie*)
// Address: 0x802F1988, Size: 52
// Dispatches through vtable offset 0x220/0x224
// NON_MATCHING: vtable dispatch
//=============================================================================
void EGraphics::Destroy(EMovie* movie) {
    // vtable dispatch
    (void)movie;
}

//=============================================================================
// EGraphics::GetSystemFont
// Address: 0x802F1E98, Size: 48
// NON_MATCHING: calls some init function then returns this->m_systemFont
//=============================================================================
void* EGraphics::GetSystemFont() {
    // Calls an init function first, then returns offset 0x90
    return *(void**)((u8*)this + 0x90);
}

//=============================================================================
// EGraphics::GetFrameBufferTextureCoordinate
// Address: 0x802F1F9C, Size: 24
// Copies EVec2 from parameter to return value (pass by value -> struct copy)
//=============================================================================
void EGraphics::GetFrameBufferTextureCoordinate(EVec2 coord) {
    // Original stores coord.x and coord.y into return struct
    // The function takes coord by value (passed on stack as r5 in PPC)
    // and copies it to the return struct pointer (r3)
    (void)coord;
}

//=============================================================================
// EGraphics::SetMotionBlur
// Address: 0x802F20D8, Size: 20
// Stores 4 floats at offsets 0x2F0-0x2FC
// NON_MATCHING: SN Systems stores f4 first then f1,f2,f3; GCC stores f1,f2,f3,f4
//=============================================================================
void EGraphics::SetMotionBlur(float a, float b, float c, float d) {
    *(float*)((u8*)this + 0x2FC) = d;
    *(float*)((u8*)this + 0x2F0) = a;
    *(float*)((u8*)this + 0x2F4) = b;
    *(float*)((u8*)this + 0x2F8) = c;
}

//=============================================================================
// EGraphics::GetCameraBloom
// Address: 0x802F20EC, Size: 36
// Loads 4 floats from offsets 0x2AC-0x2B8
// NON_MATCHING: GCC uses f0 for all loads, original alternates f0/f13
//=============================================================================
void EGraphics::GetCameraBloom(float& a, float& b, float& c, float& d) {
    a = *(float*)((u8*)this + 0x2AC);
    b = *(float*)((u8*)this + 0x2B0);
    c = *(float*)((u8*)this + 0x2B4);
    d = *(float*)((u8*)this + 0x2B8);
}

//=============================================================================
// EGraphics::GetMotionBlur
// Address: 0x802F2110, Size: 36
// Loads 4 floats from offsets 0x2F0-0x2FC
// NON_MATCHING: GCC uses f0 for all loads, original alternates f0/f13
//=============================================================================
void EGraphics::GetMotionBlur(float& a, float& b, float& c, float& d) {
    a = *(float*)((u8*)this + 0x2F0);
    b = *(float*)((u8*)this + 0x2F4);
    c = *(float*)((u8*)this + 0x2F8);
    d = *(float*)((u8*)this + 0x2FC);
}

//=============================================================================
// EGraphics::SetTint
// Address: 0x802F2134, Size: 60
// Copies two EVec3 to offsets 0x300 and 0x30C
//=============================================================================
void EGraphics::SetTint(EVec3& a, EVec3& b) {
    *(EVec3*)((u8*)this + 0x300) = a;
    *(EVec3*)((u8*)this + 0x30C) = b;
}

//=============================================================================
// EGraphics::GetTint
// Address: 0x802F2170, Size: 60
// Copies two EVec3 from offsets 0x300 and 0x30C
//=============================================================================
void EGraphics::GetTint(EVec3& a, EVec3& b) {
    a = *(EVec3*)((u8*)this + 0x300);
    b = *(EVec3*)((u8*)this + 0x30C);
}

//=============================================================================
// EGraphics::Shutdown
// Address: 0x802F21AC, Size: 4
//=============================================================================
void EGraphics::Shutdown() {
    // Empty stub - just blr
}

//=============================================================================
// EGraphics::FrameBufferClearFlag
// Address: 0x802F21B0, Size: 8
// Returns this->0x0C
//=============================================================================
u32 EGraphics::FrameBufferClearFlag() {
    return *(u32*)((u8*)this + 0x0C);
}

//=============================================================================
// EGraphics::FrameBufferClearRequestFlag
// Address: 0x802F21B8, Size: 8
// Returns this->0x10
//=============================================================================
u32 EGraphics::FrameBufferClearRequestFlag() {
    return *(u32*)((u8*)this + 0x10);
}

//=============================================================================
// EGraphics::DrawCensorRects
// Address: 0x802F21C0, Size: 4
//=============================================================================
void EGraphics::DrawCensorRects(ERC*) {
    // Empty stub - just blr
}

//=============================================================================
// EGraphics::GetFrameBufferTexture
// Address: 0x802F21C4, Size: 8
// Returns 0
//=============================================================================
int EGraphics::GetFrameBufferTexture(int) {
    return 0;
}

//=============================================================================
// EGraphics::GetDepthBufferTexture
// Address: 0x802F21CC, Size: 8
// Returns 0
//=============================================================================
int EGraphics::GetDepthBufferTexture() {
    return 0;
}

//=============================================================================
// EGraphics::NeedFlushToDestroy(EDL*)
// Address: 0x802F21D4, Size: 8
// Returns 1
//=============================================================================
int EGraphics::NeedFlushToDestroy(EDL*) {
    return 1;
}

//=============================================================================
// EGraphics::NeedFlushToDestroy(ETexture*)
// Address: 0x802F21DC, Size: 8
// Returns 1
//=============================================================================
int EGraphics::NeedFlushToDestroy(ETexture*) {
    return 1;
}

//=============================================================================
// EGraphics::NeedFlushToDestroy(ERenderSurface*)
// Address: 0x802F21E4, Size: 8
// Returns 1
//=============================================================================
int EGraphics::NeedFlushToDestroy(ERenderSurface*) {
    return 1;
}

//=============================================================================
// EGraphics::NeedFlushToDestroy(EMovie*)
// Address: 0x802F21EC, Size: 8
// Returns 1
//=============================================================================
int EGraphics::NeedFlushToDestroy(EMovie*) {
    return 1;
}

//=============================================================================
// EGraphics::GetLargestAvailableTextureMemoryBlock
// Address: 0x802F21F4, Size: 8
// Returns -1 (0xFFFFFFFF)
//=============================================================================
int EGraphics::GetLargestAvailableTextureMemoryBlock() {
    return -1;
}

//=============================================================================
// EGraphics::NeedFlushToDestroy(EShader*)
// Address: 0x802F21FC, Size: 8
// Returns 1
//=============================================================================
int EGraphics::NeedFlushToDestroy(EShader*) {
    return 1;
}

//=============================================================================
// EGraphics::GetFarZVal
// Address: 0x802F2204, Size: 12
// Loads float constant from .sdata2
// NON_MATCHING: GCC generates lis+ori+lfs, original uses lis+lfs (SDA-relative)
//=============================================================================
float EGraphics::GetFarZVal() {
    // Original loads from lis r9,0x8042; lfs f1,-3948(r9)
    // This is a constant - likely 100000.0f or similar far-Z value
    return *(volatile float*)0x8041F094;
}

//=============================================================================
// EGraphics::GetNearZVal
// Address: 0x802F2210, Size: 12
// Loads float constant from .sdata2
// NON_MATCHING: GCC generates lis+ori+lfs, original uses lis+lfs (SDA-relative)
//=============================================================================
float EGraphics::GetNearZVal() {
    return *(volatile float*)0x8041F098;
}

//=============================================================================
// EGraphics::GetCoordinateSystem
// Address: 0x802F221C, Size: 8
// Returns this->0x98
//=============================================================================
u32 EGraphics::GetCoordinateSystem() {
    return *(u32*)((u8*)this + 0x98);
}

//=============================================================================
// EGraphics::SetCoordinateSystem
// Address: 0x802F2224, Size: 8
// Sets this->0x98 to coord system
//=============================================================================
void EGraphics::SetCoordinateSystem(ECoordinateSystem cs) {
    *(u32*)((u8*)this + 0x98) = (u32)cs;
}

//=============================================================================
// EGraphics::GetScreenAspect
// Address: 0x802F222C, Size: 12
// Loads float constant from .sdata2
//=============================================================================
float EGraphics::GetScreenAspect() {
    return *(volatile float*)0x8041F09C;
}

//=============================================================================
// EGraphics::GetScreenXSize
// Address: 0x802F2238, Size: 8
// Returns this->0x18
//=============================================================================
int EGraphics::GetScreenXSize() {
    return *(int*)((u8*)this + 0x18);
}

//=============================================================================
// EGraphics::GetScreenYSize
// Address: 0x802F2240, Size: 8
// Returns this->0x1C
//=============================================================================
int EGraphics::GetScreenYSize() {
    return *(int*)((u8*)this + 0x1C);
}

//=============================================================================
// EGraphics::GetXPixelSize
// Address: 0x802F2248, Size: 64
// Returns 1.0f / (float)GetScreenXSize()
// NON_MATCHING: int-to-float conversion uses different codegen
//=============================================================================
float EGraphics::GetXPixelSize() {
    int xSize = *(int*)((u8*)this + 0x18);
    return 1.0f / (float)xSize;
}

//=============================================================================
// EGraphics::GetYPixelSize
// Address: 0x802F2288, Size: 64
// Returns 1.0f / (float)GetScreenYSize()
// NON_MATCHING: int-to-float conversion uses different codegen
//=============================================================================
float EGraphics::GetYPixelSize() {
    int ySize = *(int*)((u8*)this + 0x1C);
    return 1.0f / (float)ySize;
}

//=============================================================================
// EGraphics::GetActualScreenXSize
// Address: 0x802F22C8, Size: 8
// Returns this->0x18
//=============================================================================
int EGraphics::GetActualScreenXSize() {
    return *(int*)((u8*)this + 0x18);
}

//=============================================================================
// EGraphics::GetActualScreenYSize
// Address: 0x802F22D0, Size: 8
// Returns this->0x1C
//=============================================================================
int EGraphics::GetActualScreenYSize() {
    return *(int*)((u8*)this + 0x1C);
}

//=============================================================================
// EGraphics::SetScreenXOffset
// Address: 0x802F22D8, Size: 8
// Sets this->0x20
//=============================================================================
void EGraphics::SetScreenXOffset(int x) {
    *(int*)((u8*)this + 0x20) = x;
}

//=============================================================================
// EGraphics::SetScreenYOffset
// Address: 0x802F22E0, Size: 8
// Sets this->0x24
//=============================================================================
void EGraphics::SetScreenYOffset(int y) {
    *(int*)((u8*)this + 0x24) = y;
}

//=============================================================================
// EGraphics::GetScreenXOffset
// Address: 0x802F22E8, Size: 8
// Returns this->0x20
//=============================================================================
int EGraphics::GetScreenXOffset() {
    return *(int*)((u8*)this + 0x20);
}

//=============================================================================
// EGraphics::GetScreenYOffset
// Address: 0x802F22F0, Size: 8
// Returns this->0x24
//=============================================================================
int EGraphics::GetScreenYOffset() {
    return *(int*)((u8*)this + 0x24);
}

//=============================================================================
// EGraphics::GetMaxTextureXSize
// Address: 0x802F22F8, Size: 8
// Returns 1024
//=============================================================================
int EGraphics::GetMaxTextureXSize() {
    return 1024;
}

//=============================================================================
// EGraphics::GetMaxTextureYSize
// Address: 0x802F2300, Size: 8
// Returns 1024
//=============================================================================
int EGraphics::GetMaxTextureYSize() {
    return 1024;
}

//=============================================================================
// EGraphics::GetNormalMapMatrix
// Address: 0x802F2308, Size: 8
// Returns pointer to this+0x40
//=============================================================================
EMat4* EGraphics::GetNormalMapMatrix() {
    return (EMat4*)((u8*)this + 0x40);
}

//=============================================================================
// EGraphics::GrabFrameBufferChunk32
// Address: 0x802F2310, Size: 4
//=============================================================================
void EGraphics::GrabFrameBufferChunk32(int, int, int, int, unsigned int*, int*) {
    // Empty stub
}

//=============================================================================
// EGraphics::DiscardAllVram
// Address: 0x802F2314, Size: 4
//=============================================================================
void EGraphics::DiscardAllVram() {
    // Empty stub
}

//=============================================================================
// EGraphics::ClearStencilBuffer
// Address: 0x802F2318, Size: 4
//=============================================================================
void EGraphics::ClearStencilBuffer() {
    // Empty stub
}

//=============================================================================
// EGraphics::ProcessFrameEffects
// Address: 0x802F231C, Size: 4
//=============================================================================
void EGraphics::ProcessFrameEffects() {
    // Empty stub
}

//=============================================================================
// EGraphics::EnableWireframe
// Address: 0x802F2320, Size: 8
// Sets this->0x318
//=============================================================================
void EGraphics::EnableWireframe(bool enable) {
    *(u32*)((u8*)this + 0x318) = (u32)enable;
}

//=============================================================================
// EGraphics::EnableFirstPassRender
// Address: 0x802F2328, Size: 12
// Sets this->0x31C = 1
// NON_MATCHING: GCC uses r9, original uses r0
//=============================================================================
void EGraphics::EnableFirstPassRender() {
    *(u32*)((u8*)this + 0x31C) = 1;
}

//=============================================================================
// EGraphics::EnableNormalRender
// Address: 0x802F2334, Size: 12
// Sets this->0x31C = 0
// NON_MATCHING: GCC uses r9, original uses r0
//=============================================================================
void EGraphics::EnableNormalRender() {
    *(u32*)((u8*)this + 0x31C) = 0;
}

//=============================================================================
// EGraphics::IsFirstPassRenderOnly
// Address: 0x802F2340, Size: 8
// Returns this->0x31C
//=============================================================================
int EGraphics::IsFirstPassRenderOnly() {
    return *(int*)((u8*)this + 0x31C);
}

//=============================================================================
// EGraphics::SetEnableFrameEffects
// Address: 0x802F2348, Size: 8
// Sets this->0x320
//=============================================================================
void EGraphics::SetEnableFrameEffects(bool enable) {
    *(u32*)((u8*)this + 0x320) = (u32)enable;
}

//=============================================================================
// EGraphics::IsEnableFrameEffects
// Address: 0x802F2350, Size: 8
// Returns this->0x320
//=============================================================================
int EGraphics::IsEnableFrameEffects() {
    return *(int*)((u8*)this + 0x320);
}

//=============================================================================
// EGraphics::IsInsideBeginEnd
// Address: 0x802F2358, Size: 8
// Returns this->0x04
//=============================================================================
int EGraphics::IsInsideBeginEnd() {
    return *(int*)((u8*)this + 0x04);
}

//=============================================================================
// EGraphics::ManagedStartup
// Address: 0x802F2360, Size: 8
// Returns 1
//=============================================================================
int EGraphics::ManagedStartup() {
    return 1;
}

//=============================================================================
// EGraphics::SelectFrameBuffer
// Address: 0x802F2368, Size: 4
//=============================================================================
void EGraphics::SelectFrameBuffer(int) {
    // Empty stub
}

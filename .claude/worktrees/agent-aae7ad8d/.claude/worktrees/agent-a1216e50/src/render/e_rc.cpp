// e_rc.cpp - ERC class (render context)
// Part of the Sims 2 GC decompilation
// Original: engine_ngc_release_dvd.lib(e_rc.obj)
//
// Small functions (<=64 bytes) decompiled from the e_rc object file.

#include "render/e_rc.h"

// External function declarations
extern void* DLAlloc(void* dl, u32 size);
extern void* DLAllocExternal(void* dl, void* ptr, int size);
extern void DLFlushableAlloc(void* dl, u32 size);
extern void DLFlushableAllocExternal(void* dl, void* ptr, int size);
extern void DLValidate(void* dl);
extern void EStr_Copy(void* dest, const char* src);
extern void ERC_ERC_InitHelper(int active, int type);

//=============================================================================
// ERC::Connect
// Address: 0x802F682C, Size: 16
// Sets entry type to 7, stores pointer
//=============================================================================
void ERC::Connect(EDLEntry* a, EDLEntry* b) {
    *(u8*)a = 7;
    *(void**)((u8*)a + 4) = b;
}

//=============================================================================
// ERC::TriStripRef (float version)
// Address: 0x802F6A2C, Size: 52
// Dispatches through vtable offset 0x20/0x24
// NON_MATCHING: vtable dispatch
//=============================================================================
void ERC::TriStripRef(int count, float* verts, float* texCoords, unsigned char* colors, signed char* normals, unsigned char* flags, bool strip) {
    // vtable dispatch through this->m_vtable[0x20]
    void** vtable = *(void***)((u8*)this + 0x70);
    s16 thunkOff = *(s16*)((u8*)vtable + 0x20);
    void* fn = *(void**)((u8*)vtable + 0x24);
    void* thisPtr = (void*)((u8*)this + thunkOff);
    typedef void (*Fn)(void*, int, float*, float*, unsigned char*, signed char*, unsigned char*, bool);
    ((Fn)fn)(thisPtr, count, verts, texCoords, colors, normals, flags, strip);
}

//=============================================================================
// ERC::TriStripRef (short version)
// Address: 0x802F6BAC, Size: 52
// Dispatches through vtable offset 0x30/0x34
// NON_MATCHING: vtable dispatch
//=============================================================================
void ERC::TriStripRef(int count, short* verts, short* texCoords, unsigned char* colors, signed char* normals, unsigned char* flags, bool strip) {
    void** vtable = *(void***)((u8*)this + 0x70);
    s16 thunkOff = *(s16*)((u8*)vtable + 0x30);
    void* fn = *(void**)((u8*)vtable + 0x34);
    void* thisPtr = (void*)((u8*)this + thunkOff);
    typedef void (*Fn)(void*, int, short*, short*, unsigned char*, signed char*, unsigned char*, bool);
    ((Fn)fn)(thisPtr, count, verts, texCoords, colors, normals, flags, strip);
}

//=============================================================================
// ERC::TriFan
// Address: 0x802F6BE0, Size: 4
//=============================================================================
void ERC::TriFan(EGEVert*, int) {
    // Empty stub
}

//=============================================================================
// ERC::TriList
// Address: 0x802F6BE4, Size: 4
//=============================================================================
void ERC::TriList(EGEVert*, int) {
    // Empty stub
}

//=============================================================================
// ERC::QuadList(EGEVert*, int)
// Address: 0x802F6BE8, Size: 4
//=============================================================================
void ERC::QuadList(EGEVert*, int) {
    // Empty stub
}

//=============================================================================
// ERC::QuadList(int, float*, float*, unsigned char*, signed char*, bool)
// Address: 0x802F6BEC, Size: 4
//=============================================================================
void ERC::QuadList(int, float*, float*, unsigned char*, signed char*, bool) {
    // Empty stub
}

//=============================================================================
// ERC::PointList
// Address: 0x802F6D58, Size: 4
//=============================================================================
void ERC::PointList(EGEVert*, int) {
    // Empty stub
}

//=============================================================================
// ERC::ParticleListInfo
// Address: 0x802F7068, Size: 4
//=============================================================================
void ERC::ParticleListInfo(EGEParticleListInfo*) {
    // Empty stub
}

//=============================================================================
// ERC::ParticleListBegin
// Address: 0x802F706C, Size: 8
// Returns 0
//=============================================================================
int ERC::ParticleListBegin(unsigned int, unsigned int) {
    return 0;
}

//=============================================================================
// ERC::ParticleListEnd
// Address: 0x802F7074, Size: 4
//=============================================================================
void ERC::ParticleListEnd(unsigned int) {
    // Empty stub
}

//=============================================================================
// ERC::ModelMatrixId
// Address: 0x802F7900, Size: 60
// Dispatches through vtable offset 0xE0/0xE4 with args (0, 254)
// NON_MATCHING: vtable dispatch
//=============================================================================
void ERC::ModelMatrixId() {
    void** vtable = *(void***)((u8*)this + 0x70);
    s16 thunkOff = *(s16*)((u8*)vtable + 0xE0);
    void* fn = *(void**)((u8*)vtable + 0xE4);
    void* thisPtr = (void*)((u8*)this + thunkOff);
    typedef void (*Fn)(void*, int, int);
    ((Fn)fn)(thisPtr, 0, 254);
}

//=============================================================================
// ERC::MipMapSetup
// Address: 0x802F826C, Size: 4
//=============================================================================
void ERC::MipMapSetup(EGEVert*, bool, bool) {
    // Empty stub
}

//=============================================================================
// ERC::SetColorModulation
// Address: 0x802F8DE0, Size: 4
//=============================================================================
void ERC::SetColorModulation(int, EVec4) {
    // Empty stub
}

//=============================================================================
// ERC::EnableColorModulation
// Address: 0x802F8DE4, Size: 4
//=============================================================================
void ERC::EnableColorModulation(bool) {
    // Empty stub
}

//=============================================================================
// ERC::SetBlendModePass3
// Address: 0x802F8EC4, Size: 4
//=============================================================================
void ERC::SetBlendModePass3(int, int, int, int, int) {
    // Empty stub
}

//=============================================================================
// ERC::SetTextureAlphaValue
// Address: 0x802F8EC8, Size: 4
//=============================================================================
void ERC::SetTextureAlphaValue(unsigned char, unsigned char, unsigned char) {
    // Empty stub
}

//=============================================================================
// ERC::SetDebugMarker
// Address: 0x802F9674, Size: 4
//=============================================================================
void ERC::SetDebugMarker(int) {
    // Empty stub
}

//=============================================================================
// ERC::SetAlphaPlane
// Address: 0x802F9798, Size: 4
//=============================================================================
void ERC::SetAlphaPlane(float, EVec4, float, float) {
    // Empty stub
}

//=============================================================================
// ERC::SetFog
// Address: 0x802F979C, Size: 4
//=============================================================================
void ERC::SetFog(float, float, EVec4) {
    // Empty stub
}

//=============================================================================
// ERC::Alloc
// Address: 0x802F98C0, Size: 36
// Calls DLAlloc(this->m_dlPtr, size) with alignment
// NON_MATCHING: bl target
//=============================================================================
void* ERC::Alloc(unsigned int size, int align) {
    return DLAlloc(m_dlPtr, size);
}

//=============================================================================
// ERC::AllocExternal
// Address: 0x802F98E4, Size: 36
// Calls DLAllocExternal(this->m_dlPtr, ptr, size)
// NON_MATCHING: bl target
//=============================================================================
void* ERC::AllocExternal(void* ptr, int size) {
    return DLAllocExternal(m_dlPtr, ptr, size);
}

//=============================================================================
// ERC::AllocFlushable
// Address: 0x802F9908, Size: 40
// Calls DLFlushableAlloc(this->m_dlPtr + 0x18, size)
// NON_MATCHING: offset into DL struct
//=============================================================================
void* ERC::AllocFlushable(unsigned int size, int align) {
    void* dlBase = m_dlPtr;
    void* dlFlush = (void*)((u8*)dlBase + 0x18);
    return DLAlloc(dlFlush, size);
}

//=============================================================================
// ERC::AllocFlushableExternal
// Address: 0x802F9930, Size: 40
// Calls DLAllocExternal(this->m_dlPtr + 0x18, ptr, size)
// NON_MATCHING: offset into DL struct
//=============================================================================
void* ERC::AllocFlushableExternal(void* ptr, int size) {
    void* dlBase = m_dlPtr;
    void* dlFlush = (void*)((u8*)dlBase + 0x18);
    return DLAllocExternal(dlFlush, ptr, size);
}

//=============================================================================
// ERC::ProcessFrameEffects
// Address: 0x802F99B4, Size: 56
// Dispatches through gpEGraphics vtable at offset 0x1A0/0x1A4
// NON_MATCHING: vtable dispatch via global pointer
//=============================================================================
void ERC::ProcessFrameEffects(int type, void* data) {
    // Uses gpEGraphics (r13-26392) to dispatch
    (void)type;
    (void)data;
}

//=============================================================================
// ERC::SetName
// Address: 0x802F99EC, Size: 36
// Copies string to this+0x6C
// NON_MATCHING: bl target for string copy
//=============================================================================
void ERC::SetName(char* name) {
    EStr_Copy((void*)((u8*)this + 0x6C), name);
}

//=============================================================================
// ERC::ModelMatrix
// Address: 0x802F9A80, Size: 56
// Dispatches through vtable offset 0xE8/0xEC with flag=1
// NON_MATCHING: vtable dispatch
//=============================================================================
void ERC::ModelMatrix(EMat4* mat) {
    void** vtable = *(void***)((u8*)this + 0x70);
    s16 thunkOff = *(s16*)((u8*)vtable + 0xE8);
    void* fn = *(void**)((u8*)vtable + 0xEC);
    void* thisPtr = (void*)((u8*)this + thunkOff);
    typedef void (*Fn)(void*, EMat4*, int);
    ((Fn)fn)(thisPtr, mat, 1);
}

//=============================================================================
// ERC::LightsRadiosity
// Address: 0x802F9AB8, Size: 4
//=============================================================================
void ERC::LightsRadiosity(EVec3_ref&, EVec3_ref&, float) {
    // Empty stub
}

//=============================================================================
// ERC::Validate
// Address: 0x802F9ABC, Size: 36
// Calls DLValidate(this->m_dlPtr)
// NON_MATCHING: bl target
//=============================================================================
void ERC::Validate() {
    DLValidate(m_dlPtr);
}

//=============================================================================
// ERC::GetFogColor
// Address: 0x802F9AE0, Size: 44
// Returns EVec4 copy from (this->m_dlPtr->0x5C)
// The fog color is at m_dlPtr + 0x5C (16 bytes = EVec4)
//=============================================================================
EVec4* ERC::GetFogColor() {
    // Original copies 4 floats from r4+0x5C into return struct (r3)
    // r4 is some internal pointer
    return 0;
}

//=============================================================================
// ERC::AllocVertexData
// Address: 0x802F9B0C, Size: 8
// Returns 0
//=============================================================================
void* ERC::AllocVertexData(unsigned int) {
    return 0;
}

//=============================================================================
// ERC::SetCopyDataCallback
// Address: 0x802F9B14, Size: 12
// Sets function pointer and context at offsets 0x54, 0x58
//=============================================================================
void ERC::SetCopyDataCallback(void (*fn)(void*, void*), void* ctx) {
    *(void**)((u8*)this + 0x58) = ctx;
    *(void**)((u8*)this + 0x54) = (void*)fn;
}

//=============================================================================
// ERC::IsOpen
// Address: 0x802F9B20, Size: 24
// Returns true if m_openCount (offset 0x18) != 0
//=============================================================================
bool ERC::IsOpen() const {
    u8 count = *(u8*)((u8*)this + 0x18);
    if (count != 0) {
        return true;
    }
    return false;
}

//=============================================================================
// ERC::EndCommand
// Address: 0x802F9B38, Size: 24
// Sets m_endCommandFlag = 1, decrements m_openCount
//=============================================================================
void ERC::EndCommand() {
    u8 count = *(u8*)((u8*)this + 0x18);
    *(u32*)((u8*)this + 0x14) = 1;
    *(u8*)((u8*)this + 0x18) = count - 1;
}

//=============================================================================
// global constructors keyed to ERC::ERC(void)
// Address: 0x802F9B50, Size: 44
// Calls ERC_ERC_InitHelper(1, 0xFFFF)
// NON_MATCHING: bl target and SDA load pattern
//=============================================================================
static void __sinit_e_rc_cpp() {
    ERC_ERC_InitHelper(1, 0xFFFF);
}

//=============================================================================
// global destructors keyed to ERC::ERC(void)
// Address: 0x802F9B7C, Size: 44
// Calls ERC_ERC_InitHelper(0, 0xFFFF)
// NON_MATCHING: bl target and SDA load pattern
//=============================================================================
// Note: destructor handled by __destroy_global_chain

// ============================================================================
// MEDIUM FUNCTIONS (65-256 bytes)
// ============================================================================

// Forward declarations for medium functions
struct EViewport;
struct ELights;
struct EGEPackedParticle;
struct EGELineStreak;
class ETexture;
class ERenderSurface;
class EMovie;
struct ETextureDef;
struct EShaderDef;
struct ERenderSurfaceDef;

extern void EStr_Init(void* str);
extern void EStr_Destroy(void* str, void* data);
extern void EDL_AddRef(void* dl, void* entry);
extern void* DLAllocAndCopy(void* dl, void* data, int size);
extern void memcpy_wrapper(void* dst, const void* src, u32 size);

// Helper: vtable dispatch thunk pattern used throughout ERC
// The vtable at this+0x70 has entries laid out as:
//   offset+0x00: s16 thunk_offset
//   offset+0x04: void* function_ptr
// To call: this_adjusted = this + thunk_offset; fn(this_adjusted, args...)

//=============================================================================
// ERC::ERC(void)
// Address: 0x802F64A8, Size: 132
// NON_MATCHING: vtable address, bl targets
//=============================================================================
ERC::ERC() {
    // Sets vtable at offset 0x70
    // vtable = 0x8046AA48 (computed from lis/addi)
    // Calls EStr_Init(this+0x6C) to initialize name string
    EStr_Init((void*)((u8*)this + 0x6C));
    m_openCount = 0;
    *(u32*)((u8*)this + 0x20) = 0; // m_allocCount
    // Fill 4 entries at this+0x24..0x30 with 0xFF
    for (int i = 0; i < 4; i++) {
        *(u32*)((u8*)this + 0x30 - i * 4) = 0xFF;
    }
    *(u32*)((u8*)this + 0x58) = 0; // m_copyDataCtx
    *(u32*)((u8*)this + 0x34) = 0; // m_matrixDirty
    *(u32*)((u8*)this + 0x38) = 0; // m_matrixData
    *(u32*)((u8*)this + 0x3C) = 0;
    *(u32*)((u8*)this + 0x40) = 0;
    *(u32*)((u8*)this + 0x54) = 0;
}

//=============================================================================
// ERC::~ERC(void)
// Address: 0x802F652C, Size: 84
// NON_MATCHING: vtable address, bl targets
//=============================================================================
// Already declared in header as destructor
// Resets vtable, destroys name string, conditionally frees
// Uses: EStr_Destroy(this+0x6C, data), operator delete

//=============================================================================
// ERC::Init(RCMode)
// Address: 0x802F6580, Size: 136
// NON_MATCHING: vtable dispatch, bl targets
//=============================================================================
// Initializes the render context for a given mode
// Gets gpEGraphics from r13 SDA, calls AllocDisplayList, then AllocAndCopy

//=============================================================================
// ERC::BeginCommand(int, int)
// Address: 0x802F6608, Size: 144
// NON_MATCHING: vtable dispatch
//=============================================================================
// Saves old command, sets new command type, conditionally dispatches
// through vtable+0x2C0/0x2C4 and vtable+0x2C8/0x2CC

//=============================================================================
// ERC::Send(void)
// Address: 0x802F6698, Size: 244
// NON_MATCHING: vtable dispatch, bl targets
//=============================================================================
// Complex function: checks m_endCommandFlag, creates DL handle,
// dispatches through multiple vtable entries

//=============================================================================
// ERC::NewEntry(int)
// Address: 0x802F678C, Size: 160
// NON_MATCHING: vtable dispatch, bl targets
//=============================================================================
// Allocates a new display list entry of given size (in 8-byte units)
// If space available in current DL, returns pointer directly
// Otherwise calls AllocAndCopy for overflow

//=============================================================================
// ERC::TriStrip(EGEVert*, int)
// Address: 0x802F683C, Size: 176
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::TriStrip(EGEVert* verts, int count) {
    if (count == 0) return;
    void* copy = AllocAndCopy((void*)verts, count * 80);
    // vtable dispatch: BeginPrimitive(2, 1)
    void** vt = *(void***)((u8*)this + 0x70);
    {
        s16 off = *(s16*)((u8*)vt + 0x2B0);
        void* fn = *(void**)((u8*)vt + 0x2B4);
        typedef void (*Fn)(void*, int, int);
        ((Fn)fn)((u8*)this + off, 2, 1);
    }
    // Update vertex count: this->m_dl->0x54 += count
    void* dl = *(void**)((u8*)this + 0x00);
    *(u32*)((u8*)dl + 0x54) += count;
    // vtable dispatch: NewEntry(1)
    EDLEntry* entry;
    {
        s16 off = *(s16*)((u8*)vt + 0x2A8);
        void* fn = *(void**)((u8*)vt + 0x2AC);
        typedef EDLEntry* (*Fn)(void*, int);
        entry = ((Fn)fn)((u8*)this + off, 1);
    }
    // Fill entry: type=0, count=count, data=copy
    *(u8*)entry = 0;
    *(u16*)((u8*)entry + 2) = (u16)count;
    *(void**)((u8*)entry + 4) = copy;
    // vtable dispatch: EndPrimitive()
    {
        s16 off = *(s16*)((u8*)vt + 0x2B8);
        void* fn = *(void**)((u8*)vt + 0x2BC);
        typedef void (*Fn)(void*);
        ((Fn)fn)((u8*)this + off);
    }
}

//=============================================================================
// ERC::LineList(EGEVert*, int)
// Address: 0x802F6BF0, Size: 180
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::LineList(EGEVert* verts, int count) {
    if (count == 0) return;
    void* copy = AllocAndCopy((void*)verts, count * 80);
    // BeginPrimitive(2, 5)
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 2, 5); }
    void* dl = *(void**)((u8*)this + 0x00);
    *(u32*)((u8*)dl + 0x54) += count;
    // NewEntry(1)
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x1A; // command 26
    *(u16*)((u8*)entry + 2) = (u16)count;
    *(void**)((u8*)entry + 4) = copy;
    // EndPrimitive
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::LineStrip(EGEVert*, int)
// Address: 0x802F6CA4, Size: 180
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::LineStrip(EGEVert* verts, int count) {
    if (count == 0) return;
    void* copy = AllocAndCopy((void*)verts, count * 80);
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 2, 4); }
    void* dl = *(void**)((u8*)this + 0x00);
    *(u32*)((u8*)dl + 0x54) += count;
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x1B; // command 27
    *(u16*)((u8*)entry + 2) = (u16)count;
    *(void**)((u8*)entry + 4) = copy;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::SpriteList(EGEVert*, int)
// Address: 0x802F6E88, Size: 180
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::SpriteList(EGEVert* verts, int count) {
    if (count == 0) return;
    void* copy = AllocAndCopy((void*)verts, count * 80);
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 2, 6); }
    void* dl = *(void**)((u8*)this + 0x00);
    *(u32*)((u8*)dl + 0x54) += count;
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x05; // command 5
    *(u16*)((u8*)entry + 2) = (u16)count;
    *(void**)((u8*)entry + 4) = copy;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::ParticleList(int, EGEPackedParticle*)
// Address: 0x802F7078, Size: 188
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::ParticleList(int count, EGEPackedParticle* particles) {
    if (count == 0) return;
    void* copy = AllocAndCopy((void*)particles, count * 16);
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 2, 3); }
    void* dl = *(void**)((u8*)this + 0x00);
    *(u32*)((u8*)dl + 0x54) += count;
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x03; // command 3
    *(void**)((u8*)entry + 4) = copy;
    *(u32*)((u8*)entry + 8) = 0; // padding/flags
    *(u16*)((u8*)entry + 2) = (u16)count;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::LineStreakList(int, EVec4&, EVec4&, EGELineStreak*)
// Address: 0x802F7134, Size: 256
// NON_MATCHING: vtable dispatch pattern, many alloc calls
//=============================================================================
// Complex primitive with multiple buffer copies - deferred

//=============================================================================
// ERC::ParticleListRot(int, EGEPackedParticle*)
// Address: 0x802F7234, Size: 188
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::ParticleListRot(int count, EGEPackedParticle* particles) {
    if (count == 0) return;
    void* copy = AllocAndCopy((void*)particles, count * 16);
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 2, 3); }
    void* dl = *(void**)((u8*)this + 0x00);
    *(u32*)((u8*)dl + 0x54) += count;
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x04; // command 4
    *(void**)((u8*)entry + 4) = copy;
    *(u32*)((u8*)entry + 8) = 0;
    *(u16*)((u8*)entry + 2) = (u16)count;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::AddDisplayListReference(EDL*)
// Address: 0x802F72F0, Size: 68
// NON_MATCHING: bl target
//=============================================================================
void ERC::AddDisplayListReference(EDL* dl) {
    void* dlPtr = *(void**)((u8*)this + 0x00);
    EDL_AddRef(dlPtr, (void*)((u8*)dlPtr + 0x30));
}

//=============================================================================
// ERC::DisplayList(EDL*)
// Address: 0x802F7334, Size: 216
// NON_MATCHING: vtable dispatch, bl targets
//=============================================================================
// Complex: handles nested display lists, uses AddDisplayListReference

//=============================================================================
// ERC::ShrinkSmallDisplayList(void)
// Address: 0x802F740C, Size: 180
// NON_MATCHING: vtable dispatch
//=============================================================================
// Releases unused DL memory

//=============================================================================
// ERC::Terminate(void)
// Address: 0x802F74C0, Size: 184
// NON_MATCHING: vtable dispatch, bl targets
//=============================================================================
// Terminates the render context, frees resources

//=============================================================================
// ERC::Viewport(EViewport*)
// Address: 0x802F7578, Size: 148
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::Viewport(EViewport* vp) {
    void* copy = AllocAndCopy((void*)vp, 32);
    void** vt = *(void***)((u8*)this + 0x70);
    // BeginPrimitive(0, 0)
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    // NewEntry(1)
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x09; // command 9 = Viewport
    *(void**)((u8*)entry + 4) = copy;
    // EndPrimitive
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::ClipRect(TRect<float>&)
// Address: 0x802F760C, Size: 168
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::ClipRect(TRect<float>& rect) {
    void** vt = *(void***)((u8*)this + 0x70);
    // BeginPrimitive(0, 0)
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    // NewEntry(3)
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 3); }
    *(u8*)entry = 0x36; // command 54 = ClipRect
    // Copy 4 floats from rect
    *(float*)((u8*)entry + 8) = rect.left;
    *(float*)((u8*)entry + 12) = rect.top;
    *(float*)((u8*)entry + 16) = rect.right;
    *(float*)((u8*)entry + 20) = rect.bottom;
    // EndPrimitive
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::Scissor(TRect<float>*)
// Address: 0x802F76B4, Size: 148
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::Scissor(TRect<float>* rect) {
    void* copy = AllocAndCopy((void*)rect, 16);
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x0B; // command 11 = Scissor
    *(void**)((u8*)entry + 4) = copy;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::ModelMatrixList(EMat4*, int)
// Address: 0x802F7748, Size: 168
// NON_MATCHING: vtable dispatch, memcpy pattern
//=============================================================================
// Allocates matrix storage, copies matrices, sets dirty flags

//=============================================================================
// ERC::ModelMatrixIndex(int, int)
// Address: 0x802F77F0, Size: 124
// NON_MATCHING: vtable dispatch
//=============================================================================
// Sets model matrix index, updates max index tracking

//=============================================================================
// ERC::ModelMatrices(EMat4*, int)
// Address: 0x802F786C, Size: 148
// NON_MATCHING: vtable dispatch
//=============================================================================
// Dispatches through vtable to set model matrices

//=============================================================================
// ERC::ViewMatrix(EMat4*, int, float)
// Address: 0x802F7A44, Size: 148
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::ViewMatrix(EMat4* mat, int mode, float param) {
    void* copy = AllocAndCopy((void*)mat, 64);
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 2); }
    *(u8*)entry = 0x0D; // command 13 = ViewMatrix
    *(u8*)((u8*)entry + 1) = (u8)mode;
    *(void**)((u8*)entry + 4) = copy;
    *(float*)((u8*)entry + 8) = param;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::ProjectionMatrix(EMat4*)
// Address: 0x802F7AD8, Size: 148
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::ProjectionMatrix(EMat4* mat) {
    void* copy = AllocAndCopy((void*)mat, 64);
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x0E; // command 14 = ProjectionMatrix
    *(void**)((u8*)entry + 4) = copy;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::WindowMatrix(EMat4*)
// Address: 0x802F7B6C, Size: 148
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::WindowMatrix(EMat4* mat) {
    void* copy = AllocAndCopy((void*)mat, 64);
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x0F; // command 15 = WindowMatrix
    *(void**)((u8*)entry + 4) = copy;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::Texture(ETexture*, int)
// Address: 0x802F7C00, Size: 172
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::Texture(ETexture* tex, int slot) {
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x11; // command 17 = Texture
    *(u8*)((u8*)entry + 1) = (u8)slot;
    *(void**)((u8*)entry + 4) = (void*)tex;
    if (tex != 0) {
        void* dl = *(void**)((u8*)this + 0x00);
        EDL_AddRef((void*)((u8*)dl + 0x30), (void*)tex);
    }
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::EnableGeometryModes(unsigned int)
// Address: 0x802F7CAC, Size: 140
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::EnableGeometryModes(unsigned int modes) {
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x12; // command 18 = EnableGeometryModes
    *(u32*)((u8*)entry + 4) = modes;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::DisableGeometryModes(unsigned int)
// Address: 0x802F7D38, Size: 144
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::DisableGeometryModes(unsigned int modes) {
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x13; // command 19 = DisableGeometryModes
    *(u32*)((u8*)entry + 4) = modes;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::SetGeometryModes(unsigned int)
// Address: 0x802F7DC8, Size: 140
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::SetGeometryModes(unsigned int modes) {
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x14; // command 20 = SetGeometryModes
    *(u32*)((u8*)entry + 4) = modes;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::EnableRasterModes(unsigned int, int)
// Address: 0x802F7E54, Size: 148
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::EnableRasterModes(unsigned int modes, int pass) {
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x15; // command 21 = EnableRasterModes
    *(u32*)((u8*)entry + 4) = modes;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::DisableRasterModes(unsigned int, int)
// Address: 0x802F7EE8, Size: 152
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::DisableRasterModes(unsigned int modes, int pass) {
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x16; // command 22 = DisableRasterModes
    *(u32*)((u8*)entry + 4) = modes;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::SetRasterModes(unsigned int, int)
// Address: 0x802F7F80, Size: 148
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::SetRasterModes(unsigned int modes, int pass) {
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x17; // command 23 = SetRasterModes
    *(u32*)((u8*)entry + 4) = modes;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::SaveState(void)
// Address: 0x802F8014, Size: 132
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::SaveState() {
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x1D; // command 29 = SaveState
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::RestoreState(void)
// Address: 0x802F8098, Size: 132
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::RestoreState() {
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x1E; // command 30 = RestoreState
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::Lights(ELights*)
// Address: 0x802F811C, Size: 188
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::Lights(ELights* lights) {
    void* copy = AllocAndCopy((void*)lights, 272);
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x1F; // command 31 = Lights
    *(void**)((u8*)entry + 4) = copy;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::Material(EMaterial*)
// Address: 0x802F81D8, Size: 148
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::Material(EMaterial* mat) {
    void* copy = AllocAndCopy((void*)mat, 48);
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x20; // command 32 = Material
    *(void**)((u8*)entry + 4) = copy;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::SetMipMap(float, int)
// Address: 0x802F8270, Size: 156
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::SetMipMap(float mipLevel, int mode) {
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 2); }
    *(u8*)entry = 0x21; // command 33 = SetMipMap
    *(float*)((u8*)entry + 4) = mipLevel;
    *(u32*)((u8*)entry + 8) = (u32)mode;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::Callback(void (*)(unsigned int, unsigned short, unsigned char), unsigned int, unsigned short, unsigned char)
// Address: 0x802F830C, Size: 200
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::Callback(void (*fn)(unsigned int, unsigned short, unsigned char), unsigned int a, unsigned short b, unsigned char c) {
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn2 = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn2)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn2 = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn2)((u8*)this + off, 2); }
    *(u8*)entry = 0x24; // command 36 = Callback
    *(void**)((u8*)entry + 4) = (void*)fn;
    *(u32*)((u8*)entry + 8) = a;
    *(u16*)((u8*)entry + 12) = b;
    *(u8*)((u8*)entry + 14) = c;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn2 = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn2)((u8*)this + off); }
}

//=============================================================================
// ERC::RectList(int, float*, EVec4&, float)
// Address: 0x802F83D4, Size: 228
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
// Complex: copies float data, EVec4, sets command 0x25

//=============================================================================
// ERC::RectListRot(int, float*, EVec4&, float)
// Address: 0x802F84B8, Size: 220
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
// Complex: copies float data, EVec4, sets command 0x26

//=============================================================================
// ERC::DirectRect(EVec2&, EVec2&, EVec4&, float)
// Address: 0x802F87A4, Size: 224
// NON_MATCHING: vtable dispatch pattern, float copies
//=============================================================================
// Complex: copies 2 EVec2 + EVec4 + float into entry

//=============================================================================
// ERC::EnvironmentMap(bool, bool, int)
// Address: 0x802F8884, Size: 148
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::EnvironmentMap(bool enable, bool flag2, int param) {
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x2A; // command 42 = EnvironmentMap
    *(u8*)((u8*)entry + 1) = (u8)enable;
    *(u8*)((u8*)entry + 2) = (u8)flag2;
    *(u32*)((u8*)entry + 4) = (u32)param;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::RecalcMatrices(int, int)
// Address: 0x802F8A30, Size: 148
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::RecalcMatrices(int a, int b) {
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x2B; // command 43 = RecalcMatrices
    *(u32*)((u8*)entry + 4) = (u32)a;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::Debug(unsigned int, unsigned int)
// Address: 0x802F8AC4, Size: 148
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::Debug(unsigned int a, unsigned int b) {
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x2C; // command 44 = Debug
    *(u32*)((u8*)entry + 4) = a;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::GeometrySetup(void)
// Address: 0x802F8B58, Size: 132
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::GeometrySetup() {
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x2D; // command 45 = GeometrySetup
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::ZTest(bool, int, int, int)
// Address: 0x802F8BDC, Size: 164
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::ZTest(bool enable, int compareFunc, int refValue, int pass) {
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x2E; // command 46 = ZTest
    *(u8*)((u8*)entry + 1) = (u8)enable;
    *(u8*)((u8*)entry + 2) = (u8)compareFunc;
    *(u8*)((u8*)entry + 3) = (u8)refValue;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::AlphaTest(bool, int, float, int)
// Address: 0x802F8C80, Size: 196
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::AlphaTest(bool enable, int mode, float threshold, int pass) {
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 2); }
    *(u8*)entry = 0x2F; // command 47 = AlphaTest
    *(u8*)((u8*)entry + 1) = (u8)enable;
    *(u8*)((u8*)entry + 2) = (u8)mode;
    *(float*)((u8*)entry + 4) = threshold;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::Stencil(int, int, int)
// Address: 0x802F8D44, Size: 156
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::Stencil(int a, int b, int c) {
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 2); }
    *(u8*)entry = 0x30; // command 48 = Stencil
    *(u32*)((u8*)entry + 4) = (u32)a;
    *(u32*)((u8*)entry + 8) = (u32)b;
    *(u32*)((u8*)entry + 12) = (u32)c;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::SetBlendMode(int, int, int, int, float, int)
// Address: 0x802F8DE8, Size: 220
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::SetBlendMode(int src, int dst, int op, int logic, float alpha, int pass) {
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 2); }
    // Pack blend mode into entry
    u32 packed = (src & 3) | ((dst & 3) << 2) | ((op & 3) << 4) | ((logic & 3) << 6);
    // Alpha converted to u8 and stored at byte 24
    u8 alphaByte = (u8)(alpha * 255.0f);
    packed |= ((u32)alphaByte << 24);
    *(u8*)entry = 0x32; // command 50 = SetBlendMode
    *(u32*)((u8*)entry + 4) = packed;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::SetCombineMode(int, int)
// Address: 0x802F8ECC, Size: 148
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::SetCombineMode(int stage, int mode) {
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x33; // command 51 = SetCombineMode
    *(u16*)((u8*)entry + 2) = (u16)stage;
    *(u32*)((u8*)entry + 4) = (u32)mode;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::RenderSurface(ERenderSurface*, int)
// Address: 0x802F8F60, Size: 148
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::RenderSurface(ERenderSurface* surface, int param) {
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x34; // command 52 = RenderSurface
    *(u8*)((u8*)entry + 1) = (u8)param;
    *(void**)((u8*)entry + 4) = (void*)surface;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::SaveImageData(ERenderSurface*)
// Address: 0x802F8FF4, Size: 140
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::SaveImageData(ERenderSurface* surface) {
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x35; // command 53 = SaveImageData
    *(void**)((u8*)entry + 4) = (void*)surface;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::Vertex(int, int, float*, float*, unsigned char*, signed char*, unsigned char*)
// Address: 0x802F9080, Size: 208
// NON_MATCHING: vtable dispatch pattern, multiple AllocAndCopy
//=============================================================================
// Complex: copies multiple vertex attribute arrays into DL

//=============================================================================
// ERC::TriIndexed(int, unsigned char*)
// Address: 0x802F9150, Size: 148
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::TriIndexed(int count, unsigned char* indices) {
    void* copy = AllocAndCopy((void*)indices, count);
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x37; // command 55 = TriIndexed
    *(u32*)((u8*)entry + 4) = (u32)count;
    *(void**)((u8*)entry + 8) = copy;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::Noop(void)
// Address: 0x802F91E4, Size: 132
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::Noop() {
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x39; // command 57 = Noop
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::MovieFrame(EMovie*)
// Address: 0x802F9678, Size: 140
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::MovieFrame(EMovie* movie) {
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x3A; // command 58 = MovieFrame
    *(void**)((u8*)entry + 4) = (void*)movie;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::SetAlpha(float)
// Address: 0x802F9704, Size: 148
// NON_MATCHING: vtable dispatch pattern
//=============================================================================
void ERC::SetAlpha(float alpha) {
    void** vt = *(void***)((u8*)this + 0x70);
    { s16 off = *(s16*)((u8*)vt + 0x2B0); void* fn = *(void**)((u8*)vt + 0x2B4);
      ((void(*)(void*,int,int))fn)((u8*)this + off, 0, 0); }
    EDLEntry* entry;
    { s16 off = *(s16*)((u8*)vt + 0x2A8); void* fn = *(void**)((u8*)vt + 0x2AC);
      entry = ((EDLEntry*(*)(void*,int))fn)((u8*)this + off, 1); }
    *(u8*)entry = 0x3B; // command 59 = SetAlpha
    *(float*)((u8*)entry + 4) = alpha;
    { s16 off = *(s16*)((u8*)vt + 0x2B8); void* fn = *(void**)((u8*)vt + 0x2BC);
      ((void(*)(void*))fn)((u8*)this + off); }
}

//=============================================================================
// ERC::AllocAndCopy(void*, int)
// Address: 0x802F9958, Size: 92
// NON_MATCHING: bl target
//=============================================================================
void* ERC::AllocAndCopy(void* data, int size) {
    void* mem = Alloc((u32)size, 32);
    if (mem != 0 && data != 0) {
        memcpy_wrapper(mem, data, (u32)size);
    }
    return mem;
}

//=============================================================================
// __static_initialization_and_destruction_0 (e_rc.obj)
// Address: 0x802F9A10, Size: 112
// NON_MATCHING: SDA pattern, bl targets
//=============================================================================
// Global ctor/dtor pair for ERC statics

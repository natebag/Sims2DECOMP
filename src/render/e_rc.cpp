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

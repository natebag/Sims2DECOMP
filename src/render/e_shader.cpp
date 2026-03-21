// e_shader.cpp - EShader class (shader system)
// Part of the Sims 2 GC decompilation
// Original: engine_ngc_release_dvd.lib(e_shader.obj)
//
// Small functions (<=64 bytes) decompiled from the e_shader object file.

#include "render/e_shader.h"

// External functions
extern void* PoolAlloc(void* pool, void* item, u32 size);
extern void PoolFree(void* pool, void* item);
extern void EShader_EShader_InitHelper(int active, int type);
extern void ERC_Release(void* rc);

// Pool global
static void* s_shaderPool = (void*)0x804BBBDCu; // NON_MATCHING: address is link-time

//=============================================================================
// EShader::UseOverrideTexture
// Address: 0x802FA438, Size: 60
// Checks flag 0x0400_0000, validates texture index, sets override
//=============================================================================
bool EShader::UseOverrideTexture(unsigned char index) {
    u32 flags = *(u32*)((u8*)this + 0x04);
    if (!(flags & 0x04000000)) {
        return false;
    }
    u8 texCount = *(u8*)((u8*)this + 0x88);
    if (index >= texCount) {
        return false;
    }
    // Set override flag and store index
    flags |= 0x02000000;
    *(u8*)((u8*)this + 0xEC) = index;
    *(u32*)((u8*)this + 0x04) = flags;
    return true;
}

//=============================================================================
// EShader::SelectForShadowMask
// Address: 0x802FA9AC, Size: 56
// Dispatches through this->0xF0 vtable offset 0x10/0x14
// NON_MATCHING: vtable dispatch
//=============================================================================
void EShader::SelectForShadowMask(ERC* rc) {
    void** vtable = *(void***)((u8*)this + 0xF0);
    s16 thunkOff = *(s16*)((u8*)vtable + 0x10);
    void* fn = *(void**)((u8*)vtable + 0x14);
    void* thisPtr = (void*)((u8*)this + thunkOff);
    typedef void (*Fn)(void*, ERC*, int);
    ((Fn)fn)(thisPtr, rc, 0);
}

//=============================================================================
// EShader::SetShadowAlpha
// Address: 0x802FA9E4, Size: 4
//=============================================================================
void EShader::SetShadowAlpha(float) {
    // Empty stub
}

//=============================================================================
// EShader::operator new
// Address: 0x802FAA4C, Size: 48
// Allocates from shader pool
// NON_MATCHING: pool address, bl target
//=============================================================================
void* EShader::operator new(u32 size) {
    return PoolAlloc(s_shaderPool, (void*)(unsigned long)size, 8);
}

//=============================================================================
// EShader::operator delete
// Address: 0x802FAA7C, Size: 44
// Frees to shader pool
// NON_MATCHING: pool address, bl target
//=============================================================================
void EShader::operator delete(void* ptr) {
    PoolFree(s_shaderPool, ptr);
}

//=============================================================================
// EShader::Select
// Address: 0x802FAAA8, Size: 4
//=============================================================================
void EShader::Select(ERC*, unsigned int) {
    // Empty stub
}

//=============================================================================
// EShader::GetMaterial
// Address: 0x802FAAAC, Size: 8
// Returns this + 0x10
//=============================================================================
void* EShader::GetMaterial() const {
    return (void*)((u8*)this + 0x10);
}

//=============================================================================
// EShader::SetSurfaceProperty
// Address: 0x802FAAB4, Size: 16
// ORs flag into this->m_flags
//=============================================================================
void EShader::SetSurfaceProperty(unsigned int prop) {
    u32 flags = *(u32*)((u8*)this + 0x04);
    flags |= prop;
    *(u32*)((u8*)this + 0x04) = flags;
}

//=============================================================================
// EShader::ClearSurfaceProperty
// Address: 0x802FAAC4, Size: 16
// ANDCs flag from this->m_flags
//=============================================================================
void EShader::ClearSurfaceProperty(unsigned int prop) {
    u32 flags = *(u32*)((u8*)this + 0x04);
    flags &= ~prop;
    *(u32*)((u8*)this + 0x04) = flags;
}

//=============================================================================
// EShader::IsSurface
// Address: 0x802FAAD4, Size: 24
// Tests if flag is set in m_flags
//=============================================================================
bool EShader::IsSurface(unsigned int prop) const {
    u32 flags = *(u32*)((u8*)this + 0x04);
    if (flags & prop) {
        return true;
    }
    return false;
}

//=============================================================================
// EShader::GetSurfaceProperties
// Address: 0x802FAAEC, Size: 8
// Returns this->m_flags
//=============================================================================
u32 EShader::GetSurfaceProperties() const {
    return *(u32*)((u8*)this + 0x04);
}

//=============================================================================
// EShader::CanColorBeModified
// Address: 0x802FAAF4, Size: 20
// Checks bits in m_shaderData and m_flags
// Returns (m_flags[0x74] | m_shaderData[0xB4]) >> 27 & 1
//=============================================================================
bool EShader::CanColorBeModified() const {
    u32 shaderData = *(u32*)((u8*)this + 0xB4);
    u32 geomFlags = *(u32*)((u8*)this + 0x74);
    return ((geomFlags | shaderData) >> 27) & 1;
}

//=============================================================================
// EShader::GetModifiableColor
// Address: 0x802FAB08, Size: 16
// Returns pointer at this + 0x40 + index * 4
//=============================================================================
void* EShader::GetModifiableColor(unsigned int index) const {
    u32 offset = index * 4;
    return (void*)*((u32*)((u8*)this + 0x40) + index);
}

//=============================================================================
// EShader::SetTexture
// Address: 0x802FAB18, Size: 16
// Stores texture at this + 0x64 + slot * 64
//=============================================================================
void EShader::SetTexture(ETexture* tex, int slot) {
    u32 offset = (u32)slot * 64;
    *(ETexture**)((u8*)this + 0x64 + offset) = tex;
}

//=============================================================================
// EShader::SetMultiTexture
// Address: 0x802FAB28, Size: 16
// Stores texture via this->0x68 array indexed by slot
//=============================================================================
void EShader::SetMultiTexture(ETexture* tex, int slot) {
    u32* texArray = *(u32**)((u8*)this + 0x68);
    u32 offset = (u32)slot * 4;
    *(ETexture**)((u8*)texArray + offset) = tex;
}

//=============================================================================
// EShader::UndoOverrideTexture
// Address: 0x802FAB38, Size: 16
// Clears bit 6 from m_flags (mask off bit at position 6)
// rlwinm r0,r0,0,7,5 => clear bit 6
//=============================================================================
void EShader::UndoOverrideTexture() {
    u32 flags = *(u32*)((u8*)this + 0x04);
    flags &= ~(1 << 25); // clear bit 25 (0x02000000)
    *(u32*)((u8*)this + 0x04) = flags;
}

//=============================================================================
// EShader::SetAlternateShader
// Address: 0x802FAB48, Size: 4
//=============================================================================
void EShader::SetAlternateShader(EShader*) {
    // Empty stub
}

//=============================================================================
// EShader::GetShaderDef
// Address: 0x802FAB4C, Size: 4
//=============================================================================
EShaderDef* EShader::GetShaderDef() const {
    // Empty stub - just blr
    return 0;
}

//=============================================================================
// EShader::IsFacer
// Address: 0x802FAB50, Size: 24
// Tests bits 2-3 (0x0C) of m_flags
//=============================================================================
bool EShader::IsFacer() const {
    u32 flags = *(u32*)((u8*)this + 0x04);
    if (flags & 0x0C) {
        return true;
    }
    return false;
}

//=============================================================================
// EShader::IsCylindricalFacer
// Address: 0x802FAB68, Size: 12
// Returns bit 29 of m_flags (bit 3 from LSB = 0x08 >> 3)
// rlwinm r3,r3,29,31,31
//=============================================================================
bool EShader::IsCylindricalFacer() const {
    u32 flags = *(u32*)((u8*)this + 0x04);
    return (flags >> 3) & 1;
}

//=============================================================================
// EShader::GetShaderUpdate
// Address: 0x802FAB74, Size: 8
// Returns this->0xE8
//=============================================================================
EShaderUpdate* EShader::GetShaderUpdate() const {
    return *(EShaderUpdate**)((u8*)this + 0xE8);
}

//=============================================================================
// EShader::SetAlphaTestThreshold
// Address: 0x802FABC0, Size: 16
// Stores float at this + 0x78 + pass * 64
//=============================================================================
void EShader::SetAlphaTestThreshold(float threshold, int pass) {
    u32 offset = (u32)pass * 64;
    *(float*)((u8*)this + 0x78 + offset) = threshold;
}

//=============================================================================
// EShader::UpdateMaterialCoefficients
// Address: 0x802FABD0, Size: 4
//=============================================================================
void EShader::UpdateMaterialCoefficients() {
    // Empty stub
}

//=============================================================================
// EShader::IsValid
// Address: 0x802FABD4, Size: 28
// Checks m_magic against 0x900DBEEF
//=============================================================================
bool EShader::IsValid() {
    u32 magic = *(u32*)((u8*)this + 0xE4);
    u32 check = magic ^ 0x900DBEEFu;
    // subfic r0,r3,0; adde r3,r0,r3 => (check == 0 ? 1 : 0)
    // This is the "is zero" pattern
    return (check == 0);
}

//=============================================================================
// EShader::RemoveGeometryModes
// Address: 0x802FABF0, Size: 4
//=============================================================================
void EShader::RemoveGeometryModes(unsigned int) {
    // Empty stub
}

//=============================================================================
// EShader::AddGeometryModes
// Address: 0x802FABF4, Size: 4
//=============================================================================
void EShader::AddGeometryModes(unsigned int) {
    // Empty stub
}

//=============================================================================
// global constructors keyed to EShader::EShader(void)
// Address: 0x802FABF8, Size: 44
// Calls EShader_EShader_InitHelper(1, 0xFFFF)
// NON_MATCHING: bl target
//=============================================================================
static void __sinit_e_shader_cpp() {
    EShader_EShader_InitHelper(1, 0xFFFF);
}

//=============================================================================
// global destructors keyed to EShader::EShader(void)
// Address: 0x802FAC24, Size: 44
// Calls EShader_EShader_InitHelper(0, 0xFFFF)
// NON_MATCHING: bl target
//=============================================================================
// Note: destructor handled by __destroy_global_chain


// ============================================================================
// e_window.obj functions
// ============================================================================

// Forward declarations for EWindow
class EWindow;
class E3DWindow;

extern EWindow* EWindow_m_pCurrentWindow;
extern E3DWindow* EWindow_m_pCurrent3DWindow;
extern void EWindow_InitHelper(int active, int type);

// Transform matrix struct (matches offsets 0x00, 0x14, 0x30, 0x34)
// m_scaleX at 0x00, m_scaleY at 0x14, m_offsetX at 0x30, m_offsetY at 0x34
struct EWindowTransform {
    float m_scaleX;       // 0x00
    u8 pad04[0x10];       // 0x04
    float m_scaleY;       // 0x14
    u8 pad18[0x18];       // 0x18
    float m_offsetX;      // 0x30
    float m_offsetY;      // 0x34
    u8 pad38[0x28];       // 0x38
    float m_clipLeft;     // 0x60
    float m_clipTop;      // 0x64
    float m_clipRight;    // 0x68
    float m_clipBottom;   // 0x6C
};

//=============================================================================
// EWindow::TransformToPixel
// Address: 0x80300330, Size: 44
// out.x = in.x * scaleX + offsetX
// out.y = in.y * scaleY + offsetY
//=============================================================================
// EWindow is really an EWindowTransform embedded, so this = transform matrix

//=============================================================================
// EWindow::Transform (EVec2&, EVec2&)
// Address: 0x80300924, Size: 44
// Same math as TransformToPixel
//=============================================================================

//=============================================================================
// EWindow::Transform (float, float, float&, float&)
// Address: 0x80300950, Size: 36
// out1 = in1 * scaleX + offsetX
// out2 = in2 * scaleY + offsetY
//=============================================================================

//=============================================================================
// EWindow::TransformInv (EVec2&, EVec2&)
// Address: 0x80300974, Size: 52
// out.x = (in.x - offsetX) / scaleX
// out.y = (in.y - offsetY) / scaleY
//=============================================================================

//=============================================================================
// EWindow::TransformInv (float, float, float&, float&)
// Address: 0x803009A8, Size: 44
// out1 = (in1 - offsetX) / scaleX
// out2 = (in2 - offsetY) / scaleY
//=============================================================================

//=============================================================================
// EWindow::TransformScale (float, float, float&, float&)
// Address: 0x803009D4, Size: 28
// out1 = in1 * scaleX
// out2 = in2 * scaleY
//=============================================================================

//=============================================================================
// EWindow::TransformScale (EVec2&, EVec2&)
// Address: 0x803009F0, Size: 36
// out.x = in.x * scaleX
// out.y = in.y * scaleY
//=============================================================================

//=============================================================================
// EWindow::ClipTest
// Address: 0x80300A14, Size: 40
// Loads EVec2 from input, calls internal clip test
// NON_MATCHING: bl to internal function
//=============================================================================

//=============================================================================
// EWindow::GetCurrentWindow
// Address: 0x80300AE8, Size: 8
// Returns static m_pCurrentWindow from r13 SDA
//=============================================================================

//=============================================================================
// EWindow::GetCurrent3DWindow
// Address: 0x80300AF0, Size: 8
// Returns static m_pCurrent3DWindow from r13 SDA
//=============================================================================

//=============================================================================
// EWindow::WindowMatrixChanged
// Address: 0x80300AF8, Size: 4
//=============================================================================

//=============================================================================
// EWindow::InputCoordinatesChanged
// Address: 0x80300AFC, Size: 4
//=============================================================================

//=============================================================================
// EWindow::OutputCoordinatesChanged
// Address: 0x80300B00, Size: 4
//=============================================================================

//=============================================================================
// EWindow::Cast3DWindow
// Address: 0x80300B04, Size: 8
// Returns 0 (null)
//=============================================================================

//=============================================================================
// EWindow::operator new
// Address: 0x8030082C, Size: 64
// NON_MATCHING: bl targets
//=============================================================================

//=============================================================================
// EWindow::operator delete
// Address: 0x8030086C, Size: 52
// NON_MATCHING: bl targets
//=============================================================================

//=============================================================================
// EWindow::SetInputCoordinatesAndClip
// Address: 0x803008A0, Size: 60
// NON_MATCHING: bl targets
//=============================================================================

//=============================================================================
// global constructors keyed to EWindow::m_pCurrentWindow
// Address: 0x80300B0C, Size: 44
// Calls EWindow_InitHelper(1, 0xFFFF)
// NON_MATCHING: bl target
//=============================================================================


// ============================================================================
// background.obj functions
// ============================================================================

// Background vtable address placeholder
// Background ctor sets vtable to 0x8046A5D0

//=============================================================================
// Background::Background
// Address: 0x802E1BFC, Size: 20
// Sets vtable pointer
// NON_MATCHING: vtable address
//=============================================================================

//=============================================================================
// Background::~Background
// Address: 0x802E1C10, Size: 52
// Sets vtable, conditionally calls operator delete
// NON_MATCHING: vtable address, bl target
//=============================================================================

//=============================================================================
// BackgroundImpl::Update
// Address: 0x802E1E50, Size: 4
//=============================================================================

//=============================================================================
// BackgroundImpl::SendCommand
// Address: 0x802E1F00, Size: 40
// Calls queue push at this+0x368
// NON_MATCHING: bl target
//=============================================================================

//=============================================================================
// BackgroundImpl::IsCallingThread
// Address: 0x802E2104, Size: 36
// Checks thread at this+0x08
// NON_MATCHING: bl target
//=============================================================================


// ============================================================================
// e_3dwindow.obj functions
// ============================================================================

//=============================================================================
// E3DWindow::Cast3DWindow
// Address: 0x802E76A4, Size: 4
// Returns this (just blr since this is already in r3)
//=============================================================================

//=============================================================================
// E3DWindow::GetLookPos
// Address: 0x802E767C, Size: 8
// Returns this + 0x280
//=============================================================================

//=============================================================================
// E3DWindow::GetLookDir
// Address: 0x802E7684, Size: 8
// Returns this + 0x290
//=============================================================================

//=============================================================================
// E3DWindow::GetLookAt
// Address: 0x802E768C, Size: 8
// Returns this + 0xA0
//=============================================================================

//=============================================================================
// E3DWindow::GetProjection
// Address: 0x802E7694, Size: 8
// Returns this + 0x160
//=============================================================================

//=============================================================================
// E3DWindow::GetNormalizedProjection
// Address: 0x802E769C, Size: 8
// Returns this + 0x1E0
//=============================================================================

//=============================================================================
// E3DWindow::InputCoordinatesChanged
// Address: 0x802E60A0, Size: 32
// Calls parent function at 0x802E4760
// NON_MATCHING: bl target
//=============================================================================

//=============================================================================
// E3DWindow::OutputCoordinatesChanged
// Address: 0x802E60C0, Size: 32
// Calls parent function at 0x802E46FC
// NON_MATCHING: bl target
//=============================================================================


// ============================================================================
// e_submodel.obj functions
// ============================================================================

//=============================================================================
// ESubModel::ESubModel
// Address: 0x802FAC50, Size: 56
// Calls parent constructor, sets m_pad14 = 0
// NON_MATCHING: bl target
//=============================================================================

//=============================================================================
// ESubModel::GetCompositeShaderFlags
// Address: 0x802FAE20, Size: 8
// Returns 0
//=============================================================================

//=============================================================================
// operator>>(EStream&, ESubModel&)
// Address: 0x802FAE28, Size: 4
// Empty stub
//=============================================================================


// ============================================================================
// e_submodelshader.obj functions
// ============================================================================

//=============================================================================
// VertexDataInitialization
// Address: 0x802FBA24, Size: 4
// Empty stub
//=============================================================================

//=============================================================================
// VertexDataDeinitialization
// Address: 0x802FBA28, Size: 4
// Empty stub
//=============================================================================

//=============================================================================
// ESubModelShader::VertexDataAllocation
// Address: 0x802FBA2C, Size: 56
// NON_MATCHING: vtable dispatch via gpEGraphics
//=============================================================================

//=============================================================================
// ESubModelShader::VertexDataDeallocation
// Address: 0x802FBA64, Size: 64
// NON_MATCHING: vtable dispatch via gpEGraphics
//=============================================================================

//=============================================================================
// ESubModelShader::MorphDataAllocation
// Address: 0x802FBAA4, Size: 40
// Allocates from pool
// NON_MATCHING: pool address, bl target
//=============================================================================

//=============================================================================
// ESubModelShader::MorphDataDeallocation
// Address: 0x802FBACC, Size: 40
// Frees to pool
// NON_MATCHING: pool address, bl target
//=============================================================================

//=============================================================================
// ESubModelShader::DelRefSubResources
// Address: 0x802FBBC8, Size: 64
// Frees vertex buffer at offset 0x08 if non-null
// NON_MATCHING: bl target
//=============================================================================

//=============================================================================
// ESubModelShader::DrawNormals
// Address: 0x802FD24C, Size: 4
// Empty stub
//=============================================================================

//=============================================================================
// ESubModelShader::DrawWireFrame
// Address: 0x802FD250, Size: 4
// Empty stub
//=============================================================================

//=============================================================================
// ESubModelShader::MorphBreakUpStrip
// Address: 0x802FD254, Size: 4
// Empty stub
//=============================================================================

//=============================================================================
// ESubModelShader::UnRegisterMorphTarget
// Address: 0x802FD3E8, Size: 20
// Clears morph target at index: this + 0x38 + index * 4 = 0
//=============================================================================

//=============================================================================
// ESubModelShader::CanColorBeModified
// Address: 0x802FF7D0, Size: 64
// Checks shader at offset 0x08, then checks shader's shader at 0x14/0x18
// Returns (flags[0x74] | flags[0xB4]) >> 27 & 1
//=============================================================================

//=============================================================================
// ESubModelShader::GetModifiableColor
// Address: 0x802FF810, Size: 52
// Like CanColorBeModified but returns color pointer at shader + 0x40 + index * 4
//=============================================================================

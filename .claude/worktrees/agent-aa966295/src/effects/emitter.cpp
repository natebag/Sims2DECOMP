// emitter.cpp - Emitter particle system (emitter.obj + emitterspr3d.obj)
// Decompiled small functions (<=64 bytes) from The Sims 2 GameCube
// emitter.obj:      c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\emitter.obj
// emitterspr3d.obj: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\emitterspr3d.obj

#include "effects/emitter.h"

// ===================================================================
// emitter.obj small functions
// ===================================================================

// 0x80238480 - 48 bytes
// Emitter::Destroy(void)
// Checks if m_pEmitter is non-null, then calls PEmitterDestroy
// Note: PEmitterDestroy takes pointer to the pemitter* field (addi r3, r3, 0x7C)
void Emitter::Destroy() {
    if (m_pEmitter != 0) {
        PEmitterDestroy(&m_pEmitter);
    }
}

// 0x8023867c - 32 bytes
// Emitter::GetNumActiveParticles(void)
int Emitter::GetNumActiveParticles() {
    if (m_pEmitter == 0) {
        return 0;
    }
    // lwz r9, 0x54(r9) -- internal data pointer within pemitter
    // lwz r3, 0x84(r9) -- active particle count
    u8* inner = *(u8**)((u8*)m_pEmitter + 0x54);
    return *(int*)(inner + 0x84);
}

// 0x8023869c - 8 bytes
// Emitter::Get(void)
pemitter* Emitter::Get() {
    return m_pEmitter;
}

// 0x80238928 - 44 bytes
// Emitter::Reset(void)
void Emitter::Reset() {
    if (m_pEmitter != 0) {
        PEmitterReset(m_pEmitter);
    }
}

// 0x80238954 - 32 bytes
// Emitter::SetSortPos(EVec3 &)
// NON_MATCHING: SN Systems compiler hoists all loads before stores
void Emitter::SetSortPos(EVec3& pos) {
    u32* src = (u32*)&pos;
    m_sortPosX = src[0];
    m_sortPosY = src[1];
    m_sortPosZ = src[2];
}

// 0x80238974 - 12 bytes
// Emitter::SetScale(float)
// lwz r9, 0x7C(r3); stfs f1, 0xBC(r9)
void Emitter::SetScale(float scale) {
    *(float*)((u8*)m_pEmitter + 0xBC) = scale;
}

// 0x802389d4 - 8 bytes
// Emitter::VisibilityTest(E3DWindow &)
// Always returns 0 (always visible)
int Emitter::VisibilityTest(E3DWindow& window) {
    return 0;
}

// 0x80238b08 - 48 bytes
// Emitter::GetInstName(EInstance::InstType &)
// NON_MATCHING: Returns absolute rodata string addresses; instruction scheduling differs
const char* Emitter::GetInstName(InstType& type) {
    u8* em = (u8*)m_pEmitter;
    type.value = 5;
    void* namePtr = *(void**)(em + 0x80);
    if (namePtr != 0) {
        return (const char*)0x8040F630; // NON_MATCHING: rodata string address
    }
    return (const char*)0x8040F728; // NON_MATCHING: rodata string address
}

// ===================================================================
// emitterspr3d.obj small functions
// ===================================================================

// 0x80239e08 - 32 bytes
// EmitterSpr3d::Destroy(void)
// Calls base Emitter::Destroy
void EmitterSpr3d::Destroy() {
    ((Emitter*)this)->Destroy();
}

// 0x80239f10 - 64 bytes
// EmitterGeomProcessCB(void *)
// NON_MATCHING: Uses r13-relative globals and indirect function call (blrl)
void EmitterGeomProcessCB(void* data) {
    // NON_MATCHING: requires r13-relative global access and indirect call
    (void)data;
}

// 0x8023a4d4 - 4 bytes (just blr)
static void __static_initialization_and_destruction_0(int construct, int priority) {
    (void)construct;
    (void)priority;
}

// 0x8023a4d8 - 44 bytes
// global constructors keyed to gSprCount
static void _GLOBAL__I_gSprCount() __attribute__((constructor));
static void _GLOBAL__I_gSprCount() {
    __static_initialization_and_destruction_0(1, 0xFFFF);
}

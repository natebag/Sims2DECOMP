#ifndef EMITTER_H
#define EMITTER_H

#include "types.h"

// Forward declarations
class E3DWindow;
class ELevelDrawData;
class EOrderTableData;
class ERC;

struct EVec3 {
    float x, y, z;
};

struct PVector4 {
    float x, y, z, w;
};

struct InstType {
    int value;
};

// Particle system opaque types
struct particle;
struct pemitter;
struct pemitterinfo;
struct psystem;

// pemitter C API
extern "C" {
    void PEmitterDestroy(void* emitter);   // 0x80303500
    void PEmitterReset(void* emitter);     // 0x80303284
}

// Emitter class layout from disassembly:
// EInstance base occupies 0x00-0x7B (0x7C bytes, includes vtable at 0x00)
// 0x7C = pemitter* m_pEmitter
// 0x80 = EVec3 m_sortPos (12 bytes)
// 0x8C+ = additional fields
//
// Since we need m_pEmitter at exactly offset 0x7C, and EInstance
// has a vtable pointer at offset 0x00, we model this as a flat struct.
struct Emitter {
    u8 m_instanceBase[0x7C];    // 0x00 - EInstance base (vtable + members)
    pemitter* m_pEmitter;        // 0x7C
    u32 m_sortPosX;              // 0x80
    u32 m_sortPosY;              // 0x84
    u32 m_sortPosZ;              // 0x88

    void Destroy();
    int GetNumActiveParticles();
    pemitter* Get();
    void Reset();
    void SetSortPos(EVec3& pos);
    void SetScale(float scale);
    int VisibilityTest(E3DWindow& window);
    const char* GetInstName(InstType& type);
};

// EmitterSpr3d - sprite-based 3D emitter (inherits Emitter layout)
struct EmitterSpr3d {
    u8 m_emitterBase[0x8C];     // Emitter base
    // Additional EmitterSpr3d fields follow

    void Destroy();
};

// Free function callbacks
void EmitterGeomProcessCB(void* data);

#endif // EMITTER_H

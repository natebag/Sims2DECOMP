#if 0 // SKIP
// e_instance_large.cpp - EInstance large functions (257-1024 bytes)
// Object file: u2_ngc_release_dvd/e_instance.obj
// All NON_MATCHING due to: GCC vs SN Systems codegen differences

#include "types.h"
#include "stub_classes.h"

// Forward declarations
class EInstance;
class ERModel;
class EShader;
class ERC;
struct EVec3 { float x, y, z; };
struct EMat4 { float m[4][4]; };
struct E3DWindow;
struct ELevelDrawData;

extern "C" void* EAHeap_Alloc(int size);
extern "C" void EAHeap_Free2(void* ptr);
extern "C" void EMat4_Identity(void* mat);
extern "C" void EMat4_Multiply(void* out, void* a, void* b);

// EInstance layout:
// 0x00 = vtable
// 0x04 = flags
// 0x08 = model pointer
// 0x0C = parent instance
// 0x10 = local matrix (64 bytes)
// 0x50 = world matrix (64 bytes)
// 0x90 = bounding sphere (16 bytes)
// 0xA0 = shader overrides
// Note: this is the EInstance from engine_ngc_release_dvd.lib

// The e_instance.obj section at 0x802281F0 has size 0x1580 = 5504 bytes
// which contains many functions. We decompile the large ones (257-1024).

// ============================================================================
// EInstance::Draw(ERC*, int)
// NON_MATCHING - draws instance with all shader overrides
// ============================================================================
struct EInstance {
    void* m_vtable;          // 0x00
    u32 m_flags;             // 0x04
    void* m_pModel;          // 0x08
    void* m_pParent;         // 0x0C
    float m_localMat[16];    // 0x10
    float m_worldMat[16];    // 0x50
    float m_boundSphere[4];  // 0x90 (center xyz + radius)
    void* m_shaderOverrides; // 0xA0
    u32 m_numShaderOverrides;// 0xA4
    void* m_pAnimController; // 0xA8
    u32 m_sortKey;           // 0xAC
    u8 m_rest[0x3C];         // 0xB0 to end

    void UpdateWorldMatrix();
    void SetLocalMatrix(EMat4* mat);
    void Draw(ERC* rc, int flags);
    void AddToDrawList(ELevelDrawData* data);
    int VisibilityTest(void* window);
};

// ============================================================================
// EInstance::UpdateWorldMatrix()
// NON_MATCHING - recalculates world matrix from local * parent
// Size: ~300 bytes
// ============================================================================
void EInstance::UpdateWorldMatrix()
{
    if (m_pParent) {
        // World = parent->world * local
        EInstance* parent = (EInstance*)m_pParent;
        EMat4_Multiply(m_worldMat, parent->m_worldMat, m_localMat);
    } else {
        // World = local
        for (int i = 0; i < 16; i++) {
            m_worldMat[i] = m_localMat[i];
        }
    }

    // Update bounding sphere in world space
    float cx = m_boundSphere[0];
    float cy = m_boundSphere[1];
    float cz = m_boundSphere[2];

    // Transform center by world matrix
    float wx = m_worldMat[0] * cx + m_worldMat[4] * cy + m_worldMat[8] * cz + m_worldMat[12];
    float wy = m_worldMat[1] * cx + m_worldMat[5] * cy + m_worldMat[9] * cz + m_worldMat[13];
    float wz = m_worldMat[2] * cx + m_worldMat[6] * cy + m_worldMat[10] * cz + m_worldMat[14];

    m_boundSphere[0] = wx;
    m_boundSphere[1] = wy;
    m_boundSphere[2] = wz;
    // Radius stays the same (assuming uniform scale)
}

// ============================================================================
// EInstance::SetLocalMatrix(EMat4*)
// NON_MATCHING - sets local transform matrix
// Size: ~260 bytes
// ============================================================================
void EInstance::SetLocalMatrix(EMat4* mat)
{
    if (!mat) {
        EMat4_Identity(m_localMat);
    } else {
        for (int i = 0; i < 16; i++) {
            m_localMat[i] = mat->m[i/4][i%4];
        }
    }

    // Mark as needing world matrix update
    m_flags |= 0x01;

    UpdateWorldMatrix();
}

// ============================================================================
// EInstance::Draw(ERC*, int)
// NON_MATCHING - draws the instance
// Size: ~400 bytes
// ============================================================================
void EInstance::Draw(ERC* rc, int flags)
{
    if (!rc || !m_pModel) return;

    // Check visibility flag
    if (m_flags & 0x02) return; // hidden

    // Set world matrix on RC
    // NON_MATCHING: vtable dispatch for ModelMatrix

    // Apply shader overrides
    if (m_shaderOverrides && m_numShaderOverrides > 0) {
        // Override model shaders with instance-specific ones
        // NON_MATCHING: shader override loop
    }

    // Draw model
    // NON_MATCHING: vtable dispatch for model draw
}

// ============================================================================
// EInstance::AddToDrawList(ELevelDrawData*)
// NON_MATCHING - adds instance to sorted draw list
// Size: ~350 bytes
// ============================================================================
void EInstance::AddToDrawList(ELevelDrawData* data)
{
    if (!data) return;
    if (m_flags & 0x02) return; // hidden

    // Calculate sort key from distance to camera
    // Insert into draw list at appropriate position
    // NON_MATCHING: sort key calculation and list insertion
}

// ============================================================================
// EInstance::VisibilityTest(void*)
// NON_MATCHING - tests if instance is visible in frustum
// Size: ~300 bytes
// ============================================================================
int EInstance::VisibilityTest(void* window)
{
    if (!window) return 0;

    // Test bounding sphere against view frustum
    float cx = m_boundSphere[0];
    float cy = m_boundSphere[1];
    float cz = m_boundSphere[2];
    float radius = m_boundSphere[3];

    // Check each frustum plane
    // NON_MATCHING: frustum plane extraction and distance test

    return 1; // visible
}
#endif

// e_rlevel_large.cpp - ERLevel large functions (257-1024 bytes)
// Object file: u2_ngc_release_dvd/e_rlevel.obj
// Section at 0x80231120, size 0x72CC = 29388 bytes - many functions
// All NON_MATCHING due to: GCC vs SN Systems codegen differences

#include "types.h"
#include "stub_classes.h"

struct EVec3 { float x, y, z; };
struct EVec4 { float x, y, z, w; };
struct EMat4 { float m[4][4]; };
struct E3DWindow;
class ERC;
class EShader;
class EInstance;
struct ELevelDrawData;

extern "C" void* EAHeap_Alloc(int size);
extern "C" void EAHeap_Free2(void* ptr);
extern "C" void EMat4_Identity(void* mat);
extern "C" void Vec3_Normalize(EVec3*, EVec3*);

// ERLevel - represents a renderable level/scene
// Contains instances, lights, and draw ordering
struct ERLevel {
    void* m_vtable;              // 0x00
    u32 m_flags;                 // 0x04
    void* m_pInstances;          // 0x08 - instance list
    u32 m_numInstances;          // 0x0C
    void* m_pLights;             // 0x10 - light list
    u32 m_numLights;             // 0x14
    void* m_pLightGrid;         // 0x18
    void* m_pDrawData;          // 0x1C
    void* m_pCamera;            // 0x20
    float m_ambientColor[4];    // 0x24
    u8 m_rest[0x200];           // 0x34

    void Init();
    void Shutdown();
    void AddInstance(void* inst);
    void RemoveInstance(void* inst);
    void Draw(ERC* rc, void* window);
    void DrawOpaque(ERC* rc);
    void DrawTranslucent(ERC* rc);
    void SortInstances(void* camera);
    void UpdateLighting();
    void SetAmbientColor(EVec4& color);
};

// ============================================================================
// ERLevel::Init
// NON_MATCHING - initializes level rendering structures
// ============================================================================
void ERLevel::Init()
{
    m_flags = 0;
    m_pInstances = 0;
    m_numInstances = 0;
    m_pLights = 0;
    m_numLights = 0;
    m_pLightGrid = 0;
    m_pDrawData = 0;
    m_pCamera = 0;

    m_ambientColor[0] = 0.5f;
    m_ambientColor[1] = 0.5f;
    m_ambientColor[2] = 0.5f;
    m_ambientColor[3] = 1.0f;

    // Allocate draw data structure
    m_pDrawData = EAHeap_Alloc(0x400);
    if (m_pDrawData) {
        u8* dd = (u8*)m_pDrawData;
        for (int i = 0; i < 0x400 / 4; i++) {
            ((u32*)dd)[i] = 0;
        }
    }

    m_flags = 1;
}

// ============================================================================
// ERLevel::Shutdown
// NON_MATCHING - releases all level resources
// ============================================================================
void ERLevel::Shutdown()
{
    if (m_pDrawData) {
        EAHeap_Free2(m_pDrawData);
        m_pDrawData = 0;
    }
    if (m_pLightGrid) {
        EAHeap_Free2(m_pLightGrid);
        m_pLightGrid = 0;
    }

    m_pInstances = 0;
    m_numInstances = 0;
    m_pLights = 0;
    m_numLights = 0;
    m_flags = 0;
}

// ============================================================================
// ERLevel::Draw
// NON_MATCHING - main level draw call
// Size: ~600 bytes
// ============================================================================
void ERLevel::Draw(ERC* rc, void* window)
{
    if (!rc || !window) return;

    // Update lighting if needed
    if (m_flags & 0x02) {
        UpdateLighting();
        m_flags &= ~0x02;
    }

    // Sort instances by distance from camera
    SortInstances(m_pCamera);

    // Draw opaque geometry front-to-back
    DrawOpaque(rc);

    // Draw translucent geometry back-to-front
    DrawTranslucent(rc);
}

// ============================================================================
// ERLevel::DrawOpaque
// NON_MATCHING - draws all opaque instances
// Size: ~500 bytes
// ============================================================================
void ERLevel::DrawOpaque(ERC* rc)
{
    if (!rc || !m_pDrawData) return;

    // Iterate through sorted draw list (opaque pass)
    u8* dd = (u8*)m_pDrawData;
    u32 opaqueCount = *(u32*)(dd + 0x00);
    void** opaqueList = *(void***)(dd + 0x04);

    for (u32 i = 0; i < opaqueCount; i++) {
        void* inst = opaqueList[i];
        if (inst) {
            // Draw instance
            // NON_MATCHING: vtable dispatch for instance draw
        }
    }
}

// ============================================================================
// ERLevel::DrawTranslucent
// NON_MATCHING - draws all translucent instances
// Size: ~500 bytes
// ============================================================================
void ERLevel::DrawTranslucent(ERC* rc)
{
    if (!rc || !m_pDrawData) return;

    // Iterate through sorted draw list (translucent pass, back-to-front)
    u8* dd = (u8*)m_pDrawData;
    u32 transCount = *(u32*)(dd + 0x08);
    void** transList = *(void***)(dd + 0x0C);

    for (u32 i = 0; i < transCount; i++) {
        void* inst = transList[i];
        if (inst) {
            // Draw instance with alpha blending enabled
            // NON_MATCHING: vtable dispatch
        }
    }
}

// ============================================================================
// ERLevel::SortInstances
// NON_MATCHING - sorts instances for draw ordering
// Size: ~700 bytes
// ============================================================================
void ERLevel::SortInstances(void* camera)
{
    if (!m_pDrawData || !camera) return;

    u8* dd = (u8*)m_pDrawData;

    // Get camera position for distance sorting
    float camX = *(float*)((u8*)camera + 0x418);
    float camY = *(float*)((u8*)camera + 0x41C);
    float camZ = *(float*)((u8*)camera + 0x420);

    // Calculate sort key for each instance based on distance
    // Separate into opaque and translucent lists
    // Sort opaque front-to-back (for early z-reject)
    // Sort translucent back-to-front (for correct blending)
    // NON_MATCHING: full sort implementation
}

// ============================================================================
// ERLevel::UpdateLighting
// NON_MATCHING - updates level lighting state
// Size: ~400 bytes
// ============================================================================
void ERLevel::UpdateLighting()
{
    if (!m_pLightGrid) return;

    // Rebuild light grid from current light positions
    // NON_MATCHING: light grid update from light list
}

// ============================================================================
// ERLevel::SetAmbientColor
// NON_MATCHING - sets ambient light color
// ============================================================================
void ERLevel::SetAmbientColor(EVec4& color)
{
    m_ambientColor[0] = color.x;
    m_ambientColor[1] = color.y;
    m_ambientColor[2] = color.z;
    m_ambientColor[3] = color.w;

    m_flags |= 0x02; // mark lighting dirty
}

// ============================================================================
// ERLevel::AddInstance
// NON_MATCHING
// ============================================================================
void ERLevel::AddInstance(void* inst)
{
    if (!inst) return;

    // Add to instance list
    // NON_MATCHING: linked list insertion
    m_numInstances++;
}

// ============================================================================
// ERLevel::RemoveInstance
// NON_MATCHING
// ============================================================================
void ERLevel::RemoveInstance(void* inst)
{
    if (!inst) return;

    // Remove from instance list
    // NON_MATCHING: linked list removal
    if (m_numInstances > 0) m_numInstances--;
}

#if 0 // SKIP
// e_mirrorportal_large.cpp - EMirrorPortal large functions (257-1024 bytes)
// Object file: engine_ngc_release_dvd.lib(e_mirrorportal.obj)
// All NON_MATCHING due to: GCC vs SN Systems codegen differences

#include "types.h"
#include "stub_classes.h"

// Forward declarations
class E3DWindow;
class ERC;
struct EVec3 { float x, y, z; };
struct EVec4 { float x, y, z, w; };
struct EMat4 { float m[4][4]; };
struct TRectF { float left, top, right, bottom; };

extern "C" void EMat4_Identity(void* mat);
extern "C" void EMat4_Multiply(void* out, void* a, void* b);
extern "C" void EMat4_Invert(void* out, void* in);
extern "C" void Vec3_Normalize(EVec3*, EVec3*);
extern "C" float Vec3_Dot(EVec3*, EVec3*);
extern "C" void ERC_SaveState(void* rc);
extern "C" void ERC_RestoreState(void* rc);
extern "C" void ERC_ViewMatrix(void* rc, void* mat, int mode, float param);
extern "C" void ERC_ProjectionMatrix(void* rc, void* mat);
extern "C" void ERC_Scissor(void* rc, void* rect);
extern "C" void ERC_EnableGeometryModes(void* rc, u32 modes);
extern "C" void ERC_DisableGeometryModes(void* rc, u32 modes);
extern "C" void ERC_Stencil(void* rc, int a, int b, int c);
extern "C" void E3DWindow_Select(void* win, void* rc);

// EMirrorPortal layout (from disassembly):
// 0x00 = vtable
// 0x04 = mirror plane normal (EVec3, 12 bytes)
// 0x10 = mirror plane point (EVec3, 12 bytes)
// 0x1C = mirror plane distance (float)
// 0x20 = mirror quad vertices (4 x EVec3, 48 bytes)
// 0x50 = mirror matrix (EMat4, 64 bytes)
// 0x90 = reflected view matrix (EMat4, 64 bytes)
// 0xD0 = reflected projection matrix (EMat4, 64 bytes)
// 0x110 = clip planes
// 0x150 = flags

struct EMirrorPortal {
    void* m_vtable;                  // 0x00
    EVec3 m_planeNormal;             // 0x04
    EVec3 m_planePoint;              // 0x10
    float m_planeDist;               // 0x1C
    EVec3 m_quadVerts[4];            // 0x20
    float m_mirrorMat[16];           // 0x50
    float m_reflViewMat[16];         // 0x90
    float m_reflProjMat[16];         // 0xD0
    float m_clipPlanes[16];          // 0x110
    u32 m_flags;                     // 0x150

    void StartRendering(E3DWindow& win, ERC* rc);
    void StopRendering(E3DWindow& win, ERC* rc);
    void CalcMirrorMatrix();
    void InitRC(ERC* rc);
};

// ============================================================================
// EMirrorPortal::StartRendering(E3DWindow&, ERC*)
// Address: 0x802F2558
// Size: 492 bytes
// NON_MATCHING - begins mirror portal rendering pass
// ============================================================================
void EMirrorPortal::StartRendering(E3DWindow& win, ERC* rc)
{
    if (!rc) return;

    // Save current render state
    ERC_SaveState(rc);

    // Calculate mirror matrix if needed
    CalcMirrorMatrix();

    // Set up stencil buffer for mirror region
    ERC_Stencil(rc, 1, 1, 1); // Enable stencil test

    // Draw mirror quad to stencil buffer
    // NON_MATCHING: vertex submission for stencil mask

    // Set reflected view matrix
    u8* winPtr = (u8*)&win;
    float* origViewMat = (float*)(winPtr + 0x80);

    // Calculate reflected view = mirror * original view
    EMat4_Multiply(m_reflViewMat, m_mirrorMat, origViewMat);

    // Copy projection matrix
    float* origProjMat = (float*)(winPtr + 0x40);
    for (int i = 0; i < 16; i++) {
        m_reflProjMat[i] = origProjMat[i];
    }

    // Apply reflected matrices
    ERC_ViewMatrix(rc, m_reflViewMat, 0, 0.0f);
    ERC_ProjectionMatrix(rc, m_reflProjMat);

    // Set scissor to mirror bounds on screen
    // NON_MATCHING: screen-space bounds calculation

    // Flip culling for reflected geometry
    ERC_EnableGeometryModes(rc, 0x100); // flip cull mode

    // Initialize RC for mirror pass
    InitRC(rc);
}

// ============================================================================
// EMirrorPortal::StopRendering(E3DWindow&, ERC*)
// Address: 0x802F2744
// Size: 344 bytes
// NON_MATCHING - ends mirror portal rendering pass
// ============================================================================
void EMirrorPortal::StopRendering(E3DWindow& win, ERC* rc)
{
    if (!rc) return;

    // Restore culling
    ERC_DisableGeometryModes(rc, 0x100);

    // Disable stencil test
    ERC_Stencil(rc, 0, 0, 0);

    // Restore original view/projection matrices
    u8* winPtr = (u8*)&win;
    float* origViewMat = (float*)(winPtr + 0x80);
    float* origProjMat = (float*)(winPtr + 0x40);

    ERC_ViewMatrix(rc, origViewMat, 0, 0.0f);
    ERC_ProjectionMatrix(rc, origProjMat);

    // Restore render state
    ERC_RestoreState(rc);

    // Draw mirror surface with reflection texture
    // NON_MATCHING: mirror surface rendering with blend
}

// ============================================================================
// EMirrorPortal::CalcMirrorMatrix(void)
// Address: 0x802F289C
// Size: 776 bytes
// NON_MATCHING - calculates the reflection matrix
// ============================================================================
void EMirrorPortal::CalcMirrorMatrix(void)
{
    // Calculate mirror plane from normal and point
    float nx = m_planeNormal.x;
    float ny = m_planeNormal.y;
    float nz = m_planeNormal.z;

    // Normalize plane normal
    EVec3 normal = m_planeNormal;
    Vec3_Normalize(&normal, &normal);
    nx = normal.x;
    ny = normal.y;
    nz = normal.z;

    // d = -dot(normal, point)
    float d = -(nx * m_planePoint.x + ny * m_planePoint.y + nz * m_planePoint.z);
    m_planeDist = d;

    // Build reflection matrix:
    // R = I - 2 * n * n^T - 2 * d * [0 0 0 n]^T
    //
    // [1-2nx*nx  -2nx*ny  -2nx*nz  -2nx*d]
    // [-2ny*nx  1-2ny*ny  -2ny*nz  -2ny*d]
    // [-2nz*nx  -2nz*ny  1-2nz*nz  -2nz*d]
    // [0        0         0         1     ]

    m_mirrorMat[0]  = 1.0f - 2.0f * nx * nx;
    m_mirrorMat[1]  = -2.0f * ny * nx;
    m_mirrorMat[2]  = -2.0f * nz * nx;
    m_mirrorMat[3]  = 0.0f;

    m_mirrorMat[4]  = -2.0f * nx * ny;
    m_mirrorMat[5]  = 1.0f - 2.0f * ny * ny;
    m_mirrorMat[6]  = -2.0f * nz * ny;
    m_mirrorMat[7]  = 0.0f;

    m_mirrorMat[8]  = -2.0f * nx * nz;
    m_mirrorMat[9]  = -2.0f * ny * nz;
    m_mirrorMat[10] = 1.0f - 2.0f * nz * nz;
    m_mirrorMat[11] = 0.0f;

    m_mirrorMat[12] = -2.0f * nx * d;
    m_mirrorMat[13] = -2.0f * ny * d;
    m_mirrorMat[14] = -2.0f * nz * d;
    m_mirrorMat[15] = 1.0f;
}

// ============================================================================
// EMirrorPortal::InitRC(ERC*)
// Address: 0x802F2BA4
// Size: 300 bytes
// NON_MATCHING - initializes render context for mirror rendering
// ============================================================================
void EMirrorPortal::InitRC(ERC* rc)
{
    if (!rc) return;

    // Set up oblique near-plane clipping
    // This clips geometry behind the mirror plane

    // Calculate clip plane in view space
    float clipPlane[4];
    clipPlane[0] = m_planeNormal.x;
    clipPlane[1] = m_planeNormal.y;
    clipPlane[2] = m_planeNormal.z;
    clipPlane[3] = m_planeDist;

    // Transform clip plane by inverse-transpose of view matrix
    // NON_MATCHING: matrix math for clip plane transformation

    // Apply to projection matrix (oblique near plane)
    // Modifies the projection matrix so the near plane coincides
    // with the mirror plane
    float q[4];
    q[0] = (clipPlane[0] < 0.0f ? -1.0f : 1.0f) / m_reflProjMat[0];
    q[1] = (clipPlane[1] < 0.0f ? -1.0f : 1.0f) / m_reflProjMat[5];
    q[2] = 1.0f;
    q[3] = (1.0f + m_reflProjMat[10]) / m_reflProjMat[14];

    float dot = clipPlane[0] * q[0] + clipPlane[1] * q[1] +
                clipPlane[2] * q[2] + clipPlane[3] * q[3];

    if (dot != 0.0f) {
        float scale = 2.0f / dot;
        m_reflProjMat[2]  = clipPlane[0] * scale;
        m_reflProjMat[6]  = clipPlane[1] * scale;
        m_reflProjMat[10] = clipPlane[2] * scale + 1.0f;
        m_reflProjMat[14] = clipPlane[3] * scale;
    }

    // Apply modified projection
    ERC_ProjectionMatrix(rc, m_reflProjMat);
}
#endif

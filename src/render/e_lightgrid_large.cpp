// e_lightgrid_large.cpp - ELightGrid large functions (257-1024 bytes)
// Object file: u2_ngc_release_dvd/e_lightgrid.obj
// All NON_MATCHING due to: GCC vs SN Systems codegen differences

#include "types.h"
#include "stub_classes.h"

struct EVec3 { float x, y, z; };
struct EVec4 { float x, y, z, w; };

extern "C" void* EAHeap_Alloc(int size);
extern "C" void EAHeap_Free2(void* ptr);
extern "C" float sqrtf(float);

// ELightGrid - light grid for ambient/directional lighting
// Stores lighting samples in a 3D grid for fast lookup
// Object at 0x8022FA6C, size 0x16B4
struct ELightGrid {
    void* m_vtable;         // 0x00
    u32 m_flags;            // 0x04
    u32 m_sizeX;            // 0x08
    u32 m_sizeY;            // 0x0C
    u32 m_sizeZ;            // 0x10
    float m_minX;           // 0x14
    float m_minY;           // 0x18
    float m_minZ;           // 0x1C
    float m_cellSize;       // 0x20
    void* m_pSamples;       // 0x24 - array of light samples
    u32 m_numSamples;       // 0x28
    void* m_pProbes;        // 0x2C

    void Init(float minX, float minY, float minZ, float cellSize, int sizeX, int sizeY, int sizeZ);
    void Shutdown();
    void SampleAtPoint(EVec3& pos, EVec4& outAmbient, EVec3& outDir);
    void Interpolate(float x, float y, float z, EVec4& outAmbient, EVec3& outDir);
    void BuildFromLightList(void* lights, int numLights);
    void AddProbe(EVec3& pos, EVec4& color, float radius);
};

// ============================================================================
// ELightGrid::Init
// NON_MATCHING - initializes the light grid
// ============================================================================
void ELightGrid::Init(float minX, float minY, float minZ, float cellSize,
                      int sizeX, int sizeY, int sizeZ)
{
    m_minX = minX;
    m_minY = minY;
    m_minZ = minZ;
    m_cellSize = cellSize;
    m_sizeX = sizeX;
    m_sizeY = sizeY;
    m_sizeZ = sizeZ;

    // Allocate sample buffer
    // Each sample: ambient color (16 bytes) + direction (12 bytes) = 28 bytes
    u32 totalSamples = sizeX * sizeY * sizeZ;
    m_numSamples = totalSamples;

    void* samples = EAHeap_Alloc(totalSamples * 28);
    m_pSamples = samples;

    // Clear samples to default ambient
    if (samples) {
        u8* p = (u8*)samples;
        for (u32 i = 0; i < totalSamples; i++) {
            *(float*)(p + i * 28 + 0) = 0.5f;  // ambient R
            *(float*)(p + i * 28 + 4) = 0.5f;  // ambient G
            *(float*)(p + i * 28 + 8) = 0.5f;  // ambient B
            *(float*)(p + i * 28 + 12) = 1.0f;  // ambient A
            *(float*)(p + i * 28 + 16) = 0.0f;  // dir X
            *(float*)(p + i * 28 + 20) = 1.0f;  // dir Y
            *(float*)(p + i * 28 + 24) = 0.0f;  // dir Z
        }
    }

    m_pProbes = 0;
    m_flags = 1; // initialized
}

// ============================================================================
// ELightGrid::Shutdown
// NON_MATCHING - frees all grid resources
// ============================================================================
void ELightGrid::Shutdown()
{
    if (m_pSamples) {
        EAHeap_Free2(m_pSamples);
        m_pSamples = 0;
    }
    if (m_pProbes) {
        EAHeap_Free2(m_pProbes);
        m_pProbes = 0;
    }
    m_numSamples = 0;
    m_flags = 0;
}

// ============================================================================
// ELightGrid::SampleAtPoint
// NON_MATCHING - samples lighting at a world position with trilinear interpolation
// Size: ~400 bytes
// ============================================================================
void ELightGrid::SampleAtPoint(EVec3& pos, EVec4& outAmbient, EVec3& outDir)
{
    if (!m_pSamples || m_numSamples == 0) {
        outAmbient.x = 0.5f;
        outAmbient.y = 0.5f;
        outAmbient.z = 0.5f;
        outAmbient.w = 1.0f;
        outDir.x = 0.0f;
        outDir.y = 1.0f;
        outDir.z = 0.0f;
        return;
    }

    // Convert world position to grid coordinates
    float gx = (pos.x - m_minX) / m_cellSize;
    float gy = (pos.y - m_minY) / m_cellSize;
    float gz = (pos.z - m_minZ) / m_cellSize;

    // Trilinear interpolation
    Interpolate(gx, gy, gz, outAmbient, outDir);
}

// ============================================================================
// ELightGrid::Interpolate
// NON_MATCHING - trilinear interpolation of grid samples
// Size: ~500 bytes
// ============================================================================
void ELightGrid::Interpolate(float x, float y, float z, EVec4& outAmbient, EVec3& outDir)
{
    // Clamp to grid bounds
    if (x < 0.0f) x = 0.0f;
    if (y < 0.0f) y = 0.0f;
    if (z < 0.0f) z = 0.0f;
    if (x >= (float)(m_sizeX - 1)) x = (float)(m_sizeX - 1) - 0.001f;
    if (y >= (float)(m_sizeY - 1)) y = (float)(m_sizeY - 1) - 0.001f;
    if (z >= (float)(m_sizeZ - 1)) z = (float)(m_sizeZ - 1) - 0.001f;

    int ix = (int)x;
    int iy = (int)y;
    int iz = (int)z;
    float fx = x - (float)ix;
    float fy = y - (float)iy;
    float fz = z - (float)iz;

    // Get 8 corner samples
    u8* samples = (u8*)m_pSamples;
    int stride = 28;

    // Sample indices for 8 corners of the cell
    int idx000 = (iz * m_sizeY * m_sizeX + iy * m_sizeX + ix) * stride;
    int idx100 = idx000 + stride;
    int idx010 = idx000 + m_sizeX * stride;
    int idx110 = idx010 + stride;
    int idx001 = idx000 + m_sizeY * m_sizeX * stride;
    int idx101 = idx001 + stride;
    int idx011 = idx001 + m_sizeX * stride;
    int idx111 = idx011 + stride;

    // Trilinear interpolation for ambient color
    float w000 = (1.0f - fx) * (1.0f - fy) * (1.0f - fz);
    float w100 = fx * (1.0f - fy) * (1.0f - fz);
    float w010 = (1.0f - fx) * fy * (1.0f - fz);
    float w110 = fx * fy * (1.0f - fz);
    float w001 = (1.0f - fx) * (1.0f - fy) * fz;
    float w101 = fx * (1.0f - fy) * fz;
    float w011 = (1.0f - fx) * fy * fz;
    float w111 = fx * fy * fz;

    outAmbient.x = w000 * *(float*)(samples + idx000 + 0) +
                   w100 * *(float*)(samples + idx100 + 0) +
                   w010 * *(float*)(samples + idx010 + 0) +
                   w110 * *(float*)(samples + idx110 + 0) +
                   w001 * *(float*)(samples + idx001 + 0) +
                   w101 * *(float*)(samples + idx101 + 0) +
                   w011 * *(float*)(samples + idx011 + 0) +
                   w111 * *(float*)(samples + idx111 + 0);

    outAmbient.y = w000 * *(float*)(samples + idx000 + 4) +
                   w100 * *(float*)(samples + idx100 + 4) +
                   w010 * *(float*)(samples + idx010 + 4) +
                   w110 * *(float*)(samples + idx110 + 4) +
                   w001 * *(float*)(samples + idx001 + 4) +
                   w101 * *(float*)(samples + idx101 + 4) +
                   w011 * *(float*)(samples + idx011 + 4) +
                   w111 * *(float*)(samples + idx111 + 4);

    outAmbient.z = w000 * *(float*)(samples + idx000 + 8) +
                   w100 * *(float*)(samples + idx100 + 8) +
                   w010 * *(float*)(samples + idx010 + 8) +
                   w110 * *(float*)(samples + idx110 + 8) +
                   w001 * *(float*)(samples + idx001 + 8) +
                   w101 * *(float*)(samples + idx101 + 8) +
                   w011 * *(float*)(samples + idx011 + 8) +
                   w111 * *(float*)(samples + idx111 + 8);

    outAmbient.w = 1.0f;

    // Direction is similarly interpolated
    outDir.x = w000 * *(float*)(samples + idx000 + 16) +
               w100 * *(float*)(samples + idx100 + 16) +
               w010 * *(float*)(samples + idx010 + 16) +
               w110 * *(float*)(samples + idx110 + 16) +
               w001 * *(float*)(samples + idx001 + 16) +
               w101 * *(float*)(samples + idx101 + 16) +
               w011 * *(float*)(samples + idx011 + 16) +
               w111 * *(float*)(samples + idx111 + 16);

    outDir.y = w000 * *(float*)(samples + idx000 + 20) +
               w100 * *(float*)(samples + idx100 + 20) +
               w010 * *(float*)(samples + idx010 + 20) +
               w110 * *(float*)(samples + idx110 + 20) +
               w001 * *(float*)(samples + idx001 + 20) +
               w101 * *(float*)(samples + idx101 + 20) +
               w011 * *(float*)(samples + idx011 + 20) +
               w111 * *(float*)(samples + idx111 + 20);

    outDir.z = w000 * *(float*)(samples + idx000 + 24) +
               w100 * *(float*)(samples + idx100 + 24) +
               w010 * *(float*)(samples + idx010 + 24) +
               w110 * *(float*)(samples + idx110 + 24) +
               w001 * *(float*)(samples + idx001 + 24) +
               w101 * *(float*)(samples + idx101 + 24) +
               w011 * *(float*)(samples + idx011 + 24) +
               w111 * *(float*)(samples + idx111 + 24);
}

// ============================================================================
// ELightGrid::BuildFromLightList
// NON_MATCHING - builds grid from list of light sources
// Size: ~800 bytes
// ============================================================================
void ELightGrid::BuildFromLightList(void* lights, int numLights)
{
    if (!m_pSamples || !lights) return;

    // For each grid cell, accumulate light contributions
    u8* samples = (u8*)m_pSamples;

    for (u32 z = 0; z < m_sizeZ; z++) {
        for (u32 y = 0; y < m_sizeY; y++) {
            for (u32 x = 0; x < m_sizeX; x++) {
                // World position of this grid sample
                float wx = m_minX + (float)x * m_cellSize;
                float wy = m_minY + (float)y * m_cellSize;
                float wz = m_minZ + (float)z * m_cellSize;

                float totalR = 0.0f, totalG = 0.0f, totalB = 0.0f;
                float dirX = 0.0f, dirY = 0.0f, dirZ = 0.0f;

                // Accumulate light from each source
                for (int i = 0; i < numLights; i++) {
                    // Each light: position (12) + color (16) + radius (4) = 32 bytes
                    u8* light = (u8*)lights + i * 32;
                    float lx = *(float*)(light + 0);
                    float ly = *(float*)(light + 4);
                    float lz = *(float*)(light + 8);
                    float lr = *(float*)(light + 12);
                    float lg = *(float*)(light + 16);
                    float lb = *(float*)(light + 20);
                    float radius = *(float*)(light + 28);

                    float dx = lx - wx;
                    float dy = ly - wy;
                    float dz = lz - wz;
                    float dist = sqrtf(dx * dx + dy * dy + dz * dz);

                    if (dist < radius && dist > 0.001f) {
                        float atten = 1.0f - (dist / radius);
                        totalR += lr * atten;
                        totalG += lg * atten;
                        totalB += lb * atten;
                        dirX += dx / dist * atten;
                        dirY += dy / dist * atten;
                        dirZ += dz / dist * atten;
                    }
                }

                // Store result
                int idx = (z * m_sizeY * m_sizeX + y * m_sizeX + x) * 28;
                *(float*)(samples + idx + 0) = totalR;
                *(float*)(samples + idx + 4) = totalG;
                *(float*)(samples + idx + 8) = totalB;
                *(float*)(samples + idx + 12) = 1.0f;
                *(float*)(samples + idx + 16) = dirX;
                *(float*)(samples + idx + 20) = dirY;
                *(float*)(samples + idx + 24) = dirZ;
            }
        }
    }
}

// ============================================================================
// ELightGrid::AddProbe
// NON_MATCHING - adds a light probe
// Size: ~300 bytes
// ============================================================================
void ELightGrid::AddProbe(EVec3& pos, EVec4& color, float radius)
{
    // Add a light probe that contributes to the grid
    // Allocates probe in linked list
    // NON_MATCHING: probe allocation and list management
}

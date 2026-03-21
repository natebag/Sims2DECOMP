#ifndef E_RC_H
#define E_RC_H

#include "types.h"

// Forward declarations
class EDLEntry;
class EGEVert;
class EGEParticleListInfo;
class EMat4;
class EDL;
struct EVec4 { float x, y, z, w; };
struct EVec3_ref { float x, y, z; };

// ERC - render context
class ERC {
public:
    void* m_dlPtr;        // 0x00 - pointer to display list data
    u32 m_isInsideBeginEnd; // 0x04
    u8 pad08[0x0C];       // 0x08
    u32 m_endCommandFlag; // 0x14
    u8 m_openCount;       // 0x18 - count for IsOpen
    u8 pad19[0x37];       // 0x19
    u8 pad50[0x04];       // 0x50
    void* m_copyDataFn;   // 0x54
    void* m_copyDataCtx;  // 0x58
    u8 pad5C[0x10];       // 0x5C
    char m_name[16];      // 0x6C (at offset 0x6C)
    void* m_vtable;       // 0x70

    // Connection
    void Connect(EDLEntry* a, EDLEntry* b);

    // Triangle/primitive stubs (all just blr = empty)
    void TriStripRef(int count, float* verts, float* texCoords, unsigned char* colors, signed char* normals, unsigned char* flags, bool strip);
    void TriStripRef(int count, short* verts, short* texCoords, unsigned char* colors, signed char* normals, unsigned char* flags, bool strip);
    void TriFan(EGEVert* verts, int count);
    void TriList(EGEVert* verts, int count);
    void QuadList(EGEVert* verts, int count);
    void QuadList(int count, float* verts, float* texCoords, unsigned char* colors, signed char* normals, bool strip);
    void PointList(EGEVert* verts, int count);
    void ParticleListInfo(EGEParticleListInfo* info);
    int ParticleListBegin(unsigned int a, unsigned int b);
    void ParticleListEnd(unsigned int a);

    // Matrix
    void ModelMatrixId();
    void ModelMatrix(EMat4* mat);

    // Misc stubs
    void MipMapSetup(EGEVert* verts, bool a, bool b);
    void SetColorModulation(int slot, EVec4 color);
    void EnableColorModulation(bool enable);
    void SetBlendModePass3(int a, int b, int c, int d, int e);
    void SetTextureAlphaValue(unsigned char a, unsigned char b, unsigned char c);
    void SetDebugMarker(int marker);
    void SetAlphaPlane(float a, EVec4 color, float c, float d);
    void SetFog(float start, float end, EVec4 color);
    void LightsRadiosity(EVec3_ref& a, EVec3_ref& b, float c);

    // Alloc
    void* Alloc(unsigned int size, int align);
    void* AllocExternal(void* ptr, int size);
    void* AllocFlushable(unsigned int size, int align);
    void* AllocFlushableExternal(void* ptr, int size);
    void* AllocVertexData(unsigned int size);

    // Misc
    void ProcessFrameEffects(int type, void* data);
    void SetName(char* name);
    void Validate();
    EVec4* GetFogColor();
    void SetCopyDataCallback(void (*fn)(void*, void*), void* ctx);
    bool IsOpen() const;
    void EndCommand();

    ERC();
};

// External functions called by ERC
void ERC_ERC_Init(int active, int type);  // global ctor helper at 0x802F9A10

#endif // E_RC_H

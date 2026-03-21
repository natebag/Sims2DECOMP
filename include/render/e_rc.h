#ifndef E_RC_H
#define E_RC_H

#include "types.h"

// RCMode enum
enum RCMode {
    RCMODE_DEFAULT = 0,
    RCMODE_NORMAL = 1,
    RCMODE_FLUSH = 2,
    RCMODE_IMMEDIATE = 3
};

// Forward declarations
class EDLEntry;
class EGEVert;
class EGEParticleListInfo;
class EGEPackedParticle;
class EGELineStreak;
class EMat4;
class EDL;
class ETexture;
class ERenderSurface;
class EShader;
class EMovie;
struct EViewport;
struct ELights;
struct EMaterial;
struct EVec2 { float x, y; };
struct EVec4 { float x, y, z, w; };
struct EVec3_ref { float x, y, z; };
template<typename T> struct TRect { T left, top, right, bottom; };

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
    ~ERC();

    // Medium functions - Init/lifecycle
    void Init(RCMode mode);
    void BeginCommand(int cmdType, int param);
    void Send();
    EDLEntry* NewEntry(int slots);
    void Terminate();
    void ShrinkSmallDisplayList();

    // Medium functions - Primitives
    void TriStrip(EGEVert* verts, int count);
    void LineList(EGEVert* verts, int count);
    void LineStrip(EGEVert* verts, int count);
    void SpriteList(EGEVert* verts, int count);
    void ParticleList(int count, EGEPackedParticle* particles);
    void LineStreakList(int count, EVec4& a, EVec4& b, EGELineStreak* streaks);
    void ParticleListRot(int count, EGEPackedParticle* particles);
    void AddDisplayListReference(EDL* dl);
    void DisplayList(EDL* dl);

    // Medium functions - State
    void Viewport(EViewport* vp);
    void ClipRect(TRect<float>& rect);
    void Scissor(TRect<float>* rect);
    void ModelMatrixList(EMat4* mats, int count);
    void ModelMatrixIndex(int index, int slot);
    void ModelMatrices(EMat4* mats, int count);
    void ViewMatrix(EMat4* mat, int mode, float param);
    void ProjectionMatrix(EMat4* mat);
    void WindowMatrix(EMat4* mat);
    void Texture(ETexture* tex, int slot);
    void EnableGeometryModes(unsigned int modes);
    void DisableGeometryModes(unsigned int modes);
    void SetGeometryModes(unsigned int modes);
    void EnableRasterModes(unsigned int modes, int pass);
    void DisableRasterModes(unsigned int modes, int pass);
    void SetRasterModes(unsigned int modes, int pass);
    void SaveState();
    void RestoreState();
    void Lights(ELights* lights);
    void Material(EMaterial* mat);
    void SetMipMap(float mipLevel, int mode);
    void Callback(void (*fn)(unsigned int, unsigned short, unsigned char), unsigned int a, unsigned short b, unsigned char c);
    void RectList(int count, float* data, EVec4& color, float depth);
    void RectListRot(int count, float* data, EVec4& color, float depth);
    void DirectRect(EVec2& pos, EVec2& size, EVec4& color, float depth);
    void EnvironmentMap(bool enable, bool flag2, int param);
    void RecalcMatrices(int a, int b);
    void Debug(unsigned int a, unsigned int b);
    void GeometrySetup();
    void ZTest(bool enable, int compareFunc, int refValue, int pass);
    void AlphaTest(bool enable, int mode, float threshold, int pass);
    void Stencil(int a, int b, int c);
    void SetBlendMode(int src, int dst, int op, int logic, float alpha, int pass);
    void SetCombineMode(int stage, int mode);
    void RenderSurface(ERenderSurface* surface, int param);
    void SaveImageData(ERenderSurface* surface);
    void Vertex(int a, int b, float* verts, float* texCoords, unsigned char* colors, signed char* normals, unsigned char* flags);
    void TriIndexed(int count, unsigned char* indices);
    void Noop();
    void MovieFrame(EMovie* movie);
    void SetAlpha(float alpha);
    void* AllocAndCopy(void* data, int size);
};

// External functions called by ERC
void ERC_ERC_Init(int active, int type);  // global ctor helper at 0x802F9A10

#endif // E_RC_H

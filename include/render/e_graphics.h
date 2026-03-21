#ifndef E_GRAPHICS_H
#define E_GRAPHICS_H

#include "types.h"

// Forward declarations
class ERC;
class EDL;
class EShader;
class ETexture;
class ERenderSurface;
class EMovie;
class EDLEntry;
class EMat4;

// Enums
enum RCMode {
    RCMODE_0 = 0,
    RCMODE_1 = 1,
    RCMODE_2 = 2,
    RCMODE_3 = 3
};

enum ECoordinateSystem {
    COORDSYS_DEFAULT = 0
};

// EVec2 - 2D vector (8 bytes)
struct EVec2 {
    float x, y;
};

// EVec3 - 3D vector (12 bytes)
struct EVec3 {
    float x, y, z;
};

// TRect<float> template (16 bytes)
template<typename T>
struct TRect {
    T left, top, right, bottom;
};

// EGraphics - main graphics system singleton
class EGraphics {
public:
    // Virtual function table (vtable at offset 0x00)
    // The vtable contains many virtual functions accessed via offset

    u8 pad04[0x04];              // 0x04 - m_insideBeginEnd?
    u8 pad08[0x04];              // 0x08
    u32 m_frameBufClearFlag;     // 0x0C
    u32 m_frameBufClearReqFlag;  // 0x10
    u8 pad14[0x04];              // 0x14
    u32 m_screenXSize;           // 0x18
    u32 m_screenYSize;           // 0x1C
    u32 m_screenXOffset;         // 0x20
    u32 m_screenYOffset;         // 0x24
    u8 pad28[0x18];              // 0x28
    u32 m_normalMapMatrix;       // 0x40  (offset from this)
    u8 pad44[0x4C];              // 0x44
    void* m_systemFont;          // 0x90
    u8 pad94[0x04];              // 0x94
    u32 m_coordinateSystem;      // 0x98
    u8 pad9C[0x84];              // 0x9C
    EVec3 m_backgroundColor;     // 0x80  (within struct at offset 0x80)
    u8 padC0[0x1EC];             // ...
    float m_cameraBloom[4];      // 0x2AC (bloom1, bloom2, bloom3, bloom4)
    u8 pad2BC[0x3C];             // 0x2BC
    float m_motionBlur[4];       // 0x2F0 (blur1, blur2, blur3, blur4)
    EVec3 m_tintA;               // 0x300
    EVec3 m_tintB;               // 0x30C
    u32 m_wireframe;             // 0x318
    u32 m_firstPassRenderOnly;   // 0x31C
    u32 m_enableFrameEffects;    // 0x320
    u8 pad324[0x14];             // 0x324
    void* m_vtablePtr;           // 0x338 (vtable for vcalls)

    // Small stubs (4 bytes = blr)
    virtual void ManagedShutdown();
    void DoSwapBuffer(int);
    void DoSetupFrameBuffer(int);
    void Shutdown();
    void DrawCensorRects(ERC*);
    void GrabFrameBufferChunk32(int, int, int, int, unsigned int*, int*);
    void DiscardAllVram();
    void ClearStencilBuffer();
    void ProcessFrameEffects();
    void SelectFrameBuffer(int);

    // Small getters/setters (8 bytes)
    u32 FrameBufferClearFlag();
    u32 FrameBufferClearRequestFlag();
    int GetFrameBufferTexture(int);
    int GetDepthBufferTexture();
    int NeedFlushToDestroy(EDL*);
    int NeedFlushToDestroy(ETexture*);
    int NeedFlushToDestroy(ERenderSurface*);
    int NeedFlushToDestroy(EMovie*);
    int GetLargestAvailableTextureMemoryBlock();
    int NeedFlushToDestroy(EShader*);
    u32 GetCoordinateSystem();
    void SetCoordinateSystem(ECoordinateSystem cs);
    int GetScreenXSize();
    int GetScreenYSize();
    int GetActualScreenXSize();
    int GetActualScreenYSize();
    void SetScreenXOffset(int x);
    void SetScreenYOffset(int y);
    int GetScreenXOffset();
    int GetScreenYOffset();
    int GetMaxTextureXSize();
    int GetMaxTextureYSize();
    EMat4* GetNormalMapMatrix();
    void EnableWireframe(bool enable);
    int IsFirstPassRenderOnly();
    void SetEnableFrameEffects(bool enable);
    int IsEnableFrameEffects();
    int IsInsideBeginEnd();
    int ManagedStartup();

    // 12-byte functions
    float GetFarZVal();
    float GetNearZVal();
    float GetScreenAspect();
    void EnableFirstPassRender();
    void EnableNormalRender();

    // Larger small functions
    void GetFrameBufferTextureCoordinate(EVec2 coord);
    void SetMotionBlur(float a, float b, float c, float d);
    void GetCameraBloom(float& a, float& b, float& c, float& d);
    void GetMotionBlur(float& a, float& b, float& c, float& d);
    float GetXPixelSize();
    float GetYPixelSize();

    // Rect/color functions
    void GetScissorRect(TRect<float>* out, TRect<float>& a, TRect<float>& b);
    void SetBackgroundColor(EVec3& color, int idx, bool flag);
    void GetBackgroundColor(EVec3& color, int& outIdx);
    void SetTint(EVec3& a, EVec3& b);
    void GetTint(EVec3& a, EVec3& b);

    // Alloc/free
    EDL* AllocDL(RCMode mode);
    void FreeDL(EDL* dl, RCMode mode);
    ERC* AllocRC(RCMode mode);
    void FreeRC(ERC* rc, RCMode mode);
    void Execute(EDL* dl, bool flush);
    EDL* AllocDisplayList(RCMode mode);
    void Destroy(EDL* dl);
    void DeallocateDL(EDL* dl, RCMode mode);
    EMovie* CreateMovie();
    void Destroy(EMovie* movie);
    void* GetSystemFont();
};

// Global EGraphics pointer (stored in r13 SDA)
extern EGraphics* gpEGraphics;

#endif // E_GRAPHICS_H

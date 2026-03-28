#ifndef SKINCOMPOSITOR_H
#define SKINCOMPOSITOR_H

#include "types.h"
#include "sim/simmodel.h"  // for eBodyPartS2C

// Forward declarations
class ERTexture;
class CasSimDescriptionS2C;

// ============================================================================
// SkinCompositor - Skin texture compositor for Sim models
// Size: 0x28 (40 bytes) based on constructor analysis
// Object file: skincompositor.obj
// ============================================================================
class SkinCompositor {
public:
    SkinCompositor();
    ~SkinCompositor();

    void Reset();
    void CreateSkinQuadrantHiRes(ERTexture* tex, unsigned char quadrant, CasSimDescriptionS2C* desc);
    void CreateSkinQuadrantLoRes(ERTexture* tex, unsigned char quadrant, CasSimDescriptionS2C* desc);
    void CreateSkin(ERTexture* tex, unsigned char quadrant, CasSimDescriptionS2C* desc, bool lowRes);
    void CreateSkinQuadrantPrecomposited(ERTexture* tex, unsigned int quadrant, bool flag);
    void InitScratchpadTextures(unsigned short size);
    void InitSkinTexture();
    void FinalizeSkinTexture();
    void LoadAllTextureLayers();
    void GetTextureIDs(unsigned int& id, unsigned int* a, unsigned int* b, unsigned int* c);
    void BlendTexture(eBodyPartS2C part, unsigned int a, unsigned int b);
    void GetFinalReflectionMask();

    // Member layout (from constructor):
    u16 m_size;                // +0x00 (set to 256 in ctor)
    u8 _pad02[2];              // +0x02
    void* m_ptr04;             // +0x04
    void* m_ptr08;             // +0x08
    void* m_ptr0C;             // +0x0C
    void* m_ptr10;             // +0x10
    void* m_ptr14;             // +0x14
    void* m_ptr18;             // +0x18
    u8 m_byte1C;               // +0x1C
    u8 _pad1D[3];              // +0x1D
    void* m_ptr20;             // +0x20
    void* m_ptr24;             // +0x24
};

#endif // SKINCOMPOSITOR_H

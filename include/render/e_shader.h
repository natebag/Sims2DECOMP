#ifndef E_SHADER_H
#define E_SHADER_H

#include "types.h"

// Forward declarations
class ERC;
class ETexture;
struct EMaterial;

// EShaderDef
struct EShaderDef;

// EShaderUpdate
struct EShaderUpdate;

// EShader - shader object
class EShader {
public:
    void* m_vtablePtr;       // 0x00
    u32 m_flags;             // 0x04 - surface properties / flags bitfield
    u8 pad08[0x08];          // 0x08
    // Material data at offset 0x10
    u8 m_material[0x30];     // 0x10 - EMaterial embedded
    u8 pad40[0x24];          // 0x40
    u8 m_modifiableColors[0x30]; // 0x64 - array of modifiable color data (indexed * 64)
    u8 pad94[0x14];          // 0x94  (offset to m_multiTexture at 0x68)
    u32 m_textureCount;      // 0x88
    u8 padA4[0x28];          // 0x8C
    u32 m_shaderData;        // 0xB4
    u8 padB8[0x30];          // 0xB8
    void* m_shaderUpdate;    // 0xE8 - EShaderUpdate*
    u32 m_magic;             // 0xE4 - magic/validation value
    u8 padEC[0x01];          // 0xEC - override texture index
    u8 padED[0x03];          // 0xED
    void* m_shaderDef;       // 0xF0 - EShaderDef*

    // operator new/delete
    void* operator new(u32 size);
    void operator delete(void* ptr);

    // Surface properties
    void SetSurfaceProperty(unsigned int prop);
    void ClearSurfaceProperty(unsigned int prop);
    bool IsSurface(unsigned int prop) const;
    u32 GetSurfaceProperties() const;

    // Material
    void* GetMaterial() const;

    // Color/texture
    bool CanColorBeModified() const;
    void* GetModifiableColor(unsigned int index) const;
    void SetTexture(ETexture* tex, int slot);
    void SetMultiTexture(ETexture* tex, int slot);
    void UndoOverrideTexture();
    bool UseOverrideTexture(unsigned char index);
    void SetAlternateShader(EShader* shader);
    void SetAlphaTestThreshold(float threshold, int pass);

    // Getters
    EShaderDef* GetShaderDef() const;
    bool IsFacer() const;
    bool IsCylindricalFacer() const;
    EShaderUpdate* GetShaderUpdate() const;

    // Shadow
    void SelectForShadowMask(ERC* rc);
    void SetShadowAlpha(float alpha);
    void Select(ERC* rc, unsigned int flags);

    // Misc
    void UpdateMaterialCoefficients();
    bool IsValid();
    void RemoveGeometryModes(unsigned int modes);
    void AddGeometryModes(unsigned int modes);

    EShader();
};

// EShader allocation pool
extern void* g_shaderPool;

// EShader init/deinit (called by global ctors/dtors)
void EShader_EShader_Init(int active, int type);  // at 0x802FA9E8

#endif // E_SHADER_H

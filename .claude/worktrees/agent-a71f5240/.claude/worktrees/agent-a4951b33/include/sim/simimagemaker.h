#ifndef SIMIMAGEMAKER_H
#define SIMIMAGEMAKER_H

#include "types.h"

// Forward declarations
class EShader;
class EIStaticModel;
class ERC;
class ETexture;
class ELights;
class SimModel;
struct E3DWindow;
struct EVec3;

// Body part enum for Sims 2 console
enum eBodyPartS2C {
    // up to 25 (0x19) body parts based on bounds check in SetModel
    BODYPART_COUNT = 26
};

// ============================================================================
// SimImageMaker - Creates portrait/thumbnail images of Sims
// From: simimagemaker.obj
// Layout:
//   +0x00: m_width (u32)
//   +0x04: m_height (u32)
//   +0x08: m_depth (u32)
//   +0x88: m_gender (u32, bool)
//   +0x8C: m_skinShader (EShader*)
//   +0x90: m_models[26] (EIStaticModel* array, 0x68 bytes)
// ============================================================================
class SimImageMaker {
public:
    SimImageMaker(void);
    ~SimImageMaker(void);

    BOOL Init(void);
    void Reset(void);
    void Shutdown(void);
    void SetToDefaultValues(void);

    void SetGender(bool gender);
    void SetSkinShader(EShader* shader);
    void SetModel(eBodyPartS2C part, EIStaticModel* model);
    void SetPortraitModels(SimModel* simModel);

    void OverrideImageSize(unsigned int width, unsigned int height, unsigned int depth);
    void OverrideLights(ELights& lights);
    void OverridePose(unsigned int pose, EVec3& pos, EVec3& rot, EVec3& scale, float param);
    void OverrideBackground(unsigned int bgId);

    void CreateImage(void);
    void CreateImage32x32(void);
    void InitWindow(E3DWindow& window, ERC* rc);
    void PoseSim(ERC* rc);
    void CopyToFinalImage(ETexture* texture);
    void UpdateRepShaders(int rep);

private:
    u32 m_width;               // 0x00
    u32 m_height;              // 0x04
    u32 m_depth;               // 0x08
    u8 m_pad0C[0x7C];         // 0x0C
    u32 m_gender;              // 0x88
    EShader* m_skinShader;     // 0x8C
    EIStaticModel* m_models[BODYPART_COUNT]; // 0x90
};

#endif // SIMIMAGEMAKER_H

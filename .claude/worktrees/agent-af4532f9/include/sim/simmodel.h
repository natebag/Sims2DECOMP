#ifndef SIMMODEL_H
#define SIMMODEL_H

#include "types.h"
#include "core/e_vec3.h"

// Forward declarations
class CasSimDescriptionS2C;
class CasSimPartsS2C;
class EIStaticModel;
class EShader;
class EMat4;
class EAnimController;
class ETextureDef;
class ETexture;
class ERC;
class EString;
class ERTexture;

// Body part enum - 26 entries based on loop counts
enum eBodyPartS2C {
    BODY_PART_0 = 0,
    BODY_PART_COUNT = 26
};

// Tattoo texture type enum
enum eTattooTextureTypeS2C {
    TATTOO_TYPE_0 = 0
};

// Forward declare for globals
struct Globals;
extern Globals _globals;

// ============================================================================
// SimModel - Manages Sim 3D model parts, textures, and morphing
// Size: ~0x168 bytes
// Object file: simmodel.obj
// ============================================================================
class SimModel {
public:
    SimModel();
    ~SimModel();

    void Reset();
    void Init(CasSimDescriptionS2C* desc, bool highRes);
    void SetHighResolution(bool highRes);
    void SetSimDescription(CasSimDescriptionS2C* desc);
    void FlushLoadingModels();
    void DeallocateAllModels();
    void DeallocateAllSkinTextures();
    void DeallocateModelPart(eBodyPartS2C part);
    void DeallocateMorphResources();
    void DetachSimDescription();
    void Clone();
    bool IsLoadingModels() const;
    bool VerifyRequiredModels() const;
    void SetAllModels();
    void UpdateHead(bool, bool, bool);
    void UpdateOuterLayerCollar(bool, bool);
    void UpdateOuterLayerTorso(bool, bool, bool, bool);
    void UpdateOuterLayerSleeve(bool, bool, bool, bool);
    void UpdateMidLayerCollar(bool);
    void UpdateMidLayerTorso(bool, bool, bool, bool);
    void UpdateMidLayerSleeve(bool, bool, bool, bool);
    void UpdateInnerLayerTorso(bool, bool, bool);
    void UpdateInnerLayerSleeve(bool, bool, bool);
    void UpdateLowerBody(bool, bool);
    void UpdateShoes(bool, bool, bool);
    void UpdateVestScarf(bool, bool, bool);
    void UpdateHat(bool, bool, bool);
    void UpdateHair(bool, bool, bool);
    void UpdateArmAccessory(bool, bool, bool);
    void UpdateBelt(bool, bool, bool);
    void UpdateGlasses(bool, bool, bool);
    void UpdateFacialFeature(bool, bool, bool);
    void UpdateNecklaceEarring(bool, bool, bool);
    void SetModelPart(eBodyPartS2C part, unsigned int id);
    void LoadAllMorphTargets();
    void UpdateModelPart(eBodyPartS2C part, bool, bool);
    void ChangeModelPart(eBodyPartS2C part, unsigned int id, bool, bool);
    void UpdateQueuedModelPart(eBodyPartS2C part, bool, bool);
    void WeldSharedVertices(eBodyPartS2C, eBodyPartS2C, bool);
    void ApplyLatticeMorphingToModelPart(eBodyPartS2C part);
    void ApplySkinToModelPart(eBodyPartS2C part);
    void RebuildModified();
    void CompositeSkinPart(unsigned char part);
    void GetChangedModels(int* out);
    void SetModelPartASync(eBodyPartS2C part, unsigned int id);
    void WeldAllSharedVertices();
    void ApplyAllLatticeMorphing();
    void ApplyAllMorphTargets();
    int UsingHighResolutionModel();
    unsigned int GetGameStateModelID(unsigned int id, bool highRes);
    void ApplyMorphTargetsToRegion(unsigned int, unsigned int, float, unsigned int*);
    void CreateSkin(char* name);
    void GetSkinTextureDef(ETextureDef& def, bool highRes);
    void ApplySkinToModels();
    void TransformModelPartUV(eBodyPartS2C part);
    void TransformAllModelUV();
    void GetModelUVTransformParameters(eBodyPartS2C part, EVec2& a, EVec2& b, unsigned int& c, EVec2& d, EVec2& e);
    void CompositeAllSkin();
    unsigned int GetGameStateTextureID(unsigned int id, bool highRes);
    void UpdateReweld(bool);
    void UpdateReweldCAS(bool);
    void UpdateSimDescriptionIndices(unsigned int* indices);
    void GetModelName(eBodyPartS2C part, EString& name);
    void GetTextureName(eBodyPartS2C part, EString& name);
    void GetTattooTextureName(eTattooTextureTypeS2C type, EString& name);

    // Static data
    static char s_SimPartsMapNames[16];
    static unsigned char s_SimPartsMap[260];

    // Member layout (from constructor):
    // +0x00: flags per body part (26 u32s)
    u32 m_partFlags[26];               // +0x00

    // +0x68: model pointers (26 entries, 104 bytes)
    u32 m_modelPtrs[26];               // +0x68

    // +0xD0: texture/morph data (26 entries, 104 bytes)
    u32 m_morphData[26];               // +0xD0

    // +0x138: pointer to CasSimDescriptionS2C
    CasSimDescriptionS2C* m_pSimDescription; // +0x138

    // +0x13C: unknown pointer
    void* m_pUnk13C;                   // +0x13C

    // +0x140: texture pointers (4 entries)
    u32 m_texturePtrs[4];              // +0x140

    // +0x150: high resolution flag
    u32 m_highRes;                     // +0x150

    // +0x154: unknown
    u32 m_unk154;                      // +0x154

    // +0x158: EString objects (4)
    u32 m_strings[4];                  // +0x158

    // +0x168: tail padding to match original 0x16C size
    u32 m_unk168;                      // +0x168
};

// External globals
extern u16 gSimPartsMapSizeMultiplier_CAS;
extern u16 gSimPartsMapSizeMultiplier_Game;
extern u16 gSimPartsMapSize;

// ============================================================================
// ESims3DHead - Sim face/head 3D rendering
// Vtable at 0x8045cd08
// Object file: simhead.obj
// ============================================================================
class ESim;
class cXPerson;
class EVec4;
class EAHeap;

class ESims3DHead {
public:
    ESims3DHead(ESim* sim);
    virtual ~ESims3DHead();
    virtual void Update();
    virtual void Draw(ERC* rc);

    void InitHead(cXPerson* person);
    void InitShaders();
    void ResetShaders();
    void Draw2D(ERC* rc, cXPerson* person);

    void* operator new(unsigned int size);
    void operator delete(void* ptr);

    // Static members
    static EShader* m_pShd;
    static ETexture* m_pHeadBorder;
};

// External globals for ESims3DHead
extern float ESims3DHead_yfov;
extern float ESims3DHead_near;
extern float ESims3DHead_far;
extern float _p1head_xoff;
extern float _p1head_yoff;
extern float _p2head_xoff;
extern float _p2head_yoff;
extern float _button_yoff;
extern float _lbutton_xoff;
extern float _rbutton_xoff;
extern float _head_win_l;
extern float _head_win_r;
extern float _head_win_t;
extern float _head_win_b;
extern float _quick_stat_w;
extern float _quick_stat_h;
extern float _quick_stat_xoff;
extern float _quick_stat_yoff;
extern EVec2 _v3DHeadOff;
extern EVec2 _v3DHeadOffp1;
extern EVec2 _v3DHeadOffp2;
extern float moodfactor;

// ============================================================================
// SimRenderer - Static renderer for Sim models
// Object file: simrenderer.obj
// ============================================================================
class SimRenderer {
public:
    static void Render(ERC* rc, EIStaticModel** models, EShader* shader, EMat4* mat, unsigned int count, bool flag);
    static void Render(ERC* rc, EIStaticModel** models, EAnimController* anim, EShader* shader, EMat4& mat, bool flag);
    static void MorphParts(EIStaticModel** models, bool flag);
    static void RenderGhosted(ERC* rc, EIStaticModel** models, EMat4* mat, unsigned int count, bool flag);

    static u32 s_bodyPartRenderOrder[26];
};

// ============================================================================
// CasSimRenderer - CAS (Create-A-Sim) renderer
// Vtable at 0x804660f8
// Object file: simrenderer.obj / cassimrenderer.obj
// ============================================================================
class CasSimRenderer {
public:
    CasSimRenderer();
    virtual ~CasSimRenderer();

    void Init();
    void SetPosition(EVec3& pos, float rot);
    int GetNumActiveBodyModels();
    void UpdateSkin();
    void Draw(ERC* rc);
    void DrawShadow(ERC* rc);
    void SetNextAnimation(unsigned int animId);
    void CheckPending();
    void SetupSimCommon();
    void CreateFaceImage(unsigned int, unsigned int, unsigned int, bool, unsigned int);
    unsigned int GetNumBodyModels(eBodyPartS2C part);
    unsigned int GetNumTattooTextures(eTattooTextureTypeS2C type);
    unsigned int GetIconTextureId(eBodyPartS2C part, unsigned int index);
    unsigned int GetIconTattooTextureId(eTattooTextureTypeS2C type, unsigned int index);
    void SetFaceImage(ETexture* tex);
    void DrawFaceImage(ERC* rc);
    void UpdateRepShaders(int);
    void GetBonePos(unsigned int boneId, EVec3& pos);
    unsigned int GetPositionNum() const;
    void SetPositionNum(unsigned int num);
    void SetSimRotation(float rot);
    SimModel* GetSimModel();

    // +0x00: unknown (set to 0 in ctor, before vtable)
    u32 m_unk00;                       // +0x00

    // +0x04: vtable (implicit in C++)

    // +0x08: embedded SimModel (starts at this+8)
    SimModel m_simModel;               // +0x08

    // After SimModel: EAnimController at +0x174
    // +0x174: 0x78 bytes for anim controller
    char m_animController[0x78];       // +0x174

    // +0x1EC: position (EVec3, 12 bytes)
    EVec3 m_position;                  // +0x1EC

    // +0x1F8: padding
    char _pad1F8[0x10];                // +0x1F8

    // +0x208: rotation angle (stfs f1,520(r3), 520=0x208)
    float m_rotation;                  // +0x208

    // +0x20C: sim rotation (stfs f1,524(r3), 524=0x20C)
    float m_simRotation;               // +0x20C

    // +0x210: padding
    char _pad210[0x04];                // +0x210

    // +0x214: position number (lwz/stw at 532(r3), 532=0x214)
    u32 m_positionNum;                 // +0x214

    // +0x218: rest of CAS data
    char _padRest[0x10];               // +0x218

    // +0x228: total approx size
};

// External data for CasSimRenderer
extern EVec3 _vInitialSimPos;
extern EVec3 _vInitialSimScale;

#endif // SIMMODEL_H

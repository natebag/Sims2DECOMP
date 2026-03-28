#ifndef IOBJECT_H
#define IOBJECT_H

#include "types.h"

// Placement new
inline void* operator new(u32 size, void* ptr) { return ptr; }

// Forward declarations
class EStream;
class EFile;
class EVec3;
class EMat4;
class ELights;
class E3DWindow;
class ERC;
class ELevelDrawData;
class ERAnim;
class EAnimNote;
class EAnimController;
class ERLevel;
class EHouse;
class EILight;
class cXObject;
class AttachmentNode;

// ============================================================================
// EStorable - Base class for EA's serialization system
// Minimal definition for compilation
// ============================================================================
class EStorable {
public:
    virtual ~EStorable();
    EStorable* CreateCopy() const;
};

// ============================================================================
// Emitter - Base class for particle emitters
// Minimal definition for compilation
// ============================================================================
class Emitter {
public:
    virtual ~Emitter();
};

// Forward declare for TArray allocator
struct TArrayDefaultAllocator;

// ============================================================================
// ObjAnimDef - Animation definition for object models
// Size: at least 0x18
// ============================================================================
struct ObjAnimDef {
    u32 m_pad00;         // +0x00
    u32 m_pad04;         // +0x04
    u32 m_pad08;         // +0x08
    u32 m_pad0C;         // +0x0C
    u32 m_pad10;         // +0x10
    u32 m_modelId;       // +0x14 - model ID (checked in UpdateBulb, UpdateModel)
};

// ============================================================================
// EParticleObj - Particle effect container for objects
// Size: 0x10
// ============================================================================
class EParticleObj {
public:
    EParticleObj();
    ~EParticleObj();

    void CreateEffects(EMat4& mat, float scale, ObjAnimDef* animDef);
    void UpdateEffectPosAndAlphaFade(EAnimController& ctrl, float alpha, EMat4& mat, EVec3* pos, float fade);

    u32 m_effectPtrs[3]; // +0x00, +0x04, +0x08
    u32 m_count;         // +0x0C
};

// ============================================================================
// ETypeInfo - Runtime type information for EA's serialization system
// ============================================================================
struct ETypeInfo {
    // Internal layout varies per class, at least 0x18 bytes
    // +0x0C: const char* typeName
    // +0x10: u32 typeKey
    // +0x14: u16 typeVersion
    // +0x16: u16 readVersion
    char m_data[0x18];
};

// ============================================================================
// TArray<EILight*, TArrayDefaultAllocator> - Template array for light pointers
// Size: 0x0C
// ============================================================================
template<typename T, typename Allocator>
class TArray {
public:
    void Init();
    TArray();
    ~TArray();

    void Destruct(T* ptr, int count);
    void Construct(T* ptr, int count);
    void Copy(T* dst, T* src, int count);
    void CopyReverse(T* dst, T* src, int count);
    void Insert(T* pos, int index, int count);
    void Add(T& item);
    void Deallocate();
    void DeleteAll();
    void SetSize(int size, int grow);

    T* m_pData;     // +0x00
    int m_size;     // +0x04
    int m_capacity; // +0x08
};

// ============================================================================
// ISimsObjectModel - Base object model for Sims objects
// Size: at least 0x464
// Vtable at 0x8045c220
// ============================================================================
class ISimsObjectModel : public EStorable {
public:
    ISimsObjectModel();
    virtual ~ISimsObjectModel();

    // Type system (EStorable overrides)
    virtual const ETypeInfo* GetTypeInfo() const;
    virtual const char* GetTypeName() const;
    virtual u32 GetTypeKey() const;
    virtual u16 GetTypeVersion() const;
    virtual ISimsObjectModel* CreateCopy() const;

    // Static type system
    static const ETypeInfo* GetTypeInfoStatic();
    static u16 GetReadVersion();
    static void RegisterType(u16 version);

    // Factory methods
    static ISimsObjectModel* New();
    static void Construct(ISimsObjectModel* obj);
    static void Destruct(ISimsObjectModel* obj);
    void SafeDelete();

    // Accessors
    void* GetShadow();
    bool GetDynamic();
    void SetDynamic(bool dynamic);
    EVec3* GetPos();
    void SetPos(EVec3& pos);
    void SetPosStatic(EVec3& pos, float rot);
    EVec3* GetDir();
    void SetDir(EVec3& dir);
    float GetRot();
    void SetRot(float rot);
    void* GetILight();

    // Animation
    bool ShouldAnimStartBlendIn(u32 animId);
    bool ShouldAnimStartImmediate(u32 animId);
    bool ShouldKillAllAnimTracks(u32 animId);
    void AnimStartImmediate(u32 animId);
    void AnimStartBlendIn(u32 animId);
    void KillAllAnimTracks();
    void UpdateAnim(ObjAnimDef* animDef);
    void UpdateAnimTrack(ObjAnimDef* animDef, bool flag);
    void UpdateTracks();
    void UpdateAnimController();
    void DoAnimation();
    void UpdateModel(ObjAnimDef* animDef);
    void UpdateBulb(ObjAnimDef* animDef);
    void UpdateShader(ObjAnimDef* animDef);
    void StartNewAnimTrack(ObjAnimDef* animDef, bool flag);
    void ProcessPropertyEventTags(ObjAnimDef* animDef, float time);
    void processAnimEvents(ERAnim* anim, int start, int end, bool flag);
    void animEventHandler(ERAnim* anim, EAnimNote& note, int param);

    // Object setup
    void SetOutOfWorld();
    void StartBurp(int index);
    void SetSOMModel(u32 modelId);
    void SetupCharacter();
    void InitBulb();
    void SetInitalObjectState();
    virtual void Create(cXObject* obj, EHouse* house);
    virtual void SetObjOrient();
    void OrientSubObjects();
    void OrentSubObject();
    void CalcOrient();
    void CalcDynamicOrient();
    void SetWallForPortal();
    void CreateShadow();

    // Rendering
    void Update();
    void UpdateParticle(ObjAnimDef* animDef);
    void UpdateHighlightAnim();
    void BlendHighlights(ELights* lights, bool* flag);
    void CalcLightsFromPos(ELights* lights, bool flag);
    void DoLightingCalculation();
    bool VisibilityTest(E3DWindow& window);
    bool IsVisible();
    void Draw(ELevelDrawData& drawData);
    void AnimateLights();
    void DrawBounds(ERC* rc);
    void GetAnimDef(int index, bool flag);
    float GetHeightOffset();
    void ChageShader(u32 oldShader, u32 newShader);
    bool IsMultiTilePart();
    void ApplyMatrix(float scale, EVec3& pos, EVec3& dir);

    // Sub-models
    void InsertSubModelsInHouse(ERLevel* level);
    void PropigateFlagsToSubModels();
    void RemoveSubModelsFromHouse(ERLevel* level);
    void CleanupStuff(ERLevel* level);
    bool GetAdjacentRoom(bool side);
    void TryAnimateObject(short animId, short* result);
    void PreloadAnimation(short animId);

    // Static data
    static void* m_pWhiteShader;

    // Member variables (partial layout from disassembly)
    // EStorable base members come first (vtable ptr etc.)
    // ...
    // +0x0328: cXObject* m_pObject
    // +0x032C: u32 m_flags  (bit 6 = dynamic)
    // +0x03C8: EHouse* m_pHouse
    // +0x03F0: float m_rot
    // +0x03F8: float[2] m_burpScale
    // +0x0404: EVec3 m_pos  (12 bytes)
    // +0x0410: EVec3 m_dir  (12 bytes)
    // +0x0420: u32 m_bulbModelId (current bulb model)
    // +0x0424: ... (more anim state)
    // +0x0428: u32 m_animTrackCount (for ShouldAnimStartBlendIn)
    // +0x044C: void* m_pShadow
    // +0x0460: EILight* m_pILight
};

// ============================================================================
// ISimsWallObjectModel - Wall-mounted object model
// Inherits from ISimsObjectModel
// Vtable at 0x8045bff8
// ============================================================================
class ISimsWallObjectModel : public ISimsObjectModel {
public:
    ISimsWallObjectModel();
    virtual ~ISimsWallObjectModel();

    virtual const ETypeInfo* GetTypeInfo() const;
    virtual const char* GetTypeName() const;
    virtual u32 GetTypeKey() const;
    virtual u16 GetTypeVersion() const;
    virtual ISimsWallObjectModel* CreateCopy() const;
    virtual void CreateShadow();
    virtual void Create(cXObject* obj, EHouse* house);
    virtual void SetObjOrient();

    static const ETypeInfo* GetTypeInfoStatic();
    static u16 GetReadVersion();
    static void RegisterType(u16 version);
    static ISimsWallObjectModel* New();
    static void Construct(ISimsWallObjectModel* obj);
    static void Destruct(ISimsWallObjectModel* obj);
    void SafeDelete();
};

// ============================================================================
// ISimsMultiTileObjectModel - Multi-tile object model
// Inherits from ISimsObjectModel
// Vtable at 0x8045bdd0
// ============================================================================
class ISimsMultiTileObjectModel : public ISimsObjectModel {
public:
    ISimsMultiTileObjectModel();
    virtual ~ISimsMultiTileObjectModel();

    virtual const ETypeInfo* GetTypeInfo() const;
    virtual const char* GetTypeName() const;
    virtual u32 GetTypeKey() const;
    virtual u16 GetTypeVersion() const;
    virtual ISimsMultiTileObjectModel* CreateCopy() const;
    virtual void Create(cXObject* obj, EHouse* house);
    virtual void SetObjOrient();

    static const ETypeInfo* GetTypeInfoStatic();
    static u16 GetReadVersion();
    static void RegisterType(u16 version);
    static ISimsMultiTileObjectModel* New();
    static void Construct(ISimsMultiTileObjectModel* obj);
    static void Destruct(ISimsMultiTileObjectModel* obj);
    void SafeDelete();
};

// ============================================================================
// ISimsCounterTopObject - Counter top object model
// Inherits from ISimsObjectModel
// Vtable at 0x8045bba8
// ============================================================================
class ISimsCounterTopObject : public ISimsObjectModel {
public:
    ISimsCounterTopObject();
    virtual ~ISimsCounterTopObject();

    virtual const ETypeInfo* GetTypeInfo() const;
    virtual const char* GetTypeName() const;
    virtual u32 GetTypeKey() const;
    virtual u16 GetTypeVersion() const;
    virtual ISimsCounterTopObject* CreateCopy() const;
    virtual void Create(cXObject* obj, EHouse* house);
    virtual void SetObjOrient();

    static const ETypeInfo* GetTypeInfoStatic();
    static u16 GetReadVersion();
    static void RegisterType(u16 version);
    static ISimsCounterTopObject* New();
    static void Construct(ISimsCounterTopObject* obj);
    static void Destruct(ISimsCounterTopObject* obj);
    void SafeDelete();

    static bool IsSinkId(cXObject* obj);
};

// ============================================================================
// IShrubObject - Shrub/plant object model
// Inherits from ISimsObjectModel
// Vtable at 0x8045b980
// ============================================================================
class IShrubObject : public ISimsObjectModel {
public:
    IShrubObject();
    virtual ~IShrubObject();

    virtual const ETypeInfo* GetTypeInfo() const;
    virtual const char* GetTypeName() const;
    virtual u32 GetTypeKey() const;
    virtual u16 GetTypeVersion() const;
    virtual IShrubObject* CreateCopy() const;
    virtual void Create(cXObject* obj, EHouse* house);
    virtual void SetObjOrient();

    static const ETypeInfo* GetTypeInfoStatic();
    static u16 GetReadVersion();
    static void RegisterType(u16 version);
    static IShrubObject* New();
    static void Construct(IShrubObject* obj);
    static void Destruct(IShrubObject* obj);
    void SafeDelete();
};

// ============================================================================
// EParticleEffect - Individual particle effect instance
// ============================================================================
class EParticleEffect {
public:
    EParticleEffect(AttachmentNode& node, EMat4& mat);
    ~EParticleEffect();
    void UpdateParticleEffectLoad();
    void SetPos(EMat4& mat, EVec3* pos);
    void SetAlphaFade(float fade);
};

// ============================================================================
// EmitterGeom3d / EmitterGeom3dTab - Particle emitter geometry classes
// Inherit from Emitter
// ============================================================================
class EmitterGeom3d : public Emitter {
public:
    virtual ~EmitterGeom3d();
};

class EmitterGeom3dTab : public Emitter {
public:
    virtual ~EmitterGeom3dTab();
};

// Streaming operators
EStream& operator<<(EStream& stream, ISimsObjectModel* obj);
EStream& operator>>(EStream& stream, ISimsObjectModel*& obj);
EFile& operator>>(EFile& file, ISimsObjectModel*& obj);

EStream& operator<<(EStream& stream, ISimsWallObjectModel* obj);
EStream& operator>>(EStream& stream, ISimsWallObjectModel*& obj);
EFile& operator>>(EFile& file, ISimsWallObjectModel*& obj);

EStream& operator<<(EStream& stream, ISimsMultiTileObjectModel* obj);
EStream& operator>>(EStream& stream, ISimsMultiTileObjectModel*& obj);
EFile& operator>>(EFile& file, ISimsMultiTileObjectModel*& obj);

EStream& operator<<(EStream& stream, ISimsCounterTopObject* obj);
EStream& operator>>(EStream& stream, ISimsCounterTopObject*& obj);
EFile& operator>>(EFile& file, ISimsCounterTopObject*& obj);

EStream& operator<<(EStream& stream, IShrubObject* obj);
EStream& operator>>(EStream& stream, IShrubObject*& obj);
EFile& operator>>(EFile& file, IShrubObject*& obj);

// External streaming operators (from base library)
extern EStream& operator<<(EStream& stream, EStorable* obj);
extern EStream& operator>>(EStream& stream, EStorable*& obj);
extern EFile& operator>>(EFile& file, EStorable*& obj);

#endif // IOBJECT_H

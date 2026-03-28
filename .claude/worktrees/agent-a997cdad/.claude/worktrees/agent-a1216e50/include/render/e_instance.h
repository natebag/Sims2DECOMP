#ifndef E_INSTANCE_H
#define E_INSTANCE_H

#include "types.h"

// Forward declarations
class EStream;
class EFile;
class EBoundSphere;
class EVec3;
class EMat4;
class EOrderTableData;
class E3DWindow;
class ELevelDrawData;
class ERC;
class ERLevel;
class EInstance;

// EBound3 - axis-aligned bounding box (24 bytes)
struct EBound3 {
    float minX, minY, minZ;
    float maxX, maxY, maxZ;

    void CalcBoundSphere(EBoundSphere& sphere);
};

// ETypeInfo - type registration info (0x28 bytes)
struct ETypeInfo {
    u8 pad00[0x0C];     // 0x00
    char* m_name;        // 0x0C
    u32 m_key;           // 0x10
    u16 m_version;       // 0x14
    u16 m_readVersion;   // 0x16
    u8 pad18[0x10];      // 0x18

    void Register(void* (*newFn)(), void (*constructFn)(void*),
                  void (*destructFn)(void*), u16 version,
                  char* name, ETypeInfo* parent);
};

// Portal type enum
typedef int EPortalType;

// Function pointer types
typedef bool (*HiddenFn)(u32);
typedef void (*PortalSideFn)(u32, bool, s16&, s16&);

// InstType for GetInstName
struct InstType {
    int value;
};

// EStorable - base class for serializable objects
class EStorable {
public:
    virtual void SafeDelete();
    virtual const ETypeInfo* GetTypeInfo() const;
    virtual const char* GetTypeName() const;
    virtual u32 GetTypeKey() const;
    virtual u16 GetTypeVersion() const;
    virtual ~EStorable();
    virtual void Read(EStream& stream);
    virtual void Write(EStream& stream);
    virtual void Load(EFile& file);

    static ETypeInfo m_typeInfo;

    EStorable* CreateCopy() const;
};

// EInstance class - game object instance
// Total size: 0x7C (124 bytes) from New()
class EInstance : public EStorable {
public:
    EInstance();
    virtual ~EInstance();

    // EStorable overrides
    virtual void SafeDelete();
    virtual const ETypeInfo* GetTypeInfo() const;
    virtual const char* GetTypeName() const;
    virtual u32 GetTypeKey() const;
    virtual u16 GetTypeVersion() const;
    virtual void Read(EStream& stream);
    virtual void Write(EStream& stream);
    virtual void Load(EFile& file);

    // EInstance virtuals
    virtual void Init();
    virtual void Update();
    virtual void DoAnimation();
    virtual void DoLightingCalculation();
    virtual int VisibilityTest(E3DWindow& window);
    virtual void Draw(ELevelDrawData& data);
    virtual void DrawStencil(ELevelDrawData& data);
    virtual void DrawShadow(ELevelDrawData& data);
    virtual void DrawWireFrame(ERC* rc);
    virtual void SetOrient(EMat4& orient);
    virtual void RebuildShaders();
    virtual const char* GetInstName(InstType& type);
    virtual int GetUpdatePriority();
    virtual void RegisterFloor();
    virtual void GetShadowCenter(EVec3& center) const;
    virtual void GetBoundSphere(EBoundSphere& sphere);
    virtual void ReadInstanceData(EStream& stream, bool flag);
    virtual int CanReloadInstanceData();
    virtual ERLevel* GetLevel();
    virtual void* GetOwner();
    virtual int GetNumRoomID();
    virtual int GetRoomID(u32 index);
    virtual void GetVelocity(EVec3& vel);
    virtual void GetPos(EVec3& pos);
    virtual void GetOrient(EMat4& orient);
    virtual int HasModifiableColor();
    virtual void ModifyColor(u32 color);
    virtual int GetModifiableColor(u32 index);
    virtual void AddedToLevel(ERLevel* level);
    virtual void AboutToBeRemovedFromLevel(ERLevel* level);
    virtual void RemovedFromLevel(ERLevel* level);
    virtual void RealizeShaderTuning();

    // Non-virtual methods
    void RemoveFromLevel();
    void SetBounds(EBound3& bounds);
    void InsertInOrderTable(EOrderTableData& data);
    void SetInstAlpha(float alpha);
    float GetInstAlpha();
    static void SetContext(int context);
    static int GetContext();
    void SetPortalType(EPortalType type);
    EPortalType GetPortalType();
    void RegisterOtherSideFn(u32 data, PortalSideFn fn);
    u32 GetThisSideData();
    PortalSideFn GetThisSideFn();
    u32 GetOtherSideData();
    PortalSideFn GetOtherSideFn();
    void RegisterThisSideFn(u32 data, PortalSideFn fn);
    void RegisterHiddenFn(u32 data, HiddenFn fn);
    bool IsHidden();
    void SetShadowInterpolated(bool interp);
    const EBound3* GetBounds() const;
    bool IsShadow();
    EInstance* GetShadowOwner();
    int IsWall();
    void ShouldInterestFade(bool fade);
    void ResetLocation();
    void GetLocationId(s16& a, s16& b);
    void GetOtherSide(s16& a, s16& b);

    // Static factory/type methods
    static EInstance* New();
    static void Construct(EInstance* inst);
    static void Destruct(EInstance* inst);
    static const ETypeInfo* GetTypeInfoStatic();
    static u16 GetReadVersion();
    static void RegisterType(u16 version);
    EStorable* CreateCopy() const;

    // Member data - offsets from this pointer (vtable at 0x00)
    // Layout determined from constructor at 0x80228290
    ERLevel* m_pLevel;          // 0x04 (= 0)
    u32 m_field08;              // 0x08 (= 0)
    u32 m_field0C;              // 0x0C (= 0, SetShadowInterpolated)
    u32 m_isWall;               // 0x10 (= 0)
    EPortalType m_portalType;   // 0x14 (= 0)
    EInstance* m_shadowOwner;   // 0x18 (= 0)
    PortalSideFn m_thisSideFn;  // 0x1C (= 0)
    PortalSideFn m_otherSideFn; // 0x20 (= 0)
    u32 m_otherSideData;        // 0x24 (= 0)
    u32 m_thisSideData;         // 0x28 (= 0)
    u32 m_hiddenData;           // 0x2C (= 0)
    HiddenFn m_hiddenFn;        // 0x30 (= 0)
    u32 m_field34;              // 0x34 (= 0)
    u32 m_field38;              // 0x38 (= 0)
    EBound3 m_bounds;           // 0x3C (24 bytes, initialized to all 0.0f)
    s32 m_field54;              // 0x54 (= -1)
    u32 m_field58;              // 0x58 (= 0)
    u32 m_field5C;              // 0x5C (= 15 = 0x0F)
    float m_instAlpha0;         // 0x60 (= 1.0f, instAlpha context 0)
    float m_instAlpha1;         // 0x64 (= 1.0f, instAlpha context 1)
    u32 m_field68;              // 0x68 (= 1)
    u32 m_field6C;              // 0x6C (= 1, ShouldInterestFade)
    u32 m_field70;              // 0x70 (= 1)
    u32 m_field74;              // 0x74 (= 0)
    u32 m_field78;              // 0x78 (= 0)

    static ETypeInfo m_typeInfo;
    static int _instanceContext;
};

// LightArray helper struct
struct LightArray {
    char pad[0xD00];
    int count;          // 0xD00

    void Init();
};

#endif // E_INSTANCE_H

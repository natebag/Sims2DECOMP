#ifndef E_LIGHT_H
#define E_LIGHT_H

#include "types.h"
#include "render/e_instance.h"
#include "core/e_vec3.h"

// Forward declarations
class EStream;
class EFile;
class EMat4;
class EBoundSphere;
class ERLevel;
class E3DWindow;
class ELevelDrawData;
class ERC;
class ERModel;
class EAnimController;

// Light type enum
enum ELightType {
    LIGHTTYPE_BASE = 0,
    LIGHTTYPE_AMBIENT = 1,
    LIGHTTYPE_DIRECTIONAL = 2,
    LIGHTTYPE_POINT = 3,
    LIGHTTYPE_POINTAMB = 4,
    LIGHTTYPE_SPOT = 5
};

// eTrackFlags enum
enum eTrackFlags {
    TRACK_DEFAULT = 0
};

// ----- EILight (base light class) -----
// Inherits from EInstance (0x7C bytes base)
// Total size: 0xAC (172 bytes) from New() which allocates 0xAC
class EILight : public EInstance {
public:
    // 0x7C: m_enabled (int)
    int m_enabled;          // 0x7C
    // 0x80: m_useScaleIntensity (int)
    int m_useScaleIntensity; // 0x80
    // 0x84: m_lightIndex (int)
    int m_lightIndex;       // 0x84
    // 0x88: m_isEnabled (int)
    int m_isEnabled;        // 0x88
    // 0x8C: m_intensity (float)
    float m_intensity;      // 0x8C
    // 0x90: m_color (EVec3, 12 bytes)
    EVec3 m_color;          // 0x90
    // 0x9C: m_intensityScale (EVec3, 12 bytes)
    EVec3 m_intensityScale; // 0x9C
    // 0xA8: m_useScaleIntensity2 (int)
    int m_useScaleIntensity2; // 0xA8

    EILight();
    virtual ~EILight();

    // Virtuals
    virtual void SafeDelete();
    virtual const ETypeInfo* GetTypeInfo() const;
    virtual const char* GetTypeName() const;
    virtual u32 GetTypeKey() const;
    virtual u16 GetTypeVersion() const;
    virtual void Read(EStream& stream);
    virtual void Write(EStream& stream);
    virtual void Load(EFile& file);
    virtual void Init();

    // EILight-specific virtuals
    virtual void LightingParameters(EVec3& a, float& b, EVec3& c, EVec3& d);
    virtual void CalcFullIntensityLightOnPoint(EVec3& a, float& b);
    virtual void Setup();
    virtual int GetLightType();
    virtual void GetPosition(EVec3& pos);

    // Non-virtual
    void SetIntensityScale(EVec3& scale);
    void UseScaleIntensity(bool use);
    EVec3* GetIntensityScale();
    void SetIntensity(float intensity);
    float GetIntensity() const;
    void SetColor(EVec3& color);
    EVec3* GetColor() const;
    void Enable(bool enable);
    int IsEnabled();
    float GetFalloffEnd();
    static void SetHaveLightsChanged(bool changed);
    static int HaveLightsChanged();

    static EILight* New();
    static void Construct(EILight* light);
    static void Destruct(EILight* light);
    static const ETypeInfo* GetTypeInfoStatic();
    static u16 GetReadVersion();
    static void RegisterType(u16 version);
    EStorable* CreateCopy() const;

    static ETypeInfo m_typeInfo;
};

EStream& operator<<(EStream& stream, EILight* light);
EStream& operator>>(EStream& stream, EILight*& light);
EFile& operator>>(EFile& file, EILight*& light);

// ----- EIAmbLight -----
// Inherits from EILight
class EIAmbLight : public EILight {
public:
    virtual void SafeDelete();
    virtual const ETypeInfo* GetTypeInfo() const;
    virtual const char* GetTypeName() const;
    virtual u32 GetTypeKey() const;
    virtual u16 GetTypeVersion() const;
    virtual int GetLightType();

    static void Construct(EIAmbLight* light);
    static void Destruct(EIAmbLight* light);
    static const ETypeInfo* GetTypeInfoStatic();
    static u16 GetReadVersion();
    EStorable* CreateCopy() const;

    static ETypeInfo m_typeInfo;
};

EStream& operator<<(EStream& stream, EIAmbLight* light);
EStream& operator>>(EStream& stream, EIAmbLight*& light);
EFile& operator>>(EFile& file, EIAmbLight*& light);

// ----- EIDirLight -----
// EILight + direction at 0xAC (EVec3, 12 bytes)
// Total size approx 0xB8
class EIDirLight : public EILight {
public:
    EVec3 m_dir;  // 0xAC

    virtual void SafeDelete();
    virtual const ETypeInfo* GetTypeInfo() const;
    virtual const char* GetTypeName() const;
    virtual u32 GetTypeKey() const;
    virtual u16 GetTypeVersion() const;
    virtual void Write(EStream& stream);
    virtual int GetLightType();

    void SetDir(EVec3& dir);
    EVec3* GetDir() const;

    static EIDirLight* New();
    static void Construct(EIDirLight* light);
    static void Destruct(EIDirLight* light);
    static const ETypeInfo* GetTypeInfoStatic();
    static u16 GetReadVersion();
    EStorable* CreateCopy() const;

    static ETypeInfo m_typeInfo;
};

EStream& operator<<(EStream& stream, EIDirLight* light);
EStream& operator>>(EStream& stream, EIDirLight*& light);
EFile& operator>>(EFile& file, EIDirLight*& light);

// ----- EIPointLight -----
// EILight + position at 0xAC, radius, roomId, etc.
class EIPointLight : public EILight {
public:
    EVec3 m_position;   // 0xAC
    u8 pad_B8[0x08];    // 0xB8
    int m_roomId;       // 0xC0
    u8 pad_C4[0x04];    // 0xC4
    float m_falloffEnd; // 0xC8

    virtual void SafeDelete();
    virtual const ETypeInfo* GetTypeInfo() const;
    virtual const char* GetTypeName() const;
    virtual u32 GetTypeKey() const;
    virtual u16 GetTypeVersion() const;
    virtual int GetLightType();
    virtual void GetPosition(EVec3& pos);
    virtual float GetFalloffEnd();
    virtual int GetRoomId();

    static EIPointLight* New();
    static void Construct(EIPointLight* light);
    static void Destruct(EIPointLight* light);
    static const ETypeInfo* GetTypeInfoStatic();
    static u16 GetReadVersion();
    EStorable* CreateCopy() const;

    static ETypeInfo m_typeInfo;
};

EStream& operator<<(EStream& stream, EIPointLight* light);
EStream& operator>>(EStream& stream, EIPointLight*& light);
EFile& operator>>(EFile& file, EIPointLight*& light);

// ----- EIPortalPointLight -----
class EIPortalPointLight : public EIPointLight {
public:
    static ETypeInfo m_typeInfo;
};

EStream& operator<<(EStream& stream, EIPortalPointLight* light);
EStream& operator>>(EStream& stream, EIPortalPointLight*& light);
EFile& operator>>(EFile& file, EIPortalPointLight*& light);

// ----- EIPointAmbLight -----
class EIPointAmbLight : public EILight {
public:
    virtual void SafeDelete();
    virtual const ETypeInfo* GetTypeInfo() const;
    virtual const char* GetTypeName() const;
    virtual u32 GetTypeKey() const;
    virtual u16 GetTypeVersion() const;

    static EIPointAmbLight* New();
    static void Construct(EIPointAmbLight* light);
    static void Destruct(EIPointAmbLight* light);
    static const ETypeInfo* GetTypeInfoStatic();
    static u16 GetReadVersion();
    EStorable* CreateCopy() const;

    static ETypeInfo m_typeInfo;
};

EStream& operator<<(EStream& stream, EIPointAmbLight* light);
EStream& operator>>(EStream& stream, EIPointAmbLight*& light);
EFile& operator>>(EFile& file, EIPointAmbLight*& light);

// ----- EISpotLight -----
class EISpotLight : public EILight {
public:
    virtual void SafeDelete();
    virtual const ETypeInfo* GetTypeInfo() const;
    virtual const char* GetTypeName() const;
    virtual u32 GetTypeKey() const;
    virtual u16 GetTypeVersion() const;

    static EISpotLight* New();
    static void Construct(EISpotLight* light);
    static void Destruct(EISpotLight* light);
    static const ETypeInfo* GetTypeInfoStatic();
    static u16 GetReadVersion();
    EStorable* CreateCopy() const;

    static ETypeInfo m_typeInfo;
};

EStream& operator<<(EStream& stream, EISpotLight* light);
EStream& operator>>(EStream& stream, EISpotLight*& light);
EFile& operator>>(EFile& file, EISpotLight*& light);

// ----- EIGameInstance -----
class EIGameInstance : public EInstance {
public:
    EIGameInstance();
    virtual ~EIGameInstance();

    virtual void SafeDelete();
    virtual const ETypeInfo* GetTypeInfo() const;
    virtual const char* GetTypeName() const;
    virtual u32 GetTypeKey() const;
    virtual u16 GetTypeVersion() const;

    static EIGameInstance* New();
    static void Construct(EIGameInstance* inst);
    static void Destruct(EIGameInstance* inst);
    static const ETypeInfo* GetTypeInfoStatic();
    static u16 GetReadVersion();
    EStorable* CreateCopy() const;

    static ETypeInfo m_typeInfo;
};

EStream& operator<<(EStream& stream, EIGameInstance* inst);
EStream& operator>>(EStream& stream, EIGameInstance*& inst);
EFile& operator>>(EFile& file, EIGameInstance*& inst);

// ----- EIStaticModel -----
// EInstance (0x7C) + EMat4 at 0x80 (64 bytes) + orient at 0xC0 (64 bytes) + more
class EIStaticModel : public EInstance {
public:
    u8 m_drawMatrix[64]; // 0x80 - EMat4
    u8 m_orient[64];     // 0xC0 - EMat4 orient
    u8 pad100[0x10];     // 0x100
    u32 m_modelId;       // 0x110
    u32 m_modColor;      // 0x114
    u8 pad118[0x04];     // 0x118
    u8 pad11C[0x04];     // 0x11C
    ERModel* m_model;    // 0x120
    EVec3 m_pos;         // 0xF0 (actual pos)

    virtual void SafeDelete();
    virtual const ETypeInfo* GetTypeInfo() const;
    virtual const char* GetTypeName() const;
    virtual u32 GetTypeKey() const;
    virtual u16 GetTypeVersion() const;
    virtual int VisibilityTest(E3DWindow& window);
    virtual const char* GetInstName(InstType& type);
    virtual void GetBoundSphere(EBoundSphere& sphere);
    virtual int HasModifiableColor();
    virtual void ModifyColor(u32 color);
    virtual int GetModifiableColor();
    virtual void GetPos(EVec3& pos);
    virtual int SetModel(u32 modelId, bool flag, EInstance* inst, EAnimController* ctrl);

    int IsSkydome() const;
    u32 GetModelId();
    ERModel* GetModel();
    EMat4* GetDrawMatrix();
    EMat4* GetOrient() const;

    static EIStaticModel* New();
    static void Construct(EIStaticModel* model);
    static void Destruct(EIStaticModel* model);
    static const ETypeInfo* GetTypeInfoStatic();
    static u16 GetReadVersion();
    EStorable* CreateCopy() const;

    void* operator new(unsigned int size);
    void* operator new(unsigned int size, void* ptr);
    void operator delete(void* ptr);

    static ETypeInfo m_typeInfo;
};

EStream& operator<<(EStream& stream, EIStaticModel* model);
EStream& operator>>(EStream& stream, EIStaticModel*& model);
EFile& operator>>(EFile& file, EIStaticModel*& model);

// ----- EIStaticSubModel -----
class EIStaticSubModel : public EInstance {
public:
    u8 pad7C[0x04];      // 0x7C
    u8 m_boundSphere[16]; // 0x80 - EBoundSphere (4 floats)
    u32 m_modColor2;     // 0x94

    virtual void SafeDelete();
    virtual const ETypeInfo* GetTypeInfo() const;
    virtual const char* GetTypeName() const;
    virtual u32 GetTypeKey() const;
    virtual u16 GetTypeVersion() const;
    virtual int VisibilityTest(E3DWindow& window);
    virtual const char* GetInstName(InstType& type);
    virtual void GetBoundSphere(EBoundSphere& sphere);
    virtual void ModifyColor(u32 color);
    virtual int GetModifiableColor();
    virtual void RealizeShaderTuning();

    void Deallocate();
    EBoundSphere* GetBoundSphere();

    static EIStaticSubModel* New();
    static void Construct(EIStaticSubModel* model);
    static void Destruct(EIStaticSubModel* model);
    static const ETypeInfo* GetTypeInfoStatic();
    static u16 GetReadVersion();
    EStorable* CreateCopy() const;

    void* operator new(unsigned int size);
    void* operator new(unsigned int size, void* ptr);
    void operator delete(void* ptr);

    static ETypeInfo m_typeInfo;
};

EStream& operator<<(EStream& stream, EIStaticSubModel* model);
EStream& operator>>(EStream& stream, EIStaticSubModel*& model);
EFile& operator>>(EFile& file, EIStaticSubModel*& model);

// ----- EMirrorPortal -----
class EMirrorPortal {
public:
    u8 pad00[0x38];      // 0x00
    int m_numCorners;    // 0x38
    int m_portalStackId; // 0x3C
    u8 pad40[0x04];      // 0x40
    void* m_texture;     // 0x44

    void SetNumCorners(int n);
    EVec3* GetCorner(int index) const;
    void SetCorner(int index, EVec3& corner);
    void SetFieldOfView(float fov);
    void PopPortal(E3DWindow& window);
};

#endif // E_LIGHT_H
